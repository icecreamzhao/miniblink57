/*
* Copyright 2013 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#include "GrPathProcessor.h"

<<<<<<< HEAD
#include "gl/GrGLGpu.h"
#include "glsl/GrGLSLCaps.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProcessorTypes.h"
#include "glsl/GrGLSLUniformHandler.h"
#include "glsl/GrGLSLVarying.h"

class GrGLPathProcessor : public GrGLSLPrimitiveProcessor {
public:
    GrGLPathProcessor()
        : fColor(GrColor_ILLEGAL)
    {
    }

    static void GenKey(const GrPathProcessor& pathProc,
        const GrGLSLCaps&,
        GrProcessorKeyBuilder* b)
    {
        b->add32(SkToInt(pathProc.overrides().readsColor()) | (SkToInt(pathProc.overrides().readsCoverage()) << 1) | (SkToInt(pathProc.viewMatrix().hasPerspective()) << 2));
    }

    void emitCode(EmitArgs& args) override
    {
        GrGLSLPPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrPathProcessor& pathProc = args.fGP.cast<GrPathProcessor>();

        if (!pathProc.viewMatrix().hasPerspective()) {
            args.fVaryingHandler->setNoPerspective();
        }

        // emit transforms
        this->emitTransforms(args.fVaryingHandler, args.fTransformsIn, args.fTransformsOut);

        // Setup uniform color
        if (pathProc.overrides().readsColor()) {
            const char* stagedLocalVarName;
            fColorUniform = args.fUniformHandler->addUniform(kFragment_GrShaderFlag,
                kVec4f_GrSLType,
                kDefault_GrSLPrecision,
                "Color",
                &stagedLocalVarName);
            fragBuilder->codeAppendf("%s = %s;", args.fOutputColor, stagedLocalVarName);
        }

        // setup constant solid coverage
        if (pathProc.overrides().readsCoverage()) {
            fragBuilder->codeAppendf("%s = vec4(1);", args.fOutputCoverage);
        }
    }

    void emitTransforms(GrGLSLVaryingHandler* varyingHandler,
        const TransformsIn& tin,
        TransformsOut* tout)
    {
        tout->push_back_n(tin.count());
        fInstalledTransforms.push_back_n(tin.count());
        for (int i = 0; i < tin.count(); i++) {
            const ProcCoords& coordTransforms = tin[i];
            fInstalledTransforms[i].push_back_n(coordTransforms.count());
            for (int t = 0; t < coordTransforms.count(); t++) {
                GrSLType varyingType = coordTransforms[t]->getMatrix().hasPerspective() ? kVec3f_GrSLType : kVec2f_GrSLType;

                SkString strVaryingName("MatrixCoord");
                strVaryingName.appendf("_%i_%i", i, t);
                GrGLSLVertToFrag v(varyingType);
                GrGLVaryingHandler* glVaryingHandler = (GrGLVaryingHandler*)varyingHandler;
                fInstalledTransforms[i][t].fHandle = glVaryingHandler->addPathProcessingVarying(strVaryingName.c_str(),
                                                                         &v)
                                                         .toIndex();
                fInstalledTransforms[i][t].fType = varyingType;

                (*tout)[i].emplace_back(SkString(v.fsIn()), varyingType);
            }
        }
    }

    void setData(const GrGLSLProgramDataManager& pd,
        const GrPrimitiveProcessor& primProc) override
    {
        const GrPathProcessor& pathProc = primProc.cast<GrPathProcessor>();
        if (pathProc.overrides().readsColor() && pathProc.color() != fColor) {
            float c[4];
            GrColorToRGBAFloat(pathProc.color(), c);
            pd.set4fv(fColorUniform, 1, c);
            fColor = pathProc.color();
        }
    }

    void setTransformData(const GrPrimitiveProcessor& primProc,
        const GrGLSLProgramDataManager& pdman,
        int index,
        const SkTArray<const GrCoordTransform*, true>& coordTransforms) override
    {
        const GrPathProcessor& pathProc = primProc.cast<GrPathProcessor>();
        SkSTArray<2, VaryingTransform, true>& transforms = fInstalledTransforms[index];
        int numTransforms = transforms.count();
        for (int t = 0; t < numTransforms; ++t) {
            SkASSERT(transforms[t].fHandle.isValid());
            const SkMatrix& transform = GetTransformMatrix(pathProc.localMatrix(),
                *coordTransforms[t]);
            if (transforms[t].fCurrentValue.cheapEqualTo(transform)) {
                continue;
            }
            transforms[t].fCurrentValue = transform;

            SkASSERT(transforms[t].fType == kVec2f_GrSLType || transforms[t].fType == kVec3f_GrSLType);
            unsigned components = transforms[t].fType == kVec2f_GrSLType ? 2 : 3;
            pdman.setPathFragmentInputTransform(transforms[t].fHandle, components, transform);
        }
    }

private:
    typedef GrGLSLProgramDataManager::VaryingHandle VaryingHandle;
    struct VaryingTransform : public Transform {
        VaryingTransform()
            : Transform()
        {
        }
        VaryingHandle fHandle;
    };

    SkSTArray<8, SkSTArray<2, VaryingTransform, true>> fInstalledTransforms;

    UniformHandle fColorUniform;
    GrColor fColor;

    typedef GrGLSLPrimitiveProcessor INHERITED;
};

GrPathProcessor::GrPathProcessor(GrColor color,
    const GrXPOverridesForBatch& overrides,
    const SkMatrix& viewMatrix,
    const SkMatrix& localMatrix)
    : fColor(color)
    , fViewMatrix(viewMatrix)
    , fLocalMatrix(localMatrix)
    , fOverrides(overrides)
{
    this->initClassID<GrPathProcessor>();
}

void GrPathProcessor::getGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLPathProcessor::GenKey(*this, caps, b);
}

GrGLSLPrimitiveProcessor* GrPathProcessor::createGLSLInstance(const GrGLSLCaps& caps) const
{
    SkASSERT(caps.pathRenderingSupport());
    return new GrGLPathProcessor();
=======
#include "gl/GrGLPathProcessor.h"
#include "gl/GrGLGpu.h"

#include "glsl/GrGLSLCaps.h"

GrPathProcessor::GrPathProcessor(GrColor color,
                                 const SkMatrix& viewMatrix,
                                 const SkMatrix& localMatrix)
    : INHERITED(true)
    , fColor(color)
    , fViewMatrix(viewMatrix)
    , fLocalMatrix(localMatrix) {
    this->initClassID<GrPathProcessor>();
}

void GrPathProcessor::getInvariantOutputColor(GrInitInvariantOutput* out) const {
    out->setKnownFourComponents(fColor);
}

void GrPathProcessor::getInvariantOutputCoverage(GrInitInvariantOutput* out) const {
    out->setKnownSingleComponent(0xff);
}

void GrPathProcessor::initBatchTracker(GrBatchTracker* bt, const GrPipelineInfo& init) const {
    PathBatchTracker* local = bt->cast<PathBatchTracker>();
    if (!init.readsColor()) {
        local->fInputColorType = kIgnored_GrGPInput;
        local->fColor = GrColor_ILLEGAL;
    } else {
        local->fInputColorType = kUniform_GrGPInput;
        if (!init.getOverrideColorIfSet(&local->fColor)) {
            local->fColor = this->color();
        }
    }

    local->fInputCoverageType = init.readsCoverage() ? kAllOnes_GrGPInput : kIgnored_GrGPInput;
    local->fUsesLocalCoords = init.readsLocalCoords();
}

bool GrPathProcessor::canMakeEqual(const GrBatchTracker& m,
                                   const GrPrimitiveProcessor& that,
                                   const GrBatchTracker& t) const {
    if (this->classID() != that.classID() || !this->hasSameTextureAccesses(that)) {
        return false;
    }

    const GrPathProcessor& other = that.cast<GrPathProcessor>();
    if (!this->viewMatrix().cheapEqualTo(other.viewMatrix())) {
        return false;
    }

    const PathBatchTracker& mine = m.cast<PathBatchTracker>();
    const PathBatchTracker& theirs = t.cast<PathBatchTracker>();
    if (mine.fColor != theirs.fColor) {
        return false;
    }

    if (mine.fUsesLocalCoords != theirs.fUsesLocalCoords) {
        return false;
    }

    if (mine.fUsesLocalCoords && !this->localMatrix().cheapEqualTo(other.localMatrix())) {
        return false;
    }

    return true;
}

void GrPathProcessor::getGLProcessorKey(const GrBatchTracker& bt,
                                        const GrGLSLCaps& caps,
                                        GrProcessorKeyBuilder* b) const {
    GrGLPathProcessor::GenKey(*this, bt, caps, b);
}

GrGLPrimitiveProcessor* GrPathProcessor::createGLInstance(const GrBatchTracker& bt,
                                                          const GrGLSLCaps& caps) const {
    SkASSERT(caps.pathRenderingSupport());
    return SkNEW_ARGS(GrGLPathProcessor, (*this, bt));
>>>>>>> miniblink49
}
