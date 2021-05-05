// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WMLNames_h
#define WMLNames_h

#include "core/dom/QualifiedName.h"
#include <memory>

namespace blink {

class WMLQualifiedName : public QualifiedName {
};

namespace WMLNames {

    // Namespace
    extern const WTF::AtomicString& wmlNamespaceURI;

    // Tags
    extern const blink::WMLQualifiedName& headTag;
    extern const blink::WMLQualifiedName& tdTag;
    extern const blink::WMLQualifiedName& trTag;
    extern const blink::WMLQualifiedName& aTag;
    extern const blink::WMLQualifiedName& accessTag;
    extern const blink::WMLQualifiedName& anchorTag;
    extern const blink::WMLQualifiedName& brTag;
    extern const blink::WMLQualifiedName& cardTag;
    extern const blink::WMLQualifiedName& doTag;
    extern const blink::WMLQualifiedName& fieldsetTag;
    extern const blink::WMLQualifiedName& goTag;
    extern const blink::WMLQualifiedName& imgTag;
    extern const blink::WMLQualifiedName& insertedLegendTag;
    extern const blink::WMLQualifiedName& metaTag;
    extern const blink::WMLQualifiedName& noopTag;
    extern const blink::WMLQualifiedName& oneventTag;
    extern const blink::WMLQualifiedName& pTag;
    extern const blink::WMLQualifiedName& postfieldTag;
    extern const blink::WMLQualifiedName& prevTag;
    extern const blink::WMLQualifiedName& refreshTag;
    extern const blink::WMLQualifiedName& setvarTag;
    extern const blink::WMLQualifiedName& tableTag;
    extern const blink::WMLQualifiedName& templateTag;
    extern const blink::WMLQualifiedName& timerTag;

    // Attributes
    extern const blink::QualifiedName& cache_controlAttr;
    extern const blink::QualifiedName& columnsAttr;
    extern const blink::QualifiedName& domainAttr;
    extern const blink::QualifiedName& emptyokAttr;
    extern const blink::QualifiedName& formatAttr;
    extern const blink::QualifiedName& foruaAttr;
    extern const blink::QualifiedName& inameAttr;
    extern const blink::QualifiedName& ivalueAttr;
    extern const blink::QualifiedName& localsrcAttr;
    extern const blink::QualifiedName& modeAttr;
    extern const blink::QualifiedName& newcontextAttr;
    extern const blink::QualifiedName& onenterbackwardAttr;
    extern const blink::QualifiedName& onenterforwardAttr;
    extern const blink::QualifiedName& onpickAttr;
    extern const blink::QualifiedName& ontimerAttr;
    extern const blink::QualifiedName& optionalAttr;
    extern const blink::QualifiedName& orderedAttr;
    extern const blink::QualifiedName& pathAttr;
    extern const blink::QualifiedName& sendrefererAttr;

    const unsigned WMLTagsCount = 24;
    std::unique_ptr<const WMLQualifiedName*[]> getWMLTags();

    const unsigned WMLAttrsCount = 19;
    std::unique_ptr<const QualifiedName*[]> getWMLAttrs();

    void init();

} // WMLNames
} // namespace blink

#endif
