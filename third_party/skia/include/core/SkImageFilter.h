/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkImageFilter_DEFINED
#define SkImageFilter_DEFINED

<<<<<<< HEAD
#include "../private/SkMutex.h"
#include "../private/SkTArray.h"
#include "../private/SkTemplates.h"
=======
>>>>>>> miniblink49
#include "SkFilterQuality.h"
#include "SkFlattenable.h"
#include "SkMatrix.h"
#include "SkRect.h"
<<<<<<< HEAD

class GrContext;
class GrFragmentProcessor;
class SkColorFilter;
struct SkIPoint;
class SkSpecialImage;
class SkImageFilterCache;
struct SkImageFilterCacheKey;
=======
#include "SkSurfaceProps.h"
#include "SkTemplates.h"

class GrFragmentProcessor;
class GrProcessorDataManager;
class GrTexture;
class SkBaseDevice;
class SkBitmap;
class SkColorFilter;
struct SkIPoint;
>>>>>>> miniblink49

/**
 *  Base class for image filters. If one is installed in the paint, then
 *  all drawing occurs as usual, but it is as if the drawing happened into an
 *  offscreen (before the xfermode is applied). This offscreen bitmap will
 *  then be handed to the imagefilter, who in turn creates a new bitmap which
 *  is what will finally be drawn to the device (using the original xfermode).
 */
class SK_API SkImageFilter : public SkFlattenable {
public:
<<<<<<< HEAD
    class Context {
    public:
        Context(const SkMatrix& ctm, const SkIRect& clipBounds, SkImageFilterCache* cache)
            : fCTM(ctm)
            , fClipBounds(clipBounds)
            , fCache(cache)
        {
        }

        const SkMatrix& ctm() const { return fCTM; }
        const SkIRect& clipBounds() const { return fClipBounds; }
        SkImageFilterCache* cache() const { return fCache; }

    private:
        SkMatrix fCTM;
        SkIRect fClipBounds;
        SkImageFilterCache* fCache;
    };

    class CropRect {
    public:
        enum CropEdge {
            kHasLeft_CropEdge = 0x01,
            kHasTop_CropEdge = 0x02,
            kHasWidth_CropEdge = 0x04,
            kHasHeight_CropEdge = 0x08,
            kHasAll_CropEdge = 0x0F,
        };
        CropRect() { }
        explicit CropRect(const SkRect& rect, uint32_t flags = kHasAll_CropEdge)
            : fRect(rect)
            , fFlags(flags)
        {
        }
        uint32_t flags() const { return fFlags; }
        const SkRect& rect() const { return fRect; }
#ifndef SK_IGNORE_TO_STRING
        void toString(SkString* str) const;
#endif

        /**
         *  Apply this cropRect to the imageBounds. If a given edge of the cropRect is not
         *  set, then the corresponding edge from imageBounds will be used. If "embiggen"
         *  is true, the crop rect is allowed to enlarge the size of the rect, otherwise
         *  it may only reduce the rect. Filters that can affect transparent black should 
         *  pass "true", while all other filters should pass "false".
         *
         *  Note: imageBounds is in "device" space, as the output cropped rectangle will be,
         *  so the matrix is ignored for those. It is only applied the croprect's bounds.
         */
        void applyTo(const SkIRect& imageBounds, const SkMatrix&, bool embiggen,
            SkIRect* cropped) const;

=======
    class CropRect {
    public:
        enum CropEdge {
            kHasLeft_CropEdge   = 0x01,
            kHasTop_CropEdge    = 0x02,
            kHasRight_CropEdge  = 0x04,
            kHasBottom_CropEdge = 0x08,
            kHasAll_CropEdge    = 0x0F,
        };
        CropRect() {}
        explicit CropRect(const SkRect& rect, uint32_t flags = kHasAll_CropEdge) : fRect(rect), fFlags(flags) {}
        uint32_t flags() const { return fFlags; }
        const SkRect& rect() const { return fRect; }
>>>>>>> miniblink49
    private:
        SkRect fRect;
        uint32_t fFlags;
    };

<<<<<<< HEAD
    enum TileUsage {
        kPossible_TileUsage, //!< the created device may be drawn tiled
        kNever_TileUsage, //!< the created device will never be drawn tiled
    };

    /**
     *  Request a new filtered image to be created from the src image.
     *
     *  The context contains the environment in which the filter is occurring.
     *  It includes the clip bounds, CTM and cache.
=======
    // This cache maps from (filter's unique ID + CTM + clipBounds + src bitmap generation ID) to
    // (result, offset).
    class Cache : public SkRefCnt {
    public:
        struct Key;
        virtual ~Cache() {}
        static Cache* Create(size_t maxBytes);
        static Cache* Get();
        virtual bool get(const Key& key, SkBitmap* result, SkIPoint* offset) const = 0;
        virtual void set(const Key& key, const SkBitmap& result, const SkIPoint& offset) = 0;
        virtual void purge() {}
    };

    class Context {
    public:
        Context(const SkMatrix& ctm, const SkIRect& clipBounds, Cache* cache) :
            fCTM(ctm), fClipBounds(clipBounds), fCache(cache) {
        }
        const SkMatrix& ctm() const { return fCTM; }
        const SkIRect& clipBounds() const { return fClipBounds; }
        Cache* cache() const { return fCache; }
    private:
        SkMatrix fCTM;
        SkIRect  fClipBounds;
        Cache*   fCache;
    };

    class Proxy {
    public:
        Proxy(SkBaseDevice* device) : fDevice(device) { }

        SkBaseDevice* createDevice(int width, int height);

        // Returns true if the proxy handled the filter itself. If this returns
        // false then the filter's code will be called.
        bool filterImage(const SkImageFilter*, const SkBitmap& src, const SkImageFilter::Context&,
                         SkBitmap* result, SkIPoint* offset);

    private:
        SkBaseDevice* fDevice;
    };


    /**
     *  Request a new (result) image to be created from the src image.
     *  If the src has no pixels (isNull()) then the request just wants to
     *  receive the config and width/height of the result.
     *
     *  The matrix is the current matrix on the canvas.
>>>>>>> miniblink49
     *
     *  Offset is the amount to translate the resulting image relative to the
     *  src when it is drawn. This is an out-param.
     *
<<<<<<< HEAD
     *  If the result image cannot be created, or the result would be
     *  transparent black, return null, in which case the offset parameter
     *  should be ignored by the caller.
     *
     *  TODO: Right now the imagefilters sometimes return empty result bitmaps/
     *        specialimages. That doesn't seem quite right.
     */
    sk_sp<SkSpecialImage> filterImage(SkSpecialImage* src, const Context&, SkIPoint* offset) const;

    enum MapDirection {
        kForward_MapDirection,
        kReverse_MapDirection
    };
    /**
     * Map a device-space rect recursively forward or backward through the
     * filter DAG. kForward_MapDirection is used to determine which pixels of
     * the destination canvas a source image rect would touch after filtering.
     * kReverse_MapDirection is used to determine which rect of the source
     * image would be required to fill the given rect (typically, clip bounds).
     * Used for clipping and temp-buffer allocations, so the result need not
     * be exact, but should never be smaller than the real answer. The default
     * implementation recursively unions all input bounds, or returns the
     * source rect if no inputs.
     */
    SkIRect filterBounds(const SkIRect& src, const SkMatrix& ctm,
        MapDirection = kReverse_MapDirection) const;

#if SK_SUPPORT_GPU
    static sk_sp<SkSpecialImage> DrawWithFP(GrContext* context,
        sk_sp<GrFragmentProcessor> fp,
        const SkIRect& bounds);
#endif
=======
     *  If the result image cannot be created, return false, in which case both
     *  the result and offset parameters will be ignored by the caller.
     */
    bool filterImage(Proxy*, const SkBitmap& src, const Context&,
                     SkBitmap* result, SkIPoint* offset) const;

    /**
     *  Given the src bounds of an image, this returns the bounds of the result
     *  image after the filter has been applied.
     */
    bool filterBounds(const SkIRect& src, const SkMatrix& ctm, SkIRect* dst) const;

    /**
     *  Returns true if the filter can be processed on the GPU.  This is most
     *  often used for multi-pass effects, where intermediate results must be
     *  rendered to textures.  For single-pass effects, use asFragmentProcessor().
     *  The default implementation returns asFragmentProcessor(NULL, NULL, SkMatrix::I(),
     *  SkIRect()).
     */
    virtual bool canFilterImageGPU() const;

    /**
     *  Process this image filter on the GPU.  This is most often used for
     *  multi-pass effects, where intermediate results must be rendered to
     *  textures.  For single-pass effects, use asFragmentProcessor().  src is the
     *  source image for processing, as a texture-backed bitmap.  result is
     *  the destination bitmap, which should contain a texture-backed pixelref
     *  on success.  offset is the amount to translate the resulting image
     *  relative to the src when it is drawn. The default implementation does
     *  single-pass processing using asFragmentProcessor().
     */
    virtual bool filterImageGPU(Proxy*, const SkBitmap& src, const Context&,
                                SkBitmap* result, SkIPoint* offset) const;
>>>>>>> miniblink49

    /**
     *  Returns whether this image filter is a color filter and puts the color filter into the
     *  "filterPtr" parameter if it can. Does nothing otherwise.
     *  If this returns false, then the filterPtr is unchanged.
     *  If this returns true, then if filterPtr is not null, it must be set to a ref'd colorfitler
     *  (i.e. it may not be set to NULL).
     */
<<<<<<< HEAD
    bool isColorFilterNode(SkColorFilter** filterPtr) const
    {
=======
    bool isColorFilterNode(SkColorFilter** filterPtr) const {
>>>>>>> miniblink49
        return this->onIsColorFilterNode(filterPtr);
    }

    // DEPRECATED : use isColorFilterNode() instead
<<<<<<< HEAD
    bool asColorFilter(SkColorFilter** filterPtr) const
    {
=======
    bool asColorFilter(SkColorFilter** filterPtr) const {
>>>>>>> miniblink49
        return this->isColorFilterNode(filterPtr);
    }

    /**
     *  Returns true (and optionally returns a ref'd filter) if this imagefilter can be completely
     *  replaced by the returned colorfilter. i.e. the two effects will affect drawing in the
     *  same way.
     */
<<<<<<< HEAD
    bool asAColorFilter(SkColorFilter** filterPtr) const;
=======
    bool asAColorFilter(SkColorFilter** filterPtr) const {
        return this->countInputs() > 0 &&
               NULL == this->getInput(0) &&
               this->isColorFilterNode(filterPtr);
    }
>>>>>>> miniblink49

    /**
     *  Returns the number of inputs this filter will accept (some inputs can
     *  be NULL).
     */
<<<<<<< HEAD
    int countInputs() const { return fInputs.count(); }
=======
    int countInputs() const { return fInputCount; }
>>>>>>> miniblink49

    /**
     *  Returns the input filter at a given index, or NULL if no input is
     *  connected.  The indices used are filter-specific.
     */
<<<<<<< HEAD
    SkImageFilter* getInput(int i) const
    {
        SkASSERT(i < fInputs.count());
        return fInputs[i].get();
=======
    SkImageFilter* getInput(int i) const {
        SkASSERT(i < fInputCount);
        return fInputs[i];
>>>>>>> miniblink49
    }

    /**
     *  Returns whether any edges of the crop rect have been set. The crop
     *  rect is set at construction time, and determines which pixels from the
<<<<<<< HEAD
     *  input image will be processed, and which pixels in the output image will be allowed.
     *  The size of the crop rect should be
     *  used as the size of the destination image. The origin of this rect
     *  should be used to offset access to the input images, and should also
     *  be added to the "offset" parameter in onFilterImage.
=======
     *  input image will be processed. The size of the crop rect should be
     *  used as the size of the destination image. The origin of this rect
     *  should be used to offset access to the input images, and should also
     *  be added to the "offset" parameter in onFilterImage and
     *  filterImageGPU(). (The latter ensures that the resulting buffer is
     *  drawn in the correct location.)
>>>>>>> miniblink49
     */
    bool cropRectIsSet() const { return fCropRect.flags() != 0x0; }

    CropRect getCropRect() const { return fCropRect; }

    // Default impl returns union of all input bounds.
<<<<<<< HEAD
    virtual SkRect computeFastBounds(const SkRect&) const;

    // Can this filter DAG compute the resulting bounds of an object-space rectangle?
    bool canComputeFastBounds() const;

    /**
     *  If this filter can be represented by another filter + a localMatrix, return that filter,
     *  else return null.
     */
    sk_sp<SkImageFilter> makeWithLocalMatrix(const SkMatrix&) const;

#ifdef SK_SUPPORT_LEGACY_IMAGEFILTER_PTR
    SkImageFilter* newWithLocalMatrix(const SkMatrix& matrix) const
    {
        return this->makeWithLocalMatrix(matrix).release();
    }
#endif

    /**
     *  ImageFilters can natively handle scaling and translate components in the CTM. Only some of
     *  them can handle affine (or more complex) matrices. This call returns true iff the filter
     *  and all of its (non-null) inputs can handle these more complex matrices.
     */
    bool canHandleComplexCTM() const;

    /**
     * Return an imagefilter which transforms its input by the given matrix.
     */
    static sk_sp<SkImageFilter> MakeMatrixFilter(const SkMatrix& matrix,
        SkFilterQuality quality,
        sk_sp<SkImageFilter> input);

#ifdef SK_SUPPORT_LEGACY_IMAGEFILTER_PTR
    static SkImageFilter* CreateMatrixFilter(const SkMatrix& matrix,
        SkFilterQuality filterQuality,
        SkImageFilter* input = nullptr)
    {
        return MakeMatrixFilter(matrix, filterQuality, sk_ref_sp<SkImageFilter>(input)).release();
    }
=======
    virtual void computeFastBounds(const SkRect&, SkRect*) const;

    /**
     * Create an SkMatrixImageFilter, which transforms its input by the given matrix.
     */
    static SkImageFilter* CreateMatrixFilter(const SkMatrix& matrix,
                                             SkFilterQuality,
                                             SkImageFilter* input = NULL);

#if SK_SUPPORT_GPU
    /**
     * Wrap the given texture in a texture-backed SkBitmap.
     */
    static void WrapTexture(GrTexture* texture, int width, int height, SkBitmap* result);

    /**
     * Recursively evaluate this filter on the GPU. If the filter has no GPU
     * implementation, it will be processed in software and uploaded to the GPU.
     */
    bool getInputResultGPU(SkImageFilter::Proxy* proxy, const SkBitmap& src, const Context&,
                           SkBitmap* result, SkIPoint* offset) const;
>>>>>>> miniblink49
#endif

    SK_TO_STRING_PUREVIRT()
    SK_DEFINE_FLATTENABLE_TYPE(SkImageFilter)

protected:
    class Common {
    public:
<<<<<<< HEAD
=======
        Common() {}
        ~Common();

>>>>>>> miniblink49
        /**
         *  Attempt to unflatten the cropRect and the expected number of input filters.
         *  If any number of input filters is valid, pass -1.
         *  If this fails (i.e. corrupt buffer or contents) then return false and common will
         *  be left uninitialized.
         *  If this returns true, then inputCount() is the number of found input filters, each
         *  of which may be NULL or a valid imagefilter.
         */
        bool unflatten(SkReadBuffer&, int expectedInputs);

        const CropRect& cropRect() const { return fCropRect; }
<<<<<<< HEAD
        int inputCount() const { return fInputs.count(); }
        sk_sp<SkImageFilter>* inputs() const { return fInputs.get(); }

        sk_sp<SkImageFilter> getInput(int index) const { return fInputs[index]; }
=======
        int             inputCount() const { return fInputs.count(); }
        SkImageFilter** inputs() const { return fInputs.get(); }

        SkImageFilter*  getInput(int index) const { return fInputs[index]; }

        // If the caller wants a copy of the inputs, call this and it will transfer ownership
        // of the unflattened input filters to the caller. This is just a short-cut for copying
        // the inputs, calling ref() on each, and then waiting for Common's destructor to call
        // unref() on each.
        void detachInputs(SkImageFilter** inputs);
>>>>>>> miniblink49

    private:
        CropRect fCropRect;
        // most filters accept at most 2 input-filters
<<<<<<< HEAD
        SkAutoSTArray<2, sk_sp<SkImageFilter>> fInputs;
=======
        SkAutoSTArray<2, SkImageFilter*> fInputs;
>>>>>>> miniblink49

        void allocInputs(int count);
    };

<<<<<<< HEAD
    SkImageFilter(sk_sp<SkImageFilter>* inputs, int inputCount, const CropRect* cropRect);
=======
    SkImageFilter(int inputCount, SkImageFilter** inputs, const CropRect* cropRect = NULL);
>>>>>>> miniblink49

    virtual ~SkImageFilter();

    /**
     *  Constructs a new SkImageFilter read from an SkReadBuffer object.
     *
     *  @param inputCount    The exact number of inputs expected for this SkImageFilter object.
     *                       -1 can be used if the filter accepts any number of inputs.
     *  @param rb            SkReadBuffer object from which the SkImageFilter is read.
     */
    explicit SkImageFilter(int inputCount, SkReadBuffer& rb);

    void flatten(SkWriteBuffer&) const override;

    /**
     *  This is the virtual which should be overridden by the derived class
     *  to perform image filtering.
     *
     *  src is the original primitive bitmap. If the filter has a connected
     *  input, it should recurse on that input and use that in place of src.
     *
     *  The matrix is the current matrix on the canvas.
     *
     *  Offset is the amount to translate the resulting image relative to the
     *  src when it is drawn. This is an out-param.
     *
<<<<<<< HEAD
     *  If the result image cannot be created (either because of error or if, say, the result
     *  is entirely clipped out), this should return nullptr.
     *  Callers that affect transparent black should explicitly handle nullptr
     *  results and press on. In the error case this behavior will produce a better result
     *  than nothing and is necessary for the clipped out case.
     *  If the return value is nullptr then offset should be ignored.
     */
    virtual sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* src, const Context&,
        SkIPoint* offset) const = 0;

    /**
     * This function recurses into its inputs with the given rect (first
     * argument), calls filterBounds() with the given map direction on each,
     * and returns the union of those results. If a derived class has special
     * recursion requirements (e.g., it has an input which does not participate
     * in bounds computation), it can be overridden here.
     *
     * Note that this function is *not* responsible for mapping the rect for
     * this node's filter bounds requirements (i.e., calling
     * onFilterNodeBounds()); that is handled by filterBounds().
     */
    virtual SkIRect onFilterBounds(const SkIRect&, const SkMatrix&, MapDirection) const;

    /**
     * Performs a forwards or reverse mapping of the given rect to accommodate
     * this filter's margin requirements. kForward_MapDirection is used to
     * determine the destination pixels which would be touched by filtering
     * the given given source rect (e.g., given source bitmap bounds,
     * determine the optimal bounds of the filtered offscreen bitmap).
     * kReverse_MapDirection is used to determine which pixels of the
     * input(s) would be required to fill the given destination rect
     * (e.g., clip bounds). NOTE: these operations may not be the
     * inverse of the other. For example, blurring expands the given rect
     * in both forward and reverse directions. Unlike
     * onFilterBounds(), this function is non-recursive.
     */
    virtual SkIRect onFilterNodeBounds(const SkIRect&, const SkMatrix&, MapDirection) const;

    // Helper function which invokes filter processing on the input at the
    // specified "index". If the input is null, it returns "src" and leaves
    // "offset" untouched. If the input is non-null, it
    // calls filterImage() on that input, and returns the result.
    sk_sp<SkSpecialImage> filterInput(int index,
        SkSpecialImage* src,
        const Context&,
        SkIPoint* offset) const;
=======
     *  If the result image cannot be created, this should false, in which
     *  case both the result and offset parameters will be ignored by the
     *  caller.
     */
    virtual bool onFilterImage(Proxy*, const SkBitmap& src, const Context&,
                               SkBitmap* result, SkIPoint* offset) const;
    // Given the bounds of the destination rect to be filled in device
    // coordinates (first parameter), and the CTM, compute (conservatively)
    // which rect of the source image would be required (third parameter).
    // Used for clipping and temp-buffer allocations, so the result need not
    // be exact, but should never be smaller than the real answer. The default
    // implementation recursively unions all input bounds, or returns false if
    // no inputs.
    virtual bool onFilterBounds(const SkIRect&, const SkMatrix&, SkIRect*) const;
>>>>>>> miniblink49

    /**
     *  Return true (and return a ref'd colorfilter) if this node in the DAG is just a
     *  colorfilter w/o CropRect constraints.
     */
<<<<<<< HEAD
    virtual bool onIsColorFilterNode(SkColorFilter** /*filterPtr*/) const
    {
        return false;
    }

    /**
     *  Override this to describe the behavior of your subclass - as a leaf node. The caller will
     *  take care of calling your inputs (and return false if any of them could not handle it).
     */
    virtual bool onCanHandleComplexCTM() const { return false; }

    /** Given a "srcBounds" rect, computes destination bounds for this filter.
     *  "dstBounds" are computed by transforming the crop rect by the context's
     *  CTM, applying it to the initial bounds, and intersecting the result with
     *  the context's clip bounds.  "srcBounds" (if non-null) are computed by
     *  intersecting the initial bounds with "dstBounds", to ensure that we never
     *  sample outside of the crop rect (this restriction may be relaxed in the
     *  future).
     */
    bool applyCropRect(const Context&, const SkIRect& srcBounds, SkIRect* dstBounds) const;

    /** A variant of the above call which takes the original source bitmap and
     *  source offset. If the resulting crop rect is not entirely contained by
     *  the source bitmap's bounds, it creates a new bitmap in "result" and
     *  pads the edges with transparent black. In that case, the srcOffset is
     *  modified to be the same as the bounds, since no further adjustment is
     *  needed by the caller. This version should only be used by filters
     *  which are not capable of processing a smaller source bitmap into a
     *  larger destination.
     */
    sk_sp<SkSpecialImage> applyCropRect(const Context&, SkSpecialImage* src, SkIPoint* srcOffset,
        SkIRect* bounds) const;

    /**
     *  Creates a modified Context for use when recursing up the image filter DAG.
     *  The clip bounds are adjusted to accommodate any margins that this
     *  filter requires by calling this node's
     *  onFilterNodeBounds(..., kReverse_MapDirection).
     */
    Context mapContext(const Context& ctx) const;
=======
    virtual bool onIsColorFilterNode(SkColorFilter** /*filterPtr*/) const {
        return false;
    }

    /** Computes source bounds as the src bitmap bounds offset by srcOffset.
     *  Apply the transformed crop rect to the bounds if any of the
     *  corresponding edge flags are set. Intersects the result against the
     *  context's clipBounds, and returns the result in "bounds". If there is
     *  no intersection, returns false and leaves "bounds" unchanged.
     */
    bool applyCropRect(const Context&, const SkBitmap& src, const SkIPoint& srcOffset,
                       SkIRect* bounds) const;

    /** Same as the above call, except that if the resulting crop rect is not
     *  entirely contained by the source bitmap's bounds, it creates a new
     *  bitmap in "result" and pads the edges with transparent black. In that
     *  case, the srcOffset is modified to be the same as the bounds, since no
     *  further adjustment is needed by the caller. This version should only
     *  be used by filters which are not capable of processing a smaller
     *  source bitmap into a larger destination.
     */
    bool applyCropRect(const Context&, Proxy* proxy, const SkBitmap& src, SkIPoint* srcOffset,
                       SkIRect* bounds, SkBitmap* result) const;

    /**
     *  Returns true if the filter can be expressed a single-pass
     *  GrProcessor, used to process this filter on the GPU, or false if
     *  not.
     *
     *  If effect is non-NULL, a new GrProcessor instance is stored
     *  in it.  The caller assumes ownership of the stage, and it is up to the
     *  caller to unref it.
     *
     *  The effect can assume its vertexCoords space maps 1-to-1 with texels
     *  in the texture.  "matrix" is a transformation to apply to filter
     *  parameters before they are used in the effect. Note that this function
     *  will be called with (NULL, NULL, SkMatrix::I()) to query for support,
     *  so returning "true" indicates support for all possible matrices.
     */
    virtual bool asFragmentProcessor(GrFragmentProcessor**, GrProcessorDataManager*, GrTexture*,
                                     const SkMatrix&, const SkIRect& bounds) const;
>>>>>>> miniblink49

private:
    friend class SkGraphics;
    static void PurgeCache();

<<<<<<< HEAD
    void init(sk_sp<SkImageFilter>* inputs, int inputCount, const CropRect* cropRect);

    bool usesSrcInput() const { return fUsesSrcInput; }
    virtual bool affectsTransparentBlack() const { return false; }

    SkAutoSTArray<2, sk_sp<SkImageFilter>> fInputs;

    bool fUsesSrcInput;
    CropRect fCropRect;
    uint32_t fUniqueID; // Globally unique
    mutable SkTArray<SkImageFilterCacheKey> fCacheKeys;
    mutable SkMutex fMutex;
    typedef SkFlattenable INHERITED;
=======
    bool usesSrcInput() const { return fUsesSrcInput; }

    typedef SkFlattenable INHERITED;
    int fInputCount;
    SkImageFilter** fInputs;
    bool fUsesSrcInput;
    CropRect fCropRect;
    uint32_t fUniqueID; // Globally unique
>>>>>>> miniblink49
};

/**
 *  Helper to unflatten the common data, and return NULL if we fail.
 */
<<<<<<< HEAD
#define SK_IMAGEFILTER_UNFLATTEN_COMMON(localVar, expectedCount) \
    Common localVar;                                             \
    do {                                                         \
        if (!localVar.unflatten(buffer, expectedCount)) {        \
            return NULL;                                         \
        }                                                        \
=======
#define SK_IMAGEFILTER_UNFLATTEN_COMMON(localVar, expectedCount)    \
    Common localVar;                                                \
    do {                                                            \
        if (!localVar.unflatten(buffer, expectedCount)) {           \
            return NULL;                                            \
        }                                                           \
>>>>>>> miniblink49
    } while (0)

#endif
