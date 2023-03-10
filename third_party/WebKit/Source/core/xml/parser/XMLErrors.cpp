/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY GOOGLE INC. AND ITS CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL GOOGLE INC.
 * OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "core/xml/parser/XMLErrors.h"

#include "core/HTMLNames.h"
#include "core/SVGNames.h"
#include "core/dom/Document.h"
#include "core/dom/Element.h"
#include "core/dom/Text.h"
#include "core/xml/DocumentXSLT.h"
#include "wtf/text/WTFString.h"

namespace blink {

using namespace HTMLNames;

const int maxErrors = 25;

XMLErrors::XMLErrors(Document* document)
    : m_document(document)
    , m_errorCount(0)
    , m_lastErrorPosition(TextPosition::belowRangePosition())
{
}

DEFINE_TRACE(XMLErrors)
{
    visitor->trace(m_document);
}

void XMLErrors::handleError(ErrorType type,
    const char* message,
    int lineNumber,
    int columnNumber)
{
    handleError(type, message,
        TextPosition(OrdinalNumber::fromOneBasedInt(lineNumber),
            OrdinalNumber::fromOneBasedInt(columnNumber)));
}

void XMLErrors::handleError(ErrorType type,
    const char* message,
    TextPosition position)
{
    if (type == ErrorTypeFatal || (m_errorCount < maxErrors && m_lastErrorPosition.m_line != position.m_line && m_lastErrorPosition.m_column != position.m_column)) {
        switch (type) {
        case ErrorTypeWarning:
            appendErrorMessage("warning", position, message);
            break;
        case ErrorTypeFatal:
        case ErrorTypeNonFatal:
            appendErrorMessage("error", position, message);
        }

        m_lastErrorPosition = position;
        ++m_errorCount;
    }
}

void XMLErrors::appendErrorMessage(const String& typeString,
    TextPosition position,
    const char* message)
{
    // <typeString> on line <lineNumber> at column <columnNumber>: <message>
    m_errorMessages.append(typeString);
    m_errorMessages.append(" on line ");
    m_errorMessages.appendNumber(position.m_line.oneBasedInt());
    m_errorMessages.append(" at column ");
    m_errorMessages.appendNumber(position.m_column.oneBasedInt());
    m_errorMessages.append(": ");
    m_errorMessages.append(message);
}

static inline Element* createXHTMLParserErrorHeader(
    Document* doc,
    const String& errorMessages)
{
    Element* reportElement = doc->createElement(
        QualifiedName(nullAtom, "parsererror", xhtmlNamespaceURI),
        CreatedByParser);

    Vector<Attribute> reportAttributes;
    reportAttributes.push_back(Attribute(
        styleAttr,
        "display: block; white-space: pre; border: 2px solid #c77; padding: 0 "
        "1em 0 1em; margin: 1em; background-color: #fdd; color: black"));
    reportElement->parserSetAttributes(reportAttributes);

    Element* h3 = doc->createElement(h3Tag, CreatedByParser);
    reportElement->parserAppendChild(h3);
    h3->parserAppendChild(
        doc->createTextNode("This page contains the following errors:"));

    Element* fixed = doc->createElement(divTag, CreatedByParser);
    Vector<Attribute> fixedAttributes;
    fixedAttributes.push_back(
        Attribute(styleAttr, "font-family:monospace;font-size:12px"));
    fixed->parserSetAttributes(fixedAttributes);
    reportElement->parserAppendChild(fixed);

    fixed->parserAppendChild(doc->createTextNode(errorMessages));

    h3 = doc->createElement(h3Tag, CreatedByParser);
    reportElement->parserAppendChild(h3);
    h3->parserAppendChild(doc->createTextNode(
        "Below is a rendering of the page up to the first error."));

    return reportElement;
}

void XMLErrors::insertErrorMessageBlock()
{
    // One or more errors occurred during parsing of the code. Display an error
    // block to the user above the normal content (the DOM tree is created
    // manually and includes line/col info regarding where the errors are located)

    // Create elements for display
    Element* documentElement = m_document->documentElement();
    if (!documentElement) {
        Element* rootElement = m_document->createElement(htmlTag, CreatedByParser);
        Element* body = m_document->createElement(bodyTag, CreatedByParser);
        rootElement->parserAppendChild(body);
        m_document->parserAppendChild(rootElement);
        documentElement = body;
    } else if (documentElement->namespaceURI() == SVGNames::svgNamespaceURI) {
        Element* rootElement = m_document->createElement(htmlTag, CreatedByParser);
        Element* head = m_document->createElement(headTag, CreatedByParser);
        Element* style = m_document->createElement(styleTag, CreatedByParser);
        head->parserAppendChild(style);
        style->parserAppendChild(
            m_document->createTextNode("html, body { height: 100% } parsererror + "
                                       "svg { width: 100%; height: 100% }"));
        style->finishParsingChildren();
        rootElement->parserAppendChild(head);
        Element* body = m_document->createElement(bodyTag, CreatedByParser);
        rootElement->parserAppendChild(body);

        m_document->parserRemoveChild(*documentElement);

        body->parserAppendChild(documentElement);
        m_document->parserAppendChild(rootElement);

        documentElement = body;
    }

    String errorMessages = m_errorMessages.toString();
    Element* reportElement = createXHTMLParserErrorHeader(m_document, errorMessages);

    if (DocumentXSLT::hasTransformSourceDocument(*m_document)) {
        Vector<Attribute> attributes;
        attributes.push_back(Attribute(styleAttr, "white-space: normal"));
        Element* paragraph = m_document->createElement(pTag, CreatedByParser);
        paragraph->parserSetAttributes(attributes);
        paragraph->parserAppendChild(m_document->createTextNode(
            "This document was created as the result of an XSL transformation. The "
            "line and column numbers given are from the transformed result."));
        reportElement->parserAppendChild(paragraph);
    }

    Node* firstChild = documentElement->firstChild();
    if (firstChild)
        documentElement->parserInsertBefore(reportElement, *firstChild);
    else
        documentElement->parserAppendChild(reportElement);

    // FIXME: Why do we need to call this manually?
    m_document->updateStyleAndLayoutTree();
}

} // namespace blink
