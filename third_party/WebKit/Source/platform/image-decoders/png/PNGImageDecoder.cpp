/*
 * Copyright (C) 2006 Apple Computer, Inc.
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
<<<<<<< HEAD
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
=======
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
>>>>>>> miniblink49
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

<<<<<<< HEAD
#include "platform/image-decoders/png/PNGImageDecoder.h"

#include "platform/image-decoders/png/PNGImageReader.h"
#include "third_party/libpng/png.h"

#include "third_party/skia/include/core/SkPoint3.h"
#include "third_party/skia/include/core/SkMatrix.h"
#include "third_party/skia/include/core/SkMatrix44.h"
//#include "third_party/skia/include/third_party/skcms/skcms.h"
#include <float.h>

#include "wtf/PtrUtil.h"
#include <memory>


struct SK_API SkColorSpaceTransferFn {
    float fG;
    float fA;
    float fB;
    float fC;
    float fD;
    float fE;
    float fF;
};

/**
*  Describes a color gamut with primaries and a white point.
*/
struct SK_API SkColorSpacePrimaries {
    float fRX, fRY;
    float fGX, fGY;
    float fBX, fBY;
    float fWX, fWY;

    /**
    *  Convert primaries and a white point to a toXYZD50 matrix, the preferred color gamut
    *  representation of SkColorSpace.
    */
    bool toXYZD50(SkMatrix44* toXYZD50) const;
};

static inline float add_epsilon(float v)
{
    return v + FLT_MIN;
}

static inline bool is_zero_to_one(float v)
{
    // Because we allow a value just barely larger than 1, the client can use an
    // entirely linear transfer function.
    return (0.0f <= v) && (v <= add_epsilon(1.0f));
}

bool SkColorSpacePrimaries::toXYZD50(SkMatrix44* toXYZ_D50) const
{
    if (!is_zero_to_one(fRX) || !is_zero_to_one(fRY) ||
        !is_zero_to_one(fGX) || !is_zero_to_one(fGY) ||
        !is_zero_to_one(fBX) || !is_zero_to_one(fBY) ||
        !is_zero_to_one(fWX) || !is_zero_to_one(fWY)) {
        return false;
    }

    // First, we need to convert xy values (primaries) to XYZ.
    SkMatrix primaries;
    primaries.setAll(fRX, fGX, fBX,
        fRY, fGY, fBY,
        1.0f - fRX - fRY, 1.0f - fGX - fGY, 1.0f - fBX - fBY);
    SkMatrix primariesInv;
    if (!primaries.invert(&primariesInv)) {
        return false;
    }

    // Assumes that Y is 1.0f.
    SkVector3 wXYZ = SkVector3::Make(fWX / fWY, 1.0f, (1.0f - fWX - fWY) / fWY);
    SkVector3 XYZ;
    XYZ.fX = primariesInv[0] * wXYZ.fX + primariesInv[1] * wXYZ.fY + primariesInv[2] * wXYZ.fZ;
    XYZ.fY = primariesInv[3] * wXYZ.fX + primariesInv[4] * wXYZ.fY + primariesInv[5] * wXYZ.fZ;
    XYZ.fZ = primariesInv[6] * wXYZ.fX + primariesInv[7] * wXYZ.fY + primariesInv[8] * wXYZ.fZ;
    SkMatrix toXYZ;
    toXYZ.setAll(XYZ.fX, 0.0f, 0.0f,
        0.0f, XYZ.fY, 0.0f,
        0.0f, 0.0f, XYZ.fZ);
    toXYZ.postConcat(primaries);

    // Now convert toXYZ matrix to toXYZD50.
    SkVector3 wXYZD50 = SkVector3::Make(0.96422f, 1.0f, 0.82521f);

    // Calculate the chromatic adaptation matrix.  We will use the Bradford method, thus
    // the matrices below.  The Bradford method is used by Adobe and is widely considered
    // to be the best.
    SkMatrix mA, mAInv;
    mA.setAll(+0.8951f, +0.2664f, -0.1614f,
        -0.7502f, +1.7135f, +0.0367f,
        +0.0389f, -0.0685f, +1.0296f);
    mAInv.setAll(+0.9869929f, -0.1470543f, +0.1599627f,
        +0.4323053f, +0.5183603f, +0.0492912f,
        -0.0085287f, +0.0400428f, +0.9684867f);

    SkVector3 srcCone;
    srcCone.fX = mA[0] * wXYZ.fX + mA[1] * wXYZ.fY + mA[2] * wXYZ.fZ;
    srcCone.fY = mA[3] * wXYZ.fX + mA[4] * wXYZ.fY + mA[5] * wXYZ.fZ;
    srcCone.fZ = mA[6] * wXYZ.fX + mA[7] * wXYZ.fY + mA[8] * wXYZ.fZ;
    SkVector3 dstCone;
    dstCone.fX = mA[0] * wXYZD50.fX + mA[1] * wXYZD50.fY + mA[2] * wXYZD50.fZ;
    dstCone.fY = mA[3] * wXYZD50.fX + mA[4] * wXYZD50.fY + mA[5] * wXYZD50.fZ;
    dstCone.fZ = mA[6] * wXYZD50.fX + mA[7] * wXYZD50.fY + mA[8] * wXYZD50.fZ;

    SkMatrix DXToD50;
    DXToD50.setIdentity();
    DXToD50[0] = dstCone.fX / srcCone.fX;
    DXToD50[4] = dstCone.fY / srcCone.fY;
    DXToD50[8] = dstCone.fZ / srcCone.fZ;
    DXToD50.postConcat(mAInv);
    DXToD50.preConcat(mA);

    toXYZ.postConcat(DXToD50);
    toXYZ_D50->set3x3(toXYZ[0], toXYZ[3], toXYZ[6],
        toXYZ[1], toXYZ[4], toXYZ[7],
        toXYZ[2], toXYZ[5], toXYZ[8]);
    return true;
}

namespace blink {

PNGImageDecoder::PNGImageDecoder(AlphaOption alphaOption,
    const ColorBehavior& colorBehavior,
    size_t maxDecodedBytes,
    size_t offset)
    : ImageDecoder(alphaOption, colorBehavior, maxDecodedBytes)
    , m_offset(offset)
{
}

PNGImageDecoder::~PNGImageDecoder() { }

inline float pngFixedToFloat(png_fixed_point x)
{
    return ((float)x) * 0.00001f;
}

inline sk_sp<SkColorSpace> readColorSpace(png_structp png, png_infop info)
{
    if (png_get_valid(png, info, PNG_INFO_sRGB)) {
        return SkColorSpace::MakeNamed(SkColorSpace::kSRGB_Named);
    }

//     png_charp name = nullptr;
//     int compression = 0;
//     png_bytep profile = nullptr;
//     png_uint_32 length = 0;
//     if (png_get_iCCP(png, info, &name, &compression, &profile, &length)) {
//         return SkColorSpace::NewICC(profile, length);
//     }
// 
//     png_fixed_point chrm[8];
//     if (png_get_cHRM_fixed(png, info, &chrm[0], &chrm[1], &chrm[2], &chrm[3], &chrm[4], &chrm[5], &chrm[6], &chrm[7])) {
//         SkColorSpacePrimaries primaries;
//         primaries.fRX = pngFixedToFloat(chrm[2]);
//         primaries.fRY = pngFixedToFloat(chrm[3]);
//         primaries.fGX = pngFixedToFloat(chrm[4]);
//         primaries.fGY = pngFixedToFloat(chrm[5]);
//         primaries.fBX = pngFixedToFloat(chrm[6]);
//         primaries.fBY = pngFixedToFloat(chrm[7]);
//         primaries.fWX = pngFixedToFloat(chrm[0]);
//         primaries.fWY = pngFixedToFloat(chrm[1]);
// 
//         SkMatrix44 toXYZD50(SkMatrix44::kUninitialized_Constructor);
//         if (primaries.toXYZD50(&toXYZD50)) {
//             png_fixed_point gammaFixed;
//             if (PNG_INFO_gAMA == png_get_gAMA_fixed(png, info, &gammaFixed)) {
//                 SkColorSpaceTransferFn fn;
//                 fn.fA = 1.0f;
//                 fn.fB = fn.fC = fn.fD = fn.fE = fn.fF = 0.0f;
//                 // This is necessary because the gAMA chunk actually stores 1/gamma.
//                 fn.fG = 1.0f / pngFixedToFloat(gammaFixed);
//                 return SkColorSpace::MakeRGB(fn, toXYZD50);
//             }
// 
//             // Note that we only use the cHRM tag when gAMA is present.  The
//             // specification states that the cHRM is valid even without a gAMA
//             // tag, but we cannot apply the cHRM without guessing a transfer
//             // function.  It's possible that we should guess sRGB transfer
//             // function, given that unmarked PNGs should be treated as sRGB.
//             // However, the current behavior matches Safari and Firefox.
//         }
//     }

    return nullptr;
}

=======
#include "config.h"
#include "platform/image-decoders/png/PNGImageDecoder.h"

#include "wtf/PassOwnPtr.h"

#include "libpng/png.h"
#if !defined(PNG_LIBPNG_VER_MAJOR) || !defined(PNG_LIBPNG_VER_MINOR)
#error version error: compile against a versioned libpng.
#endif
#if USE(QCMSLIB)
#include "qcms.h"
#endif

#if PNG_LIBPNG_VER_MAJOR > 1 || (PNG_LIBPNG_VER_MAJOR == 1 && PNG_LIBPNG_VER_MINOR >= 4)
#define JMPBUF(png_ptr) png_jmpbuf(png_ptr)
#else
#define JMPBUF(png_ptr) png_ptr->jmpbuf
#endif

namespace {

inline blink::PNGImageDecoder* imageDecoder(png_structp png)
{
    return static_cast<blink::PNGImageDecoder*>(png_get_progressive_ptr(png));
}

void PNGAPI pngHeaderAvailable(png_structp png, png_infop)
{
    imageDecoder(png)->headerAvailable();
}

void PNGAPI pngRowAvailable(png_structp png, png_bytep row, png_uint_32 rowIndex, int state)
{
    imageDecoder(png)->rowAvailable(row, rowIndex, state);
}

void PNGAPI pngComplete(png_structp png, png_infop)
{
    imageDecoder(png)->complete();
}

void PNGAPI pngFailed(png_structp png, png_const_charp)
{
    longjmp(JMPBUF(png), 1);
}

} // anonymous

namespace blink {

class PNGImageReader {
    WTF_MAKE_FAST_ALLOCATED(PNGImageReader);
public:
    PNGImageReader(PNGImageDecoder* decoder)
        : m_decoder(decoder)
        , m_readOffset(0)
        , m_currentBufferSize(0)
        , m_decodingSizeOnly(false)
        , m_hasAlpha(false)
#if USE(QCMSLIB)
        , m_transform(0)
        , m_rowBuffer()
#endif
    {
        m_png = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, pngFailed, 0);
        m_info = png_create_info_struct(m_png);
        png_set_progressive_read_fn(m_png, m_decoder, pngHeaderAvailable, pngRowAvailable, pngComplete);
    }

    ~PNGImageReader()
    {
        close();
    }

    void close()
    {
        if (m_png && m_info)
            // This will zero the pointers.
            png_destroy_read_struct(&m_png, &m_info, 0);
#if USE(QCMSLIB)
        clearColorTransform();
#endif
        m_readOffset = 0;
    }

    bool decode(const SharedBuffer& data, bool sizeOnly)
    {
        m_decodingSizeOnly = sizeOnly;

        // We need to do the setjmp here. Otherwise bad things will happen.
        if (setjmp(JMPBUF(m_png)))
            return m_decoder->setFailed();

        const char* segment;
        while (unsigned segmentLength = data.getSomeData(segment, m_readOffset)) {
            m_readOffset += segmentLength;
            m_currentBufferSize = m_readOffset;
            png_process_data(m_png, m_info, reinterpret_cast<png_bytep>(const_cast<char*>(segment)), segmentLength);
            if (sizeOnly ? m_decoder->isDecodedSizeAvailable() : m_decoder->frameIsCompleteAtIndex(0))
                return true;
        }

        return false;
    }

    png_structp pngPtr() const { return m_png; }
    png_infop infoPtr() const { return m_info; }

    void setReadOffset(unsigned offset) { m_readOffset = offset; }
    unsigned currentBufferSize() const { return m_currentBufferSize; }
    bool decodingSizeOnly() const { return m_decodingSizeOnly; }
    void setHasAlpha(bool hasAlpha) { m_hasAlpha = hasAlpha; }
    bool hasAlpha() const { return m_hasAlpha; }

    png_bytep interlaceBuffer() const { return m_interlaceBuffer.get(); }
    void createInterlaceBuffer(int size) { m_interlaceBuffer = adoptArrayPtr(new png_byte[size]); }
#if USE(QCMSLIB)
    png_bytep rowBuffer() const { return m_rowBuffer.get(); }
    void createRowBuffer(int size) { m_rowBuffer = adoptArrayPtr(new png_byte[size]); }
    qcms_transform* colorTransform() const { return m_transform; }

    void clearColorTransform()
    {
        if (m_transform)
            qcms_transform_release(m_transform);
        m_transform = 0;
    }

    void createColorTransform(const ColorProfile& colorProfile, bool hasAlpha, bool sRGB)
    {
        clearColorTransform();

        if (colorProfile.isEmpty() && !sRGB)
            return;
        qcms_profile* deviceProfile = ImageDecoder::qcmsOutputDeviceProfile();
        if (!deviceProfile)
            return;
        qcms_profile* inputProfile = 0;
        if (!colorProfile.isEmpty())
            inputProfile = qcms_profile_from_memory(colorProfile.data(), colorProfile.size());
        else
            inputProfile = qcms_profile_sRGB();
        if (!inputProfile)
            return;
        // We currently only support color profiles for RGB and RGBA images.
        ASSERT(rgbData == qcms_profile_get_color_space(inputProfile));
        qcms_data_type dataFormat = hasAlpha ? QCMS_DATA_RGBA_8 : QCMS_DATA_RGB_8;
        // FIXME: Don't force perceptual intent if the image profile contains an intent.
        m_transform = qcms_transform_create(inputProfile, dataFormat, deviceProfile, dataFormat, QCMS_INTENT_PERCEPTUAL);
        qcms_profile_release(inputProfile);
    }
#endif

private:
    png_structp m_png;
    png_infop m_info;
    PNGImageDecoder* m_decoder;
    unsigned m_readOffset;
    unsigned m_currentBufferSize;
    bool m_decodingSizeOnly;
    bool m_hasAlpha;
    OwnPtr<png_byte[]> m_interlaceBuffer;
#if USE(QCMSLIB)
    qcms_transform* m_transform;
    OwnPtr<png_byte[]> m_rowBuffer;
#endif
};

PNGImageDecoder::PNGImageDecoder(ImageSource::AlphaOption alphaOption, ImageSource::GammaAndColorProfileOption colorOptions, size_t maxDecodedBytes)
    : ImageDecoder(alphaOption, colorOptions, maxDecodedBytes)
    , m_hasColorProfile(false)
{
}

PNGImageDecoder::~PNGImageDecoder()
{
}

#if USE(QCMSLIB)
static void getColorProfile(png_structp png, png_infop info, ColorProfile& colorProfile, bool& sRGB)
{
#ifdef PNG_iCCP_SUPPORTED
    ASSERT(colorProfile.isEmpty());
    if (png_get_valid(png, info, PNG_INFO_sRGB)) {
        sRGB = true;
        return;
    }

    char* profileName;
    int compressionType;
#if (PNG_LIBPNG_VER < 10500)
    png_charp profile;
#else
    png_bytep profile;
#endif
    png_uint_32 profileLength;
    if (!png_get_iCCP(png, info, &profileName, &compressionType, &profile, &profileLength))
        return;

    // Only accept RGB color profiles from input class devices.
    bool ignoreProfile = false;
    char* profileData = reinterpret_cast<char*>(profile);
    if (profileLength < ImageDecoder::iccColorProfileHeaderLength)
        ignoreProfile = true;
    else if (!ImageDecoder::rgbColorProfile(profileData, profileLength))
        ignoreProfile = true;
    else if (!ImageDecoder::inputDeviceColorProfile(profileData, profileLength))
        ignoreProfile = true;

    if (!ignoreProfile)
        colorProfile.append(profileData, profileLength);
#endif
}
#endif

>>>>>>> miniblink49
void PNGImageDecoder::headerAvailable()
{
    png_structp png = m_reader->pngPtr();
    png_infop info = m_reader->infoPtr();
    png_uint_32 width = png_get_image_width(png, info);
    png_uint_32 height = png_get_image_height(png, info);

    // Protect against large PNGs. See http://bugzil.la/251381 for more details.
    const unsigned long maxPNGSize = 1000000UL;
    if (width > maxPNGSize || height > maxPNGSize) {
        longjmp(JMPBUF(png), 1);
        return;
    }

    // Set the image size now that the image header is available.
    if (!setSize(width, height)) {
        longjmp(JMPBUF(png), 1);
        return;
    }

    int bitDepth, colorType, interlaceType, compressionType, filterType, channels;
<<<<<<< HEAD
    png_get_IHDR(png, info, &width, &height, &bitDepth, &colorType,
        &interlaceType, &compressionType, &filterType);
=======
    png_get_IHDR(png, info, &width, &height, &bitDepth, &colorType, &interlaceType, &compressionType, &filterType);
>>>>>>> miniblink49

    // The options we set here match what Mozilla does.

    // Expand to ensure we use 24-bit for RGB and 32-bit for RGBA.
    if (colorType == PNG_COLOR_TYPE_PALETTE || (colorType == PNG_COLOR_TYPE_GRAY && bitDepth < 8))
        png_set_expand(png);

    png_bytep trns = 0;
    int trnsCount = 0;
    if (png_get_valid(png, info, PNG_INFO_tRNS)) {
        png_get_tRNS(png, info, &trns, &trnsCount, 0);
        png_set_expand(png);
    }

    if (bitDepth == 16)
        png_set_strip_16(png);

    if (colorType == PNG_COLOR_TYPE_GRAY || colorType == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(png);

<<<<<<< HEAD
    if ((colorType & PNG_COLOR_MASK_COLOR) && !ignoresColorSpace()) {
        // We only support color profiles for color PALETTE and RGB[A] PNG.
        // Supporting color profiles for gray-scale images is slightly tricky, at
        // least using the CoreGraphics ICC library, because we expand gray-scale
        // images to RGB but we do not similarly transform the color profile. We'd
        // either need to transform the color profile or we'd need to decode into a
        // gray-scale image buffer and hand that to CoreGraphics.
        sk_sp<SkColorSpace> colorSpace = readColorSpace(png, info);
        if (colorSpace) {
            setEmbeddedColorSpace(colorSpace);
        }
    }

    if (!hasEmbeddedColorSpace()) {
        // TODO (msarett):
        // Applying the transfer function (gamma) should be handled by
        // SkColorSpaceXform.  Here we always convert to a transfer function that
        // is a 2.2 exponential.  This is a little strange given that the dst
        // transfer function is not necessarily a 2.2 exponential.
        // TODO (msarett):
        // Often, PNGs that specify their transfer function with the gAMA tag will
        // also specify their gamut with the cHRM tag.  We should read this tag
        // and do a full color space transformation if it is present.
        const double inverseGamma = 0.45455;
        const double defaultGamma = 2.2;
        double gamma;
        if (!ignoresColorSpace() && png_get_gAMA(png, info, &gamma)) {
=======
#if USE(QCMSLIB)
    if ((colorType & PNG_COLOR_MASK_COLOR) && !m_ignoreGammaAndColorProfile) {
        // We only support color profiles for color PALETTE and RGB[A] PNG. Supporting
        // color profiles for gray-scale images is slightly tricky, at least using the
        // CoreGraphics ICC library, because we expand gray-scale images to RGB but we
        // do not similarly transform the color profile. We'd either need to transform
        // the color profile or we'd need to decode into a gray-scale image buffer and
        // hand that to CoreGraphics.
        bool sRGB = false;
        ColorProfile colorProfile;
        getColorProfile(png, info, colorProfile, sRGB);
        bool imageHasAlpha = (colorType & PNG_COLOR_MASK_ALPHA) || trnsCount;
        m_reader->createColorTransform(colorProfile, imageHasAlpha, sRGB);
        m_hasColorProfile = !!m_reader->colorTransform();
    }
#endif

    if (!m_hasColorProfile) {
        // Deal with gamma and keep it under our control.
        const double inverseGamma = 0.45455;
        const double defaultGamma = 2.2;
        double gamma;
        if (!m_ignoreGammaAndColorProfile && png_get_gAMA(png, info, &gamma)) {
>>>>>>> miniblink49
            const double maxGamma = 21474.83;
            if ((gamma <= 0.0) || (gamma > maxGamma)) {
                gamma = inverseGamma;
                png_set_gAMA(png, info, gamma);
            }
            png_set_gamma(png, defaultGamma, gamma);
        } else {
            png_set_gamma(png, defaultGamma, inverseGamma);
        }
    }

    // Tell libpng to send us rows for interlaced pngs.
    if (interlaceType == PNG_INTERLACE_ADAM7)
        png_set_interlace_handling(png);

    // Update our info now.
    png_read_update_info(png, info);
    channels = png_get_channels(png, info);
    ASSERT(channels == 3 || channels == 4);

    m_reader->setHasAlpha(channels == 4);

    if (m_reader->decodingSizeOnly()) {
<<<<<<< HEAD
// If we only needed the size, halt the reader.
#if PNG_LIBPNG_VER_MAJOR > 1 || (PNG_LIBPNG_VER_MAJOR == 1 && PNG_LIBPNG_VER_MINOR >= 5)
        // Passing '0' tells png_process_data_pause() not to cache unprocessed data.
=======
        // If we only needed the size, halt the reader.
#if PNG_LIBPNG_VER_MAJOR > 1 || (PNG_LIBPNG_VER_MAJOR == 1 && PNG_LIBPNG_VER_MINOR >= 5)
        // '0' argument to png_process_data_pause means: Do not cache unprocessed data.
>>>>>>> miniblink49
        m_reader->setReadOffset(m_reader->currentBufferSize() - png_process_data_pause(png, 0));
#else
        m_reader->setReadOffset(m_reader->currentBufferSize() - png->buffer_size);
        png->buffer_size = 0;
#endif
    }
}

void PNGImageDecoder::rowAvailable(unsigned char* rowBuffer, unsigned rowIndex, int)
{
    if (m_frameBufferCache.isEmpty())
        return;

    // Initialize the framebuffer if needed.
    ImageFrame& buffer = m_frameBufferCache[0];
<<<<<<< HEAD
    if (buffer.getStatus() == ImageFrame::FrameEmpty) {
        png_structp png = m_reader->pngPtr();
        if (!buffer.setSizeAndColorSpace(size().width(), size().height(),
                colorSpaceForSkImages())) {
=======
    if (buffer.status() == ImageFrame::FrameEmpty) {
        png_structp png = m_reader->pngPtr();
        if (!buffer.setSize(size().width(), size().height())) {
>>>>>>> miniblink49
            longjmp(JMPBUF(png), 1);
            return;
        }

        unsigned colorChannels = m_reader->hasAlpha() ? 4 : 3;
        if (PNG_INTERLACE_ADAM7 == png_get_interlace_type(png, m_reader->infoPtr())) {
            m_reader->createInterlaceBuffer(colorChannels * size().width() * size().height());
            if (!m_reader->interlaceBuffer()) {
                longjmp(JMPBUF(png), 1);
                return;
            }
        }

<<<<<<< HEAD
=======
#if USE(QCMSLIB)
        if (m_reader->colorTransform()) {
            m_reader->createRowBuffer(colorChannels * size().width());
            if (!m_reader->rowBuffer()) {
                longjmp(JMPBUF(png), 1);
                return;
            }
        }
#endif
>>>>>>> miniblink49
        buffer.setStatus(ImageFrame::FramePartial);
        buffer.setHasAlpha(false);

        // For PNGs, the frame always fills the entire image.
        buffer.setOriginalFrameRect(IntRect(IntPoint(), size()));
    }

    /* libpng comments (here to explain what follows).
     *
     * this function is called for every row in the image. If the
     * image is interlacing, and you turned on the interlace handler,
     * this function will be called for every row in every pass.
     * Some of these rows will not be changed from the previous pass.
     * When the row is not changed, the new_row variable will be NULL.
     * The rows and passes are called in order, so you don't really
     * need the row_num and pass, but I'm supplying them because it
     * may make your life easier.
     */

    // Nothing to do if the row is unchanged, or the row is outside
    // the image bounds: libpng may send extra rows, ignore them to
    // make our lives easier.
    if (!rowBuffer)
        return;
    int y = rowIndex;
    if (y < 0 || y >= size().height())
        return;

    /* libpng comments (continued).
     *
     * For the non-NULL rows of interlaced images, you must call
     * png_progressive_combine_row() passing in the row and the
     * old row.  You can call this function for NULL rows (it will
     * just return) and for non-interlaced images (it just does the
     * memcpy for you) if it will make the code easier. Thus, you
     * can just do this for all cases:
     *
     *    png_progressive_combine_row(png_ptr, old_row, new_row);
     *
     * where old_row is what was displayed for previous rows. Note
     * that the first pass (pass == 0 really) will completely cover
     * the old row, so the rows do not have to be initialized. After
     * the first pass (and only for interlaced images), you will have
     * to pass the current row, and the function will combine the
     * old row and the new row.
     */

    bool hasAlpha = m_reader->hasAlpha();
    png_bytep row = rowBuffer;

    if (png_bytep interlaceBuffer = m_reader->interlaceBuffer()) {
        unsigned colorChannels = hasAlpha ? 4 : 3;
        row = interlaceBuffer + (rowIndex * colorChannels * size().width());
        png_progressive_combine_row(m_reader->pngPtr(), row, rowBuffer);
    }

<<<<<<< HEAD
    // Write the decoded row pixels to the frame buffer. The repetitive
    // form of the row write loops is for speed.
    ImageFrame::PixelData* const dstRow = buffer.getAddr(0, y);
    unsigned alphaMask = 255;
    int width = size().width();

    png_bytep srcPtr = row;
    if (hasAlpha) {
        // Here we apply the color space transformation to the dst space.
        // It does not really make sense to transform to a gamma-encoded
        // space and then immediately after, perform a linear premultiply.
        // Ideally we would pass kPremul_SkAlphaType to xform->apply(),
        // instructing SkColorSpaceXform to perform the linear premultiply
        // while the pixels are a linear space.
        // We cannot do this because when we apply the gamma encoding after
        // the premultiply, we will very likely end up with valid pixels
        // where R, G, and/or B are greater than A.  The legacy drawing
        // pipeline does not know how to handle this.
//         if (SkColorSpaceXform* xform = colorTransform()) {
//             SkColorSpaceXform::ColorFormat colorFormat = SkColorSpaceXform::kRGBA_8888_ColorFormat;
//             xform->apply(colorFormat, dstRow, colorFormat, srcPtr, size().width(), kUnpremul_SkAlphaType);
//             srcPtr = (png_bytep)dstRow;
//         }

        if (buffer.premultiplyAlpha()) {
            for (auto* dstPixel = dstRow; dstPixel < dstRow + width;
                 dstPixel++, srcPtr += 4) {
                buffer.setRGBAPremultiply(dstPixel, srcPtr[0], srcPtr[1], srcPtr[2],
                    srcPtr[3]);
                alphaMask &= srcPtr[3];
            }
        } else {
            for (auto* dstPixel = dstRow; dstPixel < dstRow + width;
                 dstPixel++, srcPtr += 4) {
                buffer.setRGBARaw(dstPixel, srcPtr[0], srcPtr[1], srcPtr[2], srcPtr[3]);
                alphaMask &= srcPtr[3];
            }
        }
    } else {
        for (auto* dstPixel = dstRow; dstPixel < dstRow + width;
             dstPixel++, srcPtr += 3) {
            buffer.setRGBARaw(dstPixel, srcPtr[0], srcPtr[1], srcPtr[2], 255);
        }

        // We'll apply the color space xform to opaque pixels after they have been
        // written to the ImageFrame, purely because SkColorSpaceXform supports
        // RGBA (and not RGB).
//         if (SkColorSpaceXform* xform = colorTransform()) {
//             xform->apply(xformColorFormat(), dstRow, xformColorFormat(), dstRow,
//                 size().width(), kOpaque_SkAlphaType);
//         }
=======
#if USE(QCMSLIB)
    if (qcms_transform* transform = m_reader->colorTransform()) {
        qcms_transform_data(transform, row, m_reader->rowBuffer(), size().width());
        row = m_reader->rowBuffer();
    }
#endif

    // Write the decoded row pixels to the frame buffer. The repetitive
    // form of the row write loops is for speed.
    ImageFrame::PixelData* address = buffer.getAddr(0, y);
    unsigned alphaMask = 255;
    int width = size().width();

    png_bytep pixel = row;
    if (hasAlpha) {
        if (buffer.premultiplyAlpha()) {
            for (int x = 0; x < width; ++x, pixel += 4) {
                buffer.setRGBAPremultiply(address++, pixel[0], pixel[1], pixel[2], pixel[3]);
                alphaMask &= pixel[3];
            }
        } else {
            for (int x = 0; x < width; ++x, pixel += 4) {
                buffer.setRGBARaw(address++, pixel[0], pixel[1], pixel[2], pixel[3]);
                alphaMask &= pixel[3];
            }
        }
    } else {
        for (int x = 0; x < width; ++x, pixel += 3) {
            buffer.setRGBARaw(address++, pixel[0], pixel[1], pixel[2], 255);
        }
>>>>>>> miniblink49
    }

    if (alphaMask != 255 && !buffer.hasAlpha())
        buffer.setHasAlpha(true);

    buffer.setPixelsChanged(true);
}

void PNGImageDecoder::complete()
{
    if (m_frameBufferCache.isEmpty())
        return;

    m_frameBufferCache[0].setStatus(ImageFrame::FrameComplete);
}

inline bool isComplete(const PNGImageDecoder* decoder)
{
    return decoder->frameIsCompleteAtIndex(0);
}

void PNGImageDecoder::decode(bool onlySize)
{
    if (failed())
        return;

    if (!m_reader)
<<<<<<< HEAD
        m_reader = WTF::makeUnique<PNGImageReader>(this, m_offset);
=======
        m_reader = adoptPtr(new PNGImageReader(this));
>>>>>>> miniblink49

    // If we couldn't decode the image but have received all the data, decoding
    // has failed.
    if (!m_reader->decode(*m_data, onlySize) && isAllDataReceived())
        setFailed();

    // If decoding is done or failed, we don't need the PNGImageReader anymore.
    if (isComplete(this) || failed())
<<<<<<< HEAD
        m_reader.reset();
=======
        m_reader.clear();
>>>>>>> miniblink49
}

} // namespace blink
