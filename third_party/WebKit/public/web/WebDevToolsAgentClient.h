/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebDevToolsAgentClient_h
#define WebDevToolsAgentClient_h

#include "../platform/WebCommon.h"
#include "../platform/WebString.h"

namespace blink {

class WebLocalFrame;
class WebString;

class WebDevToolsAgentClient {
public:
    // Sends response message over the protocol, update agent state on the browser
    // side for potential re-attach. |callId| for notifications is 0, |state| for
    // notifications is empty.
    virtual void sendProtocolMessage(int sessionId,
        int callId,
        const WebString& response,
        const WebString& state) { }

    // Returns process id.
    virtual long processId() { return -1; }

    // Returns unique identifier of the entity within process.
    virtual int debuggerId() { return -1; }

    // Resume the inspected renderer that is waiting for DevTools front-end to
    // initialize its state.
    virtual void resumeStartup() { }

    class WebKitClientMessageLoop {
    public:
        virtual ~WebKitClientMessageLoop() { }
        virtual void run() = 0;
        virtual void quitNow() = 0;
    };
    virtual WebKitClientMessageLoop* createClientMessageLoop() { return 0; }
    virtual void willEnterDebugLoop() { }
    virtual void didExitDebugLoop() { }

    virtual bool requestDevToolsForFrame(WebLocalFrame*) { return false; }

    virtual void enableTracing(const WebString& categoryFilter) { }
    virtual void disableTracing() { }

    virtual void setCPUThrottlingRate(double rate) { }

protected:
    ~WebDevToolsAgentClient() { }
};

} // namespace blink

#endif
