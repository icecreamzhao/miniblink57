/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
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

#ifndef InspectorIndexedDBAgent_h
#define InspectorIndexedDBAgent_h

#include "core/inspector/InspectorBaseAgent.h"
#include "core/inspector/protocol/IndexedDB.h"
#include "modules/ModulesExport.h"
#include "wtf/text/WTFString.h"

#include <v8-inspector.h>

namespace blink {

class InspectedFrames;

class MODULES_EXPORT InspectorIndexedDBAgent final
    : public InspectorBaseAgent<protocol::IndexedDB::Metainfo> {
public:
    InspectorIndexedDBAgent(InspectedFrames*, v8_inspector::V8InspectorSession*);
    ~InspectorIndexedDBAgent() override;
    DECLARE_VIRTUAL_TRACE();

    void restore() override;
    void didCommitLoadForLocalFrame(LocalFrame*) override;

    // Called from the front-end.
    Response enable() override;
    Response disable() override;
    void requestDatabaseNames(
        const String& securityOrigin,
        std::unique_ptr<RequestDatabaseNamesCallback>) override;
    void requestDatabase(const String& securityOrigin,
        const String& databaseName,
        std::unique_ptr<RequestDatabaseCallback>) override;
    void requestData(const String& securityOrigin,
        const String& databaseName,
        const String& objectStoreName,
        const String& indexName,
        int skipCount,
        int pageSize,
        Maybe<protocol::IndexedDB::KeyRange>,
        std::unique_ptr<RequestDataCallback>) override;
    void clearObjectStore(const String& securityOrigin,
        const String& databaseName,
        const String& objectStoreName,
        std::unique_ptr<ClearObjectStoreCallback>) override;

private:
    Member<InspectedFrames> m_inspectedFrames;
    v8_inspector::V8InspectorSession* m_v8Session;
};

} // namespace blink

#endif // !defined(InspectorIndexedDBAgent_h)
