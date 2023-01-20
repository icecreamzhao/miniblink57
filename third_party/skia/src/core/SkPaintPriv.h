/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkPaintPriv_DEFINED
#define SkPaintPriv_DEFINED

#include "SkTypes.h"

class SkBitmap;
class SkImage;
class SkPaint;

<<<<<<< HEAD
class SkPaintPriv {
public:
    enum ShaderOverrideOpacity {
        kNone_ShaderOverrideOpacity, //!< there is no overriding shader (bitmap or image)
        kOpaque_ShaderOverrideOpacity, //!< the overriding shader is opaque
        kNotOpaque_ShaderOverrideOpacity, //!< the overriding shader may not be opaque
    };

    /**
     *  Returns true if drawing with this paint (or nullptr) will ovewrite all affected pixels.
     *
     *  Note: returns conservative true, meaning it may return false even though the paint might
     *        in fact overwrite its pixels.
     */
    static bool Overwrites(const SkPaint* paint, ShaderOverrideOpacity);

    static bool Overwrites(const SkPaint& paint)
    {
        return Overwrites(&paint, kNone_ShaderOverrideOpacity);
    }

    /**
     *  Returns true if drawing this bitmap with this paint (or nullptr) will ovewrite all affected
     *  pixels.
     */
    static bool Overwrites(const SkBitmap&, const SkPaint* paint);

    /**
     *  Returns true if drawing this image with this paint (or nullptr) will ovewrite all affected
     *  pixels.
     */
    static bool Overwrites(const SkImage*, const SkPaint* paint);
};

=======
enum SkPaintBitmapOpacity {
    // No content replaces the paint's color
    kNoBitmap_SkPaintBitmapOpacity = 0,
    // The color replacement is known to be opaque
    kOpaque_SkPaintBitmapOpacity = 1,
    // We have no information about the color or it is transparent
    kUnknown_SkPaintBitmapOpacity = 2
};

/** Returns true if draw calls that use the paint will completely occlude
    canvas contents that are covered by the draw.
    @param paint The paint to be analyzed, NULL is equivalent to
        the default paint.
    @param contentType The type of the content that will be drawn,
        kNoBitmap_SkPaintBitmapOpacity if there is no content in adition to the paint.
    @return true if paint is opaque
*/
bool isPaintOpaque(const SkPaint* paint, SkPaintBitmapOpacity contentType);

/** Returns true if draw calls that use the paint will completely occlude
    canvas contents that are covered by the draw.
    @param paint The paint to be analyzed, NULL is equivalent to
        the default paint.
    @param bmpReplacesShader a bitmap to be used in place of the paint's
        shader.
    @return true if paint is opaque
*/
bool isPaintOpaque(const SkPaint* paint, const SkBitmap* bmpReplacesShader = NULL);
bool isPaintOpaque(const SkPaint* paint, const SkImage* image);

>>>>>>> miniblink49
#endif
