// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/cachestorage/CacheStorageError.h"

#include "core/dom/DOMException.h"
#include "core/dom/ExceptionCode.h"
#include "modules/cachestorage/Cache.h"
<<<<<<< HEAD
#include "public/platform/modules/serviceworker/WebServiceWorkerCacheError.h"

namespace blink {

DOMException* CacheStorageError::createException(
    WebServiceWorkerCacheError webError)
{
    switch (webError) {
    case WebServiceWorkerCacheErrorNotImplemented:
        return DOMException::create(NotSupportedError,
            "Method is not implemented.");
=======
#include "public/platform/WebServiceWorkerCacheError.h"

namespace blink {

DOMException* CacheStorageError::take(ScriptPromiseResolver*, PassOwnPtr<WebType> webError)
{
    return CacheStorageError::createException(*webError);
}

DOMException* CacheStorageError::createException(WebType webError)
{
    switch (webError) {
    case WebServiceWorkerCacheErrorNotImplemented:
        return DOMException::create(NotSupportedError, "Method is not implemented.");
>>>>>>> miniblink49
    case WebServiceWorkerCacheErrorNotFound:
        return DOMException::create(NotFoundError, "Entry was not found.");
    case WebServiceWorkerCacheErrorExists:
        return DOMException::create(InvalidAccessError, "Entry already exists.");
<<<<<<< HEAD
    case WebServiceWorkerCacheErrorQuotaExceeded:
        return DOMException::create(QuotaExceededError, "Quota exceeded.");
    case WebServiceWorkerCacheErrorCacheNameNotFound:
        return DOMException::create(NotFoundError, "Cache was not found.");
    case WebServiceWorkerCacheErrorTooLarge:
        return DOMException::create(AbortError, "Operation too large.");
    }
    NOTREACHED();
    return nullptr;
=======
    default:
        ASSERT_NOT_REACHED();
        return DOMException::create(NotSupportedError, "Unknown error.");
    }
>>>>>>> miniblink49
}

} // namespace blink
