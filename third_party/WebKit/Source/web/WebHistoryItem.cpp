/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
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
#include "public/web/WebHistoryItem.h"

#include "bindings/core/v8/SerializedScriptValue.h"
#include "core/loader/HistoryItem.h"
<<<<<<< HEAD
#include "platform/network/EncodedFormData.h"
=======
#include "platform/network/FormData.h"
>>>>>>> miniblink49
#include "platform/weborigin/KURL.h"
#include "public/platform/WebFloatPoint.h"
#include "public/platform/WebHTTPBody.h"
#include "public/platform/WebPoint.h"
#include "public/platform/WebString.h"
#include "public/platform/WebVector.h"
#include "public/web/WebSerializedScriptValue.h"
#include "wtf/text/StringHash.h"

namespace blink {

void WebHistoryItem::initialize()
{
    m_private = HistoryItem::create();
}

void WebHistoryItem::reset()
{
    m_private.reset();
}

void WebHistoryItem::assign(const WebHistoryItem& other)
{
    m_private = other.m_private;
}

WebString WebHistoryItem::urlString() const
{
    return m_private->urlString();
}

void WebHistoryItem::setURLString(const WebString& url)
{
<<<<<<< HEAD
    m_private->setURLString(KURL(ParsedURLString, url).getString());
=======
    m_private->setURLString(KURL(ParsedURLString, url).string());
>>>>>>> miniblink49
}

WebString WebHistoryItem::referrer() const
{
    return m_private->referrer().referrer;
}

<<<<<<< HEAD
WebReferrerPolicy WebHistoryItem::getReferrerPolicy() const
=======
WebReferrerPolicy WebHistoryItem::referrerPolicy() const
>>>>>>> miniblink49
{
    return static_cast<WebReferrerPolicy>(m_private->referrer().referrerPolicy);
}

<<<<<<< HEAD
void WebHistoryItem::setReferrer(const WebString& referrer,
    WebReferrerPolicy referrerPolicy)
{
    m_private->setReferrer(
        Referrer(referrer, static_cast<ReferrerPolicy>(referrerPolicy)));
=======
void WebHistoryItem::setReferrer(const WebString& referrer, WebReferrerPolicy referrerPolicy)
{
    m_private->setReferrer(Referrer(referrer, static_cast<ReferrerPolicy>(referrerPolicy)));
>>>>>>> miniblink49
}

WebString WebHistoryItem::target() const
{
    return m_private->target();
}

void WebHistoryItem::setTarget(const WebString& target)
{
    m_private->setTarget(target);
}

<<<<<<< HEAD
WebFloatPoint WebHistoryItem::visualViewportScrollOffset() const
{
    ScrollOffset offset = m_private->visualViewportScrollOffset();
    return WebFloatPoint(offset.width(), offset.height());
}

void WebHistoryItem::setVisualViewportScrollOffset(
    const WebFloatPoint& scrollOffset)
{
    m_private->setVisualViewportScrollOffset(toScrollOffset(scrollOffset));
}

WebPoint WebHistoryItem::getScrollOffset() const
{
    ScrollOffset offset = m_private->getScrollOffset();
    return WebPoint(offset.width(), offset.height());
=======
WebFloatPoint WebHistoryItem::pinchViewportScrollOffset() const
{
    return m_private->pinchViewportScrollPoint();
}

void WebHistoryItem::setPinchViewportScrollOffset(const WebFloatPoint& scrollOffset)
{
    m_private->setPinchViewportScrollPoint(scrollOffset);
}

WebPoint WebHistoryItem::scrollOffset() const
{
    return m_private->scrollPoint();
>>>>>>> miniblink49
}

void WebHistoryItem::setScrollOffset(const WebPoint& scrollOffset)
{
<<<<<<< HEAD
    m_private->setScrollOffset(ScrollOffset(scrollOffset.x, scrollOffset.y));
=======
    m_private->setScrollPoint(scrollOffset);
>>>>>>> miniblink49
}

float WebHistoryItem::pageScaleFactor() const
{
    return m_private->pageScaleFactor();
}

void WebHistoryItem::setPageScaleFactor(float scale)
{
    m_private->setPageScaleFactor(scale);
}

<<<<<<< HEAD
WebVector<WebString> WebHistoryItem::getDocumentState() const
{
    return m_private->getDocumentState();
=======
WebVector<WebString> WebHistoryItem::documentState() const
{
    return m_private->documentState();
>>>>>>> miniblink49
}

void WebHistoryItem::setDocumentState(const WebVector<WebString>& state)
{
    // FIXME: would be nice to avoid the intermediate copy
    Vector<String> ds;
    for (size_t i = 0; i < state.size(); ++i)
<<<<<<< HEAD
        ds.push_back(state[i]);
=======
        ds.append(state[i]);
>>>>>>> miniblink49
    m_private->setDocumentState(ds);
}

long long WebHistoryItem::itemSequenceNumber() const
{
    return m_private->itemSequenceNumber();
}

void WebHistoryItem::setItemSequenceNumber(long long itemSequenceNumber)
{
    m_private->setItemSequenceNumber(itemSequenceNumber);
}

long long WebHistoryItem::documentSequenceNumber() const
{
    return m_private->documentSequenceNumber();
}

<<<<<<< HEAD
void WebHistoryItem::setDocumentSequenceNumber(
    long long documentSequenceNumber)
=======
void WebHistoryItem::setDocumentSequenceNumber(long long documentSequenceNumber)
>>>>>>> miniblink49
{
    m_private->setDocumentSequenceNumber(documentSequenceNumber);
}

WebHistoryScrollRestorationType WebHistoryItem::scrollRestorationType() const
{
<<<<<<< HEAD
    return static_cast<WebHistoryScrollRestorationType>(
        m_private->scrollRestorationType());
}

void WebHistoryItem::setScrollRestorationType(
    WebHistoryScrollRestorationType type)
{
    m_private->setScrollRestorationType(
        static_cast<HistoryScrollRestorationType>(type));
=======
    return static_cast<WebHistoryScrollRestorationType>(m_private->scrollRestorationType());
}

void WebHistoryItem::setScrollRestorationType(WebHistoryScrollRestorationType type)
{
    m_private->setScrollRestorationType(static_cast<HistoryScrollRestorationType>(type));
>>>>>>> miniblink49
}

WebSerializedScriptValue WebHistoryItem::stateObject() const
{
    return WebSerializedScriptValue(m_private->stateObject());
}

void WebHistoryItem::setStateObject(const WebSerializedScriptValue& object)
{
    m_private->setStateObject(object);
}

WebString WebHistoryItem::httpContentType() const
{
    return m_private->formContentType();
}

void WebHistoryItem::setHTTPContentType(const WebString& httpContentType)
{
    m_private->setFormContentType(httpContentType);
}

WebHTTPBody WebHistoryItem::httpBody() const
{
    return WebHTTPBody(m_private->formData());
}

void WebHistoryItem::setHTTPBody(const WebHTTPBody& httpBody)
{
    m_private->setFormData(httpBody);
}

WebVector<WebString> WebHistoryItem::getReferencedFilePaths() const
{
    HashSet<String> filePaths;
<<<<<<< HEAD
    const EncodedFormData* formData = m_private->formData();
=======
    const FormData* formData = m_private->formData();
>>>>>>> miniblink49
    if (formData) {
        for (size_t i = 0; i < formData->elements().size(); ++i) {
            const FormDataElement& element = formData->elements()[i];
            if (element.m_type == FormDataElement::encodedFile)
                filePaths.add(element.m_filename);
        }
    }

    const Vector<String>& referencedFilePaths = m_private->getReferencedFilePaths();
    for (size_t i = 0; i < referencedFilePaths.size(); ++i)
        filePaths.add(referencedFilePaths[i]);

    Vector<String> results;
    copyToVector(filePaths, results);
    return results;
}

<<<<<<< HEAD
WebHistoryItem::WebHistoryItem(HistoryItem* item)
=======
WebHistoryItem::WebHistoryItem(const PassRefPtrWillBeRawPtr<HistoryItem>& item)
>>>>>>> miniblink49
    : m_private(item)
{
}

<<<<<<< HEAD
WebHistoryItem& WebHistoryItem::operator=(HistoryItem* item)
=======
WebHistoryItem& WebHistoryItem::operator=(const PassRefPtrWillBeRawPtr<HistoryItem>& item)
>>>>>>> miniblink49
{
    m_private = item;
    return *this;
}

<<<<<<< HEAD
WebHistoryItem::operator HistoryItem*() const
=======
WebHistoryItem::operator PassRefPtrWillBeRawPtr<HistoryItem>() const
>>>>>>> miniblink49
{
    return m_private.get();
}

} // namespace blink
