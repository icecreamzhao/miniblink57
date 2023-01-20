// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/credentialmanager/PlatformPasswordCredential.h"

namespace blink {

<<<<<<< HEAD
PlatformPasswordCredential* PlatformPasswordCredential::create(
    const String& id,
    const String& password,
    const String& name,
    const KURL& iconURL)
=======
PlatformPasswordCredential* PlatformPasswordCredential::create(const String& id, const String& password, const String& name, const KURL& iconURL)
>>>>>>> miniblink49
{
    return new PlatformPasswordCredential(id, password, name, iconURL);
}

<<<<<<< HEAD
PlatformPasswordCredential::PlatformPasswordCredential(const String& id,
    const String& password,
    const String& name,
    const KURL& iconURL)
=======
PlatformPasswordCredential::PlatformPasswordCredential(const String& id, const String& password, const String& name, const KURL& iconURL)
>>>>>>> miniblink49
    : PlatformCredential(id, name, iconURL)
    , m_password(password)
{
    setType("password");
}

<<<<<<< HEAD
PlatformPasswordCredential::~PlatformPasswordCredential() { }

} // namespace blink
=======
PlatformPasswordCredential::~PlatformPasswordCredential()
{
}

} // namespace blink

>>>>>>> miniblink49
