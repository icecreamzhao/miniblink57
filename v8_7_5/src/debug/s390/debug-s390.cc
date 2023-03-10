// Copyright 2015 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/v8.h"

#if V8_TARGET_ARCH_S390

#include "src/debug/debug.h"

#include "src/debug/liveedit.h"
#include "src/frames-inl.h"
#include "src/macro-assembler.h"

namespace v8 {
namespace internal {

#define __ ACCESS_MASM(masm)

    void DebugCodegen::GenerateHandleDebuggerStatement(MacroAssembler* masm)
    {
        {
            FrameScope scope(masm, StackFrame::INTERNAL);
            __ CallRuntime(Runtime::kHandleDebuggerStatement, 0);
        }
        __ MaybeDropFrames();

        // Return to caller.
        __ Ret();
    }

    void DebugCodegen::GenerateFrameDropperTrampoline(MacroAssembler* masm)
    {
        // Frame is being dropped:
        // - Drop to the target frame specified by r3.
        // - Look up current function on the frame.
        // - Leave the frame.
        // - Restart the frame by calling the function.

        __ LoadRR(fp, r3);
        __ LoadP(r3, MemOperand(fp, JavaScriptFrameConstants::kFunctionOffset));
        __ LeaveFrame(StackFrame::INTERNAL);
        __ LoadP(r2, FieldMemOperand(r3, JSFunction::kSharedFunctionInfoOffset));
        __ LoadLogicalHalfWordP(
            r2, FieldMemOperand(r2, SharedFunctionInfo::kFormalParameterCountOffset));
        __ LoadRR(r4, r2);

        ParameterCount dummy1(r4);
        ParameterCount dummy2(r2);
        __ InvokeFunction(r3, dummy1, dummy2, JUMP_FUNCTION);
    }

    const bool LiveEdit::kFrameDropperSupported = true;

#undef __
} // namespace internal
} // namespace v8

#endif // V8_TARGET_ARCH_S390
