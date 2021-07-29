// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/web_impl_win/WebFrameSchedulerImpl.h"

#include "content/web_impl_win/WebTaskRunnerImpl.h"
#include "content/web_impl_win/WebViewSchedulerImpl.h"
#include "third_party/WebKit/public/platform/Platform.h"
#include "third_party/WebKit/public/platform/WebString.h"

namespace content {

WebFrameSchedulerImpl::WebFrameSchedulerImpl(WebViewSchedulerImpl* parent_web_view_scheduler)
    : parent_web_view_scheduler_(parent_web_view_scheduler)
    , frame_visible_(true)
    , page_visible_(true)
{
}

WebFrameSchedulerImpl::~WebFrameSchedulerImpl()
{
    if (parent_web_view_scheduler_)
        parent_web_view_scheduler_->Unregister(this);
}

void WebFrameSchedulerImpl::DetachFromWebViewScheduler()
{
    parent_web_view_scheduler_ = nullptr;
}

void WebFrameSchedulerImpl::setFrameVisible(bool frame_visible)
{
    frame_visible_ = frame_visible;
    // TODO(alexclarke): Do something with this flag.
}

RefPtr<blink::WebTaskRunner> WebFrameSchedulerImpl::loadingTaskRunner()
{
    DCHECK(parent_web_view_scheduler_);
    //     if (!loading_web_task_runner_) {
    //         loading_web_task_runner_.reset(new WebTaskRunnerImpl());
    //     }
    //
    //     return loading_web_task_runner_.get();
    return blink::Platform::current()->currentThread()->getWebTaskRunner();
}

RefPtr<blink::WebTaskRunner> WebFrameSchedulerImpl::timerTaskRunner()
{
    DCHECK(parent_web_view_scheduler_);
    //     if (!timer_web_task_runner_) {
    //         timer_web_task_runner_.reset(new WebTaskRunnerImpl());
    //     }
    //     return timer_web_task_runner_.get();
    return blink::Platform::current()->currentThread()->getWebTaskRunner();
}

RefPtr<blink::WebTaskRunner> WebFrameSchedulerImpl::unthrottledTaskRunner()
{
    DCHECK(parent_web_view_scheduler_);
    return blink::Platform::current()->currentThread()->getWebTaskRunner();
}

void WebFrameSchedulerImpl::setPageVisible(bool page_visible)
{
    DCHECK(parent_web_view_scheduler_);
    if (page_visible_ == page_visible)
        return;

    page_visible_ = page_visible;

    if (!timer_web_task_runner_) {
        return;
    }

    if (page_visible_) {

    } else {
    }
}

void WebFrameSchedulerImpl::OnVirtualTimeDomainChanged()
{
    DCHECK(parent_web_view_scheduler_);
}

} // namespace scheduler
