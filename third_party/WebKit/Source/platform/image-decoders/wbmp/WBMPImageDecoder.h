/*
 * Copyright (c) 2008, 2009, Google Inc. All rights reserved.
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

#ifndef WBMPImageDecoder_h
#define WBMPImageDecoder_h

//#include "platform/image-decoders/bmp/WBMPImageReader.h"
//#include "wtf/OwnPtr.h"
#include "third_party/WebKit/Source/platform/image-decoders/ImageDecoder.h"

class SkStream;
class SkBitmap;

namespace blink {

// This class decodes the WBMP image format.
class PLATFORM_EXPORT WBMPImageDecoder : public ImageDecoder {
public:
    WBMPImageDecoder(AlphaOption, const ColorBehavior&, size_t maxDecodedBytes);

    static bool matchesBMPSignature(sk_sp<SkData> data);

    // ImageDecoder
    virtual String filenameExtension() const override { return "wbmp"; }
    //virtual bool isSizeAvailable() override;
    //virtual ImageFrame* frameBufferAtIndex(size_t) override;

    virtual void decodeSize() override;
    virtual void decode(size_t) override;

private:
    //void decode(ImageFrame* buffer);
    bool decodeHelper(/*ImageFrame* buffer*/);
    bool onDecode(SkStream* stream, SkBitmap* decodedBitmap, bool decodePixelsMode);

    // The reader used to do most of the WBMP decoding.
    //SkImageDecoder* m_reader;
};

} // namespace WebCore

#endif
