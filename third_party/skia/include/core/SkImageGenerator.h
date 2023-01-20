/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkImageGenerator_DEFINED
#define SkImageGenerator_DEFINED

<<<<<<< HEAD
#include "SkBitmap.h"
#include "SkColor.h"
#include "SkImageInfo.h"
#include "SkYUVSizeInfo.h"

class GrContext;
class GrTexture;
class GrTextureParams;
class SkBitmap;
class SkData;
class SkImageGenerator;
class SkMatrix;
class SkPaint;
class SkPicture;

#ifdef SK_SUPPORT_LEGACY_REFENCODEDDATA_NOCTX
#define SK_REFENCODEDDATA_CTXPARAM
#else
#define SK_REFENCODEDDATA_CTXPARAM GrContext* ctx
#endif
=======
#include "SkColor.h"
#include "SkImageInfo.h"

class SkBitmap;
class SkData;
class SkImageGenerator;

//#define SK_LEGACY_IMAGE_GENERATOR_ENUMS_AND_OPTIONS
>>>>>>> miniblink49

/**
 *  Takes ownership of SkImageGenerator.  If this method fails for
 *  whatever reason, it will return false and immediatetely delete
 *  the generator.  If it succeeds, it will modify destination
 *  bitmap.
 *
 *  If generator is NULL, will safely return false.
 *
 *  If this fails or when the SkDiscardablePixelRef that is
<<<<<<< HEAD
 *  installed into destination is destroyed, it will
 *  delete the generator.  Therefore, generator should be
 *  allocated with new.
=======
 *  installed into destination is destroyed, it will call
 *  SkDELETE() on the generator.  Therefore, generator should be
 *  allocated with SkNEW() or SkNEW_ARGS().
>>>>>>> miniblink49
 *
 *  @param destination Upon success, this bitmap will be
 *  configured and have a pixelref installed.
 *
 *  @return true iff successful.
 */
<<<<<<< HEAD
SK_API bool SkDEPRECATED_InstallDiscardablePixelRef(SkImageGenerator*, SkBitmap* destination);
=======
SK_API bool SkInstallDiscardablePixelRef(SkImageGenerator*, SkBitmap* destination);
>>>>>>> miniblink49

/**
 *  On success, installs a discardable pixelref into destination, based on encoded data.
 *  Regardless of success or failure, the caller must still balance their ownership of encoded.
 */
<<<<<<< HEAD
SK_API bool SkDEPRECATED_InstallDiscardablePixelRef(SkData* encoded, SkBitmap* destination);
=======
SK_API bool SkInstallDiscardablePixelRef(SkData* encoded, SkBitmap* destination);
>>>>>>> miniblink49

/**
 *  An interface that allows a purgeable PixelRef (such as a
 *  SkDiscardablePixelRef) to decode and re-decode an image as needed.
 */
class SK_API SkImageGenerator : public SkNoncopyable {
public:
    /**
     *  The PixelRef which takes ownership of this SkImageGenerator
     *  will call the image generator's destructor.
     */
    virtual ~SkImageGenerator() { }

<<<<<<< HEAD
    uint32_t uniqueID() const { return fUniqueID; }

    /**
     *  Return a ref to the encoded (i.e. compressed) representation,
     *  of this data. If the GrContext is non-null, then the caller is only interested in
     *  gpu-specific formats, so the impl may return null even if they have encoded data,
     *  assuming they know it is not suitable for the gpu.
=======
    /**
     *  Return a ref to the encoded (i.e. compressed) representation,
     *  of this data.
>>>>>>> miniblink49
     *
     *  If non-NULL is returned, the caller is responsible for calling
     *  unref() on the data when it is finished.
     */
<<<<<<< HEAD
    SkData* refEncodedData(GrContext* ctx = nullptr)
    {
#ifdef SK_SUPPORT_LEGACY_REFENCODEDDATA_NOCTX
        return this->onRefEncodedData();
#else
        return this->onRefEncodedData(ctx);
#endif
    }
=======
    SkData* refEncodedData() { return this->onRefEncodedData(); }
>>>>>>> miniblink49

    /**
     *  Return the ImageInfo associated with this generator.
     */
    const SkImageInfo& getInfo() const { return fInfo; }

<<<<<<< HEAD
=======
#ifdef SK_LEGACY_IMAGE_GENERATOR_ENUMS_AND_OPTIONS
    /**
     *  Used to describe the result of a call to getPixels().
     *
     *  Result is the union of possible results from subclasses.
     */
    enum Result {
        /**
         *  General return value for success.
         */
        kSuccess,
        /**
         *  The input is incomplete. A partial image was generated.
         */
        kIncompleteInput,
        /**
         *  The generator cannot convert to match the request, ignoring
         *  dimensions.
         */
        kInvalidConversion,
        /**
         *  The generator cannot scale to requested size.
         */
        kInvalidScale,
        /**
         *  Parameters (besides info) are invalid. e.g. NULL pixels, rowBytes
         *  too small, etc.
         */
        kInvalidParameters,
        /**
         *  The input did not contain a valid image.
         */
        kInvalidInput,
        /**
         *  Fulfilling this request requires rewinding the input, which is not
         *  supported for this input.
         */
        kCouldNotRewind,
        /**
         *  This method is not implemented by this generator.
         */
        kUnimplemented,
    };

    /**
     *  Whether or not the memory passed to getPixels is zero initialized.
     */
    enum ZeroInitialized {
        /**
         *  The memory passed to getPixels is zero initialized. The SkCodec
         *  may take advantage of this by skipping writing zeroes.
         */
        kYes_ZeroInitialized,
        /**
         *  The memory passed to getPixels has not been initialized to zero,
         *  so the SkCodec must write all zeroes to memory.
         *
         *  This is the default. It will be used if no Options struct is used.
         */
        kNo_ZeroInitialized,
    };

    /**
     *  Additional options to pass to getPixels.
     */
    struct Options {
        Options()
            : fZeroInitialized(kNo_ZeroInitialized) {}

        ZeroInitialized fZeroInitialized;
    };
#endif

>>>>>>> miniblink49
    /**
     *  Decode into the given pixels, a block of memory of size at
     *  least (info.fHeight - 1) * rowBytes + (info.fWidth *
     *  bytesPerPixel)
     *
     *  Repeated calls to this function should give the same results,
     *  allowing the PixelRef to be immutable.
     *
     *  @param info A description of the format (config, size)
     *         expected by the caller.  This can simply be identical
     *         to the info returned by getInfo().
     *
     *         This contract also allows the caller to specify
     *         different output-configs, which the implementation can
     *         decide to support or not.
     *
     *         A size that does not match getInfo() implies a request
     *         to scale. If the generator cannot perform this scale,
     *         it will return kInvalidScale.
     *
     *  If info is kIndex8_SkColorType, then the caller must provide storage for up to 256
     *  SkPMColor values in ctable. On success the generator must copy N colors into that storage,
     *  (where N is the logical number of table entries) and set ctableCount to N.
     *
     *  If info is not kIndex8_SkColorType, then the last two parameters may be NULL. If ctableCount
     *  is not null, it will be set to 0.
     *
     *  @return true on success.
     */
    bool getPixels(const SkImageInfo& info, void* pixels, size_t rowBytes,
<<<<<<< HEAD
        SkPMColor ctable[], int* ctableCount);
=======
                   SkPMColor ctable[], int* ctableCount);
>>>>>>> miniblink49

    /**
     *  Simplified version of getPixels() that asserts that info is NOT kIndex8_SkColorType and
     *  uses the default Options.
     */
    bool getPixels(const SkImageInfo& info, void* pixels, size_t rowBytes);

    /**
<<<<<<< HEAD
     *  If decoding to YUV is supported, this returns true.  Otherwise, this
     *  returns false and does not modify any of the parameters.
     *
     *  @param sizeInfo   Output parameter indicating the sizes and required
     *                    allocation widths of the Y, U, and V planes.
     *  @param colorSpace Output parameter.
     */
    bool queryYUV8(SkYUVSizeInfo* sizeInfo, SkYUVColorSpace* colorSpace) const;

    /**
     *  Returns true on success and false on failure.
     *  This always attempts to perform a full decode.  If the client only
     *  wants size, it should call queryYUV8().
     *
     *  @param sizeInfo   Needs to exactly match the values returned by the
     *                    query, except the WidthBytes may be larger than the
     *                    recommendation (but not smaller).
     *  @param planes     Memory for each of the Y, U, and V planes.
     */
    bool getYUV8Planes(const SkYUVSizeInfo& sizeInfo, void* planes[3]);

    /**
     *  If the generator can natively/efficiently return its pixels as a GPU image (backed by a
     *  texture) this will return that image. If not, this will return NULL.
     *
     *  Regarding the GrContext parameter:
     *
     *  The caller may pass NULL for the context. In that case the generator may assume that its
     *  internal context is current. If it has no internal context, then it should just return
     *  null.
     *
     *  If the caller passes a non-null context, then the generator should only succeed if:
     *  - it has no intrinsic context, and will use the caller's
     *  - its internal context is the same
     *  - it can somehow convert its texture into one that is valid for the provided context.
     *
     *  Regarding the GrTextureParams parameter:
     *
     *  If the context (the provided one or the generator's intrinsic one) determines that to
     *  support the specified usage, it must return a different sized texture it may,
     *  so the caller must inspect the texture's width/height and compare them to the generator's
     *  getInfo() width/height. For readback usage use GrTextureParams::ClampNoFilter()
     */
    GrTexture* generateTexture(GrContext*, const SkIRect* subset = nullptr);

    struct SupportedSizes {
        SkISize fSizes[2];
    };

    /**
     *  Some generators can efficiently scale their contents. If this is supported, the generator
     *  may only support certain scaled dimensions. Call this with the desired scale factor,
     *  and it will return true if scaling is supported, and in supportedSizes[] it will return
     *  the nearest supported dimensions.
     *
     *  If no native scaling is supported, or scale is invalid (e.g. scale <= 0 || scale > 1)
     *  this will return false, and the supportedsizes will be undefined.
     */
    bool computeScaledDimensions(SkScalar scale, SupportedSizes*);

    /**
     *  Scale the generator's pixels to fit into scaledSize.
     *  This routine also support retrieving only a subset of the pixels. That subset is specified
     *  by the following rectangle (in the scaled space):
     *
     *      subset = SkIRect::MakeXYWH(subsetOrigin.x(), subsetOrigin.y(),
     *                                 subsetPixels.width(), subsetPixels.height())
     *
     *  If subset is not contained inside the scaledSize, this returns false.
     *
     *      whole = SkIRect::MakeWH(scaledSize.width(), scaledSize.height())
     *      if (!whole.contains(subset)) {
     *          return false;
     *      }
     *
     *  If the requested colortype/alphatype in pixels is not supported,
     *  or the requested scaledSize is not supported, or the generator encounters an error,
     *  this returns false.
     */
    bool generateScaledPixels(const SkISize& scaledSize, const SkIPoint& subsetOrigin,
        const SkPixmap& subsetPixels);

    bool generateScaledPixels(const SkPixmap& scaledPixels)
    {
        return this->generateScaledPixels(SkISize::Make(scaledPixels.width(),
                                              scaledPixels.height()),
            SkIPoint::Make(0, 0), scaledPixels);
    }
=======
     *  If planes or rowBytes is NULL or if any entry in planes is NULL or if any entry in rowBytes
     *  is 0, this imagegenerator should output the sizes and return true if it can efficiently
     *  return YUV planar data. If it cannot, it should return false. Note that either planes and
     *  rowBytes are both fully defined and non NULL/non 0 or they are both NULL or have NULL or 0
     *  entries only. Having only partial planes/rowBytes information is not supported.
     *
     *  If all planes and rowBytes entries are non NULL or non 0, then it should copy the
     *  associated YUV data into those planes of memory supplied by the caller. It should validate
     *  that the sizes match what it expected. If the sizes do not match, it should return false.
     */
    bool getYUV8Planes(SkISize sizes[3], void* planes[3], size_t rowBytes[3],
                       SkYUVColorSpace* colorSpace);
>>>>>>> miniblink49

    /**
     *  If the default image decoder system can interpret the specified (encoded) data, then
     *  this returns a new ImageGenerator for it. Otherwise this returns NULL. Either way
     *  the caller is still responsible for managing their ownership of the data.
     */
    static SkImageGenerator* NewFromEncoded(SkData*);

<<<<<<< HEAD
    /** Return a new image generator backed by the specified picture.  If the size is empty or
     *  the picture is NULL, this returns NULL.
     *  The optional matrix and paint arguments are passed to drawPicture() at rasterization
     *  time.
     */
    static SkImageGenerator* NewFromPicture(const SkISize&, const SkPicture*, const SkMatrix*,
        const SkPaint*);

    bool tryGenerateBitmap(SkBitmap* bm)
    {
        return this->tryGenerateBitmap(bm, nullptr, nullptr);
    }
    bool tryGenerateBitmap(SkBitmap* bm, const SkImageInfo& info, SkBitmap::Allocator* allocator)
    {
        return this->tryGenerateBitmap(bm, &info, allocator);
    }
    void generateBitmap(SkBitmap* bm)
    {
        if (!this->tryGenerateBitmap(bm, nullptr, nullptr)) {
            sk_throw();
        }
    }
    void generateBitmap(SkBitmap* bm, const SkImageInfo& info)
    {
        if (!this->tryGenerateBitmap(bm, &info, nullptr)) {
            sk_throw();
        }
    }

protected:
    enum {
        kNeedNewImageUniqueID = 0
    };

    SkImageGenerator(const SkImageInfo& info, uint32_t uniqueId = kNeedNewImageUniqueID);

    virtual SkData* onRefEncodedData(SK_REFENCODEDDATA_CTXPARAM);

    virtual bool onGetPixels(const SkImageInfo& info, void* pixels, size_t rowBytes,
        SkPMColor ctable[], int* ctableCount);

    virtual bool onQueryYUV8(SkYUVSizeInfo*, SkYUVColorSpace*) const
    {
        return false;
    }
    virtual bool onGetYUV8Planes(const SkYUVSizeInfo&, void* [3] /*planes*/)
    {
        return false;
    }

    virtual GrTexture* onGenerateTexture(GrContext*, const SkIRect*)
    {
        return nullptr;
    }

    virtual bool onComputeScaledDimensions(SkScalar, SupportedSizes*)
    {
        return false;
    }
    virtual bool onGenerateScaledPixels(const SkISize&, const SkIPoint&, const SkPixmap&)
    {
        return false;
    }

    bool tryGenerateBitmap(SkBitmap* bm, const SkImageInfo* optionalInfo, SkBitmap::Allocator*);

private:
    const SkImageInfo fInfo;
    const uint32_t fUniqueID;
=======
protected:
    SkImageGenerator(const SkImageInfo& info) : fInfo(info) {}

    virtual SkData* onRefEncodedData();

#ifdef SK_LEGACY_IMAGE_GENERATOR_ENUMS_AND_OPTIONS
    virtual Result onGetPixels(const SkImageInfo& info,
                               void* pixels, size_t rowBytes, const Options&,
                               SkPMColor ctable[], int* ctableCount);
#else
    virtual bool onGetPixels(const SkImageInfo& info, void* pixels, size_t rowBytes,
                             SkPMColor ctable[], int* ctableCount);
#endif
    virtual bool onGetYUV8Planes(SkISize sizes[3], void* planes[3], size_t rowBytes[3]);
    virtual bool onGetYUV8Planes(SkISize sizes[3], void* planes[3], size_t rowBytes[3],
                                 SkYUVColorSpace* colorSpace);

private:
    const SkImageInfo fInfo;
>>>>>>> miniblink49

    // This is our default impl, which may be different on different platforms.
    // It is called from NewFromEncoded() after it has checked for any runtime factory.
    // The SkData will never be NULL, as that will have been checked by NewFromEncoded.
    static SkImageGenerator* NewFromEncodedImpl(SkData*);
};

<<<<<<< HEAD
#endif // SkImageGenerator_DEFINED
=======
#endif  // SkImageGenerator_DEFINED
>>>>>>> miniblink49
