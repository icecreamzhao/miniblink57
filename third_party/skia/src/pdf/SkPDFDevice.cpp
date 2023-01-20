/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkPDFDevice.h"

<<<<<<< HEAD
#include "SkAnnotationKeys.h"
#include "SkBitmapKey.h"
#include "SkColor.h"
#include "SkColorFilter.h"
#include "SkDraw.h"
#include "SkGlyphCache.h"
#include "SkPDFBitmap.h"
#include "SkPDFCanon.h"
#include "SkPDFDocument.h"
=======
#include "SkAnnotation.h"
#include "SkColor.h"
#include "SkClipStack.h"
#include "SkData.h"
#include "SkDraw.h"
#include "SkGlyphCache.h"
#include "SkPaint.h"
#include "SkPath.h"
#include "SkPathOps.h"
#include "SkPDFBitmap.h"
>>>>>>> miniblink49
#include "SkPDFFont.h"
#include "SkPDFFormXObject.h"
#include "SkPDFGraphicState.h"
#include "SkPDFResourceDict.h"
#include "SkPDFShader.h"
#include "SkPDFStream.h"
#include "SkPDFTypes.h"
#include "SkPDFUtils.h"
<<<<<<< HEAD
#include "SkPath.h"
#include "SkPathEffect.h"
#include "SkPathOps.h"
#include "SkRRect.h"
#include "SkRasterClip.h"
#include "SkString.h"
#include "SkSurface.h"
#include "SkTemplates.h"
#include "SkTextFormatParams.h"
=======
#include "SkRect.h"
#include "SkRRect.h"
#include "SkString.h"
#include "SkSurface.h"
#include "SkTextFormatParams.h"
#include "SkTemplates.h"
>>>>>>> miniblink49
#include "SkTypefacePriv.h"
#include "SkXfermodeInterpretation.h"

#define DPI_FOR_RASTER_SCALE_ONE 72

// Utility functions

// If the paint will definitely draw opaquely, replace kSrc_Mode with
// kSrcOver_Mode.  http://crbug.com/473572
<<<<<<< HEAD
static void replace_srcmode_on_opaque_paint(SkPaint* paint)
{
    if (kSrcOver_SkXfermodeInterpretation
        == SkInterpretXfermode(*paint, false)) {
        paint->setXfermode(nullptr);
    }
}

static void emit_pdf_color(SkColor color, SkWStream* result)
{
    SkASSERT(SkColorGetA(color) == 0xFF); // We handle alpha elsewhere.
=======
static void replace_srcmode_on_opaque_paint(SkPaint* paint) {
    if (kSrcOver_SkXfermodeInterpretation
        == SkInterpretXfermode(*paint, false)) {
        paint->setXfermode(NULL);
    }
}

static void emit_pdf_color(SkColor color, SkWStream* result) {
    SkASSERT(SkColorGetA(color) == 0xFF);  // We handle alpha elsewhere.
>>>>>>> miniblink49
    SkScalar colorScale = SkScalarInvert(0xFF);
    SkPDFUtils::AppendScalar(SkColorGetR(color) * colorScale, result);
    result->writeText(" ");
    SkPDFUtils::AppendScalar(SkColorGetG(color) * colorScale, result);
    result->writeText(" ");
    SkPDFUtils::AppendScalar(SkColorGetB(color) * colorScale, result);
    result->writeText(" ");
}

<<<<<<< HEAD
static SkPaint calculate_text_paint(const SkPaint& paint)
{
    SkPaint result = paint;
    if (result.isFakeBoldText()) {
        SkScalar fakeBoldScale = SkScalarInterpFunc(result.getTextSize(),
            kStdFakeBoldInterpKeys,
            kStdFakeBoldInterpValues,
            kStdFakeBoldInterpLength);
=======
static SkPaint calculate_text_paint(const SkPaint& paint) {
    SkPaint result = paint;
    if (result.isFakeBoldText() || (result.getTypeface() && result.getTypeface()->isBold())) {
        SkScalar fakeBoldScale = SkScalarInterpFunc(result.getTextSize(),
                                                    kStdFakeBoldInterpKeys,
                                                    kStdFakeBoldInterpValues,
                                                    kStdFakeBoldInterpLength);
>>>>>>> miniblink49
        SkScalar width = SkScalarMul(result.getTextSize(), fakeBoldScale);
        if (result.getStyle() == SkPaint::kFill_Style) {
            result.setStyle(SkPaint::kStrokeAndFill_Style);
        } else {
            width += result.getStrokeWidth();
        }
        result.setStrokeWidth(width);
    }
    return result;
}

// Stolen from measure_text in SkDraw.cpp and then tweaked.
<<<<<<< HEAD
static void align_text(SkPaint::GlyphCacheProc glyphCacheProc, const SkPaint& paint,
    const uint16_t* glyphs, size_t len,
    SkScalar* x, SkScalar* y)
{
=======
static void align_text(SkDrawCacheProc glyphCacheProc, const SkPaint& paint,
                       const uint16_t* glyphs, size_t len,
                       SkScalar* x, SkScalar* y) {
>>>>>>> miniblink49
    if (paint.getTextAlign() == SkPaint::kLeft_Align) {
        return;
    }

    SkMatrix ident;
    ident.reset();
<<<<<<< HEAD
    SkAutoGlyphCache autoCache(paint, nullptr, &ident);
=======
    SkAutoGlyphCache autoCache(paint, NULL, &ident);
>>>>>>> miniblink49
    SkGlyphCache* cache = autoCache.getCache();

    const char* start = reinterpret_cast<const char*>(glyphs);
    const char* stop = reinterpret_cast<const char*>(glyphs + len);
<<<<<<< HEAD
    SkScalar xAdv = 0, yAdv = 0;

    // TODO(vandebo): This probably needs to take kerning into account.
    while (start < stop) {
        const SkGlyph& glyph = glyphCacheProc(cache, &start);
        xAdv += SkFloatToScalar(glyph.fAdvanceX);
        yAdv += SkFloatToScalar(glyph.fAdvanceY);
=======
    SkFixed xAdv = 0, yAdv = 0;

    // TODO(vandebo): This probably needs to take kerning into account.
    while (start < stop) {
        const SkGlyph& glyph = glyphCacheProc(cache, &start, 0, 0);
        xAdv += glyph.fAdvanceX;
        yAdv += glyph.fAdvanceY;
>>>>>>> miniblink49
    };
    if (paint.getTextAlign() == SkPaint::kLeft_Align) {
        return;
    }

<<<<<<< HEAD
    if (paint.getTextAlign() == SkPaint::kCenter_Align) {
        xAdv = SkScalarHalf(xAdv);
        yAdv = SkScalarHalf(yAdv);
    }
    *x = *x - xAdv;
    *y = *y - yAdv;
}

static int max_glyphid_for_typeface(SkTypeface* typeface)
{
=======
    SkScalar xAdj = SkFixedToScalar(xAdv);
    SkScalar yAdj = SkFixedToScalar(yAdv);
    if (paint.getTextAlign() == SkPaint::kCenter_Align) {
        xAdj = SkScalarHalf(xAdj);
        yAdj = SkScalarHalf(yAdj);
    }
    *x = *x - xAdj;
    *y = *y - yAdj;
}

static int max_glyphid_for_typeface(SkTypeface* typeface) {
>>>>>>> miniblink49
    SkAutoResolveDefaultTypeface autoResolve(typeface);
    typeface = autoResolve.get();
    return typeface->countGlyphs() - 1;
}

typedef SkAutoSTMalloc<128, uint16_t> SkGlyphStorage;

static int force_glyph_encoding(const SkPaint& paint, const void* text,
<<<<<<< HEAD
    size_t len, SkGlyphStorage* storage,
    const uint16_t** glyphIDs)
{
    // Make sure we have a glyph id encoding.
    if (paint.getTextEncoding() != SkPaint::kGlyphID_TextEncoding) {
        int numGlyphs = paint.textToGlyphs(text, len, nullptr);
=======
                                size_t len, SkGlyphStorage* storage,
                                const uint16_t** glyphIDs) {
    // Make sure we have a glyph id encoding.
    if (paint.getTextEncoding() != SkPaint::kGlyphID_TextEncoding) {
        int numGlyphs = paint.textToGlyphs(text, len, NULL);
>>>>>>> miniblink49
        storage->reset(numGlyphs);
        paint.textToGlyphs(text, len, storage->get());
        *glyphIDs = storage->get();
        return numGlyphs;
    }

    // For user supplied glyph ids we need to validate them.
    SkASSERT((len & 1) == 0);
    int numGlyphs = SkToInt(len / 2);
    const uint16_t* input = static_cast<const uint16_t*>(text);

    int maxGlyphID = max_glyphid_for_typeface(paint.getTypeface());
    int validated;
    for (validated = 0; validated < numGlyphs; ++validated) {
        if (input[validated] > maxGlyphID) {
            break;
        }
    }
    if (validated >= numGlyphs) {
        *glyphIDs = static_cast<const uint16_t*>(text);
        return numGlyphs;
    }

    // Silently drop anything out of range.
    storage->reset(numGlyphs);
    if (validated > 0) {
        memcpy(storage->get(), input, validated * sizeof(uint16_t));
    }

    for (int i = validated; i < numGlyphs; ++i) {
        storage->get()[i] = input[i];
        if (input[i] > maxGlyphID) {
            storage->get()[i] = 0;
        }
    }
    *glyphIDs = storage->get();
    return numGlyphs;
}

static void set_text_transform(SkScalar x, SkScalar y, SkScalar textSkewX,
<<<<<<< HEAD
    SkWStream* content)
{
=======
                               SkWStream* content) {
>>>>>>> miniblink49
    // Flip the text about the x-axis to account for origin swap and include
    // the passed parameters.
    content->writeText("1 0 ");
    SkPDFUtils::AppendScalar(0 - textSkewX, content);
    content->writeText(" -1 ");
    SkPDFUtils::AppendScalar(x, content);
    content->writeText(" ");
    SkPDFUtils::AppendScalar(y, content);
    content->writeText(" Tm\n");
}

<<<<<<< HEAD
SkPDFDevice::GraphicStateEntry::GraphicStateEntry()
    : fColor(SK_ColorBLACK)
    , fTextScaleX(SK_Scalar1)
    , fTextFill(SkPaint::kFill_Style)
    , fShaderIndex(-1)
    , fGraphicStateIndex(-1)
    , fFont(nullptr)
    , fTextSize(SK_ScalarNaN)
{
    fMatrix.reset();
}

bool SkPDFDevice::GraphicStateEntry::compareInitialState(
    const GraphicStateEntry& cur)
{
    return fColor == cur.fColor && fShaderIndex == cur.fShaderIndex && fGraphicStateIndex == cur.fGraphicStateIndex && fMatrix == cur.fMatrix && fClipStack == cur.fClipStack && (fTextScaleX == 0 || (fTextScaleX == cur.fTextScaleX && fTextFill == cur.fTextFill));
=======
// It is important to not confuse GraphicStateEntry with SkPDFGraphicState, the
// later being our representation of an object in the PDF file.
struct GraphicStateEntry {
    GraphicStateEntry();

    // Compare the fields we care about when setting up a new content entry.
    bool compareInitialState(const GraphicStateEntry& b);

    SkMatrix fMatrix;
    // We can't do set operations on Paths, though PDF natively supports
    // intersect.  If the clip stack does anything other than intersect,
    // we have to fall back to the region.  Treat fClipStack as authoritative.
    // See http://code.google.com/p/skia/issues/detail?id=221
    SkClipStack fClipStack;
    SkRegion fClipRegion;

    // When emitting the content entry, we will ensure the graphic state
    // is set to these values first.
    SkColor fColor;
    SkScalar fTextScaleX;  // Zero means we don't care what the value is.
    SkPaint::Style fTextFill;  // Only if TextScaleX is non-zero.
    int fShaderIndex;
    int fGraphicStateIndex;

    // We may change the font (i.e. for Type1 support) within a
    // ContentEntry.  This is the one currently in effect, or NULL if none.
    SkPDFFont* fFont;
    // In PDF, text size has no default value. It is only valid if fFont is
    // not NULL.
    SkScalar fTextSize;
};

GraphicStateEntry::GraphicStateEntry() : fColor(SK_ColorBLACK),
                                         fTextScaleX(SK_Scalar1),
                                         fTextFill(SkPaint::kFill_Style),
                                         fShaderIndex(-1),
                                         fGraphicStateIndex(-1),
                                         fFont(NULL),
                                         fTextSize(SK_ScalarNaN) {
    fMatrix.reset();
}

bool GraphicStateEntry::compareInitialState(const GraphicStateEntry& cur) {
    return fColor == cur.fColor &&
           fShaderIndex == cur.fShaderIndex &&
           fGraphicStateIndex == cur.fGraphicStateIndex &&
           fMatrix == cur.fMatrix &&
           fClipStack == cur.fClipStack &&
           (fTextScaleX == 0 ||
               (fTextScaleX == cur.fTextScaleX && fTextFill == cur.fTextFill));
>>>>>>> miniblink49
}

class GraphicStackState {
public:
    GraphicStackState(const SkClipStack& existingClipStack,
<<<<<<< HEAD
        const SkRegion& existingClipRegion,
        SkWStream* contentStream)
        : fStackDepth(0)
        , fContentStream(contentStream)
    {
=======
                      const SkRegion& existingClipRegion,
                      SkWStream* contentStream)
            : fStackDepth(0),
              fContentStream(contentStream) {
>>>>>>> miniblink49
        fEntries[0].fClipStack = existingClipStack;
        fEntries[0].fClipRegion = existingClipRegion;
    }

    void updateClip(const SkClipStack& clipStack, const SkRegion& clipRegion,
<<<<<<< HEAD
        const SkPoint& translation);
    void updateMatrix(const SkMatrix& matrix);
    void updateDrawingState(const SkPDFDevice::GraphicStateEntry& state);
=======
                    const SkPoint& translation);
    void updateMatrix(const SkMatrix& matrix);
    void updateDrawingState(const GraphicStateEntry& state);
>>>>>>> miniblink49

    void drainStack();

private:
    void push();
    void pop();
<<<<<<< HEAD
    SkPDFDevice::GraphicStateEntry* currentEntry() { return &fEntries[fStackDepth]; }

    // Conservative limit on save depth, see impl. notes in PDF 1.4 spec.
    static const int kMaxStackDepth = 12;
    SkPDFDevice::GraphicStateEntry fEntries[kMaxStackDepth + 1];
=======
    GraphicStateEntry* currentEntry() { return &fEntries[fStackDepth]; }

    // Conservative limit on save depth, see impl. notes in PDF 1.4 spec.
    static const int kMaxStackDepth = 12;
    GraphicStateEntry fEntries[kMaxStackDepth + 1];
>>>>>>> miniblink49
    int fStackDepth;
    SkWStream* fContentStream;
};

<<<<<<< HEAD
void GraphicStackState::drainStack()
{
=======
void GraphicStackState::drainStack() {
>>>>>>> miniblink49
    while (fStackDepth) {
        pop();
    }
}

<<<<<<< HEAD
void GraphicStackState::push()
{
=======
void GraphicStackState::push() {
>>>>>>> miniblink49
    SkASSERT(fStackDepth < kMaxStackDepth);
    fContentStream->writeText("q\n");
    fStackDepth++;
    fEntries[fStackDepth] = fEntries[fStackDepth - 1];
}

<<<<<<< HEAD
void GraphicStackState::pop()
{
=======
void GraphicStackState::pop() {
>>>>>>> miniblink49
    SkASSERT(fStackDepth > 0);
    fContentStream->writeText("Q\n");
    fStackDepth--;
}

// This function initializes iter to be an iterator on the "stack" argument
// and then skips over the leading entries as specified in prefix.  It requires
// and asserts that "prefix" will be a prefix to "stack."
static void skip_clip_stack_prefix(const SkClipStack& prefix,
<<<<<<< HEAD
    const SkClipStack& stack,
    SkClipStack::Iter* iter)
{
=======
                                   const SkClipStack& stack,
                                   SkClipStack::Iter* iter) {
>>>>>>> miniblink49
    SkClipStack::B2TIter prefixIter(prefix);
    iter->reset(stack, SkClipStack::Iter::kBottom_IterStart);

    const SkClipStack::Element* prefixEntry;
    const SkClipStack::Element* iterEntry;

    for (prefixEntry = prefixIter.next(); prefixEntry;
<<<<<<< HEAD
         prefixEntry = prefixIter.next()) {
=======
            prefixEntry = prefixIter.next()) {
>>>>>>> miniblink49
        iterEntry = iter->next();
        SkASSERT(iterEntry);
        // Because of SkClipStack does internal intersection, the last clip
        // entry may differ.
        if (*prefixEntry != *iterEntry) {
            SkASSERT(prefixEntry->getOp() == SkRegion::kIntersect_Op);
            SkASSERT(iterEntry->getOp() == SkRegion::kIntersect_Op);
            SkASSERT(iterEntry->getType() == prefixEntry->getType());
            // back up the iterator by one
            iter->prev();
            prefixEntry = prefixIter.next();
            break;
        }
    }

<<<<<<< HEAD
    SkASSERT(prefixEntry == nullptr);
}

static void emit_clip(SkPath* clipPath, SkRect* clipRect,
    SkWStream* contentStream)
{
=======
    SkASSERT(prefixEntry == NULL);
}

static void emit_clip(SkPath* clipPath, SkRect* clipRect,
                      SkWStream* contentStream) {
>>>>>>> miniblink49
    SkASSERT(clipPath || clipRect);

    SkPath::FillType clipFill;
    if (clipPath) {
        SkPDFUtils::EmitPath(*clipPath, SkPaint::kFill_Style, contentStream);
        clipFill = clipPath->getFillType();
    } else {
        SkPDFUtils::AppendRectangle(*clipRect, contentStream);
        clipFill = SkPath::kWinding_FillType;
    }

    NOT_IMPLEMENTED(clipFill == SkPath::kInverseEvenOdd_FillType, false);
    NOT_IMPLEMENTED(clipFill == SkPath::kInverseWinding_FillType, false);
    if (clipFill == SkPath::kEvenOdd_FillType) {
        contentStream->writeText("W* n\n");
    } else {
        contentStream->writeText("W n\n");
    }
}

/* Calculate an inverted path's equivalent non-inverted path, given the
 * canvas bounds.
 * outPath may alias with invPath (since this is supported by PathOps).
 */
static bool calculate_inverse_path(const SkRect& bounds, const SkPath& invPath,
<<<<<<< HEAD
    SkPath* outPath)
{
=======
                                   SkPath* outPath) {
>>>>>>> miniblink49
    SkASSERT(invPath.isInverseFillType());

    SkPath clipPath;
    clipPath.addRect(bounds);

    return Op(clipPath, invPath, kIntersect_SkPathOp, outPath);
}

<<<<<<< HEAD
=======
#ifdef SK_PDF_USE_PATHOPS_CLIPPING
>>>>>>> miniblink49
// Sanity check the numerical values of the SkRegion ops and PathOps ops
// enums so region_op_to_pathops_op can do a straight passthrough cast.
// If these are failing, it may be necessary to make region_op_to_pathops_op
// do more.
<<<<<<< HEAD
static_assert(SkRegion::kDifference_Op == (int)kDifference_SkPathOp, "region_pathop_mismatch");
static_assert(SkRegion::kIntersect_Op == (int)kIntersect_SkPathOp, "region_pathop_mismatch");
static_assert(SkRegion::kUnion_Op == (int)kUnion_SkPathOp, "region_pathop_mismatch");
static_assert(SkRegion::kXOR_Op == (int)kXOR_SkPathOp, "region_pathop_mismatch");
static_assert(SkRegion::kReverseDifference_Op == (int)kReverseDifference_SkPathOp,
    "region_pathop_mismatch");

static SkPathOp region_op_to_pathops_op(SkRegion::Op op)
{
=======
SK_COMPILE_ASSERT(SkRegion::kDifference_Op == (int)kDifference_SkPathOp,
                  region_pathop_mismatch);
SK_COMPILE_ASSERT(SkRegion::kIntersect_Op == (int)kIntersect_SkPathOp,
                  region_pathop_mismatch);
SK_COMPILE_ASSERT(SkRegion::kUnion_Op == (int)kUnion_SkPathOp,
                  region_pathop_mismatch);
SK_COMPILE_ASSERT(SkRegion::kXOR_Op == (int)kXOR_SkPathOp,
                  region_pathop_mismatch);
SK_COMPILE_ASSERT(SkRegion::kReverseDifference_Op ==
                  (int)kReverseDifference_SkPathOp,
                  region_pathop_mismatch);

static SkPathOp region_op_to_pathops_op(SkRegion::Op op) {
>>>>>>> miniblink49
    SkASSERT(op >= 0);
    SkASSERT(op <= SkRegion::kReverseDifference_Op);
    return (SkPathOp)op;
}

/* Uses Path Ops to calculate a vector SkPath clip from a clip stack.
 * Returns true if successful, or false if not successful.
 * If successful, the resulting clip is stored in outClipPath.
 * If not successful, outClipPath is undefined, and a fallback method
 * should be used.
 */
static bool get_clip_stack_path(const SkMatrix& transform,
<<<<<<< HEAD
    const SkClipStack& clipStack,
    const SkRegion& clipRegion,
    SkPath* outClipPath)
{
=======
                                const SkClipStack& clipStack,
                                const SkRegion& clipRegion,
                                SkPath* outClipPath) {
>>>>>>> miniblink49
    outClipPath->reset();
    outClipPath->setFillType(SkPath::kInverseWinding_FillType);

    const SkClipStack::Element* clipEntry;
    SkClipStack::Iter iter;
    iter.reset(clipStack, SkClipStack::Iter::kBottom_IterStart);
    for (clipEntry = iter.next(); clipEntry; clipEntry = iter.next()) {
        SkPath entryPath;
        if (SkClipStack::Element::kEmpty_Type == clipEntry->getType()) {
            outClipPath->reset();
            outClipPath->setFillType(SkPath::kInverseWinding_FillType);
            continue;
        } else {
            clipEntry->asPath(&entryPath);
        }
        entryPath.transform(transform);

        if (SkRegion::kReplace_Op == clipEntry->getOp()) {
            *outClipPath = entryPath;
        } else {
            SkPathOp op = region_op_to_pathops_op(clipEntry->getOp());
            if (!Op(*outClipPath, entryPath, op, outClipPath)) {
                return false;
            }
        }
    }

    if (outClipPath->isInverseFillType()) {
        // The bounds are slightly outset to ensure this is correct in the
        // face of floating-point accuracy and possible SkRegion bitmap
        // approximations.
        SkRect clipBounds = SkRect::Make(clipRegion.getBounds());
        clipBounds.outset(SK_Scalar1, SK_Scalar1);
        if (!calculate_inverse_path(clipBounds, *outClipPath, outClipPath)) {
            return false;
        }
    }
    return true;
}
<<<<<<< HEAD
=======
#endif
>>>>>>> miniblink49

// TODO(vandebo): Take advantage of SkClipStack::getSaveCount(), the PDF
// graphic state stack, and the fact that we can know all the clips used
// on the page to optimize this.
void GraphicStackState::updateClip(const SkClipStack& clipStack,
<<<<<<< HEAD
    const SkRegion& clipRegion,
    const SkPoint& translation)
{
=======
                                   const SkRegion& clipRegion,
                                   const SkPoint& translation) {
>>>>>>> miniblink49
    if (clipStack == currentEntry()->fClipStack) {
        return;
    }

    while (fStackDepth > 0) {
        pop();
        if (clipStack == currentEntry()->fClipStack) {
            return;
        }
    }
    push();

    currentEntry()->fClipStack = clipStack;
    currentEntry()->fClipRegion = clipRegion;

    SkMatrix transform;
    transform.setTranslate(translation.fX, translation.fY);

<<<<<<< HEAD
    SkPath clipPath;
    if (get_clip_stack_path(transform, clipStack, clipRegion, &clipPath)) {
        emit_clip(&clipPath, nullptr, fContentStream);
        return;
    }

=======
#ifdef SK_PDF_USE_PATHOPS_CLIPPING
    SkPath clipPath;
    if (get_clip_stack_path(transform, clipStack, clipRegion, &clipPath)) {
        emit_clip(&clipPath, NULL, fContentStream);
        return;
    }
#endif
>>>>>>> miniblink49
    // gsState->initialEntry()->fClipStack/Region specifies the clip that has
    // already been applied.  (If this is a top level device, then it specifies
    // a clip to the content area.  If this is a layer, then it specifies
    // the clip in effect when the layer was created.)  There's no need to
    // reapply that clip; SKCanvas's SkDrawIter will draw anything outside the
    // initial clip on the parent layer.  (This means there's a bug if the user
    // expands the clip and then uses any xfer mode that uses dst:
    // http://code.google.com/p/skia/issues/detail?id=228 )
    SkClipStack::Iter iter;
    skip_clip_stack_prefix(fEntries[0].fClipStack, clipStack, &iter);

    // If the clip stack does anything other than intersect or if it uses
    // an inverse fill type, we have to fall back to the clip region.
    bool needRegion = false;
    const SkClipStack::Element* clipEntry;
    for (clipEntry = iter.next(); clipEntry; clipEntry = iter.next()) {
<<<<<<< HEAD
        if (clipEntry->getOp() != SkRegion::kIntersect_Op || clipEntry->isInverseFilled()) {
=======
        if (clipEntry->getOp() != SkRegion::kIntersect_Op ||
                clipEntry->isInverseFilled()) {
>>>>>>> miniblink49
            needRegion = true;
            break;
        }
    }

    if (needRegion) {
        SkPath clipPath;
        SkAssertResult(clipRegion.getBoundaryPath(&clipPath));
<<<<<<< HEAD
        emit_clip(&clipPath, nullptr, fContentStream);
=======
        emit_clip(&clipPath, NULL, fContentStream);
>>>>>>> miniblink49
    } else {
        skip_clip_stack_prefix(fEntries[0].fClipStack, clipStack, &iter);
        const SkClipStack::Element* clipEntry;
        for (clipEntry = iter.next(); clipEntry; clipEntry = iter.next()) {
            SkASSERT(clipEntry->getOp() == SkRegion::kIntersect_Op);
            switch (clipEntry->getType()) {
<<<<<<< HEAD
            case SkClipStack::Element::kRect_Type: {
                SkRect translatedClip;
                transform.mapRect(&translatedClip, clipEntry->getRect());
                emit_clip(nullptr, &translatedClip, fContentStream);
                break;
            }
            default: {
                SkPath translatedPath;
                clipEntry->asPath(&translatedPath);
                translatedPath.transform(transform, &translatedPath);
                emit_clip(&translatedPath, nullptr, fContentStream);
                break;
            }
=======
                case SkClipStack::Element::kRect_Type: {
                    SkRect translatedClip;
                    transform.mapRect(&translatedClip, clipEntry->getRect());
                    emit_clip(NULL, &translatedClip, fContentStream);
                    break;
                }
                default: {
                    SkPath translatedPath;
                    clipEntry->asPath(&translatedPath);
                    translatedPath.transform(transform, &translatedPath);
                    emit_clip(&translatedPath, NULL, fContentStream);
                    break;
                }
>>>>>>> miniblink49
            }
        }
    }
}

<<<<<<< HEAD
void GraphicStackState::updateMatrix(const SkMatrix& matrix)
{
=======
void GraphicStackState::updateMatrix(const SkMatrix& matrix) {
>>>>>>> miniblink49
    if (matrix == currentEntry()->fMatrix) {
        return;
    }

    if (currentEntry()->fMatrix.getType() != SkMatrix::kIdentity_Mask) {
        SkASSERT(fStackDepth > 0);
<<<<<<< HEAD
        SkASSERT(fEntries[fStackDepth].fClipStack == fEntries[fStackDepth - 1].fClipStack);
=======
        SkASSERT(fEntries[fStackDepth].fClipStack ==
                 fEntries[fStackDepth -1].fClipStack);
>>>>>>> miniblink49
        pop();

        SkASSERT(currentEntry()->fMatrix.getType() == SkMatrix::kIdentity_Mask);
    }
    if (matrix.getType() == SkMatrix::kIdentity_Mask) {
        return;
    }

    push();
    SkPDFUtils::AppendTransform(matrix, fContentStream);
    currentEntry()->fMatrix = matrix;
}

<<<<<<< HEAD
void GraphicStackState::updateDrawingState(const SkPDFDevice::GraphicStateEntry& state)
{
=======
void GraphicStackState::updateDrawingState(const GraphicStateEntry& state) {
>>>>>>> miniblink49
    // PDF treats a shader as a color, so we only set one or the other.
    if (state.fShaderIndex >= 0) {
        if (state.fShaderIndex != currentEntry()->fShaderIndex) {
            SkPDFUtils::ApplyPattern(state.fShaderIndex, fContentStream);
            currentEntry()->fShaderIndex = state.fShaderIndex;
        }
    } else {
<<<<<<< HEAD
        if (state.fColor != currentEntry()->fColor || currentEntry()->fShaderIndex >= 0) {
=======
        if (state.fColor != currentEntry()->fColor ||
                currentEntry()->fShaderIndex >= 0) {
>>>>>>> miniblink49
            emit_pdf_color(state.fColor, fContentStream);
            fContentStream->writeText("RG ");
            emit_pdf_color(state.fColor, fContentStream);
            fContentStream->writeText("rg\n");
            currentEntry()->fColor = state.fColor;
            currentEntry()->fShaderIndex = -1;
        }
    }

    if (state.fGraphicStateIndex != currentEntry()->fGraphicStateIndex) {
        SkPDFUtils::ApplyGraphicState(state.fGraphicStateIndex, fContentStream);
        currentEntry()->fGraphicStateIndex = state.fGraphicStateIndex;
    }

    if (state.fTextScaleX) {
        if (state.fTextScaleX != currentEntry()->fTextScaleX) {
            SkScalar pdfScale = SkScalarMul(state.fTextScaleX,
<<<<<<< HEAD
                SkIntToScalar(100));
=======
                                            SkIntToScalar(100));
>>>>>>> miniblink49
            SkPDFUtils::AppendScalar(pdfScale, fContentStream);
            fContentStream->writeText(" Tz\n");
            currentEntry()->fTextScaleX = state.fTextScaleX;
        }
        if (state.fTextFill != currentEntry()->fTextFill) {
<<<<<<< HEAD
            static_assert(SkPaint::kFill_Style == 0, "enum_must_match_value");
            static_assert(SkPaint::kStroke_Style == 1, "enum_must_match_value");
            static_assert(SkPaint::kStrokeAndFill_Style == 2, "enum_must_match_value");
=======
            SK_COMPILE_ASSERT(SkPaint::kFill_Style == 0, enum_must_match_value);
            SK_COMPILE_ASSERT(SkPaint::kStroke_Style == 1,
                              enum_must_match_value);
            SK_COMPILE_ASSERT(SkPaint::kStrokeAndFill_Style == 2,
                              enum_must_match_value);
>>>>>>> miniblink49
            fContentStream->writeDecAsText(state.fTextFill);
            fContentStream->writeText(" Tr\n");
            currentEntry()->fTextFill = state.fTextFill;
        }
    }
}

<<<<<<< HEAD
static bool not_supported_for_layers(const SkPaint& layerPaint)
{
    // PDF does not support image filters, so render them on CPU.
    // Note that this rendering is done at "screen" resolution (100dpi), not
    // printer resolution.
    // TODO: It may be possible to express some filters natively using PDF
    // to improve quality and file size (https://bug.skia.org/3043)

    // TODO: should we return true if there is a colorfilter?
    return layerPaint.getImageFilter() != nullptr;
}

SkBaseDevice* SkPDFDevice::onCreateDevice(const CreateInfo& cinfo, const SkPaint* layerPaint)
{
    if (cinfo.fForImageFilter || (layerPaint && not_supported_for_layers(*layerPaint))) {
        return nullptr;
    }
    SkISize size = SkISize::Make(cinfo.fInfo.width(), cinfo.fInfo.height());
    return SkPDFDevice::Create(size, fRasterDpi, fDocument);
}

SkPDFCanon* SkPDFDevice::getCanon() const { return fDocument->canon(); }
=======
static bool not_supported_for_layers(const SkPaint& layerPaint) {
    // PDF does not support image filters, so render them on CPU.
    // Note that this rendering is done at "screen" resolution (100dpi), not
    // printer resolution.
    // FIXME: It may be possible to express some filters natively using PDF
    // to improve quality and file size (http://skbug.com/3043)

    // TODO: should we return true if there is a colorfilter?
    return layerPaint.getImageFilter() != NULL;
}

SkBaseDevice* SkPDFDevice::onCreateDevice(const CreateInfo& cinfo, const SkPaint* layerPaint) {
    if (cinfo.fForImageFilter ||
        (layerPaint && not_supported_for_layers(*layerPaint))) {
        return NULL;
    }
    SkISize size = SkISize::Make(cinfo.fInfo.width(), cinfo.fInfo.height());
    return SkPDFDevice::Create(size, fRasterDpi, fCanon);
}


struct ContentEntry {
    GraphicStateEntry fState;
    SkDynamicMemoryWStream fContent;
    SkAutoTDelete<ContentEntry> fNext;

    // If the stack is too deep we could get Stack Overflow.
    // So we manually destruct the object.
    ~ContentEntry() {
        ContentEntry* val = fNext.detach();
        while (val != NULL) {
            ContentEntry* valNext = val->fNext.detach();
            // When the destructor is called, fNext is NULL and exits.
            delete val;
            val = valNext;
        }
    }
};
>>>>>>> miniblink49

// A helper class to automatically finish a ContentEntry at the end of a
// drawing method and maintain the state needed between set up and finish.
class ScopedContentEntry {
public:
    ScopedContentEntry(SkPDFDevice* device, const SkDraw& draw,
<<<<<<< HEAD
        const SkPaint& paint, bool hasText = false)
        : fDevice(device)
        , fContentEntry(nullptr)
        , fXfermode(SkXfermode::kSrcOver_Mode)
        , fDstFormXObject(nullptr)
    {
        init(draw.fClipStack, draw.fRC->bwRgn(), *draw.fMatrix, paint, hasText);
    }
    ScopedContentEntry(SkPDFDevice* device, const SkClipStack* clipStack,
        const SkRegion& clipRegion, const SkMatrix& matrix,
        const SkPaint& paint, bool hasText = false)
        : fDevice(device)
        , fContentEntry(nullptr)
        , fXfermode(SkXfermode::kSrcOver_Mode)
        , fDstFormXObject(nullptr)
    {
        init(clipStack, clipRegion, matrix, paint, hasText);
    }

    ~ScopedContentEntry()
    {
        if (fContentEntry) {
            SkPath* shape = &fShape;
            if (shape->isEmpty()) {
                shape = nullptr;
=======
                       const SkPaint& paint, bool hasText = false)
        : fDevice(device),
          fContentEntry(NULL),
          fXfermode(SkXfermode::kSrcOver_Mode),
          fDstFormXObject(NULL) {
        init(draw.fClipStack, *draw.fClip, *draw.fMatrix, paint, hasText);
    }
    ScopedContentEntry(SkPDFDevice* device, const SkClipStack* clipStack,
                       const SkRegion& clipRegion, const SkMatrix& matrix,
                       const SkPaint& paint, bool hasText = false)
        : fDevice(device),
          fContentEntry(NULL),
          fXfermode(SkXfermode::kSrcOver_Mode),
          fDstFormXObject(NULL) {
        init(clipStack, clipRegion, matrix, paint, hasText);
    }

    ~ScopedContentEntry() {
        if (fContentEntry) {
            SkPath* shape = &fShape;
            if (shape->isEmpty()) {
                shape = NULL;
>>>>>>> miniblink49
            }
            fDevice->finishContentEntry(fXfermode, fDstFormXObject, shape);
        }
        SkSafeUnref(fDstFormXObject);
    }

<<<<<<< HEAD
    SkPDFDevice::ContentEntry* entry() { return fContentEntry; }

    /* Returns true when we explicitly need the shape of the drawing. */
    bool needShape()
    {
        switch (fXfermode) {
        case SkXfermode::kClear_Mode:
        case SkXfermode::kSrc_Mode:
        case SkXfermode::kSrcIn_Mode:
        case SkXfermode::kSrcOut_Mode:
        case SkXfermode::kDstIn_Mode:
        case SkXfermode::kDstOut_Mode:
        case SkXfermode::kSrcATop_Mode:
        case SkXfermode::kDstATop_Mode:
        case SkXfermode::kModulate_Mode:
            return true;
        default:
            return false;
=======
    ContentEntry* entry() { return fContentEntry; }

    /* Returns true when we explicitly need the shape of the drawing. */
    bool needShape() {
        switch (fXfermode) {
            case SkXfermode::kClear_Mode:
            case SkXfermode::kSrc_Mode:
            case SkXfermode::kSrcIn_Mode:
            case SkXfermode::kSrcOut_Mode:
            case SkXfermode::kDstIn_Mode:
            case SkXfermode::kDstOut_Mode:
            case SkXfermode::kSrcATop_Mode:
            case SkXfermode::kDstATop_Mode:
            case SkXfermode::kModulate_Mode:
                return true;
            default:
                return false;
>>>>>>> miniblink49
        }
    }

    /* Returns true unless we only need the shape of the drawing. */
<<<<<<< HEAD
    bool needSource()
    {
=======
    bool needSource() {
>>>>>>> miniblink49
        if (fXfermode == SkXfermode::kClear_Mode) {
            return false;
        }
        return true;
    }

    /* If the shape is different than the alpha component of the content, then
     * setShape should be called with the shape.  In particular, images and
     * devices have rectangular shape.
     */
<<<<<<< HEAD
    void setShape(const SkPath& shape)
    {
=======
    void setShape(const SkPath& shape) {
>>>>>>> miniblink49
        fShape = shape;
    }

private:
    SkPDFDevice* fDevice;
<<<<<<< HEAD
    SkPDFDevice::ContentEntry* fContentEntry;
=======
    ContentEntry* fContentEntry;
>>>>>>> miniblink49
    SkXfermode::Mode fXfermode;
    SkPDFFormXObject* fDstFormXObject;
    SkPath fShape;

    void init(const SkClipStack* clipStack, const SkRegion& clipRegion,
<<<<<<< HEAD
        const SkMatrix& matrix, const SkPaint& paint, bool hasText)
    {
=======
              const SkMatrix& matrix, const SkPaint& paint, bool hasText) {
>>>>>>> miniblink49
        // Shape has to be flatten before we get here.
        if (matrix.hasPerspective()) {
            NOT_IMPLEMENTED(!matrix.hasPerspective(), false);
            return;
        }
        if (paint.getXfermode()) {
            paint.getXfermode()->asMode(&fXfermode);
        }
        fContentEntry = fDevice->setUpContentEntry(clipStack, clipRegion,
<<<<<<< HEAD
            matrix, paint, hasText,
            &fDstFormXObject);
=======
                                                   matrix, paint, hasText,
                                                   &fDstFormXObject);
>>>>>>> miniblink49
    }
};

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkPDFDevice::SkPDFDevice(SkISize pageSize, SkScalar rasterDpi, SkPDFDocument* doc, bool flip)
=======
SkPDFDevice::SkPDFDevice(SkISize pageSize,
                         SkScalar rasterDpi,
                         SkPDFCanon* canon,
                         bool flip)
>>>>>>> miniblink49
    : INHERITED(SkSurfaceProps(0, kUnknown_SkPixelGeometry))
    , fPageSize(pageSize)
    , fContentSize(pageSize)
    , fExistingClipRegion(SkIRect::MakeSize(pageSize))
<<<<<<< HEAD
    , fClipStack(nullptr)
    , fFontGlyphUsage(new SkPDFGlyphSetMap)
    , fRasterDpi(rasterDpi)
    , fDocument(doc)
{
    SkASSERT(pageSize.width() > 0);
    SkASSERT(pageSize.height() > 0);
    fLegacyBitmap.setInfo(
        SkImageInfo::MakeUnknown(pageSize.width(), pageSize.height()));
=======
    , fAnnotations(NULL)
    , fLastContentEntry(NULL)
    , fLastMarginContentEntry(NULL)
    , fDrawingArea(kContent_DrawingArea)
    , fClipStack(NULL)
    , fFontGlyphUsage(SkNEW(SkPDFGlyphSetMap))
    , fRasterDpi(rasterDpi)
    , fCanon(canon) {
    SkASSERT(pageSize.width() > 0);
    SkASSERT(pageSize.height() > 0);
    fLegacyBitmap.setInfo(
            SkImageInfo::MakeUnknown(pageSize.width(), pageSize.height()));
>>>>>>> miniblink49
    if (flip) {
        // Skia generally uses the top left as the origin but PDF
        // natively has the origin at the bottom left. This matrix
        // corrects for that.  But that only needs to be done once, we
        // don't do it when layering.
        fInitialTransform.setTranslate(0, SkIntToScalar(pageSize.fHeight));
        fInitialTransform.preScale(SK_Scalar1, -SK_Scalar1);
    } else {
        fInitialTransform.setIdentity();
    }
}

<<<<<<< HEAD
SkPDFDevice::~SkPDFDevice()
{
    this->cleanUp(true);
}

void SkPDFDevice::init()
{
    fContentEntries.reset();
    if (fFontGlyphUsage.get() == nullptr) {
        fFontGlyphUsage.reset(new SkPDFGlyphSetMap);
    }
}

void SkPDFDevice::cleanUp(bool clearFontUsage)
{
=======
SkPDFDevice::~SkPDFDevice() {
    this->cleanUp(true);
}

void SkPDFDevice::init() {
    fAnnotations = NULL;
    fContentEntries.free();
    fLastContentEntry = NULL;
    fMarginContentEntries.free();
    fLastMarginContentEntry = NULL;
    fDrawingArea = kContent_DrawingArea;
    if (fFontGlyphUsage.get() == NULL) {
        fFontGlyphUsage.reset(SkNEW(SkPDFGlyphSetMap));
    }
}

void SkPDFDevice::cleanUp(bool clearFontUsage) {
>>>>>>> miniblink49
    fGraphicStateResources.unrefAll();
    fXObjectResources.unrefAll();
    fFontResources.unrefAll();
    fShaderResources.unrefAll();
<<<<<<< HEAD
=======
    SkSafeUnref(fAnnotations);
    fNamedDestinations.deleteAll();
>>>>>>> miniblink49

    if (clearFontUsage) {
        fFontGlyphUsage->reset();
    }
}

<<<<<<< HEAD
void SkPDFDevice::drawAnnotation(const SkDraw& d, const SkRect& rect, const char key[],
    SkData* value)
{
    if (0 == rect.width() && 0 == rect.height()) {
        handlePointAnnotation({ rect.x(), rect.y() }, *d.fMatrix, key, value);
    } else {
        SkPath path;
        path.addRect(rect);
        handlePathAnnotation(path, d, key, value);
    }
}

void SkPDFDevice::drawPaint(const SkDraw& d, const SkPaint& paint)
{
=======
void SkPDFDevice::drawPaint(const SkDraw& d, const SkPaint& paint) {
>>>>>>> miniblink49
    SkPaint newPaint = paint;
    replace_srcmode_on_opaque_paint(&newPaint);

    newPaint.setStyle(SkPaint::kFill_Style);
    ScopedContentEntry content(this, d, newPaint);
    internalDrawPaint(newPaint, content.entry());
}

void SkPDFDevice::internalDrawPaint(const SkPaint& paint,
<<<<<<< HEAD
    SkPDFDevice::ContentEntry* contentEntry)
{
=======
                                    ContentEntry* contentEntry) {
>>>>>>> miniblink49
    if (!contentEntry) {
        return;
    }
    SkRect bbox = SkRect::MakeWH(SkIntToScalar(this->width()),
<<<<<<< HEAD
        SkIntToScalar(this->height()));
=======
                                 SkIntToScalar(this->height()));
>>>>>>> miniblink49
    SkMatrix inverse;
    if (!contentEntry->fState.fMatrix.invert(&inverse)) {
        return;
    }
    inverse.mapRect(&bbox);

    SkPDFUtils::AppendRectangle(bbox, &contentEntry->fContent);
    SkPDFUtils::PaintPath(paint.getStyle(), SkPath::kWinding_FillType,
<<<<<<< HEAD
        &contentEntry->fContent);
}

void SkPDFDevice::drawPoints(const SkDraw& d,
    SkCanvas::PointMode mode,
    size_t count,
    const SkPoint* points,
    const SkPaint& srcPaint)
{
=======
                          &contentEntry->fContent);
}

void SkPDFDevice::drawPoints(const SkDraw& d,
                             SkCanvas::PointMode mode,
                             size_t count,
                             const SkPoint* points,
                             const SkPaint& srcPaint) {
>>>>>>> miniblink49
    SkPaint passedPaint = srcPaint;
    replace_srcmode_on_opaque_paint(&passedPaint);

    if (count == 0) {
        return;
    }

<<<<<<< HEAD
=======
    if (handlePointAnnotation(points, count, *d.fMatrix, passedPaint)) {
        return;
    }

>>>>>>> miniblink49
    // SkDraw::drawPoints converts to multiple calls to fDevice->drawPath.
    // We only use this when there's a path effect because of the overhead
    // of multiple calls to setUpContentEntry it causes.
    if (passedPaint.getPathEffect()) {
<<<<<<< HEAD
        if (d.fRC->isEmpty()) {
=======
        if (d.fClip->isEmpty()) {
>>>>>>> miniblink49
            return;
        }
        SkDraw pointDraw(d);
        pointDraw.fDevice = this;
        pointDraw.drawPoints(mode, count, points, passedPaint, true);
        return;
    }

    const SkPaint* paint = &passedPaint;
    SkPaint modifiedPaint;

<<<<<<< HEAD
    if (mode == SkCanvas::kPoints_PointMode && paint->getStrokeCap() != SkPaint::kRound_Cap) {
=======
    if (mode == SkCanvas::kPoints_PointMode &&
            paint->getStrokeCap() != SkPaint::kRound_Cap) {
>>>>>>> miniblink49
        modifiedPaint = *paint;
        paint = &modifiedPaint;
        if (paint->getStrokeWidth()) {
            // PDF won't draw a single point with square/butt caps because the
            // orientation is ambiguous.  Draw a rectangle instead.
            modifiedPaint.setStyle(SkPaint::kFill_Style);
            SkScalar strokeWidth = paint->getStrokeWidth();
            SkScalar halfStroke = SkScalarHalf(strokeWidth);
            for (size_t i = 0; i < count; i++) {
                SkRect r = SkRect::MakeXYWH(points[i].fX, points[i].fY, 0, 0);
                r.inset(-halfStroke, -halfStroke);
                drawRect(d, r, modifiedPaint);
            }
            return;
        } else {
            modifiedPaint.setStrokeCap(SkPaint::kRound_Cap);
        }
    }

    ScopedContentEntry content(this, d, *paint);
    if (!content.entry()) {
        return;
    }

    switch (mode) {
<<<<<<< HEAD
    case SkCanvas::kPolygon_PointMode:
        SkPDFUtils::MoveTo(points[0].fX, points[0].fY,
            &content.entry()->fContent);
        for (size_t i = 1; i < count; i++) {
            SkPDFUtils::AppendLine(points[i].fX, points[i].fY,
                &content.entry()->fContent);
        }
        SkPDFUtils::StrokePath(&content.entry()->fContent);
        break;
    case SkCanvas::kLines_PointMode:
        for (size_t i = 0; i < count / 2; i++) {
            SkPDFUtils::MoveTo(points[i * 2].fX, points[i * 2].fY,
                &content.entry()->fContent);
            SkPDFUtils::AppendLine(points[i * 2 + 1].fX,
                points[i * 2 + 1].fY,
                &content.entry()->fContent);
            SkPDFUtils::StrokePath(&content.entry()->fContent);
        }
        break;
    case SkCanvas::kPoints_PointMode:
        SkASSERT(paint->getStrokeCap() == SkPaint::kRound_Cap);
        for (size_t i = 0; i < count; i++) {
            SkPDFUtils::MoveTo(points[i].fX, points[i].fY,
                &content.entry()->fContent);
            SkPDFUtils::ClosePath(&content.entry()->fContent);
            SkPDFUtils::StrokePath(&content.entry()->fContent);
        }
        break;
    default:
        SkASSERT(false);
    }
}

static sk_sp<SkPDFDict> create_link_annotation(const SkRect& translatedRect)
{
    auto annotation = sk_make_sp<SkPDFDict>("Annot");
    annotation->insertName("Subtype", "Link");
    annotation->insertInt("F", 4); // required by ISO 19005

    auto border = sk_make_sp<SkPDFArray>();
    border->reserve(3);
    border->appendInt(0); // Horizontal corner radius.
    border->appendInt(0); // Vertical corner radius.
    border->appendInt(0); // Width, 0 = no border.
    annotation->insertObject("Border", std::move(border));

    auto rect = sk_make_sp<SkPDFArray>();
    rect->reserve(4);
    rect->appendScalar(translatedRect.fLeft);
    rect->appendScalar(translatedRect.fTop);
    rect->appendScalar(translatedRect.fRight);
    rect->appendScalar(translatedRect.fBottom);
    annotation->insertObject("Rect", std::move(rect));

    return annotation;
}

static sk_sp<SkPDFDict> create_link_to_url(const SkData* urlData, const SkRect& r)
{
    auto annotation = create_link_annotation(r);
    SkString url(static_cast<const char*>(urlData->data()),
        urlData->size() - 1);
    auto action = sk_make_sp<SkPDFDict>("Action");
    action->insertName("S", "URI");
    action->insertString("URI", url);
    annotation->insertObject("A", std::move(action));
    return annotation;
}

static sk_sp<SkPDFDict> create_link_named_dest(const SkData* nameData,
    const SkRect& r)
{
    auto annotation = create_link_annotation(r);
    SkString name(static_cast<const char*>(nameData->data()),
        nameData->size() - 1);
    annotation->insertName("Dest", name);
    return annotation;
}

void SkPDFDevice::drawRect(const SkDraw& d,
    const SkRect& rect,
    const SkPaint& srcPaint)
{
=======
        case SkCanvas::kPolygon_PointMode:
            SkPDFUtils::MoveTo(points[0].fX, points[0].fY,
                               &content.entry()->fContent);
            for (size_t i = 1; i < count; i++) {
                SkPDFUtils::AppendLine(points[i].fX, points[i].fY,
                                       &content.entry()->fContent);
            }
            SkPDFUtils::StrokePath(&content.entry()->fContent);
            break;
        case SkCanvas::kLines_PointMode:
            for (size_t i = 0; i < count/2; i++) {
                SkPDFUtils::MoveTo(points[i * 2].fX, points[i * 2].fY,
                                   &content.entry()->fContent);
                SkPDFUtils::AppendLine(points[i * 2 + 1].fX,
                                       points[i * 2 + 1].fY,
                                       &content.entry()->fContent);
                SkPDFUtils::StrokePath(&content.entry()->fContent);
            }
            break;
        case SkCanvas::kPoints_PointMode:
            SkASSERT(paint->getStrokeCap() == SkPaint::kRound_Cap);
            for (size_t i = 0; i < count; i++) {
                SkPDFUtils::MoveTo(points[i].fX, points[i].fY,
                                   &content.entry()->fContent);
                SkPDFUtils::ClosePath(&content.entry()->fContent);
                SkPDFUtils::StrokePath(&content.entry()->fContent);
            }
            break;
        default:
            SkASSERT(false);
    }
}

void SkPDFDevice::drawRect(const SkDraw& d,
                           const SkRect& rect,
                           const SkPaint& srcPaint) {
>>>>>>> miniblink49
    SkPaint paint = srcPaint;
    replace_srcmode_on_opaque_paint(&paint);
    SkRect r = rect;
    r.sort();

    if (paint.getPathEffect()) {
<<<<<<< HEAD
        if (d.fRC->isEmpty()) {
=======
        if (d.fClip->isEmpty()) {
>>>>>>> miniblink49
            return;
        }
        SkPath path;
        path.addRect(r);
<<<<<<< HEAD
        drawPath(d, path, paint, nullptr, true);
=======
        drawPath(d, path, paint, NULL, true);
        return;
    }

    if (handleRectAnnotation(r, *d.fMatrix, paint)) {
>>>>>>> miniblink49
        return;
    }

    ScopedContentEntry content(this, d, paint);
    if (!content.entry()) {
        return;
    }
    SkPDFUtils::AppendRectangle(r, &content.entry()->fContent);
    SkPDFUtils::PaintPath(paint.getStyle(), SkPath::kWinding_FillType,
<<<<<<< HEAD
        &content.entry()->fContent);
}

void SkPDFDevice::drawRRect(const SkDraw& draw,
    const SkRRect& rrect,
    const SkPaint& srcPaint)
{
    SkPaint paint = srcPaint;
    replace_srcmode_on_opaque_paint(&paint);
    SkPath path;
    path.addRRect(rrect);
    this->drawPath(draw, path, paint, nullptr, true);
}

void SkPDFDevice::drawOval(const SkDraw& draw,
    const SkRect& oval,
    const SkPaint& srcPaint)
{
    SkPaint paint = srcPaint;
    replace_srcmode_on_opaque_paint(&paint);
    SkPath path;
    path.addOval(oval);
    this->drawPath(draw, path, paint, nullptr, true);
}

void SkPDFDevice::drawPath(const SkDraw& d,
    const SkPath& origPath,
    const SkPaint& srcPaint,
    const SkMatrix* prePathMatrix,
    bool pathIsMutable)
{
=======
                          &content.entry()->fContent);
}

void SkPDFDevice::drawRRect(const SkDraw& draw,
                            const SkRRect& rrect,
                            const SkPaint& srcPaint) {
    SkPaint paint = srcPaint;
    replace_srcmode_on_opaque_paint(&paint);
    SkPath  path;
    path.addRRect(rrect);
    this->drawPath(draw, path, paint, NULL, true);
}

void SkPDFDevice::drawOval(const SkDraw& draw,
                           const SkRect& oval,
                           const SkPaint& srcPaint) {
    SkPaint paint = srcPaint;
    replace_srcmode_on_opaque_paint(&paint);
    SkPath  path;
    path.addOval(oval);
    this->drawPath(draw, path, paint, NULL, true);
}

void SkPDFDevice::drawPath(const SkDraw& d,
                           const SkPath& origPath,
                           const SkPaint& srcPaint,
                           const SkMatrix* prePathMatrix,
                           bool pathIsMutable) {
>>>>>>> miniblink49
    SkPaint paint = srcPaint;
    replace_srcmode_on_opaque_paint(&paint);
    SkPath modifiedPath;
    SkPath* pathPtr = const_cast<SkPath*>(&origPath);

    SkMatrix matrix = *d.fMatrix;
    if (prePathMatrix) {
        if (paint.getPathEffect() || paint.getStyle() != SkPaint::kFill_Style) {
            if (!pathIsMutable) {
                pathPtr = &modifiedPath;
                pathIsMutable = true;
            }
            origPath.transform(*prePathMatrix, pathPtr);
        } else {
            matrix.preConcat(*prePathMatrix);
        }
    }

    if (paint.getPathEffect()) {
<<<<<<< HEAD
        if (d.fRC->isEmpty()) {
=======
        if (d.fClip->isEmpty()) {
>>>>>>> miniblink49
            return;
        }
        if (!pathIsMutable) {
            pathPtr = &modifiedPath;
            pathIsMutable = true;
        }
        bool fill = paint.getFillPath(origPath, pathPtr);

        SkPaint noEffectPaint(paint);
<<<<<<< HEAD
        noEffectPaint.setPathEffect(nullptr);
=======
        noEffectPaint.setPathEffect(NULL);
>>>>>>> miniblink49
        if (fill) {
            noEffectPaint.setStyle(SkPaint::kFill_Style);
        } else {
            noEffectPaint.setStyle(SkPaint::kStroke_Style);
            noEffectPaint.setStrokeWidth(0);
        }
<<<<<<< HEAD
        drawPath(d, *pathPtr, noEffectPaint, nullptr, true);
=======
        drawPath(d, *pathPtr, noEffectPaint, NULL, true);
>>>>>>> miniblink49
        return;
    }

    if (handleInversePath(d, origPath, paint, pathIsMutable, prePathMatrix)) {
        return;
    }

<<<<<<< HEAD
    ScopedContentEntry content(this, d.fClipStack, d.fRC->bwRgn(), matrix, paint);
    if (!content.entry()) {
        return;
    }
    bool consumeDegeratePathSegments = paint.getStyle() == SkPaint::kFill_Style || (paint.getStrokeCap() != SkPaint::kRound_Cap && paint.getStrokeCap() != SkPaint::kSquare_Cap);
    SkPDFUtils::EmitPath(*pathPtr, paint.getStyle(),
        consumeDegeratePathSegments,
        &content.entry()->fContent);
    SkPDFUtils::PaintPath(paint.getStyle(), pathPtr->getFillType(),
        &content.entry()->fContent);
}

void SkPDFDevice::drawBitmapRect(const SkDraw& draw,
    const SkBitmap& bitmap,
    const SkRect* src,
    const SkRect& dst,
    const SkPaint& srcPaint,
    SkCanvas::SrcRectConstraint constraint)
{
    SkASSERT(false);
}

void SkPDFDevice::drawBitmap(const SkDraw& d,
    const SkBitmap& bitmap,
    const SkMatrix& matrix,
    const SkPaint& srcPaint)
{
=======
    if (handleRectAnnotation(pathPtr->getBounds(), matrix, paint)) {
        return;
    }

    ScopedContentEntry content(this, d.fClipStack, *d.fClip, matrix, paint);
    if (!content.entry()) {
        return;
    }
    SkPDFUtils::EmitPath(*pathPtr, paint.getStyle(),
                         &content.entry()->fContent);
    SkPDFUtils::PaintPath(paint.getStyle(), pathPtr->getFillType(),
                          &content.entry()->fContent);
}

void SkPDFDevice::drawBitmapRect(const SkDraw& draw, const SkBitmap& bitmap,
                                 const SkRect* src, const SkRect& dst,
                                 const SkPaint& srcPaint,
                                 SkCanvas::DrawBitmapRectFlags flags) {
>>>>>>> miniblink49
    SkPaint paint = srcPaint;
    if (bitmap.isOpaque()) {
        replace_srcmode_on_opaque_paint(&paint);
    }

<<<<<<< HEAD
    if (d.fRC->isEmpty()) {
=======
    // TODO: this code path must be updated to respect the flags parameter
    SkMatrix    matrix;
    SkRect      bitmapBounds, tmpSrc, tmpDst;
    SkBitmap    tmpBitmap;

    bitmapBounds.isetWH(bitmap.width(), bitmap.height());

    // Compute matrix from the two rectangles
    if (src) {
        tmpSrc = *src;
    } else {
        tmpSrc = bitmapBounds;
    }
    matrix.setRectToRect(tmpSrc, dst, SkMatrix::kFill_ScaleToFit);

    const SkBitmap* bitmapPtr = &bitmap;

    // clip the tmpSrc to the bounds of the bitmap, and recompute dstRect if
    // needed (if the src was clipped). No check needed if src==null.
    if (src) {
        if (!bitmapBounds.contains(*src)) {
            if (!tmpSrc.intersect(bitmapBounds)) {
                return; // nothing to draw
            }
            // recompute dst, based on the smaller tmpSrc
            matrix.mapRect(&tmpDst, tmpSrc);
        }

        // since we may need to clamp to the borders of the src rect within
        // the bitmap, we extract a subset.
        // TODO: make sure this is handled in drawBitmap and remove from here.
        SkIRect srcIR;
        tmpSrc.roundOut(&srcIR);
        if (!bitmap.extractSubset(&tmpBitmap, srcIR)) {
            return;
        }
        bitmapPtr = &tmpBitmap;

        // Since we did an extract, we need to adjust the matrix accordingly
        SkScalar dx = 0, dy = 0;
        if (srcIR.fLeft > 0) {
            dx = SkIntToScalar(srcIR.fLeft);
        }
        if (srcIR.fTop > 0) {
            dy = SkIntToScalar(srcIR.fTop);
        }
        if (dx || dy) {
            matrix.preTranslate(dx, dy);
        }
    }
    this->drawBitmap(draw, *bitmapPtr, matrix, paint);
}

void SkPDFDevice::drawBitmap(const SkDraw& d, const SkBitmap& bitmap,
                             const SkMatrix& matrix, const SkPaint& srcPaint) {
    SkPaint paint = srcPaint;
    if (bitmap.isOpaque()) {
        replace_srcmode_on_opaque_paint(&paint);
    }

    if (d.fClip->isEmpty()) {
>>>>>>> miniblink49
        return;
    }

    SkMatrix transform = matrix;
    transform.postConcat(*d.fMatrix);
<<<<<<< HEAD
    SkImageBitmap imageBitmap(bitmap);
    this->internalDrawImage(
        transform, d.fClipStack, d.fRC->bwRgn(), imageBitmap, paint);
}

void SkPDFDevice::drawSprite(const SkDraw& d,
    const SkBitmap& bitmap,
    int x,
    int y,
    const SkPaint& srcPaint)
{
=======
    this->internalDrawBitmap(transform, d.fClipStack, *d.fClip, bitmap, NULL,
                             paint);
}

void SkPDFDevice::drawSprite(const SkDraw& d, const SkBitmap& bitmap,
                             int x, int y, const SkPaint& srcPaint) {
>>>>>>> miniblink49
    SkPaint paint = srcPaint;
    if (bitmap.isOpaque()) {
        replace_srcmode_on_opaque_paint(&paint);
    }

<<<<<<< HEAD
    if (d.fRC->isEmpty()) {
=======
    if (d.fClip->isEmpty()) {
>>>>>>> miniblink49
        return;
    }

    SkMatrix matrix;
    matrix.setTranslate(SkIntToScalar(x), SkIntToScalar(y));
<<<<<<< HEAD
    SkImageBitmap imageBitmap(bitmap);
    this->internalDrawImage(
        matrix, d.fClipStack, d.fRC->bwRgn(), imageBitmap, paint);
}

void SkPDFDevice::drawImage(const SkDraw& draw,
    const SkImage* image,
    SkScalar x,
    SkScalar y,
    const SkPaint& srcPaint)
{
    SkPaint paint = srcPaint;
    if (!image) {
        return;
    }
    if (image->isOpaque()) {
        replace_srcmode_on_opaque_paint(&paint);
    }
    if (draw.fRC->isEmpty()) {
        return;
    }
    SkMatrix transform = SkMatrix::MakeTrans(x, y);
    transform.postConcat(*draw.fMatrix);
    SkImageBitmap imageBitmap(const_cast<SkImage*>(image));
    this->internalDrawImage(
        transform, draw.fClipStack, draw.fRC->bwRgn(), imageBitmap, paint);
}

void SkPDFDevice::drawImageRect(const SkDraw& draw,
    const SkImage* image,
    const SkRect* src,
    const SkRect& dst,
    const SkPaint& srcPaint,
    SkCanvas::SrcRectConstraint constraint)
{
    SkASSERT(false);
=======
    this->internalDrawBitmap(matrix, d.fClipStack, *d.fClip, bitmap, NULL,
                             paint);
>>>>>>> miniblink49
}

//  Create a PDF string. Maximum length (in bytes) is 65,535.
//  @param input     A string value.
//  @param len       The length of the input array.
//  @param wideChars True iff the upper byte in each uint16_t is
//                   significant and should be encoded and not
//                   discarded.  If true, the upper byte is encoded
//                   first.  Otherwise, we assert the upper byte is
//                   zero.
<<<<<<< HEAD
static void write_wide_string(SkDynamicMemoryWStream* wStream,
    const uint16_t* input,
    size_t len,
    bool wideChars)
{
    if (wideChars) {
        SkASSERT(2 * len < 65535);
        static const char gHex[] = "0123456789ABCDEF";
        wStream->writeText("<");
        for (size_t i = 0; i < len; i++) {
            char result[4]; // Big-endian
            result[0] = gHex[(input[i] >> 12) & 0xF];
            result[1] = gHex[(input[i] >> 8) & 0xF];
            result[2] = gHex[(input[i] >> 4) & 0xF];
            result[3] = gHex[(input[i]) & 0xF];
            wStream->write(result, 4);
        }
        wStream->writeText(">");
    } else {
        SkASSERT(len <= 65535);
        SkAutoMalloc buffer(len); // Remove every other byte.
        uint8_t* ptr = (uint8_t*)buffer.get();
        for (size_t i = 0; i < len; i++) {
            SkASSERT(0 == input[i] >> 8);
            ptr[i] = static_cast<uint8_t>(input[i]);
        }
        SkPDFUtils::WriteString(wStream, (char*)buffer.get(), len);
    }
}

static void draw_transparent_text(SkPDFDevice* device,
    const SkDraw& d,
    const void* text, size_t len,
    SkScalar x, SkScalar y,
    const SkPaint& srcPaint)
{

    SkPaint transparent;
    if (!SkPDFFont::CanEmbedTypeface(transparent.getTypeface(),
            device->getCanon())) {
        SkDEBUGFAIL("default typeface should be embeddable");
        return; // Avoid infinite loop in release.
    }
    transparent.setTextSize(srcPaint.getTextSize());
    transparent.setColor(SK_ColorTRANSPARENT);
    switch (srcPaint.getTextEncoding()) {
    case SkPaint::kGlyphID_TextEncoding: {
        // Since a glyphId<->Unicode mapping is typeface-specific,
        // map back to Unicode first.
        size_t glyphCount = len / 2;
        SkAutoTMalloc<SkUnichar> unichars(glyphCount);
        srcPaint.glyphsToUnichars(
            (const uint16_t*)text, SkToInt(glyphCount), &unichars[0]);
        transparent.setTextEncoding(SkPaint::kUTF32_TextEncoding);
        device->drawText(d, &unichars[0],
            glyphCount * sizeof(SkUnichar),
            x, y, transparent);
        break;
    }
    case SkPaint::kUTF8_TextEncoding:
    case SkPaint::kUTF16_TextEncoding:
    case SkPaint::kUTF32_TextEncoding:
        transparent.setTextEncoding(srcPaint.getTextEncoding());
        device->drawText(d, text, len, x, y, transparent);
        break;
    default:
        SkFAIL("unknown text encoding");
=======
static SkString format_wide_string(const uint16_t* input,
                                   size_t len,
                                   bool wideChars) {
    if (wideChars) {
        SkASSERT(2 * len < 65535);
        static const char gHex[] = "0123456789ABCDEF";
        SkString result(4 * len + 2);
        result[0] = '<';
        for (size_t i = 0; i < len; i++) {
            result[4 * i + 1] = gHex[(input[i] >> 12) & 0xF];
            result[4 * i + 2] = gHex[(input[i] >>  8) & 0xF];
            result[4 * i + 3] = gHex[(input[i] >>  4) & 0xF];
            result[4 * i + 4] = gHex[(input[i]      ) & 0xF];
        }
        result[4 * len + 1] = '>';
        return result;
    } else {
        SkASSERT(len <= 65535);
        SkString tmp(len);
        for (size_t i = 0; i < len; i++) {
            SkASSERT(0 == input[i] >> 8);
            tmp[i] = static_cast<uint8_t>(input[i]);
        }
        return SkPDFUtils::FormatString(tmp.c_str(), tmp.size());
>>>>>>> miniblink49
    }
}

void SkPDFDevice::drawText(const SkDraw& d, const void* text, size_t len,
<<<<<<< HEAD
    SkScalar x, SkScalar y, const SkPaint& srcPaint)
{
    if (!SkPDFFont::CanEmbedTypeface(srcPaint.getTypeface(), fDocument->canon())) {
        // https://bug.skia.org/3866
        SkPath path;
        srcPaint.getTextPath(text, len, x, y, &path);
        this->drawPath(d, path, srcPaint, &SkMatrix::I(), true);
        // Draw text transparently to make it copyable/searchable/accessable.
        draw_transparent_text(this, d, text, len, x, y, srcPaint);
        return;
    }
    SkPaint paint = srcPaint;
    replace_srcmode_on_opaque_paint(&paint);

    NOT_IMPLEMENTED(paint.getMaskFilter() != nullptr, false);
    if (paint.getMaskFilter() != nullptr) {
=======
                           SkScalar x, SkScalar y, const SkPaint& srcPaint) {
    SkPaint paint = srcPaint;
    replace_srcmode_on_opaque_paint(&paint);

    NOT_IMPLEMENTED(paint.getMaskFilter() != NULL, false);
    if (paint.getMaskFilter() != NULL) {
>>>>>>> miniblink49
        // Don't pretend we support drawing MaskFilters, it makes for artifacts
        // making text unreadable (e.g. same text twice when using CSS shadows).
        return;
    }
    SkPaint textPaint = calculate_text_paint(paint);
    ScopedContentEntry content(this, d, textPaint, true);
    if (!content.entry()) {
        return;
    }

    SkGlyphStorage storage(0);
<<<<<<< HEAD
    const uint16_t* glyphIDs = nullptr;
    int numGlyphs = force_glyph_encoding(paint, text, len, &storage, &glyphIDs);
    textPaint.setTextEncoding(SkPaint::kGlyphID_TextEncoding);

    SkPaint::GlyphCacheProc glyphCacheProc = textPaint.getGlyphCacheProc(true);
    align_text(glyphCacheProc, textPaint, glyphIDs, numGlyphs, &x, &y);
    content.entry()->fContent.writeText("BT\n");
    set_text_transform(x, y, textPaint.getTextSkewX(),
        &content.entry()->fContent);
=======
    const uint16_t* glyphIDs = NULL;
    int numGlyphs = force_glyph_encoding(paint, text, len, &storage, &glyphIDs);
    textPaint.setTextEncoding(SkPaint::kGlyphID_TextEncoding);

    SkDrawCacheProc glyphCacheProc = textPaint.getDrawCacheProc();
    align_text(glyphCacheProc, textPaint, glyphIDs, numGlyphs, &x, &y);
    content.entry()->fContent.writeText("BT\n");
    set_text_transform(x, y, textPaint.getTextSkewX(),
                       &content.entry()->fContent);
>>>>>>> miniblink49
    int consumedGlyphCount = 0;

    SkTDArray<uint16_t> glyphIDsCopy(glyphIDs, numGlyphs);

    while (numGlyphs > consumedGlyphCount) {
        this->updateFont(textPaint, glyphIDs[consumedGlyphCount], content.entry());
        SkPDFFont* font = content.entry()->fState.fFont;

        int availableGlyphs = font->glyphsToPDFFontEncoding(
<<<<<<< HEAD
            glyphIDsCopy.begin() + consumedGlyphCount,
            numGlyphs - consumedGlyphCount);
        fFontGlyphUsage->noteGlyphUsage(
            font, glyphIDsCopy.begin() + consumedGlyphCount,
            availableGlyphs);
        write_wide_string(&content.entry()->fContent,
            glyphIDsCopy.begin() + consumedGlyphCount,
            availableGlyphs, font->multiByteGlyphs());
=======
                glyphIDsCopy.begin() + consumedGlyphCount,
                numGlyphs - consumedGlyphCount);
        fFontGlyphUsage->noteGlyphUsage(
                font,  glyphIDsCopy.begin() + consumedGlyphCount,
                availableGlyphs);
        SkString encodedString =
                format_wide_string(glyphIDsCopy.begin() + consumedGlyphCount,
                                   availableGlyphs, font->multiByteGlyphs());
        content.entry()->fContent.writeText(encodedString.c_str());
>>>>>>> miniblink49
        consumedGlyphCount += availableGlyphs;
        content.entry()->fContent.writeText(" Tj\n");
    }
    content.entry()->fContent.writeText("ET\n");
}

void SkPDFDevice::drawPosText(const SkDraw& d, const void* text, size_t len,
<<<<<<< HEAD
    const SkScalar pos[], int scalarsPerPos,
    const SkPoint& offset, const SkPaint& srcPaint)
{
    if (!SkPDFFont::CanEmbedTypeface(srcPaint.getTypeface(), fDocument->canon())) {
        const SkPoint* positions = reinterpret_cast<const SkPoint*>(pos);
        SkAutoTMalloc<SkPoint> positionsBuffer;
        if (2 != scalarsPerPos) {
            int glyphCount = srcPaint.textToGlyphs(text, len, NULL);
            positionsBuffer.reset(glyphCount);
            for (int i = 0; i < glyphCount; ++i) {
                positionsBuffer[i].set(pos[i], 0.0f);
            }
            positions = &positionsBuffer[0];
        }
        SkPath path;
        srcPaint.getPosTextPath(text, len, positions, &path);
        SkMatrix matrix;
        matrix.setTranslate(offset);
        this->drawPath(d, path, srcPaint, &matrix, true);
        // Draw text transparently to make it copyable/searchable/accessable.
        draw_transparent_text(
            this, d, text, len, offset.x() + positions[0].x(),
            offset.y() + positions[0].y(), srcPaint);
        return;
    }

    SkPaint paint = srcPaint;
    replace_srcmode_on_opaque_paint(&paint);

    NOT_IMPLEMENTED(paint.getMaskFilter() != nullptr, false);
    if (paint.getMaskFilter() != nullptr) {
=======
                              const SkScalar pos[], int scalarsPerPos,
                              const SkPoint& offset, const SkPaint& srcPaint) {
    SkPaint paint = srcPaint;
    replace_srcmode_on_opaque_paint(&paint);

    NOT_IMPLEMENTED(paint.getMaskFilter() != NULL, false);
    if (paint.getMaskFilter() != NULL) {
>>>>>>> miniblink49
        // Don't pretend we support drawing MaskFilters, it makes for artifacts
        // making text unreadable (e.g. same text twice when using CSS shadows).
        return;
    }
    SkASSERT(1 == scalarsPerPos || 2 == scalarsPerPos);
    SkPaint textPaint = calculate_text_paint(paint);
    ScopedContentEntry content(this, d, textPaint, true);
    if (!content.entry()) {
        return;
    }

    SkGlyphStorage storage(0);
<<<<<<< HEAD
    const uint16_t* glyphIDs = nullptr;
    size_t numGlyphs = force_glyph_encoding(paint, text, len, &storage, &glyphIDs);
    textPaint.setTextEncoding(SkPaint::kGlyphID_TextEncoding);

    SkPaint::GlyphCacheProc glyphCacheProc = textPaint.getGlyphCacheProc(true);
=======
    const uint16_t* glyphIDs = NULL;
    size_t numGlyphs = force_glyph_encoding(paint, text, len, &storage, &glyphIDs);
    textPaint.setTextEncoding(SkPaint::kGlyphID_TextEncoding);

    SkDrawCacheProc glyphCacheProc = textPaint.getDrawCacheProc();
>>>>>>> miniblink49
    content.entry()->fContent.writeText("BT\n");
    this->updateFont(textPaint, glyphIDs[0], content.entry());
    for (size_t i = 0; i < numGlyphs; i++) {
        SkPDFFont* font = content.entry()->fState.fFont;
        uint16_t encodedValue = glyphIDs[i];
        if (font->glyphsToPDFFontEncoding(&encodedValue, 1) != 1) {
            // The current pdf font cannot encode the current glyph.
            // Try to get a pdf font which can encode the current glyph.
            this->updateFont(textPaint, glyphIDs[i], content.entry());
            font = content.entry()->fState.fFont;
            if (font->glyphsToPDFFontEncoding(&encodedValue, 1) != 1) {
                SkDEBUGFAIL("PDF could not encode glyph.");
                continue;
            }
        }

        fFontGlyphUsage->noteGlyphUsage(font, &encodedValue, 1);
        SkScalar x = offset.x() + pos[i * scalarsPerPos];
        SkScalar y = offset.y() + (2 == scalarsPerPos ? pos[i * scalarsPerPos + 1] : 0);

        align_text(glyphCacheProc, textPaint, glyphIDs + i, 1, &x, &y);
        set_text_transform(x, y, textPaint.getTextSkewX(), &content.entry()->fContent);
<<<<<<< HEAD
        write_wide_string(&content.entry()->fContent, &encodedValue, 1,
            font->multiByteGlyphs());
=======
        SkString encodedString =
                format_wide_string(&encodedValue, 1, font->multiByteGlyphs());
        content.entry()->fContent.writeText(encodedString.c_str());
>>>>>>> miniblink49
        content.entry()->fContent.writeText(" Tj\n");
    }
    content.entry()->fContent.writeText("ET\n");
}

void SkPDFDevice::drawVertices(const SkDraw& d, SkCanvas::VertexMode,
<<<<<<< HEAD
    int vertexCount, const SkPoint verts[],
    const SkPoint texs[], const SkColor colors[],
    SkXfermode* xmode, const uint16_t indices[],
    int indexCount, const SkPaint& paint)
{
    if (d.fRC->isEmpty()) {
=======
                               int vertexCount, const SkPoint verts[],
                               const SkPoint texs[], const SkColor colors[],
                               SkXfermode* xmode, const uint16_t indices[],
                               int indexCount, const SkPaint& paint) {
    if (d.fClip->isEmpty()) {
>>>>>>> miniblink49
        return;
    }
    // TODO: implement drawVertices
}

void SkPDFDevice::drawDevice(const SkDraw& d, SkBaseDevice* device,
<<<<<<< HEAD
    int x, int y, const SkPaint& paint)
{
    // our onCreateCompatibleDevice() always creates SkPDFDevice subclasses.
    SkPDFDevice* pdfDevice = static_cast<SkPDFDevice*>(device);

    SkScalar scalarX = SkIntToScalar(x);
    SkScalar scalarY = SkIntToScalar(y);
    for (const RectWithData& l : pdfDevice->fLinkToURLs) {
        SkRect r = l.rect.makeOffset(scalarX, scalarY);
        fLinkToURLs.emplace_back(r, l.data.get());
    }
    for (const RectWithData& l : pdfDevice->fLinkToDestinations) {
        SkRect r = l.rect.makeOffset(scalarX, scalarY);
        fLinkToDestinations.emplace_back(r, l.data.get());
    }
    for (const NamedDestination& d : pdfDevice->fNamedDestinations) {
        SkPoint p = d.point + SkPoint::Make(scalarX, scalarY);
        fNamedDestinations.emplace_back(d.nameData.get(), p);
    }

=======
                             int x, int y, const SkPaint& paint) {
    // our onCreateCompatibleDevice() always creates SkPDFDevice subclasses.
    SkPDFDevice* pdfDevice = static_cast<SkPDFDevice*>(device);
>>>>>>> miniblink49
    if (pdfDevice->isContentEmpty()) {
        return;
    }

    SkMatrix matrix;
    matrix.setTranslate(SkIntToScalar(x), SkIntToScalar(y));
<<<<<<< HEAD
    ScopedContentEntry content(this, d.fClipStack, d.fRC->bwRgn(), matrix, paint);
=======
    ScopedContentEntry content(this, d.fClipStack, *d.fClip, matrix, paint);
>>>>>>> miniblink49
    if (!content.entry()) {
        return;
    }
    if (content.needShape()) {
        SkPath shape;
        shape.addRect(SkRect::MakeXYWH(SkIntToScalar(x), SkIntToScalar(y),
<<<<<<< HEAD
            SkIntToScalar(device->width()),
            SkIntToScalar(device->height())));
=======
                                       SkIntToScalar(device->width()),
                                       SkIntToScalar(device->height())));
>>>>>>> miniblink49
        content.setShape(shape);
    }
    if (!content.needSource()) {
        return;
    }

<<<<<<< HEAD
    auto xObject = sk_make_sp<SkPDFFormXObject>(pdfDevice);
    SkPDFUtils::DrawFormXObject(this->addXObjectResource(xObject.get()),
        &content.entry()->fContent);
=======
    SkAutoTUnref<SkPDFFormXObject> xObject(new SkPDFFormXObject(pdfDevice));
    SkPDFUtils::DrawFormXObject(this->addXObjectResource(xObject.get()),
                                &content.entry()->fContent);
>>>>>>> miniblink49

    // Merge glyph sets from the drawn device.
    fFontGlyphUsage->merge(pdfDevice->getFontGlyphUsage());
}

<<<<<<< HEAD
SkImageInfo SkPDFDevice::imageInfo() const
{
    return fLegacyBitmap.info();
}

void SkPDFDevice::onAttachToCanvas(SkCanvas* canvas)
{
=======
SkImageInfo SkPDFDevice::imageInfo() const {
    return fLegacyBitmap.info();
}

void SkPDFDevice::onAttachToCanvas(SkCanvas* canvas) {
>>>>>>> miniblink49
    INHERITED::onAttachToCanvas(canvas);

    // Canvas promises that this ptr is valid until onDetachFromCanvas is called
    fClipStack = canvas->getClipStack();
}

<<<<<<< HEAD
void SkPDFDevice::onDetachFromCanvas()
{
    INHERITED::onDetachFromCanvas();

    fClipStack = nullptr;
}

sk_sp<SkSurface> SkPDFDevice::makeSurface(const SkImageInfo& info, const SkSurfaceProps& props)
{
    return SkSurface::MakeRaster(info, &props);
}

sk_sp<SkPDFDict> SkPDFDevice::makeResourceDict() const
{
=======
void SkPDFDevice::onDetachFromCanvas() {
    INHERITED::onDetachFromCanvas();

    fClipStack = NULL;
}

SkSurface* SkPDFDevice::newSurface(const SkImageInfo& info, const SkSurfaceProps& props) {
    return SkSurface::NewRaster(info, &props);
}

ContentEntry* SkPDFDevice::getLastContentEntry() {
    if (fDrawingArea == kContent_DrawingArea) {
        return fLastContentEntry;
    } else {
        return fLastMarginContentEntry;
    }
}

SkAutoTDelete<ContentEntry>* SkPDFDevice::getContentEntries() {
    if (fDrawingArea == kContent_DrawingArea) {
        return &fContentEntries;
    } else {
        return &fMarginContentEntries;
    }
}

void SkPDFDevice::setLastContentEntry(ContentEntry* contentEntry) {
    if (fDrawingArea == kContent_DrawingArea) {
        fLastContentEntry = contentEntry;
    } else {
        fLastMarginContentEntry = contentEntry;
    }
}

void SkPDFDevice::setDrawingArea(DrawingArea drawingArea) {
    // A ScopedContentEntry only exists during the course of a draw call, so
    // this can't be called while a ScopedContentEntry exists.
    fDrawingArea = drawingArea;
}

SkPDFDict* SkPDFDevice::createResourceDict() const {
>>>>>>> miniblink49
    SkTDArray<SkPDFObject*> fonts;
    fonts.setReserve(fFontResources.count());
    for (SkPDFFont* font : fFontResources) {
        fonts.push(font);
    }
<<<<<<< HEAD
    return SkPDFResourceDict::Make(
        &fGraphicStateResources,
        &fShaderResources,
        &fXObjectResources,
        &fonts);
}

const SkTDArray<SkPDFFont*>& SkPDFDevice::getFontResources() const
{
    return fFontResources;
}

sk_sp<SkPDFArray> SkPDFDevice::copyMediaBox() const
{
    auto mediaBox = sk_make_sp<SkPDFArray>();
    mediaBox->reserve(4);
    mediaBox->appendInt(0);
    mediaBox->appendInt(0);
    mediaBox->appendInt(fPageSize.width());
    mediaBox->appendInt(fPageSize.height());
    return mediaBox;
}

std::unique_ptr<SkStreamAsset> SkPDFDevice::content() const
{
    SkDynamicMemoryWStream buffer;
    this->writeContent(&buffer);
    return std::unique_ptr<SkStreamAsset>(
        buffer.bytesWritten() > 0
            ? buffer.detachAsStream()
            : new SkMemoryStream);
}

void SkPDFDevice::writeContent(SkWStream* out) const
{
=======
    return SkPDFResourceDict::Create(
            &fGraphicStateResources,
            &fShaderResources,
            &fXObjectResources,
            &fonts);
}

const SkTDArray<SkPDFFont*>& SkPDFDevice::getFontResources() const {
    return fFontResources;
}

SkPDFArray* SkPDFDevice::copyMediaBox() const {
    // should this be a singleton?

    SkAutoTUnref<SkPDFArray> mediaBox(SkNEW(SkPDFArray));
    mediaBox->reserve(4);
    mediaBox->appendInt(0);
    mediaBox->appendInt(0);
    mediaBox->appendInt(fPageSize.fWidth);
    mediaBox->appendInt(fPageSize.fHeight);
    return mediaBox.detach();
}

SkStreamAsset* SkPDFDevice::content() const {
    SkDynamicMemoryWStream buffer;
    this->writeContent(&buffer);
    return buffer.detachAsStream();
}

void SkPDFDevice::copyContentEntriesToData(ContentEntry* entry,
        SkWStream* data) const {
    // TODO(ctguil): For margins, I'm not sure fExistingClipStack/Region is the
    // right thing to pass here.
    GraphicStackState gsState(fExistingClipStack, fExistingClipRegion, data);
    while (entry != NULL) {
        SkPoint translation;
        translation.iset(this->getOrigin());
        translation.negate();
        gsState.updateClip(entry->fState.fClipStack, entry->fState.fClipRegion,
                           translation);
        gsState.updateMatrix(entry->fState.fMatrix);
        gsState.updateDrawingState(entry->fState);

        entry->fContent.writeToStream(data);
        entry = entry->fNext.get();
    }
    gsState.drainStack();
}

void SkPDFDevice::writeContent(SkWStream* out) const {
>>>>>>> miniblink49
    if (fInitialTransform.getType() != SkMatrix::kIdentity_Mask) {
        SkPDFUtils::AppendTransform(fInitialTransform, out);
    }

<<<<<<< HEAD
=======
    // TODO(aayushkumar): Apply clip along the margins.  Currently, webkit
    // colors the contentArea white before it starts drawing into it and
    // that currently acts as our clip.
    // Also, think about adding a transform here (or assume that the values
    // sent across account for that)
    SkPDFDevice::copyContentEntriesToData(fMarginContentEntries.get(), out);

>>>>>>> miniblink49
    // If the content area is the entire page, then we don't need to clip
    // the content area (PDF area clips to the page size).  Otherwise,
    // we have to clip to the content area; we've already applied the
    // initial transform, so just clip to the device size.
    if (fPageSize != fContentSize) {
        SkRect r = SkRect::MakeWH(SkIntToScalar(this->width()),
<<<<<<< HEAD
            SkIntToScalar(this->height()));
        emit_clip(nullptr, &r, out);
    }

    GraphicStackState gsState(fExistingClipStack, fExistingClipRegion, out);
    for (const auto& entry : fContentEntries) {
        SkPoint translation;
        translation.iset(this->getOrigin());
        translation.negate();
        gsState.updateClip(entry.fState.fClipStack, entry.fState.fClipRegion,
            translation);
        gsState.updateMatrix(entry.fState.fMatrix);
        gsState.updateDrawingState(entry.fState);

        entry.fContent.writeToStream(out);
    }
    gsState.drainStack();
=======
                                  SkIntToScalar(this->height()));
        emit_clip(NULL, &r, out);
    }

    SkPDFDevice::copyContentEntriesToData(fContentEntries.get(), out);
>>>>>>> miniblink49
}

/* Draws an inverse filled path by using Path Ops to compute the positive
 * inverse using the current clip as the inverse bounds.
 * Return true if this was an inverse path and was properly handled,
 * otherwise returns false and the normal drawing routine should continue,
 * either as a (incorrect) fallback or because the path was not inverse
 * in the first place.
 */
bool SkPDFDevice::handleInversePath(const SkDraw& d, const SkPath& origPath,
<<<<<<< HEAD
    const SkPaint& paint, bool pathIsMutable,
    const SkMatrix* prePathMatrix)
{
=======
                                    const SkPaint& paint, bool pathIsMutable,
                                    const SkMatrix* prePathMatrix) {
>>>>>>> miniblink49
    if (!origPath.isInverseFillType()) {
        return false;
    }

<<<<<<< HEAD
    if (d.fRC->isEmpty()) {
=======
    if (d.fClip->isEmpty()) {
>>>>>>> miniblink49
        return false;
    }

    SkPath modifiedPath;
    SkPath* pathPtr = const_cast<SkPath*>(&origPath);
    SkPaint noInversePaint(paint);

    // Merge stroking operations into final path.
<<<<<<< HEAD
    if (SkPaint::kStroke_Style == paint.getStyle() || SkPaint::kStrokeAndFill_Style == paint.getStyle()) {
=======
    if (SkPaint::kStroke_Style == paint.getStyle() ||
        SkPaint::kStrokeAndFill_Style == paint.getStyle()) {
>>>>>>> miniblink49
        bool doFillPath = paint.getFillPath(origPath, &modifiedPath);
        if (doFillPath) {
            noInversePaint.setStyle(SkPaint::kFill_Style);
            noInversePaint.setStrokeWidth(0);
            pathPtr = &modifiedPath;
        } else {
            // To be consistent with the raster output, hairline strokes
            // are rendered as non-inverted.
            modifiedPath.toggleInverseFillType();
<<<<<<< HEAD
            drawPath(d, modifiedPath, paint, nullptr, true);
=======
            drawPath(d, modifiedPath, paint, NULL, true);
>>>>>>> miniblink49
            return true;
        }
    }

    // Get bounds of clip in current transform space
    // (clip bounds are given in device space).
    SkRect bounds;
    SkMatrix transformInverse;
    SkMatrix totalMatrix = *d.fMatrix;
    if (prePathMatrix) {
        totalMatrix.preConcat(*prePathMatrix);
    }
    if (!totalMatrix.invert(&transformInverse)) {
        return false;
    }
<<<<<<< HEAD
    bounds.set(d.fRC->getBounds());
=======
    bounds.set(d.fClip->getBounds());
>>>>>>> miniblink49
    transformInverse.mapRect(&bounds);

    // Extend the bounds by the line width (plus some padding)
    // so the edge doesn't cause a visible stroke.
    bounds.outset(paint.getStrokeWidth() + SK_Scalar1,
<<<<<<< HEAD
        paint.getStrokeWidth() + SK_Scalar1);
=======
                  paint.getStrokeWidth() + SK_Scalar1);
>>>>>>> miniblink49

    if (!calculate_inverse_path(bounds, *pathPtr, &modifiedPath)) {
        return false;
    }

    drawPath(d, modifiedPath, noInversePaint, prePathMatrix, true);
    return true;
}

<<<<<<< HEAD
void SkPDFDevice::handlePointAnnotation(const SkPoint& point,
    const SkMatrix& matrix,
    const char key[], SkData* value)
{
    if (!value) {
        return;
    }

    if (!strcmp(SkAnnotationKeys::Define_Named_Dest_Key(), key)) {
        SkPoint transformedPoint;
        matrix.mapXY(point.x(), point.y(), &transformedPoint);
        fNamedDestinations.emplace_back(value, transformedPoint);
    }
}

void SkPDFDevice::handlePathAnnotation(const SkPath& path,
    const SkDraw& d,
    const char key[], SkData* value)
{
    if (!value) {
        return;
    }

    SkPath transformedPath = path;
    transformedPath.transform(*d.fMatrix);
    SkRasterClip clip = *d.fRC;
    clip.op(transformedPath, SkIRect::MakeWH(width(), height()), SkRegion::kIntersect_Op,
        false);
    SkRect transformedRect = SkRect::Make(clip.getBounds());

    if (!strcmp(SkAnnotationKeys::URL_Key(), key)) {
        if (!transformedRect.isEmpty()) {
            fLinkToURLs.emplace_back(transformedRect, value);
        }
    } else if (!strcmp(SkAnnotationKeys::Link_Named_Dest_Key(), key)) {
        if (!transformedRect.isEmpty()) {
            fLinkToDestinations.emplace_back(transformedRect, value);
        }
    }
}

void SkPDFDevice::appendAnnotations(SkPDFArray* array) const
{
    array->reserve(fLinkToURLs.count() + fLinkToDestinations.count());
    for (const RectWithData& rectWithURL : fLinkToURLs) {
        SkRect r;
        fInitialTransform.mapRect(&r, rectWithURL.rect);
        array->appendObject(create_link_to_url(rectWithURL.data.get(), r));
    }
    for (const RectWithData& linkToDestination : fLinkToDestinations) {
        SkRect r;
        fInitialTransform.mapRect(&r, linkToDestination.rect);
        array->appendObject(
            create_link_named_dest(linkToDestination.data.get(), r));
    }
}

void SkPDFDevice::appendDestinations(SkPDFDict* dict, SkPDFObject* page) const
{
    for (const NamedDestination& dest : fNamedDestinations) {
        auto pdfDest = sk_make_sp<SkPDFArray>();
        pdfDest->reserve(5);
        pdfDest->appendObjRef(sk_ref_sp(page));
        pdfDest->appendName("XYZ");
        SkPoint p = fInitialTransform.mapXY(dest.point.x(), dest.point.y());
        pdfDest->appendScalar(p.x());
        pdfDest->appendScalar(p.y());
        pdfDest->appendInt(0); // Leave zoom unchanged
        SkString name(static_cast<const char*>(dest.nameData->data()));
        dict->insertObject(name, std::move(pdfDest));
    }
}

SkPDFFormXObject* SkPDFDevice::createFormXObjectFromDevice()
{
    SkPDFFormXObject* xobject = new SkPDFFormXObject(this);
    // We always draw the form xobjects that we create back into the device, so
    // we simply preserve the font usage instead of pulling it out and merging
    // it back in later.
    cleanUp(false); // Reset this device to have no content.
=======
bool SkPDFDevice::handleRectAnnotation(const SkRect& r, const SkMatrix& matrix,
                                       const SkPaint& p) {
    SkAnnotation* annotationInfo = p.getAnnotation();
    if (!annotationInfo) {
        return false;
    }
    SkData* urlData = annotationInfo->find(SkAnnotationKeys::URL_Key());
    if (urlData) {
        handleLinkToURL(urlData, r, matrix);
        return p.getAnnotation() != NULL;
    }
    SkData* linkToName = annotationInfo->find(
            SkAnnotationKeys::Link_Named_Dest_Key());
    if (linkToName) {
        handleLinkToNamedDest(linkToName, r, matrix);
        return p.getAnnotation() != NULL;
    }
    return false;
}

bool SkPDFDevice::handlePointAnnotation(const SkPoint* points, size_t count,
                                        const SkMatrix& matrix,
                                        const SkPaint& paint) {
    SkAnnotation* annotationInfo = paint.getAnnotation();
    if (!annotationInfo) {
        return false;
    }
    SkData* nameData = annotationInfo->find(
            SkAnnotationKeys::Define_Named_Dest_Key());
    if (nameData) {
        for (size_t i = 0; i < count; i++) {
            defineNamedDestination(nameData, points[i], matrix);
        }
        return paint.getAnnotation() != NULL;
    }
    return false;
}

void SkPDFDevice::addAnnotation(SkPDFDict* annotation) {
    if (NULL == fAnnotations) {
        fAnnotations = SkNEW(SkPDFArray);
    }
    fAnnotations->appendObject(annotation);
}

static SkPDFDict* create_link_annotation(const SkRect& r,
                                         const SkMatrix& initialTransform,
                                         const SkMatrix& matrix) {
    SkMatrix transform = matrix;
    transform.postConcat(initialTransform);
    SkRect translatedRect;
    transform.mapRect(&translatedRect, r);

    SkAutoTUnref<SkPDFDict> annotation(SkNEW_ARGS(SkPDFDict, ("Annot")));
    annotation->insertName("Subtype", "Link");

    SkAutoTUnref<SkPDFArray> border(SkNEW(SkPDFArray));
    border->reserve(3);
    border->appendInt(0);  // Horizontal corner radius.
    border->appendInt(0);  // Vertical corner radius.
    border->appendInt(0);  // Width, 0 = no border.
    annotation->insertObject("Border", border.detach());

    SkAutoTUnref<SkPDFArray> rect(SkNEW(SkPDFArray));
    rect->reserve(4);
    rect->appendScalar(translatedRect.fLeft);
    rect->appendScalar(translatedRect.fTop);
    rect->appendScalar(translatedRect.fRight);
    rect->appendScalar(translatedRect.fBottom);
    annotation->insertObject("Rect", rect.detach());

    return annotation.detach();
}

void SkPDFDevice::handleLinkToURL(SkData* urlData, const SkRect& r,
                                  const SkMatrix& matrix) {
    SkAutoTUnref<SkPDFDict> annotation(
            create_link_annotation(r, fInitialTransform, matrix));

    SkString url(static_cast<const char *>(urlData->data()),
                 urlData->size() - 1);
    SkAutoTUnref<SkPDFDict> action(SkNEW_ARGS(SkPDFDict, ("Action")));
    action->insertName("S", "URI");
    action->insertString("URI", url);
    annotation->insertObject("A", action.detach());
    this->addAnnotation(annotation.detach());
}

void SkPDFDevice::handleLinkToNamedDest(SkData* nameData, const SkRect& r,
                                        const SkMatrix& matrix) {
    SkAutoTUnref<SkPDFDict> annotation(
            create_link_annotation(r, fInitialTransform, matrix));
    SkString name(static_cast<const char *>(nameData->data()),
                  nameData->size() - 1);
    annotation->insertName("Dest", name);
    this->addAnnotation(annotation.detach());
}

struct NamedDestination {
    const SkData* nameData;
    SkPoint point;

    NamedDestination(const SkData* nameData, const SkPoint& point)
        : nameData(SkRef(nameData)), point(point) {}

    ~NamedDestination() {
        nameData->unref();
    }
};

void SkPDFDevice::defineNamedDestination(SkData* nameData, const SkPoint& point,
                                         const SkMatrix& matrix) {
    SkMatrix transform = matrix;
    transform.postConcat(fInitialTransform);
    SkPoint translatedPoint;
    transform.mapXY(point.x(), point.y(), &translatedPoint);
    fNamedDestinations.push(
        SkNEW_ARGS(NamedDestination, (nameData, translatedPoint)));
}

void SkPDFDevice::appendDestinations(SkPDFDict* dict, SkPDFObject* page) const {
    int nDest = fNamedDestinations.count();
    for (int i = 0; i < nDest; i++) {
        NamedDestination* dest = fNamedDestinations[i];
        SkAutoTUnref<SkPDFArray> pdfDest(SkNEW(SkPDFArray));
        pdfDest->reserve(5);
        pdfDest->appendObjRef(SkRef(page));
        pdfDest->appendName("XYZ");
        pdfDest->appendScalar(dest->point.x());
        pdfDest->appendScalar(dest->point.y());
        pdfDest->appendInt(0);  // Leave zoom unchanged
        SkString name(static_cast<const char*>(dest->nameData->data()));
        dict->insertObject(name, pdfDest.detach());
    }
}

SkPDFFormXObject* SkPDFDevice::createFormXObjectFromDevice() {
    SkPDFFormXObject* xobject = SkNEW_ARGS(SkPDFFormXObject, (this));
    // We always draw the form xobjects that we create back into the device, so
    // we simply preserve the font usage instead of pulling it out and merging
    // it back in later.
    cleanUp(false);  // Reset this device to have no content.
>>>>>>> miniblink49
    init();
    return xobject;
}

void SkPDFDevice::drawFormXObjectWithMask(int xObjectIndex,
<<<<<<< HEAD
    SkPDFFormXObject* mask,
    const SkClipStack* clipStack,
    const SkRegion& clipRegion,
    SkXfermode::Mode mode,
    bool invertClip)
{
=======
                                          SkPDFFormXObject* mask,
                                          const SkClipStack* clipStack,
                                          const SkRegion& clipRegion,
                                          SkXfermode::Mode mode,
                                          bool invertClip) {
>>>>>>> miniblink49
    if (clipRegion.isEmpty() && !invertClip) {
        return;
    }

<<<<<<< HEAD
    auto sMaskGS = SkPDFGraphicState::GetSMaskGraphicState(
        mask, invertClip, SkPDFGraphicState::kAlpha_SMaskMode, fDocument->canon());
=======
    SkAutoTUnref<SkPDFObject> sMaskGS(SkPDFGraphicState::GetSMaskGraphicState(
            mask, invertClip, SkPDFGraphicState::kAlpha_SMaskMode));
>>>>>>> miniblink49

    SkMatrix identity;
    identity.reset();
    SkPaint paint;
    paint.setXfermodeMode(mode);
    ScopedContentEntry content(this, clipStack, clipRegion, identity, paint);
    if (!content.entry()) {
        return;
    }
    SkPDFUtils::ApplyGraphicState(addGraphicStateResource(sMaskGS.get()),
<<<<<<< HEAD
        &content.entry()->fContent);
    SkPDFUtils::DrawFormXObject(xObjectIndex, &content.entry()->fContent);

    // Call makeNoSmaskGraphicState() instead of
    // SkPDFGraphicState::MakeNoSmaskGraphicState so that the canon
    // can deduplicate.
    sMaskGS = fDocument->canon()->makeNoSmaskGraphicState();
    SkPDFUtils::ApplyGraphicState(addGraphicStateResource(sMaskGS.get()),
        &content.entry()->fContent);
}

SkPDFDevice::ContentEntry* SkPDFDevice::setUpContentEntry(const SkClipStack* clipStack,
    const SkRegion& clipRegion,
    const SkMatrix& matrix,
    const SkPaint& paint,
    bool hasText,
    SkPDFFormXObject** dst)
{
    *dst = nullptr;
    if (clipRegion.isEmpty()) {
        return nullptr;
=======
                                  &content.entry()->fContent);
    SkPDFUtils::DrawFormXObject(xObjectIndex, &content.entry()->fContent);

    sMaskGS.reset(SkPDFGraphicState::GetNoSMaskGraphicState());
    SkPDFUtils::ApplyGraphicState(addGraphicStateResource(sMaskGS.get()),
                                  &content.entry()->fContent);
}

ContentEntry* SkPDFDevice::setUpContentEntry(const SkClipStack* clipStack,
                                             const SkRegion& clipRegion,
                                             const SkMatrix& matrix,
                                             const SkPaint& paint,
                                             bool hasText,
                                             SkPDFFormXObject** dst) {
    *dst = NULL;
    if (clipRegion.isEmpty()) {
        return NULL;
>>>>>>> miniblink49
    }

    // The clip stack can come from an SkDraw where it is technically optional.
    SkClipStack synthesizedClipStack;
<<<<<<< HEAD
    if (clipStack == nullptr) {
=======
    if (clipStack == NULL) {
>>>>>>> miniblink49
        if (clipRegion == fExistingClipRegion) {
            clipStack = &fExistingClipStack;
        } else {
            // GraphicStackState::updateClip expects the clip stack to have
            // fExistingClip as a prefix, so start there, then set the clip
            // to the passed region.
            synthesizedClipStack = fExistingClipStack;
            SkPath clipPath;
            clipRegion.getBoundaryPath(&clipPath);
            synthesizedClipStack.clipDevPath(clipPath, SkRegion::kReplace_Op,
<<<<<<< HEAD
                false);
=======
                                             false);
>>>>>>> miniblink49
            clipStack = &synthesizedClipStack;
        }
    }

    SkXfermode::Mode xfermode = SkXfermode::kSrcOver_Mode;
    if (paint.getXfermode()) {
        paint.getXfermode()->asMode(&xfermode);
    }

    // For the following modes, we want to handle source and destination
    // separately, so make an object of what's already there.
<<<<<<< HEAD
    if (xfermode == SkXfermode::kClear_Mode || xfermode == SkXfermode::kSrc_Mode || xfermode == SkXfermode::kSrcIn_Mode || xfermode == SkXfermode::kDstIn_Mode || xfermode == SkXfermode::kSrcOut_Mode || xfermode == SkXfermode::kDstOut_Mode || xfermode == SkXfermode::kSrcATop_Mode || xfermode == SkXfermode::kDstATop_Mode || xfermode == SkXfermode::kModulate_Mode) {
        if (!isContentEmpty()) {
            *dst = createFormXObjectFromDevice();
            SkASSERT(isContentEmpty());
        } else if (xfermode != SkXfermode::kSrc_Mode && xfermode != SkXfermode::kSrcOut_Mode) {
            // Except for Src and SrcOut, if there isn't anything already there,
            // then we're done.
            return nullptr;
=======
    if (xfermode == SkXfermode::kClear_Mode       ||
            xfermode == SkXfermode::kSrc_Mode     ||
            xfermode == SkXfermode::kSrcIn_Mode   ||
            xfermode == SkXfermode::kDstIn_Mode   ||
            xfermode == SkXfermode::kSrcOut_Mode  ||
            xfermode == SkXfermode::kDstOut_Mode  ||
            xfermode == SkXfermode::kSrcATop_Mode ||
            xfermode == SkXfermode::kDstATop_Mode ||
            xfermode == SkXfermode::kModulate_Mode) {
        if (!isContentEmpty()) {
            *dst = createFormXObjectFromDevice();
            SkASSERT(isContentEmpty());
        } else if (xfermode != SkXfermode::kSrc_Mode &&
                   xfermode != SkXfermode::kSrcOut_Mode) {
            // Except for Src and SrcOut, if there isn't anything already there,
            // then we're done.
            return NULL;
>>>>>>> miniblink49
        }
    }
    // TODO(vandebo): Figure out how/if we can handle the following modes:
    // Xor, Plus.

    // Dst xfer mode doesn't draw source at all.
    if (xfermode == SkXfermode::kDst_Mode) {
<<<<<<< HEAD
        return nullptr;
    }

    SkPDFDevice::ContentEntry* entry;
    if (fContentEntries.back() && fContentEntries.back()->fContent.getOffset() == 0) {
        entry = fContentEntries.back();
    } else if (xfermode != SkXfermode::kDstOver_Mode) {
        entry = fContentEntries.emplace_back();
    } else {
        entry = fContentEntries.emplace_front();
    }
    populateGraphicStateEntryFromPaint(matrix, *clipStack, clipRegion, paint,
        hasText, &entry->fState);
=======
        return NULL;
    }

    ContentEntry* entry;
    SkAutoTDelete<ContentEntry> newEntry;

    ContentEntry* lastContentEntry = getLastContentEntry();
    if (lastContentEntry && lastContentEntry->fContent.getOffset() == 0) {
        entry = lastContentEntry;
    } else {
        newEntry.reset(new ContentEntry);
        entry = newEntry.get();
    }

    populateGraphicStateEntryFromPaint(matrix, *clipStack, clipRegion, paint,
                                       hasText, &entry->fState);
    if (lastContentEntry && xfermode != SkXfermode::kDstOver_Mode &&
            entry->fState.compareInitialState(lastContentEntry->fState)) {
        return lastContentEntry;
    }

    SkAutoTDelete<ContentEntry>* contentEntries = getContentEntries();
    if (!lastContentEntry) {
        contentEntries->reset(entry);
        setLastContentEntry(entry);
    } else if (xfermode == SkXfermode::kDstOver_Mode) {
        entry->fNext.reset(contentEntries->detach());
        contentEntries->reset(entry);
    } else {
        lastContentEntry->fNext.reset(entry);
        setLastContentEntry(entry);
    }
    newEntry.detach();
>>>>>>> miniblink49
    return entry;
}

void SkPDFDevice::finishContentEntry(SkXfermode::Mode xfermode,
<<<<<<< HEAD
    SkPDFFormXObject* dst,
    SkPath* shape)
{
    if (xfermode != SkXfermode::kClear_Mode && xfermode != SkXfermode::kSrc_Mode && xfermode != SkXfermode::kDstOver_Mode && xfermode != SkXfermode::kSrcIn_Mode && xfermode != SkXfermode::kDstIn_Mode && xfermode != SkXfermode::kSrcOut_Mode && xfermode != SkXfermode::kDstOut_Mode && xfermode != SkXfermode::kSrcATop_Mode && xfermode != SkXfermode::kDstATop_Mode && xfermode != SkXfermode::kModulate_Mode) {
=======
                                     SkPDFFormXObject* dst,
                                     SkPath* shape) {
    if (xfermode != SkXfermode::kClear_Mode       &&
            xfermode != SkXfermode::kSrc_Mode     &&
            xfermode != SkXfermode::kDstOver_Mode &&
            xfermode != SkXfermode::kSrcIn_Mode   &&
            xfermode != SkXfermode::kDstIn_Mode   &&
            xfermode != SkXfermode::kSrcOut_Mode  &&
            xfermode != SkXfermode::kDstOut_Mode  &&
            xfermode != SkXfermode::kSrcATop_Mode &&
            xfermode != SkXfermode::kDstATop_Mode &&
            xfermode != SkXfermode::kModulate_Mode) {
>>>>>>> miniblink49
        SkASSERT(!dst);
        return;
    }
    if (xfermode == SkXfermode::kDstOver_Mode) {
        SkASSERT(!dst);
<<<<<<< HEAD
        if (fContentEntries.front()->fContent.getOffset() == 0) {
            // For DstOver, an empty content entry was inserted before the rest
            // of the content entries. If nothing was drawn, it needs to be
            // removed.
            fContentEntries.pop_front();
=======
        ContentEntry* firstContentEntry = getContentEntries()->get();
        if (firstContentEntry->fContent.getOffset() == 0) {
            // For DstOver, an empty content entry was inserted before the rest
            // of the content entries. If nothing was drawn, it needs to be
            // removed.
            SkAutoTDelete<ContentEntry>* contentEntries = getContentEntries();
            contentEntries->reset(firstContentEntry->fNext.detach());
>>>>>>> miniblink49
        }
        return;
    }
    if (!dst) {
<<<<<<< HEAD
        SkASSERT(xfermode == SkXfermode::kSrc_Mode || xfermode == SkXfermode::kSrcOut_Mode);
        return;
    }

    SkASSERT(dst);
    SkASSERT(fContentEntries.count() == 1);
=======
        SkASSERT(xfermode == SkXfermode::kSrc_Mode ||
                 xfermode == SkXfermode::kSrcOut_Mode);
        return;
    }

    ContentEntry* contentEntries = getContentEntries()->get();
    SkASSERT(dst);
    SkASSERT(!contentEntries->fNext.get());
>>>>>>> miniblink49
    // Changing the current content into a form-xobject will destroy the clip
    // objects which is fine since the xobject will already be clipped. However
    // if source has shape, we need to clip it too, so a copy of the clip is
    // saved.
<<<<<<< HEAD

    SkClipStack clipStack = fContentEntries.front()->fState.fClipStack;
    SkRegion clipRegion = fContentEntries.front()->fState.fClipRegion;
=======
    SkClipStack clipStack = contentEntries->fState.fClipStack;
    SkRegion clipRegion = contentEntries->fState.fClipRegion;
>>>>>>> miniblink49

    SkMatrix identity;
    identity.reset();
    SkPaint stockPaint;

<<<<<<< HEAD
    sk_sp<SkPDFFormXObject> srcFormXObject;
=======
    SkAutoTUnref<SkPDFFormXObject> srcFormXObject;
>>>>>>> miniblink49
    if (isContentEmpty()) {
        // If nothing was drawn and there's no shape, then the draw was a
        // no-op, but dst needs to be restored for that to be true.
        // If there is shape, then an empty source with Src, SrcIn, SrcOut,
        // DstIn, DstAtop or Modulate reduces to Clear and DstOut or SrcAtop
        // reduces to Dst.
<<<<<<< HEAD
        if (shape == nullptr || xfermode == SkXfermode::kDstOut_Mode || xfermode == SkXfermode::kSrcATop_Mode) {
            ScopedContentEntry content(this, &fExistingClipStack,
                fExistingClipRegion, identity,
                stockPaint);
            SkPDFUtils::DrawFormXObject(this->addXObjectResource(dst),
                &content.entry()->fContent);
=======
        if (shape == NULL || xfermode == SkXfermode::kDstOut_Mode ||
                xfermode == SkXfermode::kSrcATop_Mode) {
            ScopedContentEntry content(this, &fExistingClipStack,
                                       fExistingClipRegion, identity,
                                       stockPaint);
            SkPDFUtils::DrawFormXObject(this->addXObjectResource(dst),
                                        &content.entry()->fContent);
>>>>>>> miniblink49
            return;
        } else {
            xfermode = SkXfermode::kClear_Mode;
        }
    } else {
<<<<<<< HEAD
        SkASSERT(fContentEntries.count() == 1);
=======
        SkASSERT(!fContentEntries->fNext.get());
>>>>>>> miniblink49
        srcFormXObject.reset(createFormXObjectFromDevice());
    }

    // TODO(vandebo) srcFormXObject may contain alpha, but here we want it
    // without alpha.
    if (xfermode == SkXfermode::kSrcATop_Mode) {
        // TODO(vandebo): In order to properly support SrcATop we have to track
        // the shape of what's been drawn at all times. It's the intersection of
        // the non-transparent parts of the device and the outlines (shape) of
        // all images and devices drawn.
        drawFormXObjectWithMask(addXObjectResource(srcFormXObject.get()), dst,
<<<<<<< HEAD
            &fExistingClipStack, fExistingClipRegion,
            SkXfermode::kSrcOver_Mode, true);
    } else {
        sk_sp<SkPDFFormXObject> dstMaskStorage;
        SkPDFFormXObject* dstMask = srcFormXObject.get();
        if (shape != nullptr) {
            // Draw shape into a form-xobject.
            SkRasterClip rc(clipRegion);
            SkDraw d;
            d.fMatrix = &identity;
            d.fRC = &rc;
=======
                                &fExistingClipStack, fExistingClipRegion,
                                SkXfermode::kSrcOver_Mode, true);
    } else {
        SkAutoTUnref<SkPDFFormXObject> dstMaskStorage;
        SkPDFFormXObject* dstMask = srcFormXObject.get();
        if (shape != NULL) {
            // Draw shape into a form-xobject.
            SkDraw d;
            d.fMatrix = &identity;
            d.fClip = &clipRegion;
>>>>>>> miniblink49
            d.fClipStack = &clipStack;
            SkPaint filledPaint;
            filledPaint.setColor(SK_ColorBLACK);
            filledPaint.setStyle(SkPaint::kFill_Style);
<<<<<<< HEAD
            this->drawPath(d, *shape, filledPaint, nullptr, true);
=======
            this->drawPath(d, *shape, filledPaint, NULL, true);
>>>>>>> miniblink49

            dstMaskStorage.reset(createFormXObjectFromDevice());
            dstMask = dstMaskStorage.get();
        }
        drawFormXObjectWithMask(addXObjectResource(dst), dstMask,
<<<<<<< HEAD
            &fExistingClipStack, fExistingClipRegion,
            SkXfermode::kSrcOver_Mode, true);
=======
                                &fExistingClipStack, fExistingClipRegion,
                                SkXfermode::kSrcOver_Mode, true);
>>>>>>> miniblink49
    }

    if (xfermode == SkXfermode::kClear_Mode) {
        return;
<<<<<<< HEAD
    } else if (xfermode == SkXfermode::kSrc_Mode || xfermode == SkXfermode::kDstATop_Mode) {
        ScopedContentEntry content(this, &fExistingClipStack,
            fExistingClipRegion, identity, stockPaint);
        if (content.entry()) {
            SkPDFUtils::DrawFormXObject(
                this->addXObjectResource(srcFormXObject.get()),
                &content.entry()->fContent);
=======
    } else if (xfermode == SkXfermode::kSrc_Mode ||
            xfermode == SkXfermode::kDstATop_Mode) {
        ScopedContentEntry content(this, &fExistingClipStack,
                                   fExistingClipRegion, identity, stockPaint);
        if (content.entry()) {
            SkPDFUtils::DrawFormXObject(
                    this->addXObjectResource(srcFormXObject.get()),
                    &content.entry()->fContent);
>>>>>>> miniblink49
        }
        if (xfermode == SkXfermode::kSrc_Mode) {
            return;
        }
    } else if (xfermode == SkXfermode::kSrcATop_Mode) {
        ScopedContentEntry content(this, &fExistingClipStack,
<<<<<<< HEAD
            fExistingClipRegion, identity, stockPaint);
        if (content.entry()) {
            SkPDFUtils::DrawFormXObject(this->addXObjectResource(dst),
                &content.entry()->fContent);
        }
    }

    SkASSERT(xfermode == SkXfermode::kSrcIn_Mode || xfermode == SkXfermode::kDstIn_Mode || xfermode == SkXfermode::kSrcOut_Mode || xfermode == SkXfermode::kDstOut_Mode || xfermode == SkXfermode::kSrcATop_Mode || xfermode == SkXfermode::kDstATop_Mode || xfermode == SkXfermode::kModulate_Mode);

    if (xfermode == SkXfermode::kSrcIn_Mode || xfermode == SkXfermode::kSrcOut_Mode || xfermode == SkXfermode::kSrcATop_Mode) {
        drawFormXObjectWithMask(addXObjectResource(srcFormXObject.get()), dst,
            &fExistingClipStack, fExistingClipRegion,
            SkXfermode::kSrcOver_Mode,
            xfermode == SkXfermode::kSrcOut_Mode);
=======
                                   fExistingClipRegion, identity, stockPaint);
        if (content.entry()) {
            SkPDFUtils::DrawFormXObject(this->addXObjectResource(dst),
                                        &content.entry()->fContent);
        }
    }

    SkASSERT(xfermode == SkXfermode::kSrcIn_Mode   ||
             xfermode == SkXfermode::kDstIn_Mode   ||
             xfermode == SkXfermode::kSrcOut_Mode  ||
             xfermode == SkXfermode::kDstOut_Mode  ||
             xfermode == SkXfermode::kSrcATop_Mode ||
             xfermode == SkXfermode::kDstATop_Mode ||
             xfermode == SkXfermode::kModulate_Mode);

    if (xfermode == SkXfermode::kSrcIn_Mode ||
            xfermode == SkXfermode::kSrcOut_Mode ||
            xfermode == SkXfermode::kSrcATop_Mode) {
        drawFormXObjectWithMask(addXObjectResource(srcFormXObject.get()), dst,
                                &fExistingClipStack, fExistingClipRegion,
                                SkXfermode::kSrcOver_Mode,
                                xfermode == SkXfermode::kSrcOut_Mode);
>>>>>>> miniblink49
    } else {
        SkXfermode::Mode mode = SkXfermode::kSrcOver_Mode;
        if (xfermode == SkXfermode::kModulate_Mode) {
            drawFormXObjectWithMask(addXObjectResource(srcFormXObject.get()),
<<<<<<< HEAD
                dst, &fExistingClipStack,
                fExistingClipRegion,
                SkXfermode::kSrcOver_Mode, false);
            mode = SkXfermode::kMultiply_Mode;
        }
        drawFormXObjectWithMask(addXObjectResource(dst), srcFormXObject.get(),
            &fExistingClipStack, fExistingClipRegion, mode,
            xfermode == SkXfermode::kDstOut_Mode);
    }
}

bool SkPDFDevice::isContentEmpty()
{
    if (!fContentEntries.front() || fContentEntries.front()->fContent.getOffset() == 0) {
        SkASSERT(fContentEntries.count() <= 1);
=======
                                    dst, &fExistingClipStack,
                                    fExistingClipRegion,
                                    SkXfermode::kSrcOver_Mode, false);
            mode = SkXfermode::kMultiply_Mode;
        }
        drawFormXObjectWithMask(addXObjectResource(dst), srcFormXObject.get(),
                                &fExistingClipStack, fExistingClipRegion, mode,
                                xfermode == SkXfermode::kDstOut_Mode);
    }
}

bool SkPDFDevice::isContentEmpty() {
    ContentEntry* contentEntries = getContentEntries()->get();
    if (!contentEntries || contentEntries->fContent.getOffset() == 0) {
        SkASSERT(!contentEntries || !contentEntries->fNext.get());
>>>>>>> miniblink49
        return true;
    }
    return false;
}

void SkPDFDevice::populateGraphicStateEntryFromPaint(
<<<<<<< HEAD
    const SkMatrix& matrix,
    const SkClipStack& clipStack,
    const SkRegion& clipRegion,
    const SkPaint& paint,
    bool hasText,
    SkPDFDevice::GraphicStateEntry* entry)
{
    NOT_IMPLEMENTED(paint.getPathEffect() != nullptr, false);
    NOT_IMPLEMENTED(paint.getMaskFilter() != nullptr, false);
    NOT_IMPLEMENTED(paint.getColorFilter() != nullptr, false);
=======
        const SkMatrix& matrix,
        const SkClipStack& clipStack,
        const SkRegion& clipRegion,
        const SkPaint& paint,
        bool hasText,
        GraphicStateEntry* entry) {
    NOT_IMPLEMENTED(paint.getPathEffect() != NULL, false);
    NOT_IMPLEMENTED(paint.getMaskFilter() != NULL, false);
    NOT_IMPLEMENTED(paint.getColorFilter() != NULL, false);
>>>>>>> miniblink49

    entry->fMatrix = matrix;
    entry->fClipStack = clipStack;
    entry->fClipRegion = clipRegion;
    entry->fColor = SkColorSetA(paint.getColor(), 0xFF);
    entry->fShaderIndex = -1;

    // PDF treats a shader as a color, so we only set one or the other.
<<<<<<< HEAD
    sk_sp<SkPDFObject> pdfShader;
    SkShader* shader = paint.getShader();
=======
    SkAutoTUnref<SkPDFObject> pdfShader;
    const SkShader* shader = paint.getShader();
>>>>>>> miniblink49
    SkColor color = paint.getColor();
    if (shader) {
        // PDF positions patterns relative to the initial transform, so
        // we need to apply the current transform to the shader parameters.
        SkMatrix transform = matrix;
        transform.postConcat(fInitialTransform);

        // PDF doesn't support kClamp_TileMode, so we simulate it by making
        // a pattern the size of the current clip.
        SkIRect bounds = clipRegion.getBounds();

        // We need to apply the initial transform to bounds in order to get
        // bounds in a consistent coordinate system.
        SkRect boundsTemp;
        boundsTemp.set(bounds);
        fInitialTransform.mapRect(&boundsTemp);
        boundsTemp.roundOut(&bounds);

<<<<<<< HEAD
        SkScalar rasterScale = SkIntToScalar(fRasterDpi) / DPI_FOR_RASTER_SCALE_ONE;
        pdfShader.reset(SkPDFShader::GetPDFShader(
            fDocument, fRasterDpi, shader, transform, bounds, rasterScale));
=======
        SkScalar rasterScale =
                SkIntToScalar(fRasterDpi) / DPI_FOR_RASTER_SCALE_ONE;
        pdfShader.reset(SkPDFShader::GetPDFShader(
                fCanon, fRasterDpi, *shader, transform, bounds, rasterScale));
>>>>>>> miniblink49

        if (pdfShader.get()) {
            // pdfShader has been canonicalized so we can directly compare
            // pointers.
            int resourceIndex = fShaderResources.find(pdfShader.get());
            if (resourceIndex < 0) {
                resourceIndex = fShaderResources.count();
                fShaderResources.push(pdfShader.get());
                pdfShader.get()->ref();
            }
            entry->fShaderIndex = resourceIndex;
        } else {
            // A color shader is treated as an invalid shader so we don't have
            // to set a shader just for a color.
            SkShader::GradientInfo gradientInfo;
            SkColor gradientColor;
            gradientInfo.fColors = &gradientColor;
<<<<<<< HEAD
            gradientInfo.fColorOffsets = nullptr;
            gradientInfo.fColorCount = 1;
            if (shader->asAGradient(&gradientInfo) == SkShader::kColor_GradientType) {
=======
            gradientInfo.fColorOffsets = NULL;
            gradientInfo.fColorCount = 1;
            if (shader->asAGradient(&gradientInfo) ==
                    SkShader::kColor_GradientType) {
>>>>>>> miniblink49
                entry->fColor = SkColorSetA(gradientColor, 0xFF);
                color = gradientColor;
            }
        }
    }

<<<<<<< HEAD
    sk_sp<SkPDFGraphicState> newGraphicState;
    if (color == paint.getColor()) {
        newGraphicState.reset(
            SkPDFGraphicState::GetGraphicStateForPaint(fDocument->canon(), paint));
=======
    SkAutoTUnref<SkPDFGraphicState> newGraphicState;
    if (color == paint.getColor()) {
        newGraphicState.reset(
                SkPDFGraphicState::GetGraphicStateForPaint(fCanon, paint));
>>>>>>> miniblink49
    } else {
        SkPaint newPaint = paint;
        newPaint.setColor(color);
        newGraphicState.reset(
<<<<<<< HEAD
            SkPDFGraphicState::GetGraphicStateForPaint(fDocument->canon(), newPaint));
=======
                SkPDFGraphicState::GetGraphicStateForPaint(fCanon, newPaint));
>>>>>>> miniblink49
    }
    int resourceIndex = addGraphicStateResource(newGraphicState.get());
    entry->fGraphicStateIndex = resourceIndex;

    if (hasText) {
        entry->fTextScaleX = paint.getTextScaleX();
        entry->fTextFill = paint.getStyle();
    } else {
        entry->fTextScaleX = 0;
    }
}

<<<<<<< HEAD
int SkPDFDevice::addGraphicStateResource(SkPDFObject* gs)
{
=======
int SkPDFDevice::addGraphicStateResource(SkPDFObject* gs) {
>>>>>>> miniblink49
    // Assumes that gs has been canonicalized (so we can directly compare
    // pointers).
    int result = fGraphicStateResources.find(gs);
    if (result < 0) {
        result = fGraphicStateResources.count();
        fGraphicStateResources.push(gs);
        gs->ref();
    }
    return result;
}

<<<<<<< HEAD
int SkPDFDevice::addXObjectResource(SkPDFObject* xObject)
{
=======
int SkPDFDevice::addXObjectResource(SkPDFObject* xObject) {
>>>>>>> miniblink49
    // Assumes that xobject has been canonicalized (so we can directly compare
    // pointers).
    int result = fXObjectResources.find(xObject);
    if (result < 0) {
        result = fXObjectResources.count();
        fXObjectResources.push(xObject);
        xObject->ref();
    }
    return result;
}

void SkPDFDevice::updateFont(const SkPaint& paint, uint16_t glyphID,
<<<<<<< HEAD
    SkPDFDevice::ContentEntry* contentEntry)
{
    SkTypeface* typeface = paint.getTypeface();
    if (contentEntry->fState.fFont == nullptr || contentEntry->fState.fTextSize != paint.getTextSize() || !contentEntry->fState.fFont->hasGlyph(glyphID)) {
        int fontIndex = getFontResourceIndex(typeface, glyphID);
        contentEntry->fContent.writeText("/");
        contentEntry->fContent.writeText(SkPDFResourceDict::getResourceName(
            SkPDFResourceDict::kFont_ResourceType,
            fontIndex)
                                             .c_str());
=======
                             ContentEntry* contentEntry) {
    SkTypeface* typeface = paint.getTypeface();
    if (contentEntry->fState.fFont == NULL ||
            contentEntry->fState.fTextSize != paint.getTextSize() ||
            !contentEntry->fState.fFont->hasGlyph(glyphID)) {
        int fontIndex = getFontResourceIndex(typeface, glyphID);
        contentEntry->fContent.writeText("/");
        contentEntry->fContent.writeText(SkPDFResourceDict::getResourceName(
                SkPDFResourceDict::kFont_ResourceType,
                fontIndex).c_str());
>>>>>>> miniblink49
        contentEntry->fContent.writeText(" ");
        SkPDFUtils::AppendScalar(paint.getTextSize(), &contentEntry->fContent);
        contentEntry->fContent.writeText(" Tf\n");
        contentEntry->fState.fFont = fFontResources[fontIndex];
    }
}

<<<<<<< HEAD
int SkPDFDevice::getFontResourceIndex(SkTypeface* typeface, uint16_t glyphID)
{
    sk_sp<SkPDFFont> newFont(
        SkPDFFont::GetFontResource(fDocument->canon(), typeface, glyphID));
=======
int SkPDFDevice::getFontResourceIndex(SkTypeface* typeface, uint16_t glyphID) {
    SkAutoTUnref<SkPDFFont> newFont(
            SkPDFFont::GetFontResource(fCanon, typeface, glyphID));
>>>>>>> miniblink49
    int resourceIndex = fFontResources.find(newFont.get());
    if (resourceIndex < 0) {
        resourceIndex = fFontResources.count();
        fFontResources.push(newFont.get());
        newFont.get()->ref();
    }
    return resourceIndex;
}

<<<<<<< HEAD
static SkSize rect_to_size(const SkRect& r)
{
    return SkSize::Make(r.width(), r.height());
}

static sk_sp<SkImage> color_filter(const SkImageBitmap& imageBitmap,
    SkColorFilter* colorFilter)
{
    auto surface = SkSurface::MakeRaster(SkImageInfo::MakeN32Premul(imageBitmap.dimensions()));
    SkASSERT(surface);
    SkCanvas* canvas = surface->getCanvas();
    canvas->clear(SK_ColorTRANSPARENT);
    SkPaint paint;
    paint.setColorFilter(sk_ref_sp(colorFilter));
    imageBitmap.draw(canvas, &paint);
    canvas->flush();
    return surface->makeImageSnapshot();
}

////////////////////////////////////////////////////////////////////////////////
void SkPDFDevice::internalDrawImage(const SkMatrix& origMatrix,
    const SkClipStack* clipStack,
    const SkRegion& origClipRegion,
    SkImageBitmap imageBitmap,
    const SkPaint& paint)
{
    if (imageBitmap.dimensions().isZero()) {
        return;
    }
#ifdef SK_PDF_IMAGE_STATS
    gDrawImageCalls.fetch_add(1);
#endif
    SkMatrix matrix = origMatrix;
    SkRegion perspectiveBounds;
    const SkRegion* clipRegion = &origClipRegion;
    sk_sp<SkImage> autoImageUnref;
=======
void SkPDFDevice::internalDrawBitmap(const SkMatrix& origMatrix,
                                     const SkClipStack* clipStack,
                                     const SkRegion& origClipRegion,
                                     const SkBitmap& origBitmap,
                                     const SkIRect* srcRect,
                                     const SkPaint& paint) {
    SkMatrix matrix = origMatrix;
    SkRegion perspectiveBounds;
    const SkRegion* clipRegion = &origClipRegion;
    SkBitmap perspectiveBitmap;
    const SkBitmap* bitmap = &origBitmap;
    SkBitmap tmpSubsetBitmap;
>>>>>>> miniblink49

    // Rasterize the bitmap using perspective in a new bitmap.
    if (origMatrix.hasPerspective()) {
        if (fRasterDpi == 0) {
            return;
        }
<<<<<<< HEAD
        // Transform the bitmap in the new space, without taking into
        // account the initial transform.
        SkPath perspectiveOutline;
        SkRect imageBounds = SkRect::Make(imageBitmap.bounds());
        perspectiveOutline.addRect(imageBounds);
=======
        SkBitmap* subsetBitmap;
        if (srcRect) {
            if (!origBitmap.extractSubset(&tmpSubsetBitmap, *srcRect)) {
               return;
            }
            subsetBitmap = &tmpSubsetBitmap;
        } else {
            subsetBitmap = &tmpSubsetBitmap;
            *subsetBitmap = origBitmap;
        }
        srcRect = NULL;

        // Transform the bitmap in the new space, without taking into
        // account the initial transform.
        SkPath perspectiveOutline;
        perspectiveOutline.addRect(
                SkRect::MakeWH(SkIntToScalar(subsetBitmap->width()),
                               SkIntToScalar(subsetBitmap->height())));
>>>>>>> miniblink49
        perspectiveOutline.transform(origMatrix);

        // TODO(edisonn): perf - use current clip too.
        // Retrieve the bounds of the new shape.
        SkRect bounds = perspectiveOutline.getBounds();

        // Transform the bitmap in the new space, taking into
        // account the initial transform.
        SkMatrix total = origMatrix;
        total.postConcat(fInitialTransform);
<<<<<<< HEAD
        SkScalar dpiScale = SkIntToScalar(fRasterDpi) / SkIntToScalar(DPI_FOR_RASTER_SCALE_ONE);
        total.postScale(dpiScale, dpiScale);

        SkPath physicalPerspectiveOutline;
        physicalPerspectiveOutline.addRect(imageBounds);
        physicalPerspectiveOutline.transform(total);

        SkRect physicalPerspectiveBounds = physicalPerspectiveOutline.getBounds();
        SkScalar scaleX = physicalPerspectiveBounds.width() / bounds.width();
        SkScalar scaleY = physicalPerspectiveBounds.height() / bounds.height();
=======
        total.postScale(SkIntToScalar(fRasterDpi) /
                            SkIntToScalar(DPI_FOR_RASTER_SCALE_ONE),
                        SkIntToScalar(fRasterDpi) /
                            SkIntToScalar(DPI_FOR_RASTER_SCALE_ONE));
        SkPath physicalPerspectiveOutline;
        physicalPerspectiveOutline.addRect(
                SkRect::MakeWH(SkIntToScalar(subsetBitmap->width()),
                               SkIntToScalar(subsetBitmap->height())));
        physicalPerspectiveOutline.transform(total);

        SkScalar scaleX = physicalPerspectiveOutline.getBounds().width() /
                              bounds.width();
        SkScalar scaleY = physicalPerspectiveOutline.getBounds().height() /
                              bounds.height();
>>>>>>> miniblink49

        // TODO(edisonn): A better approach would be to use a bitmap shader
        // (in clamp mode) and draw a rect over the entire bounding box. Then
        // intersect perspectiveOutline to the clip. That will avoid introducing
        // alpha to the image while still giving good behavior at the edge of
        // the image.  Avoiding alpha will reduce the pdf size and generation
        // CPU time some.

<<<<<<< HEAD
        SkISize wh = rect_to_size(physicalPerspectiveBounds).toCeil();

        auto surface(SkSurface::MakeRaster(SkImageInfo::MakeN32Premul(wh)));
        if (!surface) {
            return;
        }
        SkCanvas* canvas = surface->getCanvas();
        canvas->clear(SK_ColorTRANSPARENT);
=======
        const int w = SkScalarCeilToInt(physicalPerspectiveOutline.getBounds().width());
        const int h = SkScalarCeilToInt(physicalPerspectiveOutline.getBounds().height());
        if (!perspectiveBitmap.tryAllocN32Pixels(w, h)) {
            return;
        }
        perspectiveBitmap.eraseColor(SK_ColorTRANSPARENT);

        SkCanvas canvas(perspectiveBitmap);
>>>>>>> miniblink49

        SkScalar deltaX = bounds.left();
        SkScalar deltaY = bounds.top();

        SkMatrix offsetMatrix = origMatrix;
        offsetMatrix.postTranslate(-deltaX, -deltaY);
        offsetMatrix.postScale(scaleX, scaleY);

        // Translate the draw in the new canvas, so we perfectly fit the
        // shape in the bitmap.
<<<<<<< HEAD
        canvas->setMatrix(offsetMatrix);
        imageBitmap.draw(canvas, nullptr);
        // Make sure the final bits are in the bitmap.
        canvas->flush();
=======
        canvas.setMatrix(offsetMatrix);

        canvas.drawBitmap(*subsetBitmap, SkIntToScalar(0), SkIntToScalar(0));

        // Make sure the final bits are in the bitmap.
        canvas.flush();
>>>>>>> miniblink49

        // In the new space, we use the identity matrix translated
        // and scaled to reflect DPI.
        matrix.setScale(1 / scaleX, 1 / scaleY);
        matrix.postTranslate(deltaX, deltaY);

<<<<<<< HEAD
        perspectiveBounds.setRect(bounds.roundOut());
        clipRegion = &perspectiveBounds;

        autoImageUnref = surface->makeImageSnapshot();
        imageBitmap = SkImageBitmap(autoImageUnref.get());
=======
        perspectiveBounds.setRect(
                SkIRect::MakeXYWH(SkScalarFloorToInt(bounds.x()),
                                  SkScalarFloorToInt(bounds.y()),
                                  SkScalarCeilToInt(bounds.width()),
                                  SkScalarCeilToInt(bounds.height())));
        clipRegion = &perspectiveBounds;
        srcRect = NULL;
        bitmap = &perspectiveBitmap;
>>>>>>> miniblink49
    }

    SkMatrix scaled;
    // Adjust for origin flip.
    scaled.setScale(SK_Scalar1, -SK_Scalar1);
    scaled.postTranslate(0, SK_Scalar1);
    // Scale the image up from 1x1 to WxH.
<<<<<<< HEAD
    SkIRect subset = imageBitmap.bounds();
    scaled.postScale(SkIntToScalar(imageBitmap.dimensions().width()),
        SkIntToScalar(imageBitmap.dimensions().height()));
    scaled.postConcat(matrix);
    ScopedContentEntry content(this, clipStack, *clipRegion, scaled, paint);
    if (!content.entry()) {
=======
    SkIRect subset = bitmap->bounds();
    scaled.postScale(SkIntToScalar(subset.width()),
                     SkIntToScalar(subset.height()));
    scaled.postConcat(matrix);
    ScopedContentEntry content(this, clipStack, *clipRegion, scaled, paint);
    if (!content.entry() || (srcRect && !subset.intersect(*srcRect))) {
>>>>>>> miniblink49
        return;
    }
    if (content.needShape()) {
        SkPath shape;
<<<<<<< HEAD
        shape.addRect(SkRect::Make(subset));
=======
        shape.addRect(SkRect::MakeWH(SkIntToScalar(subset.width()),
                                     SkIntToScalar(subset.height())));
>>>>>>> miniblink49
        shape.transform(matrix);
        content.setShape(shape);
    }
    if (!content.needSource()) {
        return;
    }

<<<<<<< HEAD
    if (SkColorFilter* colorFilter = paint.getColorFilter()) {
        // TODO(https://bug.skia.org/4378): implement colorfilter on other
        // draw calls.  This code here works for all
        // drawBitmap*()/drawImage*() calls amd ImageFilters (which
        // rasterize a layer on this backend).  Fortuanely, this seems
        // to be how Chromium impements most color-filters.
        autoImageUnref = color_filter(imageBitmap, colorFilter);
        imageBitmap = SkImageBitmap(autoImageUnref.get());
        // TODO(halcanary): de-dupe this by caching filtered images.
        // (maybe in the resource cache?)
    }

    SkBitmapKey key = imageBitmap.getKey();
    sk_sp<SkPDFObject> pdfimage = fDocument->canon()->findPDFBitmap(key);
    if (!pdfimage) {
        auto img = imageBitmap.makeImage();
        if (!img) {
            return;
        }
        pdfimage = SkPDFCreateBitmapObject(
            std::move(img), fDocument->canon()->getPixelSerializer());
        if (!pdfimage) {
            return;
        }
        fDocument->serialize(pdfimage); // serialize images early.
        fDocument->canon()->addPDFBitmap(key, pdfimage);
    }
    // TODO(halcanary): addXObjectResource() should take a sk_sp<SkPDFObject>
    SkPDFUtils::DrawFormXObject(this->addXObjectResource(pdfimage.get()),
        &content.entry()->fContent);
=======
    SkBitmap subsetBitmap;
    // Should extractSubset be done by the SkPDFDevice?
    if (!bitmap->extractSubset(&subsetBitmap, subset)) {
        return;
    }
    SkAutoTUnref<SkPDFObject> image(SkPDFBitmap::Create(fCanon, subsetBitmap));
    if (!image) {
        return;
    }

    SkPDFUtils::DrawFormXObject(this->addXObjectResource(image.get()),
                                &content.entry()->fContent);
>>>>>>> miniblink49
}
