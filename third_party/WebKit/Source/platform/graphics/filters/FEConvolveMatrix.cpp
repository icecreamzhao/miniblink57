/*
 * Copyright (C) 2004, 2005, 2006, 2007 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2004, 2005 Rob Buis <buis@kde.org>
 * Copyright (C) 2005 Eric Seidel <eric@webkit.org>
 * Copyright (C) 2009 Dirk Schulze <krit@webkit.org>
 * Copyright (C) 2010 Zoltan Herczeg <zherczeg@webkit.org>
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

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/graphics/filters/FEConvolveMatrix.h"

#include "SkMatrixConvolutionImageFilter.h"
#include "platform/graphics/filters/SkiaImageFilterBuilder.h"
#include "platform/text/TextStream.h"
<<<<<<< HEAD
#include "wtf/CheckedNumeric.h"
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

FEConvolveMatrix::FEConvolveMatrix(Filter* filter,
    const IntSize& kernelSize,
    float divisor,
    float bias,
    const IntPoint& targetOffset,
    EdgeModeType edgeMode,
    bool preserveAlpha,
    const Vector<float>& kernelMatrix)
=======
#include "wtf/OwnPtr.h"

namespace blink {

FEConvolveMatrix::FEConvolveMatrix(Filter* filter, const IntSize& kernelSize,
    float divisor, float bias, const IntPoint& targetOffset, EdgeModeType edgeMode,
    const FloatPoint& kernelUnitLength, bool preserveAlpha, const Vector<float>& kernelMatrix)
>>>>>>> miniblink49
    : FilterEffect(filter)
    , m_kernelSize(kernelSize)
    , m_divisor(divisor)
    , m_bias(bias)
    , m_targetOffset(targetOffset)
    , m_edgeMode(edgeMode)
<<<<<<< HEAD
    , m_preserveAlpha(preserveAlpha)
    , m_kernelMatrix(kernelMatrix)
{
}

FEConvolveMatrix* FEConvolveMatrix::create(Filter* filter,
    const IntSize& kernelSize,
    float divisor,
    float bias,
    const IntPoint& targetOffset,
    EdgeModeType edgeMode,
    bool preserveAlpha,
    const Vector<float>& kernelMatrix)
{
    return new FEConvolveMatrix(filter, kernelSize, divisor, bias, targetOffset,
        edgeMode, preserveAlpha, kernelMatrix);
}

FloatRect FEConvolveMatrix::mapEffect(const FloatRect& rect) const
{
    if (!parametersValid())
        return rect;
    FloatRect result = rect;
    result.moveBy(-m_targetOffset);
    result.expand(FloatSize(m_kernelSize));
    return result;
}

bool FEConvolveMatrix::setDivisor(float divisor)
{
=======
    , m_kernelUnitLength(kernelUnitLength)
    , m_preserveAlpha(preserveAlpha)
    , m_kernelMatrix(kernelMatrix)
{
    ASSERT(m_kernelSize.width() > 0);
    ASSERT(m_kernelSize.height() > 0);
}

PassRefPtrWillBeRawPtr<FEConvolveMatrix> FEConvolveMatrix::create(Filter* filter, const IntSize& kernelSize,
    float divisor, float bias, const IntPoint& targetOffset, EdgeModeType edgeMode,
    const FloatPoint& kernelUnitLength, bool preserveAlpha, const Vector<float>& kernelMatrix)
{
    return adoptRefWillBeNoop(new FEConvolveMatrix(filter, kernelSize, divisor, bias, targetOffset, edgeMode, kernelUnitLength,
        preserveAlpha, kernelMatrix));
}

FloatRect FEConvolveMatrix::mapPaintRect(const FloatRect& rect, bool forward)
{
    FloatRect result = rect;

    result.moveBy(forward ? -m_targetOffset : m_targetOffset - m_kernelSize);
    result.expand(m_kernelSize);
    return result;
}

IntSize FEConvolveMatrix::kernelSize() const
{
    return m_kernelSize;
}

void FEConvolveMatrix::setKernelSize(const IntSize& kernelSize)
{
    ASSERT(kernelSize.width() > 0);
    ASSERT(kernelSize.height() > 0);
    m_kernelSize = kernelSize;
}

const Vector<float>& FEConvolveMatrix::kernel() const
{
    return m_kernelMatrix;
}

void FEConvolveMatrix::setKernel(const Vector<float>& kernel)
{
    m_kernelMatrix = kernel;
}

float FEConvolveMatrix::divisor() const
{
    return m_divisor;
}

bool FEConvolveMatrix::setDivisor(float divisor)
{
    ASSERT(divisor);
>>>>>>> miniblink49
    if (m_divisor == divisor)
        return false;
    m_divisor = divisor;
    return true;
}

<<<<<<< HEAD
=======
float FEConvolveMatrix::bias() const
{
    return m_bias;
}

>>>>>>> miniblink49
bool FEConvolveMatrix::setBias(float bias)
{
    if (m_bias == bias)
        return false;
    m_bias = bias;
    return true;
}

<<<<<<< HEAD
=======
IntPoint FEConvolveMatrix::targetOffset() const
{
    return m_targetOffset;
}

>>>>>>> miniblink49
bool FEConvolveMatrix::setTargetOffset(const IntPoint& targetOffset)
{
    if (m_targetOffset == targetOffset)
        return false;
    m_targetOffset = targetOffset;
    return true;
}

<<<<<<< HEAD
=======
EdgeModeType FEConvolveMatrix::edgeMode() const
{
    return m_edgeMode;
}

>>>>>>> miniblink49
bool FEConvolveMatrix::setEdgeMode(EdgeModeType edgeMode)
{
    if (m_edgeMode == edgeMode)
        return false;
    m_edgeMode = edgeMode;
    return true;
}

<<<<<<< HEAD
=======
FloatPoint FEConvolveMatrix::kernelUnitLength() const
{
    return m_kernelUnitLength;
}

bool FEConvolveMatrix::setKernelUnitLength(const FloatPoint& kernelUnitLength)
{
    ASSERT(kernelUnitLength.x() > 0);
    ASSERT(kernelUnitLength.y() > 0);
    if (m_kernelUnitLength == kernelUnitLength)
        return false;
    m_kernelUnitLength = kernelUnitLength;
    return true;
}

bool FEConvolveMatrix::preserveAlpha() const
{
    return m_preserveAlpha;
}

>>>>>>> miniblink49
bool FEConvolveMatrix::setPreserveAlpha(bool preserveAlpha)
{
    if (m_preserveAlpha == preserveAlpha)
        return false;
    m_preserveAlpha = preserveAlpha;
    return true;
}

SkMatrixConvolutionImageFilter::TileMode toSkiaTileMode(EdgeModeType edgeMode)
{
    switch (edgeMode) {
    case EDGEMODE_DUPLICATE:
        return SkMatrixConvolutionImageFilter::kClamp_TileMode;
    case EDGEMODE_WRAP:
        return SkMatrixConvolutionImageFilter::kRepeat_TileMode;
    case EDGEMODE_NONE:
        return SkMatrixConvolutionImageFilter::kClampToBlack_TileMode;
    default:
        return SkMatrixConvolutionImageFilter::kClamp_TileMode;
    }
}

<<<<<<< HEAD
bool FEConvolveMatrix::parametersValid() const
{
    if (m_kernelSize.isEmpty())
        return false;
    uint64_t kernelArea = m_kernelSize.area();
    if (!CheckedNumeric<int>(kernelArea).IsValid())
        return false;
    if (safeCast<size_t>(kernelArea) != m_kernelMatrix.size())
        return false;
    if (m_targetOffset.x() < 0 || m_targetOffset.x() >= m_kernelSize.width())
        return false;
    if (m_targetOffset.y() < 0 || m_targetOffset.y() >= m_kernelSize.height())
        return false;
    if (!m_divisor)
        return false;
    return true;
}

sk_sp<SkImageFilter> FEConvolveMatrix::createImageFilter()
{
    if (!parametersValid())
        return createTransparentBlack();

    sk_sp<SkImageFilter> input(
        SkiaImageFilterBuilder::build(inputEffect(0), operatingColorSpace()));
    SkISize kernelSize(
        SkISize::Make(m_kernelSize.width(), m_kernelSize.height()));
    // parametersValid() above checks that the kernel area fits in int.
    int numElements = safeCast<int>(m_kernelSize.area());
=======
PassRefPtr<SkImageFilter> FEConvolveMatrix::createImageFilter(SkiaImageFilterBuilder* builder)
{
    RefPtr<SkImageFilter> input(builder->build(inputEffect(0), operatingColorSpace()));

    SkISize kernelSize(SkISize::Make(m_kernelSize.width(), m_kernelSize.height()));
    int numElements = kernelSize.width() * kernelSize.height();
>>>>>>> miniblink49
    SkScalar gain = SkFloatToScalar(1.0f / m_divisor);
    SkScalar bias = SkFloatToScalar(m_bias * 255);
    SkIPoint target = SkIPoint::Make(m_targetOffset.x(), m_targetOffset.y());
    SkMatrixConvolutionImageFilter::TileMode tileMode = toSkiaTileMode(m_edgeMode);
    bool convolveAlpha = !m_preserveAlpha;
<<<<<<< HEAD
    std::unique_ptr<SkScalar[]> kernel = wrapArrayUnique(new SkScalar[numElements]);
    for (int i = 0; i < numElements; ++i)
        kernel[i] = SkFloatToScalar(m_kernelMatrix[numElements - 1 - i]);
    SkImageFilter::CropRect cropRect = getCropRect();
    return SkMatrixConvolutionImageFilter::Make(
        kernelSize, kernel.get(), gain, bias, target, tileMode, convolveAlpha,
        std::move(input), &cropRect);
=======
    OwnPtr<SkScalar[]> kernel = adoptArrayPtr(new SkScalar[numElements]);
    for (int i = 0; i < numElements; ++i)
        kernel[i] = SkFloatToScalar(m_kernelMatrix[numElements - 1 - i]);
    SkImageFilter::CropRect cropRect = getCropRect(builder->cropOffset());
    return adoptRef(SkMatrixConvolutionImageFilter::Create(kernelSize, kernel.get(), gain, bias, target, tileMode, convolveAlpha, input.get(), &cropRect));
>>>>>>> miniblink49
}

static TextStream& operator<<(TextStream& ts, const EdgeModeType& type)
{
    switch (type) {
    case EDGEMODE_UNKNOWN:
        ts << "UNKNOWN";
        break;
    case EDGEMODE_DUPLICATE:
        ts << "DUPLICATE";
        break;
    case EDGEMODE_WRAP:
        ts << "WRAP";
        break;
    case EDGEMODE_NONE:
        ts << "NONE";
        break;
    }
    return ts;
}

<<<<<<< HEAD
TextStream& FEConvolveMatrix::externalRepresentation(TextStream& ts,
    int indent) const
=======
TextStream& FEConvolveMatrix::externalRepresentation(TextStream& ts, int indent) const
>>>>>>> miniblink49
{
    writeIndent(ts, indent);
    ts << "[feConvolveMatrix";
    FilterEffect::externalRepresentation(ts);
<<<<<<< HEAD
    ts << " order=\"" << FloatSize(m_kernelSize) << "\" "
       << "kernelMatrix=\"" << m_kernelMatrix << "\" "
=======
    ts << " order=\"" << m_kernelSize << "\" "
       << "kernelMatrix=\"" << m_kernelMatrix  << "\" "
>>>>>>> miniblink49
       << "divisor=\"" << m_divisor << "\" "
       << "bias=\"" << m_bias << "\" "
       << "target=\"" << m_targetOffset << "\" "
       << "edgeMode=\"" << m_edgeMode << "\" "
<<<<<<< HEAD
=======
       << "kernelUnitLength=\"" << m_kernelUnitLength << "\" "
>>>>>>> miniblink49
       << "preserveAlpha=\"" << m_preserveAlpha << "\"]\n";
    inputEffect(0)->externalRepresentation(ts, indent + 1);
    return ts;
}

} // namespace blink
