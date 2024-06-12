// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8IDBIndex.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8IDBObjectStore.h"
#include "bindings/modules/v8/V8IDBRequest.h"
#include "core/dom/Document.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8IDBIndex::wrapperTypeInfo = { gin::kEmbedderBlink, V8IDBIndex::domTemplate, V8IDBIndex::trace, V8IDBIndex::traceWrappers, 0, nullptr, "IDBIndex", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in IDBIndex.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& IDBIndex::s_wrapperTypeInfo = V8IDBIndex::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, IDBIndex>::value,
    "IDBIndex inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&IDBIndex::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "IDBIndex is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace IDBIndexV8Internal {

    static void nameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        IDBIndex* impl = V8IDBIndex::toImpl(holder);

        v8SetReturnValueString(info, impl->name(), info.GetIsolate());
    }

    MODULES_EXPORT void nameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::nameAttributeGetter(info);
    }

    static void nameAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        IDBIndex* impl = V8IDBIndex::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "IDBIndex", "name");

        // Prepare the value to be set.
        V8StringResource<> cppValue = v8Value;
        if (!cppValue.prepare())
            return;

        impl->setName(cppValue, exceptionState);
    }

    MODULES_EXPORT void nameAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        IDBIndexV8Internal::nameAttributeSetter(v8Value, info);
    }

    static void objectStoreAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        IDBIndex* impl = V8IDBIndex::toImpl(holder);

        IDBObjectStore* cppValue(WTF::getPtr(impl->objectStore()));

        // Keep the wrapper object for the return value alive as long as |this|
        // object is alive in order to save creation time of the wrapper object.
        if (cppValue && DOMDataStore::setReturnValue(info.GetReturnValue(), cppValue))
            return;
        v8::Local<v8::Value> v8Value(ToV8(cppValue, holder, info.GetIsolate()));
        const char kKeepAliveKey[] = "KeepAlive#IDBIndex#objectStore";
        V8HiddenValue::setHiddenValue(ScriptState::current(info.GetIsolate()), holder, v8AtomicString(info.GetIsolate(), StringView(kKeepAliveKey, sizeof kKeepAliveKey)), v8Value);

        v8SetReturnValue(info, v8Value);
    }

    MODULES_EXPORT void objectStoreAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::objectStoreAttributeGetter(info);
    }

    static void keyPathAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        IDBIndex* impl = V8IDBIndex::toImpl(holder);

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        v8SetReturnValue(info, impl->keyPath(scriptState).v8Value());
    }

    MODULES_EXPORT void keyPathAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::keyPathAttributeGetter(info);
    }

    static void multiEntryAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        IDBIndex* impl = V8IDBIndex::toImpl(holder);

        v8SetReturnValueBool(info, impl->multiEntry());
    }

    MODULES_EXPORT void multiEntryAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::multiEntryAttributeGetter(info);
    }

    static void uniqueAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        IDBIndex* impl = V8IDBIndex::toImpl(holder);

        v8SetReturnValueBool(info, impl->unique());
    }

    MODULES_EXPORT void uniqueAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::uniqueAttributeGetter(info);
    }

    static void getMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "IDBIndex", "get");

        IDBIndex* impl = V8IDBIndex::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        ScriptValue key;
        key = ScriptValue(ScriptState::current(info.GetIsolate()), info[0]);

        IDBRequest* result = impl->get(scriptState, key, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    MODULES_EXPORT void getMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::getMethod(info);
    }

    static void getKeyMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "IDBIndex", "getKey");

        IDBIndex* impl = V8IDBIndex::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        ScriptValue key;
        key = ScriptValue(ScriptState::current(info.GetIsolate()), info[0]);

        IDBRequest* result = impl->getKey(scriptState, key, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    MODULES_EXPORT void getKeyMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::getKeyMethod(info);
    }

    static void getAllMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "IDBIndex", "getAll");

        IDBIndex* impl = V8IDBIndex::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        ScriptValue range;
        unsigned maxCount;
        range = ScriptValue(ScriptState::current(info.GetIsolate()), info[0]);

        if (!info[1]->IsUndefined()) {
            maxCount = toUInt32(info.GetIsolate(), info[1], EnforceRange, exceptionState);
            if (exceptionState.hadException())
                return;
        } else {
            maxCount = 4294967295u;
        }

        IDBRequest* result = impl->getAll(scriptState, range, maxCount, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    MODULES_EXPORT void getAllMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::getAllMethod(info);
    }

    static void getAllKeysMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "IDBIndex", "getAllKeys");

        IDBIndex* impl = V8IDBIndex::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        ScriptValue range;
        unsigned maxCount;
        range = ScriptValue(ScriptState::current(info.GetIsolate()), info[0]);

        if (!info[1]->IsUndefined()) {
            maxCount = toUInt32(info.GetIsolate(), info[1], EnforceRange, exceptionState);
            if (exceptionState.hadException())
                return;
        } else {
            maxCount = 4294967295u;
        }

        IDBRequest* result = impl->getAllKeys(scriptState, range, maxCount, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    MODULES_EXPORT void getAllKeysMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::getAllKeysMethod(info);
    }

    static void countMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "IDBIndex", "count");

        IDBIndex* impl = V8IDBIndex::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        ScriptValue key;
        key = ScriptValue(ScriptState::current(info.GetIsolate()), info[0]);

        IDBRequest* result = impl->count(scriptState, key, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    MODULES_EXPORT void countMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::countMethod(info);
    }

    static void openCursorMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "IDBIndex", "openCursor");

        IDBIndex* impl = V8IDBIndex::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        ScriptValue range;
        V8StringResource<> direction;
        range = ScriptValue(ScriptState::current(info.GetIsolate()), info[0]);

        if (!info[1]->IsUndefined()) {
            direction = info[1];
            if (!direction.prepare())
                return;
            const char* validDirectionValues[] = {
                "next",
                "nextunique",
                "prev",
                "prevunique",
            };
            if (!isValidEnum(direction, validDirectionValues, WTF_ARRAY_LENGTH(validDirectionValues), "IDBCursorDirection", exceptionState)) {
                return;
            }
        } else {
            direction = String("next");
        }

        IDBRequest* result = impl->openCursor(scriptState, range, direction, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    MODULES_EXPORT void openCursorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::openCursorMethod(info);
    }

    static void openKeyCursorMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "IDBIndex", "openKeyCursor");

        IDBIndex* impl = V8IDBIndex::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        ScriptValue range;
        V8StringResource<> direction;
        range = ScriptValue(ScriptState::current(info.GetIsolate()), info[0]);

        if (!info[1]->IsUndefined()) {
            direction = info[1];
            if (!direction.prepare())
                return;
            const char* validDirectionValues[] = {
                "next",
                "nextunique",
                "prev",
                "prevunique",
            };
            if (!isValidEnum(direction, validDirectionValues, WTF_ARRAY_LENGTH(validDirectionValues), "IDBCursorDirection", exceptionState)) {
                return;
            }
        } else {
            direction = String("next");
        }

        IDBRequest* result = impl->openKeyCursor(scriptState, range, direction, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    MODULES_EXPORT void openKeyCursorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        IDBIndexV8Internal::openKeyCursorMethod(info);
    }

} // namespace IDBIndexV8Internal

const V8DOMConfiguration::AccessorConfiguration V8IDBIndexAccessors[] = {
    { "name", IDBIndexV8Internal::nameAttributeGetterCallback, IDBIndexV8Internal::nameAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "objectStore", IDBIndexV8Internal::objectStoreAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "keyPath", IDBIndexV8Internal::keyPathAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "multiEntry", IDBIndexV8Internal::multiEntryAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "unique", IDBIndexV8Internal::uniqueAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8IDBIndexMethods[] = {
    { "get", IDBIndexV8Internal::getMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "getKey", IDBIndexV8Internal::getKeyMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "getAll", IDBIndexV8Internal::getAllMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "getAllKeys", IDBIndexV8Internal::getAllKeysMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "count", IDBIndexV8Internal::countMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "openCursor", IDBIndexV8Internal::openCursorMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "openKeyCursor", IDBIndexV8Internal::openKeyCursorMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8IDBIndexTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8IDBIndex::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8IDBIndex::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8IDBIndexAccessors, WTF_ARRAY_LENGTH(V8IDBIndexAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8IDBIndexMethods, WTF_ARRAY_LENGTH(V8IDBIndexMethods));
}

v8::Local<v8::FunctionTemplate> V8IDBIndex::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8IDBIndexTemplate);
}

bool V8IDBIndex::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8IDBIndex::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

IDBIndex* V8IDBIndex::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink
