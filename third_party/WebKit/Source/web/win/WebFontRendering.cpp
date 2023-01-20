// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "public/web/win/WebFontRendering.h"

#include "platform/fonts/FontCache.h"

namespace blink {

// static
<<<<<<< HEAD
void WebFontRendering::setSkiaFontManager(sk_sp<SkFontMgr> fontMgr)
{
    FontCache::setFontManager(std::move(fontMgr));
=======
void WebFontRendering::setUseDirectWrite(bool useDirectWrite)
{
    FontCache::setUseDirectWrite(useDirectWrite);
}

// static
void WebFontRendering::setDirectWriteFactory(IDWriteFactory* factory)
{
    FontCache::setDirectWriteFactory(factory);
>>>>>>> miniblink49
}

// static
void WebFontRendering::setDeviceScaleFactor(float deviceScaleFactor)
{
<<<<<<< HEAD
#if OS(WIN)
    FontCache::setDeviceScaleFactor(deviceScaleFactor);
#endif
=======
    FontCache::setDeviceScaleFactor(deviceScaleFactor);
}

// static
void WebFontRendering::setUseSubpixelPositioning(bool useSubpixelPositioning)
{
    FontCache::setUseSubpixelPositioning(useSubpixelPositioning);
>>>>>>> miniblink49
}

// static
void WebFontRendering::addSideloadedFontForTesting(SkTypeface* typeface)
{
<<<<<<< HEAD
#if OS(WIN)
    FontCache::addSideloadedFontForTesting(typeface);
#endif
=======
    FontCache::addSideloadedFontForTesting(typeface);
>>>>>>> miniblink49
}

// static
void WebFontRendering::setMenuFontMetrics(const wchar_t* familyName, int32_t fontHeight)
{
<<<<<<< HEAD
#if OS(WIN)
    FontCache::setMenuFontMetrics(familyName, fontHeight);
#endif
=======
    FontCache::setMenuFontMetrics(familyName, fontHeight);
>>>>>>> miniblink49
}

// static
void WebFontRendering::setSmallCaptionFontMetrics(const wchar_t* familyName, int32_t fontHeight)
{
<<<<<<< HEAD
#if OS(WIN)
    FontCache::setSmallCaptionFontMetrics(familyName, fontHeight);
#endif
=======
    FontCache::setSmallCaptionFontMetrics(familyName, fontHeight);
>>>>>>> miniblink49
}

// static
void WebFontRendering::setStatusFontMetrics(const wchar_t* familyName, int32_t fontHeight)
{
<<<<<<< HEAD
#if OS(WIN)
    FontCache::setStatusFontMetrics(familyName, fontHeight);
#endif
}

// static
void WebFontRendering::setAntialiasedTextEnabled(bool enabled)
{
#if OS(WIN)
    FontCache::setAntialiasedTextEnabled(enabled);
#endif
}

// static
void WebFontRendering::setLCDTextEnabled(bool enabled)
{
#if OS(WIN)
    FontCache::setLCDTextEnabled(enabled);
#endif
}

// static
void WebFontRendering::setUseSkiaFontFallback(bool useSkiaFontFallback)
{
#if OS(WIN)
    FontCache::setUseSkiaFontFallback(useSkiaFontFallback);
#endif
=======
    FontCache::setStatusFontMetrics(familyName, fontHeight);
}

// static
void WebFontRendering::setLCDOrder(SkFontHost::LCDOrder order)
{
    SkFontHost::SetSubpixelOrder(order);
}

// static
void WebFontRendering::setLCDOrientation(SkFontHost::LCDOrientation orientation)
{
    SkFontHost::SetSubpixelOrientation(orientation);
>>>>>>> miniblink49
}

} // namespace blink
