// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "WMLElementFactory.h"

#include "WMLNames.h"
#include "core/dom/Document.h"
#include "core/dom/custom/V0CustomElement.h"
#include "core/dom/custom/V0CustomElementRegistrationContext.h"
#include "core/frame/Settings.h"
#include "core/wml/WMLAElement.h"
#include "core/wml/WMLAccessElement.h"
#include "core/wml/WMLAnchorElement.h"
#include "core/wml/WMLBRElement.h"
#include "core/wml/WMLCardElement.h"
#include "core/wml/WMLDoElement.h"
#include "core/wml/WMLElement.h"
#include "core/wml/WMLFieldSetElement.h"
#include "core/wml/WMLGoElement.h"
#include "core/wml/WMLImageElement.h"
#include "core/wml/WMLInsertedLegendElement.h"
#include "core/wml/WMLMetaElement.h"
#include "core/wml/WMLNoopElement.h"
#include "core/wml/WMLOnEventElement.h"
#include "core/wml/WMLPElement.h"
#include "core/wml/WMLPostfieldElement.h"
#include "core/wml/WMLPrevElement.h"
#include "core/wml/WMLRefreshElement.h"
#include "core/wml/WMLSetvarElement.h"
#include "core/wml/WMLTableElement.h"
#include "core/wml/WMLTemplateElement.h"
#include "core/wml/WMLTimerElement.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "wtf/HashMap.h"

namespace blink {

using namespace WMLNames;

typedef WMLElement* (*ConstructorFunction)(
    Document&,
    CreateElementFlags);

typedef HashMap<AtomicString, ConstructorFunction> FunctionMap;

static FunctionMap* g_constructors = 0;

static WMLElement* headConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLElement::create(headTag, document);
}
static WMLElement* tdConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLElement::create(tdTag, document);
}
static WMLElement* trConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLElement::create(trTag, document);
}
static WMLElement* aConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLAElement::create(document);
}
static WMLElement* accessConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLAccessElement::create(document);
}
static WMLElement* anchorConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLAnchorElement::create(document);
}
static WMLElement* brConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLBRElement::create(document);
}
static WMLElement* cardConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLCardElement::create(document);
}
static WMLElement* doConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLDoElement::create(document);
}
static WMLElement* fieldsetConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLFieldSetElement::create(document);
}
static WMLElement* goConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLGoElement::create(document);
}
static WMLElement* imgConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLImageElement::create(document);
}
static WMLElement* insertedLegendConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLInsertedLegendElement::create(document);
}
static WMLElement* metaConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLMetaElement::create(document);
}
static WMLElement* noopConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLNoopElement::create(document);
}
static WMLElement* oneventConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLOnEventElement::create(document);
}
static WMLElement* pConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLPElement::create(document);
}
static WMLElement* postfieldConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLPostfieldElement::create(document);
}
static WMLElement* prevConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLPrevElement::create(document);
}
static WMLElement* refreshConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLRefreshElement::create(document);
}
static WMLElement* setvarConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLSetvarElement::create(document);
}
static WMLElement* tableConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLTableElement::create(document);
}
static WMLElement* templateConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLTemplateElement::create(document);
}
static WMLElement* timerConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return WMLTimerElement::create(document);
}

struct CreateWMLFunctionMapData {
    const QualifiedName& tag;
    ConstructorFunction func;
};

static void createWMLFunctionMap()
{
    ASSERT(!g_constructors);
    g_constructors = new FunctionMap;
    // Empty array initializer lists are illegal [dcl.init.aggr] and will not
    // compile in MSVC. If tags list is empty, add check to skip this.
    static const CreateWMLFunctionMapData data[] = {
        { headTag, headConstructor },
        { tdTag, tdConstructor },
        { trTag, trConstructor },
        { aTag, aConstructor },
        { accessTag, accessConstructor },
        { anchorTag, anchorConstructor },
        { brTag, brConstructor },
        { cardTag, cardConstructor },
        { doTag, doConstructor },
        { fieldsetTag, fieldsetConstructor },
        { goTag, goConstructor },
        { imgTag, imgConstructor },
        { insertedLegendTag, insertedLegendConstructor },
        { metaTag, metaConstructor },
        { noopTag, noopConstructor },
        { oneventTag, oneventConstructor },
        { pTag, pConstructor },
        { postfieldTag, postfieldConstructor },
        { prevTag, prevConstructor },
        { refreshTag, refreshConstructor },
        { setvarTag, setvarConstructor },
        { tableTag, tableConstructor },
        { templateTag, templateConstructor },
        { timerTag, timerConstructor },
    };
    for (size_t i = 0; i < WTF_ARRAY_LENGTH(data); i++)
        g_constructors->set(data[i].tag.localName(), data[i].func);
}

WMLElement* WMLElementFactory::createWMLElement(
    const AtomicString& localName,
    Document& document,
    CreateElementFlags flags)
{
    if (!g_constructors)
        createWMLFunctionMap();
    if (ConstructorFunction function = g_constructors->get(localName))
        return function(document, flags);

    if (document.registrationContext() && V0CustomElement::isValidName(localName)) {
        Element* element = document.registrationContext()->createCustomTagElement(
            document, QualifiedName(nullAtom, localName, wmlNamespaceURI));
        SECURITY_DCHECK(element->isWMLElement());
        return toWMLElement(element);
    }

    return WMLElement::create(QualifiedName(nullAtom, localName, wmlNamespaceURI), document);
}

} // namespace blink