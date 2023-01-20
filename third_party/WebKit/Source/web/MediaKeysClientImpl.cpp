// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "web/MediaKeysClientImpl.h"

#include "core/dom/Document.h"
#include "core/dom/ExecutionContext.h"
#include "public/platform/WebContentDecryptionModule.h"
#include "public/web/WebFrameClient.h"
#include "web/WebLocalFrameImpl.h"

namespace blink {

<<<<<<< HEAD
MediaKeysClientImpl::MediaKeysClientImpl() { }

WebEncryptedMediaClient* MediaKeysClientImpl::encryptedMediaClient(
    ExecutionContext* executionContext)
=======
MediaKeysClientImpl::MediaKeysClientImpl()
{
}

WebEncryptedMediaClient* MediaKeysClientImpl::encryptedMediaClient(ExecutionContext* executionContext)
>>>>>>> miniblink49
{
    Document* document = toDocument(executionContext);
    WebLocalFrameImpl* webFrame = WebLocalFrameImpl::fromFrame(document->frame());
    return webFrame->client()->encryptedMediaClient();
}

} // namespace blink
