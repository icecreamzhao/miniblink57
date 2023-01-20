/*
 * Copyright (C) 2004, 2005, 2006, 2007 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2004, 2005 Rob Buis <buis@kde.org>
 * Copyright (C) 2005 Eric Seidel <eric@webkit.org>
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef FETile_h
#define FETile_h

#include "platform/graphics/filters/FilterEffect.h"

namespace blink {

<<<<<<< HEAD
class PLATFORM_EXPORT FETile final : public FilterEffect {
public:
    static FETile* create(Filter*);
=======
class PLATFORM_EXPORT FETile : public FilterEffect {
public:
    static PassRefPtrWillBeRawPtr<FETile> create(Filter*);

    PassRefPtr<SkImageFilter> createImageFilter(SkiaImageFilterBuilder*) override;

    FloatRect mapPaintRect(const FloatRect&, bool forward = true) final;

    FilterEffectType filterEffectType() const override { return FilterEffectTypeTile; }
>>>>>>> miniblink49

    TextStream& externalRepresentation(TextStream&, int indention) const override;

private:
    FETile(Filter*);
<<<<<<< HEAD

    FilterEffectType getFilterEffectType() const override
    {
        return FilterEffectTypeTile;
    }

    FloatRect mapInputs(const FloatRect&) const final;

    sk_sp<SkImageFilter> createImageFilter() override;
=======
>>>>>>> miniblink49
};

} // namespace blink

#endif // FETile_h
