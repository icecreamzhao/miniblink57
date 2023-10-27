// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "config.h"
#include "bindings/core/v8/Modulator.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/html/parser/HTMLParserScriptRunner.h"
#include "core/dom/Document.h"
#include "public/platform/Platform.h"
#include "wtf/StdLibExtras.h"

namespace blink {

Modulator::Modulator()
{

}

Modulator::~Modulator()
{

}

// MyScriptPromiseResolver::MyScriptPromiseResolver(v8::Local<v8::Context> context, v8::Local<v8::Promise::Resolver> resolver)
// {
//     m_context = new v8::Persistent<v8::Context>(context->GetIsolate(), context);
//     m_resolver = new v8::Persistent<v8::Promise::Resolver>(context->GetIsolate(), resolver);
// }
// 
// void MyScriptPromiseResolver::reject()
// {
//     v8::Isolate* isolate = v8::Isolate::GetCurrent();
//     v8::HandleScope handleScope(isolate);
//     v8::Local<v8::Promise::Resolver> resolverLocal = m_resolver->Get(isolate);
//     v8::Local<v8::Context> contextLocal = m_context->Get(isolate);
// 
//     resolverLocal->Reject(contextLocal, v8::Undefined(isolate));
// 
//     m_resolver->Reset();
//     m_context->Reset();
//     delete m_resolver;
//     delete m_context;
//     m_resolver = nullptr;
//     m_context = nullptr;
// }
// 
// void MyScriptPromiseResolver::resolve(v8::Local<v8::Value> val)
// {
//     v8::Isolate* isolate = v8::Isolate::GetCurrent();
//     v8::HandleScope handleScope(isolate);
//     v8::Local<v8::Promise::Resolver> resolverLocal = m_resolver->Get(isolate);
//     v8::Local<v8::Context> contextLocal = m_context->Get(isolate);
// 
//     resolverLocal->Resolve(contextLocal, val);
// 
//     m_resolver->Reset();
//     m_context->Reset();
//     delete m_resolver;
//     delete m_context;
//     m_resolver = nullptr;
//     m_context = nullptr;
// }

void Modulator::resolveDynamically(
    ScriptState* scriptState,
    const String& specifier,
    const KURL& url,
    //const ReferrerScriptInfo&,
    ScriptPromiseResolver* resolver)
{
    RELEASE_ASSERT(scriptState);
    if (!m_scriptState) {
        m_scriptState = scriptState;
    } else {
        RELEASE_ASSERT(scriptState == m_scriptState);
    }
    m_scriptState->ref();

//     char* output = (char*)malloc(0x100);
//     sprintf_s(output, 0x99, "Modulator::resolveDynamically: this:%p, m_scriptState:%p\n", this, m_scriptState);
//     OutputDebugStringA(output);
//     free(output);

    Platform::current()->mainThread()->postTask(FROM_HERE,
        WTF::bind(&Modulator::resolveDynamicallyDelay, wrapPersistent(this), specifier, url, wrapPersistent(resolver)));
}

void Modulator::resolveDynamicallyDelay(
    const String& specifier,
    const KURL& url,
    //const ReferrerScriptInfo&,
    ScriptPromiseResolver* resolver)
{
    do {
        if (!m_scriptRunner.get())
            break;

//         char* output = (char*)malloc(0x100);
//         sprintf_s(output, 0x99, "Modulator::resolveDynamicallyDelay: this:%p, m_scriptState:%p ScriptPromiseResolver:%p\n", this, m_scriptState, resolver);
//         OutputDebugStringA(output);
//         free(output);

        LocalDOMWindow* domWin = m_scriptState->domWindow();
        if (!domWin)
            break;
        Document* document = domWin->document();
        if (!document)
            break;

        LocalFrame* frame = document->frame();
        if (!frame) 
            break;

        KURL urlFull(url, specifier);
        bool b = m_scriptRunner->requestPendingModuleScript(document, /*parentModuleRecord*/nullptr, urlFull.getUTF8String(), resolver);
        if (b)
            resolver = nullptr;
    } while (false);

    m_scriptState->deref();

    if (resolver)
        resolver->reject();
}

void Modulator::shutdown()
{
    HeapHashMap<String, Member<ModuleRecord>>::iterator it = m_moduleRecordUrlMap.begin();
    for (; it != m_moduleRecordUrlMap.end(); ++it) {
        ModuleRecord* rec = it->value.get();
        rec->clearModule();
    }
}

void Modulator::setScriptRunner(HTMLParserScriptRunner* scriptRunner)
{
    DCHECK(!m_scriptRunner || m_scriptRunner == scriptRunner);
    m_scriptRunner = scriptRunner;
}

void Modulator::onModuleScriptLoader()
{
    if (m_scriptRunner.get())
        m_scriptRunner->executeScriptsWaitingForParsing();
}

void Modulator::add(ModuleRecord* record)
{
    if (-1 != record->getIdHash())
        m_moduleRecordIdMap.add(record->getIdHash(), record);

    m_moduleRecordUrlMap.add(record->url().getUTF8String(), record);
}

ModuleRecord* Modulator::getModuleRecordById(int id)
{
    HeapHashMap<int, Member<ModuleRecord>>::iterator it = m_moduleRecordIdMap.find(id);
    if (it != m_moduleRecordIdMap.end())
        return it->value.get();
    return nullptr;
}

ModuleRecord* Modulator::getModuleRecordByUrl(const KURL& url)
{
    HeapHashMap<String, Member<ModuleRecord>>::iterator it = m_moduleRecordUrlMap.find(url.getUTF8String());
    if (it != m_moduleRecordUrlMap.end())
        return it->value.get();
    return nullptr;
}

Modulator* Modulator::from(v8::Local<v8::Context> context)
{
    ScriptState* scriptState = ScriptState::from(context);
    if (!scriptState)
        return nullptr;
    return scriptState->modulator();
}

DEFINE_TRACE(Modulator)
{
    visitor->trace(m_moduleRecordIdMap);
    visitor->trace(m_moduleRecordUrlMap);
    visitor->trace(m_scriptRunner);
}

} // namespace blink
