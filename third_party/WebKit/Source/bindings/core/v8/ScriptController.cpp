/*
 * Copyright (C) 2008, 2009 Google Inc. All rights reserved.
 * Copyright (C) 2009 Apple Inc. All rights reserved.
 * Copyright (C) 2014 Opera Software ASA. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "bindings/core/v8/ScriptController.h"

#include "bindings/core/v8/ScriptSourceCode.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/V8Binding.h"
#include "bindings/core/v8/V8Event.h"
#include "bindings/core/v8/V8GCController.h"
#include "bindings/core/v8/V8HTMLElement.h"
#include "bindings/core/v8/V8PerContextData.h"
#include "bindings/core/v8/V8ScriptRunner.h"
#include "bindings/core/v8/V8Window.h"
#include "bindings/core/v8/WindowProxy.h"
#include "core/dom/Document.h"
#include "core/dom/Node.h"
#include "core/dom/ScriptableDocumentParser.h"
#include "core/events/Event.h"
#include "core/events/EventListener.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/Settings.h"
#include "core/frame/UseCounter.h"
#include "core/frame/csp/ContentSecurityPolicy.h"
#include "core/html/HTMLPlugInElement.h"
#include "core/inspector/ConsoleMessage.h"
#include "core/inspector/InspectorInstrumentation.h"
#include "core/inspector/InspectorTraceEvents.h"
#include "core/inspector/MainThreadDebugger.h"
#include "core/loader/DocumentLoader.h"
#include "core/loader/FrameLoader.h"
#include "core/loader/FrameLoaderClient.h"
#include "core/loader/NavigationScheduler.h"
#include "core/loader/ProgressTracker.h"
#include "core/plugins/PluginView.h"
#include "platform/Histogram.h"
#include "platform/UserGestureIndicator.h"
#include "platform/Widget.h"
#include "platform/instrumentation/tracing/TraceEvent.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/Platform.h"
#include "wtf/CurrentTime.h"
#include "wtf/StdLibExtras.h"
#include "wtf/StringExtras.h"
#include "wtf/text/CString.h"
#include "wtf/text/StringBuilder.h"
#include "wtf/text/TextPosition.h"
#ifndef DISABLE_NPAPI
#include "bindings/core/v8/npruntime_impl.h"
#include "bindings/core/v8/npruntime_priv.h"
#include "bindings/core/v8/NPV8Object.h"
#include "bindings/core/v8/V8NPObject.h"
#include "core/html/HTMLPluginElement.h"
#endif

namespace blink {

ScriptController::ScriptController(LocalFrame* frame)
    : m_windowProxyManager(LocalWindowProxyManager::create(*frame))
#ifndef DISABLE_NPAPI
    , m_pluginObjects(new PluginObjectMap())
    , m_windowScriptNPObject(nullptr)
#endif
{
}

DEFINE_TRACE(ScriptController)
{
    visitor->trace(m_windowProxyManager);
}

void ScriptController::clearForClose()
{
    m_windowProxyManager->clearForClose();
    MainThreadDebugger::instance()->didClearContextsForFrame(frame());
}

void ScriptController::updateSecurityOrigin(SecurityOrigin* securityOrigin)
{
    m_windowProxyManager->updateSecurityOrigin(securityOrigin);
}

namespace {

    V8CacheOptions cacheOptions(const ScriptResource* resource,
        const Settings* settings)
    {
        V8CacheOptions v8CacheOptions(V8CacheOptionsDefault);
        if (settings)
            v8CacheOptions = settings->getV8CacheOptions();
        if (resource && !resource->response().cacheStorageCacheName().isNull()) {
            switch (settings->getV8CacheStrategiesForCacheStorage()) {
            case V8CacheStrategiesForCacheStorage::None:
                v8CacheOptions = V8CacheOptionsNone;
                break;
            case V8CacheStrategiesForCacheStorage::Normal:
                v8CacheOptions = V8CacheOptionsCode;
                break;
            case V8CacheStrategiesForCacheStorage::Default:
            case V8CacheStrategiesForCacheStorage::Aggressive:
                v8CacheOptions = V8CacheOptionsAlways;
                break;
            }
        }
        return v8CacheOptions;
    }

} // namespace

v8::Local<v8::Value> ScriptController::executeScriptAndReturnValue(
    v8::Local<v8::Context> context,
    const ScriptSourceCode& source,
    AccessControlStatus accessControlStatus)
{
    TRACE_EVENT1("devtools.timeline", "EvaluateScript", "data",
        InspectorEvaluateScriptEvent::data(
            frame(), source.url().getString(), source.startPosition()));
    InspectorInstrumentation::NativeBreakpoint nativeBreakpoint(
        frame()->document(), "scriptFirstStatement", false);

    v8::Local<v8::Value> result;
    {
        V8CacheOptions v8CacheOptions = cacheOptions(source.resource(), frame()->settings());

        // Isolate exceptions that occur when compiling and executing
        // the code. These exceptions should not interfere with
        // javascript code we might evaluate from C++ when returning
        // from here.
        v8::TryCatch tryCatch(isolate());
        tryCatch.SetVerbose(true);

        v8::Local<v8::Script> script;
        if (!v8Call(V8ScriptRunner::compileScript(
                        source, isolate(), accessControlStatus, v8CacheOptions),
                script, tryCatch))
            return result;

        if (!v8Call(V8ScriptRunner::runCompiledScript(isolate(), script,
                        frame()->document()),
                result, tryCatch))
            return result;
    }

    TRACE_EVENT_INSTANT1(TRACE_DISABLED_BY_DEFAULT("devtools.timeline"),
        "UpdateCounters", TRACE_EVENT_SCOPE_THREAD, "data",
        InspectorUpdateCountersEvent::data());

    return result;
}

LocalWindowProxy* ScriptController::windowProxy(DOMWrapperWorld& world)
{
    LocalWindowProxy* windowProxy = m_windowProxyManager->windowProxy(world);
    windowProxy->initializeIfNeeded();
    return windowProxy;
}

bool ScriptController::shouldBypassMainWorldCSP()
{
    v8::HandleScope handleScope(isolate());
    v8::Local<v8::Context> context = isolate()->GetCurrentContext();
    if (context.IsEmpty() || !toDOMWindow(context))
        return false;
    DOMWrapperWorld& world = DOMWrapperWorld::current(isolate());
    return world.isIsolatedWorld() ? world.isolatedWorldHasContentSecurityPolicy()
                                   : false;
}

TextPosition ScriptController::eventHandlerPosition() const
{
    ScriptableDocumentParser* parser = frame()->document()->scriptableDocumentParser();
    if (parser)
        return parser->textPosition();
    return TextPosition::minimumPosition();
}

void ScriptController::enableEval()
{
    v8::HandleScope handleScope(isolate());
    v8::Local<v8::Context> v8Context = m_windowProxyManager->mainWorldProxy()->contextIfInitialized();
    if (v8Context.IsEmpty())
        return;
    v8Context->AllowCodeGenerationFromStrings(true);
}

void ScriptController::disableEval(const String& errorMessage)
{
    v8::HandleScope handleScope(isolate());
    v8::Local<v8::Context> v8Context = m_windowProxyManager->mainWorldProxy()->contextIfInitialized();
    if (v8Context.IsEmpty())
        return;
    v8Context->AllowCodeGenerationFromStrings(false);
    v8Context->SetErrorMessageForCodeGenerationFromStrings(
        v8String(isolate(), errorMessage));
}

PassRefPtr<SharedPersistent<v8::Object>> ScriptController::createPluginWrapper(
    Widget* widget)
{
    ASSERT(widget);

    if (!widget->isPluginView())
        return nullptr;

    v8::HandleScope handleScope(isolate());
    v8::Local<v8::Object> scriptableObject = toPluginView(widget)->scriptableObject(isolate());

    if (scriptableObject.IsEmpty())
        return nullptr;

    return SharedPersistent<v8::Object>::create(scriptableObject, isolate());
}

V8Extensions& ScriptController::registeredExtensions()
{
    DEFINE_STATIC_LOCAL(V8Extensions, extensions, ());
    return extensions;
}

void ScriptController::registerExtensionIfNeeded(v8::Extension* extension)
{
    const V8Extensions& extensions = registeredExtensions();
    for (size_t i = 0; i < extensions.size(); ++i) {
        if (extensions[i] == extension)
            return;
    }
    v8::RegisterExtension(extension);
    registeredExtensions().push_back(extension);
}

void ScriptController::clearWindowProxy()
{
#ifndef DISABLE_NPAPI
    clearScriptObjects();
#endif
    // V8 binding expects ScriptController::clearWindowProxy only be called when a
    // frame is loading a new page. This creates a new context for the new page.
    m_windowProxyManager->clearForNavigation();
    MainThreadDebugger::instance()->didClearContextsForFrame(frame());
}

void ScriptController::updateDocument()
{
    m_windowProxyManager->mainWorldProxy()->updateDocument();
}

bool ScriptController::canExecuteScripts(
    ReasonForCallingCanExecuteScripts reason)
{

    if (frame()->document() && frame()->document()->isSandboxed(SandboxScripts)) {
        // FIXME: This message should be moved off the console once a solution to
        // https://bugs.webkit.org/show_bug.cgi?id=103274 exists.
        if (reason == AboutToExecuteScript)
            frame()->document()->addConsoleMessage(ConsoleMessage::create(
                SecurityMessageSource, ErrorMessageLevel,
                "Blocked script execution in '" + frame()->document()->url().elidedString() + "' because the document's frame is sandboxed and the "
                                                                                              "'allow-scripts' permission is not set."));
        return false;
    }

    if (frame()->document() && frame()->document()->isViewSource()) {
        ASSERT(frame()->document()->getSecurityOrigin()->isUnique());
        return true;
    }

    FrameLoaderClient* client = frame()->loader().client();
    if (!client)
        return false;
    Settings* settings = frame()->settings();
    const bool allowed = client->allowScript(settings && settings->getScriptEnabled());
    if (!allowed && reason == AboutToExecuteScript)
        client->didNotAllowScript();
    return allowed;
}

bool ScriptController::executeScriptIfJavaScriptURL(const KURL& url,
    Element* element)
{
    if (!protocolIsJavaScript(url))
        return false;

    bool shouldBypassMainWorldContentSecurityPolicy = ContentSecurityPolicy::shouldBypassMainWorld(frame()->document());
    if (!frame()->page() || (!shouldBypassMainWorldContentSecurityPolicy && !frame()->document()->contentSecurityPolicy()->allowJavaScriptURLs(element, frame()->document()->url(), eventHandlerPosition().m_line))) {
        return true;
    }

    bool progressNotificationsNeeded = frame()->loader().stateMachine()->isDisplayingInitialEmptyDocument() && !frame()->isLoading();
    if (progressNotificationsNeeded)
        frame()->loader().progress().progressStarted();

    Document* ownerDocument = frame()->document();

    const int javascriptSchemeLength = sizeof("javascript:") - 1;

    bool locationChangeBefore = frame()->navigationScheduler().locationChangePending();

    String decodedURL = decodeURLEscapeSequences(url.getString());
    v8::HandleScope handleScope(isolate());
    v8::Local<v8::Value> result = evaluateScriptInMainWorld(
        ScriptSourceCode(decodedURL.substring(javascriptSchemeLength)),
        NotSharableCrossOrigin, DoNotExecuteScriptWhenScriptsDisabled);

    // If executing script caused this frame to be removed from the page, we
    // don't want to try to replace its document!
    if (!frame()->page())
        return true;

    if (result.IsEmpty() || !result->IsString()) {
        if (progressNotificationsNeeded)
            frame()->loader().progress().progressCompleted();
        return true;
    }
    String scriptResult = toCoreString(v8::Local<v8::String>::Cast(result));

    // We're still in a frame, so there should be a DocumentLoader.
    ASSERT(frame()->document()->loader());
    if (!locationChangeBefore && frame()->navigationScheduler().locationChangePending())
        return true;

    frame()->loader().replaceDocumentWhileExecutingJavaScriptURL(scriptResult,
        ownerDocument);
    return true;
}

void ScriptController::executeScriptInMainWorld(const String& script,
    ExecuteScriptPolicy policy)
{
    v8::HandleScope handleScope(isolate());
    evaluateScriptInMainWorld(ScriptSourceCode(script), NotSharableCrossOrigin,
        policy);
}

void ScriptController::executeScriptInMainWorld(
    const ScriptSourceCode& sourceCode,
    AccessControlStatus accessControlStatus)
{
    v8::HandleScope handleScope(isolate());
    evaluateScriptInMainWorld(sourceCode, accessControlStatus,
        DoNotExecuteScriptWhenScriptsDisabled);
}

v8::Local<v8::Value> ScriptController::executeScriptInMainWorldAndReturnValue(
    const ScriptSourceCode& sourceCode,
    ExecuteScriptPolicy policy)
{
    return evaluateScriptInMainWorld(sourceCode, NotSharableCrossOrigin, policy);
}

v8::Local<v8::Value> ScriptController::evaluateScriptInMainWorld(
    const ScriptSourceCode& sourceCode,
    AccessControlStatus accessControlStatus,
    ExecuteScriptPolicy policy)
{
    if (policy == DoNotExecuteScriptWhenScriptsDisabled && !canExecuteScripts(AboutToExecuteScript))
        return v8::Local<v8::Value>();

    ScriptState* scriptState = ScriptState::forMainWorld(frame());
    if (!scriptState)
        return v8::Local<v8::Value>();
    v8::EscapableHandleScope handleScope(isolate());
    ScriptState::Scope scope(scriptState);

    if (frame()->loader().stateMachine()->isDisplayingInitialEmptyDocument())
        frame()->loader().didAccessInitialDocument();

    v8::Local<v8::Value> object = executeScriptAndReturnValue(
        scriptState->context(), sourceCode, accessControlStatus);

    if (object.IsEmpty())
        return v8::Local<v8::Value>();

    return handleScope.Escape(object);
}

void ScriptController::executeScriptInIsolatedWorld(
    int worldID,
    const HeapVector<ScriptSourceCode>& sources,
    Vector<v8::Local<v8::Value>>* results)
{
    ASSERT(worldID > 0);

    RefPtr<DOMWrapperWorld> world = DOMWrapperWorld::ensureIsolatedWorld(isolate(), worldID);
    LocalWindowProxy* isolatedWorldWindowProxy = windowProxy(*world);
    ScriptState* scriptState = isolatedWorldWindowProxy->getScriptState();
    if (!scriptState->contextIsValid())
        return;
    v8::Context::Scope scope(scriptState->context());
    v8::Local<v8::Array> resultArray = v8::Array::New(isolate(), sources.size());

    for (size_t i = 0; i < sources.size(); ++i) {
        v8::Local<v8::Value> evaluationResult = executeScriptAndReturnValue(scriptState->context(), sources[i]);
        if (evaluationResult.IsEmpty())
            evaluationResult = v8::Local<v8::Value>::New(isolate(), v8::Undefined(isolate()));
        if (!v8CallBoolean(resultArray->CreateDataProperty(scriptState->context(),
                i, evaluationResult)))
            return;
    }

    if (results) {
        for (size_t i = 0; i < resultArray->Length(); ++i) {
            v8::Local<v8::Value> value;
            if (!resultArray->Get(scriptState->context(), i).ToLocal(&value))
                return;
            results->push_back(value);
        }
    }
}

#ifndef DISABLE_NPAPI

void* ScriptController::createPluginWrapper(void* widget)
{
    //   ASSERT(widget);
    // 
    // //   if (!widget->isPluginView())
    // //     return nullptr;
    // 
    //   v8::HandleScope handleScope(isolate());
    //   v8::Local<v8::Object> scriptableObject = toPluginView(widget)->scriptableObject(isolate());
    // 
    //   if (scriptableObject.IsEmpty())
    //     return nullptr;
    // 
    //   // LocalFrame Memory Management for NPObjects
    //   // -------------------------------------
    //   // NPObjects are treated differently than other objects wrapped by JS.
    //   // NPObjects can be created either by the browser (e.g. the main
    //   // window object) or by the plugin (the main plugin object
    //   // for a HTMLEmbedElement). Further, unlike most DOM Objects, the frame
    //   // is especially careful to ensure NPObjects terminate at frame teardown because
    //   // if a plugin leaks a reference, it could leak its objects (or the browser's objects).
    //   //
    //   // The LocalFrame maintains a list of plugin objects (m_pluginObjects)
    //   // which it can use to quickly find the wrapped embed object.
    //   //
    //   // Inside the NPRuntime, we've added a few methods for registering
    //   // wrapped NPObjects. The purpose of the registration is because
    //   // javascript garbage collection is non-deterministic, yet we need to
    //   // be able to tear down the plugin objects immediately. When an object
    //   // is registered, javascript can use it. When the object is destroyed,
    //   // or when the object's "owning" object is destroyed, the object will
    //   // be un-registered, and the javascript engine must not use it.
    //   //
    //   // Inside the javascript engine, the engine can keep a reference to the
    //   // NPObject as part of its wrapper. However, before accessing the object
    //   // it must consult the _NPN_Registry.
    // 
    //   if (isWrappedNPObject(scriptableObject)) {
    //     // Track the plugin object. We've been given a reference to the object.
    //     m_pluginObjects->set(widget, v8ObjectToNPObject(scriptableObject));
    //   }
    // 
    //   return SharedPersistent<v8::Object>::create(scriptableObject, isolate());
    return nullptr;
}

void ScriptController::cleanupScriptObjectsForPlugin(void* nativeHandle)
{
    PluginObjectMap::iterator it = m_pluginObjects->find(nativeHandle);
    if (it == m_pluginObjects->end())
        return;
    _NPN_UnregisterObject(it->value);
    _NPN_ReleaseObject(it->value);
    m_pluginObjects->remove(it);
}

void ScriptController::clearScriptObjects()
{
    PluginObjectMap::iterator it = m_pluginObjects->begin();
    for (; it != m_pluginObjects->end(); ++it) {
        _NPN_UnregisterObject(it->value);
        _NPN_ReleaseObject(it->value);
    }
    m_pluginObjects->clear();

    if (m_windowScriptNPObject) {
        // Dispose of the underlying V8 object before releasing our reference
        // to it, so that if a plugin fails to release it properly we will
        // only leak the NPObject wrapper, not the object, its document, or
        // anything else they reference.
        disposeUnderlyingV8Object(isolate(), m_windowScriptNPObject);
        _NPN_ReleaseObject(m_windowScriptNPObject);
        m_windowScriptNPObject = nullptr;
    }
}

static NPObject* createNoScriptObject()
{
    DebugBreak();
    return 0;
}

static NPObject* createScriptObject(LocalFrame* frame, v8::Isolate* isolate)
{
    v8::HandleScope handleScope(isolate);
    ScriptState* scriptState = ScriptState::from(toV8ContextEvenIfDetached(frame, DOMWrapperWorld::mainWorld()));

    if (!scriptState->contextIsValid())
        return createNoScriptObject();

    ScriptState::Scope scope(scriptState);
    LocalDOMWindow* window = frame->domWindow();
    v8::Local<v8::Value> global = ToV8((ScriptWrappable*)window, scriptState->context()->Global(), scriptState->isolate());
    if (global.IsEmpty())
        return createNoScriptObject();
    DCHECK(global->IsObject());
    return npCreateV8ScriptObject(isolate, 0, v8::Local<v8::Object>::Cast(global), window);
}

NPObject* ScriptController::windowScriptNPObject()
{
    if (m_windowScriptNPObject)
        return m_windowScriptNPObject;

    m_windowScriptNPObject = createScriptObject(frame(), isolate());
    _NPN_RegisterObject(m_windowScriptNPObject, 0);

    return m_windowScriptNPObject;
}

NPObject* ScriptController::createScriptObjectForPluginElement(HTMLPlugInElement* plugin)
{
    // Can't create NPObjects when JavaScript is disabled.
    v8::HandleScope handleScope(isolate());
    ScriptState* scriptState = ScriptState::from(toV8ContextEvenIfDetached(frame(), DOMWrapperWorld::mainWorld()));

    if (!scriptState->contextIsValid())
        return createNoScriptObject();

    ScriptState::Scope scope(scriptState);
    LocalDOMWindow* window = frame()->domWindow();
    v8::Local<v8::Value> v8plugin = ToV8(plugin, scriptState->context()->Global(), scriptState->isolate());
    if (v8plugin.IsEmpty() || !v8plugin->IsObject())
        return createNoScriptObject();

    return npCreateV8ScriptObject(scriptState->isolate(), 0, v8::Local<v8::Object>::Cast(v8plugin), window);
}

bool ScriptController::bindToWindowObject(LocalFrame*, const String& key, NPObject* object)
{
    v8::HandleScope handleScope(isolate());
    ScriptState* scriptState = ScriptState::from(toV8ContextEvenIfDetached(frame(), DOMWrapperWorld::mainWorld()));

    if (!scriptState->contextIsValid())
        return false;

    ScriptState::Scope scope(scriptState);
    v8::Local<v8::Object> value = createV8ObjectForNPObject(isolate(), object, 0);

    // Attach to the global object.
    v8::Maybe<bool> maybe = scriptState->context()->Global()->Set(scriptState->context(), v8String(isolate(), key), value);
    if (maybe.IsNothing())
        return false;
    return maybe.FromJust();
}

ScriptController::~ScriptController()
{
    delete m_pluginObjects;
}

#endif // DISABLE_NPAPI

} // namespace blink
