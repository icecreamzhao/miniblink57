/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrColorProcessor_DEFINED
#define GrColorProcessor_DEFINED

#include "GrFragmentProcessor.h"

<<<<<<< HEAD
=======
class GrInvariantOutput;

>>>>>>> miniblink49
/**
 * This is a simple GrFragmentProcessor that outputs a constant color. It may do one of the
 * following with its input color: ignore it, or multiply it by the constant color, multiply its
 * alpha by the constant color and ignore the input color's r, g, and b.
 */
class GrConstColorProcessor : public GrFragmentProcessor {
public:
    enum InputMode {
        kIgnore_InputMode,
        kModulateRGBA_InputMode,
        kModulateA_InputMode,

        kLastInputMode = kModulateA_InputMode
    };
    static const int kInputModeCnt = kLastInputMode + 1;

<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrColor color, InputMode mode)
    {
        return sk_sp<GrFragmentProcessor>(new GrConstColorProcessor(color, mode));
    }

    const char* name() const override { return "Color"; }

    SkString dumpInfo() const override
    {
        SkString str;
        str.appendf("Color: 0x%08x", fColor);
        return str;
    }
=======
    static GrFragmentProcessor* Create(GrColor color, InputMode mode) {
        return SkNEW_ARGS(GrConstColorProcessor, (color, mode));
    }

    ~GrConstColorProcessor() override {}

    const char* name() const override { return "Color"; }

    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;
>>>>>>> miniblink49

    GrColor color() const { return fColor; }

    InputMode inputMode() const { return fMode; }

private:
<<<<<<< HEAD
    GrConstColorProcessor(GrColor color, InputMode mode)
        : fColor(color)
        , fMode(mode)
    {
        this->initClassID<GrConstColorProcessor>();
    }

    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

=======
    GrConstColorProcessor(GrColor color, InputMode mode) : fColor(color), fMode(mode) {
        this->initClassID<GrConstColorProcessor>();
    }

>>>>>>> miniblink49
    bool onIsEqual(const GrFragmentProcessor&) const override;

    void onComputeInvariantOutput(GrInvariantOutput* inout) const override;

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

<<<<<<< HEAD
    GrColor fColor;
    InputMode fMode;
=======
    GrColor     fColor;
    InputMode   fMode;
>>>>>>> miniblink49

    typedef GrFragmentProcessor INHERITED;
};

#endif
