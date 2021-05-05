// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "InputModeNames.h"

#include "wtf/StdLibExtras.h"

// Generated from:
// - ../../third_party/WebKit/Source/core/editing/InputModeNames.in

namespace blink {
namespace InputModeNames {

    using namespace WTF;

    void* NamesStorage[InputModeNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

    const AtomicString& email = reinterpret_cast<AtomicString*>(&NamesStorage)[0];
    const AtomicString& full_width_latin = reinterpret_cast<AtomicString*>(&NamesStorage)[1];
    const AtomicString& kana = reinterpret_cast<AtomicString*>(&NamesStorage)[2];
    const AtomicString& kana_name = reinterpret_cast<AtomicString*>(&NamesStorage)[3];
    const AtomicString& katakana = reinterpret_cast<AtomicString*>(&NamesStorage)[4];
    const AtomicString& latin = reinterpret_cast<AtomicString*>(&NamesStorage)[5];
    const AtomicString& latin_name = reinterpret_cast<AtomicString*>(&NamesStorage)[6];
    const AtomicString& latin_prose = reinterpret_cast<AtomicString*>(&NamesStorage)[7];
    const AtomicString& numeric = reinterpret_cast<AtomicString*>(&NamesStorage)[8];
    const AtomicString& tel = reinterpret_cast<AtomicString*>(&NamesStorage)[9];
    const AtomicString& url = reinterpret_cast<AtomicString*>(&NamesStorage)[10];
    const AtomicString& verbatim = reinterpret_cast<AtomicString*>(&NamesStorage)[11];

    void init()
    {
        struct NameEntry {
            const char* name;
            unsigned hash;
            unsigned char length;
        };

        static const NameEntry kNames[] = {
            { "email", 13948917, 5 },
            { "full-width-latin", 16442077, 16 },
            { "kana", 8791843, 4 },
            { "kana-name", 11336314, 9 },
            { "katakana", 14340306, 8 },
            { "latin", 9919982, 5 },
            { "latin-name", 8774438, 10 },
            { "latin-prose", 13040355, 11 },
            { "numeric", 14288860, 7 },
            { "tel", 1681717, 3 },
            { "url", 10560150, 3 },
            { "verbatim", 5845248, 8 },
        };

        for (size_t i = 0; i < WTF_ARRAY_LENGTH(kNames); i++) {
            StringImpl* stringImpl = StringImpl::createStatic(kNames[i].name, kNames[i].length, kNames[i].hash);
            void* address = reinterpret_cast<AtomicString*>(&NamesStorage) + i;
            new (address) AtomicString(stringImpl);
        }
    }

} // InputModeNames
} // namespace blink
