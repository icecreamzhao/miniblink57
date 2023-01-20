/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkSurfacePriv_DEFINED
#define SkSurfacePriv_DEFINED

#include "SkSurfaceProps.h"

<<<<<<< HEAD
static inline SkSurfaceProps SkSurfacePropsCopyOrDefault(const SkSurfaceProps* props)
{
=======
static inline SkSurfaceProps SkSurfacePropsCopyOrDefault(const SkSurfaceProps* props) {
>>>>>>> miniblink49
    if (props) {
        return *props;
    } else {
        return SkSurfaceProps(SkSurfaceProps::kLegacyFontHost_InitType);
    }
}

<<<<<<< HEAD
static inline SkPixelGeometry SkSurfacePropsDefaultPixelGeometry()
{
=======
static inline SkPixelGeometry SkSurfacePropsDefaultPixelGeometry() {
>>>>>>> miniblink49
    return SkSurfaceProps(SkSurfaceProps::kLegacyFontHost_InitType).pixelGeometry();
}

#endif
