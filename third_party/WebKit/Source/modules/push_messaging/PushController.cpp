// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/push_messaging/PushController.h"

#include "public/platform/modules/push_messaging/WebPushClient.h"
#include "wtf/Assertions.h"

namespace blink {

PushController::PushController(LocalFrame& frame, WebPushClient* client)
    : Supplement<LocalFrame>(frame)
    , m_client(client)
{
}

WebPushClient& PushController::clientFrom(LocalFrame* frame)
{
    PushController* controller = PushController::from(frame);
    DCHECK(controller);
    WebPushClient* client = controller->client();
    DCHECK(client);
=======
#include "config.h"
#include "modules/push_messaging/PushController.h"

#include "public/platform/modules/push_messaging/WebPushClient.h"
#include "wtf/PassOwnPtr.h"

namespace blink {

PushController::PushController(WebPushClient* client)
    : m_client(client)
{
}

PassOwnPtrWillBeRawPtr<PushController> PushController::create(WebPushClient* client)
{
    return adoptPtrWillBeNoop(new PushController(client));
}

WebPushClient& PushController::clientFrom(LocalFrame* frame)
{
    PushController* controller = PushController::from(frame);
    ASSERT(controller);
    WebPushClient* client = controller->client();
    ASSERT(client);
>>>>>>> miniblink49
    return *client;
}

const char* PushController::supplementName()
{
    return "PushController";
}

void providePushControllerTo(LocalFrame& frame, WebPushClient* client)
{
<<<<<<< HEAD
    PushController::provideTo(frame, PushController::supplementName(),
        new PushController(frame, client));
=======
    PushController::provideTo(frame, PushController::supplementName(), PushController::create(client));
>>>>>>> miniblink49
}

} // namespace blink
