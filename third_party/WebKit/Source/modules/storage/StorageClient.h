// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef StorageClient_h
#define StorageClient_h

#include "modules/storage/StorageArea.h"
<<<<<<< HEAD
#include <memory>
=======
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49

namespace blink {

class StorageNamespace;

class StorageClient {
public:
    virtual ~StorageClient() { }

<<<<<<< HEAD
    virtual std::unique_ptr<StorageNamespace> createSessionStorageNamespace() = 0;
#ifndef MINIBLINK_NO_PAGE_LOCALSTORAGE
    virtual std::unique_ptr<StorageNamespace> createLocalStorageNamespace() = 0;
#endif
=======
    virtual PassOwnPtr<StorageNamespace> createSessionStorageNamespace() = 0;

>>>>>>> miniblink49
    virtual bool canAccessStorage(LocalFrame*, StorageType) const = 0;
};

} // namespace blink

#endif // StorageClient_h
