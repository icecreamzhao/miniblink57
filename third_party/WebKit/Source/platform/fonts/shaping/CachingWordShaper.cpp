/*
 * Copyright (C) 2015 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY GOOGLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "platform/fonts/shaping/CachingWordShaper.h"

#include "platform/fonts/CharacterRange.h"
#include "platform/fonts/SimpleFontData.h"
#include "platform/fonts/shaping/CachingWordShapeIterator.h"
#include "platform/fonts/shaping/HarfBuzzShaper.h"
#include "platform/fonts/shaping/ShapeCache.h"
#include "platform/fonts/shaping/ShapeResultBuffer.h"
=======
#ifndef MINIBLINK_NO_HARFBUZZ
#include "config.h"
#include "platform/fonts/shaping/CachingWordShaper.h"

#include "platform/fonts/SimpleFontData.h"
#ifndef MINIBLINK_NO_HARFBUZZ
#include "platform/fonts/shaping/CachingWordShapeIterator.h"
#include "platform/fonts/shaping/HarfBuzzShaper.h"
#include "platform/fonts/shaping/ShapeCache.h"
#endif
>>>>>>> miniblink49
#include "wtf/text/CharacterNames.h"

namespace blink {

<<<<<<< HEAD
=======
CachingWordShaper::CachingWordShaper()
{
//#ifdef MINIBLINK_NOT_IMPLEMENTED
    m_shapeCache = new ShapeCache();
//#endif // MINIBLINK_NOT_IMPLEMENTED
}

CachingWordShaper::~CachingWordShaper()
{
//#ifdef MINIBLINK_NOT_IMPLEMENTED
    delete m_shapeCache;
//#endif // MINIBLINK_NOT_IMPLEMENTED
}

void CachingWordShaper::clear()
{
//#ifdef MINIBLINK_NOT_IMPLEMENTED
    if (m_shapeCache)
        m_shapeCache->clear();
//#endif // MINIBLINK_NOT_IMPLEMENTED
}

>>>>>>> miniblink49
float CachingWordShaper::width(const Font* font, const TextRun& run,
    HashSet<const SimpleFontData*>* fallbackFonts,
    FloatRect* glyphBounds)
{
    float width = 0;
<<<<<<< HEAD
    RefPtr<const ShapeResult> wordResult;
    CachingWordShapeIterator iterator(m_shapeCache, run, font);
    while (iterator.next(&wordResult)) {
        if (wordResult) {
            if (glyphBounds) {
                FloatRect adjustedBounds = wordResult->bounds();
                // Translate glyph bounds to the current glyph position which
                // is the total width before this glyph.
                adjustedBounds.setX(adjustedBounds.x() + width);
                glyphBounds->unite(adjustedBounds);
            }
            width += wordResult->width();
            if (fallbackFonts)
                wordResult->fallbackFonts(fallbackFonts, font->primaryFont());
        }
    }

    return width;
}

static inline float shapeResultsForRun(ShapeCache* shapeCache, const Font* font,
    const TextRun& run, HashSet<const SimpleFontData*>* fallbackFonts,
    ShapeResultBuffer* resultsBuffer)
{
    CachingWordShapeIterator iterator(shapeCache, run, font);
    RefPtr<const ShapeResult> wordResult;
    float totalWidth = 0;
    while (iterator.next(&wordResult)) {
        if (wordResult) {
            totalWidth += wordResult->width();
            if (fallbackFonts)
                wordResult->fallbackFonts(fallbackFonts, font->primaryFont());
            resultsBuffer->appendResult(wordResult.release());
=======
//#ifdef MINIBLINK_NOT_IMPLEMENTED
    RefPtr<ShapeResult> wordResult;
    CachingWordShapeIterator iterator(m_shapeCache, run, font, fallbackFonts);
    while (iterator.next(&wordResult)) {
        if (wordResult) {
            width += wordResult->width();
            if (glyphBounds)
                glyphBounds->unite(wordResult->bounds());
        }
    }
//#endif // MINIBLINK_NOT_IMPLEMENTED
//     notImplemented();
    return width;
}

//#ifdef MINIBLINK_NOT_IMPLEMENTED
static inline float shapeResultsForRun(ShapeCache* shapeCache, const Font* font,
    const TextRun& run, HashSet<const SimpleFontData*>* fallbackFonts,
    Vector<RefPtr<ShapeResult>>* results)
{
    CachingWordShapeIterator iterator(shapeCache, run, font, fallbackFonts);
    RefPtr<ShapeResult> wordResult;
    float totalWidth = 0;
    while (iterator.next(&wordResult)) {
        if (wordResult) {
            results->append(wordResult);
            totalWidth += wordResult->width();
>>>>>>> miniblink49
        }
    }
    return totalWidth;
}
<<<<<<< HEAD

int CachingWordShaper::offsetForPosition(const Font* font, const TextRun& run, float targetX, bool includePartialGlyphs)
{
    ShapeResultBuffer buffer;
    shapeResultsForRun(m_shapeCache, font, run, nullptr, &buffer);

    return buffer.offsetForPosition(run, targetX, includePartialGlyphs);
}
=======
//#endif // MINIBLINK_NOT_IMPLEMENTED
>>>>>>> miniblink49

float CachingWordShaper::fillGlyphBuffer(const Font* font, const TextRun& run,
    HashSet<const SimpleFontData*>* fallbackFonts,
    GlyphBuffer* glyphBuffer, unsigned from, unsigned to)
{
<<<<<<< HEAD
    ShapeResultBuffer buffer;
    shapeResultsForRun(m_shapeCache, font, run, fallbackFonts, &buffer);

    return buffer.fillGlyphBuffer(glyphBuffer, run, from, to);
=======
//#ifdef MINIBLINK_NOT_IMPLEMENTED
    Vector<RefPtr<ShapeResult>> results;
    shapeResultsForRun(m_shapeCache, font, run, fallbackFonts, &results);

    return ShapeResult::fillGlyphBuffer(results, glyphBuffer, run, from, to);
// #endif // MINIBLINK_NOT_IMPLEMENTED
//     notImplemented();
//     return 0;
>>>>>>> miniblink49
}

float CachingWordShaper::fillGlyphBufferForTextEmphasis(const Font* font,
    const TextRun& run, const GlyphData* emphasisData, GlyphBuffer* glyphBuffer,
    unsigned from, unsigned to)
{
<<<<<<< HEAD
    ShapeResultBuffer buffer;
    shapeResultsForRun(m_shapeCache, font, run, nullptr, &buffer);

    return buffer.fillGlyphBufferForTextEmphasis(glyphBuffer, run, emphasisData, from, to);
}

CharacterRange CachingWordShaper::getCharacterRange(const Font* font,
    const TextRun& run, unsigned from, unsigned to)
{
    ShapeResultBuffer buffer;
    float totalWidth = shapeResultsForRun(m_shapeCache, font, run, nullptr, &buffer);

    return buffer.getCharacterRange(run.direction(), totalWidth, from, to);
}

Vector<CharacterRange> CachingWordShaper::individualCharacterRanges(const Font* font, const TextRun& run)
{
    ShapeResultBuffer buffer;
    float totalWidth = shapeResultsForRun(m_shapeCache, font, run, nullptr, &buffer);

    auto ranges = buffer.individualCharacterRanges(run.direction(), totalWidth);
    // The shaper can fail to return glyph metrics for all characters (see
    // crbug.com/613915 and crbug.com/615661) so add empty ranges to ensure all
    // characters have an associated range.
    while (ranges.size() < static_cast<unsigned>(run.length()))
        ranges.append(CharacterRange(0, 0));
    return ranges;
}

}; // namespace blink
=======
//#ifdef MINIBLINK_NOT_IMPLEMENTED
    Vector<RefPtr<ShapeResult>> results;
    shapeResultsForRun(m_shapeCache, font, run, nullptr, &results);

    return ShapeResult::fillGlyphBufferForTextEmphasis(results, glyphBuffer,
        run, emphasisData, from, to);
//#endif // MINIBLINK_NOT_IMPLEMENTED
//     notImplemented();
//     return 0;
}

FloatRect CachingWordShaper::selectionRect(const Font* font, const TextRun& run,
    const FloatPoint& point, int height, unsigned from, unsigned to)
{
//#ifdef MINIBLINK_NOT_IMPLEMENTED
    Vector<RefPtr<ShapeResult>> results;
    float totalWidth = shapeResultsForRun(m_shapeCache, font, run, nullptr,
        &results);

    return ShapeResult::selectionRect(results, run.direction(), totalWidth,
        point, height, from, to);
//#endif // MINIBLINK_NOT_IMPLEMENTED
//     notImplemented();
//     return FloatRect();
}

}; // namespace blink

#endif
>>>>>>> miniblink49
