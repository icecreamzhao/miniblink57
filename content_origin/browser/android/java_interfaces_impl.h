// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_BROWSER_ANDROID_JAVA_INTERFACES_IMPL_H_
#define CONTENT_BROWSER_ANDROID_JAVA_INTERFACES_IMPL_H_

#include "content/public/browser/android/java_interfaces.h"
#include "services/service_manager/public/interfaces/interface_provider.mojom.h"

namespace content {
class WebContents;

void BindInterfaceRegistryForWebContents(
    service_manager::mojom::InterfaceProviderRequest request,
    WebContents* web_contents);

} // namespace content

#endif // CONTENT_BROWSER_ANDROID_JAVA_INTERFACES_IMPL_H_
