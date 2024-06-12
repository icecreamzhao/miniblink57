/*
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
 *           (C) 2001 Dirk Mueller (mueller@kde.org)
 * Copyright (C) 2004, 2005, 2006, 2007, 2008 Apple Inc. All rights reserved.
 * Copyright (C) 2006 Samuel Weinig (sam@webkit.org)
 * Copyright (C) 2008, 2009 Torch Mobile Inc. All rights reserved.
 * (http://www.torchmobile.com/)
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

#include "core/dom/DOMImplementation.h"

#include "bindings/core/v8/ExceptionState.h"
#include "core/HTMLNames.h"
#include "core/SVGNames.h"
#if ENABLE_WML
#include "core/WMLNames.h"
#include "core/wml/WMLDocument.h"
#endif
#include "core/css/CSSStyleSheet.h"
#include "core/css/MediaList.h"
#include "core/css/StyleSheetContents.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/DocumentInit.h"
#include "core/dom/DocumentType.h"
#include "core/dom/Element.h"
#include "core/dom/Text.h"
#include "core/dom/XMLDocument.h"
#include "core/dom/custom/V0CustomElementRegistrationContext.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/UseCounter.h"
#include "core/html/HTMLDocument.h"
#include "core/html/HTMLHeadElement.h"
#include "core/html/HTMLMediaElement.h"
#include "core/html/HTMLTitleElement.h"
#include "core/html/HTMLViewSourceDocument.h"
#include "core/html/ImageDocument.h"
#include "core/html/MediaDocument.h"
#include "core/html/PluginDocument.h"
#include "core/html/TextDocument.h"
#include "core/loader/FrameLoader.h"
#include "core/page/Page.h"
#include "platform/graphics/Image.h"
#include "platform/network/mime/ContentType.h"
#include "platform/network/mime/MIMETypeRegistry.h"
#include "platform/plugins/PluginData.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "wtf/StdLibExtras.h"

namespace blink {

DOMImplementation::DOMImplementation(Document& document)
    : m_document(document)
{
}

DocumentType* DOMImplementation::createDocumentType(
    const AtomicString& qualifiedName,
    const String& publicId,
    const String& systemId,
    ExceptionState& exceptionState)
{
    AtomicString prefix, localName;
    if (!Document::parseQualifiedName(qualifiedName, prefix, localName,
            exceptionState))
        return nullptr;

    return DocumentType::create(m_document, qualifiedName, publicId, systemId);
}

XMLDocument* DOMImplementation::createDocument(
    const AtomicString& namespaceURI,
    const AtomicString& qualifiedName,
    DocumentType* doctype,
    ExceptionState& exceptionState)
{
    XMLDocument* doc = nullptr;
    DocumentInit init = DocumentInit::fromContext(document().contextDocument());
    if (namespaceURI == SVGNames::svgNamespaceURI) {
        doc = XMLDocument::createSVG(init);
    } else if (namespaceURI == HTMLNames::xhtmlNamespaceURI) {
        doc = XMLDocument::createXHTML(
            init.withRegistrationContext(document().registrationContext()));
#if ENABLE_WML
//     } else if (namespaceURI == WMLNames::wmlNamespaceURI) {
//         doc = WMLDocument::create(init);
#endif
    } else {
        doc = XMLDocument::create(init);
    }

    doc->setSecurityOrigin(document().getSecurityOrigin());
    doc->setContextFeatures(document().contextFeatures());

    Node* documentElement = nullptr;
    if (!qualifiedName.isEmpty()) {
        documentElement = doc->createElementNS(namespaceURI, qualifiedName, exceptionState);
        if (exceptionState.hadException())
            return nullptr;
    }

    if (doctype)
        doc->appendChild(doctype);
    if (documentElement)
        doc->appendChild(documentElement);

    return doc;
}

bool DOMImplementation::isXMLMIMEType(const String& mimeType)
{
    if (equalIgnoringCase(mimeType, "text/xml") || equalIgnoringCase(mimeType, "application/xml") ||
#if ENABLE(WML)
        equalIgnoringCase(mimeType, "text/vnd.wap.wml") || equalIgnoringCase(mimeType, "application/vnd.wap.wmlc") || equalIgnoringCase(mimeType, "application/vnd.wap.xhtml+xml") ||
#endif
        equalIgnoringCase(mimeType, "text/xsl"))
        return true;

    // Per RFCs 3023 and 2045, an XML MIME type is of the form:
    // ^[0-9a-zA-Z_\\-+~!$\\^{}|.%'`#&*]+/[0-9a-zA-Z_\\-+~!$\\^{}|.%'`#&*]+\+xml$

    int length = mimeType.length();
    if (length < 7)
        return false;

    if (mimeType[0] == '/' || mimeType[length - 5] == '/' || !mimeType.endsWith("+xml", TextCaseASCIIInsensitive))
        return false;

    bool hasSlash = false;
    for (int i = 0; i < length - 4; ++i) {
        UChar ch = mimeType[i];
        if (ch >= '0' && ch <= '9')
            continue;
        if (ch >= 'a' && ch <= 'z')
            continue;
        if (ch >= 'A' && ch <= 'Z')
            continue;
        switch (ch) {
        case '_':
        case '-':
        case '+':
        case '~':
        case '!':
        case '$':
        case '^':
        case '{':
        case '}':
        case '|':
        case '.':
        case '%':
        case '\'':
        case '`':
        case '#':
        case '&':
        case '*':
            continue;
        case '/':
            if (hasSlash)
                return false;
            hasSlash = true;
            continue;
        default:
            return false;
        }
    }

    return true;
}

bool DOMImplementation::isJSONMIMEType(const String& mimeType)
{
    if (mimeType.startsWith("application/json", TextCaseASCIIInsensitive))
        return true;
    if (mimeType.startsWith("application/", TextCaseASCIIInsensitive)) {
        size_t subtype = mimeType.find("+json", 12, TextCaseASCIIInsensitive);
        if (subtype != kNotFound) {
            // Just check that a parameter wasn't matched.
            size_t parameterMarker = mimeType.find(";");
            if (parameterMarker == kNotFound) {
                unsigned endSubtype = static_cast<unsigned>(subtype) + 5;
                return endSubtype == mimeType.length() || isASCIISpace(mimeType[endSubtype]);
            }
            return parameterMarker > subtype;
        }
    }
    return false;
}

static bool isTextPlainType(const String& mimeType)
{
    return mimeType.startsWith("text/", TextCaseASCIIInsensitive) && !(equalIgnoringCase(mimeType, "text/html") || equalIgnoringCase(mimeType, "text/xml") || equalIgnoringCase(mimeType, "text/xsl"));
}

bool DOMImplementation::isTextMIMEType(const String& mimeType)
{
    return MIMETypeRegistry::isSupportedJavaScriptMIMEType(mimeType) || isJSONMIMEType(mimeType) || isTextPlainType(mimeType);
}

HTMLDocument* DOMImplementation::createHTMLDocument(const String& title)
{
    DocumentInit init = DocumentInit::fromContext(document().contextDocument())
                            .withRegistrationContext(document().registrationContext());
    HTMLDocument* d = HTMLDocument::create(init);
    d->open();
    d->write("<!doctype html><html><head></head><body></body></html>");
    if (!title.isNull()) {
        HTMLHeadElement* headElement = d->head();
        DCHECK(headElement);
        HTMLTitleElement* titleElement = HTMLTitleElement::create(*d);
        headElement->appendChild(titleElement);
        titleElement->appendChild(d->createTextNode(title), ASSERT_NO_EXCEPTION);
    }
    d->setSecurityOrigin(document().getSecurityOrigin());
    d->setContextFeatures(document().contextFeatures());
    return d;
}

Document* DOMImplementation::createDocument(const String& type,
    const DocumentInit& init,
    bool inViewSourceMode)
{
    if (inViewSourceMode)
        return HTMLViewSourceDocument::create(init, type);

    // Plugins cannot take HTML and XHTML from us, and we don't even need to
    // initialize the plugin database for those.
    if (type == "text/html")
        return HTMLDocument::create(init);
    if (type == "application/xhtml+xml")
        return XMLDocument::createXHTML(init);

    PluginData* pluginData = nullptr;
    if (init.frame() && init.frame()->page() && init.frame()->loader().allowPlugins(NotAboutToInstantiatePlugin)) {
        // If the document is being created for the main frame,
        // init.frame()->tree().top()->securityContext() returns nullptr.
        // For that reason, the origin must be retrieved directly from init.url().
        if (init.frame()->isMainFrame()) {
            RefPtr<SecurityOrigin> origin = SecurityOrigin::create(init.url());
            pluginData = init.frame()->page()->pluginData(origin.get());
        } else {
            pluginData = init.frame()->page()->pluginData(
                init.frame()->tree().top()->securityContext()->getSecurityOrigin());
        }
    }

    // PDF is one image type for which a plugin can override built-in support.
    // We do not want QuickTime to take over all image types, obviously.
    if ((type == "application/pdf" || type == "text/pdf") && pluginData && pluginData->supportsMimeType(type))
        return PluginDocument::create(init);
    // multipart/x-mixed-replace is only supported for images.
    if (Image::supportsType(type) || type == "multipart/x-mixed-replace")
        return ImageDocument::create(init);

    // Check to see if the type can be played by our media player, if so create a
    // MediaDocument
    if (HTMLMediaElement::supportsType(ContentType(type)))
        return MediaDocument::create(init);

    // Everything else except text/plain can be overridden by plugins. In
    // particular, Adobe SVG Viewer should be used for SVG, if installed.
    // Disallowing plugins to use text/plain prevents plugins from hijacking a
    // fundamental type that the browser is expected to handle, and also serves as
    // an optimization to prevent loading the plugin database in the common case.
    if (type != "text/plain" && pluginData && pluginData->supportsMimeType(type))
        return PluginDocument::create(init);
#if ENABLE_WML
//     if (type == "text/vnd.wap.wml" || type == "application/vnd.wap.wmlc")
//         return WMLDocument::create(init);
#endif

    if (isTextMIMEType(type))
        return TextDocument::create(init);
    if (type == "image/svg+xml")
        return XMLDocument::createSVG(init);
    if (isXMLMIMEType(type))
        return XMLDocument::create(init);

    return HTMLDocument::create(init);
}

DEFINE_TRACE(DOMImplementation)
{
    visitor->trace(m_document);
}

} // namespace blink
