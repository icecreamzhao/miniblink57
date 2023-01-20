<<<<<<< HEAD
/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

=======
>>>>>>> miniblink49
#ifndef RecordTestUtils_DEFINED
#define RecordTestUtils_DEFINED

#include "SkRecord.h"
#include "SkRecords.h"
<<<<<<< HEAD
#include "Test.h"

// If the command we're reading is a U, set ptr to it, otherwise set it to nullptr.
template <typename U>
struct ReadAs {
    ReadAs()
        : ptr(nullptr)
        , type(SkRecords::Type(~0))
    {
    }
=======

// If the command we're reading is a U, set ptr to it, otherwise set it to NULL.
template <typename U>
struct ReadAs {
    ReadAs() : ptr(NULL), type(SkRecords::Type(~0)) {}
>>>>>>> miniblink49

    const U* ptr;
    SkRecords::Type type;

<<<<<<< HEAD
    void operator()(const U& r)
    {
        ptr = &r;
        type = U::kType;
    }
=======
    void operator()(const U& r) { ptr = &r; type = U::kType; }
>>>>>>> miniblink49

    template <typename T>
    void operator()(const T&) { type = U::kType; }
};

// Assert that the ith command in record is of type T, and return it.
template <typename T>
<<<<<<< HEAD
static const T* assert_type(skiatest::Reporter* r, const SkRecord& record, int index)
{
    ReadAs<T> reader;
    record.visit(index, reader);
=======
static const T* assert_type(skiatest::Reporter* r, const SkRecord& record, unsigned index) {
    ReadAs<T> reader;
    record.visit<void>(index, reader);
>>>>>>> miniblink49
    REPORTER_ASSERT(r, T::kType == reader.type);
    REPORTER_ASSERT(r, SkToBool(reader.ptr));
    return reader.ptr;
}

<<<<<<< HEAD
template <typename DrawT>
struct MatchType {
    template <typename T>
    int operator()(const T&) { return 0; }
    int operator()(const DrawT&) { return 1; }
};

template <typename DrawT>
int count_instances_of_type(const SkRecord& record)
{
    MatchType<DrawT> matcher;
    int counter = 0;
    for (int i = 0; i < record.count(); i++) {
        counter += record.visit(i, matcher);
=======
template <typename DrawT> struct MatchType {
    template <typename T> int operator()(const T&) { return 0; }
    int operator()(const DrawT&) { return 1; }
};

template <typename DrawT> int count_instances_of_type(const SkRecord& record) {
    MatchType<DrawT> matcher;
    int counter = 0;
    for (unsigned i = 0; i < record.count(); i++) {
        counter += record.visit<int>(i, matcher);
>>>>>>> miniblink49
    }
    return counter;
}

<<<<<<< HEAD
template <typename DrawT>
int find_first_instances_of_type(const SkRecord& record)
{
    MatchType<DrawT> matcher;
    for (int i = 0; i < record.count(); i++) {
        if (record.visit(i, matcher)) {
=======
template <typename DrawT> int find_first_instances_of_type(const SkRecord& record) {
    MatchType<DrawT> matcher;
    for (unsigned i = 0; i < record.count(); i++) {
        if (record.visit<int>(i, matcher)) {
>>>>>>> miniblink49
            return i;
        }
    }
    return -1;
}

<<<<<<< HEAD
#endif //RecordTestUtils_DEFINED
=======
#endif//RecordTestUtils_DEFINED
>>>>>>> miniblink49
