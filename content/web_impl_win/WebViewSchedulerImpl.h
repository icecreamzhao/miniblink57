// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_SCHEDULER_RENDERER_WEB_VIEW_SCHEDULER_IMPL_H_
#define COMPONENTS_SCHEDULER_RENDERER_WEB_VIEW_SCHEDULER_IMPL_H_

#include "third_party/WebKit/public/platform/WebViewScheduler.h"
#include <memory>
#include <set>

namespace blink {
class WebView;
} // namespace blink

namespace content {

class AutoAdvancingVirtualTimeDomain;
class RendererSchedulerImpl;
class WebFrameSchedulerImpl;

class WebViewSchedulerImpl : public blink::WebViewScheduler {
public:
    WebViewSchedulerImpl(blink::WebView* web_view, bool disable_background_timer_throttling);

    ~WebViewSchedulerImpl() override;

    // blink::WebViewScheduler implementation:
    void setPageVisible(bool page_visible) override;
    std::unique_ptr<blink::WebFrameScheduler> createFrameScheduler(blink::BlameContext*) override;
    void enableVirtualTime() override;
    //void setAllowVirtualTimeToAdvance(bool allow_virtual_time_to_advance) override;

    bool virtualTimeAllowedToAdvance() const override;
    void setVirtualTimePolicy(blink::WebViewScheduler::VirtualTimePolicy) override;
    void audioStateChanged(bool isAudioPlaying) override;
    bool hasActiveConnectionForTest() const override;

    std::unique_ptr<WebFrameSchedulerImpl> createWebFrameSchedulerImpl();

private:
    friend class WebFrameSchedulerImpl;

    void Unregister(WebFrameSchedulerImpl* frame_scheduler);

    std::set<WebFrameSchedulerImpl*> frame_schedulers_;
    blink::WebView* web_view_;

    bool page_visible_;
    bool disable_background_timer_throttling_;
    bool allow_virtual_time_to_advance_;

    DISALLOW_COPY_AND_ASSIGN(WebViewSchedulerImpl);
};

} // namespace scheduler

#endif // COMPONENTS_SCHEDULER_RENDERER_WEB_VIEW_SCHEDULER_IMPL_H_
