// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef EventModulesFactory_h
#define EventModulesFactory_h

#include "core/events/EventFactory.h"
#include "platform/heap/Handle.h"
#include "wtf/PassRefPtr.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
#include "wtf/text/AtomicString.h"
#include <memory>
=======
#include "wtf/text/AtomicString.h"
>>>>>>> miniblink49

namespace blink {

class Event;

class EventModulesFactory final : public EventFactoryBase {
public:
<<<<<<< HEAD
    static std::unique_ptr<EventModulesFactory> create()
    {
        return WTF::makeUnique<EventModulesFactory>();
    }

    Event* create(ExecutionContext*, const String& eventType) override;
};

} // namespace blink
=======
    static PassOwnPtr<EventModulesFactory> create()
    {
        return adoptPtr(new EventModulesFactory());
    }

    PassRefPtrWillBeRawPtr<Event> create(const String& eventType) override;
};

}
>>>>>>> miniblink49

#endif
