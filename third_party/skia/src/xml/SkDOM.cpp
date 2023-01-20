<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkDOM.h"
#include "SkStream.h"
#include "SkXMLWriter.h"

/////////////////////////////////////////////////////////////////////////

#include "SkXMLParser.h"
bool SkXMLParser::parse(const SkDOM& dom, const SkDOMNode* node)
{
    const char* elemName = dom.getName(node);

    if (this->startElement(elemName))
        return false;

    SkDOM::AttrIter iter(dom, node);
<<<<<<< HEAD
    const char *name, *value;

    while ((name = iter.next(&value)) != nullptr)
        if (this->addAttribute(name, value))
            return false;

    if ((node = dom.getFirstChild(node)) != nullptr)
        do {
            if (!this->parse(dom, node))
                return false;
        } while ((node = dom.getNextSibling(node)) != nullptr);
=======
    const char*     name, *value;

    while ((name = iter.next(&value)) != NULL)
        if (this->addAttribute(name, value))
            return false;

    if ((node = dom.getFirstChild(node)) != NULL)
        do {
            if (!this->parse(dom, node))
                return false;
        } while ((node = dom.getNextSibling(node)) != NULL);
>>>>>>> miniblink49

    return !this->endElement(elemName);
}

/////////////////////////////////////////////////////////////////////////

struct SkDOMAttr {
    const char* fName;
    const char* fValue;
};

struct SkDOMNode {
    const char* fName;
<<<<<<< HEAD
    SkDOMNode* fFirstChild;
    SkDOMNode* fNextSibling;
    uint16_t fAttrCount;
    uint8_t fType;
    uint8_t fPad;
=======
    SkDOMNode*  fFirstChild;
    SkDOMNode*  fNextSibling;
    uint16_t    fAttrCount;
    uint8_t     fType;
    uint8_t     fPad;
>>>>>>> miniblink49

    const SkDOMAttr* attrs() const
    {
        return (const SkDOMAttr*)(this + 1);
    }
    SkDOMAttr* attrs()
    {
        return (SkDOMAttr*)(this + 1);
    }
};

/////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#define kMinChunkSize 512

SkDOM::SkDOM()
    : fAlloc(kMinChunkSize)
    , fRoot(nullptr)
=======
#define kMinChunkSize   512

SkDOM::SkDOM() : fAlloc(kMinChunkSize), fRoot(NULL)
>>>>>>> miniblink49
{
}

SkDOM::~SkDOM()
{
}

const SkDOM::Node* SkDOM::getRootNode() const
{
    return fRoot;
}

const SkDOM::Node* SkDOM::getFirstChild(const Node* node, const char name[]) const
{
    SkASSERT(node);
    const Node* child = node->fFirstChild;

<<<<<<< HEAD
    if (name) {
        for (; child != nullptr; child = child->fNextSibling)
=======
    if (name)
    {
        for (; child != NULL; child = child->fNextSibling)
>>>>>>> miniblink49
            if (!strcmp(name, child->fName))
                break;
    }
    return child;
}

const SkDOM::Node* SkDOM::getNextSibling(const Node* node, const char name[]) const
{
    SkASSERT(node);
    const Node* sibling = node->fNextSibling;
<<<<<<< HEAD
    if (name) {
        for (; sibling != nullptr; sibling = sibling->fNextSibling)
=======
    if (name)
    {
        for (; sibling != NULL; sibling = sibling->fNextSibling)
>>>>>>> miniblink49
            if (!strcmp(name, sibling->fName))
                break;
    }
    return sibling;
}

SkDOM::Type SkDOM::getType(const Node* node) const
{
    SkASSERT(node);
    return (Type)node->fType;
}

const char* SkDOM::getName(const Node* node) const
{
    SkASSERT(node);
    return node->fName;
}

const char* SkDOM::findAttr(const Node* node, const char name[]) const
{
    SkASSERT(node);
    const Attr* attr = node->attrs();
    const Attr* stop = attr + node->fAttrCount;

<<<<<<< HEAD
    while (attr < stop) {
=======
    while (attr < stop)
    {
>>>>>>> miniblink49
        if (!strcmp(attr->fName, name))
            return attr->fValue;
        attr += 1;
    }
<<<<<<< HEAD
    return nullptr;
=======
    return NULL;
>>>>>>> miniblink49
}

/////////////////////////////////////////////////////////////////////////////////////

const SkDOM::Attr* SkDOM::getFirstAttr(const Node* node) const
{
<<<<<<< HEAD
    return node->fAttrCount ? node->attrs() : nullptr;
=======
    return node->fAttrCount ? node->attrs() : NULL;
>>>>>>> miniblink49
}

const SkDOM::Attr* SkDOM::getNextAttr(const Node* node, const Attr* attr) const
{
    SkASSERT(node);
<<<<<<< HEAD
    if (attr == nullptr)
        return nullptr;
    return (attr - node->attrs() + 1) < node->fAttrCount ? attr + 1 : nullptr;
=======
    if (attr == NULL)
        return NULL;
    return (attr - node->attrs() + 1) < node->fAttrCount ? attr + 1 : NULL;
>>>>>>> miniblink49
}

const char* SkDOM::getAttrName(const Node* node, const Attr* attr) const
{
    SkASSERT(node);
    SkASSERT(attr);
    return attr->fName;
}

const char* SkDOM::getAttrValue(const Node* node, const Attr* attr) const
{
    SkASSERT(node);
    SkASSERT(attr);
    return attr->fValue;
}

/////////////////////////////////////////////////////////////////////////////////////

SkDOM::AttrIter::AttrIter(const SkDOM&, const SkDOM::Node* node)
{
    SkASSERT(node);
    fAttr = node->attrs();
    fStop = fAttr + node->fAttrCount;
}

const char* SkDOM::AttrIter::next(const char** value)
{
<<<<<<< HEAD
    const char* name = nullptr;

    if (fAttr < fStop) {
=======
    const char* name = NULL;

    if (fAttr < fStop)
    {
>>>>>>> miniblink49
        name = fAttr->fName;
        if (value)
            *value = fAttr->fValue;
        fAttr += 1;
    }
    return name;
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#include "SkTDArray.h"
#include "SkXMLParser.h"
=======
#include "SkXMLParser.h"
#include "SkTDArray.h"
>>>>>>> miniblink49

static char* dupstr(SkChunkAlloc* chunk, const char src[])
{
    SkASSERT(chunk && src);
<<<<<<< HEAD
    size_t len = strlen(src);
    char* dst = (char*)chunk->alloc(len + 1, SkChunkAlloc::kThrow_AllocFailType);
=======
    size_t  len = strlen(src);
    char*   dst = (char*)chunk->alloc(len + 1, SkChunkAlloc::kThrow_AllocFailType);
>>>>>>> miniblink49
    memcpy(dst, src, len + 1);
    return dst;
}

class SkDOMParser : public SkXMLParser {
public:
<<<<<<< HEAD
    SkDOMParser(SkChunkAlloc* chunk)
        : SkXMLParser(&fParserError)
        , fAlloc(chunk)
    {
        fAlloc->reset();
        fRoot = nullptr;
=======
    SkDOMParser(SkChunkAlloc* chunk) : SkXMLParser(&fParserError), fAlloc(chunk)
    {
        fAlloc->reset();
        fRoot = NULL;
>>>>>>> miniblink49
        fLevel = 0;
        fNeedToFlush = true;
    }
    SkDOM::Node* getRoot() const { return fRoot; }
    SkXMLParserError fParserError;

protected:
    void flushAttributes()
    {
        SkASSERT(fLevel > 0);

        int attrCount = fAttrs.count();

        SkDOM::Node* node = (SkDOM::Node*)fAlloc->alloc(sizeof(SkDOM::Node) + attrCount * sizeof(SkDOM::Attr),
<<<<<<< HEAD
            SkChunkAlloc::kThrow_AllocFailType);

        node->fName = fElemName;
        node->fFirstChild = nullptr;
        node->fAttrCount = SkToU16(attrCount);
        node->fType = fElemType;

        if (fRoot == nullptr) {
            node->fNextSibling = nullptr;
            fRoot = node;
        } else // this adds siblings in reverse order. gets corrected in onEndElement()
=======
                                                        SkChunkAlloc::kThrow_AllocFailType);

        node->fName = fElemName;
        node->fFirstChild = NULL;
        node->fAttrCount = SkToU16(attrCount);
        node->fType = fElemType;

        if (fRoot == NULL)
        {
            node->fNextSibling = NULL;
            fRoot = node;
        }
        else    // this adds siblings in reverse order. gets corrected in onEndElement()
>>>>>>> miniblink49
        {
            SkDOM::Node* parent = fParentStack.top();
            SkASSERT(fRoot && parent);
            node->fNextSibling = parent->fFirstChild;
            parent->fFirstChild = node;
        }
        *fParentStack.push() = node;

<<<<<<< HEAD
        sk_careful_memcpy(node->attrs(), fAttrs.begin(), attrCount * sizeof(SkDOM::Attr));
        fAttrs.reset();
    }

    bool onStartElement(const char elem[]) override
    {
=======
        memcpy(node->attrs(), fAttrs.begin(), attrCount * sizeof(SkDOM::Attr));
        fAttrs.reset();

    }

    bool onStartElement(const char elem[]) override {
>>>>>>> miniblink49
        this->startCommon(elem, SkDOM::kElement_Type);
        return false;
    }

<<<<<<< HEAD
    bool onAddAttribute(const char name[], const char value[]) override
    {
=======
    bool onAddAttribute(const char name[], const char value[]) override {
>>>>>>> miniblink49
        SkDOM::Attr* attr = fAttrs.append();
        attr->fName = dupstr(fAlloc, name);
        attr->fValue = dupstr(fAlloc, value);
        return false;
    }

<<<<<<< HEAD
    bool onEndElement(const char elem[]) override
    {
=======
    bool onEndElement(const char elem[]) override {
>>>>>>> miniblink49
        --fLevel;
        if (fNeedToFlush)
            this->flushAttributes();
        fNeedToFlush = false;

        SkDOM::Node* parent;

        fParentStack.pop(&parent);

        SkDOM::Node* child = parent->fFirstChild;
<<<<<<< HEAD
        SkDOM::Node* prev = nullptr;
        while (child) {
=======
        SkDOM::Node* prev = NULL;
        while (child)
        {
>>>>>>> miniblink49
            SkDOM::Node* next = child->fNextSibling;
            child->fNextSibling = prev;
            prev = child;
            child = next;
        }
        parent->fFirstChild = prev;
        return false;
    }

<<<<<<< HEAD
    bool onText(const char text[], int len) override
    {
=======
    bool onText(const char text[], int len) override {
>>>>>>> miniblink49
        SkString str(text, len);
        this->startCommon(str.c_str(), SkDOM::kText_Type);
        this->SkDOMParser::onEndElement(str.c_str());

        return false;
    }

private:
<<<<<<< HEAD
    void startCommon(const char elem[], SkDOM::Type type)
    {
=======
    void startCommon(const char elem[], SkDOM::Type type) {
>>>>>>> miniblink49
        if (fLevel > 0 && fNeedToFlush)
            this->flushAttributes();

        fNeedToFlush = true;
        fElemName = dupstr(fAlloc, elem);
        fElemType = type;
        ++fLevel;
    }

    SkTDArray<SkDOM::Node*> fParentStack;
<<<<<<< HEAD
    SkChunkAlloc* fAlloc;
    SkDOM::Node* fRoot;
    bool fNeedToFlush;

    // state needed for flushAttributes()
    SkTDArray<SkDOM::Attr> fAttrs;
    char* fElemName;
    SkDOM::Type fElemType;
    int fLevel;
=======
    SkChunkAlloc*           fAlloc;
    SkDOM::Node*            fRoot;
    bool                    fNeedToFlush;

    // state needed for flushAttributes()
    SkTDArray<SkDOM::Attr>  fAttrs;
    char*                   fElemName;
    SkDOM::Type             fElemType;
    int                     fLevel;
>>>>>>> miniblink49
};

const SkDOM::Node* SkDOM::build(const char doc[], size_t len)
{
    SkDOMParser parser(&fAlloc);
<<<<<<< HEAD
    if (!parser.parse(doc, len)) {
        SkDEBUGCODE(SkDebugf("xml parse error, line %d\n", parser.fParserError.getLineNumber());)
            fRoot
            = nullptr;
        fAlloc.reset();
        return nullptr;
=======
    if (!parser.parse(doc, len))
    {
        SkDEBUGCODE(SkDebugf("xml parse error, line %d\n", parser.fParserError.getLineNumber());)
        fRoot = NULL;
        fAlloc.reset();
        return NULL;
>>>>>>> miniblink49
    }
    fRoot = parser.getRoot();
    return fRoot;
}

///////////////////////////////////////////////////////////////////////////

static void walk_dom(const SkDOM& dom, const SkDOM::Node* node, SkXMLParser* parser)
{
    const char* elem = dom.getName(node);
    if (dom.getType(node) == SkDOM::kText_Type) {
        SkASSERT(dom.countChildren(node) == 0);
        parser->text(elem, SkToInt(strlen(elem)));
        return;
    }

    parser->startElement(elem);

    SkDOM::AttrIter iter(dom, node);
<<<<<<< HEAD
    const char* name;
    const char* value;
    while ((name = iter.next(&value)) != nullptr)
        parser->addAttribute(name, value);

    node = dom.getFirstChild(node, nullptr);
    while (node) {
        walk_dom(dom, node, parser);
        node = dom.getNextSibling(node, nullptr);
=======
    const char*     name;
    const char*     value;
    while ((name = iter.next(&value)) != NULL)
        parser->addAttribute(name, value);

    node = dom.getFirstChild(node, NULL);
    while (node)
    {
        walk_dom(dom, node, parser);
        node = dom.getNextSibling(node, NULL);
>>>>>>> miniblink49
    }

    parser->endElement(elem);
}

const SkDOM::Node* SkDOM::copy(const SkDOM& dom, const SkDOM::Node* node)
{
    SkDOMParser parser(&fAlloc);

    walk_dom(dom, node, &parser);

    fRoot = parser.getRoot();
    return fRoot;
}

<<<<<<< HEAD
SkXMLParser* SkDOM::beginParsing()
{
    SkASSERT(!fParser);
    fParser.reset(new SkDOMParser(&fAlloc));
=======
SkXMLParser* SkDOM::beginParsing() {
    SkASSERT(!fParser);
    fParser.reset(SkNEW_ARGS(SkDOMParser, (&fAlloc)));
>>>>>>> miniblink49

    return fParser.get();
}

<<<<<<< HEAD
const SkDOM::Node* SkDOM::finishParsing()
{
    SkASSERT(fParser);
    fRoot = fParser->getRoot();
    fParser.reset();
=======
const SkDOM::Node* SkDOM::finishParsing() {
    SkASSERT(fParser);
    fRoot = fParser->getRoot();
    fParser.free();
>>>>>>> miniblink49

    return fRoot;
}

//////////////////////////////////////////////////////////////////////////

int SkDOM::countChildren(const Node* node, const char elem[]) const
{
    int count = 0;

    node = this->getFirstChild(node, elem);
<<<<<<< HEAD
    while (node) {
=======
    while (node)
    {
>>>>>>> miniblink49
        count += 1;
        node = this->getNextSibling(node, elem);
    }
    return count;
}

//////////////////////////////////////////////////////////////////////////

#include "SkParse.h"

bool SkDOM::findS32(const Node* node, const char name[], int32_t* value) const
{
    const char* vstr = this->findAttr(node, name);
    return vstr && SkParse::FindS32(vstr, value);
}

bool SkDOM::findScalars(const Node* node, const char name[], SkScalar value[], int count) const
{
    const char* vstr = this->findAttr(node, name);
    return vstr && SkParse::FindScalars(vstr, value, count);
}

bool SkDOM::findHex(const Node* node, const char name[], uint32_t* value) const
{
    const char* vstr = this->findAttr(node, name);
    return vstr && SkParse::FindHex(vstr, value);
}

bool SkDOM::findBool(const Node* node, const char name[], bool* value) const
{
    const char* vstr = this->findAttr(node, name);
    return vstr && SkParse::FindBool(vstr, value);
}

int SkDOM::findList(const Node* node, const char name[], const char list[]) const
{
    const char* vstr = this->findAttr(node, name);
    return vstr ? SkParse::FindList(vstr, list) : -1;
}

bool SkDOM::hasAttr(const Node* node, const char name[], const char value[]) const
{
    const char* vstr = this->findAttr(node, name);
    return vstr && !strcmp(vstr, value);
}

bool SkDOM::hasS32(const Node* node, const char name[], int32_t target) const
{
    const char* vstr = this->findAttr(node, name);
<<<<<<< HEAD
    int32_t value;
=======
    int32_t     value;
>>>>>>> miniblink49
    return vstr && SkParse::FindS32(vstr, &value) && value == target;
}

bool SkDOM::hasScalar(const Node* node, const char name[], SkScalar target) const
{
    const char* vstr = this->findAttr(node, name);
<<<<<<< HEAD
    SkScalar value;
=======
    SkScalar    value;
>>>>>>> miniblink49
    return vstr && SkParse::FindScalar(vstr, &value) && value == target;
}

bool SkDOM::hasHex(const Node* node, const char name[], uint32_t target) const
{
    const char* vstr = this->findAttr(node, name);
<<<<<<< HEAD
    uint32_t value;
=======
    uint32_t    value;
>>>>>>> miniblink49
    return vstr && SkParse::FindHex(vstr, &value) && value == target;
}

bool SkDOM::hasBool(const Node* node, const char name[], bool target) const
{
    const char* vstr = this->findAttr(node, name);
<<<<<<< HEAD
    bool value;
=======
    bool        value;
>>>>>>> miniblink49
    return vstr && SkParse::FindBool(vstr, &value) && value == target;
}

//////////////////////////////////////////////////////////////////////////

#ifdef SK_DEBUG

void SkDOM::dump(const Node* node, int level) const
{
<<<<<<< HEAD
    if (node == nullptr)
=======
    if (node == NULL)
>>>>>>> miniblink49
        node = this->getRootNode();

    SkDebugWStream debugStream;
    SkXMLStreamWriter xmlWriter(&debugStream);
    xmlWriter.writeDOM(*this, node, false);
}

void SkDOM::UnitTest()
{
#ifdef SK_SUPPORT_UNITTEST
<<<<<<< HEAD
    static const char gDoc[] = "<root a='1' b='2'>"
                               "<elem1 c='3' />"
                               "<elem2 d='4' />"
                               "<elem3 e='5'>"
                               "<subelem1/>"
                               "<subelem2 f='6' g='7'/>"
                               "</elem3>"
                               "<elem4 h='8'/>"
                               "</root>";

    SkDOM dom;

    SkASSERT(dom.getRootNode() == nullptr);
=======
    static const char gDoc[] =
        "<root a='1' b='2'>"
            "<elem1 c='3' />"
            "<elem2 d='4' />"
            "<elem3 e='5'>"
                "<subelem1/>"
                "<subelem2 f='6' g='7'/>"
            "</elem3>"
            "<elem4 h='8'/>"
        "</root>"
        ;

    SkDOM   dom;

    SkASSERT(dom.getRootNode() == NULL);
>>>>>>> miniblink49

    const Node* root = dom.build(gDoc, sizeof(gDoc) - 1);
    SkASSERT(root && dom.getRootNode() == root);

    const char* v = dom.findAttr(root, "a");
    SkASSERT(v && !strcmp(v, "1"));
    v = dom.findAttr(root, "b");
    SkASSERT(v && !strcmp(v, "2"));
    v = dom.findAttr(root, "c");
<<<<<<< HEAD
    SkASSERT(v == nullptr);
=======
    SkASSERT(v == NULL);
>>>>>>> miniblink49

    SkASSERT(dom.getFirstChild(root, "elem1"));
    SkASSERT(!dom.getFirstChild(root, "subelem1"));

    dom.dump();
#endif
}

#endif
