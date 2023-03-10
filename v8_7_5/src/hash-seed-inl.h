// Copyright 2019 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_HASH_SEED_INL_H_
#define V8_HASH_SEED_INL_H_

#include <stdint.h>

// The #includes below currently lead to cyclic transitive includes, so
// HashSeed() ends up being required before it is defined, so we have to
// declare it here. This is a workaround; if we needed this permanently then
// we should put that line into a "hash-seed.h" header; but we won't need
// it for long.
// TODO(jkummerow): Get rid of this by breaking circular include dependencies.
namespace v8 {
namespace internal {

    class Isolate;
    class ReadOnlyRoots;

    // TODO(v8:7464): Remove the Isolate version of this.
    inline uint64_t HashSeed(Isolate* isolate);
    inline uint64_t HashSeed(ReadOnlyRoots roots);

} // namespace internal
} // namespace v8

// See comment above for why this isn't at the top of the file.
#include "src/objects/fixed-array-inl.h"
#include "src/roots-inl.h"

namespace v8 {
namespace internal {

    inline uint64_t HashSeed(Isolate* isolate)
    {
        return HashSeed(ReadOnlyRoots(isolate));
    }

    inline uint64_t HashSeed(ReadOnlyRoots roots)
    {
        uint64_t seed;
        roots.hash_seed()->copy_out(0, reinterpret_cast<byte*>(&seed), kInt64Size);
        DCHECK(FLAG_randomize_hashes || seed == 0);
        return seed;
    }

} // namespace internal
} // namespace v8

#endif // V8_HASH_SEED_INL_H_
