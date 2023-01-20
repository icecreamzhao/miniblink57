/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkXfermodeInterpretation.h"
#include "SkPaint.h"

<<<<<<< HEAD
static bool just_solid_color(const SkPaint& p)
{
=======
static bool just_solid_color(const SkPaint& p) {
>>>>>>> miniblink49
    return SK_AlphaOPAQUE == p.getAlpha()
        && !p.getColorFilter() && !p.getShader();
}

SkXfermodeInterpretation SkInterpretXfermode(const SkPaint& paint,
<<<<<<< HEAD
    bool dstIsOpaque)
{
=======
                                             bool dstIsOpaque) {
>>>>>>> miniblink49
    const SkXfermode* xfer = paint.getXfermode();
    SkXfermode::Mode mode;
    if (!SkXfermode::AsMode(xfer, &mode)) {
        return kNormal_SkXfermodeInterpretation;
    }
    switch (mode) {
<<<<<<< HEAD
    case SkXfermode::kSrcOver_Mode:
        return kSrcOver_SkXfermodeInterpretation;
    case SkXfermode::kSrc_Mode:
        if (just_solid_color(paint)) {
            return kSrcOver_SkXfermodeInterpretation;
        }
        return kNormal_SkXfermodeInterpretation;
    case SkXfermode::kDst_Mode:
        return kSkipDrawing_SkXfermodeInterpretation;
    case SkXfermode::kDstOver_Mode:
        if (dstIsOpaque) {
            return kSkipDrawing_SkXfermodeInterpretation;
        }
        return kNormal_SkXfermodeInterpretation;
    case SkXfermode::kSrcIn_Mode:
        if (dstIsOpaque && just_solid_color(paint)) {
            return kSrcOver_SkXfermodeInterpretation;
        }
        return kNormal_SkXfermodeInterpretation;
    case SkXfermode::kDstIn_Mode:
        if (just_solid_color(paint)) {
            return kSkipDrawing_SkXfermodeInterpretation;
        }
        return kNormal_SkXfermodeInterpretation;
    default:
        return kNormal_SkXfermodeInterpretation;
=======
        case SkXfermode::kSrcOver_Mode:
            return kSrcOver_SkXfermodeInterpretation;
        case SkXfermode::kSrc_Mode:
            if (just_solid_color(paint)) {
                return kSrcOver_SkXfermodeInterpretation;
            }
            return kNormal_SkXfermodeInterpretation;
        case SkXfermode::kDst_Mode:
            return kSkipDrawing_SkXfermodeInterpretation;
        case SkXfermode::kDstOver_Mode:
            if (dstIsOpaque) {
                return kSkipDrawing_SkXfermodeInterpretation;
            }
            return kNormal_SkXfermodeInterpretation;
        case SkXfermode::kSrcIn_Mode:
            if (dstIsOpaque && just_solid_color(paint)) {
                return kSrcOver_SkXfermodeInterpretation;
            }
            return kNormal_SkXfermodeInterpretation;
        case SkXfermode::kDstIn_Mode:
            if (just_solid_color(paint)) {
                return kSkipDrawing_SkXfermodeInterpretation;
            }
            return kNormal_SkXfermodeInterpretation;
        default:
            return kNormal_SkXfermodeInterpretation;
>>>>>>> miniblink49
    }
}
