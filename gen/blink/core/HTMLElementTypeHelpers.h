// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HTMLElementTypeHelpers_h
#define HTMLElementTypeHelpers_h

#include "HTMLNames.h"
#include "core/html/HTMLElement.h"
#include "platform/RuntimeEnabledFeatures.h"

namespace blink {
// Type checking.
class HTMLAnchorElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLAnchorElement(const HTMLAnchorElement&);
void isHTMLAnchorElement(const HTMLAnchorElement*);

inline bool isHTMLAnchorElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::aTag);
}
inline bool isHTMLAnchorElement(const HTMLElement* element)
{
    return element && isHTMLAnchorElement(*element);
}
inline bool isHTMLAnchorElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLAnchorElement(toHTMLElement(node));
}
inline bool isHTMLAnchorElement(const Node* node)
{
    return node && isHTMLAnchorElement(*node);
}
template <>
inline bool isElementOfType<const HTMLAnchorElement>(const Node& node)
{
    return isHTMLAnchorElement(node);
}
template <>
inline bool isElementOfType<const HTMLAnchorElement>(const HTMLElement& element)
{
    return isHTMLAnchorElement(element);
}

class HTMLAreaElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLAreaElement(const HTMLAreaElement&);
void isHTMLAreaElement(const HTMLAreaElement*);

inline bool isHTMLAreaElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::areaTag);
}
inline bool isHTMLAreaElement(const HTMLElement* element)
{
    return element && isHTMLAreaElement(*element);
}
inline bool isHTMLAreaElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLAreaElement(toHTMLElement(node));
}
inline bool isHTMLAreaElement(const Node* node)
{
    return node && isHTMLAreaElement(*node);
}
template <>
inline bool isElementOfType<const HTMLAreaElement>(const Node& node)
{
    return isHTMLAreaElement(node);
}
template <>
inline bool isElementOfType<const HTMLAreaElement>(const HTMLElement& element)
{
    return isHTMLAreaElement(element);
}

class HTMLAudioElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLAudioElement(const HTMLAudioElement&);
void isHTMLAudioElement(const HTMLAudioElement*);

inline bool isHTMLAudioElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::audioTag);
}
inline bool isHTMLAudioElement(const HTMLElement* element)
{
    return element && isHTMLAudioElement(*element);
}
inline bool isHTMLAudioElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLAudioElement(toHTMLElement(node));
}
inline bool isHTMLAudioElement(const Node* node)
{
    return node && isHTMLAudioElement(*node);
}
template <>
inline bool isElementOfType<const HTMLAudioElement>(const Node& node)
{
    return isHTMLAudioElement(node);
}
template <>
inline bool isElementOfType<const HTMLAudioElement>(const HTMLElement& element)
{
    return isHTMLAudioElement(element);
}

class HTMLBRElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLBRElement(const HTMLBRElement&);
void isHTMLBRElement(const HTMLBRElement*);

inline bool isHTMLBRElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::brTag);
}
inline bool isHTMLBRElement(const HTMLElement* element)
{
    return element && isHTMLBRElement(*element);
}
inline bool isHTMLBRElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLBRElement(toHTMLElement(node));
}
inline bool isHTMLBRElement(const Node* node)
{
    return node && isHTMLBRElement(*node);
}
template <>
inline bool isElementOfType<const HTMLBRElement>(const Node& node)
{
    return isHTMLBRElement(node);
}
template <>
inline bool isElementOfType<const HTMLBRElement>(const HTMLElement& element)
{
    return isHTMLBRElement(element);
}

class HTMLBaseElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLBaseElement(const HTMLBaseElement&);
void isHTMLBaseElement(const HTMLBaseElement*);

inline bool isHTMLBaseElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::baseTag);
}
inline bool isHTMLBaseElement(const HTMLElement* element)
{
    return element && isHTMLBaseElement(*element);
}
inline bool isHTMLBaseElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLBaseElement(toHTMLElement(node));
}
inline bool isHTMLBaseElement(const Node* node)
{
    return node && isHTMLBaseElement(*node);
}
template <>
inline bool isElementOfType<const HTMLBaseElement>(const Node& node)
{
    return isHTMLBaseElement(node);
}
template <>
inline bool isElementOfType<const HTMLBaseElement>(const HTMLElement& element)
{
    return isHTMLBaseElement(element);
}

class HTMLBodyElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLBodyElement(const HTMLBodyElement&);
void isHTMLBodyElement(const HTMLBodyElement*);

inline bool isHTMLBodyElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::bodyTag);
}
inline bool isHTMLBodyElement(const HTMLElement* element)
{
    return element && isHTMLBodyElement(*element);
}
inline bool isHTMLBodyElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLBodyElement(toHTMLElement(node));
}
inline bool isHTMLBodyElement(const Node* node)
{
    return node && isHTMLBodyElement(*node);
}
template <>
inline bool isElementOfType<const HTMLBodyElement>(const Node& node)
{
    return isHTMLBodyElement(node);
}
template <>
inline bool isElementOfType<const HTMLBodyElement>(const HTMLElement& element)
{
    return isHTMLBodyElement(element);
}

class HTMLButtonElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLButtonElement(const HTMLButtonElement&);
void isHTMLButtonElement(const HTMLButtonElement*);

inline bool isHTMLButtonElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::buttonTag);
}
inline bool isHTMLButtonElement(const HTMLElement* element)
{
    return element && isHTMLButtonElement(*element);
}
inline bool isHTMLButtonElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLButtonElement(toHTMLElement(node));
}
inline bool isHTMLButtonElement(const Node* node)
{
    return node && isHTMLButtonElement(*node);
}
template <>
inline bool isElementOfType<const HTMLButtonElement>(const Node& node)
{
    return isHTMLButtonElement(node);
}
template <>
inline bool isElementOfType<const HTMLButtonElement>(const HTMLElement& element)
{
    return isHTMLButtonElement(element);
}

class HTMLCanvasElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLCanvasElement(const HTMLCanvasElement&);
void isHTMLCanvasElement(const HTMLCanvasElement*);

inline bool isHTMLCanvasElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::canvasTag);
}
inline bool isHTMLCanvasElement(const HTMLElement* element)
{
    return element && isHTMLCanvasElement(*element);
}
inline bool isHTMLCanvasElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLCanvasElement(toHTMLElement(node));
}
inline bool isHTMLCanvasElement(const Node* node)
{
    return node && isHTMLCanvasElement(*node);
}
template <>
inline bool isElementOfType<const HTMLCanvasElement>(const Node& node)
{
    return isHTMLCanvasElement(node);
}
template <>
inline bool isElementOfType<const HTMLCanvasElement>(const HTMLElement& element)
{
    return isHTMLCanvasElement(element);
}

class HTMLContentElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLContentElement(const HTMLContentElement&);
void isHTMLContentElement(const HTMLContentElement*);

inline bool isHTMLContentElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::contentTag);
}
inline bool isHTMLContentElement(const HTMLElement* element)
{
    return element && isHTMLContentElement(*element);
}
inline bool isHTMLContentElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLContentElement(toHTMLElement(node));
}
inline bool isHTMLContentElement(const Node* node)
{
    return node && isHTMLContentElement(*node);
}
template <>
inline bool isElementOfType<const HTMLContentElement>(const Node& node)
{
    return isHTMLContentElement(node);
}
template <>
inline bool isElementOfType<const HTMLContentElement>(const HTMLElement& element)
{
    return isHTMLContentElement(element);
}

class HTMLDListElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLDListElement(const HTMLDListElement&);
void isHTMLDListElement(const HTMLDListElement*);

inline bool isHTMLDListElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::dlTag);
}
inline bool isHTMLDListElement(const HTMLElement* element)
{
    return element && isHTMLDListElement(*element);
}
inline bool isHTMLDListElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLDListElement(toHTMLElement(node));
}
inline bool isHTMLDListElement(const Node* node)
{
    return node && isHTMLDListElement(*node);
}
template <>
inline bool isElementOfType<const HTMLDListElement>(const Node& node)
{
    return isHTMLDListElement(node);
}
template <>
inline bool isElementOfType<const HTMLDListElement>(const HTMLElement& element)
{
    return isHTMLDListElement(element);
}

class HTMLDataListElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLDataListElement(const HTMLDataListElement&);
void isHTMLDataListElement(const HTMLDataListElement*);

inline bool isHTMLDataListElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::datalistTag);
}
inline bool isHTMLDataListElement(const HTMLElement* element)
{
    return element && isHTMLDataListElement(*element);
}
inline bool isHTMLDataListElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLDataListElement(toHTMLElement(node));
}
inline bool isHTMLDataListElement(const Node* node)
{
    return node && isHTMLDataListElement(*node);
}
template <>
inline bool isElementOfType<const HTMLDataListElement>(const Node& node)
{
    return isHTMLDataListElement(node);
}
template <>
inline bool isElementOfType<const HTMLDataListElement>(const HTMLElement& element)
{
    return isHTMLDataListElement(element);
}

class HTMLDetailsElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLDetailsElement(const HTMLDetailsElement&);
void isHTMLDetailsElement(const HTMLDetailsElement*);

inline bool isHTMLDetailsElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::detailsTag);
}
inline bool isHTMLDetailsElement(const HTMLElement* element)
{
    return element && isHTMLDetailsElement(*element);
}
inline bool isHTMLDetailsElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLDetailsElement(toHTMLElement(node));
}
inline bool isHTMLDetailsElement(const Node* node)
{
    return node && isHTMLDetailsElement(*node);
}
template <>
inline bool isElementOfType<const HTMLDetailsElement>(const Node& node)
{
    return isHTMLDetailsElement(node);
}
template <>
inline bool isElementOfType<const HTMLDetailsElement>(const HTMLElement& element)
{
    return isHTMLDetailsElement(element);
}

class HTMLDialogElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLDialogElement(const HTMLDialogElement&);
void isHTMLDialogElement(const HTMLDialogElement*);

inline bool isHTMLDialogElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::dialogTag);
}
inline bool isHTMLDialogElement(const HTMLElement* element)
{
    return element && isHTMLDialogElement(*element);
}
inline bool isHTMLDialogElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLDialogElement(toHTMLElement(node));
}
inline bool isHTMLDialogElement(const Node* node)
{
    return node && isHTMLDialogElement(*node);
}
template <>
inline bool isElementOfType<const HTMLDialogElement>(const Node& node)
{
    return isHTMLDialogElement(node);
}
template <>
inline bool isElementOfType<const HTMLDialogElement>(const HTMLElement& element)
{
    return isHTMLDialogElement(element);
}

class HTMLDirectoryElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLDirectoryElement(const HTMLDirectoryElement&);
void isHTMLDirectoryElement(const HTMLDirectoryElement*);

inline bool isHTMLDirectoryElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::dirTag);
}
inline bool isHTMLDirectoryElement(const HTMLElement* element)
{
    return element && isHTMLDirectoryElement(*element);
}
inline bool isHTMLDirectoryElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLDirectoryElement(toHTMLElement(node));
}
inline bool isHTMLDirectoryElement(const Node* node)
{
    return node && isHTMLDirectoryElement(*node);
}
template <>
inline bool isElementOfType<const HTMLDirectoryElement>(const Node& node)
{
    return isHTMLDirectoryElement(node);
}
template <>
inline bool isElementOfType<const HTMLDirectoryElement>(const HTMLElement& element)
{
    return isHTMLDirectoryElement(element);
}

class HTMLDivElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLDivElement(const HTMLDivElement&);
void isHTMLDivElement(const HTMLDivElement*);

inline bool isHTMLDivElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::divTag);
}
inline bool isHTMLDivElement(const HTMLElement* element)
{
    return element && isHTMLDivElement(*element);
}
inline bool isHTMLDivElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLDivElement(toHTMLElement(node));
}
inline bool isHTMLDivElement(const Node* node)
{
    return node && isHTMLDivElement(*node);
}
template <>
inline bool isElementOfType<const HTMLDivElement>(const Node& node)
{
    return isHTMLDivElement(node);
}
template <>
inline bool isElementOfType<const HTMLDivElement>(const HTMLElement& element)
{
    return isHTMLDivElement(element);
}

class HTMLFieldSetElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLFieldSetElement(const HTMLFieldSetElement&);
void isHTMLFieldSetElement(const HTMLFieldSetElement*);

inline bool isHTMLFieldSetElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::fieldsetTag);
}
inline bool isHTMLFieldSetElement(const HTMLElement* element)
{
    return element && isHTMLFieldSetElement(*element);
}
inline bool isHTMLFieldSetElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLFieldSetElement(toHTMLElement(node));
}
inline bool isHTMLFieldSetElement(const Node* node)
{
    return node && isHTMLFieldSetElement(*node);
}
template <>
inline bool isElementOfType<const HTMLFieldSetElement>(const Node& node)
{
    return isHTMLFieldSetElement(node);
}
template <>
inline bool isElementOfType<const HTMLFieldSetElement>(const HTMLElement& element)
{
    return isHTMLFieldSetElement(element);
}

class HTMLFontElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLFontElement(const HTMLFontElement&);
void isHTMLFontElement(const HTMLFontElement*);

inline bool isHTMLFontElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::fontTag);
}
inline bool isHTMLFontElement(const HTMLElement* element)
{
    return element && isHTMLFontElement(*element);
}
inline bool isHTMLFontElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLFontElement(toHTMLElement(node));
}
inline bool isHTMLFontElement(const Node* node)
{
    return node && isHTMLFontElement(*node);
}
template <>
inline bool isElementOfType<const HTMLFontElement>(const Node& node)
{
    return isHTMLFontElement(node);
}
template <>
inline bool isElementOfType<const HTMLFontElement>(const HTMLElement& element)
{
    return isHTMLFontElement(element);
}

class HTMLFormElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLFormElement(const HTMLFormElement&);
void isHTMLFormElement(const HTMLFormElement*);

inline bool isHTMLFormElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::formTag);
}
inline bool isHTMLFormElement(const HTMLElement* element)
{
    return element && isHTMLFormElement(*element);
}
inline bool isHTMLFormElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLFormElement(toHTMLElement(node));
}
inline bool isHTMLFormElement(const Node* node)
{
    return node && isHTMLFormElement(*node);
}
template <>
inline bool isElementOfType<const HTMLFormElement>(const Node& node)
{
    return isHTMLFormElement(node);
}
template <>
inline bool isElementOfType<const HTMLFormElement>(const HTMLElement& element)
{
    return isHTMLFormElement(element);
}

class HTMLFrameElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLFrameElement(const HTMLFrameElement&);
void isHTMLFrameElement(const HTMLFrameElement*);

inline bool isHTMLFrameElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::frameTag);
}
inline bool isHTMLFrameElement(const HTMLElement* element)
{
    return element && isHTMLFrameElement(*element);
}
inline bool isHTMLFrameElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLFrameElement(toHTMLElement(node));
}
inline bool isHTMLFrameElement(const Node* node)
{
    return node && isHTMLFrameElement(*node);
}
template <>
inline bool isElementOfType<const HTMLFrameElement>(const Node& node)
{
    return isHTMLFrameElement(node);
}
template <>
inline bool isElementOfType<const HTMLFrameElement>(const HTMLElement& element)
{
    return isHTMLFrameElement(element);
}

class HTMLFrameSetElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLFrameSetElement(const HTMLFrameSetElement&);
void isHTMLFrameSetElement(const HTMLFrameSetElement*);

inline bool isHTMLFrameSetElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::framesetTag);
}
inline bool isHTMLFrameSetElement(const HTMLElement* element)
{
    return element && isHTMLFrameSetElement(*element);
}
inline bool isHTMLFrameSetElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLFrameSetElement(toHTMLElement(node));
}
inline bool isHTMLFrameSetElement(const Node* node)
{
    return node && isHTMLFrameSetElement(*node);
}
template <>
inline bool isElementOfType<const HTMLFrameSetElement>(const Node& node)
{
    return isHTMLFrameSetElement(node);
}
template <>
inline bool isElementOfType<const HTMLFrameSetElement>(const HTMLElement& element)
{
    return isHTMLFrameSetElement(element);
}

class HTMLHRElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLHRElement(const HTMLHRElement&);
void isHTMLHRElement(const HTMLHRElement*);

inline bool isHTMLHRElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::hrTag);
}
inline bool isHTMLHRElement(const HTMLElement* element)
{
    return element && isHTMLHRElement(*element);
}
inline bool isHTMLHRElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLHRElement(toHTMLElement(node));
}
inline bool isHTMLHRElement(const Node* node)
{
    return node && isHTMLHRElement(*node);
}
template <>
inline bool isElementOfType<const HTMLHRElement>(const Node& node)
{
    return isHTMLHRElement(node);
}
template <>
inline bool isElementOfType<const HTMLHRElement>(const HTMLElement& element)
{
    return isHTMLHRElement(element);
}

class HTMLHeadElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLHeadElement(const HTMLHeadElement&);
void isHTMLHeadElement(const HTMLHeadElement*);

inline bool isHTMLHeadElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::headTag);
}
inline bool isHTMLHeadElement(const HTMLElement* element)
{
    return element && isHTMLHeadElement(*element);
}
inline bool isHTMLHeadElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLHeadElement(toHTMLElement(node));
}
inline bool isHTMLHeadElement(const Node* node)
{
    return node && isHTMLHeadElement(*node);
}
template <>
inline bool isElementOfType<const HTMLHeadElement>(const Node& node)
{
    return isHTMLHeadElement(node);
}
template <>
inline bool isElementOfType<const HTMLHeadElement>(const HTMLElement& element)
{
    return isHTMLHeadElement(element);
}

class HTMLHtmlElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLHtmlElement(const HTMLHtmlElement&);
void isHTMLHtmlElement(const HTMLHtmlElement*);

inline bool isHTMLHtmlElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::htmlTag);
}
inline bool isHTMLHtmlElement(const HTMLElement* element)
{
    return element && isHTMLHtmlElement(*element);
}
inline bool isHTMLHtmlElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLHtmlElement(toHTMLElement(node));
}
inline bool isHTMLHtmlElement(const Node* node)
{
    return node && isHTMLHtmlElement(*node);
}
template <>
inline bool isElementOfType<const HTMLHtmlElement>(const Node& node)
{
    return isHTMLHtmlElement(node);
}
template <>
inline bool isElementOfType<const HTMLHtmlElement>(const HTMLElement& element)
{
    return isHTMLHtmlElement(element);
}

class HTMLIFrameElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLIFrameElement(const HTMLIFrameElement&);
void isHTMLIFrameElement(const HTMLIFrameElement*);

inline bool isHTMLIFrameElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::iframeTag);
}
inline bool isHTMLIFrameElement(const HTMLElement* element)
{
    return element && isHTMLIFrameElement(*element);
}
inline bool isHTMLIFrameElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLIFrameElement(toHTMLElement(node));
}
inline bool isHTMLIFrameElement(const Node* node)
{
    return node && isHTMLIFrameElement(*node);
}
template <>
inline bool isElementOfType<const HTMLIFrameElement>(const Node& node)
{
    return isHTMLIFrameElement(node);
}
template <>
inline bool isElementOfType<const HTMLIFrameElement>(const HTMLElement& element)
{
    return isHTMLIFrameElement(element);
}

class HTMLLIElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLLIElement(const HTMLLIElement&);
void isHTMLLIElement(const HTMLLIElement*);

inline bool isHTMLLIElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::liTag);
}
inline bool isHTMLLIElement(const HTMLElement* element)
{
    return element && isHTMLLIElement(*element);
}
inline bool isHTMLLIElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLLIElement(toHTMLElement(node));
}
inline bool isHTMLLIElement(const Node* node)
{
    return node && isHTMLLIElement(*node);
}
template <>
inline bool isElementOfType<const HTMLLIElement>(const Node& node)
{
    return isHTMLLIElement(node);
}
template <>
inline bool isElementOfType<const HTMLLIElement>(const HTMLElement& element)
{
    return isHTMLLIElement(element);
}

class HTMLLabelElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLLabelElement(const HTMLLabelElement&);
void isHTMLLabelElement(const HTMLLabelElement*);

inline bool isHTMLLabelElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::labelTag);
}
inline bool isHTMLLabelElement(const HTMLElement* element)
{
    return element && isHTMLLabelElement(*element);
}
inline bool isHTMLLabelElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLLabelElement(toHTMLElement(node));
}
inline bool isHTMLLabelElement(const Node* node)
{
    return node && isHTMLLabelElement(*node);
}
template <>
inline bool isElementOfType<const HTMLLabelElement>(const Node& node)
{
    return isHTMLLabelElement(node);
}
template <>
inline bool isElementOfType<const HTMLLabelElement>(const HTMLElement& element)
{
    return isHTMLLabelElement(element);
}

class HTMLLegendElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLLegendElement(const HTMLLegendElement&);
void isHTMLLegendElement(const HTMLLegendElement*);

inline bool isHTMLLegendElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::legendTag);
}
inline bool isHTMLLegendElement(const HTMLElement* element)
{
    return element && isHTMLLegendElement(*element);
}
inline bool isHTMLLegendElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLLegendElement(toHTMLElement(node));
}
inline bool isHTMLLegendElement(const Node* node)
{
    return node && isHTMLLegendElement(*node);
}
template <>
inline bool isElementOfType<const HTMLLegendElement>(const Node& node)
{
    return isHTMLLegendElement(node);
}
template <>
inline bool isElementOfType<const HTMLLegendElement>(const HTMLElement& element)
{
    return isHTMLLegendElement(element);
}

class HTMLMapElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLMapElement(const HTMLMapElement&);
void isHTMLMapElement(const HTMLMapElement*);

inline bool isHTMLMapElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::mapTag);
}
inline bool isHTMLMapElement(const HTMLElement* element)
{
    return element && isHTMLMapElement(*element);
}
inline bool isHTMLMapElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLMapElement(toHTMLElement(node));
}
inline bool isHTMLMapElement(const Node* node)
{
    return node && isHTMLMapElement(*node);
}
template <>
inline bool isElementOfType<const HTMLMapElement>(const Node& node)
{
    return isHTMLMapElement(node);
}
template <>
inline bool isElementOfType<const HTMLMapElement>(const HTMLElement& element)
{
    return isHTMLMapElement(element);
}

class HTMLMarqueeElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLMarqueeElement(const HTMLMarqueeElement&);
void isHTMLMarqueeElement(const HTMLMarqueeElement*);

inline bool isHTMLMarqueeElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::marqueeTag);
}
inline bool isHTMLMarqueeElement(const HTMLElement* element)
{
    return element && isHTMLMarqueeElement(*element);
}
inline bool isHTMLMarqueeElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLMarqueeElement(toHTMLElement(node));
}
inline bool isHTMLMarqueeElement(const Node* node)
{
    return node && isHTMLMarqueeElement(*node);
}
template <>
inline bool isElementOfType<const HTMLMarqueeElement>(const Node& node)
{
    return isHTMLMarqueeElement(node);
}
template <>
inline bool isElementOfType<const HTMLMarqueeElement>(const HTMLElement& element)
{
    return isHTMLMarqueeElement(element);
}

class HTMLMenuElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLMenuElement(const HTMLMenuElement&);
void isHTMLMenuElement(const HTMLMenuElement*);

inline bool isHTMLMenuElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::menuTag);
}
inline bool isHTMLMenuElement(const HTMLElement* element)
{
    return element && isHTMLMenuElement(*element);
}
inline bool isHTMLMenuElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLMenuElement(toHTMLElement(node));
}
inline bool isHTMLMenuElement(const Node* node)
{
    return node && isHTMLMenuElement(*node);
}
template <>
inline bool isElementOfType<const HTMLMenuElement>(const Node& node)
{
    return isHTMLMenuElement(node);
}
template <>
inline bool isElementOfType<const HTMLMenuElement>(const HTMLElement& element)
{
    return isHTMLMenuElement(element);
}

class HTMLMenuItemElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLMenuItemElement(const HTMLMenuItemElement&);
void isHTMLMenuItemElement(const HTMLMenuItemElement*);

inline bool isHTMLMenuItemElement(const HTMLElement& element)
{
    if (!RuntimeEnabledFeatures::contextMenuEnabled())
        return false;
    return element.hasTagName(HTMLNames::menuitemTag);
}
inline bool isHTMLMenuItemElement(const HTMLElement* element)
{
    return element && isHTMLMenuItemElement(*element);
}
inline bool isHTMLMenuItemElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLMenuItemElement(toHTMLElement(node));
}
inline bool isHTMLMenuItemElement(const Node* node)
{
    return node && isHTMLMenuItemElement(*node);
}
template <>
inline bool isElementOfType<const HTMLMenuItemElement>(const Node& node)
{
    return isHTMLMenuItemElement(node);
}
template <>
inline bool isElementOfType<const HTMLMenuItemElement>(const HTMLElement& element)
{
    return isHTMLMenuItemElement(element);
}

class HTMLMetaElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLMetaElement(const HTMLMetaElement&);
void isHTMLMetaElement(const HTMLMetaElement*);

inline bool isHTMLMetaElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::metaTag);
}
inline bool isHTMLMetaElement(const HTMLElement* element)
{
    return element && isHTMLMetaElement(*element);
}
inline bool isHTMLMetaElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLMetaElement(toHTMLElement(node));
}
inline bool isHTMLMetaElement(const Node* node)
{
    return node && isHTMLMetaElement(*node);
}
template <>
inline bool isElementOfType<const HTMLMetaElement>(const Node& node)
{
    return isHTMLMetaElement(node);
}
template <>
inline bool isElementOfType<const HTMLMetaElement>(const HTMLElement& element)
{
    return isHTMLMetaElement(element);
}

class HTMLMeterElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLMeterElement(const HTMLMeterElement&);
void isHTMLMeterElement(const HTMLMeterElement*);

inline bool isHTMLMeterElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::meterTag);
}
inline bool isHTMLMeterElement(const HTMLElement* element)
{
    return element && isHTMLMeterElement(*element);
}
inline bool isHTMLMeterElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLMeterElement(toHTMLElement(node));
}
inline bool isHTMLMeterElement(const Node* node)
{
    return node && isHTMLMeterElement(*node);
}
template <>
inline bool isElementOfType<const HTMLMeterElement>(const Node& node)
{
    return isHTMLMeterElement(node);
}
template <>
inline bool isElementOfType<const HTMLMeterElement>(const HTMLElement& element)
{
    return isHTMLMeterElement(element);
}

class HTMLOListElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLOListElement(const HTMLOListElement&);
void isHTMLOListElement(const HTMLOListElement*);

inline bool isHTMLOListElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::olTag);
}
inline bool isHTMLOListElement(const HTMLElement* element)
{
    return element && isHTMLOListElement(*element);
}
inline bool isHTMLOListElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLOListElement(toHTMLElement(node));
}
inline bool isHTMLOListElement(const Node* node)
{
    return node && isHTMLOListElement(*node);
}
template <>
inline bool isElementOfType<const HTMLOListElement>(const Node& node)
{
    return isHTMLOListElement(node);
}
template <>
inline bool isElementOfType<const HTMLOListElement>(const HTMLElement& element)
{
    return isHTMLOListElement(element);
}

class HTMLOptGroupElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLOptGroupElement(const HTMLOptGroupElement&);
void isHTMLOptGroupElement(const HTMLOptGroupElement*);

inline bool isHTMLOptGroupElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::optgroupTag);
}
inline bool isHTMLOptGroupElement(const HTMLElement* element)
{
    return element && isHTMLOptGroupElement(*element);
}
inline bool isHTMLOptGroupElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLOptGroupElement(toHTMLElement(node));
}
inline bool isHTMLOptGroupElement(const Node* node)
{
    return node && isHTMLOptGroupElement(*node);
}
template <>
inline bool isElementOfType<const HTMLOptGroupElement>(const Node& node)
{
    return isHTMLOptGroupElement(node);
}
template <>
inline bool isElementOfType<const HTMLOptGroupElement>(const HTMLElement& element)
{
    return isHTMLOptGroupElement(element);
}

class HTMLOptionElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLOptionElement(const HTMLOptionElement&);
void isHTMLOptionElement(const HTMLOptionElement*);

inline bool isHTMLOptionElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::optionTag);
}
inline bool isHTMLOptionElement(const HTMLElement* element)
{
    return element && isHTMLOptionElement(*element);
}
inline bool isHTMLOptionElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLOptionElement(toHTMLElement(node));
}
inline bool isHTMLOptionElement(const Node* node)
{
    return node && isHTMLOptionElement(*node);
}
template <>
inline bool isElementOfType<const HTMLOptionElement>(const Node& node)
{
    return isHTMLOptionElement(node);
}
template <>
inline bool isElementOfType<const HTMLOptionElement>(const HTMLElement& element)
{
    return isHTMLOptionElement(element);
}

class HTMLOutputElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLOutputElement(const HTMLOutputElement&);
void isHTMLOutputElement(const HTMLOutputElement*);

inline bool isHTMLOutputElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::outputTag);
}
inline bool isHTMLOutputElement(const HTMLElement* element)
{
    return element && isHTMLOutputElement(*element);
}
inline bool isHTMLOutputElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLOutputElement(toHTMLElement(node));
}
inline bool isHTMLOutputElement(const Node* node)
{
    return node && isHTMLOutputElement(*node);
}
template <>
inline bool isElementOfType<const HTMLOutputElement>(const Node& node)
{
    return isHTMLOutputElement(node);
}
template <>
inline bool isElementOfType<const HTMLOutputElement>(const HTMLElement& element)
{
    return isHTMLOutputElement(element);
}

class HTMLParagraphElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLParagraphElement(const HTMLParagraphElement&);
void isHTMLParagraphElement(const HTMLParagraphElement*);

inline bool isHTMLParagraphElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::pTag);
}
inline bool isHTMLParagraphElement(const HTMLElement* element)
{
    return element && isHTMLParagraphElement(*element);
}
inline bool isHTMLParagraphElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLParagraphElement(toHTMLElement(node));
}
inline bool isHTMLParagraphElement(const Node* node)
{
    return node && isHTMLParagraphElement(*node);
}
template <>
inline bool isElementOfType<const HTMLParagraphElement>(const Node& node)
{
    return isHTMLParagraphElement(node);
}
template <>
inline bool isElementOfType<const HTMLParagraphElement>(const HTMLElement& element)
{
    return isHTMLParagraphElement(element);
}

class HTMLParamElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLParamElement(const HTMLParamElement&);
void isHTMLParamElement(const HTMLParamElement*);

inline bool isHTMLParamElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::paramTag);
}
inline bool isHTMLParamElement(const HTMLElement* element)
{
    return element && isHTMLParamElement(*element);
}
inline bool isHTMLParamElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLParamElement(toHTMLElement(node));
}
inline bool isHTMLParamElement(const Node* node)
{
    return node && isHTMLParamElement(*node);
}
template <>
inline bool isElementOfType<const HTMLParamElement>(const Node& node)
{
    return isHTMLParamElement(node);
}
template <>
inline bool isElementOfType<const HTMLParamElement>(const HTMLElement& element)
{
    return isHTMLParamElement(element);
}

class HTMLPictureElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLPictureElement(const HTMLPictureElement&);
void isHTMLPictureElement(const HTMLPictureElement*);

inline bool isHTMLPictureElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::pictureTag);
}
inline bool isHTMLPictureElement(const HTMLElement* element)
{
    return element && isHTMLPictureElement(*element);
}
inline bool isHTMLPictureElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLPictureElement(toHTMLElement(node));
}
inline bool isHTMLPictureElement(const Node* node)
{
    return node && isHTMLPictureElement(*node);
}
template <>
inline bool isElementOfType<const HTMLPictureElement>(const Node& node)
{
    return isHTMLPictureElement(node);
}
template <>
inline bool isElementOfType<const HTMLPictureElement>(const HTMLElement& element)
{
    return isHTMLPictureElement(element);
}

class HTMLProgressElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLProgressElement(const HTMLProgressElement&);
void isHTMLProgressElement(const HTMLProgressElement*);

inline bool isHTMLProgressElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::progressTag);
}
inline bool isHTMLProgressElement(const HTMLElement* element)
{
    return element && isHTMLProgressElement(*element);
}
inline bool isHTMLProgressElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLProgressElement(toHTMLElement(node));
}
inline bool isHTMLProgressElement(const Node* node)
{
    return node && isHTMLProgressElement(*node);
}
template <>
inline bool isElementOfType<const HTMLProgressElement>(const Node& node)
{
    return isHTMLProgressElement(node);
}
template <>
inline bool isElementOfType<const HTMLProgressElement>(const HTMLElement& element)
{
    return isHTMLProgressElement(element);
}

class HTMLSelectElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLSelectElement(const HTMLSelectElement&);
void isHTMLSelectElement(const HTMLSelectElement*);

inline bool isHTMLSelectElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::selectTag);
}
inline bool isHTMLSelectElement(const HTMLElement* element)
{
    return element && isHTMLSelectElement(*element);
}
inline bool isHTMLSelectElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLSelectElement(toHTMLElement(node));
}
inline bool isHTMLSelectElement(const Node* node)
{
    return node && isHTMLSelectElement(*node);
}
template <>
inline bool isElementOfType<const HTMLSelectElement>(const Node& node)
{
    return isHTMLSelectElement(node);
}
template <>
inline bool isElementOfType<const HTMLSelectElement>(const HTMLElement& element)
{
    return isHTMLSelectElement(element);
}

class HTMLShadowElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLShadowElement(const HTMLShadowElement&);
void isHTMLShadowElement(const HTMLShadowElement*);

inline bool isHTMLShadowElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::shadowTag);
}
inline bool isHTMLShadowElement(const HTMLElement* element)
{
    return element && isHTMLShadowElement(*element);
}
inline bool isHTMLShadowElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLShadowElement(toHTMLElement(node));
}
inline bool isHTMLShadowElement(const Node* node)
{
    return node && isHTMLShadowElement(*node);
}
template <>
inline bool isElementOfType<const HTMLShadowElement>(const Node& node)
{
    return isHTMLShadowElement(node);
}
template <>
inline bool isElementOfType<const HTMLShadowElement>(const HTMLElement& element)
{
    return isHTMLShadowElement(element);
}

class HTMLSlotElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLSlotElement(const HTMLSlotElement&);
void isHTMLSlotElement(const HTMLSlotElement*);

inline bool isHTMLSlotElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::slotTag);
}
inline bool isHTMLSlotElement(const HTMLElement* element)
{
    return element && isHTMLSlotElement(*element);
}
inline bool isHTMLSlotElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLSlotElement(toHTMLElement(node));
}
inline bool isHTMLSlotElement(const Node* node)
{
    return node && isHTMLSlotElement(*node);
}
template <>
inline bool isElementOfType<const HTMLSlotElement>(const Node& node)
{
    return isHTMLSlotElement(node);
}
template <>
inline bool isElementOfType<const HTMLSlotElement>(const HTMLElement& element)
{
    return isHTMLSlotElement(element);
}

class HTMLSourceElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLSourceElement(const HTMLSourceElement&);
void isHTMLSourceElement(const HTMLSourceElement*);

inline bool isHTMLSourceElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::sourceTag);
}
inline bool isHTMLSourceElement(const HTMLElement* element)
{
    return element && isHTMLSourceElement(*element);
}
inline bool isHTMLSourceElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLSourceElement(toHTMLElement(node));
}
inline bool isHTMLSourceElement(const Node* node)
{
    return node && isHTMLSourceElement(*node);
}
template <>
inline bool isElementOfType<const HTMLSourceElement>(const Node& node)
{
    return isHTMLSourceElement(node);
}
template <>
inline bool isElementOfType<const HTMLSourceElement>(const HTMLElement& element)
{
    return isHTMLSourceElement(element);
}

class HTMLSpanElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLSpanElement(const HTMLSpanElement&);
void isHTMLSpanElement(const HTMLSpanElement*);

inline bool isHTMLSpanElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::spanTag);
}
inline bool isHTMLSpanElement(const HTMLElement* element)
{
    return element && isHTMLSpanElement(*element);
}
inline bool isHTMLSpanElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLSpanElement(toHTMLElement(node));
}
inline bool isHTMLSpanElement(const Node* node)
{
    return node && isHTMLSpanElement(*node);
}
template <>
inline bool isElementOfType<const HTMLSpanElement>(const Node& node)
{
    return isHTMLSpanElement(node);
}
template <>
inline bool isElementOfType<const HTMLSpanElement>(const HTMLElement& element)
{
    return isHTMLSpanElement(element);
}

class HTMLTableCaptionElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLTableCaptionElement(const HTMLTableCaptionElement&);
void isHTMLTableCaptionElement(const HTMLTableCaptionElement*);

inline bool isHTMLTableCaptionElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::captionTag);
}
inline bool isHTMLTableCaptionElement(const HTMLElement* element)
{
    return element && isHTMLTableCaptionElement(*element);
}
inline bool isHTMLTableCaptionElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLTableCaptionElement(toHTMLElement(node));
}
inline bool isHTMLTableCaptionElement(const Node* node)
{
    return node && isHTMLTableCaptionElement(*node);
}
template <>
inline bool isElementOfType<const HTMLTableCaptionElement>(const Node& node)
{
    return isHTMLTableCaptionElement(node);
}
template <>
inline bool isElementOfType<const HTMLTableCaptionElement>(const HTMLElement& element)
{
    return isHTMLTableCaptionElement(element);
}

class HTMLTableElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLTableElement(const HTMLTableElement&);
void isHTMLTableElement(const HTMLTableElement*);

inline bool isHTMLTableElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::tableTag);
}
inline bool isHTMLTableElement(const HTMLElement* element)
{
    return element && isHTMLTableElement(*element);
}
inline bool isHTMLTableElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLTableElement(toHTMLElement(node));
}
inline bool isHTMLTableElement(const Node* node)
{
    return node && isHTMLTableElement(*node);
}
template <>
inline bool isElementOfType<const HTMLTableElement>(const Node& node)
{
    return isHTMLTableElement(node);
}
template <>
inline bool isElementOfType<const HTMLTableElement>(const HTMLElement& element)
{
    return isHTMLTableElement(element);
}

class HTMLTableRowElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLTableRowElement(const HTMLTableRowElement&);
void isHTMLTableRowElement(const HTMLTableRowElement*);

inline bool isHTMLTableRowElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::trTag);
}
inline bool isHTMLTableRowElement(const HTMLElement* element)
{
    return element && isHTMLTableRowElement(*element);
}
inline bool isHTMLTableRowElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLTableRowElement(toHTMLElement(node));
}
inline bool isHTMLTableRowElement(const Node* node)
{
    return node && isHTMLTableRowElement(*node);
}
template <>
inline bool isElementOfType<const HTMLTableRowElement>(const Node& node)
{
    return isHTMLTableRowElement(node);
}
template <>
inline bool isElementOfType<const HTMLTableRowElement>(const HTMLElement& element)
{
    return isHTMLTableRowElement(element);
}

class HTMLTemplateElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLTemplateElement(const HTMLTemplateElement&);
void isHTMLTemplateElement(const HTMLTemplateElement*);

inline bool isHTMLTemplateElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::templateTag);
}
inline bool isHTMLTemplateElement(const HTMLElement* element)
{
    return element && isHTMLTemplateElement(*element);
}
inline bool isHTMLTemplateElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLTemplateElement(toHTMLElement(node));
}
inline bool isHTMLTemplateElement(const Node* node)
{
    return node && isHTMLTemplateElement(*node);
}
template <>
inline bool isElementOfType<const HTMLTemplateElement>(const Node& node)
{
    return isHTMLTemplateElement(node);
}
template <>
inline bool isElementOfType<const HTMLTemplateElement>(const HTMLElement& element)
{
    return isHTMLTemplateElement(element);
}

class HTMLTextAreaElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLTextAreaElement(const HTMLTextAreaElement&);
void isHTMLTextAreaElement(const HTMLTextAreaElement*);

inline bool isHTMLTextAreaElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::textareaTag);
}
inline bool isHTMLTextAreaElement(const HTMLElement* element)
{
    return element && isHTMLTextAreaElement(*element);
}
inline bool isHTMLTextAreaElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLTextAreaElement(toHTMLElement(node));
}
inline bool isHTMLTextAreaElement(const Node* node)
{
    return node && isHTMLTextAreaElement(*node);
}
template <>
inline bool isElementOfType<const HTMLTextAreaElement>(const Node& node)
{
    return isHTMLTextAreaElement(node);
}
template <>
inline bool isElementOfType<const HTMLTextAreaElement>(const HTMLElement& element)
{
    return isHTMLTextAreaElement(element);
}

class HTMLTitleElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLTitleElement(const HTMLTitleElement&);
void isHTMLTitleElement(const HTMLTitleElement*);

inline bool isHTMLTitleElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::titleTag);
}
inline bool isHTMLTitleElement(const HTMLElement* element)
{
    return element && isHTMLTitleElement(*element);
}
inline bool isHTMLTitleElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLTitleElement(toHTMLElement(node));
}
inline bool isHTMLTitleElement(const Node* node)
{
    return node && isHTMLTitleElement(*node);
}
template <>
inline bool isElementOfType<const HTMLTitleElement>(const Node& node)
{
    return isHTMLTitleElement(node);
}
template <>
inline bool isElementOfType<const HTMLTitleElement>(const HTMLElement& element)
{
    return isHTMLTitleElement(element);
}

class HTMLTrackElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLTrackElement(const HTMLTrackElement&);
void isHTMLTrackElement(const HTMLTrackElement*);

inline bool isHTMLTrackElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::trackTag);
}
inline bool isHTMLTrackElement(const HTMLElement* element)
{
    return element && isHTMLTrackElement(*element);
}
inline bool isHTMLTrackElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLTrackElement(toHTMLElement(node));
}
inline bool isHTMLTrackElement(const Node* node)
{
    return node && isHTMLTrackElement(*node);
}
template <>
inline bool isElementOfType<const HTMLTrackElement>(const Node& node)
{
    return isHTMLTrackElement(node);
}
template <>
inline bool isElementOfType<const HTMLTrackElement>(const HTMLElement& element)
{
    return isHTMLTrackElement(element);
}

class HTMLUListElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLUListElement(const HTMLUListElement&);
void isHTMLUListElement(const HTMLUListElement*);

inline bool isHTMLUListElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::ulTag);
}
inline bool isHTMLUListElement(const HTMLElement* element)
{
    return element && isHTMLUListElement(*element);
}
inline bool isHTMLUListElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLUListElement(toHTMLElement(node));
}
inline bool isHTMLUListElement(const Node* node)
{
    return node && isHTMLUListElement(*node);
}
template <>
inline bool isElementOfType<const HTMLUListElement>(const Node& node)
{
    return isHTMLUListElement(node);
}
template <>
inline bool isElementOfType<const HTMLUListElement>(const HTMLElement& element)
{
    return isHTMLUListElement(element);
}

class HTMLVideoElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLVideoElement(const HTMLVideoElement&);
void isHTMLVideoElement(const HTMLVideoElement*);

inline bool isHTMLVideoElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::videoTag);
}
inline bool isHTMLVideoElement(const HTMLElement* element)
{
    return element && isHTMLVideoElement(*element);
}
inline bool isHTMLVideoElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLVideoElement(toHTMLElement(node));
}
inline bool isHTMLVideoElement(const Node* node)
{
    return node && isHTMLVideoElement(*node);
}
template <>
inline bool isElementOfType<const HTMLVideoElement>(const Node& node)
{
    return isHTMLVideoElement(node);
}
template <>
inline bool isElementOfType<const HTMLVideoElement>(const HTMLElement& element)
{
    return isHTMLVideoElement(element);
}

class HTMLEmbedElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLEmbedElement(const HTMLEmbedElement&);
void isHTMLEmbedElement(const HTMLEmbedElement*);

inline bool isHTMLEmbedElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::embedTag);
}
inline bool isHTMLEmbedElement(const HTMLElement* element)
{
    return element && isHTMLEmbedElement(*element);
}
inline bool isHTMLEmbedElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLEmbedElement(toHTMLElement(node));
}
inline bool isHTMLEmbedElement(const Node* node)
{
    return node && isHTMLEmbedElement(*node);
}
template <>
inline bool isElementOfType<const HTMLEmbedElement>(const Node& node)
{
    return isHTMLEmbedElement(node);
}
template <>
inline bool isElementOfType<const HTMLEmbedElement>(const HTMLElement& element)
{
    return isHTMLEmbedElement(element);
}

class HTMLImageElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLImageElement(const HTMLImageElement&);
void isHTMLImageElement(const HTMLImageElement*);

inline bool isHTMLImageElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::imgTag);
}
inline bool isHTMLImageElement(const HTMLElement* element)
{
    return element && isHTMLImageElement(*element);
}
inline bool isHTMLImageElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLImageElement(toHTMLElement(node));
}
inline bool isHTMLImageElement(const Node* node)
{
    return node && isHTMLImageElement(*node);
}
template <>
inline bool isElementOfType<const HTMLImageElement>(const Node& node)
{
    return isHTMLImageElement(node);
}
template <>
inline bool isElementOfType<const HTMLImageElement>(const HTMLElement& element)
{
    return isHTMLImageElement(element);
}

class HTMLInputElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLInputElement(const HTMLInputElement&);
void isHTMLInputElement(const HTMLInputElement*);

inline bool isHTMLInputElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::inputTag);
}
inline bool isHTMLInputElement(const HTMLElement* element)
{
    return element && isHTMLInputElement(*element);
}
inline bool isHTMLInputElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLInputElement(toHTMLElement(node));
}
inline bool isHTMLInputElement(const Node* node)
{
    return node && isHTMLInputElement(*node);
}
template <>
inline bool isElementOfType<const HTMLInputElement>(const Node& node)
{
    return isHTMLInputElement(node);
}
template <>
inline bool isElementOfType<const HTMLInputElement>(const HTMLElement& element)
{
    return isHTMLInputElement(element);
}

class HTMLLinkElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLLinkElement(const HTMLLinkElement&);
void isHTMLLinkElement(const HTMLLinkElement*);

inline bool isHTMLLinkElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::linkTag);
}
inline bool isHTMLLinkElement(const HTMLElement* element)
{
    return element && isHTMLLinkElement(*element);
}
inline bool isHTMLLinkElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLLinkElement(toHTMLElement(node));
}
inline bool isHTMLLinkElement(const Node* node)
{
    return node && isHTMLLinkElement(*node);
}
template <>
inline bool isElementOfType<const HTMLLinkElement>(const Node& node)
{
    return isHTMLLinkElement(node);
}
template <>
inline bool isElementOfType<const HTMLLinkElement>(const HTMLElement& element)
{
    return isHTMLLinkElement(element);
}

class HTMLObjectElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLObjectElement(const HTMLObjectElement&);
void isHTMLObjectElement(const HTMLObjectElement*);

inline bool isHTMLObjectElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::objectTag);
}
inline bool isHTMLObjectElement(const HTMLElement* element)
{
    return element && isHTMLObjectElement(*element);
}
inline bool isHTMLObjectElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLObjectElement(toHTMLElement(node));
}
inline bool isHTMLObjectElement(const Node* node)
{
    return node && isHTMLObjectElement(*node);
}
template <>
inline bool isElementOfType<const HTMLObjectElement>(const Node& node)
{
    return isHTMLObjectElement(node);
}
template <>
inline bool isElementOfType<const HTMLObjectElement>(const HTMLElement& element)
{
    return isHTMLObjectElement(element);
}

class HTMLScriptElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLScriptElement(const HTMLScriptElement&);
void isHTMLScriptElement(const HTMLScriptElement*);

inline bool isHTMLScriptElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::scriptTag);
}
inline bool isHTMLScriptElement(const HTMLElement* element)
{
    return element && isHTMLScriptElement(*element);
}
inline bool isHTMLScriptElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLScriptElement(toHTMLElement(node));
}
inline bool isHTMLScriptElement(const Node* node)
{
    return node && isHTMLScriptElement(*node);
}
template <>
inline bool isElementOfType<const HTMLScriptElement>(const Node& node)
{
    return isHTMLScriptElement(node);
}
template <>
inline bool isElementOfType<const HTMLScriptElement>(const HTMLElement& element)
{
    return isHTMLScriptElement(element);
}

class HTMLStyleElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLStyleElement(const HTMLStyleElement&);
void isHTMLStyleElement(const HTMLStyleElement*);

inline bool isHTMLStyleElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::styleTag);
}
inline bool isHTMLStyleElement(const HTMLElement* element)
{
    return element && isHTMLStyleElement(*element);
}
inline bool isHTMLStyleElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLStyleElement(toHTMLElement(node));
}
inline bool isHTMLStyleElement(const Node* node)
{
    return node && isHTMLStyleElement(*node);
}
template <>
inline bool isElementOfType<const HTMLStyleElement>(const Node& node)
{
    return isHTMLStyleElement(node);
}
template <>
inline bool isElementOfType<const HTMLStyleElement>(const HTMLElement& element)
{
    return isHTMLStyleElement(element);
}

class HTMLBDIElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLBDIElement(const HTMLBDIElement&);
void isHTMLBDIElement(const HTMLBDIElement*);

inline bool isHTMLBDIElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::bdiTag);
}
inline bool isHTMLBDIElement(const HTMLElement* element)
{
    return element && isHTMLBDIElement(*element);
}
inline bool isHTMLBDIElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLBDIElement(toHTMLElement(node));
}
inline bool isHTMLBDIElement(const Node* node)
{
    return node && isHTMLBDIElement(*node);
}
template <>
inline bool isElementOfType<const HTMLBDIElement>(const Node& node)
{
    return isHTMLBDIElement(node);
}
template <>
inline bool isElementOfType<const HTMLBDIElement>(const HTMLElement& element)
{
    return isHTMLBDIElement(element);
}

class HTMLNoEmbedElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLNoEmbedElement(const HTMLNoEmbedElement&);
void isHTMLNoEmbedElement(const HTMLNoEmbedElement*);

inline bool isHTMLNoEmbedElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::noembedTag);
}
inline bool isHTMLNoEmbedElement(const HTMLElement* element)
{
    return element && isHTMLNoEmbedElement(*element);
}
inline bool isHTMLNoEmbedElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLNoEmbedElement(toHTMLElement(node));
}
inline bool isHTMLNoEmbedElement(const Node* node)
{
    return node && isHTMLNoEmbedElement(*node);
}
template <>
inline bool isElementOfType<const HTMLNoEmbedElement>(const Node& node)
{
    return isHTMLNoEmbedElement(node);
}
template <>
inline bool isElementOfType<const HTMLNoEmbedElement>(const HTMLElement& element)
{
    return isHTMLNoEmbedElement(element);
}

class HTMLNoScriptElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLNoScriptElement(const HTMLNoScriptElement&);
void isHTMLNoScriptElement(const HTMLNoScriptElement*);

inline bool isHTMLNoScriptElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::noscriptTag);
}
inline bool isHTMLNoScriptElement(const HTMLElement* element)
{
    return element && isHTMLNoScriptElement(*element);
}
inline bool isHTMLNoScriptElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLNoScriptElement(toHTMLElement(node));
}
inline bool isHTMLNoScriptElement(const Node* node)
{
    return node && isHTMLNoScriptElement(*node);
}
template <>
inline bool isElementOfType<const HTMLNoScriptElement>(const Node& node)
{
    return isHTMLNoScriptElement(node);
}
template <>
inline bool isElementOfType<const HTMLNoScriptElement>(const HTMLElement& element)
{
    return isHTMLNoScriptElement(element);
}

class HTMLRTElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLRTElement(const HTMLRTElement&);
void isHTMLRTElement(const HTMLRTElement*);

inline bool isHTMLRTElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::rtTag);
}
inline bool isHTMLRTElement(const HTMLElement* element)
{
    return element && isHTMLRTElement(*element);
}
inline bool isHTMLRTElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLRTElement(toHTMLElement(node));
}
inline bool isHTMLRTElement(const Node* node)
{
    return node && isHTMLRTElement(*node);
}
template <>
inline bool isElementOfType<const HTMLRTElement>(const Node& node)
{
    return isHTMLRTElement(node);
}
template <>
inline bool isElementOfType<const HTMLRTElement>(const HTMLElement& element)
{
    return isHTMLRTElement(element);
}

class HTMLRubyElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLRubyElement(const HTMLRubyElement&);
void isHTMLRubyElement(const HTMLRubyElement*);

inline bool isHTMLRubyElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::rubyTag);
}
inline bool isHTMLRubyElement(const HTMLElement* element)
{
    return element && isHTMLRubyElement(*element);
}
inline bool isHTMLRubyElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLRubyElement(toHTMLElement(node));
}
inline bool isHTMLRubyElement(const Node* node)
{
    return node && isHTMLRubyElement(*node);
}
template <>
inline bool isElementOfType<const HTMLRubyElement>(const Node& node)
{
    return isHTMLRubyElement(node);
}
template <>
inline bool isElementOfType<const HTMLRubyElement>(const HTMLElement& element)
{
    return isHTMLRubyElement(element);
}

class HTMLSummaryElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLSummaryElement(const HTMLSummaryElement&);
void isHTMLSummaryElement(const HTMLSummaryElement*);

inline bool isHTMLSummaryElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::summaryTag);
}
inline bool isHTMLSummaryElement(const HTMLElement* element)
{
    return element && isHTMLSummaryElement(*element);
}
inline bool isHTMLSummaryElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLSummaryElement(toHTMLElement(node));
}
inline bool isHTMLSummaryElement(const Node* node)
{
    return node && isHTMLSummaryElement(*node);
}
template <>
inline bool isElementOfType<const HTMLSummaryElement>(const Node& node)
{
    return isHTMLSummaryElement(node);
}
template <>
inline bool isElementOfType<const HTMLSummaryElement>(const HTMLElement& element)
{
    return isHTMLSummaryElement(element);
}

class HTMLWBRElement;
// Catch unnecessary runtime check of type known at compile time.
void isHTMLWBRElement(const HTMLWBRElement&);
void isHTMLWBRElement(const HTMLWBRElement*);

inline bool isHTMLWBRElement(const HTMLElement& element)
{
    return element.hasTagName(HTMLNames::wbrTag);
}
inline bool isHTMLWBRElement(const HTMLElement* element)
{
    return element && isHTMLWBRElement(*element);
}
inline bool isHTMLWBRElement(const Node& node)
{
    return node.isHTMLElement() && isHTMLWBRElement(toHTMLElement(node));
}
inline bool isHTMLWBRElement(const Node* node)
{
    return node && isHTMLWBRElement(*node);
}
template <>
inline bool isElementOfType<const HTMLWBRElement>(const Node& node)
{
    return isHTMLWBRElement(node);
}
template <>
inline bool isElementOfType<const HTMLWBRElement>(const HTMLElement& element)
{
    return isHTMLWBRElement(element);
}

// Using macros because the types are forward-declared and we don't want to use
// reinterpret_cast in the casting functions above. reinterpret_cast would be
// unsafe due to multiple inheritence.

#define toHTMLAnchorElement(x) blink::toElement<blink::HTMLAnchorElement>(x)
#define toHTMLAnchorElementOrDie(x) blink::toElementOrDie<blink::HTMLAnchorElement>(x)
#define toHTMLAreaElement(x) blink::toElement<blink::HTMLAreaElement>(x)
#define toHTMLAreaElementOrDie(x) blink::toElementOrDie<blink::HTMLAreaElement>(x)
#define toHTMLAudioElement(x) blink::toElement<blink::HTMLAudioElement>(x)
#define toHTMLAudioElementOrDie(x) blink::toElementOrDie<blink::HTMLAudioElement>(x)
#define toHTMLBRElement(x) blink::toElement<blink::HTMLBRElement>(x)
#define toHTMLBRElementOrDie(x) blink::toElementOrDie<blink::HTMLBRElement>(x)
#define toHTMLBaseElement(x) blink::toElement<blink::HTMLBaseElement>(x)
#define toHTMLBaseElementOrDie(x) blink::toElementOrDie<blink::HTMLBaseElement>(x)
#define toHTMLBodyElement(x) blink::toElement<blink::HTMLBodyElement>(x)
#define toHTMLBodyElementOrDie(x) blink::toElementOrDie<blink::HTMLBodyElement>(x)
#define toHTMLButtonElement(x) blink::toElement<blink::HTMLButtonElement>(x)
#define toHTMLButtonElementOrDie(x) blink::toElementOrDie<blink::HTMLButtonElement>(x)
#define toHTMLCanvasElement(x) blink::toElement<blink::HTMLCanvasElement>(x)
#define toHTMLCanvasElementOrDie(x) blink::toElementOrDie<blink::HTMLCanvasElement>(x)
#define toHTMLContentElement(x) blink::toElement<blink::HTMLContentElement>(x)
#define toHTMLContentElementOrDie(x) blink::toElementOrDie<blink::HTMLContentElement>(x)
#define toHTMLDListElement(x) blink::toElement<blink::HTMLDListElement>(x)
#define toHTMLDListElementOrDie(x) blink::toElementOrDie<blink::HTMLDListElement>(x)
#define toHTMLDataListElement(x) blink::toElement<blink::HTMLDataListElement>(x)
#define toHTMLDataListElementOrDie(x) blink::toElementOrDie<blink::HTMLDataListElement>(x)
#define toHTMLDetailsElement(x) blink::toElement<blink::HTMLDetailsElement>(x)
#define toHTMLDetailsElementOrDie(x) blink::toElementOrDie<blink::HTMLDetailsElement>(x)
#define toHTMLDialogElement(x) blink::toElement<blink::HTMLDialogElement>(x)
#define toHTMLDialogElementOrDie(x) blink::toElementOrDie<blink::HTMLDialogElement>(x)
#define toHTMLDirectoryElement(x) blink::toElement<blink::HTMLDirectoryElement>(x)
#define toHTMLDirectoryElementOrDie(x) blink::toElementOrDie<blink::HTMLDirectoryElement>(x)
#define toHTMLDivElement(x) blink::toElement<blink::HTMLDivElement>(x)
#define toHTMLDivElementOrDie(x) blink::toElementOrDie<blink::HTMLDivElement>(x)
#define toHTMLFieldSetElement(x) blink::toElement<blink::HTMLFieldSetElement>(x)
#define toHTMLFieldSetElementOrDie(x) blink::toElementOrDie<blink::HTMLFieldSetElement>(x)
#define toHTMLFontElement(x) blink::toElement<blink::HTMLFontElement>(x)
#define toHTMLFontElementOrDie(x) blink::toElementOrDie<blink::HTMLFontElement>(x)
#define toHTMLFormElement(x) blink::toElement<blink::HTMLFormElement>(x)
#define toHTMLFormElementOrDie(x) blink::toElementOrDie<blink::HTMLFormElement>(x)
#define toHTMLFrameElement(x) blink::toElement<blink::HTMLFrameElement>(x)
#define toHTMLFrameElementOrDie(x) blink::toElementOrDie<blink::HTMLFrameElement>(x)
#define toHTMLFrameSetElement(x) blink::toElement<blink::HTMLFrameSetElement>(x)
#define toHTMLFrameSetElementOrDie(x) blink::toElementOrDie<blink::HTMLFrameSetElement>(x)
#define toHTMLHRElement(x) blink::toElement<blink::HTMLHRElement>(x)
#define toHTMLHRElementOrDie(x) blink::toElementOrDie<blink::HTMLHRElement>(x)
#define toHTMLHeadElement(x) blink::toElement<blink::HTMLHeadElement>(x)
#define toHTMLHeadElementOrDie(x) blink::toElementOrDie<blink::HTMLHeadElement>(x)
#define toHTMLHtmlElement(x) blink::toElement<blink::HTMLHtmlElement>(x)
#define toHTMLHtmlElementOrDie(x) blink::toElementOrDie<blink::HTMLHtmlElement>(x)
#define toHTMLIFrameElement(x) blink::toElement<blink::HTMLIFrameElement>(x)
#define toHTMLIFrameElementOrDie(x) blink::toElementOrDie<blink::HTMLIFrameElement>(x)
#define toHTMLLIElement(x) blink::toElement<blink::HTMLLIElement>(x)
#define toHTMLLIElementOrDie(x) blink::toElementOrDie<blink::HTMLLIElement>(x)
#define toHTMLLabelElement(x) blink::toElement<blink::HTMLLabelElement>(x)
#define toHTMLLabelElementOrDie(x) blink::toElementOrDie<blink::HTMLLabelElement>(x)
#define toHTMLLegendElement(x) blink::toElement<blink::HTMLLegendElement>(x)
#define toHTMLLegendElementOrDie(x) blink::toElementOrDie<blink::HTMLLegendElement>(x)
#define toHTMLMapElement(x) blink::toElement<blink::HTMLMapElement>(x)
#define toHTMLMapElementOrDie(x) blink::toElementOrDie<blink::HTMLMapElement>(x)
#define toHTMLMarqueeElement(x) blink::toElement<blink::HTMLMarqueeElement>(x)
#define toHTMLMarqueeElementOrDie(x) blink::toElementOrDie<blink::HTMLMarqueeElement>(x)
#define toHTMLMenuElement(x) blink::toElement<blink::HTMLMenuElement>(x)
#define toHTMLMenuElementOrDie(x) blink::toElementOrDie<blink::HTMLMenuElement>(x)
#define toHTMLMenuItemElement(x) blink::toElement<blink::HTMLMenuItemElement>(x)
#define toHTMLMenuItemElementOrDie(x) blink::toElementOrDie<blink::HTMLMenuItemElement>(x)
#define toHTMLMetaElement(x) blink::toElement<blink::HTMLMetaElement>(x)
#define toHTMLMetaElementOrDie(x) blink::toElementOrDie<blink::HTMLMetaElement>(x)
#define toHTMLMeterElement(x) blink::toElement<blink::HTMLMeterElement>(x)
#define toHTMLMeterElementOrDie(x) blink::toElementOrDie<blink::HTMLMeterElement>(x)
#define toHTMLOListElement(x) blink::toElement<blink::HTMLOListElement>(x)
#define toHTMLOListElementOrDie(x) blink::toElementOrDie<blink::HTMLOListElement>(x)
#define toHTMLOptGroupElement(x) blink::toElement<blink::HTMLOptGroupElement>(x)
#define toHTMLOptGroupElementOrDie(x) blink::toElementOrDie<blink::HTMLOptGroupElement>(x)
#define toHTMLOptionElement(x) blink::toElement<blink::HTMLOptionElement>(x)
#define toHTMLOptionElementOrDie(x) blink::toElementOrDie<blink::HTMLOptionElement>(x)
#define toHTMLOutputElement(x) blink::toElement<blink::HTMLOutputElement>(x)
#define toHTMLOutputElementOrDie(x) blink::toElementOrDie<blink::HTMLOutputElement>(x)
#define toHTMLParagraphElement(x) blink::toElement<blink::HTMLParagraphElement>(x)
#define toHTMLParagraphElementOrDie(x) blink::toElementOrDie<blink::HTMLParagraphElement>(x)
#define toHTMLParamElement(x) blink::toElement<blink::HTMLParamElement>(x)
#define toHTMLParamElementOrDie(x) blink::toElementOrDie<blink::HTMLParamElement>(x)
#define toHTMLPictureElement(x) blink::toElement<blink::HTMLPictureElement>(x)
#define toHTMLPictureElementOrDie(x) blink::toElementOrDie<blink::HTMLPictureElement>(x)
#define toHTMLProgressElement(x) blink::toElement<blink::HTMLProgressElement>(x)
#define toHTMLProgressElementOrDie(x) blink::toElementOrDie<blink::HTMLProgressElement>(x)
#define toHTMLSelectElement(x) blink::toElement<blink::HTMLSelectElement>(x)
#define toHTMLSelectElementOrDie(x) blink::toElementOrDie<blink::HTMLSelectElement>(x)
#define toHTMLShadowElement(x) blink::toElement<blink::HTMLShadowElement>(x)
#define toHTMLShadowElementOrDie(x) blink::toElementOrDie<blink::HTMLShadowElement>(x)
#define toHTMLSlotElement(x) blink::toElement<blink::HTMLSlotElement>(x)
#define toHTMLSlotElementOrDie(x) blink::toElementOrDie<blink::HTMLSlotElement>(x)
#define toHTMLSourceElement(x) blink::toElement<blink::HTMLSourceElement>(x)
#define toHTMLSourceElementOrDie(x) blink::toElementOrDie<blink::HTMLSourceElement>(x)
#define toHTMLSpanElement(x) blink::toElement<blink::HTMLSpanElement>(x)
#define toHTMLSpanElementOrDie(x) blink::toElementOrDie<blink::HTMLSpanElement>(x)
#define toHTMLTableCaptionElement(x) blink::toElement<blink::HTMLTableCaptionElement>(x)
#define toHTMLTableCaptionElementOrDie(x) blink::toElementOrDie<blink::HTMLTableCaptionElement>(x)
#define toHTMLTableElement(x) blink::toElement<blink::HTMLTableElement>(x)
#define toHTMLTableElementOrDie(x) blink::toElementOrDie<blink::HTMLTableElement>(x)
#define toHTMLTableRowElement(x) blink::toElement<blink::HTMLTableRowElement>(x)
#define toHTMLTableRowElementOrDie(x) blink::toElementOrDie<blink::HTMLTableRowElement>(x)
#define toHTMLTemplateElement(x) blink::toElement<blink::HTMLTemplateElement>(x)
#define toHTMLTemplateElementOrDie(x) blink::toElementOrDie<blink::HTMLTemplateElement>(x)
#define toHTMLTextAreaElement(x) blink::toElement<blink::HTMLTextAreaElement>(x)
#define toHTMLTextAreaElementOrDie(x) blink::toElementOrDie<blink::HTMLTextAreaElement>(x)
#define toHTMLTitleElement(x) blink::toElement<blink::HTMLTitleElement>(x)
#define toHTMLTitleElementOrDie(x) blink::toElementOrDie<blink::HTMLTitleElement>(x)
#define toHTMLTrackElement(x) blink::toElement<blink::HTMLTrackElement>(x)
#define toHTMLTrackElementOrDie(x) blink::toElementOrDie<blink::HTMLTrackElement>(x)
#define toHTMLUListElement(x) blink::toElement<blink::HTMLUListElement>(x)
#define toHTMLUListElementOrDie(x) blink::toElementOrDie<blink::HTMLUListElement>(x)
#define toHTMLVideoElement(x) blink::toElement<blink::HTMLVideoElement>(x)
#define toHTMLVideoElementOrDie(x) blink::toElementOrDie<blink::HTMLVideoElement>(x)
#define toHTMLEmbedElement(x) blink::toElement<blink::HTMLEmbedElement>(x)
#define toHTMLEmbedElementOrDie(x) blink::toElementOrDie<blink::HTMLEmbedElement>(x)
#define toHTMLImageElement(x) blink::toElement<blink::HTMLImageElement>(x)
#define toHTMLImageElementOrDie(x) blink::toElementOrDie<blink::HTMLImageElement>(x)
#define toHTMLInputElement(x) blink::toElement<blink::HTMLInputElement>(x)
#define toHTMLInputElementOrDie(x) blink::toElementOrDie<blink::HTMLInputElement>(x)
#define toHTMLLinkElement(x) blink::toElement<blink::HTMLLinkElement>(x)
#define toHTMLLinkElementOrDie(x) blink::toElementOrDie<blink::HTMLLinkElement>(x)
#define toHTMLObjectElement(x) blink::toElement<blink::HTMLObjectElement>(x)
#define toHTMLObjectElementOrDie(x) blink::toElementOrDie<blink::HTMLObjectElement>(x)
#define toHTMLScriptElement(x) blink::toElement<blink::HTMLScriptElement>(x)
#define toHTMLScriptElementOrDie(x) blink::toElementOrDie<blink::HTMLScriptElement>(x)
#define toHTMLStyleElement(x) blink::toElement<blink::HTMLStyleElement>(x)
#define toHTMLStyleElementOrDie(x) blink::toElementOrDie<blink::HTMLStyleElement>(x)
#define toHTMLBDIElement(x) blink::toElement<blink::HTMLBDIElement>(x)
#define toHTMLBDIElementOrDie(x) blink::toElementOrDie<blink::HTMLBDIElement>(x)
#define toHTMLNoEmbedElement(x) blink::toElement<blink::HTMLNoEmbedElement>(x)
#define toHTMLNoEmbedElementOrDie(x) blink::toElementOrDie<blink::HTMLNoEmbedElement>(x)
#define toHTMLNoScriptElement(x) blink::toElement<blink::HTMLNoScriptElement>(x)
#define toHTMLNoScriptElementOrDie(x) blink::toElementOrDie<blink::HTMLNoScriptElement>(x)
#define toHTMLRTElement(x) blink::toElement<blink::HTMLRTElement>(x)
#define toHTMLRTElementOrDie(x) blink::toElementOrDie<blink::HTMLRTElement>(x)
#define toHTMLRubyElement(x) blink::toElement<blink::HTMLRubyElement>(x)
#define toHTMLRubyElementOrDie(x) blink::toElementOrDie<blink::HTMLRubyElement>(x)
#define toHTMLSummaryElement(x) blink::toElement<blink::HTMLSummaryElement>(x)
#define toHTMLSummaryElementOrDie(x) blink::toElementOrDie<blink::HTMLSummaryElement>(x)
#define toHTMLWBRElement(x) blink::toElement<blink::HTMLWBRElement>(x)
#define toHTMLWBRElementOrDie(x) blink::toElementOrDie<blink::HTMLWBRElement>(x)

enum class HTMLElementType {
    kHTMLAnchorElement,
    kHTMLAreaElement,
    kHTMLAudioElement,
    kHTMLBaseElement,
    kHTMLBDIElement,
    kHTMLBodyElement,
    kHTMLBRElement,
    kHTMLButtonElement,
    kHTMLCanvasElement,
    kHTMLContentElement,
    kHTMLDataListElement,
    kHTMLDetailsElement,
    kHTMLDialogElement,
    kHTMLDirectoryElement,
    kHTMLDivElement,
    kHTMLDListElement,
    kHTMLElement,
    kHTMLEmbedElement,
    kHTMLFieldSetElement,
    kHTMLFontElement,
    kHTMLFormElement,
    kHTMLFrameElement,
    kHTMLFrameSetElement,
    kHTMLHeadElement,
    kHTMLHeadingElement,
    kHTMLHRElement,
    kHTMLHtmlElement,
    kHTMLIFrameElement,
    kHTMLImageElement,
    kHTMLInputElement,
    kHTMLLabelElement,
    kHTMLLegendElement,
    kHTMLLIElement,
    kHTMLLinkElement,
    kHTMLMapElement,
    kHTMLMarqueeElement,
    kHTMLMenuElement,
    kHTMLMenuItemElement,
    kHTMLMetaElement,
    kHTMLMeterElement,
    kHTMLModElement,
    kHTMLNoEmbedElement,
    kHTMLNoScriptElement,
    kHTMLObjectElement,
    kHTMLOListElement,
    kHTMLOptGroupElement,
    kHTMLOptionElement,
    kHTMLOutputElement,
    kHTMLParagraphElement,
    kHTMLParamElement,
    kHTMLPictureElement,
    kHTMLPreElement,
    kHTMLProgressElement,
    kHTMLQuoteElement,
    kHTMLRTElement,
    kHTMLRubyElement,
    kHTMLScriptElement,
    kHTMLSelectElement,
    kHTMLShadowElement,
    kHTMLSlotElement,
    kHTMLSourceElement,
    kHTMLSpanElement,
    kHTMLStyleElement,
    kHTMLSummaryElement,
    kHTMLTableCaptionElement,
    kHTMLTableCellElement,
    kHTMLTableColElement,
    kHTMLTableElement,
    kHTMLTableRowElement,
    kHTMLTableSectionElement,
    kHTMLTemplateElement,
    kHTMLTextAreaElement,
    kHTMLTitleElement,
    kHTMLTrackElement,
    kHTMLUListElement,
    kHTMLUnknownElement,
    kHTMLVideoElement,
    kHTMLWBRElement,
};

// Tag checking.
// tagName is the local name for an html element in lowercase
// The corresponding HTMLElement type for the tag name will be returned
// Do NOT use this function with SVG tag names and SVGElements
// If tagName is an undefined html tag name HTMLUnknownElement is returned
HTMLElementType htmlElementTypeForTag(const AtomicString& tagName);

} // namespace blink

#endif
