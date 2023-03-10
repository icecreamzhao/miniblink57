// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_INTL_SUPPORT
#error Internationalization is expected to be enabled.
#endif // V8_INTL_SUPPORT

#ifndef V8_OBJECTS_JS_NUMBER_FORMAT_INL_H_
#define V8_OBJECTS_JS_NUMBER_FORMAT_INL_H_

#include "src/objects-inl.h"
#include "src/objects/js-number-format.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"

namespace v8 {
namespace internal {

    OBJECT_CONSTRUCTORS_IMPL(JSNumberFormat, JSObject)

    ACCESSORS(JSNumberFormat, locale, String, kLocaleOffset)
    ACCESSORS(JSNumberFormat, icu_number_format, Managed<icu::NumberFormat>,
        kICUNumberFormatOffset)
    ACCESSORS(JSNumberFormat, bound_format, Object, kBoundFormatOffset)
    SMI_ACCESSORS(JSNumberFormat, flags, kFlagsOffset)

    inline void JSNumberFormat::set_style(Style style)
    {
        DCHECK_LT(style, Style::COUNT);
        int hints = flags();
        hints = StyleBits::update(hints, style);
        set_flags(hints);
    }

    inline JSNumberFormat::Style JSNumberFormat::style() const
    {
        return StyleBits::decode(flags());
    }

    inline void JSNumberFormat::set_currency_display(
        CurrencyDisplay currency_display)
    {
        DCHECK_LT(currency_display, CurrencyDisplay::COUNT);
        int hints = flags();
        hints = CurrencyDisplayBits::update(hints, currency_display);
        set_flags(hints);
    }

    inline JSNumberFormat::CurrencyDisplay JSNumberFormat::currency_display()
        const
    {
        return CurrencyDisplayBits::decode(flags());
    }

    CAST_ACCESSOR(JSNumberFormat)

} // namespace internal
} // namespace v8

#include "src/objects/object-macros-undef.h"

#endif // V8_OBJECTS_JS_NUMBER_FORMAT_INL_H_
