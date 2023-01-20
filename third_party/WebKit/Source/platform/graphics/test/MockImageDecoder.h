/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef MockImageDecoder_h

#include "platform/image-decoders/ImageDecoder.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
#include <memory>
=======
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49

namespace blink {

class MockImageDecoderClient {
public:
<<<<<<< HEAD
    MockImageDecoderClient()
        : m_firstFrameForcedToBeEmpty(false)
    {
    }

=======
>>>>>>> miniblink49
    virtual void decoderBeingDestroyed() = 0;
    virtual void decodeRequested() = 0;
    virtual ImageFrame::Status status() = 0;
    virtual size_t frameCount() = 0;
    virtual int repetitionCount() const = 0;
    virtual float frameDuration() const = 0;
<<<<<<< HEAD
    virtual void clearCacheExceptFrameRequested(size_t) {};
=======
>>>>>>> miniblink49

    // Clients can control the behavior of MockImageDecoder::decodedSize() by
    // overriding this method. The default implementation causes
    // MockImageDecoder::decodedSize() to return the same thing as
    // MockImageDecoder::size(). See the precise implementation of
    // MockImageDecoder::decodedSize() below.
    virtual IntSize decodedSize() const { return IntSize(); }
<<<<<<< HEAD

    void forceFirstFrameToBeEmpty() { m_firstFrameForcedToBeEmpty = true; };

    bool firstFrameForcedToBeEmpty() const { return m_firstFrameForcedToBeEmpty; }

private:
    bool m_firstFrameForcedToBeEmpty;
=======
>>>>>>> miniblink49
};

class MockImageDecoder : public ImageDecoder {
public:
<<<<<<< HEAD
    static std::unique_ptr<MockImageDecoder> create(
        MockImageDecoderClient* client)
    {
        return WTF::makeUnique<MockImageDecoder>(client);
    }

    MockImageDecoder(MockImageDecoderClient* client)
        : ImageDecoder(AlphaPremultiplied,
            ColorBehavior::transformToTargetForTesting(),
            noDecodedImageByteLimit)
        , m_client(client)
    {
    }

    ~MockImageDecoder() { m_client->decoderBeingDestroyed(); }
=======
    static PassOwnPtr<MockImageDecoder> create(MockImageDecoderClient* client) { return adoptPtr(new MockImageDecoder(client)); }

    MockImageDecoder(MockImageDecoderClient* client)
        : ImageDecoder(ImageSource::AlphaPremultiplied, ImageSource::GammaAndColorProfileApplied, noDecodedImageByteLimit)
        , m_client(client)
    { }

    ~MockImageDecoder()
    {
        m_client->decoderBeingDestroyed();
    }
>>>>>>> miniblink49

    IntSize decodedSize() const override
    {
        return m_client->decodedSize().isEmpty() ? size() : m_client->decodedSize();
    }

<<<<<<< HEAD
    String filenameExtension() const override { return "mock"; }

    int repetitionCount() const override { return m_client->repetitionCount(); }
=======
    String filenameExtension() const override
    {
        return "mock";
    }

    int repetitionCount() const override
    {
        return m_client->repetitionCount();
    }
>>>>>>> miniblink49

    bool frameIsCompleteAtIndex(size_t) const override
    {
        return m_client->status() == ImageFrame::FrameComplete;
    }

    float frameDurationAtIndex(size_t) const override
    {
        return m_client->frameDuration();
    }

<<<<<<< HEAD
    size_t clearCacheExceptFrame(size_t clearExceptFrame) override
    {
        m_client->clearCacheExceptFrameRequested(clearExceptFrame);
        return 0;
    }

    size_t frameBytesAtIndex(size_t index) const override
    {
        if (m_client->firstFrameForcedToBeEmpty() && index == 0)
            return 0;
        return ImageDecoder::frameBytesAtIndex(index);
    }
=======
    size_t clearCacheExceptFrame(size_t) override { return 0; }
>>>>>>> miniblink49

private:
    void decodeSize() override { }

    size_t decodeFrameCount() override { return m_client->frameCount(); }

    void decode(size_t index) override
    {
        m_client->decodeRequested();
        m_frameBufferCache[index].setStatus(m_client->status());
    }

    void initializeNewFrame(size_t index) override
    {
<<<<<<< HEAD
        m_frameBufferCache[index].setSizeAndColorSpace(
            size().width(), size().height(), colorSpaceForSkImages());
=======
        m_frameBufferCache[index].setSize(size().width(), size().height());
>>>>>>> miniblink49
        m_frameBufferCache[index].setHasAlpha(false);
    }

    MockImageDecoderClient* m_client;
};

class MockImageDecoderFactory : public ImageDecoderFactory {
public:
<<<<<<< HEAD
    static std::unique_ptr<MockImageDecoderFactory> create(
        MockImageDecoderClient* client,
        const SkISize& decodedSize)
    {
        return WTF::wrapUnique(new MockImageDecoderFactory(
            client, IntSize(decodedSize.width(), decodedSize.height())));
    }

    static std::unique_ptr<MockImageDecoderFactory> create(
        MockImageDecoderClient* client,
        const IntSize& decodedSize)
    {
        return WTF::wrapUnique(new MockImageDecoderFactory(client, decodedSize));
    }

    std::unique_ptr<ImageDecoder> create() override
    {
        std::unique_ptr<MockImageDecoder> decoder = MockImageDecoder::create(m_client);
        decoder->setSize(m_decodedSize.width(), m_decodedSize.height());
        return std::move(decoder);
    }

private:
    MockImageDecoderFactory(MockImageDecoderClient* client,
        const IntSize& decodedSize)
=======
    static PassOwnPtr<MockImageDecoderFactory> create(MockImageDecoderClient* client, const SkISize& decodedSize)
    {
        return adoptPtr(new MockImageDecoderFactory(client, IntSize(decodedSize.width(), decodedSize.height())));
    }

    static PassOwnPtr<MockImageDecoderFactory> create(MockImageDecoderClient* client, const IntSize& decodedSize)
    {
        return adoptPtr(new MockImageDecoderFactory(client, decodedSize));
    }

    PassOwnPtr<ImageDecoder> create() override
    {
        OwnPtr<MockImageDecoder> decoder = MockImageDecoder::create(m_client);
        decoder->setSize(m_decodedSize.width(), m_decodedSize.height());
        return decoder.release();
    }

private:
    MockImageDecoderFactory(MockImageDecoderClient* client, const IntSize& decodedSize)
>>>>>>> miniblink49
        : m_client(client)
        , m_decodedSize(decodedSize)
    {
    }

    MockImageDecoderClient* m_client;
    IntSize m_decodedSize;
};

} // namespace blink

#endif // MockImageDecoder_h
