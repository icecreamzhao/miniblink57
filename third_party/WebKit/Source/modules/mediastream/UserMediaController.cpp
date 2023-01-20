/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
<<<<<<< HEAD
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

=======
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
>>>>>>> miniblink49
#include "modules/mediastream/UserMediaController.h"

namespace blink {

const char* UserMediaController::supplementName()
{
    return "UserMediaController";
}

<<<<<<< HEAD
UserMediaController::UserMediaController(
    LocalFrame& frame,
    std::unique_ptr<UserMediaClient> client)
    : Supplement<LocalFrame>(frame)
    , m_client(std::move(client))
{
}

DEFINE_TRACE(UserMediaController)
{
    Supplement<LocalFrame>::trace(visitor);
}

void provideUserMediaTo(LocalFrame& frame,
    std::unique_ptr<UserMediaClient> client)
{
    UserMediaController::provideTo(
        frame, UserMediaController::supplementName(),
        new UserMediaController(frame, std::move(client)));
=======
UserMediaController::UserMediaController(UserMediaClient* client)
    : m_client(client)
{
}

DEFINE_EMPTY_DESTRUCTOR_WILL_BE_REMOVED(UserMediaController)

DEFINE_TRACE(UserMediaController)
{
    WillBeHeapSupplement<LocalFrame>::trace(visitor);
}

PassOwnPtrWillBeRawPtr<UserMediaController> UserMediaController::create(UserMediaClient* client)
{
    return adoptPtrWillBeNoop(new UserMediaController(client));
}

void provideUserMediaTo(LocalFrame& frame, UserMediaClient* client)
{
    UserMediaController::provideTo(frame, UserMediaController::supplementName(), UserMediaController::create(client));
>>>>>>> miniblink49
}

} // namespace blink
