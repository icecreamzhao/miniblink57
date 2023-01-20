// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "platform/geometry/LayoutRectOutsets.h"

#include "testing/gtest/include/gtest/gtest.h"
=======
#include "config.h"
#include "platform/geometry/LayoutRectOutsets.h"

#include <gtest/gtest.h>
>>>>>>> miniblink49

namespace blink {
namespace {

<<<<<<< HEAD
    TEST(LayoutRectOutsetsTest, LogicalOutsets_Horizontal)
    {
        LayoutRectOutsets outsets(1, 2, 3, 4);
        EXPECT_EQ(LayoutRectOutsets(1, 2, 3, 4),
            outsets.logicalOutsets(WritingMode::kHorizontalTb));
    }

    TEST(LayoutRectOutsetsTest, LogicalOutsets_Vertical)
    {
        LayoutRectOutsets outsets(1, 2, 3, 4);
        EXPECT_EQ(LayoutRectOutsets(4, 3, 2, 1),
            outsets.logicalOutsets(WritingMode::kVerticalLr));
        EXPECT_EQ(LayoutRectOutsets(4, 3, 2, 1),
            outsets.logicalOutsets(WritingMode::kVerticalRl));
    }

    TEST(LayoutRectOutsetsTest, LogicalOutsetsWithFlippedLines)
    {
        LayoutRectOutsets outsets(1, 2, 3, 4);
        EXPECT_EQ(LayoutRectOutsets(1, 2, 3, 4),
            outsets.logicalOutsetsWithFlippedLines(WritingMode::kHorizontalTb));
        EXPECT_EQ(LayoutRectOutsets(2, 3, 4, 1),
            outsets.logicalOutsetsWithFlippedLines(WritingMode::kVerticalLr));
        EXPECT_EQ(LayoutRectOutsets(4, 3, 2, 1),
            outsets.logicalOutsetsWithFlippedLines(WritingMode::kVerticalRl));
    }
=======
TEST(LayoutRectOutsetsTest, LogicalOutsets_Horizontal)
{
    LayoutRectOutsets outsets(1, 2, 3, 4);
    EXPECT_EQ(LayoutRectOutsets(1, 2, 3, 4), outsets.logicalOutsets(TopToBottomWritingMode));
    EXPECT_EQ(LayoutRectOutsets(1, 2, 3, 4), outsets.logicalOutsets(BottomToTopWritingMode));
}

TEST(LayoutRectOutsetsTest, LogicalOutsets_Vertical)
{
    LayoutRectOutsets outsets(1, 2, 3, 4);
    EXPECT_EQ(LayoutRectOutsets(4, 3, 2, 1), outsets.logicalOutsets(LeftToRightWritingMode));
    EXPECT_EQ(LayoutRectOutsets(4, 3, 2, 1), outsets.logicalOutsets(RightToLeftWritingMode));
}

TEST(LayoutRectOutsetsTest, LogicalOutsetsWithFlippedLines)
{
    LayoutRectOutsets outsets(1, 2, 3, 4);
    EXPECT_EQ(LayoutRectOutsets(1, 2, 3, 4), outsets.logicalOutsetsWithFlippedLines(TopToBottomWritingMode));
    EXPECT_EQ(LayoutRectOutsets(3, 2, 1, 4), outsets.logicalOutsetsWithFlippedLines(BottomToTopWritingMode));
    EXPECT_EQ(LayoutRectOutsets(2, 3, 4, 1), outsets.logicalOutsetsWithFlippedLines(LeftToRightWritingMode));
    EXPECT_EQ(LayoutRectOutsets(4, 3, 2, 1), outsets.logicalOutsetsWithFlippedLines(RightToLeftWritingMode));
}
>>>>>>> miniblink49

} // namespace
} // namespace blink
