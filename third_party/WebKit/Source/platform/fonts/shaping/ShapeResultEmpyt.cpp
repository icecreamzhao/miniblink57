/*
 * Copyright (c) 2012 Google Inc. All rights reserved.
 * Copyright (C) 2013 BlackBerry Limited. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "platform/fonts/shaping/ShapeResult.h"

#include "platform/fonts/Font.h"
//#include "platform/fonts/shaping/ShapeResultInlineHeaders.h"
#include "platform/fonts/shaping/ShapeResultSpacing.h"
#include "wtf/PtrUtil.h"
//#include <hb.h>
#include <memory>

namespace blink {

ShapeResult::ShapeResult(const Font* font, unsigned numCharacters, TextDirection direction)
    : m_width(0)
    , m_primaryFont(const_cast<SimpleFontData*>(font->primaryFont()))
    , m_numCharacters(numCharacters)
    , m_numGlyphs(0)
    , m_direction(direction)
    , m_hasVerticalOffsets(0)
{
}

ShapeResult::ShapeResult(const ShapeResult& other)
    : m_width(other.m_width)
    , m_glyphBoundingBox(other.m_glyphBoundingBox)
    , m_primaryFont(other.m_primaryFont)
    , m_numCharacters(other.m_numCharacters)
    , m_numGlyphs(other.m_numGlyphs)
    , m_direction(other.m_direction)
    , m_hasVerticalOffsets(other.m_hasVerticalOffsets)
{
    m_runs.reserveCapacity(other.m_runs.size());
    for (const auto& run : other.m_runs)
        m_runs.append(wrapUnique(new ShapeResult::RunInfo(*run)));
}

ShapeResult::~ShapeResult()
{
}

} // namespace blink
