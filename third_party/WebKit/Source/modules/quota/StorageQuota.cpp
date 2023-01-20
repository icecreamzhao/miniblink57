/*
 * Copyright (C) 2014 Google Inc. All rights reserved.
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

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/quota/StorageQuota.h"

#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
<<<<<<< HEAD
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "modules/quota/DOMError.h"
=======
#include "core/dom/DOMError.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
>>>>>>> miniblink49
#include "modules/quota/StorageQuotaCallbacksImpl.h"
#include "modules/quota/StorageQuotaClient.h"
#include "platform/weborigin/KURL.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/Platform.h"
#include "public/platform/WebStorageQuotaCallbacks.h"
#include "public/platform/WebStorageQuotaType.h"

namespace blink {

namespace {

<<<<<<< HEAD
    struct StorageTypeMapping {
        WebStorageQuotaType type;
        const char* const name;
    };

    const StorageTypeMapping storageTypeMappings[] = {
        { WebStorageQuotaTypeTemporary, "temporary" },
        { WebStorageQuotaTypePersistent, "persistent" },
    };

    WebStorageQuotaType stringToStorageQuotaType(const String& type)
    {
        for (size_t i = 0; i < WTF_ARRAY_LENGTH(storageTypeMappings); ++i) {
            if (storageTypeMappings[i].name == type)
                return storageTypeMappings[i].type;
        }
        ASSERT_NOT_REACHED();
        return WebStorageQuotaTypeTemporary;
    }

} // namespace

StorageQuota::StorageQuota() { }
=======
struct StorageTypeMapping {
    WebStorageQuotaType type;
    const char* const name;
};

const StorageTypeMapping storageTypeMappings[] = {
    { WebStorageQuotaTypeTemporary, "temporary" },
    { WebStorageQuotaTypePersistent, "persistent" },
};

WebStorageQuotaType stringToStorageQuotaType(const String& type)
{
    for (size_t i = 0; i < WTF_ARRAY_LENGTH(storageTypeMappings); ++i) {
        if (storageTypeMappings[i].name == type)
            return storageTypeMappings[i].type;
    }
    ASSERT_NOT_REACHED();
    return WebStorageQuotaTypeTemporary;
}

} // namespace

StorageQuota::StorageQuota()
{
}
>>>>>>> miniblink49

Vector<String> StorageQuota::supportedTypes() const
{
    Vector<String> types;
    for (size_t i = 0; i < WTF_ARRAY_LENGTH(storageTypeMappings); ++i)
<<<<<<< HEAD
        types.push_back(storageTypeMappings[i].name);
=======
        types.append(storageTypeMappings[i].name);
>>>>>>> miniblink49
    return types;
}

ScriptPromise StorageQuota::queryInfo(ScriptState* scriptState, String type)
{
<<<<<<< HEAD
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    SecurityOrigin* securityOrigin = scriptState->getExecutionContext()->getSecurityOrigin();
=======
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    SecurityOrigin* securityOrigin = scriptState->executionContext()->securityOrigin();
>>>>>>> miniblink49
    if (securityOrigin->isUnique()) {
        resolver->reject(DOMError::create(NotSupportedError));
        return promise;
    }

    KURL storagePartition = KURL(KURL(), securityOrigin->toString());
    StorageQuotaCallbacks* callbacks = StorageQuotaCallbacksImpl::create(resolver);
<<<<<<< HEAD
    Platform::current()->queryStorageUsageAndQuota(
        storagePartition, stringToStorageQuotaType(type), callbacks);
    return promise;
}

ScriptPromise StorageQuota::requestPersistentQuota(
    ScriptState* scriptState,
    unsigned long long newQuota)
{
    StorageQuotaClient* client = StorageQuotaClient::from(scriptState->getExecutionContext());
    if (!client) {
        ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
=======
    Platform::current()->queryStorageUsageAndQuota(storagePartition, stringToStorageQuotaType(type), callbacks);
    return promise;
}

ScriptPromise StorageQuota::requestPersistentQuota(ScriptState* scriptState, unsigned long long newQuota)
{
    StorageQuotaClient* client = StorageQuotaClient::from(scriptState->executionContext());
    if (!client) {
        RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
>>>>>>> miniblink49
        ScriptPromise promise = resolver->promise();
        resolver->reject(DOMError::create(NotSupportedError));
        return promise;
    }

    return client->requestPersistentQuota(scriptState, newQuota);
}

} // namespace blink
