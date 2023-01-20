// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_TRAP_HANDLER_HANDLER_INSIDE_POSIX_H_
#define V8_TRAP_HANDLER_HANDLER_INSIDE_POSIX_H_

#include <signal.h>
#include "include/v8config.h"

namespace v8 {
namespace internal {
<<<<<<< HEAD
    namespace trap_handler {

#if V8_OS_LINUX
        constexpr int kOobSignal = SIGSEGV;
#elif V8_OS_MACOSX
        constexpr int kOobSignal = SIGBUS;
=======
namespace trap_handler {

#if V8_OS_LINUX
constexpr int kOobSignal = SIGSEGV;
#elif V8_OS_MACOSX
constexpr int kOobSignal = SIGBUS;
>>>>>>> miniblink49
#else
#error Posix trap handlers are only supported on Linux and MacOSX.
#endif

<<<<<<< HEAD
        void HandleSignal(int signum, siginfo_t* info, void* context);

        bool TryHandleSignal(int signum, siginfo_t* info, void* context);

    } // namespace trap_handler
} // namespace internal
} // namespace v8

#endif // V8_TRAP_HANDLER_HANDLER_INSIDE_POSIX_H_
=======
void HandleSignal(int signum, siginfo_t* info, void* context);

bool TryHandleSignal(int signum, siginfo_t* info, void* context);

}  // namespace trap_handler
}  // namespace internal
}  // namespace v8

#endif  // V8_TRAP_HANDLER_HANDLER_INSIDE_POSIX_H_
>>>>>>> miniblink49
