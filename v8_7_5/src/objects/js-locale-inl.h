// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_INTL_SUPPORT
#error Internationalization is expected to be enabled.
#endif // V8_INTL_SUPPORT

#ifndef V8_OBJECTS_JS_LOCALE_INL_H_
#define V8_OBJECTS_JS_LOCALE_INL_H_

#include "src/api-inl.h"
#include "src/objects-inl.h"
#include "src/objects/js-locale.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"

namespace v8 {
namespace internal {

    OBJECT_CONSTRUCTORS_IMPL(JSLocale, JSObject)

    ACCESSORS(JSLocale, icu_locale, Managed<icu::Locale>, kICULocaleOffset)

    CAST_ACCESSOR(JSLocale)

} // namespace internal
} // namespace v8

#include "src/objects/object-macros-undef.h"

#endif // V8_OBJECTS_JS_LOCALE_INL_H_
