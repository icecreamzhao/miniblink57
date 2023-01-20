// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/beacon/NavigatorBeacon.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/modules/v8/ArrayBufferViewOrBlobOrStringOrFormData.h"
#include "core/dom/DOMArrayBufferView.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "core/fetch/FetchUtils.h"
=======
#include "config.h"
#include "modules/beacon/NavigatorBeacon.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/modules/v8/UnionTypesModules.h"
#include "core/dom/DOMArrayBufferView.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
>>>>>>> miniblink49
#include "core/fileapi/Blob.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/Settings.h"
#include "core/frame/UseCounter.h"
#include "core/frame/csp/ContentSecurityPolicy.h"
<<<<<<< HEAD
#include "core/html/FormData.h"
#include "core/loader/PingLoader.h"
=======
#include "core/html/DOMFormData.h"
#include "core/loader/BeaconLoader.h"
>>>>>>> miniblink49

namespace blink {

NavigatorBeacon::NavigatorBeacon(Navigator& navigator)
<<<<<<< HEAD
    : Supplement<Navigator>(navigator)
=======
    : LocalFrameLifecycleObserver(navigator.frame())
>>>>>>> miniblink49
    , m_transmittedBytes(0)
{
}

<<<<<<< HEAD
NavigatorBeacon::~NavigatorBeacon() { }

DEFINE_TRACE(NavigatorBeacon)
{
    Supplement<Navigator>::trace(visitor);
=======
NavigatorBeacon::~NavigatorBeacon()
{
}

DEFINE_TRACE(NavigatorBeacon)
{
    LocalFrameLifecycleObserver::trace(visitor);
    HeapSupplement<Navigator>::trace(visitor);
>>>>>>> miniblink49
}

const char* NavigatorBeacon::supplementName()
{
    return "NavigatorBeacon";
}

NavigatorBeacon& NavigatorBeacon::from(Navigator& navigator)
{
<<<<<<< HEAD
    NavigatorBeacon* supplement = static_cast<NavigatorBeacon*>(
        Supplement<Navigator>::from(navigator, supplementName()));
=======
    NavigatorBeacon* supplement = static_cast<NavigatorBeacon*>(HeapSupplement<Navigator>::from(navigator, supplementName()));
>>>>>>> miniblink49
    if (!supplement) {
        supplement = new NavigatorBeacon(navigator);
        provideTo(navigator, supplementName(), supplement);
    }
    return *supplement;
}

<<<<<<< HEAD
bool NavigatorBeacon::canSendBeacon(ExecutionContext* context,
    const KURL& url,
    ExceptionState& exceptionState)
{
    if (!url.isValid()) {
        exceptionState.throwDOMException(
            SyntaxError, "The URL argument is ill-formed or unsupported.");
=======
bool NavigatorBeacon::canSendBeacon(ExecutionContext* context, const KURL& url, ExceptionState& exceptionState)
{
    if (!url.isValid()) {
        exceptionState.throwDOMException(SyntaxError, "The URL argument is ill-formed or unsupported.");
>>>>>>> miniblink49
        return false;
    }
    // For now, only support HTTP and related.
    if (!url.protocolIsInHTTPFamily()) {
<<<<<<< HEAD
        exceptionState.throwDOMException(
            SyntaxError, "Beacons are only supported over HTTP(S).");
=======
        exceptionState.throwDOMException(SyntaxError, "Beacons are only supported over HTTP(S).");
>>>>>>> miniblink49
        return false;
    }
    // FIXME: CSP is not enforced on redirects, crbug.com/372197
    if (!ContentSecurityPolicy::shouldBypassMainWorld(context) && !context->contentSecurityPolicy()->allowConnectToSource(url)) {
<<<<<<< HEAD
        // We can safely expose the URL to JavaScript, as these checks happen
        // synchronously before redirection. JavaScript receives no new information.
        exceptionState.throwSecurityError(
            "Refused to send beacon to '" + url.elidedString() + "' because it violates the document's Content Security Policy.");
=======
        // We can safely expose the URL to JavaScript, as these checks happen synchronously before redirection. JavaScript receives no new information.
        exceptionState.throwSecurityError("Refused to send beacon to '" + url.elidedString() + "' because it violates the document's Content Security Policy.");
>>>>>>> miniblink49
        return false;
    }

    // If detached from frame, do not allow sending a Beacon.
<<<<<<< HEAD
    if (!supplementable()->frame())
=======
    if (!frame() || !frame()->client())
>>>>>>> miniblink49
        return false;

    return true;
}

int NavigatorBeacon::maxAllowance() const
{
<<<<<<< HEAD
    DCHECK(supplementable()->frame());
    const Settings* settings = supplementable()->frame()->settings();
    if (settings) {
        int maxAllowed = settings->getMaxBeaconTransmission();
=======
    ASSERT(frame());
    const Settings* settings = frame()->settings();
    if (settings) {
        int maxAllowed = settings->maxBeaconTransmission();
>>>>>>> miniblink49
        if (maxAllowed < m_transmittedBytes)
            return 0;
        return maxAllowed - m_transmittedBytes;
    }
    return m_transmittedBytes;
}

<<<<<<< HEAD
void NavigatorBeacon::addTransmittedBytes(int sentBytes)
{
    DCHECK_GE(sentBytes, 0);
    m_transmittedBytes += sentBytes;
}

bool NavigatorBeacon::sendBeacon(
    ScriptState* scriptState,
    Navigator& navigator,
    const String& urlstring,
    const ArrayBufferViewOrBlobOrStringOrFormData& data,
    ExceptionState& exceptionState)
{
    return NavigatorBeacon::from(navigator).sendBeaconImpl(scriptState, urlstring,
        data, exceptionState);
}

bool NavigatorBeacon::sendBeaconImpl(
    ScriptState* scriptState,
    const String& urlstring,
    const ArrayBufferViewOrBlobOrStringOrFormData& data,
    ExceptionState& exceptionState)
{
    ExecutionContext* context = scriptState->getExecutionContext();
    KURL url = context->completeURL(urlstring);
    if (!canSendBeacon(context, url, exceptionState))
        return false;

    int allowance = maxAllowance();
    int bytes = 0;
    bool allowed;

    if (data.isArrayBufferView()) {
        allowed = PingLoader::sendBeacon(supplementable()->frame(), allowance, url,
            data.getAsArrayBufferView(), bytes);
    } else if (data.isBlob()) {
        Blob* blob = data.getAsBlob();
        if (!FetchUtils::isSimpleContentType(AtomicString(blob->type()))) {
            UseCounter::count(context,
                UseCounter::SendBeaconWithNonSimpleContentType);
            if (RuntimeEnabledFeatures::
                    sendBeaconThrowForBlobWithNonSimpleTypeEnabled()) {
                exceptionState.throwSecurityError(
                    "sendBeacon() with a Blob whose type is not CORS-safelisted MIME "
                    "type is disallowed experimentally. See http://crbug.com/490015 "
                    "for details.");
                return false;
            }
        }
        allowed = PingLoader::sendBeacon(supplementable()->frame(), allowance, url,
            blob, bytes);
    } else if (data.isString()) {
        allowed = PingLoader::sendBeacon(supplementable()->frame(), allowance, url,
            data.getAsString(), bytes);
    } else if (data.isFormData()) {
        allowed = PingLoader::sendBeacon(supplementable()->frame(), allowance, url,
            data.getAsFormData(), bytes);
    } else {
        allowed = PingLoader::sendBeacon(supplementable()->frame(), allowance, url,
            String(), bytes);
    }

    if (allowed) {
        addTransmittedBytes(bytes);
        return true;
    }

    UseCounter::count(context, UseCounter::SendBeaconQuotaExceeded);
    return false;
=======
bool NavigatorBeacon::beaconResult(ExecutionContext* context, bool allowed, int sentBytes)
{
    if (allowed) {
        ASSERT(sentBytes >= 0);
        m_transmittedBytes += sentBytes;
    } else {
        UseCounter::count(context, UseCounter::SendBeaconQuotaExceeded);
    }
    return allowed;
}

bool NavigatorBeacon::sendBeacon(ExecutionContext* context, Navigator& navigator, const String& urlstring, const ArrayBufferViewOrBlobOrStringOrFormData& data, ExceptionState& exceptionState)
{
    NavigatorBeacon& impl = NavigatorBeacon::from(navigator);

    KURL url = context->completeURL(urlstring);
    if (!impl.canSendBeacon(context, url, exceptionState))
        return false;

    int allowance = impl.maxAllowance();
    int bytes = 0;
    bool allowed;

    if (data.isArrayBufferView())
        allowed = BeaconLoader::sendBeacon(impl.frame(), allowance, url, data.getAsArrayBufferView(), bytes);
    else if (data.isBlob())
        allowed = BeaconLoader::sendBeacon(impl.frame(), allowance, url, data.getAsBlob(), bytes);
    else if (data.isString())
        allowed = BeaconLoader::sendBeacon(impl.frame(), allowance, url, data.getAsString(), bytes);
    else if (data.isFormData())
        allowed = BeaconLoader::sendBeacon(impl.frame(), allowance, url, data.getAsFormData(), bytes);
    else
        allowed = BeaconLoader::sendBeacon(impl.frame(), allowance, url, String(), bytes);

    return impl.beaconResult(context, allowed, bytes);
>>>>>>> miniblink49
}

} // namespace blink
