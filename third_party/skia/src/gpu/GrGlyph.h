/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrGlyph_DEFINED
#define GrGlyph_DEFINED

#include "GrBatchAtlas.h"
#include "GrRect.h"
#include "GrTypes.h"

#include "SkChecksum.h"
<<<<<<< HEAD
#include "SkFixed.h"
=======
>>>>>>> miniblink49
#include "SkPath.h"

class GrPlot;

/*  Need this to be quad-state:
    - complete w/ image
    - just metrics
    - failed to get image, but has metrics
    - failed to get metrics
 */
struct GrGlyph {
    enum MaskStyle {
        kCoverage_MaskStyle,
        kDistance_MaskStyle
    };
<<<<<<< HEAD

    typedef uint32_t PackedID;

    GrBatchAtlas::AtlasID fID;
    SkPath* fPath;
    PackedID fPackedID;
    GrMaskFormat fMaskFormat;
    GrIRect16 fBounds;
    SkIPoint16 fAtlasLocation;
    bool fTooLargeForAtlas;

    void init(GrGlyph::PackedID packed, const SkIRect& bounds, GrMaskFormat format)
    {
        fID = GrBatchAtlas::kInvalidAtlasID;
        fPath = nullptr;
=======
    
    typedef uint32_t PackedID;

    // TODO either plot or AtlasID will be valid, not both
    GrBatchAtlas::AtlasID fID;
    GrPlot*               fPlot;
    SkPath*               fPath;
    PackedID              fPackedID;
    GrMaskFormat          fMaskFormat;
    GrIRect16             fBounds;
    SkIPoint16            fAtlasLocation;
    bool                  fTooLargeForAtlas;

    void init(GrGlyph::PackedID packed, const SkIRect& bounds, GrMaskFormat format) {
        fID = GrBatchAtlas::kInvalidAtlasID;
        fPlot = NULL;
        fPath = NULL;
>>>>>>> miniblink49
        fPackedID = packed;
        fBounds.set(bounds);
        fMaskFormat = format;
        fAtlasLocation.set(0, 0);
        fTooLargeForAtlas = GrBatchAtlas::GlyphTooLargeForAtlas(bounds.width(), bounds.height());
    }

<<<<<<< HEAD
    void reset()
    {
        if (fPath) {
            delete fPath;
            fPath = nullptr;
=======
    void free() {
        if (fPath) {
            delete fPath;
            fPath = NULL;
>>>>>>> miniblink49
        }
    }

    int width() const { return fBounds.width(); }
    int height() const { return fBounds.height(); }
    bool isEmpty() const { return fBounds.isEmpty(); }
    uint16_t glyphID() const { return UnpackID(fPackedID); }

    ///////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
    static inline unsigned ExtractSubPixelBitsFromFixed(SkFixed pos)
    {
=======
    static inline unsigned ExtractSubPixelBitsFromFixed(SkFixed pos) {
>>>>>>> miniblink49
        // two most significant fraction bits from fixed-point
        return (pos >> 14) & 3;
    }

<<<<<<< HEAD
    static inline PackedID Pack(uint16_t glyphID, SkFixed x, SkFixed y, MaskStyle ms)
    {
=======
    static inline PackedID Pack(uint16_t glyphID, SkFixed x, SkFixed y, MaskStyle ms) {
>>>>>>> miniblink49
        x = ExtractSubPixelBitsFromFixed(x);
        y = ExtractSubPixelBitsFromFixed(y);
        int dfFlag = (ms == kDistance_MaskStyle) ? 0x1 : 0x0;
        return (dfFlag << 20) | (x << 18) | (y << 16) | glyphID;
    }

<<<<<<< HEAD
    static inline SkFixed UnpackFixedX(PackedID packed)
    {
        return ((packed >> 18) & 3) << 14;
    }

    static inline SkFixed UnpackFixedY(PackedID packed)
    {
        return ((packed >> 16) & 3) << 14;
    }

    static inline MaskStyle UnpackMaskStyle(PackedID packed)
    {
        return ((packed >> 20) & 1) ? kDistance_MaskStyle : kCoverage_MaskStyle;
    }

    static inline uint16_t UnpackID(PackedID packed)
    {
        return (uint16_t)packed;
    }

    static inline const GrGlyph::PackedID& GetKey(const GrGlyph& glyph)
    {
        return glyph.fPackedID;
    }

    static inline uint32_t Hash(GrGlyph::PackedID key)
    {
=======
    static inline SkFixed UnpackFixedX(PackedID packed) {
        return ((packed >> 18) & 3) << 14;
    }

    static inline SkFixed UnpackFixedY(PackedID packed) {
        return ((packed >> 16) & 3) << 14;
    }

    static inline MaskStyle UnpackMaskStyle(PackedID packed) {
        return ((packed >> 20) & 1) ? kDistance_MaskStyle : kCoverage_MaskStyle;
    }
    
    static inline uint16_t UnpackID(PackedID packed) {
        return (uint16_t)packed;
    }

    static inline const GrGlyph::PackedID& GetKey(const GrGlyph& glyph) {
        return glyph.fPackedID;
    }

    static inline uint32_t Hash(GrGlyph::PackedID key) {
>>>>>>> miniblink49
        return SkChecksum::Mix(key);
    }
};

#endif
