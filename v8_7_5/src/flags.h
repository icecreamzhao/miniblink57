// Copyright 2006-2008 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_FLAGS_H_
#define V8_FLAGS_H_

#include <vector>

#include "src/globals.h"
#include "src/wasm/wasm-limits.h"

namespace v8 {
namespace internal {

// Declare all of our flags.
#define FLAG_MODE_DECLARE
#include "src/flag-definitions.h" // NOLINT

    // The global list of all flags.
    class V8_EXPORT_PRIVATE FlagList {
    public:
        // The list of all flags with a value different from the default
        // and their values. The format of the list is like the format of the
        // argv array passed to the main function, e.g.
        // ("--prof", "--log-file", "v8.prof", "--nolazy").
        //
        // The caller is responsible for disposing the list, as well
        // as every element of it.
        static std::vector<const char*>* argv();

        // Set the flag values by parsing the command line. If remove_flags is
        // set, the recognized flags and associated values are removed from (argc,
        // argv) and only unknown arguments remain. Returns 0 if no error occurred.
        // Otherwise, returns the argv index > 0 for the argument where an error
        // occurred. In that case, (argc, argv) will remain unchanged independent of
        // the remove_flags value, and no assumptions about flag settings should be
        // made.
        //
        // The following syntax for flags is accepted (both '-' and '--' are ok):
        //
        //   --flag        (bool flags only)
        //   --no-flag     (bool flags only)
        //   --flag=value  (non-bool flags only, no spaces around '=')
        //   --flag value  (non-bool flags only)
        //   --            (capture all remaining args in JavaScript)
        static int SetFlagsFromCommandLine(int* argc,
            char** argv,
            bool remove_flags);

        // Set the flag values by parsing the string str. Splits string into argc
        // substrings argv[], each of which consisting of non-white-space chars,
        // and then calls SetFlagsFromCommandLine() and returns its result.
        static int SetFlagsFromString(const char* str, int len);

        // Reset all flags to their default value.
        static void ResetAllFlags();

        // Print help to stdout with flags, types, and default values.
        static void PrintHelp();

        // Set flags as consequence of being implied by another flag.
        static void EnforceFlagImplications();

        // Hash of flags (to quickly determine mismatching flag expectations).
        // This hash is calculated during V8::Initialize and cached.
        static uint32_t Hash();
    };

} // namespace internal
} // namespace v8

#endif // V8_FLAGS_H_
