// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CSSPropertyAPIContent_h
#define CSSPropertyAPIContent_h

#include "core/CSSPropertyNames.h"
#include "core/css/properties/CSSPropertyAPI.h"

namespace blink {

class CSSParserTokenRange;
class CSSParserContext;

class CSSPropertyAPIContent : public CSSPropertyAPI {
public:
    static const CSSValue* parseSingleValue(CSSParserTokenRange&,
        const CSSParserContext*);
};

} // namespace blink

#endif // CSSPropertyAPIContent_h
