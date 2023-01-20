/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkPaintFlagsDrawFilter.h"
#include "SkPaint.h"

SkPaintFlagsDrawFilter::SkPaintFlagsDrawFilter(uint32_t clearFlags,
<<<<<<< HEAD
    uint32_t setFlags)
{
=======
                                               uint32_t setFlags) {
>>>>>>> miniblink49
    fClearFlags = SkToU16(clearFlags & SkPaint::kAllFlags);
    fSetFlags = SkToU16(setFlags & SkPaint::kAllFlags);
}

<<<<<<< HEAD
bool SkPaintFlagsDrawFilter::filter(SkPaint* paint, Type)
{
=======
bool SkPaintFlagsDrawFilter::filter(SkPaint* paint, Type) {
>>>>>>> miniblink49
    paint->setFlags((paint->getFlags() & ~fClearFlags) | fSetFlags);
    return true;
}
