// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_OBJECTS_MICROTASK_H_
#define V8_OBJECTS_MICROTASK_H_

#include "src/objects.h"
#include "src/objects/struct.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"

namespace v8 {
namespace internal {

    // Abstract base class for all microtasks that can be scheduled on the
    // microtask queue. This class merely serves the purpose of a marker
    // interface.
    class Microtask : public Struct {
    public:
        // Dispatched behavior.
        DECL_CAST(Microtask)
        DECL_VERIFIER(Microtask)

        OBJECT_CONSTRUCTORS(Microtask, Struct);
    };

    // A CallbackTask is a special Microtask that allows us to schedule
    // C++ microtask callbacks on the microtask queue. This is heavily
    // used by Blink for example.
    class CallbackTask : public Microtask {
    public:
        DECL_ACCESSORS(callback, Foreign)
        DECL_ACCESSORS(data, Foreign)

        DEFINE_FIELD_OFFSET_CONSTANTS(Microtask::kHeaderSize,
            TORQUE_GENERATED_CALLBACK_TASK_FIELDS)

        // Dispatched behavior.
        DECL_CAST(CallbackTask)
        DECL_PRINTER(CallbackTask)
        DECL_VERIFIER(CallbackTask)

        OBJECT_CONSTRUCTORS(CallbackTask, Microtask);
    };

    // A CallableTask is a special (internal) Microtask that allows us to
    // schedule arbitrary callables on the microtask queue. We use this
    // for various tests of the microtask queue.
    class CallableTask : public Microtask {
    public:
        DECL_ACCESSORS(callable, JSReceiver)
        DECL_ACCESSORS(context, Context)

        DEFINE_FIELD_OFFSET_CONSTANTS(Microtask::kHeaderSize,
            TORQUE_GENERATED_CALLABLE_TASK_FIELDS)

        // Dispatched behavior.
        DECL_CAST(CallableTask)
        DECL_PRINTER(CallableTask)
        DECL_VERIFIER(CallableTask)
        void BriefPrintDetails(std::ostream& os);

        OBJECT_CONSTRUCTORS(CallableTask, Microtask);
    };

} // namespace internal
} // namespace v8

#include "src/objects/object-macros-undef.h"

#endif // V8_OBJECTS_MICROTASK_H_
