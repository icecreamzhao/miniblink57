// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/command_line.h"
#include "base/macros.h"
#include "content/browser/webrtc/webrtc_content_browsertest_base.h"
#include "content/public/common/content_switches.h"

namespace {

const char kJavaScriptFeaturesNeeded[] = "--expose-gc";
const char kDataChannelHtmlFile[] = "/media/datachannel_test.html";

} // namespace

namespace content {

// This test is flaky, see https://crbug.com/611620.
class DISABLED_WebRtcDataChannelTest : public WebRtcContentBrowserTestBase {
public:
    DISABLED_WebRtcDataChannelTest() { }
    ~DISABLED_WebRtcDataChannelTest() override { }

    void SetUpCommandLine(base::CommandLine* command_line) override
    {
        WebRtcContentBrowserTestBase::SetUpCommandLine(command_line);
        AppendUseFakeUIForMediaStreamFlag();
        base::CommandLine::ForCurrentProcess()->AppendSwitchASCII(
            switches::kJavaScriptFlags, kJavaScriptFeaturesNeeded);
    }

private:
    DISALLOW_COPY_AND_ASSIGN(DISABLED_WebRtcDataChannelTest);
};

IN_PROC_BROWSER_TEST_F(DISABLED_WebRtcDataChannelTest, DataChannelGC)
{
    MakeTypicalCall("testDataChannelGC();", kDataChannelHtmlFile);
}

} // namespace content
