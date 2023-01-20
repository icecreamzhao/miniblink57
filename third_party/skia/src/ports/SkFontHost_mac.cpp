<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkTypes.h" // Keep this before any #ifdef ...
#if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
=======
#include "SkTypes.h"  // Keep this before any #ifdef ...
>>>>>>> miniblink49

#ifdef SK_BUILD_FOR_MAC
#import <ApplicationServices/ApplicationServices.h>
#endif

#ifdef SK_BUILD_FOR_IOS
<<<<<<< HEAD
#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>
#include <CoreText/CTFontManager.h>
#include <CoreText/CoreText.h>
=======
#include <CoreText/CoreText.h>
#include <CoreText/CTFontManager.h>
#include <CoreGraphics/CoreGraphics.h>
#include <CoreFoundation/CoreFoundation.h>
>>>>>>> miniblink49
#endif

#include "SkAdvancedTypefaceMetrics.h"
#include "SkCGUtils.h"
#include "SkColorPriv.h"
#include "SkDescriptor.h"
#include "SkEndian.h"
#include "SkFloatingPoint.h"
#include "SkFontDescriptor.h"
#include "SkFontMgr.h"
#include "SkGlyph.h"
<<<<<<< HEAD
#include "SkMaskGamma.h"
#include "SkMathPriv.h"
=======
#include "SkLazyFnPtr.h"
#include "SkMaskGamma.h"
>>>>>>> miniblink49
#include "SkMutex.h"
#include "SkOTTable_glyf.h"
#include "SkOTTable_head.h"
#include "SkOTTable_hhea.h"
#include "SkOTTable_loca.h"
#include "SkOTUtils.h"
<<<<<<< HEAD
#include "SkOnce.h"
=======
>>>>>>> miniblink49
#include "SkPaint.h"
#include "SkPath.h"
#include "SkSFNTHeader.h"
#include "SkStream.h"
#include "SkString.h"
<<<<<<< HEAD
#include "SkTemplates.h"
#include "SkTypefaceCache.h"
#include "SkTypeface_mac.h"
#include "SkUtils.h"

#include <dlfcn.h>

// Experimental code to use a global lock whenever we access CG, to see if this reduces
// crashes in Chrome
#define USE_GLOBAL_MUTEX_FOR_CG_ACCESS

#ifdef USE_GLOBAL_MUTEX_FOR_CG_ACCESS
SK_DECLARE_STATIC_MUTEX(gCGMutex);
#define AUTO_CG_LOCK() SkAutoMutexAcquire amc(gCGMutex)
#else
#define AUTO_CG_LOCK()
#endif

=======
#include "SkTypefaceCache.h"
#include "SkTypeface_mac.h"
#include "SkUtils.h"
#include "SkUtils.h"

#include <dlfcn.h>

>>>>>>> miniblink49
// Set to make glyph bounding boxes visible.
#define SK_SHOW_TEXT_BLIT_COVERAGE 0

class SkScalerContext_Mac;

// CTFontManagerCopyAvailableFontFamilyNames() is not always available, so we
// provide a wrapper here that will return an empty array if need be.
<<<<<<< HEAD
static CFArrayRef SkCTFontManagerCopyAvailableFontFamilyNames()
{
#ifdef SK_BUILD_FOR_IOS
    return CFArrayCreate(nullptr, nullptr, 0, nullptr);
=======
static CFArrayRef SkCTFontManagerCopyAvailableFontFamilyNames() {
#ifdef SK_BUILD_FOR_IOS
    return CFArrayCreate(NULL, NULL, 0, NULL);
>>>>>>> miniblink49
#else
    return CTFontManagerCopyAvailableFontFamilyNames();
#endif
}

<<<<<<< HEAD
// Being templated and taking const T* prevents calling
// CFSafeRelease(autoCFRelease) through implicit conversion.
template <typename T>
static void CFSafeRelease(/*CFTypeRef*/ const T* cfTypeRef)
{
=======

// Being templated and taking const T* prevents calling
// CFSafeRelease(autoCFRelease) through implicit conversion.
template <typename T> static void CFSafeRelease(/*CFTypeRef*/const T* cfTypeRef) {
>>>>>>> miniblink49
    if (cfTypeRef) {
        CFRelease(cfTypeRef);
    }
}

// Being templated and taking const T* prevents calling
// CFSafeRetain(autoCFRelease) through implicit conversion.
<<<<<<< HEAD
template <typename T>
static void CFSafeRetain(/*CFTypeRef*/ const T* cfTypeRef)
{
=======
template <typename T> static void CFSafeRetain(/*CFTypeRef*/const T* cfTypeRef) {
>>>>>>> miniblink49
    if (cfTypeRef) {
        CFRetain(cfTypeRef);
    }
}

/** Acts like a CFRef, but calls CFSafeRelease when it goes out of scope. */
<<<<<<< HEAD
template <typename CFRef>
class AutoCFRelease : private SkNoncopyable {
public:
    explicit AutoCFRelease(CFRef cfRef = nullptr)
        : fCFRef(cfRef)
    {
    }
    ~AutoCFRelease() { CFSafeRelease(fCFRef); }

    void reset(CFRef that = nullptr)
    {
=======
template<typename CFRef> class AutoCFRelease : private SkNoncopyable {
public:
    explicit AutoCFRelease(CFRef cfRef = NULL) : fCFRef(cfRef) { }
    ~AutoCFRelease() { CFSafeRelease(fCFRef); }

    void reset(CFRef that = NULL) {
>>>>>>> miniblink49
        if (that != fCFRef) {
            CFSafeRelease(fCFRef);
            fCFRef = that;
        }
    }

<<<<<<< HEAD
    CFRef release()
    {
        CFRef self = fCFRef;
        fCFRef = nullptr;
=======
    CFRef detach() {
        CFRef self = fCFRef;
        fCFRef = NULL;
>>>>>>> miniblink49
        return self;
    }

    operator CFRef() const { return fCFRef; }
    CFRef get() const { return fCFRef; }

<<<<<<< HEAD
    CFRef* operator&()
    {
        SkASSERT(fCFRef == nullptr);
        return &fCFRef;
    }

=======
    CFRef* operator&() { SkASSERT(fCFRef == NULL); return &fCFRef; }
>>>>>>> miniblink49
private:
    CFRef fCFRef;
};

<<<<<<< HEAD
static CFStringRef make_CFString(const char str[])
{
    return CFStringCreateWithCString(nullptr, str, kCFStringEncodingUTF8);
}

template <typename T>
class AutoCGTable : SkNoncopyable {
public:
    AutoCGTable(CGFontRef font)
        //Undocumented: the tag parameter in this call is expected in machine order and not BE order.
        : fCFData(CGFontCopyTableForTag(font, SkSetFourByteTag(T::TAG0, T::TAG1, T::TAG2, T::TAG3)))
        , fData(fCFData ? reinterpret_cast<const T*>(CFDataGetBytePtr(fCFData)) : nullptr)
    {
    }
=======
static CFStringRef make_CFString(const char str[]) {
    return CFStringCreateWithCString(NULL, str, kCFStringEncodingUTF8);
}

template<typename T> class AutoCGTable : SkNoncopyable {
public:
    AutoCGTable(CGFontRef font)
    //Undocumented: the tag parameter in this call is expected in machine order and not BE order.
    : fCFData(CGFontCopyTableForTag(font, SkSetFourByteTag(T::TAG0, T::TAG1, T::TAG2, T::TAG3)))
    , fData(fCFData ? reinterpret_cast<const T*>(CFDataGetBytePtr(fCFData)) : NULL)
    { }
>>>>>>> miniblink49

    const T* operator->() const { return fData; }

private:
    AutoCFRelease<CFDataRef> fCFData;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
public:
    const T* fData;
};

// inline versions of these rect helpers

<<<<<<< HEAD
static bool CGRectIsEmpty_inline(const CGRect& rect)
{
    return rect.size.width <= 0 || rect.size.height <= 0;
}

static CGFloat CGRectGetMinX_inline(const CGRect& rect)
{
    return rect.origin.x;
}

static CGFloat CGRectGetMaxX_inline(const CGRect& rect)
{
    return rect.origin.x + rect.size.width;
}

static CGFloat CGRectGetMinY_inline(const CGRect& rect)
{
    return rect.origin.y;
}

static CGFloat CGRectGetMaxY_inline(const CGRect& rect)
{
    return rect.origin.y + rect.size.height;
}

static CGFloat CGRectGetWidth_inline(const CGRect& rect)
{
=======
static bool CGRectIsEmpty_inline(const CGRect& rect) {
    return rect.size.width <= 0 || rect.size.height <= 0;
}

static CGFloat CGRectGetMinX_inline(const CGRect& rect) {
    return rect.origin.x;
}

static CGFloat CGRectGetMaxX_inline(const CGRect& rect) {
    return rect.origin.x + rect.size.width;
}

static CGFloat CGRectGetMinY_inline(const CGRect& rect) {
    return rect.origin.y;
}

static CGFloat CGRectGetMaxY_inline(const CGRect& rect) {
    return rect.origin.y + rect.size.height;
}

static CGFloat CGRectGetWidth_inline(const CGRect& rect) {
>>>>>>> miniblink49
    return rect.size.width;
}

///////////////////////////////////////////////////////////////////////////////

static void sk_memset_rect32(uint32_t* ptr, uint32_t value,
<<<<<<< HEAD
    int width, int height, size_t rowBytes)
{
=======
                             int width, int height, size_t rowBytes) {
>>>>>>> miniblink49
    SkASSERT(width);
    SkASSERT(width * sizeof(uint32_t) <= rowBytes);

    if (width >= 32) {
        while (height) {
            sk_memset32(ptr, value, width);
            ptr = (uint32_t*)((char*)ptr + rowBytes);
            height -= 1;
        }
        return;
    }

    rowBytes -= width * sizeof(uint32_t);

    if (width >= 8) {
        while (height) {
            int w = width;
            do {
<<<<<<< HEAD
                *ptr++ = value;
                *ptr++ = value;
                *ptr++ = value;
                *ptr++ = value;
                *ptr++ = value;
                *ptr++ = value;
                *ptr++ = value;
                *ptr++ = value;
=======
                *ptr++ = value; *ptr++ = value;
                *ptr++ = value; *ptr++ = value;
                *ptr++ = value; *ptr++ = value;
                *ptr++ = value; *ptr++ = value;
>>>>>>> miniblink49
                w -= 8;
            } while (w >= 8);
            while (--w >= 0) {
                *ptr++ = value;
            }
            ptr = (uint32_t*)((char*)ptr + rowBytes);
            height -= 1;
        }
    } else {
        while (height) {
            int w = width;
            do {
                *ptr++ = value;
            } while (--w > 0);
            ptr = (uint32_t*)((char*)ptr + rowBytes);
            height -= 1;
        }
    }
}

#include <sys/utsname.h>

typedef uint32_t CGRGBPixel;

<<<<<<< HEAD
static unsigned CGRGBPixel_getAlpha(CGRGBPixel pixel)
{
=======
static unsigned CGRGBPixel_getAlpha(CGRGBPixel pixel) {
>>>>>>> miniblink49
    return pixel & 0xFF;
}

static const char FONT_DEFAULT_NAME[] = "Lucida Sans";

// See Source/WebKit/chromium/base/mac/mac_util.mm DarwinMajorVersionInternal for original source.
<<<<<<< HEAD
static int readVersion()
{
=======
static int readVersion() {
>>>>>>> miniblink49
    struct utsname info;
    if (uname(&info) != 0) {
        SkDebugf("uname failed\n");
        return 0;
    }
    if (strcmp(info.sysname, "Darwin") != 0) {
        SkDebugf("unexpected uname sysname %s\n", info.sysname);
        return 0;
    }
    char* dot = strchr(info.release, '.');
    if (!dot) {
        SkDebugf("expected dot in uname release %s\n", info.release);
        return 0;
    }
    int version = atoi(info.release);
    if (version == 0) {
        SkDebugf("could not parse uname release %s\n", info.release);
    }
    return version;
}

<<<<<<< HEAD
static int darwinVersion()
{
=======
static int darwinVersion() {
>>>>>>> miniblink49
    static int darwin_version = readVersion();
    return darwin_version;
}

<<<<<<< HEAD
static bool isSnowLeopard()
{
    return darwinVersion() == 10;
}

static bool isLion()
{
    return darwinVersion() == 11;
}

static bool isMountainLion()
{
    return darwinVersion() == 12;
}

static bool isLCDFormat(unsigned format)
{
    return SkMask::kLCD16_Format == format;
}

static CGFloat ScalarToCG(SkScalar scalar)
{
=======
static bool isSnowLeopard() {
    return darwinVersion() == 10;
}

static bool isLion() {
    return darwinVersion() == 11;
}

static bool isMountainLion() {
    return darwinVersion() == 12;
}

static bool isLCDFormat(unsigned format) {
    return SkMask::kLCD16_Format == format;
}

static CGFloat ScalarToCG(SkScalar scalar) {
>>>>>>> miniblink49
    if (sizeof(CGFloat) == sizeof(float)) {
        return SkScalarToFloat(scalar);
    } else {
        SkASSERT(sizeof(CGFloat) == sizeof(double));
<<<<<<< HEAD
        return (CGFloat)SkScalarToDouble(scalar);
    }
}

static SkScalar CGToScalar(CGFloat cgFloat)
{
    if (sizeof(CGFloat) == sizeof(float)) {
        return SkFloatToScalar(cgFloat);
=======
        return (CGFloat) SkScalarToDouble(scalar);
    }
}

static SkScalar CGToScalar(CGFloat cgFloat) {
    if (sizeof(CGFloat) == sizeof(float)) {
        return cgFloat;
>>>>>>> miniblink49
    } else {
        SkASSERT(sizeof(CGFloat) == sizeof(double));
        return SkDoubleToScalar(cgFloat);
    }
}

<<<<<<< HEAD
static float CGToFloat(CGFloat cgFloat)
{
    if (sizeof(CGFloat) == sizeof(float)) {
        return cgFloat;
    } else {
        SkASSERT(sizeof(CGFloat) == sizeof(double));
        return static_cast<float>(cgFloat);
    }
}

static CGAffineTransform MatrixToCGAffineTransform(const SkMatrix& matrix,
    SkScalar sx = SK_Scalar1,
    SkScalar sy = SK_Scalar1)
{
    return CGAffineTransformMake(ScalarToCG(matrix[SkMatrix::kMScaleX] * sx),
        -ScalarToCG(matrix[SkMatrix::kMSkewY] * sy),
        -ScalarToCG(matrix[SkMatrix::kMSkewX] * sx),
        ScalarToCG(matrix[SkMatrix::kMScaleY] * sy),
        ScalarToCG(matrix[SkMatrix::kMTransX] * sx),
        ScalarToCG(matrix[SkMatrix::kMTransY] * sy));
=======
static CGAffineTransform MatrixToCGAffineTransform(const SkMatrix& matrix,
                                                   SkScalar sx = SK_Scalar1,
                                                   SkScalar sy = SK_Scalar1) {
    return CGAffineTransformMake( ScalarToCG(matrix[SkMatrix::kMScaleX] * sx),
                                 -ScalarToCG(matrix[SkMatrix::kMSkewY]  * sy),
                                 -ScalarToCG(matrix[SkMatrix::kMSkewX]  * sx),
                                  ScalarToCG(matrix[SkMatrix::kMScaleY] * sy),
                                  ScalarToCG(matrix[SkMatrix::kMTransX] * sx),
                                  ScalarToCG(matrix[SkMatrix::kMTransY] * sy));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

#define BITMAP_INFO_RGB (kCGImageAlphaNoneSkipFirst | kCGBitmapByteOrder32Host)

/**
 * There does not appear to be a publicly accessable API for determining if lcd
 * font smoothing will be applied if we request it. The main issue is that if
 * smoothing is applied a gamma of 2.0 will be used, if not a gamma of 1.0.
 */
<<<<<<< HEAD
static bool supports_LCD()
{
    static int gSupportsLCD = -1;
    if (gSupportsLCD >= 0) {
        return (bool)gSupportsLCD;
=======
static bool supports_LCD() {
    static int gSupportsLCD = -1;
    if (gSupportsLCD >= 0) {
        return (bool) gSupportsLCD;
>>>>>>> miniblink49
    }
    uint32_t rgb = 0;
    AutoCFRelease<CGColorSpaceRef> colorspace(CGColorSpaceCreateDeviceRGB());
    AutoCFRelease<CGContextRef> cgContext(CGBitmapContextCreate(&rgb, 1, 1, 8, 4,
<<<<<<< HEAD
        colorspace, BITMAP_INFO_RGB));
=======
                                                                colorspace, BITMAP_INFO_RGB));
>>>>>>> miniblink49
    CGContextSelectFont(cgContext, "Helvetica", 16, kCGEncodingMacRoman);
    CGContextSetShouldSmoothFonts(cgContext, true);
    CGContextSetShouldAntialias(cgContext, true);
    CGContextSetTextDrawingMode(cgContext, kCGTextFill);
    CGContextSetGrayFillColor(cgContext, 1, 1);
    CGContextShowTextAtPoint(cgContext, -1, 0, "|", 1);
    uint32_t r = (rgb >> 16) & 0xFF;
<<<<<<< HEAD
    uint32_t g = (rgb >> 8) & 0xFF;
    uint32_t b = (rgb >> 0) & 0xFF;
    gSupportsLCD = (r != g || r != b);
    return (bool)gSupportsLCD;
=======
    uint32_t g = (rgb >>  8) & 0xFF;
    uint32_t b = (rgb >>  0) & 0xFF;
    gSupportsLCD = (r != g || r != b);
    return (bool) gSupportsLCD;
>>>>>>> miniblink49
}

class Offscreen {
public:
    Offscreen()
<<<<<<< HEAD
        : fRGBSpace(nullptr)
        , fCG(nullptr)
=======
        : fRGBSpace(NULL)
        , fCG(NULL)
>>>>>>> miniblink49
        , fDoAA(false)
        , fDoLCD(false)
    {
        fSize.set(0, 0);
    }

    CGRGBPixel* getCG(const SkScalerContext_Mac& context, const SkGlyph& glyph,
<<<<<<< HEAD
        CGGlyph glyphID, size_t* rowBytesPtr,
        bool generateA8FromLCD);
=======
                      CGGlyph glyphID, size_t* rowBytesPtr,
                      bool generateA8FromLCD);
>>>>>>> miniblink49

private:
    enum {
        kSize = 32 * 32 * sizeof(CGRGBPixel)
    };
    SkAutoSMalloc<kSize> fImageStorage;
    AutoCFRelease<CGColorSpaceRef> fRGBSpace;

    // cached state
    AutoCFRelease<CGContextRef> fCG;
    SkISize fSize;
    bool fDoAA;
    bool fDoLCD;

<<<<<<< HEAD
    static int RoundSize(int dimension)
    {
=======
    static int RoundSize(int dimension) {
>>>>>>> miniblink49
        return SkNextPow2(dimension);
    }
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static bool find_dict_float(CFDictionaryRef dict, CFStringRef name, float* value)
{
    CFNumberRef num;
    return CFDictionaryGetValueIfPresent(dict, name, (const void**)&num)
        && CFNumberIsFloatType(num)
        && CFNumberGetValue(num, kCFNumberFloatType, value);
}

static int unit_weight_to_fontstyle(float unit)
{
=======
static bool find_dict_float(CFDictionaryRef dict, CFStringRef name, float* value) {
    CFNumberRef num;
    return CFDictionaryGetValueIfPresent(dict, name, (const void**)&num)
    && CFNumberIsFloatType(num)
    && CFNumberGetValue(num, kCFNumberFloatType, value);
}

static int unit_weight_to_fontstyle(float unit) {
>>>>>>> miniblink49
    float value;
    if (unit < 0) {
        value = 100 + (1 + unit) * 300;
    } else {
        value = 400 + unit * 500;
    }
    return sk_float_round2int(value);
}

<<<<<<< HEAD
static int unit_width_to_fontstyle(float unit)
{
=======
static int unit_width_to_fontstyle(float unit) {
>>>>>>> miniblink49
    float value;
    if (unit < 0) {
        value = 1 + (1 + unit) * 4;
    } else {
        value = 5 + unit * 4;
    }
    return sk_float_round2int(value);
}

<<<<<<< HEAD
static SkFontStyle fontstyle_from_descriptor(CTFontDescriptorRef desc)
{
    AutoCFRelease<CFDictionaryRef> dict(
        (CFDictionaryRef)CTFontDescriptorCopyAttribute(desc, kCTFontTraitsAttribute));
    if (nullptr == dict.get()) {
=======
static SkFontStyle fontstyle_from_descriptor(CTFontDescriptorRef desc) {
    AutoCFRelease<CFDictionaryRef> dict(
            (CFDictionaryRef)CTFontDescriptorCopyAttribute(desc, kCTFontTraitsAttribute));
    if (NULL == dict.get()) {
>>>>>>> miniblink49
        return SkFontStyle();
    }

    float weight, width, slant;
    if (!find_dict_float(dict, kCTFontWeightTrait, &weight)) {
        weight = 0;
    }
    if (!find_dict_float(dict, kCTFontWidthTrait, &width)) {
        width = 0;
    }
    if (!find_dict_float(dict, kCTFontSlantTrait, &slant)) {
        slant = 0;
    }

    return SkFontStyle(unit_weight_to_fontstyle(weight),
<<<<<<< HEAD
        unit_width_to_fontstyle(width),
        slant ? SkFontStyle::kItalic_Slant
              : SkFontStyle::kUpright_Slant);
}

#define WEIGHT_THRESHOLD ((SkFontStyle::kNormal_Weight + SkFontStyle::kBold_Weight) / 2)
=======
                       unit_width_to_fontstyle(width),
                       slant ? SkFontStyle::kItalic_Slant
                       : SkFontStyle::kUpright_Slant);
}

static SkTypeface::Style computeStyleBits(CTFontRef font, bool* isFixedPitch) {
    unsigned style = SkTypeface::kNormal;
    CTFontSymbolicTraits traits = CTFontGetSymbolicTraits(font);

    if (traits & kCTFontBoldTrait) {
        style |= SkTypeface::kBold;
    }
    if (traits & kCTFontItalicTrait) {
        style |= SkTypeface::kItalic;
    }
    if (isFixedPitch) {
        *isFixedPitch = (traits & kCTFontMonoSpaceTrait) != 0;
    }
    return (SkTypeface::Style)style;
}

#define WEIGHT_THRESHOLD    ((SkFontStyle::kNormal_Weight + SkFontStyle::kBold_Weight)/2)
>>>>>>> miniblink49

// kCTFontColorGlyphsTrait was added in the Mac 10.7 and iPhone 4.3 SDKs.
// Being an enum value it is not guarded by version macros, but old SDKs must still be supported.
#if defined(__MAC_10_7) || defined(__IPHONE_4_3)
static const uint32_t SkCTFontColorGlyphsTrait = kCTFontColorGlyphsTrait;
#else
static const uint32_t SkCTFontColorGlyphsTrait = (1 << 13);
#endif

class SkTypeface_Mac : public SkTypeface {
public:
    SkTypeface_Mac(CTFontRef fontRef, CFTypeRef resourceRef,
<<<<<<< HEAD
        const SkFontStyle& fs, bool isFixedPitch,
        bool isLocalStream)
        : SkTypeface(fs, SkTypefaceCache::NewFontID(), isFixedPitch)
=======
                   const SkFontStyle& fs, bool isFixedPitch,
                   const char requestedName[], bool isLocalStream)
        : SkTypeface(fs, SkTypefaceCache::NewFontID(), isFixedPitch)
        , fRequestedName(requestedName)
>>>>>>> miniblink49
        , fFontRef(fontRef) // caller has already called CFRetain for us
        , fOriginatingCFTypeRef(resourceRef) // caller has already called CFRetain for us
        , fHasColorGlyphs(SkToBool(CTFontGetSymbolicTraits(fFontRef) & SkCTFontColorGlyphsTrait))
        , fIsLocalStream(isLocalStream)
    {
        SkASSERT(fontRef);
    }

<<<<<<< HEAD
=======
    SkString fRequestedName;
>>>>>>> miniblink49
    AutoCFRelease<CTFontRef> fFontRef;
    AutoCFRelease<CFTypeRef> fOriginatingCFTypeRef;
    const bool fHasColorGlyphs;

protected:
    int onGetUPEM() const override;
    SkStreamAsset* onOpenStream(int* ttcIndex) const override;
    SkFontData* onCreateFontData() const override;
    void onGetFamilyName(SkString* familyName) const override;
    SkTypeface::LocalizedStrings* onCreateFamilyNameIterator() const override;
    int onGetTableTags(SkFontTableTag tags[]) const override;
    virtual size_t onGetTableData(SkFontTableTag, size_t offset,
<<<<<<< HEAD
        size_t length, void* data) const override;
    SkScalerContext* onCreateScalerContext(const SkScalerContextEffects&,
        const SkDescriptor*) const override;
    void onFilterRec(SkScalerContextRec*) const override;
    void onGetFontDescriptor(SkFontDescriptor*, bool*) const override;
    virtual SkAdvancedTypefaceMetrics* onGetAdvancedTypefaceMetrics(
        PerGlyphInfo,
        const uint32_t*, uint32_t) const override;
    virtual int onCharsToGlyphs(const void* chars, Encoding, uint16_t glyphs[],
        int glyphCount) const override;
=======
                                  size_t length, void* data) const override;
    SkScalerContext* onCreateScalerContext(const SkDescriptor*) const override;
    void onFilterRec(SkScalerContextRec*) const override;
    void onGetFontDescriptor(SkFontDescriptor*, bool*) const override;
    virtual SkAdvancedTypefaceMetrics* onGetAdvancedTypefaceMetrics(
                                PerGlyphInfo,
                                const uint32_t*, uint32_t) const override;
    virtual int onCharsToGlyphs(const void* chars, Encoding, uint16_t glyphs[],
                                int glyphCount) const override;
>>>>>>> miniblink49
    int onCountGlyphs() const override;

private:
    bool fIsLocalStream;

    typedef SkTypeface INHERITED;
};

/** Creates a typeface without searching the cache. Takes ownership of the CTFontRef. */
<<<<<<< HEAD
static SkTypeface* NewFromFontRef(CTFontRef fontRef, CFTypeRef resourceRef, bool isLocalStream)
{
    SkASSERT(fontRef);

    AutoCFRelease<CTFontDescriptorRef> desc(CTFontCopyFontDescriptor(fontRef));
    SkFontStyle style = fontstyle_from_descriptor(desc);

    CTFontSymbolicTraits traits = CTFontGetSymbolicTraits(fontRef);
    bool isFixedPitch = SkToBool(traits & kCTFontMonoSpaceTrait);
    return new SkTypeface_Mac(fontRef, resourceRef, style, isFixedPitch, isLocalStream);
}

static bool find_by_CTFontRef(SkTypeface* cached, void* context)
{
=======
static SkTypeface* NewFromFontRef(CTFontRef fontRef, CFTypeRef resourceRef,
                                  const char name[], bool isLocalStream)
{
    SkASSERT(fontRef);
    bool isFixedPitch;
    SkFontStyle style = SkFontStyle(computeStyleBits(fontRef, &isFixedPitch));

    return new SkTypeface_Mac(fontRef, resourceRef, style, isFixedPitch, name, isLocalStream);
}

static bool find_by_CTFontRef(SkTypeface* cached, const SkFontStyle&, void* context) {
>>>>>>> miniblink49
    CTFontRef self = (CTFontRef)context;
    CTFontRef other = ((SkTypeface_Mac*)cached)->fFontRef;

    return CFEqual(self, other);
}

/** Creates a typeface from a name, searching the cache. */
<<<<<<< HEAD
static SkTypeface* NewFromName(const char familyName[], const SkFontStyle& theStyle)
{
=======
static SkTypeface* NewFromName(const char familyName[], const SkFontStyle& theStyle) {
>>>>>>> miniblink49
    CTFontSymbolicTraits ctFontTraits = 0;
    if (theStyle.weight() >= SkFontStyle::kBold_Weight) {
        ctFontTraits |= kCTFontBoldTrait;
    }
    if (theStyle.slant() != SkFontStyle::kUpright_Slant) {
        ctFontTraits |= kCTFontItalicTrait;
    }

    //TODO: add weight width slant

    // Create the font info
    AutoCFRelease<CFStringRef> cfFontName(make_CFString(familyName));

    AutoCFRelease<CFNumberRef> cfFontTraits(
<<<<<<< HEAD
        CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &ctFontTraits));

    AutoCFRelease<CFMutableDictionaryRef> cfAttributes(
        CFDictionaryCreateMutable(kCFAllocatorDefault, 0,
            &kCFTypeDictionaryKeyCallBacks,
            &kCFTypeDictionaryValueCallBacks));

    AutoCFRelease<CFMutableDictionaryRef> cfTraits(
        CFDictionaryCreateMutable(kCFAllocatorDefault, 0,
            &kCFTypeDictionaryKeyCallBacks,
            &kCFTypeDictionaryValueCallBacks));

    if (!cfFontName || !cfFontTraits || !cfAttributes || !cfTraits) {
        return nullptr;
=======
            CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &ctFontTraits));

    AutoCFRelease<CFMutableDictionaryRef> cfAttributes(
            CFDictionaryCreateMutable(kCFAllocatorDefault, 0,
                                      &kCFTypeDictionaryKeyCallBacks,
                                      &kCFTypeDictionaryValueCallBacks));

    AutoCFRelease<CFMutableDictionaryRef> cfTraits(
            CFDictionaryCreateMutable(kCFAllocatorDefault, 0,
                                      &kCFTypeDictionaryKeyCallBacks,
                                      &kCFTypeDictionaryValueCallBacks));

    if (!cfFontName || !cfFontTraits || !cfAttributes || !cfTraits) {
        return NULL;
>>>>>>> miniblink49
    }

    CFDictionaryAddValue(cfTraits, kCTFontSymbolicTrait, cfFontTraits);

    CFDictionaryAddValue(cfAttributes, kCTFontFamilyNameAttribute, cfFontName);
    CFDictionaryAddValue(cfAttributes, kCTFontTraitsAttribute, cfTraits);

    AutoCFRelease<CTFontDescriptorRef> ctFontDesc(
<<<<<<< HEAD
        CTFontDescriptorCreateWithAttributes(cfAttributes));
    if (!ctFontDesc) {
        return nullptr;
    }

    AutoCFRelease<CTFontRef> ctFont(CTFontCreateWithFontDescriptor(ctFontDesc, 0, nullptr));
    if (!ctFont) {
        return nullptr;
    }

    SkTypeface* face = SkTypefaceCache::FindByProcAndRef(find_by_CTFontRef, (void*)ctFont.get());
    if (face) {
        return face;
    }
    face = NewFromFontRef(ctFont.release(), nullptr, false);
    SkTypefaceCache::Add(face);
=======
            CTFontDescriptorCreateWithAttributes(cfAttributes));
    if (!ctFontDesc) {
        return NULL;
    }

    AutoCFRelease<CTFontRef> ctFont(CTFontCreateWithFontDescriptor(ctFontDesc, 0, NULL));
    if (!ctFont) {
        return NULL;
    }

    SkTypeface* face = SkTypefaceCache::FindByProcAndRef(find_by_CTFontRef, (void*)ctFont.get());
    if (!face) {
        face = NewFromFontRef(ctFont.detach(), NULL, NULL, false);
        SkTypefaceCache::Add(face, face->fontStyle());
    }
>>>>>>> miniblink49
    return face;
}

SK_DECLARE_STATIC_MUTEX(gGetDefaultFaceMutex);
<<<<<<< HEAD
static SkTypeface* GetDefaultFace()
{
=======
static SkTypeface* GetDefaultFace() {
>>>>>>> miniblink49
    SkAutoMutexAcquire ma(gGetDefaultFaceMutex);

    static SkTypeface* gDefaultFace;

<<<<<<< HEAD
    if (nullptr == gDefaultFace) {
        gDefaultFace = NewFromName(FONT_DEFAULT_NAME, SkFontStyle());
=======
    if (NULL == gDefaultFace) {
        gDefaultFace = NewFromName(FONT_DEFAULT_NAME, SkFontStyle());
        SkTypefaceCache::Add(gDefaultFace, SkFontStyle());
>>>>>>> miniblink49
    }
    return gDefaultFace;
}

///////////////////////////////////////////////////////////////////////////////

extern CTFontRef SkTypeface_GetCTFontRef(const SkTypeface* face);
<<<<<<< HEAD
CTFontRef SkTypeface_GetCTFontRef(const SkTypeface* face)
{
    const SkTypeface_Mac* macface = (const SkTypeface_Mac*)face;
    return macface ? macface->fFontRef.get() : nullptr;
=======
CTFontRef SkTypeface_GetCTFontRef(const SkTypeface* face) {
    const SkTypeface_Mac* macface = (const SkTypeface_Mac*)face;
    return macface ? macface->fFontRef.get() : NULL;
>>>>>>> miniblink49
}

/*  This function is visible on the outside. It first searches the cache, and if
 *  not found, returns a new entry (after adding it to the cache).
 */
<<<<<<< HEAD
SkTypeface* SkCreateTypefaceFromCTFont(CTFontRef fontRef, CFTypeRef resourceRef)
{
    SkTypeface* face = SkTypefaceCache::FindByProcAndRef(find_by_CTFontRef, (void*)fontRef);
    if (face) {
        return face;
    }
    CFRetain(fontRef);
    if (resourceRef) {
        CFRetain(resourceRef);
    }
    face = NewFromFontRef(fontRef, resourceRef, false);
    SkTypefaceCache::Add(face);
    return face;
}

static const char* map_css_names(const char* name)
{
    static const struct {
        const char* fFrom; // name the caller specified
        const char* fTo; // "canonical" name we map to
    } gPairs[] = {
        { "sans-serif", "Helvetica" },
        { "serif", "Times" },
        { "monospace", "Courier" }
=======
SkTypeface* SkCreateTypefaceFromCTFont(CTFontRef fontRef, CFTypeRef resourceRef) {
    SkTypeface* face = SkTypefaceCache::FindByProcAndRef(find_by_CTFontRef, (void*)fontRef);
    if (!face) {
        CFRetain(fontRef);
        if (resourceRef) {
            CFRetain(resourceRef);
        }
        face = NewFromFontRef(fontRef, resourceRef, NULL, false);
        SkTypefaceCache::Add(face, face->fontStyle());
    }
    return face;
}

struct NameStyle {
    const char* fName;
    SkFontStyle fStyle;
};

static bool find_by_NameStyle(SkTypeface* cachedFace, const SkFontStyle& cachedStyle, void* ctx) {
    const SkTypeface_Mac* cachedMacFace = static_cast<SkTypeface_Mac*>(cachedFace);
    const NameStyle* requested = static_cast<const NameStyle*>(ctx);

    return cachedStyle == requested->fStyle
        && cachedMacFace->fRequestedName.equals(requested->fName);
}

static const char* map_css_names(const char* name) {
    static const struct {
        const char* fFrom;  // name the caller specified
        const char* fTo;    // "canonical" name we map to
    } gPairs[] = {
        { "sans-serif", "Helvetica" },
        { "serif",      "Times"     },
        { "monospace",  "Courier"   }
>>>>>>> miniblink49
    };

    for (size_t i = 0; i < SK_ARRAY_COUNT(gPairs); i++) {
        if (strcmp(name, gPairs[i].fFrom) == 0) {
            return gPairs[i].fTo;
        }
    }
<<<<<<< HEAD
    return name; // no change
=======
    return name;    // no change
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

/** GlyphRect is in FUnits (em space, y up). */
struct GlyphRect {
    int16_t fMinX;
    int16_t fMinY;
    int16_t fMaxX;
    int16_t fMaxY;
};

class SkScalerContext_Mac : public SkScalerContext {
public:
<<<<<<< HEAD
    SkScalerContext_Mac(SkTypeface_Mac*, const SkScalerContextEffects&, const SkDescriptor*);
=======
    SkScalerContext_Mac(SkTypeface_Mac*, const SkDescriptor*);
>>>>>>> miniblink49

protected:
    unsigned generateGlyphCount(void) override;
    uint16_t generateCharToGlyph(SkUnichar uni) override;
    void generateAdvance(SkGlyph* glyph) override;
    void generateMetrics(SkGlyph* glyph) override;
    void generateImage(const SkGlyph& glyph) override;
    void generatePath(const SkGlyph& glyph, SkPath* path) override;
    void generateFontMetrics(SkPaint::FontMetrics*) override;

private:
<<<<<<< HEAD
    static void CTPathElement(void* info, const CGPathElement* element);
=======
    static void CTPathElement(void *info, const CGPathElement *element);
>>>>>>> miniblink49

    /** Returns the offset from the horizontal origin to the vertical origin in SkGlyph units. */
    void getVerticalOffset(CGGlyph glyphID, SkPoint* offset) const;

    /** Initializes and returns the value of fFBoundingBoxesGlyphOffset.
     *
     *  For use with (and must be called before) generateBBoxes.
     */
    uint16_t getFBoundingBoxesGlyphOffset();

    /** Initializes fFBoundingBoxes and returns true on success.
     *
     *  On Lion and Mountain Lion, CTFontGetBoundingRectsForGlyphs has a bug which causes it to
     *  return a bad value in bounds.origin.x for SFNT fonts whose hhea::numberOfHMetrics is
     *  less than its maxp::numGlyphs. When this is the case we try to read the bounds from the
     *  font directly.
     *
     *  This routine initializes fFBoundingBoxes to an array of
     *  fGlyphCount - fFBoundingBoxesGlyphOffset GlyphRects which contain the bounds in FUnits
     *  (em space, y up) of glyphs with ids in the range [fFBoundingBoxesGlyphOffset, fGlyphCount).
     *
     *  Returns true if fFBoundingBoxes is properly initialized. The table can only be properly
     *  initialized for a TrueType font with 'head', 'loca', and 'glyf' tables.
     *
     *  TODO: A future optimization will compute fFBoundingBoxes once per fCTFont.
     */
    bool generateBBoxes();

    /** Converts from FUnits (em space, y up) to SkGlyph units (pixels, y down).
     *
     *  Used on Snow Leopard to correct CTFontGetVerticalTranslationsForGlyphs.
     *  Used on Lion to correct CTFontGetBoundingRectsForGlyphs.
     */
    SkMatrix fFUnitMatrix;

    Offscreen fOffscreen;
<<<<<<< HEAD
=======
    AutoCFRelease<CTFontRef> fCTFont;
    CGAffineTransform fTransform;
    CGAffineTransform fInvTransform;
>>>>>>> miniblink49

    /** Unrotated variant of fCTFont.
     *
     *  In 10.10.1 CTFontGetAdvancesForGlyphs applies the font transform to the width of the
     *  advances, but always sets the height to 0. This font is used to get the advances of the
     *  unrotated glyph, and then the rotation is applied separately.
     *
     *  CT vertical metrics are pre-rotated (in em space, before transform) 90deg clock-wise.
     *  This makes kCTFontDefaultOrientation dangerous, because the metrics from
     *  kCTFontHorizontalOrientation are in a different space from kCTFontVerticalOrientation.
     *  With kCTFontVerticalOrientation the advances must be unrotated.
<<<<<<< HEAD
     *
     *  Sometimes, creating a copy of a CTFont with the same size but different trasform will select
     *  different underlying font data. As a result, avoid ever creating more than one CTFont per
     *  SkScalerContext to ensure that only one CTFont is used.
     *
     *  As a result of the above (and other constraints) this font contains the size, but not the
     *  transform. The transform must always be applied separately.
     */
    AutoCFRelease<CTFontRef> fCTFont;

    /** The transform without the font size. */
    CGAffineTransform fTransform;
    CGAffineTransform fInvTransform;
=======
     */
    AutoCFRelease<CTFontRef> fCTUnrotatedFont;
>>>>>>> miniblink49

    AutoCFRelease<CGFontRef> fCGFont;
    SkAutoTMalloc<GlyphRect> fFBoundingBoxes;
    uint16_t fFBoundingBoxesGlyphOffset;
    uint16_t fGlyphCount;
    bool fGeneratedFBoundingBoxes;
    const bool fDoSubPosition;
    const bool fVertical;

    friend class Offscreen;

    typedef SkScalerContext INHERITED;
};

<<<<<<< HEAD
// CTFontCreateCopyWithAttributes or CTFontCreateCopyWithSymbolicTraits cannot be used on 10.10
// and later, as they will return different underlying fonts depending on the size requested.
// It is not possible to use descriptors with CTFontCreateWithFontDescriptor, since that does not
// work with non-system fonts. As a result, create the strike specific CTFonts from the underlying
// CGFont.
static CTFontRef ctfont_create_exact_copy(CTFontRef baseFont, CGFloat textSize,
    const CGAffineTransform* transform)
{
    AutoCFRelease<CGFontRef> baseCGFont(CTFontCopyGraphicsFont(baseFont, nullptr));

    // The last parameter (CTFontDescriptorRef attributes) *must* be nullptr.
    // If non-nullptr then with fonts with variation axes, the copy will fail in
    // CGFontVariationFromDictCallback when it assumes kCGFontVariationAxisName is CFNumberRef
    // which it quite obviously is not.

    // Because we cannot setup the CTFont descriptor to match, the same restriction applies here
    // as other uses of CTFontCreateWithGraphicsFont which is that such CTFonts should not escape
    // the scaler context, since they aren't 'normal'.
    return CTFontCreateWithGraphicsFont(baseCGFont, textSize, transform, nullptr);
}

SkScalerContext_Mac::SkScalerContext_Mac(SkTypeface_Mac* typeface,
    const SkScalerContextEffects& effects,
    const SkDescriptor* desc)
    : INHERITED(typeface, effects, desc)
    , fFBoundingBoxes()
    , fFBoundingBoxesGlyphOffset(0)
    , fGeneratedFBoundingBoxes(false)
    , fDoSubPosition(SkToBool(fRec.fFlags & kSubpixelPositioning_Flag))
    , fVertical(SkToBool(fRec.fFlags & kVertical_Flag))

{
    AUTO_CG_LOCK();

=======
SkScalerContext_Mac::SkScalerContext_Mac(SkTypeface_Mac* typeface,
                                         const SkDescriptor* desc)
        : INHERITED(typeface, desc)
        , fFBoundingBoxes()
        , fFBoundingBoxesGlyphOffset(0)
        , fGeneratedFBoundingBoxes(false)
        , fDoSubPosition(SkToBool(fRec.fFlags & kSubpixelPositioning_Flag))
        , fVertical(SkToBool(fRec.fFlags & kVertical_Flag))

{
>>>>>>> miniblink49
    CTFontRef ctFont = typeface->fFontRef.get();
    CFIndex numGlyphs = CTFontGetGlyphCount(ctFont);
    SkASSERT(numGlyphs >= 1 && numGlyphs <= 0xFFFF);
    fGlyphCount = SkToU16(numGlyphs);

    // CT on (at least) 10.9 will size color glyphs down from the requested size, but not up.
    // As a result, it is necessary to know the actual device size and request that.
    SkVector scale;
    SkMatrix skTransform;
    fRec.computeMatrices(SkScalerContextRec::kVertical_PreMatrixScale, &scale, &skTransform,
<<<<<<< HEAD
        nullptr, nullptr, &fFUnitMatrix);
    fTransform = MatrixToCGAffineTransform(skTransform);
    fInvTransform = CGAffineTransformInvert(fTransform);

    // The transform contains everything except the requested text size.
    // Some properties, like 'trak', are based on the text size (before applying the matrix).
    CGFloat textSize = ScalarToCG(scale.y());
    fCTFont.reset(ctfont_create_exact_copy(ctFont, textSize, nullptr));
    fCGFont.reset(CTFontCopyGraphicsFont(fCTFont, nullptr));
=======
                         NULL, NULL, &fFUnitMatrix);
    fTransform = MatrixToCGAffineTransform(skTransform);
    fInvTransform = CGAffineTransformInvert(fTransform);

    AutoCFRelease<CTFontDescriptorRef> ctFontDesc;
    if (fVertical) {
        // Setting the vertical orientation here is required for vertical metrics on some versions.
        AutoCFRelease<CFMutableDictionaryRef> cfAttributes(CFDictionaryCreateMutable(
                kCFAllocatorDefault, 0,
                &kCFTypeDictionaryKeyCallBacks,
                &kCFTypeDictionaryValueCallBacks));
        if (cfAttributes) {
            CTFontOrientation ctOrientation = kCTFontVerticalOrientation;
            AutoCFRelease<CFNumberRef> cfVertical(CFNumberCreate(
                    kCFAllocatorDefault, kCFNumberSInt32Type, &ctOrientation));
            CFDictionaryAddValue(cfAttributes, kCTFontOrientationAttribute, cfVertical);
            ctFontDesc.reset(CTFontDescriptorCreateWithAttributes(cfAttributes));
        }
    }

    // The transform contains everything except the requested text size.
    // Some properties, like 'trak', are based on the text size (before applying the matrix).
    CGFloat textSize = ScalarToCG(scale.y());

    fCTFont.reset(CTFontCreateCopyWithAttributes(ctFont, textSize, &fTransform, ctFontDesc));
    fCGFont.reset(CTFontCopyGraphicsFont(fCTFont, NULL));
    fCTUnrotatedFont.reset(CTFontCreateCopyWithAttributes(ctFont, textSize,
                                                          &CGAffineTransformIdentity, NULL));
>>>>>>> miniblink49

    // The fUnitMatrix includes the text size (and em) as it is used to scale the raw font data.
    SkScalar emPerFUnit = SkScalarInvert(SkIntToScalar(CGFontGetUnitsPerEm(fCGFont)));
    fFUnitMatrix.preScale(emPerFUnit, -emPerFUnit);
}

<<<<<<< HEAD
/** This is an implementation of CTFontDrawGlyphs for 10.6; it was introduced in 10.7. */
static void legacy_CTFontDrawGlyphs(CTFontRef, const CGGlyph glyphs[], const CGPoint points[],
    size_t count, CGContextRef cg)
=======
extern "C" {

/** CTFontDrawGlyphs was introduced in 10.7. */
typedef void (*CTFontDrawGlyphsProc)(CTFontRef, const CGGlyph[], const CGPoint[],
                                     size_t, CGContextRef);

/** This is an implementation of CTFontDrawGlyphs for 10.6. */
static void sk_legacy_CTFontDrawGlyphs(CTFontRef, const CGGlyph glyphs[], const CGPoint points[],
                                       size_t count, CGContextRef cg)
>>>>>>> miniblink49
{
    CGContextShowGlyphsAtPositions(cg, glyphs, points, count);
}

<<<<<<< HEAD
typedef decltype(legacy_CTFontDrawGlyphs) CTFontDrawGlyphsProc;

static CTFontDrawGlyphsProc* choose_CTFontDrawGlyphs()
{
    if (void* real = dlsym(RTLD_DEFAULT, "CTFontDrawGlyphs")) {
        return (CTFontDrawGlyphsProc*)real;
    }
    return &legacy_CTFontDrawGlyphs;
}

CGRGBPixel* Offscreen::getCG(const SkScalerContext_Mac& context, const SkGlyph& glyph,
    CGGlyph glyphID, size_t* rowBytesPtr,
    bool generateA8FromLCD)
{
    static SkOnce once;
    static CTFontDrawGlyphsProc* ctFontDrawGlyphs;
    once([] { ctFontDrawGlyphs = choose_CTFontDrawGlyphs(); });
=======
}

CTFontDrawGlyphsProc SkChooseCTFontDrawGlyphs() {
    CTFontDrawGlyphsProc realCTFontDrawGlyphs;
    *reinterpret_cast<void**>(&realCTFontDrawGlyphs) = dlsym(RTLD_DEFAULT, "CTFontDrawGlyphs");
    return realCTFontDrawGlyphs ? realCTFontDrawGlyphs : sk_legacy_CTFontDrawGlyphs;
};

SK_DECLARE_STATIC_LAZY_FN_PTR(CTFontDrawGlyphsProc, gCTFontDrawGlyphs, SkChooseCTFontDrawGlyphs);

CGRGBPixel* Offscreen::getCG(const SkScalerContext_Mac& context, const SkGlyph& glyph,
                             CGGlyph glyphID, size_t* rowBytesPtr,
                             bool generateA8FromLCD)
{
    CTFontDrawGlyphsProc ctFontDrawGlyphs = gCTFontDrawGlyphs.get();
>>>>>>> miniblink49

    if (!fRGBSpace) {
        //It doesn't appear to matter what color space is specified.
        //Regular blends and antialiased text are always (s*a + d*(1-a))
        //and smoothed text is always g=2.0.
        fRGBSpace.reset(CGColorSpaceCreateDeviceRGB());
    }

    // default to kBW_Format
    bool doAA = false;
    bool doLCD = false;

    if (SkMask::kBW_Format != glyph.fMaskFormat) {
        doLCD = true;
        doAA = true;
    }

    // FIXME: lcd smoothed un-hinted rasterization unsupported.
    if (!generateA8FromLCD && SkMask::kA8_Format == glyph.fMaskFormat) {
        doLCD = false;
        doAA = true;
    }

    // If this font might have color glyphs, disable LCD as there's no way to support it.
    // CoreText doesn't tell us which format it ended up using, so we can't detect it.
<<<<<<< HEAD
    // A8 will end up black on transparent, but TODO: we can detect gray and set to A8.
=======
    // A8 will be ugly too (white on transparent), but TODO: we can detect gray and set to A8.
>>>>>>> miniblink49
    if (SkMask::kARGB32_Format == glyph.fMaskFormat) {
        doLCD = false;
    }

    size_t rowBytes = fSize.fWidth * sizeof(CGRGBPixel);
    if (!fCG || fSize.fWidth < glyph.fWidth || fSize.fHeight < glyph.fHeight) {
        if (fSize.fWidth < glyph.fWidth) {
            fSize.fWidth = RoundSize(glyph.fWidth);
        }
        if (fSize.fHeight < glyph.fHeight) {
            fSize.fHeight = RoundSize(glyph.fHeight);
        }

        rowBytes = fSize.fWidth * sizeof(CGRGBPixel);
        void* image = fImageStorage.reset(rowBytes * fSize.fHeight);
        const CGImageAlphaInfo alpha = (SkMask::kARGB32_Format == glyph.fMaskFormat)
<<<<<<< HEAD
            ? kCGImageAlphaPremultipliedFirst
            : kCGImageAlphaNoneSkipFirst;
        const CGBitmapInfo bitmapInfo = kCGBitmapByteOrder32Host | alpha;
        fCG.reset(CGBitmapContextCreate(image, fSize.fWidth, fSize.fHeight, 8,
            rowBytes, fRGBSpace, bitmapInfo));
=======
                                     ? kCGImageAlphaPremultipliedFirst
                                     : kCGImageAlphaNoneSkipFirst;
        const CGBitmapInfo bitmapInfo = kCGBitmapByteOrder32Host | alpha;
        fCG.reset(CGBitmapContextCreate(image, fSize.fWidth, fSize.fHeight, 8,
                                        rowBytes, fRGBSpace, bitmapInfo));
>>>>>>> miniblink49

        // Skia handles quantization and subpixel positioning,
        // so disable quantization and enabe subpixel positioning in CG.
        CGContextSetAllowsFontSubpixelQuantization(fCG, false);
        CGContextSetShouldSubpixelQuantizeFonts(fCG, false);

        // Because CG always draws from the horizontal baseline,
        // if there is a non-integral translation from the horizontal origin to the vertical origin,
        // then CG cannot draw the glyph in the correct location without subpixel positioning.
        CGContextSetAllowsFontSubpixelPositioning(fCG, true);
        CGContextSetShouldSubpixelPositionFonts(fCG, true);

        CGContextSetTextDrawingMode(fCG, kCGTextFill);

<<<<<<< HEAD
        // Draw black on white to create mask. (Special path exists to speed this up in CG.)
        CGContextSetGrayFillColor(fCG, 0.0f, 1.0f);
=======
        // Draw white on black to create mask.
        // TODO: Draw black on white and invert, CG has a special case codepath.
        CGContextSetGrayFillColor(fCG, 1.0f, 1.0f);
>>>>>>> miniblink49

        // force our checks below to happen
        fDoAA = !doAA;
        fDoLCD = !doLCD;

<<<<<<< HEAD
        if (legacy_CTFontDrawGlyphs == ctFontDrawGlyphs) {
=======
        if (sk_legacy_CTFontDrawGlyphs == ctFontDrawGlyphs) {
>>>>>>> miniblink49
            // CTFontDrawGlyphs will apply the font, font size, and font matrix to the CGContext.
            // Our 'fake' one does not, so set up the CGContext here.
            CGContextSetFont(fCG, context.fCGFont);
            CGContextSetFontSize(fCG, CTFontGetSize(context.fCTFont));
        }
        CGContextSetTextMatrix(fCG, context.fTransform);
    }

    if (fDoAA != doAA) {
        CGContextSetShouldAntialias(fCG, doAA);
        fDoAA = doAA;
    }
    if (fDoLCD != doLCD) {
        CGContextSetShouldSmoothFonts(fCG, doLCD);
        fDoLCD = doLCD;
    }

    CGRGBPixel* image = (CGRGBPixel*)fImageStorage.get();
    // skip rows based on the glyph's height
    image += (fSize.fHeight - glyph.fHeight) * fSize.fWidth;

<<<<<<< HEAD
    // Erase to white (or transparent black if it's a color glyph, to not composite against white).
    uint32_t bgColor = (SkMask::kARGB32_Format != glyph.fMaskFormat) ? 0xFFFFFFFF : 0x00000000;
    sk_memset_rect32(image, bgColor, glyph.fWidth, glyph.fHeight, rowBytes);
=======
    // erase to black
    sk_memset_rect32(image, 0, glyph.fWidth, glyph.fHeight, rowBytes);
>>>>>>> miniblink49

    float subX = 0;
    float subY = 0;
    if (context.fDoSubPosition) {
        subX = SkFixedToFloat(glyph.getSubXFixed());
        subY = SkFixedToFloat(glyph.getSubYFixed());
    }

    // CoreText and CoreGraphics always draw using the horizontal baseline origin.
    if (context.fVertical) {
        SkPoint offset;
        context.getVerticalOffset(glyphID, &offset);
        subX += offset.fX;
        subY += offset.fY;
    }

    CGPoint point = CGPointMake(-glyph.fLeft + subX, glyph.fTop + glyph.fHeight - subY);
    // Prior to 10.10, CTFontDrawGlyphs acted like CGContextShowGlyphsAtPositions and took
    // 'positions' which are in text space. The glyph location (in device space) must be
    // mapped into text space, so that CG can convert it back into device space.
    // In 10.10.1, this is handled directly in CTFontDrawGlyphs.
    //
    // However, in 10.10.2 color glyphs no longer rotate based on the font transform.
    // So always make the font transform identity and place the transform on the context.
    point = CGPointApplyAffineTransform(point, context.fInvTransform);

<<<<<<< HEAD
    ctFontDrawGlyphs(context.fCTFont, &glyphID, &point, 1, fCG);
=======
    ctFontDrawGlyphs(context.fCTUnrotatedFont, &glyphID, &point, 1, fCG);
>>>>>>> miniblink49

    SkASSERT(rowBytesPtr);
    *rowBytesPtr = rowBytes;
    return image;
}

<<<<<<< HEAD
void SkScalerContext_Mac::getVerticalOffset(CGGlyph glyphID, SkPoint* offset) const
{
=======
void SkScalerContext_Mac::getVerticalOffset(CGGlyph glyphID, SkPoint* offset) const {
>>>>>>> miniblink49
    // Snow Leopard returns cgVertOffset in completely un-transformed FUnits (em space, y up).
    // Lion and Leopard return cgVertOffset in CG units (pixels, y up).
    CGSize cgVertOffset;
    CTFontGetVerticalTranslationsForGlyphs(fCTFont, &glyphID, &cgVertOffset, 1);
<<<<<<< HEAD
    if (isSnowLeopard()) {
        SkPoint skVertOffset = { CGToScalar(cgVertOffset.width), CGToScalar(cgVertOffset.height) };
        // From FUnits (em space, y up) to SkGlyph units (pixels, y down).
        fFUnitMatrix.mapPoints(&skVertOffset, 1);
        *offset = skVertOffset;
        return;
    }
    cgVertOffset = CGSizeApplyAffineTransform(cgVertOffset, fTransform);
    SkPoint skVertOffset = { CGToScalar(cgVertOffset.width), CGToScalar(cgVertOffset.height) };
    // From CG units (pixels, y up) to SkGlyph units (pixels, y down).
    skVertOffset.fY = -skVertOffset.fY;
    *offset = skVertOffset;
}

uint16_t SkScalerContext_Mac::getFBoundingBoxesGlyphOffset()
{
=======

    SkPoint skVertOffset = { CGToScalar(cgVertOffset.width), CGToScalar(cgVertOffset.height) };
    if (isSnowLeopard()) {
        // From FUnits (em space, y up) to SkGlyph units (pixels, y down).
        fFUnitMatrix.mapPoints(&skVertOffset, 1);
    } else {
        // From CG units (pixels, y up) to SkGlyph units (pixels, y down).
        skVertOffset.fY = -skVertOffset.fY;
    }

    *offset = skVertOffset;
}

uint16_t SkScalerContext_Mac::getFBoundingBoxesGlyphOffset() {
>>>>>>> miniblink49
    if (fFBoundingBoxesGlyphOffset) {
        return fFBoundingBoxesGlyphOffset;
    }
    fFBoundingBoxesGlyphOffset = fGlyphCount; // fallback for all fonts
    AutoCGTable<SkOTTableHorizontalHeader> hheaTable(fCGFont);
    if (hheaTable.fData) {
        fFBoundingBoxesGlyphOffset = SkEndian_SwapBE16(hheaTable->numberOfHMetrics);
    }
    return fFBoundingBoxesGlyphOffset;
}

<<<<<<< HEAD
bool SkScalerContext_Mac::generateBBoxes()
{
=======
bool SkScalerContext_Mac::generateBBoxes() {
>>>>>>> miniblink49
    if (fGeneratedFBoundingBoxes) {
        return SkToBool(fFBoundingBoxes.get());
    }
    fGeneratedFBoundingBoxes = true;

    AutoCGTable<SkOTTableHead> headTable(fCGFont);
    if (!headTable.fData) {
        return false;
    }

    AutoCGTable<SkOTTableIndexToLocation> locaTable(fCGFont);
    if (!locaTable.fData) {
        return false;
    }

    AutoCGTable<SkOTTableGlyph> glyfTable(fCGFont);
    if (!glyfTable.fData) {
        return false;
    }

    uint16_t entries = fGlyphCount - fFBoundingBoxesGlyphOffset;
    fFBoundingBoxes.reset(entries);

    SkOTTableHead::IndexToLocFormat locaFormat = headTable->indexToLocFormat;
    SkOTTableGlyph::Iterator glyphDataIter(*glyfTable.fData, *locaTable.fData, locaFormat);
    glyphDataIter.advance(fFBoundingBoxesGlyphOffset);
    for (uint16_t boundingBoxesIndex = 0; boundingBoxesIndex < entries; ++boundingBoxesIndex) {
        const SkOTTableGlyphData* glyphData = glyphDataIter.next();
        GlyphRect& rect = fFBoundingBoxes[boundingBoxesIndex];
        rect.fMinX = SkEndian_SwapBE16(glyphData->xMin);
        rect.fMinY = SkEndian_SwapBE16(glyphData->yMin);
        rect.fMaxX = SkEndian_SwapBE16(glyphData->xMax);
        rect.fMaxY = SkEndian_SwapBE16(glyphData->yMax);
    }

    return true;
}

<<<<<<< HEAD
unsigned SkScalerContext_Mac::generateGlyphCount(void)
{
    return fGlyphCount;
}

uint16_t SkScalerContext_Mac::generateCharToGlyph(SkUnichar uni)
{
    AUTO_CG_LOCK();

=======
unsigned SkScalerContext_Mac::generateGlyphCount(void) {
    return fGlyphCount;
}

uint16_t SkScalerContext_Mac::generateCharToGlyph(SkUnichar uni) {
>>>>>>> miniblink49
    CGGlyph cgGlyph[2];
    UniChar theChar[2]; // UniChar is a UTF-16 16-bit code unit.

    // Get the glyph
    size_t numUniChar = SkUTF16_FromUnichar(uni, theChar);
    SkASSERT(sizeof(CGGlyph) <= sizeof(uint16_t));

    // Undocumented behavior of CTFontGetGlyphsForCharacters with non-bmp code points:
    // When a surrogate pair is detected, the glyph index used is the index of the high surrogate.
    // It is documented that if a mapping is unavailable, the glyph will be set to 0.
    CTFontGetGlyphsForCharacters(fCTFont, theChar, cgGlyph, numUniChar);
    return cgGlyph[0];
}

<<<<<<< HEAD
void SkScalerContext_Mac::generateAdvance(SkGlyph* glyph)
{
    this->generateMetrics(glyph);
}

void SkScalerContext_Mac::generateMetrics(SkGlyph* glyph)
{
    AUTO_CG_LOCK();

    const CGGlyph cgGlyph = (CGGlyph)glyph->getGlyphID();
=======
void SkScalerContext_Mac::generateAdvance(SkGlyph* glyph) {
    this->generateMetrics(glyph);
}

void SkScalerContext_Mac::generateMetrics(SkGlyph* glyph) {
    const CGGlyph cgGlyph = (CGGlyph) glyph->getGlyphID();
>>>>>>> miniblink49
    glyph->zeroMetrics();

    // The following block produces cgAdvance in CG units (pixels, y up).
    CGSize cgAdvance;
    if (fVertical) {
<<<<<<< HEAD
        CTFontGetAdvancesForGlyphs(fCTFont, kCTFontVerticalOrientation,
            &cgGlyph, &cgAdvance, 1);
=======
        CTFontGetAdvancesForGlyphs(fCTUnrotatedFont, kCTFontVerticalOrientation,
                                   &cgGlyph, &cgAdvance, 1);
>>>>>>> miniblink49
        // Vertical advances are returned as widths instead of heights.
        SkTSwap(cgAdvance.height, cgAdvance.width);
        cgAdvance.height = -cgAdvance.height;
    } else {
<<<<<<< HEAD
        CTFontGetAdvancesForGlyphs(fCTFont, kCTFontHorizontalOrientation,
            &cgGlyph, &cgAdvance, 1);
    }
    cgAdvance = CGSizeApplyAffineTransform(cgAdvance, fTransform);
    glyph->fAdvanceX = CGToFloat(cgAdvance.width);
    glyph->fAdvanceY = -CGToFloat(cgAdvance.height);
=======
        CTFontGetAdvancesForGlyphs(fCTUnrotatedFont, kCTFontHorizontalOrientation,
                                   &cgGlyph, &cgAdvance, 1);
    }
    cgAdvance = CGSizeApplyAffineTransform(cgAdvance, CTFontGetMatrix(fCTFont));
    glyph->fAdvanceX =  SkFloatToFixed_Check(cgAdvance.width);
    glyph->fAdvanceY = -SkFloatToFixed_Check(cgAdvance.height);
>>>>>>> miniblink49

    // The following produces skBounds in SkGlyph units (pixels, y down),
    // or returns early if skBounds would be empty.
    SkRect skBounds;

    // On Mountain Lion, CTFontGetBoundingRectsForGlyphs with kCTFontVerticalOrientation and
    // CTFontGetVerticalTranslationsForGlyphs do not agree when using OTF CFF fonts.
    // For TTF fonts these two do agree and we can use CTFontGetBoundingRectsForGlyphs to get
    // the bounding box and CTFontGetVerticalTranslationsForGlyphs to then draw the glyph
    // inside that bounding box. However, with OTF CFF fonts this does not work. It appears that
    // CTFontGetBoundingRectsForGlyphs with kCTFontVerticalOrientation on OTF CFF fonts tries
    // to center the glyph along the vertical baseline and also perform some mysterious shift
    // along the baseline. CTFontGetVerticalTranslationsForGlyphs does not appear to perform
    // these steps.
    //
    // It is not known which is correct (or if either is correct). However, we must always draw
    // from the horizontal origin and must use CTFontGetVerticalTranslationsForGlyphs to draw.
    // As a result, we do not call CTFontGetBoundingRectsForGlyphs for vertical glyphs.

    // On Snow Leopard, CTFontGetBoundingRectsForGlyphs ignores kCTFontVerticalOrientation and
    // returns horizontal bounds.

    // On Lion and Mountain Lion, CTFontGetBoundingRectsForGlyphs has a bug which causes it to
    // return a bad value in cgBounds.origin.x for SFNT fonts whose hhea::numberOfHMetrics is
    // less than its maxp::numGlyphs. When this is the case we try to read the bounds from the
    // font directly.
<<<<<<< HEAD
    if ((isLion() || isMountainLion()) && (cgGlyph < fGlyphCount && cgGlyph >= getFBoundingBoxesGlyphOffset() && generateBBoxes())) {
=======
    if ((isLion() || isMountainLion()) &&
        (cgGlyph < fGlyphCount && cgGlyph >= getFBoundingBoxesGlyphOffset() && generateBBoxes()))
    {
>>>>>>> miniblink49
        const GlyphRect& gRect = fFBoundingBoxes[cgGlyph - fFBoundingBoxesGlyphOffset];
        if (gRect.fMinX >= gRect.fMaxX || gRect.fMinY >= gRect.fMaxY) {
            return;
        }
        skBounds = SkRect::MakeLTRB(gRect.fMinX, gRect.fMinY, gRect.fMaxX, gRect.fMaxY);
        // From FUnits (em space, y up) to SkGlyph units (pixels, y down).
        fFUnitMatrix.mapRect(&skBounds);

    } else {
        // CTFontGetBoundingRectsForGlyphs produces cgBounds in CG units (pixels, y up).
        CGRect cgBounds;
        CTFontGetBoundingRectsForGlyphs(fCTFont, kCTFontHorizontalOrientation,
<<<<<<< HEAD
            &cgGlyph, &cgBounds, 1);
        cgBounds = CGRectApplyAffineTransform(cgBounds, fTransform);
=======
                                        &cgGlyph, &cgBounds, 1);
>>>>>>> miniblink49

        // BUG?
        // 0x200B (zero-advance space) seems to return a huge (garbage) bounds, when
        // it should be empty. So, if we see a zero-advance, we check if it has an
        // empty path or not, and if so, we jam the bounds to 0. Hopefully a zero-advance
        // is rare, so we won't incur a big performance cost for this extra check.
        if (0 == cgAdvance.width && 0 == cgAdvance.height) {
<<<<<<< HEAD
            AutoCFRelease<CGPathRef> path(CTFontCreatePathForGlyph(fCTFont, cgGlyph, nullptr));
            if (nullptr == path || CGPathIsEmpty(path)) {
=======
            AutoCFRelease<CGPathRef> path(CTFontCreatePathForGlyph(fCTFont, cgGlyph, NULL));
            if (NULL == path || CGPathIsEmpty(path)) {
>>>>>>> miniblink49
                return;
            }
        }

        if (CGRectIsEmpty_inline(cgBounds)) {
            return;
        }

        // Convert cgBounds to SkGlyph units (pixels, y down).
        skBounds = SkRect::MakeXYWH(cgBounds.origin.x, -cgBounds.origin.y - cgBounds.size.height,
<<<<<<< HEAD
            cgBounds.size.width, cgBounds.size.height);
=======
                                    cgBounds.size.width, cgBounds.size.height);
>>>>>>> miniblink49
    }

    if (fVertical) {
        // Due to all of the vertical bounds bugs, skBounds is always the horizontal bounds.
        // Convert these horizontal bounds into vertical bounds.
        SkPoint offset;
        getVerticalOffset(cgGlyph, &offset);
        skBounds.offset(offset);
    }

    // Currently the bounds are based on being rendered at (0,0).
    // The top left must not move, since that is the base from which subpixel positioning is offset.
    if (fDoSubPosition) {
        skBounds.fRight += SkFixedToFloat(glyph->getSubXFixed());
        skBounds.fBottom += SkFixedToFloat(glyph->getSubYFixed());
    }

    SkIRect skIBounds;
    skBounds.roundOut(&skIBounds);
    // Expand the bounds by 1 pixel, to give CG room for anti-aliasing.
    // Note that this outset is to allow room for LCD smoothed glyphs. However, the correct outset
    // is not currently known, as CG dilates the outlines by some percentage.
    // Note that if this context is A8 and not back-forming from LCD, there is no need to outset.
    skIBounds.outset(1, 1);
    glyph->fLeft = SkToS16(skIBounds.fLeft);
    glyph->fTop = SkToS16(skIBounds.fTop);
    glyph->fWidth = SkToU16(skIBounds.width());
    glyph->fHeight = SkToU16(skIBounds.height());
}

#include "SkColorPriv.h"

<<<<<<< HEAD
static void build_power_table(uint8_t table[])
{
    for (int i = 0; i < 256; i++) {
        float x = i / 255.f;
        int xx = SkScalarRoundToInt(x * x * 255);
=======
static void build_power_table(uint8_t table[], float ee) {
    for (int i = 0; i < 256; i++) {
        float x = i / 255.f;
        x = sk_float_pow(x, ee);
        int xx = SkScalarRoundToInt(x * 255);
>>>>>>> miniblink49
        table[i] = SkToU8(xx);
    }
}

/**
 *  This will invert the gamma applied by CoreGraphics, so we can get linear
 *  values.
 *
 *  CoreGraphics obscurely defaults to 2.0 as the smoothing gamma value.
 *  The color space used does not appear to affect this choice.
 */
<<<<<<< HEAD
static const uint8_t* getInverseGammaTableCoreGraphicSmoothing()
{
    static bool gInited;
    static uint8_t gTableCoreGraphicsSmoothing[256];
    if (!gInited) {
        build_power_table(gTableCoreGraphicsSmoothing);
=======
static const uint8_t* getInverseGammaTableCoreGraphicSmoothing() {
    static bool gInited;
    static uint8_t gTableCoreGraphicsSmoothing[256];
    if (!gInited) {
        build_power_table(gTableCoreGraphicsSmoothing, 2.0f);
>>>>>>> miniblink49
        gInited = true;
    }
    return gTableCoreGraphicsSmoothing;
}

<<<<<<< HEAD
static void cgpixels_to_bits(uint8_t dst[], const CGRGBPixel src[], int count)
{
    while (count > 0) {
        uint8_t mask = 0;
        for (int i = 7; i >= 0; --i) {
            mask |= ((CGRGBPixel_getAlpha(*src++) >> 7) ^ 0x1) << i;
=======
static void cgpixels_to_bits(uint8_t dst[], const CGRGBPixel src[], int count) {
    while (count > 0) {
        uint8_t mask = 0;
        for (int i = 7; i >= 0; --i) {
            mask |= (CGRGBPixel_getAlpha(*src++) >> 7) << i;
>>>>>>> miniblink49
            if (0 == --count) {
                break;
            }
        }
        *dst++ = mask;
    }
}

<<<<<<< HEAD
template <bool APPLY_PREBLEND>
static inline uint8_t rgb_to_a8(CGRGBPixel rgb, const uint8_t* table8)
{
    U8CPU r = 0xFF - ((rgb >> 16) & 0xFF);
    U8CPU g = 0xFF - ((rgb >> 8) & 0xFF);
    U8CPU b = 0xFF - ((rgb >> 0) & 0xFF);
=======
template<bool APPLY_PREBLEND>
static inline uint8_t rgb_to_a8(CGRGBPixel rgb, const uint8_t* table8) {
    U8CPU r = (rgb >> 16) & 0xFF;
    U8CPU g = (rgb >>  8) & 0xFF;
    U8CPU b = (rgb >>  0) & 0xFF;
>>>>>>> miniblink49
    U8CPU lum = sk_apply_lut_if<APPLY_PREBLEND>(SkComputeLuminance(r, g, b), table8);
#if SK_SHOW_TEXT_BLIT_COVERAGE
    lum = SkTMax(lum, (U8CPU)0x30);
#endif
    return lum;
}
<<<<<<< HEAD
template <bool APPLY_PREBLEND>
static void rgb_to_a8(const CGRGBPixel* SK_RESTRICT cgPixels, size_t cgRowBytes,
    const SkGlyph& glyph, const uint8_t* table8)
{
=======
template<bool APPLY_PREBLEND>
static void rgb_to_a8(const CGRGBPixel* SK_RESTRICT cgPixels, size_t cgRowBytes,
                      const SkGlyph& glyph, const uint8_t* table8) {
>>>>>>> miniblink49
    const int width = glyph.fWidth;
    size_t dstRB = glyph.rowBytes();
    uint8_t* SK_RESTRICT dst = (uint8_t*)glyph.fImage;

    for (int y = 0; y < glyph.fHeight; y++) {
        for (int i = 0; i < width; ++i) {
            dst[i] = rgb_to_a8<APPLY_PREBLEND>(cgPixels[i], table8);
        }
        cgPixels = (CGRGBPixel*)((char*)cgPixels + cgRowBytes);
        dst += dstRB;
    }
}

<<<<<<< HEAD
template <bool APPLY_PREBLEND>
static inline uint16_t rgb_to_lcd16(CGRGBPixel rgb, const uint8_t* tableR,
    const uint8_t* tableG,
    const uint8_t* tableB)
{
    U8CPU r = sk_apply_lut_if<APPLY_PREBLEND>(0xFF - ((rgb >> 16) & 0xFF), tableR);
    U8CPU g = sk_apply_lut_if<APPLY_PREBLEND>(0xFF - ((rgb >> 8) & 0xFF), tableG);
    U8CPU b = sk_apply_lut_if<APPLY_PREBLEND>(0xFF - ((rgb >> 0) & 0xFF), tableB);
=======
template<bool APPLY_PREBLEND>
static inline uint16_t rgb_to_lcd16(CGRGBPixel rgb, const uint8_t* tableR,
                                                    const uint8_t* tableG,
                                                    const uint8_t* tableB) {
    U8CPU r = sk_apply_lut_if<APPLY_PREBLEND>((rgb >> 16) & 0xFF, tableR);
    U8CPU g = sk_apply_lut_if<APPLY_PREBLEND>((rgb >>  8) & 0xFF, tableG);
    U8CPU b = sk_apply_lut_if<APPLY_PREBLEND>((rgb >>  0) & 0xFF, tableB);
>>>>>>> miniblink49
#if SK_SHOW_TEXT_BLIT_COVERAGE
    r = SkTMax(r, (U8CPU)0x30);
    g = SkTMax(g, (U8CPU)0x30);
    b = SkTMax(b, (U8CPU)0x30);
#endif
    return SkPack888ToRGB16(r, g, b);
}
<<<<<<< HEAD
template <bool APPLY_PREBLEND>
static void rgb_to_lcd16(const CGRGBPixel* SK_RESTRICT cgPixels, size_t cgRowBytes, const SkGlyph& glyph,
    const uint8_t* tableR, const uint8_t* tableG, const uint8_t* tableB)
{
=======
template<bool APPLY_PREBLEND>
static void rgb_to_lcd16(const CGRGBPixel* SK_RESTRICT cgPixels, size_t cgRowBytes, const SkGlyph& glyph,
                         const uint8_t* tableR, const uint8_t* tableG, const uint8_t* tableB) {
>>>>>>> miniblink49
    const int width = glyph.fWidth;
    size_t dstRB = glyph.rowBytes();
    uint16_t* SK_RESTRICT dst = (uint16_t*)glyph.fImage;

    for (int y = 0; y < glyph.fHeight; y++) {
        for (int i = 0; i < width; i++) {
            dst[i] = rgb_to_lcd16<APPLY_PREBLEND>(cgPixels[i], tableR, tableG, tableB);
        }
        cgPixels = (CGRGBPixel*)((char*)cgPixels + cgRowBytes);
        dst = (uint16_t*)((char*)dst + dstRB);
    }
}

<<<<<<< HEAD
static SkPMColor cgpixels_to_pmcolor(CGRGBPixel rgb)
{
    U8CPU a = (rgb >> 24) & 0xFF;
    U8CPU r = (rgb >> 16) & 0xFF;
    U8CPU g = (rgb >> 8) & 0xFF;
    U8CPU b = (rgb >> 0) & 0xFF;
=======
static SkPMColor cgpixels_to_pmcolor(CGRGBPixel rgb) {
    U8CPU a = (rgb >> 24) & 0xFF;
    U8CPU r = (rgb >> 16) & 0xFF;
    U8CPU g = (rgb >>  8) & 0xFF;
    U8CPU b = (rgb >>  0) & 0xFF;
>>>>>>> miniblink49
#if SK_SHOW_TEXT_BLIT_COVERAGE
    a = SkTMax(a, (U8CPU)0x30);
#endif
    return SkPackARGB32(a, r, g, b);
}

<<<<<<< HEAD
void SkScalerContext_Mac::generateImage(const SkGlyph& glyph)
{
    CGGlyph cgGlyph = (CGGlyph)glyph.getGlyphID();
=======
template <typename T> T* SkTAddByteOffset(T* ptr, size_t byteOffset) {
    return (T*)((char*)ptr + byteOffset);
}

void SkScalerContext_Mac::generateImage(const SkGlyph& glyph) {
    CGGlyph cgGlyph = (CGGlyph) glyph.getGlyphID();
>>>>>>> miniblink49

    // FIXME: lcd smoothed un-hinted rasterization unsupported.
    bool generateA8FromLCD = fRec.getHinting() != SkPaint::kNo_Hinting;

    // Draw the glyph
    size_t cgRowBytes;
    CGRGBPixel* cgPixels = fOffscreen.getCG(*this, glyph, cgGlyph, &cgRowBytes, generateA8FromLCD);
<<<<<<< HEAD
    if (cgPixels == nullptr) {
        return;
    }

=======
    if (cgPixels == NULL) {
        return;
    }

    //TODO: see if drawing black on white and inverting is faster (at least in
    //lcd case) as core graphics appears to have special case code for drawing
    //black text.

>>>>>>> miniblink49
    // Fix the glyph
    const bool isLCD = isLCDFormat(glyph.fMaskFormat);
    if (isLCD || (glyph.fMaskFormat == SkMask::kA8_Format && supports_LCD() && generateA8FromLCD)) {
        const uint8_t* table = getInverseGammaTableCoreGraphicSmoothing();

        //Note that the following cannot really be integrated into the
        //pre-blend, since we may not be applying the pre-blend; when we aren't
        //applying the pre-blend it means that a filter wants linear anyway.
        //Other code may also be applying the pre-blend, so we'd need another
        //one with this and one without.
        CGRGBPixel* addr = cgPixels;
        for (int y = 0; y < glyph.fHeight; ++y) {
            for (int x = 0; x < glyph.fWidth; ++x) {
                int r = (addr[x] >> 16) & 0xFF;
<<<<<<< HEAD
                int g = (addr[x] >> 8) & 0xFF;
                int b = (addr[x] >> 0) & 0xFF;
                addr[x] = (table[r] << 16) | (table[g] << 8) | table[b];
            }
            addr = SkTAddOffset<CGRGBPixel>(addr, cgRowBytes);
=======
                int g = (addr[x] >>  8) & 0xFF;
                int b = (addr[x] >>  0) & 0xFF;
                addr[x] = (table[r] << 16) | (table[g] << 8) | table[b];
            }
            addr = SkTAddByteOffset(addr, cgRowBytes);
>>>>>>> miniblink49
        }
    }

    // Convert glyph to mask
    switch (glyph.fMaskFormat) {
<<<<<<< HEAD
    case SkMask::kLCD16_Format: {
        if (fPreBlend.isApplicable()) {
            rgb_to_lcd16<true>(cgPixels, cgRowBytes, glyph,
                fPreBlend.fR, fPreBlend.fG, fPreBlend.fB);
        } else {
            rgb_to_lcd16<false>(cgPixels, cgRowBytes, glyph,
                fPreBlend.fR, fPreBlend.fG, fPreBlend.fB);
        }
    } break;
    case SkMask::kA8_Format: {
        if (fPreBlend.isApplicable()) {
            rgb_to_a8<true>(cgPixels, cgRowBytes, glyph, fPreBlend.fG);
        } else {
            rgb_to_a8<false>(cgPixels, cgRowBytes, glyph, fPreBlend.fG);
        }
    } break;
    case SkMask::kBW_Format: {
        const int width = glyph.fWidth;
        size_t dstRB = glyph.rowBytes();
        uint8_t* dst = (uint8_t*)glyph.fImage;
        for (int y = 0; y < glyph.fHeight; y++) {
            cgpixels_to_bits(dst, cgPixels, width);
            cgPixels = (CGRGBPixel*)((char*)cgPixels + cgRowBytes);
            dst += dstRB;
        }
    } break;
    case SkMask::kARGB32_Format: {
        const int width = glyph.fWidth;
        size_t dstRB = glyph.rowBytes();
        SkPMColor* dst = (SkPMColor*)glyph.fImage;
        for (int y = 0; y < glyph.fHeight; y++) {
            for (int x = 0; x < width; ++x) {
                dst[x] = cgpixels_to_pmcolor(cgPixels[x]);
            }
            cgPixels = (CGRGBPixel*)((char*)cgPixels + cgRowBytes);
            dst = (SkPMColor*)((char*)dst + dstRB);
        }
    } break;
    default:
        SkDEBUGFAIL("unexpected mask format");
        break;
=======
        case SkMask::kLCD16_Format: {
            if (fPreBlend.isApplicable()) {
                rgb_to_lcd16<true>(cgPixels, cgRowBytes, glyph,
                                   fPreBlend.fR, fPreBlend.fG, fPreBlend.fB);
            } else {
                rgb_to_lcd16<false>(cgPixels, cgRowBytes, glyph,
                                    fPreBlend.fR, fPreBlend.fG, fPreBlend.fB);
            }
        } break;
        case SkMask::kA8_Format: {
            if (fPreBlend.isApplicable()) {
                rgb_to_a8<true>(cgPixels, cgRowBytes, glyph, fPreBlend.fG);
            } else {
                rgb_to_a8<false>(cgPixels, cgRowBytes, glyph, fPreBlend.fG);
            }
        } break;
        case SkMask::kBW_Format: {
            const int width = glyph.fWidth;
            size_t dstRB = glyph.rowBytes();
            uint8_t* dst = (uint8_t*)glyph.fImage;
            for (int y = 0; y < glyph.fHeight; y++) {
                cgpixels_to_bits(dst, cgPixels, width);
                cgPixels = (CGRGBPixel*)((char*)cgPixels + cgRowBytes);
                dst += dstRB;
            }
        } break;
        case SkMask::kARGB32_Format: {
            const int width = glyph.fWidth;
            size_t dstRB = glyph.rowBytes();
            SkPMColor* dst = (SkPMColor*)glyph.fImage;
            for (int y = 0; y < glyph.fHeight; y++) {
                for (int x = 0; x < width; ++x) {
                    dst[x] = cgpixels_to_pmcolor(cgPixels[x]);
                }
                cgPixels = (CGRGBPixel*)((char*)cgPixels + cgRowBytes);
                dst = (SkPMColor*)((char*)dst + dstRB);
            }
        } break;
        default:
            SkDEBUGFAIL("unexpected mask format");
            break;
>>>>>>> miniblink49
    }
}

/*
 *  Our subpixel resolution is only 2 bits in each direction, so a scale of 4
 *  seems sufficient, and possibly even correct, to allow the hinted outline
 *  to be subpixel positioned.
 */
#define kScaleForSubPixelPositionHinting (4.0f)

<<<<<<< HEAD
void SkScalerContext_Mac::generatePath(const SkGlyph& glyph, SkPath* path)
{
    AUTO_CG_LOCK();

    SkScalar scaleX = SK_Scalar1;
    SkScalar scaleY = SK_Scalar1;

    CGAffineTransform xform = fTransform;
=======
void SkScalerContext_Mac::generatePath(const SkGlyph& glyph, SkPath* path) {
    CTFontRef font = fCTFont;
    SkScalar scaleX = SK_Scalar1;
    SkScalar scaleY = SK_Scalar1;

>>>>>>> miniblink49
    /*
     *  For subpixel positioning, we want to return an unhinted outline, so it
     *  can be positioned nicely at fractional offsets. However, we special-case
     *  if the baseline of the (horizontal) text is axis-aligned. In those cases
     *  we want to retain hinting in the direction orthogonal to the baseline.
     *  e.g. for horizontal baseline, we want to retain hinting in Y.
     *  The way we remove hinting is to scale the font by some value (4) in that
     *  direction, ask for the path, and then scale the path back down.
     */
<<<<<<< HEAD
    if (fDoSubPosition) {
        // start out by assuming that we want no hining in X and Y
        scaleX = scaleY = kScaleForSubPixelPositionHinting;
        // now see if we need to restore hinting for axis-aligned baselines
        switch (this->computeAxisAlignmentForHText()) {
        case kX_SkAxisAlignment:
            scaleY = SK_Scalar1; // want hinting in the Y direction
            break;
        case kY_SkAxisAlignment:
            scaleX = SK_Scalar1; // want hinting in the X direction
            break;
        default:
            break;
        }

        CGAffineTransform scale(CGAffineTransformMakeScale(ScalarToCG(scaleX), ScalarToCG(scaleY)));
        xform = CGAffineTransformConcat(fTransform, scale);
    }

    CGGlyph cgGlyph = (CGGlyph)glyph.getGlyphID();
    AutoCFRelease<CGPathRef> cgPath(CTFontCreatePathForGlyph(fCTFont, cgGlyph, &xform));

    path->reset();
    if (cgPath != nullptr) {
=======
    if (fRec.fFlags & SkScalerContext::kSubpixelPositioning_Flag) {
        SkMatrix m;
        fRec.getSingleMatrix(&m);

        // start out by assuming that we want no hining in X and Y
        scaleX = scaleY = kScaleForSubPixelPositionHinting;
        // now see if we need to restore hinting for axis-aligned baselines
        switch (SkComputeAxisAlignmentForHText(m)) {
            case kX_SkAxisAlignment:
                scaleY = SK_Scalar1; // want hinting in the Y direction
                break;
            case kY_SkAxisAlignment:
                scaleX = SK_Scalar1; // want hinting in the X direction
                break;
            default:
                break;
        }

        CGAffineTransform xform = MatrixToCGAffineTransform(m, scaleX, scaleY);
        // need to release font when we're done
        font = CTFontCreateCopyWithAttributes(fCTFont, 1, &xform, NULL);
    }

    CGGlyph cgGlyph = (CGGlyph)glyph.getGlyphID();
    AutoCFRelease<CGPathRef> cgPath(CTFontCreatePathForGlyph(font, cgGlyph, NULL));

    path->reset();
    if (cgPath != NULL) {
>>>>>>> miniblink49
        CGPathApply(cgPath, path, SkScalerContext_Mac::CTPathElement);
    }

    if (fDoSubPosition) {
        SkMatrix m;
        m.setScale(SkScalarInvert(scaleX), SkScalarInvert(scaleY));
        path->transform(m);
<<<<<<< HEAD
=======
        // balance the call to CTFontCreateCopyWithAttributes
        CFSafeRelease(font);
>>>>>>> miniblink49
    }
    if (fVertical) {
        SkPoint offset;
        getVerticalOffset(cgGlyph, &offset);
        path->offset(offset.fX, offset.fY);
    }
}

<<<<<<< HEAD
void SkScalerContext_Mac::generateFontMetrics(SkPaint::FontMetrics* metrics)
{
    if (nullptr == metrics) {
        return;
    }

    AUTO_CG_LOCK();

    CGRect theBounds = CTFontGetBoundingBox(fCTFont);

    metrics->fTop = CGToScalar(-CGRectGetMaxY_inline(theBounds));
    metrics->fAscent = CGToScalar(-CTFontGetAscent(fCTFont));
    metrics->fDescent = CGToScalar(CTFontGetDescent(fCTFont));
    metrics->fBottom = CGToScalar(-CGRectGetMinY_inline(theBounds));
    metrics->fLeading = CGToScalar(CTFontGetLeading(fCTFont));
    metrics->fAvgCharWidth = CGToScalar(CGRectGetWidth_inline(theBounds));
    metrics->fXMin = CGToScalar(CGRectGetMinX_inline(theBounds));
    metrics->fXMax = CGToScalar(CGRectGetMaxX_inline(theBounds));
    metrics->fMaxCharWidth = metrics->fXMax - metrics->fXMin;
    metrics->fXHeight = CGToScalar(CTFontGetXHeight(fCTFont));
    metrics->fCapHeight = CGToScalar(CTFontGetCapHeight(fCTFont));
    metrics->fUnderlineThickness = CGToScalar(CTFontGetUnderlineThickness(fCTFont));
    metrics->fUnderlinePosition = -CGToScalar(CTFontGetUnderlinePosition(fCTFont));
=======
void SkScalerContext_Mac::generateFontMetrics(SkPaint::FontMetrics* metrics) {
    if (NULL == metrics) {
        return;
    }

    CGRect theBounds = CTFontGetBoundingBox(fCTFont);

    metrics->fTop          = CGToScalar(-CGRectGetMaxY_inline(theBounds));
    metrics->fAscent       = CGToScalar(-CTFontGetAscent(fCTFont));
    metrics->fDescent      = CGToScalar( CTFontGetDescent(fCTFont));
    metrics->fBottom       = CGToScalar(-CGRectGetMinY_inline(theBounds));
    metrics->fLeading      = CGToScalar( CTFontGetLeading(fCTFont));
    metrics->fAvgCharWidth = CGToScalar( CGRectGetWidth_inline(theBounds));
    metrics->fXMin         = CGToScalar( CGRectGetMinX_inline(theBounds));
    metrics->fXMax         = CGToScalar( CGRectGetMaxX_inline(theBounds));
    metrics->fMaxCharWidth = metrics->fXMax - metrics->fXMin;
    metrics->fXHeight      = CGToScalar( CTFontGetXHeight(fCTFont));
    metrics->fCapHeight    = CGToScalar( CTFontGetCapHeight(fCTFont));
    metrics->fUnderlineThickness = CGToScalar( CTFontGetUnderlineThickness(fCTFont));
    metrics->fUnderlinePosition = -CGToScalar( CTFontGetUnderlinePosition(fCTFont));
>>>>>>> miniblink49

    metrics->fFlags |= SkPaint::FontMetrics::kUnderlineThinknessIsValid_Flag;
    metrics->fFlags |= SkPaint::FontMetrics::kUnderlinePositionIsValid_Flag;
}

<<<<<<< HEAD
void SkScalerContext_Mac::CTPathElement(void* info, const CGPathElement* element)
{
=======
void SkScalerContext_Mac::CTPathElement(void *info, const CGPathElement *element) {
>>>>>>> miniblink49
    SkPath* skPath = (SkPath*)info;

    // Process the path element
    switch (element->type) {
<<<<<<< HEAD
    case kCGPathElementMoveToPoint:
        skPath->moveTo(element->points[0].x, -element->points[0].y);
        break;

    case kCGPathElementAddLineToPoint:
        skPath->lineTo(element->points[0].x, -element->points[0].y);
        break;

    case kCGPathElementAddQuadCurveToPoint:
        skPath->quadTo(element->points[0].x, -element->points[0].y,
            element->points[1].x, -element->points[1].y);
        break;

    case kCGPathElementAddCurveToPoint:
        skPath->cubicTo(element->points[0].x, -element->points[0].y,
            element->points[1].x, -element->points[1].y,
            element->points[2].x, -element->points[2].y);
        break;

    case kCGPathElementCloseSubpath:
        skPath->close();
        break;

    default:
        SkDEBUGFAIL("Unknown path element!");
        break;
    }
}

///////////////////////////////////////////////////////////////////////////////

// Returns nullptr on failure
// Call must still manage its ownership of provider
static SkTypeface* create_from_dataProvider(CGDataProviderRef provider)
{
    AutoCFRelease<CGFontRef> cg(CGFontCreateWithDataProvider(provider));
    if (nullptr == cg) {
        return nullptr;
    }
    CTFontRef ct = CTFontCreateWithGraphicsFont(cg, 0, nullptr, nullptr);
    return ct ? NewFromFontRef(ct, nullptr, true) : nullptr;
=======
        case kCGPathElementMoveToPoint:
            skPath->moveTo(element->points[0].x, -element->points[0].y);
            break;

        case kCGPathElementAddLineToPoint:
            skPath->lineTo(element->points[0].x, -element->points[0].y);
            break;

        case kCGPathElementAddQuadCurveToPoint:
            skPath->quadTo(element->points[0].x, -element->points[0].y,
                           element->points[1].x, -element->points[1].y);
            break;

        case kCGPathElementAddCurveToPoint:
            skPath->cubicTo(element->points[0].x, -element->points[0].y,
                            element->points[1].x, -element->points[1].y,
                            element->points[2].x, -element->points[2].y);
            break;

        case kCGPathElementCloseSubpath:
            skPath->close();
            break;

        default:
            SkDEBUGFAIL("Unknown path element!");
            break;
        }
}


///////////////////////////////////////////////////////////////////////////////

// Returns NULL on failure
// Call must still manage its ownership of provider
static SkTypeface* create_from_dataProvider(CGDataProviderRef provider) {
    AutoCFRelease<CGFontRef> cg(CGFontCreateWithDataProvider(provider));
    if (NULL == cg) {
        return NULL;
    }
    CTFontRef ct = CTFontCreateWithGraphicsFont(cg, 0, NULL, NULL);
    return ct ? NewFromFontRef(ct, NULL, NULL, true) : NULL;
>>>>>>> miniblink49
}

// Web fonts added to the the CTFont registry do not return their character set.
// Iterate through the font in this case. The existing caller caches the result,
// so the performance impact isn't too bad.
static void populate_glyph_to_unicode_slow(CTFontRef ctFont, CFIndex glyphCount,
<<<<<<< HEAD
    SkTDArray<SkUnichar>* glyphToUnicode)
{
=======
                                           SkTDArray<SkUnichar>* glyphToUnicode) {
>>>>>>> miniblink49
    glyphToUnicode->setCount(SkToInt(glyphCount));
    SkUnichar* out = glyphToUnicode->begin();
    sk_bzero(out, glyphCount * sizeof(SkUnichar));
    UniChar unichar = 0;
    while (glyphCount > 0) {
        CGGlyph glyph;
        if (CTFontGetGlyphsForCharacters(ctFont, &unichar, &glyph, 1)) {
            out[glyph] = unichar;
            --glyphCount;
        }
        if (++unichar == 0) {
            break;
        }
    }
}

// Construct Glyph to Unicode table.
// Unicode code points that require conjugate pairs in utf16 are not
// supported.
static void populate_glyph_to_unicode(CTFontRef ctFont, CFIndex glyphCount,
<<<<<<< HEAD
    SkTDArray<SkUnichar>* glyphToUnicode)
{
=======
                                      SkTDArray<SkUnichar>* glyphToUnicode) {
>>>>>>> miniblink49
    AutoCFRelease<CFCharacterSetRef> charSet(CTFontCopyCharacterSet(ctFont));
    if (!charSet) {
        populate_glyph_to_unicode_slow(ctFont, glyphCount, glyphToUnicode);
        return;
    }

    AutoCFRelease<CFDataRef> bitmap(CFCharacterSetCreateBitmapRepresentation(kCFAllocatorDefault,
<<<<<<< HEAD
        charSet));
=======
                                                                             charSet));
>>>>>>> miniblink49
    if (!bitmap) {
        return;
    }
    CFIndex length = CFDataGetLength(bitmap);
    if (!length) {
        return;
    }
    if (length > 8192) {
        // TODO: Add support for Unicode above 0xFFFF
        // Consider only the BMP portion of the Unicode character points.
        // The bitmap may contain other planes, up to plane 16.
        // See http://developer.apple.com/library/ios/#documentation/CoreFoundation/Reference/CFCharacterSetRef/Reference/reference.html
        length = 8192;
    }
    const UInt8* bits = CFDataGetBytePtr(bitmap);
    glyphToUnicode->setCount(SkToInt(glyphCount));
    SkUnichar* out = glyphToUnicode->begin();
    sk_bzero(out, glyphCount * sizeof(SkUnichar));
    for (int i = 0; i < length; i++) {
        int mask = bits[i];
        if (!mask) {
            continue;
        }
        for (int j = 0; j < 8; j++) {
            CGGlyph glyph;
            UniChar unichar = static_cast<UniChar>((i << 3) + j);
            if (mask & (1 << j) && CTFontGetGlyphsForCharacters(ctFont, &unichar, &glyph, 1)) {
                out[glyph] = unichar;
            }
        }
    }
}

<<<<<<< HEAD
/** Assumes src and dst are not nullptr. */
static void CFStringToSkString(CFStringRef src, SkString* dst)
{
    // Reserve enough room for the worst-case string,
    // plus 1 byte for the trailing null.
    CFIndex length = CFStringGetMaximumSizeForEncoding(CFStringGetLength(src),
                         kCFStringEncodingUTF8)
        + 1;
=======
static bool getWidthAdvance(CTFontRef ctFont, int gId, int16_t* data) {
    CGSize advance;
    advance.width = 0;
    CGGlyph glyph = gId;
    CTFontGetAdvancesForGlyphs(ctFont, kCTFontHorizontalOrientation, &glyph, &advance, 1);
    *data = sk_float_round2int(advance.width);
    return true;
}

/** Assumes src and dst are not NULL. */
static void CFStringToSkString(CFStringRef src, SkString* dst) {
    // Reserve enough room for the worst-case string,
    // plus 1 byte for the trailing null.
    CFIndex length = CFStringGetMaximumSizeForEncoding(CFStringGetLength(src),
                                                       kCFStringEncodingUTF8) + 1;
>>>>>>> miniblink49
    dst->resize(length);
    CFStringGetCString(src, dst->writable_str(), length, kCFStringEncodingUTF8);
    // Resize to the actual UTF-8 length used, stripping the null character.
    dst->resize(strlen(dst->c_str()));
}

SkAdvancedTypefaceMetrics* SkTypeface_Mac::onGetAdvancedTypefaceMetrics(
<<<<<<< HEAD
    PerGlyphInfo perGlyphInfo,
    const uint32_t* glyphIDs,
    uint32_t glyphIDsCount) const
{

    AUTO_CG_LOCK();

    CTFontRef originalCTFont = fFontRef.get();
    AutoCFRelease<CTFontRef> ctFont(ctfont_create_exact_copy(
        originalCTFont, CTFontGetUnitsPerEm(originalCTFont), nullptr));

=======
        PerGlyphInfo perGlyphInfo,
        const uint32_t* glyphIDs,
        uint32_t glyphIDsCount) const {

    CTFontRef originalCTFont = fFontRef.get();
    AutoCFRelease<CTFontRef> ctFont(CTFontCreateCopyWithAttributes(
            originalCTFont, CTFontGetUnitsPerEm(originalCTFont), NULL, NULL));
>>>>>>> miniblink49
    SkAdvancedTypefaceMetrics* info = new SkAdvancedTypefaceMetrics;

    {
        AutoCFRelease<CFStringRef> fontName(CTFontCopyPostScriptName(ctFont));
        if (fontName.get()) {
            CFStringToSkString(fontName, &info->fFontName);
        }
    }

    CFIndex glyphCount = CTFontGetGlyphCount(ctFont);
    info->fLastGlyphID = SkToU16(glyphCount - 1);
    info->fEmSize = CTFontGetUnitsPerEm(ctFont);

    if (perGlyphInfo & kToUnicode_PerGlyphInfo) {
        populate_glyph_to_unicode(ctFont, glyphCount, &info->fGlyphToUnicode);
    }

    // If it's not a truetype font, mark it as 'other'. Assume that TrueType
    // fonts always have both glyf and loca tables. At the least, this is what
    // sfntly needs to subset the font. CTFontCopyAttribute() does not always
    // succeed in determining this directly.
    if (!this->getTableSize('glyf') || !this->getTableSize('loca')) {
        return info;
    }

    info->fType = SkAdvancedTypefaceMetrics::kTrueType_Font;
    CTFontSymbolicTraits symbolicTraits = CTFontGetSymbolicTraits(ctFont);
    if (symbolicTraits & kCTFontMonoSpaceTrait) {
        info->fStyle |= SkAdvancedTypefaceMetrics::kFixedPitch_Style;
    }
    if (symbolicTraits & kCTFontItalicTrait) {
        info->fStyle |= SkAdvancedTypefaceMetrics::kItalic_Style;
    }
    CTFontStylisticClass stylisticClass = symbolicTraits & kCTFontClassMaskTrait;
    if (stylisticClass >= kCTFontOldStyleSerifsClass && stylisticClass <= kCTFontSlabSerifsClass) {
        info->fStyle |= SkAdvancedTypefaceMetrics::kSerif_Style;
    } else if (stylisticClass & kCTFontScriptsClass) {
        info->fStyle |= SkAdvancedTypefaceMetrics::kScript_Style;
    }
<<<<<<< HEAD
    info->fItalicAngle = (int16_t)CTFontGetSlantAngle(ctFont);
    info->fAscent = (int16_t)CTFontGetAscent(ctFont);
    info->fDescent = (int16_t)CTFontGetDescent(ctFont);
    info->fCapHeight = (int16_t)CTFontGetCapHeight(ctFont);
    CGRect bbox = CTFontGetBoundingBox(ctFont);

    SkRect r;
    r.set(CGToScalar(CGRectGetMinX_inline(bbox)), // Left
        CGToScalar(CGRectGetMaxY_inline(bbox)), // Top
        CGToScalar(CGRectGetMaxX_inline(bbox)), // Right
        CGToScalar(CGRectGetMinY_inline(bbox))); // Bottom
=======
    info->fItalicAngle = (int16_t) CTFontGetSlantAngle(ctFont);
    info->fAscent = (int16_t) CTFontGetAscent(ctFont);
    info->fDescent = (int16_t) CTFontGetDescent(ctFont);
    info->fCapHeight = (int16_t) CTFontGetCapHeight(ctFont);
    CGRect bbox = CTFontGetBoundingBox(ctFont);

    SkRect r;
    r.set( CGToScalar(CGRectGetMinX_inline(bbox)),   // Left
           CGToScalar(CGRectGetMaxY_inline(bbox)),   // Top
           CGToScalar(CGRectGetMaxX_inline(bbox)),   // Right
           CGToScalar(CGRectGetMinY_inline(bbox)));  // Bottom
>>>>>>> miniblink49

    r.roundOut(&(info->fBBox));

    // Figure out a good guess for StemV - Min width of i, I, !, 1.
    // This probably isn't very good with an italic font.
    int16_t min_width = SHRT_MAX;
    info->fStemV = 0;
<<<<<<< HEAD
    static const UniChar stem_chars[] = { 'i', 'I', '!', '1' };
=======
    static const UniChar stem_chars[] = {'i', 'I', '!', '1'};
>>>>>>> miniblink49
    const size_t count = sizeof(stem_chars) / sizeof(stem_chars[0]);
    CGGlyph glyphs[count];
    CGRect boundingRects[count];
    if (CTFontGetGlyphsForCharacters(ctFont, stem_chars, glyphs, count)) {
        CTFontGetBoundingRectsForGlyphs(ctFont, kCTFontHorizontalOrientation,
<<<<<<< HEAD
            glyphs, boundingRects, count);
        for (size_t i = 0; i < count; i++) {
            int16_t width = (int16_t)boundingRects[i].size.width;
=======
                                        glyphs, boundingRects, count);
        for (size_t i = 0; i < count; i++) {
            int16_t width = (int16_t) boundingRects[i].size.width;
>>>>>>> miniblink49
            if (width > 0 && width < min_width) {
                min_width = width;
                info->fStemV = min_width;
            }
        }
    }

    if (perGlyphInfo & kHAdvance_PerGlyphInfo) {
        if (info->fStyle & SkAdvancedTypefaceMetrics::kFixedPitch_Style) {
<<<<<<< HEAD
            SkAdvancedTypefaceMetrics::WidthRange range(0);
            range.fAdvance.append(1, &min_width);
            SkAdvancedTypefaceMetrics::FinishRange(
                &range, 0, SkAdvancedTypefaceMetrics::WidthRange::kDefault);
            info->fGlyphWidths.emplace_back(std::move(range));
        } else {
            CTFontRef borrowedCTFont = ctFont.get();
            info->setGlyphWidths(
                SkToInt(glyphCount),
                glyphIDs,
                glyphIDsCount,
                SkAdvancedTypefaceMetrics::GetAdvance([borrowedCTFont](int gId, int16_t* data) {
                    CGSize advance;
                    advance.width = 0;
                    CGGlyph glyph = gId;
                    CTFontGetAdvancesForGlyphs(borrowedCTFont, kCTFontHorizontalOrientation,
                        &glyph, &advance, 1);
                    *data = sk_float_round2int(advance.width);
                    return true;
                }));
=======
            skia_advanced_typeface_metrics_utils::appendRange(&info->fGlyphWidths, 0);
            info->fGlyphWidths->fAdvance.append(1, &min_width);
            skia_advanced_typeface_metrics_utils::finishRange(info->fGlyphWidths.get(), 0,
                        SkAdvancedTypefaceMetrics::WidthRange::kDefault);
        } else {
            info->fGlyphWidths.reset(
                skia_advanced_typeface_metrics_utils::getAdvanceData(ctFont.get(),
                               SkToInt(glyphCount),
                               glyphIDs,
                               glyphIDsCount,
                               &getWidthAdvance));
>>>>>>> miniblink49
        }
    }
    return info;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static SK_SFNT_ULONG get_font_type_tag(const SkTypeface_Mac* typeface)
{
    CTFontRef ctFont = typeface->fFontRef.get();
    AutoCFRelease<CFNumberRef> fontFormatRef(
        static_cast<CFNumberRef>(CTFontCopyAttribute(ctFont, kCTFontFormatAttribute)));
=======
static SK_SFNT_ULONG get_font_type_tag(const SkTypeface_Mac* typeface) {
    CTFontRef ctFont = typeface->fFontRef.get();
    AutoCFRelease<CFNumberRef> fontFormatRef(
            static_cast<CFNumberRef>(CTFontCopyAttribute(ctFont, kCTFontFormatAttribute)));
>>>>>>> miniblink49
    if (!fontFormatRef) {
        return 0;
    }

    SInt32 fontFormatValue;
    if (!CFNumberGetValue(fontFormatRef, kCFNumberSInt32Type, &fontFormatValue)) {
        return 0;
    }

    switch (fontFormatValue) {
<<<<<<< HEAD
    case kCTFontFormatOpenTypePostScript:
        return SkSFNTHeader::fontType_OpenTypeCFF::TAG;
    case kCTFontFormatOpenTypeTrueType:
        return SkSFNTHeader::fontType_WindowsTrueType::TAG;
    case kCTFontFormatTrueType:
        return SkSFNTHeader::fontType_MacTrueType::TAG;
    case kCTFontFormatPostScript:
        return SkSFNTHeader::fontType_PostScript::TAG;
    case kCTFontFormatBitmap:
        return SkSFNTHeader::fontType_MacTrueType::TAG;
    case kCTFontFormatUnrecognized:
    default:
        //CT seems to be unreliable in being able to obtain the type,
        //even if all we want is the first four bytes of the font resource.
        //Just the presence of the FontForge 'FFTM' table seems to throw it off.
        return SkSFNTHeader::fontType_WindowsTrueType::TAG;
    }
}

SkStreamAsset* SkTypeface_Mac::onOpenStream(int* ttcIndex) const
{
    SK_SFNT_ULONG fontType = get_font_type_tag(this);
    if (0 == fontType) {
        return nullptr;
=======
        case kCTFontFormatOpenTypePostScript:
            return SkSFNTHeader::fontType_OpenTypeCFF::TAG;
        case kCTFontFormatOpenTypeTrueType:
            return SkSFNTHeader::fontType_WindowsTrueType::TAG;
        case kCTFontFormatTrueType:
            return SkSFNTHeader::fontType_MacTrueType::TAG;
        case kCTFontFormatPostScript:
            return SkSFNTHeader::fontType_PostScript::TAG;
        case kCTFontFormatBitmap:
            return SkSFNTHeader::fontType_MacTrueType::TAG;
        case kCTFontFormatUnrecognized:
        default:
            //CT seems to be unreliable in being able to obtain the type,
            //even if all we want is the first four bytes of the font resource.
            //Just the presence of the FontForge 'FFTM' table seems to throw it off.
            return SkSFNTHeader::fontType_WindowsTrueType::TAG;
    }
}

SkStreamAsset* SkTypeface_Mac::onOpenStream(int* ttcIndex) const {
    SK_SFNT_ULONG fontType = get_font_type_tag(this);
    if (0 == fontType) {
        return NULL;
>>>>>>> miniblink49
    }

    // get table tags
    int numTables = this->countTables();
    SkTDArray<SkFontTableTag> tableTags;
    tableTags.setCount(numTables);
    this->getTableTags(tableTags.begin());

    // calc total size for font, save sizes
    SkTDArray<size_t> tableSizes;
    size_t totalSize = sizeof(SkSFNTHeader) + sizeof(SkSFNTHeader::TableDirectoryEntry) * numTables;
    for (int tableIndex = 0; tableIndex < numTables; ++tableIndex) {
        size_t tableSize = this->getTableSize(tableTags[tableIndex]);
        totalSize += (tableSize + 3) & ~3;
        *tableSizes.append() = tableSize;
    }

    // reserve memory for stream, and zero it (tables must be zero padded)
    SkMemoryStream* stream = new SkMemoryStream(totalSize);
    char* dataStart = (char*)stream->getMemoryBase();
    sk_bzero(dataStart, totalSize);
    char* dataPtr = dataStart;

    // compute font header entries
    uint16_t entrySelector = 0;
    uint16_t searchRange = 1;
<<<<<<< HEAD
    while (searchRange<numTables> > 1) {
=======
    while (searchRange < numTables >> 1) {
>>>>>>> miniblink49
        entrySelector++;
        searchRange <<= 1;
    }
    searchRange <<= 4;
    uint16_t rangeShift = (numTables << 4) - searchRange;

    // write font header
    SkSFNTHeader* header = (SkSFNTHeader*)dataPtr;
    header->fontType = fontType;
    header->numTables = SkEndian_SwapBE16(numTables);
    header->searchRange = SkEndian_SwapBE16(searchRange);
    header->entrySelector = SkEndian_SwapBE16(entrySelector);
    header->rangeShift = SkEndian_SwapBE16(rangeShift);
    dataPtr += sizeof(SkSFNTHeader);

    // write tables
    SkSFNTHeader::TableDirectoryEntry* entry = (SkSFNTHeader::TableDirectoryEntry*)dataPtr;
    dataPtr += sizeof(SkSFNTHeader::TableDirectoryEntry) * numTables;
    for (int tableIndex = 0; tableIndex < numTables; ++tableIndex) {
        size_t tableSize = tableSizes[tableIndex];
        this->getTableData(tableTags[tableIndex], 0, tableSize, dataPtr);
        entry->tag = SkEndian_SwapBE32(tableTags[tableIndex]);
        entry->checksum = SkEndian_SwapBE32(SkOTUtils::CalcTableChecksum((SK_OT_ULONG*)dataPtr,
<<<<<<< HEAD
            tableSize));
=======
                                                                         tableSize));
>>>>>>> miniblink49
        entry->offset = SkEndian_SwapBE32(SkToU32(dataPtr - dataStart));
        entry->logicalLength = SkEndian_SwapBE32(SkToU32(tableSize));

        dataPtr += (tableSize + 3) & ~3;
        ++entry;
    }

    *ttcIndex = 0;
    return stream;
}

struct NonDefaultAxesContext {
    SkFixed* axisValue;
    CFArrayRef cgAxes;
};
<<<<<<< HEAD
static void set_non_default_axes(CFTypeRef key, CFTypeRef value, void* context)
{
=======
static void set_non_default_axes(CFTypeRef key, CFTypeRef value, void* context) {
>>>>>>> miniblink49
    NonDefaultAxesContext* self = static_cast<NonDefaultAxesContext*>(context);

    if (CFGetTypeID(key) != CFStringGetTypeID() || CFGetTypeID(value) != CFNumberGetTypeID()) {
        return;
    }

    // The key is a CFString which is a string from the 'name' table.
    // Search the cgAxes for an axis with this name, and use its index to store the value.
    CFIndex keyIndex = -1;
    CFStringRef keyString = static_cast<CFStringRef>(key);
    for (CFIndex i = 0; i < CFArrayGetCount(self->cgAxes); ++i) {
        CFTypeRef cgAxis = CFArrayGetValueAtIndex(self->cgAxes, i);
        if (CFGetTypeID(cgAxis) != CFDictionaryGetTypeID()) {
            continue;
        }

        CFDictionaryRef cgAxisDict = static_cast<CFDictionaryRef>(cgAxis);
        CFTypeRef cgAxisName = CFDictionaryGetValue(cgAxisDict, kCGFontVariationAxisName);
        if (!cgAxisName || CFGetTypeID(cgAxisName) != CFStringGetTypeID()) {
            continue;
        }
        CFStringRef cgAxisNameString = static_cast<CFStringRef>(cgAxisName);
        if (CFStringCompare(keyString, cgAxisNameString, 0) == kCFCompareEqualTo) {
            keyIndex = i;
            break;
        }
    }
    if (keyIndex == -1) {
        return;
    }

    CFNumberRef valueNumber = static_cast<CFNumberRef>(value);
    double valueDouble;
<<<<<<< HEAD
    if (!CFNumberGetValue(valueNumber, kCFNumberDoubleType, &valueDouble) || valueDouble < SkFixedToDouble(SK_FixedMin) || SkFixedToDouble(SK_FixedMax) < valueDouble) {
=======
    if (!CFNumberGetValue(valueNumber, kCFNumberDoubleType, &valueDouble) ||
        valueDouble < SkFixedToDouble(SK_FixedMin) || SkFixedToDouble(SK_FixedMax) < valueDouble)
    {
>>>>>>> miniblink49
        return;
    }
    self->axisValue[keyIndex] = SkDoubleToFixed(valueDouble);
}
static bool get_variations(CTFontRef fFontRef, CFIndex* cgAxisCount,
<<<<<<< HEAD
    SkAutoSTMalloc<4, SkFixed>* axisValues)
{
    // CTFontCopyVariationAxes and CTFontCopyVariation do not work when applied to fonts which
    // started life with CGFontCreateWithDataProvider (they simply always return nullptr).
    // As a result, we are limited to CGFontCopyVariationAxes and CGFontCopyVariations.
    AutoCFRelease<CGFontRef> cgFont(CTFontCopyGraphicsFont(fFontRef, nullptr));

    AutoCFRelease<CFDictionaryRef> cgVariations(CGFontCopyVariations(cgFont));
    // If a font has no variations CGFontCopyVariations returns nullptr (instead of an empty dict).
=======
                           SkAutoSTMalloc<4, SkFixed>* axisValues)
{
    // CTFontCopyVariationAxes and CTFontCopyVariation do not work when applied to fonts which
    // started life with CGFontCreateWithDataProvider (they simply always return NULL).
    // As a result, we are limited to CGFontCopyVariationAxes and CGFontCopyVariations.
    AutoCFRelease<CGFontRef> cgFont(CTFontCopyGraphicsFont(fFontRef, NULL));

    AutoCFRelease<CFDictionaryRef> cgVariations(CGFontCopyVariations(cgFont));
    // If a font has no variations CGFontCopyVariations returns NULL (instead of an empty dict).
>>>>>>> miniblink49
    if (!cgVariations.get()) {
        return false;
    }

    AutoCFRelease<CFArrayRef> cgAxes(CGFontCopyVariationAxes(cgFont));
    *cgAxisCount = CFArrayGetCount(cgAxes);
    axisValues->reset(*cgAxisCount);

    // Set all of the axes to their default values.
    // Fail if any default value cannot be determined.
    for (CFIndex i = 0; i < *cgAxisCount; ++i) {
        CFTypeRef cgAxis = CFArrayGetValueAtIndex(cgAxes, i);
        if (CFGetTypeID(cgAxis) != CFDictionaryGetTypeID()) {
            return false;
        }

        CFDictionaryRef cgAxisDict = static_cast<CFDictionaryRef>(cgAxis);
        CFTypeRef axisDefaultValue = CFDictionaryGetValue(cgAxisDict,
<<<<<<< HEAD
            kCGFontVariationAxisDefaultValue);
=======
                                                          kCGFontVariationAxisDefaultValue);
>>>>>>> miniblink49
        if (!axisDefaultValue || CFGetTypeID(axisDefaultValue) != CFNumberGetTypeID()) {
            return false;
        }
        CFNumberRef axisDefaultValueNumber = static_cast<CFNumberRef>(axisDefaultValue);
        double axisDefaultValueDouble;
<<<<<<< HEAD
        if (!CFNumberGetValue(axisDefaultValueNumber, kCFNumberDoubleType, &axisDefaultValueDouble)) {
            return false;
        }
        if (axisDefaultValueDouble < SkFixedToDouble(SK_FixedMin) || SkFixedToDouble(SK_FixedMax) < axisDefaultValueDouble) {
=======
        if (!CFNumberGetValue(axisDefaultValueNumber, kCFNumberDoubleType, &axisDefaultValueDouble))
        {
            return false;
        }
        if (axisDefaultValueDouble < SkFixedToDouble(SK_FixedMin) ||
                                     SkFixedToDouble(SK_FixedMax) < axisDefaultValueDouble)
        {
>>>>>>> miniblink49
            return false;
        }
        (*axisValues)[(int)i] = SkDoubleToFixed(axisDefaultValueDouble);
    }

    // Override the default values with the given font's stated axis values.
    NonDefaultAxesContext c = { axisValues->get(), cgAxes.get() };
    CFDictionaryApplyFunction(cgVariations, set_non_default_axes, &c);

    return true;
}
<<<<<<< HEAD
SkFontData* SkTypeface_Mac::onCreateFontData() const
{
=======
SkFontData* SkTypeface_Mac::onCreateFontData() const {
>>>>>>> miniblink49
    int index;
    SkAutoTDelete<SkStreamAsset> stream(this->onOpenStream(&index));

    CFIndex cgAxisCount;
    SkAutoSTMalloc<4, SkFixed> axisValues;
    if (get_variations(fFontRef, &cgAxisCount, &axisValues)) {
<<<<<<< HEAD
        return new SkFontData(stream.release(), index, axisValues.get(), cgAxisCount);
    }
    return new SkFontData(stream.release(), index, nullptr, 0);
=======
        return new SkFontData(stream.detach(), index, axisValues.get(), cgAxisCount);
    }
    return new SkFontData(stream.detach(), index, NULL, 0);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
int SkTypeface_Mac::onGetUPEM() const
{
    AutoCFRelease<CGFontRef> cgFont(CTFontCopyGraphicsFont(fFontRef, nullptr));
    return CGFontGetUnitsPerEm(cgFont);
}

SkTypeface::LocalizedStrings* SkTypeface_Mac::onCreateFamilyNameIterator() const
{
    SkTypeface::LocalizedStrings* nameIter = SkOTUtils::LocalizedStrings_NameTable::CreateForFamilyNames(*this);
    if (nullptr == nameIter) {
=======
int SkTypeface_Mac::onGetUPEM() const {
    AutoCFRelease<CGFontRef> cgFont(CTFontCopyGraphicsFont(fFontRef, NULL));
    return CGFontGetUnitsPerEm(cgFont);
}

SkTypeface::LocalizedStrings* SkTypeface_Mac::onCreateFamilyNameIterator() const {
    SkTypeface::LocalizedStrings* nameIter =
        SkOTUtils::LocalizedStrings_NameTable::CreateForFamilyNames(*this);
    if (NULL == nameIter) {
>>>>>>> miniblink49
        AutoCFRelease<CFStringRef> cfLanguage;
        AutoCFRelease<CFStringRef> cfFamilyName(
            CTFontCopyLocalizedName(fFontRef, kCTFontFamilyNameKey, &cfLanguage));

        SkString skLanguage;
        SkString skFamilyName;
        if (cfLanguage.get()) {
            CFStringToSkString(cfLanguage.get(), &skLanguage);
        } else {
            skLanguage = "und"; //undetermined
        }
        if (cfFamilyName.get()) {
            CFStringToSkString(cfFamilyName.get(), &skFamilyName);
        }

        nameIter = new SkOTUtils::LocalizedStrings_SingleName(skFamilyName, skLanguage);
    }
    return nameIter;
}

// If, as is the case with web fonts, the CTFont data isn't available,
// the CGFont data may work. While the CGFont may always provide the
// right result, leave the CTFont code path to minimize disruption.
<<<<<<< HEAD
static CFDataRef copyTableFromFont(CTFontRef ctFont, SkFontTableTag tag)
{
    CFDataRef data = CTFontCopyTable(ctFont, (CTFontTableTag)tag,
        kCTFontTableOptionNoOptions);
    if (nullptr == data) {
        AutoCFRelease<CGFontRef> cgFont(CTFontCopyGraphicsFont(ctFont, nullptr));
=======
static CFDataRef copyTableFromFont(CTFontRef ctFont, SkFontTableTag tag) {
    CFDataRef data = CTFontCopyTable(ctFont, (CTFontTableTag) tag,
                                     kCTFontTableOptionNoOptions);
    if (NULL == data) {
        AutoCFRelease<CGFontRef> cgFont(CTFontCopyGraphicsFont(ctFont, NULL));
>>>>>>> miniblink49
        data = CGFontCopyTableForTag(cgFont, tag);
    }
    return data;
}

<<<<<<< HEAD
int SkTypeface_Mac::onGetTableTags(SkFontTableTag tags[]) const
{
    AutoCFRelease<CFArrayRef> cfArray(CTFontCopyAvailableTables(fFontRef,
        kCTFontTableOptionNoOptions));
    if (nullptr == cfArray) {
=======
int SkTypeface_Mac::onGetTableTags(SkFontTableTag tags[]) const {
    AutoCFRelease<CFArrayRef> cfArray(CTFontCopyAvailableTables(fFontRef,
                                                kCTFontTableOptionNoOptions));
    if (NULL == cfArray) {
>>>>>>> miniblink49
        return 0;
    }
    int count = SkToInt(CFArrayGetCount(cfArray));
    if (tags) {
        for (int i = 0; i < count; ++i) {
            uintptr_t fontTag = reinterpret_cast<uintptr_t>(CFArrayGetValueAtIndex(cfArray, i));
            tags[i] = static_cast<SkFontTableTag>(fontTag);
        }
    }
    return count;
}

size_t SkTypeface_Mac::onGetTableData(SkFontTableTag tag, size_t offset,
<<<<<<< HEAD
    size_t length, void* dstData) const
{
    AutoCFRelease<CFDataRef> srcData(copyTableFromFont(fFontRef, tag));
    if (nullptr == srcData) {
=======
                                      size_t length, void* dstData) const {
    AutoCFRelease<CFDataRef> srcData(copyTableFromFont(fFontRef, tag));
    if (NULL == srcData) {
>>>>>>> miniblink49
        return 0;
    }

    size_t srcSize = CFDataGetLength(srcData);
    if (offset >= srcSize) {
        return 0;
    }
    if (length > srcSize - offset) {
        length = srcSize - offset;
    }
    if (dstData) {
        memcpy(dstData, CFDataGetBytePtr(srcData) + offset, length);
    }
    return length;
}

<<<<<<< HEAD
SkScalerContext* SkTypeface_Mac::onCreateScalerContext(const SkScalerContextEffects& effects,
    const SkDescriptor* desc) const
{
    return new SkScalerContext_Mac(const_cast<SkTypeface_Mac*>(this), effects, desc);
}

void SkTypeface_Mac::onFilterRec(SkScalerContextRec* rec) const
{
    if (rec->fFlags & SkScalerContext::kLCD_BGROrder_Flag || rec->fFlags & SkScalerContext::kLCD_Vertical_Flag) {
=======
SkScalerContext* SkTypeface_Mac::onCreateScalerContext(const SkDescriptor* desc) const {
    return new SkScalerContext_Mac(const_cast<SkTypeface_Mac*>(this), desc);
}

void SkTypeface_Mac::onFilterRec(SkScalerContextRec* rec) const {
    if (rec->fFlags & SkScalerContext::kLCD_BGROrder_Flag ||
        rec->fFlags & SkScalerContext::kLCD_Vertical_Flag)
    {
>>>>>>> miniblink49
        rec->fMaskFormat = SkMask::kA8_Format;
        // Render the glyphs as close as possible to what was requested.
        // The above turns off subpixel rendering, but the user requested it.
        // Normal hinting will cause the A8 masks to be generated from CoreGraphics subpixel masks.
        // See comments below for more details.
        rec->setHinting(SkPaint::kNormal_Hinting);
    }

<<<<<<< HEAD
    unsigned flagsWeDontSupport = SkScalerContext::kDevKernText_Flag | SkScalerContext::kForceAutohinting_Flag | SkScalerContext::kLCD_BGROrder_Flag | SkScalerContext::kLCD_Vertical_Flag;
=======
    unsigned flagsWeDontSupport = SkScalerContext::kDevKernText_Flag  |
                                  SkScalerContext::kForceAutohinting_Flag  |
                                  SkScalerContext::kLCD_BGROrder_Flag |
                                  SkScalerContext::kLCD_Vertical_Flag;
>>>>>>> miniblink49

    rec->fFlags &= ~flagsWeDontSupport;

    bool lcdSupport = supports_LCD();

    // Only two levels of hinting are supported.
    // kNo_Hinting means avoid CoreGraphics outline dilation.
    // kNormal_Hinting means CoreGraphics outline dilation is allowed.
    // If there is no lcd support, hinting (dilation) cannot be supported.
    SkPaint::Hinting hinting = rec->getHinting();
    if (SkPaint::kSlight_Hinting == hinting || !lcdSupport) {
        hinting = SkPaint::kNo_Hinting;
    } else if (SkPaint::kFull_Hinting == hinting) {
        hinting = SkPaint::kNormal_Hinting;
    }
    rec->setHinting(hinting);

    // FIXME: lcd smoothed un-hinted rasterization unsupported.
    // Tracked by http://code.google.com/p/skia/issues/detail?id=915 .
    // There is no current means to honor a request for unhinted lcd,
    // so arbitrarilly ignore the hinting request and honor lcd.

    // Hinting and smoothing should be orthogonal, but currently they are not.
    // CoreGraphics has no API to influence hinting. However, its lcd smoothed
    // output is drawn from auto-dilated outlines (the amount of which is
    // determined by AppleFontSmoothing). Its regular anti-aliased output is
    // drawn from un-dilated outlines.

    // The behavior of Skia is as follows:
    // [AA][no-hint]: generate AA using CoreGraphic's AA output.
    // [AA][yes-hint]: use CoreGraphic's LCD output and reduce it to a single
    // channel. This matches [LCD][yes-hint] in weight.
    // [LCD][no-hint]: curently unable to honor, and must pick which to respect.
    // Currenly side with LCD, effectively ignoring the hinting setting.
    // [LCD][yes-hint]: generate LCD using CoreGraphic's LCD output.

    if (isLCDFormat(rec->fMaskFormat)) {
        if (lcdSupport) {
            //CoreGraphics creates 555 masks for smoothed text anyway.
            rec->fMaskFormat = SkMask::kLCD16_Format;
            rec->setHinting(SkPaint::kNormal_Hinting);
        } else {
            rec->fMaskFormat = SkMask::kA8_Format;
        }
    }

    // CoreText provides no information as to whether a glyph will be color or not.
    // Fonts may mix outlines and bitmaps, so information is needed on a glyph by glyph basis.
    // If a font contains an 'sbix' table, consider it to be a color font, and disable lcd.
    if (fHasColorGlyphs) {
        rec->fMaskFormat = SkMask::kARGB32_Format;
    }

    // Unhinted A8 masks (those not derived from LCD masks) must respect SK_GAMMA_APPLY_TO_A8.
    // All other masks can use regular gamma.
    if (SkMask::kA8_Format == rec->fMaskFormat && SkPaint::kNo_Hinting == hinting) {
#ifndef SK_GAMMA_APPLY_TO_A8
<<<<<<< HEAD
        // SRGBTODO: Is this correct? Do we want contrast boost?
=======
>>>>>>> miniblink49
        rec->ignorePreBlend();
#endif
    } else {
        //CoreGraphics dialates smoothed text as needed.
        rec->setContrast(0);
    }
}

// we take ownership of the ref
<<<<<<< HEAD
static const char* get_str(CFStringRef ref, SkString* str)
{
    if (nullptr == ref) {
        return nullptr;
=======
static const char* get_str(CFStringRef ref, SkString* str) {
    if (NULL == ref) {
        return NULL;
>>>>>>> miniblink49
    }
    CFStringToSkString(ref, str);
    CFSafeRelease(ref);
    return str->c_str();
}

<<<<<<< HEAD
void SkTypeface_Mac::onGetFamilyName(SkString* familyName) const
{
=======
void SkTypeface_Mac::onGetFamilyName(SkString* familyName) const {
>>>>>>> miniblink49
    get_str(CTFontCopyFamilyName(fFontRef), familyName);
}

void SkTypeface_Mac::onGetFontDescriptor(SkFontDescriptor* desc,
<<<<<<< HEAD
    bool* isLocalStream) const
{
=======
                                         bool* isLocalStream) const {
>>>>>>> miniblink49
    SkString tmpStr;

    desc->setFamilyName(get_str(CTFontCopyFamilyName(fFontRef), &tmpStr));
    desc->setFullName(get_str(CTFontCopyFullName(fFontRef), &tmpStr));
    desc->setPostscriptName(get_str(CTFontCopyPostScriptName(fFontRef), &tmpStr));
    *isLocalStream = fIsLocalStream;
}

int SkTypeface_Mac::onCharsToGlyphs(const void* chars, Encoding encoding,
<<<<<<< HEAD
    uint16_t glyphs[], int glyphCount) const
=======
                                    uint16_t glyphs[], int glyphCount) const
>>>>>>> miniblink49
{
    // Undocumented behavior of CTFontGetGlyphsForCharacters with non-bmp code points:
    // When a surrogate pair is detected, the glyph index used is the index of the high surrogate.
    // It is documented that if a mapping is unavailable, the glyph will be set to 0.

    SkAutoSTMalloc<1024, UniChar> charStorage;
    const UniChar* src; // UniChar is a UTF-16 16-bit code unit.
    int srcCount;
    switch (encoding) {
<<<<<<< HEAD
    case kUTF8_Encoding: {
        const char* utf8 = reinterpret_cast<const char*>(chars);
        UniChar* utf16 = charStorage.reset(2 * glyphCount);
        src = utf16;
        for (int i = 0; i < glyphCount; ++i) {
            SkUnichar uni = SkUTF8_NextUnichar(&utf8);
            utf16 += SkUTF16_FromUnichar(uni, utf16);
        }
        srcCount = SkToInt(utf16 - src);
        break;
    }
    case kUTF16_Encoding: {
        src = reinterpret_cast<const UniChar*>(chars);
        int extra = 0;
        for (int i = 0; i < glyphCount; ++i) {
            if (SkUTF16_IsHighSurrogate(src[i + extra])) {
                ++extra;
            }
        }
        srcCount = glyphCount + extra;
        break;
    }
    case kUTF32_Encoding: {
        const SkUnichar* utf32 = reinterpret_cast<const SkUnichar*>(chars);
        UniChar* utf16 = charStorage.reset(2 * glyphCount);
        src = utf16;
        for (int i = 0; i < glyphCount; ++i) {
            utf16 += SkUTF16_FromUnichar(utf32[i], utf16);
        }
        srcCount = SkToInt(utf16 - src);
        break;
    }
    }

    // If glyphs is nullptr, CT still needs glyph storage for finding the first failure.
    // Also, if there are any non-bmp code points, the provided 'glyphs' storage will be inadequate.
    SkAutoSTMalloc<1024, uint16_t> glyphStorage;
    uint16_t* macGlyphs = glyphs;
    if (nullptr == macGlyphs || srcCount > glyphCount) {
=======
        case kUTF8_Encoding: {
            const char* utf8 = reinterpret_cast<const char*>(chars);
            UniChar* utf16 = charStorage.reset(2 * glyphCount);
            src = utf16;
            for (int i = 0; i < glyphCount; ++i) {
                SkUnichar uni = SkUTF8_NextUnichar(&utf8);
                utf16 += SkUTF16_FromUnichar(uni, utf16);
            }
            srcCount = SkToInt(utf16 - src);
            break;
        }
        case kUTF16_Encoding: {
            src = reinterpret_cast<const UniChar*>(chars);
            int extra = 0;
            for (int i = 0; i < glyphCount; ++i) {
                if (SkUTF16_IsHighSurrogate(src[i + extra])) {
                    ++extra;
                }
            }
            srcCount = glyphCount + extra;
            break;
        }
        case kUTF32_Encoding: {
            const SkUnichar* utf32 = reinterpret_cast<const SkUnichar*>(chars);
            UniChar* utf16 = charStorage.reset(2 * glyphCount);
            src = utf16;
            for (int i = 0; i < glyphCount; ++i) {
                utf16 += SkUTF16_FromUnichar(utf32[i], utf16);
            }
            srcCount = SkToInt(utf16 - src);
            break;
        }
    }

    // If glyphs is NULL, CT still needs glyph storage for finding the first failure.
    // Also, if there are any non-bmp code points, the provided 'glyphs' storage will be inadequate.
    SkAutoSTMalloc<1024, uint16_t> glyphStorage;
    uint16_t* macGlyphs = glyphs;
    if (NULL == macGlyphs || srcCount > glyphCount) {
>>>>>>> miniblink49
        macGlyphs = glyphStorage.reset(srcCount);
    }

    bool allEncoded = CTFontGetGlyphsForCharacters(fFontRef, src, macGlyphs, srcCount);

    // If there were any non-bmp, then copy and compact.
<<<<<<< HEAD
    // If 'glyphs' is nullptr, then compact glyphStorage in-place.
    // If all are bmp and 'glyphs' is non-nullptr, 'glyphs' already contains the compact glyphs.
    // If some are non-bmp and 'glyphs' is non-nullptr, copy and compact into 'glyphs'.
    uint16_t* compactedGlyphs = glyphs;
    if (nullptr == compactedGlyphs) {
=======
    // If 'glyphs' is NULL, then compact glyphStorage in-place.
    // If all are bmp and 'glyphs' is non-NULL, 'glyphs' already contains the compact glyphs.
    // If some are non-bmp and 'glyphs' is non-NULL, copy and compact into 'glyphs'.
    uint16_t* compactedGlyphs = glyphs;
    if (NULL == compactedGlyphs) {
>>>>>>> miniblink49
        compactedGlyphs = macGlyphs;
    }
    if (srcCount > glyphCount) {
        int extra = 0;
        for (int i = 0; i < glyphCount; ++i) {
            compactedGlyphs[i] = macGlyphs[i + extra];
            if (SkUTF16_IsHighSurrogate(src[i + extra])) {
                ++extra;
            }
        }
    }

    if (allEncoded) {
        return glyphCount;
    }

    // If we got false, then we need to manually look for first failure.
    for (int i = 0; i < glyphCount; ++i) {
        if (0 == compactedGlyphs[i]) {
            return i;
        }
    }
    // Odd to get here, as we expected CT to have returned true up front.
    return glyphCount;
}

<<<<<<< HEAD
int SkTypeface_Mac::onCountGlyphs() const
{
=======
int SkTypeface_Mac::onCountGlyphs() const {
>>>>>>> miniblink49
    return SkToInt(CTFontGetGlyphCount(fFontRef));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static bool find_desc_str(CTFontDescriptorRef desc, CFStringRef name, SkString* value)
{
    AutoCFRelease<CFStringRef> ref((CFStringRef)CTFontDescriptorCopyAttribute(desc, name));
    if (nullptr == ref.get()) {
=======
static bool find_desc_str(CTFontDescriptorRef desc, CFStringRef name, SkString* value) {
    AutoCFRelease<CFStringRef> ref((CFStringRef)CTFontDescriptorCopyAttribute(desc, name));
    if (NULL == ref.get()) {
>>>>>>> miniblink49
        return false;
    }
    CFStringToSkString(ref, value);
    return true;
}

#include "SkFontMgr.h"

<<<<<<< HEAD
static inline int sqr(int value)
{
    SkASSERT(SkAbs32(value) < 0x7FFF); // check for overflow
=======
static inline int sqr(int value) {
    SkASSERT(SkAbs32(value) < 0x7FFF);  // check for overflow
>>>>>>> miniblink49
    return value * value;
}

// We normalize each axis (weight, width, italic) to be base-900
<<<<<<< HEAD
static int compute_metric(const SkFontStyle& a, const SkFontStyle& b)
{
    return sqr(a.weight() - b.weight()) + sqr((a.width() - b.width()) * 100) + sqr((a.slant() != b.slant()) * 900);
}

static SkTypeface* createFromDesc(CTFontDescriptorRef desc)
{
    AutoCFRelease<CTFontRef> ctFont(CTFontCreateWithFontDescriptor(desc, 0, nullptr));
    if (!ctFont) {
        return nullptr;
    }

    SkTypeface* face = SkTypefaceCache::FindByProcAndRef(find_by_CTFontRef, (void*)ctFont.get());
=======
static int compute_metric(const SkFontStyle& a, const SkFontStyle& b) {
    return sqr(a.weight() - b.weight()) +
           sqr((a.width() - b.width()) * 100) +
           sqr((a.isItalic() != b.isItalic()) * 900);
}

static SkTypeface* createFromDesc(CFStringRef cfFamilyName, CTFontDescriptorRef desc) {
    NameStyle cacheRequest;
    SkString skFamilyName;
    CFStringToSkString(cfFamilyName, &skFamilyName);
    cacheRequest.fName = skFamilyName.c_str();
    cacheRequest.fStyle = fontstyle_from_descriptor(desc);

    SkTypeface* face = SkTypefaceCache::FindByProcAndRef(find_by_NameStyle, &cacheRequest);
>>>>>>> miniblink49
    if (face) {
        return face;
    }

<<<<<<< HEAD
    face = NewFromFontRef(ctFont.release(), nullptr, false);
    SkTypefaceCache::Add(face);
=======
    AutoCFRelease<CTFontRef> ctFont(CTFontCreateWithFontDescriptor(desc, 0, NULL));
    if (!ctFont) {
        return NULL;
    }

    bool isFixedPitch;
    (void)computeStyleBits(ctFont, &isFixedPitch);

    face = SkNEW_ARGS(SkTypeface_Mac, (ctFont.detach(), NULL,
                                       cacheRequest.fStyle, isFixedPitch,
                                       skFamilyName.c_str(), false));
    SkTypefaceCache::Add(face, face->fontStyle());
>>>>>>> miniblink49
    return face;
}

class SkFontStyleSet_Mac : public SkFontStyleSet {
public:
<<<<<<< HEAD
    SkFontStyleSet_Mac(CTFontDescriptorRef desc)
        : fArray(CTFontDescriptorCreateMatchingFontDescriptors(desc, nullptr))
        , fCount(0)
    {
        if (nullptr == fArray) {
            fArray = CFArrayCreate(nullptr, nullptr, 0, nullptr);
=======
    SkFontStyleSet_Mac(CFStringRef familyName, CTFontDescriptorRef desc)
        : fArray(CTFontDescriptorCreateMatchingFontDescriptors(desc, NULL))
        , fFamilyName(familyName)
        , fCount(0) {
        CFRetain(familyName);
        if (NULL == fArray) {
            fArray = CFArrayCreate(NULL, NULL, 0, NULL);
>>>>>>> miniblink49
        }
        fCount = SkToInt(CFArrayGetCount(fArray));
    }

<<<<<<< HEAD
    virtual ~SkFontStyleSet_Mac()
    {
        CFRelease(fArray);
    }

    int count() override
    {
        return fCount;
    }

    void getStyle(int index, SkFontStyle* style, SkString* name) override
    {
=======
    virtual ~SkFontStyleSet_Mac() {
        CFRelease(fArray);
        CFRelease(fFamilyName);
    }

    int count() override {
        return fCount;
    }

    void getStyle(int index, SkFontStyle* style, SkString* name) override {
>>>>>>> miniblink49
        SkASSERT((unsigned)index < (unsigned)fCount);
        CTFontDescriptorRef desc = (CTFontDescriptorRef)CFArrayGetValueAtIndex(fArray, index);
        if (style) {
            *style = fontstyle_from_descriptor(desc);
        }
        if (name) {
            if (!find_desc_str(desc, kCTFontStyleNameAttribute, name)) {
                name->reset();
            }
        }
    }

<<<<<<< HEAD
    SkTypeface* createTypeface(int index) override
    {
        SkASSERT((unsigned)index < (unsigned)CFArrayGetCount(fArray));
        CTFontDescriptorRef desc = (CTFontDescriptorRef)CFArrayGetValueAtIndex(fArray, index);

        return createFromDesc(desc);
    }

    SkTypeface* matchStyle(const SkFontStyle& pattern) override
    {
        if (0 == fCount) {
            return nullptr;
        }
        return createFromDesc(findMatchingDesc(pattern));
    }

private:
    CFArrayRef fArray;
    int fCount;

    CTFontDescriptorRef findMatchingDesc(const SkFontStyle& pattern) const
    {
        int bestMetric = SK_MaxS32;
        CTFontDescriptorRef bestDesc = nullptr;
=======
    SkTypeface* createTypeface(int index) override {
        SkASSERT((unsigned)index < (unsigned)CFArrayGetCount(fArray));
        CTFontDescriptorRef desc = (CTFontDescriptorRef)CFArrayGetValueAtIndex(fArray, index);

        return createFromDesc(fFamilyName, desc);
    }

    SkTypeface* matchStyle(const SkFontStyle& pattern) override {
        if (0 == fCount) {
            return NULL;
        }
        return createFromDesc(fFamilyName, findMatchingDesc(pattern));
    }

private:
    CFArrayRef  fArray;
    CFStringRef fFamilyName;
    int         fCount;

    CTFontDescriptorRef findMatchingDesc(const SkFontStyle& pattern) const {
        int bestMetric = SK_MaxS32;
        CTFontDescriptorRef bestDesc = NULL;
>>>>>>> miniblink49

        for (int i = 0; i < fCount; ++i) {
            CTFontDescriptorRef desc = (CTFontDescriptorRef)CFArrayGetValueAtIndex(fArray, i);
            int metric = compute_metric(pattern, fontstyle_from_descriptor(desc));
            if (0 == metric) {
                return desc;
            }
            if (metric < bestMetric) {
                bestMetric = metric;
                bestDesc = desc;
            }
        }
        SkASSERT(bestDesc);
        return bestDesc;
    }
};

class SkFontMgr_Mac : public SkFontMgr {
<<<<<<< HEAD
    CFArrayRef fNames;
    int fCount;

    CFStringRef stringAt(int index) const
    {
=======
    CFArrayRef  fNames;
    int         fCount;

    CFStringRef stringAt(int index) const {
>>>>>>> miniblink49
        SkASSERT((unsigned)index < (unsigned)fCount);
        return (CFStringRef)CFArrayGetValueAtIndex(fNames, index);
    }

<<<<<<< HEAD
    static SkFontStyleSet* CreateSet(CFStringRef cfFamilyName)
    {
        AutoCFRelease<CFMutableDictionaryRef> cfAttr(
            CFDictionaryCreateMutable(kCFAllocatorDefault, 0,
                &kCFTypeDictionaryKeyCallBacks,
                &kCFTypeDictionaryValueCallBacks));
=======
    static SkFontStyleSet* CreateSet(CFStringRef cfFamilyName) {
        AutoCFRelease<CFMutableDictionaryRef> cfAttr(
                 CFDictionaryCreateMutable(kCFAllocatorDefault, 0,
                                           &kCFTypeDictionaryKeyCallBacks,
                                           &kCFTypeDictionaryValueCallBacks));
>>>>>>> miniblink49

        CFDictionaryAddValue(cfAttr, kCTFontFamilyNameAttribute, cfFamilyName);

        AutoCFRelease<CTFontDescriptorRef> desc(
<<<<<<< HEAD
            CTFontDescriptorCreateWithAttributes(cfAttr));
        return new SkFontStyleSet_Mac(desc);
=======
                                CTFontDescriptorCreateWithAttributes(cfAttr));
        return SkNEW_ARGS(SkFontStyleSet_Mac, (cfFamilyName, desc));
>>>>>>> miniblink49
    }

public:
    SkFontMgr_Mac()
        : fNames(SkCTFontManagerCopyAvailableFontFamilyNames())
<<<<<<< HEAD
        , fCount(fNames ? SkToInt(CFArrayGetCount(fNames)) : 0)
    {
    }

    virtual ~SkFontMgr_Mac()
    {
=======
        , fCount(fNames ? SkToInt(CFArrayGetCount(fNames)) : 0) {}

    virtual ~SkFontMgr_Mac() {
>>>>>>> miniblink49
        CFSafeRelease(fNames);
    }

protected:
<<<<<<< HEAD
    int onCountFamilies() const override
    {
        return fCount;
    }

    void onGetFamilyName(int index, SkString* familyName) const override
    {
=======
    int onCountFamilies() const override {
        return fCount;
    }

    void onGetFamilyName(int index, SkString* familyName) const override {
>>>>>>> miniblink49
        if ((unsigned)index < (unsigned)fCount) {
            CFStringToSkString(this->stringAt(index), familyName);
        } else {
            familyName->reset();
        }
    }

<<<<<<< HEAD
    SkFontStyleSet* onCreateStyleSet(int index) const override
    {
        if ((unsigned)index >= (unsigned)fCount) {
            return nullptr;
=======
    SkFontStyleSet* onCreateStyleSet(int index) const override {
        if ((unsigned)index >= (unsigned)fCount) {
            return NULL;
>>>>>>> miniblink49
        }
        return CreateSet(this->stringAt(index));
    }

<<<<<<< HEAD
    SkFontStyleSet* onMatchFamily(const char familyName[]) const override
    {
=======
    SkFontStyleSet* onMatchFamily(const char familyName[]) const override {
>>>>>>> miniblink49
        AutoCFRelease<CFStringRef> cfName(make_CFString(familyName));
        return CreateSet(cfName);
    }

    virtual SkTypeface* onMatchFamilyStyle(const char familyName[],
<<<<<<< HEAD
        const SkFontStyle& fontStyle) const override
    {
        SkAutoTUnref<SkFontStyleSet> sset(this->matchFamily(familyName));
        return sset->matchStyle(fontStyle);
    }

    virtual SkTypeface* onMatchFamilyStyleCharacter(const char familyName[], const SkFontStyle&,
        const char* bcp47[], int bcp47Count,
        SkUnichar character) const override
    {
        return nullptr;
    }

    virtual SkTypeface* onMatchFaceStyle(const SkTypeface* familyMember,
        const SkFontStyle&) const override
    {
        return nullptr;
    }

    SkTypeface* onCreateFromData(SkData* data, int ttcIndex) const override
    {
        AutoCFRelease<CGDataProviderRef> pr(SkCreateDataProviderFromData(data));
        if (nullptr == pr) {
            return nullptr;
=======
                                           const SkFontStyle&) const override {
        return NULL;
    }

    virtual SkTypeface* onMatchFamilyStyleCharacter(const char familyName[], const SkFontStyle&,
                                                    const char* bcp47[], int bcp47Count,
                                                    SkUnichar character) const override {
        return NULL;
    }

    virtual SkTypeface* onMatchFaceStyle(const SkTypeface* familyMember,
                                         const SkFontStyle&) const override {
        return NULL;
    }

    SkTypeface* onCreateFromData(SkData* data, int ttcIndex) const override {
        AutoCFRelease<CGDataProviderRef> pr(SkCreateDataProviderFromData(data));
        if (NULL == pr) {
            return NULL;
>>>>>>> miniblink49
        }
        return create_from_dataProvider(pr);
    }

<<<<<<< HEAD
    SkTypeface* onCreateFromStream(SkStreamAsset* stream, int ttcIndex) const override
    {
        AutoCFRelease<CGDataProviderRef> pr(SkCreateDataProviderFromStream(stream));
        if (nullptr == pr) {
            return nullptr;
=======
    SkTypeface* onCreateFromStream(SkStreamAsset* stream, int ttcIndex) const override {
        AutoCFRelease<CGDataProviderRef> pr(SkCreateDataProviderFromStream(stream));
        if (NULL == pr) {
            return NULL;
>>>>>>> miniblink49
        }
        return create_from_dataProvider(pr);
    }

<<<<<<< HEAD
    static CFNumberRef get_tag_for_name(CFStringRef name, CFArrayRef ctAxes)
    {
        CFIndex ctAxisCount = CFArrayGetCount(ctAxes);
        for (int i = 0; i < ctAxisCount; ++i) {
            CFTypeRef ctAxisInfo = CFArrayGetValueAtIndex(ctAxes, i);
            if (CFDictionaryGetTypeID() != CFGetTypeID(ctAxisInfo)) {
                return nullptr;
            }
            CFDictionaryRef ctAxisInfoDict = static_cast<CFDictionaryRef>(ctAxisInfo);

            CFTypeRef ctAxisName = CFDictionaryGetValue(ctAxisInfoDict,
                kCTFontVariationAxisNameKey);
            if (!ctAxisName || CFGetTypeID(ctAxisName) != CFStringGetTypeID()) {
                return nullptr;
            }

            if (CFEqual(name, ctAxisName)) {
                CFTypeRef tag = CFDictionaryGetValue(ctAxisInfoDict,
                    kCTFontVariationAxisIdentifierKey);
                if (!tag || CFGetTypeID(tag) != CFNumberGetTypeID()) {
                    return nullptr;
                }
                return static_cast<CFNumberRef>(tag);
            }
        }
        return nullptr;
    }
    static CFDictionaryRef get_axes(CGFontRef cg, const FontParameters& params)
    {
        AutoCFRelease<CFArrayRef> cgAxes(CGFontCopyVariationAxes(cg));
        if (!cgAxes) {
            return nullptr;
        }
        CFIndex axisCount = CFArrayGetCount(cgAxes);

        // The CGFont variation data is keyed by name, and lacks the tag.
        // The CTFont variation data is keyed by tag, and also has the name.
        // We would like to work with CTFont variaitons, but creating a CTFont font with
        // CTFont variation dictionary runs into bugs. So use the CTFont variation data
        // to match names to tags to create the appropriate CGFont.
        AutoCFRelease<CTFontRef> ct(CTFontCreateWithGraphicsFont(cg, 0, nullptr, nullptr));
        AutoCFRelease<CFArrayRef> ctAxes(CTFontCopyVariationAxes(ct));
        if (!ctAxes || CFArrayGetCount(ctAxes) != axisCount) {
            return nullptr;
        }

        int paramAxisCount;
        const FontParameters::Axis* paramAxes = params.getAxes(&paramAxisCount);

        CFMutableDictionaryRef dict = CFDictionaryCreateMutable(kCFAllocatorDefault, axisCount,
            &kCFTypeDictionaryKeyCallBacks,
            &kCFTypeDictionaryValueCallBacks);
        for (int i = 0; i < axisCount; ++i) {
            CFTypeRef axisInfo = CFArrayGetValueAtIndex(cgAxes, i);
            if (CFDictionaryGetTypeID() != CFGetTypeID(axisInfo)) {
                return nullptr;
            }
            CFDictionaryRef axisInfoDict = static_cast<CFDictionaryRef>(axisInfo);

            CFTypeRef axisName = CFDictionaryGetValue(axisInfoDict, kCGFontVariationAxisName);
            if (!axisName || CFGetTypeID(axisName) != CFStringGetTypeID()) {
                return nullptr;
            }

            CFNumberRef tagNumber = get_tag_for_name(static_cast<CFStringRef>(axisName), ctAxes);
            if (!tagNumber) {
                // Could not find a tag to go with the name of this index.
                // This would be a bug in CG/CT.
                continue;
            }
            int64_t tagLong;
            if (!CFNumberGetValue(tagNumber, kCFNumberSInt64Type, &tagLong)) {
                return nullptr;
            }

            // The variation axes can be set to any value, but cg will effectively pin them.
            // Pin them here to normalize.
            CFTypeRef min = CFDictionaryGetValue(axisInfoDict, kCGFontVariationAxisMinValue);
            CFTypeRef max = CFDictionaryGetValue(axisInfoDict, kCGFontVariationAxisMaxValue);
            CFTypeRef def = CFDictionaryGetValue(axisInfoDict, kCGFontVariationAxisDefaultValue);
            if (!min || CFGetTypeID(min) != CFNumberGetTypeID() || !max || CFGetTypeID(max) != CFNumberGetTypeID() || !def || CFGetTypeID(def) != CFNumberGetTypeID()) {
                return nullptr;
            }
            CFNumberRef minNumber = static_cast<CFNumberRef>(min);
            CFNumberRef maxNumber = static_cast<CFNumberRef>(max);
            CFNumberRef defNumber = static_cast<CFNumberRef>(def);
            double minDouble;
            double maxDouble;
            double defDouble;
            if (!CFNumberGetValue(minNumber, kCFNumberDoubleType, &minDouble) || !CFNumberGetValue(maxNumber, kCFNumberDoubleType, &maxDouble) || !CFNumberGetValue(defNumber, kCFNumberDoubleType, &defDouble)) {
                return nullptr;
            }

            double value = defDouble;
            for (int j = 0; j < paramAxisCount; ++j) {
                if (paramAxes[j].fTag == tagLong) {
                    value = SkTPin(SkScalarToDouble(paramAxes[j].fStyleValue), minDouble, maxDouble);
                    break;
                }
            }
            CFNumberRef valueNumber = CFNumberCreate(kCFAllocatorDefault, kCFNumberDoubleType,
                &value);
            CFDictionaryAddValue(dict, axisName, valueNumber);
            CFRelease(valueNumber);
        }
        return dict;
    }
    SkTypeface* onCreateFromStream(SkStreamAsset* s, const FontParameters& params) const override
    {
        AutoCFRelease<CGDataProviderRef> provider(SkCreateDataProviderFromStream(s));
        if (nullptr == provider) {
            return nullptr;
        }
        AutoCFRelease<CGFontRef> cg(CGFontCreateWithDataProvider(provider));
        if (nullptr == cg) {
            return nullptr;
        }

        AutoCFRelease<CFDictionaryRef> cgVariations(get_axes(cg, params));
        // The CGFontRef returned by CGFontCreateCopyWithVariations when the passed CGFontRef was
        // created from a data provider does not appear to have any ownership of the underlying
        // data. The original CGFontRef must be kept alive until the copy will no longer be used.
        AutoCFRelease<CGFontRef> cgVariant;
        if (cgVariations) {
            cgVariant.reset(CGFontCreateCopyWithVariations(cg, cgVariations));
        } else {
            cgVariant.reset(cg.release());
        }

        CTFontRef ct = CTFontCreateWithGraphicsFont(cgVariant, 0, nullptr, nullptr);
        if (!ct) {
            return nullptr;
        }
        return NewFromFontRef(ct, cg.release(), true);
    }

    static CFDictionaryRef get_axes(CGFontRef cg, SkFontData* fontData)
    {
        AutoCFRelease<CFArrayRef> cgAxes(CGFontCopyVariationAxes(cg));
        if (!cgAxes) {
            return nullptr;
=======
    static CFDictionaryRef get_axes(CGFontRef cg, SkFontData* fontData) {
        AutoCFRelease<CFArrayRef> cgAxes(CGFontCopyVariationAxes(cg));
        if (!cgAxes) {
            return NULL;
>>>>>>> miniblink49
        }

        CFIndex axisCount = CFArrayGetCount(cgAxes);
        if (0 == axisCount || axisCount != fontData->getAxisCount()) {
<<<<<<< HEAD
            return nullptr;
        }

        CFMutableDictionaryRef dict = CFDictionaryCreateMutable(kCFAllocatorDefault, axisCount,
            &kCFTypeDictionaryKeyCallBacks,
            &kCFTypeDictionaryValueCallBacks);
        for (int i = 0; i < fontData->getAxisCount(); ++i) {
            CFTypeRef axisInfo = CFArrayGetValueAtIndex(cgAxes, i);
            if (CFDictionaryGetTypeID() != CFGetTypeID(axisInfo)) {
                return nullptr;
=======
            return NULL;
        }

        CFMutableDictionaryRef dict = CFDictionaryCreateMutable(kCFAllocatorDefault, axisCount,
                                                                &kCFTypeDictionaryKeyCallBacks,
                                                                &kCFTypeDictionaryValueCallBacks);
        for (int i = 0; i < fontData->getAxisCount(); ++i) {
            CFTypeRef axisInfo = CFArrayGetValueAtIndex(cgAxes, i);
            if (CFDictionaryGetTypeID() != CFGetTypeID(axisInfo)) {
                return NULL;
>>>>>>> miniblink49
            }
            CFDictionaryRef axisInfoDict = static_cast<CFDictionaryRef>(axisInfo);

            CFTypeRef axisName = CFDictionaryGetValue(axisInfoDict, kCGFontVariationAxisName);
            if (!axisName || CFGetTypeID(axisName) != CFStringGetTypeID()) {
<<<<<<< HEAD
                return nullptr;
=======
                return NULL;
>>>>>>> miniblink49
            }

            // The variation axes can be set to any value, but cg will effectively pin them.
            // Pin them here to normalize.
            CFTypeRef min = CFDictionaryGetValue(axisInfoDict, kCGFontVariationAxisMinValue);
            CFTypeRef max = CFDictionaryGetValue(axisInfoDict, kCGFontVariationAxisMaxValue);
<<<<<<< HEAD
            if (!min || CFGetTypeID(min) != CFNumberGetTypeID() || !max || CFGetTypeID(max) != CFNumberGetTypeID()) {
                return nullptr;
=======
            if (!min || CFGetTypeID(min) != CFNumberGetTypeID() ||
                !max || CFGetTypeID(max) != CFNumberGetTypeID())
            {
                return NULL;
>>>>>>> miniblink49
            }
            CFNumberRef minNumber = static_cast<CFNumberRef>(min);
            CFNumberRef maxNumber = static_cast<CFNumberRef>(max);
            double minDouble;
            double maxDouble;
<<<<<<< HEAD
            if (!CFNumberGetValue(minNumber, kCFNumberDoubleType, &minDouble) || !CFNumberGetValue(maxNumber, kCFNumberDoubleType, &maxDouble)) {
                return nullptr;
            }
            double value = SkTPin(SkFixedToDouble(fontData->getAxis()[i]), minDouble, maxDouble);
            CFNumberRef valueNumber = CFNumberCreate(kCFAllocatorDefault, kCFNumberDoubleType,
                &value);
=======
            if (!CFNumberGetValue(minNumber, kCFNumberDoubleType, &minDouble) ||
                !CFNumberGetValue(maxNumber, kCFNumberDoubleType, &maxDouble))
            {
                return NULL;
            }
            double value = SkTPin(SkFixedToDouble(fontData->getAxis()[i]), minDouble, maxDouble);
            CFNumberRef valueNumber = CFNumberCreate(kCFAllocatorDefault, kCFNumberDoubleType,
                                                     &value);
>>>>>>> miniblink49

            CFDictionaryAddValue(dict, axisName, valueNumber);
            CFRelease(valueNumber);
        }
        return dict;
    }
<<<<<<< HEAD
    SkTypeface* onCreateFromFontData(SkFontData* data) const override
    {
        SkAutoTDelete<SkFontData> fontData(data);
        SkStreamAsset* stream = fontData->detachStream();
        AutoCFRelease<CGDataProviderRef> provider(SkCreateDataProviderFromStream(stream));
        if (nullptr == provider) {
            return nullptr;
        }
        AutoCFRelease<CGFontRef> cg(CGFontCreateWithDataProvider(provider));
        if (nullptr == cg) {
            return nullptr;
=======
    SkTypeface* onCreateFromFontData(SkFontData* data) const override {
        SkAutoTDelete<SkFontData> fontData(data);
        SkStreamAsset* stream = fontData->detachStream();
        AutoCFRelease<CGDataProviderRef> provider(SkCreateDataProviderFromStream(stream));
        if (NULL == provider) {
            return NULL;
        }
        AutoCFRelease<CGFontRef> cg(CGFontCreateWithDataProvider(provider));
        if (NULL == cg) {
            return NULL;
>>>>>>> miniblink49
        }

        AutoCFRelease<CFDictionaryRef> cgVariations(get_axes(cg, fontData));
        // The CGFontRef returned by CGFontCreateCopyWithVariations when the passed CGFontRef was
        // created from a data provider does not appear to have any ownership of the underlying
        // data. The original CGFontRef must be kept alive until the copy will no longer be used.
        AutoCFRelease<CGFontRef> cgVariant;
        if (cgVariations) {
            cgVariant.reset(CGFontCreateCopyWithVariations(cg, cgVariations));
        } else {
<<<<<<< HEAD
            cgVariant.reset(cg.release());
        }

        CTFontRef ct = CTFontCreateWithGraphicsFont(cgVariant, 0, nullptr, nullptr);
        if (!ct) {
            return nullptr;
        }
        return NewFromFontRef(ct, cg.release(), true);
    }

    SkTypeface* onCreateFromFile(const char path[], int ttcIndex) const override
    {
        AutoCFRelease<CGDataProviderRef> pr(CGDataProviderCreateWithFilename(path));
        if (nullptr == pr) {
            return nullptr;
=======
            cgVariant.reset(cg.detach());
        }

        CTFontRef ct = CTFontCreateWithGraphicsFont(cgVariant, 0, NULL, NULL);
        if (!ct) {
            return NULL;
        }
        return NewFromFontRef(ct, cg.detach(), NULL, true);
    }

    SkTypeface* onCreateFromFile(const char path[], int ttcIndex) const override {
        AutoCFRelease<CGDataProviderRef> pr(CGDataProviderCreateWithFilename(path));
        if (NULL == pr) {
            return NULL;
>>>>>>> miniblink49
        }
        return create_from_dataProvider(pr);
    }

<<<<<<< HEAD
    SkTypeface* onLegacyCreateTypeface(const char familyName[], SkFontStyle style) const override
    {
=======
    virtual SkTypeface* onLegacyCreateTypeface(const char familyName[],
                                               unsigned styleBits) const override {

        SkFontStyle style = SkFontStyle((SkTypeface::Style)styleBits);
>>>>>>> miniblink49
        if (familyName) {
            familyName = map_css_names(familyName);
        }

        if (!familyName || !*familyName) {
            familyName = FONT_DEFAULT_NAME;
        }

<<<<<<< HEAD
        SkTypeface* face = NewFromName(familyName, style);
        if (face) {
            return face;
        }

        return SkSafeRef(GetDefaultFace());
=======
        NameStyle cacheRequest = { familyName, style };
        SkTypeface* face = SkTypefaceCache::FindByProcAndRef(find_by_NameStyle, &cacheRequest);

        if (NULL == face) {
            face = NewFromName(familyName, style);
            if (face) {
                SkTypefaceCache::Add(face, style);
            } else {
                face = GetDefaultFace();
                face->ref();
            }
        }
        return face;
>>>>>>> miniblink49
    }
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkFontMgr* SkFontMgr::Factory() { return new SkFontMgr_Mac; }

#endif //defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
=======
SkFontMgr* SkFontMgr::Factory() {
    return SkNEW(SkFontMgr_Mac);
}
>>>>>>> miniblink49
