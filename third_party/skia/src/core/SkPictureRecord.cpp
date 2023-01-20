/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkPictureRecord.h"
<<<<<<< HEAD
=======
#include "SkDevice.h"
>>>>>>> miniblink49
#include "SkImage_Base.h"
#include "SkPatchUtils.h"
#include "SkPixelRef.h"
#include "SkRRect.h"
#include "SkRSXform.h"
<<<<<<< HEAD
#include "SkTSearch.h"
#include "SkTextBlob.h"
=======
#include "SkTextBlob.h"
#include "SkTSearch.h"
>>>>>>> miniblink49

#define HEAP_BLOCK_SIZE 4096

enum {
    // just need a value that save or getSaveCount would never return
    kNoInitialSave = -1,
};

// A lot of basic types get stored as a uint32_t: bools, ints, paint indices, etc.
static int const kUInt32Size = 4;

<<<<<<< HEAD
SkPictureRecord::SkPictureRecord(const SkISize& dimensions, uint32_t flags)
    : INHERITED(dimensions.width(), dimensions.height())
    , fRecordFlags(flags)
    , fInitialSaveCount(kNoInitialSave)
{
}

SkPictureRecord::~SkPictureRecord()
{
    fImageRefs.unrefAll();
    fPictureRefs.unrefAll();
    fDrawableRefs.unrefAll();
=======
static const uint32_t kSaveSize = kUInt32Size;
#ifdef SK_DEBUG
static const uint32_t kSaveLayerNoBoundsSize = 4 * kUInt32Size;
static const uint32_t kSaveLayerWithBoundsSize = 4 * kUInt32Size + sizeof(SkRect);
#endif//SK_DEBUG

SkPictureRecord::SkPictureRecord(const SkISize& dimensions, uint32_t flags)
    : INHERITED(dimensions.width(), dimensions.height())
    , fRecordFlags(flags)
    , fInitialSaveCount(kNoInitialSave) {
}

SkPictureRecord::~SkPictureRecord() {
    fImageRefs.unrefAll();
    fPictureRefs.unrefAll();
>>>>>>> miniblink49
    fTextBlobRefs.unrefAll();
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkPictureRecord::willSave()
{
=======
#ifdef SK_DEBUG
// Return the offset of the paint inside a given op's byte stream. A zero
// return value means there is no paint (and you really shouldn't be calling
// this method)
static inline size_t get_paint_offset(DrawType op, size_t opSize) {
    // These offsets are where the paint would be if the op size doesn't overflow
    static const uint8_t gPaintOffsets[] = {
        0,  // UNUSED - no paint
        0,  // CLIP_PATH - no paint
        0,  // CLIP_REGION - no paint
        0,  // CLIP_RECT - no paint
        0,  // CLIP_RRECT - no paint
        0,  // CONCAT - no paint
        1,  // DRAW_BITMAP - right after op code
        1,  // DRAW_BITMAP_MATRIX - right after op code, deprecated
        1,  // DRAW_BITMAP_NINE - right after op code
        1,  // DRAW_BITMAP_RECT_TO_RECT - right after op code
        0,  // DRAW_CLEAR - no paint
        0,  // DRAW_DATA - no paint
        1,  // DRAW_OVAL - right after op code
        1,  // DRAW_PAINT - right after op code
        1,  // DRAW_PATH - right after op code
        0,  // DRAW_PICTURE - no paint
        1,  // DRAW_POINTS - right after op code
        1,  // DRAW_POS_TEXT - right after op code
        1,  // DRAW_POS_TEXT_TOP_BOTTOM - right after op code
        1,  // DRAW_POS_TEXT_H - right after op code
        1,  // DRAW_POS_TEXT_H_TOP_BOTTOM - right after op code
        1,  // DRAW_RECT - right after op code
        1,  // DRAW_RRECT - right after op code
        1,  // DRAW_SPRITE - right after op code
        1,  // DRAW_TEXT - right after op code
        1,  // DRAW_TEXT_ON_PATH - right after op code
        1,  // DRAW_TEXT_TOP_BOTTOM - right after op code
        1,  // DRAW_VERTICES - right after op code
        0,  // RESTORE - no paint
        0,  // ROTATE - no paint
        0,  // SAVE - no paint
        0,  // SAVE_LAYER - see below - this paint's location varies
        0,  // SCALE - no paint
        0,  // SET_MATRIX - no paint
        0,  // SKEW - no paint
        0,  // TRANSLATE - no paint
        0,  // NOOP - no paint
        0,  // BEGIN_GROUP - no paint
        0,  // COMMENT - no paint
        0,  // END_GROUP - no paint
        1,  // DRAWDRRECT - right after op code
        0,  // PUSH_CULL - no paint
        0,  // POP_CULL - no paint
        1,  // DRAW_PATCH - right after op code
        1,  // DRAW_PICTURE_MATRIX_PAINT - right after op code
        1,  // DRAW_TEXT_BLOB- right after op code
        1,  // DRAW_IMAGE - right after op code
        1,  // DRAW_IMAGE_RECT - right after op code
        1,  // DRAW_ATLAS - right after op code
        1,  // DRAW_IMAGE_NINE - right after op code
    };

    SK_COMPILE_ASSERT(sizeof(gPaintOffsets) == LAST_DRAWTYPE_ENUM + 1,
                      need_to_be_in_sync);
    SkASSERT((unsigned)op <= (unsigned)LAST_DRAWTYPE_ENUM);

    int overflow = 0;
    if (0 != (opSize & ~MASK_24) || opSize == MASK_24) {
        // This op's size overflows so an extra uint32_t will be written
        // after the op code
        overflow = sizeof(uint32_t);
    }

    if (SAVE_LAYER == op) {
        static const uint32_t kSaveLayerNoBoundsPaintOffset = 2 * kUInt32Size;
        static const uint32_t kSaveLayerWithBoundsPaintOffset = 2 * kUInt32Size + sizeof(SkRect);

        if (kSaveLayerNoBoundsSize == opSize) {
            return kSaveLayerNoBoundsPaintOffset + overflow;
        } else {
            SkASSERT(kSaveLayerWithBoundsSize == opSize);
            return kSaveLayerWithBoundsPaintOffset + overflow;
        }
    }

    SkASSERT(0 != gPaintOffsets[op]);   // really shouldn't be calling this method
    return gPaintOffsets[op] * sizeof(uint32_t) + overflow;
}
#endif//SK_DEBUG

void SkPictureRecord::willSave() {
>>>>>>> miniblink49
    // record the offset to us, making it non-positive to distinguish a save
    // from a clip entry.
    fRestoreOffsetStack.push(-(int32_t)fWriter.bytesWritten());
    this->recordSave();

    this->INHERITED::willSave();
}

<<<<<<< HEAD
void SkPictureRecord::recordSave()
{
    fContentInfo.onSave();

    // op only
    size_t size = sizeof(kUInt32Size);
=======
void SkPictureRecord::recordSave() {
    fContentInfo.onSave();

    // op only
    size_t size = kSaveSize;
>>>>>>> miniblink49
    size_t initialOffset = this->addDraw(SAVE, &size);

    this->validate(initialOffset, size);
}

<<<<<<< HEAD
SkCanvas::SaveLayerStrategy SkPictureRecord::getSaveLayerStrategy(const SaveLayerRec& rec)
{
    // record the offset to us, making it non-positive to distinguish a save
    // from a clip entry.
    fRestoreOffsetStack.push(-(int32_t)fWriter.bytesWritten());
    this->recordSaveLayer(rec);

    (void)this->INHERITED::getSaveLayerStrategy(rec);
=======
SkCanvas::SaveLayerStrategy SkPictureRecord::willSaveLayer(const SkRect* bounds,
                                                           const SkPaint* paint, SaveFlags flags) {
    // record the offset to us, making it non-positive to distinguish a save
    // from a clip entry.
    fRestoreOffsetStack.push(-(int32_t)fWriter.bytesWritten());
    this->recordSaveLayer(bounds, paint, flags);

    this->INHERITED::willSaveLayer(bounds, paint, flags);
>>>>>>> miniblink49
    /*  No need for a (potentially very big) layer which we don't actually need
        at this time (and may not be able to afford since during record our
        clip starts out the size of the picture, which is often much larger
        than the size of the actual device we'll use during playback).
     */
    return kNoLayer_SaveLayerStrategy;
}

<<<<<<< HEAD
void SkPictureRecord::recordSaveLayer(const SaveLayerRec& rec)
{
    fContentInfo.onSaveLayer();

    // op + flatflags
    size_t size = 2 * kUInt32Size;
    uint32_t flatFlags = 0;

    if (rec.fBounds) {
        flatFlags |= SAVELAYERREC_HAS_BOUNDS;
        size += sizeof(*rec.fBounds);
    }
    if (rec.fPaint) {
        flatFlags |= SAVELAYERREC_HAS_PAINT;
        size += sizeof(uint32_t); // index
    }
    if (rec.fBackdrop) {
        flatFlags |= SAVELAYERREC_HAS_BACKDROP;
        size += sizeof(uint32_t); // (paint) index
    }
    if (rec.fSaveLayerFlags) {
        flatFlags |= SAVELAYERREC_HAS_FLAGS;
        size += sizeof(uint32_t);
    }

    const size_t initialOffset = this->addDraw(SAVE_LAYER_SAVELAYERREC, &size);
    this->addInt(flatFlags);
    if (flatFlags & SAVELAYERREC_HAS_BOUNDS) {
        this->addRect(*rec.fBounds);
    }
    if (flatFlags & SAVELAYERREC_HAS_PAINT) {
        this->addPaintPtr(rec.fPaint);
    }
    if (flatFlags & SAVELAYERREC_HAS_BACKDROP) {
        // overkill, but we didn't already track single flattenables, so using a paint for that
        SkPaint paint;
        paint.setImageFilter(const_cast<SkImageFilter*>(rec.fBackdrop));
        this->addPaint(paint);
    }
    if (flatFlags & SAVELAYERREC_HAS_FLAGS) {
        this->addInt(rec.fSaveLayerFlags);
    }
=======
void SkPictureRecord::recordSaveLayer(const SkRect* bounds, const SkPaint* paint,
                                      SaveFlags flags) {
    fContentInfo.onSaveLayer();

    // op + bool for 'bounds'
    size_t size = 2 * kUInt32Size;
    if (bounds) {
        size += sizeof(*bounds); // + rect
    }
    // + paint index + flags
    size += 2 * kUInt32Size;

    SkASSERT(kSaveLayerNoBoundsSize == size || kSaveLayerWithBoundsSize == size);

    size_t initialOffset = this->addDraw(SAVE_LAYER, &size);
    this->addRectPtr(bounds);
    SkASSERT(initialOffset+get_paint_offset(SAVE_LAYER, size) == fWriter.bytesWritten());
    this->addPaintPtr(paint);
    this->addInt(flags);

>>>>>>> miniblink49
    this->validate(initialOffset, size);
}

#ifdef SK_DEBUG
/*
 * Read the op code from 'offset' in 'writer' and extract the size too.
 */
<<<<<<< HEAD
static DrawType peek_op_and_size(SkWriter32* writer, size_t offset, uint32_t* size)
{
=======
static DrawType peek_op_and_size(SkWriter32* writer, size_t offset, uint32_t* size) {
>>>>>>> miniblink49
    uint32_t peek = writer->readTAt<uint32_t>(offset);

    uint32_t op;
    UNPACK_8_24(peek, op, *size);
    if (MASK_24 == *size) {
        // size required its own slot right after the op code
        *size = writer->readTAt<uint32_t>(offset + kUInt32Size);
    }
<<<<<<< HEAD
    return (DrawType)op;
}
#endif //SK_DEBUG

void SkPictureRecord::willRestore()
{
=======
    return (DrawType) op;
}
#endif//SK_DEBUG

void SkPictureRecord::willRestore() {
    // FIXME: SkDeferredCanvas needs to be refactored to respect
    // save/restore balancing so that the following test can be
    // turned on permanently.
>>>>>>> miniblink49
#if 0
    SkASSERT(fRestoreOffsetStack.count() > 1);
#endif

    // check for underflow
    if (fRestoreOffsetStack.count() == 0) {
        return;
    }

    this->recordRestore();

    fRestoreOffsetStack.pop();

    this->INHERITED::willRestore();
}

<<<<<<< HEAD
void SkPictureRecord::recordRestore(bool fillInSkips)
{
=======
void SkPictureRecord::recordRestore(bool fillInSkips) {
>>>>>>> miniblink49
    fContentInfo.onRestore();

    if (fillInSkips) {
        this->fillRestoreOffsetPlaceholdersForCurrentStackLevel((uint32_t)fWriter.bytesWritten());
    }
    size_t size = 1 * kUInt32Size; // RESTORE consists solely of 1 op code
    size_t initialOffset = this->addDraw(RESTORE, &size);
    this->validate(initialOffset, size);
}

<<<<<<< HEAD
void SkPictureRecord::recordTranslate(const SkMatrix& m)
{
=======
void SkPictureRecord::recordTranslate(const SkMatrix& m) {
>>>>>>> miniblink49
    SkASSERT(SkMatrix::kTranslate_Mask == m.getType());

    // op + dx + dy
    size_t size = 1 * kUInt32Size + 2 * sizeof(SkScalar);
    size_t initialOffset = this->addDraw(TRANSLATE, &size);
    this->addScalar(m.getTranslateX());
    this->addScalar(m.getTranslateY());
    this->validate(initialOffset, size);
}

<<<<<<< HEAD
void SkPictureRecord::recordScale(const SkMatrix& m)
{
=======
void SkPictureRecord::recordScale(const SkMatrix& m) {
>>>>>>> miniblink49
    SkASSERT(SkMatrix::kScale_Mask == m.getType());

    // op + sx + sy
    size_t size = 1 * kUInt32Size + 2 * sizeof(SkScalar);
    size_t initialOffset = this->addDraw(SCALE, &size);
    this->addScalar(m.getScaleX());
    this->addScalar(m.getScaleY());
    this->validate(initialOffset, size);
}

<<<<<<< HEAD
void SkPictureRecord::didConcat(const SkMatrix& matrix)
{
    switch (matrix.getType()) {
    case SkMatrix::kTranslate_Mask:
        this->recordTranslate(matrix);
        break;
    case SkMatrix::kScale_Mask:
        this->recordScale(matrix);
        break;
    default:
        this->recordConcat(matrix);
        break;
=======
void SkPictureRecord::didConcat(const SkMatrix& matrix) {
    switch (matrix.getType()) {
        case SkMatrix::kTranslate_Mask:
            this->recordTranslate(matrix);
            break;
        case SkMatrix::kScale_Mask:
            this->recordScale(matrix);
            break;
        default:
            this->recordConcat(matrix);
            break;
>>>>>>> miniblink49
    }
    this->INHERITED::didConcat(matrix);
}

<<<<<<< HEAD
void SkPictureRecord::recordConcat(const SkMatrix& matrix)
{
    this->validate(fWriter.bytesWritten(), 0);
    // op + matrix
    size_t size = kUInt32Size + matrix.writeToMemory(nullptr);
=======
void SkPictureRecord::recordConcat(const SkMatrix& matrix) {
    this->validate(fWriter.bytesWritten(), 0);
    // op + matrix
    size_t size = kUInt32Size + matrix.writeToMemory(NULL);
>>>>>>> miniblink49
    size_t initialOffset = this->addDraw(CONCAT, &size);
    this->addMatrix(matrix);
    this->validate(initialOffset, size);
}

<<<<<<< HEAD
void SkPictureRecord::didSetMatrix(const SkMatrix& matrix)
{
    this->validate(fWriter.bytesWritten(), 0);
    // op + matrix
    size_t size = kUInt32Size + matrix.writeToMemory(nullptr);
=======
void SkPictureRecord::didSetMatrix(const SkMatrix& matrix) {
    this->validate(fWriter.bytesWritten(), 0);
    // op + matrix
    size_t size = kUInt32Size + matrix.writeToMemory(NULL);
>>>>>>> miniblink49
    size_t initialOffset = this->addDraw(SET_MATRIX, &size);
    this->addMatrix(matrix);
    this->validate(initialOffset, size);
    this->INHERITED::didSetMatrix(matrix);
}

<<<<<<< HEAD
static bool regionOpExpands(SkRegion::Op op)
{
    switch (op) {
    case SkRegion::kUnion_Op:
    case SkRegion::kXOR_Op:
    case SkRegion::kReverseDifference_Op:
    case SkRegion::kReplace_Op:
        return true;
    case SkRegion::kIntersect_Op:
    case SkRegion::kDifference_Op:
        return false;
    default:
        SkDEBUGFAIL("unknown region op");
        return false;
    }
}

void SkPictureRecord::fillRestoreOffsetPlaceholdersForCurrentStackLevel(uint32_t restoreOffset)
{
=======
static bool regionOpExpands(SkRegion::Op op) {
    switch (op) {
        case SkRegion::kUnion_Op:
        case SkRegion::kXOR_Op:
        case SkRegion::kReverseDifference_Op:
        case SkRegion::kReplace_Op:
            return true;
        case SkRegion::kIntersect_Op:
        case SkRegion::kDifference_Op:
            return false;
        default:
            SkDEBUGFAIL("unknown region op");
            return false;
    }
}

void SkPictureRecord::fillRestoreOffsetPlaceholdersForCurrentStackLevel(uint32_t restoreOffset) {
>>>>>>> miniblink49
    int32_t offset = fRestoreOffsetStack.top();
    while (offset > 0) {
        uint32_t peek = fWriter.readTAt<uint32_t>(offset);
        fWriter.overwriteTAt(offset, restoreOffset);
        offset = peek;
    }

#ifdef SK_DEBUG
    // offset of 0 has been disabled, so we skip it
    if (offset > 0) {
        // assert that the final offset value points to a save verb
        uint32_t opSize;
        DrawType drawOp = peek_op_and_size(&fWriter, -offset, &opSize);
<<<<<<< HEAD
        SkASSERT(SAVE_LAYER_SAVEFLAGS_DEPRECATED != drawOp);
        SkASSERT(SAVE_LAYER_SAVELAYERFLAGS_DEPRECATED_JAN_2016 != drawOp);
        SkASSERT(SAVE == drawOp || SAVE_LAYER_SAVELAYERREC == drawOp);
=======
        SkASSERT(SAVE == drawOp || SAVE_LAYER == drawOp);
>>>>>>> miniblink49
    }
#endif
}

<<<<<<< HEAD
void SkPictureRecord::beginRecording()
{
=======
void SkPictureRecord::beginRecording() {
>>>>>>> miniblink49
    // we have to call this *after* our constructor, to ensure that it gets
    // recorded. This is balanced by restoreToCount() call from endRecording,
    // which in-turn calls our overridden restore(), so those get recorded too.
    fInitialSaveCount = this->save();
}

<<<<<<< HEAD
void SkPictureRecord::endRecording()
{
=======
void SkPictureRecord::endRecording() {
>>>>>>> miniblink49
    SkASSERT(kNoInitialSave != fInitialSaveCount);
    this->restoreToCount(fInitialSaveCount);
}

<<<<<<< HEAD
size_t SkPictureRecord::recordRestoreOffsetPlaceholder(SkRegion::Op op)
{
=======
size_t SkPictureRecord::recordRestoreOffsetPlaceholder(SkRegion::Op op) {
>>>>>>> miniblink49
    if (fRestoreOffsetStack.isEmpty()) {
        return -1;
    }

    // The RestoreOffset field is initially filled with a placeholder
    // value that points to the offset of the previous RestoreOffset
    // in the current stack level, thus forming a linked list so that
    // the restore offsets can be filled in when the corresponding
    // restore command is recorded.
    int32_t prevOffset = fRestoreOffsetStack.top();

    if (regionOpExpands(op)) {
        // Run back through any previous clip ops, and mark their offset to
        // be 0, disabling their ability to trigger a jump-to-restore, otherwise
        // they could hide this clips ability to expand the clip (i.e. go from
        // empty to non-empty).
        this->fillRestoreOffsetPlaceholdersForCurrentStackLevel(0);

        // Reset the pointer back to the previous clip so that subsequent
        // restores don't overwrite the offsets we just cleared.
        prevOffset = 0;
    }

    size_t offset = fWriter.bytesWritten();
    this->addInt(prevOffset);
    fRestoreOffsetStack.top() = SkToU32(offset);
    return offset;
}

<<<<<<< HEAD
void SkPictureRecord::onClipRect(const SkRect& rect, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkPictureRecord::onClipRect(const SkRect& rect, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    this->recordClipRect(rect, op, kSoft_ClipEdgeStyle == edgeStyle);
    this->INHERITED::onClipRect(rect, op, edgeStyle);
}

<<<<<<< HEAD
size_t SkPictureRecord::recordClipRect(const SkRect& rect, SkRegion::Op op, bool doAA)
{
=======
size_t SkPictureRecord::recordClipRect(const SkRect& rect, SkRegion::Op op, bool doAA) {
>>>>>>> miniblink49
    // id + rect + clip params
    size_t size = 1 * kUInt32Size + sizeof(rect) + 1 * kUInt32Size;
    // recordRestoreOffsetPlaceholder doesn't always write an offset
    if (!fRestoreOffsetStack.isEmpty()) {
        // + restore offset
        size += kUInt32Size;
    }
    size_t initialOffset = this->addDraw(CLIP_RECT, &size);
    this->addRect(rect);
    this->addInt(ClipParams_pack(op, doAA));
    size_t offset = this->recordRestoreOffsetPlaceholder(op);

    this->validate(initialOffset, size);
    return offset;
}

<<<<<<< HEAD
void SkPictureRecord::onClipRRect(const SkRRect& rrect, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkPictureRecord::onClipRRect(const SkRRect& rrect, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    this->recordClipRRect(rrect, op, kSoft_ClipEdgeStyle == edgeStyle);
    this->INHERITED::onClipRRect(rrect, op, edgeStyle);
}

<<<<<<< HEAD
size_t SkPictureRecord::recordClipRRect(const SkRRect& rrect, SkRegion::Op op, bool doAA)
{
=======
size_t SkPictureRecord::recordClipRRect(const SkRRect& rrect, SkRegion::Op op, bool doAA) {
>>>>>>> miniblink49
    // op + rrect + clip params
    size_t size = 1 * kUInt32Size + SkRRect::kSizeInMemory + 1 * kUInt32Size;
    // recordRestoreOffsetPlaceholder doesn't always write an offset
    if (!fRestoreOffsetStack.isEmpty()) {
        // + restore offset
        size += kUInt32Size;
    }
    size_t initialOffset = this->addDraw(CLIP_RRECT, &size);
    this->addRRect(rrect);
    this->addInt(ClipParams_pack(op, doAA));
    size_t offset = recordRestoreOffsetPlaceholder(op);
    this->validate(initialOffset, size);
    return offset;
}

<<<<<<< HEAD
void SkPictureRecord::onClipPath(const SkPath& path, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkPictureRecord::onClipPath(const SkPath& path, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    int pathID = this->addPathToHeap(path);
    this->recordClipPath(pathID, op, kSoft_ClipEdgeStyle == edgeStyle);
    this->INHERITED::onClipPath(path, op, edgeStyle);
}

<<<<<<< HEAD
size_t SkPictureRecord::recordClipPath(int pathID, SkRegion::Op op, bool doAA)
{
=======
size_t SkPictureRecord::recordClipPath(int pathID, SkRegion::Op op, bool doAA) {
>>>>>>> miniblink49
    // op + path index + clip params
    size_t size = 3 * kUInt32Size;
    // recordRestoreOffsetPlaceholder doesn't always write an offset
    if (!fRestoreOffsetStack.isEmpty()) {
        // + restore offset
        size += kUInt32Size;
    }
    size_t initialOffset = this->addDraw(CLIP_PATH, &size);
    this->addInt(pathID);
    this->addInt(ClipParams_pack(op, doAA));
    size_t offset = recordRestoreOffsetPlaceholder(op);
    this->validate(initialOffset, size);
    return offset;
}

<<<<<<< HEAD
void SkPictureRecord::onClipRegion(const SkRegion& region, SkRegion::Op op)
{
=======
void SkPictureRecord::onClipRegion(const SkRegion& region, SkRegion::Op op) {
>>>>>>> miniblink49
    this->recordClipRegion(region, op);
    this->INHERITED::onClipRegion(region, op);
}

<<<<<<< HEAD
size_t SkPictureRecord::recordClipRegion(const SkRegion& region, SkRegion::Op op)
{
    // op + clip params + region
    size_t size = 2 * kUInt32Size + region.writeToMemory(nullptr);
=======
size_t SkPictureRecord::recordClipRegion(const SkRegion& region, SkRegion::Op op) {
    // op + clip params + region
    size_t size = 2 * kUInt32Size + region.writeToMemory(NULL);
>>>>>>> miniblink49
    // recordRestoreOffsetPlaceholder doesn't always write an offset
    if (!fRestoreOffsetStack.isEmpty()) {
        // + restore offset
        size += kUInt32Size;
    }
    size_t initialOffset = this->addDraw(CLIP_REGION, &size);
    this->addRegion(region);
    this->addInt(ClipParams_pack(op, false));
    size_t offset = this->recordRestoreOffsetPlaceholder(op);

    this->validate(initialOffset, size);
    return offset;
}

<<<<<<< HEAD
void SkPictureRecord::onDrawPaint(const SkPaint& paint)
{
    // op + paint index
    size_t size = 2 * kUInt32Size;
    size_t initialOffset = this->addDraw(DRAW_PAINT, &size);
=======
void SkPictureRecord::onDrawPaint(const SkPaint& paint) {
    // op + paint index
    size_t size = 2 * kUInt32Size;
    size_t initialOffset = this->addDraw(DRAW_PAINT, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_PAINT, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawPoints(PointMode mode, size_t count, const SkPoint pts[],
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                                   const SkPaint& paint) {
>>>>>>> miniblink49
    fContentInfo.onDrawPoints(count, paint);

    // op + paint index + mode + count + point data
    size_t size = 4 * kUInt32Size + count * sizeof(SkPoint);
    size_t initialOffset = this->addDraw(DRAW_POINTS, &size);
<<<<<<< HEAD
=======
    SkASSERT(initialOffset+get_paint_offset(DRAW_POINTS, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);

    this->addInt(mode);
    this->addInt(SkToInt(count));
    fWriter.writeMul4(pts, count * sizeof(SkPoint));
    this->validate(initialOffset, size);
}

<<<<<<< HEAD
void SkPictureRecord::onDrawOval(const SkRect& oval, const SkPaint& paint)
{
    // op + paint index + rect
    size_t size = 2 * kUInt32Size + sizeof(oval);
    size_t initialOffset = this->addDraw(DRAW_OVAL, &size);
=======
void SkPictureRecord::onDrawOval(const SkRect& oval, const SkPaint& paint) {
    // op + paint index + rect
    size_t size = 2 * kUInt32Size + sizeof(oval);
    size_t initialOffset = this->addDraw(DRAW_OVAL, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_OVAL, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);
    this->addRect(oval);
    this->validate(initialOffset, size);
}

<<<<<<< HEAD
void SkPictureRecord::onDrawRect(const SkRect& rect, const SkPaint& paint)
{
    // op + paint index + rect
    size_t size = 2 * kUInt32Size + sizeof(rect);
    size_t initialOffset = this->addDraw(DRAW_RECT, &size);
=======
void SkPictureRecord::onDrawRect(const SkRect& rect, const SkPaint& paint) {
    // op + paint index + rect
    size_t size = 2 * kUInt32Size + sizeof(rect);
    size_t initialOffset = this->addDraw(DRAW_RECT, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_RECT, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);
    this->addRect(rect);
    this->validate(initialOffset, size);
}

<<<<<<< HEAD
void SkPictureRecord::onDrawRRect(const SkRRect& rrect, const SkPaint& paint)
{
    // op + paint index + rrect
    size_t size = 2 * kUInt32Size + SkRRect::kSizeInMemory;
    size_t initialOffset = this->addDraw(DRAW_RRECT, &size);
=======
void SkPictureRecord::onDrawRRect(const SkRRect& rrect, const SkPaint& paint) {
    // op + paint index + rrect
    size_t size = 2 * kUInt32Size + SkRRect::kSizeInMemory;
    size_t initialOffset = this->addDraw(DRAW_RRECT, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_RRECT, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);
    this->addRRect(rrect);
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawDRRect(const SkRRect& outer, const SkRRect& inner,
<<<<<<< HEAD
    const SkPaint& paint)
{
    // op + paint index + rrects
    size_t size = 2 * kUInt32Size + SkRRect::kSizeInMemory * 2;
    size_t initialOffset = this->addDraw(DRAW_DRRECT, &size);
=======
                                   const SkPaint& paint) {
    // op + paint index + rrects
    size_t size = 2 * kUInt32Size + SkRRect::kSizeInMemory * 2;
    size_t initialOffset = this->addDraw(DRAW_DRRECT, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_DRRECT, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);
    this->addRRect(outer);
    this->addRRect(inner);
    this->validate(initialOffset, size);
}

<<<<<<< HEAD
void SkPictureRecord::onDrawPath(const SkPath& path, const SkPaint& paint)
{
=======
void SkPictureRecord::onDrawPath(const SkPath& path, const SkPaint& paint) {
>>>>>>> miniblink49
    fContentInfo.onDrawPath(path, paint);

    // op + paint index + path index
    size_t size = 3 * kUInt32Size;
    size_t initialOffset = this->addDraw(DRAW_PATH, &size);
<<<<<<< HEAD
=======
    SkASSERT(initialOffset+get_paint_offset(DRAW_PATH, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);
    this->addPath(path);
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawBitmap(const SkBitmap& bitmap, SkScalar left, SkScalar top,
<<<<<<< HEAD
    const SkPaint* paint)
{
    // op + paint index + bitmap index + left + top
    size_t size = 3 * kUInt32Size + 2 * sizeof(SkScalar);
    size_t initialOffset = this->addDraw(DRAW_BITMAP, &size);
=======
                                   const SkPaint* paint) {
    // op + paint index + bitmap index + left + top
    size_t size = 3 * kUInt32Size + 2 * sizeof(SkScalar);
    size_t initialOffset = this->addDraw(DRAW_BITMAP, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_BITMAP, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaintPtr(paint);
    this->addBitmap(bitmap);
    this->addScalar(left);
    this->addScalar(top);
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawBitmapRect(const SkBitmap& bitmap, const SkRect* src, const SkRect& dst,
<<<<<<< HEAD
    const SkPaint* paint, SrcRectConstraint constraint)
{
    // id + paint index + bitmap index + bool for 'src' + flags
    size_t size = 5 * kUInt32Size;
    if (src) {
        size += sizeof(*src); // + rect
    }
    size += sizeof(dst); // + rect

    size_t initialOffset = this->addDraw(DRAW_BITMAP_RECT, &size);
    this->addPaintPtr(paint);
    this->addBitmap(bitmap);
    this->addRectPtr(src); // may be null
    this->addRect(dst);
    this->addInt(constraint);
=======
                                       const SkPaint* paint, DrawBitmapRectFlags flags) {
    // id + paint index + bitmap index + bool for 'src' + flags
    size_t size = 5 * kUInt32Size;
    if (src) {
        size += sizeof(*src);   // + rect
    }
    size += sizeof(dst);        // + rect

    size_t initialOffset = this->addDraw(DRAW_BITMAP_RECT_TO_RECT, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_BITMAP_RECT_TO_RECT, size)
             == fWriter.bytesWritten());
    this->addPaintPtr(paint);
    this->addBitmap(bitmap);
    this->addRectPtr(src);  // may be null
    this->addRect(dst);
    this->addInt(flags);
>>>>>>> miniblink49
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawImage(const SkImage* image, SkScalar x, SkScalar y,
<<<<<<< HEAD
    const SkPaint* paint)
{
    // op + paint_index + image_index + x + y
    size_t size = 3 * kUInt32Size + 2 * sizeof(SkScalar);
    size_t initialOffset = this->addDraw(DRAW_IMAGE, &size);
=======
                                  const SkPaint* paint) {
    // op + paint_index + image_index + x + y
    size_t size = 3 * kUInt32Size + 2 * sizeof(SkScalar);
    size_t initialOffset = this->addDraw(DRAW_IMAGE, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_IMAGE, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaintPtr(paint);
    this->addImage(image);
    this->addScalar(x);
    this->addScalar(y);
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawImageRect(const SkImage* image, const SkRect* src, const SkRect& dst,
<<<<<<< HEAD
    const SkPaint* paint, SrcRectConstraint constraint)
{
    // id + paint_index + image_index + bool_for_src + constraint
    size_t size = 5 * kUInt32Size;
    if (src) {
        size += sizeof(*src); // + rect
    }
    size += sizeof(dst); // + rect

    size_t initialOffset = this->addDraw(DRAW_IMAGE_RECT, &size);
    this->addPaintPtr(paint);
    this->addImage(image);
    this->addRectPtr(src); // may be null
    this->addRect(dst);
    this->addInt(constraint);
=======
                                      const SkPaint* paint) {
    // id + paint_index + image_index + bool_for_src
    size_t size = 4 * kUInt32Size;
    if (src) {
        size += sizeof(*src);   // + rect
    }
    size += sizeof(dst);        // + rect
    
    size_t initialOffset = this->addDraw(DRAW_IMAGE_RECT, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_IMAGE_RECT, size)
             == fWriter.bytesWritten());
    this->addPaintPtr(paint);
    this->addImage(image);
    this->addRectPtr(src);  // may be null
    this->addRect(dst);
>>>>>>> miniblink49
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawImageNine(const SkImage* img, const SkIRect& center, const SkRect& dst,
<<<<<<< HEAD
    const SkPaint* paint)
{
    // id + paint_index + image_index + center + dst
    size_t size = 3 * kUInt32Size + sizeof(SkIRect) + sizeof(SkRect);

    size_t initialOffset = this->addDraw(DRAW_IMAGE_NINE, &size);
=======
                                      const SkPaint* paint) {
    // id + paint_index + image_index + center + dst
    size_t size = 3 * kUInt32Size + sizeof(SkIRect) + sizeof(SkRect);
    
    size_t initialOffset = this->addDraw(DRAW_IMAGE_NINE, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_IMAGE_NINE, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaintPtr(paint);
    this->addImage(img);
    this->addIRect(center);
    this->addRect(dst);
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawBitmapNine(const SkBitmap& bitmap, const SkIRect& center,
<<<<<<< HEAD
    const SkRect& dst, const SkPaint* paint)
{
    // op + paint index + bitmap id + center + dst rect
    size_t size = 3 * kUInt32Size + sizeof(center) + sizeof(dst);
    size_t initialOffset = this->addDraw(DRAW_BITMAP_NINE, &size);
=======
                                       const SkRect& dst, const SkPaint* paint) {
    // op + paint index + bitmap id + center + dst rect
    size_t size = 3 * kUInt32Size + sizeof(center) + sizeof(dst);
    size_t initialOffset = this->addDraw(DRAW_BITMAP_NINE, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_BITMAP_NINE, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaintPtr(paint);
    this->addBitmap(bitmap);
    this->addIRect(center);
    this->addRect(dst);
    this->validate(initialOffset, size);
}

<<<<<<< HEAD
void SkPictureRecord::onDrawText(const void* text, size_t byteLength, SkScalar x, SkScalar y,
    const SkPaint& paint)
{
=======
void SkPictureRecord::onDrawSprite(const SkBitmap& bitmap, int left, int top,
                                   const SkPaint* paint) {
    // op + paint index + bitmap index + left + top
    size_t size = 5 * kUInt32Size;
    size_t initialOffset = this->addDraw(DRAW_SPRITE, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_SPRITE, size) == fWriter.bytesWritten());
    this->addPaintPtr(paint);
    this->addBitmap(bitmap);
    this->addInt(left);
    this->addInt(top);
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawText(const void* text, size_t byteLength, SkScalar x, SkScalar y,
                                 const SkPaint& paint) {
>>>>>>> miniblink49
    // op + paint index + length + 'length' worth of chars + x + y
    size_t size = 3 * kUInt32Size + SkAlign4(byteLength) + 2 * sizeof(SkScalar);

    DrawType op = DRAW_TEXT;
    size_t initialOffset = this->addDraw(op, &size);
<<<<<<< HEAD
=======
    SkASSERT(initialOffset+get_paint_offset(op, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);
    this->addText(text, byteLength);
    this->addScalar(x);
    this->addScalar(y);
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawPosText(const void* text, size_t byteLength, const SkPoint pos[],
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                                    const SkPaint& paint) {
>>>>>>> miniblink49
    int points = paint.countText(text, byteLength);

    // op + paint index + length + 'length' worth of data + num points + x&y point data
    size_t size = 3 * kUInt32Size + SkAlign4(byteLength) + kUInt32Size + points * sizeof(SkPoint);

    DrawType op = DRAW_POS_TEXT;

    size_t initialOffset = this->addDraw(op, &size);
<<<<<<< HEAD
=======
    SkASSERT(initialOffset+get_paint_offset(op, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);
    this->addText(text, byteLength);
    this->addInt(points);
    fWriter.writeMul4(pos, points * sizeof(SkPoint));
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawPosTextH(const void* text, size_t byteLength, const SkScalar xpos[],
<<<<<<< HEAD
    SkScalar constY, const SkPaint& paint)
{
=======
                                     SkScalar constY, const SkPaint& paint) {
>>>>>>> miniblink49
    int points = paint.countText(text, byteLength);

    // op + paint index + length + 'length' worth of data + num points
    size_t size = 3 * kUInt32Size + SkAlign4(byteLength) + 1 * kUInt32Size;
    // + y + the actual points
    size += 1 * kUInt32Size + points * sizeof(SkScalar);

    size_t initialOffset = this->addDraw(DRAW_POS_TEXT_H, &size);
    this->addPaint(paint);
    this->addText(text, byteLength);
    this->addInt(points);
    this->addScalar(constY);
    fWriter.writeMul4(xpos, points * sizeof(SkScalar));
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawTextOnPath(const void* text, size_t byteLength, const SkPath& path,
<<<<<<< HEAD
    const SkMatrix* matrix, const SkPaint& paint)
{
    // op + paint index + length + 'length' worth of data + path index + matrix
    const SkMatrix& m = matrix ? *matrix : SkMatrix::I();
    size_t size = 3 * kUInt32Size + SkAlign4(byteLength) + kUInt32Size + m.writeToMemory(nullptr);
    size_t initialOffset = this->addDraw(DRAW_TEXT_ON_PATH, &size);
=======
                                       const SkMatrix* matrix, const SkPaint& paint) {
    // op + paint index + length + 'length' worth of data + path index + matrix
    const SkMatrix& m = matrix ? *matrix : SkMatrix::I();
    size_t size = 3 * kUInt32Size + SkAlign4(byteLength) + kUInt32Size + m.writeToMemory(NULL);
    size_t initialOffset = this->addDraw(DRAW_TEXT_ON_PATH, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_TEXT_ON_PATH, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);
    this->addText(text, byteLength);
    this->addPath(path);
    this->addMatrix(m);
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawTextBlob(const SkTextBlob* blob, SkScalar x, SkScalar y,
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                                     const SkPaint& paint) {
>>>>>>> miniblink49

    // op + paint index + blob index + x/y
    size_t size = 3 * kUInt32Size + 2 * sizeof(SkScalar);
    size_t initialOffset = this->addDraw(DRAW_TEXT_BLOB, &size);
<<<<<<< HEAD
=======
    SkASSERT(initialOffset + get_paint_offset(DRAW_TEXT_BLOB, size) == fWriter.bytesWritten());
>>>>>>> miniblink49

    this->addPaint(paint);
    this->addTextBlob(blob);
    this->addScalar(x);
    this->addScalar(y);

    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawPicture(const SkPicture* picture, const SkMatrix* matrix,
<<<<<<< HEAD
    const SkPaint* paint)
{
=======
                                    const SkPaint* paint) {
>>>>>>> miniblink49
    // op + picture index
    size_t size = 2 * kUInt32Size;
    size_t initialOffset;

<<<<<<< HEAD
    if (nullptr == matrix && nullptr == paint) {
=======
    if (NULL == matrix && NULL == paint) {
>>>>>>> miniblink49
        initialOffset = this->addDraw(DRAW_PICTURE, &size);
        this->addPicture(picture);
    } else {
        const SkMatrix& m = matrix ? *matrix : SkMatrix::I();
<<<<<<< HEAD
        size += m.writeToMemory(nullptr) + kUInt32Size; // matrix + paint
        initialOffset = this->addDraw(DRAW_PICTURE_MATRIX_PAINT, &size);
=======
        size += m.writeToMemory(NULL) + kUInt32Size;    // matrix + paint
        initialOffset = this->addDraw(DRAW_PICTURE_MATRIX_PAINT, &size);
        SkASSERT(initialOffset + get_paint_offset(DRAW_PICTURE_MATRIX_PAINT, size)
                 == fWriter.bytesWritten());
>>>>>>> miniblink49
        this->addPaintPtr(paint);
        this->addMatrix(m);
        this->addPicture(picture);
    }
    this->validate(initialOffset, size);
}

<<<<<<< HEAD
void SkPictureRecord::onDrawDrawable(SkDrawable* drawable, const SkMatrix* matrix)
{
    // op + drawable index
    size_t size = 2 * kUInt32Size;
    size_t initialOffset;

    if (nullptr == matrix) {
        initialOffset = this->addDraw(DRAW_DRAWABLE, &size);
        this->addDrawable(drawable);
    } else {
        size += matrix->writeToMemory(nullptr); // matrix
        initialOffset = this->addDraw(DRAW_DRAWABLE_MATRIX, &size);
        this->addMatrix(*matrix);
        this->addDrawable(drawable);
    }
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawVertices(VertexMode vmode, int vertexCount,
    const SkPoint vertices[], const SkPoint texs[],
    const SkColor colors[], SkXfermode* xfer,
    const uint16_t indices[], int indexCount,
    const SkPaint& paint)
{
=======
void SkPictureRecord::onDrawVertices(VertexMode vmode, int vertexCount,
                                     const SkPoint vertices[], const SkPoint texs[],
                                     const SkColor colors[], SkXfermode* xfer,
                                     const uint16_t indices[], int indexCount,
                                     const SkPaint& paint) {
>>>>>>> miniblink49
    uint32_t flags = 0;
    if (texs) {
        flags |= DRAW_VERTICES_HAS_TEXS;
    }
    if (colors) {
        flags |= DRAW_VERTICES_HAS_COLORS;
    }
    if (indexCount > 0) {
        flags |= DRAW_VERTICES_HAS_INDICES;
    }
    if (xfer) {
        SkXfermode::Mode mode;
        if (xfer->asMode(&mode) && SkXfermode::kModulate_Mode != mode) {
            flags |= DRAW_VERTICES_HAS_XFER;
        }
    }

    // op + paint index + flags + vmode + vCount + vertices
    size_t size = 5 * kUInt32Size + vertexCount * sizeof(SkPoint);
    if (flags & DRAW_VERTICES_HAS_TEXS) {
<<<<<<< HEAD
        size += vertexCount * sizeof(SkPoint); // + uvs
    }
    if (flags & DRAW_VERTICES_HAS_COLORS) {
        size += vertexCount * sizeof(SkColor); // + vert colors
=======
        size += vertexCount * sizeof(SkPoint);  // + uvs
    }
    if (flags & DRAW_VERTICES_HAS_COLORS) {
        size += vertexCount * sizeof(SkColor);  // + vert colors
>>>>>>> miniblink49
    }
    if (flags & DRAW_VERTICES_HAS_INDICES) {
        // + num indices + indices
        size += 1 * kUInt32Size + SkAlign4(indexCount * sizeof(uint16_t));
    }
    if (flags & DRAW_VERTICES_HAS_XFER) {
<<<<<<< HEAD
        size += kUInt32Size; // mode enum
    }

    size_t initialOffset = this->addDraw(DRAW_VERTICES, &size);
=======
        size += kUInt32Size;    // mode enum
    }

    size_t initialOffset = this->addDraw(DRAW_VERTICES, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_VERTICES, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);
    this->addInt(flags);
    this->addInt(vmode);
    this->addInt(vertexCount);
    this->addPoints(vertices, vertexCount);
    if (flags & DRAW_VERTICES_HAS_TEXS) {
        this->addPoints(texs, vertexCount);
    }
    if (flags & DRAW_VERTICES_HAS_COLORS) {
        fWriter.writeMul4(colors, vertexCount * sizeof(SkColor));
    }
    if (flags & DRAW_VERTICES_HAS_INDICES) {
        this->addInt(indexCount);
        fWriter.writePad(indices, indexCount * sizeof(uint16_t));
    }
    if (flags & DRAW_VERTICES_HAS_XFER) {
        SkXfermode::Mode mode = SkXfermode::kModulate_Mode;
        (void)xfer->asMode(&mode);
        this->addInt(mode);
    }
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawPatch(const SkPoint cubics[12], const SkColor colors[4],
<<<<<<< HEAD
    const SkPoint texCoords[4], SkXfermode* xmode,
    const SkPaint& paint)
{
=======
                                  const SkPoint texCoords[4], SkXfermode* xmode,
                                  const SkPaint& paint) {
>>>>>>> miniblink49
    // op + paint index + patch 12 control points + flag + patch 4 colors + 4 texture coordinates
    size_t size = 2 * kUInt32Size + SkPatchUtils::kNumCtrlPts * sizeof(SkPoint) + kUInt32Size;
    uint32_t flag = 0;
    if (colors) {
        flag |= DRAW_VERTICES_HAS_COLORS;
        size += SkPatchUtils::kNumCorners * sizeof(SkColor);
    }
    if (texCoords) {
        flag |= DRAW_VERTICES_HAS_TEXS;
        size += SkPatchUtils::kNumCorners * sizeof(SkPoint);
    }
    if (xmode) {
        SkXfermode::Mode mode;
        if (xmode->asMode(&mode) && SkXfermode::kModulate_Mode != mode) {
            flag |= DRAW_VERTICES_HAS_XFER;
            size += kUInt32Size;
        }
    }

    size_t initialOffset = this->addDraw(DRAW_PATCH, &size);
<<<<<<< HEAD
=======
    SkASSERT(initialOffset+get_paint_offset(DRAW_PATCH, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaint(paint);
    this->addPatch(cubics);
    this->addInt(flag);

    // write optional parameters
    if (colors) {
        fWriter.write(colors, SkPatchUtils::kNumCorners * sizeof(SkColor));
    }
    if (texCoords) {
        fWriter.write(texCoords, SkPatchUtils::kNumCorners * sizeof(SkPoint));
    }
    if (flag & DRAW_VERTICES_HAS_XFER) {
        SkXfermode::Mode mode = SkXfermode::kModulate_Mode;
        xmode->asMode(&mode);
        this->addInt(mode);
    }
    this->validate(initialOffset, size);
}

void SkPictureRecord::onDrawAtlas(const SkImage* atlas, const SkRSXform xform[], const SkRect tex[],
<<<<<<< HEAD
    const SkColor colors[], int count, SkXfermode::Mode mode,
    const SkRect* cull, const SkPaint* paint)
{
=======
                                  const SkColor colors[], int count, SkXfermode::Mode mode,
                                  const SkRect* cull, const SkPaint* paint) {
>>>>>>> miniblink49
    // [op + paint-index + atlas-index + flags + count] + [xform] + [tex] + [*colors + mode] + cull
    size_t size = 5 * kUInt32Size + count * sizeof(SkRSXform) + count * sizeof(SkRect);
    uint32_t flags = 0;
    if (colors) {
        flags |= DRAW_ATLAS_HAS_COLORS;
        size += count * sizeof(SkColor);
<<<<<<< HEAD
        size += sizeof(uint32_t); // xfermode::mode
=======
        size += sizeof(uint32_t);   // xfermode::mode
>>>>>>> miniblink49
    }
    if (cull) {
        flags |= DRAW_ATLAS_HAS_CULL;
        size += sizeof(SkRect);
    }
<<<<<<< HEAD

    size_t initialOffset = this->addDraw(DRAW_ATLAS, &size);
=======
    
    size_t initialOffset = this->addDraw(DRAW_ATLAS, &size);
    SkASSERT(initialOffset+get_paint_offset(DRAW_ATLAS, size) == fWriter.bytesWritten());
>>>>>>> miniblink49
    this->addPaintPtr(paint);
    this->addImage(atlas);
    this->addInt(flags);
    this->addInt(count);
    fWriter.write(xform, count * sizeof(SkRSXform));
    fWriter.write(tex, count * sizeof(SkRect));

    // write optional parameters
    if (colors) {
        fWriter.write(colors, count * sizeof(SkColor));
        this->addInt(mode);
    }
    if (cull) {
        fWriter.write(cull, sizeof(SkRect));
    }
    this->validate(initialOffset, size);
}

<<<<<<< HEAD
void SkPictureRecord::onDrawAnnotation(const SkRect& rect, const char key[], SkData* value)
{
    size_t keyLen = fWriter.WriteStringSize(key);
    size_t valueLen = fWriter.WriteDataSize(value);
    size_t size = 4 + sizeof(SkRect) + keyLen + valueLen;

    size_t initialOffset = this->addDraw(DRAW_ANNOTATION, &size);
    this->addRect(rect);
    fWriter.writeString(key);
    fWriter.writeData(value);
    this->validate(initialOffset, size);
}

///////////////////////////////////////////////////////////////////////////////

sk_sp<SkSurface> SkPictureRecord::onNewSurface(const SkImageInfo& info, const SkSurfaceProps&)
{
    return nullptr;
}

// If we already have a stored, can we reuse it instead of also storing b?
static bool equivalent(const SkBitmap& a, const SkBitmap& b)
{
=======
///////////////////////////////////////////////////////////////////////////////

SkSurface* SkPictureRecord::onNewSurface(const SkImageInfo& info, const SkSurfaceProps&) {
    return NULL;
}

// If we already have a stored, can we reuse it instead of also storing b?
static bool equivalent(const SkBitmap& a, const SkBitmap& b) {
>>>>>>> miniblink49
    if (a.info() != b.info() || a.pixelRefOrigin() != b.pixelRefOrigin()) {
        // Requiring a.info() == b.info() may be overkill in some cases (alphatype mismatch),
        // but it sure makes things easier to reason about below.
        return false;
    }
    if (a.pixelRef() == b.pixelRef()) {
<<<<<<< HEAD
        return true; // Same shape and same pixels -> same bitmap.
=======
        return true;  // Same shape and same pixels -> same bitmap.
>>>>>>> miniblink49
    }

    // From here down we're going to have to look at the bitmap data, so we require pixelRefs().
    if (!a.pixelRef() || !b.pixelRef()) {
        return false;
    }

    // If the bitmaps have encoded data, check first before locking pixels so they don't decode.
    SkAutoTUnref<SkData> encA(a.pixelRef()->refEncodedData()),
<<<<<<< HEAD
        encB(b.pixelRef()->refEncodedData());
    if (encA && encB) {
        return encA->equals(encB);
    } else if (encA || encB) {
        return false; // One has encoded data but the other does not.
=======
                         encB(b.pixelRef()->refEncodedData());
    if (encA && encB) {
        return encA->equals(encB);
    } else if (encA || encB) {
        return false;   // One has encoded data but the other does not.
>>>>>>> miniblink49
    }

    // As a last resort, we have to look at the pixels.  This will read back textures.
    SkAutoLockPixels al(a), bl(b);
    const char* ap = (const char*)a.getPixels();
    const char* bp = (const char*)b.getPixels();
    if (ap && bp) {
        // We check row by row; row bytes might differ.
<<<<<<< HEAD
        SkASSERT(a.info() == b.info()); // We checked this above.
        SkASSERT(a.info().bytesPerPixel() > 0); // If we have pixelRefs, this better be true.
=======
        SkASSERT(a.info() == b.info());          // We checked this above.
        SkASSERT(a.info().bytesPerPixel() > 0);  // If we have pixelRefs, this better be true.
>>>>>>> miniblink49
        const SkImageInfo info = a.info();
        const size_t bytesToCompare = info.width() * info.bytesPerPixel();
        for (int row = 0; row < info.height(); row++) {
            if (0 != memcmp(ap, bp, bytesToCompare)) {
                return false;
            }
            ap += a.rowBytes();
            bp += b.rowBytes();
        }
        return true;
    }
<<<<<<< HEAD
    return false; // Couldn't get pixels for both bitmaps.
}

void SkPictureRecord::addBitmap(const SkBitmap& bitmap)
{
=======
    return false;  // Couldn't get pixels for both bitmaps.
}

void SkPictureRecord::addBitmap(const SkBitmap& bitmap) {
>>>>>>> miniblink49
    // First see if we already have this bitmap.  This deduplication should really
    // only be important for our tests, where bitmaps tend not to be tagged immutable.
    // In Chrome (and hopefully Android?) they're typically immutable.
    for (int i = 0; i < fBitmaps.count(); i++) {
        if (equivalent(fBitmaps[i], bitmap)) {
<<<<<<< HEAD
            this->addInt(i); // Unlike the rest, bitmap indices are 0-based.
=======
            this->addInt(i);  // Unlike the rest, bitmap indices are 0-based.
>>>>>>> miniblink49
            return;
        }
    }
    // Don't have it.  We'll add it to our list, making sure it's tagged as immutable.
    if (bitmap.isImmutable()) {
        // Shallow copies of bitmaps are cheap, so immutable == fast.
        fBitmaps.push_back(bitmap);
    } else {
        // If you see this block on a memory profile, it's a good opportunity to reduce RAM usage.
        SkBitmap copy;
        bitmap.copyTo(&copy);
        copy.setImmutable();
        fBitmaps.push_back(copy);
    }
<<<<<<< HEAD
    this->addInt(fBitmaps.count() - 1); // Remember, 0-based.
}

void SkPictureRecord::addImage(const SkImage* image)
{
=======
    this->addInt(fBitmaps.count()-1);  // Remember, 0-based.
}

void SkPictureRecord::addImage(const SkImage* image) {
>>>>>>> miniblink49
    int index = fImageRefs.find(image);
    if (index >= 0) {
        this->addInt(index);
    } else {
        *fImageRefs.append() = SkRef(image);
<<<<<<< HEAD
        this->addInt(fImageRefs.count() - 1);
    }
}

void SkPictureRecord::addMatrix(const SkMatrix& matrix)
{
    fWriter.writeMatrix(matrix);
}

void SkPictureRecord::addPaintPtr(const SkPaint* paint)
{
=======
        this->addInt(fImageRefs.count()-1);
    }
}

void SkPictureRecord::addMatrix(const SkMatrix& matrix) {
    fWriter.writeMatrix(matrix);
}

void SkPictureRecord::addPaintPtr(const SkPaint* paint) {
>>>>>>> miniblink49
    fContentInfo.onAddPaintPtr(paint);

    if (paint) {
        fPaints.push_back(*paint);
        this->addInt(fPaints.count());
    } else {
        this->addInt(0);
    }
}

<<<<<<< HEAD
int SkPictureRecord::addPathToHeap(const SkPath& path)
{
    if (int* n = fPaths.find(path)) {
        return *n;
    }
    int n = fPaths.count() + 1; // 0 is reserved for null / error.
    fPaths.set(path, n);
    return n;
}

void SkPictureRecord::addPath(const SkPath& path)
{
    this->addInt(this->addPathToHeap(path));
}

void SkPictureRecord::addPatch(const SkPoint cubics[12])
{
    fWriter.write(cubics, SkPatchUtils::kNumCtrlPts * sizeof(SkPoint));
}

void SkPictureRecord::addPicture(const SkPicture* picture)
{
    int index = fPictureRefs.find(picture);
    if (index < 0) { // not found
=======
int SkPictureRecord::addPathToHeap(const SkPath& path) {
    fPaths.push_back(path);
    return fPaths.count();
}

void SkPictureRecord::addPath(const SkPath& path) {
    this->addInt(this->addPathToHeap(path));
}

void SkPictureRecord::addPatch(const SkPoint cubics[12]) {
    fWriter.write(cubics, SkPatchUtils::kNumCtrlPts * sizeof(SkPoint));
}

void SkPictureRecord::addPicture(const SkPicture* picture) {
    int index = fPictureRefs.find(picture);
    if (index < 0) {    // not found
>>>>>>> miniblink49
        index = fPictureRefs.count();
        *fPictureRefs.append() = picture;
        picture->ref();
    }
    // follow the convention of recording a 1-based index
    this->addInt(index + 1);
}

<<<<<<< HEAD
void SkPictureRecord::addDrawable(SkDrawable* drawable)
{
    int index = fDrawableRefs.find(drawable);
    if (index < 0) { // not found
        index = fDrawableRefs.count();
        *fDrawableRefs.append() = drawable;
        drawable->ref();
    }
    // follow the convention of recording a 1-based index
    this->addInt(index + 1);
}

void SkPictureRecord::addPoint(const SkPoint& point)
{
    fWriter.writePoint(point);
}

void SkPictureRecord::addPoints(const SkPoint pts[], int count)
{
    fWriter.writeMul4(pts, count * sizeof(SkPoint));
}

void SkPictureRecord::addNoOp()
{
=======
void SkPictureRecord::addPoint(const SkPoint& point) {
    fWriter.writePoint(point);
}

void SkPictureRecord::addPoints(const SkPoint pts[], int count) {
    fWriter.writeMul4(pts, count * sizeof(SkPoint));
}

void SkPictureRecord::addNoOp() {
>>>>>>> miniblink49
    size_t size = kUInt32Size; // op
    this->addDraw(NOOP, &size);
}

<<<<<<< HEAD
void SkPictureRecord::addRect(const SkRect& rect)
{
    fWriter.writeRect(rect);
}

void SkPictureRecord::addRectPtr(const SkRect* rect)
{
    if (fWriter.writeBool(rect != nullptr)) {
=======
void SkPictureRecord::addRect(const SkRect& rect) {
    fWriter.writeRect(rect);
}

void SkPictureRecord::addRectPtr(const SkRect* rect) {
    if (fWriter.writeBool(rect != NULL)) {
>>>>>>> miniblink49
        fWriter.writeRect(*rect);
    }
}

<<<<<<< HEAD
void SkPictureRecord::addIRect(const SkIRect& rect)
{
    fWriter.write(&rect, sizeof(rect));
}

void SkPictureRecord::addIRectPtr(const SkIRect* rect)
{
    if (fWriter.writeBool(rect != nullptr)) {
=======
void SkPictureRecord::addIRect(const SkIRect& rect) {
    fWriter.write(&rect, sizeof(rect));
}

void SkPictureRecord::addIRectPtr(const SkIRect* rect) {
    if (fWriter.writeBool(rect != NULL)) {
>>>>>>> miniblink49
        *(SkIRect*)fWriter.reserve(sizeof(SkIRect)) = *rect;
    }
}

<<<<<<< HEAD
void SkPictureRecord::addRRect(const SkRRect& rrect)
{
    fWriter.writeRRect(rrect);
}

void SkPictureRecord::addRegion(const SkRegion& region)
{
    fWriter.writeRegion(region);
}

void SkPictureRecord::addText(const void* text, size_t byteLength)
{
=======
void SkPictureRecord::addRRect(const SkRRect& rrect) {
    fWriter.writeRRect(rrect);
}

void SkPictureRecord::addRegion(const SkRegion& region) {
    fWriter.writeRegion(region);
}

void SkPictureRecord::addText(const void* text, size_t byteLength) {
>>>>>>> miniblink49
    fContentInfo.onDrawText();
    addInt(SkToInt(byteLength));
    fWriter.writePad(text, byteLength);
}

<<<<<<< HEAD
void SkPictureRecord::addTextBlob(const SkTextBlob* blob)
{
=======
void SkPictureRecord::addTextBlob(const SkTextBlob *blob) {
>>>>>>> miniblink49
    int index = fTextBlobRefs.count();
    *fTextBlobRefs.append() = blob;
    blob->ref();
    // follow the convention of recording a 1-based index
    this->addInt(index + 1);
}

///////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
=======

>>>>>>> miniblink49
