// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NavigatorBeacon_h
#define NavigatorBeacon_h

<<<<<<< HEAD
=======
#include "core/frame/LocalFrameLifecycleObserver.h"
>>>>>>> miniblink49
#include "core/frame/Navigator.h"
#include "platform/Supplementable.h"
#include "platform/heap/Handle.h"

namespace blink {

<<<<<<< HEAD
class ScriptState;
class ExceptionState;
class KURL;
class ArrayBufferViewOrBlobOrStringOrFormData;

class NavigatorBeacon final : public GarbageCollectedFinalized<NavigatorBeacon>,
                              public Supplement<Navigator> {
    USING_GARBAGE_COLLECTED_MIXIN(NavigatorBeacon);

=======
class Blob;
class ExceptionState;
class ExecutionContext;
class KURL;
class ArrayBufferViewOrBlobOrStringOrFormData;

class NavigatorBeacon final : public GarbageCollectedFinalized<NavigatorBeacon>, public LocalFrameLifecycleObserver, public HeapSupplement<Navigator> {
    USING_GARBAGE_COLLECTED_MIXIN(NavigatorBeacon);
>>>>>>> miniblink49
public:
    static NavigatorBeacon& from(Navigator&);
    virtual ~NavigatorBeacon();

<<<<<<< HEAD
    static bool sendBeacon(ScriptState*,
        Navigator&,
        const String&,
        const ArrayBufferViewOrBlobOrStringOrFormData&,
        ExceptionState&);
=======
    static bool sendBeacon(ExecutionContext*, Navigator&, const String&, const ArrayBufferViewOrBlobOrStringOrFormData&, ExceptionState&);
>>>>>>> miniblink49

    DECLARE_VIRTUAL_TRACE();

private:
    explicit NavigatorBeacon(Navigator&);

    static const char* supplementName();

<<<<<<< HEAD
    bool sendBeaconImpl(ScriptState*,
        const String&,
        const ArrayBufferViewOrBlobOrStringOrFormData&,
        ExceptionState&);
    bool canSendBeacon(ExecutionContext*, const KURL&, ExceptionState&);
    int maxAllowance() const;
    void addTransmittedBytes(int sentBytes);
=======
    bool canSendBeacon(ExecutionContext*, const KURL&, ExceptionState&);
    int maxAllowance() const;
    bool beaconResult(ExecutionContext*, bool allowed, int sentBytes);
>>>>>>> miniblink49

    int m_transmittedBytes;
};

} // namespace blink

#endif // NavigatorBeacon_h
