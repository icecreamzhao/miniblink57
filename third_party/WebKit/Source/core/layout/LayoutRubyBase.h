/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
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

#ifndef LayoutRubyBase_h
#define LayoutRubyBase_h

#include "core/layout/LayoutBlockFlow.h"

namespace blink {

class LayoutRubyRun;

class LayoutRubyBase final : public LayoutBlockFlow {
public:
    ~LayoutRubyBase() override;
    static LayoutRubyBase* createAnonymous(Document*);

    const char* name() const override { return "LayoutRubyBase"; }

    bool isOfType(LayoutObjectType type) const override
    {
        return type == LayoutObjectRubyBase || LayoutBlockFlow::isOfType(type);
    }

    bool isChildAllowed(LayoutObject*, const ComputedStyle&) const override;

private:
    LayoutRubyBase();

    ETextAlign textAlignmentForLine(bool endsWithSoftBreak) const override;
    void adjustInlineDirectionLineBounds(unsigned expansionOpportunityCount,
        LayoutUnit& logicalLeft,
        LayoutUnit& logicalWidth) const override;

    void moveChildren(LayoutRubyBase* toBase,
        LayoutObject* beforeChild = nullptr);
    void moveInlineChildren(LayoutRubyBase* toBase,
        LayoutObject* beforeChild = nullptr);
    void moveBlockChildren(LayoutRubyBase* toBase,
        LayoutObject* beforeChild = nullptr);

    // Allow LayoutRubyRun to manipulate the children within ruby bases.
    friend class LayoutRubyRun;
};

DEFINE_LAYOUT_OBJECT_TYPE_CASTS(LayoutRubyBase, isRubyBase());

} // namespace blink

#endif // LayoutRubyBase_h
