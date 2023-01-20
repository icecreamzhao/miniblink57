/*
 * Copyright (C) 2015 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/image-decoders/FastSharedBufferReader.h"

namespace blink {

<<<<<<< HEAD
FastSharedBufferReader::FastSharedBufferReader(PassRefPtr<SegmentReader> data)
=======
FastSharedBufferReader::FastSharedBufferReader(PassRefPtr<SharedBuffer> data)
>>>>>>> miniblink49
    : m_data(data)
    , m_segment(0)
    , m_segmentLength(0)
    , m_dataPosition(0)
{
}

<<<<<<< HEAD
void FastSharedBufferReader::setData(PassRefPtr<SegmentReader> data)
{
    if (data == m_data)
        return;
    m_data = data;
    clearCache();
}

void FastSharedBufferReader::clearCache()
{
    m_segment = 0;
    m_segmentLength = 0;
    m_dataPosition = 0;
}

const char* FastSharedBufferReader::getConsecutiveData(size_t dataPosition,
    size_t length,
    char* buffer) const
=======
const char* FastSharedBufferReader::getConsecutiveData(size_t dataPosition, size_t length, char* buffer)
>>>>>>> miniblink49
{
    RELEASE_ASSERT(dataPosition + length <= m_data->size());

    // Use the cached segment if it can serve the request.
    if (dataPosition >= m_dataPosition && dataPosition + length <= m_dataPosition + m_segmentLength)
        return m_segment + dataPosition - m_dataPosition;

    // Return a pointer into |m_data| if the request doesn't span segments.
    getSomeDataInternal(dataPosition);
    if (length <= m_segmentLength)
        return m_segment;

<<<<<<< HEAD
    for (char* dest = buffer;;) {
=======
    for (char* dest = buffer; ; ) {
>>>>>>> miniblink49
        size_t copy = std::min(length, m_segmentLength);
        memcpy(dest, m_segment, copy);
        length -= copy;
        if (!length)
            return buffer;

        // Continue reading the next segment.
        dest += copy;
        getSomeDataInternal(m_dataPosition + copy);
    }
}

<<<<<<< HEAD
size_t FastSharedBufferReader::getSomeData(const char*& someData,
    size_t dataPosition) const
=======
size_t FastSharedBufferReader::getSomeData(const char*& someData, size_t dataPosition)
>>>>>>> miniblink49
{
    getSomeDataInternal(dataPosition);
    someData = m_segment;
    return m_segmentLength;
}

<<<<<<< HEAD
void FastSharedBufferReader::getSomeDataInternal(size_t dataPosition) const
=======
void FastSharedBufferReader::getSomeDataInternal(unsigned dataPosition)
>>>>>>> miniblink49
{
    m_dataPosition = dataPosition;
    m_segmentLength = m_data->getSomeData(m_segment, dataPosition);
    ASSERT(m_segmentLength);
}

} // namespace blink
