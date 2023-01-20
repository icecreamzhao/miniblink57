/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
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
#include "platform/blob/BlobRegistry.h"

#include "platform/CrossThreadFunctional.h"
#include "platform/WebTaskRunner.h"
#include "platform/blob/BlobData.h"
#include "platform/blob/BlobURL.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "platform/weborigin/URLSecurityOriginMap.h"
=======
#include "config.h"
#include "platform/blob/BlobRegistry.h"

#include "platform/ThreadSafeFunctional.h"
#include "platform/blob/BlobData.h"
#include "platform/blob/BlobURL.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "platform/weborigin/SecurityOriginCache.h"
>>>>>>> miniblink49
#include "public/platform/Platform.h"
#include "public/platform/WebBlobData.h"
#include "public/platform/WebBlobRegistry.h"
#include "public/platform/WebString.h"
#include "public/platform/WebTraceLocation.h"
#include "wtf/Assertions.h"
#include "wtf/HashMap.h"
<<<<<<< HEAD
=======
#include "wtf/MainThread.h"
>>>>>>> miniblink49
#include "wtf/RefPtr.h"
#include "wtf/ThreadSpecific.h"
#include "wtf/Threading.h"
#include "wtf/text/StringHash.h"
#include "wtf/text/WTFString.h"
<<<<<<< HEAD
#include <memory>

namespace blink {

class BlobOriginMap : public URLSecurityOriginMap {
public:
    BlobOriginMap();
    SecurityOrigin* getOrigin(const KURL&) override;
};

static WebBlobRegistry* getBlobRegistry()
{
    return Platform::current()->getBlobRegistry();
=======

namespace blink {

class BlobOriginCache : public SecurityOriginCache {
public:
    BlobOriginCache();
    SecurityOrigin* cachedOrigin(const KURL&) override;
};

static WebBlobRegistry* blobRegistry()
{
    return Platform::current()->blobRegistry();
>>>>>>> miniblink49
}

typedef HashMap<String, RefPtr<SecurityOrigin>> BlobURLOriginMap;
static ThreadSpecific<BlobURLOriginMap>& originMap()
{
<<<<<<< HEAD
    // We want to create the BlobOriginMap exactly once because it is shared by
    // all the threads.
    DEFINE_THREAD_SAFE_STATIC_LOCAL(BlobOriginMap, cache, new BlobOriginMap);
    (void)cache; // BlobOriginMap's constructor does the interesting work.

    DEFINE_THREAD_SAFE_STATIC_LOCAL(ThreadSpecific<BlobURLOriginMap>, map,
        new ThreadSpecific<BlobURLOriginMap>);
=======
    // We want to create the BlobOriginCache exactly once because it is shared by all the threads.
    AtomicallyInitializedStaticReference(BlobOriginCache, cache, new BlobOriginCache);
    (void)cache; // BlobOriginCache's constructor does the interesting work.

    AtomicallyInitializedStaticReference(ThreadSpecific<BlobURLOriginMap>, map, new ThreadSpecific<BlobURLOriginMap>);
>>>>>>> miniblink49
    return map;
}

static void saveToOriginMap(SecurityOrigin* origin, const KURL& url)
{
    // If the blob URL contains null origin, as in the context with unique
    // security origin or file URL, save the mapping between url and origin so
<<<<<<< HEAD
    // that the origin can be retrieved when doing security origin check.
    //
    // See the definition of the origin of a Blob URL in the File API spec.
    if (origin && BlobURL::getOrigin(url) == "null")
        originMap()->add(url.getString(), origin);
=======
    // that the origin can be retrived when doing security origin check.
    if (origin && BlobURL::getOrigin(url) == "null")
        originMap()->add(url.string(), origin);
>>>>>>> miniblink49
}

static void removeFromOriginMap(const KURL& url)
{
    if (BlobURL::getOrigin(url) == "null")
<<<<<<< HEAD
        originMap()->remove(url.getString());
}

void BlobRegistry::registerBlobData(const String& uuid,
    std::unique_ptr<BlobData> data)
{
    getBlobRegistry()->registerBlobData(uuid, WebBlobData(std::move(data)));
=======
        originMap()->remove(url.string());
}

void BlobRegistry::registerBlobData(const String& uuid, PassOwnPtr<BlobData> data)
{
    blobRegistry()->registerBlobData(uuid, WebBlobData(data));
>>>>>>> miniblink49
}

void BlobRegistry::addBlobDataRef(const String& uuid)
{
<<<<<<< HEAD
    getBlobRegistry()->addBlobDataRef(uuid);
=======
    blobRegistry()->addBlobDataRef(uuid);
>>>>>>> miniblink49
}

void BlobRegistry::removeBlobDataRef(const String& uuid)
{
<<<<<<< HEAD
    getBlobRegistry()->removeBlobDataRef(uuid);
}

void BlobRegistry::registerPublicBlobURL(SecurityOrigin* origin,
    const KURL& url,
    PassRefPtr<BlobDataHandle> handle)
{
    saveToOriginMap(origin, url);
    getBlobRegistry()->registerPublicBlobURL(url, handle->uuid());
=======
    blobRegistry()->removeBlobDataRef(uuid);
}

void BlobRegistry::registerPublicBlobURL(SecurityOrigin* origin, const KURL& url, PassRefPtr<BlobDataHandle> handle)
{
    saveToOriginMap(origin, url);
    blobRegistry()->registerPublicBlobURL(url, handle->uuid());
>>>>>>> miniblink49
}

void BlobRegistry::revokePublicBlobURL(const KURL& url)
{
    removeFromOriginMap(url);
<<<<<<< HEAD
    getBlobRegistry()->revokePublicBlobURL(url);
=======
    blobRegistry()->revokePublicBlobURL(url);
>>>>>>> miniblink49
}

static void registerStreamURLTask(const KURL& url, const String& type)
{
<<<<<<< HEAD
    if (WebBlobRegistry* registry = getBlobRegistry())
=======
    if (WebBlobRegistry* registry = blobRegistry())
>>>>>>> miniblink49
        registry->registerStreamURL(url, type);
}

void BlobRegistry::registerStreamURL(const KURL& url, const String& type)
{
    if (isMainThread())
        registerStreamURLTask(url, type);
    else
<<<<<<< HEAD
        Platform::current()->mainThread()->getWebTaskRunner()->postTask(
            BLINK_FROM_HERE, crossThreadBind(&registerStreamURLTask, url, type));
=======
        Platform::current()->mainThread()->postTask(FROM_HERE, threadSafeBind(&registerStreamURLTask, url, type));
>>>>>>> miniblink49
}

static void registerStreamURLFromTask(const KURL& url, const KURL& srcURL)
{
<<<<<<< HEAD
    if (WebBlobRegistry* registry = getBlobRegistry())
        registry->registerStreamURL(url, srcURL);
}

void BlobRegistry::registerStreamURL(SecurityOrigin* origin,
    const KURL& url,
    const KURL& srcURL)
=======
    if (WebBlobRegistry* registry = blobRegistry())
        registry->registerStreamURL(url, srcURL);
}

void BlobRegistry::registerStreamURL(SecurityOrigin* origin, const KURL& url, const KURL& srcURL)
>>>>>>> miniblink49
{
    saveToOriginMap(origin, url);

    if (isMainThread())
        registerStreamURLFromTask(url, srcURL);
    else
<<<<<<< HEAD
        Platform::current()->mainThread()->getWebTaskRunner()->postTask(
            BLINK_FROM_HERE,
            crossThreadBind(&registerStreamURLFromTask, url, srcURL));
}

static void addDataToStreamTask(const KURL& url,
    PassRefPtr<RawData> streamData)
{
    if (WebBlobRegistry* registry = getBlobRegistry())
        registry->addDataToStream(url, streamData->data(), streamData->length());
}

void BlobRegistry::addDataToStream(const KURL& url,
    PassRefPtr<RawData> streamData)
{
    if (isMainThread())
        addDataToStreamTask(url, std::move(streamData));
    else
        Platform::current()->mainThread()->getWebTaskRunner()->postTask(
            BLINK_FROM_HERE,
            crossThreadBind(&addDataToStreamTask, url, std::move(streamData)));
=======
        Platform::current()->mainThread()->postTask(FROM_HERE, threadSafeBind(&registerStreamURLFromTask, url, srcURL));
}

static void addDataToStreamTask(const KURL& url, PassRefPtr<RawData> streamData)
{
    if (WebBlobRegistry* registry = blobRegistry())
        registry->addDataToStream(url, streamData->data(), streamData->length());
}

void BlobRegistry::addDataToStream(const KURL& url, PassRefPtr<RawData> streamData)
{
    if (isMainThread())
        addDataToStreamTask(url, streamData);
    else
        Platform::current()->mainThread()->postTask(FROM_HERE, threadSafeBind(&addDataToStreamTask, url, streamData));
>>>>>>> miniblink49
}

static void flushStreamTask(const KURL& url)
{
<<<<<<< HEAD
    if (WebBlobRegistry* registry = getBlobRegistry())
=======
    if (WebBlobRegistry* registry = blobRegistry())
>>>>>>> miniblink49
        registry->flushStream(url);
}

void BlobRegistry::flushStream(const KURL& url)
{
    if (isMainThread())
        flushStreamTask(url);
    else
<<<<<<< HEAD
        Platform::current()->mainThread()->getWebTaskRunner()->postTask(
            BLINK_FROM_HERE, crossThreadBind(&flushStreamTask, url));
=======
        Platform::current()->mainThread()->postTask(FROM_HERE, threadSafeBind(&flushStreamTask, url));
>>>>>>> miniblink49
}

static void finalizeStreamTask(const KURL& url)
{
<<<<<<< HEAD
    if (WebBlobRegistry* registry = getBlobRegistry())
=======
    if (WebBlobRegistry* registry = blobRegistry())
>>>>>>> miniblink49
        registry->finalizeStream(url);
}

void BlobRegistry::finalizeStream(const KURL& url)
{
    if (isMainThread())
        finalizeStreamTask(url);
    else
<<<<<<< HEAD
        Platform::current()->mainThread()->getWebTaskRunner()->postTask(
            BLINK_FROM_HERE, crossThreadBind(&finalizeStreamTask, url));
=======
        Platform::current()->mainThread()->postTask(FROM_HERE, threadSafeBind(&finalizeStreamTask, url));
>>>>>>> miniblink49
}

static void abortStreamTask(const KURL& url)
{
<<<<<<< HEAD
    if (WebBlobRegistry* registry = getBlobRegistry())
=======
    if (WebBlobRegistry* registry = blobRegistry())
>>>>>>> miniblink49
        registry->abortStream(url);
}

void BlobRegistry::abortStream(const KURL& url)
{
    if (isMainThread())
        abortStreamTask(url);
    else
<<<<<<< HEAD
        Platform::current()->mainThread()->getWebTaskRunner()->postTask(
            BLINK_FROM_HERE, crossThreadBind(&abortStreamTask, url));
=======
        Platform::current()->mainThread()->postTask(FROM_HERE, threadSafeBind(&abortStreamTask, url));
>>>>>>> miniblink49
}

static void unregisterStreamURLTask(const KURL& url)
{
<<<<<<< HEAD
    if (WebBlobRegistry* registry = getBlobRegistry())
=======
    if (WebBlobRegistry* registry = blobRegistry())
>>>>>>> miniblink49
        registry->unregisterStreamURL(url);
}

void BlobRegistry::unregisterStreamURL(const KURL& url)
{
    removeFromOriginMap(url);

    if (isMainThread())
        unregisterStreamURLTask(url);
    else
<<<<<<< HEAD
        Platform::current()->mainThread()->getWebTaskRunner()->postTask(
            BLINK_FROM_HERE, crossThreadBind(&unregisterStreamURLTask, url));
}

BlobOriginMap::BlobOriginMap()
{
    SecurityOrigin::setMap(this);
}

SecurityOrigin* BlobOriginMap::getOrigin(const KURL& url)
{
    if (url.protocolIs("blob"))
        return originMap()->get(url.getString());
=======
        Platform::current()->mainThread()->postTask(FROM_HERE, threadSafeBind(&unregisterStreamURLTask, url));
}

BlobOriginCache::BlobOriginCache()
{
    SecurityOrigin::setCache(this);
}

SecurityOrigin* BlobOriginCache::cachedOrigin(const KURL& url)
{
    if (url.protocolIs("blob"))
        return originMap()->get(url.string());
>>>>>>> miniblink49
    return 0;
}

} // namespace blink
