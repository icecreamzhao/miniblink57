// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/websockets/InspectorWebSocketEvents.h"

#include "core/dom/Document.h"
#include "platform/weborigin/KURL.h"
#include <memory>

namespace blink {

std::unique_ptr<TracedValue> InspectorWebSocketCreateEvent::data(
    Document* document,
    unsigned long identifier,
    const KURL& url,
    const String& protocol)
{
    std::unique_ptr<TracedValue> value = TracedValue::create();
    value->setInteger("identifier", identifier);
    value->setString("url", url.getString());
=======
#include "config.h"
#include "modules/websockets/InspectorWebSocketEvents.h"

#include "core/dom/Document.h"
#include "platform/TracedValue.h"
#include "platform/weborigin/KURL.h"

namespace blink {

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorWebSocketCreateEvent::data(Document* document, unsigned long identifier, const KURL& url, const String& protocol)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    RefPtr<TracedValue> value = TracedValue::create();
    value->setInteger("identifier", identifier);
    value->setString("url", url.string());
>>>>>>> miniblink49
    value->setString("frame", toHexString(document->frame()));
    if (!protocol.isNull())
        value->setString("webSocketProtocol", protocol);
    setCallStack(value.get());
<<<<<<< HEAD
    return value;
}

std::unique_ptr<TracedValue> InspectorWebSocketEvent::data(
    Document* document,
    unsigned long identifier)
{
    std::unique_ptr<TracedValue> value = TracedValue::create();
    value->setInteger("identifier", identifier);
    value->setString("frame", toHexString(document->frame()));
    setCallStack(value.get());
    return value;
=======
    return value.release();
#endif
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorWebSocketEvent::data(Document* document, unsigned long identifier)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    RefPtr<TracedValue> value = TracedValue::create();
    value->setInteger("identifier", identifier);
    value->setString("frame", toHexString(document->frame()));
    setCallStack(value.get());
    return value.release();
#endif
    return nullptr;
>>>>>>> miniblink49
}

} // namespace blink
