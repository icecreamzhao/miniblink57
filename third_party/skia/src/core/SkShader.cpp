/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkShader.h"
=======
>>>>>>> miniblink49
#include "SkAtomics.h"
#include "SkBitmapProcShader.h"
#include "SkColorShader.h"
#include "SkEmptyShader.h"
#include "SkMallocPixelRef.h"
#include "SkPaint.h"
#include "SkPicture.h"
#include "SkPictureShader.h"
#include "SkReadBuffer.h"
#include "SkScalar.h"
<<<<<<< HEAD
#include "SkWriteBuffer.h"

#if SK_SUPPORT_GPU
#include "GrFragmentProcessor.h"
#endif

//#define SK_TRACK_SHADER_LIFETIME

#ifdef SK_TRACK_SHADER_LIFETIME
static int32_t gShaderCounter;
#endif

static inline void inc_shader_counter()
{
=======
#include "SkShader.h"
#include "SkWriteBuffer.h"

//#define SK_TRACK_SHADER_LIFETIME

#ifdef SK_TRACK_SHADER_LIFETIME
    static int32_t gShaderCounter;
#endif

static inline void inc_shader_counter() {
>>>>>>> miniblink49
#ifdef SK_TRACK_SHADER_LIFETIME
    int32_t prev = sk_atomic_inc(&gShaderCounter);
    SkDebugf("+++ shader counter %d\n", prev + 1);
#endif
}
<<<<<<< HEAD
static inline void dec_shader_counter()
{
=======
static inline void dec_shader_counter() {
>>>>>>> miniblink49
#ifdef SK_TRACK_SHADER_LIFETIME
    int32_t prev = sk_atomic_dec(&gShaderCounter);
    SkDebugf("--- shader counter %d\n", prev - 1);
#endif
}

<<<<<<< HEAD
SkShader::SkShader(const SkMatrix* localMatrix)
{
=======
SkShader::SkShader(const SkMatrix* localMatrix) {
>>>>>>> miniblink49
    inc_shader_counter();
    if (localMatrix) {
        fLocalMatrix = *localMatrix;
    } else {
        fLocalMatrix.reset();
    }
    // Pre-cache so future calls to fLocalMatrix.getType() are threadsafe.
    (void)fLocalMatrix.getType();
}

<<<<<<< HEAD
SkShader::~SkShader()
{
    dec_shader_counter();
}

void SkShader::flatten(SkWriteBuffer& buffer) const
{
=======
SkShader::~SkShader() {
    dec_shader_counter();
}

void SkShader::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    this->INHERITED::flatten(buffer);
    bool hasLocalM = !fLocalMatrix.isIdentity();
    buffer.writeBool(hasLocalM);
    if (hasLocalM) {
        buffer.writeMatrix(fLocalMatrix);
    }
}

<<<<<<< HEAD
bool SkShader::computeTotalInverse(const ContextRec& rec, SkMatrix* totalInverse) const
{
=======
bool SkShader::computeTotalInverse(const ContextRec& rec, SkMatrix* totalInverse) const {
>>>>>>> miniblink49
    SkMatrix total;
    total.setConcat(*rec.fMatrix, fLocalMatrix);

    const SkMatrix* m = &total;
    if (rec.fLocalMatrix) {
        total.setConcat(*m, *rec.fLocalMatrix);
        m = &total;
    }
    return m->invert(totalInverse);
}

<<<<<<< HEAD
bool SkShader::asLuminanceColor(SkColor* colorPtr) const
{
    SkColor storage;
    if (nullptr == colorPtr) {
        colorPtr = &storage;
    }
    if (this->onAsLuminanceColor(colorPtr)) {
        *colorPtr = SkColorSetA(*colorPtr, 0xFF); // we only return opaque
=======
bool SkShader::asLuminanceColor(SkColor* colorPtr) const {
    SkColor storage;
    if (NULL == colorPtr) {
        colorPtr = &storage;
    }
    if (this->onAsLuminanceColor(colorPtr)) {
        *colorPtr = SkColorSetA(*colorPtr, 0xFF);   // we only return opaque
>>>>>>> miniblink49
        return true;
    }
    return false;
}

<<<<<<< HEAD
SkShader::Context* SkShader::createContext(const ContextRec& rec, void* storage) const
{
    if (!this->computeTotalInverse(rec, nullptr)) {
        return nullptr;
=======
SkShader::Context* SkShader::createContext(const ContextRec& rec, void* storage) const {
    if (!this->computeTotalInverse(rec, NULL)) {
        return NULL;
>>>>>>> miniblink49
    }
    return this->onCreateContext(rec, storage);
}

<<<<<<< HEAD
SkShader::Context* SkShader::onCreateContext(const ContextRec& rec, void*) const
{
    return nullptr;
}

size_t SkShader::contextSize(const ContextRec& rec) const
{
    return this->onContextSize(rec);
}

size_t SkShader::onContextSize(const ContextRec&) const
{
=======
SkShader::Context* SkShader::onCreateContext(const ContextRec& rec, void*) const {
    return NULL;
}

size_t SkShader::contextSize() const {
>>>>>>> miniblink49
    return 0;
}

SkShader::Context::Context(const SkShader& shader, const ContextRec& rec)
<<<<<<< HEAD
    : fShader(shader)
    , fCTM(*rec.fMatrix)
=======
    : fShader(shader), fCTM(*rec.fMatrix)
>>>>>>> miniblink49
{
    // Because the context parameters must be valid at this point, we know that the matrix is
    // invertible.
    SkAssertResult(fShader.computeTotalInverse(rec, &fTotalInverse));
    fTotalInverseClass = (uint8_t)ComputeMatrixClass(fTotalInverse);

    fPaintAlpha = rec.fPaint->getAlpha();
}

<<<<<<< HEAD
SkShader::Context::~Context() { }

SkShader::Context::ShadeProc SkShader::Context::asAShadeProc(void** ctx)
{
    return nullptr;
}

void SkShader::Context::shadeSpan4f(int x, int y, SkPM4f dst[], int count)
{
    const int N = 128;
    SkPMColor tmp[N];
    while (count > 0) {
        int n = SkTMin(count, N);
        this->shadeSpan(x, y, tmp, n);
        for (int i = 0; i < n; ++i) {
            dst[i] = SkPM4f::FromPMColor(tmp[i]);
        }
        dst += n;
        x += n;
        count -= n;
    }
=======
SkShader::Context::~Context() {}

SkShader::Context::ShadeProc SkShader::Context::asAShadeProc(void** ctx) {
    return NULL;
>>>>>>> miniblink49
}

#include "SkColorPriv.h"

<<<<<<< HEAD
#define kTempColorQuadCount 6 // balance between speed (larger) and saving stack-space
#define kTempColorCount (kTempColorQuadCount << 2)

#ifdef SK_CPU_BENDIAN
#define SkU32BitShiftToByteOffset(shift) (3 - ((shift) >> 3))
#else
#define SkU32BitShiftToByteOffset(shift) ((shift) >> 3)
#endif

void SkShader::Context::shadeSpanAlpha(int x, int y, uint8_t alpha[], int count)
{
    SkASSERT(count > 0);

    SkPMColor colors[kTempColorCount];
=======
void SkShader::Context::shadeSpan16(int x, int y, uint16_t span16[], int count) {
    SkASSERT(span16);
    SkASSERT(count > 0);
    SkASSERT(this->canCallShadeSpan16());

    // basically, if we get here, the subclass screwed up
    SkDEBUGFAIL("kHasSpan16 flag is set, but shadeSpan16() not implemented");
}

#define kTempColorQuadCount 6   // balance between speed (larger) and saving stack-space
#define kTempColorCount     (kTempColorQuadCount << 2)

#ifdef SK_CPU_BENDIAN
    #define SkU32BitShiftToByteOffset(shift)    (3 - ((shift) >> 3))
#else
    #define SkU32BitShiftToByteOffset(shift)    ((shift) >> 3)
#endif

void SkShader::Context::shadeSpanAlpha(int x, int y, uint8_t alpha[], int count) {
    SkASSERT(count > 0);

    SkPMColor   colors[kTempColorCount];
>>>>>>> miniblink49

    while ((count -= kTempColorCount) >= 0) {
        this->shadeSpan(x, y, colors, kTempColorCount);
        x += kTempColorCount;

        const uint8_t* srcA = (const uint8_t*)colors + SkU32BitShiftToByteOffset(SK_A32_SHIFT);
        int quads = kTempColorQuadCount;
        do {
            U8CPU a0 = srcA[0];
            U8CPU a1 = srcA[4];
            U8CPU a2 = srcA[8];
            U8CPU a3 = srcA[12];
<<<<<<< HEAD
            srcA += 4 * 4;
=======
            srcA += 4*4;
>>>>>>> miniblink49
            *alpha++ = SkToU8(a0);
            *alpha++ = SkToU8(a1);
            *alpha++ = SkToU8(a2);
            *alpha++ = SkToU8(a3);
        } while (--quads != 0);
    }
    SkASSERT(count < 0);
    SkASSERT(count + kTempColorCount >= 0);
    if (count += kTempColorCount) {
        this->shadeSpan(x, y, colors, count);

        const uint8_t* srcA = (const uint8_t*)colors + SkU32BitShiftToByteOffset(SK_A32_SHIFT);
        do {
            *alpha++ = *srcA;
            srcA += 4;
        } while (--count != 0);
    }
#if 0
    do {
        int n = count;
        if (n > kTempColorCount)
            n = kTempColorCount;
        SkASSERT(n > 0);

        this->shadeSpan(x, y, colors, n);
        x += n;
        count -= n;

        const uint8_t* srcA = (const uint8_t*)colors + SkU32BitShiftToByteOffset(SK_A32_SHIFT);
        do {
            *alpha++ = *srcA;
            srcA += 4;
        } while (--n != 0);
    } while (count > 0);
#endif
}

<<<<<<< HEAD
SkShader::Context::MatrixClass SkShader::Context::ComputeMatrixClass(const SkMatrix& mat)
{
    MatrixClass mc = kLinear_MatrixClass;

    if (mat.hasPerspective()) {
        if (mat.isFixedStepInX()) {
=======
SkShader::Context::MatrixClass SkShader::Context::ComputeMatrixClass(const SkMatrix& mat) {
    MatrixClass mc = kLinear_MatrixClass;

    if (mat.hasPerspective()) {
        if (mat.fixedStepInX(0, NULL, NULL)) {
>>>>>>> miniblink49
            mc = kFixedStepInX_MatrixClass;
        } else {
            mc = kPerspective_MatrixClass;
        }
    }
    return mc;
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkShader::GradientType SkShader::asAGradient(GradientInfo* info) const
{
    return kNone_GradientType;
}

#if SK_SUPPORT_GPU
sk_sp<GrFragmentProcessor> SkShader::asFragmentProcessor(GrContext*, const SkMatrix&,
    const SkMatrix*, SkFilterQuality,
    SkSourceGammaTreatment) const
{
    return nullptr;
}
#endif

SkShader* SkShader::refAsALocalMatrixShader(SkMatrix*) const
{
    return nullptr;
}

sk_sp<SkShader> SkShader::MakeEmptyShader() { return sk_make_sp<SkEmptyShader>(); }

sk_sp<SkShader> SkShader::MakeColorShader(SkColor color) { return sk_make_sp<SkColorShader>(color); }

sk_sp<SkShader> SkShader::MakeBitmapShader(const SkBitmap& src, TileMode tmx, TileMode tmy,
    const SkMatrix* localMatrix)
{
    return SkMakeBitmapShader(src, tmx, tmy, localMatrix, nullptr);
}

sk_sp<SkShader> SkShader::MakePictureShader(sk_sp<SkPicture> src, TileMode tmx, TileMode tmy,
    const SkMatrix* localMatrix, const SkRect* tile)
{
    return SkPictureShader::Make(std::move(src), tmx, tmy, localMatrix, tile);
}

#ifndef SK_IGNORE_TO_STRING
void SkShader::toString(SkString* str) const
{
=======
SkShader::BitmapType SkShader::asABitmap(SkBitmap*, SkMatrix*, TileMode*) const {
    return kNone_BitmapType;
}

SkShader::GradientType SkShader::asAGradient(GradientInfo* info) const {
    return kNone_GradientType;
}

bool SkShader::asFragmentProcessor(GrContext*, const SkPaint&, const SkMatrix&, const SkMatrix*,
                                   GrColor*, GrProcessorDataManager*,
                                   GrFragmentProcessor**)  const {
    return false;
}

SkShader* SkShader::refAsALocalMatrixShader(SkMatrix*) const {
    return NULL;
}

SkShader* SkShader::CreateEmptyShader() {
    return SkNEW(SkEmptyShader);
}

SkShader* SkShader::CreateColorShader(SkColor color) {
    return SkNEW_ARGS(SkColorShader, (color));
}

SkShader* SkShader::CreateBitmapShader(const SkBitmap& src, TileMode tmx, TileMode tmy,
                                       const SkMatrix* localMatrix) {
    return SkCreateBitmapShader(src, tmx, tmy, localMatrix, NULL);
}

SkShader* SkShader::CreatePictureShader(const SkPicture* src, TileMode tmx, TileMode tmy,
                                        const SkMatrix* localMatrix, const SkRect* tile) {
    return SkPictureShader::Create(src, tmx, tmy, localMatrix, tile);
}

#ifndef SK_IGNORE_TO_STRING
void SkShader::toString(SkString* str) const {
>>>>>>> miniblink49
    if (!fLocalMatrix.isIdentity()) {
        str->append(" ");
        fLocalMatrix.toString(str);
    }
}
#endif

<<<<<<< HEAD
///////////////////////////////////////////////////////////////////////////////////////////////////

sk_sp<SkFlattenable> SkEmptyShader::CreateProc(SkReadBuffer&)
{
    return SkShader::MakeEmptyShader();
}

#ifndef SK_IGNORE_TO_STRING
#include "SkEmptyShader.h"

void SkEmptyShader::toString(SkString* str) const
{
    str->append("SkEmptyShader: (");
=======
//////////////////////////////////////////////////////////////////////////////

#include "SkUtils.h"

SkColorShader::SkColorShader(SkColor c)
    : fColor(c) {
}

bool SkColorShader::isOpaque() const {
    return SkColorGetA(fColor) == 255;
}

SkFlattenable* SkColorShader::CreateProc(SkReadBuffer& buffer) {
    return SkNEW_ARGS(SkColorShader, (buffer.readColor()));
}

void SkColorShader::flatten(SkWriteBuffer& buffer) const {
    buffer.writeColor(fColor);
}

uint32_t SkColorShader::ColorShaderContext::getFlags() const {
    return fFlags;
}

uint8_t SkColorShader::ColorShaderContext::getSpan16Alpha() const {
    return SkGetPackedA32(fPMColor);
}

SkShader::Context* SkColorShader::onCreateContext(const ContextRec& rec, void* storage) const {
    return SkNEW_PLACEMENT_ARGS(storage, ColorShaderContext, (*this, rec));
}

SkColorShader::ColorShaderContext::ColorShaderContext(const SkColorShader& shader,
                                                      const ContextRec& rec)
    : INHERITED(shader, rec)
{
    SkColor color = shader.fColor;
    unsigned a = SkAlphaMul(SkColorGetA(color), SkAlpha255To256(rec.fPaint->getAlpha()));

    unsigned r = SkColorGetR(color);
    unsigned g = SkColorGetG(color);
    unsigned b = SkColorGetB(color);

    // we want this before we apply any alpha
    fColor16 = SkPack888ToRGB16(r, g, b);

    if (a != 255) {
        r = SkMulDiv255Round(r, a);
        g = SkMulDiv255Round(g, a);
        b = SkMulDiv255Round(b, a);
    }
    fPMColor = SkPackARGB32(a, r, g, b);

    fFlags = kConstInY32_Flag;
    if (255 == a) {
        fFlags |= kOpaqueAlpha_Flag;
        if (rec.fPaint->isDither() == false) {
            fFlags |= kHasSpan16_Flag;
        }
    }
}

void SkColorShader::ColorShaderContext::shadeSpan(int x, int y, SkPMColor span[], int count) {
    sk_memset32(span, fPMColor, count);
}

void SkColorShader::ColorShaderContext::shadeSpan16(int x, int y, uint16_t span[], int count) {
    sk_memset16(span, fColor16, count);
}

void SkColorShader::ColorShaderContext::shadeSpanAlpha(int x, int y, uint8_t alpha[], int count) {
    memset(alpha, SkGetPackedA32(fPMColor), count);
}

// if we had a asAColor method, that would be more efficient...
SkShader::BitmapType SkColorShader::asABitmap(SkBitmap* bitmap, SkMatrix* matrix,
                                              TileMode modes[]) const {
    return kNone_BitmapType;
}

SkShader::GradientType SkColorShader::asAGradient(GradientInfo* info) const {
    if (info) {
        if (info->fColors && info->fColorCount >= 1) {
            info->fColors[0] = fColor;
        }
        info->fColorCount = 1;
        info->fTileMode = SkShader::kRepeat_TileMode;
    }
    return kColor_GradientType;
}

#if SK_SUPPORT_GPU

#include "SkGr.h"

bool SkColorShader::asFragmentProcessor(GrContext*, const SkPaint& paint, const SkMatrix&,
                                        const SkMatrix*, GrColor* paintColor,
                                        GrProcessorDataManager*, GrFragmentProcessor** fp) const {
    *fp = NULL;
    SkColor skColor = fColor;
    U8CPU newA = SkMulDiv255Round(SkColorGetA(fColor), paint.getAlpha());
    *paintColor = SkColor2GrColor(SkColorSetA(skColor, newA));
    return true;
}

#else

bool SkColorShader::asFragmentProcessor(GrContext*, const SkPaint&, const SkMatrix&,
                                        const SkMatrix*, GrColor*, GrProcessorDataManager*,
                                        GrFragmentProcessor**) const {
    SkDEBUGFAIL("Should not call in GPU-less build");
    return false;
}

#endif

#ifndef SK_IGNORE_TO_STRING
void SkColorShader::toString(SkString* str) const {
    str->append("SkColorShader: (");

    str->append("Color: ");
    str->appendHex(fColor);
>>>>>>> miniblink49

    this->INHERITED::toString(str);

    str->append(")");
}
#endif

<<<<<<< HEAD
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef SK_SUPPORT_LEGACY_CREATESHADER_PTR
SkShader* SkShader::CreateComposeShader(SkShader* dst, SkShader* src, SkXfermode::Mode mode)
{
    return MakeComposeShader(sk_ref_sp(dst), sk_ref_sp(src), mode).release();
}
SkShader* SkShader::CreateComposeShader(SkShader* dst, SkShader* src, SkXfermode* xfer)
{
    return MakeComposeShader(sk_ref_sp(dst), sk_ref_sp(src), xfer).release();
}
SkShader* SkShader::CreatePictureShader(const SkPicture* src, TileMode tmx, TileMode tmy,
    const SkMatrix* localMatrix, const SkRect* tile)
{
    return MakePictureShader(sk_ref_sp(const_cast<SkPicture*>(src)), tmx, tmy,
        localMatrix, tile)
        .release();
}
SkShader* SkShader::newWithColorFilter(SkColorFilter* filter) const
{
    return this->makeWithColorFilter(sk_ref_sp(filter)).release();
}
#endif

#ifdef SK_SUPPORT_LEGACY_XFERMODE_PTR
#include "SkXfermode.h"
sk_sp<SkShader> SkShader::MakeComposeShader(sk_sp<SkShader> dst, sk_sp<SkShader> src,
    SkXfermode* xfer)
{
    return MakeComposeShader(std::move(dst), std::move(src), sk_ref_sp(xfer));
=======
///////////////////////////////////////////////////////////////////////////////

SkFlattenable* SkEmptyShader::CreateProc(SkReadBuffer&) {
    return SkShader::CreateEmptyShader();
}

#ifndef SK_IGNORE_TO_STRING
#include "SkEmptyShader.h"

void SkEmptyShader::toString(SkString* str) const {
    str->append("SkEmptyShader: (");

    this->INHERITED::toString(str);

    str->append(")");
>>>>>>> miniblink49
}
#endif
