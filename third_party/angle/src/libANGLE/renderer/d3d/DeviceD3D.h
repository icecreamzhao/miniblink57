//
// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// DeviceD3D.h: D3D implementation of egl::Device

#ifndef LIBANGLE_RENDERER_D3D_DEVICED3D_H_
#define LIBANGLE_RENDERER_D3D_DEVICED3D_H_

#include "libANGLE/Device.h"
#include "libANGLE/renderer/DeviceImpl.h"
#include "libANGLE/renderer/d3d/RendererD3D.h"

namespace rx {
class DeviceD3D : public DeviceImpl {
public:
    DeviceD3D();
    ~DeviceD3D() override;

    egl::Error initialize(void* device, EGLint deviceType, EGLBoolean external);
    egl::Error getDevice(void** outValue) override;
    EGLint getType() override;
    void generateExtensions(egl::DeviceExtensions* outExtensions) const override;
    bool deviceExternallySourced() override { return mDeviceExternallySourced; }

private:
    void* mDevice;
    EGLint mDeviceType;
    bool mDeviceExternallySourced;
    bool mIsInitialized;
};

}

#endif // LIBANGLE_RENDERER_D3D_DEVICED3D_H_
