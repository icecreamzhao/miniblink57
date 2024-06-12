// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "V8ConsoleBase.h"
#include "config.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "core/frame/UseCounter.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "third_party/WebKit/Source/core/page/ChromeClient.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

static void logMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (info.Length() < 1)
        return;

    v8::Local<v8::Value> value = info[0];
    if (!value->IsString())
        return;

    v8::Local<v8::String> stringInfo = value->ToString();
    v8::String::Utf8Value stringInfoUtf8(stringInfo);
//     OutputDebugStringA(*utf8);
//     OutputDebugStringA("\n");

    int lineNumber = 0;
    String stack;
    String url;

    const v8::StackTrace::StackTraceOptions options = static_cast<v8::StackTrace::StackTraceOptions>(
        v8::StackTrace::kLineNumber
        | v8::StackTrace::kColumnOffset
        | v8::StackTrace::kScriptId
        | v8::StackTrace::kScriptNameOrSourceURL
        | v8::StackTrace::kFunctionName);

    int stackNum = 50;
    v8::HandleScope handleScope(info.GetIsolate());
    v8::Local<v8::StackTrace> stackTrace(v8::StackTrace::CurrentStackTrace(info.GetIsolate(), stackNum, options));
    int count = stackTrace->GetFrameCount();

    for (int i = 0; i < count; ++i) {
        v8::Local<v8::StackFrame> stackFrame = stackTrace->GetFrame(info.GetIsolate(), i);
        int frameCount = stackTrace->GetFrameCount();
        int line = stackFrame->GetLineNumber();
        v8::Local<v8::String> scriptName = stackFrame->GetScriptNameOrSourceURL();
        v8::Local<v8::String> funcName = stackFrame->GetFunctionName();

        std::string scriptNameWTF;
        std::string funcNameWTF;

        if (!scriptName.IsEmpty()) {
            v8::String::Utf8Value scriptNameUtf8(scriptName);
            scriptNameWTF = *scriptNameUtf8;
        }

        if (!funcName.IsEmpty()) {
            v8::String::Utf8Value funcNameUtf8(funcName);
            funcNameWTF = *funcNameUtf8;
        }

        stack.append(String::format("line:%d, [", line));

        if (!scriptNameWTF.empty()) {
            stack.append(scriptNameWTF.c_str());
        }
        stack.append("] , [");

        if (!funcNameWTF.empty()) {
            stack.append(funcNameWTF.c_str());
        }
        stack.append("]\n");

        if (0 == i) {
            lineNumber = line;
            url = scriptNameWTF.c_str();
        }
    }
    stack.append("\n");

    Document& document = *toDocument(currentExecutionContext(info.GetIsolate()));
    document.frame()->chromeClient().addMessageToConsole(document.frame(), ConsoleAPIMessageSource, LogMessageLevel, String(*stringInfoUtf8), lineNumber, url, stack);

}

static void addFunction(v8::Isolate* isolate, v8::Local<v8::FunctionTemplate> tmpl, const char* name, v8::FunctionCallback callback)
{
    v8::Local<v8::ObjectTemplate> objectTemplate = tmpl->InstanceTemplate();
    if (objectTemplate.IsEmpty())
        return;

    v8::Local<v8::FunctionTemplate> functionTemplate = v8::FunctionTemplate::New(isolate, callback);
    objectTemplate->Set(v8::String::NewFromUtf8(isolate, name, v8::NewStringType::kNormal, -1).ToLocalChecked(), functionTemplate);
}

static void installV8ConsoleBaseTemplate(v8::Local<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    functionTemplate->SetClassName(v8::String::NewFromUtf8(isolate, "Console"));

    addFunction(isolate, functionTemplate, "assert", logMethodCallback);
    addFunction(isolate, functionTemplate, "clear", logMethodCallback);
    addFunction(isolate, functionTemplate, "count", logMethodCallback);
    addFunction(isolate, functionTemplate, "error", logMethodCallback);
    addFunction(isolate, functionTemplate, "group", logMethodCallback);
    addFunction(isolate, functionTemplate, "groupCollapsed", logMethodCallback);
    addFunction(isolate, functionTemplate, "groupEnd", logMethodCallback);
    addFunction(isolate, functionTemplate, "info", logMethodCallback);
    addFunction(isolate, functionTemplate, "log", logMethodCallback);
    addFunction(isolate, functionTemplate, "table", logMethodCallback);
    addFunction(isolate, functionTemplate, "time", logMethodCallback);
    addFunction(isolate, functionTemplate, "warn", logMethodCallback);
    addFunction(isolate, functionTemplate, "timeEnd", logMethodCallback);
    addFunction(isolate, functionTemplate, "trace", logMethodCallback);
    addFunction(isolate, functionTemplate, "timeStamp", logMethodCallback);    

    //     v8::Local<v8::ObjectTemplate> instanceTemplate = functionTemplate->InstanceTemplate();
    //     ALLOW_UNUSED_LOCAL(instanceTemplate);
    //     v8::Local<v8::ObjectTemplate> prototypeTemplate = functionTemplate->PrototypeTemplate();
    //     ALLOW_UNUSED_LOCAL(prototypeTemplate);
}

v8::Local<v8::FunctionTemplate> V8ConsoleBase::domTemplate(v8::Isolate* isolate)
{
    v8::Local<v8::FunctionTemplate> result = v8::FunctionTemplate::New(isolate, nullptr);
    installV8ConsoleBaseTemplate(result, isolate);
    return result;
}
//
// bool V8ConsoleBase::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
// {
//     return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
// }
//
// v8::Local<v8::Object> V8ConsoleBase::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
// {
//     return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
// }
//
// ConsoleBase* V8ConsoleBase::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
// {
//     return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : 0;
// }
//
// void V8ConsoleBase::refObject(ScriptWrappable* scriptWrappable)
// {
// }
//
// void V8ConsoleBase::derefObject(ScriptWrappable* scriptWrappable)
// {
// }

} // namespace blink
