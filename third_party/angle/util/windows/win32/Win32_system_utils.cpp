//
// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// Win32_system_utils.cpp: Implementation of OS-specific functions for Win32 (Windows)

#include "system_utils.h"

#include <array>
#include <windows.h>

namespace angle {

void SetLowPriorityProcess()
{
    SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);
}

} // namespace angle
