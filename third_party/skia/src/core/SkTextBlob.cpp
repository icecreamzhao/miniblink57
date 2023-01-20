/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkTextBlobRunIterator.h"
=======
#include "SkTextBlob.h"
>>>>>>> miniblink49

#include "SkReadBuffer.h"
#include "SkTypeface.h"
#include "SkWriteBuffer.h"

namespace {

// TODO(fmalita): replace with SkFont.
class RunFont : SkNoncopyable {
public:
    RunFont(const SkPaint& paint)
        : fSize(paint.getTextSize())
        , fScaleX(paint.getTextScaleX())
        , fTypeface(SkSafeRef(paint.getTypeface()))
        , fSkewX(paint.getTextSkewX())
<<<<<<< HEAD
        , fAlign(paint.getTextAlign())
        , fHinting(paint.getHinting())
        , fFlags(paint.getFlags() & kFlagsMask)
    {
    }

    void applyToPaint(SkPaint* paint) const
    {
        paint->setTextEncoding(SkPaint::kGlyphID_TextEncoding);
        paint->setTypeface(fTypeface);
        paint->setTextSize(fSize);
        paint->setTextScaleX(fScaleX);
        paint->setTextSkewX(fSkewX);
        paint->setTextAlign(static_cast<SkPaint::Align>(fAlign));
=======
        , fHinting(paint.getHinting())
        , fFlags(paint.getFlags() & kFlagsMask) { }

    void applyToPaint(SkPaint* paint) const {
        paint->setTextEncoding(SkPaint::kGlyphID_TextEncoding);
        paint->setTypeface(fTypeface.get());
        paint->setTextSize(fSize);
        paint->setTextScaleX(fScaleX);
        paint->setTextSkewX(fSkewX);
>>>>>>> miniblink49
        paint->setHinting(static_cast<SkPaint::Hinting>(fHinting));

        paint->setFlags((paint->getFlags() & ~kFlagsMask) | fFlags);
    }

<<<<<<< HEAD
    bool operator==(const RunFont& other) const
    {
=======
    bool operator==(const RunFont& other) const {
>>>>>>> miniblink49
        return fTypeface == other.fTypeface
            && fSize == other.fSize
            && fScaleX == other.fScaleX
            && fSkewX == other.fSkewX
<<<<<<< HEAD
            && fAlign == other.fAlign
=======
>>>>>>> miniblink49
            && fHinting == other.fHinting
            && fFlags == other.fFlags;
    }

<<<<<<< HEAD
    bool operator!=(const RunFont& other) const
    {
=======
    bool operator!=(const RunFont& other) const {
>>>>>>> miniblink49
        return !(*this == other);
    }

    uint32_t flags() const { return fFlags; }

private:
<<<<<<< HEAD
    const static uint32_t kFlagsMask = SkPaint::kAntiAlias_Flag | SkPaint::kUnderlineText_Flag | SkPaint::kStrikeThruText_Flag | SkPaint::kFakeBoldText_Flag | SkPaint::kLinearText_Flag | SkPaint::kSubpixelText_Flag | SkPaint::kDevKernText_Flag | SkPaint::kLCDRenderText_Flag | SkPaint::kEmbeddedBitmapText_Flag | SkPaint::kAutoHinting_Flag | SkPaint::kVerticalText_Flag | SkPaint::kGenA8FromLCD_Flag;

    SkScalar fSize;
    SkScalar fScaleX;

    // Keep this SkAutoTUnref off the first position, to avoid interfering with SkNoncopyable
    // empty baseclass optimization (http://code.google.com/p/skia/issues/detail?id=3694).
    sk_sp<SkTypeface> fTypeface;
    SkScalar fSkewX;

    static_assert(SkPaint::kAlignCount < 4, "insufficient_align_bits");
    uint32_t fAlign : 2;
    static_assert(SkPaint::kFull_Hinting < 4, "insufficient_hinting_bits");
    uint32_t fHinting : 2;
    static_assert((kFlagsMask & 0xffff) == kFlagsMask, "insufficient_flags_bits");
    uint32_t fFlags : 16;
=======
    const static uint32_t kFlagsMask =
        SkPaint::kAntiAlias_Flag          |
        SkPaint::kUnderlineText_Flag      |
        SkPaint::kStrikeThruText_Flag     |
        SkPaint::kFakeBoldText_Flag       |
        SkPaint::kLinearText_Flag         |
        SkPaint::kSubpixelText_Flag       |
        SkPaint::kDevKernText_Flag        |
        SkPaint::kLCDRenderText_Flag      |
        SkPaint::kEmbeddedBitmapText_Flag |
        SkPaint::kAutoHinting_Flag        |
        SkPaint::kVerticalText_Flag       |
        SkPaint::kGenA8FromLCD_Flag;

    SkScalar                 fSize;
    SkScalar                 fScaleX;

    // Keep this SkAutoTUnref off the first position, to avoid interfering with SkNoncopyable
    // empty baseclass optimization (http://code.google.com/p/skia/issues/detail?id=3694).
    SkAutoTUnref<SkTypeface> fTypeface;
    SkScalar                 fSkewX;

    SK_COMPILE_ASSERT(SkPaint::kFull_Hinting < 4, insufficient_hinting_bits);
    uint32_t                 fHinting : 2;
    SK_COMPILE_ASSERT((kFlagsMask & 0xffff) == kFlagsMask, insufficient_flags_bits);
    uint32_t                 fFlags : 16;
>>>>>>> miniblink49

    typedef SkNoncopyable INHERITED;
};

struct RunFontStorageEquivalent {
    SkScalar fSize, fScaleX;
<<<<<<< HEAD
    void* fTypeface;
    SkScalar fSkewX;
    uint32_t fFlags;
};
static_assert(sizeof(RunFont) == sizeof(RunFontStorageEquivalent), "runfont_should_stay_packed");
=======
    void*    fTypeface;
    SkScalar fSkewX;
    uint32_t fFlags;
};
SK_COMPILE_ASSERT(sizeof(RunFont) == sizeof(RunFontStorageEquivalent), runfont_should_stay_packed);
>>>>>>> miniblink49

} // anonymous namespace

//
// Textblob data is laid out into externally-managed storage as follows:
//
//    -----------------------------------------------------------------------------
//   | SkTextBlob | RunRecord | Glyphs[] | Pos[] | RunRecord | Glyphs[] | Pos[] | ...
//    -----------------------------------------------------------------------------
//
//  Each run record describes a text blob run, and can be used to determine the (implicit)
//  location of the following record.

SkDEBUGCODE(static const unsigned kRunRecordMagic = 0xb10bcafe;)

<<<<<<< HEAD
    class SkTextBlob::RunRecord {
=======
class SkTextBlob::RunRecord {
>>>>>>> miniblink49
public:
    RunRecord(uint32_t count, const SkPoint& offset, const SkPaint& font, GlyphPositioning pos)
        : fFont(font)
        , fCount(count)
        , fOffset(offset)
<<<<<<< HEAD
        , fPositioning(pos)
    {
        SkDEBUGCODE(fMagic = kRunRecordMagic);
    }

    uint32_t glyphCount() const
    {
        return fCount;
    }

    const SkPoint& offset() const
    {
        return fOffset;
    }

    const RunFont& font() const
    {
        return fFont;
    }

    GlyphPositioning positioning() const
    {
        return fPositioning;
    }

    uint16_t* glyphBuffer() const
    {
=======
        , fPositioning(pos) {
        SkDEBUGCODE(fMagic = kRunRecordMagic);
    }

    uint32_t glyphCount() const {
        return fCount;
    }

    const SkPoint& offset() const {
        return fOffset;
    }

    const RunFont& font() const {
        return fFont;
    }

    GlyphPositioning positioning() const {
        return fPositioning;
    }

    uint16_t* glyphBuffer() const {
>>>>>>> miniblink49
        // Glyph are stored immediately following the record.
        return reinterpret_cast<uint16_t*>(const_cast<RunRecord*>(this) + 1);
    }

<<<<<<< HEAD
    SkScalar* posBuffer() const
    {
        // Position scalars follow the (aligned) glyph buffer.
        return reinterpret_cast<SkScalar*>(reinterpret_cast<uint8_t*>(this->glyphBuffer()) + SkAlign4(fCount * sizeof(uint16_t)));
    }

    static size_t StorageSize(int glyphCount, SkTextBlob::GlyphPositioning positioning)
    {
        // RunRecord object + (aligned) glyph buffer + position buffer
        return SkAlignPtr(sizeof(SkTextBlob::RunRecord)
            + SkAlign4(glyphCount * sizeof(uint16_t))
            + glyphCount * sizeof(SkScalar) * ScalarsPerGlyph(positioning));
    }

    static const RunRecord* First(const SkTextBlob* blob)
    {
=======
    SkScalar* posBuffer() const {
        // Position scalars follow the (aligned) glyph buffer.
        return reinterpret_cast<SkScalar*>(reinterpret_cast<uint8_t*>(this->glyphBuffer()) +
                                           SkAlign4(fCount * sizeof(uint16_t)));
    }

    static size_t StorageSize(int glyphCount, SkTextBlob::GlyphPositioning positioning) {
        // RunRecord object + (aligned) glyph buffer + position buffer
        return SkAlignPtr(sizeof(SkTextBlob::RunRecord)
                        + SkAlign4(glyphCount* sizeof(uint16_t))
                        + glyphCount * sizeof(SkScalar) * ScalarsPerGlyph(positioning));
    }

    static const RunRecord* First(const SkTextBlob* blob) {
>>>>>>> miniblink49
        // The first record (if present) is stored following the blob object.
        return reinterpret_cast<const RunRecord*>(blob + 1);
    }

<<<<<<< HEAD
    static const RunRecord* Next(const RunRecord* run)
    {
=======
    static const RunRecord* Next(const RunRecord* run) {
>>>>>>> miniblink49
        return reinterpret_cast<const RunRecord*>(reinterpret_cast<const uint8_t*>(run)
            + StorageSize(run->glyphCount(), run->positioning()));
    }

<<<<<<< HEAD
    void validate(const uint8_t* storageTop) const
    {
=======
    void validate(uint8_t* storageTop) const {
>>>>>>> miniblink49
        SkASSERT(kRunRecordMagic == fMagic);
        SkASSERT((uint8_t*)Next(this) <= storageTop);
        SkASSERT(glyphBuffer() + fCount <= (uint16_t*)posBuffer());
        SkASSERT(posBuffer() + fCount * ScalarsPerGlyph(fPositioning) <= (SkScalar*)Next(this));
    }

private:
    friend class SkTextBlobBuilder;

<<<<<<< HEAD
    void grow(uint32_t count)
    {
=======
    void grow(uint32_t count) {
>>>>>>> miniblink49
        SkScalar* initialPosBuffer = posBuffer();
        uint32_t initialCount = fCount;
        fCount += count;

        // Move the initial pos scalars to their new location.
        size_t copySize = initialCount * sizeof(SkScalar) * ScalarsPerGlyph(fPositioning);
        SkASSERT((uint8_t*)posBuffer() + copySize <= (uint8_t*)Next(this));

        // memmove, as the buffers may overlap
        memmove(posBuffer(), initialPosBuffer, copySize);
    }

<<<<<<< HEAD
    RunFont fFont;
    uint32_t fCount;
    SkPoint fOffset;
=======
    RunFont          fFont;
    uint32_t         fCount;
    SkPoint          fOffset;
>>>>>>> miniblink49
    GlyphPositioning fPositioning;

    SkDEBUGCODE(unsigned fMagic;)
};

static int32_t gNextID = 1;
<<<<<<< HEAD
static int32_t next_id()
{
=======
static int32_t next_id() {
>>>>>>> miniblink49
    int32_t id;
    do {
        id = sk_atomic_inc(&gNextID);
    } while (id == SK_InvalidGenID);
    return id;
}

SkTextBlob::SkTextBlob(int runCount, const SkRect& bounds)
    : fRunCount(runCount)
    , fBounds(bounds)
<<<<<<< HEAD
    , fUniqueID(next_id())
{
}

SkTextBlob::~SkTextBlob()
{
=======
    , fUniqueID(next_id()) {
}

SkTextBlob::~SkTextBlob() {
>>>>>>> miniblink49
    const RunRecord* run = RunRecord::First(this);
    for (int i = 0; i < fRunCount; ++i) {
        const RunRecord* nextRun = RunRecord::Next(run);
        SkDEBUGCODE(run->validate((uint8_t*)this + fStorageSize);)
<<<<<<< HEAD
            run->~RunRecord();
=======
        run->~RunRecord();
>>>>>>> miniblink49
        run = nextRun;
    }
}

<<<<<<< HEAD
void SkTextBlob::flatten(SkWriteBuffer& buffer) const
{
=======
void SkTextBlob::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    int runCount = fRunCount;

    buffer.write32(runCount);
    buffer.writeRect(fBounds);

    SkPaint runPaint;
<<<<<<< HEAD
    SkTextBlobRunIterator it(this);
=======
    RunIterator it(this);
>>>>>>> miniblink49
    while (!it.done()) {
        SkASSERT(it.glyphCount() > 0);

        buffer.write32(it.glyphCount());
        buffer.write32(it.positioning());
        buffer.writePoint(it.offset());
        // This should go away when switching to SkFont
        it.applyFontToPaint(&runPaint);
        buffer.writePaint(runPaint);

        buffer.writeByteArray(it.glyphs(), it.glyphCount() * sizeof(uint16_t));
        buffer.writeByteArray(it.pos(),
            it.glyphCount() * sizeof(SkScalar) * ScalarsPerGlyph(it.positioning()));

        it.next();
        SkDEBUGCODE(runCount--);
    }
    SkASSERT(0 == runCount);
}

<<<<<<< HEAD
const SkTextBlob* SkTextBlob::CreateFromBuffer(SkReadBuffer& reader)
{
    int runCount = reader.read32();
    if (runCount < 0) {
        return nullptr;
=======
const SkTextBlob* SkTextBlob::CreateFromBuffer(SkReadBuffer& reader) {
    int runCount = reader.read32();
    if (runCount < 0) {
        return NULL;
>>>>>>> miniblink49
    }

    SkRect bounds;
    reader.readRect(&bounds);

    SkTextBlobBuilder blobBuilder;
    for (int i = 0; i < runCount; ++i) {
        int glyphCount = reader.read32();
        GlyphPositioning pos = static_cast<GlyphPositioning>(reader.read32());
        if (glyphCount <= 0 || pos > kFull_Positioning) {
<<<<<<< HEAD
            return nullptr;
=======
            return NULL;
>>>>>>> miniblink49
        }

        SkPoint offset;
        reader.readPoint(&offset);
        SkPaint font;
        reader.readPaint(&font);

<<<<<<< HEAD
        const SkTextBlobBuilder::RunBuffer* buf = nullptr;
=======
        const SkTextBlobBuilder::RunBuffer* buf = NULL;
>>>>>>> miniblink49
        switch (pos) {
        case kDefault_Positioning:
            buf = &blobBuilder.allocRun(font, glyphCount, offset.x(), offset.y(), &bounds);
            break;
        case kHorizontal_Positioning:
            buf = &blobBuilder.allocRunPosH(font, glyphCount, offset.y(), &bounds);
            break;
        case kFull_Positioning:
            buf = &blobBuilder.allocRunPos(font, glyphCount, &bounds);
            break;
        default:
<<<<<<< HEAD
            return nullptr;
        }

        if (!reader.readByteArray(buf->glyphs, glyphCount * sizeof(uint16_t)) || !reader.readByteArray(buf->pos, glyphCount * sizeof(SkScalar) * ScalarsPerGlyph(pos))) {
            return nullptr;
=======
            return NULL;
        }

        if (!reader.readByteArray(buf->glyphs, glyphCount * sizeof(uint16_t)) ||
            !reader.readByteArray(buf->pos,
                                  glyphCount * sizeof(SkScalar) * ScalarsPerGlyph(pos))) {
            return NULL;
>>>>>>> miniblink49
        }
    }

    return blobBuilder.build();
}

<<<<<<< HEAD
unsigned SkTextBlob::ScalarsPerGlyph(GlyphPositioning pos)
{
=======
unsigned SkTextBlob::ScalarsPerGlyph(GlyphPositioning pos) {
>>>>>>> miniblink49
    // GlyphPositioning values are directly mapped to scalars-per-glyph.
    SkASSERT(pos <= 2);
    return pos;
}

<<<<<<< HEAD
SkTextBlobRunIterator::SkTextBlobRunIterator(const SkTextBlob* blob)
    : fCurrentRun(SkTextBlob::RunRecord::First(blob))
    , fRemainingRuns(blob->fRunCount)
{
    SkDEBUGCODE(fStorageTop = (uint8_t*)blob + blob->fStorageSize;)
}

bool SkTextBlobRunIterator::done() const
{
    return fRemainingRuns <= 0;
}

void SkTextBlobRunIterator::next()
{
=======
SkTextBlob::RunIterator::RunIterator(const SkTextBlob* blob)
    : fCurrentRun(RunRecord::First(blob))
    , fRemainingRuns(blob->fRunCount) {
    SkDEBUGCODE(fStorageTop = (uint8_t*)blob + blob->fStorageSize;)
}

bool SkTextBlob::RunIterator::done() const {
    return fRemainingRuns <= 0;
}

void SkTextBlob::RunIterator::next() {
>>>>>>> miniblink49
    SkASSERT(!this->done());

    if (!this->done()) {
        SkDEBUGCODE(fCurrentRun->validate(fStorageTop);)
<<<<<<< HEAD
            fCurrentRun
            = SkTextBlob::RunRecord::Next(fCurrentRun);
=======
        fCurrentRun = RunRecord::Next(fCurrentRun);
>>>>>>> miniblink49
        fRemainingRuns--;
    }
}

<<<<<<< HEAD
uint32_t SkTextBlobRunIterator::glyphCount() const
{
=======
uint32_t SkTextBlob::RunIterator::glyphCount() const {
>>>>>>> miniblink49
    SkASSERT(!this->done());
    return fCurrentRun->glyphCount();
}

<<<<<<< HEAD
const uint16_t* SkTextBlobRunIterator::glyphs() const
{
=======
const uint16_t* SkTextBlob::RunIterator::glyphs() const {
>>>>>>> miniblink49
    SkASSERT(!this->done());
    return fCurrentRun->glyphBuffer();
}

<<<<<<< HEAD
const SkScalar* SkTextBlobRunIterator::pos() const
{
=======
const SkScalar* SkTextBlob::RunIterator::pos() const {
>>>>>>> miniblink49
    SkASSERT(!this->done());
    return fCurrentRun->posBuffer();
}

<<<<<<< HEAD
const SkPoint& SkTextBlobRunIterator::offset() const
{
=======
const SkPoint& SkTextBlob::RunIterator::offset() const {
>>>>>>> miniblink49
    SkASSERT(!this->done());
    return fCurrentRun->offset();
}

<<<<<<< HEAD
SkTextBlob::GlyphPositioning SkTextBlobRunIterator::positioning() const
{
=======
SkTextBlob::GlyphPositioning SkTextBlob::RunIterator::positioning() const {
>>>>>>> miniblink49
    SkASSERT(!this->done());
    return fCurrentRun->positioning();
}

<<<<<<< HEAD
void SkTextBlobRunIterator::applyFontToPaint(SkPaint* paint) const
{
=======
void SkTextBlob::RunIterator::applyFontToPaint(SkPaint* paint) const {
>>>>>>> miniblink49
    SkASSERT(!this->done());

    fCurrentRun->font().applyToPaint(paint);
}

<<<<<<< HEAD
bool SkTextBlobRunIterator::isLCD() const
{
=======
bool SkTextBlob::RunIterator::isLCD() const {
>>>>>>> miniblink49
    return SkToBool(fCurrentRun->font().flags() & SkPaint::kLCDRenderText_Flag);
}

SkTextBlobBuilder::SkTextBlobBuilder()
    : fStorageSize(0)
    , fStorageUsed(0)
    , fRunCount(0)
    , fDeferredBounds(false)
<<<<<<< HEAD
    , fLastRun(0)
{
    fBounds.setEmpty();
}

SkTextBlobBuilder::~SkTextBlobBuilder()
{
    if (nullptr != fStorage.get()) {
=======
    , fLastRun(0) {
    fBounds.setEmpty();
}

SkTextBlobBuilder::~SkTextBlobBuilder() {
    if (NULL != fStorage.get()) {
>>>>>>> miniblink49
        // We are abandoning runs and must destruct the associated font data.
        // The easiest way to accomplish that is to use the blob destructor.
        build()->unref();
    }
}

<<<<<<< HEAD
SkRect SkTextBlobBuilder::TightRunBounds(const SkTextBlob::RunRecord& run)
{
    SkRect bounds;
    SkPaint paint;
    run.font().applyToPaint(&paint);

    if (SkTextBlob::kDefault_Positioning == run.positioning()) {
        paint.measureText(run.glyphBuffer(), run.glyphCount() * sizeof(uint16_t), &bounds);
        return bounds.makeOffset(run.offset().x(), run.offset().y());
    }

    SkAutoSTArray<16, SkRect> glyphBounds(run.glyphCount());
    paint.getTextWidths(run.glyphBuffer(),
        run.glyphCount() * sizeof(uint16_t),
        NULL,
        glyphBounds.get());

    SkASSERT(SkTextBlob::kFull_Positioning == run.positioning() || SkTextBlob::kHorizontal_Positioning == run.positioning());
    // kFull_Positioning       => [ x, y, x, y... ]
    // kHorizontal_Positioning => [ x, x, x... ]
    //                            (const y applied by runBounds.offset(run->offset()) later)
    const SkScalar horizontalConstY = 0;
    const SkScalar* glyphPosX = run.posBuffer();
    const SkScalar* glyphPosY = (run.positioning() == SkTextBlob::kFull_Positioning) ? glyphPosX + 1 : &horizontalConstY;
    const unsigned posXInc = SkTextBlob::ScalarsPerGlyph(run.positioning());
    const unsigned posYInc = (run.positioning() == SkTextBlob::kFull_Positioning) ? posXInc : 0;

    bounds.setEmpty();
    for (unsigned i = 0; i < run.glyphCount(); ++i) {
        bounds.join(glyphBounds[i].makeOffset(*glyphPosX, *glyphPosY));
        glyphPosX += posXInc;
        glyphPosY += posYInc;
    }

    SkASSERT((void*)glyphPosX <= SkTextBlob::RunRecord::Next(&run));
=======
SkRect SkTextBlobBuilder::TightRunBounds(const SkTextBlob::RunRecord& run) {
    SkASSERT(SkTextBlob::kDefault_Positioning == run.positioning());

    SkRect bounds;
    SkPaint paint;
    run.font().applyToPaint(&paint);
    paint.measureText(run.glyphBuffer(), run.glyphCount() * sizeof(uint16_t), &bounds);
>>>>>>> miniblink49

    return bounds.makeOffset(run.offset().x(), run.offset().y());
}

<<<<<<< HEAD
SkRect SkTextBlobBuilder::ConservativeRunBounds(const SkTextBlob::RunRecord& run)
{
    SkASSERT(run.glyphCount() > 0);
    SkASSERT(SkTextBlob::kFull_Positioning == run.positioning() || SkTextBlob::kHorizontal_Positioning == run.positioning());

    SkPaint paint;
    run.font().applyToPaint(&paint);
    const SkRect fontBounds = paint.getFontBounds();
    if (fontBounds.isEmpty()) {
        // Empty font bounds are likely a font bug.  TightBounds has a better chance of
        // producing useful results in this case.
        return TightRunBounds(run);
    }

    // Compute the glyph position bbox.
=======
SkRect SkTextBlobBuilder::ConservativeRunBounds(const SkTextBlob::RunRecord& run) {
    SkASSERT(run.glyphCount() > 0);
    SkASSERT(SkTextBlob::kFull_Positioning == run.positioning() ||
             SkTextBlob::kHorizontal_Positioning == run.positioning());

    // First, compute the glyph position bbox.
>>>>>>> miniblink49
    SkRect bounds;
    switch (run.positioning()) {
    case SkTextBlob::kHorizontal_Positioning: {
        const SkScalar* glyphPos = run.posBuffer();
        SkASSERT((void*)(glyphPos + run.glyphCount()) <= SkTextBlob::RunRecord::Next(&run));

        SkScalar minX = *glyphPos;
        SkScalar maxX = *glyphPos;
        for (unsigned i = 1; i < run.glyphCount(); ++i) {
            SkScalar x = glyphPos[i];
            minX = SkMinScalar(x, minX);
            maxX = SkMaxScalar(x, maxX);
        }

        bounds.setLTRB(minX, 0, maxX, 0);
    } break;
    case SkTextBlob::kFull_Positioning: {
        const SkPoint* glyphPosPts = reinterpret_cast<const SkPoint*>(run.posBuffer());
        SkASSERT((void*)(glyphPosPts + run.glyphCount()) <= SkTextBlob::RunRecord::Next(&run));

        bounds.setBounds(glyphPosPts, run.glyphCount());
    } break;
    default:
        SkFAIL("unsupported positioning mode");
    }

    // Expand by typeface glyph bounds.
<<<<<<< HEAD
    bounds.fLeft += fontBounds.left();
    bounds.fTop += fontBounds.top();
    bounds.fRight += fontBounds.right();
=======
    SkPaint paint;
    run.font().applyToPaint(&paint);
    const SkRect fontBounds = paint.getFontBounds();
    bounds.fLeft   += fontBounds.left();
    bounds.fTop    += fontBounds.top();
    bounds.fRight  += fontBounds.right();
>>>>>>> miniblink49
    bounds.fBottom += fontBounds.bottom();

    // Offset by run position.
    return bounds.makeOffset(run.offset().x(), run.offset().y());
}

<<<<<<< HEAD
void SkTextBlobBuilder::updateDeferredBounds()
{
=======
void SkTextBlobBuilder::updateDeferredBounds() {
>>>>>>> miniblink49
    SkASSERT(!fDeferredBounds || fRunCount > 0);

    if (!fDeferredBounds) {
        return;
    }

    SkASSERT(fLastRun >= sizeof(SkTextBlob));
<<<<<<< HEAD
    SkTextBlob::RunRecord* run = reinterpret_cast<SkTextBlob::RunRecord*>(fStorage.get() + fLastRun);

    // FIXME: we should also use conservative bounds for kDefault_Positioning.
    SkRect runBounds = SkTextBlob::kDefault_Positioning == run->positioning() ? TightRunBounds(*run) : ConservativeRunBounds(*run);
=======
    SkTextBlob::RunRecord* run = reinterpret_cast<SkTextBlob::RunRecord*>(fStorage.get() +
                                                                          fLastRun);

    // FIXME: we should also use conservative bounds for kDefault_Positioning.
    SkRect runBounds = SkTextBlob::kDefault_Positioning == run->positioning() ?
                       TightRunBounds(*run) : ConservativeRunBounds(*run);
>>>>>>> miniblink49
    fBounds.join(runBounds);
    fDeferredBounds = false;
}

<<<<<<< HEAD
void SkTextBlobBuilder::reserve(size_t size)
{
=======
void SkTextBlobBuilder::reserve(size_t size) {
>>>>>>> miniblink49
    // We don't currently pre-allocate, but maybe someday...
    if (fStorageUsed + size <= fStorageSize) {
        return;
    }

    if (0 == fRunCount) {
<<<<<<< HEAD
        SkASSERT(nullptr == fStorage.get());
=======
        SkASSERT(NULL == fStorage.get());
>>>>>>> miniblink49
        SkASSERT(0 == fStorageSize);
        SkASSERT(0 == fStorageUsed);

        // the first allocation also includes blob storage
        fStorageUsed += sizeof(SkTextBlob);
    }

    fStorageSize = fStorageUsed + size;
    // FYI: This relies on everything we store being relocatable, particularly SkPaint.
    fStorage.realloc(fStorageSize);
}

<<<<<<< HEAD
bool SkTextBlobBuilder::mergeRun(const SkPaint& font, SkTextBlob::GlyphPositioning positioning,
    int count, SkPoint offset)
{
=======
bool SkTextBlobBuilder::mergeRun(const SkPaint &font, SkTextBlob::GlyphPositioning positioning,
                                 int count, SkPoint offset) {
>>>>>>> miniblink49
    if (0 == fLastRun) {
        SkASSERT(0 == fRunCount);
        return false;
    }

    SkASSERT(fLastRun >= sizeof(SkTextBlob));
<<<<<<< HEAD
    SkTextBlob::RunRecord* run = reinterpret_cast<SkTextBlob::RunRecord*>(fStorage.get() + fLastRun);
=======
    SkTextBlob::RunRecord* run = reinterpret_cast<SkTextBlob::RunRecord*>(fStorage.get() +
                                                                          fLastRun);
>>>>>>> miniblink49
    SkASSERT(run->glyphCount() > 0);

    if (run->positioning() != positioning
        || run->font() != font
        || (run->glyphCount() + count < run->glyphCount())) {
        return false;
    }

    // we can merge same-font/same-positioning runs in the following cases:
    //   * fully positioned run following another fully positioned run
    //   * horizontally postioned run following another horizontally positioned run with the same
    //     y-offset
    if (SkTextBlob::kFull_Positioning != positioning
        && (SkTextBlob::kHorizontal_Positioning != positioning
            || run->offset().y() != offset.y())) {
        return false;
    }

<<<<<<< HEAD
    size_t sizeDelta = SkTextBlob::RunRecord::StorageSize(run->glyphCount() + count, positioning) - SkTextBlob::RunRecord::StorageSize(run->glyphCount(), positioning);
=======
    size_t sizeDelta = SkTextBlob::RunRecord::StorageSize(run->glyphCount() + count, positioning) -
                       SkTextBlob::RunRecord::StorageSize(run->glyphCount(), positioning);
>>>>>>> miniblink49
    this->reserve(sizeDelta);

    // reserve may have realloced
    run = reinterpret_cast<SkTextBlob::RunRecord*>(fStorage.get() + fLastRun);
    uint32_t preMergeCount = run->glyphCount();
    run->grow(count);

    // Callers expect the buffers to point at the newly added slice, ant not at the beginning.
    fCurrentRunBuffer.glyphs = run->glyphBuffer() + preMergeCount;
    fCurrentRunBuffer.pos = run->posBuffer()
<<<<<<< HEAD
        + preMergeCount * SkTextBlob::ScalarsPerGlyph(positioning);
=======
                          + preMergeCount * SkTextBlob::ScalarsPerGlyph(positioning);
>>>>>>> miniblink49

    fStorageUsed += sizeDelta;

    SkASSERT(fStorageUsed <= fStorageSize);
    run->validate(fStorage.get() + fStorageUsed);

    return true;
}

<<<<<<< HEAD
void SkTextBlobBuilder::allocInternal(const SkPaint& font,
    SkTextBlob::GlyphPositioning positioning,
    int count, SkPoint offset, const SkRect* bounds)
{
=======
void SkTextBlobBuilder::allocInternal(const SkPaint &font,
                                      SkTextBlob::GlyphPositioning positioning,
                                      int count, SkPoint offset, const SkRect* bounds) {
>>>>>>> miniblink49
    SkASSERT(count > 0);
    SkASSERT(SkPaint::kGlyphID_TextEncoding == font.getTextEncoding());

    if (!this->mergeRun(font, positioning, count, offset)) {
        this->updateDeferredBounds();

        size_t runSize = SkTextBlob::RunRecord::StorageSize(count, positioning);
        this->reserve(runSize);

        SkASSERT(fStorageUsed >= sizeof(SkTextBlob));
        SkASSERT(fStorageUsed + runSize <= fStorageSize);

        SkTextBlob::RunRecord* run = new (fStorage.get() + fStorageUsed)
<<<<<<< HEAD
            SkTextBlob::RunRecord(count, offset, font, positioning);
=======
                                         SkTextBlob::RunRecord(count, offset, font, positioning);
>>>>>>> miniblink49

        fCurrentRunBuffer.glyphs = run->glyphBuffer();
        fCurrentRunBuffer.pos = run->posBuffer();

        fLastRun = fStorageUsed;
        fStorageUsed += runSize;
        fRunCount++;

        SkASSERT(fStorageUsed <= fStorageSize);
        run->validate(fStorage.get() + fStorageUsed);
    }

    if (!fDeferredBounds) {
        if (bounds) {
            fBounds.join(*bounds);
        } else {
            fDeferredBounds = true;
        }
    }
}

const SkTextBlobBuilder::RunBuffer& SkTextBlobBuilder::allocRun(const SkPaint& font, int count,
<<<<<<< HEAD
    SkScalar x, SkScalar y,
    const SkRect* bounds)
{
=======
                                                                SkScalar x, SkScalar y,
                                                                const SkRect* bounds) {
>>>>>>> miniblink49
    this->allocInternal(font, SkTextBlob::kDefault_Positioning, count, SkPoint::Make(x, y), bounds);

    return fCurrentRunBuffer;
}

const SkTextBlobBuilder::RunBuffer& SkTextBlobBuilder::allocRunPosH(const SkPaint& font, int count,
<<<<<<< HEAD
    SkScalar y,
    const SkRect* bounds)
{
    this->allocInternal(font, SkTextBlob::kHorizontal_Positioning, count, SkPoint::Make(0, y),
        bounds);
=======
                                                                    SkScalar y,
                                                                    const SkRect* bounds) {
    this->allocInternal(font, SkTextBlob::kHorizontal_Positioning, count, SkPoint::Make(0, y),
                        bounds);
>>>>>>> miniblink49

    return fCurrentRunBuffer;
}

const SkTextBlobBuilder::RunBuffer& SkTextBlobBuilder::allocRunPos(const SkPaint& font, int count,
<<<<<<< HEAD
    const SkRect* bounds)
{
=======
                                                                   const SkRect *bounds) {
>>>>>>> miniblink49
    this->allocInternal(font, SkTextBlob::kFull_Positioning, count, SkPoint::Make(0, 0), bounds);

    return fCurrentRunBuffer;
}

<<<<<<< HEAD
const SkTextBlob* SkTextBlobBuilder::build()
{
    SkASSERT((fRunCount > 0) == (nullptr != fStorage.get()));
=======
const SkTextBlob* SkTextBlobBuilder::build() {
    SkASSERT((fRunCount > 0) == (NULL != fStorage.get()));
>>>>>>> miniblink49

    this->updateDeferredBounds();

    if (0 == fRunCount) {
<<<<<<< HEAD
        SkASSERT(nullptr == fStorage.get());
=======
        SkASSERT(NULL == fStorage.get());
>>>>>>> miniblink49
        fStorageUsed = sizeof(SkTextBlob);
        fStorage.realloc(fStorageUsed);
    }

<<<<<<< HEAD
    const SkTextBlob* blob = new (fStorage.release()) SkTextBlob(fRunCount, fBounds);
    SkDEBUGCODE(const_cast<SkTextBlob*>(blob)->fStorageSize = fStorageSize;)

        SkDEBUGCODE(
            size_t validateSize = sizeof(SkTextBlob);
            const SkTextBlob::RunRecord* run = SkTextBlob::RunRecord::First(blob);
            for (int i = 0; i < fRunCount; ++i) {
                validateSize += SkTextBlob::RunRecord::StorageSize(run->fCount, run->fPositioning);
                run->validate(reinterpret_cast<const uint8_t*>(blob) + fStorageUsed);
                run = SkTextBlob::RunRecord::Next(run);
            } SkASSERT(validateSize == fStorageUsed);)

            fStorageUsed
        = 0;
=======
    SkDEBUGCODE(
        size_t validateSize = sizeof(SkTextBlob);
        const SkTextBlob::RunRecord* run =
            SkTextBlob::RunRecord::First(reinterpret_cast<const SkTextBlob*>(fStorage.get()));
        for (int i = 0; i < fRunCount; ++i) {
            validateSize += SkTextBlob::RunRecord::StorageSize(run->fCount, run->fPositioning);
            run->validate(fStorage.get() + fStorageUsed);
            run = SkTextBlob::RunRecord::Next(run);
        }
        SkASSERT(validateSize == fStorageUsed);
    )

    const SkTextBlob* blob = new (fStorage.detach()) SkTextBlob(fRunCount, fBounds);
    SkDEBUGCODE(const_cast<SkTextBlob*>(blob)->fStorageSize = fStorageSize;)

    fStorageUsed = 0;
>>>>>>> miniblink49
    fStorageSize = 0;
    fRunCount = 0;
    fLastRun = 0;
    fBounds.setEmpty();

    return blob;
}
<<<<<<< HEAD
=======

>>>>>>> miniblink49
