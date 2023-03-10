// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_UNOPTIMIZED_COMPILATION_INFO_H_
#define V8_UNOPTIMIZED_COMPILATION_INFO_H_

#include <memory>

#include "src/feedback-vector.h"
#include "src/globals.h"
#include "src/handles.h"
#include "src/objects.h"
#include "src/source-position-table.h"
#include "src/utils.h"

namespace v8 {
namespace internal {

    class AsmWasmData;
    class CoverageInfo;
    class DeclarationScope;
    class FunctionLiteral;
    class Isolate;
    class ParseInfo;
    class SourceRangeMap;
    class Zone;

    // UnoptimizedCompilationInfo encapsulates the information needed to compile
    // unoptimized code for a given function, and the results of the compilation.
    class V8_EXPORT_PRIVATE UnoptimizedCompilationInfo final {
    public:
        UnoptimizedCompilationInfo(Zone* zone, ParseInfo* parse_info,
            FunctionLiteral* literal);

        Zone* zone() { return zone_; }

        // Compilation flag accessors.

        void MarkAsEval() { SetFlag(kIsEval); }
        bool is_eval() const { return GetFlag(kIsEval); }

        void MarkAsCollectTypeProfile() { SetFlag(kCollectTypeProfile); }
        bool collect_type_profile() const { return GetFlag(kCollectTypeProfile); }

        void MarkAsForceCollectSourcePositions() { SetFlag(kCollectSourcePositions); }
        bool collect_source_positions() const
        {
            return GetFlag(kCollectSourcePositions);
        }

        void MarkAsMightAlwaysOpt() { SetFlag(kMightAlwaysOpt); }
        bool might_always_opt() const { return GetFlag(kMightAlwaysOpt); }

        // Accessors for the input data of the function being compiled.

        FunctionLiteral* literal() const { return literal_; }
        void set_literal(FunctionLiteral* literal)
        {
            DCHECK_NOT_NULL(literal);
            literal_ = literal;
        }

        DeclarationScope* scope() const;

        int num_parameters() const;
        int num_parameters_including_this() const;

        // Accessors for optional compilation features.

        SourcePositionTableBuilder::RecordingMode SourcePositionRecordingMode() const;

        bool has_source_range_map() const { return source_range_map_ != nullptr; }
        SourceRangeMap* source_range_map() const { return source_range_map_; }
        void set_source_range_map(SourceRangeMap* source_range_map)
        {
            source_range_map_ = source_range_map;
        }

        bool has_coverage_info() const { return !coverage_info_.is_null(); }
        Handle<CoverageInfo> coverage_info() const { return coverage_info_; }
        void set_coverage_info(Handle<CoverageInfo> coverage_info)
        {
            coverage_info_ = coverage_info;
        }

        // Accessors for the output of compilation.

        bool has_bytecode_array() const { return !bytecode_array_.is_null(); }
        Handle<BytecodeArray> bytecode_array() const { return bytecode_array_; }
        void SetBytecodeArray(Handle<BytecodeArray> bytecode_array)
        {
            bytecode_array_ = bytecode_array;
        }

        bool has_asm_wasm_data() const { return !asm_wasm_data_.is_null(); }
        Handle<AsmWasmData> asm_wasm_data() const { return asm_wasm_data_; }
        void SetAsmWasmData(Handle<AsmWasmData> asm_wasm_data)
        {
            asm_wasm_data_ = asm_wasm_data;
        }

        FeedbackVectorSpec* feedback_vector_spec() { return &feedback_vector_spec_; }

    private:
        // Various configuration flags for a compilation, as well as some properties
        // of the compiled code produced by a compilation.
        enum Flag {
            kIsEval = 1 << 0,
            kCollectTypeProfile = 1 << 1,
            kMightAlwaysOpt = 1 << 2,
            kCollectSourcePositions = 1 << 3,
        };

        void SetFlag(Flag flag) { flags_ |= flag; }
        bool GetFlag(Flag flag) const { return (flags_ & flag) != 0; }

        // Compilation flags.
        unsigned flags_;

        // The zone from which the compilation pipeline working on this
        // OptimizedCompilationInfo allocates.
        Zone* zone_;

        // The root AST node of the function literal being compiled.
        FunctionLiteral* literal_;

        // Used when block coverage is enabled.
        SourceRangeMap* source_range_map_;

        // Encapsulates coverage information gathered by the bytecode generator.
        // Needs to be stored on the shared function info once compilation completes.
        Handle<CoverageInfo> coverage_info_;

        // Holds the bytecode array generated by the interpreter.
        Handle<BytecodeArray> bytecode_array_;

        // Holds the asm_wasm data struct generated by the asmjs compiler.
        Handle<AsmWasmData> asm_wasm_data_;

        // Holds the feedback vector spec generated during compilation
        FeedbackVectorSpec feedback_vector_spec_;
    };

} // namespace internal
} // namespace v8

#endif // V8_UNOPTIMIZED_COMPILATION_INFO_H_
