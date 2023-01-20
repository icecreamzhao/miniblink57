// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DeviceOrientationInspectorAgent_h
#define DeviceOrientationInspectorAgent_h

<<<<<<< HEAD
#include "core/inspector/InspectorBaseAgent.h"
#include "core/inspector/protocol/DeviceOrientation.h"
=======
#include "core/InspectorFrontend.h"
#include "core/inspector/InspectorBaseAgent.h"
>>>>>>> miniblink49
#include "modules/ModulesExport.h"
#include "wtf/text/WTFString.h"

namespace blink {

class DeviceOrientationController;
class Page;

<<<<<<< HEAD
class MODULES_EXPORT DeviceOrientationInspectorAgent final
    : public InspectorBaseAgent<protocol::DeviceOrientation::Metainfo> {
    WTF_MAKE_NONCOPYABLE(DeviceOrientationInspectorAgent);

public:
    static DeviceOrientationInspectorAgent* create(Page*);

    ~DeviceOrientationInspectorAgent() override;
    DECLARE_VIRTUAL_TRACE();

    // Protocol methods.
    Response setDeviceOrientationOverride(double, double, double) override;
    Response clearDeviceOrientationOverride() override;

    // Inspector Controller API.
    Response disable() override;
=======
typedef String ErrorString;

class MODULES_EXPORT DeviceOrientationInspectorAgent final : public InspectorBaseAgent<DeviceOrientationInspectorAgent, InspectorFrontend::DeviceOrientation>, public InspectorBackendDispatcher::DeviceOrientationCommandHandler {
    WTF_MAKE_NONCOPYABLE(DeviceOrientationInspectorAgent);
public:
    static PassOwnPtrWillBeRawPtr<DeviceOrientationInspectorAgent> create(Page*);

    ~DeviceOrientationInspectorAgent() override;

    // Protocol methods.
    void setDeviceOrientationOverride(ErrorString*, double, double, double) override;
    void clearDeviceOrientationOverride(ErrorString*) override;

    // Inspector Controller API.
    void disable(ErrorString*) override;
>>>>>>> miniblink49
    void restore() override;
    void didCommitLoadForLocalFrame(LocalFrame*) override;

private:
    explicit DeviceOrientationInspectorAgent(Page&);
    DeviceOrientationController& controller();
<<<<<<< HEAD
    Member<Page> m_page;
=======
    Page& m_page;
>>>>>>> miniblink49
};

} // namespace blink

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#endif // !defined(DeviceOrientationInspectorAgent_h)
