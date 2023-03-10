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
#include "WMLRefreshElement.h"

#include "WMLCardElement.h"
#include "WMLDocument.h"
#include "WMLPageState.h"
#include "WMLTimerElement.h"
#include "core/WMLNames.h"
#include "core/frame/Frame.h"
#include "core/frame/FrameTypes.h"
#include "core/frame/LocalFrame.h"
#include "core/loader/FrameLoader.h"

namespace blink {

WMLRefreshElement::WMLRefreshElement(Document& doc)
    : WMLTaskElement(WMLNames::refreshTag, doc)
{
}

DEFINE_NODE_FACTORY(WMLRefreshElement)

WMLRefreshElement::~WMLRefreshElement()
{
}

void WMLRefreshElement::executeTask()
{
    ASSERT(document().isWMLDocument());
    WMLDocument* document = static_cast<WMLDocument*>(&this->document());

    WMLPageState* pageState = wmlPageStateForDocument(document);
    if (!pageState)
        return;

    WMLCardElement* card = document->activeCard();
    if (!card)
        return;

    // Before perform refresh task, we store the current timeout
    // value in the page state and then stop the timer
    WMLTimerElement* timer = card->eventTimer();
    if (timer) {
        timer->storeIntervalToPageState();
        timer->stop();
    }

    storeVariableState(pageState);

    // Redisplay curremt card with current variable state
    if (LocalFrame* frame = document->frame()) {
        frame->reload(FrameLoadTypeReload, ClientRedirectPolicy::NotClientRedirect);
        //if (FrameLoader* loader = &frame->loader())
        //    loader->reload();
    }

    // After refreshing task, resume the timer if it exsits
    if (timer)
        timer->start();
}

DEFINE_TRACE(WMLRefreshElement)
{
    WMLElement::trace(visitor);
}

}

#endif
