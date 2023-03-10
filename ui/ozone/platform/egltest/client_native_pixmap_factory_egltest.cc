// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/ozone/platform/egltest/client_native_pixmap_factory_egltest.h"

#include "ui/ozone/common/stub_client_native_pixmap_factory.h" // nogncheck

namespace ui {

ClientNativePixmapFactory* CreateClientNativePixmapFactoryEgltest()
{
    return CreateStubClientNativePixmapFactory();
}

} // namespace ui
