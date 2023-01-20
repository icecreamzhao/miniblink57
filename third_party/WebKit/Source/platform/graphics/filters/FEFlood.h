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

#ifndef FEFlood_h
#define FEFlood_h

#include "platform/graphics/Color.h"
#include "platform/graphics/filters/FilterEffect.h"

namespace blink {

<<<<<<< HEAD
class PLATFORM_EXPORT FEFlood final : public FilterEffect {
public:
    static FEFlood* create(Filter*, const Color&, float);

    Color floodColor() const;
    bool setFloodColor(const Color&);
=======
class PLATFORM_EXPORT FEFlood : public FilterEffect {
public:
    static PassRefPtrWillBeRawPtr<FEFlood> create(Filter*, const Color&, float);

    Color floodColor() const;
    bool setFloodColor(const Color &);
>>>>>>> miniblink49

    float floodOpacity() const;
    bool setFloodOpacity(float);

<<<<<<< HEAD
    // feFlood does not perform color interpolation of any kind, so the result is
    // always in the current color space regardless of the value of
    // color-interpolation-filters.
    void setOperatingColorSpace(ColorSpace) override { }

=======
    // feFlood does not perform color interpolation of any kind, so the result is always in the current
    // color space regardless of the value of color-interpolation-filters.
    void setOperatingColorSpace(ColorSpace) override { }

    PassRefPtr<SkImageFilter> createImageFilter(SkiaImageFilterBuilder*) override;

>>>>>>> miniblink49
    TextStream& externalRepresentation(TextStream&, int indention) const override;

private:
    FEFlood(Filter*, const Color&, float);

<<<<<<< HEAD
    sk_sp<SkImageFilter> createImageFilter() override;

=======
>>>>>>> miniblink49
    Color m_floodColor;
    float m_floodOpacity;
};

} // namespace blink

#endif // FEFlood_h
