// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef MutationObserverInit_h
#define MutationObserverInit_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"
#include "wtf/Vector.h"
#include "wtf/text/WTFString.h"

namespace blink {

class CORE_EXPORT MutationObserverInit : public IDLDictionaryBase {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    MutationObserverInit();
    virtual ~MutationObserverInit();
    MutationObserverInit(const MutationObserverInit&);
    MutationObserverInit& operator=(const MutationObserverInit&);

    bool hasAttributeFilter() const;
    const Vector<String>& attributeFilter() const;
    void setAttributeFilter(const Vector<String>&);

    bool hasAttributeOldValue() const;
    bool attributeOldValue() const;
    void setAttributeOldValue(bool);

    bool hasAttributes() const;
    bool attributes() const;
    void setAttributes(bool);

    bool hasCharacterData() const;
    bool characterData() const;
    void setCharacterData(bool);

    bool hasCharacterDataOldValue() const;
    bool characterDataOldValue() const;
    void setCharacterDataOldValue(bool);

    bool hasChildList() const;
    bool childList() const;
    void setChildList(bool);

    bool hasSubtree() const;
    bool subtree() const;
    void setSubtree(bool);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    bool m_hasAttributeFilter = false;
    Vector<String> m_attributeFilter;
    bool m_hasAttributeOldValue = false;
    bool m_attributeOldValue;
    bool m_hasAttributes = false;
    bool m_attributes;
    bool m_hasCharacterData = false;
    bool m_characterData;
    bool m_hasCharacterDataOldValue = false;
    bool m_characterDataOldValue;
    bool m_hasChildList = false;
    bool m_childList;
    bool m_hasSubtree = false;
    bool m_subtree;

    friend class V8MutationObserverInit;
};

} // namespace blink

#endif // MutationObserverInit_h
