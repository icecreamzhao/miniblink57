// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DeviceMotionController_h
#define DeviceMotionController_h

#include "core/dom/Document.h"
#include "core/frame/DeviceSingleWindowEventController.h"
#include "modules/ModulesExport.h"

namespace blink {

class Event;

<<<<<<< HEAD
class MODULES_EXPORT DeviceMotionController final
    : public DeviceSingleWindowEventController,
      public Supplement<Document> {
    USING_GARBAGE_COLLECTED_MIXIN(DeviceMotionController);

=======
class MODULES_EXPORT DeviceMotionController final : public DeviceSingleWindowEventController, public WillBeHeapSupplement<Document> {
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(DeviceMotionController);
>>>>>>> miniblink49
public:
    ~DeviceMotionController() override;

    static const char* supplementName();
    static DeviceMotionController& from(Document&);

    // DeviceSingleWindowEventController
<<<<<<< HEAD
    void didAddEventListener(LocalDOMWindow*,
        const AtomicString& eventType) override;
=======
    void didAddEventListener(LocalDOMWindow*, const AtomicString& eventType) override;
>>>>>>> miniblink49

    DECLARE_VIRTUAL_TRACE();

private:
    explicit DeviceMotionController(Document&);

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
};

} // namespace blink

#endif // DeviceMotionController_h
