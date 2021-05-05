/**
 * Copyright (C) 2008 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
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
#include "WMLPrevElement.h"

#include "WMLCardElement.h"
#include "WMLDocument.h"
#include "WMLPageState.h"
#include "WMLTimerElement.h"
#include "core/WMLNames.h"
#include "core/page/ChromeClient.h"
#include "core/page/Page.h"
#include "public/web/WebViewClient.h"
#include "web/ChromeClientImpl.h"
#include "web/WebViewImpl.h"

namespace blink {

WMLPrevElement::WMLPrevElement(Document& doc)
    : WMLTaskElement(WMLNames::prevTag, doc)
{
}

DEFINE_NODE_FACTORY(WMLPrevElement)

WMLPrevElement::~WMLPrevElement()
{
}

void WMLPrevElement::executeTask()
{
    ASSERT(document().isWMLDocument());
    WMLDocument* document = static_cast<WMLDocument*>(&this->document());

    WMLPageState* pageState = wmlPageStateForDocument(document);
    if (!pageState)
        return;

    WMLCardElement* card = document->activeCard();
    if (!card)
        return;

    storeVariableState(pageState);

    // Stop the timer of the current card if it is active
    if (WMLTimerElement* eventTimer = card->eventTimer())
        eventTimer->stop();

    //pageState->page()->backForward()->goBack();
    WebViewImpl* impl = WebViewImpl::fromPage(pageState->page());
    if (impl)
        impl->client()->navigateBackForwardSoon(-1);
}

DEFINE_TRACE(WMLPrevElement)
{
    WMLElement::trace(visitor);
}

}

#endif
