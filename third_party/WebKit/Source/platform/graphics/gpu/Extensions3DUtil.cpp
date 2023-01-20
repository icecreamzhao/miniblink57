// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "platform/graphics/gpu/Extensions3DUtil.h"

#include "gpu/command_buffer/client/gles2_interface.h"
#include "wtf/PtrUtil.h"
#include "wtf/text/CString.h"
#include "wtf/text/StringHash.h"
#include <memory>
=======
#include "config.h"
#include "platform/graphics/gpu/Extensions3DUtil.h"

#include "public/platform/WebGraphicsContext3D.h"
#include "wtf/text/CString.h"
#include "wtf/text/StringHash.h"
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    void splitStringHelper(const String& str, HashSet<String>& set)
    {
        Vector<String> substrings;
        str.split(' ', substrings);
        for (size_t i = 0; i < substrings.size(); ++i)
            set.add(substrings[i]);
    }

} // anonymous namespace

std::unique_ptr<Extensions3DUtil> Extensions3DUtil::create(
    gpu::gles2::GLES2Interface* gl)
{
    std::unique_ptr<Extensions3DUtil> out = WTF::wrapUnique(new Extensions3DUtil(gl));
    out->initializeExtensions();
    return out;
}

Extensions3DUtil::Extensions3DUtil(gpu::gles2::GLES2Interface* gl)
    : m_gl(gl)
=======
void splitStringHelper(const String& str, HashSet<String>& set)
{
    Vector<String> substrings;
    str.split(' ', substrings);
    for (size_t i = 0; i < substrings.size(); ++i)
        set.add(substrings[i]);
}

} // anonymous namespace

PassOwnPtr<Extensions3DUtil> Extensions3DUtil::create(WebGraphicsContext3D* context)
{
    OwnPtr<Extensions3DUtil> out = adoptPtr(new Extensions3DUtil(context));
    out->initializeExtensions();
    return out.release();
}

Extensions3DUtil::Extensions3DUtil(WebGraphicsContext3D* context)
    : m_context(context)
>>>>>>> miniblink49
    , m_isValid(true)
{
}

<<<<<<< HEAD
Extensions3DUtil::~Extensions3DUtil() { }

void Extensions3DUtil::initializeExtensions()
{
    if (m_gl->GetGraphicsResetStatusKHR() != GL_NO_ERROR) {
        // If the context is lost don't initialize the extension strings.
        // This will cause supportsExtension, ensureExtensionEnabled, and
        // isExtensionEnabled to always return false.
=======
Extensions3DUtil::~Extensions3DUtil()
{
}

void Extensions3DUtil::initializeExtensions()
{
    if (m_context->isContextLost()) {
        // If the context is lost don't initialize the extension strings.
        // This will cause supportsExtension, ensureExtensionEnabled, and isExtensionEnabled to always return false.
>>>>>>> miniblink49
        m_isValid = false;
        return;
    }

<<<<<<< HEAD
    String extensionsString(m_gl->GetString(GL_EXTENSIONS));
    splitStringHelper(extensionsString, m_enabledExtensions);

    String requestableExtensionsString(m_gl->GetRequestableExtensionsCHROMIUM());
    splitStringHelper(requestableExtensionsString, m_requestableExtensions);
}

=======
    String extensionsString = m_context->getString(GL_EXTENSIONS);
    splitStringHelper(extensionsString, m_enabledExtensions);

    String requestableExtensionsString = m_context->getRequestableExtensionsCHROMIUM();
    splitStringHelper(requestableExtensionsString, m_requestableExtensions);
}


>>>>>>> miniblink49
bool Extensions3DUtil::supportsExtension(const String& name)
{
    return m_enabledExtensions.contains(name) || m_requestableExtensions.contains(name);
}

bool Extensions3DUtil::ensureExtensionEnabled(const String& name)
{
    if (m_enabledExtensions.contains(name))
        return true;

    if (m_requestableExtensions.contains(name)) {
<<<<<<< HEAD
        m_gl->RequestExtensionCHROMIUM(name.ascii().data());
=======
        m_context->requestExtensionCHROMIUM(name.ascii().data());
>>>>>>> miniblink49
        m_enabledExtensions.clear();
        m_requestableExtensions.clear();
        initializeExtensions();
    }
    return m_enabledExtensions.contains(name);
}

bool Extensions3DUtil::isExtensionEnabled(const String& name)
{
    return m_enabledExtensions.contains(name);
}

<<<<<<< HEAD
bool Extensions3DUtil::canUseCopyTextureCHROMIUM(GLenum destTarget,
    GLenum destFormat,
    GLenum destType,
    GLint level)
{
    // TODO(zmo): restriction of (RGB || RGBA)/UNSIGNED_BYTE/(Level 0) should be
    // lifted when GLES2Interface::CopyTextureCHROMIUM(...) are fully functional.
    if (destTarget == GL_TEXTURE_2D && (destFormat == GL_RGB || destFormat == GL_RGBA) && destType == GL_UNSIGNED_BYTE && !level)
=======
bool Extensions3DUtil::canUseCopyTextureCHROMIUM(GLenum destTarget, GLenum destFormat, GLenum destType, GLint level)
{
    // FIXME: restriction of (RGB || RGBA)/UNSIGNED_BYTE/(Level 0) should be lifted when
    // WebGraphicsContext3D::copyTextureCHROMIUM(...) are fully functional.
    if (destTarget == GL_TEXTURE_2D && (destFormat == GL_RGB || destFormat == GL_RGBA)
        && destType == GL_UNSIGNED_BYTE
        && !level)
>>>>>>> miniblink49
        return true;
    return false;
}

} // namespace blink
