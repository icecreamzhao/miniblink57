// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef InspectorCacheStorageAgent_h
#define InspectorCacheStorageAgent_h

<<<<<<< HEAD
#include "core/inspector/InspectorBaseAgent.h"
#include "core/inspector/protocol/CacheStorage.h"
#include "modules/ModulesExport.h"
=======
#include "core/InspectorFrontend.h"
#include "core/inspector/InspectorBaseAgent.h"
#include "modules/ModulesExport.h"
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

namespace blink {

<<<<<<< HEAD
class MODULES_EXPORT InspectorCacheStorageAgent final
    : public InspectorBaseAgent<protocol::CacheStorage::Metainfo> {
    WTF_MAKE_NONCOPYABLE(InspectorCacheStorageAgent);

public:
    static InspectorCacheStorageAgent* create()
    {
        return new InspectorCacheStorageAgent();
=======
typedef String ErrorString;

class MODULES_EXPORT InspectorCacheStorageAgent final : public InspectorBaseAgent<InspectorCacheStorageAgent, InspectorFrontend::CacheStorage>, public InspectorBackendDispatcher::CacheStorageCommandHandler {
    WTF_MAKE_NONCOPYABLE(InspectorCacheStorageAgent);

public:
    static PassOwnPtrWillBeRawPtr<InspectorCacheStorageAgent> create()
    {
        return adoptPtrWillBeNoop(new InspectorCacheStorageAgent());
>>>>>>> miniblink49
    }

    ~InspectorCacheStorageAgent() override;

    DECLARE_VIRTUAL_TRACE();

<<<<<<< HEAD
    void requestCacheNames(const String& securityOrigin,
        std::unique_ptr<RequestCacheNamesCallback>) override;
    void requestEntries(const String& cacheId,
        int skipCount,
        int pageSize,
        std::unique_ptr<RequestEntriesCallback>) override;
    void deleteCache(const String& cacheId,
        std::unique_ptr<DeleteCacheCallback>) override;
    void deleteEntry(const String& cacheId,
        const String& request,
        std::unique_ptr<DeleteEntryCallback>) override;
=======
    void requestCacheNames(ErrorString*, const String& securityOrigin, PassRefPtrWillBeRawPtr<RequestCacheNamesCallback>) override;
    void requestEntries(ErrorString*, const String& cacheId, int skipCount, int pageSize, PassRefPtrWillBeRawPtr<RequestEntriesCallback>) override;
    void deleteCache(ErrorString*, const String& cacheId, PassRefPtrWillBeRawPtr<DeleteCacheCallback>) override;
    void deleteEntry(ErrorString*, const String& cacheId, const String& request, PassRefPtrWillBeRawPtr<DeleteEntryCallback>) override;
>>>>>>> miniblink49

private:
    explicit InspectorCacheStorageAgent();
};

} // namespace blink

#endif // InspectorCacheStorageAgent_h
