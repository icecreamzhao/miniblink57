// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/web_impl_win/WebViewSchedulerImpl.h"

#include "content/web_impl_win/WebFrameSchedulerImpl.h"
#include "content/web_impl_win/WebTaskRunnerImpl.h"

#include "third_party/WebKit/public/platform/WebFrameScheduler.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebFrame.h"
#include "third_party/WebKit/public/web/WebView.h"

namespace content {

WebViewSchedulerImpl::WebViewSchedulerImpl(
    blink::WebView* web_view,
    bool disable_background_timer_throttling)
    : web_view_(web_view)
    , page_visible_(true)
    , disable_background_timer_throttling_(disable_background_timer_throttling)
    , allow_virtual_time_to_advance_(true)
{
}

WebViewSchedulerImpl::~WebViewSchedulerImpl()
{
    // TODO(alexclarke): Find out why we can't rely on the web view outliving the
    // frame.
    for (WebFrameSchedulerImpl* frame_scheduler : frame_schedulers_) {
        frame_scheduler->DetachFromWebViewScheduler();
    }
}

void WebViewSchedulerImpl::setPageVisible(bool page_visible)
{
    if (disable_background_timer_throttling_ || page_visible_ == page_visible)
        return;

    page_visible_ = page_visible;

    for (WebFrameSchedulerImpl* frame_scheduler : frame_schedulers_) {
        frame_scheduler->setPageVisible(page_visible_);
    }
}

std::unique_ptr<WebFrameSchedulerImpl> WebViewSchedulerImpl::createWebFrameSchedulerImpl()
{
    std::unique_ptr<WebFrameSchedulerImpl> frame_scheduler(new WebFrameSchedulerImpl(this));
    frame_scheduler->setPageVisible(page_visible_);
    frame_schedulers_.insert(frame_scheduler.get());
    return frame_scheduler;
}

std::unique_ptr<blink::WebFrameScheduler> WebViewSchedulerImpl::createFrameScheduler(blink::BlameContext*)
{
    return createWebFrameSchedulerImpl();
}

void WebViewSchedulerImpl::Unregister(WebFrameSchedulerImpl* frame_scheduler)
{
    DCHECK(frame_schedulers_.find(frame_scheduler) != frame_schedulers_.end());
    frame_schedulers_.erase(frame_scheduler);
}

void WebViewSchedulerImpl::enableVirtualTime()
{
    // If we've already switched to virtual time then we don't need to do
    // anything more.
    for (WebFrameSchedulerImpl* frame_scheduler : frame_schedulers_) {
        frame_scheduler->OnVirtualTimeDomainChanged();
    }
}

// void WebViewSchedulerImpl::setAllowVirtualTimeToAdvance(bool allow_virtual_time_to_advance)
// {
//     if (allow_virtual_time_to_advance_ == allow_virtual_time_to_advance)
//         return;
//
//     allow_virtual_time_to_advance_ = allow_virtual_time_to_advance;
// }

} // namespace scheduler
