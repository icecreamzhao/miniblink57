// Copyright 2013 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/api.h"
#include "src/arm64/assembler-arm64-inl.h"
#include "src/arm64/macro-assembler-arm64-inl.h"
#include "src/deoptimizer.h"
#include "src/frame-constants.h"
#include "src/register-configuration.h"
#include "src/safepoint-table.h"

namespace v8 {
namespace internal {

#define __ masm->

    namespace {

        void CopyRegListToFrame(MacroAssembler* masm, const Register& dst,
            int dst_offset, const CPURegList& reg_list,
            const Register& temp0, const Register& temp1,
            int src_offset = 0)
        {
            DCHECK_EQ(reg_list.Count() % 2, 0);
            UseScratchRegisterScope temps(masm);
            CPURegList copy_to_input = reg_list;
            int reg_size = reg_list.RegisterSizeInBytes();
            DCHECK_EQ(temp0.SizeInBytes(), reg_size);
            DCHECK_EQ(temp1.SizeInBytes(), reg_size);

            // Compute some temporary addresses to avoid having the macro assembler set
            // up a temp with an offset for accesses out of the range of the addressing
            // mode.
            Register src = temps.AcquireX();
            masm->Add(src, sp, src_offset);
            masm->Add(dst, dst, dst_offset);

            // Write reg_list into the frame pointed to by dst.
            for (int i = 0; i < reg_list.Count(); i += 2) {
                masm->Ldp(temp0, temp1, MemOperand(src, i * reg_size));

                CPURegister reg0 = copy_to_input.PopLowestIndex();
                CPURegister reg1 = copy_to_input.PopLowestIndex();
                int offset0 = reg0.code() * reg_size;
                int offset1 = reg1.code() * reg_size;

                // Pair up adjacent stores, otherwise write them separately.
                if (offset1 == offset0 + reg_size) {
                    masm->Stp(temp0, temp1, MemOperand(dst, offset0));
                } else {
                    masm->Str(temp0, MemOperand(dst, offset0));
                    masm->Str(temp1, MemOperand(dst, offset1));
                }
            }
            masm->Sub(dst, dst, dst_offset);
        }

        // TODO(jgruber): There's a hack here to explicitly skip restoration of the
        // so-called 'arm64 platform register' x18. The register may be in use by the
        // OS, thus we should not clobber it. Instead of this hack, it would be nicer
        // not to add x18 to the list of saved registers in the first place. The
        // complication here is that we require `reg_list.Count() % 2 == 0` in multiple
        // spots.
        void RestoreRegList(MacroAssembler* masm, const CPURegList& reg_list,
            const Register& src_base, int src_offset)
        {
            DCHECK_EQ(reg_list.Count() % 2, 0);
            UseScratchRegisterScope temps(masm);
            CPURegList restore_list = reg_list;
            int reg_size = restore_list.RegisterSizeInBytes();

            // Compute a temporary addresses to avoid having the macro assembler set
            // up a temp with an offset for accesses out of the range of the addressing
            // mode.
            Register src = temps.AcquireX();
            masm->Add(src, src_base, src_offset);

            // x18 is the platform register and is reserved for the use of platform ABIs.
            restore_list.Remove(x18);

            // Restore every register in restore_list from src.
            while (!restore_list.IsEmpty()) {
                CPURegister reg0 = restore_list.PopLowestIndex();
                CPURegister reg1 = restore_list.PopLowestIndex();
                int offset0 = reg0.code() * reg_size;

                if (reg1 == NoCPUReg) {
                    masm->Ldr(reg0, MemOperand(src, offset0));
                    break;
                }

                int offset1 = reg1.code() * reg_size;

                // Pair up adjacent loads, otherwise read them separately.
                if (offset1 == offset0 + reg_size) {
                    masm->Ldp(reg0, reg1, MemOperand(src, offset0));
                } else {
                    masm->Ldr(reg0, MemOperand(src, offset0));
                    masm->Ldr(reg1, MemOperand(src, offset1));
                }
            }
        }
    } // namespace

    void Deoptimizer::GenerateDeoptimizationEntries(MacroAssembler* masm,
        Isolate* isolate,
        DeoptimizeKind deopt_kind)
    {
        NoRootArrayScope no_root_array(masm);

        // TODO(all): This code needs to be revisited. We probably only need to save
        // caller-saved registers here. Callee-saved registers can be stored directly
        // in the input frame.

        // Save all allocatable double registers.
        CPURegList saved_double_registers(
            CPURegister::kVRegister, kDRegSizeInBits,
            RegisterConfiguration::Default()->allocatable_double_codes_mask());
        DCHECK_EQ(saved_double_registers.Count() % 2, 0);
        __ PushCPURegList(saved_double_registers);

        CPURegList saved_float_registers(
            CPURegister::kVRegister, kSRegSizeInBits,
            RegisterConfiguration::Default()->allocatable_float_codes_mask());
        DCHECK_EQ(saved_float_registers.Count() % 4, 0);
        __ PushCPURegList(saved_float_registers);

        // We save all the registers except sp, lr and the masm scratches.
        CPURegList saved_registers(CPURegister::kRegister, kXRegSizeInBits, 0, 28);
        saved_registers.Remove(ip0);
        saved_registers.Remove(ip1);
        saved_registers.Combine(fp);
        DCHECK_EQ(saved_registers.Count() % 2, 0);
        __ PushCPURegList(saved_registers);

        __ Mov(x3, Operand(ExternalReference::Create(IsolateAddressId::kCEntryFPAddress, isolate)));
        __ Str(fp, MemOperand(x3));

        const int kSavedRegistersAreaSize = (saved_registers.Count() * kXRegSize) + (saved_double_registers.Count() * kDRegSize) + (saved_float_registers.Count() * kSRegSize);

        // Floating point registers are saved on the stack above core registers.
        const int kFloatRegistersOffset = saved_registers.Count() * kXRegSize;
        const int kDoubleRegistersOffset = kFloatRegistersOffset + saved_float_registers.Count() * kSRegSize;

        // The bailout id was passed by the caller in x26.
        Register bailout_id = x2;
        __ Mov(bailout_id, x26);

        Register code_object = x3;
        Register fp_to_sp = x4;
        // Get the address of the location in the code object. This is the return
        // address for lazy deoptimization.
        __ Mov(code_object, lr);
        // Compute the fp-to-sp delta.
        __ Add(fp_to_sp, sp, kSavedRegistersAreaSize);
        __ Sub(fp_to_sp, fp, fp_to_sp);

        // Allocate a new deoptimizer object.
        __ Ldr(x1, MemOperand(fp, CommonFrameConstants::kContextOrFrameTypeOffset));

        // Ensure we can safely load from below fp.
        DCHECK_GT(kSavedRegistersAreaSize,
            -JavaScriptFrameConstants::kFunctionOffset);
        __ Ldr(x0, MemOperand(fp, JavaScriptFrameConstants::kFunctionOffset));

        // If x1 is a smi, zero x0.
        __ Tst(x1, kSmiTagMask);
        __ CzeroX(x0, eq);

        __ Mov(x1, static_cast<int>(deopt_kind));
        // Following arguments are already loaded:
        //  - x2: bailout id
        //  - x3: code object address
        //  - x4: fp-to-sp delta
        __ Mov(x5, ExternalReference::isolate_address(isolate));

        {
            // Call Deoptimizer::New().
            AllowExternalCallThatCantCauseGC scope(masm);
            __ CallCFunction(ExternalReference::new_deoptimizer_function(), 6);
        }

        // Preserve "deoptimizer" object in register x0.
        Register deoptimizer = x0;

        // Get the input frame descriptor pointer.
        __ Ldr(x1, MemOperand(deoptimizer, Deoptimizer::input_offset()));

        // Copy core registers into the input frame.
        CopyRegListToFrame(masm, x1, FrameDescription::registers_offset(),
            saved_registers, x2, x3);

        // Copy double registers to the input frame.
        CopyRegListToFrame(masm, x1, FrameDescription::double_registers_offset(),
            saved_double_registers, x2, x3, kDoubleRegistersOffset);

        // Copy float registers to the input frame.
        // TODO(arm): these are the lower 32-bits of the double registers stored
        // above, so we shouldn't need to store them again.
        CopyRegListToFrame(masm, x1, FrameDescription::float_registers_offset(),
            saved_float_registers, w2, w3, kFloatRegistersOffset);

        // Remove the saved registers from the stack.
        DCHECK_EQ(kSavedRegistersAreaSize % kXRegSize, 0);
        __ Drop(kSavedRegistersAreaSize / kXRegSize);

        // Compute a pointer to the unwinding limit in register x2; that is
        // the first stack slot not part of the input frame.
        Register unwind_limit = x2;
        __ Ldr(unwind_limit, MemOperand(x1, FrameDescription::frame_size_offset()));

        // Unwind the stack down to - but not including - the unwinding
        // limit and copy the contents of the activation frame to the input
        // frame description.
        __ Add(x3, x1, FrameDescription::frame_content_offset());
        __ SlotAddress(x1, 0);
        __ Lsr(unwind_limit, unwind_limit, kSystemPointerSizeLog2);
        __ Mov(x5, unwind_limit);
        __ CopyDoubleWords(x3, x1, x5);
        __ Drop(unwind_limit);

        // Compute the output frame in the deoptimizer.
        __ Push(padreg, x0); // Preserve deoptimizer object across call.
        {
            // Call Deoptimizer::ComputeOutputFrames().
            AllowExternalCallThatCantCauseGC scope(masm);
            __ CallCFunction(ExternalReference::compute_output_frames_function(), 1);
        }
        __ Pop(x4, padreg); // Restore deoptimizer object (class Deoptimizer).

        {
            UseScratchRegisterScope temps(masm);
            Register scratch = temps.AcquireX();
            __ Ldr(scratch, MemOperand(x4, Deoptimizer::caller_frame_top_offset()));
            __ Mov(sp, scratch);
        }

        // Replace the current (input) frame with the output frames.
        Label outer_push_loop, outer_loop_header;
        __ Ldrsw(x1, MemOperand(x4, Deoptimizer::output_count_offset()));
        __ Ldr(x0, MemOperand(x4, Deoptimizer::output_offset()));
        __ Add(x1, x0, Operand(x1, LSL, kSystemPointerSizeLog2));
        __ B(&outer_loop_header);

        __ Bind(&outer_push_loop);
        Register current_frame = x2;
        Register frame_size = x3;
        __ Ldr(current_frame, MemOperand(x0, kSystemPointerSize, PostIndex));
        __ Ldr(x3, MemOperand(current_frame, FrameDescription::frame_size_offset()));
        __ Lsr(frame_size, x3, kSystemPointerSizeLog2);
        __ Claim(frame_size);

        __ Add(x7, current_frame, FrameDescription::frame_content_offset());
        __ SlotAddress(x6, 0);
        __ CopyDoubleWords(x6, x7, frame_size);

        __ Bind(&outer_loop_header);
        __ Cmp(x0, x1);
        __ B(lt, &outer_push_loop);

        __ Ldr(x1, MemOperand(x4, Deoptimizer::input_offset()));
        RestoreRegList(masm, saved_double_registers, x1,
            FrameDescription::double_registers_offset());

        // TODO(all): ARM copies a lot (if not all) of the last output frame onto the
        // stack, then pops it all into registers. Here, we try to load it directly
        // into the relevant registers. Is this correct? If so, we should improve the
        // ARM code.

        // Restore registers from the last output frame.
        // Note that lr is not in the list of saved_registers and will be restored
        // later. We can use it to hold the address of last output frame while
        // reloading the other registers.
        DCHECK(!saved_registers.IncludesAliasOf(lr));
        Register last_output_frame = lr;
        __ Mov(last_output_frame, current_frame);

        RestoreRegList(masm, saved_registers, last_output_frame,
            FrameDescription::registers_offset());

        Register continuation = x7;
        __ Ldr(continuation, MemOperand(last_output_frame, FrameDescription::continuation_offset()));
        __ Ldr(lr, MemOperand(last_output_frame, FrameDescription::pc_offset()));
        __ Br(continuation);
    }

    bool Deoptimizer::PadTopOfStackRegister() { return true; }

    void FrameDescription::SetCallerPc(unsigned offset, intptr_t value)
    {
        SetFrameSlot(offset, value);
    }

    void FrameDescription::SetCallerFp(unsigned offset, intptr_t value)
    {
        SetFrameSlot(offset, value);
    }

    void FrameDescription::SetCallerConstantPool(unsigned offset, intptr_t value)
    {
        // No embedded constant pool support.
        UNREACHABLE();
    }

#undef __

} // namespace internal
} // namespace v8
