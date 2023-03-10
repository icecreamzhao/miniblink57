// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "modules/webaudio/ScriptProcessorNode.h"
#include "core/testing/DummyPageHolder.h"
#include "modules/webaudio/OfflineAudioContext.h"
#include "testing/gtest/include/gtest/gtest.h"
#include <memory>

namespace blink {

TEST(ScriptProcessorNodeTest, BufferLifetime)
{
    std::unique_ptr<DummyPageHolder> page = DummyPageHolder::create();
    OfflineAudioContext* context = OfflineAudioContext::create(
        &page->document(), 2, 1, 48000, ASSERT_NO_EXCEPTION);
    ScriptProcessorNode* node = context->createScriptProcessor(ASSERT_NO_EXCEPTION);
    ScriptProcessorHandler& handler = static_cast<ScriptProcessorHandler&>(node->handler());
    EXPECT_EQ(2u, handler.m_inputBuffers.size());
    EXPECT_EQ(2u, handler.m_outputBuffers.size());
    BaseAudioContext::AutoLocker locker(context);
    handler.dispose();
    // Buffers should live after dispose() because an audio thread is using
    // them.
    EXPECT_EQ(2u, handler.m_inputBuffers.size());
    EXPECT_EQ(2u, handler.m_outputBuffers.size());
}

} // namespace blink
