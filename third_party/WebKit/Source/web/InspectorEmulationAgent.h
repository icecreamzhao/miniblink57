// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef InspectorEmulationAgent_h
#define InspectorEmulationAgent_h

<<<<<<< HEAD
#include "core/inspector/InspectorBaseAgent.h"
#include "core/inspector/protocol/Emulation.h"
#include "platform/WebTaskRunner.h"

namespace blink {

class WebLocalFrameImpl;
class WebViewImpl;

class InspectorEmulationAgent final
    : public InspectorBaseAgent<protocol::Emulation::Metainfo> {
    WTF_MAKE_NONCOPYABLE(InspectorEmulationAgent);

public:
    class Client {
    public:
        virtual ~Client() { }

        virtual void setCPUThrottlingRate(double rate) { }
    };

    static InspectorEmulationAgent* create(WebLocalFrameImpl*, Client*);
    ~InspectorEmulationAgent() override;

    // protocol::Dispatcher::EmulationCommandHandler implementation.
    Response forceViewport(double x, double y, double scale) override;
    Response resetViewport() override;
    Response resetPageScaleFactor() override;
    Response setPageScaleFactor(double) override;
    Response setScriptExecutionDisabled(bool value) override;
    Response setTouchEmulationEnabled(bool enabled,
        Maybe<String> configuration) override;
    Response setEmulatedMedia(const String&) override;
    Response setCPUThrottlingRate(double) override;
    Response setVirtualTimePolicy(const String& policy,
        Maybe<int> virtualTimeBudgetMs) override;

    // InspectorBaseAgent overrides.
    Response disable() override;
    void restore() override;
=======
#include "core/InspectorFrontend.h"
#include "core/inspector/InspectorBaseAgent.h"

namespace blink {

class WebViewImpl;

using ErrorString = String;

class InspectorEmulationAgent final : public InspectorBaseAgent<InspectorEmulationAgent, InspectorFrontend::Emulation>, public InspectorBackendDispatcher::EmulationCommandHandler {
    WTF_MAKE_NONCOPYABLE(InspectorEmulationAgent);
public:
    static PassOwnPtrWillBeRawPtr<InspectorEmulationAgent> create(WebViewImpl*);
    ~InspectorEmulationAgent() override;

    void viewportChanged();

    // InspectorBackendDispatcher::EmulationCommandHandler implementation.
    void resetScrollAndPageScaleFactor(ErrorString*) override;
    void setPageScaleFactor(ErrorString*, double pageScaleFactor) override;
    void setScriptExecutionDisabled(ErrorString*, bool) override;
    void setTouchEmulationEnabled(ErrorString*, bool enabled, const String* configuration) override;
    void setEmulatedMedia(ErrorString*, const String&) override;

    // InspectorBaseAgent overrides.
    void disable(ErrorString*) override;
    void restore() override;
    void discardAgent() override;
    void didCommitLoadForLocalFrame(LocalFrame*) override;
>>>>>>> miniblink49

    DECLARE_VIRTUAL_TRACE();

private:
<<<<<<< HEAD
    InspectorEmulationAgent(WebLocalFrameImpl*, Client*);
    WebViewImpl* webViewImpl();
    void virtualTimeBudgetExpired();

    Member<WebLocalFrameImpl> m_webLocalFrameImpl;
    Client* m_client;
    TaskHandle m_virtualTimeBudgetExpiredTaskHandle;
};

} // namespace blink

=======
    explicit InspectorEmulationAgent(WebViewImpl*);

    WebViewImpl* m_webViewImpl;
};


} // namespace blink


>>>>>>> miniblink49
#endif // !defined(InspectorEmulationAgent_h)
