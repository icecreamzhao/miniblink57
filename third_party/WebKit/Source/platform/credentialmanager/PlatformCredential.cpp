// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/credentialmanager/PlatformCredential.h"

namespace blink {

<<<<<<< HEAD
PlatformCredential* PlatformCredential::create(const String& id,
    const String& name,
    const KURL& iconURL)
=======
PlatformCredential* PlatformCredential::create(const String& id, const String& name, const KURL& iconURL)
>>>>>>> miniblink49
{
    return new PlatformCredential(id, name, iconURL);
}

<<<<<<< HEAD
PlatformCredential::PlatformCredential(const String& id,
    const String& name,
    const KURL& iconURL)
=======
PlatformCredential::PlatformCredential(const String& id, const String& name, const KURL& iconURL)
>>>>>>> miniblink49
    : m_id(id)
    , m_name(name)
    , m_iconURL(iconURL)
    , m_type("credential")
{
}

<<<<<<< HEAD
PlatformCredential::~PlatformCredential() { }
=======
PlatformCredential::~PlatformCredential()
{
}
>>>>>>> miniblink49

} // namespace blink
