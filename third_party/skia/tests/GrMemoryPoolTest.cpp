/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Test.h"
// This is a GPU-backend specific test
#if SK_SUPPORT_GPU
#include "GrMemoryPool.h"
#include "SkRandom.h"
#include "SkTDArray.h"
#include "SkTemplates.h"

// A is the top of an inheritance tree of classes that overload op new and
// and delete to use a GrMemoryPool. The objects have values of different types
// that can be set and checked.
class A {
public:
    A() {};
<<<<<<< HEAD
    virtual void setValues(int v)
    {
        fChar = static_cast<char>(v);
    }
    virtual bool checkValues(int v)
    {
=======
    virtual void setValues(int v) {
        fChar = static_cast<char>(v);
    }
    virtual bool checkValues(int v) {
>>>>>>> miniblink49
        return fChar == static_cast<char>(v);
    }
    virtual ~A() {};

<<<<<<< HEAD
    void* operator new(size_t size)
    {
=======
    void* operator new(size_t size) {
>>>>>>> miniblink49
        if (!gPool.get()) {
            return ::operator new(size);
        } else {
            return gPool->allocate(size);
        }
    }

<<<<<<< HEAD
    void operator delete(void* p)
    {
=======
    void operator delete(void* p) {
>>>>>>> miniblink49
        if (!gPool.get()) {
            ::operator delete(p);
        } else {
            return gPool->release(p);
        }
    }

    static A* Create(SkRandom* r);

<<<<<<< HEAD
    static void SetAllocator(size_t preallocSize, size_t minAllocSize)
    {
=======
    static void SetAllocator(size_t preallocSize, size_t minAllocSize) {
>>>>>>> miniblink49
        GrMemoryPool* pool = new GrMemoryPool(preallocSize, minAllocSize);
        gPool.reset(pool);
    }

<<<<<<< HEAD
    static void ResetAllocator()
    {
        gPool.reset(nullptr);
=======
    static void ResetAllocator() {
        gPool.reset(NULL);
>>>>>>> miniblink49
    }

private:
    static SkAutoTDelete<GrMemoryPool> gPool;
    char fChar;
};

SkAutoTDelete<GrMemoryPool> A::gPool;

class B : public A {
public:
    B() {};
<<<<<<< HEAD
    virtual void setValues(int v)
    {
        fDouble = static_cast<double>(v);
        this->INHERITED::setValues(v);
    }
    virtual bool checkValues(int v)
    {
        return fDouble == static_cast<double>(v) && this->INHERITED::checkValues(v);
=======
    virtual void setValues(int v) {
        fDouble = static_cast<double>(v);
        this->INHERITED::setValues(v);
    }
    virtual bool checkValues(int v) {
        return fDouble == static_cast<double>(v) &&
               this->INHERITED::checkValues(v);
>>>>>>> miniblink49
    }
    virtual ~B() {};

private:
    double fDouble;

    typedef A INHERITED;
};

class C : public A {
public:
    C() {};
<<<<<<< HEAD
    virtual void setValues(int v)
    {
        fInt64 = static_cast<int64_t>(v);
        this->INHERITED::setValues(v);
    }
    virtual bool checkValues(int v)
    {
        return fInt64 == static_cast<int64_t>(v) && this->INHERITED::checkValues(v);
=======
    virtual void setValues(int v) {
        fInt64 = static_cast<int64_t>(v);
        this->INHERITED::setValues(v);
    }
    virtual bool checkValues(int v) {
        return fInt64 == static_cast<int64_t>(v) &&
               this->INHERITED::checkValues(v);
>>>>>>> miniblink49
    }
    virtual ~C() {};

private:
    int64_t fInt64;

    typedef A INHERITED;
};

// D derives from C and owns a dynamically created B
class D : public C {
public:
<<<<<<< HEAD
    D()
    {
        fB = new B();
    }
    virtual void setValues(int v)
    {
        fVoidStar = reinterpret_cast<void*>(static_cast<intptr_t>(v));
        this->INHERITED::setValues(v);
        fB->setValues(v);
    }
    virtual bool checkValues(int v)
    {
        return fVoidStar == reinterpret_cast<void*>(static_cast<intptr_t>(v)) && fB->checkValues(v) && this->INHERITED::checkValues(v);
    }
    virtual ~D()
    {
        delete fB;
    }

private:
    void* fVoidStar;
    B* fB;
=======
    D() {
        fB = new B();
    }
    virtual void setValues(int v) {
        fVoidStar = reinterpret_cast<void*>(v);
        this->INHERITED::setValues(v);
        fB->setValues(v);
    }
    virtual bool checkValues(int v) {
        return fVoidStar == reinterpret_cast<void*>(v) &&
               fB->checkValues(v) &&
               this->INHERITED::checkValues(v);
    }
    virtual ~D() {
        delete fB;
    }
private:
    void*   fVoidStar;
    B*      fB;
>>>>>>> miniblink49

    typedef C INHERITED;
};

class E : public A {
public:
<<<<<<< HEAD
    E() { }
    virtual void setValues(int v)
    {
=======
    E() {}
    virtual void setValues(int v) {
>>>>>>> miniblink49
        for (size_t i = 0; i < SK_ARRAY_COUNT(fIntArray); ++i) {
            fIntArray[i] = v;
        }
        this->INHERITED::setValues(v);
    }
<<<<<<< HEAD
    virtual bool checkValues(int v)
    {
=======
    virtual bool checkValues(int v) {
>>>>>>> miniblink49
        bool ok = true;
        for (size_t i = 0; ok && i < SK_ARRAY_COUNT(fIntArray); ++i) {
            if (fIntArray[i] != v) {
                ok = false;
            }
        }
        return ok && this->INHERITED::checkValues(v);
    }
<<<<<<< HEAD
    virtual ~E() { }

private:
    int fIntArray[20];
=======
    virtual ~E() {}
private:
    int   fIntArray[20];
>>>>>>> miniblink49

    typedef A INHERITED;
};

<<<<<<< HEAD
A* A::Create(SkRandom* r)
{
    switch (r->nextRangeU(0, 4)) {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    case 3:
        return new D;
    case 4:
        return new E;
    default:
        // suppress warning
        return nullptr;
=======
A* A::Create(SkRandom* r) {
    switch (r->nextRangeU(0, 4)) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        case 3:
            return new D;
        case 4:
            return new E;
        default:
            // suppress warning
            return NULL;
>>>>>>> miniblink49
    }
}

struct Rec {
    A* fInstance;
    int fValue;
};

<<<<<<< HEAD
DEF_TEST(GrMemoryPool, reporter)
{
    // prealloc and min alloc sizes for the pool
    static const size_t gSizes[][2] = {
        { 0, 0 },
        { 10 * sizeof(A), 20 * sizeof(A) },
        { 100 * sizeof(A), 100 * sizeof(A) },
        { 500 * sizeof(A), 500 * sizeof(A) },
        { 10000 * sizeof(A), 0 },
        { 1, 100 * sizeof(A) },
    };
    // different percentages of creation vs deletion
    static const float gCreateFraction[] = { 1.f, .95f, 0.75f, .5f };
=======
DEF_TEST(GrMemoryPool, reporter) {
    // prealloc and min alloc sizes for the pool
    static const size_t gSizes[][2] = {
        {0, 0},
        {10 * sizeof(A), 20 * sizeof(A)},
        {100 * sizeof(A), 100 * sizeof(A)},
        {500 * sizeof(A), 500 * sizeof(A)},
        {10000 * sizeof(A), 0},
        {1, 100 * sizeof(A)},
    };
    // different percentages of creation vs deletion
    static const float gCreateFraction[] = {1.f, .95f, 0.75f, .5f};
>>>>>>> miniblink49
    // number of create/destroys per test
    static const int kNumIters = 20000;
    // check that all the values stored in A objects are correct after this
    // number of iterations
    static const int kCheckPeriod = 500;

    SkRandom r;
    for (size_t s = 0; s < SK_ARRAY_COUNT(gSizes); ++s) {
        A::SetAllocator(gSizes[s][0], gSizes[s][1]);
        for (size_t c = 0; c < SK_ARRAY_COUNT(gCreateFraction); ++c) {
            SkTDArray<Rec> instanceRecs;
            for (int i = 0; i < kNumIters; ++i) {
                float createOrDestroy = r.nextUScalar1();
<<<<<<< HEAD
                if (createOrDestroy < gCreateFraction[c] || 0 == instanceRecs.count()) {
=======
                if (createOrDestroy < gCreateFraction[c] ||
                    0 == instanceRecs.count()) {
>>>>>>> miniblink49
                    Rec* rec = instanceRecs.append();
                    rec->fInstance = A::Create(&r);
                    rec->fValue = static_cast<int>(r.nextU());
                    rec->fInstance->setValues(rec->fValue);
                } else {
                    int d = r.nextRangeU(0, instanceRecs.count() - 1);
                    Rec& rec = instanceRecs[d];
                    REPORTER_ASSERT(reporter, rec.fInstance->checkValues(rec.fValue));
                    delete rec.fInstance;
                    instanceRecs.removeShuffle(d);
                }
                if (0 == i % kCheckPeriod) {
                    for (int r = 0; r < instanceRecs.count(); ++r) {
                        Rec& rec = instanceRecs[r];
                        REPORTER_ASSERT(reporter, rec.fInstance->checkValues(rec.fValue));
                    }
                }
            }
            for (int i = 0; i < instanceRecs.count(); ++i) {
                Rec& rec = instanceRecs[i];
                REPORTER_ASSERT(reporter, rec.fInstance->checkValues(rec.fValue));
                delete rec.fInstance;
            }
        }
    }
}

#endif
