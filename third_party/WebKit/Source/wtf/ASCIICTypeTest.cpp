// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "wtf/ASCIICType.h"

#include "testing/gtest/include/gtest/gtest.h"
=======
#include "config.h"
#include "wtf/ASCIICType.h"

#include <gtest/gtest.h>
>>>>>>> miniblink49

namespace WTF {

TEST(ASCIICTypeTest, ASCIICaseFoldTable)
{
    LChar symbol = 0xff;
    while (symbol--) {
        EXPECT_EQ(toASCIILower<LChar>(symbol), ASCIICaseFoldTable[symbol]);
    }
}

<<<<<<< HEAD
} // namespace WTF
=======
}
>>>>>>> miniblink49
