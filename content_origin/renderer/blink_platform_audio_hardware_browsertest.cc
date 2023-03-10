// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/public/test/render_view_test.h"
#include "third_party/WebKit/public/platform/Platform.h"

namespace content {

class BlinkPlatformAudioHardwareTest : public RenderViewTest {
protected:
    void SetUp() override { RenderViewTest::SetUp(); }
};

// Test that calling audioHardware functions from blink::Platform without a v8
// context returns valid values.
TEST_F(BlinkPlatformAudioHardwareTest, AudioHardwareFunctionsNoV8)
{
    blink::Platform* blink_platform = blink::Platform::current();
    size_t buffer_size = blink_platform->audioHardwareBufferSize();
    EXPECT_GT(buffer_size, 0u);
    unsigned channels = blink_platform->audioHardwareOutputChannels();
    EXPECT_GT(channels, 0u);
    double sample_rate = blink_platform->audioHardwareSampleRate();
    EXPECT_GT(sample_rate, 0.0);
}

} // namespace content
