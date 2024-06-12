// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_SCHEDULER_RENDERER_WEB_FRAME_SCHEDULER_IMPL_H_
#define COMPONENTS_SCHEDULER_RENDERER_WEB_FRAME_SCHEDULER_IMPL_H_

#include <memory>

#include "third_party/WebKit/Source/platform/WebFrameScheduler.h"

namespace content {

class AutoAdvancingVirtualTimeDomain;
class RendererSchedulerImpl;
class TaskQueue;
class WebTaskRunnerImpl;
class WebViewSchedulerImpl;

class WebFrameSchedulerImpl : public blink::WebFrameScheduler {
public:
    WebFrameSchedulerImpl(WebViewSchedulerImpl* parent_web_view_scheduler);

    ~WebFrameSchedulerImpl() override;

    // blink::WebFrameScheduler implementation:
    void setFrameVisible(bool frame_visible) override;
    void setPageVisible(bool page_visible) /*override*/;
    RefPtr<blink::WebTaskRunner> loadingTaskRunner() override;
    RefPtr<blink::WebTaskRunner> timerTaskRunner() override;
    RefPtr<blink::WebTaskRunner> unthrottledTaskRunner() override;

    void OnVirtualTimeDomainChanged();

private:
    friend class WebViewSchedulerImpl;

    void DetachFromWebViewScheduler();
    void ApplyPolicyToTimerQueue();

    std::unique_ptr<WebTaskRunnerImpl> loading_web_task_runner_;
    std::unique_ptr<WebTaskRunnerImpl> timer_web_task_runner_;
    RendererSchedulerImpl* renderer_scheduler_; // NOT OWNED
    WebViewSchedulerImpl* parent_web_view_scheduler_; // NOT OWNED

    bool frame_visible_;
    bool page_visible_;

    DISALLOW_COPY_AND_ASSIGN(WebFrameSchedulerImpl);
};

} // namespace scheduler

#endif // COMPONENTS_SCHEDULER_RENDERER_WEB_FRAME_SCHEDULER_IMPL_H_
