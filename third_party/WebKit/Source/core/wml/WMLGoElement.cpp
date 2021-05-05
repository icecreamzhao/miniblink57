/**
 * Copyright (C) 2008, 2009 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#include "config.h"

#if ENABLE_WML
#include "WMLGoElement.h"

#include "WMLCardElement.h"
#include "WMLDocument.h"
#include "WMLPageState.h"
#include "WMLPostfieldElement.h"
#include "WMLTimerElement.h"
#include "WMLVariables.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include "core/dom/Attribute.h"
#include "core/frame/LocalFrame.h"
#include "core/html/FormData.h"
#include "core/loader/FormSubmission.h"
#include "core/loader/FrameLoadRequest.h"
#include "core/loader/FrameLoader.h"
#include "platform/network/FormDataEncoder.h"
#include "platform/network/ResourceRequest.h"
#include "public/platform/WebCachePolicy.h"
#include <wtf/text/CString.h>
#include <wtf/text/TextEncoding.h>

namespace blink {

using namespace WMLNames;

WMLGoElement::WMLGoElement(Document& doc)
    : WMLTaskElement(goTag, doc)
{
}

DEFINE_NODE_FACTORY(WMLGoElement)

void WMLGoElement::registerPostfieldElement(WMLPostfieldElement* postfield)
{
    ASSERT(m_postfieldElements.find(postfield) == WTF::kNotFound);
    m_postfieldElements.append(postfield);
}

void WMLGoElement::deregisterPostfieldElement(WMLPostfieldElement* postfield)
{
    size_t position = m_postfieldElements.find(postfield);
    ASSERT(position != WTF::kNotFound);
    m_postfieldElements.remove(position);
}

void WMLGoElement::parseAttribute(const AttributeModificationParams& params)
{
    if (params.name == HTMLNames::methodAttr) {
#ifdef TENCENT_CHANGES
        // 2012-08-24
        // cameralu
        // here, webkit finds method, but not set it, so post method of wml go element is invalid,
        // we should set it
        m_formAttributes.updateMethodType(params.newValue);
#else
        m_formAttributes.parseMethodType(value);
#endif
    } else if (params.name == HTMLNames::enctypeAttr)
        m_formAttributes.parseEncodingType(parseValueSubstitutingVariableReferences(params.newValue));
    else if (params.name == HTMLNames::accept_charsetAttr)
        m_formAttributes.setAcceptCharset(parseValueForbiddingVariableReferences(params.newValue));
    else
        WMLTaskElement::parseAttribute(params);
}

void WMLGoElement::executeTask()
{
    ASSERT(document().isWMLDocument());
    WMLDocument* document = static_cast<WMLDocument*>(&this->document());

    WMLPageState* pageState = wmlPageStateForDocument(document);
    if (!pageState)
        return;

    WMLCardElement* card = document->activeCard();
    if (!card)
        return;

    LocalFrame* frame = document->frame();
    if (!frame)
        return;

    FrameLoader* loader = &frame->loader();
    if (!loader)
        return;

    String href = getAttribute(HTMLNames::hrefAttr);
    if (href.isEmpty())
        return;

    // Substitute variables within target url attribute value
    KURL url = document->completeURL(substituteVariableReferences(href, document, WMLVariableEscapingEscape));
    if (url.isEmpty())
        return;

    pageState->reset();

    //totrit: collect the input-elemnts' variables first.
    pageState->collectSelectElementVariables();
    pageState->collectInputElementVariables();
    storeVariableState(pageState);

    // Stop the timer of the current card if it is active
    if (WMLTimerElement* eventTimer = card->eventTimer())
        eventTimer->stop();

    // FIXME: 'newcontext' handling not implemented for external cards
    bool inSameDeck = document->url().path() == url.path();
    if (inSameDeck && url.hasFragmentIdentifier()) {
        if (WMLCardElement* card = WMLCardElement::findNamedCardInDocument(document, url.fragmentIdentifier())) {
            if (card->isNewContext())
                pageState->reset();
        }
    }

    // Prepare loading the destination url
    ResourceRequest request(url);

    if (getAttribute(sendrefererAttr) == "true")
        request.setHTTPReferrer(Referrer(document->outgoingReferrer(), ReferrerPolicyDefault));

    String cacheControl = getAttribute(cache_controlAttr);

    if (m_formAttributes.method() == FormSubmission::PostMethod)
        preparePOSTRequest(request, inSameDeck, cacheControl);
    else
        prepareGETRequest(request, url);

    // Set HTTP cache-control header if needed
    if (!cacheControl.isEmpty()) {
        request.setHTTPHeaderField("cache-control", AtomicString(cacheControl));

        if (cacheControl == "no-cache")
            request.setCachePolicy(WebCachePolicy::ValidatingCacheData /*ReloadIgnoringCacheData*/);
    }

    loader->load(FrameLoadRequest(document, request));
}

void WMLGoElement::preparePOSTRequest(ResourceRequest& request, bool inSameDeck, const String& cacheControl)
{
    request.setHTTPMethod("POST");

#ifndef TENCENT_CHANGES
    if (inSameDeck && cacheControl != "no-cache") {
        request.setCachePolicy(ReturnCacheDataDontLoad);
        return;
    }
#endif

    RefPtr<EncodedFormData> data;

    if (m_formAttributes.isMultiPartForm()) { // multipart/form-data
        Vector<char> boundary = FormDataEncoder::generateUniqueBoundaryString();
        data = createFormData(boundary.data());
        request.setHTTPContentType(m_formAttributes.encodingType() + "; boundary=" + boundary.data());
    } else {
        // text/plain or application/x-www-form-urlencoded
        data = createFormData(CString());
        request.setHTTPContentType(m_formAttributes.encodingType());
    }

    request.setHTTPBody(data);
}

void WMLGoElement::prepareGETRequest(ResourceRequest& request, const KURL& url)
{
    request.setHTTPMethod("GET");

    // Eventually display error message?
    if (m_formAttributes.isMultiPartForm())
        return;

    RefPtr<EncodedFormData> data = createFormData(CString());
    // SAMSUNG_WML_FIXES+
    // http://218.248.40.195/vswap2/interface/ExamineTest?id=wml/events/intrinsics/1&ts=0051
    if (m_postfieldElements.size() > 0) {
        KURL remoteURL(url);

        // BUG FIX postfields content must after the orginal query string
        // modified by wileywang@2012-11-15 11:37
        if (url.query().length() > 0) {
            remoteURL.setQuery(url.query() + "&" + data->flattenToString());
        } else {
            remoteURL.setQuery(data->flattenToString());
        }
        // modified end

        request.setURL(remoteURL);
    }
    // SAMSUNG_WML_FIXES-
}

PassRefPtr<EncodedFormData> WMLGoElement::createFormData(const CString& boundary)
{
    CString key;
    CString value;

    Vector<char> encodedData;
    WTF::TextEncoding encoding = FormDataEncoder::encodingFromAcceptCharset(m_formAttributes.acceptCharset(), document().encoding()).encodingForFormSubmission();

    HeapVector<Member<WMLPostfieldElement>>::iterator it = m_postfieldElements.begin();
    HeapVector<Member<WMLPostfieldElement>>::iterator end = m_postfieldElements.end();

    RefPtr<EncodedFormData> result = EncodedFormData::create();
    for (; it != end; ++it) {
        (*it)->encodeData(encoding, key, value);

        if (m_formAttributes.isMultiPartForm()) {
            Vector<char> header;
            FormDataEncoder::beginMultiPartHeader(header, boundary, key);
            FormDataEncoder::finishMultiPartHeader(header);
            result->appendData(header.data(), header.size());

            if (size_t dataSize = value.length())
                result->appendData(value.data(), dataSize);

            result->appendData("\r\n", 2);
        } else
            FormDataEncoder::addKeyValuePairAsFormData(encodedData, key, value);
    }
    // SAMSUNG_WML_FIXES+
    // http://218.248.40.195/vswap2/interface/ExamineTest?id=wml/events/intrinsics/1&ts=0051
    // Check if we have some encoded data before appending it.
    if (encodedData.size() > 0) {
        if (m_formAttributes.isMultiPartForm())
            FormDataEncoder::addBoundaryToMultiPartHeader(encodedData, boundary, true);

        result->appendData(encodedData.data(), encodedData.size());
    }
    // SAMSUNG_WML_FIXES-
    return result;
}

KURL WMLGoElement::href()
{
    ASSERT(document().isWMLDocument());
    WMLDocument* document = static_cast<WMLDocument*>(&this->document());

    WMLPageState* pageState = wmlPageStateForDocument(document);
    if (!pageState)
        return KURL();

    WMLCardElement* card = document->activeCard();
    if (!card)
        return KURL();

    String href = getAttribute(HTMLNames::hrefAttr);
    if (href.isEmpty())
        return KURL();

    // Substitute variables within target url attribute value
    KURL url = document->completeURL(substituteVariableReferences(href, document, WMLVariableEscapingEscape));
    if (url.isEmpty())
        return KURL();

    storeVariableState(pageState);

    // FIXME: 'newcontext' handling not implemented for external cards
    bool inSameDeck = document->url().path() == url.path();
    if (inSameDeck && url.hasFragmentIdentifier()) {
        if (WMLCardElement* card = WMLCardElement::findNamedCardInDocument(document, url.fragmentIdentifier())) {
            if (card->isNewContext())
                pageState->reset();
        }
    }

    // Prepare loading the destination url
    ResourceRequest request(url);

    if (getAttribute(sendrefererAttr) == "true")
        request.setHTTPReferrer(Referrer(document->outgoingReferrer(), ReferrerPolicyDefault));
    //request.setHTTPReferrer(content::Referrer(GURL(std::string(document->outgoingReferrer().characters8())), blink::WebReferrerPolicyDefault));

    String cacheControl = getAttribute(cache_controlAttr);

    if (m_formAttributes.method() == FormSubmission::PostMethod)
        preparePOSTRequest(request, inSameDeck, cacheControl);
    else
        prepareGETRequest(request, url);

    return url;
}

DEFINE_TRACE(WMLGoElement)
{
    visitor->trace(m_postfieldElements);
    WMLElement::trace(visitor);
}

}

#endif
