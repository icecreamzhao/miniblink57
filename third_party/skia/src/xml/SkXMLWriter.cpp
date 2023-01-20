/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkXMLWriter.h"
#include "SkStream.h"

<<<<<<< HEAD
SkXMLWriter::SkXMLWriter(bool doEscapeMarkup)
    : fDoEscapeMarkup(doEscapeMarkup)
=======
SkXMLWriter::SkXMLWriter(bool doEscapeMarkup) : fDoEscapeMarkup(doEscapeMarkup)
>>>>>>> miniblink49
{
}

SkXMLWriter::~SkXMLWriter()
{
    SkASSERT(fElems.count() == 0);
}

void SkXMLWriter::flush()
{
    while (fElems.count())
        this->endElement();
}

void SkXMLWriter::addAttribute(const char name[], const char value[])
{
    this->addAttributeLen(name, value, strlen(value));
}

void SkXMLWriter::addS32Attribute(const char name[], int32_t value)
{
<<<<<<< HEAD
    SkString tmp;
=======
    SkString    tmp;
>>>>>>> miniblink49
    tmp.appendS32(value);
    this->addAttribute(name, tmp.c_str());
}

void SkXMLWriter::addHexAttribute(const char name[], uint32_t value, int minDigits)
{
<<<<<<< HEAD
    SkString tmp("0x");
=======
    SkString    tmp("0x");
>>>>>>> miniblink49
    tmp.appendHex(value, minDigits);
    this->addAttribute(name, tmp.c_str());
}

void SkXMLWriter::addScalarAttribute(const char name[], SkScalar value)
{
<<<<<<< HEAD
    SkString tmp;
=======
    SkString    tmp;
>>>>>>> miniblink49
    tmp.appendScalar(value);
    this->addAttribute(name, tmp.c_str());
}

<<<<<<< HEAD
void SkXMLWriter::addText(const char text[], size_t length)
{
    if (fElems.isEmpty()) {
        return;
    }

    this->onAddText(text, length);

=======
void SkXMLWriter::addText(const char text[], size_t length) {
    if (fElems.isEmpty()) {
        return;
    }
    
    this->onAddText(text, length);
    
>>>>>>> miniblink49
    fElems.top()->fHasText = true;
}

void SkXMLWriter::doEnd(Elem* elem)
{
    delete elem;
}

bool SkXMLWriter::doStart(const char name[], size_t length)
{
    int level = fElems.count();
<<<<<<< HEAD
    bool firstChild = level > 0 && !fElems[level - 1]->fHasChildren;
    if (firstChild)
        fElems[level - 1]->fHasChildren = true;
=======
    bool firstChild = level > 0 && !fElems[level-1]->fHasChildren;
    if (firstChild)
        fElems[level-1]->fHasChildren = true;
>>>>>>> miniblink49
    Elem** elem = fElems.push();
    *elem = new Elem(name, length);
    return firstChild;
}

SkXMLWriter::Elem* SkXMLWriter::getEnd()
{
    Elem* elem;
    fElems.pop(&elem);
    return elem;
}

const char* SkXMLWriter::getHeader()
{
    static const char gHeader[] = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>";
    return gHeader;
}

void SkXMLWriter::startElement(const char name[])
{
    this->startElementLen(name, strlen(name));
}

static const char* escape_char(char c, char storage[2])
{
    static const char* gEscapeChars[] = {
        "<&lt;",
        ">&gt;",
        //"\"&quot;",
        //"'&apos;",
        "&&amp;"
    };

    const char** array = gEscapeChars;
<<<<<<< HEAD
    for (unsigned i = 0; i < SK_ARRAY_COUNT(gEscapeChars); i++) {
=======
    for (unsigned i = 0; i < SK_ARRAY_COUNT(gEscapeChars); i++)
    {
>>>>>>> miniblink49
        if (array[i][0] == c)
            return &array[i][1];
    }
    storage[0] = c;
    storage[1] = 0;
    return storage;
}

static size_t escape_markup(char dst[], const char src[], size_t length)
{
<<<<<<< HEAD
    size_t extra = 0;
    const char* stop = src + length;

    while (src < stop) {
        char orig[2];
        const char* seq = escape_char(*src, orig);
        size_t seqSize = strlen(seq);

        if (dst) {
=======
    size_t      extra = 0;
    const char* stop = src + length;

    while (src < stop)
    {
        char        orig[2];
        const char* seq = escape_char(*src, orig);
        size_t      seqSize = strlen(seq);

        if (dst)
        {
>>>>>>> miniblink49
            memcpy(dst, seq, seqSize);
            dst += seqSize;
        }

        // now record the extra size needed
<<<<<<< HEAD
        extra += seqSize - 1; // minus one to subtract the original char
=======
        extra += seqSize - 1;   // minus one to subtract the original char
>>>>>>> miniblink49

        // bump to the next src char
        src += 1;
    }
    return extra;
}

void SkXMLWriter::addAttributeLen(const char name[], const char value[], size_t length)
{
    SkString valueStr;

<<<<<<< HEAD
    if (fDoEscapeMarkup) {
        size_t extra = escape_markup(nullptr, value, length);
        if (extra) {
=======
    if (fDoEscapeMarkup)
    {
        size_t   extra = escape_markup(NULL, value, length);
        if (extra)
        {
>>>>>>> miniblink49
            valueStr.resize(length + extra);
            (void)escape_markup(valueStr.writable_str(), value, length);
            value = valueStr.c_str();
            length += extra;
        }
    }
    this->onAddAttributeLen(name, value, length);
}

void SkXMLWriter::startElementLen(const char elem[], size_t length)
{
    this->onStartElementLen(elem, length);
}

////////////////////////////////////////////////////////////////////////////////////////

static void write_dom(const SkDOM& dom, const SkDOM::Node* node, SkXMLWriter* w, bool skipRoot)
{
<<<<<<< HEAD
    if (!skipRoot) {
=======
    if (!skipRoot)
    {
>>>>>>> miniblink49
        const char* elem = dom.getName(node);
        if (dom.getType(node) == SkDOM::kText_Type) {
            SkASSERT(dom.countChildren(node) == 0);
            w->addText(elem, strlen(elem));
            return;
        }

        w->startElement(elem);

        SkDOM::AttrIter iter(dom, node);
        const char* name;
        const char* value;
<<<<<<< HEAD
        while ((name = iter.next(&value)) != nullptr)
            w->addAttribute(name, value);
    }

    node = dom.getFirstChild(node, nullptr);
    while (node) {
        write_dom(dom, node, w, false);
        node = dom.getNextSibling(node, nullptr);
=======
        while ((name = iter.next(&value)) != NULL)
            w->addAttribute(name, value);
    }

    node = dom.getFirstChild(node, NULL);
    while (node)
    {
        write_dom(dom, node, w, false);
        node = dom.getNextSibling(node, NULL);
>>>>>>> miniblink49
    }

    if (!skipRoot)
        w->endElement();
}

void SkXMLWriter::writeDOM(const SkDOM& dom, const SkDOM::Node* node, bool skipRoot)
{
    if (node)
        write_dom(dom, node, this, skipRoot);
}

void SkXMLWriter::writeHeader()
{
}

// SkXMLStreamWriter

static void tab(SkWStream& stream, int level)
{
    for (int i = 0; i < level; i++)
        stream.writeText("\t");
}

<<<<<<< HEAD
SkXMLStreamWriter::SkXMLStreamWriter(SkWStream* stream)
    : fStream(*stream)
=======
SkXMLStreamWriter::SkXMLStreamWriter(SkWStream* stream) : fStream(*stream)
>>>>>>> miniblink49
{
}

SkXMLStreamWriter::~SkXMLStreamWriter()
{
    this->flush();
}

void SkXMLStreamWriter::onAddAttributeLen(const char name[], const char value[], size_t length)
{
    SkASSERT(!fElems.top()->fHasChildren && !fElems.top()->fHasText);
    fStream.writeText(" ");
    fStream.writeText(name);
    fStream.writeText("=\"");
    fStream.write(value, length);
    fStream.writeText("\"");
}

<<<<<<< HEAD
void SkXMLStreamWriter::onAddText(const char text[], size_t length)
{
=======
void SkXMLStreamWriter::onAddText(const char text[], size_t length) {
>>>>>>> miniblink49
    Elem* elem = fElems.top();

    if (!elem->fHasChildren && !elem->fHasText) {
        fStream.writeText(">");
        fStream.newline();
    }

    tab(fStream, fElems.count() + 1);
    fStream.write(text, length);
    fStream.newline();
}

void SkXMLStreamWriter::onEndElement()
{
    Elem* elem = getEnd();
<<<<<<< HEAD
    if (elem->fHasChildren || elem->fHasText) {
=======
    if (elem->fHasChildren || elem->fHasText)
    {
>>>>>>> miniblink49
        tab(fStream, fElems.count());
        fStream.writeText("</");
        fStream.writeText(elem->fName.c_str());
        fStream.writeText(">");
    } else {
        fStream.writeText("/>");
    }
    fStream.newline();
    doEnd(elem);
}

void SkXMLStreamWriter::onStartElementLen(const char name[], size_t length)
{
    int level = fElems.count();
<<<<<<< HEAD
    if (this->doStart(name, length)) {
=======
    if (this->doStart(name, length))
    {
>>>>>>> miniblink49
        // the first child, need to close with >
        fStream.writeText(">");
        fStream.newline();
    }

    tab(fStream, level);
    fStream.writeText("<");
    fStream.write(name, length);
}

void SkXMLStreamWriter::writeHeader()
{
    const char* header = getHeader();
    fStream.write(header, strlen(header));
    fStream.newline();
}

////////////////////////////////////////////////////////////////////////////////////////////////

#include "SkXMLParser.h"

SkXMLParserWriter::SkXMLParserWriter(SkXMLParser* parser)
<<<<<<< HEAD
    : SkXMLWriter(false)
    , fParser(*parser)
=======
    : SkXMLWriter(false), fParser(*parser)
>>>>>>> miniblink49
{
}

SkXMLParserWriter::~SkXMLParserWriter()
{
    this->flush();
}

void SkXMLParserWriter::onAddAttributeLen(const char name[], const char value[], size_t length)
{
    SkASSERT(fElems.count() == 0 || (!fElems.top()->fHasChildren && !fElems.top()->fHasText));
    SkString str(value, length);
    fParser.addAttribute(name, str.c_str());
}

<<<<<<< HEAD
void SkXMLParserWriter::onAddText(const char text[], size_t length)
{
=======
void SkXMLParserWriter::onAddText(const char text[], size_t length) {
>>>>>>> miniblink49
    fParser.text(text, SkToInt(length));
}

void SkXMLParserWriter::onEndElement()
{
    Elem* elem = this->getEnd();
    fParser.endElement(elem->fName.c_str());
    this->doEnd(elem);
}

void SkXMLParserWriter::onStartElementLen(const char name[], size_t length)
{
    (void)this->doStart(name, length);
    SkString str(name, length);
    fParser.startElement(str.c_str());
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

#ifdef SK_DEBUG

void SkXMLStreamWriter::UnitTest()
{
#ifdef SK_SUPPORT_UNITTEST
<<<<<<< HEAD
    SkDebugWStream s;
    SkXMLStreamWriter w(&s);
=======
    SkDebugWStream  s;
    SkXMLStreamWriter       w(&s);
>>>>>>> miniblink49

    w.startElement("elem0");
    w.addAttribute("hello", "world");
    w.addS32Attribute("dec", 42);
    w.addHexAttribute("hex", 0x42, 3);
    w.addScalarAttribute("scalar", -4.2f);
    w.startElement("elem1");
<<<<<<< HEAD
    w.endElement();
    w.startElement("elem1");
    w.addAttribute("name", "value");
    w.endElement();
    w.startElement("elem1");
    w.startElement("elem2");
    w.startElement("elem3");
    w.addAttribute("name", "value");
    w.endElement();
    w.endElement();
    w.startElement("elem2");
    w.endElement();
    w.endElement();
=======
        w.endElement();
        w.startElement("elem1");
        w.addAttribute("name", "value");
        w.endElement();
        w.startElement("elem1");
            w.startElement("elem2");
                w.startElement("elem3");
                w.addAttribute("name", "value");
                w.endElement();
            w.endElement();
            w.startElement("elem2");
            w.endElement();
        w.endElement();
>>>>>>> miniblink49
    w.endElement();
#endif
}

#endif
