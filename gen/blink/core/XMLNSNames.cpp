// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "XMLNSNames.h"

#include "wtf/PtrUtil.h"
#include "wtf/StaticConstructors.h"
#include "wtf/StdLibExtras.h"
#include <memory>

namespace blink {
namespace XMLNSNames {

    using namespace blink;

    DEFINE_GLOBAL(AtomicString, xmlnsNamespaceURI);

    // Attributes

    void* AttrStorage[XMLNSAttrsCount * ((sizeof(QualifiedName) + sizeof(void*) - 1) / sizeof(void*))];

    const QualifiedName& xmlnsAttr = reinterpret_cast<QualifiedName*>(&AttrStorage)[0];

    std::unique_ptr<const QualifiedName* []> getXMLNSAttrs() {
        std::unique_ptr<const QualifiedName*[]> attrs = wrapArrayUnique(new const QualifiedName*[XMLNSAttrsCount]);
        for (size_t i = 0; i < XMLNSAttrsCount; i++)
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
        AtomicString xmlnsNS("http://www.w3.org/2000/xmlns/");

        // Namespace
        new ((void*)&xmlnsNamespaceURI) AtomicString(xmlnsNS);
        static const NameEntry kNames[] = {
            { "xmlns", 171597, 5, 0, 1 },
        };

        size_t attr_i = 0;
        for (size_t i = 0; i < WTF_ARRAY_LENGTH(kNames); i++) {
            StringImpl* stringImpl = StringImpl::createStatic(kNames[i].name, kNames[i].length, kNames[i].hash);
            void* address = reinterpret_cast<QualifiedName*>(&AttrStorage) + attr_i;
            QualifiedName::createStatic(address, stringImpl, xmlnsNS);
            attr_i++;
        }
        ASSERT(attr_i == XMLNSAttrsCount);
    }

} // XMLNS
} // namespace blink
