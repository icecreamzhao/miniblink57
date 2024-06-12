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
#include "WMLAnchorElement.h"

#include "WMLNames.h"
#include "WMLTaskElement.h"
#include "core/EventNames.h"
#include "core/HTMLNames.h"
#include "core/events/KeyboardEvent.h"

namespace blink {

WMLAnchorElement::WMLAnchorElement(Document& doc)
    : WMLAElement(WMLNames::anchorTag, doc)
#ifndef TENCENT_CHANGES
    , m_task(0)
#endif
{
#ifdef TENCENT_CHANGES
    m_taskList.clear();
#endif
    // Calling setIsLink(), and returning a non-null value on CSSStyleSelectors' linkAttribute
    // method, makes it possible to 'appear as link' (just like <a href="..">) without the need to
    // actually set the href value to an empty value in the DOM tree.
    setIsLink(true);
}

DEFINE_NODE_FACTORY(WMLAnchorElement)

WMLAnchorElement::~WMLAnchorElement()
{
}

void WMLAnchorElement::defaultEventHandler(Event* event)
{
    bool shouldHandle = false;

    if (event->type() == EventTypeNames::click)
        shouldHandle = true;
        //     else if (event->type() == EventTypeNames::keydown && event->isKeyboardEvent() && isFocused())
        //         shouldHandle = static_cast<KeyboardEvent*>(event)->keyIdentifier() == "Enter";

#ifdef TENCENT_CHANGES
    if (shouldHandle) {
        for (std::vector<WMLTaskElement*>::iterator it = m_taskList.begin(); it != m_taskList.end(); it++) {
            (*it)->executeTask();
        }

        event->setDefaultHandled();
        return;
    }
#else
    if (shouldHandle && m_task) {
        m_task->executeTask();
        event->setDefaultHandled();
        return;
    }
#endif

    // Skip WMLAElement::defaultEventHandler, we don't own a href attribute, that needs to be handled.
    WMLElement::defaultEventHandler(event);
}

void WMLAnchorElement::registerTask(WMLTaskElement* task)
{
#ifdef TENCENT_CHANGES
    m_taskList.push_back(task);
#else
    ASSERT(!m_task);
    m_task = task;
#endif
}

void WMLAnchorElement::deregisterTask(WMLTaskElement* task)
{
#ifdef TENCENT_CHANGES
    for (std::vector<WMLTaskElement*>::iterator it = m_taskList.begin();
         it != m_taskList.end(); it++) {
        if (*it == task) {
            m_taskList.erase(it);
            return;
        }
    }
#else
    ASSERT_UNUSED(task, m_task == task);
    m_task = 0;
#endif
}

DEFINE_TRACE(WMLAnchorElement)
{
    WMLElement::trace(visitor);
}

}

#endif
