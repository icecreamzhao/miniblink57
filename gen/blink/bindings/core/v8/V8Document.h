// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.h.tmpl

// clang-format on
#ifndef V8Document_h
#define V8Document_h

#include "bindings/core/v8/HTMLScriptElementOrSVGScriptElement.h"
#include "bindings/core/v8/NodeOrString.h"
#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/core/v8/StringOrDictionary.h"
#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8Binding.h"
#include "bindings/core/v8/V8DOMWrapper.h"
#include "bindings/core/v8/V8Node.h"
#include "bindings/core/v8/WrapperTypeInfo.h"
#include "core/CoreExport.h"
#include "core/dom/Document.h"
#include "platform/heap/Handle.h"

namespace blink {

class V8Document {
    STATIC_ONLY(V8Document);

public:
    CORE_EXPORT static bool hasInstance(v8::Local<v8::Value>, v8::Isolate*);
    static v8::Local<v8::Object> findInstanceInPrototypeChain(v8::Local<v8::Value>, v8::Isolate*);
    CORE_EXPORT static v8::Local<v8::FunctionTemplate> domTemplate(v8::Isolate*, const DOMWrapperWorld&);
    static Document* toImpl(v8::Local<v8::Object> object)
    {
        return toScriptWrappable(object)->toImpl<Document>();
    }
    CORE_EXPORT static Document* toImplWithTypeCheck(v8::Isolate*, v8::Local<v8::Value>);
    CORE_EXPORT static const WrapperTypeInfo wrapperTypeInfo;
    template <typename VisitorDispatcher>
    static void trace(VisitorDispatcher visitor, ScriptWrappable* scriptWrappable)
    {
        visitor->trace(scriptWrappable->toImpl<Document>());
    }
    static void traceWrappers(WrapperVisitor* visitor, ScriptWrappable* scriptWrappable)
    {
        visitor->traceWrappers(scriptWrappable->toImpl<Document>());
    }
    static void openMethodCustom(const v8::FunctionCallbackInfo<v8::Value>&);
    static void createTouchMethodPrologueCustom(const v8::FunctionCallbackInfo<v8::Value>&, Document*);
    static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 0;
    CORE_EXPORT static void preparePrototypeAndInterfaceObject(v8::Local<v8::Context>, const DOMWrapperWorld&, v8::Local<v8::Object> prototypeObject, v8::Local<v8::Function> interfaceObject, v8::Local<v8::FunctionTemplate> interfaceTemplate);

    CORE_EXPORT static void installRuntimeEnabledFeatures(
        v8::Isolate* isolate,
        const DOMWrapperWorld& world,
        v8::Local<v8::Object> instance,
        v8::Local<v8::Object> prototype,
        v8::Local<v8::Function> interface);
};

template <>
struct V8TypeOf<Document> {
    typedef V8Document Type;
};

} // namespace blink

#endif // V8Document_h
