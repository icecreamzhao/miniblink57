/*
 *  Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies)
 *  Copyright (C) 2008 Apple Inc. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
<<<<<<< HEAD
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA 02110-1301 USA
 */

=======
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "config.h"
>>>>>>> miniblink49
#include "modules/plugins/DOMPluginArray.h"

#include "core/frame/LocalFrame.h"
#include "core/page/Page.h"
#include "platform/plugins/PluginData.h"
#include "wtf/Vector.h"
#include "wtf/text/AtomicString.h"

namespace blink {

DOMPluginArray::DOMPluginArray(LocalFrame* frame)
<<<<<<< HEAD
    : ContextClient(frame)
=======
    : DOMWindowProperty(frame)
>>>>>>> miniblink49
{
}

DEFINE_TRACE(DOMPluginArray)
{
<<<<<<< HEAD
    ContextClient::trace(visitor);
=======
    DOMWindowProperty::trace(visitor);
>>>>>>> miniblink49
}

unsigned DOMPluginArray::length() const
{
    PluginData* data = pluginData();
    if (!data)
        return 0;
    return data->plugins().size();
}

DOMPlugin* DOMPluginArray::item(unsigned index)
{
    PluginData* data = pluginData();
    if (!data)
        return nullptr;
    const Vector<PluginInfo>& plugins = data->plugins();
    if (index >= plugins.size())
        return nullptr;
<<<<<<< HEAD
    return DOMPlugin::create(data, frame(), index);
=======
    return DOMPlugin::create(data, m_frame, index);
>>>>>>> miniblink49
}

DOMPlugin* DOMPluginArray::namedItem(const AtomicString& propertyName)
{
    PluginData* data = pluginData();
    if (!data)
        return nullptr;
    const Vector<PluginInfo>& plugins = data->plugins();
    for (unsigned i = 0; i < plugins.size(); ++i) {
        if (plugins[i].name == propertyName)
<<<<<<< HEAD
            return DOMPlugin::create(data, frame(), i);
=======
            return DOMPlugin::create(data, m_frame, i);
>>>>>>> miniblink49
    }
    return nullptr;
}

void DOMPluginArray::refresh(bool reload)
{
<<<<<<< HEAD
    if (!frame())
        return;
    Page::refreshPlugins();
    if (reload)
        frame()->reload(FrameLoadTypeReload, ClientRedirectPolicy::ClientRedirect);
=======
    if (!m_frame)
        return;
    Page::refreshPlugins();
    if (reload)
        m_frame->reload(FrameLoadTypeReload, ClientRedirect);
>>>>>>> miniblink49
}

PluginData* DOMPluginArray::pluginData() const
{
<<<<<<< HEAD
    if (!frame())
        return nullptr;
    return frame()->pluginData();
=======
    if (!m_frame)
        return nullptr;
    Page* page = m_frame->page();
    if (!page)
        return nullptr;
    return page->pluginData();
>>>>>>> miniblink49
}

} // namespace blink
