// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"

>>>>>>> miniblink49
#include "public/platform/WebEncryptedMediaRequest.h"

#include "platform/EncryptedMediaRequest.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/WebMediaKeySystemConfiguration.h"
#include "public/platform/WebSecurityOrigin.h"
#include "public/platform/WebString.h"
#include "public/platform/WebVector.h"

namespace blink {

<<<<<<< HEAD
WebEncryptedMediaRequest::WebEncryptedMediaRequest(
    const WebEncryptedMediaRequest& request)
=======
WebEncryptedMediaRequest::WebEncryptedMediaRequest(const WebEncryptedMediaRequest& request)
>>>>>>> miniblink49
{
    assign(request);
}

<<<<<<< HEAD
WebEncryptedMediaRequest::WebEncryptedMediaRequest(
    EncryptedMediaRequest* request)
=======
WebEncryptedMediaRequest::WebEncryptedMediaRequest(EncryptedMediaRequest* request)
>>>>>>> miniblink49
    : m_private(request)
{
}

WebEncryptedMediaRequest::~WebEncryptedMediaRequest()
{
    reset();
}

WebString WebEncryptedMediaRequest::keySystem() const
{
    return m_private->keySystem();
}

<<<<<<< HEAD
const WebVector<WebMediaKeySystemConfiguration>&
WebEncryptedMediaRequest::supportedConfigurations() const
=======
const WebVector<WebMediaKeySystemConfiguration>& WebEncryptedMediaRequest::supportedConfigurations() const
>>>>>>> miniblink49
{
    return m_private->supportedConfigurations();
}

<<<<<<< HEAD
WebSecurityOrigin WebEncryptedMediaRequest::getSecurityOrigin() const
{
    return WebSecurityOrigin(m_private->getSecurityOrigin());
}

void WebEncryptedMediaRequest::requestSucceeded(
    WebContentDecryptionModuleAccess* access)
=======
WebSecurityOrigin WebEncryptedMediaRequest::securityOrigin() const
{
    return WebSecurityOrigin(m_private->securityOrigin());
}

void WebEncryptedMediaRequest::requestSucceeded(WebContentDecryptionModuleAccess* access)
>>>>>>> miniblink49
{
    m_private->requestSucceeded(access);
}

<<<<<<< HEAD
void WebEncryptedMediaRequest::requestNotSupported(
    const WebString& errorMessage)
=======
void WebEncryptedMediaRequest::requestNotSupported(const WebString& errorMessage)
>>>>>>> miniblink49
{
    m_private->requestNotSupported(errorMessage);
}

void WebEncryptedMediaRequest::assign(const WebEncryptedMediaRequest& other)
{
    m_private = other.m_private;
}

void WebEncryptedMediaRequest::reset()
{
    m_private.reset();
}

} // namespace blink
