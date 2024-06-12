// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.h.tmpl

// clang-format on
#ifndef V8RTCPeerConnection_h
#define V8RTCPeerConnection_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8Binding.h"
#include "bindings/core/v8/V8DOMWrapper.h"
#include "bindings/core/v8/V8EventTarget.h"
#include "bindings/core/v8/WrapperTypeInfo.h"
#include "bindings/modules/v8/DictionaryOrString.h"
#include "bindings/modules/v8/RTCIceCandidateInitOrRTCIceCandidate.h"
#include "modules/ModulesExport.h"
#include "modules/peerconnection/RTCPeerConnection.h"
#include "platform/heap/Handle.h"

namespace blink {

class V8RTCPeerConnection {
    STATIC_ONLY(V8RTCPeerConnection);

public:
    MODULES_EXPORT static bool hasInstance(v8::Local<v8::Value>, v8::Isolate*);
    static v8::Local<v8::Object> findInstanceInPrototypeChain(v8::Local<v8::Value>, v8::Isolate*);
    MODULES_EXPORT static v8::Local<v8::FunctionTemplate> domTemplate(v8::Isolate*, const DOMWrapperWorld&);
    static RTCPeerConnection* toImpl(v8::Local<v8::Object> object)
    {
        return toScriptWrappable(object)->toImpl<RTCPeerConnection>();
    }
    MODULES_EXPORT static RTCPeerConnection* toImplWithTypeCheck(v8::Isolate*, v8::Local<v8::Value>);
    MODULES_EXPORT static const WrapperTypeInfo wrapperTypeInfo;
    template <typename VisitorDispatcher>
    static void trace(VisitorDispatcher visitor, ScriptWrappable* scriptWrappable)
    {
        visitor->trace(scriptWrappable->toImpl<RTCPeerConnection>());
    }
    static void traceWrappers(WrapperVisitor* visitor, ScriptWrappable* scriptWrappable)
    {
        visitor->traceWrappers(scriptWrappable->toImpl<RTCPeerConnection>());
    }
    static void constructorCallback(const v8::FunctionCallbackInfo<v8::Value>&);
    static const int eventListenerCacheIndex = v8DefaultWrapperInternalFieldCount + 0;
    static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 1;
};

template <>
struct V8TypeOf<RTCPeerConnection> {
    typedef V8RTCPeerConnection Type;
};

} // namespace blink

#endif // V8RTCPeerConnection_h
