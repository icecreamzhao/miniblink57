/*
 * Copyright (C) 2006 Apple Computer, Inc.
 * Copyright (C) 2007-2009 Torch Mobile, Inc.
 * Copyright (C) Research In Motion Limited 2009-2010. All rights reserved.
 *
 * Portions are Copyright (C) 2001 mozilla.org
 *
 * Other contributors:
 *   Stuart Parmenter <stuart@mozilla.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Alternatively, the contents of this file may be used under the terms
 * of either the Mozilla Public License Version 1.1, found at
 * http://www.mozilla.org/MPL/ (the "MPL") or the GNU General Public
 * License Version 2.0, found at http://www.fsf.org/copyleft/gpl.html
 * (the "GPL"), in which case the provisions of the MPL or the GPL are
 * applicable instead of those above.  If you wish to allow use of your
 * version of this file only under the terms of one of those two
 * licenses (the MPL or the GPL) and not to allow others to use your
 * version of this file under the LGPL, indicate your decision by
 * deletingthe provisions above and replace them with the notice and
 * other provisions required by the MPL or the GPL, as the case may be.
 * If you do not delete the provisions above, a recipient may use your
 * version of this file under any of the LGPL, the MPL or the GPL.
 */

#include "config.h"

#include "ImageGDIPlusDecoder.h"
#include "wtf/PassRefPtr.h"

#include <windows.h>

#undef min
#undef max
using std::max;
using std::min;
#include <gdiplus.h>

#include "platform/graphics/GDIPlusInit.h"

namespace blink {

static const size_t sizeOfFileHeader = 14;

ImageGDIPlusDecoder::ImageGDIPlusDecoder(
    ImageDecoder::AlphaOption alphaOption,
    const ColorBehavior& colorBehavior,
    GDIPlusDecoderType type,
    size_t maxDecodedBytes)
    : ImageDecoder(alphaOption, colorBehavior, maxDecodedBytes)
    , m_decodedOffset(0)
    , m_type(type)
{
}

ImageGDIPlusDecoder::~ImageGDIPlusDecoder()
{
    m_dummyData.clear();
}

void ImageGDIPlusDecoder::setDataImpl(PassRefPtr<SegmentReader> data, bool allDataReceived)
{
    if (failed())
        return;

    //ImageDecoder::setData(data, allDataReceived);
    if (m_reader)
        m_reader->setData(data.get());
}

void ImageGDIPlusDecoder::onSetData(SegmentReader* data)
{
    if (failed())
        return;

    if (!data) {
        m_dummyData.clear();
        setDataImpl(data, isAllDataReceived());
        return;
    }

    initGDIPlusClsids();

    sk_sp<SkData> skData = data->getAsSkData();

    HGLOBAL hMem = ::GlobalAlloc(GMEM_FIXED, skData->size());
    BYTE* pMem = (BYTE*)::GlobalLock(hMem);
    memcpy(pMem, skData->data(), skData->size());

    IStream* pIStream = 0;
    ::CreateStreamOnHGlobal(hMem, FALSE, &pIStream);

    Gdiplus::Bitmap* pImgBitmap = nullptr;
    char* dummyData = nullptr;
    do {
        pImgBitmap = Gdiplus::Bitmap::FromStream(pIStream);
        if (!pImgBitmap)
            break;

        pIStream->Release();
        HRESULT hr = ::CreateStreamOnHGlobal(NULL, true, &pIStream);
        if (S_OK != hr)
            break;

        pImgBitmap->Save(pIStream, &s_bmpClsid, NULL);

        LARGE_INTEGER liTemp = { 0 };
        pIStream->Seek(liTemp, STREAM_SEEK_SET, NULL);
        DWORD dwSize = 0;
        STATSTG stats = { 0 };
        pIStream->Stat(&stats, 0);
        dwSize = (DWORD)stats.cbSize.QuadPart;

        dummyData = (char*)malloc(dwSize);
        pIStream->Read(dummyData, dwSize, NULL);

        m_dummyData = SharedBuffer::create(dummyData, (size_t)dwSize);
        setDataImpl(SegmentReader::createFromSharedBuffer(m_dummyData), isAllDataReceived());

        decode(true); // to ensure m_reader
    } while (false);

    free(dummyData);
    ::GlobalUnlock(hMem);
    ::GlobalFree(hMem);
    pIStream->Release();
    delete pImgBitmap;
}

bool ImageGDIPlusDecoder::setFailed()
{
    m_reader = nullptr;
    return ImageDecoder::setFailed();
}

void ImageGDIPlusDecoder::decode(bool onlySize)
{
    if (failed())
        return;

    // If we couldn't decode the image but we've received all the data, decoding
    // has failed.
    if (!decodeHelper(onlySize) && isAllDataReceived())
        setFailed();
    // If we're done decoding the image, we don't need the BMPImageReader
    // anymore.  (If we failed, |m_reader| has already been cleared.)
    else if (!m_frameBufferCache.isEmpty() && (m_frameBufferCache.front().getStatus() == ImageFrame::FrameComplete))
        m_reader = nullptr;
}

bool ImageGDIPlusDecoder::decodeHelper(bool onlySize)
{
    size_t imgDataOffset = 0;
    if (!m_data.get() || (m_decodedOffset < sizeOfFileHeader) && !processFileHeader(imgDataOffset))
        return false;

    if (!m_reader) {
        m_reader = std::unique_ptr<BMPImageReader>(new BMPImageReader(this, m_decodedOffset, imgDataOffset, false));
        //m_reader->setForceBitMaskAlpha();
        m_reader->setData(m_data.get());
    }

    if (!m_frameBufferCache.isEmpty())
        m_reader->setBuffer(&m_frameBufferCache.front());

    return m_reader->decodeBMP(onlySize);
}

bool ImageGDIPlusDecoder::processFileHeader(size_t& imgDataOffset)
{
    // Read file header.
    ASSERT(!m_decodedOffset);
    sk_sp<SkData> skData = m_data->getAsSkData();

    if (!skData.get() || skData->size() < sizeOfFileHeader)
        return false;

    const char* data = (const char*)skData->data();
    const uint16_t fileType = (data[0] << 8) | static_cast<uint8_t>(data[1]);
    imgDataOffset = readUint32(10);
    m_decodedOffset = sizeOfFileHeader;

    // See if this is a bitmap filetype we understand.
    enum {
        BMAP = 0x424D, // "BM"
        // The following additional OS/2 2.x header values (see
        // http://www.fileformat.info/format/os2bmp/egff.htm ) aren't widely
        // decoded, and are unlikely to be in much use.
        /*
                    ICON = 0x4943,  // "IC"
                    POINTER = 0x5054,  // "PT"
                    COLORICON = 0x4349,  // "CI"
                    COLORPOINTER = 0x4350,  // "CP"
                    BITMAPARRAY = 0x4241,  // "BA"
                    */
    };
    return (fileType == BMAP) || setFailed();
}

uint32_t ImageGDIPlusDecoder::readUint32(int offset) const
{
    sk_sp<SkData> skData = m_data->getAsSkData();
    return readUint32((const char*)(skData->data()), m_decodedOffset + offset);
}

uint32_t ImageGDIPlusDecoder::readUint32(const char* data, int offset)
{
    uint32_t result;
    memcpy(&result, &data[offset], 4);
#if CPU(BIG_ENDIAN)
    result = ((result & 0xff) << 24) | ((result & 0xff00) << 8) | ((result & 0xff0000) >> 8) | ((result & 0xff000000) >> 24);
#endif
    return result;
}

} // namespace blink
