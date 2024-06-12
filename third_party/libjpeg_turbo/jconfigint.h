/* libjpeg-turbo build number */
#define BUILD  "@BUILD@"

/* Compiler's inline keyword */
#undef inline

/* How to obtain function inlining. */
#define INLINE inline /*@INLINE@*/

/* How to obtain thread-local storage */
#define THREAD_LOCAL  @THREAD_LOCAL@

/* Define to the full name of this package. */
#define PACKAGE_NAME  "@CMAKE_PROJECT_NAME@"

/* Version number of package */
#define VERSION  "@VERSION@"

/* The size of `size_t', as computed by sizeof. */
//#define SIZEOF_SIZE_T  @SIZE_T@

#if defined(_WIN64) || __SIZEOF_LONG__ == 8 || defined(__LP64__)
#define SIZEOF_SIZE_T 8
#else
#define SIZEOF_SIZE_T 4
#endif

// /* Define if your compiler has __builtin_ctzl() and sizeof(unsigned long) == sizeof(size_t). */
// #cmakedefine HAVE_BUILTIN_CTZL
// 
// /* Define to 1 if you have the <intrin.h> header file. */
// #cmakedefine HAVE_INTRIN_H
#if defined(_MSC_VER)
#define HAVE_INTRIN_H
#else
#undef HAVE_INTRIN_H
#endif

#if defined(_MSC_VER) && defined(HAVE_INTRIN_H)
#if (SIZEOF_SIZE_T == 8)
#define HAVE_BITSCANFORWARD64
#elif (SIZEOF_SIZE_T == 4)
#define HAVE_BITSCANFORWARD
#endif
#endif
