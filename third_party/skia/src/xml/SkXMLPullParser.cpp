<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkStream.h"
#include "SkXMLParser.h"
=======
#include "SkXMLParser.h"
#include "SkStream.h"
>>>>>>> miniblink49

static void reset(SkXMLPullParser::Curr* curr)
{
    curr->fEventType = SkXMLPullParser::ERROR;
    curr->fName = "";
    curr->fAttrInfoCount = 0;
    curr->fIsWhitespace = false;
}

<<<<<<< HEAD
SkXMLPullParser::SkXMLPullParser()
    : fStream(nullptr)
=======
SkXMLPullParser::SkXMLPullParser() : fStream(NULL)
>>>>>>> miniblink49
{
    fCurr.fEventType = ERROR;
    fDepth = -1;
}

<<<<<<< HEAD
SkXMLPullParser::SkXMLPullParser(SkStream* stream)
    : fStream(nullptr)
=======
SkXMLPullParser::SkXMLPullParser(SkStream* stream) : fStream(NULL)
>>>>>>> miniblink49
{
    fCurr.fEventType = ERROR;
    fDepth = 0;

    this->setStream(stream);
}

SkXMLPullParser::~SkXMLPullParser()
{
<<<<<<< HEAD
    this->setStream(nullptr);
=======
    this->setStream(NULL);
>>>>>>> miniblink49
}

SkStream* SkXMLPullParser::setStream(SkStream* stream)
{
    if (fStream && !stream)
        this->onExit();

    SkRefCnt_SafeAssign(fStream, stream);

<<<<<<< HEAD
    if (fStream) {
        fCurr.fEventType = START_DOCUMENT;
        this->onInit();
    } else {
=======
    if (fStream)
    {
        fCurr.fEventType = START_DOCUMENT;
        this->onInit();
    }
    else
    {
>>>>>>> miniblink49
        fCurr.fEventType = ERROR;
    }
    fDepth = 0;

    return fStream;
}

SkXMLPullParser::EventType SkXMLPullParser::nextToken()
{
    switch (fCurr.fEventType) {
    case ERROR:
    case END_DOCUMENT:
        break;
    case END_TAG:
        fDepth -= 1;
        // fall through
    default:
        reset(&fCurr);
        fCurr.fEventType = this->onNextToken();
        break;
    }

    switch (fCurr.fEventType) {
    case START_TAG:
        fDepth += 1;
        break;
    default:
        break;
    }

    return fCurr.fEventType;
}

const char* SkXMLPullParser::getName()
{
    switch (fCurr.fEventType) {
    case START_TAG:
    case END_TAG:
        return fCurr.fName;
    default:
<<<<<<< HEAD
        return nullptr;
=======
        return NULL;
>>>>>>> miniblink49
    }
}

const char* SkXMLPullParser::getText()
{
    switch (fCurr.fEventType) {
    case TEXT:
    case IGNORABLE_WHITESPACE:
        return fCurr.fName;
    default:
<<<<<<< HEAD
        return nullptr;
=======
        return NULL;
>>>>>>> miniblink49
    }
}

bool SkXMLPullParser::isWhitespace()
{
    switch (fCurr.fEventType) {
    case IGNORABLE_WHITESPACE:
        return true;
    case TEXT:
    case CDSECT:
        return fCurr.fIsWhitespace;
    default:
<<<<<<< HEAD
        return false; // unknown/illegal
=======
        return false;   // unknown/illegal
>>>>>>> miniblink49
    }
}

int SkXMLPullParser::getAttributeCount()
{
    return fCurr.fAttrInfoCount;
}

void SkXMLPullParser::getAttributeInfo(int index, AttrInfo* info)
{
    SkASSERT((unsigned)index < (unsigned)fCurr.fAttrInfoCount);

    if (info)
        *info = fCurr.fAttrInfos[index];
}

bool SkXMLPullParser::onEntityReplacement(const char name[],
<<<<<<< HEAD
    SkString* replacement)
=======
                                          SkString* replacement)
>>>>>>> miniblink49
{
    // TODO: std 5 entities here
    return false;
}
