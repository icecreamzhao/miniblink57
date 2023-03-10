// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_OBJECTS_FEEDBACK_CELL_H_
#define V8_OBJECTS_FEEDBACK_CELL_H_

#include "src/objects/struct.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"

namespace v8 {
namespace internal {

    // This is a special cell used to maintain both the link between a
    // closure and its feedback vector, as well as a way to count the
    // number of closures created for a certain function per native
    // context. There's at most one FeedbackCell for each function in
    // a native context.
    class FeedbackCell : public Struct {
    public:
        static int GetInitialInterruptBudget()
        {
            if (FLAG_lazy_feedback_allocation) {
                return FLAG_budget_for_feedback_vector_allocation;
            }
            return FLAG_interrupt_budget;
        }

        // [value]: value of the cell.
        DECL_ACCESSORS(value, HeapObject)
        DECL_INT32_ACCESSORS(interrupt_budget)

        DECL_CAST(FeedbackCell)

        // Dispatched behavior.
        DECL_PRINTER(FeedbackCell)
        DECL_VERIFIER(FeedbackCell)

// Layout description.
#define FEEDBACK_CELL_FIELDS(V)           \
    V(kValueOffset, kTaggedSize)          \
    /* Non-pointer fields */              \
    V(kInterruptBudgetOffset, kInt32Size) \
    /* Total size. */                     \
    V(kUnalignedSize, 0)

        DEFINE_FIELD_OFFSET_CONSTANTS(HeapObject::kHeaderSize, FEEDBACK_CELL_FIELDS)
#undef FEEDBACK_CELL_FIELDS

        static const int kSize = RoundUp<kObjectAlignment>(int { kUnalignedSize });

        inline void clear_padding();

        using BodyDescriptor = FixedBodyDescriptor<kValueOffset, kInterruptBudgetOffset, kSize>;

        OBJECT_CONSTRUCTORS(FeedbackCell, Struct);
    };

} // namespace internal
} // namespace v8

#include "src/objects/object-macros-undef.h"

#endif // V8_OBJECTS_FEEDBACK_CELL_H_
