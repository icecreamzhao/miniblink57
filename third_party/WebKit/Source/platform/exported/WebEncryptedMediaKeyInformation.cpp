// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "public/platform/WebEncryptedMediaKeyInformation.h"

namespace blink {

<<<<<<< HEAD
WebEncryptedMediaKeyInformation::WebEncryptedMediaKeyInformation() { }

WebEncryptedMediaKeyInformation::~WebEncryptedMediaKeyInformation() { }
=======
WebEncryptedMediaKeyInformation::WebEncryptedMediaKeyInformation()
{
}

WebEncryptedMediaKeyInformation::~WebEncryptedMediaKeyInformation()
{
}
>>>>>>> miniblink49

WebData WebEncryptedMediaKeyInformation::id() const
{
    return m_id;
}

void WebEncryptedMediaKeyInformation::setId(const WebData& id)
{
    m_id.assign(id);
}

<<<<<<< HEAD
WebEncryptedMediaKeyInformation::KeyStatus
WebEncryptedMediaKeyInformation::status() const
=======
WebEncryptedMediaKeyInformation::KeyStatus WebEncryptedMediaKeyInformation::status() const
>>>>>>> miniblink49
{
    return m_status;
}

void WebEncryptedMediaKeyInformation::setStatus(KeyStatus status)
{
    m_status = status;
}

uint32_t WebEncryptedMediaKeyInformation::systemCode() const
{
    return m_systemCode;
}

void WebEncryptedMediaKeyInformation::setSystemCode(uint32_t systemCode)
{
    m_systemCode = systemCode;
}

} // namespace blink
