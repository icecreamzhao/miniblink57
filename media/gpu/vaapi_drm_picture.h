// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// This file contains an implementation of picture allocation for the
// Ozone window system used by VaapiVideoDecodeAccelerator to produce
// output pictures.

#ifndef MEDIA_GPU_VAAPI_DRM_PICTURE_H_
#define MEDIA_GPU_VAAPI_DRM_PICTURE_H_

#include <stdint.h>

#include "base/macros.h"
#include "base/memory/ref_counted.h"
#include "base/memory/weak_ptr.h"
#include "media/gpu/vaapi_picture.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/geometry/size.h"

namespace gl {
class GLImage;
}

namespace ui {
class NativePixmap;
}

namespace media {

class VaapiWrapper;

// Implementation of VaapiPicture for the ozone/drm backed chromium.
class VaapiDrmPicture : public VaapiPicture {
public:
    VaapiDrmPicture(const scoped_refptr<VaapiWrapper>& vaapi_wrapper,
        const MakeGLContextCurrentCallback& make_context_current_cb,
        const BindGLImageCallback& bind_image_cb_,
        int32_t picture_buffer_id,
        const gfx::Size& size,
        uint32_t texture_id,
        uint32_t client_texture_id);

    ~VaapiDrmPicture() override;

    bool Allocate(gfx::BufferFormat format) override;
    bool ImportGpuMemoryBufferHandle(
        gfx::BufferFormat format,
        const gfx::GpuMemoryBufferHandle& gpu_memory_buffer_handle) override;

    bool DownloadFromSurface(const scoped_refptr<VASurface>& va_surface) override;

    bool AllowOverlay() const override;

private:
    bool Initialize();

    // Ozone buffer, the storage of the EGLImage and the VASurface.
    scoped_refptr<ui::NativePixmap> pixmap_;

    // EGLImage bound to the GL textures used by the VDA client.
    scoped_refptr<gl::GLImage> gl_image_;

    // VASurface used to transfer from the decoder's pixel format.
    scoped_refptr<VASurface> va_surface_;

    DISALLOW_COPY_AND_ASSIGN(VaapiDrmPicture);
};

} // namespace media

#endif // MEDIA_GPU_VAAPI_DRM_PICTURE_H_
