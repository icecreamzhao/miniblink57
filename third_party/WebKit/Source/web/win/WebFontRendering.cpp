// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "public/web/win/WebFontRendering.h"

#include "platform/fonts/FontCache.h"

namespace blink {

// static
void WebFontRendering::setSkiaFontManager(sk_sp<SkFontMgr> fontMgr)
{
    FontCache::setFontManager(std::move(fontMgr));
}

// static
void WebFontRendering::setDeviceScaleFactor(float deviceScaleFactor)
{
#if OS(WIN)
    FontCache::setDeviceScaleFactor(deviceScaleFactor);
#endif
}

// static
void WebFontRendering::addSideloadedFontForTesting(SkTypeface* typeface)
{
#if OS(WIN)
    FontCache::addSideloadedFontForTesting(typeface);
#endif
}

// static
void WebFontRendering::setMenuFontMetrics(const wchar_t* familyName, int32_t fontHeight)
{
#if OS(WIN)
    FontCache::setMenuFontMetrics(familyName, fontHeight);
#endif
}

// static
void WebFontRendering::setSmallCaptionFontMetrics(const wchar_t* familyName, int32_t fontHeight)
{
#if OS(WIN)
    FontCache::setSmallCaptionFontMetrics(familyName, fontHeight);
#endif
}

// static
void WebFontRendering::setStatusFontMetrics(const wchar_t* familyName, int32_t fontHeight)
{
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
}

} // namespace blink
