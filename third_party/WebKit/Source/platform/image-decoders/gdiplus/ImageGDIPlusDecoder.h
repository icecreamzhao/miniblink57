/*
 * Copyright (C) 2013 kingsoft, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef ImageGDIPlusDecoder_h
#define ImageGDIPlusDecoder_h

#include "platform/image-decoders/bmp/BMPImageDecoder.h"

namespace blink {

// This class decodes the PNG image format.
class ImageGDIPlusDecoder : public ImageDecoder {
public:
    enum GDIPlusDecoderType {
        GDIPlusDecoderPNG,
        GDIPlusDecoderJPG
    };

    ImageGDIPlusDecoder(ImageDecoder::AlphaOption, const ColorBehavior& colorBehavior, GDIPlusDecoderType type, size_t maxDecodedBytes);
    virtual ~ImageGDIPlusDecoder();

    String filenameExtension() const override { return "bmp"; }

    virtual void onSetData(SegmentReader* data) override;

    // ImageDecoder:
    // CAUTION: setFailed() deletes |m_reader|.  Be careful to avoid
    // accessing deleted memory, especially when calling this from inside
    // BMPImageReader!
    bool setFailed() override;

protected:
    void setDataImpl(PassRefPtr<SegmentReader> data, bool allDataReceived);

    RefPtr<SharedBuffer> m_dummyData;
    GDIPlusDecoderType m_type;

    // ImageDecoder:
    void decodeSize() override { decode(true); }
    void decode(size_t) override { decode(false); }

    uint32_t readUint32(int offset) const;

    static uint32_t readUint32(const char* data, int offset);

    // Decodes the image.  If |onlySize| is true, stops decoding after
    // calculating the image size. If decoding fails but there is no more
    // data coming, sets the "decode failure" flag.
    void decode(bool onlySize);

    // Decodes the image.  If |onlySize| is true, stops decoding after
    // calculating the image size. Returns whether decoding succeeded.
    bool decodeHelper(bool onlySize);

    // Processes the file header at the beginning of the data.  Sets
    // |imgDataOffset| based on the header contents. Returns true if the
    // file header could be decoded.
    bool processFileHeader(size_t& imgDataOffset);

    // An index into |m_data| representing how much we've already decoded.
    // Note that this only tracks data _this_ class decodes; once the
    // BMPImageReader takes over this will not be updated further.
    size_t m_decodedOffset;

    // The reader used to do most of the BMP decoding.
    std::unique_ptr<BMPImageReader> m_reader;
};

} // namespace blink

#endif // ImageGDIPlusDecoder_h