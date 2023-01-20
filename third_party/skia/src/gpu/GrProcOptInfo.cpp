/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrProcOptInfo.h"

<<<<<<< HEAD
#include "GrGeometryProcessor.h"

#include "batches/GrDrawBatch.h"

void GrProcOptInfo::calcWithInitialValues(const GrFragmentProcessor* const processors[],
    int cnt,
    GrColor startColor,
    GrColorComponentFlags flags,
    bool areCoverageStages,
    bool isLCD)
{
=======
#include "GrBatch.h"
#include "GrFragmentProcessor.h"
#include "GrFragmentStage.h"
#include "GrGeometryProcessor.h"

void GrProcOptInfo::calcColorWithBatch(const GrBatch* batch,
                                       const GrFragmentStage* stages,
                                       int stageCount) {
    GrInitInvariantOutput out;
    batch->getInvariantOutputColor(&out);
    fInOut.reset(out);
    this->internalCalc(stages, stageCount, batch->willReadFragmentPosition());
}

void GrProcOptInfo::calcCoverageWithBatch(const GrBatch* batch,
                                          const GrFragmentStage* stages,
                                          int stageCount) {
    GrInitInvariantOutput out;
    batch->getInvariantOutputCoverage(&out);
    fInOut.reset(out);
    this->internalCalc(stages, stageCount, batch->willReadFragmentPosition());
}

void GrProcOptInfo::calcColorWithPrimProc(const GrPrimitiveProcessor* primProc,
                                          const GrFragmentStage* stages,
                                          int stageCount) {
    GrInitInvariantOutput out;
    primProc->getInvariantOutputColor(&out);
    fInOut.reset(out);
    this->internalCalc(stages, stageCount, primProc->willReadFragmentPosition());
}

void GrProcOptInfo::calcCoverageWithPrimProc(const GrPrimitiveProcessor* primProc,
                                             const GrFragmentStage* stages,
                                             int stageCount) {
    GrInitInvariantOutput out;
    primProc->getInvariantOutputCoverage(&out);
    fInOut.reset(out);
    this->internalCalc(stages, stageCount, primProc->willReadFragmentPosition());
}

void GrProcOptInfo::calcWithInitialValues(const GrFragmentStage* stages,
                                          int stageCount,
                                          GrColor startColor,
                                          GrColorComponentFlags flags,
                                          bool areCoverageStages) {
>>>>>>> miniblink49
    GrInitInvariantOutput out;
    out.fIsSingleComponent = areCoverageStages;
    out.fColor = startColor;
    out.fValidFlags = flags;
<<<<<<< HEAD
    out.fIsLCDCoverage = isLCD;
    fInOut.reset(out);
    this->internalCalc(processors, cnt);
}

void GrProcOptInfo::initUsingInvariantOutput(GrInitInvariantOutput invOutput)
{
    fInOut.reset(invOutput);
}

void GrProcOptInfo::completeCalculations(const GrFragmentProcessor* const processors[], int cnt)
{
    this->internalCalc(processors, cnt);
}

void GrProcOptInfo::internalCalc(const GrFragmentProcessor* const processors[], int cnt)
{
    fFirstEffectiveProcessorIndex = 0;
    fInputColorIsUsed = true;
    fInputColor = fInOut.color();

    for (int i = 0; i < cnt; ++i) {
        const GrFragmentProcessor* processor = processors[i];
=======
    fInOut.reset(out);
    this->internalCalc(stages, stageCount, false);
}

void GrProcOptInfo::internalCalc(const GrFragmentStage* stages,
                                 int stageCount,
                                 bool initWillReadFragmentPosition) {
    fFirstEffectStageIndex = 0;
    fInputColorIsUsed = true;
    fInputColor = fInOut.color();
    fReadsFragPosition = initWillReadFragmentPosition;

    for (int i = 0; i < stageCount; ++i) {
        const GrFragmentProcessor* processor = stages[i].processor();
>>>>>>> miniblink49
        fInOut.resetWillUseInputColor();
        processor->computeInvariantOutput(&fInOut);
        SkDEBUGCODE(fInOut.validate());
        if (!fInOut.willUseInputColor()) {
<<<<<<< HEAD
            fFirstEffectiveProcessorIndex = i;
            fInputColorIsUsed = false;
        }
        if (kRGBA_GrColorComponentFlags == fInOut.validFlags()) {
            fFirstEffectiveProcessorIndex = i + 1;
=======
            fFirstEffectStageIndex = i;
            fInputColorIsUsed = false;
            // Reset these since we don't care if previous stages read these values
            fReadsFragPosition = initWillReadFragmentPosition;
        }
        if (processor->willReadFragmentPosition()) {
            fReadsFragPosition = true;
        }
        if (kRGBA_GrColorComponentFlags == fInOut.validFlags()) {
            fFirstEffectStageIndex = i + 1;
>>>>>>> miniblink49
            fInputColor = fInOut.color();
            fInputColorIsUsed = true;
            // Since we are clearing all previous color stages we are in a state where we have found
            // zero stages that don't multiply the inputColor.
            fInOut.resetNonMulStageFound();
<<<<<<< HEAD
=======
            // Reset these since we don't care if previous stages read these values
            fReadsFragPosition = initWillReadFragmentPosition;
>>>>>>> miniblink49
        }
    }
}
