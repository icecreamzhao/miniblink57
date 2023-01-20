
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkDrawColor.h"
#ifdef SK_DEBUG
#include "SkDisplayList.h"
#endif
#include "SkDrawPaint.h"
#include "SkParse.h"
#include "SkScript.h"

enum HSV_Choice {
    kGetHue,
    kGetSaturation,
    kGetValue
};

<<<<<<< HEAD
static SkScalar RGB_to_HSV(SkColor color, HSV_Choice choice)
{
=======
static SkScalar RGB_to_HSV(SkColor color, HSV_Choice choice) {
>>>>>>> miniblink49
    SkScalar red = SkIntToScalar(SkColorGetR(color));
    SkScalar green = SkIntToScalar(SkColorGetG(color));
    SkScalar blue = SkIntToScalar(SkColorGetB(color));
    SkScalar min = SkMinScalar(SkMinScalar(red, green), blue);
    SkScalar value = SkMaxScalar(SkMaxScalar(red, green), blue);
    if (choice == kGetValue)
<<<<<<< HEAD
        return value / 255;
=======
        return value/255;
>>>>>>> miniblink49
    SkScalar delta = value - min;
    SkScalar saturation = value == 0 ? 0 : delta / value;
    if (choice == kGetSaturation)
        return saturation;
    SkScalar hue;
    if (saturation == 0)
        hue = 0;
    else {
        SkScalar part60 = 60 / delta;
        if (red == value) {
            hue = SkScalarMul(green - blue, part60);
            if (hue < 0)
                hue += 360 * SK_Scalar1;
<<<<<<< HEAD
        } else if (green == value)
            hue = 120 * SK_Scalar1 + SkScalarMul(blue - red, part60);
        else // blue == value
=======
        }
        else if (green == value)
            hue = 120 * SK_Scalar1 + SkScalarMul(blue - red, part60);
        else  // blue == value
>>>>>>> miniblink49
            hue = 240 * SK_Scalar1 + SkScalarMul(red - green, part60);
    }
    SkASSERT(choice == kGetHue);
    return hue;
}

<<<<<<< HEAD
#if defined _WIN32 // disable 'red', etc. may be used without having been initialized
#pragma warning(push)
#pragma warning(disable : 4701)
#endif

static SkColor HSV_to_RGB(SkColor color, HSV_Choice choice, SkScalar hsv)
{
=======
#if defined _WIN32 && _MSC_VER >= 1300  // disable 'red', etc. may be used without having been initialized
#pragma warning ( push )
#pragma warning ( disable : 4701 )
#endif

static SkColor HSV_to_RGB(SkColor color, HSV_Choice choice, SkScalar hsv) {
>>>>>>> miniblink49
    SkScalar hue = choice == kGetHue ? hsv : RGB_to_HSV(color, kGetHue);
    SkScalar saturation = choice == kGetSaturation ? hsv : RGB_to_HSV(color, kGetSaturation);
    SkScalar value = choice == kGetValue ? hsv : RGB_to_HSV(color, kGetValue);
    value *= 255;
    SkScalar red SK_INIT_TO_AVOID_WARNING;
    SkScalar green SK_INIT_TO_AVOID_WARNING;
    SkScalar blue SK_INIT_TO_AVOID_WARNING;
<<<<<<< HEAD
    if (saturation == 0) // color is on black-and-white center line
=======
    if (saturation == 0)    // color is on black-and-white center line
>>>>>>> miniblink49
        red = green = blue = value;
    else {
        //SkScalar fraction = SkScalarMod(hue, 60 * SK_Scalar1);
        int sextant = SkScalarFloorToInt(hue / 60);
        SkScalar fraction = hue / 60 - SkIntToScalar(sextant);
<<<<<<< HEAD
        SkScalar p = SkScalarMul(value, SK_Scalar1 - saturation);
        SkScalar q = SkScalarMul(value, SK_Scalar1 - SkScalarMul(saturation, fraction));
        SkScalar t = SkScalarMul(value, SK_Scalar1 - SkScalarMul(saturation, SK_Scalar1 - fraction));
        switch (sextant % 6) {
        case 0:
            red = value;
            green = t;
            blue = p;
            break;
        case 1:
            red = q;
            green = value;
            blue = p;
            break;
        case 2:
            red = p;
            green = value;
            blue = t;
            break;
        case 3:
            red = p;
            green = q;
            blue = value;
            break;
        case 4:
            red = t;
            green = p;
            blue = value;
            break;
        case 5:
            red = value;
            green = p;
            blue = q;
            break;
=======
        SkScalar p = SkScalarMul(value , SK_Scalar1 - saturation);
        SkScalar q = SkScalarMul(value, SK_Scalar1 - SkScalarMul(saturation, fraction));
        SkScalar t = SkScalarMul(value, SK_Scalar1 -
            SkScalarMul(saturation, SK_Scalar1 - fraction));
        switch (sextant % 6) {
            case 0: red = value; green = t; blue = p; break;
            case 1: red = q; green = value; blue = p; break;
            case 2: red = p; green = value; blue = t; break;
            case 3: red = p; green = q; blue = value; break;
            case 4: red = t;  green = p; blue = value; break;
            case 5: red = value; green = p; blue = q; break;
>>>>>>> miniblink49
        }
    }
    //used to say SkToU8((U8CPU) red) etc
    return SkColorSetARGB(SkColorGetA(color), SkScalarRoundToInt(red),
<<<<<<< HEAD
        SkScalarRoundToInt(green), SkScalarRoundToInt(blue));
}

#if defined _WIN32
#pragma warning(pop)
=======
                          SkScalarRoundToInt(green), SkScalarRoundToInt(blue));
}

#if defined _WIN32 && _MSC_VER >= 1300
#pragma warning ( pop )
>>>>>>> miniblink49
#endif

enum SkDrawColor_Properties {
    SK_PROPERTY(alpha),
    SK_PROPERTY(blue),
    SK_PROPERTY(green),
    SK_PROPERTY(hue),
    SK_PROPERTY(red),
    SK_PROPERTY(saturation),
    SK_PROPERTY(value)
};

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDrawColor::fInfo[] = {
    SK_MEMBER_PROPERTY(alpha, Float),
    SK_MEMBER_PROPERTY(blue, Float),
    SK_MEMBER(color, ARGB),
    SK_MEMBER_PROPERTY(green, Float),
    SK_MEMBER_PROPERTY(hue, Float),
    SK_MEMBER_PROPERTY(red, Float),
    SK_MEMBER_PROPERTY(saturation, Float),
    SK_MEMBER_PROPERTY(value, Float),
};

#endif

DEFINE_GET_MEMBER(SkDrawColor);

<<<<<<< HEAD
SkDrawColor::SkDrawColor()
    : fDirty(false)
{
=======
SkDrawColor::SkDrawColor() : fDirty(false) {
>>>>>>> miniblink49
    color = SK_ColorBLACK;
    fHue = fSaturation = fValue = SK_ScalarNaN;
}

<<<<<<< HEAD
bool SkDrawColor::add()
{
    if (fPaint->color != nullptr)
=======
bool SkDrawColor::add() {
    if (fPaint->color != NULL)
>>>>>>> miniblink49
        return true; // error (probably color in paint as attribute as well)
    fPaint->color = this;
    fPaint->fOwnsColor = true;
    return false;
}

<<<<<<< HEAD
SkDisplayable* SkDrawColor::deepCopy(SkAnimateMaker*)
{
=======
SkDisplayable* SkDrawColor::deepCopy(SkAnimateMaker*) {
>>>>>>> miniblink49
    SkDrawColor* copy = new SkDrawColor();
    copy->color = color;
    copy->fHue = fHue;
    copy->fSaturation = fSaturation;
    copy->fValue = fValue;
    copy->fDirty = fDirty;
    return copy;
}

<<<<<<< HEAD
void SkDrawColor::dirty()
{
=======
void SkDrawColor::dirty(){
>>>>>>> miniblink49
    fDirty = true;
}

#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
void SkDrawColor::dump(SkAnimateMaker* maker)
{
    dumpBase(maker);
    SkDebugf("alpha=\"%d\" red=\"%d\" green=\"%d\" blue=\"%d\" />\n",
        SkColorGetA(color) / 255, SkColorGetR(color),
=======
void SkDrawColor::dump(SkAnimateMaker* maker) {
    dumpBase(maker);
    SkDebugf("alpha=\"%d\" red=\"%d\" green=\"%d\" blue=\"%d\" />\n",
        SkColorGetA(color)/255, SkColorGetR(color),
>>>>>>> miniblink49
        SkColorGetG(color), SkColorGetB(color));
}
#endif

<<<<<<< HEAD
SkColor SkDrawColor::getColor()
{
=======
SkColor SkDrawColor::getColor() {
>>>>>>> miniblink49
    if (fDirty) {
        if (SkScalarIsNaN(fValue) == false)
            color = HSV_to_RGB(color, kGetValue, fValue);
        if (SkScalarIsNaN(fSaturation) == false)
            color = HSV_to_RGB(color, kGetSaturation, fSaturation);
        if (SkScalarIsNaN(fHue) == false)
            color = HSV_to_RGB(color, kGetHue, fHue);
        fDirty = false;
    }
    return color;
}

<<<<<<< HEAD
SkDisplayable* SkDrawColor::getParent() const
{
    return fPaint;
}

bool SkDrawColor::getProperty(int index, SkScriptValue* value) const
{
    value->fType = SkType_Float;
    SkScalar result;
    switch (index) {
    case SK_PROPERTY(alpha):
        result = SkIntToScalar(SkColorGetA(color)) / 255;
        break;
    case SK_PROPERTY(blue):
        result = SkIntToScalar(SkColorGetB(color));
        break;
    case SK_PROPERTY(green):
        result = SkIntToScalar(SkColorGetG(color));
        break;
    case SK_PROPERTY(hue):
        result = RGB_to_HSV(color, kGetHue);
        break;
    case SK_PROPERTY(red):
        result = SkIntToScalar(SkColorGetR(color));
        break;
    case SK_PROPERTY(saturation):
        result = RGB_to_HSV(color, kGetSaturation);
        break;
    case SK_PROPERTY(value):
        result = RGB_to_HSV(color, kGetValue);
        break;
    default:
        SkASSERT(0);
        return false;
=======
SkDisplayable* SkDrawColor::getParent() const {
    return fPaint;
}

bool SkDrawColor::getProperty(int index, SkScriptValue* value) const {
    value->fType = SkType_Float;
    SkScalar result;
    switch(index) {
        case SK_PROPERTY(alpha):
            result = SkIntToScalar(SkColorGetA(color)) / 255;
            break;
        case SK_PROPERTY(blue):
            result = SkIntToScalar(SkColorGetB(color));
            break;
        case SK_PROPERTY(green):
            result = SkIntToScalar(SkColorGetG(color));
            break;
        case SK_PROPERTY(hue):
            result = RGB_to_HSV(color, kGetHue);
            break;
        case SK_PROPERTY(red):
            result = SkIntToScalar(SkColorGetR(color));
            break;
        case SK_PROPERTY(saturation):
            result = RGB_to_HSV(color, kGetSaturation);
            break;
        case SK_PROPERTY(value):
            result = RGB_to_HSV(color, kGetValue);
            break;
        default:
            SkASSERT(0);
            return false;
>>>>>>> miniblink49
    }
    value->fOperand.fScalar = result;
    return true;
}

<<<<<<< HEAD
void SkDrawColor::onEndElement(SkAnimateMaker&)
{
    fDirty = true;
}

bool SkDrawColor::setParent(SkDisplayable* parent)
{
    SkASSERT(parent != nullptr);
=======
void SkDrawColor::onEndElement(SkAnimateMaker&) {
    fDirty = true;
}

bool SkDrawColor::setParent(SkDisplayable* parent) {
    SkASSERT(parent != NULL);
>>>>>>> miniblink49
    if (parent->getType() == SkType_DrawLinearGradient || parent->getType() == SkType_DrawRadialGradient)
        return false;
    if (parent->isPaint() == false)
        return true;
<<<<<<< HEAD
    fPaint = (SkDrawPaint*)parent;
    return false;
}

bool SkDrawColor::setProperty(int index, SkScriptValue& value)
{
    SkASSERT(value.fType == SkType_Float);
    SkScalar scalar = value.fOperand.fScalar;
    switch (index) {
    case SK_PROPERTY(alpha):
        uint8_t alpha;
        alpha = scalar == SK_Scalar1 ? 255 : SkToU8((U8CPU)(scalar * 256));
        color = SkColorSetARGB(alpha, SkColorGetR(color),
            SkColorGetG(color), SkColorGetB(color));
        break;
    case SK_PROPERTY(blue):
        scalar = SkScalarClampMax(scalar, 255 * SK_Scalar1);
        color = SkColorSetARGB(SkColorGetA(color), SkColorGetR(color),
            SkColorGetG(color), SkToU8((U8CPU)scalar));
        break;
    case SK_PROPERTY(green):
        scalar = SkScalarClampMax(scalar, 255 * SK_Scalar1);
        color = SkColorSetARGB(SkColorGetA(color), SkColorGetR(color),
            SkToU8((U8CPU)scalar), SkColorGetB(color));
        break;
    case SK_PROPERTY(hue):
        fHue = scalar; //RGB_to_HSV(color, kGetHue);
        fDirty = true;
        break;
    case SK_PROPERTY(red):
        scalar = SkScalarClampMax(scalar, 255 * SK_Scalar1);
        color = SkColorSetARGB(SkColorGetA(color), SkToU8((U8CPU)scalar),
            SkColorGetG(color), SkColorGetB(color));
        break;
    case SK_PROPERTY(saturation):
        fSaturation = scalar; //RGB_to_HSV(color, kGetSaturation);
        fDirty = true;
        break;
    case SK_PROPERTY(value):
        fValue = scalar; //RGB_to_HSV(color, kGetValue);
        fDirty = true;
        break;
    default:
        SkASSERT(0);
        return false;
=======
    fPaint = (SkDrawPaint*) parent;
    return false;
}

bool SkDrawColor::setProperty(int index, SkScriptValue& value) {
    SkASSERT(value.fType == SkType_Float);
    SkScalar scalar = value.fOperand.fScalar;
    switch (index) {
        case SK_PROPERTY(alpha):
            uint8_t alpha;
            alpha = scalar == SK_Scalar1 ? 255 : SkToU8((U8CPU) (scalar * 256));
            color = SkColorSetARGB(alpha, SkColorGetR(color),
                SkColorGetG(color), SkColorGetB(color));
            break;
        case SK_PROPERTY(blue):
            scalar = SkScalarClampMax(scalar, 255 * SK_Scalar1);
            color = SkColorSetARGB(SkColorGetA(color), SkColorGetR(color),
                SkColorGetG(color), SkToU8((U8CPU) scalar));
            break;
        case SK_PROPERTY(green):
            scalar = SkScalarClampMax(scalar, 255 * SK_Scalar1);
            color = SkColorSetARGB(SkColorGetA(color), SkColorGetR(color),
                SkToU8((U8CPU) scalar), SkColorGetB(color));
            break;
        case SK_PROPERTY(hue):
            fHue = scalar;//RGB_to_HSV(color, kGetHue);
            fDirty = true;
            break;
        case SK_PROPERTY(red):
            scalar = SkScalarClampMax(scalar, 255 * SK_Scalar1);
            color = SkColorSetARGB(SkColorGetA(color), SkToU8((U8CPU) scalar),
                SkColorGetG(color), SkColorGetB(color));
        break;
        case SK_PROPERTY(saturation):
            fSaturation = scalar;//RGB_to_HSV(color, kGetSaturation);
            fDirty = true;
            break;
        case SK_PROPERTY(value):
            fValue = scalar;//RGB_to_HSV(color, kGetValue);
            fDirty = true;
            break;
        default:
            SkASSERT(0);
            return false;
>>>>>>> miniblink49
    }
    return true;
}
