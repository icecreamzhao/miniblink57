/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrGLInitGLSL_DEFINED
#define GrGLInitGLSL_DEFINED

<<<<<<< HEAD
#include "GrColor.h"
#include "GrTypesPriv.h"
#include "SkString.h"
#include "gl/GrGLInterface.h"
#include "glsl/GrGLSL.h"
=======
#include "gl/GrGLInterface.h"
#include "glsl/GrGLSL.h"
#include "GrColor.h"
#include "GrTypesPriv.h"
#include "SkString.h"
>>>>>>> miniblink49

class GrGLContextInfo;

/**
 * Gets the most recent GLSL Generation compatible with the OpenGL context.
 */
bool GrGLGetGLSLGeneration(const GrGLInterface* gl, GrGLSLGeneration* generation);

<<<<<<< HEAD
=======
/**
 * Returns a string to include at the beginning of a shader to declare the GLSL
 * version.
 */
const char* GrGLGetGLSLVersionDecl(const GrGLContextInfo&);

/**
 * Adds a line of GLSL code to declare the default precision for float types.
 */
void GrGLAppendGLSLDefaultFloatPrecisionDeclaration(GrSLPrecision, GrGLStandard, SkString* out);


>>>>>>> miniblink49
#endif
