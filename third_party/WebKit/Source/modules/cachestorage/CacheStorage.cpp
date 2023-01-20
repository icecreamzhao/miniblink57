// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/cachestorage/CacheStorage.h"

#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "bindings/core/v8/ScriptState.h"
#include "core/dom/DOMException.h"
#include "core/dom/ExceptionCode.h"
<<<<<<< HEAD
#include "core/inspector/ConsoleMessage.h"
#include "modules/cachestorage/CacheStorageError.h"
#include "modules/fetch/Request.h"
#include "modules/fetch/Response.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerCacheError.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerCacheStorage.h"
#include "wtf/PtrUtil.h"
#include <memory>
#include <utility>
=======
#include "modules/cachestorage/CacheStorageError.h"
#include "modules/fetch/Request.h"
#include "modules/fetch/Response.h"
#include "public/platform/WebServiceWorkerCacheError.h"
#include "public/platform/WebServiceWorkerCacheStorage.h"
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    DOMException* createNoImplementationException()
    {
        return DOMException::create(NotSupportedError,
            "No CacheStorage implementation provided.");
    }

    bool commonChecks(ScriptState* scriptState, ExceptionState& exceptionState)
    {
        ExecutionContext* executionContext = scriptState->getExecutionContext();
        // FIXME: May be null due to worker termination: http://crbug.com/413518.
        if (!executionContext)
            return false;

        String errorMessage;
        if (!executionContext->isSecureContext(errorMessage)) {
            exceptionState.throwSecurityError(errorMessage);
            return false;
        }
        return true;
    }

} // namespace

// FIXME: Consider using CallbackPromiseAdapter.
class CacheStorage::Callbacks final
    : public WebServiceWorkerCacheStorage::CacheStorageCallbacks {
    WTF_MAKE_NONCOPYABLE(Callbacks);

public:
    explicit Callbacks(ScriptPromiseResolver* resolver)
        : m_resolver(resolver)
    {
    }
=======
DOMException* createNoImplementationException()
{
    return DOMException::create(NotSupportedError, "No CacheStorage implementation provided.");
}

}

// FIXME: Consider using CallbackPromiseAdapter.
class CacheStorage::Callbacks final : public WebServiceWorkerCacheStorage::CacheStorageCallbacks {
    WTF_MAKE_NONCOPYABLE(Callbacks);
public:
    explicit Callbacks(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
        : m_resolver(resolver) { }
>>>>>>> miniblink49
    ~Callbacks() override { }

    void onSuccess() override
    {
<<<<<<< HEAD
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
=======
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
>>>>>>> miniblink49
            return;
        m_resolver->resolve(true);
        m_resolver.clear();
    }

<<<<<<< HEAD
    void onError(WebServiceWorkerCacheError reason) override
    {
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
            return;
        if (reason == WebServiceWorkerCacheErrorNotFound)
            m_resolver->resolve(false);
        else
            m_resolver->reject(CacheStorageError::createException(reason));
=======
    // Ownership of |rawReason| must be passed.
    void onError(WebServiceWorkerCacheError* rawReason) override
    {
        OwnPtr<WebServiceWorkerCacheError> reason = adoptPtr(rawReason);
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        if (*reason == WebServiceWorkerCacheErrorNotFound)
            m_resolver->resolve(false);
        else
            m_resolver->reject(CacheStorageError::createException(*reason));
>>>>>>> miniblink49
        m_resolver.clear();
    }

private:
<<<<<<< HEAD
    Persistent<ScriptPromiseResolver> m_resolver;
};

// FIXME: Consider using CallbackPromiseAdapter.
class CacheStorage::WithCacheCallbacks final
    : public WebServiceWorkerCacheStorage::CacheStorageWithCacheCallbacks {
    WTF_MAKE_NONCOPYABLE(WithCacheCallbacks);

public:
    WithCacheCallbacks(const String& cacheName,
        CacheStorage* cacheStorage,
        ScriptPromiseResolver* resolver)
        : m_cacheName(cacheName)
        , m_cacheStorage(cacheStorage)
        , m_resolver(resolver)
    {
    }
    ~WithCacheCallbacks() override { }

    void onSuccess(std::unique_ptr<WebServiceWorkerCache> webCache) override
    {
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
            return;
        Cache* cache = Cache::create(m_cacheStorage->m_scopedFetcher,
            WTF::wrapUnique(webCache.release()));
=======
    RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
};

// FIXME: Consider using CallbackPromiseAdapter.
class CacheStorage::WithCacheCallbacks final : public WebServiceWorkerCacheStorage::CacheStorageWithCacheCallbacks {
    WTF_MAKE_NONCOPYABLE(WithCacheCallbacks);
public:
    WithCacheCallbacks(const String& cacheName, CacheStorage* cacheStorage, PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
        : m_cacheName(cacheName), m_cacheStorage(cacheStorage), m_resolver(resolver) { }
    ~WithCacheCallbacks() override { }

    // Ownership of |rawWebCache| must be passed.
    void onSuccess(WebServiceWorkerCache* rawWebCache) override
    {
        OwnPtr<WebServiceWorkerCache> webCache = adoptPtr(rawWebCache);
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        // FIXME: Remove this once content's WebServiceWorkerCache implementation has landed.
        if (!webCache) {
            m_resolver->reject("not implemented");
            return;
        }
        Cache* cache = Cache::create(m_cacheStorage->m_scopedFetcher, webCache.release());
        m_cacheStorage->m_nameToCacheMap.set(m_cacheName, cache);
>>>>>>> miniblink49
        m_resolver->resolve(cache);
        m_resolver.clear();
    }

<<<<<<< HEAD
    void onError(WebServiceWorkerCacheError reason) override
    {
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
            return;
        if (reason == WebServiceWorkerCacheErrorNotFound)
            m_resolver->resolve();
        else
            m_resolver->reject(CacheStorageError::createException(reason));
=======
    // Ownership of |rawReason| must be passed.
    void onError(WebServiceWorkerCacheError* rawReason) override
    {
        OwnPtr<WebServiceWorkerCacheError> reason = adoptPtr(rawReason);
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        if (*reason == WebServiceWorkerCacheErrorNotFound)
            m_resolver->resolve();
        else
            m_resolver->reject(CacheStorageError::createException(*reason));
>>>>>>> miniblink49
        m_resolver.clear();
    }

private:
    String m_cacheName;
    Persistent<CacheStorage> m_cacheStorage;
<<<<<<< HEAD
    Persistent<ScriptPromiseResolver> m_resolver;
};

// FIXME: Consider using CallbackPromiseAdapter.
class CacheStorage::MatchCallbacks
    : public WebServiceWorkerCacheStorage::CacheStorageMatchCallbacks {
    WTF_MAKE_NONCOPYABLE(MatchCallbacks);

public:
    explicit MatchCallbacks(ScriptPromiseResolver* resolver)
        : m_resolver(resolver)
    {
    }

    void onSuccess(const WebServiceWorkerResponse& webResponse) override
    {
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
            return;
        ScriptState::Scope scope(m_resolver->getScriptState());
        m_resolver->resolve(
            Response::create(m_resolver->getScriptState(), webResponse));
        m_resolver.clear();
    }

    void onError(WebServiceWorkerCacheError reason) override
    {
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
            return;
        if (reason == WebServiceWorkerCacheErrorNotFound || reason == WebServiceWorkerCacheErrorCacheNameNotFound)
            m_resolver->resolve();
        else
            m_resolver->reject(CacheStorageError::createException(reason));
=======
    RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
};

// FIXME: Consider using CallbackPromiseAdapter.
class CacheStorage::MatchCallbacks : public WebServiceWorkerCacheStorage::CacheStorageMatchCallbacks {
    WTF_MAKE_NONCOPYABLE(MatchCallbacks);
public:
    MatchCallbacks(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
        : m_resolver(resolver) { }

    void onSuccess(WebServiceWorkerResponse* webResponse) override
    {
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        m_resolver->resolve(Response::create(m_resolver->scriptState()->executionContext(), *webResponse));
        m_resolver.clear();
    }

    // Ownership of |rawReason| must be passed.
    void onError(WebServiceWorkerCacheError* rawReason) override
    {
        OwnPtr<WebServiceWorkerCacheError> reason = adoptPtr(rawReason);
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        if (*reason == WebServiceWorkerCacheErrorNotFound)
            m_resolver->resolve();
        else
            m_resolver->reject(CacheStorageError::createException(*reason));
>>>>>>> miniblink49
        m_resolver.clear();
    }

private:
<<<<<<< HEAD
    Persistent<ScriptPromiseResolver> m_resolver;
};

// FIXME: Consider using CallbackPromiseAdapter.
class CacheStorage::DeleteCallbacks final
    : public WebServiceWorkerCacheStorage::CacheStorageCallbacks {
    WTF_MAKE_NONCOPYABLE(DeleteCallbacks);

public:
    DeleteCallbacks(const String& cacheName,
        CacheStorage* cacheStorage,
        ScriptPromiseResolver* resolver)
        : m_cacheName(cacheName)
        , m_cacheStorage(cacheStorage)
        , m_resolver(resolver)
    {
    }
=======
    RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
};


// FIXME: Consider using CallbackPromiseAdapter.
class CacheStorage::DeleteCallbacks final : public WebServiceWorkerCacheStorage::CacheStorageCallbacks {
    WTF_MAKE_NONCOPYABLE(DeleteCallbacks);
public:
    DeleteCallbacks(const String& cacheName, CacheStorage* cacheStorage, PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
        : m_cacheName(cacheName), m_cacheStorage(cacheStorage), m_resolver(resolver) { }
>>>>>>> miniblink49
    ~DeleteCallbacks() override { }

    void onSuccess() override
    {
<<<<<<< HEAD
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
=======
        m_cacheStorage->m_nameToCacheMap.remove(m_cacheName);
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
>>>>>>> miniblink49
            return;
        m_resolver->resolve(true);
        m_resolver.clear();
    }

<<<<<<< HEAD
    void onError(WebServiceWorkerCacheError reason) override
    {
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
            return;
        if (reason == WebServiceWorkerCacheErrorNotFound)
            m_resolver->resolve(false);
        else
            m_resolver->reject(CacheStorageError::createException(reason));
=======
    // Ownership of |rawReason| must be passed.
    void onError(WebServiceWorkerCacheError* rawReason) override
    {
        OwnPtr<WebServiceWorkerCacheError> reason = adoptPtr(rawReason);
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        if (*reason == WebServiceWorkerCacheErrorNotFound)
            m_resolver->resolve(false);
        else
            m_resolver->reject(CacheStorageError::createException(*reason));
>>>>>>> miniblink49
        m_resolver.clear();
    }

private:
    String m_cacheName;
    Persistent<CacheStorage> m_cacheStorage;
<<<<<<< HEAD
    Persistent<ScriptPromiseResolver> m_resolver;
};

// FIXME: Consider using CallbackPromiseAdapter.
class CacheStorage::KeysCallbacks final
    : public WebServiceWorkerCacheStorage::CacheStorageKeysCallbacks {
    WTF_MAKE_NONCOPYABLE(KeysCallbacks);

public:
    explicit KeysCallbacks(ScriptPromiseResolver* resolver)
        : m_resolver(resolver)
    {
    }
    ~KeysCallbacks() override { }

    void onSuccess(const WebVector<WebString>& keys) override
    {
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
            return;
        Vector<String> wtfKeys;
        for (size_t i = 0; i < keys.size(); ++i)
            wtfKeys.push_back(keys[i]);
=======
    RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
};

// FIXME: Consider using CallbackPromiseAdapter.
class CacheStorage::KeysCallbacks final : public WebServiceWorkerCacheStorage::CacheStorageKeysCallbacks {
    WTF_MAKE_NONCOPYABLE(KeysCallbacks);
public:
    explicit KeysCallbacks(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
        : m_resolver(resolver) { }
    ~KeysCallbacks() override { }

    void onSuccess(WebVector<WebString>* keys) override
    {
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        Vector<String> wtfKeys;
        for (size_t i = 0; i < keys->size(); ++i)
            wtfKeys.append((*keys)[i]);
>>>>>>> miniblink49
        m_resolver->resolve(wtfKeys);
        m_resolver.clear();
    }

<<<<<<< HEAD
    void onError(WebServiceWorkerCacheError reason) override
    {
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
            return;
        m_resolver->reject(CacheStorageError::createException(reason));
=======
    // Ownership of |rawReason| must be passed.
    void onError(WebServiceWorkerCacheError* rawReason) override
    {
        OwnPtr<WebServiceWorkerCacheError> reason = adoptPtr(rawReason);
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        m_resolver->reject(CacheStorageError::createException(*reason));
>>>>>>> miniblink49
        m_resolver.clear();
    }

private:
<<<<<<< HEAD
    Persistent<ScriptPromiseResolver> m_resolver;
};

CacheStorage* CacheStorage::create(
    GlobalFetch::ScopedFetcher* fetcher,
    WebServiceWorkerCacheStorage* webCacheStorage)
{
    return new CacheStorage(fetcher, WTF::wrapUnique(webCacheStorage));
}

ScriptPromise CacheStorage::open(ScriptState* scriptState,
    const String& cacheName,
    ExceptionState& exceptionState)
{
    if (!commonChecks(scriptState, exceptionState))
        return ScriptPromise();

    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    const ScriptPromise promise = resolver->promise();

    if (m_webCacheStorage) {
        m_webCacheStorage->dispatchOpen(
            WTF::makeUnique<WithCacheCallbacks>(cacheName, this, resolver),
            cacheName);
    } else {
        resolver->reject(createNoImplementationException());
    }

    return promise;
}

ScriptPromise CacheStorage::has(ScriptState* scriptState,
    const String& cacheName,
    ExceptionState& exceptionState)
{
    if (!commonChecks(scriptState, exceptionState))
        return ScriptPromise();

    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    const ScriptPromise promise = resolver->promise();

    if (m_webCacheStorage) {
        m_webCacheStorage->dispatchHas(WTF::makeUnique<Callbacks>(resolver),
            cacheName);
    } else {
        resolver->reject(createNoImplementationException());
    }

    return promise;
}

ScriptPromise CacheStorage::deleteFunction(ScriptState* scriptState,
    const String& cacheName,
    ExceptionState& exceptionState)
{
    if (!commonChecks(scriptState, exceptionState))
        return ScriptPromise();

    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    const ScriptPromise promise = resolver->promise();

    if (m_webCacheStorage) {
        m_webCacheStorage->dispatchDelete(
            WTF::makeUnique<DeleteCallbacks>(cacheName, this, resolver), cacheName);
    } else {
        resolver->reject(createNoImplementationException());
    }

    return promise;
}

ScriptPromise CacheStorage::keys(ScriptState* scriptState,
    ExceptionState& exceptionState)
{
    if (!commonChecks(scriptState, exceptionState))
        return ScriptPromise();

    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    const ScriptPromise promise = resolver->promise();

    if (m_webCacheStorage)
        m_webCacheStorage->dispatchKeys(WTF::makeUnique<KeysCallbacks>(resolver));
=======
    RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
};

CacheStorage* CacheStorage::create(WeakPtr<GlobalFetch::ScopedFetcher> fetcher, WebServiceWorkerCacheStorage* webCacheStorage)
{
    return new CacheStorage(fetcher, adoptPtr(webCacheStorage));
}

ScriptPromise CacheStorage::open(ScriptState* scriptState, const String& cacheName)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    const ScriptPromise promise = resolver->promise();

    if (m_nameToCacheMap.contains(cacheName)) {
        Cache* cache = m_nameToCacheMap.find(cacheName)->value;
        resolver->resolve(cache);
        return promise;
    }

    if (m_webCacheStorage)
        m_webCacheStorage->dispatchOpen(new WithCacheCallbacks(cacheName, this, resolver), cacheName);
>>>>>>> miniblink49
    else
        resolver->reject(createNoImplementationException());

    return promise;
}

<<<<<<< HEAD
ScriptPromise CacheStorage::match(ScriptState* scriptState,
    const RequestInfo& request,
    const CacheQueryOptions& options,
    ExceptionState& exceptionState)
{
    ASSERT(!request.isNull());
    if (!commonChecks(scriptState, exceptionState))
        return ScriptPromise();
=======
ScriptPromise CacheStorage::has(ScriptState* scriptState, const String& cacheName)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    const ScriptPromise promise = resolver->promise();

    if (m_nameToCacheMap.contains(cacheName)) {
        resolver->resolve(true);
        return promise;
    }

    if (m_webCacheStorage)
        m_webCacheStorage->dispatchHas(new Callbacks(resolver), cacheName);
    else
        resolver->reject(createNoImplementationException());

    return promise;
}

ScriptPromise CacheStorage::deleteFunction(ScriptState* scriptState, const String& cacheName)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    const ScriptPromise promise = resolver->promise();

    if (m_webCacheStorage)
        m_webCacheStorage->dispatchDelete(new DeleteCallbacks(cacheName, this, resolver), cacheName);
    else
        resolver->reject(createNoImplementationException());

    return promise;
}

ScriptPromise CacheStorage::keys(ScriptState* scriptState)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    const ScriptPromise promise = resolver->promise();

    if (m_webCacheStorage)
        m_webCacheStorage->dispatchKeys(new KeysCallbacks(resolver));
    else
        resolver->reject(createNoImplementationException());

    return promise;
}

ScriptPromise CacheStorage::match(ScriptState* scriptState, const RequestInfo& request, const CacheQueryOptions& options, ExceptionState& exceptionState)
{
    ASSERT(!request.isNull());
>>>>>>> miniblink49

    if (request.isRequest())
        return matchImpl(scriptState, request.getAsRequest(), options);
    Request* newRequest = Request::create(scriptState, request.getAsUSVString(), exceptionState);
    if (exceptionState.hadException())
        return ScriptPromise();
    return matchImpl(scriptState, newRequest, options);
}

<<<<<<< HEAD
ScriptPromise CacheStorage::matchImpl(ScriptState* scriptState,
    const Request* request,
    const CacheQueryOptions& options)
=======
ScriptPromise CacheStorage::matchImpl(ScriptState* scriptState, const Request* request, const CacheQueryOptions& options)
>>>>>>> miniblink49
{
    WebServiceWorkerRequest webRequest;
    request->populateWebServiceWorkerRequest(webRequest);

<<<<<<< HEAD
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    const ScriptPromise promise = resolver->promise();

    if (request->method() != HTTPNames::GET && !options.ignoreMethod()) {
        resolver->resolve();
        return promise;
    }

    if (m_webCacheStorage)
        m_webCacheStorage->dispatchMatch(WTF::makeUnique<MatchCallbacks>(resolver),
            webRequest,
            Cache::toWebQueryParams(options));
=======
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    const ScriptPromise promise = resolver->promise();

    if (m_webCacheStorage)
        m_webCacheStorage->dispatchMatch(new MatchCallbacks(resolver), webRequest, Cache::toWebQueryParams(options));
>>>>>>> miniblink49
    else
        resolver->reject(createNoImplementationException());

    return promise;
}

<<<<<<< HEAD
CacheStorage::CacheStorage(
    GlobalFetch::ScopedFetcher* fetcher,
    std::unique_ptr<WebServiceWorkerCacheStorage> webCacheStorage)
    : m_scopedFetcher(fetcher)
    , m_webCacheStorage(std::move(webCacheStorage))
{
}

CacheStorage::~CacheStorage() { }

void CacheStorage::dispose()
{
    m_webCacheStorage.reset();
=======
CacheStorage::CacheStorage(WeakPtr<GlobalFetch::ScopedFetcher> fetcher, PassOwnPtr<WebServiceWorkerCacheStorage> webCacheStorage)
    : m_scopedFetcher(fetcher)
    , m_webCacheStorage(webCacheStorage)
{
}

CacheStorage::~CacheStorage()
{
}

void CacheStorage::dispose()
{
    m_webCacheStorage.clear();
>>>>>>> miniblink49
}

DEFINE_TRACE(CacheStorage)
{
<<<<<<< HEAD
    visitor->trace(m_scopedFetcher);
=======
    visitor->trace(m_nameToCacheMap);
>>>>>>> miniblink49
}

} // namespace blink
