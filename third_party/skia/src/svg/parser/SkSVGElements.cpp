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
#include "SkSVGElements.h"
#include "SkSVGParser.h"

SkSVGBase::~SkSVGBase()
{
}

void SkSVGBase::addAttribute(SkSVGParser& parser, int attrIndex,
    const char* attrValue, size_t attrLength)
{
    SkString* first = (SkString*)((char*)this + sizeof(SkSVGElement));
=======

#include "SkSVGElements.h"
#include "SkSVGParser.h"

SkSVGBase::~SkSVGBase() {
}

void SkSVGBase::addAttribute(SkSVGParser& parser, int attrIndex,
        const char* attrValue, size_t attrLength) {
    SkString* first = (SkString*) ((char*) this + sizeof(SkSVGElement));
>>>>>>> miniblink49
    first += attrIndex;
    first->set(attrValue, attrLength);
}

<<<<<<< HEAD
SkSVGElement::SkSVGElement()
    : fParent(nullptr)
    , fIsDef(false)
    , fIsNotDef(true)
{
}

SkSVGElement::~SkSVGElement()
{
}

SkSVGElement* SkSVGElement::getGradient()
{
    return nullptr;
}

bool SkSVGElement::isGroupParent()
{
=======

SkSVGElement::SkSVGElement() : fParent(NULL), fIsDef(false), fIsNotDef(true) {
}

SkSVGElement::~SkSVGElement() {
}

SkSVGElement* SkSVGElement::getGradient() {
    return NULL;
}

bool SkSVGElement::isGroupParent() {
>>>>>>> miniblink49
    SkSVGElement* parent = fParent;
    while (parent) {
        if (parent->getType() != SkSVGType_G)
            return false;
        parent = parent->fParent;
    }
    return true;
}

<<<<<<< HEAD
bool SkSVGElement::isDef()
{
    return isGroupParent() == false ? fParent->isDef() : fIsDef;
}

bool SkSVGElement::isFlushable()
{
    return true;
}

bool SkSVGElement::isGroup()
{
    return false;
}

bool SkSVGElement::isNotDef()
{
    return isGroupParent() == false ? fParent->isNotDef() : fIsNotDef;
}

bool SkSVGElement::onEndElement(SkSVGParser& parser)
{
=======
bool SkSVGElement::isDef() {
    return isGroupParent() == false ? fParent->isDef() : fIsDef;
}

bool SkSVGElement::isFlushable() {
    return true;
}

bool SkSVGElement::isGroup() {
    return false;
}

bool SkSVGElement::isNotDef() {
    return isGroupParent() == false ? fParent->isNotDef() : fIsNotDef;
}

bool SkSVGElement::onEndElement(SkSVGParser& parser) {
>>>>>>> miniblink49
    if (f_id.size() > 0)
        parser.getIDs().set(f_id.c_str(), f_id.size(), this);
    return false;
}

<<<<<<< HEAD
bool SkSVGElement::onStartElement(SkSVGElement* child)
{
=======
bool SkSVGElement::onStartElement(SkSVGElement* child) {
>>>>>>> miniblink49
    *fChildren.append() = child;
    return false;
}

<<<<<<< HEAD
void SkSVGElement::translate(SkSVGParser& parser, bool)
{
=======
void SkSVGElement::translate(SkSVGParser& parser, bool) {
>>>>>>> miniblink49
    if (f_id.size() > 0)
        SVG_ADD_ATTRIBUTE(id);
}

<<<<<<< HEAD
void SkSVGElement::setIsDef()
{
=======
void SkSVGElement::setIsDef() {
>>>>>>> miniblink49
    fIsDef = isDef();
}

//void SkSVGElement::setIsNotDef() {
//  fIsNotDef = isNotDef();
//}

<<<<<<< HEAD
void SkSVGElement::write(SkSVGParser&, SkString&)
{
=======
void SkSVGElement::write(SkSVGParser& , SkString& ) {
>>>>>>> miniblink49
    SkASSERT(0);
}
