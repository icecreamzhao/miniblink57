// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DeviceOrientationController_h
#define DeviceOrientationController_h

#include "core/dom/Document.h"
#include "core/frame/DeviceSingleWindowEventController.h"
#include "modules/ModulesExport.h"

namespace blink {

class DeviceOrientationData;
<<<<<<< HEAD
class DeviceOrientationDispatcher;
class Event;

class MODULES_EXPORT DeviceOrientationController
    : public DeviceSingleWindowEventController,
      public Supplement<Document> {
    USING_GARBAGE_COLLECTED_MIXIN(DeviceOrientationController);

=======
class Event;

class MODULES_EXPORT DeviceOrientationController final : public DeviceSingleWindowEventController, public WillBeHeapSupplement<Document> {
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(DeviceOrientationController);
>>>>>>> miniblink49
public:
    ~DeviceOrientationController() override;

    static const char* supplementName();
    static DeviceOrientationController& from(Document&);

    // Inherited from DeviceSingleWindowEventController.
    void didUpdateData() override;
<<<<<<< HEAD
    void didAddEventListener(LocalDOMWindow*,
        const AtomicString& eventType) override;
=======
    void didAddEventListener(LocalDOMWindow*, const AtomicString& eventType) override;
>>>>>>> miniblink49

    void setOverride(DeviceOrientationData*);
    void clearOverride();

    DECLARE_VIRTUAL_TRACE();

<<<<<<< HEAD
protected:
    explicit DeviceOrientationController(Document&);

    virtual DeviceOrientationDispatcher& dispatcherInstance() const;

private:
=======
private:
    explicit DeviceOrientationController(Document&);

>>>>>>> miniblink49
    // Inherited from DeviceEventControllerBase.
    void registerWithDispatcher() override;
    void unregisterWithDispatcher() override;
    bool hasLastData() override;

    // Inherited from DeviceSingleWindowEventController.
<<<<<<< HEAD
    Event* lastEvent() const override;
=======
    PassRefPtrWillBeRawPtr<Event> lastEvent() const override;
>>>>>>> miniblink49
    const AtomicString& eventTypeName() const override;
    bool isNullEvent(Event*) const override;

    DeviceOrientationData* lastData() const;

<<<<<<< HEAD
    Member<DeviceOrientationData> m_overrideOrientationData;
=======
    PersistentWillBeMember<DeviceOrientationData> m_overrideOrientationData;
>>>>>>> miniblink49
};

} // namespace blink

#endif // DeviceOrientationController_h
