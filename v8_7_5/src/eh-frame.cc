// Copyright 2016 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/eh-frame.h"

#include <iomanip>
#include <ostream>

#include "src/code-desc.h"

#if !defined(V8_TARGET_ARCH_X64) && !defined(V8_TARGET_ARCH_ARM) && !defined(V8_TARGET_ARCH_ARM64)

// Placeholders for unsupported architectures.

namespace v8 {
namespace internal {

    const int EhFrameConstants::kCodeAlignmentFactor = 1;
    const int EhFrameConstants::kDataAlignmentFactor = 1;

    void EhFrameWriter::WriteReturnAddressRegisterCode() { UNIMPLEMENTED(); }

    void EhFrameWriter::WriteInitialStateInCie() { UNIMPLEMENTED(); }

    int EhFrameWriter::RegisterToDwarfCode(Register)
    {
        UNIMPLEMENTED();
        return -1;
    }

#ifdef ENABLE_DISASSEMBLER

    const char* EhFrameDisassembler::DwarfRegisterCodeToString(int)
    {
        UNIMPLEMENTED();
        return nullptr;
    }

#endif

} // namespace internal
} // namespace v8

#endif

namespace v8 {
namespace internal {

    STATIC_CONST_MEMBER_DEFINITION const int
        EhFrameConstants::kEhFrameTerminatorSize;
    STATIC_CONST_MEMBER_DEFINITION const int EhFrameConstants::kEhFrameHdrVersion;
    STATIC_CONST_MEMBER_DEFINITION const int EhFrameConstants::kEhFrameHdrSize;

    STATIC_CONST_MEMBER_DEFINITION const uint32_t EhFrameWriter::kInt32Placeholder;

    // static
    void EhFrameWriter::WriteEmptyEhFrame(std::ostream& stream)
    { // NOLINT
        stream.put(EhFrameConstants::kEhFrameHdrVersion);

        // .eh_frame pointer encoding specifier.
        stream.put(EhFrameConstants::kSData4 | EhFrameConstants::kPcRel);

        // Lookup table size encoding.
        stream.put(EhFrameConstants::kUData4);

        // Lookup table entries encoding.
        stream.put(EhFrameConstants::kSData4 | EhFrameConstants::kDataRel);

        // Dummy pointers and 0 entries in the lookup table.
        char dummy_data[EhFrameConstants::kEhFrameHdrSize - 4] = { 0 };
        stream.write(&dummy_data[0], sizeof(dummy_data));
    }

    EhFrameWriter::EhFrameWriter(Zone* zone)
        : cie_size_(0)
        , last_pc_offset_(0)
        , writer_state_(InternalState::kUndefined)
        , base_register_(no_reg)
        , base_offset_(0)
        , eh_frame_buffer_(zone)
    {
    }

    void EhFrameWriter::Initialize()
    {
        DCHECK_EQ(writer_state_, InternalState::kUndefined);
        eh_frame_buffer_.reserve(128);
        writer_state_ = InternalState::kInitialized;
        WriteCie();
        WriteFdeHeader();
    }

    void EhFrameWriter::WriteCie()
    {
        static const int kCIEIdentifier = 0;
        static const int kCIEVersion = 3;
        static const int kAugmentationDataSize = 2;
        static const byte kAugmentationString[] = { 'z', 'L', 'R', 0 };

        // Placeholder for the size of the CIE.
        int size_offset = eh_frame_offset();
        WriteInt32(kInt32Placeholder);

        // CIE identifier and version.
        int record_start_offset = eh_frame_offset();
        WriteInt32(kCIEIdentifier);
        WriteByte(kCIEVersion);

        // Augmentation data contents descriptor: LSDA and FDE encoding.
        WriteBytes(&kAugmentationString[0], sizeof(kAugmentationString));

        // Alignment factors.
        WriteSLeb128(EhFrameConstants::kCodeAlignmentFactor);
        WriteSLeb128(EhFrameConstants::kDataAlignmentFactor);

        WriteReturnAddressRegisterCode();

        // Augmentation data.
        WriteULeb128(kAugmentationDataSize);
        // No language-specific data area (LSDA).
        WriteByte(EhFrameConstants::kOmit);
        // FDE pointers encoding.
        WriteByte(EhFrameConstants::kSData4 | EhFrameConstants::kPcRel);

        // Write directives to build the initial state of the unwinding table.
        DCHECK_EQ(eh_frame_offset() - size_offset,
            EhFrameConstants::kInitialStateOffsetInCie);
        WriteInitialStateInCie();

        WritePaddingToAlignedSize(eh_frame_offset() - record_start_offset);

        int record_end_offset = eh_frame_offset();
        int encoded_cie_size = record_end_offset - record_start_offset;
        cie_size_ = record_end_offset - size_offset;

        // Patch the size of the CIE now that we know it.
        PatchInt32(size_offset, encoded_cie_size);
    }

    void EhFrameWriter::WriteFdeHeader()
    {
        DCHECK_NE(cie_size_, 0);

        // Placeholder for size of the FDE. Will be filled in Finish().
        DCHECK_EQ(eh_frame_offset(), fde_offset());
        WriteInt32(kInt32Placeholder);

        // Backwards offset to the CIE.
        WriteInt32(cie_size_ + kInt32Size);

        // Placeholder for pointer to procedure. Will be filled in Finish().
        DCHECK_EQ(eh_frame_offset(), GetProcedureAddressOffset());
        WriteInt32(kInt32Placeholder);

        // Placeholder for size of the procedure. Will be filled in Finish().
        DCHECK_EQ(eh_frame_offset(), GetProcedureSizeOffset());
        WriteInt32(kInt32Placeholder);

        // No augmentation data.
        WriteByte(0);
    }

    void EhFrameWriter::WriteEhFrameHdr(int code_size)
    {
        DCHECK_EQ(writer_state_, InternalState::kInitialized);

        //
        // In order to calculate offsets in the .eh_frame_hdr, we must know the layout
        // of the DSO generated by perf inject, which is assumed to be the following:
        //
        //  |      ...      |                        |
        //  +---------------+ <-- (F) ---            |  Larger offsets in file
        //  |               |           ^            |
        //  |  Instructions |           | .text      v
        //  |               |           v
        //  +---------------+ <-- (E) ---
        //  |///////////////|
        //  |////Padding////|
        //  |///////////////|
        //  +---------------+ <-- (D) ---
        //  |               |           ^
        //  |      CIE      |           |
        //  |               |           |
        //  +---------------+ <-- (C)   |
        //  |               |           | .eh_frame
        //  |      FDE      |           |
        //  |               |           |
        //  +---------------+           |
        //  |   terminator  |           v
        //  +---------------+ <-- (B) ---
        //  |    version    |           ^
        //  +---------------+           |
        //  |   encoding    |           |
        //  |  specifiers   |           |
        //  +---------------+ <---(A)   | .eh_frame_hdr
        //  |   offset to   |           |
        //  |   .eh_frame   |           |
        //  +---------------+           |
        //  |      ...      |          ...
        //
        // (F) is aligned to a 16-byte boundary.
        // (D) is aligned to a  8-byte boundary.
        // (B) is aligned to a  4-byte boundary.
        // (C), (E) and (A) have no alignment requirements.
        //
        // The distance between (A) and (B) is 4 bytes.
        //
        // The size of the FDE is required to be a multiple of the pointer size, which
        // means that (B) will be naturally aligned to a 4-byte boundary on all the
        // architectures we support.
        //
        // Because (E) has no alignment requirements, there is padding between (E) and
        // (D). (F) is aligned at a 16-byte boundary, thus to a 8-byte one as well.
        //

        int eh_frame_size = eh_frame_offset();

        WriteByte(EhFrameConstants::kEhFrameHdrVersion);

        // .eh_frame pointer encoding specifier.
        WriteByte(EhFrameConstants::kSData4 | EhFrameConstants::kPcRel);
        // Lookup table size encoding specifier.
        WriteByte(EhFrameConstants::kUData4);
        // Lookup table entries encoding specifier.
        WriteByte(EhFrameConstants::kSData4 | EhFrameConstants::kDataRel);

        // Pointer to .eh_frame, relative to this offset (A -> D in the diagram).
        WriteInt32(-(eh_frame_size + EhFrameConstants::kFdeVersionSize + EhFrameConstants::kFdeEncodingSpecifiersSize));

        // Number of entries in the LUT, one for the only routine.
        WriteInt32(1);

        // Pointer to the start of the routine, relative to the beginning of the
        // .eh_frame_hdr (B -> F in the diagram).
        WriteInt32(-(RoundUp(code_size, 8) + eh_frame_size));

        // Pointer to the start of the associated FDE, relative to the start of the
        // .eh_frame_hdr (B -> C  in the diagram).
        WriteInt32(-(eh_frame_size - cie_size_));

        DCHECK_EQ(eh_frame_offset() - eh_frame_size,
            EhFrameConstants::kEhFrameHdrSize);
    }

    void EhFrameWriter::WritePaddingToAlignedSize(int unpadded_size)
    {
        DCHECK_EQ(writer_state_, InternalState::kInitialized);
        DCHECK_GE(unpadded_size, 0);

        int padding_size = RoundUp(unpadded_size, kSystemPointerSize) - unpadded_size;

        byte nop = static_cast<byte>(EhFrameConstants::DwarfOpcodes::kNop);
        static const byte kPadding[] = { nop, nop, nop, nop, nop, nop, nop, nop };
        DCHECK_LE(padding_size, static_cast<int>(sizeof(kPadding)));
        WriteBytes(&kPadding[0], padding_size);
    }

    void EhFrameWriter::AdvanceLocation(int pc_offset)
    {
        DCHECK_EQ(writer_state_, InternalState::kInitialized);
        DCHECK_GE(pc_offset, last_pc_offset_);
        uint32_t delta = pc_offset - last_pc_offset_;

        DCHECK_EQ(delta % EhFrameConstants::kCodeAlignmentFactor, 0u);
        uint32_t factored_delta = delta / EhFrameConstants::kCodeAlignmentFactor;

        if (factored_delta <= EhFrameConstants::kLocationMask) {
            WriteByte((EhFrameConstants::kLocationTag
                          << EhFrameConstants::kLocationMaskSize)
                | (factored_delta & EhFrameConstants::kLocationMask));
        } else if (factored_delta <= kMaxUInt8) {
            WriteOpcode(EhFrameConstants::DwarfOpcodes::kAdvanceLoc1);
            WriteByte(factored_delta);
        } else if (factored_delta <= kMaxUInt16) {
            WriteOpcode(EhFrameConstants::DwarfOpcodes::kAdvanceLoc2);
            WriteInt16(factored_delta);
        } else {
            WriteOpcode(EhFrameConstants::DwarfOpcodes::kAdvanceLoc4);
            WriteInt32(factored_delta);
        }

        last_pc_offset_ = pc_offset;
    }

    void EhFrameWriter::SetBaseAddressOffset(int base_offset)
    {
        DCHECK_EQ(writer_state_, InternalState::kInitialized);
        DCHECK_GE(base_offset, 0);
        WriteOpcode(EhFrameConstants::DwarfOpcodes::kDefCfaOffset);
        WriteULeb128(base_offset);
        base_offset_ = base_offset;
    }

    void EhFrameWriter::SetBaseAddressRegister(Register base_register)
    {
        DCHECK_EQ(writer_state_, InternalState::kInitialized);
        int code = RegisterToDwarfCode(base_register);
        WriteOpcode(EhFrameConstants::DwarfOpcodes::kDefCfaRegister);
        WriteULeb128(code);
        base_register_ = base_register;
    }

    void EhFrameWriter::SetBaseAddressRegisterAndOffset(Register base_register,
        int base_offset)
    {
        DCHECK_EQ(writer_state_, InternalState::kInitialized);
        DCHECK_GE(base_offset, 0);
        int code = RegisterToDwarfCode(base_register);
        WriteOpcode(EhFrameConstants::DwarfOpcodes::kDefCfa);
        WriteULeb128(code);
        WriteULeb128(base_offset);
        base_offset_ = base_offset;
        base_register_ = base_register;
    }

    void EhFrameWriter::RecordRegisterSavedToStack(int register_code, int offset)
    {
        DCHECK_EQ(writer_state_, InternalState::kInitialized);
        DCHECK_EQ(offset % EhFrameConstants::kDataAlignmentFactor, 0);
        int factored_offset = offset / EhFrameConstants::kDataAlignmentFactor;
        if (factored_offset >= 0) {
            DCHECK_LE(register_code, EhFrameConstants::kSavedRegisterMask);
            WriteByte((EhFrameConstants::kSavedRegisterTag
                          << EhFrameConstants::kSavedRegisterMaskSize)
                | (register_code & EhFrameConstants::kSavedRegisterMask));
            WriteULeb128(factored_offset);
        } else {
            WriteOpcode(EhFrameConstants::DwarfOpcodes::kOffsetExtendedSf);
            WriteULeb128(register_code);
            WriteSLeb128(factored_offset);
        }
    }

    void EhFrameWriter::RecordRegisterNotModified(Register name)
    {
        DCHECK_EQ(writer_state_, InternalState::kInitialized);
        WriteOpcode(EhFrameConstants::DwarfOpcodes::kSameValue);
        WriteULeb128(RegisterToDwarfCode(name));
    }

    void EhFrameWriter::RecordRegisterFollowsInitialRule(Register name)
    {
        DCHECK_EQ(writer_state_, InternalState::kInitialized);
        int code = RegisterToDwarfCode(name);
        DCHECK_LE(code, EhFrameConstants::kFollowInitialRuleMask);
        WriteByte((EhFrameConstants::kFollowInitialRuleTag
                      << EhFrameConstants::kFollowInitialRuleMaskSize)
            | (code & EhFrameConstants::kFollowInitialRuleMask));
    }

    void EhFrameWriter::Finish(int code_size)
    {
        DCHECK_EQ(writer_state_, InternalState::kInitialized);
        DCHECK_GE(eh_frame_offset(), cie_size_);

        DCHECK_GE(eh_frame_offset(), fde_offset() + kInt32Size);
        WritePaddingToAlignedSize(eh_frame_offset() - fde_offset() - kInt32Size);

        // Write the size of the FDE now that we know it.
        // The encoded size does not include the size field itself.
        int encoded_fde_size = eh_frame_offset() - fde_offset() - kInt32Size;
        PatchInt32(fde_offset(), encoded_fde_size);

        // Write size and offset to procedure.
        PatchInt32(GetProcedureAddressOffset(),
            -(RoundUp(code_size, 8) + GetProcedureAddressOffset()));
        PatchInt32(GetProcedureSizeOffset(), code_size);

        // Terminate the .eh_frame.
        static const byte kTerminator[EhFrameConstants::kEhFrameTerminatorSize] = { 0 };
        WriteBytes(&kTerminator[0], EhFrameConstants::kEhFrameTerminatorSize);

        WriteEhFrameHdr(code_size);

        writer_state_ = InternalState::kFinalized;
    }

    void EhFrameWriter::GetEhFrame(CodeDesc* desc)
    {
        DCHECK_EQ(writer_state_, InternalState::kFinalized);
        desc->unwinding_info_size = static_cast<int>(eh_frame_buffer_.size());
        desc->unwinding_info = eh_frame_buffer_.data();
    }

    void EhFrameWriter::WriteULeb128(uint32_t value)
    {
        do {
            byte chunk = value & 0x7F;
            value >>= 7;
            if (value != 0)
                chunk |= 0x80;
            WriteByte(chunk);
        } while (value != 0);
    }

    void EhFrameWriter::WriteSLeb128(int32_t value)
    {
        static const int kSignBitMask = 0x40;
        bool done;
        do {
            byte chunk = value & 0x7F;
            value >>= 7;
            done = ((value == 0) && ((chunk & kSignBitMask) == 0)) || ((value == -1) && ((chunk & kSignBitMask) != 0));
            if (!done)
                chunk |= 0x80;
            WriteByte(chunk);
        } while (!done);
    }

    uint32_t EhFrameIterator::GetNextULeb128()
    {
        int size = 0;
        uint32_t result = DecodeULeb128(next_, &size);
        DCHECK_LE(next_ + size, end_);
        next_ += size;
        return result;
    }

    int32_t EhFrameIterator::GetNextSLeb128()
    {
        int size = 0;
        int32_t result = DecodeSLeb128(next_, &size);
        DCHECK_LE(next_ + size, end_);
        next_ += size;
        return result;
    }

    // static
    uint32_t EhFrameIterator::DecodeULeb128(const byte* encoded,
        int* encoded_size)
    {
        const byte* current = encoded;
        uint32_t result = 0;
        int shift = 0;

        do {
            DCHECK_LT(shift, 8 * static_cast<int>(sizeof(result)));
            result |= (*current & 0x7F) << shift;
            shift += 7;
        } while (*current++ >= 128);

        DCHECK_NOT_NULL(encoded_size);
        *encoded_size = static_cast<int>(current - encoded);

        return result;
    }

    // static
    int32_t EhFrameIterator::DecodeSLeb128(const byte* encoded, int* encoded_size)
    {
        static const byte kSignBitMask = 0x40;

        const byte* current = encoded;
        int32_t result = 0;
        int shift = 0;
        byte chunk;

        do {
            chunk = *current++;
            DCHECK_LT(shift, 8 * static_cast<int>(sizeof(result)));
            result |= (chunk & 0x7F) << shift;
            shift += 7;
        } while (chunk >= 128);

        // Sign extend the result if the last chunk has the sign bit set.
        if (chunk & kSignBitMask)
            result |= (~0ull) << shift;

        DCHECK_NOT_NULL(encoded_size);
        *encoded_size = static_cast<int>(current - encoded);

        return result;
    }

#ifdef ENABLE_DISASSEMBLER

    namespace {

        class StreamModifiersScope final {
        public:
            explicit StreamModifiersScope(std::ostream* stream)
                : stream_(stream)
                , flags_(stream->flags())
            {
            }
            ~StreamModifiersScope() { stream_->flags(flags_); }

        private:
            std::ostream* stream_;
            std::ios::fmtflags flags_;
        };

    } // namespace

    // static
    void EhFrameDisassembler::DumpDwarfDirectives(std::ostream& stream, // NOLINT
        const byte* start,
        const byte* end)
    {
        StreamModifiersScope modifiers_scope(&stream);

        EhFrameIterator eh_frame_iterator(start, end);
        uint32_t offset_in_procedure = 0;

        while (!eh_frame_iterator.Done()) {
            stream << eh_frame_iterator.current_address() << "  ";

            byte bytecode = eh_frame_iterator.GetNextByte();

            if (((bytecode >> EhFrameConstants::kLocationMaskSize) & 0xFF) == EhFrameConstants::kLocationTag) {
                int value = (bytecode & EhFrameConstants::kLocationMask) * EhFrameConstants::kCodeAlignmentFactor;
                offset_in_procedure += value;
                stream << "| pc_offset=" << offset_in_procedure << " (delta=" << value
                       << ")\n";
                continue;
            }

            if (((bytecode >> EhFrameConstants::kSavedRegisterMaskSize) & 0xFF) == EhFrameConstants::kSavedRegisterTag) {
                int32_t decoded_offset = eh_frame_iterator.GetNextULeb128();
                stream << "| " << DwarfRegisterCodeToString(bytecode & EhFrameConstants::kLocationMask)
                       << " saved at base" << std::showpos
                       << decoded_offset * EhFrameConstants::kDataAlignmentFactor
                       << std::noshowpos << '\n';
                continue;
            }

            if (((bytecode >> EhFrameConstants::kFollowInitialRuleMaskSize) & 0xFF) == EhFrameConstants::kFollowInitialRuleTag) {
                stream << "| " << DwarfRegisterCodeToString(bytecode & EhFrameConstants::kLocationMask)
                       << " follows rule in CIE\n";
                continue;
            }

            switch (static_cast<EhFrameConstants::DwarfOpcodes>(bytecode)) {
            case EhFrameConstants::DwarfOpcodes::kOffsetExtendedSf: {
                stream << "| "
                       << DwarfRegisterCodeToString(eh_frame_iterator.GetNextULeb128());
                int32_t decoded_offset = eh_frame_iterator.GetNextSLeb128();
                stream << " saved at base" << std::showpos
                       << decoded_offset * EhFrameConstants::kDataAlignmentFactor
                       << std::noshowpos << '\n';
                break;
            }
            case EhFrameConstants::DwarfOpcodes::kAdvanceLoc1: {
                int value = eh_frame_iterator.GetNextByte() * EhFrameConstants::kCodeAlignmentFactor;
                offset_in_procedure += value;
                stream << "| pc_offset=" << offset_in_procedure << " (delta=" << value
                       << ")\n";
                break;
            }
            case EhFrameConstants::DwarfOpcodes::kAdvanceLoc2: {
                int value = eh_frame_iterator.GetNextUInt16() * EhFrameConstants::kCodeAlignmentFactor;
                offset_in_procedure += value;
                stream << "| pc_offset=" << offset_in_procedure << " (delta=" << value
                       << ")\n";
                break;
            }
            case EhFrameConstants::DwarfOpcodes::kAdvanceLoc4: {
                int value = eh_frame_iterator.GetNextUInt32() * EhFrameConstants::kCodeAlignmentFactor;
                offset_in_procedure += value;
                stream << "| pc_offset=" << offset_in_procedure << " (delta=" << value
                       << ")\n";
                break;
            }
            case EhFrameConstants::DwarfOpcodes::kDefCfa: {
                uint32_t base_register = eh_frame_iterator.GetNextULeb128();
                uint32_t base_offset = eh_frame_iterator.GetNextULeb128();
                stream << "| base_register=" << DwarfRegisterCodeToString(base_register)
                       << ", base_offset=" << base_offset << '\n';
                break;
            }
            case EhFrameConstants::DwarfOpcodes::kDefCfaOffset: {
                stream << "| base_offset=" << eh_frame_iterator.GetNextULeb128()
                       << '\n';
                break;
            }
            case EhFrameConstants::DwarfOpcodes::kDefCfaRegister: {
                stream << "| base_register="
                       << DwarfRegisterCodeToString(eh_frame_iterator.GetNextULeb128())
                       << '\n';
                break;
            }
            case EhFrameConstants::DwarfOpcodes::kSameValue: {
                stream << "| "
                       << DwarfRegisterCodeToString(eh_frame_iterator.GetNextULeb128())
                       << " not modified from previous frame\n";
                break;
            }
            case EhFrameConstants::DwarfOpcodes::kNop:
                stream << "| nop\n";
                break;
            default:
                UNREACHABLE();
                return;
            }
        }
    }

    void EhFrameDisassembler::DisassembleToStream(std::ostream& stream)
    { // NOLINT
        // The encoded CIE size does not include the size field itself.
        const int cie_size = ReadUnalignedUInt32(reinterpret_cast<Address>(start_)) + kInt32Size;
        const int fde_offset = cie_size;

        const byte* cie_directives_start = start_ + EhFrameConstants::kInitialStateOffsetInCie;
        const byte* cie_directives_end = start_ + cie_size;
        DCHECK_LE(cie_directives_start, cie_directives_end);

        stream << reinterpret_cast<const void*>(start_) << "  .eh_frame: CIE\n";
        DumpDwarfDirectives(stream, cie_directives_start, cie_directives_end);

        Address procedure_offset_address = reinterpret_cast<Address>(start_) + fde_offset + EhFrameConstants::kProcedureAddressOffsetInFde;
        int32_t procedure_offset = ReadUnalignedValue<int32_t>(procedure_offset_address);

        Address procedure_size_address = reinterpret_cast<Address>(start_) + fde_offset + EhFrameConstants::kProcedureSizeOffsetInFde;
        uint32_t procedure_size = ReadUnalignedUInt32(procedure_size_address);

        const byte* fde_start = start_ + fde_offset;
        stream << reinterpret_cast<const void*>(fde_start) << "  .eh_frame: FDE\n"
               << reinterpret_cast<const void*>(procedure_offset_address)
               << "  | procedure_offset=" << procedure_offset << '\n'
               << reinterpret_cast<const void*>(procedure_size_address)
               << "  | procedure_size=" << procedure_size << '\n';

        const int fde_directives_offset = fde_offset + 4 * kInt32Size + 1;

        const byte* fde_directives_start = start_ + fde_directives_offset;
        const byte* fde_directives_end = end_ - EhFrameConstants::kEhFrameHdrSize - EhFrameConstants::kEhFrameTerminatorSize;
        DCHECK_LE(fde_directives_start, fde_directives_end);

        DumpDwarfDirectives(stream, fde_directives_start, fde_directives_end);

        const byte* fde_terminator_start = fde_directives_end;
        stream << reinterpret_cast<const void*>(fde_terminator_start)
               << "  .eh_frame: terminator\n";

        const byte* eh_frame_hdr_start = fde_terminator_start + EhFrameConstants::kEhFrameTerminatorSize;
        stream << reinterpret_cast<const void*>(eh_frame_hdr_start)
               << "  .eh_frame_hdr\n";
    }

#endif

} // namespace internal
} // namespace v8
