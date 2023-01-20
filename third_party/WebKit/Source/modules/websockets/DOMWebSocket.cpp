/*
 * Copyright (C) 2011 Google Inc.  All rights reserved.
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

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/websockets/DOMWebSocket.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/ScriptController.h"
<<<<<<< HEAD
#include "bindings/core/v8/SourceLocation.h"
#include "bindings/modules/v8/StringOrStringSequence.h"
=======
#include "bindings/modules/v8/UnionTypesModules.h"
>>>>>>> miniblink49
#include "core/dom/DOMArrayBuffer.h"
#include "core/dom/DOMArrayBufferView.h"
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "core/dom/SecurityContext.h"
#include "core/events/MessageEvent.h"
#include "core/fileapi/Blob.h"
<<<<<<< HEAD
=======
#include "core/frame/ConsoleTypes.h"
>>>>>>> miniblink49
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/UseCounter.h"
#include "core/frame/csp/ContentSecurityPolicy.h"
#include "core/inspector/ConsoleMessage.h"
<<<<<<< HEAD
#include "modules/websockets/CloseEvent.h"
#include "platform/Histogram.h"
#include "platform/blob/BlobData.h"
#include "platform/network/NetworkLog.h"
#include "platform/weborigin/KnownPorts.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/Platform.h"
#include "public/platform/WebInsecureRequestPolicy.h"
#include "wtf/Assertions.h"
#include "wtf/HashSet.h"
#include "wtf/MathExtras.h"
#include "wtf/StdLibExtras.h"
#include "wtf/text/CString.h"
#include "wtf/text/StringBuilder.h"

static const size_t kMaxByteSizeForHistogram = 100 * 1000 * 1000;
static const int32_t kBucketCountForMessageSizeHistogram = 50;
=======
#include "core/inspector/ScriptCallStack.h"
#include "modules/websockets/CloseEvent.h"
#include "platform/Logging.h"
#include "platform/blob/BlobData.h"
#include "platform/heap/Handle.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/Platform.h"
#include "wtf/Assertions.h"
#include "wtf/HashSet.h"
#include "wtf/PassOwnPtr.h"
#include "wtf/StdLibExtras.h"
#include "wtf/text/CString.h"
#include "wtf/text/StringBuilder.h"
#include "wtf/text/WTFString.h"
>>>>>>> miniblink49

namespace blink {

DOMWebSocket::EventQueue::EventQueue(EventTarget* target)
    : m_state(Active)
    , m_target(target)
<<<<<<< HEAD
    , m_resumeTimer(this, &EventQueue::resumeTimerFired)
{
}

DOMWebSocket::EventQueue::~EventQueue()
{
    contextDestroyed();
}

void DOMWebSocket::EventQueue::dispatch(Event* event)
{
    switch (m_state) {
    case Active:
        DCHECK(m_events.isEmpty());
        DCHECK(m_target->getExecutionContext());
=======
    , m_resumeTimer(this, &EventQueue::resumeTimerFired) { }

DOMWebSocket::EventQueue::~EventQueue() { stop(); }

void DOMWebSocket::EventQueue::dispatch(PassRefPtrWillBeRawPtr<Event> event)
{
    switch (m_state) {
    case Active:
        ASSERT(m_events.isEmpty());
        ASSERT(m_target->executionContext());
>>>>>>> miniblink49
        m_target->dispatchEvent(event);
        break;
    case Suspended:
        m_events.append(event);
        break;
    case Stopped:
<<<<<<< HEAD
        DCHECK(m_events.isEmpty());
=======
        ASSERT(m_events.isEmpty());
>>>>>>> miniblink49
        // Do nothing.
        break;
    }
}

bool DOMWebSocket::EventQueue::isEmpty() const
{
    return m_events.isEmpty();
}

void DOMWebSocket::EventQueue::suspend()
{
    m_resumeTimer.stop();
    if (m_state != Active)
        return;

    m_state = Suspended;
}

void DOMWebSocket::EventQueue::resume()
{
    if (m_state != Suspended || m_resumeTimer.isActive())
        return;

<<<<<<< HEAD
    m_resumeTimer.startOneShot(0, BLINK_FROM_HERE);
}

void DOMWebSocket::EventQueue::contextDestroyed()
=======
    m_resumeTimer.startOneShot(0, FROM_HERE);
}

void DOMWebSocket::EventQueue::stop()
>>>>>>> miniblink49
{
    if (m_state == Stopped)
        return;

    m_state = Stopped;
    m_resumeTimer.stop();
    m_events.clear();
}

void DOMWebSocket::EventQueue::dispatchQueuedEvents()
{
    if (m_state != Active)
        return;

<<<<<<< HEAD
    HeapDeque<Member<Event>> events;
=======
    WillBeHeapDeque<RefPtrWillBeMember<Event>> events;
>>>>>>> miniblink49
    events.swap(m_events);
    while (!events.isEmpty()) {
        if (m_state == Stopped || m_state == Suspended)
            break;
<<<<<<< HEAD
        DCHECK_EQ(m_state, Active);
        DCHECK(m_target->getExecutionContext());
=======
        ASSERT(m_state == Active);
        ASSERT(m_target->executionContext());
>>>>>>> miniblink49
        m_target->dispatchEvent(events.takeFirst());
        // |this| can be stopped here.
    }
    if (m_state == Suspended) {
        while (!m_events.isEmpty())
            events.append(m_events.takeFirst());
        events.swap(m_events);
    }
}

<<<<<<< HEAD
void DOMWebSocket::EventQueue::resumeTimerFired(TimerBase*)
{
    DCHECK_EQ(m_state, Suspended);
=======
void DOMWebSocket::EventQueue::resumeTimerFired(Timer<EventQueue>*)
{
    ASSERT(m_state == Suspended);
>>>>>>> miniblink49
    m_state = Active;
    dispatchQueuedEvents();
}

DEFINE_TRACE(DOMWebSocket::EventQueue)
{
    visitor->trace(m_target);
    visitor->trace(m_events);
}

const size_t maxReasonSizeInBytes = 123;

static inline bool isValidSubprotocolCharacter(UChar character)
{
    const UChar minimumProtocolCharacter = '!'; // U+0021.
    const UChar maximumProtocolCharacter = '~'; // U+007E.
    // Set to true if character does not matches "separators" ABNF defined in
    // RFC2616. SP and HT are excluded since the range check excludes them.
<<<<<<< HEAD
    bool isNotSeparator = character != '"' && character != '(' && character != ')' && character != ',' && character != '/' && !(character >= ':' && character <= '@') // U+003A - U+0040 (':', ';', '<', '=', '>', '?', '@').
=======
    bool isNotSeparator = character != '"' && character != '(' && character != ')' && character != ',' && character != '/'
        && !(character >= ':' && character <= '@') // U+003A - U+0040 (':', ';', '<', '=', '>', '?', '@').
>>>>>>> miniblink49
        && !(character >= '[' && character <= ']') // U+005B - U+005D ('[', '\\', ']').
        && character != '{' && character != '}';
    return character >= minimumProtocolCharacter && character <= maximumProtocolCharacter && isNotSeparator;
}

bool DOMWebSocket::isValidSubprotocolString(const String& protocol)
{
    if (protocol.isEmpty())
        return false;
    for (size_t i = 0; i < protocol.length(); ++i) {
        if (!isValidSubprotocolCharacter(protocol[i]))
            return false;
    }
    return true;
}

static String encodeSubprotocolString(const String& protocol)
{
    StringBuilder builder;
    for (size_t i = 0; i < protocol.length(); i++) {
        if (protocol[i] < 0x20 || protocol[i] > 0x7E)
            builder.append(String::format("\\u%04X", protocol[i]));
        else if (protocol[i] == 0x5c)
<<<<<<< HEAD
            builder.append("\\\\");
=======
            builder.appendLiteral("\\\\");
>>>>>>> miniblink49
        else
            builder.append(protocol[i]);
    }
    return builder.toString();
}

<<<<<<< HEAD
static String joinStrings(const Vector<String>& strings,
    const char* separator)
=======
static String joinStrings(const Vector<String>& strings, const char* separator)
>>>>>>> miniblink49
{
    StringBuilder builder;
    for (size_t i = 0; i < strings.size(); ++i) {
        if (i)
            builder.append(separator);
        builder.append(strings[i]);
    }
    return builder.toString();
}

static void setInvalidStateErrorForSendMethod(ExceptionState& exceptionState)
{
<<<<<<< HEAD
    exceptionState.throwDOMException(InvalidStateError,
        "Still in CONNECTING state.");
=======
    exceptionState.throwDOMException(InvalidStateError, "Still in CONNECTING state.");
>>>>>>> miniblink49
}

const char* DOMWebSocket::subprotocolSeperator()
{
    return ", ";
}

DOMWebSocket::DOMWebSocket(ExecutionContext* context)
<<<<<<< HEAD
    : SuspendableObject(context)
    , m_state(kConnecting)
=======
    : ActiveDOMObject(context)
    , m_state(CONNECTING)
>>>>>>> miniblink49
    , m_bufferedAmount(0)
    , m_consumedBufferedAmount(0)
    , m_bufferedAmountAfterClose(0)
    , m_binaryType(BinaryTypeBlob)
<<<<<<< HEAD
    , m_binaryTypeChangesAfterOpen(0)
    , m_subprotocol("")
    , m_extensions("")
    , m_eventQueue(EventQueue::create(this))
    , m_bufferedAmountConsumeTimer(
          this,
          &DOMWebSocket::reflectBufferedAmountConsumption)
=======
    , m_subprotocol("")
    , m_extensions("")
    , m_eventQueue(EventQueue::create(this))
    , m_bufferedAmountConsumeTimer(this, &DOMWebSocket::reflectBufferedAmountConsumption)
>>>>>>> miniblink49
{
}

DOMWebSocket::~DOMWebSocket()
{
<<<<<<< HEAD
    DCHECK(!m_channel);
=======
    ASSERT(!m_channel);
>>>>>>> miniblink49
}

void DOMWebSocket::logError(const String& message)
{
<<<<<<< HEAD
    if (getExecutionContext())
        getExecutionContext()->addConsoleMessage(
            ConsoleMessage::create(JSMessageSource, ErrorMessageLevel, message));
}

DOMWebSocket* DOMWebSocket::create(ExecutionContext* context,
    const String& url,
    ExceptionState& exceptionState)
=======
    executionContext()->addConsoleMessage(ConsoleMessage::create(JSMessageSource, ErrorMessageLevel, message));
}

DOMWebSocket* DOMWebSocket::create(ExecutionContext* context, const String& url, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    StringOrStringSequence protocols;
    return create(context, url, protocols, exceptionState);
}

<<<<<<< HEAD
DOMWebSocket* DOMWebSocket::create(ExecutionContext* context,
    const String& url,
    const StringOrStringSequence& protocols,
    ExceptionState& exceptionState)
{
    if (url.isNull()) {
        exceptionState.throwDOMException(
            SyntaxError,
            "Failed to create a WebSocket: the provided URL is invalid.");
=======
DOMWebSocket* DOMWebSocket::create(ExecutionContext* context, const String& url, const StringOrStringSequence& protocols, ExceptionState& exceptionState)
{
    if (url.isNull()) {
        exceptionState.throwDOMException(SyntaxError, "Failed to create a WebSocket: the provided URL is invalid.");
>>>>>>> miniblink49
        return nullptr;
    }

    DOMWebSocket* webSocket = new DOMWebSocket(context);
    webSocket->suspendIfNeeded();

    if (protocols.isNull()) {
        Vector<String> protocolsVector;
        webSocket->connect(url, protocolsVector, exceptionState);
    } else if (protocols.isString()) {
        Vector<String> protocolsVector;
<<<<<<< HEAD
        protocolsVector.push_back(protocols.getAsString());
        webSocket->connect(url, protocolsVector, exceptionState);
    } else {
        DCHECK(protocols.isStringSequence());
=======
        protocolsVector.append(protocols.getAsString());
        webSocket->connect(url, protocolsVector, exceptionState);
    } else {
        ASSERT(protocols.isStringSequence());
>>>>>>> miniblink49
        webSocket->connect(url, protocols.getAsStringSequence(), exceptionState);
    }

    if (exceptionState.hadException())
        return nullptr;

    return webSocket;
}

<<<<<<< HEAD
void DOMWebSocket::connect(const String& url,
    const Vector<String>& protocols,
    ExceptionState& exceptionState)
{
    UseCounter::count(getExecutionContext(), UseCounter::WebSocket);

    NETWORK_DVLOG(1) << "WebSocket " << this << " connect() url=" << url;
    m_url = KURL(KURL(), url);

    if (getExecutionContext()->securityContext().getInsecureRequestPolicy() & kUpgradeInsecureRequests && m_url.protocol() == "ws") {
        UseCounter::count(getExecutionContext(),
            UseCounter::UpgradeInsecureRequestsUpgradedRequest);
=======
void DOMWebSocket::connect(const String& url, const Vector<String>& protocols, ExceptionState& exceptionState)
{
    WTF_LOG(Network, "WebSocket %p connect() url='%s'", this, url.utf8().data());
    m_url = KURL(KURL(), url);

    if (executionContext()->securityContext().insecureRequestsPolicy() == SecurityContext::InsecureRequestsUpgrade && m_url.protocol() == "ws") {
        UseCounter::count(executionContext(), UseCounter::UpgradeInsecureRequestsUpgradedRequest);
>>>>>>> miniblink49
        m_url.setProtocol("wss");
        if (m_url.port() == 80)
            m_url.setPort(443);
    }

    if (!m_url.isValid()) {
<<<<<<< HEAD
        m_state = kClosed;
        exceptionState.throwDOMException(SyntaxError,
            "The URL '" + url + "' is invalid.");
        return;
    }
    if (!m_url.protocolIs("ws") && !m_url.protocolIs("wss")) {
        m_state = kClosed;
        exceptionState.throwDOMException(
            SyntaxError, "The URL's scheme must be either 'ws' or 'wss'. '" + m_url.protocol() + "' is not allowed.");
=======
        m_state = CLOSED;
        exceptionState.throwDOMException(SyntaxError, "The URL '" + url + "' is invalid.");
        return;
    }
    if (!m_url.protocolIs("ws") && !m_url.protocolIs("wss")) {
        m_state = CLOSED;
        exceptionState.throwDOMException(SyntaxError, "The URL's scheme must be either 'ws' or 'wss'. '" + m_url.protocol() + "' is not allowed.");
>>>>>>> miniblink49
        return;
    }

    if (m_url.hasFragmentIdentifier()) {
<<<<<<< HEAD
        m_state = kClosed;
        exceptionState.throwDOMException(
            SyntaxError,
            "The URL contains a fragment identifier ('" + m_url.fragmentIdentifier() + "'). Fragment identifiers are not allowed in WebSocket URLs.");
        return;
    }

    if (!isPortAllowedForScheme(m_url)) {
        m_state = kClosed;
        exceptionState.throwSecurityError(
            "The port " + String::number(m_url.port()) + " is not allowed.");
        return;
    }

    // FIXME: Convert this to check the isolated world's Content Security Policy
    // once webkit.org/b/104520 is solved.
    if (!ContentSecurityPolicy::shouldBypassMainWorld(getExecutionContext()) && !getExecutionContext()->contentSecurityPolicy()->allowConnectToSource(m_url)) {
        m_state = kClosed;
        // The URL is safe to expose to JavaScript, as this check happens
        // synchronously before redirection.
        exceptionState.throwSecurityError(
            "Refused to connect to '" + m_url.elidedString() + "' because it violates the document's Content Security Policy.");
=======
        m_state = CLOSED;
        exceptionState.throwDOMException(SyntaxError, "The URL contains a fragment identifier ('" + m_url.fragmentIdentifier() + "'). Fragment identifiers are not allowed in WebSocket URLs.");
        return;
    }

    if (!Platform::current()->portAllowed(m_url)) {
        m_state = CLOSED;
        exceptionState.throwSecurityError("The port " + String::number(m_url.port()) + " is not allowed.");
        return;
    }

    // FIXME: Convert this to check the isolated world's Content Security Policy once webkit.org/b/104520 is solved.
    if (!ContentSecurityPolicy::shouldBypassMainWorld(executionContext()) && !executionContext()->contentSecurityPolicy()->allowConnectToSource(m_url)) {
        m_state = CLOSED;
        // The URL is safe to expose to JavaScript, as this check happens synchronously before redirection.
        exceptionState.throwSecurityError("Refused to connect to '" + m_url.elidedString() + "' because it violates the document's Content Security Policy.");
>>>>>>> miniblink49
        return;
    }

    // Fail if not all elements in |protocols| are valid.
    for (size_t i = 0; i < protocols.size(); ++i) {
        if (!isValidSubprotocolString(protocols[i])) {
<<<<<<< HEAD
            m_state = kClosed;
            exceptionState.throwDOMException(
                SyntaxError, "The subprotocol '" + encodeSubprotocolString(protocols[i]) + "' is invalid.");
=======
            m_state = CLOSED;
            exceptionState.throwDOMException(SyntaxError, "The subprotocol '" + encodeSubprotocolString(protocols[i]) + "' is invalid.");
>>>>>>> miniblink49
            return;
        }
    }

    // Fail if there're duplicated elements in |protocols|.
    HashSet<String> visited;
    for (size_t i = 0; i < protocols.size(); ++i) {
        if (!visited.add(protocols[i]).isNewEntry) {
<<<<<<< HEAD
            m_state = kClosed;
            exceptionState.throwDOMException(
                SyntaxError, "The subprotocol '" + encodeSubprotocolString(protocols[i]) + "' is duplicated.");
=======
            m_state = CLOSED;
            exceptionState.throwDOMException(SyntaxError, "The subprotocol '" + encodeSubprotocolString(protocols[i]) + "' is duplicated.");
>>>>>>> miniblink49
            return;
        }
    }

<<<<<<< HEAD
    if (getExecutionContext()->getSecurityOrigin()->hasSuborigin()) {
        m_state = kClosed;
        exceptionState.throwSecurityError(
            "Connecting to a WebSocket from a suborigin is not allowed.");
        return;
    }

=======
>>>>>>> miniblink49
    String protocolString;
    if (!protocols.isEmpty())
        protocolString = joinStrings(protocols, subprotocolSeperator());

<<<<<<< HEAD
    m_channel = createChannel(getExecutionContext(), this);

    if (!m_channel->connect(m_url, protocolString)) {
        m_state = kClosed;
        exceptionState.throwSecurityError(
            "An insecure WebSocket connection may not be initiated from a page "
            "loaded over HTTPS.");
=======
    m_channel = createChannel(executionContext(), this);

    if (!m_channel->connect(m_url, protocolString)) {
        m_state = CLOSED;
        exceptionState.throwSecurityError("An insecure WebSocket connection may not be initiated from a page loaded over HTTPS.");
>>>>>>> miniblink49
        releaseChannel();
        return;
    }
}

void DOMWebSocket::updateBufferedAmountAfterClose(uint64_t payloadSize)
{
    m_bufferedAmountAfterClose += payloadSize;

    logError("WebSocket is already in CLOSING or CLOSED state.");
}

<<<<<<< HEAD
void DOMWebSocket::reflectBufferedAmountConsumption(TimerBase*)
{
    DCHECK_GE(m_bufferedAmount, m_consumedBufferedAmount);
    // Cast to unsigned long long is required since clang doesn't accept
    // combination of %llu and uint64_t (known as unsigned long).
    NETWORK_DVLOG(1) << "WebSocket " << this
                     << " reflectBufferedAmountConsumption() " << m_bufferedAmount
                     << " => " << (m_bufferedAmount - m_consumedBufferedAmount);
=======
void DOMWebSocket::reflectBufferedAmountConsumption(Timer<DOMWebSocket>*)
{
    ASSERT(m_bufferedAmount >= m_consumedBufferedAmount);
    // Cast to unsigned long long is required since clang doesn't accept
    // combination of %llu and uint64_t (known as unsigned long).
    WTF_LOG(Network, "WebSocket %p reflectBufferedAmountConsumption() %llu => %llu", this, static_cast<unsigned long long>(m_bufferedAmount), static_cast<unsigned long long>(m_bufferedAmount - m_consumedBufferedAmount));
>>>>>>> miniblink49

    m_bufferedAmount -= m_consumedBufferedAmount;
    m_consumedBufferedAmount = 0;
}

void DOMWebSocket::releaseChannel()
{
<<<<<<< HEAD
    DCHECK(m_channel);
=======
    ASSERT(m_channel);
>>>>>>> miniblink49
    m_channel->disconnect();
    m_channel = nullptr;
}

<<<<<<< HEAD
void DOMWebSocket::logBinaryTypeChangesAfterOpen()
{
    DEFINE_THREAD_SAFE_STATIC_LOCAL(
        CustomCountHistogram, binaryTypeChangesHistogram,
        new CustomCountHistogram("WebCore.WebSocket.BinaryTypeChangesAfterOpen",
            1, 1024, 10));
    DVLOG(3) << "WebSocket " << static_cast<void*>(this)
             << " logBinaryTypeChangesAfterOpen() logging "
             << m_binaryTypeChangesAfterOpen;
    binaryTypeChangesHistogram.count(m_binaryTypeChangesAfterOpen);
}

=======
>>>>>>> miniblink49
void DOMWebSocket::send(const String& message, ExceptionState& exceptionState)
{
    CString encodedMessage = message.utf8();

<<<<<<< HEAD
    NETWORK_DVLOG(1) << "WebSocket " << this << " send() Sending String "
                     << message;
    if (m_state == kConnecting) {
        setInvalidStateErrorForSendMethod(exceptionState);
        return;
    }
    // No exception is raised if the connection was once established but has
    // subsequently been closed.
    if (m_state == kClosing || m_state == kClosed) {
        updateBufferedAmountAfterClose(encodedMessage.length());
        return;
    }

    recordSendTypeHistogram(WebSocketSendTypeString);

    DCHECK(m_channel);
=======
    WTF_LOG(Network, "WebSocket %p send() Sending String '%s'", this, encodedMessage.data());
    if (m_state == CONNECTING) {
        setInvalidStateErrorForSendMethod(exceptionState);
        return;
    }
    // No exception is raised if the connection was once established but has subsequently been closed.
    if (m_state == CLOSING || m_state == CLOSED) {
        updateBufferedAmountAfterClose(encodedMessage.length());
        return;
    }
    Platform::current()->histogramEnumeration("WebCore.WebSocket.SendType", WebSocketSendTypeString, WebSocketSendTypeMax);
    ASSERT(m_channel);
>>>>>>> miniblink49
    m_bufferedAmount += encodedMessage.length();
    m_channel->send(encodedMessage);
}

<<<<<<< HEAD
void DOMWebSocket::send(DOMArrayBuffer* binaryData,
    ExceptionState& exceptionState)
{
    NETWORK_DVLOG(1) << "WebSocket " << this << " send() Sending ArrayBuffer "
                     << binaryData;
    DCHECK(binaryData);
    DCHECK(binaryData->buffer());
    if (m_state == kConnecting) {
        setInvalidStateErrorForSendMethod(exceptionState);
        return;
    }
    if (m_state == kClosing || m_state == kClosed) {
        updateBufferedAmountAfterClose(binaryData->byteLength());
        return;
    }
    recordSendTypeHistogram(WebSocketSendTypeArrayBuffer);
    recordSendMessageSizeHistogram(WebSocketSendTypeArrayBuffer,
        binaryData->byteLength());
    DCHECK(m_channel);
=======
void DOMWebSocket::send(DOMArrayBuffer* binaryData, ExceptionState& exceptionState)
{
    WTF_LOG(Network, "WebSocket %p send() Sending ArrayBuffer %p", this, binaryData);
    ASSERT(binaryData && binaryData->buffer());
    if (m_state == CONNECTING) {
        setInvalidStateErrorForSendMethod(exceptionState);
        return;
    }
    if (m_state == CLOSING || m_state == CLOSED) {
        updateBufferedAmountAfterClose(binaryData->byteLength());
        return;
    }
    Platform::current()->histogramEnumeration("WebCore.WebSocket.SendType", WebSocketSendTypeArrayBuffer, WebSocketSendTypeMax);
    ASSERT(m_channel);
>>>>>>> miniblink49
    m_bufferedAmount += binaryData->byteLength();
    m_channel->send(*binaryData, 0, binaryData->byteLength());
}

<<<<<<< HEAD
void DOMWebSocket::send(DOMArrayBufferView* arrayBufferView,
    ExceptionState& exceptionState)
{
    NETWORK_DVLOG(1) << "WebSocket " << this << " send() Sending ArrayBufferView "
                     << arrayBufferView;
    DCHECK(arrayBufferView);
    if (m_state == kConnecting) {
        setInvalidStateErrorForSendMethod(exceptionState);
        return;
    }
    if (m_state == kClosing || m_state == kClosed) {
        updateBufferedAmountAfterClose(arrayBufferView->byteLength());
        return;
    }
    recordSendTypeHistogram(WebSocketSendTypeArrayBufferView);
    recordSendMessageSizeHistogram(WebSocketSendTypeArrayBufferView,
        arrayBufferView->byteLength());
    DCHECK(m_channel);
    m_bufferedAmount += arrayBufferView->byteLength();
    m_channel->send(*arrayBufferView->buffer(), arrayBufferView->byteOffset(),
        arrayBufferView->byteLength());
=======
void DOMWebSocket::send(DOMArrayBufferView* arrayBufferView, ExceptionState& exceptionState)
{
    WTF_LOG(Network, "WebSocket %p send() Sending ArrayBufferView %p", this, arrayBufferView);
    ASSERT(arrayBufferView);
    if (m_state == CONNECTING) {
        setInvalidStateErrorForSendMethod(exceptionState);
        return;
    }
    if (m_state == CLOSING || m_state == CLOSED) {
        updateBufferedAmountAfterClose(arrayBufferView->byteLength());
        return;
    }
    Platform::current()->histogramEnumeration("WebCore.WebSocket.SendType", WebSocketSendTypeArrayBufferView, WebSocketSendTypeMax);
    ASSERT(m_channel);
    m_bufferedAmount += arrayBufferView->byteLength();
    m_channel->send(*arrayBufferView->buffer(), arrayBufferView->byteOffset(), arrayBufferView->byteLength());
>>>>>>> miniblink49
}

void DOMWebSocket::send(Blob* binaryData, ExceptionState& exceptionState)
{
<<<<<<< HEAD
    NETWORK_DVLOG(1) << "WebSocket " << this << " send() Sending Blob "
                     << binaryData->uuid();
    DCHECK(binaryData);
    if (m_state == kConnecting) {
        setInvalidStateErrorForSendMethod(exceptionState);
        return;
    }
    if (m_state == kClosing || m_state == kClosed) {
        updateBufferedAmountAfterClose(binaryData->size());
        return;
    }
    unsigned long long size = binaryData->size();
    recordSendTypeHistogram(WebSocketSendTypeBlob);
    recordSendMessageSizeHistogram(
        WebSocketSendTypeBlob,
        clampTo<size_t>(size, 0, kMaxByteSizeForHistogram));
    m_bufferedAmount += size;
    DCHECK(m_channel);

    // When the runtime type of |binaryData| is File,
    // binaryData->blobDataHandle()->size() returns -1. However, in order to
    // maintain the value of |m_bufferedAmount| correctly, the WebSocket code
    // needs to fix the size of the File at this point. For this reason,
    // construct a new BlobDataHandle here with the size that this method
    // observed.
    m_channel->send(
        BlobDataHandle::create(binaryData->uuid(), binaryData->type(), size));
}

void DOMWebSocket::close(unsigned short code,
    const String& reason,
    ExceptionState& exceptionState)
=======
    WTF_LOG(Network, "WebSocket %p send() Sending Blob '%s'", this, binaryData->uuid().utf8().data());
    ASSERT(binaryData);
    if (m_state == CONNECTING) {
        setInvalidStateErrorForSendMethod(exceptionState);
        return;
    }
    if (m_state == CLOSING || m_state == CLOSED) {
        updateBufferedAmountAfterClose(binaryData->size());
        return;
    }
    Platform::current()->histogramEnumeration("WebCore.WebSocket.SendType", WebSocketSendTypeBlob, WebSocketSendTypeMax);
    m_bufferedAmount += binaryData->size();
    ASSERT(m_channel);
    m_channel->send(binaryData->blobDataHandle());
}

void DOMWebSocket::close(unsigned short code, const String& reason, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    closeInternal(code, reason, exceptionState);
}

void DOMWebSocket::close(ExceptionState& exceptionState)
{
<<<<<<< HEAD
    closeInternal(WebSocketChannel::CloseEventCodeNotSpecified, String(),
        exceptionState);
=======
    closeInternal(WebSocketChannel::CloseEventCodeNotSpecified, String(), exceptionState);
>>>>>>> miniblink49
}

void DOMWebSocket::close(unsigned short code, ExceptionState& exceptionState)
{
    closeInternal(code, String(), exceptionState);
}

<<<<<<< HEAD
void DOMWebSocket::closeInternal(int code,
    const String& reason,
    ExceptionState& exceptionState)
{
    String cleansedReason = reason;
    if (code == WebSocketChannel::CloseEventCodeNotSpecified) {
        NETWORK_DVLOG(1) << "WebSocket " << this
                         << " close() without code and reason";
    } else {
        NETWORK_DVLOG(1) << "WebSocket " << this << " close() code=" << code
                         << " reason=" << reason;
        if (!(code == WebSocketChannel::CloseEventCodeNormalClosure || (WebSocketChannel::CloseEventCodeMinimumUserDefined <= code && code <= WebSocketChannel::CloseEventCodeMaximumUserDefined))) {
            exceptionState.throwDOMException(
                InvalidAccessError,
                "The code must be either 1000, or between 3000 and 4999. " + String::number(code) + " is neither.");
            return;
        }
        // Bindings specify USVString, so unpaired surrogates are already replaced
        // with U+FFFD.
        CString utf8 = reason.utf8();
        if (utf8.length() > maxReasonSizeInBytes) {
            exceptionState.throwDOMException(
                SyntaxError, "The message must not be greater than " + String::number(maxReasonSizeInBytes) + " bytes.");
            return;
        }
        if (!reason.isEmpty() && !reason.is8Bit()) {
            DCHECK_GT(utf8.length(), 0u);
=======
void DOMWebSocket::closeInternal(int code, const String& reason, ExceptionState& exceptionState)
{
    String cleansedReason = reason;
    if (code == WebSocketChannel::CloseEventCodeNotSpecified) {
        WTF_LOG(Network, "WebSocket %p close() without code and reason", this);
    } else {
        WTF_LOG(Network, "WebSocket %p close() code=%d reason='%s'", this, code, reason.utf8().data());
        if (!(code == WebSocketChannel::CloseEventCodeNormalClosure || (WebSocketChannel::CloseEventCodeMinimumUserDefined <= code && code <= WebSocketChannel::CloseEventCodeMaximumUserDefined))) {
            exceptionState.throwDOMException(InvalidAccessError, "The code must be either 1000, or between 3000 and 4999. " + String::number(code) + " is neither.");
            return;
        }
        // Bindings specify USVString, so unpaired surrogates are already replaced with U+FFFD.
        CString utf8 = reason.utf8();
        if (utf8.length() > maxReasonSizeInBytes) {
            exceptionState.throwDOMException(SyntaxError, "The message must not be greater than " + String::number(maxReasonSizeInBytes) + " bytes.");
            return;
        }
        if (!reason.isEmpty() && !reason.is8Bit()) {
            ASSERT(utf8.length() > 0);
>>>>>>> miniblink49
            // reason might contain unpaired surrogates. Reconstruct it from
            // utf8.
            cleansedReason = String::fromUTF8(utf8.data(), utf8.length());
        }
    }

<<<<<<< HEAD
    if (m_state == kClosing || m_state == kClosed)
        return;
    if (m_state == kConnecting) {
        m_state = kClosing;
        m_channel->fail("WebSocket is closed before the connection is established.",
            WarningMessageLevel,
            SourceLocation::create(String(), 0, 0, nullptr));
        return;
    }
    m_state = kClosing;
=======
    if (m_state == CLOSING || m_state == CLOSED)
        return;
    if (m_state == CONNECTING) {
        m_state = CLOSING;
        m_channel->fail("WebSocket is closed before the connection is established.", WarningMessageLevel, String(), 0);
        return;
    }
    m_state = CLOSING;
>>>>>>> miniblink49
    if (m_channel)
        m_channel->close(code, cleansedReason);
}

const KURL& DOMWebSocket::url() const
{
    return m_url;
}

DOMWebSocket::State DOMWebSocket::readyState() const
{
    return m_state;
}

unsigned DOMWebSocket::bufferedAmount() const
{
    uint64_t sum = m_bufferedAmountAfterClose + m_bufferedAmount;

    if (sum > std::numeric_limits<unsigned>::max())
        return std::numeric_limits<unsigned>::max();
    return sum;
}

String DOMWebSocket::protocol() const
{
    return m_subprotocol;
}

String DOMWebSocket::extensions() const
{
    return m_extensions;
}

String DOMWebSocket::binaryType() const
{
    switch (m_binaryType) {
    case BinaryTypeBlob:
        return "blob";
    case BinaryTypeArrayBuffer:
        return "arraybuffer";
    }
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return String();
}

void DOMWebSocket::setBinaryType(const String& binaryType)
{
    if (binaryType == "blob") {
<<<<<<< HEAD
        setBinaryTypeInternal(BinaryTypeBlob);
        return;
    }
    if (binaryType == "arraybuffer") {
        setBinaryTypeInternal(BinaryTypeArrayBuffer);
        return;
    }
    NOTREACHED();
}

void DOMWebSocket::setBinaryTypeInternal(BinaryType binaryType)
{
    if (m_binaryType == binaryType)
        return;
    m_binaryType = binaryType;
    if (m_state == kOpen || m_state == kClosing)
        ++m_binaryTypeChangesAfterOpen;
=======
        m_binaryType = BinaryTypeBlob;
        return;
    }
    if (binaryType == "arraybuffer") {
        m_binaryType = BinaryTypeArrayBuffer;
        return;
    }
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

const AtomicString& DOMWebSocket::interfaceName() const
{
    return EventTargetNames::DOMWebSocket;
}

<<<<<<< HEAD
ExecutionContext* DOMWebSocket::getExecutionContext() const
{
    return SuspendableObject::getExecutionContext();
}

void DOMWebSocket::contextDestroyed(ExecutionContext*)
{
    NETWORK_DVLOG(1) << "WebSocket " << this << " contextDestroyed()";
    m_eventQueue->contextDestroyed();
    if (m_channel) {
        m_channel->close(WebSocketChannel::CloseEventCodeGoingAway, String());
        releaseChannel();
    }
    if (m_state != kClosed) {
        m_state = kClosed;
        logBinaryTypeChangesAfterOpen();
    }
=======
ExecutionContext* DOMWebSocket::executionContext() const
{
    return ActiveDOMObject::executionContext();
}

void DOMWebSocket::contextDestroyed()
{
    WTF_LOG(Network, "WebSocket %p contextDestroyed()", this);
    ASSERT(!m_channel);
    ASSERT(m_state == CLOSED);
    ActiveDOMObject::contextDestroyed();
>>>>>>> miniblink49
}

bool DOMWebSocket::hasPendingActivity() const
{
    return m_channel || !m_eventQueue->isEmpty();
}

void DOMWebSocket::suspend()
{
    m_eventQueue->suspend();
}

void DOMWebSocket::resume()
{
    m_eventQueue->resume();
}

<<<<<<< HEAD
void DOMWebSocket::didConnect(const String& subprotocol,
    const String& extensions)
{
    NETWORK_DVLOG(1) << "WebSocket " << this << " didConnect()";
    if (m_state != kConnecting)
        return;
    m_state = kOpen;
=======
void DOMWebSocket::stop()
{
    m_eventQueue->stop();
    if (m_channel) {
        m_channel->close(WebSocketChannel::CloseEventCodeGoingAway, String());
        releaseChannel();
    }
    m_state = CLOSED;
}

void DOMWebSocket::didConnect(const String& subprotocol, const String& extensions)
{
    WTF_LOG(Network, "WebSocket %p didConnect()", this);
    if (m_state != CONNECTING)
        return;
    m_state = OPEN;
>>>>>>> miniblink49
    m_subprotocol = subprotocol;
    m_extensions = extensions;
    m_eventQueue->dispatch(Event::create(EventTypeNames::open));
}

void DOMWebSocket::didReceiveTextMessage(const String& msg)
{
<<<<<<< HEAD
    NETWORK_DVLOG(1) << "WebSocket " << this
                     << " didReceiveTextMessage() Text message " << msg;
    if (m_state != kOpen)
        return;
    recordReceiveTypeHistogram(WebSocketReceiveTypeString);

    m_eventQueue->dispatch(
        MessageEvent::create(msg, SecurityOrigin::create(m_url)->toString()));
}

void DOMWebSocket::didReceiveBinaryMessage(
    std::unique_ptr<Vector<char>> binaryData)
{
    NETWORK_DVLOG(1) << "WebSocket " << this << " didReceiveBinaryMessage() "
                     << binaryData->size() << " byte binary message";
=======
    WTF_LOG(Network, "WebSocket %p didReceiveTextMessage() Text message '%s'", this, msg.utf8().data());
    if (m_state != OPEN)
        return;
    Platform::current()->histogramEnumeration("WebCore.WebSocket.ReceiveType", WebSocketReceiveTypeString, WebSocketReceiveTypeMax);
    m_eventQueue->dispatch(MessageEvent::create(msg, SecurityOrigin::create(m_url)->toString()));
}

void DOMWebSocket::didReceiveBinaryMessage(PassOwnPtr<Vector<char>> binaryData)
{
    WTF_LOG(Network, "WebSocket %p didReceiveBinaryMessage() %lu byte binary message", this, static_cast<unsigned long>(binaryData->size()));
>>>>>>> miniblink49
    switch (m_binaryType) {
    case BinaryTypeBlob: {
        size_t size = binaryData->size();
        RefPtr<RawData> rawData = RawData::create();
        binaryData->swap(*rawData->mutableData());
<<<<<<< HEAD
        std::unique_ptr<BlobData> blobData = BlobData::create();
        blobData->appendData(rawData.release(), 0, BlobDataItem::toEndOfFile);
        Blob* blob = Blob::create(BlobDataHandle::create(std::move(blobData), size));
        recordReceiveTypeHistogram(WebSocketReceiveTypeBlob);
        recordReceiveMessageSizeHistogram(WebSocketReceiveTypeBlob, size);
        m_eventQueue->dispatch(MessageEvent::create(
            blob, SecurityOrigin::create(m_url)->toString()));
=======
        OwnPtr<BlobData> blobData = BlobData::create();
        blobData->appendData(rawData.release(), 0, BlobDataItem::toEndOfFile);
        Blob* blob = Blob::create(BlobDataHandle::create(blobData.release(), size));
        Platform::current()->histogramEnumeration("WebCore.WebSocket.ReceiveType", WebSocketReceiveTypeBlob, WebSocketReceiveTypeMax);
        m_eventQueue->dispatch(MessageEvent::create(blob, SecurityOrigin::create(m_url)->toString()));
>>>>>>> miniblink49
        break;
    }

    case BinaryTypeArrayBuffer:
<<<<<<< HEAD
        DOMArrayBuffer* arrayBuffer = DOMArrayBuffer::create(binaryData->data(), binaryData->size());
        recordReceiveTypeHistogram(WebSocketReceiveTypeArrayBuffer);
        recordReceiveMessageSizeHistogram(WebSocketReceiveTypeArrayBuffer,
            binaryData->size());
        m_eventQueue->dispatch(MessageEvent::create(
            arrayBuffer, SecurityOrigin::create(m_url)->toString()));
=======
        RefPtr<DOMArrayBuffer> arrayBuffer = DOMArrayBuffer::create(binaryData->data(), binaryData->size());
        Platform::current()->histogramEnumeration("WebCore.WebSocket.ReceiveType", WebSocketReceiveTypeArrayBuffer, WebSocketReceiveTypeMax);
        m_eventQueue->dispatch(MessageEvent::create(arrayBuffer.release(), SecurityOrigin::create(m_url)->toString()));
>>>>>>> miniblink49
        break;
    }
}

void DOMWebSocket::didError()
{
<<<<<<< HEAD
    NETWORK_DVLOG(1) << "WebSocket " << this << " didError()";
    m_state = kClosed;
    logBinaryTypeChangesAfterOpen();
=======
    WTF_LOG(Network, "WebSocket %p didError()", this);
    m_state = CLOSED;
>>>>>>> miniblink49
    m_eventQueue->dispatch(Event::create(EventTypeNames::error));
}

void DOMWebSocket::didConsumeBufferedAmount(uint64_t consumed)
{
<<<<<<< HEAD
    DCHECK_GE(m_bufferedAmount, consumed + m_consumedBufferedAmount);
    NETWORK_DVLOG(1) << "WebSocket " << this << " didConsumeBufferedAmount("
                     << consumed << ")";
    if (m_state == kClosed)
        return;
    m_consumedBufferedAmount += consumed;
    if (!m_bufferedAmountConsumeTimer.isActive())
        m_bufferedAmountConsumeTimer.startOneShot(0, BLINK_FROM_HERE);
=======
    ASSERT(m_bufferedAmount >= consumed + m_consumedBufferedAmount);
    // Cast to unsigned long long is required since clang doesn't accept
    // combination of %llu and uint64_t (known as unsigned long).
    WTF_LOG(Network, "WebSocket %p didConsumeBufferedAmount(%llu)", this, static_cast<unsigned long long>(consumed));
    if (m_state == CLOSED)
        return;
    m_consumedBufferedAmount += consumed;
    if (!m_bufferedAmountConsumeTimer.isActive())
        m_bufferedAmountConsumeTimer.startOneShot(0, FROM_HERE);
>>>>>>> miniblink49
}

void DOMWebSocket::didStartClosingHandshake()
{
<<<<<<< HEAD
    NETWORK_DVLOG(1) << "WebSocket " << this << " didStartClosingHandshake()";
    m_state = kClosing;
}

void DOMWebSocket::didClose(
    ClosingHandshakeCompletionStatus closingHandshakeCompletion,
    unsigned short code,
    const String& reason)
{
    NETWORK_DVLOG(1) << "WebSocket " << this << " didClose()";
    if (!m_channel)
        return;
    bool allDataHasBeenConsumed = m_bufferedAmount == m_consumedBufferedAmount;
    bool wasClean = m_state == kClosing && allDataHasBeenConsumed && closingHandshakeCompletion == ClosingHandshakeComplete && code != WebSocketChannel::CloseEventCodeAbnormalClosure;
    m_state = kClosed;
=======
    WTF_LOG(Network, "WebSocket %p didStartClosingHandshake()", this);
    m_state = CLOSING;
}

void DOMWebSocket::didClose(ClosingHandshakeCompletionStatus closingHandshakeCompletion, unsigned short code, const String& reason)
{
    WTF_LOG(Network, "WebSocket %p didClose()", this);
    if (!m_channel)
        return;
    bool allDataHasBeenConsumed = m_bufferedAmount == m_consumedBufferedAmount;
    bool wasClean = m_state == CLOSING && allDataHasBeenConsumed && closingHandshakeCompletion == ClosingHandshakeComplete && code != WebSocketChannel::CloseEventCodeAbnormalClosure;
    m_state = CLOSED;
>>>>>>> miniblink49

    m_eventQueue->dispatch(CloseEvent::create(wasClean, code, reason));
    releaseChannel();
}

<<<<<<< HEAD
void DOMWebSocket::recordSendTypeHistogram(WebSocketSendType type)
{
    DEFINE_THREAD_SAFE_STATIC_LOCAL(
        EnumerationHistogram, sendTypeHistogram,
        new EnumerationHistogram("WebCore.WebSocket.SendType",
            WebSocketSendTypeMax));
    sendTypeHistogram.count(type);
}

void DOMWebSocket::recordSendMessageSizeHistogram(WebSocketSendType type,
    size_t size)
{
    // Truncate |size| to avoid overflowing int32_t.
    int32_t sizeToCount = clampTo<int32_t>(size, 0, kMaxByteSizeForHistogram);
    switch (type) {
    case WebSocketSendTypeArrayBuffer: {
        DEFINE_THREAD_SAFE_STATIC_LOCAL(
            CustomCountHistogram, arrayBufferMessageSizeHistogram,
            new CustomCountHistogram(
                "WebCore.WebSocket.MessageSize.Send.ArrayBuffer", 1,
                kMaxByteSizeForHistogram, kBucketCountForMessageSizeHistogram));
        arrayBufferMessageSizeHistogram.count(sizeToCount);
        return;
    }

    case WebSocketSendTypeArrayBufferView: {
        DEFINE_THREAD_SAFE_STATIC_LOCAL(
            CustomCountHistogram, arrayBufferViewMessageSizeHistogram,
            new CustomCountHistogram(
                "WebCore.WebSocket.MessageSize.Send.ArrayBufferView", 1,
                kMaxByteSizeForHistogram, kBucketCountForMessageSizeHistogram));
        arrayBufferViewMessageSizeHistogram.count(sizeToCount);
        return;
    }

    case WebSocketSendTypeBlob: {
        DEFINE_THREAD_SAFE_STATIC_LOCAL(
            CustomCountHistogram, blobMessageSizeHistogram,
            new CustomCountHistogram("WebCore.WebSocket.MessageSize.Send.Blob", 1,
                kMaxByteSizeForHistogram,
                kBucketCountForMessageSizeHistogram));
        blobMessageSizeHistogram.count(sizeToCount);
        return;
    }

    default:
        NOTREACHED();
    }
}

void DOMWebSocket::recordReceiveTypeHistogram(WebSocketReceiveType type)
{
    DEFINE_THREAD_SAFE_STATIC_LOCAL(
        EnumerationHistogram, receiveTypeHistogram,
        new EnumerationHistogram("WebCore.WebSocket.ReceiveType",
            WebSocketReceiveTypeMax));
    receiveTypeHistogram.count(type);
}

void DOMWebSocket::recordReceiveMessageSizeHistogram(WebSocketReceiveType type,
    size_t size)
{
    // Truncate |size| to avoid overflowing int32_t.
    int32_t sizeToCount = clampTo<int32_t>(size, 0, kMaxByteSizeForHistogram);
    switch (type) {
    case WebSocketReceiveTypeArrayBuffer: {
        DEFINE_THREAD_SAFE_STATIC_LOCAL(
            CustomCountHistogram, arrayBufferMessageSizeHistogram,
            new CustomCountHistogram(
                "WebCore.WebSocket.MessageSize.Receive.ArrayBuffer", 1,
                kMaxByteSizeForHistogram, kBucketCountForMessageSizeHistogram));
        arrayBufferMessageSizeHistogram.count(sizeToCount);
        return;
    }

    case WebSocketReceiveTypeBlob: {
        DEFINE_THREAD_SAFE_STATIC_LOCAL(
            CustomCountHistogram, blobMessageSizeHistogram,
            new CustomCountHistogram("WebCore.WebSocket.MessageSize.Receive.Blob",
                1, kMaxByteSizeForHistogram,
                kBucketCountForMessageSizeHistogram));
        blobMessageSizeHistogram.count(sizeToCount);
        return;
    }

    default:
        NOTREACHED();
    }
}

=======
>>>>>>> miniblink49
DEFINE_TRACE(DOMWebSocket)
{
    visitor->trace(m_channel);
    visitor->trace(m_eventQueue);
    WebSocketChannelClient::trace(visitor);
<<<<<<< HEAD
    EventTargetWithInlineData::trace(visitor);
    SuspendableObject::trace(visitor);
=======
    RefCountedGarbageCollectedEventTargetWithInlineData<DOMWebSocket>::trace(visitor);
    ActiveDOMObject::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
