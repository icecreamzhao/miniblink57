// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/partial_interface.cpp.tmpl

// clang-format on
#include "V8URLPartial.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8URL.h"
#include "bindings/modules/v8/V8MediaSource.h"
#include "bindings/modules/v8/V8MediaStream.h"
#include "core/dom/Document.h"
#include "modules/mediasource/URLMediaSource.h"
#include "modules/mediastream/URLMediaStream.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

namespace DOMURLPartialV8Internal {

    static void createObjectURL2Method(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaSource* source;
        source = V8MediaSource::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!source) {
          V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("createObjectURL", "URL", "parameter 1 is not of type 'MediaSource'."));
        
          return;
        }
        
        ExecutionContext* executionContext = currentExecutionContext(info.GetIsolate());
        v8SetReturnValueString(info, URLMediaSource::createObjectURL(executionContext, source), info.GetIsolate());
    }

    static void createObjectURL3Method(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MediaStream* stream;
        stream = V8MediaStream::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!stream) {
          V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("createObjectURL", "URL", "parameter 1 is not of type 'MediaStream'."));
        
          return;
        }
        
        ExecutionContext* executionContext = currentExecutionContext(info.GetIsolate());
        v8SetReturnValueString(info, URLMediaStream::createObjectURL(executionContext, stream), info.GetIsolate());
    }

    static void createObjectURLMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        bool isArityError = false;
        switch (std::min(1, info.Length())) {
          case 1:
            if (V8MediaSource::hasInstance(info[0], info.GetIsolate())) {
              createObjectURL2Method(info);
              return;
            }
            if (V8MediaStream::hasInstance(info[0], info.GetIsolate())) {
              createObjectURL3Method(info);
              return;
            }
            break;
          default:
            isArityError = true;
        }
        
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URL", "createObjectURL");
        
        if (isArityError) {
          if (info.Length() < 1) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
          }
        }
        exceptionState.throwTypeError("No function was found that matched the signature provided.");
        //exceptionState.throwTypeError("'createObjectURL' not implemented.");
    }

} // namespace DOMURLPartialV8Internal

void V8URLPartial::installV8URLTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8URL::installV8URLTemplate(isolate, world, interfaceTemplate);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
}

void V8URLPartial::initialize()
{
    // Should be invoked from ModulesInitializer.
    V8URL::updateWrapperTypeInfo(&V8URLPartial::installV8URLTemplate, nullptr);
    V8URL::registerCreateObjectURLMethodForPartialInterface(&DOMURLPartialV8Internal::createObjectURLMethod);
}

} // namespace blink
