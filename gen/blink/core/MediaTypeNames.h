// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MediaTypeNames_h
#define MediaTypeNames_h

#include "core/CoreExport.h"
#include "wtf/text/AtomicString.h"

// Generated from:
// - ../../third_party/WebKit/Source/core/css/MediaTypeNames.in

namespace blink {
namespace MediaTypeNames {

    CORE_EXPORT extern const WTF::AtomicString& all;
    CORE_EXPORT extern const WTF::AtomicString& braille;
    CORE_EXPORT extern const WTF::AtomicString& embossed;
    CORE_EXPORT extern const WTF::AtomicString& handheld;
    CORE_EXPORT extern const WTF::AtomicString& print;
    CORE_EXPORT extern const WTF::AtomicString& projection;
    CORE_EXPORT extern const WTF::AtomicString& screen;
    CORE_EXPORT extern const WTF::AtomicString& speech;
    CORE_EXPORT extern const WTF::AtomicString& tty;
    CORE_EXPORT extern const WTF::AtomicString& tv;

    const unsigned MediaTypeNamesCount = 10;

    CORE_EXPORT void init();

} // MediaTypeNames
} // namespace blink

#endif
