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
#include "SkSVGParser.h"
#include "SkSVGCircle.h"
#include "SkSVGClipPath.h"
#include "SkSVGDefs.h"
#include "SkSVGEllipse.h"
#include "SkSVGFeColorMatrix.h"
#include "SkSVGFilter.h"
#include "SkSVGG.h"
#include "SkSVGImage.h"
#include "SkSVGLine.h"
#include "SkSVGLinearGradient.h"
#include "SkSVGMask.h"
#include "SkSVGMetadata.h"
#include "SkSVGPath.h"
#include "SkSVGPolygon.h"
#include "SkSVGPolyline.h"
#include "SkSVGRadialGradient.h"
#include "SkSVGRect.h"
#include "SkSVGSVG.h"
#include "SkSVGStop.h"
#include "SkSVGSymbol.h"
#include "SkSVGText.h"
#include "SkSVGUse.h"
#include "SkTSearch.h"
#include <stdio.h>

static int gGeneratedMatrixID = 0;

<<<<<<< HEAD
SkSVGParser::SkSVGParser(SkXMLParserError* errHandler)
    : SkXMLParser(errHandler)
    , fHead(&fEmptyPaint)
    , fIDs(256)
    , fXMLWriter(&fStream)
    , fCurrElement(nullptr)
    , fInSVG(false)
    , fSuppressPaint(false)
{
=======
SkSVGParser::SkSVGParser(SkXMLParserError* errHandler) :
    SkXMLParser(errHandler),
    fHead(&fEmptyPaint), fIDs(256),
        fXMLWriter(&fStream), fCurrElement(NULL), fInSVG(false), fSuppressPaint(false) {
>>>>>>> miniblink49
    fLastTransform.reset();
    fEmptyPaint.f_fill.set("black");
    fEmptyPaint.f_stroke.set("none");
    fEmptyPaint.f_strokeMiterlimit.set("4");
    fEmptyPaint.f_fillRule.set("winding");
    fEmptyPaint.f_opacity.set("1");
<<<<<<< HEAD
    fEmptyPaint.fNext = nullptr;
=======
    fEmptyPaint.fNext = NULL;
>>>>>>> miniblink49
    for (int index = SkSVGPaint::kInitial + 1; index < SkSVGPaint::kTerminal; index++) {
        SkString* initial = fEmptyPaint[index];
        if (initial->size() == 0)
            continue;
        fLastFlush[index]->set(*initial);
    }
}

<<<<<<< HEAD
SkSVGParser::~SkSVGParser()
{
}

void SkSVGParser::Delete(SkTDArray<SkSVGElement*>& fChildren)
{
=======
SkSVGParser::~SkSVGParser() {
}

void SkSVGParser::Delete(SkTDArray<SkSVGElement*>& fChildren) {
>>>>>>> miniblink49
    SkSVGElement** ptr;
    for (ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        Delete((*ptr)->fChildren);
        delete *ptr;
    }
}

int SkSVGParser::findAttribute(SkSVGBase* element, const char* attrValue,
<<<<<<< HEAD
    size_t len, bool isPaint)
{
=======
        size_t len, bool isPaint) {
>>>>>>> miniblink49
    const SkSVGAttribute* attributes;
    size_t count = element->getAttributes(&attributes);
    size_t result = 0;
    while (result < count) {
        if (strncmp(attributes->fName, attrValue, len) == 0 && strlen(attributes->fName) == len) {
<<<<<<< HEAD
            SkASSERT(result == (attributes->fOffset - (isPaint ? sizeof(SkString) : sizeof(SkSVGElement))) / sizeof(SkString));
=======
            SkASSERT(result == (attributes->fOffset -
                (isPaint ? sizeof(SkString) : sizeof(SkSVGElement))) / sizeof(SkString));
>>>>>>> miniblink49
            return result;
        }
        attributes++;
        result++;
    }
    return -1;
}

#if 0
const char* SkSVGParser::getFinal() {
    _startElement("screenplay");
    // generate defs
    SkSVGElement** ptr;
    for (ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkSVGElement* element = *ptr;
        translate(element, true);
    }
    // generate onLoad
    _startElement("event");
    _addAttribute("kind", "onLoad");
    _startElement("paint");
    _addAttribute("antiAlias", "true");
    _endElement();
    for (ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkSVGElement* element = *ptr;
        translate(element, false);
    }
    _endElement(); // event
    _endElement(); // screenplay
    Delete(fChildren);
    fStream.write("", 1);
    return fStream.getStream();
}
#endif

<<<<<<< HEAD
SkString& SkSVGParser::getPaintLast(SkSVGPaint::Field field)
{
=======
SkString& SkSVGParser::getPaintLast(SkSVGPaint::Field field) {
>>>>>>> miniblink49
    SkSVGPaint* state = fHead;
    do {
        SkString* attr = (*state)[field];
        SkASSERT(attr);
        if (attr->size() > 0)
            return *attr;
        state = state->fNext;
    } while (state);
    SkASSERT(0);
    SkASSERT(fEmptyPaint[field]);
    return *fEmptyPaint[field];
}

<<<<<<< HEAD
bool SkSVGParser::isStrokeAndFill(SkSVGPaint** strokeState, SkSVGPaint** fillState)
{
=======
bool SkSVGParser::isStrokeAndFill(  SkSVGPaint** strokeState, SkSVGPaint** fillState) {
>>>>>>> miniblink49
    SkSVGPaint* walking = fHead;
    bool stroke = false;
    bool fill = false;
    bool strokeSet = false;
    bool fillSet = false;
<<<<<<< HEAD
    while (walking != nullptr) {
=======
    while (walking != NULL) {
>>>>>>> miniblink49
        if (strokeSet == false && walking->f_stroke.size() > 0) {
            stroke = walking->f_stroke.equals("none") == false;
            *strokeState = walking;
            strokeSet = true;
        }
        if (fillSet == false && walking->f_fill.size() > 0) {
            fill = walking->f_fill.equals("none") == false;
            *fillState = walking;
            fillSet = true;
        }
        walking = walking->fNext;
    }
    return stroke && fill;
}

<<<<<<< HEAD
bool SkSVGParser::onAddAttribute(const char name[], const char value[])
{
    return onAddAttributeLen(name, value, strlen(value));
}

bool SkSVGParser::onAddAttributeLen(const char name[], const char value[], size_t len)
{
    if (fCurrElement == nullptr) // this signals we should ignore attributes for this element
=======
bool SkSVGParser::onAddAttribute(const char name[], const char value[]) {
    return onAddAttributeLen(name, value, strlen(value));
}

bool SkSVGParser::onAddAttributeLen(const char name[], const char value[], size_t len) {
    if (fCurrElement == NULL)    // this signals we should ignore attributes for this element
>>>>>>> miniblink49
        return true;
    if (fCurrElement->fIsDef == false && fCurrElement->fIsNotDef == false)
        return false; // also an ignored element
    size_t nameLen = strlen(name);
    int attrIndex = findAttribute(fCurrElement, name, nameLen, false);
    if (attrIndex == -1) {
        attrIndex = findAttribute(&fCurrElement->fPaintState, name, nameLen, true);
        if (attrIndex >= 0) {
            fCurrElement->fPaintState.addAttribute(*this, attrIndex, value, len);
            return false;
        }
        if (nameLen == 2 && strncmp("id", name, nameLen) == 0) {
            fCurrElement->f_id.set(value, len);
            return false;
        }
        if (strchr(name, ':') != 0) // part of a different namespace
            return false;
    }
    SkASSERT(attrIndex >= 0);
    fCurrElement->addAttribute(*this, attrIndex, value, len);
    return false;
}

<<<<<<< HEAD
bool SkSVGParser::onEndElement(const char elem[])
{
=======
bool SkSVGParser::onEndElement(const char elem[]) {
>>>>>>> miniblink49
    int parentIndex = fParents.count() - 1;
    if (parentIndex >= 0) {
        SkSVGElement* element = fParents[parentIndex];
        element->onEndElement(*this);
        fParents.remove(parentIndex);
    }
    return false;
}

<<<<<<< HEAD
bool SkSVGParser::onStartElement(const char name[])
{
    return onStartElementLen(name, strlen(name));
}

bool SkSVGParser::onStartElementLen(const char name[], size_t len)
{
=======
bool SkSVGParser::onStartElement(const char name[]) {
    return onStartElementLen(name, strlen(name));
}

bool SkSVGParser::onStartElementLen(const char name[], size_t len) {
>>>>>>> miniblink49
    if (strncmp(name, "svg", len) == 0) {
        fInSVG = true;
    } else if (fInSVG == false)
        return false;
    const char* nextColon = strchr(name, ':');
    if (nextColon && (size_t)(nextColon - name) < len)
        return false;
    SkSVGTypes type = GetType(name, len);
<<<<<<< HEAD
    //    SkASSERT(type >= 0);
    if (type < 0) {
        type = SkSVGType_G;
        //        return true;
    }
    SkSVGElement* parent = fParents.count() > 0 ? fParents.top() : nullptr;
=======
//    SkASSERT(type >= 0);
    if (type < 0) {
        type = SkSVGType_G;
//        return true;
    }
    SkSVGElement* parent = fParents.count() > 0 ? fParents.top() : NULL;
>>>>>>> miniblink49
    SkSVGElement* element = CreateElement(type, parent);
    bool result = false;
    if (parent) {
        element->fParent = parent;
        result = fParents.top()->onStartElement(element);
    } else
        *fChildren.append() = element;
    if (strncmp(name, "svg", len) != 0)
        *fParents.append() = element;
    fCurrElement = element;
    return result;
}

<<<<<<< HEAD
bool SkSVGParser::onText(const char text[], int len)
{
=======
bool SkSVGParser::onText(const char text[], int len) {
>>>>>>> miniblink49
    if (fInSVG == false)
        return false;
    SkSVGTypes type = fCurrElement->getType();
    if (type != SkSVGType_Text && type != SkSVGType_Tspan)
        return false;
<<<<<<< HEAD
    SkSVGText* textElement = (SkSVGText*)fCurrElement;
=======
    SkSVGText* textElement = (SkSVGText*) fCurrElement;
>>>>>>> miniblink49
    textElement->f_text.set(text, len);
    return false;
}

static int32_t strokeFillID = 0;

<<<<<<< HEAD
void SkSVGParser::translate(SkSVGElement* element, bool isDef)
{
    SkSVGPaint::Push(&fHead, &element->fPaintState);
    bool isFlushable = element->isFlushable();
    if ((element->fIsDef == false && element->fIsNotDef == false) || (element->fIsDef && isDef == false && element->fIsNotDef == false) || (element->fIsDef == false && isDef && element->fIsNotDef)) {
        isFlushable = false;
    }
    SkSVGPaint *strokeState = nullptr, *fillState = nullptr;
=======
void SkSVGParser::translate(SkSVGElement* element, bool isDef) {
    SkSVGPaint::Push(&fHead, &element->fPaintState);
    bool isFlushable = element->isFlushable();
    if ((element->fIsDef == false && element->fIsNotDef == false) ||
        (element->fIsDef && isDef == false && element->fIsNotDef == false) ||
        (element->fIsDef == false && isDef && element->fIsNotDef)) {
        isFlushable = false;
    }
    SkSVGPaint* strokeState = NULL, * fillState = NULL;
>>>>>>> miniblink49
    if (isFlushable)
        element->fPaintState.setSave(*this);
    if (isFlushable && isStrokeAndFill(&strokeState, &fillState)) {
        SkString& elementID = element->f_id;
        if (elementID.size() == 0) {
            elementID.set("sf");
            elementID.appendS32(++strokeFillID);
        }
        SkString saveStroke(strokeState->f_stroke);
        SkString saveFill(fillState->f_fill);
        strokeState->f_stroke.set("none");
        element->fPaintState.flush(*this, isFlushable, isDef);
        element->translate(*this, isDef);
        strokeState->f_stroke.set(saveStroke);
        fillState->f_fill.set("none");
        if (element->fPaintState.flush(*this, isFlushable, isDef)) {
            _startElement("add");
            _addAttributeLen("use", elementID.c_str(), elementID.size());
<<<<<<< HEAD
            _endElement(); // add
=======
            _endElement();  // add
>>>>>>> miniblink49
        }
        fillState->f_fill.set(saveFill);
    } else {
        element->fPaintState.flush(*this, isFlushable, isDef);
        if (isFlushable || element->isGroup())
            element->translate(*this, isDef);
    }
    SkSVGPaint::Pop(&fHead);
}

<<<<<<< HEAD
void SkSVGParser::translateMatrix(SkString& string, SkString* stringID)
{
=======
void SkSVGParser::translateMatrix(SkString& string, SkString* stringID) {
>>>>>>> miniblink49
    if (string.size() == 0)
        return;
    if (stringID->size() > 0) {
        _startElement("add");
        _addAttribute("use", stringID->c_str());
        _endElement(); // add
        return;
    }
    SkASSERT(strncmp(string.c_str(), "matrix", 6) == 0);
    ++gGeneratedMatrixID;
    _startElement("matrix");
    char idStr[24];
    strcpy(idStr, "sk_matrix");
    sprintf(idStr + strlen(idStr), "%d", gGeneratedMatrixID);
    _addAttribute("id", idStr);
    stringID->set(idStr);
    const char* str = string.c_str();
    SkASSERT(strncmp(str, "matrix(", 7) == 0);
    str += 6;
    const char* strEnd = strrchr(str, ')');
<<<<<<< HEAD
    SkASSERT(strEnd != nullptr);
    SkString mat(str, strEnd - str);
    ConvertToArray(mat);
    const char* elems[6];
    static const int order[] = { 0, 3, 1, 4, 2, 5 };
=======
    SkASSERT(strEnd != NULL);
    SkString mat(str, strEnd - str);
    ConvertToArray(mat);
    const char* elems[6];
    static const int order[] = {0, 3, 1, 4, 2, 5};
>>>>>>> miniblink49
    const int* orderPtr = order;
    str = mat.c_str();
    strEnd = str + mat.size();
    while (str < strEnd) {
        elems[*orderPtr++] = str;
<<<<<<< HEAD
        while (str < strEnd && *str != ',')
=======
        while (str < strEnd && *str != ',' )
>>>>>>> miniblink49
            str++;
        str++;
    }
    string.reset();
    for (int index = 0; index < 6; index++) {
        const char* end = strchr(elems[index], ',');
<<<<<<< HEAD
        if (end == nullptr)
            end = strchr(elems[index], ']');
=======
        if (end == NULL)
            end= strchr(elems[index], ']');
>>>>>>> miniblink49
        string.append(elems[index], end - elems[index] + 1);
    }
    string.remove(string.size() - 1, 1);
    string.append(",0,0,1]");
    _addAttribute("matrix", string);
<<<<<<< HEAD
    _endElement(); // matrix
}

static bool is_whitespace(char ch)
{
    return ch > 0 && ch <= ' ';
}

void SkSVGParser::ConvertToArray(SkString& vals)
{
    vals.appendUnichar(']');
    char* valCh = (char*)vals.c_str();
=======
    _endElement();  // matrix
}

static bool is_whitespace(char ch) {
    return ch > 0 && ch <= ' ';
}

void SkSVGParser::ConvertToArray(SkString& vals) {
    vals.appendUnichar(']');
    char* valCh = (char*) vals.c_str();
>>>>>>> miniblink49
    valCh[0] = '[';
    int index = 1;
    while (valCh[index] != ']') {
        while (is_whitespace(valCh[index]))
            index++;
        bool foundComma = false;
        char next;
        do {
            next = valCh[index++];
            if (next == ',') {
                foundComma = true;
                continue;
            }
            if (next == ']') {
                index--;
                goto undoLastComma;
            }
            if (next == ' ')
                break;
            foundComma = false;
        } while (is_whitespace(next) == false);
        if (foundComma == false)
            valCh[index - 1] = ',';
    }
undoLastComma:
    while (is_whitespace(valCh[--index]))
        ;
    if (valCh[index] == ',')
        valCh[index] = ' ';
}

<<<<<<< HEAD
#define CASE_NEW(type)               \
    case SkSVGType_##type:           \
        created = new SkSVG##type(); \
        break

SkSVGElement* SkSVGParser::CreateElement(SkSVGTypes type, SkSVGElement* parent)
{
    SkSVGElement* created = nullptr;
=======
#define CASE_NEW(type) case SkSVGType_##type : created = new SkSVG##type(); break

SkSVGElement* SkSVGParser::CreateElement(SkSVGTypes type, SkSVGElement* parent) {
    SkSVGElement* created = NULL;
>>>>>>> miniblink49
    switch (type) {
        CASE_NEW(Circle);
        CASE_NEW(ClipPath);
        CASE_NEW(Defs);
        CASE_NEW(Ellipse);
        CASE_NEW(FeColorMatrix);
        CASE_NEW(Filter);
        CASE_NEW(G);
        CASE_NEW(Image);
        CASE_NEW(Line);
        CASE_NEW(LinearGradient);
        CASE_NEW(Mask);
        CASE_NEW(Metadata);
        CASE_NEW(Path);
        CASE_NEW(Polygon);
        CASE_NEW(Polyline);
        CASE_NEW(RadialGradient);
        CASE_NEW(Rect);
        CASE_NEW(Stop);
        CASE_NEW(SVG);
        CASE_NEW(Symbol);
        CASE_NEW(Text);
        CASE_NEW(Tspan);
        CASE_NEW(Use);
<<<<<<< HEAD
    default:
        SkASSERT(0);
        return nullptr;
=======
        default:
            SkASSERT(0);
            return NULL;
>>>>>>> miniblink49
    }
    created->fParent = parent;
    bool isDef = created->fIsDef = created->isDef();
    bool isNotDef = created->fIsNotDef = created->isNotDef();
    if (isDef) {
        SkSVGElement* up = parent;
        while (up && up->fIsDef == false) {
            up->fIsDef = true;
            up = up->fParent;
        }
    }
    if (isNotDef) {
        SkSVGElement* up = parent;
        while (up && up->fIsNotDef == false) {
            up->fIsNotDef = true;
            up = up->fParent;
        }
    }
    return created;
}

const SkSVGTypeName gSVGTypeNames[] = {
<<<<<<< HEAD
    { "circle", SkSVGType_Circle },
    { "clipPath", SkSVGType_ClipPath },
    { "defs", SkSVGType_Defs },
    { "ellipse", SkSVGType_Ellipse },
    { "feColorMatrix", SkSVGType_FeColorMatrix },
    { "filter", SkSVGType_Filter },
    { "g", SkSVGType_G },
    { "image", SkSVGType_Image },
    { "line", SkSVGType_Line },
    { "linearGradient", SkSVGType_LinearGradient },
    { "mask", SkSVGType_Mask },
    { "metadata", SkSVGType_Metadata },
    { "path", SkSVGType_Path },
    { "polygon", SkSVGType_Polygon },
    { "polyline", SkSVGType_Polyline },
    { "radialGradient", SkSVGType_RadialGradient },
    { "rect", SkSVGType_Rect },
    { "stop", SkSVGType_Stop },
    { "svg", SkSVGType_SVG },
    { "symbol", SkSVGType_Symbol },
    { "text", SkSVGType_Text },
    { "tspan", SkSVGType_Tspan },
    { "use", SkSVGType_Use }
=======
    {"circle", SkSVGType_Circle},
    {"clipPath", SkSVGType_ClipPath},
    {"defs", SkSVGType_Defs},
    {"ellipse", SkSVGType_Ellipse},
    {"feColorMatrix", SkSVGType_FeColorMatrix},
    {"filter", SkSVGType_Filter},
    {"g", SkSVGType_G},
    {"image", SkSVGType_Image},
    {"line", SkSVGType_Line},
    {"linearGradient", SkSVGType_LinearGradient},
    {"mask", SkSVGType_Mask},
    {"metadata", SkSVGType_Metadata},
    {"path", SkSVGType_Path},
    {"polygon", SkSVGType_Polygon},
    {"polyline", SkSVGType_Polyline},
    {"radialGradient", SkSVGType_RadialGradient},
    {"rect", SkSVGType_Rect},
    {"stop", SkSVGType_Stop},
    {"svg", SkSVGType_SVG},
    {"symbol", SkSVGType_Symbol},
    {"text", SkSVGType_Text},
    {"tspan", SkSVGType_Tspan},
    {"use", SkSVGType_Use}
>>>>>>> miniblink49
};

const int kSVGTypeNamesSize = SK_ARRAY_COUNT(gSVGTypeNames);

<<<<<<< HEAD
SkSVGTypes SkSVGParser::GetType(const char match[], size_t len)
{
    int index = SkStrSearch(&gSVGTypeNames[0].fName, kSVGTypeNamesSize, match,
        len, sizeof(gSVGTypeNames[0]));
    return index >= 0 && index < kSVGTypeNamesSize ? gSVGTypeNames[index].fType : (SkSVGTypes)-1;
=======
SkSVGTypes SkSVGParser::GetType(const char match[], size_t len ) {
    int index = SkStrSearch(&gSVGTypeNames[0].fName, kSVGTypeNamesSize, match,
        len, sizeof(gSVGTypeNames[0]));
    return index >= 0 && index < kSVGTypeNamesSize ? gSVGTypeNames[index].fType :
        (SkSVGTypes) -1;
>>>>>>> miniblink49
}
