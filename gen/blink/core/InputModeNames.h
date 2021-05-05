// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef InputModeNames_h
#define InputModeNames_h

#include "core/CoreExport.h"
#include "wtf/text/AtomicString.h"

// Generated from:
// - ../../third_party/WebKit/Source/core/editing/InputModeNames.in

namespace blink {
namespace InputModeNames {

    CORE_EXPORT extern const WTF::AtomicString& email;
    CORE_EXPORT extern const WTF::AtomicString& full_width_latin;
    CORE_EXPORT extern const WTF::AtomicString& kana;
    CORE_EXPORT extern const WTF::AtomicString& kana_name;
    CORE_EXPORT extern const WTF::AtomicString& katakana;
    CORE_EXPORT extern const WTF::AtomicString& latin;
    CORE_EXPORT extern const WTF::AtomicString& latin_name;
    CORE_EXPORT extern const WTF::AtomicString& latin_prose;
    CORE_EXPORT extern const WTF::AtomicString& numeric;
    CORE_EXPORT extern const WTF::AtomicString& tel;
    CORE_EXPORT extern const WTF::AtomicString& url;
    CORE_EXPORT extern const WTF::AtomicString& verbatim;

    const unsigned InputModeNamesCount = 12;

    CORE_EXPORT void init();

} // InputModeNames
} // namespace blink

#endif
