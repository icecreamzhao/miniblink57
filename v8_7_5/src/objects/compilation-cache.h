// Copyright 2017 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_OBJECTS_COMPILATION_CACHE_H_
#define V8_OBJECTS_COMPILATION_CACHE_H_

#include "src/objects/feedback-cell.h"
#include "src/objects/hash-table.h"
#include "src/objects/js-regexp.h"
#include "src/objects/shared-function-info.h"
#include "src/roots.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"

namespace v8 {
namespace internal {

    class CompilationCacheShape : public BaseShape<HashTableKey*> {
    public:
        static inline bool IsMatch(HashTableKey* key, Object value)
        {
            return key->IsMatch(value);
        }

        static inline uint32_t Hash(Isolate* isolate, HashTableKey* key)
        {
            return key->Hash();
        }

        static inline uint32_t RegExpHash(String string, Smi flags);

        static inline uint32_t StringSharedHash(String source,
            SharedFunctionInfo shared,
            LanguageMode language_mode,
            int position);

        static inline uint32_t HashForObject(ReadOnlyRoots roots, Object object);

        static const int kPrefixSize = 0;
        static const int kEntrySize = 3;
    };

    class InfoCellPair {
    public:
        InfoCellPair() { }
        inline InfoCellPair(SharedFunctionInfo shared, FeedbackCell feedback_cell);

        FeedbackCell feedback_cell() const
        {
            DCHECK(is_compiled_scope_.is_compiled());
            return feedback_cell_;
        }
        SharedFunctionInfo shared() const
        {
            DCHECK(is_compiled_scope_.is_compiled());
            return shared_;
        }

        bool has_feedback_cell() const
        {
            return !feedback_cell_.is_null() && is_compiled_scope_.is_compiled();
        }
        bool has_shared() const
        {
            // Only return true if SFI is compiled - the bytecode could have been
            // flushed while it's in the compilation cache, and not yet have been
            // removed form the compilation cache.
            return !shared_.is_null() && is_compiled_scope_.is_compiled();
        }

    private:
        IsCompiledScope is_compiled_scope_;
        SharedFunctionInfo shared_;
        FeedbackCell feedback_cell_;
    };

    // This cache is used in two different variants. For regexp caching, it simply
    // maps identifying info of the regexp to the cached regexp object. Scripts and
    // eval code only gets cached after a second probe for the code object. To do
    // so, on first "put" only a hash identifying the source is entered into the
    // cache, mapping it to a lifetime count of the hash. On each call to Age all
    // such lifetimes get reduced, and removed once they reach zero. If a second put
    // is called while such a hash is live in the cache, the hash gets replaced by
    // an actual cache entry. Age also removes stale live entries from the cache.
    // Such entries are identified by SharedFunctionInfos pointing to either the
    // recompilation stub, or to "old" code. This avoids memory leaks due to
    // premature caching of scripts and eval strings that are never needed later.
    class CompilationCacheTable
        : public HashTable<CompilationCacheTable, CompilationCacheShape> {
    public:
        NEVER_READ_ONLY_SPACE
        static MaybeHandle<SharedFunctionInfo> LookupScript(
            Handle<CompilationCacheTable> table, Handle<String> src,
            Handle<Context> native_context, LanguageMode language_mode);
        static InfoCellPair LookupEval(Handle<CompilationCacheTable> table,
            Handle<String> src,
            Handle<SharedFunctionInfo> shared,
            Handle<Context> native_context,
            LanguageMode language_mode, int position);
        Handle<Object> LookupRegExp(Handle<String> source, JSRegExp::Flags flags);
        static Handle<CompilationCacheTable> PutScript(
            Handle<CompilationCacheTable> cache, Handle<String> src,
            Handle<Context> native_context, LanguageMode language_mode,
            Handle<SharedFunctionInfo> value);
        static Handle<CompilationCacheTable> PutEval(
            Handle<CompilationCacheTable> cache, Handle<String> src,
            Handle<SharedFunctionInfo> outer_info, Handle<SharedFunctionInfo> value,
            Handle<Context> native_context, Handle<FeedbackCell> feedback_cell,
            int position);
        static Handle<CompilationCacheTable> PutRegExp(
            Isolate* isolate, Handle<CompilationCacheTable> cache, Handle<String> src,
            JSRegExp::Flags flags, Handle<FixedArray> value);
        void Remove(Object value);
        void Age();
        static const int kHashGenerations = 10;

        DECL_CAST(CompilationCacheTable)

    private:
        OBJECT_CONSTRUCTORS(CompilationCacheTable,
            HashTable<CompilationCacheTable, CompilationCacheShape>);
    };

} // namespace internal
} // namespace v8

#include "src/objects/object-macros-undef.h"

#endif // V8_OBJECTS_COMPILATION_CACHE_H_
