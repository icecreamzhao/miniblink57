// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/encryptedmedia/MediaKeysController.h"

#include "modules/encryptedmedia/MediaKeysClient.h"
#include "public/platform/WebContentDecryptionModule.h"

namespace blink {

const char* MediaKeysController::supplementName()
{
    return "MediaKeysController";
}

MediaKeysController::MediaKeysController(MediaKeysClient* client)
    : m_client(client)
{
}

<<<<<<< HEAD
WebEncryptedMediaClient* MediaKeysController::encryptedMediaClient(
    ExecutionContext* context)
=======
WebEncryptedMediaClient* MediaKeysController::encryptedMediaClient(ExecutionContext* context)
>>>>>>> miniblink49
{
    return m_client->encryptedMediaClient(context);
}

<<<<<<< HEAD
void MediaKeysController::provideMediaKeysTo(Page& page,
    MediaKeysClient* client)
{
    MediaKeysController::provideTo(page, supplementName(),
        new MediaKeysController(client));
}

} // namespace blink
=======
void MediaKeysController::provideMediaKeysTo(Page& page, MediaKeysClient* client)
{
    MediaKeysController::provideTo(page, supplementName(), adoptPtrWillBeNoop(new MediaKeysController(client)));
}

} // namespace blink

>>>>>>> miniblink49
