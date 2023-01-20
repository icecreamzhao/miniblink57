/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrOvalRenderer_DEFINED
#define GrOvalRenderer_DEFINED

<<<<<<< HEAD
#include "GrColor.h"

class GrDrawBatch;
class GrShaderCaps;
class SkMatrix;
struct SkRect;
class SkRRect;
=======
#include "GrPaint.h"

class GrDrawTarget;
class GrPipelineBuilder;
struct SkRect;
>>>>>>> miniblink49
class SkStrokeRec;

/*
 * This class wraps helper functions that draw ovals and roundrects (filled & stroked)
 */
class GrOvalRenderer {
public:
<<<<<<< HEAD
    static GrDrawBatch* CreateOvalBatch(GrColor,
        const SkMatrix& viewMatrix,
        const SkRect& oval,
        const SkStrokeRec& stroke,
        GrShaderCaps* shaderCaps);
    static GrDrawBatch* CreateRRectBatch(GrColor,
        const SkMatrix& viewMatrix,
        const SkRRect& rrect,
        const SkStrokeRec& stroke,
        GrShaderCaps* shaderCaps);
=======
    static bool DrawOval(GrDrawTarget*,
                         GrPipelineBuilder*,
                         GrColor,
                         const SkMatrix& viewMatrix,
                         bool useAA,
                         const SkRect& oval,
                         const SkStrokeRec& stroke);
    static bool DrawRRect(GrDrawTarget*,
                          GrPipelineBuilder*,
                          GrColor,
                          const SkMatrix& viewMatrix,
                          bool useAA,
                          const SkRRect& rrect,
                          const SkStrokeRec& stroke);
    static bool DrawDRRect(GrDrawTarget* target,
                           GrPipelineBuilder*,
                           GrColor,
                           const SkMatrix& viewMatrix,
                           bool useAA,
                           const SkRRect& outer,
                           const SkRRect& inner);
>>>>>>> miniblink49

private:
    GrOvalRenderer();

<<<<<<< HEAD
    static GrDrawBatch* CreateEllipseBatch(GrColor,
        const SkMatrix& viewMatrix,
        const SkRect& ellipse,
        const SkStrokeRec& stroke);
    static GrDrawBatch* CreateDIEllipseBatch(GrColor,
        const SkMatrix& viewMatrix,
        const SkRect& ellipse,
        const SkStrokeRec& stroke);
    static GrDrawBatch* CreateCircleBatch(GrColor,
        const SkMatrix& viewMatrix,
        const SkRect& circle,
        const SkStrokeRec& stroke);
=======
    static bool DrawEllipse(GrDrawTarget* target,
                            GrPipelineBuilder*,
                            GrColor,
                            const SkMatrix& viewMatrix,
                            bool useCoverageAA,
                            const SkRect& ellipse,
                            const SkStrokeRec& stroke);
    static bool DrawDIEllipse(GrDrawTarget* target,
                              GrPipelineBuilder*,
                              GrColor,
                              const SkMatrix& viewMatrix,
                              bool useCoverageAA,
                              const SkRect& ellipse,
                              const SkStrokeRec& stroke);
    static void DrawCircle(GrDrawTarget* target,
                           GrPipelineBuilder*,
                           GrColor,
                           const SkMatrix& viewMatrix,
                           bool useCoverageAA,
                           const SkRect& circle,
                           const SkStrokeRec& stroke);
>>>>>>> miniblink49
};

#endif // GrOvalRenderer_DEFINED
