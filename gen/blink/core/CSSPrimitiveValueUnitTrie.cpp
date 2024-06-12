// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/css/CSSPrimitiveValue.h"

namespace blink {

namespace {

    template <typename CharacterType>
    CSSPrimitiveValue::UnitType cssPrimitiveValueUnitFromTrie(
        const CharacterType* data, unsigned length)
    {
        DCHECK(data);
        DCHECK(length);
        switch (length) {
        case 1:
            switch (toASCIILower(data[0])) {
            case 's':
                return CSSPrimitiveValue::UnitType::Seconds;
            }
            break;
        case 2:
            switch (toASCIILower(data[0])) {
            case 'c':
                switch (toASCIILower(data[1])) {
                case 'h':
                    return CSSPrimitiveValue::UnitType::Chs;
                case 'm':
                    return CSSPrimitiveValue::UnitType::Centimeters;
                }
                break;
            case 'e':
                switch (toASCIILower(data[1])) {
                case 'm':
                    return CSSPrimitiveValue::UnitType::Ems;
                case 'x':
                    return CSSPrimitiveValue::UnitType::Exs;
                }
                break;
            case 'f':
                if (toASCIILower(data[1]) == 'r')
                    return CSSPrimitiveValue::UnitType::Fraction;
                break;
            case 'h':
                if (toASCIILower(data[1]) == 'z')
                    return CSSPrimitiveValue::UnitType::Hertz;
                break;
            case 'i':
                if (toASCIILower(data[1]) == 'n')
                    return CSSPrimitiveValue::UnitType::Inches;
                break;
            case 'm':
                switch (toASCIILower(data[1])) {
                case 'm':
                    return CSSPrimitiveValue::UnitType::Millimeters;
                case 's':
                    return CSSPrimitiveValue::UnitType::Milliseconds;
                }
                break;
            case 'p':
                switch (toASCIILower(data[1])) {
                case 'c':
                    return CSSPrimitiveValue::UnitType::Picas;
                case 't':
                    return CSSPrimitiveValue::UnitType::Points;
                case 'x':
                    return CSSPrimitiveValue::UnitType::Pixels;
                }
                break;
            case 'v':
                switch (toASCIILower(data[1])) {
                case 'h':
                    return CSSPrimitiveValue::UnitType::ViewportHeight;
                case 'w':
                    return CSSPrimitiveValue::UnitType::ViewportWidth;
                }
                break;
            }
            break;
        case 3:
            switch (toASCIILower(data[0])) {
            case 'd':
                switch (toASCIILower(data[1])) {
                case 'e':
                    if (toASCIILower(data[2]) == 'g')
                        return CSSPrimitiveValue::UnitType::Degrees;
                    break;
                case 'p':
                    if (toASCIILower(data[2]) == 'i')
                        return CSSPrimitiveValue::UnitType::DotsPerInch;
                    break;
                }
                break;
            case 'k':
                if (toASCIILower(data[1]) == 'h' && toASCIILower(data[2]) == 'z')
                    return CSSPrimitiveValue::UnitType::Kilohertz;
                break;
            case 'r':
                switch (toASCIILower(data[1])) {
                case 'a':
                    if (toASCIILower(data[2]) == 'd')
                        return CSSPrimitiveValue::UnitType::Radians;
                    break;
                case 'e':
                    if (toASCIILower(data[2]) == 'm')
                        return CSSPrimitiveValue::UnitType::Rems;
                    break;
                }
                break;
            }
            break;
        case 4:
            switch (toASCIILower(data[0])) {
            case 'd':
                switch (toASCIILower(data[1])) {
                case 'p':
                    switch (toASCIILower(data[2])) {
                    case 'c':
                        if (toASCIILower(data[3]) == 'm')
                            return CSSPrimitiveValue::UnitType::DotsPerCentimeter;
                        break;
                    case 'p':
                        if (toASCIILower(data[3]) == 'x')
                            return CSSPrimitiveValue::UnitType::DotsPerPixel;
                        break;
                    }
                    break;
                }
                break;
            case 'g':
                if (toASCIILower(data[1]) == 'r' && toASCIILower(data[2]) == 'a' && toASCIILower(data[3]) == 'd')
                    return CSSPrimitiveValue::UnitType::Gradians;
                break;
            case 't':
                if (toASCIILower(data[1]) == 'u' && toASCIILower(data[2]) == 'r' && toASCIILower(data[3]) == 'n')
                    return CSSPrimitiveValue::UnitType::Turns;
                break;
            case 'v':
                switch (toASCIILower(data[1])) {
                case 'm':
                    switch (toASCIILower(data[2])) {
                    case 'a':
                        if (toASCIILower(data[3]) == 'x')
                            return CSSPrimitiveValue::UnitType::ViewportMax;
                        break;
                    case 'i':
                        if (toASCIILower(data[3]) == 'n')
                            return CSSPrimitiveValue::UnitType::ViewportMin;
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 5:
            switch (toASCIILower(data[0])) {
            case '_':
                if (toASCIILower(data[1]) == '_' && toASCIILower(data[2]) == 'q' && toASCIILower(data[3]) == 'e' && toASCIILower(data[4]) == 'm')
                    return CSSPrimitiveValue::UnitType::QuirkyEms;
                break;
            }
            break;
        }
        return CSSPrimitiveValue::UnitType::Unknown;
    }

} // namespace

CSSPrimitiveValue::UnitType CSSPrimitiveValue::stringToUnitType(
    const LChar* characters8, unsigned length)
{
    return cssPrimitiveValueUnitFromTrie(characters8, length);
}

CSSPrimitiveValue::UnitType CSSPrimitiveValue::stringToUnitType(
    const UChar* characters16, unsigned length)
{
    return cssPrimitiveValueUnitFromTrie(characters16, length);
}

} // namespace blink
