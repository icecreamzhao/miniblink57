// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SVGElementTypeHelpers_h
#define SVGElementTypeHelpers_h

#include "SVGNames.h"
#include "core/svg/SVGElement.h"
#include "platform/RuntimeEnabledFeatures.h"

namespace blink {
// Type checking.
class SVGAElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGAElement(const SVGAElement&);
void isSVGAElement(const SVGAElement*);

inline bool isSVGAElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::aTag);
}
inline bool isSVGAElement(const SVGElement* element)
{
    return element && isSVGAElement(*element);
}
inline bool isSVGAElement(const Node& node)
{
    return node.isSVGElement() && isSVGAElement(toSVGElement(node));
}
inline bool isSVGAElement(const Node* node)
{
    return node && isSVGAElement(*node);
}
template <>
inline bool isElementOfType<const SVGAElement>(const Node& node)
{
    return isSVGAElement(node);
}
template <>
inline bool isElementOfType<const SVGAElement>(const SVGElement& element)
{
    return isSVGAElement(element);
}

class SVGAnimateMotionElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGAnimateMotionElement(const SVGAnimateMotionElement&);
void isSVGAnimateMotionElement(const SVGAnimateMotionElement*);

inline bool isSVGAnimateMotionElement(const SVGElement& element)
{
    if (!RuntimeEnabledFeatures::smilEnabled())
        return false;
    return element.hasTagName(SVGNames::animateMotionTag);
}
inline bool isSVGAnimateMotionElement(const SVGElement* element)
{
    return element && isSVGAnimateMotionElement(*element);
}
inline bool isSVGAnimateMotionElement(const Node& node)
{
    return node.isSVGElement() && isSVGAnimateMotionElement(toSVGElement(node));
}
inline bool isSVGAnimateMotionElement(const Node* node)
{
    return node && isSVGAnimateMotionElement(*node);
}
template <>
inline bool isElementOfType<const SVGAnimateMotionElement>(const Node& node)
{
    return isSVGAnimateMotionElement(node);
}
template <>
inline bool isElementOfType<const SVGAnimateMotionElement>(const SVGElement& element)
{
    return isSVGAnimateMotionElement(element);
}

class SVGAnimateTransformElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGAnimateTransformElement(const SVGAnimateTransformElement&);
void isSVGAnimateTransformElement(const SVGAnimateTransformElement*);

inline bool isSVGAnimateTransformElement(const SVGElement& element)
{
    if (!RuntimeEnabledFeatures::smilEnabled())
        return false;
    return element.hasTagName(SVGNames::animateTransformTag);
}
inline bool isSVGAnimateTransformElement(const SVGElement* element)
{
    return element && isSVGAnimateTransformElement(*element);
}
inline bool isSVGAnimateTransformElement(const Node& node)
{
    return node.isSVGElement() && isSVGAnimateTransformElement(toSVGElement(node));
}
inline bool isSVGAnimateTransformElement(const Node* node)
{
    return node && isSVGAnimateTransformElement(*node);
}
template <>
inline bool isElementOfType<const SVGAnimateTransformElement>(const Node& node)
{
    return isSVGAnimateTransformElement(node);
}
template <>
inline bool isElementOfType<const SVGAnimateTransformElement>(const SVGElement& element)
{
    return isSVGAnimateTransformElement(element);
}

class SVGCircleElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGCircleElement(const SVGCircleElement&);
void isSVGCircleElement(const SVGCircleElement*);

inline bool isSVGCircleElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::circleTag);
}
inline bool isSVGCircleElement(const SVGElement* element)
{
    return element && isSVGCircleElement(*element);
}
inline bool isSVGCircleElement(const Node& node)
{
    return node.isSVGElement() && isSVGCircleElement(toSVGElement(node));
}
inline bool isSVGCircleElement(const Node* node)
{
    return node && isSVGCircleElement(*node);
}
template <>
inline bool isElementOfType<const SVGCircleElement>(const Node& node)
{
    return isSVGCircleElement(node);
}
template <>
inline bool isElementOfType<const SVGCircleElement>(const SVGElement& element)
{
    return isSVGCircleElement(element);
}

class SVGClipPathElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGClipPathElement(const SVGClipPathElement&);
void isSVGClipPathElement(const SVGClipPathElement*);

inline bool isSVGClipPathElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::clipPathTag);
}
inline bool isSVGClipPathElement(const SVGElement* element)
{
    return element && isSVGClipPathElement(*element);
}
inline bool isSVGClipPathElement(const Node& node)
{
    return node.isSVGElement() && isSVGClipPathElement(toSVGElement(node));
}
inline bool isSVGClipPathElement(const Node* node)
{
    return node && isSVGClipPathElement(*node);
}
template <>
inline bool isElementOfType<const SVGClipPathElement>(const Node& node)
{
    return isSVGClipPathElement(node);
}
template <>
inline bool isElementOfType<const SVGClipPathElement>(const SVGElement& element)
{
    return isSVGClipPathElement(element);
}

class SVGDefsElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGDefsElement(const SVGDefsElement&);
void isSVGDefsElement(const SVGDefsElement*);

inline bool isSVGDefsElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::defsTag);
}
inline bool isSVGDefsElement(const SVGElement* element)
{
    return element && isSVGDefsElement(*element);
}
inline bool isSVGDefsElement(const Node& node)
{
    return node.isSVGElement() && isSVGDefsElement(toSVGElement(node));
}
inline bool isSVGDefsElement(const Node* node)
{
    return node && isSVGDefsElement(*node);
}
template <>
inline bool isElementOfType<const SVGDefsElement>(const Node& node)
{
    return isSVGDefsElement(node);
}
template <>
inline bool isElementOfType<const SVGDefsElement>(const SVGElement& element)
{
    return isSVGDefsElement(element);
}

class SVGDescElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGDescElement(const SVGDescElement&);
void isSVGDescElement(const SVGDescElement*);

inline bool isSVGDescElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::descTag);
}
inline bool isSVGDescElement(const SVGElement* element)
{
    return element && isSVGDescElement(*element);
}
inline bool isSVGDescElement(const Node& node)
{
    return node.isSVGElement() && isSVGDescElement(toSVGElement(node));
}
inline bool isSVGDescElement(const Node* node)
{
    return node && isSVGDescElement(*node);
}
template <>
inline bool isElementOfType<const SVGDescElement>(const Node& node)
{
    return isSVGDescElement(node);
}
template <>
inline bool isElementOfType<const SVGDescElement>(const SVGElement& element)
{
    return isSVGDescElement(element);
}

class SVGDiscardElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGDiscardElement(const SVGDiscardElement&);
void isSVGDiscardElement(const SVGDiscardElement*);

inline bool isSVGDiscardElement(const SVGElement& element)
{
    if (!RuntimeEnabledFeatures::smilEnabled())
        return false;
    return element.hasTagName(SVGNames::discardTag);
}
inline bool isSVGDiscardElement(const SVGElement* element)
{
    return element && isSVGDiscardElement(*element);
}
inline bool isSVGDiscardElement(const Node& node)
{
    return node.isSVGElement() && isSVGDiscardElement(toSVGElement(node));
}
inline bool isSVGDiscardElement(const Node* node)
{
    return node && isSVGDiscardElement(*node);
}
template <>
inline bool isElementOfType<const SVGDiscardElement>(const Node& node)
{
    return isSVGDiscardElement(node);
}
template <>
inline bool isElementOfType<const SVGDiscardElement>(const SVGElement& element)
{
    return isSVGDiscardElement(element);
}

class SVGEllipseElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGEllipseElement(const SVGEllipseElement&);
void isSVGEllipseElement(const SVGEllipseElement*);

inline bool isSVGEllipseElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::ellipseTag);
}
inline bool isSVGEllipseElement(const SVGElement* element)
{
    return element && isSVGEllipseElement(*element);
}
inline bool isSVGEllipseElement(const Node& node)
{
    return node.isSVGElement() && isSVGEllipseElement(toSVGElement(node));
}
inline bool isSVGEllipseElement(const Node* node)
{
    return node && isSVGEllipseElement(*node);
}
template <>
inline bool isElementOfType<const SVGEllipseElement>(const Node& node)
{
    return isSVGEllipseElement(node);
}
template <>
inline bool isElementOfType<const SVGEllipseElement>(const SVGElement& element)
{
    return isSVGEllipseElement(element);
}

class SVGFEBlendElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEBlendElement(const SVGFEBlendElement&);
void isSVGFEBlendElement(const SVGFEBlendElement*);

inline bool isSVGFEBlendElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feBlendTag);
}
inline bool isSVGFEBlendElement(const SVGElement* element)
{
    return element && isSVGFEBlendElement(*element);
}
inline bool isSVGFEBlendElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEBlendElement(toSVGElement(node));
}
inline bool isSVGFEBlendElement(const Node* node)
{
    return node && isSVGFEBlendElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEBlendElement>(const Node& node)
{
    return isSVGFEBlendElement(node);
}
template <>
inline bool isElementOfType<const SVGFEBlendElement>(const SVGElement& element)
{
    return isSVGFEBlendElement(element);
}

class SVGFEColorMatrixElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEColorMatrixElement(const SVGFEColorMatrixElement&);
void isSVGFEColorMatrixElement(const SVGFEColorMatrixElement*);

inline bool isSVGFEColorMatrixElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feColorMatrixTag);
}
inline bool isSVGFEColorMatrixElement(const SVGElement* element)
{
    return element && isSVGFEColorMatrixElement(*element);
}
inline bool isSVGFEColorMatrixElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEColorMatrixElement(toSVGElement(node));
}
inline bool isSVGFEColorMatrixElement(const Node* node)
{
    return node && isSVGFEColorMatrixElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEColorMatrixElement>(const Node& node)
{
    return isSVGFEColorMatrixElement(node);
}
template <>
inline bool isElementOfType<const SVGFEColorMatrixElement>(const SVGElement& element)
{
    return isSVGFEColorMatrixElement(element);
}

class SVGFEComponentTransferElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEComponentTransferElement(const SVGFEComponentTransferElement&);
void isSVGFEComponentTransferElement(const SVGFEComponentTransferElement*);

inline bool isSVGFEComponentTransferElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feComponentTransferTag);
}
inline bool isSVGFEComponentTransferElement(const SVGElement* element)
{
    return element && isSVGFEComponentTransferElement(*element);
}
inline bool isSVGFEComponentTransferElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEComponentTransferElement(toSVGElement(node));
}
inline bool isSVGFEComponentTransferElement(const Node* node)
{
    return node && isSVGFEComponentTransferElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEComponentTransferElement>(const Node& node)
{
    return isSVGFEComponentTransferElement(node);
}
template <>
inline bool isElementOfType<const SVGFEComponentTransferElement>(const SVGElement& element)
{
    return isSVGFEComponentTransferElement(element);
}

class SVGFECompositeElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFECompositeElement(const SVGFECompositeElement&);
void isSVGFECompositeElement(const SVGFECompositeElement*);

inline bool isSVGFECompositeElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feCompositeTag);
}
inline bool isSVGFECompositeElement(const SVGElement* element)
{
    return element && isSVGFECompositeElement(*element);
}
inline bool isSVGFECompositeElement(const Node& node)
{
    return node.isSVGElement() && isSVGFECompositeElement(toSVGElement(node));
}
inline bool isSVGFECompositeElement(const Node* node)
{
    return node && isSVGFECompositeElement(*node);
}
template <>
inline bool isElementOfType<const SVGFECompositeElement>(const Node& node)
{
    return isSVGFECompositeElement(node);
}
template <>
inline bool isElementOfType<const SVGFECompositeElement>(const SVGElement& element)
{
    return isSVGFECompositeElement(element);
}

class SVGFEConvolveMatrixElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEConvolveMatrixElement(const SVGFEConvolveMatrixElement&);
void isSVGFEConvolveMatrixElement(const SVGFEConvolveMatrixElement*);

inline bool isSVGFEConvolveMatrixElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feConvolveMatrixTag);
}
inline bool isSVGFEConvolveMatrixElement(const SVGElement* element)
{
    return element && isSVGFEConvolveMatrixElement(*element);
}
inline bool isSVGFEConvolveMatrixElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEConvolveMatrixElement(toSVGElement(node));
}
inline bool isSVGFEConvolveMatrixElement(const Node* node)
{
    return node && isSVGFEConvolveMatrixElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEConvolveMatrixElement>(const Node& node)
{
    return isSVGFEConvolveMatrixElement(node);
}
template <>
inline bool isElementOfType<const SVGFEConvolveMatrixElement>(const SVGElement& element)
{
    return isSVGFEConvolveMatrixElement(element);
}

class SVGFEDiffuseLightingElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEDiffuseLightingElement(const SVGFEDiffuseLightingElement&);
void isSVGFEDiffuseLightingElement(const SVGFEDiffuseLightingElement*);

inline bool isSVGFEDiffuseLightingElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feDiffuseLightingTag);
}
inline bool isSVGFEDiffuseLightingElement(const SVGElement* element)
{
    return element && isSVGFEDiffuseLightingElement(*element);
}
inline bool isSVGFEDiffuseLightingElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEDiffuseLightingElement(toSVGElement(node));
}
inline bool isSVGFEDiffuseLightingElement(const Node* node)
{
    return node && isSVGFEDiffuseLightingElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEDiffuseLightingElement>(const Node& node)
{
    return isSVGFEDiffuseLightingElement(node);
}
template <>
inline bool isElementOfType<const SVGFEDiffuseLightingElement>(const SVGElement& element)
{
    return isSVGFEDiffuseLightingElement(element);
}

class SVGFEDisplacementMapElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEDisplacementMapElement(const SVGFEDisplacementMapElement&);
void isSVGFEDisplacementMapElement(const SVGFEDisplacementMapElement*);

inline bool isSVGFEDisplacementMapElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feDisplacementMapTag);
}
inline bool isSVGFEDisplacementMapElement(const SVGElement* element)
{
    return element && isSVGFEDisplacementMapElement(*element);
}
inline bool isSVGFEDisplacementMapElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEDisplacementMapElement(toSVGElement(node));
}
inline bool isSVGFEDisplacementMapElement(const Node* node)
{
    return node && isSVGFEDisplacementMapElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEDisplacementMapElement>(const Node& node)
{
    return isSVGFEDisplacementMapElement(node);
}
template <>
inline bool isElementOfType<const SVGFEDisplacementMapElement>(const SVGElement& element)
{
    return isSVGFEDisplacementMapElement(element);
}

class SVGFEDistantLightElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEDistantLightElement(const SVGFEDistantLightElement&);
void isSVGFEDistantLightElement(const SVGFEDistantLightElement*);

inline bool isSVGFEDistantLightElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feDistantLightTag);
}
inline bool isSVGFEDistantLightElement(const SVGElement* element)
{
    return element && isSVGFEDistantLightElement(*element);
}
inline bool isSVGFEDistantLightElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEDistantLightElement(toSVGElement(node));
}
inline bool isSVGFEDistantLightElement(const Node* node)
{
    return node && isSVGFEDistantLightElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEDistantLightElement>(const Node& node)
{
    return isSVGFEDistantLightElement(node);
}
template <>
inline bool isElementOfType<const SVGFEDistantLightElement>(const SVGElement& element)
{
    return isSVGFEDistantLightElement(element);
}

class SVGFEDropShadowElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEDropShadowElement(const SVGFEDropShadowElement&);
void isSVGFEDropShadowElement(const SVGFEDropShadowElement*);

inline bool isSVGFEDropShadowElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feDropShadowTag);
}
inline bool isSVGFEDropShadowElement(const SVGElement* element)
{
    return element && isSVGFEDropShadowElement(*element);
}
inline bool isSVGFEDropShadowElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEDropShadowElement(toSVGElement(node));
}
inline bool isSVGFEDropShadowElement(const Node* node)
{
    return node && isSVGFEDropShadowElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEDropShadowElement>(const Node& node)
{
    return isSVGFEDropShadowElement(node);
}
template <>
inline bool isElementOfType<const SVGFEDropShadowElement>(const SVGElement& element)
{
    return isSVGFEDropShadowElement(element);
}

class SVGFEFloodElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEFloodElement(const SVGFEFloodElement&);
void isSVGFEFloodElement(const SVGFEFloodElement*);

inline bool isSVGFEFloodElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feFloodTag);
}
inline bool isSVGFEFloodElement(const SVGElement* element)
{
    return element && isSVGFEFloodElement(*element);
}
inline bool isSVGFEFloodElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEFloodElement(toSVGElement(node));
}
inline bool isSVGFEFloodElement(const Node* node)
{
    return node && isSVGFEFloodElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEFloodElement>(const Node& node)
{
    return isSVGFEFloodElement(node);
}
template <>
inline bool isElementOfType<const SVGFEFloodElement>(const SVGElement& element)
{
    return isSVGFEFloodElement(element);
}

class SVGFEFuncAElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEFuncAElement(const SVGFEFuncAElement&);
void isSVGFEFuncAElement(const SVGFEFuncAElement*);

inline bool isSVGFEFuncAElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feFuncATag);
}
inline bool isSVGFEFuncAElement(const SVGElement* element)
{
    return element && isSVGFEFuncAElement(*element);
}
inline bool isSVGFEFuncAElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEFuncAElement(toSVGElement(node));
}
inline bool isSVGFEFuncAElement(const Node* node)
{
    return node && isSVGFEFuncAElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEFuncAElement>(const Node& node)
{
    return isSVGFEFuncAElement(node);
}
template <>
inline bool isElementOfType<const SVGFEFuncAElement>(const SVGElement& element)
{
    return isSVGFEFuncAElement(element);
}

class SVGFEFuncBElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEFuncBElement(const SVGFEFuncBElement&);
void isSVGFEFuncBElement(const SVGFEFuncBElement*);

inline bool isSVGFEFuncBElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feFuncBTag);
}
inline bool isSVGFEFuncBElement(const SVGElement* element)
{
    return element && isSVGFEFuncBElement(*element);
}
inline bool isSVGFEFuncBElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEFuncBElement(toSVGElement(node));
}
inline bool isSVGFEFuncBElement(const Node* node)
{
    return node && isSVGFEFuncBElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEFuncBElement>(const Node& node)
{
    return isSVGFEFuncBElement(node);
}
template <>
inline bool isElementOfType<const SVGFEFuncBElement>(const SVGElement& element)
{
    return isSVGFEFuncBElement(element);
}

class SVGFEFuncGElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEFuncGElement(const SVGFEFuncGElement&);
void isSVGFEFuncGElement(const SVGFEFuncGElement*);

inline bool isSVGFEFuncGElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feFuncGTag);
}
inline bool isSVGFEFuncGElement(const SVGElement* element)
{
    return element && isSVGFEFuncGElement(*element);
}
inline bool isSVGFEFuncGElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEFuncGElement(toSVGElement(node));
}
inline bool isSVGFEFuncGElement(const Node* node)
{
    return node && isSVGFEFuncGElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEFuncGElement>(const Node& node)
{
    return isSVGFEFuncGElement(node);
}
template <>
inline bool isElementOfType<const SVGFEFuncGElement>(const SVGElement& element)
{
    return isSVGFEFuncGElement(element);
}

class SVGFEFuncRElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEFuncRElement(const SVGFEFuncRElement&);
void isSVGFEFuncRElement(const SVGFEFuncRElement*);

inline bool isSVGFEFuncRElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feFuncRTag);
}
inline bool isSVGFEFuncRElement(const SVGElement* element)
{
    return element && isSVGFEFuncRElement(*element);
}
inline bool isSVGFEFuncRElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEFuncRElement(toSVGElement(node));
}
inline bool isSVGFEFuncRElement(const Node* node)
{
    return node && isSVGFEFuncRElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEFuncRElement>(const Node& node)
{
    return isSVGFEFuncRElement(node);
}
template <>
inline bool isElementOfType<const SVGFEFuncRElement>(const SVGElement& element)
{
    return isSVGFEFuncRElement(element);
}

class SVGFEGaussianBlurElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEGaussianBlurElement(const SVGFEGaussianBlurElement&);
void isSVGFEGaussianBlurElement(const SVGFEGaussianBlurElement*);

inline bool isSVGFEGaussianBlurElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feGaussianBlurTag);
}
inline bool isSVGFEGaussianBlurElement(const SVGElement* element)
{
    return element && isSVGFEGaussianBlurElement(*element);
}
inline bool isSVGFEGaussianBlurElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEGaussianBlurElement(toSVGElement(node));
}
inline bool isSVGFEGaussianBlurElement(const Node* node)
{
    return node && isSVGFEGaussianBlurElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEGaussianBlurElement>(const Node& node)
{
    return isSVGFEGaussianBlurElement(node);
}
template <>
inline bool isElementOfType<const SVGFEGaussianBlurElement>(const SVGElement& element)
{
    return isSVGFEGaussianBlurElement(element);
}

class SVGFEImageElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEImageElement(const SVGFEImageElement&);
void isSVGFEImageElement(const SVGFEImageElement*);

inline bool isSVGFEImageElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feImageTag);
}
inline bool isSVGFEImageElement(const SVGElement* element)
{
    return element && isSVGFEImageElement(*element);
}
inline bool isSVGFEImageElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEImageElement(toSVGElement(node));
}
inline bool isSVGFEImageElement(const Node* node)
{
    return node && isSVGFEImageElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEImageElement>(const Node& node)
{
    return isSVGFEImageElement(node);
}
template <>
inline bool isElementOfType<const SVGFEImageElement>(const SVGElement& element)
{
    return isSVGFEImageElement(element);
}

class SVGFEMergeElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEMergeElement(const SVGFEMergeElement&);
void isSVGFEMergeElement(const SVGFEMergeElement*);

inline bool isSVGFEMergeElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feMergeTag);
}
inline bool isSVGFEMergeElement(const SVGElement* element)
{
    return element && isSVGFEMergeElement(*element);
}
inline bool isSVGFEMergeElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEMergeElement(toSVGElement(node));
}
inline bool isSVGFEMergeElement(const Node* node)
{
    return node && isSVGFEMergeElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEMergeElement>(const Node& node)
{
    return isSVGFEMergeElement(node);
}
template <>
inline bool isElementOfType<const SVGFEMergeElement>(const SVGElement& element)
{
    return isSVGFEMergeElement(element);
}

class SVGFEMergeNodeElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEMergeNodeElement(const SVGFEMergeNodeElement&);
void isSVGFEMergeNodeElement(const SVGFEMergeNodeElement*);

inline bool isSVGFEMergeNodeElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feMergeNodeTag);
}
inline bool isSVGFEMergeNodeElement(const SVGElement* element)
{
    return element && isSVGFEMergeNodeElement(*element);
}
inline bool isSVGFEMergeNodeElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEMergeNodeElement(toSVGElement(node));
}
inline bool isSVGFEMergeNodeElement(const Node* node)
{
    return node && isSVGFEMergeNodeElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEMergeNodeElement>(const Node& node)
{
    return isSVGFEMergeNodeElement(node);
}
template <>
inline bool isElementOfType<const SVGFEMergeNodeElement>(const SVGElement& element)
{
    return isSVGFEMergeNodeElement(element);
}

class SVGFEMorphologyElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEMorphologyElement(const SVGFEMorphologyElement&);
void isSVGFEMorphologyElement(const SVGFEMorphologyElement*);

inline bool isSVGFEMorphologyElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feMorphologyTag);
}
inline bool isSVGFEMorphologyElement(const SVGElement* element)
{
    return element && isSVGFEMorphologyElement(*element);
}
inline bool isSVGFEMorphologyElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEMorphologyElement(toSVGElement(node));
}
inline bool isSVGFEMorphologyElement(const Node* node)
{
    return node && isSVGFEMorphologyElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEMorphologyElement>(const Node& node)
{
    return isSVGFEMorphologyElement(node);
}
template <>
inline bool isElementOfType<const SVGFEMorphologyElement>(const SVGElement& element)
{
    return isSVGFEMorphologyElement(element);
}

class SVGFEOffsetElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEOffsetElement(const SVGFEOffsetElement&);
void isSVGFEOffsetElement(const SVGFEOffsetElement*);

inline bool isSVGFEOffsetElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feOffsetTag);
}
inline bool isSVGFEOffsetElement(const SVGElement* element)
{
    return element && isSVGFEOffsetElement(*element);
}
inline bool isSVGFEOffsetElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEOffsetElement(toSVGElement(node));
}
inline bool isSVGFEOffsetElement(const Node* node)
{
    return node && isSVGFEOffsetElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEOffsetElement>(const Node& node)
{
    return isSVGFEOffsetElement(node);
}
template <>
inline bool isElementOfType<const SVGFEOffsetElement>(const SVGElement& element)
{
    return isSVGFEOffsetElement(element);
}

class SVGFEPointLightElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFEPointLightElement(const SVGFEPointLightElement&);
void isSVGFEPointLightElement(const SVGFEPointLightElement*);

inline bool isSVGFEPointLightElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::fePointLightTag);
}
inline bool isSVGFEPointLightElement(const SVGElement* element)
{
    return element && isSVGFEPointLightElement(*element);
}
inline bool isSVGFEPointLightElement(const Node& node)
{
    return node.isSVGElement() && isSVGFEPointLightElement(toSVGElement(node));
}
inline bool isSVGFEPointLightElement(const Node* node)
{
    return node && isSVGFEPointLightElement(*node);
}
template <>
inline bool isElementOfType<const SVGFEPointLightElement>(const Node& node)
{
    return isSVGFEPointLightElement(node);
}
template <>
inline bool isElementOfType<const SVGFEPointLightElement>(const SVGElement& element)
{
    return isSVGFEPointLightElement(element);
}

class SVGFESpecularLightingElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFESpecularLightingElement(const SVGFESpecularLightingElement&);
void isSVGFESpecularLightingElement(const SVGFESpecularLightingElement*);

inline bool isSVGFESpecularLightingElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feSpecularLightingTag);
}
inline bool isSVGFESpecularLightingElement(const SVGElement* element)
{
    return element && isSVGFESpecularLightingElement(*element);
}
inline bool isSVGFESpecularLightingElement(const Node& node)
{
    return node.isSVGElement() && isSVGFESpecularLightingElement(toSVGElement(node));
}
inline bool isSVGFESpecularLightingElement(const Node* node)
{
    return node && isSVGFESpecularLightingElement(*node);
}
template <>
inline bool isElementOfType<const SVGFESpecularLightingElement>(const Node& node)
{
    return isSVGFESpecularLightingElement(node);
}
template <>
inline bool isElementOfType<const SVGFESpecularLightingElement>(const SVGElement& element)
{
    return isSVGFESpecularLightingElement(element);
}

class SVGFESpotLightElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFESpotLightElement(const SVGFESpotLightElement&);
void isSVGFESpotLightElement(const SVGFESpotLightElement*);

inline bool isSVGFESpotLightElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feSpotLightTag);
}
inline bool isSVGFESpotLightElement(const SVGElement* element)
{
    return element && isSVGFESpotLightElement(*element);
}
inline bool isSVGFESpotLightElement(const Node& node)
{
    return node.isSVGElement() && isSVGFESpotLightElement(toSVGElement(node));
}
inline bool isSVGFESpotLightElement(const Node* node)
{
    return node && isSVGFESpotLightElement(*node);
}
template <>
inline bool isElementOfType<const SVGFESpotLightElement>(const Node& node)
{
    return isSVGFESpotLightElement(node);
}
template <>
inline bool isElementOfType<const SVGFESpotLightElement>(const SVGElement& element)
{
    return isSVGFESpotLightElement(element);
}

class SVGFETileElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFETileElement(const SVGFETileElement&);
void isSVGFETileElement(const SVGFETileElement*);

inline bool isSVGFETileElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feTileTag);
}
inline bool isSVGFETileElement(const SVGElement* element)
{
    return element && isSVGFETileElement(*element);
}
inline bool isSVGFETileElement(const Node& node)
{
    return node.isSVGElement() && isSVGFETileElement(toSVGElement(node));
}
inline bool isSVGFETileElement(const Node* node)
{
    return node && isSVGFETileElement(*node);
}
template <>
inline bool isElementOfType<const SVGFETileElement>(const Node& node)
{
    return isSVGFETileElement(node);
}
template <>
inline bool isElementOfType<const SVGFETileElement>(const SVGElement& element)
{
    return isSVGFETileElement(element);
}

class SVGFETurbulenceElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFETurbulenceElement(const SVGFETurbulenceElement&);
void isSVGFETurbulenceElement(const SVGFETurbulenceElement*);

inline bool isSVGFETurbulenceElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::feTurbulenceTag);
}
inline bool isSVGFETurbulenceElement(const SVGElement* element)
{
    return element && isSVGFETurbulenceElement(*element);
}
inline bool isSVGFETurbulenceElement(const Node& node)
{
    return node.isSVGElement() && isSVGFETurbulenceElement(toSVGElement(node));
}
inline bool isSVGFETurbulenceElement(const Node* node)
{
    return node && isSVGFETurbulenceElement(*node);
}
template <>
inline bool isElementOfType<const SVGFETurbulenceElement>(const Node& node)
{
    return isSVGFETurbulenceElement(node);
}
template <>
inline bool isElementOfType<const SVGFETurbulenceElement>(const SVGElement& element)
{
    return isSVGFETurbulenceElement(element);
}

class SVGFilterElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGFilterElement(const SVGFilterElement&);
void isSVGFilterElement(const SVGFilterElement*);

inline bool isSVGFilterElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::filterTag);
}
inline bool isSVGFilterElement(const SVGElement* element)
{
    return element && isSVGFilterElement(*element);
}
inline bool isSVGFilterElement(const Node& node)
{
    return node.isSVGElement() && isSVGFilterElement(toSVGElement(node));
}
inline bool isSVGFilterElement(const Node* node)
{
    return node && isSVGFilterElement(*node);
}
template <>
inline bool isElementOfType<const SVGFilterElement>(const Node& node)
{
    return isSVGFilterElement(node);
}
template <>
inline bool isElementOfType<const SVGFilterElement>(const SVGElement& element)
{
    return isSVGFilterElement(element);
}

class SVGForeignObjectElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGForeignObjectElement(const SVGForeignObjectElement&);
void isSVGForeignObjectElement(const SVGForeignObjectElement*);

inline bool isSVGForeignObjectElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::foreignObjectTag);
}
inline bool isSVGForeignObjectElement(const SVGElement* element)
{
    return element && isSVGForeignObjectElement(*element);
}
inline bool isSVGForeignObjectElement(const Node& node)
{
    return node.isSVGElement() && isSVGForeignObjectElement(toSVGElement(node));
}
inline bool isSVGForeignObjectElement(const Node* node)
{
    return node && isSVGForeignObjectElement(*node);
}
template <>
inline bool isElementOfType<const SVGForeignObjectElement>(const Node& node)
{
    return isSVGForeignObjectElement(node);
}
template <>
inline bool isElementOfType<const SVGForeignObjectElement>(const SVGElement& element)
{
    return isSVGForeignObjectElement(element);
}

class SVGGElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGGElement(const SVGGElement&);
void isSVGGElement(const SVGGElement*);

inline bool isSVGGElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::gTag);
}
inline bool isSVGGElement(const SVGElement* element)
{
    return element && isSVGGElement(*element);
}
inline bool isSVGGElement(const Node& node)
{
    return node.isSVGElement() && isSVGGElement(toSVGElement(node));
}
inline bool isSVGGElement(const Node* node)
{
    return node && isSVGGElement(*node);
}
template <>
inline bool isElementOfType<const SVGGElement>(const Node& node)
{
    return isSVGGElement(node);
}
template <>
inline bool isElementOfType<const SVGGElement>(const SVGElement& element)
{
    return isSVGGElement(element);
}

class SVGImageElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGImageElement(const SVGImageElement&);
void isSVGImageElement(const SVGImageElement*);

inline bool isSVGImageElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::imageTag);
}
inline bool isSVGImageElement(const SVGElement* element)
{
    return element && isSVGImageElement(*element);
}
inline bool isSVGImageElement(const Node& node)
{
    return node.isSVGElement() && isSVGImageElement(toSVGElement(node));
}
inline bool isSVGImageElement(const Node* node)
{
    return node && isSVGImageElement(*node);
}
template <>
inline bool isElementOfType<const SVGImageElement>(const Node& node)
{
    return isSVGImageElement(node);
}
template <>
inline bool isElementOfType<const SVGImageElement>(const SVGElement& element)
{
    return isSVGImageElement(element);
}

class SVGLineElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGLineElement(const SVGLineElement&);
void isSVGLineElement(const SVGLineElement*);

inline bool isSVGLineElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::lineTag);
}
inline bool isSVGLineElement(const SVGElement* element)
{
    return element && isSVGLineElement(*element);
}
inline bool isSVGLineElement(const Node& node)
{
    return node.isSVGElement() && isSVGLineElement(toSVGElement(node));
}
inline bool isSVGLineElement(const Node* node)
{
    return node && isSVGLineElement(*node);
}
template <>
inline bool isElementOfType<const SVGLineElement>(const Node& node)
{
    return isSVGLineElement(node);
}
template <>
inline bool isElementOfType<const SVGLineElement>(const SVGElement& element)
{
    return isSVGLineElement(element);
}

class SVGLinearGradientElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGLinearGradientElement(const SVGLinearGradientElement&);
void isSVGLinearGradientElement(const SVGLinearGradientElement*);

inline bool isSVGLinearGradientElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::linearGradientTag);
}
inline bool isSVGLinearGradientElement(const SVGElement* element)
{
    return element && isSVGLinearGradientElement(*element);
}
inline bool isSVGLinearGradientElement(const Node& node)
{
    return node.isSVGElement() && isSVGLinearGradientElement(toSVGElement(node));
}
inline bool isSVGLinearGradientElement(const Node* node)
{
    return node && isSVGLinearGradientElement(*node);
}
template <>
inline bool isElementOfType<const SVGLinearGradientElement>(const Node& node)
{
    return isSVGLinearGradientElement(node);
}
template <>
inline bool isElementOfType<const SVGLinearGradientElement>(const SVGElement& element)
{
    return isSVGLinearGradientElement(element);
}

class SVGMPathElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGMPathElement(const SVGMPathElement&);
void isSVGMPathElement(const SVGMPathElement*);

inline bool isSVGMPathElement(const SVGElement& element)
{
    if (!RuntimeEnabledFeatures::smilEnabled())
        return false;
    return element.hasTagName(SVGNames::mpathTag);
}
inline bool isSVGMPathElement(const SVGElement* element)
{
    return element && isSVGMPathElement(*element);
}
inline bool isSVGMPathElement(const Node& node)
{
    return node.isSVGElement() && isSVGMPathElement(toSVGElement(node));
}
inline bool isSVGMPathElement(const Node* node)
{
    return node && isSVGMPathElement(*node);
}
template <>
inline bool isElementOfType<const SVGMPathElement>(const Node& node)
{
    return isSVGMPathElement(node);
}
template <>
inline bool isElementOfType<const SVGMPathElement>(const SVGElement& element)
{
    return isSVGMPathElement(element);
}

class SVGMarkerElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGMarkerElement(const SVGMarkerElement&);
void isSVGMarkerElement(const SVGMarkerElement*);

inline bool isSVGMarkerElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::markerTag);
}
inline bool isSVGMarkerElement(const SVGElement* element)
{
    return element && isSVGMarkerElement(*element);
}
inline bool isSVGMarkerElement(const Node& node)
{
    return node.isSVGElement() && isSVGMarkerElement(toSVGElement(node));
}
inline bool isSVGMarkerElement(const Node* node)
{
    return node && isSVGMarkerElement(*node);
}
template <>
inline bool isElementOfType<const SVGMarkerElement>(const Node& node)
{
    return isSVGMarkerElement(node);
}
template <>
inline bool isElementOfType<const SVGMarkerElement>(const SVGElement& element)
{
    return isSVGMarkerElement(element);
}

class SVGMaskElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGMaskElement(const SVGMaskElement&);
void isSVGMaskElement(const SVGMaskElement*);

inline bool isSVGMaskElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::maskTag);
}
inline bool isSVGMaskElement(const SVGElement* element)
{
    return element && isSVGMaskElement(*element);
}
inline bool isSVGMaskElement(const Node& node)
{
    return node.isSVGElement() && isSVGMaskElement(toSVGElement(node));
}
inline bool isSVGMaskElement(const Node* node)
{
    return node && isSVGMaskElement(*node);
}
template <>
inline bool isElementOfType<const SVGMaskElement>(const Node& node)
{
    return isSVGMaskElement(node);
}
template <>
inline bool isElementOfType<const SVGMaskElement>(const SVGElement& element)
{
    return isSVGMaskElement(element);
}

class SVGMetadataElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGMetadataElement(const SVGMetadataElement&);
void isSVGMetadataElement(const SVGMetadataElement*);

inline bool isSVGMetadataElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::metadataTag);
}
inline bool isSVGMetadataElement(const SVGElement* element)
{
    return element && isSVGMetadataElement(*element);
}
inline bool isSVGMetadataElement(const Node& node)
{
    return node.isSVGElement() && isSVGMetadataElement(toSVGElement(node));
}
inline bool isSVGMetadataElement(const Node* node)
{
    return node && isSVGMetadataElement(*node);
}
template <>
inline bool isElementOfType<const SVGMetadataElement>(const Node& node)
{
    return isSVGMetadataElement(node);
}
template <>
inline bool isElementOfType<const SVGMetadataElement>(const SVGElement& element)
{
    return isSVGMetadataElement(element);
}

class SVGPathElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGPathElement(const SVGPathElement&);
void isSVGPathElement(const SVGPathElement*);

inline bool isSVGPathElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::pathTag);
}
inline bool isSVGPathElement(const SVGElement* element)
{
    return element && isSVGPathElement(*element);
}
inline bool isSVGPathElement(const Node& node)
{
    return node.isSVGElement() && isSVGPathElement(toSVGElement(node));
}
inline bool isSVGPathElement(const Node* node)
{
    return node && isSVGPathElement(*node);
}
template <>
inline bool isElementOfType<const SVGPathElement>(const Node& node)
{
    return isSVGPathElement(node);
}
template <>
inline bool isElementOfType<const SVGPathElement>(const SVGElement& element)
{
    return isSVGPathElement(element);
}

class SVGPatternElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGPatternElement(const SVGPatternElement&);
void isSVGPatternElement(const SVGPatternElement*);

inline bool isSVGPatternElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::patternTag);
}
inline bool isSVGPatternElement(const SVGElement* element)
{
    return element && isSVGPatternElement(*element);
}
inline bool isSVGPatternElement(const Node& node)
{
    return node.isSVGElement() && isSVGPatternElement(toSVGElement(node));
}
inline bool isSVGPatternElement(const Node* node)
{
    return node && isSVGPatternElement(*node);
}
template <>
inline bool isElementOfType<const SVGPatternElement>(const Node& node)
{
    return isSVGPatternElement(node);
}
template <>
inline bool isElementOfType<const SVGPatternElement>(const SVGElement& element)
{
    return isSVGPatternElement(element);
}

class SVGPolygonElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGPolygonElement(const SVGPolygonElement&);
void isSVGPolygonElement(const SVGPolygonElement*);

inline bool isSVGPolygonElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::polygonTag);
}
inline bool isSVGPolygonElement(const SVGElement* element)
{
    return element && isSVGPolygonElement(*element);
}
inline bool isSVGPolygonElement(const Node& node)
{
    return node.isSVGElement() && isSVGPolygonElement(toSVGElement(node));
}
inline bool isSVGPolygonElement(const Node* node)
{
    return node && isSVGPolygonElement(*node);
}
template <>
inline bool isElementOfType<const SVGPolygonElement>(const Node& node)
{
    return isSVGPolygonElement(node);
}
template <>
inline bool isElementOfType<const SVGPolygonElement>(const SVGElement& element)
{
    return isSVGPolygonElement(element);
}

class SVGPolylineElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGPolylineElement(const SVGPolylineElement&);
void isSVGPolylineElement(const SVGPolylineElement*);

inline bool isSVGPolylineElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::polylineTag);
}
inline bool isSVGPolylineElement(const SVGElement* element)
{
    return element && isSVGPolylineElement(*element);
}
inline bool isSVGPolylineElement(const Node& node)
{
    return node.isSVGElement() && isSVGPolylineElement(toSVGElement(node));
}
inline bool isSVGPolylineElement(const Node* node)
{
    return node && isSVGPolylineElement(*node);
}
template <>
inline bool isElementOfType<const SVGPolylineElement>(const Node& node)
{
    return isSVGPolylineElement(node);
}
template <>
inline bool isElementOfType<const SVGPolylineElement>(const SVGElement& element)
{
    return isSVGPolylineElement(element);
}

class SVGRadialGradientElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGRadialGradientElement(const SVGRadialGradientElement&);
void isSVGRadialGradientElement(const SVGRadialGradientElement*);

inline bool isSVGRadialGradientElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::radialGradientTag);
}
inline bool isSVGRadialGradientElement(const SVGElement* element)
{
    return element && isSVGRadialGradientElement(*element);
}
inline bool isSVGRadialGradientElement(const Node& node)
{
    return node.isSVGElement() && isSVGRadialGradientElement(toSVGElement(node));
}
inline bool isSVGRadialGradientElement(const Node* node)
{
    return node && isSVGRadialGradientElement(*node);
}
template <>
inline bool isElementOfType<const SVGRadialGradientElement>(const Node& node)
{
    return isSVGRadialGradientElement(node);
}
template <>
inline bool isElementOfType<const SVGRadialGradientElement>(const SVGElement& element)
{
    return isSVGRadialGradientElement(element);
}

class SVGRectElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGRectElement(const SVGRectElement&);
void isSVGRectElement(const SVGRectElement*);

inline bool isSVGRectElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::rectTag);
}
inline bool isSVGRectElement(const SVGElement* element)
{
    return element && isSVGRectElement(*element);
}
inline bool isSVGRectElement(const Node& node)
{
    return node.isSVGElement() && isSVGRectElement(toSVGElement(node));
}
inline bool isSVGRectElement(const Node* node)
{
    return node && isSVGRectElement(*node);
}
template <>
inline bool isElementOfType<const SVGRectElement>(const Node& node)
{
    return isSVGRectElement(node);
}
template <>
inline bool isElementOfType<const SVGRectElement>(const SVGElement& element)
{
    return isSVGRectElement(element);
}

class SVGSVGElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGSVGElement(const SVGSVGElement&);
void isSVGSVGElement(const SVGSVGElement*);

inline bool isSVGSVGElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::svgTag);
}
inline bool isSVGSVGElement(const SVGElement* element)
{
    return element && isSVGSVGElement(*element);
}
inline bool isSVGSVGElement(const Node& node)
{
    return node.isSVGElement() && isSVGSVGElement(toSVGElement(node));
}
inline bool isSVGSVGElement(const Node* node)
{
    return node && isSVGSVGElement(*node);
}
template <>
inline bool isElementOfType<const SVGSVGElement>(const Node& node)
{
    return isSVGSVGElement(node);
}
template <>
inline bool isElementOfType<const SVGSVGElement>(const SVGElement& element)
{
    return isSVGSVGElement(element);
}

class SVGSetElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGSetElement(const SVGSetElement&);
void isSVGSetElement(const SVGSetElement*);

inline bool isSVGSetElement(const SVGElement& element)
{
    if (!RuntimeEnabledFeatures::smilEnabled())
        return false;
    return element.hasTagName(SVGNames::setTag);
}
inline bool isSVGSetElement(const SVGElement* element)
{
    return element && isSVGSetElement(*element);
}
inline bool isSVGSetElement(const Node& node)
{
    return node.isSVGElement() && isSVGSetElement(toSVGElement(node));
}
inline bool isSVGSetElement(const Node* node)
{
    return node && isSVGSetElement(*node);
}
template <>
inline bool isElementOfType<const SVGSetElement>(const Node& node)
{
    return isSVGSetElement(node);
}
template <>
inline bool isElementOfType<const SVGSetElement>(const SVGElement& element)
{
    return isSVGSetElement(element);
}

class SVGStopElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGStopElement(const SVGStopElement&);
void isSVGStopElement(const SVGStopElement*);

inline bool isSVGStopElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::stopTag);
}
inline bool isSVGStopElement(const SVGElement* element)
{
    return element && isSVGStopElement(*element);
}
inline bool isSVGStopElement(const Node& node)
{
    return node.isSVGElement() && isSVGStopElement(toSVGElement(node));
}
inline bool isSVGStopElement(const Node* node)
{
    return node && isSVGStopElement(*node);
}
template <>
inline bool isElementOfType<const SVGStopElement>(const Node& node)
{
    return isSVGStopElement(node);
}
template <>
inline bool isElementOfType<const SVGStopElement>(const SVGElement& element)
{
    return isSVGStopElement(element);
}

class SVGSwitchElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGSwitchElement(const SVGSwitchElement&);
void isSVGSwitchElement(const SVGSwitchElement*);

inline bool isSVGSwitchElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::switchTag);
}
inline bool isSVGSwitchElement(const SVGElement* element)
{
    return element && isSVGSwitchElement(*element);
}
inline bool isSVGSwitchElement(const Node& node)
{
    return node.isSVGElement() && isSVGSwitchElement(toSVGElement(node));
}
inline bool isSVGSwitchElement(const Node* node)
{
    return node && isSVGSwitchElement(*node);
}
template <>
inline bool isElementOfType<const SVGSwitchElement>(const Node& node)
{
    return isSVGSwitchElement(node);
}
template <>
inline bool isElementOfType<const SVGSwitchElement>(const SVGElement& element)
{
    return isSVGSwitchElement(element);
}

class SVGSymbolElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGSymbolElement(const SVGSymbolElement&);
void isSVGSymbolElement(const SVGSymbolElement*);

inline bool isSVGSymbolElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::symbolTag);
}
inline bool isSVGSymbolElement(const SVGElement* element)
{
    return element && isSVGSymbolElement(*element);
}
inline bool isSVGSymbolElement(const Node& node)
{
    return node.isSVGElement() && isSVGSymbolElement(toSVGElement(node));
}
inline bool isSVGSymbolElement(const Node* node)
{
    return node && isSVGSymbolElement(*node);
}
template <>
inline bool isElementOfType<const SVGSymbolElement>(const Node& node)
{
    return isSVGSymbolElement(node);
}
template <>
inline bool isElementOfType<const SVGSymbolElement>(const SVGElement& element)
{
    return isSVGSymbolElement(element);
}

class SVGTSpanElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGTSpanElement(const SVGTSpanElement&);
void isSVGTSpanElement(const SVGTSpanElement*);

inline bool isSVGTSpanElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::tspanTag);
}
inline bool isSVGTSpanElement(const SVGElement* element)
{
    return element && isSVGTSpanElement(*element);
}
inline bool isSVGTSpanElement(const Node& node)
{
    return node.isSVGElement() && isSVGTSpanElement(toSVGElement(node));
}
inline bool isSVGTSpanElement(const Node* node)
{
    return node && isSVGTSpanElement(*node);
}
template <>
inline bool isElementOfType<const SVGTSpanElement>(const Node& node)
{
    return isSVGTSpanElement(node);
}
template <>
inline bool isElementOfType<const SVGTSpanElement>(const SVGElement& element)
{
    return isSVGTSpanElement(element);
}

class SVGTextElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGTextElement(const SVGTextElement&);
void isSVGTextElement(const SVGTextElement*);

inline bool isSVGTextElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::textTag);
}
inline bool isSVGTextElement(const SVGElement* element)
{
    return element && isSVGTextElement(*element);
}
inline bool isSVGTextElement(const Node& node)
{
    return node.isSVGElement() && isSVGTextElement(toSVGElement(node));
}
inline bool isSVGTextElement(const Node* node)
{
    return node && isSVGTextElement(*node);
}
template <>
inline bool isElementOfType<const SVGTextElement>(const Node& node)
{
    return isSVGTextElement(node);
}
template <>
inline bool isElementOfType<const SVGTextElement>(const SVGElement& element)
{
    return isSVGTextElement(element);
}

class SVGTextPathElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGTextPathElement(const SVGTextPathElement&);
void isSVGTextPathElement(const SVGTextPathElement*);

inline bool isSVGTextPathElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::textPathTag);
}
inline bool isSVGTextPathElement(const SVGElement* element)
{
    return element && isSVGTextPathElement(*element);
}
inline bool isSVGTextPathElement(const Node& node)
{
    return node.isSVGElement() && isSVGTextPathElement(toSVGElement(node));
}
inline bool isSVGTextPathElement(const Node* node)
{
    return node && isSVGTextPathElement(*node);
}
template <>
inline bool isElementOfType<const SVGTextPathElement>(const Node& node)
{
    return isSVGTextPathElement(node);
}
template <>
inline bool isElementOfType<const SVGTextPathElement>(const SVGElement& element)
{
    return isSVGTextPathElement(element);
}

class SVGTitleElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGTitleElement(const SVGTitleElement&);
void isSVGTitleElement(const SVGTitleElement*);

inline bool isSVGTitleElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::titleTag);
}
inline bool isSVGTitleElement(const SVGElement* element)
{
    return element && isSVGTitleElement(*element);
}
inline bool isSVGTitleElement(const Node& node)
{
    return node.isSVGElement() && isSVGTitleElement(toSVGElement(node));
}
inline bool isSVGTitleElement(const Node* node)
{
    return node && isSVGTitleElement(*node);
}
template <>
inline bool isElementOfType<const SVGTitleElement>(const Node& node)
{
    return isSVGTitleElement(node);
}
template <>
inline bool isElementOfType<const SVGTitleElement>(const SVGElement& element)
{
    return isSVGTitleElement(element);
}

class SVGUseElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGUseElement(const SVGUseElement&);
void isSVGUseElement(const SVGUseElement*);

inline bool isSVGUseElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::useTag);
}
inline bool isSVGUseElement(const SVGElement* element)
{
    return element && isSVGUseElement(*element);
}
inline bool isSVGUseElement(const Node& node)
{
    return node.isSVGElement() && isSVGUseElement(toSVGElement(node));
}
inline bool isSVGUseElement(const Node* node)
{
    return node && isSVGUseElement(*node);
}
template <>
inline bool isElementOfType<const SVGUseElement>(const Node& node)
{
    return isSVGUseElement(node);
}
template <>
inline bool isElementOfType<const SVGUseElement>(const SVGElement& element)
{
    return isSVGUseElement(element);
}

class SVGViewElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGViewElement(const SVGViewElement&);
void isSVGViewElement(const SVGViewElement*);

inline bool isSVGViewElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::viewTag);
}
inline bool isSVGViewElement(const SVGElement* element)
{
    return element && isSVGViewElement(*element);
}
inline bool isSVGViewElement(const Node& node)
{
    return node.isSVGElement() && isSVGViewElement(toSVGElement(node));
}
inline bool isSVGViewElement(const Node* node)
{
    return node && isSVGViewElement(*node);
}
template <>
inline bool isElementOfType<const SVGViewElement>(const Node& node)
{
    return isSVGViewElement(node);
}
template <>
inline bool isElementOfType<const SVGViewElement>(const SVGElement& element)
{
    return isSVGViewElement(element);
}

class SVGScriptElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGScriptElement(const SVGScriptElement&);
void isSVGScriptElement(const SVGScriptElement*);

inline bool isSVGScriptElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::scriptTag);
}
inline bool isSVGScriptElement(const SVGElement* element)
{
    return element && isSVGScriptElement(*element);
}
inline bool isSVGScriptElement(const Node& node)
{
    return node.isSVGElement() && isSVGScriptElement(toSVGElement(node));
}
inline bool isSVGScriptElement(const Node* node)
{
    return node && isSVGScriptElement(*node);
}
template <>
inline bool isElementOfType<const SVGScriptElement>(const Node& node)
{
    return isSVGScriptElement(node);
}
template <>
inline bool isElementOfType<const SVGScriptElement>(const SVGElement& element)
{
    return isSVGScriptElement(element);
}

class SVGStyleElement;
// Catch unnecessary runtime check of type known at compile time.
void isSVGStyleElement(const SVGStyleElement&);
void isSVGStyleElement(const SVGStyleElement*);

inline bool isSVGStyleElement(const SVGElement& element)
{
    return element.hasTagName(SVGNames::styleTag);
}
inline bool isSVGStyleElement(const SVGElement* element)
{
    return element && isSVGStyleElement(*element);
}
inline bool isSVGStyleElement(const Node& node)
{
    return node.isSVGElement() && isSVGStyleElement(toSVGElement(node));
}
inline bool isSVGStyleElement(const Node* node)
{
    return node && isSVGStyleElement(*node);
}
template <>
inline bool isElementOfType<const SVGStyleElement>(const Node& node)
{
    return isSVGStyleElement(node);
}
template <>
inline bool isElementOfType<const SVGStyleElement>(const SVGElement& element)
{
    return isSVGStyleElement(element);
}

// Using macros because the types are forward-declared and we don't want to use
// reinterpret_cast in the casting functions above. reinterpret_cast would be
// unsafe due to multiple inheritence.

#define toSVGAElement(x) blink::toElement<blink::SVGAElement>(x)
#define toSVGAElementOrDie(x) blink::toElementOrDie<blink::SVGAElement>(x)
#define toSVGAnimateMotionElement(x) blink::toElement<blink::SVGAnimateMotionElement>(x)
#define toSVGAnimateMotionElementOrDie(x) blink::toElementOrDie<blink::SVGAnimateMotionElement>(x)
#define toSVGAnimateTransformElement(x) blink::toElement<blink::SVGAnimateTransformElement>(x)
#define toSVGAnimateTransformElementOrDie(x) blink::toElementOrDie<blink::SVGAnimateTransformElement>(x)
#define toSVGCircleElement(x) blink::toElement<blink::SVGCircleElement>(x)
#define toSVGCircleElementOrDie(x) blink::toElementOrDie<blink::SVGCircleElement>(x)
#define toSVGClipPathElement(x) blink::toElement<blink::SVGClipPathElement>(x)
#define toSVGClipPathElementOrDie(x) blink::toElementOrDie<blink::SVGClipPathElement>(x)
#define toSVGDefsElement(x) blink::toElement<blink::SVGDefsElement>(x)
#define toSVGDefsElementOrDie(x) blink::toElementOrDie<blink::SVGDefsElement>(x)
#define toSVGDescElement(x) blink::toElement<blink::SVGDescElement>(x)
#define toSVGDescElementOrDie(x) blink::toElementOrDie<blink::SVGDescElement>(x)
#define toSVGDiscardElement(x) blink::toElement<blink::SVGDiscardElement>(x)
#define toSVGDiscardElementOrDie(x) blink::toElementOrDie<blink::SVGDiscardElement>(x)
#define toSVGEllipseElement(x) blink::toElement<blink::SVGEllipseElement>(x)
#define toSVGEllipseElementOrDie(x) blink::toElementOrDie<blink::SVGEllipseElement>(x)
#define toSVGFEBlendElement(x) blink::toElement<blink::SVGFEBlendElement>(x)
#define toSVGFEBlendElementOrDie(x) blink::toElementOrDie<blink::SVGFEBlendElement>(x)
#define toSVGFEColorMatrixElement(x) blink::toElement<blink::SVGFEColorMatrixElement>(x)
#define toSVGFEColorMatrixElementOrDie(x) blink::toElementOrDie<blink::SVGFEColorMatrixElement>(x)
#define toSVGFEComponentTransferElement(x) blink::toElement<blink::SVGFEComponentTransferElement>(x)
#define toSVGFEComponentTransferElementOrDie(x) blink::toElementOrDie<blink::SVGFEComponentTransferElement>(x)
#define toSVGFECompositeElement(x) blink::toElement<blink::SVGFECompositeElement>(x)
#define toSVGFECompositeElementOrDie(x) blink::toElementOrDie<blink::SVGFECompositeElement>(x)
#define toSVGFEConvolveMatrixElement(x) blink::toElement<blink::SVGFEConvolveMatrixElement>(x)
#define toSVGFEConvolveMatrixElementOrDie(x) blink::toElementOrDie<blink::SVGFEConvolveMatrixElement>(x)
#define toSVGFEDiffuseLightingElement(x) blink::toElement<blink::SVGFEDiffuseLightingElement>(x)
#define toSVGFEDiffuseLightingElementOrDie(x) blink::toElementOrDie<blink::SVGFEDiffuseLightingElement>(x)
#define toSVGFEDisplacementMapElement(x) blink::toElement<blink::SVGFEDisplacementMapElement>(x)
#define toSVGFEDisplacementMapElementOrDie(x) blink::toElementOrDie<blink::SVGFEDisplacementMapElement>(x)
#define toSVGFEDistantLightElement(x) blink::toElement<blink::SVGFEDistantLightElement>(x)
#define toSVGFEDistantLightElementOrDie(x) blink::toElementOrDie<blink::SVGFEDistantLightElement>(x)
#define toSVGFEDropShadowElement(x) blink::toElement<blink::SVGFEDropShadowElement>(x)
#define toSVGFEDropShadowElementOrDie(x) blink::toElementOrDie<blink::SVGFEDropShadowElement>(x)
#define toSVGFEFloodElement(x) blink::toElement<blink::SVGFEFloodElement>(x)
#define toSVGFEFloodElementOrDie(x) blink::toElementOrDie<blink::SVGFEFloodElement>(x)
#define toSVGFEFuncAElement(x) blink::toElement<blink::SVGFEFuncAElement>(x)
#define toSVGFEFuncAElementOrDie(x) blink::toElementOrDie<blink::SVGFEFuncAElement>(x)
#define toSVGFEFuncBElement(x) blink::toElement<blink::SVGFEFuncBElement>(x)
#define toSVGFEFuncBElementOrDie(x) blink::toElementOrDie<blink::SVGFEFuncBElement>(x)
#define toSVGFEFuncGElement(x) blink::toElement<blink::SVGFEFuncGElement>(x)
#define toSVGFEFuncGElementOrDie(x) blink::toElementOrDie<blink::SVGFEFuncGElement>(x)
#define toSVGFEFuncRElement(x) blink::toElement<blink::SVGFEFuncRElement>(x)
#define toSVGFEFuncRElementOrDie(x) blink::toElementOrDie<blink::SVGFEFuncRElement>(x)
#define toSVGFEGaussianBlurElement(x) blink::toElement<blink::SVGFEGaussianBlurElement>(x)
#define toSVGFEGaussianBlurElementOrDie(x) blink::toElementOrDie<blink::SVGFEGaussianBlurElement>(x)
#define toSVGFEImageElement(x) blink::toElement<blink::SVGFEImageElement>(x)
#define toSVGFEImageElementOrDie(x) blink::toElementOrDie<blink::SVGFEImageElement>(x)
#define toSVGFEMergeElement(x) blink::toElement<blink::SVGFEMergeElement>(x)
#define toSVGFEMergeElementOrDie(x) blink::toElementOrDie<blink::SVGFEMergeElement>(x)
#define toSVGFEMergeNodeElement(x) blink::toElement<blink::SVGFEMergeNodeElement>(x)
#define toSVGFEMergeNodeElementOrDie(x) blink::toElementOrDie<blink::SVGFEMergeNodeElement>(x)
#define toSVGFEMorphologyElement(x) blink::toElement<blink::SVGFEMorphologyElement>(x)
#define toSVGFEMorphologyElementOrDie(x) blink::toElementOrDie<blink::SVGFEMorphologyElement>(x)
#define toSVGFEOffsetElement(x) blink::toElement<blink::SVGFEOffsetElement>(x)
#define toSVGFEOffsetElementOrDie(x) blink::toElementOrDie<blink::SVGFEOffsetElement>(x)
#define toSVGFEPointLightElement(x) blink::toElement<blink::SVGFEPointLightElement>(x)
#define toSVGFEPointLightElementOrDie(x) blink::toElementOrDie<blink::SVGFEPointLightElement>(x)
#define toSVGFESpecularLightingElement(x) blink::toElement<blink::SVGFESpecularLightingElement>(x)
#define toSVGFESpecularLightingElementOrDie(x) blink::toElementOrDie<blink::SVGFESpecularLightingElement>(x)
#define toSVGFESpotLightElement(x) blink::toElement<blink::SVGFESpotLightElement>(x)
#define toSVGFESpotLightElementOrDie(x) blink::toElementOrDie<blink::SVGFESpotLightElement>(x)
#define toSVGFETileElement(x) blink::toElement<blink::SVGFETileElement>(x)
#define toSVGFETileElementOrDie(x) blink::toElementOrDie<blink::SVGFETileElement>(x)
#define toSVGFETurbulenceElement(x) blink::toElement<blink::SVGFETurbulenceElement>(x)
#define toSVGFETurbulenceElementOrDie(x) blink::toElementOrDie<blink::SVGFETurbulenceElement>(x)
#define toSVGFilterElement(x) blink::toElement<blink::SVGFilterElement>(x)
#define toSVGFilterElementOrDie(x) blink::toElementOrDie<blink::SVGFilterElement>(x)
#define toSVGForeignObjectElement(x) blink::toElement<blink::SVGForeignObjectElement>(x)
#define toSVGForeignObjectElementOrDie(x) blink::toElementOrDie<blink::SVGForeignObjectElement>(x)
#define toSVGGElement(x) blink::toElement<blink::SVGGElement>(x)
#define toSVGGElementOrDie(x) blink::toElementOrDie<blink::SVGGElement>(x)
#define toSVGImageElement(x) blink::toElement<blink::SVGImageElement>(x)
#define toSVGImageElementOrDie(x) blink::toElementOrDie<blink::SVGImageElement>(x)
#define toSVGLineElement(x) blink::toElement<blink::SVGLineElement>(x)
#define toSVGLineElementOrDie(x) blink::toElementOrDie<blink::SVGLineElement>(x)
#define toSVGLinearGradientElement(x) blink::toElement<blink::SVGLinearGradientElement>(x)
#define toSVGLinearGradientElementOrDie(x) blink::toElementOrDie<blink::SVGLinearGradientElement>(x)
#define toSVGMPathElement(x) blink::toElement<blink::SVGMPathElement>(x)
#define toSVGMPathElementOrDie(x) blink::toElementOrDie<blink::SVGMPathElement>(x)
#define toSVGMarkerElement(x) blink::toElement<blink::SVGMarkerElement>(x)
#define toSVGMarkerElementOrDie(x) blink::toElementOrDie<blink::SVGMarkerElement>(x)
#define toSVGMaskElement(x) blink::toElement<blink::SVGMaskElement>(x)
#define toSVGMaskElementOrDie(x) blink::toElementOrDie<blink::SVGMaskElement>(x)
#define toSVGMetadataElement(x) blink::toElement<blink::SVGMetadataElement>(x)
#define toSVGMetadataElementOrDie(x) blink::toElementOrDie<blink::SVGMetadataElement>(x)
#define toSVGPathElement(x) blink::toElement<blink::SVGPathElement>(x)
#define toSVGPathElementOrDie(x) blink::toElementOrDie<blink::SVGPathElement>(x)
#define toSVGPatternElement(x) blink::toElement<blink::SVGPatternElement>(x)
#define toSVGPatternElementOrDie(x) blink::toElementOrDie<blink::SVGPatternElement>(x)
#define toSVGPolygonElement(x) blink::toElement<blink::SVGPolygonElement>(x)
#define toSVGPolygonElementOrDie(x) blink::toElementOrDie<blink::SVGPolygonElement>(x)
#define toSVGPolylineElement(x) blink::toElement<blink::SVGPolylineElement>(x)
#define toSVGPolylineElementOrDie(x) blink::toElementOrDie<blink::SVGPolylineElement>(x)
#define toSVGRadialGradientElement(x) blink::toElement<blink::SVGRadialGradientElement>(x)
#define toSVGRadialGradientElementOrDie(x) blink::toElementOrDie<blink::SVGRadialGradientElement>(x)
#define toSVGRectElement(x) blink::toElement<blink::SVGRectElement>(x)
#define toSVGRectElementOrDie(x) blink::toElementOrDie<blink::SVGRectElement>(x)
#define toSVGSVGElement(x) blink::toElement<blink::SVGSVGElement>(x)
#define toSVGSVGElementOrDie(x) blink::toElementOrDie<blink::SVGSVGElement>(x)
#define toSVGSetElement(x) blink::toElement<blink::SVGSetElement>(x)
#define toSVGSetElementOrDie(x) blink::toElementOrDie<blink::SVGSetElement>(x)
#define toSVGStopElement(x) blink::toElement<blink::SVGStopElement>(x)
#define toSVGStopElementOrDie(x) blink::toElementOrDie<blink::SVGStopElement>(x)
#define toSVGSwitchElement(x) blink::toElement<blink::SVGSwitchElement>(x)
#define toSVGSwitchElementOrDie(x) blink::toElementOrDie<blink::SVGSwitchElement>(x)
#define toSVGSymbolElement(x) blink::toElement<blink::SVGSymbolElement>(x)
#define toSVGSymbolElementOrDie(x) blink::toElementOrDie<blink::SVGSymbolElement>(x)
#define toSVGTSpanElement(x) blink::toElement<blink::SVGTSpanElement>(x)
#define toSVGTSpanElementOrDie(x) blink::toElementOrDie<blink::SVGTSpanElement>(x)
#define toSVGTextElement(x) blink::toElement<blink::SVGTextElement>(x)
#define toSVGTextElementOrDie(x) blink::toElementOrDie<blink::SVGTextElement>(x)
#define toSVGTextPathElement(x) blink::toElement<blink::SVGTextPathElement>(x)
#define toSVGTextPathElementOrDie(x) blink::toElementOrDie<blink::SVGTextPathElement>(x)
#define toSVGTitleElement(x) blink::toElement<blink::SVGTitleElement>(x)
#define toSVGTitleElementOrDie(x) blink::toElementOrDie<blink::SVGTitleElement>(x)
#define toSVGUseElement(x) blink::toElement<blink::SVGUseElement>(x)
#define toSVGUseElementOrDie(x) blink::toElementOrDie<blink::SVGUseElement>(x)
#define toSVGViewElement(x) blink::toElement<blink::SVGViewElement>(x)
#define toSVGViewElementOrDie(x) blink::toElementOrDie<blink::SVGViewElement>(x)
#define toSVGScriptElement(x) blink::toElement<blink::SVGScriptElement>(x)
#define toSVGScriptElementOrDie(x) blink::toElementOrDie<blink::SVGScriptElement>(x)
#define toSVGStyleElement(x) blink::toElement<blink::SVGStyleElement>(x)
#define toSVGStyleElementOrDie(x) blink::toElementOrDie<blink::SVGStyleElement>(x)

} // namespace blink

#endif
