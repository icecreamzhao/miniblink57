/*
*******************************************************************************
*
*   Copyright (C) 2009-2012, International Business Machines
*   Corporation and others.  All Rights Reserved.
*
*******************************************************************************
*   file name:  localpointer.h
*   encoding:   US-ASCII
*   tab size:   8 (not used)
*   indentation:4
*
*   created on: 2009nov13
*   created by: Markus W. Scherer
*/

#ifndef __LOCALPOINTER_H__
#define __LOCALPOINTER_H__

/**
 * \file 
 * \brief C++ API: "Smart pointers" for use with and in ICU4C C++ code.
 *
 * These classes are inspired by
 * - std::auto_ptr
 * - boost::scoped_ptr & boost::scoped_array
 * - Taligent Safe Pointers (TOnlyPointerTo)
 *
 * but none of those provide for all of the goals for ICU smart pointers:
 * - Smart pointer owns the object and releases it when it goes out of scope.
 * - No transfer of ownership via copy/assignment to reduce misuse. Simpler & more robust.
 * - ICU-compatible: No exceptions.
 * - Need to be able to orphan/release the pointer and its ownership.
 * - Need variants for normal C++ object pointers, C++ arrays, and ICU C service objects.
 *
 * For details see http://site.icu-project.org/design/cpp/scoped_ptr
 */

#include "unicode/utypes.h"

#if U_SHOW_CPLUSPLUS_API

U_NAMESPACE_BEGIN

/**
 * "Smart pointer" base class; do not use directly: use LocalPointer etc.
 *
 * Base class for smart pointer classes that do not throw exceptions.
 *
 * Do not use this base class directly, since it does not delete its pointer.
 * A subclass must implement methods that delete the pointer:
 * Destructor and adoptInstead().
 *
 * There is no operator T *() provided because the programmer must decide
 * whether to use getAlias() (without transfer of ownership) or orpan()
 * (with transfer of ownership and NULLing of the pointer).
 *
 * @see LocalPointer
 * @see LocalArray
 * @see U_DEFINE_LOCAL_OPEN_POINTER
 * @stable ICU 4.4
 */
<<<<<<< HEAD
template <typename T>
=======
template<typename T>
>>>>>>> miniblink49
class LocalPointerBase {
public:
    /**
     * Constructor takes ownership.
     * @param p simple pointer to an object that is adopted
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    explicit LocalPointerBase(T* p = NULL)
        : ptr(p)
    {
    }
=======
    explicit LocalPointerBase(T *p=NULL) : ptr(p) {}
>>>>>>> miniblink49
    /**
     * Destructor deletes the object it owns.
     * Subclass must override: Base class does nothing.
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    ~LocalPointerBase()
    { /* delete ptr; */
    }
=======
    ~LocalPointerBase() { /* delete ptr; */ }
>>>>>>> miniblink49
    /**
     * NULL check.
     * @return TRUE if ==NULL
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    UBool isNull() const { return ptr == NULL; }
=======
    UBool isNull() const { return ptr==NULL; }
>>>>>>> miniblink49
    /**
     * NULL check.
     * @return TRUE if !=NULL
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    UBool isValid() const { return ptr != NULL; }
=======
    UBool isValid() const { return ptr!=NULL; }
>>>>>>> miniblink49
    /**
     * Comparison with a simple pointer, so that existing code
     * with ==NULL need not be changed.
     * @param other simple pointer for comparison
     * @return true if this pointer value equals other
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    bool operator==(const T* other) const { return ptr == other; }
=======
    bool operator==(const T *other) const { return ptr==other; }
>>>>>>> miniblink49
    /**
     * Comparison with a simple pointer, so that existing code
     * with !=NULL need not be changed.
     * @param other simple pointer for comparison
     * @return true if this pointer value differs from other
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    bool operator!=(const T* other) const { return ptr != other; }
=======
    bool operator!=(const T *other) const { return ptr!=other; }
>>>>>>> miniblink49
    /**
     * Access without ownership change.
     * @return the pointer value
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    T* getAlias() const { return ptr; }
=======
    T *getAlias() const { return ptr; }
>>>>>>> miniblink49
    /**
     * Access without ownership change.
     * @return the pointer value as a reference
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    T& operator*() const { return *ptr; }
=======
    T &operator*() const { return *ptr; }
>>>>>>> miniblink49
    /**
     * Access without ownership change.
     * @return the pointer value
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    T* operator->() const { return ptr; }
=======
    T *operator->() const { return ptr; }
>>>>>>> miniblink49
    /**
     * Gives up ownership; the internal pointer becomes NULL.
     * @return the pointer value;
     *         caller becomes responsible for deleting the object
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    T* orphan()
    {
        T* p = ptr;
        ptr = NULL;
=======
    T *orphan() {
        T *p=ptr;
        ptr=NULL;
>>>>>>> miniblink49
        return p;
    }
    /**
     * Deletes the object it owns,
     * and adopts (takes ownership of) the one passed in.
     * Subclass must override: Base class does not delete the object.
     * @param p simple pointer to an object that is adopted
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    void adoptInstead(T* p)
    {
        // delete ptr;
        ptr = p;
    }

=======
    void adoptInstead(T *p) {
        // delete ptr;
        ptr=p;
    }
>>>>>>> miniblink49
protected:
    /**
     * Actual pointer.
     * @internal
     */
<<<<<<< HEAD
    T* ptr;

private:
    // No comparison operators with other LocalPointerBases.
    bool operator==(const LocalPointerBase& other);
    bool operator!=(const LocalPointerBase& other);
    // No ownership transfer: No copy constructor, no assignment operator.
    LocalPointerBase(const LocalPointerBase& other);
    void operator=(const LocalPointerBase& other);
    // No heap allocation. Use only on the stack.
    static void* U_EXPORT2 operator new(size_t size);
    static void* U_EXPORT2 operator new[](size_t size);
#if U_HAVE_PLACEMENT_NEW
    static void* U_EXPORT2 operator new(size_t, void* ptr);
=======
    T *ptr;
private:
    // No comparison operators with other LocalPointerBases.
    bool operator==(const LocalPointerBase &other);
    bool operator!=(const LocalPointerBase &other);
    // No ownership transfer: No copy constructor, no assignment operator.
    LocalPointerBase(const LocalPointerBase &other);
    void operator=(const LocalPointerBase &other);
    // No heap allocation. Use only on the stack.
    static void * U_EXPORT2 operator new(size_t size);
    static void * U_EXPORT2 operator new[](size_t size);
#if U_HAVE_PLACEMENT_NEW
    static void * U_EXPORT2 operator new(size_t, void *ptr);
>>>>>>> miniblink49
#endif
};

/**
 * "Smart pointer" class, deletes objects via the standard C++ delete operator.
 * For most methods see the LocalPointerBase base class.
 *
 * Usage example:
 * \code
 * LocalPointer<UnicodeString> s(new UnicodeString((UChar32)0x50005));
 * int32_t length=s->length();  // 2
 * UChar lead=s->charAt(0);  // 0xd900
 * if(some condition) { return; }  // no need to explicitly delete the pointer
 * s.adoptInstead(new UnicodeString((UChar)0xfffc));
 * length=s->length();  // 1
 * // no need to explicitly delete the pointer
 * \endcode
 *
 * @see LocalPointerBase
 * @stable ICU 4.4
 */
<<<<<<< HEAD
template <typename T>
=======
template<typename T>
>>>>>>> miniblink49
class LocalPointer : public LocalPointerBase<T> {
public:
    /**
     * Constructor takes ownership.
     * @param p simple pointer to an object that is adopted
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    explicit LocalPointer(T* p = NULL)
        : LocalPointerBase<T>(p)
    {
    }
=======
    explicit LocalPointer(T *p=NULL) : LocalPointerBase<T>(p) {}
>>>>>>> miniblink49
    /**
     * Destructor deletes the object it owns.
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    ~LocalPointer()
    {
=======
    ~LocalPointer() {
>>>>>>> miniblink49
        delete LocalPointerBase<T>::ptr;
    }
    /**
     * Deletes the object it owns,
     * and adopts (takes ownership of) the one passed in.
     * @param p simple pointer to an object that is adopted
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    void adoptInstead(T* p)
    {
        delete LocalPointerBase<T>::ptr;
        LocalPointerBase<T>::ptr = p;
=======
    void adoptInstead(T *p) {
        delete LocalPointerBase<T>::ptr;
        LocalPointerBase<T>::ptr=p;
>>>>>>> miniblink49
    }
};

/**
 * "Smart pointer" class, deletes objects via the C++ array delete[] operator.
 * For most methods see the LocalPointerBase base class.
 * Adds operator[] for array item access.
 *
 * Usage example:
 * \code
 * LocalArray<UnicodeString> a(new UnicodeString[2]);
 * a[0].append((UChar)0x61);
 * if(some condition) { return; }  // no need to explicitly delete the array
 * a.adoptInstead(new UnicodeString[4]);
 * a[3].append((UChar)0x62).append((UChar)0x63).reverse();
 * // no need to explicitly delete the array
 * \endcode
 *
 * @see LocalPointerBase
 * @stable ICU 4.4
 */
<<<<<<< HEAD
template <typename T>
=======
template<typename T>
>>>>>>> miniblink49
class LocalArray : public LocalPointerBase<T> {
public:
    /**
     * Constructor takes ownership.
     * @param p simple pointer to an array of T objects that is adopted
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    explicit LocalArray(T* p = NULL)
        : LocalPointerBase<T>(p)
    {
    }
=======
    explicit LocalArray(T *p=NULL) : LocalPointerBase<T>(p) {}
>>>>>>> miniblink49
    /**
     * Destructor deletes the array it owns.
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    ~LocalArray()
    {
=======
    ~LocalArray() {
>>>>>>> miniblink49
        delete[] LocalPointerBase<T>::ptr;
    }
    /**
     * Deletes the array it owns,
     * and adopts (takes ownership of) the one passed in.
     * @param p simple pointer to an array of T objects that is adopted
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    void adoptInstead(T* p)
    {
        delete[] LocalPointerBase<T>::ptr;
        LocalPointerBase<T>::ptr = p;
=======
    void adoptInstead(T *p) {
        delete[] LocalPointerBase<T>::ptr;
        LocalPointerBase<T>::ptr=p;
>>>>>>> miniblink49
    }
    /**
     * Array item access (writable).
     * No index bounds check.
     * @param i array index
     * @return reference to the array item
     * @stable ICU 4.4
     */
<<<<<<< HEAD
    T& operator[](ptrdiff_t i) const { return LocalPointerBase<T>::ptr[i]; }
=======
    T &operator[](ptrdiff_t i) const { return LocalPointerBase<T>::ptr[i]; }
>>>>>>> miniblink49
};

/**
 * \def U_DEFINE_LOCAL_OPEN_POINTER
 * "Smart pointer" definition macro, deletes objects via the closeFunction.
 * Defines a subclass of LocalPointerBase which works just
 * like LocalPointer<Type> except that this subclass will use the closeFunction
 * rather than the C++ delete operator.
 *
 * Requirement: The closeFunction must tolerate a NULL pointer.
 * (We could add a NULL check here but it is normally redundant.)
 *
 * Usage example:
 * \code
 * LocalUCaseMapPointer csm(ucasemap_open(localeID, options, &errorCode));
 * utf8OutLength=ucasemap_utf8ToLower(csm.getAlias(),
 *     utf8Out, (int32_t)sizeof(utf8Out),
 *     utf8In, utf8InLength, &errorCode);
 * if(U_FAILURE(errorCode)) { return; }  // no need to explicitly delete the UCaseMap
 * \endcode
 *
 * @see LocalPointerBase
 * @see LocalPointer
 * @stable ICU 4.4
 */
#define U_DEFINE_LOCAL_OPEN_POINTER(LocalPointerClassName, Type, closeFunction) \
<<<<<<< HEAD
    class LocalPointerClassName : public LocalPointerBase<Type> {               \
    public:                                                                     \
        explicit LocalPointerClassName(Type* p = NULL)                          \
            : LocalPointerBase<Type>(p)                                         \
        {                                                                       \
        }                                                                       \
        ~LocalPointerClassName() { closeFunction(ptr); }                        \
        void adoptInstead(Type* p)                                              \
        {                                                                       \
            closeFunction(ptr);                                                 \
            ptr = p;                                                            \
        }                                                                       \
=======
    class LocalPointerClassName : public LocalPointerBase<Type> { \
    public: \
        explicit LocalPointerClassName(Type *p=NULL) : LocalPointerBase<Type>(p) {} \
        ~LocalPointerClassName() { closeFunction(ptr); } \
        void adoptInstead(Type *p) { \
            closeFunction(ptr); \
            ptr=p; \
        } \
>>>>>>> miniblink49
    }

U_NAMESPACE_END

<<<<<<< HEAD
#endif /* U_SHOW_CPLUSPLUS_API */
#endif /* __LOCALPOINTER_H__ */
=======
#endif  /* U_SHOW_CPLUSPLUS_API */
#endif  /* __LOCALPOINTER_H__ */
>>>>>>> miniblink49
