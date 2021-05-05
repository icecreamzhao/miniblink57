// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/renderer_host/render_message_filter.h"

#include <errno.h>
#include <string.h>

#include <map>
#include <utility>

#include "base/bind.h"
#include "base/bind_helpers.h"
#include "base/command_line.h"
#include "base/debug/alias.h"
#include "base/macros.h"
#include "base/numerics/safe_math.h"
#include "base/strings/sys_string_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/threading/thread.h"
#include "base/threading/worker_pool.h"
#include "build/build_config.h"
#include "content/browser/blob_storage/chrome_blob_storage_context.h"
#include "content/browser/browser_main_loop.h"
#include "content/browser/cache_storage/cache_storage_cache.h"
#include "content/browser/cache_storage/cache_storage_cache_handle.h"
#include "content/browser/cache_storage/cache_storage_context_impl.h"
#include "content/browser/cache_storage/cache_storage_manager.h"
#include "content/browser/dom_storage/dom_storage_context_wrapper.h"
#include "content/browser/dom_storage/session_storage_namespace_impl.h"
#include "content/browser/download/download_stats.h"
#include "content/browser/gpu/gpu_data_manager_impl.h"
#include "content/browser/gpu/gpu_process_host.h"
#include "content/browser/loader/resource_dispatcher_host_impl.h"
#include "content/browser/media/media_internals.h"
#include "content/browser/renderer_host/pepper/pepper_security_helper.h"
#include "content/browser/renderer_host/render_process_host_impl.h"
#include "content/browser/renderer_host/render_view_host_delegate.h"
#include "content/browser/renderer_host/render_widget_helper.h"
#include "content/browser/resource_context_impl.h"
#include "content/common/cache_storage/cache_storage_types.h"
#include "content/common/child_process_host_impl.h"
#include "content/common/child_process_messages.h"
#include "content/common/content_constants_internal.h"
#include "content/common/render_message_filter.mojom.h"
#include "content/common/render_process_messages.h"
#include "content/common/view_messages.h"
#include "content/public/browser/browser_child_process_host.h"
#include "content/public/browser/browser_context.h"
#include "content/public/browser/browser_thread.h"
#include "content/public/browser/content_browser_client.h"
#include "content/public/browser/resource_context.h"
#include "content/public/browser/user_metrics.h"
#include "content/public/common/content_switches.h"
#include "content/public/common/context_menu_params.h"
#include "content/public/common/url_constants.h"
#include "gpu/ipc/client/gpu_memory_buffer_impl.h"
#include "ipc/ipc_channel_handle.h"
#include "ipc/ipc_platform_file.h"
#include "media/base/media_log_event.h"
#include "mojo/public/cpp/system/platform_handle.h"
#include "net/base/io_buffer.h"
#include "net/base/mime_util.h"
#include "net/base/request_priority.h"
#include "net/http/http_cache.h"
#include "net/url_request/url_request_context.h"
#include "net/url_request/url_request_context_getter.h"
#include "ppapi/shared_impl/file_type_conversion.h"
#include "url/gurl.h"
#include "url/origin.h"

#if defined(OS_MACOSX)
#include "content/common/mac/font_descriptor.h"
#endif

#if defined(OS_WIN)
#include "content/common/font_cache_dispatcher_win.h"
#endif

#if defined(OS_POSIX)
#include "base/file_descriptor_posix.h"
#endif

#if defined(OS_ANDROID)
#include "content/browser/media/android/media_throttler.h"
#endif

#if defined(OS_MACOSX)
#include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
#endif

#if defined(OS_LINUX)
#include "base/linux_util.h"
#include "base/threading/platform_thread.h"
#endif

namespace content {
namespace {

    const uint32_t kFilteredMessageClasses[] = {
        ChildProcessMsgStart,
        RenderProcessMsgStart,
        ViewMsgStart,
    };

#if defined(OS_MACOSX)
    void ResizeHelperHandleMsgOnUIThread(int render_process_id,
        const IPC::Message& message)
    {
        RenderProcessHost* host = RenderProcessHost::FromID(render_process_id);
        if (host)
            host->OnMessageReceived(message);
    }

    void ResizeHelperPostMsgToUIThread(int render_process_id,
        const IPC::Message& msg)
    {
        ui::WindowResizeHelperMac::Get()->task_runner()->PostDelayedTask(
            FROM_HERE,
            base::Bind(ResizeHelperHandleMsgOnUIThread, render_process_id, msg),
            base::TimeDelta());
    }
#endif

    void NoOpCacheStorageErrorCallback(
        std::unique_ptr<CacheStorageCacheHandle> cache_handle,
        CacheStorageError error)
    {
    }

} // namespace

RenderMessageFilter::RenderMessageFilter(
    int render_process_id,
    BrowserContext* browser_context,
    net::URLRequestContextGetter* request_context,
    RenderWidgetHelper* render_widget_helper,
    MediaInternals* media_internals,
    DOMStorageContextWrapper* dom_storage_context,
    CacheStorageContextImpl* cache_storage_context)
    : BrowserMessageFilter(kFilteredMessageClasses,
        arraysize(kFilteredMessageClasses))
    , BrowserAssociatedInterface<mojom::RenderMessageFilter>(this, this)
    , resource_dispatcher_host_(ResourceDispatcherHostImpl::Get())
    , bitmap_manager_client_(HostSharedBitmapManager::current())
    , request_context_(request_context)
    , resource_context_(browser_context->GetResourceContext())
    , render_widget_helper_(render_widget_helper)
    , dom_storage_context_(dom_storage_context)
    , render_process_id_(render_process_id)
    , media_internals_(media_internals)
    , cache_storage_context_(cache_storage_context)
    , weak_ptr_factory_(this)
{
    DCHECK(request_context_.get());

    if (render_widget_helper)
        render_widget_helper_->Init(render_process_id_, resource_dispatcher_host_);
}

RenderMessageFilter::~RenderMessageFilter()
{
    // This function should be called on the IO thread.
    DCHECK_CURRENTLY_ON(BrowserThread::IO);
}

bool RenderMessageFilter::OnMessageReceived(const IPC::Message& message)
{
    bool handled = true;
    IPC_BEGIN_MESSAGE_MAP(RenderMessageFilter, message)
#if defined(OS_MACOSX)
    // On Mac, the IPCs ViewHostMsg_SwapCompositorFrame, ViewHostMsg_UpdateRect,
    // and GpuCommandBufferMsg_SwapBuffersCompleted need to be handled in a
    // nested message loop during resize.
    IPC_MESSAGE_HANDLER_GENERIC(
        ViewHostMsg_SwapCompositorFrame,
        ResizeHelperPostMsgToUIThread(render_process_id_, message))
    IPC_MESSAGE_HANDLER_GENERIC(
        ViewHostMsg_UpdateRect,
        ResizeHelperPostMsgToUIThread(render_process_id_, message))
    IPC_MESSAGE_HANDLER_GENERIC(
        ViewHostMsg_SetNeedsBeginFrames,
        ResizeHelperPostMsgToUIThread(render_process_id_, message))
#endif
    IPC_MESSAGE_HANDLER_DELAY_REPLY(ChildProcessHostMsg_HasGpuProcess,
        OnHasGpuProcess)
#if defined(OS_LINUX)
    IPC_MESSAGE_HANDLER(ChildProcessHostMsg_SetThreadPriority,
        OnSetThreadPriority)
#endif
    IPC_MESSAGE_HANDLER(RenderProcessHostMsg_DidGenerateCacheableMetadata,
        OnCacheableMetadataAvailable)
    IPC_MESSAGE_HANDLER(
        RenderProcessHostMsg_DidGenerateCacheableMetadataInCacheStorage,
        OnCacheableMetadataAvailableForCacheStorage)
#if defined(OS_MACOSX)
    IPC_MESSAGE_HANDLER_DELAY_REPLY(RenderProcessHostMsg_LoadFont, OnLoadFont)
#endif
    IPC_MESSAGE_HANDLER(ViewHostMsg_MediaLogEvents, OnMediaLogEvents)
    IPC_MESSAGE_UNHANDLED(handled = false)
    IPC_END_MESSAGE_MAP()

    return handled;
}

void RenderMessageFilter::OnDestruct() const
{
    const_cast<RenderMessageFilter*>(this)->resource_context_ = nullptr;
    BrowserThread::DeleteOnIOThread::Destruct(this);
}

void RenderMessageFilter::OverrideThreadForMessage(const IPC::Message& message,
    BrowserThread::ID* thread)
{
    if (message.type() == ViewHostMsg_MediaLogEvents::ID)
        *thread = BrowserThread::UI;
}

void RenderMessageFilter::GenerateRoutingID(
    const GenerateRoutingIDCallback& callback)
{
    callback.Run(render_widget_helper_->GetNextRoutingID());
}

void RenderMessageFilter::CreateNewWindow(
    mojom::CreateNewWindowParamsPtr params,
    const CreateNewWindowCallback& callback)
{
    bool no_javascript_access;
    bool can_create_window = GetContentClient()->browser()->CanCreateWindow(
        render_process_id_, params->opener_render_frame_id, params->opener_url,
        params->opener_top_level_frame_url, params->opener_security_origin,
        params->window_container_type, params->target_url, params->referrer,
        params->frame_name, params->disposition, params->features,
        params->user_gesture, params->opener_suppressed, resource_context_,
        &no_javascript_access);

    mojom::CreateNewWindowReplyPtr reply = mojom::CreateNewWindowReply::New();
    if (!can_create_window) {
        reply->route_id = MSG_ROUTING_NONE;
        reply->main_frame_route_id = MSG_ROUTING_NONE;
        reply->main_frame_widget_route_id = MSG_ROUTING_NONE;
        reply->cloned_session_storage_namespace_id = 0;
        return callback.Run(std::move(reply));
    }

    // This will clone the sessionStorage for namespace_id_to_clone.
    scoped_refptr<SessionStorageNamespaceImpl> cloned_namespace = new SessionStorageNamespaceImpl(dom_storage_context_.get(),
        params->session_storage_namespace_id);
    reply->cloned_session_storage_namespace_id = cloned_namespace->id();

    render_widget_helper_->CreateNewWindow(
        std::move(params), no_javascript_access, &reply->route_id,
        &reply->main_frame_route_id, &reply->main_frame_widget_route_id,
        cloned_namespace.get());
    callback.Run(std::move(reply));
}

void RenderMessageFilter::CreateNewWidget(
    int32_t opener_id,
    blink::WebPopupType popup_type,
    const CreateNewWidgetCallback& callback)
{
    int route_id = MSG_ROUTING_NONE;
    render_widget_helper_->CreateNewWidget(opener_id, popup_type, &route_id);
    callback.Run(route_id);
}

void RenderMessageFilter::CreateFullscreenWidget(
    int opener_id,
    const CreateFullscreenWidgetCallback& callback)
{
    int route_id = 0;
    render_widget_helper_->CreateNewFullscreenWidget(opener_id, &route_id);
    callback.Run(route_id);
}

#if defined(OS_MACOSX)

void RenderMessageFilter::OnLoadFont(const FontDescriptor& font,
    IPC::Message* reply_msg)
{
    FontLoader::Result* result = new FontLoader::Result;

    BrowserThread::PostTaskAndReply(
        BrowserThread::FILE, FROM_HERE,
        base::Bind(&FontLoader::LoadFont, font, result),
        base::Bind(&RenderMessageFilter::SendLoadFontReply, this, reply_msg,
            base::Owned(result)));
}

void RenderMessageFilter::SendLoadFontReply(IPC::Message* reply,
    FontLoader::Result* result)
{
    base::SharedMemoryHandle handle;
    if (result->font_data_size == 0 || result->font_id == 0) {
        result->font_data_size = 0;
        result->font_id = 0;
        handle = base::SharedMemory::NULLHandle();
    } else {
        result->font_data.GiveToProcess(base::GetCurrentProcessHandle(), &handle);
    }
    RenderProcessHostMsg_LoadFont::WriteReplyParams(
        reply, result->font_data_size, handle, result->font_id);
    Send(reply);
}

#endif // defined(OS_MACOSX)

void RenderMessageFilter::AllocatedSharedBitmap(
    mojo::ScopedSharedBufferHandle buffer,
    const cc::SharedBitmapId& id)
{
    base::SharedMemoryHandle memory_handle;
    size_t size;
    MojoResult result = mojo::UnwrapSharedMemoryHandle(
        std::move(buffer), &memory_handle, &size, NULL);
    DCHECK_EQ(result, MOJO_RESULT_OK);
    bitmap_manager_client_.ChildAllocatedSharedBitmap(size, memory_handle, id);
}

void RenderMessageFilter::DeletedSharedBitmap(const cc::SharedBitmapId& id)
{
    bitmap_manager_client_.ChildDeletedSharedBitmap(id);
}

#if defined(OS_LINUX)
void RenderMessageFilter::SetThreadPriorityOnFileThread(
    base::PlatformThreadId ns_tid,
    base::ThreadPriority priority)
{
    bool ns_pid_supported = false;
    pid_t peer_tid = base::FindThreadID(peer_pid(), ns_tid, &ns_pid_supported);
    if (peer_tid == -1) {
        if (ns_pid_supported)
            DLOG(WARNING) << "Could not find tid";
        return;
    }

    if (peer_tid == peer_pid()) {
        DLOG(WARNING) << "Changing priority of main thread is not allowed";
        return;
    }

    base::PlatformThread::SetThreadPriority(peer_tid, priority);
}

void RenderMessageFilter::OnSetThreadPriority(base::PlatformThreadId ns_tid,
    base::ThreadPriority priority)
{
    BrowserThread::PostTask(
        BrowserThread::FILE_USER_BLOCKING, FROM_HERE,
        base::Bind(&RenderMessageFilter::SetThreadPriorityOnFileThread, this,
            ns_tid, priority));
}
#endif

void RenderMessageFilter::OnCacheableMetadataAvailable(
    const GURL& url,
    base::Time expected_response_time,
    const std::vector<char>& data)
{
    net::HttpCache* cache = request_context_->GetURLRequestContext()->http_transaction_factory()->GetCache();
    if (!cache)
        return;

    // Use the same priority for the metadata write as for script
    // resources (see defaultPriorityForResourceType() in WebKit's
    // CachedResource.cpp). Note that WebURLRequest::PriorityMedium
    // corresponds to net::LOW (see ConvertWebKitPriorityToNetPriority()
    // in weburlloader_impl.cc).
    const net::RequestPriority kPriority = net::LOW;
    scoped_refptr<net::IOBuffer> buf(new net::IOBuffer(data.size()));
    if (!data.empty())
        memcpy(buf->data(), &data.front(), data.size());
    cache->WriteMetadata(url, kPriority, expected_response_time, buf.get(),
        data.size());
}

void RenderMessageFilter::OnCacheableMetadataAvailableForCacheStorage(
    const GURL& url,
    base::Time expected_response_time,
    const std::vector<char>& data,
    const url::Origin& cache_storage_origin,
    const std::string& cache_storage_cache_name)
{
    scoped_refptr<net::IOBuffer> buf(new net::IOBuffer(data.size()));
    if (!data.empty())
        memcpy(buf->data(), &data.front(), data.size());

    cache_storage_context_->cache_manager()->OpenCache(
        cache_storage_origin.GetURL(), cache_storage_cache_name,
        base::Bind(&RenderMessageFilter::OnCacheStorageOpenCallback,
            weak_ptr_factory_.GetWeakPtr(), url, expected_response_time,
            buf, data.size()));
}

void RenderMessageFilter::OnCacheStorageOpenCallback(
    const GURL& url,
    base::Time expected_response_time,
    scoped_refptr<net::IOBuffer> buf,
    int buf_len,
    std::unique_ptr<CacheStorageCacheHandle> cache_handle,
    CacheStorageError error)
{
    if (error != CACHE_STORAGE_OK || !cache_handle || !cache_handle->value())
        return;
    CacheStorageCache* cache = cache_handle->value();
    if (!cache)
        return;
    cache->WriteSideData(base::Bind(&NoOpCacheStorageErrorCallback,
                             base::Passed(std::move(cache_handle))),
        url, expected_response_time, buf, buf_len);
}

void RenderMessageFilter::OnMediaLogEvents(
    const std::vector<media::MediaLogEvent>& events)
{
    // OnMediaLogEvents() is always dispatched to the UI thread for handling.
    // See OverrideThreadForMessage().
    DCHECK_CURRENTLY_ON(BrowserThread::UI);
    if (media_internals_)
        media_internals_->OnMediaEvents(render_process_id_, events);
}

void RenderMessageFilter::OnHasGpuProcess(IPC::Message* reply_ptr)
{
    std::unique_ptr<IPC::Message> reply(reply_ptr);
    GpuProcessHost::GetProcessHandles(
        base::Bind(&RenderMessageFilter::GetGpuProcessHandlesCallback,
            weak_ptr_factory_.GetWeakPtr(), base::Passed(&reply)));
}

void RenderMessageFilter::GetGpuProcessHandlesCallback(
    std::unique_ptr<IPC::Message> reply,
    const std::list<base::ProcessHandle>& handles)
{
    bool has_gpu_process = handles.size() > 0;
    ChildProcessHostMsg_HasGpuProcess::WriteReplyParams(reply.get(),
        has_gpu_process);
    Send(reply.release());
}

} // namespace content
