// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CSSPropertyAPIClip_h
#define CSSPropertyAPIClip_h

#include "core/CSSPropertyNames.h"
#include "core/css/properties/CSSPropertyAPI.h"

namespace blink {

class CSSParserTokenRange;
class CSSParserContext;

class CSSPropertyAPIClip : public CSSPropertyAPI {
public:
    static const CSSValue* parseSingleValue(CSSParserTokenRange&,
        const CSSParserContext*);
};

} // namespace blink

#endif // CSSPropertyAPIClip_h
