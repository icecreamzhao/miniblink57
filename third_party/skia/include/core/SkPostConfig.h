/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
// IWYU pragma: private, include "SkTypes.h"

#ifndef SkPostConfig_DEFINED
#define SkPostConfig_DEFINED

#if defined(SK_BUILD_FOR_WIN32)
#define SK_BUILD_FOR_WIN
#endif

#if defined(SK_DEBUG) && defined(SK_RELEASE)
#error "cannot define both SK_DEBUG and SK_RELEASE"
#elif !defined(SK_DEBUG) && !defined(SK_RELEASE)
#error "must define either SK_DEBUG or SK_RELEASE"
#endif

#if defined(SK_SUPPORT_UNITTEST) && !defined(SK_DEBUG)
#error "can't have unittests without debug"
=======
#ifndef SkPostConfig_DEFINED
#define SkPostConfig_DEFINED

#if defined(SK_BUILD_FOR_WIN32) || defined(SK_BUILD_FOR_WINCE)
#  define SK_BUILD_FOR_WIN
#endif

#if defined(SK_DEBUG) && defined(SK_RELEASE)
#  error "cannot define both SK_DEBUG and SK_RELEASE"
#elif !defined(SK_DEBUG) && !defined(SK_RELEASE)
#  error "must define either SK_DEBUG or SK_RELEASE"
#endif

#if defined(SK_SUPPORT_UNITTEST) && !defined(SK_DEBUG)
#  error "can't have unittests without debug"
>>>>>>> miniblink49
#endif

/**
 * Matrix calculations may be float or double.
 * The default is float, as that's what Chromium's using.
 */
#if defined(SK_MSCALAR_IS_DOUBLE) && defined(SK_MSCALAR_IS_FLOAT)
<<<<<<< HEAD
#error "cannot define both SK_MSCALAR_IS_DOUBLE and SK_MSCALAR_IS_FLOAT"
#elif !defined(SK_MSCALAR_IS_DOUBLE) && !defined(SK_MSCALAR_IS_FLOAT)
#define SK_MSCALAR_IS_FLOAT
#endif

#if defined(SK_CPU_LENDIAN) && defined(SK_CPU_BENDIAN)
#error "cannot define both SK_CPU_LENDIAN and SK_CPU_BENDIAN"
#elif !defined(SK_CPU_LENDIAN) && !defined(SK_CPU_BENDIAN)
#error "must define either SK_CPU_LENDIAN or SK_CPU_BENDIAN"
=======
#  error "cannot define both SK_MSCALAR_IS_DOUBLE and SK_MSCALAR_IS_FLOAT"
#elif !defined(SK_MSCALAR_IS_DOUBLE) && !defined(SK_MSCALAR_IS_FLOAT)
#  define SK_MSCALAR_IS_FLOAT
#endif

#if defined(SK_CPU_LENDIAN) && defined(SK_CPU_BENDIAN)
#  error "cannot define both SK_CPU_LENDIAN and SK_CPU_BENDIAN"
#elif !defined(SK_CPU_LENDIAN) && !defined(SK_CPU_BENDIAN)
#  error "must define either SK_CPU_LENDIAN or SK_CPU_BENDIAN"
>>>>>>> miniblink49
#endif

/**
 * Ensure the port has defined all of SK_X32_SHIFT, or none of them.
 */
#ifdef SK_A32_SHIFT
<<<<<<< HEAD
#if !defined(SK_R32_SHIFT) || !defined(SK_G32_SHIFT) || !defined(SK_B32_SHIFT)
#error "all or none of the 32bit SHIFT amounts must be defined"
#endif
#else
#if defined(SK_R32_SHIFT) || defined(SK_G32_SHIFT) || defined(SK_B32_SHIFT)
#error "all or none of the 32bit SHIFT amounts must be defined"
#endif
#endif

#if !defined(SK_HAS_COMPILER_FEATURE)
#if defined(__has_feature)
#define SK_HAS_COMPILER_FEATURE(x) __has_feature(x)
#else
#define SK_HAS_COMPILER_FEATURE(x) 0
#endif
#endif

#if !defined(SK_ATTRIBUTE)
#if defined(__clang__) || defined(__GNUC__)
#define SK_ATTRIBUTE(attr) __attribute__((attr))
#else
#define SK_ATTRIBUTE(attr)
#endif
=======
#  if !defined(SK_R32_SHIFT) || !defined(SK_G32_SHIFT) || !defined(SK_B32_SHIFT)
#    error "all or none of the 32bit SHIFT amounts must be defined"
#  endif
#else
#  if defined(SK_R32_SHIFT) || defined(SK_G32_SHIFT) || defined(SK_B32_SHIFT)
#    error "all or none of the 32bit SHIFT amounts must be defined"
#  endif
#endif

#if !defined(SK_HAS_COMPILER_FEATURE)
#  if defined(__has_feature)
#    define SK_HAS_COMPILER_FEATURE(x) __has_feature(x)
#  else
#    define SK_HAS_COMPILER_FEATURE(x) 0
#  endif
#endif

#if !defined(SK_ATTRIBUTE)
#  if defined(__clang__) || defined(__GNUC__)
#    define SK_ATTRIBUTE(attr) __attribute__((attr))
#  else
#    define SK_ATTRIBUTE(attr)
#  endif
>>>>>>> miniblink49
#endif

// As usual, there are two ways to increase alignment... the MSVC way and the everyone-else way.
#ifndef SK_STRUCT_ALIGN
<<<<<<< HEAD
#ifdef _MSC_VER
#define SK_STRUCT_ALIGN(N) __declspec(align(N))
#else
#define SK_STRUCT_ALIGN(N) __attribute__((aligned(N)))
#endif
#endif

#if !defined(SK_SUPPORT_GPU)
#define SK_SUPPORT_GPU 0 // weolar
=======
    #ifdef _MSC_VER
        #define SK_STRUCT_ALIGN(N) __declspec(align(N))
    #else
        #define SK_STRUCT_ALIGN(N) __attribute__((aligned(N)))
    #endif
#endif

#if !defined(SK_SUPPORT_GPU)
#  define SK_SUPPORT_GPU 0
>>>>>>> miniblink49
#endif

/**
 * The clang static analyzer likes to know that when the program is not
 * expected to continue (crash, assertion failure, etc). It will notice that
 * some combination of parameters lead to a function call that does not return.
 * It can then make appropriate assumptions about the parameters in code
 * executed only if the non-returning function was *not* called.
 */
#if !defined(SkNO_RETURN_HINT)
<<<<<<< HEAD
#if SK_HAS_COMPILER_FEATURE(attribute_analyzer_noreturn)
static inline void SkNO_RETURN_HINT() __attribute__((analyzer_noreturn));
static inline void SkNO_RETURN_HINT() { }
#else
#define SkNO_RETURN_HINT() \
    do {                   \
    } while (false)
#endif
=======
#  if SK_HAS_COMPILER_FEATURE(attribute_analyzer_noreturn)
     static inline void SkNO_RETURN_HINT() __attribute__((analyzer_noreturn));
     static inline void SkNO_RETURN_HINT() {}
#  else
#    define SkNO_RETURN_HINT() do {} while (false)
#  endif
>>>>>>> miniblink49
#endif

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
// TODO(mdempsky): Move elsewhere as appropriate.
#include <new>
=======
#ifndef SkNEW
#  define SkNEW(type_name)                           (new type_name)
#  define SkNEW_ARGS(type_name, args)                (new type_name args)
#  define SkNEW_ARRAY(type_name, count)              (new type_name[(count)])
#  define SkNEW_PLACEMENT(buf, type_name)            (new (buf) type_name)
#  define SkNEW_PLACEMENT_ARGS(buf, type_name, args) (new (buf) type_name args)
#  define SkDELETE(obj)                              (delete (obj))
#  define SkDELETE_ARRAY(array)                      (delete[] (array))
#endif

#ifndef SK_CRASH
#  ifdef SK_BUILD_FOR_WIN
#    define SK_CRASH() __debugbreak()
#  else
#    if 1   // set to 0 for infinite loop, which can help connecting gdb
#      define SK_CRASH() do { SkNO_RETURN_HINT(); *(int *)(uintptr_t)0xbbadbeef = 0; } while (false)
#    else
#      define SK_CRASH() do { SkNO_RETURN_HINT(); } while (true)
#    endif
#  endif
#endif
>>>>>>> miniblink49

///////////////////////////////////////////////////////////////////////////////

#ifdef SK_BUILD_FOR_WIN
<<<<<<< HEAD
#ifndef SK_A32_SHIFT
#define SK_A32_SHIFT 24
#define SK_R32_SHIFT 16
#define SK_G32_SHIFT 8
#define SK_B32_SHIFT 0
#endif
#
#endif

#if defined(GOOGLE3)
void SkDebugfForDumpStackTrace(const char* data, void* unused);
void DumpStackTrace(int skip_count, void w(const char*, void*), void* arg);
#define SK_DUMP_GOOGLE3_STACK() DumpStackTrace(0, SkDebugfForDumpStackTrace, nullptr)
#else
#define SK_DUMP_GOOGLE3_STACK()
#endif

#ifndef SK_ABORT
#define SK_ABORT(msg)                                                       \
    do {                                                                    \
        SkNO_RETURN_HINT();                                                 \
        SkDebugf("%s:%d: fatal error: \"%s\"\n", __FILE__, __LINE__, #msg); \
        SK_DUMP_GOOGLE3_STACK();                                            \
        sk_abort_no_print();                                                \
    } while (false)
=======
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#    define WIN32_IS_MEAN_WAS_LOCALLY_DEFINED
#  endif
#  ifndef NOMINMAX
#    define NOMINMAX
#    define NOMINMAX_WAS_LOCALLY_DEFINED
#  endif
#
#  include <windows.h>
#
#  ifdef WIN32_IS_MEAN_WAS_LOCALLY_DEFINED
#    undef WIN32_IS_MEAN_WAS_LOCALLY_DEFINED
#    undef WIN32_LEAN_AND_MEAN
#  endif
#  ifdef NOMINMAX_WAS_LOCALLY_DEFINED
#    undef NOMINMAX_WAS_LOCALLY_DEFINED
#    undef NOMINMAX
#  endif
#
#  ifndef SK_A32_SHIFT
#    define SK_A32_SHIFT 24
#    define SK_R32_SHIFT 16
#    define SK_G32_SHIFT 8
#    define SK_B32_SHIFT 0
#  endif
#
#endif

#ifndef SK_ALWAYSBREAK
#  ifdef SK_DEBUG
#    define SK_ALWAYSBREAK(cond) do { \
              if (cond) break; \
              SkNO_RETURN_HINT(); \
              SkDebugf("%s:%d: failed assertion \"%s\"\n", __FILE__, __LINE__, #cond); \
              SK_CRASH(); \
        } while (false)
#  else
#    define SK_ALWAYSBREAK(cond) do { if (cond) break; SK_CRASH(); } while (false)
#  endif
>>>>>>> miniblink49
#endif

/**
 *  We check to see if the SHIFT value has already been defined.
 *  if not, we define it ourself to some default values. We default to OpenGL
 *  order (in memory: r,g,b,a)
 */
#ifndef SK_A32_SHIFT
<<<<<<< HEAD
#ifdef SK_CPU_BENDIAN
#define SK_R32_SHIFT 24
#define SK_G32_SHIFT 16
#define SK_B32_SHIFT 8
#define SK_A32_SHIFT 0
#else
#define SK_R32_SHIFT 0
#define SK_G32_SHIFT 8
#define SK_B32_SHIFT 16
#define SK_A32_SHIFT 24
#endif
=======
#  ifdef SK_CPU_BENDIAN
#    define SK_R32_SHIFT    24
#    define SK_G32_SHIFT    16
#    define SK_B32_SHIFT    8
#    define SK_A32_SHIFT    0
#  else
#    define SK_R32_SHIFT    0
#    define SK_G32_SHIFT    8
#    define SK_B32_SHIFT    16
#    define SK_A32_SHIFT    24
#  endif
>>>>>>> miniblink49
#endif

/**
 * SkColor has well defined shift values, but SkPMColor is configurable. This
 * macro is a convenience that returns true if the shift values are equal while
 * ignoring the machine's endianness.
 */
#define SK_COLOR_MATCHES_PMCOLOR_BYTE_ORDER \
    (SK_A32_SHIFT == 24 && SK_R32_SHIFT == 16 && SK_G32_SHIFT == 8 && SK_B32_SHIFT == 0)

/**
 * SK_PMCOLOR_BYTE_ORDER can be used to query the byte order of SkPMColor at compile time. The
 * relationship between the byte order and shift values depends on machine endianness. If the shift
 * order is R=0, G=8, B=16, A=24 then ((char*)&pmcolor)[0] will produce the R channel on a little
 * endian machine and the A channel on a big endian machine. Thus, given those shifts values,
 * SK_PMCOLOR_BYTE_ORDER(R,G,B,A) will be true on a little endian machine and
 * SK_PMCOLOR_BYTE_ORDER(A,B,G,R) will be true on a big endian machine.
 */
#ifdef SK_CPU_BENDIAN
<<<<<<< HEAD
#define SK_PMCOLOR_BYTE_ORDER(C0, C1, C2, C3) \
    (SK_##C3##32_SHIFT == 0 && SK_##C2##32_SHIFT == 8 && SK_##C1##32_SHIFT == 16 && SK_##C0##32_SHIFT == 24)
#else
#define SK_PMCOLOR_BYTE_ORDER(C0, C1, C2, C3) \
    (SK_##C0##32_SHIFT == 0 && SK_##C1##32_SHIFT == 8 && SK_##C2##32_SHIFT == 16 && SK_##C3##32_SHIFT == 24)
#endif

//////////////////////////////////////////////////////////////////////////////////////////////

#if defined SK_DEBUG && defined SK_BUILD_FOR_WIN32
#ifdef free
#undef free
#endif
#include <crtdbg.h>
#undef free
#
#ifdef SK_DEBUGx
#if defined(SK_SIMULATE_FAILED_MALLOC) && defined(__cplusplus)
void* operator new(
    size_t cb,
    int nBlockUse,
    const char* szFileName,
    int nLine,
    int foo);
void* operator new[](
    size_t cb,
    int nBlockUse,
    const char* szFileName,
    int nLine,
    int foo);
void operator delete(
    void* pUserData,
    int, const char*, int, int);
void operator delete(
    void* pUserData);
void operator delete[](void* p);
#define DEBUG_CLIENTBLOCK new (_CLIENT_BLOCK, __FILE__, __LINE__, 0)
#else
#define DEBUG_CLIENTBLOCK new (_CLIENT_BLOCK, __FILE__, __LINE__)
#endif
#define new DEBUG_CLIENTBLOCK
#else
#define DEBUG_CLIENTBLOCK
#endif
=======
#  define SK_PMCOLOR_BYTE_ORDER(C0, C1, C2, C3)     \
        (SK_ ## C3 ## 32_SHIFT == 0  &&             \
         SK_ ## C2 ## 32_SHIFT == 8  &&             \
         SK_ ## C1 ## 32_SHIFT == 16 &&             \
         SK_ ## C0 ## 32_SHIFT == 24)
#else
#  define SK_PMCOLOR_BYTE_ORDER(C0, C1, C2, C3)     \
        (SK_ ## C0 ## 32_SHIFT == 0  &&             \
         SK_ ## C1 ## 32_SHIFT == 8  &&             \
         SK_ ## C2 ## 32_SHIFT == 16 &&             \
         SK_ ## C3 ## 32_SHIFT == 24)
#endif

//////////////////////////////////////////////////////////////////////////////////////////////
#ifndef SK_BUILD_FOR_WINCE
#  include <string.h>
#  include <stdlib.h>
#else
#  define _CMNINTRIN_DECLARE_ONLY
#  include "cmnintrin.h"
#endif

#if defined SK_DEBUG && defined SK_BUILD_FOR_WIN32
#  ifdef free
#    undef free
#  endif
#  include <crtdbg.h>
#  undef free
#
#  ifdef SK_DEBUGx
#    if defined(SK_SIMULATE_FAILED_MALLOC) && defined(__cplusplus)
       void * operator new(
           size_t cb,
           int nBlockUse,
           const char * szFileName,
           int nLine,
           int foo
           );
       void * operator new[](
           size_t cb,
           int nBlockUse,
           const char * szFileName,
           int nLine,
           int foo
           );
       void operator delete(
           void *pUserData,
           int, const char*, int, int
           );
       void operator delete(
           void *pUserData
           );
       void operator delete[]( void * p );
#      define DEBUG_CLIENTBLOCK   new( _CLIENT_BLOCK, __FILE__, __LINE__, 0)
#    else
#      define DEBUG_CLIENTBLOCK   new( _CLIENT_BLOCK, __FILE__, __LINE__)
#    endif
#    define new DEBUG_CLIENTBLOCK
#  else
#    define DEBUG_CLIENTBLOCK
#  endif
>>>>>>> miniblink49
#endif

//////////////////////////////////////////////////////////////////////

#if !defined(SK_UNUSED)
<<<<<<< HEAD
#define SK_UNUSED SK_ATTRIBUTE(unused)
#endif

#if !defined(SK_ATTR_DEPRECATED)
// FIXME: we ignore msg for now...
#define SK_ATTR_DEPRECATED(msg) SK_ATTRIBUTE(deprecated)
#endif

#if !defined(SK_ATTR_EXTERNALLY_DEPRECATED)
#if !defined(SK_INTERNAL)
#define SK_ATTR_EXTERNALLY_DEPRECATED(msg) SK_ATTR_DEPRECATED(msg)
#else
#define SK_ATTR_EXTERNALLY_DEPRECATED(msg)
#endif
=======
#  define SK_UNUSED SK_ATTRIBUTE(unused)
#endif

#if !defined(SK_ATTR_DEPRECATED)
   // FIXME: we ignore msg for now...
#  define SK_ATTR_DEPRECATED(msg) SK_ATTRIBUTE(deprecated)
#endif

#if !defined(SK_ATTR_EXTERNALLY_DEPRECATED)
#  if !defined(SK_INTERNAL)
#    define SK_ATTR_EXTERNALLY_DEPRECATED(msg) SK_ATTR_DEPRECATED(msg)
#  else
#    define SK_ATTR_EXTERNALLY_DEPRECATED(msg)
#  endif
>>>>>>> miniblink49
#endif

/**
 * If your judgment is better than the compiler's (i.e. you've profiled it),
 * you can use SK_ALWAYS_INLINE to force inlining. E.g.
 *     inline void someMethod() { ... }             // may not be inlined
 *     SK_ALWAYS_INLINE void someMethod() { ... }   // should always be inlined
 */
#if !defined(SK_ALWAYS_INLINE)
<<<<<<< HEAD
#if defined(SK_BUILD_FOR_WIN)
#define SK_ALWAYS_INLINE __forceinline
#else
#define SK_ALWAYS_INLINE SK_ATTRIBUTE(always_inline) \
inline
#endif
=======
#  if defined(SK_BUILD_FOR_WIN)
#    define SK_ALWAYS_INLINE __forceinline
#  else
#    define SK_ALWAYS_INLINE SK_ATTRIBUTE(always_inline) inline
#  endif
>>>>>>> miniblink49
#endif

//////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#if SK_CPU_SSE_LEVEL >= SK_CPU_SSE_LEVEL_SSE1
#define SK_PREFETCH(ptr) _mm_prefetch(reinterpret_cast<const char*>(ptr), _MM_HINT_T0)
#define SK_WRITE_PREFETCH(ptr) _mm_prefetch(reinterpret_cast<const char*>(ptr), _MM_HINT_T0)
#elif defined(__GNUC__)
#define SK_PREFETCH(ptr) __builtin_prefetch(ptr)
#define SK_WRITE_PREFETCH(ptr) __builtin_prefetch(ptr, 1)
#else
#define SK_PREFETCH(ptr)
#define SK_WRITE_PREFETCH(ptr)
=======
#if defined(__clang__) || defined(__GNUC__)
#  define SK_PREFETCH(ptr) __builtin_prefetch(ptr)
#  define SK_WRITE_PREFETCH(ptr) __builtin_prefetch(ptr, 1)
#else
#  define SK_PREFETCH(ptr)
#  define SK_WRITE_PREFETCH(ptr)
>>>>>>> miniblink49
#endif

//////////////////////////////////////////////////////////////////////

#ifndef SK_PRINTF_LIKE
<<<<<<< HEAD
#if defined(__clang__) || defined(__GNUC__)
#define SK_PRINTF_LIKE(A, B) __attribute__((format(printf, (A), (B))))
#else
#define SK_PRINTF_LIKE(A, B)
#endif
=======
#  if defined(__clang__) || defined(__GNUC__)
#    define SK_PRINTF_LIKE(A, B) __attribute__((format(printf, (A), (B))))
#  else
#    define SK_PRINTF_LIKE(A, B)
#  endif
>>>>>>> miniblink49
#endif

//////////////////////////////////////////////////////////////////////

#ifndef SK_SIZE_T_SPECIFIER
<<<<<<< HEAD
#if defined(_MSC_VER)
#define SK_SIZE_T_SPECIFIER "%Iu"
#else
#define SK_SIZE_T_SPECIFIER "%zu"
#endif
=======
#  if defined(_MSC_VER)
#    define SK_SIZE_T_SPECIFIER "%Iu"
#  else
#    define SK_SIZE_T_SPECIFIER "%zu"
#  endif
>>>>>>> miniblink49
#endif

//////////////////////////////////////////////////////////////////////

#ifndef SK_ALLOW_STATIC_GLOBAL_INITIALIZERS
<<<<<<< HEAD
#define SK_ALLOW_STATIC_GLOBAL_INITIALIZERS 1
=======
#  define SK_ALLOW_STATIC_GLOBAL_INITIALIZERS 1
>>>>>>> miniblink49
#endif

//////////////////////////////////////////////////////////////////////

#ifndef SK_EGL
<<<<<<< HEAD
#if defined(SK_BUILD_FOR_ANDROID)
#define SK_EGL 1
#else
#define SK_EGL 0
#endif
=======
#  if defined(SK_BUILD_FOR_ANDROID)
#    define SK_EGL 1
#  else
#    define SK_EGL 0
#  endif
>>>>>>> miniblink49
#endif

//////////////////////////////////////////////////////////////////////

#if defined(SK_GAMMA_EXPONENT) && defined(SK_GAMMA_SRGB)
<<<<<<< HEAD
#error "cannot define both SK_GAMMA_EXPONENT and SK_GAMMA_SRGB"
#elif defined(SK_GAMMA_SRGB)
#define SK_GAMMA_EXPONENT (0.0f)
#elif !defined(SK_GAMMA_EXPONENT)
#define SK_GAMMA_EXPONENT (2.2f)
=======
#  error "cannot define both SK_GAMMA_EXPONENT and SK_GAMMA_SRGB"
#elif defined(SK_GAMMA_SRGB)
#  define SK_GAMMA_EXPONENT (0.0f)
#elif !defined(SK_GAMMA_EXPONENT)
#  define SK_GAMMA_EXPONENT (2.2f)
>>>>>>> miniblink49
#endif

//////////////////////////////////////////////////////////////////////

#ifndef GR_TEST_UTILS
<<<<<<< HEAD
#define GR_TEST_UTILS 1
#endif

//////////////////////////////////////////////////////////////////////

#if defined(SK_HISTOGRAM_ENUMERATION) && defined(SK_HISTOGRAM_BOOLEAN)
#define SK_HISTOGRAMS_ENABLED 1
#else
#define SK_HISTOGRAMS_ENABLED 0
#endif

#ifndef SK_HISTOGRAM_BOOLEAN
#define SK_HISTOGRAM_BOOLEAN(name, value)
#endif

#ifndef SK_HISTOGRAM_ENUMERATION
#define SK_HISTOGRAM_ENUMERATION(name, value, boundary_value)
=======
#  define GR_TEST_UTILS 1
#endif

#ifndef SK_OVERRIDE
#  if defined(_MSC_VER)
#    define SK_OVERRIDE override
#  elif defined(__clang__)
// Using __attribute__((override)) on clang does not appear to always work.
// Clang defaults to C++03 and warns about using override. Squelch that. Intentionally no
// push/pop here so all users of SK_OVERRIDE ignore the warning too. This is like passing
// -Wno-c++11-extensions, except that GCC won't die (because it won't see this pragma).
#    pragma clang diagnostic ignored "-Wc++11-extensions"
#
#    if __has_feature(cxx_override_control)
#      define SK_OVERRIDE override
#    elif defined(__has_extension) && __has_extension(cxx_override_control)
#      define SK_OVERRIDE override
#    endif
#  endif
#  ifndef SK_OVERRIDE
#    define SK_OVERRIDE
#  endif
>>>>>>> miniblink49
#endif

#endif // SkPostConfig_DEFINED
