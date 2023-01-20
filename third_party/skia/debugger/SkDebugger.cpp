
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkDebugger.h"
#include "SkPictureRecorder.h"
#include "SkString.h"

<<<<<<< HEAD
SkDebugger::SkDebugger()
    : fPicture(nullptr)
    , fIndex(-1)
{
=======

SkDebugger::SkDebugger()
    : fPicture(NULL)
    , fIndex(-1) {
>>>>>>> miniblink49
    // Create this some other dynamic way?
    fDebugCanvas = new SkDebugCanvas(0, 0);
}

<<<<<<< HEAD
SkDebugger::~SkDebugger()
{
=======
SkDebugger::~SkDebugger() {
>>>>>>> miniblink49
    // Need to inherit from SkRef object in order for following to work
    SkSafeUnref(fDebugCanvas);
    SkSafeUnref(fPicture);
}

<<<<<<< HEAD
void SkDebugger::loadPicture(SkPicture* picture)
{
    SkRefCnt_SafeAssign(fPicture, picture);

    delete fDebugCanvas;
    fDebugCanvas = new SkDebugCanvas(SkScalarCeilToInt(this->pictureCull().width()),
        SkScalarCeilToInt(this->pictureCull().height()));
    fDebugCanvas->setPicture(picture);
    picture->playback(fDebugCanvas);
    fDebugCanvas->setPicture(nullptr);
    fIndex = fDebugCanvas->getSize() - 1;
}

sk_sp<SkPicture> SkDebugger::copyPicture()
{
    // We can't just call clone here since we want to removed the "deleted"
    // commands. Playing back will strip those out.
    SkPictureRecorder recorder;
    SkCanvas* canvas = recorder.beginRecording(this->pictureCull().width(),
        this->pictureCull().height());
=======
void SkDebugger::loadPicture(SkPicture* picture) {
    SkRefCnt_SafeAssign(fPicture, picture);

    delete fDebugCanvas;
    fDebugCanvas = new SkDebugCanvas(SkScalarCeilToInt(this->pictureCull().width()), 
                                     SkScalarCeilToInt(this->pictureCull().height()));
    fDebugCanvas->setPicture(picture);
    picture->playback(fDebugCanvas);
    fDebugCanvas->setPicture(NULL);
    fIndex = fDebugCanvas->getSize() - 1;
}

SkPicture* SkDebugger::copyPicture() {
    // We can't just call clone here since we want to removed the "deleted"
    // commands. Playing back will strip those out.
    SkPictureRecorder recorder;
    SkCanvas* canvas = recorder.beginRecording(this->pictureCull().width(), 
                                               this->pictureCull().height());
>>>>>>> miniblink49

    bool vizMode = fDebugCanvas->getMegaVizMode();
    fDebugCanvas->setMegaVizMode(false);
    bool overDraw = fDebugCanvas->getOverdrawViz();
    fDebugCanvas->setOverdrawViz(false);
    bool pathOps = fDebugCanvas->getAllowSimplifyClip();
    fDebugCanvas->setAllowSimplifyClip(false);

    fDebugCanvas->draw(canvas);

    fDebugCanvas->setMegaVizMode(vizMode);
    fDebugCanvas->setOverdrawViz(overDraw);
    fDebugCanvas->setAllowSimplifyClip(pathOps);

<<<<<<< HEAD
    return recorder.finishRecordingAsPicture();
}

void SkDebugger::getOverviewText(const SkTDArray<double>* typeTimes,
    double totTime,
    SkString* overview,
    int numRuns)
{
=======
    return recorder.endRecording();
}

void SkDebugger::getOverviewText(const SkTDArray<double>* typeTimes,
                                 double totTime,
                                 SkString* overview,
                                 int numRuns) {
>>>>>>> miniblink49
    const SkTDArray<SkDrawCommand*>& commands = this->getDrawCommands();

    SkTDArray<int> counts;
    counts.setCount(SkDrawCommand::kOpTypeCount);
    for (int i = 0; i < SkDrawCommand::kOpTypeCount; ++i) {
        counts[i] = 0;
    }

    for (int i = 0; i < commands.count(); i++) {
        counts[commands[i]->getType()]++;
    }

    overview->reset();
    int total = 0;
#ifdef SK_DEBUG
    double totPercent = 0, tempSum = 0;
#endif
    for (int i = 0; i < SkDrawCommand::kOpTypeCount; ++i) {
        if (0 == counts[i]) {
            // if there were no commands of this type then they should've consumed no time
<<<<<<< HEAD
            SkASSERT(nullptr == typeTimes || 0.0 == (*typeTimes)[i]);
            continue;
        }

        overview->append(SkDrawCommand::GetCommandString((SkDrawCommand::OpType)i));
=======
            SkASSERT(NULL == typeTimes || 0.0 == (*typeTimes)[i]);
            continue;
        }

        overview->append(SkDrawCommand::GetCommandString((SkDrawCommand::OpType) i));
>>>>>>> miniblink49
        overview->append(": ");
        overview->appendS32(counts[i]);
        if (typeTimes && totTime >= 0.0) {
            overview->append(" - ");
<<<<<<< HEAD
            overview->appendf("%.2f", (*typeTimes)[i] / (float)numRuns);
            overview->append("ms");
            overview->append(" - ");
            double percent = 100.0 * (*typeTimes)[i] / totTime;
=======
            overview->appendf("%.2f", (*typeTimes)[i]/(float)numRuns);
            overview->append("ms");
            overview->append(" - ");
            double percent = 100.0*(*typeTimes)[i]/totTime;
>>>>>>> miniblink49
            overview->appendf("%.2f", percent);
            overview->append("%");
#ifdef SK_DEBUG
            totPercent += percent;
            tempSum += (*typeTimes)[i];
#endif
        }
        overview->append("<br/>");
        total += counts[i];
    }
#ifdef SK_DEBUG
    if (typeTimes) {
        SkASSERT(SkScalarNearlyEqual(SkDoubleToScalar(totPercent),
<<<<<<< HEAD
            SkDoubleToScalar(100.0)));
        SkASSERT(SkScalarNearlyEqual(SkDoubleToScalar(tempSum),
            SkDoubleToScalar(totTime)));
=======
                                     SkDoubleToScalar(100.0)));
        SkASSERT(SkScalarNearlyEqual(SkDoubleToScalar(tempSum),
                                     SkDoubleToScalar(totTime)));
>>>>>>> miniblink49
    }
#endif

    if (totTime > 0.0) {
        overview->append("Total Time: ");
<<<<<<< HEAD
        overview->appendf("%.2f", totTime / (float)numRuns);
=======
        overview->appendf("%.2f", totTime/(float)numRuns);
>>>>>>> miniblink49
        overview->append("ms");
#ifdef SK_DEBUG
        overview->append(" ");
        overview->appendScalar(SkDoubleToScalar(totPercent));
        overview->append("% ");
#endif
        overview->append("<br/>");
    }

    SkString totalStr;
    totalStr.append("Total Draw Commands: ");
    totalStr.appendScalar(SkDoubleToScalar(total));
    totalStr.append("<br/>");
    overview->insert(0, totalStr);

    overview->append("<br/>SkPicture L: ");
    overview->appendScalar(this->pictureCull().fLeft);
    overview->append(" T: ");
    overview->appendScalar(this->pictureCull().fTop);
    overview->append(" R: ");
    overview->appendScalar(this->pictureCull().fRight);
    overview->append(" B: ");
    overview->appendScalar(this->pictureCull().fBottom);
    overview->append("<br/>");
}

<<<<<<< HEAD
void SkDebugger::getClipStackText(SkString* clipStack)
{
=======
void SkDebugger::getClipStackText(SkString* clipStack) {
>>>>>>> miniblink49
    clipStack->set(fDebugCanvas->clipStackData());
}
