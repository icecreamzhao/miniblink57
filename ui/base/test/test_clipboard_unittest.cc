// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/base/test/test_clipboard.h"

#include "testing/gtest/include/gtest/gtest.h"

namespace ui {

struct TestClipboardTraits {
    static Clipboard* Create() { return TestClipboard::CreateForCurrentThread(); }

    static void Destroy(Clipboard* clipboard)
    {
        ASSERT_EQ(Clipboard::GetForCurrentThread(), clipboard);
        Clipboard::DestroyClipboardForCurrentThread();
    }
};

typedef TestClipboardTraits TypesToTest;

} // namespace ui

#include "ui/base/clipboard/clipboard_test_template.h"
