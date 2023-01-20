// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef StorageNamespaceController_h
#define StorageNamespaceController_h

#include "core/page/Page.h"
#include "modules/ModulesExport.h"
#include "platform/Supplementable.h"
<<<<<<< HEAD
#include <memory>
=======
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49

namespace blink {

class InspectorDOMStorageAgent;
class StorageClient;
class StorageNamespace;

<<<<<<< HEAD
class MODULES_EXPORT StorageNamespaceController final
    : public GarbageCollectedFinalized<StorageNamespaceController>,
      public Supplement<Page> {
    USING_GARBAGE_COLLECTED_MIXIN(StorageNamespaceController);

public:
    StorageNamespace* sessionStorage(bool optionalCreate = true);
#ifndef MINIBLINK_NO_PAGE_LOCALSTORAGE
    StorageNamespace* localStorage();
#endif

    StorageClient* getStorageClient();
    ~StorageNamespaceController();

    static void provideStorageNamespaceTo(Page&, StorageClient*);
    static StorageNamespaceController* from(Page* page)
    {
        return static_cast<StorageNamespaceController*>(
            Supplement<Page>::from(page, supplementName()));
    }
=======
class MODULES_EXPORT StorageNamespaceController final : public NoBaseWillBeGarbageCollectedFinalized<StorageNamespaceController>, public WillBeHeapSupplement<Page> {
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(StorageNamespaceController);
public:
    StorageNamespace* sessionStorage(bool optionalCreate = true);
    StorageClient* storageClient() { return m_client; }
    ~StorageNamespaceController();

    static void provideStorageNamespaceTo(Page&, StorageClient*);
    static StorageNamespaceController* from(Page* page) { return static_cast<StorageNamespaceController*>(WillBeHeapSupplement<Page>::from(page, supplementName())); }
>>>>>>> miniblink49

    DECLARE_TRACE();

    InspectorDOMStorageAgent* inspectorAgent() { return m_inspectorAgent; }
<<<<<<< HEAD
    void setInspectorAgent(InspectorDOMStorageAgent* agent)
    {
        m_inspectorAgent = agent;
    }

private:
    explicit StorageNamespaceController(StorageClient*);
    static const char* supplementName();
    std::unique_ptr<StorageNamespace> m_sessionStorage;
#ifndef MINIBLINK_NO_PAGE_LOCALSTORAGE
    std::unique_ptr<StorageNamespace> m_localStorage;
#endif
    StorageClient* m_client;
    Member<InspectorDOMStorageAgent> m_inspectorAgent;
=======
    void setInspectorAgent(InspectorDOMStorageAgent* agent) { m_inspectorAgent = agent; }
private:
    explicit StorageNamespaceController(StorageClient*);
    static const char* supplementName();
    OwnPtr<StorageNamespace> m_sessionStorage;
    StorageClient* m_client;
    RawPtrWillBeMember<InspectorDOMStorageAgent> m_inspectorAgent;
>>>>>>> miniblink49
};

} // namespace blink

#endif // StorageNamespaceController_h
