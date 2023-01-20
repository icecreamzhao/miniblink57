// Copyright 2017 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_BASE_TSAN_H_
#define V8_BASE_TSAN_H_

namespace v8 {
namespace base {

<<<<<<< HEAD
    // This file contains annotations for ThreadSanitizer (TSan), a race detector.
    // See
    // https://llvm.org/svn/llvm-project/compiler-rt/trunk/lib/tsan/rtl/tsan_interface_ann.cc
=======
// This file contains annotations for ThreadSanitizer (TSan), a race detector.
// See
// https://llvm.org/svn/llvm-project/compiler-rt/trunk/lib/tsan/rtl/tsan_interface_ann.cc
>>>>>>> miniblink49

#if THREAD_SANITIZER

#define TSAN_ANNOTATE_IGNORE_READS_BEGIN \
<<<<<<< HEAD
    v8::base::AnnotateIgnoreReadsBegin(__FILE__, __LINE__)
#define TSAN_ANNOTATE_IGNORE_READS_END \
    v8::base::AnnotateIgnoreReadsEnd(__FILE__, __LINE__)
#define TSAN_ANNOTATE_IGNORE_WRITES_BEGIN \
    v8::base::AnnotateIgnoreWritesBegin(__FILE__, __LINE__)
#define TSAN_ANNOTATE_IGNORE_WRITES_END \
    v8::base::AnnotateIgnoreWritesEnd(__FILE__, __LINE__)

    extern "C" {

    void AnnotateIgnoreReadsBegin(const char* file, int line);
    void AnnotateIgnoreReadsEnd(const char* file, int line);
    void AnnotateIgnoreWritesBegin(const char* file, int line);
    void AnnotateIgnoreWritesEnd(const char* file, int line);

    } // extern "C"
=======
  v8::base::AnnotateIgnoreReadsBegin(__FILE__, __LINE__)
#define TSAN_ANNOTATE_IGNORE_READS_END \
  v8::base::AnnotateIgnoreReadsEnd(__FILE__, __LINE__)
#define TSAN_ANNOTATE_IGNORE_WRITES_BEGIN \
  v8::base::AnnotateIgnoreWritesBegin(__FILE__, __LINE__)
#define TSAN_ANNOTATE_IGNORE_WRITES_END \
  v8::base::AnnotateIgnoreWritesEnd(__FILE__, __LINE__)

extern "C" {

void AnnotateIgnoreReadsBegin(const char* file, int line);
void AnnotateIgnoreReadsEnd(const char* file, int line);
void AnnotateIgnoreWritesBegin(const char* file, int line);
void AnnotateIgnoreWritesEnd(const char* file, int line);

}  // extern "C"
>>>>>>> miniblink49

#else

#define TSAN_ANNOTATE_IGNORE_READS_BEGIN ((void)0)
#define TSAN_ANNOTATE_IGNORE_READS_END ((void)0)
#define TSAN_ANNOTATE_IGNORE_WRITES_BEGIN ((void)0)
#define TSAN_ANNOTATE_IGNORE_WRITES_END ((void)0)

#endif

<<<<<<< HEAD
} // namespace base
} // namespace v8

#endif // V8_BASE_TSAN_H_
=======
}  // namespace base
}  // namespace v8

#endif  // V8_BASE_TSAN_H_
>>>>>>> miniblink49
