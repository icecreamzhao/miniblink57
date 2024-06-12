// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/public/browser/bluetooth_chooser.h"

namespace content {

BluetoothChooser::~BluetoothChooser() { }

bool BluetoothChooser::CanAskForScanningPermission()
{
    return true;
}

} // namespace content
