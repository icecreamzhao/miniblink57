// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_WASM_BASELINE_LIFTOFF_COMPILER_H_
#define V8_WASM_BASELINE_LIFTOFF_COMPILER_H_

#include "src/base/macros.h"
#include "src/wasm/function-compiler.h"

namespace v8 {
namespace internal {

    class AccountingAllocator;
    class Counters;

    namespace wasm {

        struct CompilationEnv;
        struct FunctionBody;
        class NativeModule;
        struct WasmFeatures;

        class LiftoffCompilationUnit final {
        public:
            LiftoffCompilationUnit() = default;

            WasmCompilationResult ExecuteCompilation(AccountingAllocator*,
                CompilationEnv*, const FunctionBody&,
                Counters*,
                WasmFeatures* detected_features);

        private:
            DISALLOW_COPY_AND_ASSIGN(LiftoffCompilationUnit);
        };

    } // namespace wasm
} // namespace internal
} // namespace v8

#endif // V8_WASM_BASELINE_LIFTOFF_COMPILER_H_
