/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkTypes.h"

#if SK_SUPPORT_GPU

#include "GrContext.h"
#include "GrTexture.h"
#include "GrTexturePriv.h"
#include "SkCanvas.h"
#include "SkGr.h"
#include "SkSurface.h"
#include "Test.h"

// Tests that GrSurface::asTexture(), GrSurface::asRenderTarget(), and static upcasting of texture
// and render targets to GrSurface all work as expected.
DEF_GPUTEST_FOR_NULLGL_CONTEXT(GrTextureMipMapInvalidationTest, reporter, ctxInfo)
{
    GrContext* context = ctxInfo.grContext();
    GrSurfaceDesc desc;
    desc.fConfig = kSkia8888_GrPixelConfig;
    desc.fFlags = kRenderTarget_GrSurfaceFlag;
    desc.fWidth = 256;
    desc.fHeight = 256;
    desc.fSampleCnt = 0;
    GrSurface* texRT1 = context->textureProvider()->createTexture(
        desc, SkBudgeted::kNo, nullptr, 0);
    GrSurface* texRT2 = context->textureProvider()->createTexture(
        desc, SkBudgeted::kNo, nullptr, 0);
    REPORTER_ASSERT(reporter, nullptr != texRT1);
    REPORTER_ASSERT(reporter, nullptr != texRT2);
    GrTexture* tex = texRT1->asTexture();
    REPORTER_ASSERT(reporter, nullptr != tex);
    SkBitmap bitmap;
    GrWrapTextureInBitmap(tex, 256, 256, false, &bitmap);

    // No mipmaps initially
    REPORTER_ASSERT(reporter, false == tex->texturePriv().hasMipMaps());

    // Painting with downscale and medium filter quality should result in mipmap creation
    auto surface = SkSurface::MakeRenderTargetDirect(texRT2->asRenderTarget());
    SkPaint paint;
    paint.setFilterQuality(kMedium_SkFilterQuality);
    surface->getCanvas()->scale(0.2f, 0.2f);
    surface->getCanvas()->drawBitmap(bitmap, 0, 0, &paint);
    context->flush();

    REPORTER_ASSERT(reporter, true == tex->texturePriv().hasMipMaps());
    REPORTER_ASSERT(reporter, false == tex->texturePriv().mipMapsAreDirty());

    // Invalidating the contents of the bitmap should invalidate the mipmap, but not de-allocate
    bitmap.notifyPixelsChanged();
    REPORTER_ASSERT(reporter, true == tex->texturePriv().hasMipMaps());
    REPORTER_ASSERT(reporter, true == tex->texturePriv().mipMapsAreDirty());

    texRT1->unref();
    texRT2->unref();
}

#endif
