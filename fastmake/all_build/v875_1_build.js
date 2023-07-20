import { constVal, buildCommonSetting } from "./const_val.js";

var json = [{
    "var":[
        {"sdkPath":constVal.sdkPath},
        {"clangPath":constVal.clangPath},
        {"srcPath":constVal.srcPath},
        {"ndkIncludePath":constVal.ndkIncludePath},
        {"ndkBinPath":constVal.ndkBinPath},
        {"targetDir": constVal.targetDir},
        {"sysroot": constVal.sysroot},
    ],
    "compile":{
        "ccompiler":"${clangPath}/clang.exe",
        "cppcompiler":"${clangPath}/clang++.exe",
            
        "include":[
            "${sdkPath}/include/c++/7.2.0",
            "${sdkPath}/include/c++/7.2.0/include",
            "${ndkIncludePath}",
            "${sdkPath}/include/c++/7.2.0/x86_64-unknown-linux-gnu/",
            "${sdkPath}/sysroot/usr/include",
            "${sdkPath}/sysroot/usr/",
            "${sdkPath}/sysroot/usr/include/linux",
            "${srcPath}/linux",
            "${srcPath}/gen/v8_7_5",
            "${srcPath}/gen/v8_7_5/include",
            "${srcPath}/v8_7_5",
            "${srcPath}/v8_7_5/include",
            "${srcPath}",
        ],
        "prebuildSrc":[
            //"${srcPath}/gen/v8_7_5/torque-generated/builtins-array-from-dsl-gen-x64.cc",
            //"${srcPath}/v8_7_5/src/builtins/generate-bytecodes-builtins-list.cc",
            "${srcPath}/v8_7_5/src/api.cc",
            //"${srcPath}/v8_7_5/src/trap-handler/handler-inside-posix.cc",
            //"${srcPath}/v8_7_5/src/trap-handler/handler-shared.cc",
            "${srcPath}/v8_7_5/src/trap-handler/handler-outside.cc"
        ],
        "src":[
            "${srcPath}/v8_7_5/src/asmjs/asm-parser.cc",
            "${srcPath}/v8_7_5/src/asmjs/asm-scanner.cc",
            "${srcPath}/v8_7_5/src/asmjs/asm-types.cc",
            "${srcPath}/v8_7_5/src/asmjs/asm-js.cc",
            "${srcPath}/v8_7_5/src/ast/ast-function-literal-id-reindexer.cc",
            "${srcPath}/v8_7_5/src/ast/ast-value-factory.cc",
            "${srcPath}/v8_7_5/src/ast/modules.cc",
            "${srcPath}/v8_7_5/src/ast/prettyprinter.cc",
            "${srcPath}/v8_7_5/src/ast/scopes.cc",
            "${srcPath}/v8_7_5/src/ast/source-range-ast-visitor.cc",
            "${srcPath}/v8_7_5/src/ast/variables.cc",
            "${srcPath}/v8_7_5/src/ast/ast.cc",
            "${srcPath}/v8_7_5/src/base/functional.cc",
            "${srcPath}/v8_7_5/src/base/ieee754.cc",
            "${srcPath}/v8_7_5/src/base/logging.cc",
            "${srcPath}/v8_7_5/src/base/lsan-page-allocator.cc",
            "${srcPath}/v8_7_5/src/base/once.cc",
            "${srcPath}/v8_7_5/src/base/page-allocator.cc",
            "${srcPath}/v8_7_5/src/base/region-allocator.cc",
            "${srcPath}/v8_7_5/src/base/sys-info.cc",
            "${srcPath}/v8_7_5/src/base/bits.cc",
            "${srcPath}/v8_7_5/src/base/bounded-page-allocator.cc",
            "${srcPath}/v8_7_5/src/base/cpu.cc",
            "${srcPath}/v8_7_5/src/base/division-by-constant.cc",
            "${srcPath}/v8_7_5/src/base/file-utils.cc",
            "${srcPath}/v8_7_5/src/base/debug/stack_trace.cc",
            "${srcPath}/v8_7_5/src/base/debug/stack_trace_posix.cc",
            "${srcPath}/v8_7_5/src/debug/x64/debug-x64.cc",
            "${srcPath}/v8_7_5/src/base/platform/semaphore.cc",
            "${srcPath}/v8_7_5/src/base/platform/time.cc",
            "${srcPath}/v8_7_5/src/base/platform/condition-variable.cc",
            "${srcPath}/v8_7_5/src/base/platform/mutex.cc",
            "${srcPath}/v8_7_5/src/base/utils/random-number-generator.cc",
            "${srcPath}/v8_7_5/src/builtins/ia32/builtins-ia32.cc",
            "${srcPath}/v8_7_5/src/builtins/constants-table-builder.cc",
            "${srcPath}/v8_7_5/src/builtins/generate-bytecodes-builtins-list.cc",
            "${srcPath}/v8_7_5/src/builtins/growable-fixed-array-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/setup-builtins-internal.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-api.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-arguments-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-array.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-arraybuffer.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-array-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-async-function-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-async-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-async-generator-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-async-iterator-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-bigint.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-bigint-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-boolean.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-boolean-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-call.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-call-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-callsite.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-collections.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-collections-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-console.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-console-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-constructor-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-conversion-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-dataview.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-date.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-date-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-debug-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-error.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-extras-utils.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-function.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-function-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-generator-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-global.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-global-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-handler-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-ic-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-internal.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-internal-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-interpreter-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-iterator-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-json.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-lazy-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-math.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-math-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-microtask-queue-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-number.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-number-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-object.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-object-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-promise.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-promise-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-proxy-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-reflect.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-reflect-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-regexp.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-regexp-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-sharedarraybuffer.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-sharedarraybuffer-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-string.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-string-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-symbol.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-symbol-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-trace.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-typed-array.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-typed-array-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-wasm-gen.cc",
            "${srcPath}/v8_7_5/src/builtins/builtins-weak-refs.cc",
            "${srcPath}/v8_7_5/src/builtins/x64/builtins-x64.cc",
            "${srcPath}/v8_7_5/src/compiler/load-elimination.cc",
            "${srcPath}/v8_7_5/src/compiler/loop-analysis.cc",
            "${srcPath}/v8_7_5/src/compiler/loop-peeling.cc",
            "${srcPath}/v8_7_5/src/compiler/loop-variable-optimizer.cc",
            "${srcPath}/v8_7_5/src/compiler/machine-graph.cc",
            "${srcPath}/v8_7_5/src/compiler/machine-graph-verifier.cc",
            "${srcPath}/v8_7_5/src/compiler/machine-operator.cc",
            "${srcPath}/v8_7_5/src/compiler/machine-operator-reducer.cc",
            "${srcPath}/v8_7_5/src/compiler/memory-optimizer.cc",
            "${srcPath}/v8_7_5/src/compiler/node.cc",
            "${srcPath}/v8_7_5/src/compiler/node-cache.cc",
            "${srcPath}/v8_7_5/src/compiler/node-marker.cc",
            "${srcPath}/v8_7_5/src/compiler/node-matchers.cc",
            "${srcPath}/v8_7_5/src/compiler/node-origin-table.cc",
            "${srcPath}/v8_7_5/src/compiler/node-properties.cc",
            "${srcPath}/v8_7_5/src/compiler/opcodes.cc",
            "${srcPath}/v8_7_5/src/compiler/operation-typer.cc",
            "${srcPath}/v8_7_5/src/compiler/operator.cc",
            "${srcPath}/v8_7_5/src/compiler/operator-properties.cc",
            "${srcPath}/v8_7_5/src/compiler/osr.cc",
            "${srcPath}/v8_7_5/src/compiler/pipeline.cc",
            "${srcPath}/v8_7_5/src/compiler/pipeline-statistics.cc",
            "${srcPath}/v8_7_5/src/compiler/property-access-builder.cc",
            "${srcPath}/v8_7_5/src/compiler/raw-machine-assembler.cc",
            "${srcPath}/v8_7_5/src/compiler/redundancy-elimination.cc",
            "${srcPath}/v8_7_5/src/compiler/refs-map.cc",
            "${srcPath}/v8_7_5/src/compiler/representation-change.cc",
            "${srcPath}/v8_7_5/src/compiler/schedule.cc",
            "${srcPath}/v8_7_5/src/compiler/scheduler.cc",
            "${srcPath}/v8_7_5/src/compiler/select-lowering.cc",
            "${srcPath}/v8_7_5/src/compiler/serializer-for-background-compilation.cc",
            "${srcPath}/v8_7_5/src/compiler/simd-scalar-lowering.cc",
            "${srcPath}/v8_7_5/src/compiler/simplified-lowering.cc",
            "${srcPath}/v8_7_5/src/compiler/simplified-operator.cc",
            "${srcPath}/v8_7_5/src/compiler/simplified-operator-reducer.cc",
            "${srcPath}/v8_7_5/src/compiler/state-values-utils.cc",
            "${srcPath}/v8_7_5/src/compiler/store-store-elimination.cc",
            "${srcPath}/v8_7_5/src/compiler/type-cache.cc",
            "${srcPath}/v8_7_5/src/compiler/typed-optimization.cc",
            "${srcPath}/v8_7_5/src/compiler/type-narrowing-reducer.cc",
            "${srcPath}/v8_7_5/src/compiler/typer.cc",
            "${srcPath}/v8_7_5/src/compiler/types.cc",
            "${srcPath}/v8_7_5/src/compiler/value-numbering-reducer.cc",
            "${srcPath}/v8_7_5/src/compiler/verifier.cc",
            "${srcPath}/v8_7_5/src/compiler/wasm-compiler.cc",
            "${srcPath}/v8_7_5/src/compiler/zone-stats.cc",
            "${srcPath}/v8_7_5/src/compiler/access-builder.cc",
            "${srcPath}/v8_7_5/src/compiler/access-info.cc",
            "${srcPath}/v8_7_5/src/compiler/all-nodes.cc",
            "${srcPath}/v8_7_5/src/compiler/basic-block-instrumentor.cc",
            "${srcPath}/v8_7_5/src/compiler/branch-elimination.cc",
            "${srcPath}/v8_7_5/src/compiler/bytecode-analysis.cc",
            "${srcPath}/v8_7_5/src/compiler/bytecode-graph-builder.cc",
            "${srcPath}/v8_7_5/src/compiler/bytecode-liveness-map.cc",
            "${srcPath}/v8_7_5/src/compiler/checkpoint-elimination.cc",
            "${srcPath}/v8_7_5/src/compiler/c-linkage.cc",
            "${srcPath}/v8_7_5/src/compiler/code-assembler.cc",
            "${srcPath}/v8_7_5/src/compiler/common-node-cache.cc",
            "${srcPath}/v8_7_5/src/compiler/common-operator.cc",
            "${srcPath}/v8_7_5/src/compiler/common-operator-reducer.cc",
            "${srcPath}/v8_7_5/src/compiler/compilation-dependencies.cc",
            "${srcPath}/v8_7_5/src/compiler/compiler-source-position-table.cc",
            "${srcPath}/v8_7_5/src/compiler/constant-folding-reducer.cc",
            "${srcPath}/v8_7_5/src/compiler/control-equivalence.cc",
            "${srcPath}/v8_7_5/src/compiler/control-flow-optimizer.cc",
            "${srcPath}/v8_7_5/src/compiler/dead-code-elimination.cc",
            "${srcPath}/v8_7_5/src/compiler/effect-control-linearizer.cc",
            "${srcPath}/v8_7_5/src/compiler/escape-analysis.cc",
            "${srcPath}/v8_7_5/src/compiler/escape-analysis-reducer.cc",
            "${srcPath}/v8_7_5/src/compiler/frame.cc",
            "${srcPath}/v8_7_5/src/compiler/frame-states.cc",
            "${srcPath}/v8_7_5/src/compiler/graph.cc",
            "${srcPath}/v8_7_5/src/compiler/graph-assembler.cc",
            "${srcPath}/v8_7_5/src/compiler/graph-reducer.cc",
            "${srcPath}/v8_7_5/src/compiler/graph-trimmer.cc",
            "${srcPath}/v8_7_5/src/compiler/graph-visualizer.cc",
            "${srcPath}/v8_7_5/src/compiler/int64-lowering.cc",
            "${srcPath}/v8_7_5/src/compiler/js-call-reducer.cc",
            "${srcPath}/v8_7_5/src/compiler/js-context-specialization.cc",
            "${srcPath}/v8_7_5/src/compiler/js-create-lowering.cc",
            "${srcPath}/v8_7_5/src/compiler/js-generic-lowering.cc",
            "${srcPath}/v8_7_5/src/compiler/js-graph.cc",
            "${srcPath}/v8_7_5/src/compiler/js-heap-broker.cc",
            "${srcPath}/v8_7_5/src/compiler/js-heap-copy-reducer.cc",
            "${srcPath}/v8_7_5/src/compiler/js-inlining.cc",
            "${srcPath}/v8_7_5/src/compiler/js-inlining-heuristic.cc",
            "${srcPath}/v8_7_5/src/compiler/js-intrinsic-lowering.cc",
            "${srcPath}/v8_7_5/src/compiler/js-native-context-specialization.cc",
            "${srcPath}/v8_7_5/src/compiler/js-operator.cc",
            "${srcPath}/v8_7_5/src/compiler/js-typed-lowering.cc",
            "${srcPath}/v8_7_5/src/compiler/js-type-hint-lowering.cc",
            "${srcPath}/v8_7_5/src/compiler/linkage.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/ia32/instruction-scheduler-ia32.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/ia32/instruction-selector-ia32.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/ia32/code-generator-ia32.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/instruction-scheduler.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/instruction-selector.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/jump-threading.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/live-range-separator.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/move-optimizer.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/register-allocator.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/register-allocator-verifier.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/code-generator.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/frame-elider.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/gap-resolver.cc",
            "${srcPath}/v8_7_5/src/compiler/backend/instruction.cc",
            "${srcPath}/v8_7_5/src/compiler-dispatcher/optimizing-compile-dispatcher.cc",
            "${srcPath}/v8_7_5/src/compiler-dispatcher/compiler-dispatcher.cc",
            "${srcPath}/v8_7_5/src/debug/debug-coverage.cc",
            "${srcPath}/v8_7_5/src/debug/debug-evaluate.cc",
            "${srcPath}/v8_7_5/src/debug/debug-frames.cc",
            "${srcPath}/v8_7_5/src/debug/debug-property-iterator.cc",
            "${srcPath}/v8_7_5/src/debug/debug-scope-iterator.cc",
            "${srcPath}/v8_7_5/src/debug/debug-scopes.cc",
            "${srcPath}/v8_7_5/src/debug/debug-stack-trace-iterator.cc",
            "${srcPath}/v8_7_5/src/debug/debug-type-profile.cc",
            "${srcPath}/v8_7_5/src/debug/debug.cc",
            "${srcPath}/v8_7_5/src/debug/ia32/debug-ia32.cc",
            "${srcPath}/v8_7_5/src/extensions/free-buffer-extension.cc",
            "${srcPath}/v8_7_5/src/extensions/gc-extension.cc",
            "${srcPath}/v8_7_5/src/extensions/ignition-statistics-extension.cc",
            "${srcPath}/v8_7_5/src/extensions/statistics-extension.cc",
            "${srcPath}/v8_7_5/src/extensions/trigger-failure-extension.cc",
            "${srcPath}/v8_7_5/src/extensions/externalize-string-extension.cc",
            "${srcPath}/v8_7_5/src/heap/code-stats.cc",
            "${srcPath}/v8_7_5/src/heap/concurrent-marking.cc",
            "${srcPath}/v8_7_5/src/heap/embedder-tracing.cc",
            "${srcPath}/v8_7_5/src/heap/factory.cc",
            "${srcPath}/v8_7_5/src/heap/gc-idle-time-handler.cc",
            "${srcPath}/v8_7_5/src/heap/gc-tracer.cc",
            "${srcPath}/v8_7_5/src/heap/heap.cc",
            "${srcPath}/v8_7_5/src/heap/heap-controller.cc",
            "${srcPath}/v8_7_5/src/heap/incremental-marking.cc",
            "${srcPath}/v8_7_5/src/heap/incremental-marking-job.cc",
            "${srcPath}/v8_7_5/src/heap/invalidated-slots.cc",
            "${srcPath}/v8_7_5/src/heap/item-parallel-job.cc",
            "${srcPath}/v8_7_5/src/heap/mark-compact.cc",
            "${srcPath}/v8_7_5/src/heap/marking.cc",
            "${srcPath}/v8_7_5/src/heap/memory-reducer.cc",
            "${srcPath}/v8_7_5/src/heap/object-stats.cc",
            "${srcPath}/v8_7_5/src/heap/objects-visiting.cc",
            "${srcPath}/v8_7_5/src/heap/read-only-heap.cc",
            "${srcPath}/v8_7_5/src/heap/scavenge-job.cc",
            "${srcPath}/v8_7_5/src/heap/scavenger.cc",
            "${srcPath}/v8_7_5/src/heap/setup-heap-internal.cc",
            "${srcPath}/v8_7_5/src/heap/slot-set.cc",
            "${srcPath}/v8_7_5/src/heap/spaces.cc",
            "${srcPath}/v8_7_5/src/heap/store-buffer.cc",
            "${srcPath}/v8_7_5/src/heap/stress-marking-observer.cc",
            "${srcPath}/v8_7_5/src/heap/stress-scavenge-observer.cc",
            "${srcPath}/v8_7_5/src/heap/sweeper.cc",
            "${srcPath}/v8_7_5/src/heap/array-buffer-collector.cc",
            "${srcPath}/v8_7_5/src/heap/array-buffer-tracker.cc",
            "${srcPath}/v8_7_5/src/ia32/cpu-ia32.cc",
            "${srcPath}/v8_7_5/src/ia32/deoptimizer-ia32.cc",
            "${srcPath}/v8_7_5/src/ia32/disasm-ia32.cc",
            "${srcPath}/v8_7_5/src/ia32/frame-constants-ia32.cc",
            "${srcPath}/v8_7_5/src/ia32/interface-descriptors-ia32.cc",
            "${srcPath}/v8_7_5/src/ia32/macro-assembler-ia32.cc",
            "${srcPath}/v8_7_5/src/ia32/assembler-ia32.cc",
            "${srcPath}/v8_7_5/src/ic/call-optimization.cc",
            "${srcPath}/v8_7_5/src/ic/handler-configuration.cc",
            "${srcPath}/v8_7_5/src/ic/ic.cc",
            "${srcPath}/v8_7_5/src/ic/ic-stats.cc",
            "${srcPath}/v8_7_5/src/ic/keyed-store-generic.cc",
            "${srcPath}/v8_7_5/src/ic/stub-cache.cc",
            "${srcPath}/v8_7_5/src/ic/accessor-assembler.cc",
            "${srcPath}/v8_7_5/src/ic/binary-op-assembler.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-runtime-agent-impl.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-schema-agent-impl.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-stack-trace-impl.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-value-utils.cc",
            "${srcPath}/v8_7_5/src/inspector/value-mirror.cc",
            "${srcPath}/v8_7_5/src/inspector/wasm-translation.cc",
            "${srcPath}/v8_7_5/src/inspector/custom-preview.cc",
            "${srcPath}/v8_7_5/src/inspector/injected-script.cc",
            "${srcPath}/v8_7_5/src/inspector/inspected-context.cc",
            "${srcPath}/v8_7_5/src/inspector/remote-object-id.cc",
            "${srcPath}/v8_7_5/src/inspector/search-util.cc",
            "${srcPath}/v8_7_5/src/inspector/string-16.cc",
            "${srcPath}/v8_7_5/src/inspector/string-util.cc",
            "${srcPath}/v8_7_5/src/inspector/test-interface.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-console.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-console-agent-impl.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-console-message.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-debugger.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-debugger-agent-impl.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-debugger-script.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-heap-profiler-agent-impl.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-inspector-impl.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-inspector-session-impl.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-profiler-agent-impl.cc",
            "${srcPath}/v8_7_5/src/inspector/v8-regex.cc",
            "${srcPath}/v8_7_5/src/interpreter/interpreter-intrinsics.cc",
            "${srcPath}/v8_7_5/src/interpreter/interpreter-intrinsics-generator.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-array-accessor.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-array-builder.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-array-iterator.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-array-random-iterator.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-array-writer.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-decoder.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-flags.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-generator.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-label.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-node.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-operands.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-register.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-register-optimizer.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecodes.cc",
            "${srcPath}/v8_7_5/src/interpreter/bytecode-source-info.cc",
            "${srcPath}/v8_7_5/src/interpreter/constant-array-builder.cc",
            "${srcPath}/v8_7_5/src/interpreter/control-flow-builders.cc",
            "${srcPath}/v8_7_5/src/interpreter/handler-table-builder.cc",
            "${srcPath}/v8_7_5/src/interpreter/interpreter.cc",
            "${srcPath}/v8_7_5/src/interpreter/interpreter-assembler.cc",
            "${srcPath}/v8_7_5/src/interpreter/interpreter-generator.cc",
            "${srcPath}/v8_7_5/src/libplatform/default-worker-threads-task-runner.cc",
            "${srcPath}/v8_7_5/src/libplatform/delayed-task-queue.cc",
            "${srcPath}/v8_7_5/src/libplatform/task-queue.cc",
            "${srcPath}/v8_7_5/src/libplatform/worker-thread.cc",
            "${srcPath}/v8_7_5/src/libplatform/default_platform_wrap.cc",
            "${srcPath}/v8_7_5/src/libplatform/default-foreground-task-runner.cc",
            "${srcPath}/v8_7_5/src/libplatform/default-platform.cc",
            "${srcPath}/v8_7_5/src/libplatform/tracing/trace-config.cc",
            "${srcPath}/v8_7_5/src/libplatform/tracing/trace-object.cc",
            "${srcPath}/v8_7_5/src/libplatform/tracing/trace-writer.cc",
            "${srcPath}/v8_7_5/src/libplatform/tracing/tracing-controller.cc",
            "${srcPath}/v8_7_5/src/libplatform/tracing/trace-buffer.cc",
            "${srcPath}/v8_7_5/src/libsampler/sampler.cc",
            "${srcPath}/v8_7_5/src/objects/literal-objects.cc",
        ],
        // 
        "cmd":[
            "--target=x86_64-linux-guneabi", 
            "-std=c++14",
            "-fms-extensions",
            //"-fshort-wchar",
            "-D_GLIBCXX17_INLINE=inline",
            "-D_GNU_SOURCE",
            "-DUSE_AURA",
            "-DOS_LINUX_FOR_WIN",
            "-DINSIDE_BLINK",
            "-DBLINK_IMPLEMENTATION",
            "-DSK_SUPPORT_LEGACY_CREATESHADER_PTR",
            "-DENABLE_WKE",
            "-D_HAS_CONSTEXPR=0",
            "-D_CRT_SECURE_NO_WARNINGS",
            "-DSUPPORT_XP_CODE=1",
            "-DV8_TARGET_ARCH_X64",
            "-DV8_EMBEDDED_BUILTINS=1",
            "-DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=0",
            "-DV8_PROMISE_INTERNAL_FIELD_COUNT=1",
            "-DDISABLE_UNTRUSTED_CODE_MITIGATIONS",
            "-DICU_UTIL_DATA_IMPL=ICU_UTIL_DATA_SHARED",
            "-DUCONFIG_NO_SERVICE=1",
            "-DUCONFIG_NO_REGULAR_EXPRESSIONS=1",
            "-DU_ENABLE_DYLOAD=0",
            "-DU_STATIC_IMPLEMENTATION=1",
            "-DU_HAVE_STD_STRING=1",
            "-DUCONFIG_NO_BREAK_ITERATION=0",
            "-D_CRT_SECURE_NO_DEPRECATE",
            "-D_CRT_NONSTDC_NO_DEPRECATE",
            "-DV8_NO_FAST_TLS",
            "-DV8_DEPRECATION_WARNINGS",
            "-DBUILDING_V8_SHARED=1"
        ],
        "objdir":"${srcPath}/out/tmp/v8_7_5/${targetDir}",
        "outdir":"${srcPath}/out/${targetDir}",
                
        "target":"libv8_7_5_1.a",
        "beginLibs":[
        ],
        "linkerCmd":[],
        "endLibs":[
        ],
        "linker":"${ndkBinPath}/ar.exe"
    }
}];

buildCommonSetting(json);
