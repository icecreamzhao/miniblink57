// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "public/platform/WebContentDecryptionModuleResult.h"

#include "platform/ContentDecryptionModuleResult.h"

namespace blink {

void WebContentDecryptionModuleResult::complete()
{
    m_impl->complete();
    reset();
}

<<<<<<< HEAD
void WebContentDecryptionModuleResult::completeWithContentDecryptionModule(
    WebContentDecryptionModule* cdm)
=======
void WebContentDecryptionModuleResult::completeWithContentDecryptionModule(WebContentDecryptionModule* cdm)
>>>>>>> miniblink49
{
    m_impl->completeWithContentDecryptionModule(cdm);
    reset();
}

<<<<<<< HEAD
void WebContentDecryptionModuleResult::completeWithSession(
    SessionStatus status)
=======
void WebContentDecryptionModuleResult::completeWithSession(SessionStatus status)
>>>>>>> miniblink49
{
    m_impl->completeWithSession(status);
    reset();
}

<<<<<<< HEAD
void WebContentDecryptionModuleResult::completeWithError(
    WebContentDecryptionModuleException exception,
    unsigned long systemCode,
    const WebString& errorMessage)
=======
void WebContentDecryptionModuleResult::completeWithError(WebContentDecryptionModuleException exception, unsigned long systemCode, const WebString& errorMessage)
>>>>>>> miniblink49
{
    m_impl->completeWithError(exception, systemCode, errorMessage);
    reset();
}

<<<<<<< HEAD
WebContentDecryptionModuleResult::WebContentDecryptionModuleResult(
    ContentDecryptionModuleResult* impl)
=======
WebContentDecryptionModuleResult::WebContentDecryptionModuleResult(ContentDecryptionModuleResult* impl)
>>>>>>> miniblink49
    : m_impl(impl)
{
    ASSERT(m_impl.get());
}

void WebContentDecryptionModuleResult::reset()
{
    m_impl.reset();
}

<<<<<<< HEAD
void WebContentDecryptionModuleResult::assign(
    const WebContentDecryptionModuleResult& o)
=======
void WebContentDecryptionModuleResult::assign(const WebContentDecryptionModuleResult& o)
>>>>>>> miniblink49
{
    m_impl = o.m_impl;
}

} // namespace blink
