/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrPathProcessor_DEFINED
#define GrPathProcessor_DEFINED

#include "GrPrimitiveProcessor.h"

<<<<<<< HEAD
=======
struct PathBatchTracker {
    GrGPInput fInputColorType;
    GrGPInput fInputCoverageType;
    GrColor fColor;
    bool fUsesLocalCoords;
};

>>>>>>> miniblink49
/*
 * The path equivalent of the GP.  For now this just manages color. In the long term we plan on
 * extending this class to handle all nvpr uniform / varying / program work.
 */
class GrPathProcessor : public GrPrimitiveProcessor {
public:
    static GrPathProcessor* Create(GrColor color,
<<<<<<< HEAD
        const GrXPOverridesForBatch& overrides,
        const SkMatrix& viewMatrix = SkMatrix::I(),
        const SkMatrix& localMatrix = SkMatrix::I())
    {
        return new GrPathProcessor(color, overrides, viewMatrix, localMatrix);
    }

=======
                                   const SkMatrix& viewMatrix = SkMatrix::I(),
                                   const SkMatrix& localMatrix = SkMatrix::I()) {
        return SkNEW_ARGS(GrPathProcessor, (color, viewMatrix, localMatrix));
    }

    void initBatchTracker(GrBatchTracker*, const GrPipelineInfo&) const override;

    bool canMakeEqual(const GrBatchTracker& mine,
                      const GrPrimitiveProcessor& that,
                      const GrBatchTracker& theirs) const override;

>>>>>>> miniblink49
    const char* name() const override { return "PathProcessor"; }

    GrColor color() const { return fColor; }
    const SkMatrix& viewMatrix() const { return fViewMatrix; }
    const SkMatrix& localMatrix() const { return fLocalMatrix; }

<<<<<<< HEAD
    bool willUseGeoShader() const override { return false; }

    virtual void getGLSLProcessorKey(const GrGLSLCaps& caps,
        GrProcessorKeyBuilder* b) const override;

    virtual GrGLSLPrimitiveProcessor* createGLSLInstance(const GrGLSLCaps& caps) const override;

    bool hasTransformedLocalCoords() const override { return false; }

    const GrXPOverridesForBatch& overrides() const { return fOverrides; }

    virtual bool isPathRendering() const override { return true; }

private:
    GrPathProcessor(GrColor color, const GrXPOverridesForBatch& overrides,
        const SkMatrix& viewMatrix, const SkMatrix& localMatrix);
=======

    void getInvariantOutputColor(GrInitInvariantOutput* out) const override;
    void getInvariantOutputCoverage(GrInitInvariantOutput* out) const override;

    bool willUseGeoShader() const override { return false; }

    virtual void getGLProcessorKey(const GrBatchTracker& bt,
                                   const GrGLSLCaps& caps,
                                   GrProcessorKeyBuilder* b) const override;

    virtual GrGLPrimitiveProcessor* createGLInstance(const GrBatchTracker& bt,
                                                     const GrGLSLCaps& caps) const override;

private:
    GrPathProcessor(GrColor color, const SkMatrix& viewMatrix, const SkMatrix& localMatrix);
>>>>>>> miniblink49

    bool hasExplicitLocalCoords() const override { return false; }

    GrColor fColor;
    const SkMatrix fViewMatrix;
    const SkMatrix fLocalMatrix;
<<<<<<< HEAD
    GrXPOverridesForBatch fOverrides;
=======
>>>>>>> miniblink49

    typedef GrPrimitiveProcessor INHERITED;
};

#endif
