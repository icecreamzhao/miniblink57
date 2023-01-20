/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
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
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
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

#ifndef AudioChannel_h
#define AudioChannel_h

#include "platform/PlatformExport.h"
#include "platform/audio/AudioArray.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

// An AudioChannel represents a buffer of non-interleaved floating-point audio
// samples.
// The PCM samples are normally assumed to be in a nominal range -1.0 -> +1.0
class PLATFORM_EXPORT AudioChannel {
    USING_FAST_MALLOC(AudioChannel);
    WTF_MAKE_NONCOPYABLE(AudioChannel);

public:
    // Memory can be externally referenced, or can be internally allocated with an
    // AudioFloatArray.
=======
#include "wtf/PassOwnPtr.h"

namespace blink {

// An AudioChannel represents a buffer of non-interleaved floating-point audio samples.
// The PCM samples are normally assumed to be in a nominal range -1.0 -> +1.0
class PLATFORM_EXPORT AudioChannel {
    WTF_MAKE_NONCOPYABLE(AudioChannel);
public:
    // Memory can be externally referenced, or can be internally allocated with an AudioFloatArray.
>>>>>>> miniblink49

    // Reference an external buffer.
    AudioChannel(float* storage, size_t length)
        : m_length(length)
        , m_rawPointer(storage)
        , m_silent(false)
    {
    }

    // Manage storage for us.
    explicit AudioChannel(size_t length)
        : m_length(length)
        , m_rawPointer(nullptr)
        , m_silent(true)
    {
<<<<<<< HEAD
        m_memBuffer = WTF::wrapUnique(new AudioFloatArray(length));
=======
        m_memBuffer = adoptPtr(new AudioFloatArray(length));
>>>>>>> miniblink49
    }

    // A "blank" audio channel -- must call set() before it's useful...
    AudioChannel()
        : m_length(0)
        , m_rawPointer(nullptr)
        , m_silent(true)
    {
    }

    // Redefine the memory for this channel.
    // storage represents external memory not managed by this object.
    void set(float* storage, size_t length)
    {
<<<<<<< HEAD
        m_memBuffer.reset(); // cleanup managed storage
=======
        m_memBuffer.clear(); // cleanup managed storage
>>>>>>> miniblink49
        m_rawPointer = storage;
        m_length = length;
        m_silent = false;
    }

    // How many sample-frames do we contain?
    size_t length() const { return m_length; }

    // resizeSmaller() can only be called with a new length <= the current length.
    // The data stored in the bus will remain undisturbed.
    void resizeSmaller(size_t newLength);

    // Direct access to PCM sample data. Non-const accessor clears silent flag.
    float* mutableData()
    {
        clearSilentFlag();
        return m_rawPointer ? m_rawPointer : m_memBuffer->data();
    }

<<<<<<< HEAD
    const float* data() const
    {
        return m_rawPointer ? m_rawPointer : m_memBuffer->data();
    }
=======
    const float* data() const { return m_rawPointer ? m_rawPointer : m_memBuffer->data(); }
>>>>>>> miniblink49

    // Zeroes out all sample values in buffer.
    void zero()
    {
        if (m_silent)
            return;

        m_silent = true;

        if (m_memBuffer.get())
            m_memBuffer->zero();
        else
            memset(m_rawPointer, 0, sizeof(float) * m_length);
    }

    // Clears the silent flag.
    void clearSilentFlag() { m_silent = false; }

    bool isSilent() const { return m_silent; }

    // Scales all samples by the same amount.
    void scale(float scale);

    // A simple memcpy() from the source channel
    void copyFrom(const AudioChannel* sourceChannel);

    // Copies the given range from the source channel.
<<<<<<< HEAD
    void copyFromRange(const AudioChannel* sourceChannel,
        unsigned startFrame,
        unsigned endFrame);
=======
    void copyFromRange(const AudioChannel* sourceChannel, unsigned startFrame, unsigned endFrame);
>>>>>>> miniblink49

    // Sums (with unity gain) from the source channel.
    void sumFrom(const AudioChannel* sourceChannel);

    // Returns maximum absolute value (useful for normalization).
    float maxAbsValue() const;

private:
    size_t m_length;

    float* m_rawPointer;
<<<<<<< HEAD
    std::unique_ptr<AudioFloatArray> m_memBuffer;
=======
    OwnPtr<AudioFloatArray> m_memBuffer;
>>>>>>> miniblink49
    bool m_silent;
};

} // namespace blink

#endif // AudioChannel_h
