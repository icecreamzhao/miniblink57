// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "modules/webgl/EXTShaderTextureLOD.h"

namespace blink {

EXTShaderTextureLOD::EXTShaderTextureLOD(WebGLRenderingContextBase* context)
    : WebGLExtension(context)
{
    context->extensionsUtil()->ensureExtensionEnabled(
        "GL_EXT_shader_texture_lod");
}

WebGLExtensionName EXTShaderTextureLOD::name() const
{
    return EXTShaderTextureLODName;
}

EXTShaderTextureLOD* EXTShaderTextureLOD::create(
    WebGLRenderingContextBase* context)
{
    return new EXTShaderTextureLOD(context);
}

bool EXTShaderTextureLOD::supported(WebGLRenderingContextBase* context)
{
    return context->extensionsUtil()->supportsExtension(
        "GL_EXT_shader_texture_lod");
}

const char* EXTShaderTextureLOD::extensionName()
{
    return "EXT_shader_texture_lod";
}

} // namespace blink
