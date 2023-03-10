// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/partial_interface.cpp.tmpl

// clang-format on
#include "V8DataTransferItemPartial.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8DataTransferItem.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8Entry.h"
#include "core/dom/Document.h"
#include "core/frame/UseCounter.h"
#include "modules/filesystem/DataTransferItemFileSystem.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

namespace DataTransferItemPartialV8Internal {

    static void webkitGetAsEntryMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        DataTransferItem* impl = V8DataTransferItem::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        Entry* result = DataTransferItemFileSystem::webkitGetAsEntry(scriptState, *impl);
        v8SetReturnValue(info, result);
    }

    void webkitGetAsEntryMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8DataTransferItem_WebkitGetAsEntry_Method);
        DataTransferItemPartialV8Internal::webkitGetAsEntryMethod(info);
    }

} // namespace DataTransferItemPartialV8Internal

const V8DOMConfiguration::MethodConfiguration V8DataTransferItemMethods[] = {
    { "webkitGetAsEntry", DataTransferItemPartialV8Internal::webkitGetAsEntryMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8DataTransferItemPartial::installV8DataTransferItemTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DataTransferItem::installV8DataTransferItemTemplate(isolate, world, interfaceTemplate);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8DataTransferItemMethods, WTF_ARRAY_LENGTH(V8DataTransferItemMethods));
}

void V8DataTransferItemPartial::initialize()
{
    // Should be invoked from ModulesInitializer.
    V8DataTransferItem::updateWrapperTypeInfo(
        &V8DataTransferItemPartial::installV8DataTransferItemTemplate,
        nullptr);
}

} // namespace blink
