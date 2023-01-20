
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkDOM_DEFINED
#define SkDOM_DEFINED

#include "../private/SkTemplates.h"
#include "SkChunkAlloc.h"
#include "SkScalar.h"
=======

#ifndef SkDOM_DEFINED
#define SkDOM_DEFINED

#include "SkChunkAlloc.h"
#include "SkScalar.h"
#include "SkTemplates.h"
>>>>>>> miniblink49

struct SkDOMNode;
struct SkDOMAttr;

class SkDOMParser;
class SkXMLParser;

class SkDOM {
public:
    SkDOM();
    ~SkDOM();

    typedef SkDOMNode Node;
    typedef SkDOMAttr Attr;

    /** Returns null on failure
    */
    const Node* build(const char doc[], size_t len);
    const Node* copy(const SkDOM& dom, const Node* node);

    const Node* getRootNode() const;

    SkXMLParser* beginParsing();
    const Node* finishParsing();

    enum Type {
        kElement_Type,
        kText_Type
    };
<<<<<<< HEAD
    Type getType(const Node*) const;
=======
    Type    getType(const Node*) const;
>>>>>>> miniblink49

    const char* getName(const Node*) const;
    const Node* getFirstChild(const Node*, const char elem[] = NULL) const;
    const Node* getNextSibling(const Node*, const char elem[] = NULL) const;

    const char* findAttr(const Node*, const char attrName[]) const;
    const Attr* getFirstAttr(const Node*) const;
    const Attr* getNextAttr(const Node*, const Attr*) const;
    const char* getAttrName(const Node*, const Attr*) const;
    const char* getAttrValue(const Node*, const Attr*) const;

    // helpers for walking children
    int countChildren(const Node* node, const char elem[] = NULL) const;

    // helpers for calling SkParse
    bool findS32(const Node*, const char name[], int32_t* value) const;
    bool findScalars(const Node*, const char name[], SkScalar value[], int count) const;
    bool findHex(const Node*, const char name[], uint32_t* value) const;
    bool findBool(const Node*, const char name[], bool*) const;
<<<<<<< HEAD
    int findList(const Node*, const char name[], const char list[]) const;
=======
    int  findList(const Node*, const char name[], const char list[]) const;
>>>>>>> miniblink49

    bool findScalar(const Node* node, const char name[], SkScalar value[]) const
    {
        return this->findScalars(node, name, value, 1);
    }

    bool hasAttr(const Node*, const char name[], const char value[]) const;
    bool hasS32(const Node*, const char name[], int32_t value) const;
    bool hasScalar(const Node*, const char name[], SkScalar value) const;
    bool hasHex(const Node*, const char name[], uint32_t value) const;
    bool hasBool(const Node*, const char name[], bool value) const;

    class AttrIter {
    public:
        AttrIter(const class SkDOM&, const Node*);
        const char* next(const char** value);
<<<<<<< HEAD

=======
>>>>>>> miniblink49
    private:
        const Attr* fAttr;
        const Attr* fStop;
    };

    SkDEBUGCODE(void dump(const Node* node = NULL, int tabLevel = 0) const;)
<<<<<<< HEAD
        SkDEBUGCODE(static void UnitTest();)

            private : SkChunkAlloc fAlloc;
    Node* fRoot;
=======
    SkDEBUGCODE(static void UnitTest();)

private:
    SkChunkAlloc               fAlloc;
    Node*                      fRoot;
>>>>>>> miniblink49
    SkAutoTDelete<SkDOMParser> fParser;

    friend class AttrIter;
    friend class SkDOMParser;
};

#endif
