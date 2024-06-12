// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HTMLTokenizerNames_h
#define HTMLTokenizerNames_h

#include "platform/PlatformExport.h"
#include "wtf/text/AtomicString.h"

// Generated from:
// - ../../third_party/WebKit/Source/core/html/parser/HTMLTokenizerNames.in

namespace blink {
namespace HTMLTokenizerNames {

    extern const WTF::AtomicString& doctype;
    extern const WTF::AtomicString& system;
    extern const WTF::AtomicString& cdata;
    extern const WTF::AtomicString& dashDash;
    extern const WTF::AtomicString& publicString;

    const unsigned HTMLTokenizerNamesCount = 5;

    void init();

} // HTMLTokenizerNames
} // namespace blink

#endif
