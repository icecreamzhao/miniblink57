/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkValidationUtils_DEFINED
#define SkValidationUtils_DEFINED

#include "SkBitmap.h"
#include "SkXfermode.h"

/** Returns true if coeff's value is in the SkXfermode::Coeff enum.
  */
<<<<<<< HEAD
static inline bool SkIsValidCoeff(SkXfermode::Coeff coeff)
{
=======
static inline bool SkIsValidCoeff(SkXfermode::Coeff coeff) {
>>>>>>> miniblink49
    return coeff >= 0 && coeff < SkXfermode::kCoeffCount;
}

/** Returns true if mode's value is in the SkXfermode::Mode enum.
  */
<<<<<<< HEAD
static inline bool SkIsValidMode(SkXfermode::Mode mode)
{
=======
static inline bool SkIsValidMode(SkXfermode::Mode mode) {
>>>>>>> miniblink49
    return (mode >= 0) && (mode <= SkXfermode::kLastMode);
}

/** Returns true if the rect's dimensions are between 0 and SK_MaxS32
  */
<<<<<<< HEAD
static inline bool SkIsValidIRect(const SkIRect& rect)
{
=======
static inline bool SkIsValidIRect(const SkIRect& rect) {
>>>>>>> miniblink49
    return rect.width() >= 0 && rect.height() >= 0;
}

/** Returns true if the rect's dimensions are between 0 and SK_ScalarMax
  */
<<<<<<< HEAD
static inline bool SkIsValidRect(const SkRect& rect)
{
    return (rect.fLeft <= rect.fRight) && (rect.fTop <= rect.fBottom) && SkScalarIsFinite(rect.width()) && SkScalarIsFinite(rect.height());
=======
static inline bool SkIsValidRect(const SkRect& rect) {
    return (rect.fLeft <= rect.fRight) &&
           (rect.fTop <= rect.fBottom) &&
           SkScalarIsFinite(rect.width()) &&
           SkScalarIsFinite(rect.height());
>>>>>>> miniblink49
}

#endif
