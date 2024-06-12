/*
 * Copyright (c) 2015, Tencent Inc. All rights reserved.
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
 *     * Neither the name of debugwang. nor the names of its
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

#include "platform/image-decoders/wbmp/WBMPImageDecoder.h"
#include "config.h"
#include "platform/PlatformInstrumentation.h"
#include "platform/image-decoders/ImageDecoder.h"

#include "SkColor.h"
#include "SkColorPriv.h"
#include "SkMath.h"
#include "SkStream.h"
#include "SkTemplates.h"

namespace blink {

WBMPImageDecoder::WBMPImageDecoder(AlphaOption alphaOption, const ColorBehavior& behavior, size_t maxDecodedBytes)
    : ImageDecoder(alphaOption, behavior, maxDecodedBytes)
{
}

static bool read_byte(SkStream* stream, uint8_t* data)
{
    return stream->read(data, 1) == 1;
}

static bool read_mbf(SkStream* stream, int* value)
{
    int n = 0;
    uint8_t data;
    do {
        if (!read_byte(stream, &data)) {
            return false;
        }
        n = (n << 7) | (data & 0x7F);
    } while (data & 0x80);

    *value = n;
    return true;
}

struct wbmp_head {
    int fWidth;
    int fHeight;

    bool init(SkStream* stream)
    {
        uint8_t data;

        if (!read_byte(stream, &data) || data != 0) { // unknown type
            return false;
        }
        if (!read_byte(stream, &data) || (data & 0x9F)) { // skip fixed header
            return false;
        }
        if (!read_mbf(stream, &fWidth) || (unsigned)fWidth > 0xFFFF) {
            return false;
        }
        if (!read_mbf(stream, &fHeight) || (unsigned)fHeight > 0xFFFF) {
            return false;
        }
        return fWidth != 0 && fHeight != 0;
    }
};

bool WBMPImageDecoder::matchesBMPSignature(/*const SharedBuffer& data*/ sk_sp<SkData> data)
{
    if (!data || data->size() <= 2)
        return false;

    const char* dataPtr = (const char*)data->data();
    if (0 != dataPtr[0] || 0 != dataPtr[1])
        return false;
    SkMemoryStream stream(data->data(), data->size(), false);
    wbmp_head head;
    return head.init(&stream);
}

// bool WBMPImageDecoder::isSizeAvailable()
// {
//     if (!ImageDecoder::isSizeAvailable())
//         frameBufferAtIndex(0); // here will call decode to get info
//
//     return ImageDecoder::isSizeAvailable();
// }

// ImageFrame* WBMPImageDecoder::frameBufferAtIndex(size_t index)
// {
//     if (index)
//         return 0;
//
//     if (m_frameBufferCache.isEmpty()) {
//         m_frameBufferCache.resize(1);
//         m_frameBufferCache.first().setPremultiplyAlpha(m_premultiplyAlpha);
//     }
//
//     ImageFrame* buffer = &m_frameBufferCache.first();
//     if (buffer->status() != ImageFrame::FrameComplete) {
//         PlatformInstrumentation::willDecodeImage("WBMP");
//         decode(buffer);
//         PlatformInstrumentation::didDecodeImage();
//     }
//     return buffer;
// }

void WBMPImageDecoder::decodeSize()
{
    decode(0);
}

void WBMPImageDecoder::decode(size_t)
{
    if (failed())
        return;

    if (!isAllDataReceived())
        return;

    //     if (ImageDecoder::isSizeAvailable())
    //         return;

    // If we couldn't decode the image but we've received all the data, decoding
    // has failed.
    if (!decodeHelper())
        setFailed();
}

bool WBMPImageDecoder::decodeHelper()
{
    if (0 == frameCount())
        return false;
    ImageFrame* buffer = &m_frameBufferCache[0];

    SkBitmap bitmap;
    sk_sp<SkData> skData = m_data->getAsSkData();
    if (!skData)
        return false;
    SkMemoryStream stream(skData->data(), skData->size(), false);

    //m_reader->setPrefConfigTable(gQBDefaultPrefConfigTable);

    if (!onDecode(&stream, &bitmap, true))
        return false;

    int origW = bitmap.width();
    int origH = bitmap.height();

    setSize(origW, origH);
    //buffer->setSize(origW, origH);
    SkBitmap* bufBitmap = (SkBitmap*)(&buffer->bitmap());
    bufBitmap->reset();
    bufBitmap->setInfo(SkImageInfo::MakeN32Premul(origW, origH));
    bufBitmap->allocPixels(buffer->allocator(), 0);
    buffer->zeroFillPixelData();

    bitmap.copyTo(bufBitmap, bufBitmap->colorType(), NULL);
    //     buffer->setSkBitmap(bitmap);
    //     for (int i = 0; i < origW; ++i) {
    //         for (int j = 0; j < origH; ++j) {
    //             SkColor c = bitmap.getColor(i, j);
    //             buffer->setRGBA(i, j, SkColorGetR(c), SkColorGetG(c), SkColorGetB(c), SkColorGetA(c));
    //         }
    //     }

    buffer->setHasAlpha(false);
    buffer->setOriginalFrameRect(IntRect(IntPoint(), IntSize(origW, origH)));
    buffer->setStatus(ImageFrame::FrameComplete);

    return true;
}

static void expand_bits_to_bytes(uint8_t dst[], const uint8_t src[], int bits)
{
    int bytes = bits >> 3;

    for (int i = 0; i < bytes; i++) {
        unsigned mask = *src++;
        dst[0] = (mask >> 7) & 1;
        dst[1] = (mask >> 6) & 1;
        dst[2] = (mask >> 5) & 1;
        dst[3] = (mask >> 4) & 1;
        dst[4] = (mask >> 3) & 1;
        dst[5] = (mask >> 2) & 1;
        dst[6] = (mask >> 1) & 1;
        dst[7] = (mask >> 0) & 1;
        dst += 8;
    }

    bits &= 7;
    if (bits > 0) {
        unsigned mask = *src;
        do {
            *dst++ = (mask >> 7) & 1;
            ;
            mask <<= 1;
        } while (--bits != 0);
    }
}

#define Align8(x) (((x) + 7) & ~7)

bool WBMPImageDecoder::onDecode(SkStream* stream, SkBitmap* decodedBitmap, bool decodePixelsMode)
{
    wbmp_head head;
    if (!head.init(stream))
        return false;

    int width = head.fWidth;
    int height = head.fHeight;

    // assign these directly, in case we return kDimensions_Result
    //decodedBitmap->setConfig(SkBitmap::kIndex8_Config, width, height);
    //decodedBitmap->setAlphaType(kOpaque_SkAlphaType);
    SkImageInfo info = SkImageInfo::Make(width, height, kIndex_8_SkColorType, kOpaque_SkAlphaType);
    decodedBitmap->setInfo(info);

    if (!decodePixelsMode)
        return true;

    const SkPMColor colors[] = { SK_ColorBLACK, SK_ColorWHITE };
    SkColorTable* ct = new SkColorTable(colors, 2);
    SkAutoUnref aur(ct);

    decodedBitmap->allocPixels(0, ct);

    SkAutoLockPixels alp(*decodedBitmap);

    uint8_t* dst = decodedBitmap->getAddr8(0, 0);
    // store the 1-bit valuess at the end of our pixels, so we won't stomp
    // on them before we're read them. Just trying to avoid a temp allocation
    size_t srcRB = Align8(width) >> 3;
    size_t srcSize = height * srcRB;
    uint8_t* src = dst + decodedBitmap->getSize() - srcSize;
    if (stream->read(src, srcSize) != srcSize)
        return false;

    for (int y = 0; y < height; y++) {
        expand_bits_to_bytes(dst, src, width);
        dst += decodedBitmap->rowBytes();
        src += srcRB;
    }

    return true;
}

} // namespace WebCore
