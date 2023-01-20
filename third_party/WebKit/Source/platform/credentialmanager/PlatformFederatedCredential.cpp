// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/credentialmanager/PlatformFederatedCredential.h"

namespace blink {

<<<<<<< HEAD
PlatformFederatedCredential* PlatformFederatedCredential::create(
    const String& id,
    PassRefPtr<SecurityOrigin> provider,
    const String& name,
    const KURL& iconURL)
{
    return new PlatformFederatedCredential(id, std::move(provider), name,
        iconURL);
}

PlatformFederatedCredential::PlatformFederatedCredential(
    const String& id,
    PassRefPtr<SecurityOrigin> provider,
    const String& name,
    const KURL& iconURL)
=======
PlatformFederatedCredential* PlatformFederatedCredential::create(const String& id, const KURL& provider, const String& name, const KURL& iconURL)
{
    return new PlatformFederatedCredential(id, provider, name, iconURL);
}

PlatformFederatedCredential::PlatformFederatedCredential(const String& id, const KURL& provider, const String& name, const KURL& iconURL)
>>>>>>> miniblink49
    : PlatformCredential(id, name, iconURL)
    , m_provider(provider)
{
    setType("federated");
}

<<<<<<< HEAD
PlatformFederatedCredential::~PlatformFederatedCredential() { }
=======
PlatformFederatedCredential::~PlatformFederatedCredential()
{
}
>>>>>>> miniblink49

} // namespace blink
