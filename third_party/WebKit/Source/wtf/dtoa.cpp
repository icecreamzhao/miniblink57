/****************************************************************
 *
 * The author of this software is David M. Gay.
 *
 * Copyright (c) 1991, 2000, 2001 by Lucent Technologies.
 * Copyright (C) 2002, 2005, 2006, 2007, 2008, 2010, 2012 Apple Inc.
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 *
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHOR NOR LUCENT MAKES ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 ***************************************************************/

/* Please send bug reports to David M. Gay (dmg at acm dot org,
 * with " at " changed at "@" and " dot " changed to ".").    */

/* On a machine with IEEE extended-precision registers, it is
 * necessary to specify double-precision (53-bit) rounding precision
 * before invoking strtod or dtoa.  If the machine uses (the equivalent
 * of) Intel 80x87 arithmetic, the call
 *    _control87(PC_53, MCW_PC);
 * does this with many compilers.  Whether this or another call is
 * appropriate depends on the compiler; for this to work, it may be
 * necessary to #include "float.h" or another system-dependent header
 * file.
 */

#include "wtf/dtoa.h"

#include "wtf/Vector.h"
#include <string.h>

namespace WTF {

const char* numberToString(double d, NumberToStringBuffer buffer)
{
    double_conversion::StringBuilder builder(buffer, NumberToStringBufferLength);
    const double_conversion::DoubleToStringConverter& converter = double_conversion::DoubleToStringConverter::EcmaScriptConverter();
    converter.ToShortest(d, &builder);
    return builder.Finalize();
}

static inline const char* formatStringTruncatingTrailingZerosIfNeeded(
    NumberToStringBuffer buffer,
    double_conversion::StringBuilder& builder)
{
    size_t length = builder.position();

    // If there is an exponent, stripping trailing zeros would be incorrect.
    // FIXME: Zeros should be stripped before the 'e'.
    if (memchr(buffer, 'e', length))
        return builder.Finalize();

    size_t decimalPointPosition = 0;
    for (; decimalPointPosition < length; ++decimalPointPosition) {
        if (buffer[decimalPointPosition] == '.')
            break;
    }

    // No decimal seperator found, early exit.
    if (decimalPointPosition == length)
        return builder.Finalize();

    size_t truncatedLength = length - 1;
    for (; truncatedLength > decimalPointPosition; --truncatedLength) {
        if (buffer[truncatedLength] != '0')
            break;
    }

    // No trailing zeros found to strip.
    if (truncatedLength == length - 1)
        return builder.Finalize();

    // If we removed all trailing zeros, remove the decimal point as well.
    if (truncatedLength == decimalPointPosition) {
        DCHECK_GT(truncatedLength, 0u);
        --truncatedLength;
    }

    // Truncate the StringBuilder, and return the final result.
    builder.SetPosition(truncatedLength + 1);
    return builder.Finalize();
}

const char* numberToFixedPrecisionString(double d,
    unsigned significantFigures,
    NumberToStringBuffer buffer)
{
    // Mimic String::format("%.[precision]g", ...), but use dtoas rounding
    // facilities.
    // "g": Signed value printed in f or e format, whichever is more compact for
    // the given value and precision.
    // The e format is used only when the exponent of the value is less than -4 or
    // greater than or equal to the precision argument. Trailing zeros are
    // truncated, and the decimal point appears only if one or more digits follow
    // it.
    // "precision": The precision specifies the maximum number of significant
    // digits printed.
    double_conversion::StringBuilder builder(buffer, NumberToStringBufferLength);
    const double_conversion::DoubleToStringConverter& converter = double_conversion::DoubleToStringConverter::EcmaScriptConverter();
    converter.ToPrecision(d, significantFigures, &builder);
    // FIXME: Trailing zeros should never be added in the first place. The
    // current implementation does not strip when there is an exponent, eg.
    // 1.50000e+10.
    return formatStringTruncatingTrailingZerosIfNeeded(buffer, builder);
}

const char* numberToFixedWidthString(double d,
    unsigned decimalPlaces,
    NumberToStringBuffer buffer)
{
    // Mimic String::format("%.[precision]f", ...), but use dtoas rounding
    // facilities.
    // "f": Signed value having the form [ - ]dddd.dddd, where dddd is one or more
    // decimal digits.  The number of digits before the decimal point depends on
    // the magnitude of the number, and the number of digits after the decimal
    // point depends on the requested precision.
    // "precision": The precision value specifies the number of digits after the
    // decimal point.  If a decimal point appears, at least one digit appears
    // before it.  The value is rounded to the appropriate number of digits.
    double_conversion::StringBuilder builder(buffer, NumberToStringBufferLength);
    const double_conversion::DoubleToStringConverter& converter = double_conversion::DoubleToStringConverter::EcmaScriptConverter();
    converter.ToFixed(d, decimalPlaces, &builder);
    return builder.Finalize();
}

namespace Internal {

    double parseDoubleFromLongString(const UChar* string,
        size_t length,
        size_t& parsedLength)
    {
        Vector<LChar> conversionBuffer(length);
        for (size_t i = 0; i < length; ++i)
            conversionBuffer[i] = isASCII(string[i]) ? string[i] : 0;
        return parseDouble(conversionBuffer.data(), length, parsedLength);
    }

} // namespace Internal

} // namespace WTF
