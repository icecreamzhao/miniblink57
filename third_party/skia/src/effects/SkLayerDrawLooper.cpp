<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkLayerDrawLooper.h"
#include "SkCanvas.h"
#include "SkColor.h"
#include "SkReadBuffer.h"
#include "SkString.h"
#include "SkStringUtils.h"
#include "SkUnPreMultiply.h"
#include "SkWriteBuffer.h"

SkLayerDrawLooper::LayerInfo::LayerInfo()
{
    fPaintBits = 0; // ignore our paint fields
=======
#include "SkCanvas.h"
#include "SkColor.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkLayerDrawLooper.h"
#include "SkString.h"
#include "SkStringUtils.h"
#include "SkUnPreMultiply.h"

SkLayerDrawLooper::LayerInfo::LayerInfo() {
    fPaintBits = 0;                     // ignore our paint fields
>>>>>>> miniblink49
    fColorMode = SkXfermode::kDst_Mode; // ignore our color
    fOffset.set(0, 0);
    fPostTranslate = false;
}

SkLayerDrawLooper::SkLayerDrawLooper()
<<<<<<< HEAD
    : fRecs(nullptr)
    , fCount(0)
{
}

SkLayerDrawLooper::~SkLayerDrawLooper()
{
    Rec* rec = fRecs;
    while (rec) {
        Rec* next = rec->fNext;
        delete rec;
=======
        : fRecs(NULL),
          fTopRec(NULL),
          fCount(0) {
}

SkLayerDrawLooper::~SkLayerDrawLooper() {
    Rec* rec = fRecs;
    while (rec) {
        Rec* next = rec->fNext;
        SkDELETE(rec);
>>>>>>> miniblink49
        rec = next;
    }
}

<<<<<<< HEAD
SkLayerDrawLooper::Context* SkLayerDrawLooper::createContext(SkCanvas* canvas, void* storage) const
{
    canvas->save();
    return new (storage) LayerDrawLooperContext(this);
}

static SkColor xferColor(SkColor src, SkColor dst, SkXfermode::Mode mode)
{
    switch (mode) {
    case SkXfermode::kSrc_Mode:
        return src;
    case SkXfermode::kDst_Mode:
        return dst;
    default: {
        SkPMColor pmS = SkPreMultiplyColor(src);
        SkPMColor pmD = SkPreMultiplyColor(dst);
        SkPMColor result = SkXfermode::GetProc(mode)(pmS, pmD);
        return SkUnPreMultiply::PMColorToColor(result);
    }
=======
SkLayerDrawLooper::Context* SkLayerDrawLooper::createContext(SkCanvas* canvas, void* storage) const {
    canvas->save();
    return SkNEW_PLACEMENT_ARGS(storage, LayerDrawLooperContext, (this));
}

static SkColor xferColor(SkColor src, SkColor dst, SkXfermode::Mode mode) {
    switch (mode) {
        case SkXfermode::kSrc_Mode:
            return src;
        case SkXfermode::kDst_Mode:
            return dst;
        default: {
            SkPMColor pmS = SkPreMultiplyColor(src);
            SkPMColor pmD = SkPreMultiplyColor(dst);
            SkPMColor result = SkXfermode::GetProc(mode)(pmS, pmD);
            return SkUnPreMultiply::PMColorToColor(result);
        }
>>>>>>> miniblink49
    }
}

// Even with kEntirePaint_Bits, we always ensure that the master paint's
// text-encoding is respected, since that controls how we interpret the
// text/length parameters of a draw[Pos]Text call.
void SkLayerDrawLooper::LayerDrawLooperContext::ApplyInfo(
<<<<<<< HEAD
    SkPaint* dst, const SkPaint& src, const LayerInfo& info)
{
=======
        SkPaint* dst, const SkPaint& src, const LayerInfo& info) {
>>>>>>> miniblink49

    dst->setColor(xferColor(src.getColor(), dst->getColor(), info.fColorMode));

    BitFlags bits = info.fPaintBits;
    SkPaint::TextEncoding encoding = dst->getTextEncoding();

    if (0 == bits) {
        return;
    }
    if (kEntirePaint_Bits == bits) {
        // we've already computed these, so save it from the assignment
        uint32_t f = dst->getFlags();
        SkColor c = dst->getColor();
        *dst = src;
        dst->setFlags(f);
        dst->setColor(c);
        dst->setTextEncoding(encoding);
        return;
    }

    if (bits & kStyle_Bit) {
        dst->setStyle(src.getStyle());
        dst->setStrokeWidth(src.getStrokeWidth());
        dst->setStrokeMiter(src.getStrokeMiter());
        dst->setStrokeCap(src.getStrokeCap());
        dst->setStrokeJoin(src.getStrokeJoin());
    }

    if (bits & kTextSkewX_Bit) {
        dst->setTextSkewX(src.getTextSkewX());
    }

    if (bits & kPathEffect_Bit) {
<<<<<<< HEAD
        dst->setPathEffect(sk_ref_sp(src.getPathEffect()));
    }
    if (bits & kMaskFilter_Bit) {
        dst->setMaskFilter(sk_ref_sp(src.getMaskFilter()));
    }
    if (bits & kShader_Bit) {
        dst->setShader(sk_ref_sp(src.getShader()));
    }
    if (bits & kColorFilter_Bit) {
        dst->setColorFilter(sk_ref_sp(src.getColorFilter()));
    }
    if (bits & kXfermode_Bit) {
        dst->setXfermode(sk_ref_sp(src.getXfermode()));
=======
        dst->setPathEffect(src.getPathEffect());
    }
    if (bits & kMaskFilter_Bit) {
        dst->setMaskFilter(src.getMaskFilter());
    }
    if (bits & kShader_Bit) {
        dst->setShader(src.getShader());
    }
    if (bits & kColorFilter_Bit) {
        dst->setColorFilter(src.getColorFilter());
    }
    if (bits & kXfermode_Bit) {
        dst->setXfermode(src.getXfermode());
>>>>>>> miniblink49
    }

    // we don't override these
#if 0
    dst->setTypeface(src.getTypeface());
    dst->setTextSize(src.getTextSize());
    dst->setTextScaleX(src.getTextScaleX());
    dst->setRasterizer(src.getRasterizer());
    dst->setLooper(src.getLooper());
    dst->setTextEncoding(src.getTextEncoding());
    dst->setHinting(src.getHinting());
#endif
}

// Should we add this to canvas?
<<<<<<< HEAD
static void postTranslate(SkCanvas* canvas, SkScalar dx, SkScalar dy)
{
=======
static void postTranslate(SkCanvas* canvas, SkScalar dx, SkScalar dy) {
>>>>>>> miniblink49
    SkMatrix m = canvas->getTotalMatrix();
    m.postTranslate(dx, dy);
    canvas->setMatrix(m);
}

SkLayerDrawLooper::LayerDrawLooperContext::LayerDrawLooperContext(
<<<<<<< HEAD
    const SkLayerDrawLooper* looper)
    : fCurrRec(looper->fRecs)
{
}

bool SkLayerDrawLooper::LayerDrawLooperContext::next(SkCanvas* canvas,
    SkPaint* paint)
{
    canvas->restore();
    if (nullptr == fCurrRec) {
=======
        const SkLayerDrawLooper* looper) : fCurrRec(looper->fRecs) {}

bool SkLayerDrawLooper::LayerDrawLooperContext::next(SkCanvas* canvas,
                                                     SkPaint* paint) {
    canvas->restore();
    if (NULL == fCurrRec) {
>>>>>>> miniblink49
        return false;
    }

    ApplyInfo(paint, fCurrRec->fPaint, fCurrRec->fInfo);

    canvas->save();
    if (fCurrRec->fInfo.fPostTranslate) {
        postTranslate(canvas, fCurrRec->fInfo.fOffset.fX,
<<<<<<< HEAD
            fCurrRec->fInfo.fOffset.fY);
    } else {
        canvas->translate(fCurrRec->fInfo.fOffset.fX,
            fCurrRec->fInfo.fOffset.fY);
=======
                      fCurrRec->fInfo.fOffset.fY);
    } else {
        canvas->translate(fCurrRec->fInfo.fOffset.fX,
                          fCurrRec->fInfo.fOffset.fY);
>>>>>>> miniblink49
    }
    fCurrRec = fCurrRec->fNext;

    return true;
}

<<<<<<< HEAD
bool SkLayerDrawLooper::asABlurShadow(BlurShadowRec* bsRec) const
{
=======
bool SkLayerDrawLooper::asABlurShadow(BlurShadowRec* bsRec) const {
>>>>>>> miniblink49
    if (fCount != 2) {
        return false;
    }
    const Rec* rec = fRecs;

    // bottom layer needs to be just blur(maskfilter)
    if ((rec->fInfo.fPaintBits & ~kMaskFilter_Bit)) {
        return false;
    }
    if (SkXfermode::kSrc_Mode != rec->fInfo.fColorMode) {
        return false;
    }
    const SkMaskFilter* mf = rec->fPaint.getMaskFilter();
<<<<<<< HEAD
    if (nullptr == mf) {
=======
    if (NULL == mf) {
>>>>>>> miniblink49
        return false;
    }
    SkMaskFilter::BlurRec maskBlur;
    if (!mf->asABlur(&maskBlur)) {
        return false;
    }

    rec = rec->fNext;
    // top layer needs to be "plain"
    if (rec->fInfo.fPaintBits) {
        return false;
    }
    if (SkXfermode::kDst_Mode != rec->fInfo.fColorMode) {
        return false;
    }
    if (!rec->fInfo.fOffset.equals(0, 0)) {
        return false;
    }

    if (bsRec) {
        bsRec->fSigma = maskBlur.fSigma;
        bsRec->fOffset = fRecs->fInfo.fOffset;
        bsRec->fColor = fRecs->fPaint.getColor();
        bsRec->fStyle = maskBlur.fStyle;
        bsRec->fQuality = maskBlur.fQuality;
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkLayerDrawLooper::flatten(SkWriteBuffer& buffer) const
{
=======
void SkLayerDrawLooper::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    buffer.writeInt(fCount);

    Rec* rec = fRecs;
    for (int i = 0; i < fCount; i++) {
        // Legacy "flagsmask" field -- now ignored, remove when we bump version
        buffer.writeInt(0);

        buffer.writeInt(rec->fInfo.fPaintBits);
        buffer.writeInt(rec->fInfo.fColorMode);
        buffer.writePoint(rec->fInfo.fOffset);
        buffer.writeBool(rec->fInfo.fPostTranslate);
        buffer.writePaint(rec->fPaint);
        rec = rec->fNext;
    }
}

<<<<<<< HEAD
sk_sp<SkFlattenable> SkLayerDrawLooper::CreateProc(SkReadBuffer& buffer)
{
=======
SkFlattenable* SkLayerDrawLooper::CreateProc(SkReadBuffer& buffer) {
>>>>>>> miniblink49
    int count = buffer.readInt();

    Builder builder;
    for (int i = 0; i < count; i++) {
        LayerInfo info;
        // Legacy "flagsmask" field -- now ignored, remove when we bump version
        (void)buffer.readInt();

        info.fPaintBits = buffer.readInt();
        info.fColorMode = (SkXfermode::Mode)buffer.readInt();
        buffer.readPoint(&info.fOffset);
        info.fPostTranslate = buffer.readBool();
        buffer.readPaint(builder.addLayerOnTop(info));
    }
<<<<<<< HEAD
    return builder.detach();
}

#ifndef SK_IGNORE_TO_STRING
void SkLayerDrawLooper::toString(SkString* str) const
{
=======
    return builder.detachLooper();
}

#ifndef SK_IGNORE_TO_STRING
void SkLayerDrawLooper::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("SkLayerDrawLooper (%d): ", fCount);

    Rec* rec = fRecs;
    for (int i = 0; i < fCount; i++) {
        str->appendf("%d: paintBits: (", i);
        if (0 == rec->fInfo.fPaintBits) {
            str->append("None");
        } else if (kEntirePaint_Bits == rec->fInfo.fPaintBits) {
            str->append("EntirePaint");
        } else {
            bool needSeparator = false;
            SkAddFlagToString(str, SkToBool(kStyle_Bit & rec->fInfo.fPaintBits), "Style",
<<<<<<< HEAD
                &needSeparator);
            SkAddFlagToString(str, SkToBool(kTextSkewX_Bit & rec->fInfo.fPaintBits), "TextSkewX",
                &needSeparator);
            SkAddFlagToString(str, SkToBool(kPathEffect_Bit & rec->fInfo.fPaintBits), "PathEffect",
                &needSeparator);
            SkAddFlagToString(str, SkToBool(kMaskFilter_Bit & rec->fInfo.fPaintBits), "MaskFilter",
                &needSeparator);
            SkAddFlagToString(str, SkToBool(kShader_Bit & rec->fInfo.fPaintBits), "Shader",
                &needSeparator);
            SkAddFlagToString(str, SkToBool(kColorFilter_Bit & rec->fInfo.fPaintBits), "ColorFilter",
                &needSeparator);
            SkAddFlagToString(str, SkToBool(kXfermode_Bit & rec->fInfo.fPaintBits), "Xfermode",
                &needSeparator);
        }
        str->append(") ");

        static const char* gModeStrings[SkXfermode::kLastMode + 1] = {
=======
                              &needSeparator);
            SkAddFlagToString(str, SkToBool(kTextSkewX_Bit & rec->fInfo.fPaintBits), "TextSkewX",
                              &needSeparator);
            SkAddFlagToString(str, SkToBool(kPathEffect_Bit & rec->fInfo.fPaintBits), "PathEffect",
                              &needSeparator);
            SkAddFlagToString(str, SkToBool(kMaskFilter_Bit & rec->fInfo.fPaintBits), "MaskFilter",
                              &needSeparator);
            SkAddFlagToString(str, SkToBool(kShader_Bit & rec->fInfo.fPaintBits), "Shader",
                              &needSeparator);
            SkAddFlagToString(str, SkToBool(kColorFilter_Bit & rec->fInfo.fPaintBits), "ColorFilter",
                              &needSeparator);
            SkAddFlagToString(str, SkToBool(kXfermode_Bit & rec->fInfo.fPaintBits), "Xfermode",
                              &needSeparator);
        }
        str->append(") ");

        static const char* gModeStrings[SkXfermode::kLastMode+1] = {
>>>>>>> miniblink49
            "kClear", "kSrc", "kDst", "kSrcOver", "kDstOver", "kSrcIn", "kDstIn",
            "kSrcOut", "kDstOut", "kSrcATop", "kDstATop", "kXor", "kPlus",
            "kMultiply", "kScreen", "kOverlay", "kDarken", "kLighten", "kColorDodge",
            "kColorBurn", "kHardLight", "kSoftLight", "kDifference", "kExclusion"
        };

        str->appendf("mode: %s ", gModeStrings[rec->fInfo.fColorMode]);

        str->append("offset: (");
        str->appendScalar(rec->fInfo.fOffset.fX);
        str->append(", ");
        str->appendScalar(rec->fInfo.fOffset.fY);
        str->append(") ");

        str->append("postTranslate: ");
        if (rec->fInfo.fPostTranslate) {
            str->append("true ");
        } else {
            str->append("false ");
        }

        rec->fPaint.toString(str);
        rec = rec->fNext;
    }
}
#endif

SkLayerDrawLooper::Builder::Builder()
<<<<<<< HEAD
    : fRecs(nullptr)
    , fTopRec(nullptr)
    , fCount(0)
{
}

SkLayerDrawLooper::Builder::~Builder()
{
    Rec* rec = fRecs;
    while (rec) {
        Rec* next = rec->fNext;
        delete rec;
=======
        : fRecs(NULL),
          fTopRec(NULL),
          fCount(0) {
}

SkLayerDrawLooper::Builder::~Builder() {
    Rec* rec = fRecs;
    while (rec) {
        Rec* next = rec->fNext;
        SkDELETE(rec);
>>>>>>> miniblink49
        rec = next;
    }
}

<<<<<<< HEAD
SkPaint* SkLayerDrawLooper::Builder::addLayer(const LayerInfo& info)
{
    fCount += 1;

    Rec* rec = new Rec;
    rec->fNext = fRecs;
    rec->fInfo = info;
    fRecs = rec;
    if (nullptr == fTopRec) {
=======
SkPaint* SkLayerDrawLooper::Builder::addLayer(const LayerInfo& info) {
    fCount += 1;

    Rec* rec = SkNEW(Rec);
    rec->fNext = fRecs;
    rec->fInfo = info;
    fRecs = rec;
    if (NULL == fTopRec) {
>>>>>>> miniblink49
        fTopRec = rec;
    }

    return &rec->fPaint;
}

<<<<<<< HEAD
void SkLayerDrawLooper::Builder::addLayer(SkScalar dx, SkScalar dy)
{
=======
void SkLayerDrawLooper::Builder::addLayer(SkScalar dx, SkScalar dy) {
>>>>>>> miniblink49
    LayerInfo info;

    info.fOffset.set(dx, dy);
    (void)this->addLayer(info);
}

<<<<<<< HEAD
SkPaint* SkLayerDrawLooper::Builder::addLayerOnTop(const LayerInfo& info)
{
    fCount += 1;

    Rec* rec = new Rec;
    rec->fNext = nullptr;
    rec->fInfo = info;
    if (nullptr == fRecs) {
=======
SkPaint* SkLayerDrawLooper::Builder::addLayerOnTop(const LayerInfo& info) {
    fCount += 1;

    Rec* rec = SkNEW(Rec);
    rec->fNext = NULL;
    rec->fInfo = info;
    if (NULL == fRecs) {
>>>>>>> miniblink49
        fRecs = rec;
    } else {
        SkASSERT(fTopRec);
        fTopRec->fNext = rec;
    }
    fTopRec = rec;

    return &rec->fPaint;
}

<<<<<<< HEAD
sk_sp<SkDrawLooper> SkLayerDrawLooper::Builder::detach()
{
    SkLayerDrawLooper* looper = new SkLayerDrawLooper;
=======
SkLayerDrawLooper* SkLayerDrawLooper::Builder::detachLooper() {
    SkLayerDrawLooper* looper = SkNEW(SkLayerDrawLooper);
>>>>>>> miniblink49
    looper->fCount = fCount;
    looper->fRecs = fRecs;

    fCount = 0;
<<<<<<< HEAD
    fRecs = nullptr;
    fTopRec = nullptr;

    return sk_sp<SkDrawLooper>(looper);
=======
    fRecs = NULL;
    fTopRec = NULL;

    return looper;
>>>>>>> miniblink49
}
