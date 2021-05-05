// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/common/font_list.h"

#include <memory>
#include <set>
#include <string>
#include <utility>

#include <fontconfig/fontconfig.h>

#include "base/values.h"

namespace content {

std::unique_ptr<FcPattern, decltype(&FcPatternDestroy)> CreateFormatPattern(
    const char* format)
{
    std::unique_ptr<FcPattern, decltype(&FcPatternDestroy)> pattern(
        FcPatternCreate(), FcPatternDestroy);
    FcPatternAddBool(pattern.get(), FC_SCALABLE, FcTrue);
    FcPatternAddString(pattern.get(), FC_FONTFORMAT,
        reinterpret_cast<const FcChar8*>(format));
    return pattern;
}

std::unique_ptr<base::ListValue> GetFontList_SlowBlocking()
{
    std::unique_ptr<base::ListValue> font_list(new base::ListValue);

    std::unique_ptr<FcObjectSet, decltype(&FcObjectSetDestroy)> object_set(
        FcObjectSetBuild(FC_FAMILY, NULL), FcObjectSetDestroy);

    std::set<std::string> sorted_families;

    // See https://www.freetype.org/freetype2/docs/reference/ft2-font_formats.html
    // for the list of possible formats.
    const char* allowed_formats[] = { "TrueType", "CFF" };
    for (size_t i = 0; i < arraysize(allowed_formats); ++i) {
        auto format_pattern = CreateFormatPattern(allowed_formats[i]);
        std::unique_ptr<FcFontSet, decltype(&FcFontSetDestroy)> fontset(
            FcFontList(0, format_pattern.get(), object_set.get()),
            FcFontSetDestroy);
        for (int j = 0; j < fontset->nfont; ++j) {
            char* family_string;
            FcPatternGetString(fontset->fonts[j], FC_FAMILY, 0,
                reinterpret_cast<FcChar8**>(&family_string));
            sorted_families.insert(family_string);
        }
    }

    // For backwards compatibility with the older pango implementation, add the
    // three Fontconfig aliases that pango added. Our linux default settings for
    // fixed-width was "Monospace". If we remove that, this entry is not found in
    // the list anymore, see also:
    // https://git.gnome.org/browse/pango/tree/pango/pangofc-fontmap.c?h=1.40.1#n1351
    sorted_families.insert("Monospace");
    sorted_families.insert("Sans");
    sorted_families.insert("Serif");

    for (const auto& family : sorted_families) {
        std::unique_ptr<base::ListValue> font_item(new base::ListValue());
        font_item->AppendString(family);
        font_item->AppendString(family); // localized name.
        // TODO(yusukes): Support localized family names.
        font_list->Append(std::move(font_item));
    }

    return font_list;
}

} // namespace content
