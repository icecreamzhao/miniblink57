// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/webaudio/AudioBasicProcessorHandler.h"
#include "core/testing/DummyPageHolder.h"
#include "modules/webaudio/OfflineAudioContext.h"
#include "platform/audio/AudioProcessor.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "wtf/PtrUtil.h"
#include <memory>
=======
#include "config.h"
#include "modules/webaudio/AudioBasicProcessorHandler.h"

#include "core/testing/DummyPageHolder.h"
#include "modules/webaudio/OfflineAudioContext.h"
#include "platform/audio/AudioProcessor.h"
#include <gtest/gtest.h>
>>>>>>> miniblink49

namespace blink {

class MockAudioProcessor final : public AudioProcessor {
public:
<<<<<<< HEAD
    MockAudioProcessor()
        : AudioProcessor(48000, 2)
    {
    }
=======
    MockAudioProcessor() : AudioProcessor(48000, 2) { }
>>>>>>> miniblink49
    void initialize() override { m_initialized = true; }
    void uninitialize() override { m_initialized = false; }
    void process(const AudioBus*, AudioBus*, size_t) override { }
    void reset() override { }
    void setNumberOfChannels(unsigned) override { }
    unsigned numberOfChannels() const override { return m_numberOfChannels; }
    double tailTime() const override { return 0; }
    double latencyTime() const override { return 0; }
};

class MockProcessorNode final : public AudioNode {
public:
<<<<<<< HEAD
    MockProcessorNode(BaseAudioContext& context)
        : AudioNode(context)
    {
        setHandler(AudioBasicProcessorHandler::create(
            AudioHandler::NodeTypeWaveShaper, *this, 48000,
            WTF::makeUnique<MockAudioProcessor>()));
=======
    MockProcessorNode(AudioContext& context)
        : AudioNode(context)
    {
        setHandler(AudioBasicProcessorHandler::create(AudioHandler::NodeTypeWaveShaper, *this, 48000, adoptPtr(new MockAudioProcessor())));
>>>>>>> miniblink49
        handler().initialize();
    }
};

TEST(AudioBasicProcessorHandlerTest, ProcessorFinalization)
{
<<<<<<< HEAD
    std::unique_ptr<DummyPageHolder> page = DummyPageHolder::create();
    OfflineAudioContext* context = OfflineAudioContext::create(
        &page->document(), 2, 1, 48000, ASSERT_NO_EXCEPTION);
=======
    OwnPtr<DummyPageHolder> page = DummyPageHolder::create();
    OfflineAudioContext* context = OfflineAudioContext::create(&page->document(), 2, 1, 48000, ASSERT_NO_EXCEPTION);
>>>>>>> miniblink49
    MockProcessorNode* node = new MockProcessorNode(*context);
    AudioBasicProcessorHandler& handler = static_cast<AudioBasicProcessorHandler&>(node->handler());
    EXPECT_TRUE(handler.processor());
    EXPECT_TRUE(handler.processor()->isInitialized());
<<<<<<< HEAD
    BaseAudioContext::AutoLocker locker(context);
=======
    AudioContext::AutoLocker locker(context);
>>>>>>> miniblink49
    handler.dispose();
    // The AudioProcessor should live after dispose() and should not be
    // finalized because an audio thread is using it.
    EXPECT_TRUE(handler.processor());
    EXPECT_TRUE(handler.processor()->isInitialized());
}

} // namespace blink
