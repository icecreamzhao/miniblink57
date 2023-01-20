/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrPendingProgramElement_DEFINED
#define GrPendingProgramElement_DEFINED

<<<<<<< HEAD
#include "GrTypes.h"
#include "SkRefCnt.h"
=======
#include "SkRefCnt.h"
#include "GrTypes.h"
>>>>>>> miniblink49

/**
 * Helper for owning a pending execution on a GrProgramElement. Using this rather than ref allows
 * resources that are owned by the program element to be correctly tracked as having pending reads
 * and writes rather than refs.
 */
<<<<<<< HEAD
template <typename T>
class GrPendingProgramElement : SkNoncopyable {
public:
    GrPendingProgramElement()
        : fObj(nullptr) {};

    // Adds a pending execution on obj.
    explicit GrPendingProgramElement(T* obj)
        : fObj(obj)
    {
=======
template <typename T> class GrPendingProgramElement : SkNoncopyable {
public:
    GrPendingProgramElement() : fObj(NULL) { };

    // Adds a pending execution on obj.
    explicit GrPendingProgramElement(T* obj) : fObj(obj)  {
>>>>>>> miniblink49
        if (obj) {
            obj->addPendingExecution();
        }
    }

<<<<<<< HEAD
    void reset(T* obj)
    {
=======
    void reset(T* obj) {
>>>>>>> miniblink49
        if (obj) {
            obj->addPendingExecution();
        }
        if (fObj) {
            fObj->completedExecution();
        }
        fObj = obj;
    }

    T* get() const { return fObj; }
    operator T*() { return fObj; }

<<<<<<< HEAD
    T* operator->() const { return fObj; }

    ~GrPendingProgramElement()
    {
=======
    T *operator->() const { return fObj; }

    ~GrPendingProgramElement() {
>>>>>>> miniblink49
        if (fObj) {
            fObj->completedExecution();
        }
    }

private:
<<<<<<< HEAD
    T* fObj;
=======
    T*   fObj;
>>>>>>> miniblink49

    typedef SkNoncopyable INHERITED;
};
#endif
