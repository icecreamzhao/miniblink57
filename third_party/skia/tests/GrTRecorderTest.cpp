/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMatrix.h"
#include "SkRandom.h"
#include "SkString.h"
#include "Test.h"

#if SK_SUPPORT_GPU

#include "GrTRecorder.h"

////////////////////////////////////////////////////////////////////////////////

static int activeRecorderItems = 0;

class IntWrapper {
public:
<<<<<<< HEAD
    IntWrapper() { }
    IntWrapper(int value)
        : fValue(value)
    {
    }
    operator int() { return fValue; }

=======
    IntWrapper() {}
    IntWrapper(int value) : fValue(value) {}
    operator int() { return fValue; }
>>>>>>> miniblink49
private:
    int fValue;
};

<<<<<<< HEAD
static void test_empty_back_and_pop(skiatest::Reporter* reporter)
{
=======
static void test_empty_back_and_pop(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    SkRandom rand;
    for (int data = 0; data < 2; ++data) {
        // Do this with different starting sizes to have different alignment between blocks and pops.
        // pops. We want to test poping the first guy off, guys in the middle of the block, and the
        // first guy on a non-head block.
        for (int j = 0; j < 8; ++j) {
            GrTRecorder<IntWrapper, int> recorder(j);

            REPORTER_ASSERT(reporter, recorder.empty());

            for (int i = 0; i < 100; ++i) {
                if (data) {
<<<<<<< HEAD
                    REPORTER_ASSERT(reporter, i == *GrNEW_APPEND_TO_RECORDER(recorder, IntWrapper, (i)));
                } else {
                    REPORTER_ASSERT(reporter, i == *GrNEW_APPEND_WITH_DATA_TO_RECORDER(recorder, IntWrapper, (i), rand.nextULessThan(10)));
=======
                    REPORTER_ASSERT(reporter, i == *GrNEW_APPEND_TO_RECORDER(recorder, 
                                                                             IntWrapper, (i)));
                } else {
                    REPORTER_ASSERT(reporter, i ==
                                    *GrNEW_APPEND_WITH_DATA_TO_RECORDER(recorder,
                                                                        IntWrapper, (i),
                                                                        rand.nextULessThan(10)));
>>>>>>> miniblink49
                }
                REPORTER_ASSERT(reporter, !recorder.empty());
                REPORTER_ASSERT(reporter, i == recorder.back());
                if (0 == (i % 7)) {
                    recorder.pop_back();
                    if (i > 0) {
                        REPORTER_ASSERT(reporter, !recorder.empty());
<<<<<<< HEAD
                        REPORTER_ASSERT(reporter, i - 1 == recorder.back());
=======
                        REPORTER_ASSERT(reporter, i-1 == recorder.back());
>>>>>>> miniblink49
                    }
                }
            }

            REPORTER_ASSERT(reporter, !recorder.empty());
            recorder.reset();
            REPORTER_ASSERT(reporter, recorder.empty());
        }
    }
}

struct ExtraData {
    typedef GrTRecorder<ExtraData, int> Recorder;

<<<<<<< HEAD
    ExtraData(int i)
        : fData(i)
    {
=======
    ExtraData(int i) : fData(i) {
>>>>>>> miniblink49
        int* extraData = this->extraData();
        for (int j = 0; j < i; j++) {
            extraData[j] = i;
        }
        ++activeRecorderItems;
    }
<<<<<<< HEAD
    ~ExtraData()
    {
        --activeRecorderItems;
    }
    int* extraData()
    {
=======
    ~ExtraData() {
        --activeRecorderItems;
    }
    int* extraData() {
>>>>>>> miniblink49
        return reinterpret_cast<int*>(Recorder::GetDataForItem(this));
    }
    int fData;
};

<<<<<<< HEAD
static void test_extra_data(skiatest::Reporter* reporter)
{
=======
static void test_extra_data(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    ExtraData::Recorder recorder(0);
    for (int i = 0; i < 100; ++i) {
        GrNEW_APPEND_WITH_DATA_TO_RECORDER(recorder, ExtraData, (i), i * sizeof(int));
    }
    REPORTER_ASSERT(reporter, 100 == activeRecorderItems);

    ExtraData::Recorder::Iter iter(recorder);
    for (int i = 0; i < 100; ++i) {
        REPORTER_ASSERT(reporter, iter.next());
        REPORTER_ASSERT(reporter, i == iter->fData);
        for (int j = 0; j < i; j++) {
            REPORTER_ASSERT(reporter, i == iter->extraData()[j]);
        }
    }
    REPORTER_ASSERT(reporter, !iter.next());

    ExtraData::Recorder::ReverseIter reverseIter(recorder);
    for (int i = 99; i >= 0; --i) {
        REPORTER_ASSERT(reporter, i == reverseIter->fData);
        for (int j = 0; j < i; j++) {
            REPORTER_ASSERT(reporter, i == reverseIter->extraData()[j]);
        }
        REPORTER_ASSERT(reporter, reverseIter.previous() == !!i);
    }

    recorder.reset();
    REPORTER_ASSERT(reporter, 0 == activeRecorderItems);
}

enum ClassType {
    kBase_ClassType,
    kSubclass_ClassType,
    kSubSubclass_ClassType,
    kSubclassExtraData_ClassType,
    kSubclassEmpty_ClassType,

    kNumClassTypes
};

class Base {
public:
    typedef GrTRecorder<Base, void*> Recorder;

<<<<<<< HEAD
    Base()
    {
=======
    Base() {
>>>>>>> miniblink49
        fMatrix.reset();
        ++activeRecorderItems;
    }

    virtual ~Base() { --activeRecorderItems; }

    virtual ClassType getType() { return kBase_ClassType; }

<<<<<<< HEAD
    virtual void validate(skiatest::Reporter* reporter) const
    {
=======
    virtual void validate(skiatest::Reporter* reporter) const {
>>>>>>> miniblink49
        REPORTER_ASSERT(reporter, fMatrix.isIdentity());
    }

private:
    SkMatrix fMatrix;
};

class Subclass : public Base {
public:
<<<<<<< HEAD
    Subclass()
        : fString("Lorem ipsum dolor sit amet")
    {
    }

    virtual ClassType getType() { return kSubclass_ClassType; }

    virtual void validate(skiatest::Reporter* reporter) const
    {
=======
    Subclass() : fString("Lorem ipsum dolor sit amet") {}

    virtual ClassType getType() { return kSubclass_ClassType; }

    virtual void validate(skiatest::Reporter* reporter) const {
>>>>>>> miniblink49
        Base::validate(reporter);
        REPORTER_ASSERT(reporter, !strcmp("Lorem ipsum dolor sit amet", fString.c_str()));
    }

private:
    SkString fString;
};

class SubSubclass : public Subclass {
public:
<<<<<<< HEAD
    SubSubclass()
        : fInt(1234)
        , fFloat(1.234f)
    {
    }

    virtual ClassType getType() { return kSubSubclass_ClassType; }

    virtual void validate(skiatest::Reporter* reporter) const
    {
=======
    SubSubclass() : fInt(1234), fFloat(1.234f) {}

    virtual ClassType getType() { return kSubSubclass_ClassType; }

    virtual void validate(skiatest::Reporter* reporter) const {
>>>>>>> miniblink49
        Subclass::validate(reporter);
        REPORTER_ASSERT(reporter, 1234 == fInt);
        REPORTER_ASSERT(reporter, 1.234f == fFloat);
    }

private:
    int fInt;
    float fFloat;
};

class SubclassExtraData : public Base {
public:
<<<<<<< HEAD
    SubclassExtraData(int length)
        : fLength(length)
    {
=======
    SubclassExtraData(int length) : fLength(length) {
>>>>>>> miniblink49
        int* data = reinterpret_cast<int*>(Recorder::GetDataForItem(this));
        for (int i = 0; i < fLength; ++i) {
            data[i] = ValueAt(i);
        }
    }

    virtual ClassType getType() { return kSubclassExtraData_ClassType; }

<<<<<<< HEAD
    virtual void validate(skiatest::Reporter* reporter) const
    {
=======
    virtual void validate(skiatest::Reporter* reporter) const {
>>>>>>> miniblink49
        Base::validate(reporter);
        const int* data = reinterpret_cast<const int*>(Recorder::GetDataForItem(this));
        for (int i = 0; i < fLength; ++i) {
            REPORTER_ASSERT(reporter, ValueAt(i) == data[i]);
        }
    }

private:
    static int ValueAt(uint64_t i) { return static_cast<int>(123456789 + 987654321 * i); }
    int fLength;
};

class SubclassEmpty : public Base {
public:
    virtual ClassType getType() { return kSubclassEmpty_ClassType; }
};

class Order {
public:
    Order() { this->reset(); }
    void reset() { fCurrent = 0; }
<<<<<<< HEAD
    ClassType next()
    {
        fCurrent = 1664525 * fCurrent + 1013904223;
        return static_cast<ClassType>(fCurrent % kNumClassTypes);
    }

=======
    ClassType next() {
        fCurrent = 1664525 * fCurrent + 1013904223;
        return static_cast<ClassType>(fCurrent % kNumClassTypes);
    }
>>>>>>> miniblink49
private:
    uint32_t fCurrent;
};
static void test_subclasses_iters(skiatest::Reporter*, Order&, Base::Recorder::Iter&,
<<<<<<< HEAD
    Base::Recorder::ReverseIter&, int = 0);
static void test_subclasses(skiatest::Reporter* reporter)
{
=======
                                  Base::Recorder::ReverseIter&, int = 0);
static void test_subclasses(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    Base::Recorder recorder(1024);

    Order order;
    for (int i = 0; i < 1000; i++) {
        switch (order.next()) {
<<<<<<< HEAD
        case kBase_ClassType:
            GrNEW_APPEND_TO_RECORDER(recorder, Base, ());
            break;

        case kSubclass_ClassType:
            GrNEW_APPEND_TO_RECORDER(recorder, Subclass, ());
            break;

        case kSubSubclass_ClassType:
            GrNEW_APPEND_TO_RECORDER(recorder, SubSubclass, ());
            break;

        case kSubclassExtraData_ClassType:
            GrNEW_APPEND_WITH_DATA_TO_RECORDER(recorder, SubclassExtraData, (i), sizeof(int) * i);
            break;

        case kSubclassEmpty_ClassType:
            GrNEW_APPEND_TO_RECORDER(recorder, SubclassEmpty, ());
            break;

        default:
            ERRORF(reporter, "Invalid class type");
            break;
=======
            case kBase_ClassType:
                GrNEW_APPEND_TO_RECORDER(recorder, Base, ());
                break;

            case kSubclass_ClassType:
                GrNEW_APPEND_TO_RECORDER(recorder, Subclass, ());
                break;

            case kSubSubclass_ClassType:
                GrNEW_APPEND_TO_RECORDER(recorder, SubSubclass, ());
                break;

            case kSubclassExtraData_ClassType:
                GrNEW_APPEND_WITH_DATA_TO_RECORDER(recorder, SubclassExtraData, (i), sizeof(int) * i);
                break;

            case kSubclassEmpty_ClassType:
                GrNEW_APPEND_TO_RECORDER(recorder, SubclassEmpty, ());
                break;

            default:
                ERRORF(reporter, "Invalid class type");
                break;
>>>>>>> miniblink49
        }
    }
    REPORTER_ASSERT(reporter, 1000 == activeRecorderItems);

    order.reset();
    Base::Recorder::Iter iter(recorder);
    Base::Recorder::ReverseIter reverseIter(recorder);

    test_subclasses_iters(reporter, order, iter, reverseIter);

    REPORTER_ASSERT(reporter, !iter.next());

    // Don't reset the recorder. It should automatically destruct all its items.
}
static void test_subclasses_iters(skiatest::Reporter* reporter, Order& order,
<<<<<<< HEAD
    Base::Recorder::Iter& iter,
    Base::Recorder::ReverseIter& reverseIter, int i)
{
=======
                                  Base::Recorder::Iter& iter,
                                  Base::Recorder::ReverseIter& reverseIter, int i) {
>>>>>>> miniblink49
    if (i >= 1000) {
        return;
    }

    ClassType classType = order.next();

    REPORTER_ASSERT(reporter, iter.next());
    REPORTER_ASSERT(reporter, classType == iter->getType());
    iter->validate(reporter);

    test_subclasses_iters(reporter, order, iter, reverseIter, i + 1);

    REPORTER_ASSERT(reporter, classType == reverseIter->getType());
    reverseIter->validate(reporter);
    REPORTER_ASSERT(reporter, reverseIter.previous() == !!i);
}

<<<<<<< HEAD
DEF_GPUTEST(GrTRecorder, reporter, factory)
{
=======
DEF_GPUTEST(GrTRecorder, reporter, factory) {
>>>>>>> miniblink49
    test_empty_back_and_pop(reporter);

    test_extra_data(reporter);
    REPORTER_ASSERT(reporter, 0 == activeRecorderItems); // test_extra_data should call reset().

    test_subclasses(reporter);
    REPORTER_ASSERT(reporter, 0 == activeRecorderItems); // Ensure ~GrTRecorder invokes dtors.
}

#endif
