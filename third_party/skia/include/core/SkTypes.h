/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkTypes_DEFINED
#define SkTypes_DEFINED

<<<<<<< HEAD
// IWYU pragma: begin_exports
#include "SkPreConfig.h"
#include "SkUserConfig.h"
#include "SkPostConfig.h"
#include <stddef.h>
#include <stdint.h>
// IWYU pragma: end_exports

#include <string.h>

/**
 *  sk_careful_memcpy() is just like memcpy(), but guards against undefined behavior.
 *
 * It is undefined behavior to call memcpy() with null dst or src, even if len is 0.
 * If an optimizer is "smart" enough, it can exploit this to do unexpected things.
 *     memcpy(dst, src, 0);
 *     if (src) {
 *         printf("%x\n", *src);
 *     }
 * In this code the compiler can assume src is not null and omit the if (src) {...} check,
 * unconditionally running the printf, crashing the program if src really is null.
 * Of the compilers we pay attention to only GCC performs this optimization in practice.
 */
static inline void* sk_careful_memcpy(void* dst, const void* src, size_t len)
{
    // When we pass >0 len we had better already be passing valid pointers.
    // So we just need to skip calling memcpy when len == 0.
    if (len) {
        memcpy(dst, src, len);
    }
    return dst;
}
=======
#include "SkPreConfig.h"
#include "SkUserConfig.h"
#include "SkPostConfig.h"
#include <stdint.h>
#include <sys/types.h>

#if defined(SK_ARM_HAS_NEON)
    #include <arm_neon.h>
#elif SK_CPU_SSE_LEVEL >= SK_CPU_SSE_LEVEL_SSE2
    #include <immintrin.h>
#endif
>>>>>>> miniblink49

/** \file SkTypes.h
*/

/** See SkGraphics::GetVersion() to retrieve these at runtime
 */
<<<<<<< HEAD
#define SKIA_VERSION_MAJOR 1
#define SKIA_VERSION_MINOR 0
#define SKIA_VERSION_PATCH 0
=======
#define SKIA_VERSION_MAJOR  1
#define SKIA_VERSION_MINOR  0
#define SKIA_VERSION_PATCH  0
>>>>>>> miniblink49

/*
    memory wrappers to be implemented by the porting layer (platform)
*/

/** Called internally if we run out of memory. The platform implementation must
    not return, but should either throw an exception or otherwise exit.
*/
SK_API extern void sk_out_of_memory(void);
/** Called internally if we hit an unrecoverable error.
    The platform implementation must not return, but should either throw
    an exception or otherwise exit.
*/
<<<<<<< HEAD
SK_API extern void sk_abort_no_print(void);

enum {
    SK_MALLOC_TEMP = 0x01, //!< hint to sk_malloc that the requested memory will be freed in the scope of the stack frame
    SK_MALLOC_THROW = 0x02 //!< instructs sk_malloc to call sk_throw if the memory cannot be allocated.
=======
SK_API extern void sk_throw(void);

enum {
    SK_MALLOC_TEMP  = 0x01, //!< hint to sk_malloc that the requested memory will be freed in the scope of the stack frame
    SK_MALLOC_THROW = 0x02  //!< instructs sk_malloc to call sk_throw if the memory cannot be allocated.
>>>>>>> miniblink49
};
/** Return a block of memory (at least 4-byte aligned) of at least the
    specified size. If the requested memory cannot be returned, either
    return null (if SK_MALLOC_TEMP bit is clear) or throw an exception
    (if SK_MALLOC_TEMP bit is set). To free the memory, call sk_free().
*/
SK_API extern void* sk_malloc_flags(size_t size, unsigned flags);
/** Same as sk_malloc(), but hard coded to pass SK_MALLOC_THROW as the flag
*/
SK_API extern void* sk_malloc_throw(size_t size);
/** Same as standard realloc(), but this one never returns null on failure. It will throw
    an exception if it fails.
*/
SK_API extern void* sk_realloc_throw(void* buffer, size_t size);
/** Free memory returned by sk_malloc(). It is safe to pass null.
*/
SK_API extern void sk_free(void*);

/** Much like calloc: returns a pointer to at least size zero bytes, or NULL on failure.
 */
SK_API extern void* sk_calloc(size_t size);

/** Same as sk_calloc, but throws an exception instead of returning NULL on failure.
 */
SK_API extern void* sk_calloc_throw(size_t size);

// bzero is safer than memset, but we can't rely on it, so... sk_bzero()
<<<<<<< HEAD
static inline void sk_bzero(void* buffer, size_t size)
{
    // Please c.f. sk_careful_memcpy.  It's undefined behavior to call memset(null, 0, 0).
    if (size) {
        memset(buffer, 0, size);
    }
=======
static inline void sk_bzero(void* buffer, size_t size) {
    memset(buffer, 0, size);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

#ifdef override_GLOBAL_NEW
#include <new>

<<<<<<< HEAD
inline void* operator new(size_t size)
{
    return sk_malloc_throw(size);
}

inline void operator delete(void* p)
{
=======
inline void* operator new(size_t size) {
    return sk_malloc_throw(size);
}

inline void operator delete(void* p) {
>>>>>>> miniblink49
    sk_free(p);
}
#endif

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#define SK_INIT_TO_AVOID_WARNING = 0

#ifndef SkDebugf
SK_API void SkDebugf(const char format[], ...);
#endif

#define SkASSERT_RELEASE(cond) \
    if (!(cond)) {             \
        SK_ABORT(#cond);       \
    }

#ifdef SK_DEBUG
#if defined SK_BUILD_FOR_WIN
#define SkASSERT(cond)  \
    if (!(cond)) {      \
        __debugbreak(); \
    }
#else
#define SkASSERT(cond) SkASSERT_RELEASE(cond)
#endif
#define SkDEBUGFAIL(message) SkASSERT(false && message)
#define SkDEBUGFAILF(fmt, ...) SkASSERTF(false, fmt, ##__VA_ARGS__)
#define SkDEBUGCODE(code) code
#define SkDECLAREPARAM(type, var) , type var
#define SkPARAM(var) , var
//  #define SkDEBUGF(args       )       SkDebugf##args
#define SkDEBUGF(args) SkDebugf args
#define SkAssertResult(cond) SkASSERT(cond)
#else
#define SkASSERT(cond)
#define SkDEBUGFAIL(message)
#define SkDEBUGCODE(code)
#define SkDEBUGF(args)
#define SkDECLAREPARAM(type, var)
#define SkPARAM(var)

// unlike SkASSERT, this guy executes its condition in the non-debug build.
// The if is present so that this can be used with functions marked SK_WARN_UNUSED_RESULT.
#define SkAssertResult(cond) \
    if (cond) { }            \
    do {                     \
    } while (false)
#endif

// Legacy macro names for SK_ABORT
#define SkFAIL(message) SK_ABORT(message)
#define sk_throw() SK_ABORT("sk_throw")
=======
#define SK_INIT_TO_AVOID_WARNING    = 0

#ifndef SkDebugf
    SK_API void SkDebugf(const char format[], ...);
#endif

#ifdef SK_DEBUG
    #define SkASSERT(cond)              SK_ALWAYSBREAK(cond)
    #define SkDEBUGFAIL(message)        SkASSERT(false && message)
    #define SkDEBUGCODE(code)           code
    #define SkDECLAREPARAM(type, var)   , type var
    #define SkPARAM(var)                , var
//  #define SkDEBUGF(args       )       SkDebugf##args
    #define SkDEBUGF(args       )       SkDebugf args
    #define SkAssertResult(cond)        SkASSERT(cond)
#else
    #define SkASSERT(cond)
    #define SkDEBUGFAIL(message)
    #define SkDEBUGCODE(code)
    #define SkDEBUGF(args)
    #define SkDECLAREPARAM(type, var)
    #define SkPARAM(var)

    // unlike SkASSERT, this guy executes its condition in the non-debug build
    #define SkAssertResult(cond)        cond
#endif

#define SkFAIL(message)                 SK_ALWAYSBREAK(false && message)
>>>>>>> miniblink49

// We want to evaluate cond only once, and inside the SkASSERT somewhere so we see its string form.
// So we use the comma operator to make an SkDebugf that always returns false: we'll evaluate cond,
// and if it's true the assert passes; if it's false, we'll print the message and the assert fails.
<<<<<<< HEAD
#define SkASSERTF(cond, fmt, ...) SkASSERT((cond) || (SkDebugf(fmt "\n", __VA_ARGS__), false))

#ifdef SK_IGNORE_TO_STRING
#define SK_TO_STRING_NONVIRT()
#define SK_TO_STRING_VIRT()
#define SK_TO_STRING_PUREVIRT()
#define SK_TO_STRING_OVERRIDE()
#else
class SkString;
// the 'toString' helper functions convert Sk* objects to human-readable
// form in developer mode
#define SK_TO_STRING_NONVIRT() void toString(SkString* str) const;
#define SK_TO_STRING_VIRT() virtual void toString(SkString* str) const;
#define SK_TO_STRING_PUREVIRT() virtual void toString(SkString* str) const = 0;
#define SK_TO_STRING_OVERRIDE() void toString(SkString* str) const override;
#endif

=======
#define SkASSERTF(cond, fmt, ...)       SkASSERT((cond) || (SkDebugf(fmt"\n", __VA_ARGS__), false))

#ifdef SK_DEVELOPER
    #define SkDEVCODE(code)             code
#else
    #define SkDEVCODE(code)
#endif

#ifdef SK_IGNORE_TO_STRING
    #define SK_TO_STRING_NONVIRT()
    #define SK_TO_STRING_VIRT()
    #define SK_TO_STRING_PUREVIRT()
    #define SK_TO_STRING_OVERRIDE()
#else
    // the 'toString' helper functions convert Sk* objects to human-readable
    // form in developer mode
    #define SK_TO_STRING_NONVIRT() void toString(SkString* str) const;
    #define SK_TO_STRING_VIRT() virtual void toString(SkString* str) const;
    #define SK_TO_STRING_PUREVIRT() virtual void toString(SkString* str) const = 0;
    #define SK_TO_STRING_OVERRIDE() void toString(SkString* str) const override;
#endif

template <bool>
struct SkCompileAssert {
};

// Uses static_cast<bool>(expr) instead of bool(expr) due to
// https://connect.microsoft.com/VisualStudio/feedback/details/832915

// The extra parentheses in SkCompileAssert<(...)> are a work around for
// http://gcc.gnu.org/bugzilla/show_bug.cgi?id=57771
// which was fixed in gcc 4.8.2.
#define SK_COMPILE_ASSERT(expr, msg) \
    typedef SkCompileAssert<(static_cast<bool>(expr))> \
            msg[static_cast<bool>(expr) ? 1 : -1] SK_UNUSED

>>>>>>> miniblink49
/*
 *  Usage:  SK_MACRO_CONCAT(a, b)   to construct the symbol ab
 *
 *  SK_MACRO_CONCAT_IMPL_PRIV just exists to make this work. Do not use directly
 *
 */
<<<<<<< HEAD
#define SK_MACRO_CONCAT(X, Y) SK_MACRO_CONCAT_IMPL_PRIV(X, Y)
#define SK_MACRO_CONCAT_IMPL_PRIV(X, Y) X##Y
=======
#define SK_MACRO_CONCAT(X, Y)           SK_MACRO_CONCAT_IMPL_PRIV(X, Y)
#define SK_MACRO_CONCAT_IMPL_PRIV(X, Y)  X ## Y
>>>>>>> miniblink49

/*
 *  Usage: SK_MACRO_APPEND_LINE(foo)    to make foo123, where 123 is the current
 *                                      line number. Easy way to construct
 *                                      unique names for local functions or
 *                                      variables.
 */
<<<<<<< HEAD
#define SK_MACRO_APPEND_LINE(name) SK_MACRO_CONCAT(name, __LINE__)
=======
#define SK_MACRO_APPEND_LINE(name)  SK_MACRO_CONCAT(name, __LINE__)
>>>>>>> miniblink49

/**
 * For some classes, it's almost always an error to instantiate one without a name, e.g.
 *   {
 *       SkAutoMutexAcquire(&mutex);
 *       <some code>
 *   }
 * In this case, the writer meant to hold mutex while the rest of the code in the block runs,
 * but instead the mutex is acquired and then immediately released.  The correct usage is
 *   {
 *       SkAutoMutexAcquire lock(&mutex);
 *       <some code>
 *   }
 *
 * To prevent callers from instantiating your class without a name, use SK_REQUIRE_LOCAL_VAR
 * like this:
 *   class classname {
 *       <your class>
 *   };
 *   #define classname(...) SK_REQUIRE_LOCAL_VAR(classname)
 *
 * This won't work with templates, and you must inline the class' constructors and destructors.
 * Take a look at SkAutoFree and SkAutoMalloc in this file for examples.
 */
#define SK_REQUIRE_LOCAL_VAR(classname) \
<<<<<<< HEAD
    static_assert(false, "missing name for " #classname)
=======
    SK_COMPILE_ASSERT(false, missing_name_for_##classname)
>>>>>>> miniblink49

///////////////////////////////////////////////////////////////////////

/**
 *  Fast type for signed 8 bits. Use for parameter passing and local variables,
 *  not for storage.
 */
typedef int S8CPU;

/**
 *  Fast type for unsigned 8 bits. Use for parameter passing and local
 *  variables, not for storage
 */
typedef unsigned U8CPU;

/**
 *  Fast type for signed 16 bits. Use for parameter passing and local variables,
 *  not for storage
 */
typedef int S16CPU;

/**
 *  Fast type for unsigned 16 bits. Use for parameter passing and local
 *  variables, not for storage
 */
typedef unsigned U16CPU;

/**
<<<<<<< HEAD
=======
 *  Meant to be faster than bool (doesn't promise to be 0 or 1,
 *  just 0 or non-zero
 */
typedef int SkBool;

/**
>>>>>>> miniblink49
 *  Meant to be a small version of bool, for storage purposes. Will be 0 or 1
 */
typedef uint8_t SkBool8;

<<<<<<< HEAD
#include "../private/SkTFitsIn.h"
template <typename D, typename S>
D SkTo(S s)
{
    SkASSERT(SkTFitsIn<D>(s));
    return static_cast<D>(s);
}
#define SkToS8(x) SkTo<int8_t>(x)
#define SkToU8(x) SkTo<uint8_t>(x)
#define SkToS16(x) SkTo<int16_t>(x)
#define SkToU16(x) SkTo<uint16_t>(x)
#define SkToS32(x) SkTo<int32_t>(x)
#define SkToU32(x) SkTo<uint32_t>(x)
#define SkToInt(x) SkTo<int>(x)
#define SkToUInt(x) SkTo<unsigned>(x)
#define SkToSizeT(x) SkTo<size_t>(x)

/** Returns 0 or 1 based on the condition
*/
#define SkToBool(cond) ((cond) != 0)

#define SK_MaxS16 32767
#define SK_MinS16 -32767
#define SK_MaxU16 0xFFFF
#define SK_MinU16 0
#define SK_MaxS32 0x7FFFFFFF
#define SK_MinS32 -SK_MaxS32
#define SK_MaxU32 0xFFFFFFFF
#define SK_MinU32 0
#define SK_NaN32 ((int)(1U << 31))

/** Returns true if the value can be represented with signed 16bits
 */
static inline bool SkIsS16(long x)
{
=======
#ifdef SK_DEBUG
    SK_API int8_t      SkToS8(intmax_t);
    SK_API uint8_t     SkToU8(uintmax_t);
    SK_API int16_t     SkToS16(intmax_t);
    SK_API uint16_t    SkToU16(uintmax_t);
    SK_API int32_t     SkToS32(intmax_t);
    SK_API uint32_t    SkToU32(uintmax_t);
    SK_API int         SkToInt(intmax_t);
    SK_API unsigned    SkToUInt(uintmax_t);
    SK_API size_t      SkToSizeT(uintmax_t);
    SK_API off_t       SkToOffT(intmax_t x);
#else
    #define SkToS8(x)   ((int8_t)(x))
    #define SkToU8(x)   ((uint8_t)(x))
    #define SkToS16(x)  ((int16_t)(x))
    #define SkToU16(x)  ((uint16_t)(x))
    #define SkToS32(x)  ((int32_t)(x))
    #define SkToU32(x)  ((uint32_t)(x))
    #define SkToInt(x)  ((int)(x))
    #define SkToUInt(x) ((unsigned)(x))
    #define SkToSizeT(x) ((size_t)(x))
    #define SkToOffT(x) ((off_t)(x))
#endif

/** Returns 0 or 1 based on the condition
*/
#define SkToBool(cond)  ((cond) != 0)

#define SK_MaxS16   32767
#define SK_MinS16   -32767
#define SK_MaxU16   0xFFFF
#define SK_MinU16   0
#define SK_MaxS32   0x7FFFFFFF
#define SK_MinS32   -SK_MaxS32
#define SK_MaxU32   0xFFFFFFFF
#define SK_MinU32   0
#define SK_NaN32    (1 << 31)

/** Returns true if the value can be represented with signed 16bits
 */
static inline bool SkIsS16(long x) {
>>>>>>> miniblink49
    return (int16_t)x == x;
}

/** Returns true if the value can be represented with unsigned 16bits
 */
<<<<<<< HEAD
static inline bool SkIsU16(long x)
{
    return (uint16_t)x == x;
}

static inline int32_t SkLeftShift(int32_t value, int32_t shift)
{
    return (int32_t)((uint32_t)value << shift);
}

static inline int64_t SkLeftShift(int64_t value, int32_t shift)
{
    return (int64_t)((uint64_t)value << shift);
}

//////////////////////////////////////////////////////////////////////////////

/** Returns the number of entries in an array (not a pointer) */
template <typename T, size_t N>
char (&SkArrayCountHelper(T (&array)[N]))[N];
#define SK_ARRAY_COUNT(array) (sizeof(SkArrayCountHelper(array)))

// Can be used to bracket data types that must be dense, e.g. hash keys.
#if defined(__clang__) // This should work on GCC too, but GCC diagnostic pop didn't seem to work!
#define SK_BEGIN_REQUIRE_DENSE _Pragma("GCC diagnostic push") \
    _Pragma("GCC diagnostic error \"-Wpadded\"")
#define SK_END_REQUIRE_DENSE _Pragma("GCC diagnostic pop")
#else
#define SK_BEGIN_REQUIRE_DENSE
#define SK_END_REQUIRE_DENSE
#endif

#define SkAlign2(x) (((x) + 1) >> 1 << 1)
#define SkIsAlign2(x) (0 == ((x)&1))

#define SkAlign4(x) (((x) + 3) >> 2 << 2)
#define SkIsAlign4(x) (0 == ((x)&3))

#define SkAlign8(x) (((x) + 7) >> 3 << 3)
#define SkIsAlign8(x) (0 == ((x)&7))

#define SkAlign16(x) (((x) + 15) >> 4 << 4)
#define SkIsAlign16(x) (0 == ((x)&15))

#define SkAlignPtr(x) (sizeof(void*) == 8 ? SkAlign8(x) : SkAlign4(x))
#define SkIsAlignPtr(x) (sizeof(void*) == 8 ? SkIsAlign8(x) : SkIsAlign4(x))

typedef uint32_t SkFourByteTag;
#define SkSetFourByteTag(a, b, c, d) (((a) << 24) | ((b) << 16) | ((c) << 8) | (d))
=======
static inline bool SkIsU16(long x) {
    return (uint16_t)x == x;
}

//////////////////////////////////////////////////////////////////////////////
#ifndef SK_OFFSETOF
    #define SK_OFFSETOF(type, field)    (size_t)((char*)&(((type*)1)->field) - (char*)1)
#endif

/** Returns the number of entries in an array (not a pointer) */
template <typename T, size_t N> char (&SkArrayCountHelper(T (&array)[N]))[N];
#define SK_ARRAY_COUNT(array) (sizeof(SkArrayCountHelper(array)))

#define SkAlign2(x)     (((x) + 1) >> 1 << 1)
#define SkIsAlign2(x)   (0 == ((x) & 1))

#define SkAlign4(x)     (((x) + 3) >> 2 << 2)
#define SkIsAlign4(x)   (0 == ((x) & 3))

#define SkAlign8(x)     (((x) + 7) >> 3 << 3)
#define SkIsAlign8(x)   (0 == ((x) & 7))

#define SkAlignPtr(x)   (sizeof(void*) == 8 ?   SkAlign8(x) :   SkAlign4(x))
#define SkIsAlignPtr(x) (sizeof(void*) == 8 ? SkIsAlign8(x) : SkIsAlign4(x))

typedef uint32_t SkFourByteTag;
#define SkSetFourByteTag(a, b, c, d)    (((a) << 24) | ((b) << 16) | ((c) << 8) | (d))
>>>>>>> miniblink49

/** 32 bit integer to hold a unicode value
*/
typedef int32_t SkUnichar;
<<<<<<< HEAD

/** 32 bit value to hold a millisecond duration
 *  Note that SK_MSecMax is about 25 days.
 */
=======
/** 32 bit value to hold a millisecond count
*/
>>>>>>> miniblink49
typedef uint32_t SkMSec;
/** 1 second measured in milliseconds
*/
#define SK_MSec1 1000
<<<<<<< HEAD
/** maximum representable milliseconds; 24d 20h 31m 23.647s.
=======
/** maximum representable milliseconds
>>>>>>> miniblink49
*/
#define SK_MSecMax 0x7FFFFFFF
/** Returns a < b for milliseconds, correctly handling wrap-around from 0xFFFFFFFF to 0
*/
<<<<<<< HEAD
#define SkMSec_LT(a, b) ((int32_t)(a) - (int32_t)(b) < 0)
/** Returns a <= b for milliseconds, correctly handling wrap-around from 0xFFFFFFFF to 0
*/
#define SkMSec_LE(a, b) ((int32_t)(a) - (int32_t)(b) <= 0)

/** The generation IDs in Skia reserve 0 has an invalid marker.
 */
#define SK_InvalidGenID 0
/** The unique IDs in Skia reserve 0 has an invalid marker.
 */
#define SK_InvalidUniqueID 0
=======
#define SkMSec_LT(a, b)     ((int32_t)(a) - (int32_t)(b) < 0)
/** Returns a <= b for milliseconds, correctly handling wrap-around from 0xFFFFFFFF to 0
*/
#define SkMSec_LE(a, b)     ((int32_t)(a) - (int32_t)(b) <= 0)

/** The generation IDs in Skia reserve 0 has an invalid marker.
 */
#define SK_InvalidGenID     0
/** The unique IDs in Skia reserve 0 has an invalid marker.
 */
#define SK_InvalidUniqueID  0
>>>>>>> miniblink49

/****************************************************************************
    The rest of these only build with C++
*/
#ifdef __cplusplus

/** Faster than SkToBool for integral conditions. Returns 0 or 1
*/
<<<<<<< HEAD
static inline /*constexpr*/ int Sk32ToBool(uint32_t n)
{
    return (n | (0 - n)) >> 31;
=======
static inline int Sk32ToBool(uint32_t n) {
    return (n | (0-n)) >> 31;
>>>>>>> miniblink49
}

/** Generic swap function. Classes with efficient swaps should specialize this function to take
    their fast path. This function is used by SkTSort. */
<<<<<<< HEAD
template <typename T>
inline void SkTSwap(T& a, T& b)
{
=======
template <typename T> inline void SkTSwap(T& a, T& b) {
>>>>>>> miniblink49
    T c(a);
    a = b;
    b = c;
}

<<<<<<< HEAD
static inline int32_t SkAbs32(int32_t value)
{
    SkASSERT(value != SK_NaN32); // The most negative int32_t can't be negated.
=======
static inline int32_t SkAbs32(int32_t value) {
    SkASSERT(value != SK_NaN32);  // The most negative int32_t can't be negated.
>>>>>>> miniblink49
    if (value < 0) {
        value = -value;
    }
    return value;
}

<<<<<<< HEAD
template <typename T>
inline T SkTAbs(T value)
{
=======
template <typename T> inline T SkTAbs(T value) {
>>>>>>> miniblink49
    if (value < 0) {
        value = -value;
    }
    return value;
}

<<<<<<< HEAD
static inline int32_t SkMax32(int32_t a, int32_t b)
{
=======
static inline int32_t SkMax32(int32_t a, int32_t b) {
>>>>>>> miniblink49
    if (a < b)
        a = b;
    return a;
}

<<<<<<< HEAD
static inline int32_t SkMin32(int32_t a, int32_t b)
{
=======
static inline int32_t SkMin32(int32_t a, int32_t b) {
>>>>>>> miniblink49
    if (a > b)
        a = b;
    return a;
}

<<<<<<< HEAD
template <typename T>
/*constexpr*/ const T& SkTMin(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

template <typename T>
/*constexpr*/ const T& SkTMax(const T& a, const T& b)
{
    return (b < a) ? a : b;
}

static inline int32_t SkSign32(int32_t a)
{
    return (a >> 31) | ((unsigned)-a >> 31);
}

static inline int32_t SkFastMin32(int32_t value, int32_t max)
{
=======
template <typename T> const T& SkTMin(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template <typename T> const T& SkTMax(const T& a, const T& b) {
    return (b < a) ? a : b;
}

static inline int32_t SkSign32(int32_t a) {
    return (a >> 31) | ((unsigned) -a >> 31);
}

static inline int32_t SkFastMin32(int32_t value, int32_t max) {
>>>>>>> miniblink49
    if (value > max) {
        value = max;
    }
    return value;
}

<<<<<<< HEAD
/** Returns value pinned between min and max, inclusively. */
template <typename T>
static /*constexpr*/ const T& SkTPin(const T& value, const T& min, const T& max)
{
    return SkTMax(SkTMin(value, max), min);
}

///////////////////////////////////////////////////////////////////////////////

/**
 *  Indicates whether an allocation should count against a cache budget.
 */
enum class SkBudgeted : bool {
    kNo = false,
    kYes = true
};

/**
 * Indicates whether a backing store needs to be an exact match or can be larger
 * than is strictly necessary
 */
enum class SkBackingFit {
    kApprox,
    kExact
};
=======
template <typename T> static inline const T& SkTPin(const T& x, const T& min, const T& max) {
    return SkTMax(SkTMin(x, max), min);
}

/** Returns signed 32 bit value pinned between min and max, inclusively. */
static inline int32_t SkPin32(int32_t value, int32_t min, int32_t max) {
    return SkTPin(value, min, max);
}

static inline uint32_t SkSetClearShift(uint32_t bits, bool cond,
                                       unsigned shift) {
    SkASSERT((int)cond == 0 || (int)cond == 1);
    return (bits & ~(1 << shift)) | ((int)cond << shift);
}

static inline uint32_t SkSetClearMask(uint32_t bits, bool cond,
                                      uint32_t mask) {
    return cond ? bits | mask : bits & ~mask;
}
>>>>>>> miniblink49

///////////////////////////////////////////////////////////////////////////////

/** Use to combine multiple bits in a bitmask in a type safe way.
 */
template <typename T>
<<<<<<< HEAD
T SkTBitOr(T a, T b)
{
=======
T SkTBitOr(T a, T b) {
>>>>>>> miniblink49
    return (T)(a | b);
}

/**
 *  Use to cast a pointer to a different type, and maintaining strict-aliasing
 */
<<<<<<< HEAD
template <typename Dst>
Dst SkTCast(const void* ptr)
{
=======
template <typename Dst> Dst SkTCast(const void* ptr) {
>>>>>>> miniblink49
    union {
        const void* src;
        Dst dst;
    } data;
    data.src = ptr;
    return data.dst;
}

//////////////////////////////////////////////////////////////////////////////

/** \class SkNoncopyable

SkNoncopyable is the base class for objects that do not want to
be copied. It hides its copy-constructor and its assignment-operator.
*/
class SK_API SkNoncopyable {
public:
<<<<<<< HEAD
    SkNoncopyable() { }
=======
    SkNoncopyable() {}
>>>>>>> miniblink49

private:
    SkNoncopyable(const SkNoncopyable&);
    SkNoncopyable& operator=(const SkNoncopyable&);
};

class SkAutoFree : SkNoncopyable {
public:
<<<<<<< HEAD
    SkAutoFree()
        : fPtr(NULL)
    {
    }
    explicit SkAutoFree(void* ptr)
        : fPtr(ptr)
    {
    }
=======
    SkAutoFree() : fPtr(NULL) {}
    explicit SkAutoFree(void* ptr) : fPtr(ptr) {}
>>>>>>> miniblink49
    ~SkAutoFree() { sk_free(fPtr); }

    /** Return the currently allocate buffer, or null
    */
    void* get() const { return fPtr; }

    /** Assign a new ptr allocated with sk_malloc (or null), and return the
        previous ptr. Note it is the caller's responsibility to sk_free the
        returned ptr.
    */
<<<<<<< HEAD
    void* set(void* ptr)
    {
=======
    void* set(void* ptr) {
>>>>>>> miniblink49
        void* prev = fPtr;
        fPtr = ptr;
        return prev;
    }

    /** Transfer ownership of the current ptr to the caller, setting the
        internal reference to null. Note the caller is reponsible for calling
        sk_free on the returned address.
    */
<<<<<<< HEAD
    void* release() { return this->set(NULL); }

    /** Free the current buffer, and set the internal reference to NULL. Same
        as calling sk_free(release())
    */
    void reset()
    {
=======
    void* detach() { return this->set(NULL); }

    /** Free the current buffer, and set the internal reference to NULL. Same
        as calling sk_free(detach())
    */
    void free() {
>>>>>>> miniblink49
        sk_free(fPtr);
        fPtr = NULL;
    }

private:
    void* fPtr;
    // illegal
    SkAutoFree(const SkAutoFree&);
    SkAutoFree& operator=(const SkAutoFree&);
};
#define SkAutoFree(...) SK_REQUIRE_LOCAL_VAR(SkAutoFree)

/**
 *  Manage an allocated block of heap memory. This object is the sole manager of
 *  the lifetime of the block, so the caller must not call sk_free() or delete
<<<<<<< HEAD
 *  on the block, unless release() was called.
 */
class SkAutoMalloc : SkNoncopyable {
public:
    explicit SkAutoMalloc(size_t size = 0)
    {
=======
 *  on the block, unless detach() was called.
 */
class SkAutoMalloc : SkNoncopyable {
public:
    explicit SkAutoMalloc(size_t size = 0) {
>>>>>>> miniblink49
        fPtr = size ? sk_malloc_throw(size) : NULL;
        fSize = size;
    }

<<<<<<< HEAD
    ~SkAutoMalloc()
    {
=======
    ~SkAutoMalloc() {
>>>>>>> miniblink49
        sk_free(fPtr);
    }

    /**
     *  Passed to reset to specify what happens if the requested size is smaller
     *  than the current size (and the current block was dynamically allocated).
     */
    enum OnShrink {
        /**
         *  If the requested size is smaller than the current size, and the
         *  current block is dynamically allocated, free the old block and
         *  malloc a new block of the smaller size.
         */
        kAlloc_OnShrink,

        /**
         *  If the requested size is smaller than the current size, and the
         *  current block is dynamically allocated, just return the old
         *  block.
         */
        kReuse_OnShrink
    };

    /**
     *  Reallocates the block to a new size. The ptr may or may not change.
     */
<<<<<<< HEAD
    void* reset(size_t size = 0, OnShrink shrink = kAlloc_OnShrink, bool* didChangeAlloc = NULL)
    {
=======
    void* reset(size_t size, OnShrink shrink = kAlloc_OnShrink,  bool* didChangeAlloc = NULL) {
>>>>>>> miniblink49
        if (size == fSize || (kReuse_OnShrink == shrink && size < fSize)) {
            if (didChangeAlloc) {
                *didChangeAlloc = false;
            }
            return fPtr;
        }

        sk_free(fPtr);
        fPtr = size ? sk_malloc_throw(size) : NULL;
        fSize = size;
        if (didChangeAlloc) {
            *didChangeAlloc = true;
        }

        return fPtr;
    }

    /**
<<<<<<< HEAD
=======
     *  Releases the block back to the heap
     */
    void free() {
        this->reset(0);
    }

    /**
>>>>>>> miniblink49
     *  Return the allocated block.
     */
    void* get() { return fPtr; }
    const void* get() const { return fPtr; }

<<<<<<< HEAD
    /** Transfer ownership of the current ptr to the caller, setting the
       internal reference to null. Note the caller is reponsible for calling
       sk_free on the returned address.
    */
    void* release()
    {
=======
   /** Transfer ownership of the current ptr to the caller, setting the
       internal reference to null. Note the caller is reponsible for calling
       sk_free on the returned address.
    */
    void* detach() {
>>>>>>> miniblink49
        void* ptr = fPtr;
        fPtr = NULL;
        fSize = 0;
        return ptr;
    }

private:
<<<<<<< HEAD
    void* fPtr;
    size_t fSize; // can be larger than the requested size (see kReuse)
=======
    void*   fPtr;
    size_t  fSize;  // can be larger than the requested size (see kReuse)
>>>>>>> miniblink49
};
#define SkAutoMalloc(...) SK_REQUIRE_LOCAL_VAR(SkAutoMalloc)

/**
<<<<<<< HEAD
 *  Manage an allocated block of memory. If the requested size is <= kSizeRequested (or slightly
 *  more), then the allocation will come from the stack rather than the heap. This object is the
 *  sole manager of the lifetime of the block, so the caller must not call sk_free() or delete on
 *  the block.
 */
template <size_t kSizeRequested>
class SkAutoSMalloc : SkNoncopyable {
public:
    /**
     *  Creates initially empty storage. get() returns a ptr, but it is to a zero-byte allocation.
     *  Must call reset(size) to return an allocated block.
     */
    SkAutoSMalloc()
    {
=======
 *  Manage an allocated block of memory. If the requested size is <= kSize, then
 *  the allocation will come from the stack rather than the heap. This object
 *  is the sole manager of the lifetime of the block, so the caller must not
 *  call sk_free() or delete on the block.
 */
template <size_t kSize> class SkAutoSMalloc : SkNoncopyable {
public:
    /**
     *  Creates initially empty storage. get() returns a ptr, but it is to
     *  a zero-byte allocation. Must call reset(size) to return an allocated
     *  block.
     */
    SkAutoSMalloc() {
>>>>>>> miniblink49
        fPtr = fStorage;
        fSize = kSize;
    }

    /**
<<<<<<< HEAD
     *  Allocate a block of the specified size. If size <= kSizeRequested (or slightly more), then
     *  the allocation will come from the stack, otherwise it will be dynamically allocated.
     */
    explicit SkAutoSMalloc(size_t size)
    {
=======
     *  Allocate a block of the specified size. If size <= kSize, then the
     *  allocation will come from the stack, otherwise it will be dynamically
     *  allocated.
     */
    explicit SkAutoSMalloc(size_t size) {
>>>>>>> miniblink49
        fPtr = fStorage;
        fSize = kSize;
        this->reset(size);
    }

    /**
<<<<<<< HEAD
     *  Free the allocated block (if any). If the block was small enough to have been allocated on
     *  the stack, then this does nothing.
     */
    ~SkAutoSMalloc()
    {
=======
     *  Free the allocated block (if any). If the block was small enought to
     *  have been allocated on the stack (size <= kSize) then this does nothing.
     */
    ~SkAutoSMalloc() {
>>>>>>> miniblink49
        if (fPtr != (void*)fStorage) {
            sk_free(fPtr);
        }
    }

    /**
<<<<<<< HEAD
     *  Return the allocated block. May return non-null even if the block is of zero size. Since
     *  this may be on the stack or dynamically allocated, the caller must not call sk_free() on it,
     *  but must rely on SkAutoSMalloc to manage it.
=======
     *  Return the allocated block. May return non-null even if the block is
     *  of zero size. Since this may be on the stack or dynamically allocated,
     *  the caller must not call sk_free() on it, but must rely on SkAutoSMalloc
     *  to manage it.
>>>>>>> miniblink49
     */
    void* get() const { return fPtr; }

    /**
<<<<<<< HEAD
     *  Return a new block of the requested size, freeing (as necessary) any previously allocated
     *  block. As with the constructor, if size <= kSizeRequested (or slightly more) then the return
     *  block may be allocated locally, rather than from the heap.
     */
    void* reset(size_t size,
        SkAutoMalloc::OnShrink shrink = SkAutoMalloc::kAlloc_OnShrink,
        bool* didChangeAlloc = NULL)
    {
=======
     *  Return a new block of the requested size, freeing (as necessary) any
     *  previously allocated block. As with the constructor, if size <= kSize
     *  then the return block may be allocated locally, rather than from the
     *  heap.
     */
    void* reset(size_t size,
                SkAutoMalloc::OnShrink shrink = SkAutoMalloc::kAlloc_OnShrink,
                bool* didChangeAlloc = NULL) {
>>>>>>> miniblink49
        size = (size < kSize) ? kSize : size;
        bool alloc = size != fSize && (SkAutoMalloc::kAlloc_OnShrink == shrink || size > fSize);
        if (didChangeAlloc) {
            *didChangeAlloc = alloc;
        }
        if (alloc) {
            if (fPtr != (void*)fStorage) {
                sk_free(fPtr);
            }

            if (size == kSize) {
                SkASSERT(fPtr != fStorage); // otherwise we lied when setting didChangeAlloc.
                fPtr = fStorage;
            } else {
                fPtr = sk_malloc_flags(size, SK_MALLOC_THROW | SK_MALLOC_TEMP);
            }

            fSize = size;
        }
        SkASSERT(fSize >= size && fSize >= kSize);
        SkASSERT((fPtr == fStorage) || fSize > kSize);
        return fPtr;
    }

private:
<<<<<<< HEAD
    // Align up to 32 bits.
    static const size_t kSizeAlign4 = SkAlign4(kSizeRequested);
#if defined(GOOGLE3)
    // Stack frame size is limited for GOOGLE3. 4k is less than the actual max, but some functions
    // have multiple large stack allocations.
    static const size_t kMaxBytes = 4 * 1024;
    static const size_t kSize = kSizeRequested > kMaxBytes ? kMaxBytes : kSizeAlign4;
#else
    static const size_t kSize = kSizeAlign4;
#endif

    void* fPtr;
    size_t fSize; // can be larger than the requested size (see kReuse)
    uint32_t fStorage[kSize >> 2];
=======
    void*       fPtr;
    size_t      fSize;  // can be larger than the requested size (see kReuse)
    uint32_t    fStorage[(kSize + 3) >> 2];
>>>>>>> miniblink49
};
// Can't guard the constructor because it's a template class.

#endif /* C++ */

#endif
