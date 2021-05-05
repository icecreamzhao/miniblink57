// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "HTMLElementFactory.h"

#include "HTMLNames.h"
#include "core/dom/Document.h"
#include "core/dom/custom/CustomElement.h"
#include "core/dom/custom/V0CustomElement.h"
#include "core/dom/custom/V0CustomElementRegistrationContext.h"
#include "core/frame/Settings.h"
#include "core/html/HTMLAnchorElement.h"
#include "core/html/HTMLAreaElement.h"
#include "core/html/HTMLAudioElement.h"
#include "core/html/HTMLBDIElement.h"
#include "core/html/HTMLBRElement.h"
#include "core/html/HTMLBaseElement.h"
#include "core/html/HTMLBodyElement.h"
#include "core/html/HTMLButtonElement.h"
#include "core/html/HTMLCanvasElement.h"
#include "core/html/HTMLContentElement.h"
#include "core/html/HTMLDListElement.h"
#include "core/html/HTMLDataListElement.h"
#include "core/html/HTMLDetailsElement.h"
#include "core/html/HTMLDialogElement.h"
#include "core/html/HTMLDirectoryElement.h"
#include "core/html/HTMLDivElement.h"
#include "core/html/HTMLElement.h"
#include "core/html/HTMLEmbedElement.h"
#include "core/html/HTMLFieldSetElement.h"
#include "core/html/HTMLFontElement.h"
#include "core/html/HTMLFormElement.h"
#include "core/html/HTMLFrameElement.h"
#include "core/html/HTMLFrameSetElement.h"
#include "core/html/HTMLHRElement.h"
#include "core/html/HTMLHeadElement.h"
#include "core/html/HTMLHeadingElement.h"
#include "core/html/HTMLHtmlElement.h"
#include "core/html/HTMLIFrameElement.h"
#include "core/html/HTMLImageElement.h"
#include "core/html/HTMLInputElement.h"
#include "core/html/HTMLLIElement.h"
#include "core/html/HTMLLabelElement.h"
#include "core/html/HTMLLegendElement.h"
#include "core/html/HTMLLinkElement.h"
#include "core/html/HTMLMapElement.h"
#include "core/html/HTMLMarqueeElement.h"
#include "core/html/HTMLMenuElement.h"
#include "core/html/HTMLMenuItemElement.h"
#include "core/html/HTMLMetaElement.h"
#include "core/html/HTMLMeterElement.h"
#include "core/html/HTMLModElement.h"
#include "core/html/HTMLNoEmbedElement.h"
#include "core/html/HTMLNoScriptElement.h"
#include "core/html/HTMLOListElement.h"
#include "core/html/HTMLObjectElement.h"
#include "core/html/HTMLOptGroupElement.h"
#include "core/html/HTMLOptionElement.h"
#include "core/html/HTMLOutputElement.h"
#include "core/html/HTMLParagraphElement.h"
#include "core/html/HTMLParamElement.h"
#include "core/html/HTMLPictureElement.h"
#include "core/html/HTMLPreElement.h"
#include "core/html/HTMLProgressElement.h"
#include "core/html/HTMLQuoteElement.h"
#include "core/html/HTMLRTElement.h"
#include "core/html/HTMLRubyElement.h"
#include "core/html/HTMLScriptElement.h"
#include "core/html/HTMLSelectElement.h"
#include "core/html/HTMLShadowElement.h"
#include "core/html/HTMLSlotElement.h"
#include "core/html/HTMLSourceElement.h"
#include "core/html/HTMLSpanElement.h"
#include "core/html/HTMLStyleElement.h"
#include "core/html/HTMLSummaryElement.h"
#include "core/html/HTMLTableCaptionElement.h"
#include "core/html/HTMLTableCellElement.h"
#include "core/html/HTMLTableColElement.h"
#include "core/html/HTMLTableElement.h"
#include "core/html/HTMLTableRowElement.h"
#include "core/html/HTMLTableSectionElement.h"
#include "core/html/HTMLTemplateElement.h"
#include "core/html/HTMLTextAreaElement.h"
#include "core/html/HTMLTitleElement.h"
#include "core/html/HTMLTrackElement.h"
#include "core/html/HTMLUListElement.h"
#include "core/html/HTMLUnknownElement.h"
#include "core/html/HTMLVideoElement.h"
#include "core/html/HTMLWBRElement.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "wtf/HashMap.h"

namespace blink {

using namespace HTMLNames;

typedef HTMLElement* (*ConstructorFunction)(
    Document&,
    CreateElementFlags);

typedef HashMap<AtomicString, ConstructorFunction> FunctionMap;

static FunctionMap* g_constructors = 0;

static HTMLElement* abbrConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(abbrTag, document);
}
static HTMLElement* acronymConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(acronymTag, document);
}
static HTMLElement* addressConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(addressTag, document);
}
static HTMLElement* articleConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(articleTag, document);
}
static HTMLElement* asideConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(asideTag, document);
}
static HTMLElement* bConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(bTag, document);
}
static HTMLElement* basefontConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(basefontTag, document);
}
static HTMLElement* bdoConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(bdoTag, document);
}
static HTMLElement* bigConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(bigTag, document);
}
static HTMLElement* centerConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(centerTag, document);
}
static HTMLElement* citeConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(citeTag, document);
}
static HTMLElement* codeConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(codeTag, document);
}
static HTMLElement* ddConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(ddTag, document);
}
static HTMLElement* dfnConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(dfnTag, document);
}
static HTMLElement* dtConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(dtTag, document);
}
static HTMLElement* emConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(emTag, document);
}
static HTMLElement* figcaptionConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(figcaptionTag, document);
}
static HTMLElement* figureConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(figureTag, document);
}
static HTMLElement* footerConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(footerTag, document);
}
static HTMLElement* headerConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(headerTag, document);
}
static HTMLElement* hgroupConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(hgroupTag, document);
}
static HTMLElement* iConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(iTag, document);
}
static HTMLElement* kbdConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(kbdTag, document);
}
static HTMLElement* layerConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(layerTag, document);
}
static HTMLElement* mainConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(mainTag, document);
}
static HTMLElement* markConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(markTag, document);
}
static HTMLElement* navConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(navTag, document);
}
static HTMLElement* nobrConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(nobrTag, document);
}
static HTMLElement* noframesConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(noframesTag, document);
}
static HTMLElement* nolayerConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(nolayerTag, document);
}
static HTMLElement* plaintextConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(plaintextTag, document);
}
static HTMLElement* rbConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(rbTag, document);
}
static HTMLElement* rpConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(rpTag, document);
}
static HTMLElement* rtcConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(rtcTag, document);
}
static HTMLElement* sConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(sTag, document);
}
static HTMLElement* sampConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(sampTag, document);
}
static HTMLElement* sectionConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(sectionTag, document);
}
static HTMLElement* smallConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(smallTag, document);
}
static HTMLElement* strikeConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(strikeTag, document);
}
static HTMLElement* strongConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(strongTag, document);
}
static HTMLElement* subConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(subTag, document);
}
static HTMLElement* supConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(supTag, document);
}
static HTMLElement* ttConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(ttTag, document);
}
static HTMLElement* uConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(uTag, document);
}
static HTMLElement* varConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLElement::create(varTag, document);
}
static HTMLElement* aConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLAnchorElement::create(document);
}
static HTMLElement* areaConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLAreaElement::create(document);
}
static HTMLElement* audioConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLAudioElement::create(document);
}
static HTMLElement* brConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLBRElement::create(document);
}
static HTMLElement* baseConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLBaseElement::create(document);
}
static HTMLElement* bodyConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLBodyElement::create(document);
}
static HTMLElement* buttonConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLButtonElement::create(document);
}
static HTMLElement* canvasConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLCanvasElement::create(document);
}
static HTMLElement* contentConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLContentElement::create(document);
}
static HTMLElement* dlConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLDListElement::create(document);
}
static HTMLElement* datalistConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLDataListElement::create(document);
}
static HTMLElement* detailsConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLDetailsElement::create(document);
}
static HTMLElement* dialogConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLDialogElement::create(document);
}
static HTMLElement* dirConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLDirectoryElement::create(document);
}
static HTMLElement* divConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLDivElement::create(document);
}
static HTMLElement* fieldsetConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLFieldSetElement::create(document);
}
static HTMLElement* fontConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLFontElement::create(document);
}
static HTMLElement* formConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLFormElement::create(document);
}
static HTMLElement* frameConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLFrameElement::create(document);
}
static HTMLElement* framesetConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLFrameSetElement::create(document);
}
static HTMLElement* hrConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLHRElement::create(document);
}
static HTMLElement* headConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLHeadElement::create(document);
}
static HTMLElement* h1Constructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLHeadingElement::create(h1Tag, document);
}
static HTMLElement* h2Constructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLHeadingElement::create(h2Tag, document);
}
static HTMLElement* h3Constructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLHeadingElement::create(h3Tag, document);
}
static HTMLElement* h4Constructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLHeadingElement::create(h4Tag, document);
}
static HTMLElement* h5Constructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLHeadingElement::create(h5Tag, document);
}
static HTMLElement* h6Constructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLHeadingElement::create(h6Tag, document);
}
static HTMLElement* htmlConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLHtmlElement::create(document);
}
static HTMLElement* iframeConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLIFrameElement::create(document);
}
static HTMLElement* liConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLLIElement::create(document);
}
static HTMLElement* labelConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLLabelElement::create(document);
}
static HTMLElement* legendConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLLegendElement::create(document);
}
static HTMLElement* mapConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLMapElement::create(document);
}
static HTMLElement* marqueeConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLMarqueeElement::create(document);
}
static HTMLElement* menuConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLMenuElement::create(document);
}
static HTMLElement* menuitemConstructor(
    Document& document,
    CreateElementFlags flags)
{
    if (!RuntimeEnabledFeatures::contextMenuEnabled())
        return HTMLUnknownElement::create(menuitemTag, document);
    return HTMLMenuItemElement::create(document);
}
static HTMLElement* metaConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLMetaElement::create(document);
}
static HTMLElement* meterConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLMeterElement::create(document);
}
static HTMLElement* delConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLModElement::create(delTag, document);
}
static HTMLElement* insConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLModElement::create(insTag, document);
}
static HTMLElement* olConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLOListElement::create(document);
}
static HTMLElement* optgroupConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLOptGroupElement::create(document);
}
static HTMLElement* optionConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLOptionElement::create(document);
}
static HTMLElement* outputConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLOutputElement::create(document);
}
static HTMLElement* pConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLParagraphElement::create(document);
}
static HTMLElement* paramConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLParamElement::create(document);
}
static HTMLElement* pictureConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLPictureElement::create(document);
}
static HTMLElement* preConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLPreElement::create(preTag, document);
}
static HTMLElement* listingConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLPreElement::create(listingTag, document);
}
static HTMLElement* xmpConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLPreElement::create(xmpTag, document);
}
static HTMLElement* progressConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLProgressElement::create(document);
}
static HTMLElement* blockquoteConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLQuoteElement::create(blockquoteTag, document);
}
static HTMLElement* qConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLQuoteElement::create(qTag, document);
}
static HTMLElement* selectConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLSelectElement::create(document);
}
static HTMLElement* shadowConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLShadowElement::create(document);
}
static HTMLElement* slotConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLSlotElement::create(document);
}
static HTMLElement* sourceConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLSourceElement::create(document);
}
static HTMLElement* spanConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLSpanElement::create(document);
}
static HTMLElement* captionConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTableCaptionElement::create(document);
}
static HTMLElement* tdConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTableCellElement::create(tdTag, document);
}
static HTMLElement* thConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTableCellElement::create(thTag, document);
}
static HTMLElement* colConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTableColElement::create(colTag, document);
}
static HTMLElement* colgroupConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTableColElement::create(colgroupTag, document);
}
static HTMLElement* tableConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTableElement::create(document);
}
static HTMLElement* trConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTableRowElement::create(document);
}
static HTMLElement* tbodyConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTableSectionElement::create(tbodyTag, document);
}
static HTMLElement* tfootConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTableSectionElement::create(tfootTag, document);
}
static HTMLElement* theadConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTableSectionElement::create(theadTag, document);
}
static HTMLElement* templateConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTemplateElement::create(document);
}
static HTMLElement* textareaConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTextAreaElement::create(document);
}
static HTMLElement* titleConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTitleElement::create(document);
}
static HTMLElement* trackConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLTrackElement::create(document);
}
static HTMLElement* ulConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLUListElement::create(document);
}
static HTMLElement* appletConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLUnknownElement::create(appletTag, document);
}
static HTMLElement* bgsoundConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLUnknownElement::create(bgsoundTag, document);
}
static HTMLElement* commandConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLUnknownElement::create(commandTag, document);
}
static HTMLElement* imageConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLUnknownElement::create(imageTag, document);
}
static HTMLElement* keygenConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLUnknownElement::create(keygenTag, document);
}
static HTMLElement* videoConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLVideoElement::create(document);
}
static HTMLElement* embedConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLEmbedElement::create(document, flags & CreatedByParser);
}
static HTMLElement* imgConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLImageElement::create(document, flags & CreatedByParser);
}
static HTMLElement* inputConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLInputElement::create(document, flags & CreatedByParser);
}
static HTMLElement* linkConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLLinkElement::create(document, flags & CreatedByParser);
}
static HTMLElement* objectConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLObjectElement::create(document, flags & CreatedByParser);
}
static HTMLElement* scriptConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLScriptElement::create(document, flags & CreatedByParser);
}
static HTMLElement* styleConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLStyleElement::create(document, flags & CreatedByParser);
}
static HTMLElement* bdiConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLBDIElement::create(document);
}
static HTMLElement* noembedConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLNoEmbedElement::create(document);
}
static HTMLElement* noscriptConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLNoScriptElement::create(document);
}
static HTMLElement* rtConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLRTElement::create(document);
}
static HTMLElement* rubyConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLRubyElement::create(document);
}
static HTMLElement* summaryConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLSummaryElement::create(document);
}
static HTMLElement* wbrConstructor(
    Document& document,
    CreateElementFlags flags)
{
    return HTMLWBRElement::create(document);
}

struct CreateHTMLFunctionMapData {
    const QualifiedName& tag;
    ConstructorFunction func;
};

static void createHTMLFunctionMap()
{
    ASSERT(!g_constructors);
    g_constructors = new FunctionMap;
    // Empty array initializer lists are illegal [dcl.init.aggr] and will not
    // compile in MSVC. If tags list is empty, add check to skip this.
    static const CreateHTMLFunctionMapData data[] = {
        { abbrTag, abbrConstructor },
        { acronymTag, acronymConstructor },
        { addressTag, addressConstructor },
        { articleTag, articleConstructor },
        { asideTag, asideConstructor },
        { bTag, bConstructor },
        { basefontTag, basefontConstructor },
        { bdoTag, bdoConstructor },
        { bigTag, bigConstructor },
        { centerTag, centerConstructor },
        { citeTag, citeConstructor },
        { codeTag, codeConstructor },
        { ddTag, ddConstructor },
        { dfnTag, dfnConstructor },
        { dtTag, dtConstructor },
        { emTag, emConstructor },
        { figcaptionTag, figcaptionConstructor },
        { figureTag, figureConstructor },
        { footerTag, footerConstructor },
        { headerTag, headerConstructor },
        { hgroupTag, hgroupConstructor },
        { iTag, iConstructor },
        { kbdTag, kbdConstructor },
        { layerTag, layerConstructor },
        { mainTag, mainConstructor },
        { markTag, markConstructor },
        { navTag, navConstructor },
        { nobrTag, nobrConstructor },
        { noframesTag, noframesConstructor },
        { nolayerTag, nolayerConstructor },
        { plaintextTag, plaintextConstructor },
        { rbTag, rbConstructor },
        { rpTag, rpConstructor },
        { rtcTag, rtcConstructor },
        { sTag, sConstructor },
        { sampTag, sampConstructor },
        { sectionTag, sectionConstructor },
        { smallTag, smallConstructor },
        { strikeTag, strikeConstructor },
        { strongTag, strongConstructor },
        { subTag, subConstructor },
        { supTag, supConstructor },
        { ttTag, ttConstructor },
        { uTag, uConstructor },
        { varTag, varConstructor },
        { aTag, aConstructor },
        { areaTag, areaConstructor },
        { audioTag, audioConstructor },
        { brTag, brConstructor },
        { baseTag, baseConstructor },
        { bodyTag, bodyConstructor },
        { buttonTag, buttonConstructor },
        { canvasTag, canvasConstructor },
        { contentTag, contentConstructor },
        { dlTag, dlConstructor },
        { datalistTag, datalistConstructor },
        { detailsTag, detailsConstructor },
        { dialogTag, dialogConstructor },
        { dirTag, dirConstructor },
        { divTag, divConstructor },
        { fieldsetTag, fieldsetConstructor },
        { fontTag, fontConstructor },
        { formTag, formConstructor },
        { frameTag, frameConstructor },
        { framesetTag, framesetConstructor },
        { hrTag, hrConstructor },
        { headTag, headConstructor },
        { h1Tag, h1Constructor },
        { h2Tag, h2Constructor },
        { h3Tag, h3Constructor },
        { h4Tag, h4Constructor },
        { h5Tag, h5Constructor },
        { h6Tag, h6Constructor },
        { htmlTag, htmlConstructor },
        { iframeTag, iframeConstructor },
        { liTag, liConstructor },
        { labelTag, labelConstructor },
        { legendTag, legendConstructor },
        { mapTag, mapConstructor },
        { marqueeTag, marqueeConstructor },
        { menuTag, menuConstructor },
        { menuitemTag, menuitemConstructor },
        { metaTag, metaConstructor },
        { meterTag, meterConstructor },
        { delTag, delConstructor },
        { insTag, insConstructor },
        { olTag, olConstructor },
        { optgroupTag, optgroupConstructor },
        { optionTag, optionConstructor },
        { outputTag, outputConstructor },
        { pTag, pConstructor },
        { paramTag, paramConstructor },
        { pictureTag, pictureConstructor },
        { preTag, preConstructor },
        { listingTag, listingConstructor },
        { xmpTag, xmpConstructor },
        { progressTag, progressConstructor },
        { blockquoteTag, blockquoteConstructor },
        { qTag, qConstructor },
        { selectTag, selectConstructor },
        { shadowTag, shadowConstructor },
        { slotTag, slotConstructor },
        { sourceTag, sourceConstructor },
        { spanTag, spanConstructor },
        { captionTag, captionConstructor },
        { tdTag, tdConstructor },
        { thTag, thConstructor },
        { colTag, colConstructor },
        { colgroupTag, colgroupConstructor },
        { tableTag, tableConstructor },
        { trTag, trConstructor },
        { tbodyTag, tbodyConstructor },
        { tfootTag, tfootConstructor },
        { theadTag, theadConstructor },
        { templateTag, templateConstructor },
        { textareaTag, textareaConstructor },
        { titleTag, titleConstructor },
        { trackTag, trackConstructor },
        { ulTag, ulConstructor },
        { appletTag, appletConstructor },
        { bgsoundTag, bgsoundConstructor },
        { commandTag, commandConstructor },
        { imageTag, imageConstructor },
        { keygenTag, keygenConstructor },
        { videoTag, videoConstructor },
        { embedTag, embedConstructor },
        { imgTag, imgConstructor },
        { inputTag, inputConstructor },
        { linkTag, linkConstructor },
        { objectTag, objectConstructor },
        { scriptTag, scriptConstructor },
        { styleTag, styleConstructor },
        { bdiTag, bdiConstructor },
        { noembedTag, noembedConstructor },
        { noscriptTag, noscriptConstructor },
        { rtTag, rtConstructor },
        { rubyTag, rubyConstructor },
        { summaryTag, summaryConstructor },
        { wbrTag, wbrConstructor },
    };
    for (size_t i = 0; i < WTF_ARRAY_LENGTH(data); i++)
        g_constructors->set(data[i].tag.localName(), data[i].func);
}

HTMLElement* HTMLElementFactory::createHTMLElement(
    const AtomicString& localName,
    Document& document,
    CreateElementFlags flags)
{
    if (!g_constructors)
        createHTMLFunctionMap();
    if (ConstructorFunction function = g_constructors->get(localName))
        return function(document, flags);

    // createElement handles custom element creation itself in order to
    // transmit exceptions.
    // TODO(dominicc): When the HTML parser can pass an error
    // reporting ExceptionState, and "v0" custom elements have been
    // removed, consolidate custom element creation into one place.
    if (flags != CreatedByCreateElement && CustomElement::shouldCreateCustomElement(localName)) {
        QualifiedName tagName(nullAtom, localName, HTMLNames::xhtmlNamespaceURI);
        if (flags & AsynchronousCustomElements)
            return CustomElement::createCustomElementAsync(document, tagName);
        return CustomElement::createCustomElementSync(document, tagName);
    }

    if (document.registrationContext() && V0CustomElement::isValidName(localName)) {
        Element* element = document.registrationContext()->createCustomTagElement(
            document, QualifiedName(nullAtom, localName, xhtmlNamespaceURI));
        SECURITY_DCHECK(element->isHTMLElement());
        return toHTMLElement(element);
    }

    return HTMLUnknownElement::create(QualifiedName(nullAtom, localName, xhtmlNamespaceURI), document);
}

} // namespace blink
