// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PlatformFederatedCredential_h
#define PlatformFederatedCredential_h

#include "platform/credentialmanager/PlatformCredential.h"
#include "platform/heap/Handle.h"
<<<<<<< HEAD
#include "platform/weborigin/SecurityOrigin.h"
=======
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

namespace blink {

<<<<<<< HEAD
class PLATFORM_EXPORT PlatformFederatedCredential final
    : public PlatformCredential {
    WTF_MAKE_NONCOPYABLE(PlatformFederatedCredential);

public:
    static PlatformFederatedCredential* create(
        const String& id,
        PassRefPtr<SecurityOrigin> provider,
        const String& name,
        const KURL& iconURL);
    ~PlatformFederatedCredential() override;

    PassRefPtr<SecurityOrigin> provider() const { return m_provider; }
=======
class PLATFORM_EXPORT PlatformFederatedCredential final : public PlatformCredential {
    WTF_MAKE_NONCOPYABLE(PlatformFederatedCredential);
public:
    static PlatformFederatedCredential* create(const String& id, const KURL& federation, const String& name, const KURL& iconURL);
    ~PlatformFederatedCredential() override;

    const KURL& provider() const { return m_provider; }
>>>>>>> miniblink49

    bool isFederated() override { return true; }

private:
<<<<<<< HEAD
    PlatformFederatedCredential(const String& id,
        PassRefPtr<SecurityOrigin> provider,
        const String& name,
        const KURL& iconURL);

    RefPtr<SecurityOrigin> m_provider;
=======
    PlatformFederatedCredential(const String& id, const KURL& federation, const String& name, const KURL& iconURL);

    KURL m_provider;
>>>>>>> miniblink49
};

} // namespace blink

#endif // PlatformFederatedCredential_h
