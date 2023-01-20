<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkTLazy_DEFINED
#define SkTLazy_DEFINED

#include "../private/SkTemplates.h"
#include "SkTypes.h"
#include <new>
#include <utility>
=======


#ifndef SkTLazy_DEFINED
#define SkTLazy_DEFINED

#include "SkTypes.h"
#include <new>

template <typename T> class SkTLazy;
template <typename T> void* operator new(size_t, SkTLazy<T>* lazy);
>>>>>>> miniblink49

/**
 *  Efficient way to defer allocating/initializing a class until it is needed
 *  (if ever).
 */
<<<<<<< HEAD
template <typename T>
class SkTLazy {
public:
    SkTLazy()
        : fPtr(NULL)
    {
    }

    explicit SkTLazy(const T* src)
        : fPtr(NULL)
    {
        if (src) {
            fPtr = new (fStorage.get()) T(*src);
        }
    }

    SkTLazy(const SkTLazy<T>& src)
        : fPtr(NULL)
    {
        if (src.isValid()) {
            fPtr = new (fStorage.get()) T(*src.get());
=======
template <typename T> class SkTLazy {
public:
    SkTLazy() : fPtr(NULL) {}

    explicit SkTLazy(const T* src) : fPtr(NULL) {
        if (src) {
            fPtr = new (fStorage) T(*src);
        }
    }

    SkTLazy(const SkTLazy<T>& src) : fPtr(NULL) {
        if (src.isValid()) {
            fPtr = new (fStorage) T(*src->get());
>>>>>>> miniblink49
        } else {
            fPtr = NULL;
        }
    }

<<<<<<< HEAD
    ~SkTLazy()
    {
=======
    ~SkTLazy() {
>>>>>>> miniblink49
        if (this->isValid()) {
            fPtr->~T();
        }
    }

    /**
<<<<<<< HEAD
     *  Return a pointer to an instance of the class initialized with 'args'.
     *  If a previous instance had been initialized (either from init() or
     *  set()) it will first be destroyed, so that a freshly initialized
     *  instance is always returned.
     */
    template <typename... Args>
    T* init(Args&&... args)
    {
        if (this->isValid()) {
            fPtr->~T();
        }
        fPtr = new (SkTCast<T*>(fStorage.get())) T(std::forward<Args>(args)...);
=======
     *  Return a pointer to a default-initialized instance of the class. If a
     *  previous instance had been initialized (either from init() or set()) it
     *  will first be destroyed, so that a freshly initialized instance is
     *  always returned.
     */
    T* init() {
        if (this->isValid()) {
            fPtr->~T();
        }
        fPtr = new (SkTCast<T*>(fStorage)) T;
>>>>>>> miniblink49
        return fPtr;
    }

    /**
     *  Copy src into this, and return a pointer to a copy of it. Note this
     *  will always return the same pointer, so if it is called on a lazy that
     *  has already been initialized, then this will copy over the previous
     *  contents.
     */
<<<<<<< HEAD
    T* set(const T& src)
    {
        if (this->isValid()) {
            *fPtr = src;
        } else {
            fPtr = new (SkTCast<T*>(fStorage.get())) T(src);
=======
    T* set(const T& src) {
        if (this->isValid()) {
            *fPtr = src;
        } else {
            fPtr = new (SkTCast<T*>(fStorage)) T(src);
>>>>>>> miniblink49
        }
        return fPtr;
    }

    /**
     * Destroy the lazy object (if it was created via init() or set())
     */
<<<<<<< HEAD
    void reset()
    {
=======
    void reset() {
>>>>>>> miniblink49
        if (this->isValid()) {
            fPtr->~T();
            fPtr = NULL;
        }
    }

    /**
     *  Returns true if a valid object has been initialized in the SkTLazy,
     *  false otherwise.
     */
    bool isValid() const { return SkToBool(fPtr); }

    /**
     * Returns the object. This version should only be called when the caller
     * knows that the object has been initialized.
     */
<<<<<<< HEAD
    T* get() const
    {
        SkASSERT(this->isValid());
        return fPtr;
    }
=======
    T* get() const { SkASSERT(this->isValid()); return fPtr; }
>>>>>>> miniblink49

    /**
     * Like above but doesn't assert if object isn't initialized (in which case
     * NULL is returned).
     */
    T* getMaybeNull() const { return fPtr; }

private:
<<<<<<< HEAD
    T* fPtr; // NULL or fStorage
    SkAlignedSTStorage<1, T> fStorage;
};

=======
    friend void* operator new<T>(size_t, SkTLazy* lazy);

    T*   fPtr; // NULL or fStorage
    char fStorage[sizeof(T)];
};

// Use the below macro (SkNEW_IN_TLAZY) rather than calling this directly
template <typename T> void* operator new(size_t, SkTLazy<T>* lazy) {
    SkASSERT(!lazy->isValid());
    lazy->fPtr = reinterpret_cast<T*>(lazy->fStorage);
    return lazy->fPtr;
}

// Skia doesn't use C++ exceptions but it may be compiled with them enabled. Having an op delete
// to match the op new silences warnings about missing op delete when a constructor throws an
// exception.
template <typename T> void operator delete(void*, SkTLazy<T>*) { SK_CRASH(); }

// Use this to construct a T inside an SkTLazy using a non-default constructor.
#define SkNEW_IN_TLAZY(tlazy_ptr, type_name, args) (new (tlazy_ptr) type_name args)

>>>>>>> miniblink49
/**
 * A helper built on top of SkTLazy to do copy-on-first-write. The object is initialized
 * with a const pointer but provides a non-const pointer accessor. The first time the
 * accessor is called (if ever) the object is cloned.
 *
 * In the following example at most one copy of constThing is made:
 *
 * SkTCopyOnFirstWrite<Thing> thing(&constThing);
 * ...
 * function_that_takes_a_const_thing_ptr(thing); // constThing is passed
 * ...
 * if (need_to_modify_thing()) {
 *    thing.writable()->modifyMe(); // makes a copy of constThing
 * }
 * ...
 * x = thing->readSomething();
 * ...
 * if (need_to_modify_thing_now()) {
 *    thing.writable()->changeMe(); // makes a copy of constThing if we didn't call modifyMe()
 * }
 *
 * consume_a_thing(thing); // could be constThing or a modified copy.
 */
template <typename T>
class SkTCopyOnFirstWrite {
public:
<<<<<<< HEAD
    SkTCopyOnFirstWrite(const T& initial)
        : fObj(&initial)
    {
    }

    SkTCopyOnFirstWrite(const T* initial)
        : fObj(initial)
    {
    }

    // Constructor for delayed initialization.
    SkTCopyOnFirstWrite()
        : fObj(NULL)
    {
    }

    // Should only be called once, and only if the default constructor was used.
    void init(const T& initial)
    {
=======
    SkTCopyOnFirstWrite(const T& initial) : fObj(&initial) {}

    // Constructor for delayed initialization.
    SkTCopyOnFirstWrite() : fObj(NULL) {}

    // Should only be called once, and only if the default constructor was used.
    void init(const T& initial) {
>>>>>>> miniblink49
        SkASSERT(NULL == fObj);
        SkASSERT(!fLazy.isValid());
        fObj = &initial;
    }

    /**
     * Returns a writable T*. The first time this is called the initial object is cloned.
     */
<<<<<<< HEAD
    T* writable()
    {
=======
    T* writable() {
>>>>>>> miniblink49
        SkASSERT(fObj);
        if (!fLazy.isValid()) {
            fLazy.set(*fObj);
            fObj = fLazy.get();
        }
        return const_cast<T*>(fObj);
    }

    /**
     * Operators for treating this as though it were a const pointer.
     */

<<<<<<< HEAD
    const T* operator->() const { return fObj; }

    operator const T*() const { return fObj; }

    const T& operator*() const { return *fObj; }

private:
    const T* fObj;
    SkTLazy<T> fLazy;
=======
    const T *operator->() const { return fObj; }

    operator const T*() const { return fObj; }

    const T& operator *() const { return *fObj; }

private:
    const T*    fObj;
    SkTLazy<T>  fLazy;
>>>>>>> miniblink49
};

#endif
