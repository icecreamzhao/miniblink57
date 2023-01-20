// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "IndexedDBNames.h"

#include "wtf/StdLibExtras.h"

// Generated from:
// - ../../third_party/WebKit/Source/modules/indexeddb/IndexedDBNames.in

namespace blink {
namespace IndexedDBNames {

    using namespace WTF;

    void* NamesStorage[IndexedDBNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

    const AtomicString& IndexedDB = reinterpret_cast<AtomicString*>(&NamesStorage)[0];
    const AtomicString& add = reinterpret_cast<AtomicString*>(&NamesStorage)[1];
    const AtomicString& clear = reinterpret_cast<AtomicString*>(&NamesStorage)[2];
    const AtomicString& kDelete = reinterpret_cast<AtomicString*>(&NamesStorage)[3];
    const AtomicString& done = reinterpret_cast<AtomicString*>(&NamesStorage)[4];
    const AtomicString& next = reinterpret_cast<AtomicString*>(&NamesStorage)[5];
    const AtomicString& nextunique = reinterpret_cast<AtomicString*>(&NamesStorage)[6];
    const AtomicString& none = reinterpret_cast<AtomicString*>(&NamesStorage)[7];
    const AtomicString& pending = reinterpret_cast<AtomicString*>(&NamesStorage)[8];
    const AtomicString& prev = reinterpret_cast<AtomicString*>(&NamesStorage)[9];
    const AtomicString& prevunique = reinterpret_cast<AtomicString*>(&NamesStorage)[10];
    const AtomicString& put = reinterpret_cast<AtomicString*>(&NamesStorage)[11];
    const AtomicString& readonly = reinterpret_cast<AtomicString*>(&NamesStorage)[12];
    const AtomicString& readwrite = reinterpret_cast<AtomicString*>(&NamesStorage)[13];
    const AtomicString& total = reinterpret_cast<AtomicString*>(&NamesStorage)[14];
    const AtomicString& versionchange = reinterpret_cast<AtomicString*>(&NamesStorage)[15];

    void init()
    {
        struct NameEntry {
            const char* name;
            unsigned hash;
            unsigned char length;
        };

        static const NameEntry kNames[] = {
            { "IndexedDB", 4847824, 9 },
            { "add", 2199543, 3 },
            { "clear", 12832795, 5 },
            { "delete", 16564367, 6 },
            { "done", 11685723, 4 },
            { "next", 13682113, 4 },
            { "nextunique", 15395501, 10 },
            { "none", 3454253, 4 },
            { "pending", 1181072, 7 },
            { "prev", 6676561, 4 },
            { "prevunique", 7206471, 10 },
            { "put", 3938797, 3 },
            { "readonly", 4471832, 8 },
            { "readwrite", 15868712, 9 },
            { "total", 1584834, 5 },
            { "versionchange", 1334380, 13 },
        };

        for (size_t i = 0; i < WTF_ARRAY_LENGTH(kNames); i++) {
            StringImpl* stringImpl = StringImpl::createStatic(kNames[i].name, kNames[i].length, kNames[i].hash);
            void* address = reinterpret_cast<AtomicString*>(&NamesStorage) + i;
            new (address) AtomicString(stringImpl);
        }
    }

} // IndexedDBNames
} // namespace blink
