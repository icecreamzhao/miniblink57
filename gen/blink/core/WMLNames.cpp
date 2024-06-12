// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "WMLNames.h"

#include "wtf/PtrUtil.h"
#include "wtf/StaticConstructors.h"
#include "wtf/StdLibExtras.h"
#include <memory>

namespace blink {
namespace WMLNames {

    using namespace blink;

    DEFINE_GLOBAL(AtomicString, wmlNamespaceURI);

    // Tags

    void* TagStorage[WMLTagsCount * ((sizeof(WMLQualifiedName) + sizeof(void*) - 1) / sizeof(void*))];
    const WMLQualifiedName& aTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[0];
    const WMLQualifiedName& accessTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[1];
    const WMLQualifiedName& anchorTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[2];
    const WMLQualifiedName& brTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[3];
    const WMLQualifiedName& cardTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[4];
    const WMLQualifiedName& doTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[5];
    const WMLQualifiedName& fieldsetTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[6];
    const WMLQualifiedName& goTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[7];
    const WMLQualifiedName& headTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[8];
    const WMLQualifiedName& imgTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[9];
    const WMLQualifiedName& insertedLegendTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[10];
    const WMLQualifiedName& metaTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[11];
    const WMLQualifiedName& noopTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[12];
    const WMLQualifiedName& oneventTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[13];
    const WMLQualifiedName& pTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[14];
    const WMLQualifiedName& postfieldTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[15];
    const WMLQualifiedName& prevTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[16];
    const WMLQualifiedName& refreshTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[17];
    const WMLQualifiedName& setvarTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[18];
    const WMLQualifiedName& tableTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[19];
    const WMLQualifiedName& tdTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[20];
    const WMLQualifiedName& templateTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[21];
    const WMLQualifiedName& timerTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[22];
    const WMLQualifiedName& trTag = reinterpret_cast<WMLQualifiedName*>(&TagStorage)[23];

    std::unique_ptr<const WMLQualifiedName* []> getWMLTags() {
        std::unique_ptr<const WMLQualifiedName*[]> tags = wrapArrayUnique(new const WMLQualifiedName*[WMLTagsCount]);
        for (size_t i = 0; i < WMLTagsCount; i++)
            tags[i] = reinterpret_cast<WMLQualifiedName*>(&TagStorage) + i;
        return tags;
    }

    // Attributes

    void* AttrStorage[WMLAttrsCount * ((sizeof(QualifiedName) + sizeof(void*) - 1) / sizeof(void*))];

    const QualifiedName& cache_controlAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[0];
    const QualifiedName& columnsAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[1];
    const QualifiedName& domainAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[2];
    const QualifiedName& emptyokAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[3];
    const QualifiedName& formatAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[4];
    const QualifiedName& foruaAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[5];
    const QualifiedName& inameAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[6];
    const QualifiedName& ivalueAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[7];
    const QualifiedName& localsrcAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[8];
    const QualifiedName& modeAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[9];
    const QualifiedName& newcontextAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[10];
    const QualifiedName& onenterbackwardAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[11];
    const QualifiedName& onenterforwardAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[12];
    const QualifiedName& onpickAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[13];
    const QualifiedName& ontimerAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[14];
    const QualifiedName& optionalAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[15];
    const QualifiedName& orderedAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[16];
    const QualifiedName& pathAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[17];
    const QualifiedName& sendrefererAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[18];

    std::unique_ptr<const QualifiedName* []> getWMLAttrs() {
        std::unique_ptr<const QualifiedName*[]> attrs = wrapArrayUnique(new const QualifiedName*[WMLAttrsCount]);
        for (size_t i = 0; i < WMLAttrsCount; i++)
            attrs[i] = reinterpret_cast<QualifiedName*>(&AttrStorage) + i;
        return attrs;
    }

    void init()
    {
        struct NameEntry {
            const char* name;
            unsigned hash;
            unsigned char length;
            unsigned char isTag;
            unsigned char isAttr;
        };

        // Use placement new to initialize the globals.
        AtomicString wmlNS("http://www.wapforum.org/DTD/wml_1.1.xml");

        // Namespace
        new ((void*)&wmlNamespaceURI) AtomicString(wmlNS);
        static const NameEntry kNames[] = {
            { "a", 9778235, 1, 1, 0 },
            { "access", 13594634, 6, 1, 0 },
            { "anchor", 8937022, 6, 1, 0 },
            { "br", 5574895, 2, 1, 0 },
            { "cache_control", 11148089, 13, 0, 1 },
            { "card", 7739820, 4, 1, 0 },
            { "columns", 9254985, 7, 0, 1 },
            { "do", 1956281, 2, 1, 0 },
            { "domain", 8206185, 6, 0, 1 },
            { "emptyok", 15880031, 7, 0, 1 },
            { "fieldset", 37097, 8, 1, 0 },
            { "format", 15152429, 6, 0, 1 },
            { "forua", 4387259, 5, 0, 1 },
            { "go", 16685295, 2, 1, 0 },
            { "head", 11457121, 4, 1, 0 },
            { "img", 11398162, 3, 1, 0 },
            { "iname", 11227929, 5, 0, 1 },
            { "insertedLegend", 4841704, 14, 1, 0 },
            { "ivalue", 664083, 6, 0, 1 },
            { "localsrc", 8808944, 8, 0, 1 },
            { "meta", 14067019, 4, 1, 0 },
            { "mode", 13319651, 4, 0, 1 },
            { "newcontext", 7362028, 10, 0, 1 },
            { "noop", 12141407, 4, 1, 0 },
            { "onenterbackward", 1010694, 15, 0, 1 },
            { "onenterforward", 5756549, 14, 0, 1 },
            { "onevent", 11805589, 7, 1, 0 },
            { "onpick", 4811196, 6, 0, 1 },
            { "ontimer", 898775, 7, 0, 1 },
            { "optional", 8952406, 8, 0, 1 },
            { "ordered", 3568446, 7, 0, 1 },
            { "p", 587733, 1, 1, 0 },
            { "path", 14212236, 4, 0, 1 },
            { "postfield", 13730460, 9, 1, 0 },
            { "prev", 6676561, 4, 1, 0 },
            { "refresh", 8002580, 7, 1, 0 },
            { "sendreferer", 13922707, 11, 0, 1 },
            { "setvar", 14712717, 6, 1, 0 },
            { "table", 8181317, 5, 1, 0 },
            { "td", 10309076, 2, 1, 0 },
            { "template", 12693000, 8, 1, 0 },
            { "timer", 7670808, 5, 1, 0 },
            { "tr", 16624306, 2, 1, 0 },
        };

        size_t tag_i = 0;
        size_t attr_i = 0;
        for (size_t i = 0; i < WTF_ARRAY_LENGTH(kNames); i++) {
            StringImpl* stringImpl = StringImpl::createStatic(kNames[i].name, kNames[i].length, kNames[i].hash);
            if (kNames[i].isTag) {
                void* address = reinterpret_cast<WMLQualifiedName*>(&TagStorage) + tag_i;
                QualifiedName::createStatic(address, stringImpl, wmlNS);
                tag_i++;
            }

            if (!kNames[i].isAttr)
                continue;
            void* address = reinterpret_cast<QualifiedName*>(&AttrStorage) + attr_i;
            QualifiedName::createStatic(address, stringImpl);
            attr_i++;
        }
        ASSERT(tag_i == WMLTagsCount);
        ASSERT(attr_i == WMLAttrsCount);
    }

} // WML
} // namespace blink
