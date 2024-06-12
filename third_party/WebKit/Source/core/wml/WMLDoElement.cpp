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
#include "WMLDoElement.h"

#include "WMLCardElement.h"
#include "WMLDocument.h"
#include "WMLPageState.h"
#include "WMLTaskElement.h"
#include "WMLTimerElement.h"
#include "WMLVariables.h"
#include "core/EventNames.h"
#include "core/EventTypeNames.h"
#include "core/HTMLNames.h"
#include "core/WMLNames.h"
#include "core/dom/Attribute.h"
#include "core/events/Event.h"
#include "core/events/KeyboardEvent.h"
#include "core/layout/LayoutButton.h"
#include "core/layout/LayoutObject.h"
#include "core/layout/LayoutTextFragment.h"
#include "core/page/ChromeClient.h"
#include "core/page/Page.h"
#include "public/web/WebViewClient.h"
#include "web/ChromeClientImpl.h"
#include "web/WebViewImpl.h"

namespace blink {

using namespace WMLNames;

WMLDoElement::WMLDoElement(Document& doc)
    : WMLElement(doTag, doc)
    , m_task(0)
    , m_isActive(false)
    , m_isNoop(false)
    , m_isOptional(false)
    , m_buttonText(0)
{
}

DEFINE_NODE_FACTORY(WMLDoElement)

void WMLDoElement::defaultEventHandler(Event* event)
{
    if (m_isOptional)
        return;

    if (event->type() == EventTypeNames::keypress) {
        WMLElement::defaultEventHandler(event);
        return;
    }

    if (event->type() != EventTypeNames::click && event->type() != EventTypeNames::keydown)
        return;

    //     if (event->isKeyboardEvent() && static_cast<KeyboardEvent*>(event)->keyIdentifier() != "Enter")
    //         return;
    // SAMSUNG_WML_FIXES+
    // http://spe.mobilephone.net/wit/wmlv2/formselect.wml
    // http://spe.mobilephone.net/wit/wmlv2/formempty.wml
    //if (m_type == "accept" || m_type == "options") {
    String type = m_type.lower();
    if (type == "accept" || type == "options" || type == "go" || type == "help"
        || type == "delete" || type == "select" || type == "option" || type == "unknown") {
        // SAMSUNG_WML_FIXES-
        if (m_task)
            m_task->executeTask();
    } else if (m_type == "prev") {
        // SAMSUNG_WML_FIXES+
        // wml/struct/control/select/option/5
        if (m_task) {
            m_task->executeTask();
        } else {
            ASSERT(document().isWMLDocument());
            WMLDocument* document = static_cast<WMLDocument*>(&this->document());

            WMLPageState* pageState = wmlPageStateForDocument(document);
            if (!pageState)
                return;

            // Stop the timer of the current card if it is active
            if (WMLCardElement* card = document->activeCard()) {
                if (WMLTimerElement* eventTimer = card->eventTimer())
                    eventTimer->stop();
            }

            //pageState->page()->backForward()->goBack();
            WebViewImpl* impl = WebViewImpl::fromPage(pageState->page());
            if (impl)
                impl->client()->navigateBackForwardSoon(-1);
        }
        // SAMSUNG_WML_FIXES-
    } else if (m_type == "reset") {
        WMLPageState* pageState = wmlPageStateForDocument(&document());
        if (!pageState)
            return;

        pageState->reset();
    }
}

void WMLDoElement::parseAttribute(const AttributeModificationParams& params)
{
    if (params.name == HTMLNames::typeAttr)
        m_type = parseValueForbiddingVariableReferences(params.newValue);
    else if (params.name == HTMLNames::nameAttr)
        m_name = parseValueForbiddingVariableReferences(params.newValue);
    else if (params.name == optionalAttr)
#ifdef TENCENT_CHANGES
    {
        //    m_isOptional = (attr->value() == "true");// this line is commented by harry guo. Optional tag is
        return; // supported but Opera doesn't support.So we currently keep the same with Opera.
    }
#endif // TENCENT_CHANGES
    else
        WMLElement::parseAttribute(params);
}

Node::InsertionNotificationRequest WMLDoElement::insertedInto(ContainerNode* node)
{
    WMLElement::insertedInto(node);

    // Spec: An unspecified 'name' defaults to the value of the 'type' attribute.
    if (!hasAttribute(HTMLNames::nameAttr))
        m_name = m_type;

    ContainerNode* parent = parentNode();
    if (!parent || !parent->isWMLElement())
        return InsertionDone;

    if (WMLEventHandlingElement* eventHandlingElement = toWMLEventHandlingElement(static_cast<WMLElement*>(parent)))
        eventHandlingElement->registerDoElement(this, &document());

    return InsertionDone;
}

void WMLDoElement::removedFrom(ContainerNode* node)
{
    ContainerNode* parent = parentNode();

    if (parent && parent->isWMLElement()) {
        if (WMLEventHandlingElement* eventHandlingElement = toWMLEventHandlingElement(static_cast<WMLElement*>(parent)))
            eventHandlingElement->deregisterDoElement(this);
    }

    WMLElement::removedFrom(node);
}

void WMLDoElement::setText(const String& str, LayoutButton* renderButton)
{
    if (str.isEmpty()) {
        if (m_buttonText) {
            m_buttonText->destroy();
            m_buttonText = 0;
        }
    } else {
        if (m_buttonText)
            m_buttonText->setText(str.impl());
        else {
            m_buttonText = new LayoutTextFragment(&document(), str.impl());
            m_buttonText->setStyle(renderButton->mutableStyle());

            renderButton->addChild(m_buttonText);
        }
    }
}

void WMLDoElement::attachLayoutTree(const AttachContext& attachContext)
{
    WMLElement::attachLayoutTree(attachContext);

    // The call to updateFromElement() needs to go after the call through
    // to the base class's attach() because that can sometimes do a close
    // on the renderer.
    if (LayoutButton* renderButton = (LayoutButton*)layoutObject()) {
        renderButton->updateFromElement();

        String value = label();
        if (value.isEmpty())
            value = name();

        setText(value, renderButton);
    }
}

void WMLDoElement::detachLayoutTree(const AttachContext& attachContext)
{
    WMLElement::detachLayoutTree(attachContext);
    m_buttonText = nullptr;
}

LayoutObject* WMLDoElement::createLayoutObject(const ComputedStyle& style)
{
    if (!m_isActive || m_isOptional || m_isNoop)
        return 0;

    LayoutObject* result = new LayoutButton(this);

    result->setStyle((ComputedStyle*)&style);
    result->mutableStyle()->setUnique();
    result->mutableStyle()->setBackgroundColor(StyleColor(Color::lightGray));

    return result;
}

void WMLDoElement::recalcStyle(StyleRecalcChange change, Text* nextTextSibling)
{
    WMLElement::recalcStyle(change, nextTextSibling);

    if (layoutObject())
        layoutObject()->updateFromElement();
}

void WMLDoElement::registerTask(WMLTaskElement* task)
{
    ASSERT(!m_task);
    m_task = task;
}

void WMLDoElement::deregisterTask(WMLTaskElement* task)
{
    //ASSERT_UNUSED(task, m_task == task);
    m_task = 0;
}

String WMLDoElement::label() const
{
    return parseValueSubstitutingVariableReferences(getAttribute(HTMLNames::labelAttr));
}

DEFINE_TRACE(WMLDoElement)
{
    WMLElement::trace(visitor);
}

}

#endif
