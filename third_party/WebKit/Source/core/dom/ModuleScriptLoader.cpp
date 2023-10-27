
/*
* Copyright (C) 2008 Nikolas Zimmermann <zimmermann@kde.org>
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

#include "core/dom/ModuleScriptLoader.h"
#include "core/dom/Document.h"
#include "core/fetch/FetchRequest.h"
#include "core/loader/resource/ScriptResource.h"
#include "bindings/core/v8/Modulator.h"

namespace blink {

ModuleScriptLoader* ModuleScriptLoader::create(Document* document, const KURL& url, FetchRequest::DeferOption defer)
{
    //KURL url = document->completeURL(sourceUrl);

    ScriptState* scriptState = ScriptState::forMainWorld(document->frame());
    if (scriptState && scriptState->modulator()->getModuleRecordByUrl(url))
        return nullptr;

    ModuleScriptLoader* moduleScriptLoader = new ModuleScriptLoader();
    FetchRequest request(ResourceRequest(url), "script");

    request.setCharset(document->characterSet()); // TODO: 这里应该改为父脚本元素的charset
    request.setContentSecurityCheck(DoNotCheckContentSecurityPolicy);
    request.setDefer(defer);

    moduleScriptLoader->setResource(ScriptResource::fetch(request, document->fetcher()));
    return moduleScriptLoader;
}

ModuleScriptLoader::ModuleScriptLoader()
{

}

ModuleScriptLoader::~ModuleScriptLoader()
{

}

void ModuleScriptLoader::notifyFinished(Resource* res)
{
    DCHECK(res == resource());
    if (resource()->errorOccurred())
        return;
    if (m_modulator)
        m_modulator->onModuleScriptLoader();
}

DEFINE_TRACE(ModuleScriptLoader)
{
     visitor->trace(m_modulator);
}

}