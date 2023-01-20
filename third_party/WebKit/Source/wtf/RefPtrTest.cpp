// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "wtf/RefPtr.h"

#include "testing/gtest/include/gtest/gtest.h"
#include "wtf/RefCounted.h"
#include "wtf/text/StringImpl.h"
=======
#include "config.h"
#include "wtf/RefPtr.h"

#include "wtf/text/StringImpl.h"
#include <gtest/gtest.h>
>>>>>>> miniblink49

namespace WTF {

TEST(RefPtrTest, Basic)
{
    RefPtr<StringImpl> string;
    EXPECT_TRUE(!string);
    string = StringImpl::create("test");
    EXPECT_TRUE(!!string);
    string.clear();
    EXPECT_TRUE(!string);
}

TEST(RefPtrTest, MoveAssignmentOperator)
{
    RefPtr<StringImpl> a = StringImpl::create("a");
    RefPtr<StringImpl> b = StringImpl::create("b");
<<<<<<< HEAD
    b = std::move(a);
=======
    // FIXME: Instead of explicitly casting to RefPtr<StringImpl>&& here, we should use std::move, but that
    // requires us to have a standard library that supports move semantics.
    b = static_cast<RefPtr<StringImpl>&&>(a);
>>>>>>> miniblink49
    EXPECT_TRUE(!!b);
    EXPECT_TRUE(!a);
}

<<<<<<< HEAD
class RefCountedClass : public RefCounted<RefCountedClass> {
};

TEST(RefPtrTest, ConstObject)
{
    // This test is only to ensure we force the compilation of a const RefCounted
    // object to ensure the generated code compiles.
    RefPtr<const RefCountedClass> ptrToConst = adoptRef(new RefCountedClass());
}

=======
>>>>>>> miniblink49
} // namespace WTF
