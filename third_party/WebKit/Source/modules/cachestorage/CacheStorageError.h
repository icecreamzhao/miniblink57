// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CacheStorageError_h
#define CacheStorageError_h

<<<<<<< HEAD
#include "public/platform/modules/serviceworker/WebServiceWorkerCacheError.h"
#include "wtf/Allocator.h"
#include "wtf/Noncopyable.h"
=======
#include "public/platform/WebServiceWorkerCacheError.h"
#include "wtf/Noncopyable.h"
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49

namespace blink {

class DOMException;
class ScriptPromiseResolver;

class CacheStorageError {
<<<<<<< HEAD
    STATIC_ONLY(CacheStorageError);

=======
    WTF_MAKE_NONCOPYABLE(CacheStorageError);
>>>>>>> miniblink49
public:
    // For CallbackPromiseAdapter. Ownership of a given error is not
    // transferred.
    using WebType = WebServiceWorkerCacheError;
<<<<<<< HEAD
    static DOMException* take(ScriptPromiseResolver*,
        WebServiceWorkerCacheError webError)
    {
        return createException(webError);
    }

    static DOMException* createException(WebServiceWorkerCacheError webError);
=======
    static DOMException* take(ScriptPromiseResolver*, PassOwnPtr<WebType> webError);

    static DOMException* createException(WebType webError);
>>>>>>> miniblink49
};

} // namespace blink

#endif // CacheStorageError_h
