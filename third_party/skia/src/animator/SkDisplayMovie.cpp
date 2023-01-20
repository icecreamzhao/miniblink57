
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkDisplayMovie.h"
#include "SkAnimateMaker.h"
#include "SkCanvas.h"
#include "SkPaint.h"

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDisplayMovie::fInfo[] = {
    SK_MEMBER(src, String)
};

#endif

DEFINE_GET_MEMBER(SkDisplayMovie);

<<<<<<< HEAD
SkDisplayMovie::SkDisplayMovie()
    : fDecodedSuccessfully(false)
    , fLoaded(false)
    , fMovieBuilt(false)
{
    fMovie.fMaker->fInMovie = true;
}

SkDisplayMovie::~SkDisplayMovie()
{
}

void SkDisplayMovie::buildMovie()
{
=======
SkDisplayMovie::SkDisplayMovie() : fDecodedSuccessfully(false), fLoaded(false), fMovieBuilt(false) {
    fMovie.fMaker->fInMovie = true;
}

SkDisplayMovie::~SkDisplayMovie() {
}

void SkDisplayMovie::buildMovie() {
>>>>>>> miniblink49
    if (fMovieBuilt)
        return;
    SkAnimateMaker* movieMaker = fMovie.fMaker;
    SkAnimateMaker* parentMaker = movieMaker->fParentMaker;
<<<<<<< HEAD
    if (src.size() == 0 || parentMaker == nullptr)
=======
    if (src.size() == 0 || parentMaker == NULL)
>>>>>>> miniblink49
        return;
    movieMaker->fPrefix.set(parentMaker->fPrefix);
    fDecodedSuccessfully = fMovie.fMaker->decodeURI(src.c_str());
    if (fDecodedSuccessfully == false) {

        if (movieMaker->getErrorCode() != SkXMLParserError::kNoError || movieMaker->getNativeCode() != -1) {
            movieMaker->setInnerError(parentMaker, src);
            parentMaker->setErrorCode(SkDisplayXMLParserError::kInMovie);
        } else {
            parentMaker->setErrorNoun(src);
            parentMaker->setErrorCode(SkDisplayXMLParserError::kMovieNameUnknownOrMissing);
        }
    }
    fMovieBuilt = true;
}

<<<<<<< HEAD
SkDisplayable* SkDisplayMovie::deepCopy(SkAnimateMaker* maker)
{
    SkDisplayMovie* copy = (SkDisplayMovie*)INHERITED::deepCopy(maker);
=======
SkDisplayable* SkDisplayMovie::deepCopy(SkAnimateMaker* maker) {
    SkDisplayMovie* copy = (SkDisplayMovie*) INHERITED::deepCopy(maker);
>>>>>>> miniblink49
    copy->fMovie.fMaker->fParentMaker = fMovie.fMaker->fParentMaker;
    copy->fMovie.fMaker->fHostEventSinkID = fMovie.fMaker->fHostEventSinkID;
    copy->fMovieBuilt = false;
    *fMovie.fMaker->fParentMaker->fMovies.append() = copy;
    return copy;
}

<<<<<<< HEAD
void SkDisplayMovie::dirty()
{
    buildMovie();
}

bool SkDisplayMovie::doEvent(SkDisplayEvent::Kind kind, SkEventState* state)
{
=======
void SkDisplayMovie::dirty() {
    buildMovie();
}

bool SkDisplayMovie::doEvent(SkDisplayEvent::Kind kind, SkEventState* state) {
>>>>>>> miniblink49
    if (fLoaded == false)
        return false;
    fMovie.fMaker->fEnableTime = fMovie.fMaker->fParentMaker->fEnableTime;
    return fMovie.fMaker->fEvents.doEvent(*fMovie.fMaker, kind, state);
}

<<<<<<< HEAD
bool SkDisplayMovie::draw(SkAnimateMaker& maker)
{
=======
bool SkDisplayMovie::draw(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    if (fDecodedSuccessfully == false)
        return false;
    if (fLoaded == false)
        enable(maker);
    maker.fCanvas->save();
    SkPaint local = SkPaint(*maker.fPaint);
    bool result = fMovie.draw(maker.fCanvas, &local,
<<<<<<< HEAD
                      maker.fDisplayList.getTime())
        != SkAnimator::kNotDifferent;
=======
        maker.fDisplayList.getTime()) != SkAnimator::kNotDifferent;
>>>>>>> miniblink49
    maker.fDisplayList.fInvalBounds.join(fMovie.fMaker->fDisplayList.fInvalBounds);
    maker.fCanvas->restore();
    return result;
}

#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
void SkDisplayMovie::dump(SkAnimateMaker* maker)
{
    dumpBase(maker);
    SkDebugf("src=\"%s\"/>\n", src.c_str());
=======
void SkDisplayMovie::dump(SkAnimateMaker* maker) {
    dumpBase(maker);
    SkDebugf("src=\"%s\"/>\n",  src.c_str());
>>>>>>> miniblink49
    SkAnimateMaker* movieMaker = fMovie.fMaker;
    SkDisplayList::fIndent += 4;
    movieMaker->fDisplayList.dumpInner(movieMaker);
    SkDisplayList::fIndent -= 4;
    dumpEnd(maker);
}

<<<<<<< HEAD
void SkDisplayMovie::dumpEvents()
{
=======
void SkDisplayMovie::dumpEvents() {
>>>>>>> miniblink49
    fMovie.fMaker->fEvents.dump(*fMovie.fMaker);
}
#endif

<<<<<<< HEAD
bool SkDisplayMovie::enable(SkAnimateMaker&)
{
    if (fDecodedSuccessfully == false)
        return false;
    SkAnimateMaker* movieMaker = fMovie.fMaker;
    movieMaker->fEvents.doEvent(*movieMaker, SkDisplayEvent::kOnload, nullptr);
    movieMaker->fEvents.removeEvent(SkDisplayEvent::kOnload, nullptr);
=======
bool SkDisplayMovie::enable(SkAnimateMaker&) {
    if (fDecodedSuccessfully == false)
        return false;
    SkAnimateMaker* movieMaker = fMovie.fMaker;
    movieMaker->fEvents.doEvent(*movieMaker, SkDisplayEvent::kOnload, NULL);
    movieMaker->fEvents.removeEvent(SkDisplayEvent::kOnload, NULL);
>>>>>>> miniblink49
    fLoaded = true;
    movieMaker->fLoaded = true;
    return false;
}

<<<<<<< HEAD
bool SkDisplayMovie::hasEnable() const
{
    return true;
}

void SkDisplayMovie::onEndElement(SkAnimateMaker& maker)
{
=======
bool SkDisplayMovie::hasEnable() const {
    return true;
}

void SkDisplayMovie::onEndElement(SkAnimateMaker& maker) {
>>>>>>> miniblink49
#if defined SK_DEBUG && defined SK_DEBUG_ANIMATION_TIMING
    fMovie.fMaker->fDebugTimeBase = maker.fDebugTimeBase;
#endif
    fMovie.fMaker->fPrefix.set(maker.fPrefix);
    fMovie.fMaker->fHostEventSinkID = maker.fHostEventSinkID;
    fMovie.fMaker->fParentMaker = &maker;
    buildMovie();
    *maker.fMovies.append() = this;
}
