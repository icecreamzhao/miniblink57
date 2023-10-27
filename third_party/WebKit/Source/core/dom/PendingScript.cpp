/*
 * Copyright (C) 2010 Google, Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "core/dom/PendingScript.h"

#include "bindings/core/v8/ScriptSourceCode.h"
#include "bindings/core/v8/ModuleRecord.h"
#include "bindings/core/v8/Modulator.h"
#include "core/dom/ModuleScriptLoader.h"
#include "core/dom/Element.h"
#include "core/frame/SubresourceIntegrity.h"
#include "core/html/parser/HTMLParserIdioms.h"
#include "platform/SharedBuffer.h"
#include "wtf/CurrentTime.h"

namespace blink {

//const char* kInlineScriptUrl = "inline_script_url";

PendingScript* PendingScript::create(Element* element,
    ScriptResource* resource)
{
    return new PendingScript(element, resource);
}

PendingScript::PendingScript(Element* element, ScriptResource* resource)
    : m_watchingForLoad(false)
    , m_element(element)
    , m_integrityFailure(false)
    , m_parserBlockingLoadStartTime(0)
    //////////////////////////////////////////////////////////////////////////
    , m_isModule(false)
    , m_hadGetModuleDepend(false)
    //////////////////////////////////////////////////////////////////////////
    , m_client(nullptr)
{
    if (element)
        m_isModule = equalIgnoringCase(m_element->getAttribute(HTMLNames::typeAttr), "module");

    setScriptResource(resource);
    MemoryCoordinator::instance().registerClient(this);
}

PendingScript::~PendingScript() { }

void PendingScript::dispose()
{
    stopWatchingForLoad();
    DCHECK(!m_client);
    DCHECK(!m_watchingForLoad);

    setScriptResource(nullptr);
    m_startingPosition = TextPosition::belowRangePosition();
    m_integrityFailure = false;
    m_parserBlockingLoadStartTime = 0;
    if (m_streamer)
        m_streamer->cancel();
    m_streamer = nullptr;
    m_element = nullptr;
}

void PendingScript::watchForLoad(PendingScriptClient* client)
{
    DCHECK(!m_watchingForLoad);
    // addClient() will call streamingFinished() if the load is complete. Callers
    // who do not expect to be re-entered from this call should not call
    // watchForLoad for a PendingScript which isReady. We also need to set
    // m_watchingForLoad early, since addClient() can result in calling
    // notifyFinished and further stopWatchingForLoad().
    m_watchingForLoad = true;
    m_client = client;
    if (isReady())
        m_client->pendingScriptFinished(this);
}

void PendingScript::stopWatchingForLoad()
{
    if (!m_watchingForLoad)
        return;
    DCHECK(resource());
    m_client = nullptr;
    m_watchingForLoad = false;
}

void PendingScript::streamingFinished()
{
    DCHECK(resource());
    if (m_client)
        m_client->pendingScriptFinished(this);
}

void PendingScript::setElement(Element* element)
{
    m_element = element;
    if (element)
        m_isModule = equalIgnoringCase(m_element->getAttribute(HTMLNames::typeAttr), "module");
}

void PendingScript::setScriptResource(ScriptResource* resource)
{
    setResource(resource);
}

void PendingScript::markParserBlockingLoadStartTime()
{
    DCHECK_EQ(m_parserBlockingLoadStartTime, 0.0);
    m_parserBlockingLoadStartTime = monotonicallyIncreasingTime();
}

void PendingScript::notifyFinished(Resource* resource)
{
    // The following SRI checks need to be here because, unfortunately, fetches
    // are not done purely according to the Fetch spec. In particular,
    // different requests for the same resource do not have different
    // responses; the memory cache can (and will) return the exact same
    // Resource object.
    //
    // For different requests, the same Resource object will be returned and
    // will not be associated with the particular request.  Therefore, when the
    // body of the response comes in, there's no way to validate the integrity
    // of the Resource object against a particular request (since there may be
    // several pending requests all tied to the identical object, and the
    // actual requests are not stored).
    //
    // In order to simulate the correct behavior, Blink explicitly does the SRI
    // checks here, when a PendingScript tied to a particular request is
    // finished (and in the case of a StyleSheet, at the point of execution),
    // while having proper Fetch checks in the fetch module for use in the
    // fetch JavaScript API. In a future world where the ResourceFetcher uses
    // the Fetch algorithm, this should be fixed by having separate Response
    // objects (perhaps attached to identical Resource objects) per request.
    //
    // See https://crbug.com/500701 for more information.
    if (m_element) {
        DCHECK_EQ(resource->getType(), Resource::Script);
        ScriptResource* scriptResource = toScriptResource(resource);
        String integrityAttr = m_element->fastGetAttribute(HTMLNames::integrityAttr);

        // It is possible to get back a script resource with integrity metadata
        // for a request with an empty integrity attribute. In that case, the
        // integrity check should be skipped, so this check ensures that the
        // integrity attribute isn't empty in addition to checking if the
        // resource has empty integrity metadata.
        if (!integrityAttr.isEmpty() && !scriptResource->integrityMetadata().isEmpty()) {
            ResourceIntegrityDisposition disposition = scriptResource->integrityDisposition();
            if (disposition == ResourceIntegrityDisposition::Failed) {
                // TODO(jww): This should probably also generate a console
                // message identical to the one produced by
                // CheckSubresourceIntegrity below. See https://crbug.com/585267.
                m_integrityFailure = true;
            } else if (disposition == ResourceIntegrityDisposition::NotChecked && resource->resourceBuffer()) {
                m_integrityFailure = !SubresourceIntegrity::CheckSubresourceIntegrity(
                    scriptResource->integrityMetadata(), *m_element,
                    resource->resourceBuffer()->data(),
                    resource->resourceBuffer()->size(), resource->url(), *resource);
                scriptResource->setIntegrityDisposition(
                    m_integrityFailure ? ResourceIntegrityDisposition::Failed
                                       : ResourceIntegrityDisposition::Passed);
            }
        }
    }

    // If script streaming is in use, the client will be notified in
    // streamingFinished.
    if (m_streamer)
        m_streamer->notifyFinished(resource);
    else if (m_client)
        m_client->pendingScriptFinished(this);
}

void PendingScript::notifyAppendData(ScriptResource* resource)
{
    if (m_streamer)
        m_streamer->notifyAppendData(resource);
}

DEFINE_TRACE(PendingScript)
{
    visitor->trace(m_element);
    visitor->trace(m_streamer);
    visitor->trace(m_client);
    ResourceOwner<ScriptResource>::trace(visitor);
    MemoryCoordinatorClient::trace(visitor);
}

ScriptSourceCode PendingScript::getSource(const KURL& documentURL, bool& errorOccurred) const
{
    if (resource()) {
        errorOccurred = resource()->errorOccurred() || m_integrityFailure;
        DCHECK(resource()->isLoaded());
        if (m_streamer && !m_streamer->streamingSuppressed())
            return ScriptSourceCode(m_streamer, resource());
        return ScriptSourceCode(resource());
    } else if (hasModuleScriptString()) {
        return ScriptSourceCode(m_moduleScriptString, documentURL);
    }
    errorOccurred = false;
    return ScriptSourceCode(m_element->textContent(), documentURL,
        startingPosition());
}

void PendingScript::setStreamer(ScriptStreamer* streamer)
{
    DCHECK(!m_streamer);
    DCHECK(!m_watchingForLoad);
    m_streamer = streamer;
}

bool PendingScript::isReady() const
{
    if (resource() && !resource()->isLoaded())
        return false;
    if (m_streamer && !m_streamer->isFinished())
        return false;
    return true;
}

bool PendingScript::errorOccurred() const
{
    if (resource())
        return resource()->errorOccurred();
    if (m_streamer && m_streamer->resource())
        return m_streamer->resource()->errorOccurred();
    return false;
}

void PendingScript::onMemoryStateChange(MemoryState state)
{
    if (state != MemoryState::SUSPENDED)
        return;
    if (!m_streamer)
        return;
    m_streamer->cancel();
    m_streamer = nullptr;
}

//////////////////////////////////////////////////////////////////////////
// module
bool PendingScript::isModule() const
{
    return m_isModule;
}

bool PendingScript::hadGetModuleDepend() const
{
    return m_hadGetModuleDepend;
}

void PendingScript::setGetModuleDepend()
{
    DCHECK(m_isModule && !m_hadGetModuleDepend);
    m_hadGetModuleDepend = true;
}

bool PendingScript::requesetModuleScript(Document* document, const ModuleRecord* parentModuleRecord, const String& sourceUrl, ScriptPromiseResolver* resolver)
{
    m_isModule = true;

    if (stripLeadingAndTrailingHTMLSpaces(sourceUrl).isEmpty())
        return false;

    KURL url = document->completeURL(sourceUrl);
    if (parentModuleRecord)
        url = KURL(parentModuleRecord->url(), sourceUrl);

    m_moduleScriptLoader = ModuleScriptLoader::create(document, url, resolver ? FetchRequest::NoDefer : FetchRequest::LazyLoad);
    if (!m_moduleScriptLoader)
        return false;

    ScriptState* scriptState = ScriptState::forMainWorld(document->frame());
    v8::Isolate* isolate = scriptState->isolate();
    v8::Isolate::Scope isoldateScope(isolate);
    v8::HandleScope handleScope(isolate);

    m_moduleRecord = new ModuleRecord(url, scriptState->isolate(), v8::Local<v8::Module>(), resolver);
    Modulator* modulator = Modulator::from(scriptState->context());
    modulator->add(m_moduleRecord);
    m_moduleScriptLoader->setModulator(modulator);

    setScriptResource(m_moduleScriptLoader->resource());
    return true;
}

void PendingScript::setModuleScriptString(const String& str)
{
    m_moduleScriptString = str;
}

bool PendingScript::hasModuleScriptString() const
{
    return !m_moduleScriptString.isEmpty();
}

Vector<String> PendingScript::compileModuleAndRequestDepend(HTMLParserScriptRunner* scriptRunner, Document* document)
{
    setGetModuleDepend();

    ScriptState* scriptState = ScriptState::forMainWorld(document->frame());
    v8::Isolate* isolate = scriptState->isolate();
    v8::Isolate::Scope isoldateScope(isolate);
    v8::HandleScope handleScope(isolate);
    v8::EscapableHandleScope escapableHandleScope(isolate);
    ScriptState::Scope scope(scriptState);

    KURL url = document->url();
    if (resource())
        url = resource()->url();
    
    v8::ScriptOrigin origin(
        v8String(isolate, url.getUTF8String()),
        v8::Integer::New(isolate, startingPosition().m_line.zeroBasedInt()),
        v8::Integer::New(isolate, startingPosition().m_column.zeroBasedInt()),
        v8::Boolean::New(isolate, true),   // resource_is_shared_cross_origin
        v8::Local<v8::Integer>(),          // script id
        v8::String::Empty(isolate),        // source_map_url
        v8::Boolean::New(isolate, false),  // resource_is_opaque
        v8::False(isolate),                // is_wasm
        v8::True(isolate)                  // is_module
    );

    bool errorOccurred = false;
    double loadFinishTime = resource() && resource()->url().protocolIsInHTTPFamily() ? resource()->loadFinishTime() : 0;
    ScriptSourceCode sourceCode = getSource(/*documentURLForScriptExecution(document)*/document->url(), errorOccurred);

    Vector<String> ret;
    v8::Local<v8::String> code = v8String(isolate, sourceCode.source());
    v8::ScriptCompiler::Source source(code, origin);
    v8::MaybeLocal<v8::Module> v8module = v8::ScriptCompiler::CompileModule(isolate, &source);

    if (v8module.IsEmpty())
        return ret;

    v8::Local<v8::Module> module = v8module.ToLocalChecked();
    if (!m_moduleRecord.get()) {
        m_moduleRecord = new ModuleRecord(url, isolate, module, nullptr);
    } else {
        m_moduleRecord->setModule(isolate, module); // 里面会调用m_parentResolver->resolve
    }
    Modulator* modulator = Modulator::from(scriptState->context());
    modulator->setScriptRunner(scriptRunner);
    modulator->add(m_moduleRecord);

    int length = module->GetModuleRequestsLength();
    for (int i = 0; i < length; ++i) {
        v8::Local<v8::String> v8name = module->GetModuleRequest(i);
        ret.append(toCoreString(v8name));
    }

    return ret;
}
//////////////////////////////////////////////////////////////////////////

} // namespace blink
