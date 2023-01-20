/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrDisableColorXP_DEFINED
#define GrDisableColorXP_DEFINED

#include "GrTypes.h"
#include "GrXferProcessor.h"
<<<<<<< HEAD
#include "SkRefCnt.h"
=======
>>>>>>> miniblink49

class GrProcOptInfo;

class GrDisableColorXPFactory : public GrXPFactory {
public:
<<<<<<< HEAD
    static sk_sp<GrXPFactory> Make() { return sk_sp<GrXPFactory>(new GrDisableColorXPFactory); }

    void getInvariantBlendedColor(const GrProcOptInfo& colorPOI,
        GrXPFactory::InvariantBlendedColor* blendedColor) const override
    {
=======
    static GrXPFactory* Create() {
        return SkNEW(GrDisableColorXPFactory);
    }

    bool supportsRGBCoverage(GrColor knownColor, uint32_t knownColorFlags) const override {
        return true;
    }

    void getInvariantBlendedColor(const GrProcOptInfo& colorPOI,
                                  GrXPFactory::InvariantBlendedColor* blendedColor) const override {
>>>>>>> miniblink49
        blendedColor->fKnownColorFlags = kNone_GrColorComponentFlags;
        blendedColor->fWillBlendWithDst = false;
    }

private:
    GrDisableColorXPFactory();

    GrXferProcessor* onCreateXferProcessor(const GrCaps& caps,
<<<<<<< HEAD
        const GrPipelineOptimizations& optimizations,
        bool hasMixedSamples,
        const DstTexture* dstTexture) const override;

    bool onWillReadDstColor(const GrCaps&, const GrPipelineOptimizations&) const override
    {
        return false;
    }

    bool onIsEqual(const GrXPFactory& xpfBase) const override
    {
=======
                                           const GrProcOptInfo& colorPOI,
                                           const GrProcOptInfo& coveragePOI,
                                           bool hasMixedSamples,
                                           const DstTexture* dstTexture) const override;

    bool willReadDstColor(const GrCaps& caps,
                          const GrProcOptInfo& colorPOI,
                          const GrProcOptInfo& coveragePOI,
                          bool hasMixedSamples) const override {
        return false;
    }

    bool onIsEqual(const GrXPFactory& xpfBase) const override {
>>>>>>> miniblink49
        return true;
    }

    GR_DECLARE_XP_FACTORY_TEST;

    typedef GrXPFactory INHERITED;
};

#endif
<<<<<<< HEAD
=======

>>>>>>> miniblink49
