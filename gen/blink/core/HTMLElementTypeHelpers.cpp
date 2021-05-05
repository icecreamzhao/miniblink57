// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "HTMLElementTypeHelpers.h"

#include "core/dom/Document.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "wtf/HashMap.h"

namespace blink {
using HTMLTypeMap = HashMap<AtomicString, HTMLElementType>;

static HTMLTypeMap* html_type_map = 0;

void createHTMLTypeMap()
{
    DCHECK(!html_type_map);
    html_type_map = new HTMLTypeMap;
    html_type_map->set(AtomicString("a"), HTMLElementType::kHTMLAnchorElement);
    html_type_map->set(AtomicString("area"), HTMLElementType::kHTMLAreaElement);
    html_type_map->set(AtomicString("audio"), HTMLElementType::kHTMLAudioElement);
    html_type_map->set(AtomicString("br"), HTMLElementType::kHTMLBRElement);
    html_type_map->set(AtomicString("base"), HTMLElementType::kHTMLBaseElement);
    html_type_map->set(AtomicString("body"), HTMLElementType::kHTMLBodyElement);
    html_type_map->set(AtomicString("button"), HTMLElementType::kHTMLButtonElement);
    html_type_map->set(AtomicString("canvas"), HTMLElementType::kHTMLCanvasElement);
    html_type_map->set(AtomicString("content"), HTMLElementType::kHTMLContentElement);
    html_type_map->set(AtomicString("dl"), HTMLElementType::kHTMLDListElement);
    html_type_map->set(AtomicString("datalist"), HTMLElementType::kHTMLDataListElement);
    html_type_map->set(AtomicString("details"), HTMLElementType::kHTMLDetailsElement);
    html_type_map->set(AtomicString("dialog"), HTMLElementType::kHTMLDialogElement);
    html_type_map->set(AtomicString("dir"), HTMLElementType::kHTMLDirectoryElement);
    html_type_map->set(AtomicString("div"), HTMLElementType::kHTMLDivElement);
    html_type_map->set(AtomicString("abbr"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("acronym"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("address"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("article"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("aside"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("b"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("basefont"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("bdo"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("big"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("center"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("cite"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("code"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("dd"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("dfn"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("dt"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("em"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("figcaption"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("figure"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("footer"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("header"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("hgroup"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("i"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("kbd"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("layer"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("main"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("mark"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("nav"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("nobr"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("noframes"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("nolayer"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("plaintext"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("rb"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("rp"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("rtc"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("s"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("samp"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("section"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("small"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("strike"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("strong"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("sub"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("sup"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("tt"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("u"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("var"), HTMLElementType::kHTMLElement);
    html_type_map->set(AtomicString("fieldset"), HTMLElementType::kHTMLFieldSetElement);
    html_type_map->set(AtomicString("font"), HTMLElementType::kHTMLFontElement);
    html_type_map->set(AtomicString("form"), HTMLElementType::kHTMLFormElement);
    html_type_map->set(AtomicString("frame"), HTMLElementType::kHTMLFrameElement);
    html_type_map->set(AtomicString("frameset"), HTMLElementType::kHTMLFrameSetElement);
    html_type_map->set(AtomicString("hr"), HTMLElementType::kHTMLHRElement);
    html_type_map->set(AtomicString("head"), HTMLElementType::kHTMLHeadElement);
    html_type_map->set(AtomicString("h1"), HTMLElementType::kHTMLHeadingElement);
    html_type_map->set(AtomicString("h2"), HTMLElementType::kHTMLHeadingElement);
    html_type_map->set(AtomicString("h3"), HTMLElementType::kHTMLHeadingElement);
    html_type_map->set(AtomicString("h4"), HTMLElementType::kHTMLHeadingElement);
    html_type_map->set(AtomicString("h5"), HTMLElementType::kHTMLHeadingElement);
    html_type_map->set(AtomicString("h6"), HTMLElementType::kHTMLHeadingElement);
    html_type_map->set(AtomicString("html"), HTMLElementType::kHTMLHtmlElement);
    html_type_map->set(AtomicString("iframe"), HTMLElementType::kHTMLIFrameElement);
    html_type_map->set(AtomicString("li"), HTMLElementType::kHTMLLIElement);
    html_type_map->set(AtomicString("label"), HTMLElementType::kHTMLLabelElement);
    html_type_map->set(AtomicString("legend"), HTMLElementType::kHTMLLegendElement);
    html_type_map->set(AtomicString("map"), HTMLElementType::kHTMLMapElement);
    html_type_map->set(AtomicString("marquee"), HTMLElementType::kHTMLMarqueeElement);
    html_type_map->set(AtomicString("menu"), HTMLElementType::kHTMLMenuElement);
    html_type_map->set(AtomicString("menuitem"), HTMLElementType::kHTMLMenuItemElement);
    html_type_map->set(AtomicString("meta"), HTMLElementType::kHTMLMetaElement);
    html_type_map->set(AtomicString("meter"), HTMLElementType::kHTMLMeterElement);
    html_type_map->set(AtomicString("del"), HTMLElementType::kHTMLModElement);
    html_type_map->set(AtomicString("ins"), HTMLElementType::kHTMLModElement);
    html_type_map->set(AtomicString("ol"), HTMLElementType::kHTMLOListElement);
    html_type_map->set(AtomicString("optgroup"), HTMLElementType::kHTMLOptGroupElement);
    html_type_map->set(AtomicString("option"), HTMLElementType::kHTMLOptionElement);
    html_type_map->set(AtomicString("output"), HTMLElementType::kHTMLOutputElement);
    html_type_map->set(AtomicString("p"), HTMLElementType::kHTMLParagraphElement);
    html_type_map->set(AtomicString("param"), HTMLElementType::kHTMLParamElement);
    html_type_map->set(AtomicString("picture"), HTMLElementType::kHTMLPictureElement);
    html_type_map->set(AtomicString("pre"), HTMLElementType::kHTMLPreElement);
    html_type_map->set(AtomicString("listing"), HTMLElementType::kHTMLPreElement);
    html_type_map->set(AtomicString("xmp"), HTMLElementType::kHTMLPreElement);
    html_type_map->set(AtomicString("progress"), HTMLElementType::kHTMLProgressElement);
    html_type_map->set(AtomicString("blockquote"), HTMLElementType::kHTMLQuoteElement);
    html_type_map->set(AtomicString("q"), HTMLElementType::kHTMLQuoteElement);
    html_type_map->set(AtomicString("select"), HTMLElementType::kHTMLSelectElement);
    html_type_map->set(AtomicString("shadow"), HTMLElementType::kHTMLShadowElement);
    html_type_map->set(AtomicString("slot"), HTMLElementType::kHTMLSlotElement);
    html_type_map->set(AtomicString("source"), HTMLElementType::kHTMLSourceElement);
    html_type_map->set(AtomicString("span"), HTMLElementType::kHTMLSpanElement);
    html_type_map->set(AtomicString("caption"), HTMLElementType::kHTMLTableCaptionElement);
    html_type_map->set(AtomicString("td"), HTMLElementType::kHTMLTableCellElement);
    html_type_map->set(AtomicString("th"), HTMLElementType::kHTMLTableCellElement);
    html_type_map->set(AtomicString("col"), HTMLElementType::kHTMLTableColElement);
    html_type_map->set(AtomicString("colgroup"), HTMLElementType::kHTMLTableColElement);
    html_type_map->set(AtomicString("table"), HTMLElementType::kHTMLTableElement);
    html_type_map->set(AtomicString("tr"), HTMLElementType::kHTMLTableRowElement);
    html_type_map->set(AtomicString("tbody"), HTMLElementType::kHTMLTableSectionElement);
    html_type_map->set(AtomicString("tfoot"), HTMLElementType::kHTMLTableSectionElement);
    html_type_map->set(AtomicString("thead"), HTMLElementType::kHTMLTableSectionElement);
    html_type_map->set(AtomicString("template"), HTMLElementType::kHTMLTemplateElement);
    html_type_map->set(AtomicString("textarea"), HTMLElementType::kHTMLTextAreaElement);
    html_type_map->set(AtomicString("title"), HTMLElementType::kHTMLTitleElement);
    html_type_map->set(AtomicString("track"), HTMLElementType::kHTMLTrackElement);
    html_type_map->set(AtomicString("ul"), HTMLElementType::kHTMLUListElement);
    html_type_map->set(AtomicString("applet"), HTMLElementType::kHTMLUnknownElement);
    html_type_map->set(AtomicString("bgsound"), HTMLElementType::kHTMLUnknownElement);
    html_type_map->set(AtomicString("command"), HTMLElementType::kHTMLUnknownElement);
    html_type_map->set(AtomicString("image"), HTMLElementType::kHTMLUnknownElement);
    html_type_map->set(AtomicString("keygen"), HTMLElementType::kHTMLUnknownElement);
    html_type_map->set(AtomicString("video"), HTMLElementType::kHTMLVideoElement);
    html_type_map->set(AtomicString("embed"), HTMLElementType::kHTMLEmbedElement);
    html_type_map->set(AtomicString("img"), HTMLElementType::kHTMLImageElement);
    html_type_map->set(AtomicString("input"), HTMLElementType::kHTMLInputElement);
    html_type_map->set(AtomicString("link"), HTMLElementType::kHTMLLinkElement);
    html_type_map->set(AtomicString("object"), HTMLElementType::kHTMLObjectElement);
    html_type_map->set(AtomicString("script"), HTMLElementType::kHTMLScriptElement);
    html_type_map->set(AtomicString("style"), HTMLElementType::kHTMLStyleElement);
    html_type_map->set(AtomicString("bdi"), HTMLElementType::kHTMLBDIElement);
    html_type_map->set(AtomicString("noembed"), HTMLElementType::kHTMLNoEmbedElement);
    html_type_map->set(AtomicString("noscript"), HTMLElementType::kHTMLNoScriptElement);
    html_type_map->set(AtomicString("rt"), HTMLElementType::kHTMLRTElement);
    html_type_map->set(AtomicString("ruby"), HTMLElementType::kHTMLRubyElement);
    html_type_map->set(AtomicString("summary"), HTMLElementType::kHTMLSummaryElement);
    html_type_map->set(AtomicString("wbr"), HTMLElementType::kHTMLWBRElement);
}

HTMLElementType htmlElementTypeForTag(const AtomicString& tagName)
{
    if (!html_type_map)
        createHTMLTypeMap();
    if (html_type_map->contains(tagName)) {
        if (tagName == "menuitem") {
            if (!RuntimeEnabledFeatures::contextMenuEnabled()) {
                return HTMLElementType::kHTMLUnknownElement;
            }
        }
        return html_type_map->get(tagName);
    } else {
        return HTMLElementType::kHTMLUnknownElement;
    }
}
} // namespace blink
