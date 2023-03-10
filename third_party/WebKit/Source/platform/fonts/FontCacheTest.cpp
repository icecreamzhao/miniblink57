// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "platform/fonts/FontCache.h"

#include "platform/fonts/FontDescription.h"
#include "platform/fonts/SimpleFontData.h"
#include "platform/testing/TestingPlatformSupport.h"
#include "public/platform/Platform.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace blink {

class EmptyPlatform : public TestingPlatformSupport {
public:
    EmptyPlatform() { }
    ~EmptyPlatform() override { }
};

TEST(FontCache, getLastResortFallbackFont)
{
    FontCache* fontCache = FontCache::fontCache();
    ASSERT_TRUE(fontCache);

    EmptyPlatform platform;

    FontDescription fontDescription;
    fontDescription.setGenericFamily(FontDescription::StandardFamily);
    RefPtr<SimpleFontData> fontData = fontCache->getLastResortFallbackFont(fontDescription, Retain);
    EXPECT_TRUE(fontData);

    fontDescription.setGenericFamily(FontDescription::SansSerifFamily);
    fontData = fontCache->getLastResortFallbackFont(fontDescription, Retain);
    EXPECT_TRUE(fontData);
}

} // namespace blink
