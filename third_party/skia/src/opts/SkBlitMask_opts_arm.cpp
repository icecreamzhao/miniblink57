/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#if defined(SK_ARM_HAS_NEON)

#include "SkBlitMask.h"
#include "SkBlitMask_opts_arm_neon.h"
#include "SkColor.h"
#include "SkColorPriv.h"
#include "SkUtilsArm.h"

SkBlitMask::BlitLCD16RowProc SkBlitMask::PlatformBlitRowProcs16(bool isOpaque)
{
    if (isOpaque) {
        return SK_ARM_NEON_WRAP(SkBlitLCD16OpaqueRow);
    } else {
        return SK_ARM_NEON_WRAP(SkBlitLCD16Row);
    }
}

SkBlitMask::RowProc SkBlitMask::PlatformRowProcs(SkColorType dstCT,
    SkMask::Format maskFormat,
    RowFlags flags)
{
    return nullptr;
}
#endif // #if defined(SK_ARM_HAS_NEON)
