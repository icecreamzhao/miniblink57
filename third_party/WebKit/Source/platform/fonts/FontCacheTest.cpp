// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/fonts/FontCache.h"

#include "platform/fonts/FontDescription.h"
#include "platform/fonts/SimpleFontData.h"
<<<<<<< HEAD
#include "platform/testing/TestingPlatformSupport.h"
#include "public/platform/Platform.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace blink {

class EmptyPlatform : public TestingPlatformSupport {
public:
    EmptyPlatform() { }
    ~EmptyPlatform() override { }
=======
#include "public/platform/Platform.h"
#include <gtest/gtest.h>

namespace blink {

class EmptyPlatform : public Platform {
public:
    EmptyPlatform() {}
    ~EmptyPlatform() override {}
    void cryptographicallyRandomValues(unsigned char* buffer, size_t length) override { }
>>>>>>> miniblink49
};

TEST(FontCache, getLastResortFallbackFont)
{
    FontCache* fontCache = FontCache::fontCache();
    ASSERT_TRUE(fontCache);

<<<<<<< HEAD
    EmptyPlatform platform;
=======
    Platform* oldPlatform = Platform::current();
    OwnPtr<EmptyPlatform> platform = adoptPtr(new EmptyPlatform);
    Platform::initialize(platform.get());
>>>>>>> miniblink49

    FontDescription fontDescription;
    fontDescription.setGenericFamily(FontDescription::StandardFamily);
    RefPtr<SimpleFontData> fontData = fontCache->getLastResortFallbackFont(fontDescription, Retain);
    EXPECT_TRUE(fontData);

    fontDescription.setGenericFamily(FontDescription::SansSerifFamily);
    fontData = fontCache->getLastResortFallbackFont(fontDescription, Retain);
    EXPECT_TRUE(fontData);
<<<<<<< HEAD
=======

    Platform::initialize(oldPlatform);
>>>>>>> miniblink49
}

} // namespace blink
