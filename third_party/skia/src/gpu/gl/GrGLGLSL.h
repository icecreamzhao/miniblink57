/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrGLInitGLSL_DEFINED
#define GrGLInitGLSL_DEFINED

#include "GrColor.h"
#include "GrTypesPriv.h"
#include "SkString.h"
#include "gl/GrGLInterface.h"
#include "glsl/GrGLSL.h"

class GrGLContextInfo;

/**
 * Gets the most recent GLSL Generation compatible with the OpenGL context.
 */
bool GrGLGetGLSLGeneration(const GrGLInterface* gl, GrGLSLGeneration* generation);

#endif
