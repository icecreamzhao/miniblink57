// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "SVGElementFactory.h"

#include "SVGNames.h"
#include "core/dom/Document.h"
#include "core/dom/custom/V0CustomElement.h"
#include "core/dom/custom/V0CustomElementRegistrationContext.h"
#include "core/frame/Settings.h"
#include "core/svg/SVGAElement.h"
#include "core/svg/SVGAnimateElement.h"
#include "core/svg/SVGAnimateMotionElement.h"
#include "core/svg/SVGAnimateTransformElement.h"
#include "core/svg/SVGCircleElement.h"
#include "core/svg/SVGClipPathElement.h"
#include "core/svg/SVGDefsElement.h"
#include "core/svg/SVGDescElement.h"
#include "core/svg/SVGDiscardElement.h"
#include "core/svg/SVGEllipseElement.h"
#include "core/svg/SVGFEBlendElement.h"
#include "core/svg/SVGFEColorMatrixElement.h"
#include "core/svg/SVGFEComponentTransferElement.h"
#include "core/svg/SVGFECompositeElement.h"
#include "core/svg/SVGFEConvolveMatrixElement.h"
#include "core/svg/SVGFEDiffuseLightingElement.h"
#include "core/svg/SVGFEDisplacementMapElement.h"
#include "core/svg/SVGFEDistantLightElement.h"
#include "core/svg/SVGFEDropShadowElement.h"
#include "core/svg/SVGFEFloodElement.h"
#include "core/svg/SVGFEFuncAElement.h"
#include "core/svg/SVGFEFuncBElement.h"
#include "core/svg/SVGFEFuncGElement.h"
#include "core/svg/SVGFEFuncRElement.h"
#include "core/svg/SVGFEGaussianBlurElement.h"
#include "core/svg/SVGFEImageElement.h"
#include "core/svg/SVGFEMergeElement.h"
#include "core/svg/SVGFEMergeNodeElement.h"
#include "core/svg/SVGFEMorphologyElement.h"
#include "core/svg/SVGFEOffsetElement.h"
#include "core/svg/SVGFEPointLightElement.h"
#include "core/svg/SVGFESpecularLightingElement.h"
#include "core/svg/SVGFESpotLightElement.h"
#include "core/svg/SVGFETileElement.h"
#include "core/svg/SVGFETurbulenceElement.h"
#include "core/svg/SVGFilterElement.h"
#include "core/svg/SVGForeignObjectElement.h"
#include "core/svg/SVGGElement.h"
#include "core/svg/SVGImageElement.h"
#include "core/svg/SVGLineElement.h"
#include "core/svg/SVGLinearGradientElement.h"
#include "core/svg/SVGMPathElement.h"
#include "core/svg/SVGMarkerElement.h"
#include "core/svg/SVGMaskElement.h"
#include "core/svg/SVGMetadataElement.h"
#include "core/svg/SVGPathElement.h"
#include "core/svg/SVGPatternElement.h"
#include "core/svg/SVGPolygonElement.h"
#include "core/svg/SVGPolylineElement.h"
#include "core/svg/SVGRadialGradientElement.h"
#include "core/svg/SVGRectElement.h"
#include "core/svg/SVGSVGElement.h"
#include "core/svg/SVGScriptElement.h"
#include "core/svg/SVGSetElement.h"
#include "core/svg/SVGStopElement.h"
#include "core/svg/SVGStyleElement.h"
#include "core/svg/SVGSwitchElement.h"
#include "core/svg/SVGSymbolElement.h"
#include "core/svg/SVGTSpanElement.h"
#include "core/svg/SVGTextElement.h"
#include "core/svg/SVGTextPathElement.h"
#include "core/svg/SVGTitleElement.h"
#include "core/svg/SVGUnknownElement.h"
#include "core/svg/SVGUseElement.h"
#include "core/svg/SVGViewElement.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "wtf/HashMap.h"

namespace blink {

using namespace SVGNames;

typedef SVGElement* (*ConstructorFunction)(
    Document&,
    CreateElementFlags);

typedef HashMap<AtomicString, ConstructorFunction> FunctionMap;

static FunctionMap* g_constructors = 0;

static SVGElement* aConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGAElement::create(document);
}
static SVGElement* animateConstructor(
    Document& document,
    CreateElementFlags flags)
{
    if (!RuntimeEnabledFeatures::smilEnabled())
        return SVGUnknownElement::create(animateTag, document);
    return SVGAnimateElement::create(document);
}
static SVGElement* animateMotionConstructor(
    Document& document,
    CreateElementFlags flags)
{
    if (!RuntimeEnabledFeatures::smilEnabled())
        return SVGUnknownElement::create(animateMotionTag, document);
    return SVGAnimateMotionElement::create(document);
}
static SVGElement* animateTransformConstructor(
    Document& document,
    CreateElementFlags flags)
{
    if (!RuntimeEnabledFeatures::smilEnabled())
        return SVGUnknownElement::create(animateTransformTag, document);
    return SVGAnimateTransformElement::create(document);
}
static SVGElement* circleConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGCircleElement::create(document);
}
static SVGElement* clipPathConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGClipPathElement::create(document);
}
static SVGElement* defsConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGDefsElement::create(document);
}
static SVGElement* descConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGDescElement::create(document);
}
static SVGElement* discardConstructor(
    Document& document,
    CreateElementFlags flags)
{
    if (!RuntimeEnabledFeatures::smilEnabled())
        return SVGUnknownElement::create(discardTag, document);
    return SVGDiscardElement::create(document);
}
static SVGElement* ellipseConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGEllipseElement::create(document);
}
static SVGElement* feBlendConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEBlendElement::create(document);
}
static SVGElement* feColorMatrixConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEColorMatrixElement::create(document);
}
static SVGElement* feComponentTransferConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEComponentTransferElement::create(document);
}
static SVGElement* feCompositeConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFECompositeElement::create(document);
}
static SVGElement* feConvolveMatrixConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEConvolveMatrixElement::create(document);
}
static SVGElement* feDiffuseLightingConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEDiffuseLightingElement::create(document);
}
static SVGElement* feDisplacementMapConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEDisplacementMapElement::create(document);
}
static SVGElement* feDistantLightConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEDistantLightElement::create(document);
}
static SVGElement* feDropShadowConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEDropShadowElement::create(document);
}
static SVGElement* feFloodConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEFloodElement::create(document);
}
static SVGElement* feFuncAConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEFuncAElement::create(document);
}
static SVGElement* feFuncBConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEFuncBElement::create(document);
}
static SVGElement* feFuncGConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEFuncGElement::create(document);
}
static SVGElement* feFuncRConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEFuncRElement::create(document);
}
static SVGElement* feGaussianBlurConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEGaussianBlurElement::create(document);
}
static SVGElement* feImageConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEImageElement::create(document);
}
static SVGElement* feMergeConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEMergeElement::create(document);
}
static SVGElement* feMergeNodeConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEMergeNodeElement::create(document);
}
static SVGElement* feMorphologyConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEMorphologyElement::create(document);
}
static SVGElement* feOffsetConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEOffsetElement::create(document);
}
static SVGElement* fePointLightConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFEPointLightElement::create(document);
}
static SVGElement* feSpecularLightingConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFESpecularLightingElement::create(document);
}
static SVGElement* feSpotLightConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFESpotLightElement::create(document);
}
static SVGElement* feTileConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFETileElement::create(document);
}
static SVGElement* feTurbulenceConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFETurbulenceElement::create(document);
}
static SVGElement* filterConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGFilterElement::create(document);
}
static SVGElement* foreignObjectConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGForeignObjectElement::create(document);
}
static SVGElement* gConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGGElement::create(document);
}
static SVGElement* imageConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGImageElement::create(document);
}
static SVGElement* lineConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGLineElement::create(document);
}
static SVGElement* linearGradientConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGLinearGradientElement::create(document);
}
static SVGElement* mpathConstructor(
    Document& document,
    CreateElementFlags flags)
{
    if (!RuntimeEnabledFeatures::smilEnabled())
        return SVGUnknownElement::create(mpathTag, document);
    return SVGMPathElement::create(document);
}
static SVGElement* markerConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGMarkerElement::create(document);
}
static SVGElement* maskConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGMaskElement::create(document);
}
static SVGElement* metadataConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGMetadataElement::create(document);
}
static SVGElement* pathConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGPathElement::create(document);
}
static SVGElement* patternConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGPatternElement::create(document);
}
static SVGElement* polygonConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGPolygonElement::create(document);
}
static SVGElement* polylineConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGPolylineElement::create(document);
}
static SVGElement* radialGradientConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGRadialGradientElement::create(document);
}
static SVGElement* rectConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGRectElement::create(document);
}
static SVGElement* svgConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGSVGElement::create(document);
}
static SVGElement* setConstructor(
    Document& document,
    CreateElementFlags flags)
{
    if (!RuntimeEnabledFeatures::smilEnabled())
        return SVGUnknownElement::create(setTag, document);
    return SVGSetElement::create(document);
}
static SVGElement* stopConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGStopElement::create(document);
}
static SVGElement* switchConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGSwitchElement::create(document);
}
static SVGElement* symbolConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGSymbolElement::create(document);
}
static SVGElement* tspanConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGTSpanElement::create(document);
}
static SVGElement* textConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGTextElement::create(document);
}
static SVGElement* textPathConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGTextPathElement::create(document);
}
static SVGElement* titleConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGTitleElement::create(document);
}
static SVGElement* useConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGUseElement::create(document);
}
static SVGElement* viewConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGViewElement::create(document);
}
static SVGElement* scriptConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGScriptElement::create(document, flags & CreatedByParser);
}
static SVGElement* styleConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return SVGStyleElement::create(document, flags & CreatedByParser);
}

struct CreateSVGFunctionMapData {
    const QualifiedName& tag;
    ConstructorFunction func;
};

static void createSVGFunctionMap()
{
    ASSERT(!g_constructors);
    g_constructors = new FunctionMap;
    // Empty array initializer lists are illegal [dcl.init.aggr] and will not
    // compile in MSVC. If tags list is empty, add check to skip this.
    static const CreateSVGFunctionMapData data[] = {
        { aTag, aConstructor },
        { animateTag, animateConstructor },
        { animateMotionTag, animateMotionConstructor },
        { animateTransformTag, animateTransformConstructor },
        { circleTag, circleConstructor },
        { clipPathTag, clipPathConstructor },
        { defsTag, defsConstructor },
        { descTag, descConstructor },
        { discardTag, discardConstructor },
        { ellipseTag, ellipseConstructor },
        { feBlendTag, feBlendConstructor },
        { feColorMatrixTag, feColorMatrixConstructor },
        { feComponentTransferTag, feComponentTransferConstructor },
        { feCompositeTag, feCompositeConstructor },
        { feConvolveMatrixTag, feConvolveMatrixConstructor },
        { feDiffuseLightingTag, feDiffuseLightingConstructor },
        { feDisplacementMapTag, feDisplacementMapConstructor },
        { feDistantLightTag, feDistantLightConstructor },
        { feDropShadowTag, feDropShadowConstructor },
        { feFloodTag, feFloodConstructor },
        { feFuncATag, feFuncAConstructor },
        { feFuncBTag, feFuncBConstructor },
        { feFuncGTag, feFuncGConstructor },
        { feFuncRTag, feFuncRConstructor },
        { feGaussianBlurTag, feGaussianBlurConstructor },
        { feImageTag, feImageConstructor },
        { feMergeTag, feMergeConstructor },
        { feMergeNodeTag, feMergeNodeConstructor },
        { feMorphologyTag, feMorphologyConstructor },
        { feOffsetTag, feOffsetConstructor },
        { fePointLightTag, fePointLightConstructor },
        { feSpecularLightingTag, feSpecularLightingConstructor },
        { feSpotLightTag, feSpotLightConstructor },
        { feTileTag, feTileConstructor },
        { feTurbulenceTag, feTurbulenceConstructor },
        { filterTag, filterConstructor },
        { foreignObjectTag, foreignObjectConstructor },
        { gTag, gConstructor },
        { imageTag, imageConstructor },
        { lineTag, lineConstructor },
        { linearGradientTag, linearGradientConstructor },
        { mpathTag, mpathConstructor },
        { markerTag, markerConstructor },
        { maskTag, maskConstructor },
        { metadataTag, metadataConstructor },
        { pathTag, pathConstructor },
        { patternTag, patternConstructor },
        { polygonTag, polygonConstructor },
        { polylineTag, polylineConstructor },
        { radialGradientTag, radialGradientConstructor },
        { rectTag, rectConstructor },
        { svgTag, svgConstructor },
        { setTag, setConstructor },
        { stopTag, stopConstructor },
        { switchTag, switchConstructor },
        { symbolTag, symbolConstructor },
        { tspanTag, tspanConstructor },
        { textTag, textConstructor },
        { textPathTag, textPathConstructor },
        { titleTag, titleConstructor },
        { useTag, useConstructor },
        { viewTag, viewConstructor },
        { scriptTag, scriptConstructor },
        { styleTag, styleConstructor },
    };
    for (size_t i = 0; i < WTF_ARRAY_LENGTH(data); i++)
        g_constructors->set(data[i].tag.localName(), data[i].func);
}

SVGElement* SVGElementFactory::createSVGElement(
    const AtomicString& localName,
    Document& document,
    CreateElementFlags flags)
{
    if (!g_constructors)
        createSVGFunctionMap();
    if (ConstructorFunction function = g_constructors->get(localName))
        return function(document, flags);

    if (document.registrationContext() && V0CustomElement::isValidName(localName)) {
        Element* element = document.registrationContext()->createCustomTagElement(
            document, QualifiedName(nullAtom, localName, svgNamespaceURI));
        SECURITY_DCHECK(element->isSVGElement());
        return toSVGElement(element);
    }

    return SVGUnknownElement::create(QualifiedName(nullAtom, localName, svgNamespaceURI), document);
}

} // namespace blink
