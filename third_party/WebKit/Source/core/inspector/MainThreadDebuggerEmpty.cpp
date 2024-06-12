/*
 * Copyright (c) 2011 Google Inc. All rights reserved.
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

#include "core/inspector/MainThreadDebugger.h"

#include "bindings/core/v8/BindingSecurity.h"
#include "bindings/core/v8/DOMWrapperWorld.h"
#include "bindings/core/v8/ScriptController.h"
#include "bindings/core/v8/SourceLocation.h"
#include "bindings/core/v8/V8Node.h"
#include "bindings/core/v8/V8Window.h"
#include "core/dom/ContainerNode.h"
#include "core/dom/Document.h"
#include "core/dom/Element.h"
#include "core/dom/ExecutionContext.h"
#include "core/dom/StaticNodeList.h"
#include "core/frame/FrameConsole.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/UseCounter.h"
#include "core/inspector/ConsoleMessage.h"
#include "core/inspector/IdentifiersFactory.h"
#include "core/inspector/InspectedFrames.h"
#include "core/inspector/InspectorTaskRunner.h"
#include "core/timing/MemoryInfo.h"
#include "core/workers/MainThreadWorkletGlobalScope.h"
#include "core/xml/XPathEvaluator.h"
#include "core/xml/XPathResult.h"
#include "platform/UserGestureIndicator.h"
//#include "platform/v8_inspector/public/V8Debugger.h"
#include "wtf/PtrUtil.h"
#include "wtf/ThreadingPrimitives.h"
#include <memory>

namespace blink {

namespace {

    int frameId(LocalFrame* frame)
    {
        ASSERT(frame);
        return WeakIdentifierMap<LocalFrame>::identifier(frame);
    }

    Mutex& creationMutex()
    {
        DEFINE_THREAD_SAFE_STATIC_LOCAL(Mutex, mutex, (new Mutex));
        return mutex;
    }

}

MainThreadDebugger* MainThreadDebugger::s_instance = nullptr;

MainThreadDebugger::MainThreadDebugger(v8::Isolate* isolate)
    : ThreadDebugger(isolate)
{
    MutexLocker locker(creationMutex());
    ASSERT(!s_instance);
    s_instance = this;
}

MainThreadDebugger::~MainThreadDebugger()
{
    MutexLocker locker(creationMutex());
    ASSERT(s_instance == this);
    s_instance = nullptr;
}

void MainThreadDebugger::setClientMessageLoop(std::unique_ptr<ClientMessageLoop> clientMessageLoop)
{
}

void MainThreadDebugger::didClearContextsForFrame(LocalFrame* frame)
{
}

void MainThreadDebugger::contextCreated(ScriptState* scriptState, LocalFrame* frame, SecurityOrigin* origin)
{
    ASSERT(isMainThread());
}

void MainThreadDebugger::contextWillBeDestroyed(ScriptState* scriptState)
{
}

int MainThreadDebugger::contextGroupId(LocalFrame* frame)
{
    LocalFrame* localFrameRoot = frame->localFrameRoot();
    return frameId(localFrameRoot);
}

MainThreadDebugger* MainThreadDebugger::instance()
{
    ASSERT(isMainThread());
    V8PerIsolateData* data = V8PerIsolateData::from(V8PerIsolateData::mainThreadIsolate());
    ASSERT(data->threadDebugger() && !data->threadDebugger()->isWorker());
    return static_cast<MainThreadDebugger*>(data->threadDebugger());
}

void MainThreadDebugger::interruptMainThreadAndRun(std::unique_ptr<InspectorTaskRunner::Task> task)
{
    DebugBreak();
}

void MainThreadDebugger::runMessageLoopOnPause(int contextGroupId)
{
}

void MainThreadDebugger::quitMessageLoopOnPause()
{
}

void MainThreadDebugger::exceptionThrown(ExecutionContext*, ErrorEvent*)
{
}

// void MainThreadDebugger::muteWarningsAndDeprecations()
// {
//
// }

// void MainThreadDebugger::unmuteWarningsAndDeprecations()
// {
//
// }
//
// bool MainThreadDebugger::callingContextCanAccessContext(v8::Local<v8::Context> calling, v8::Local<v8::Context> target)
// {
//     return false;
// }

v8::Local<v8::Context> MainThreadDebugger::ensureDefaultContextInGroup(int contextGroupId)
{
    LocalFrame* frame = WeakIdentifierMap<LocalFrame>::lookup(contextGroupId);
    ScriptState* scriptState = frame ? ScriptState::forMainWorld(frame) : nullptr;
    return scriptState ? scriptState->context() : v8::Local<v8::Context>();
}

// void MainThreadDebugger::messageAddedToConsole(int contextGroupId, MessageSource source, MessageLevel level, const String16& message, const String16& url, unsigned lineNumber, unsigned columnNumber, V8StackTrace* stackTrace)
// {
//     LocalFrame* frame = WeakIdentifierMap<LocalFrame>::lookup(contextGroupId);
//     if (!frame)
//         return;
//     ConsoleMessage* consoleMessage = ConsoleMessage::create(source, level, message, SourceLocation::create(url, lineNumber, columnNumber, stackTrace ? stackTrace->clone() : nullptr, 0));
//     frame->console().reportMessageToClient(consoleMessage);
// }

v8::MaybeLocal<v8::Value> MainThreadDebugger::memoryInfo(v8::Isolate* isolate, v8::Local<v8::Context> context)
{
    ExecutionContext* executionContext = toExecutionContext(context);
    DCHECK(executionContext);
    ASSERT(executionContext->isDocument());
    return ToV8(MemoryInfo::create(), context->Global(), isolate);
}

void MainThreadDebugger::installAdditionalCommandLineAPI(v8::Local<v8::Context> context, v8::Local<v8::Object> object)
{
    ThreadDebugger::installAdditionalCommandLineAPI(context, object);
    createFunctionProperty(context, object, "$", MainThreadDebugger::querySelectorCallback, "function $(selector, [startNode]) { [Command Line API] }");
    createFunctionProperty(context, object, "$$", MainThreadDebugger::querySelectorAllCallback, "function $$(selector, [startNode]) { [Command Line API] }");
    createFunctionProperty(context, object, "$x", MainThreadDebugger::xpathSelectorCallback, "function $x(xpath, [startNode]) { [Command Line API] }");
}

static Node* secondArgumentAsNode(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (info.Length() > 1) {
        if (Node* node = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[1]))
            return node;
    }
    ExecutionContext* executionContext = toExecutionContext(info.GetIsolate()->GetCurrentContext());
    if (executionContext->isDocument())
        return toDocument(executionContext);
    return nullptr;
}

void MainThreadDebugger::querySelectorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
}

void MainThreadDebugger::querySelectorAllCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
}

void MainThreadDebugger::xpathSelectorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
}

void MainThreadDebugger::reportConsoleMessage(ExecutionContext*, MessageSource, MessageLevel, const String& message, SourceLocation*)
{
    DebugBreak();
}

int MainThreadDebugger::contextGroupId(ExecutionContext*)
{
    DebugBreak();
    return 0;
}
void MainThreadDebugger::muteMetrics(int)
{
    DebugBreak();
}
void MainThreadDebugger::unmuteMetrics(int)
{
    DebugBreak();
}
void MainThreadDebugger::beginEnsureAllContextsInGroup(int)
{
    DebugBreak();
}
void MainThreadDebugger::endEnsureAllContextsInGroup(int)
{
    DebugBreak();
}
bool MainThreadDebugger::canExecuteScripts(int)
{
    DebugBreak();
    return false;
}
void MainThreadDebugger::runIfWaitingForDebugger(int)
{
    DebugBreak();
}
void MainThreadDebugger::consoleAPIMessage(int contextGroupId,
    v8_inspector::V8ConsoleAPIType,
    const v8_inspector::StringView& message,
    const v8_inspector::StringView& url,
    unsigned lineNumber,
    unsigned columnNumber,
    v8_inspector::V8StackTrace*)
{
    DebugBreak();
}

InspectorTaskRunner::~InspectorTaskRunner()
{
    notImplemented();
}

} // namespace blink
