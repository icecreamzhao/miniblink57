//
// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// EGLX11VisualTest.cpp: tests for EGL_ANGLE_x11_visual extension

#include <gtest/gtest.h>

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <X11/Xlib.h>

#include "OSWindow.h"
#include "test_utils/ANGLETest.h"
#include "x11/X11Window.h"

using namespace angle;

namespace {

const EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
}

class EGLX11VisualHintTest : public ::testing::TestWithParam<angle::PlatformParameters> {
public:
    void SetUp() override
    {
        mEglGetPlatformDisplayEXT = reinterpret_cast<PFNEGLGETPLATFORMDISPLAYEXTPROC>(
            eglGetProcAddress("eglGetPlatformDisplayEXT"));

        mDisplay = XOpenDisplay(NULL);
    }

    std::vector<EGLint> getDisplayAttributes(int visualId) const
    {
        std::vector<EGLint> attribs;

        attribs.push_back(EGL_PLATFORM_ANGLE_TYPE_ANGLE);
        attribs.push_back(GetParam().getRenderer());
        attribs.push_back(EGL_X11_VISUAL_ID_ANGLE);
        attribs.push_back(visualId);
        attribs.push_back(EGL_NONE);

        return attribs;
    }

    unsigned int chooseDifferentVisual(unsigned int visualId)
    {
        int numVisuals;
        XVisualInfo visualTemplate;
        visualTemplate.screen = DefaultScreen(mDisplay);

        XVisualInfo* visuals = XGetVisualInfo(mDisplay, VisualScreenMask, &visualTemplate, &numVisuals);
        EXPECT_TRUE(numVisuals >= 2);

        for (int i = 0; i < numVisuals; ++i) {
            if (visuals[i].visualid != visualId) {
                int result = visuals[i].visualid;
                XFree(visuals);
                return result;
            }
        }

        UNREACHABLE();
        return -1;
    }

protected:
    PFNEGLGETPLATFORMDISPLAYEXTPROC mEglGetPlatformDisplayEXT;
    Display* mDisplay;
};

// Test that display creation fails if the visual ID passed in invalid.
TEST_P(EGLX11VisualHintTest, InvalidVisualID)
{
    static const int gInvalidVisualId = -1;
    auto attributes = getDisplayAttributes(gInvalidVisualId);

    EGLDisplay display = mEglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, attributes.data());
    ASSERT_TRUE(display != EGL_NO_DISPLAY);

    ASSERT_TRUE(EGL_FALSE == eglInitialize(display, nullptr, nullptr));
    ASSERT_EGL_ERROR(EGL_NOT_INITIALIZED);
}

// Test that context creation with a visual ID succeeds, that the context exposes
// only one config, and that a clear on a surface with this config works.
TEST_P(EGLX11VisualHintTest, ValidVisualIDAndClear)
{
    // We'll test the extension with one visual ID but we don't care which one. This means we
    // can use OSWindow to create a window and just grab its visual.
    OSWindow* osWindow = CreateOSWindow();
    osWindow->initialize("EGLX11VisualHintTest", 500, 500);
    osWindow->setVisible(true);

    Window xWindow = osWindow->getNativeWindow();

    XWindowAttributes windowAttributes;
    ASSERT_NE(0, XGetWindowAttributes(mDisplay, xWindow, &windowAttributes));
    int visualId = windowAttributes.visual->visualid;

    auto attributes = getDisplayAttributes(visualId);
    EGLDisplay display = mEglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, attributes.data());
    ASSERT_NE(EGL_NO_DISPLAY, display);

    ASSERT_TRUE(EGL_TRUE == eglInitialize(display, nullptr, nullptr));

    // While this is not required by the extension, test that our implementation returns only one
    // config, with the same native visual Id that we provided.
    int nConfigs = 0;
    ASSERT_TRUE(EGL_TRUE == eglGetConfigs(display, nullptr, 0, &nConfigs));
    ASSERT_EQ(1, nConfigs);

    int nReturnedConfigs = 0;
    EGLConfig config;
    ASSERT_TRUE(EGL_TRUE == eglGetConfigs(display, &config, 1, &nReturnedConfigs));
    ASSERT_EQ(nConfigs, nReturnedConfigs);

    EGLint eglNativeId;
    ASSERT_TRUE(EGL_TRUE == eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &eglNativeId));
    ASSERT_EQ(visualId, eglNativeId);

    // Finally, try to do a clear on the window.
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs);
    ASSERT_NE(EGL_NO_CONTEXT, context);

    EGLSurface window = eglCreateWindowSurface(display, config, xWindow, nullptr);
    ASSERT_EGL_SUCCESS();

    eglMakeCurrent(display, window, window, context);
    ASSERT_EGL_SUCCESS();

    glViewport(0, 0, 500, 500);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ASSERT_GL_NO_ERROR();
    EXPECT_PIXEL_EQ(250, 250, 0, 0, 255, 255);

    // Teardown
    eglDestroySurface(display, window);
    ASSERT_EGL_SUCCESS();

    eglDestroyContext(display, context);
    ASSERT_EGL_SUCCESS();

    SafeDelete(osWindow);

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglTerminate(display);
}

// Test that EGL_BAD_MATCH is generated when trying to create an EGL window from
// an X11 window whose visual ID doesn't match the visual ID passed at display creation.
TEST_P(EGLX11VisualHintTest, InvalidWindowVisualID)
{
    // Get the default visual ID, as a good guess of a visual id for which display
    // creation will succeed.
    int visualId;
    {
        OSWindow* osWindow = CreateOSWindow();
        osWindow->initialize("EGLX11VisualHintTest", 500, 500);
        osWindow->setVisible(true);

        Window xWindow = osWindow->getNativeWindow();

        XWindowAttributes windowAttributes;
        ASSERT_NE(0, XGetWindowAttributes(mDisplay, xWindow, &windowAttributes));
        visualId = windowAttributes.visual->visualid;

        SafeDelete(osWindow);
    }

    auto attributes = getDisplayAttributes(visualId);
    EGLDisplay display = mEglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, attributes.data());
    ASSERT_NE(EGL_NO_DISPLAY, display);

    ASSERT_TRUE(EGL_TRUE == eglInitialize(display, nullptr, nullptr));

    // Initialize the window with a visual id different from the display's visual id
    int otherVisualId = chooseDifferentVisual(visualId);
    ASSERT_NE(visualId, otherVisualId);

    OSWindow* osWindow = new X11Window(otherVisualId);
    osWindow->initialize("EGLX11VisualHintTest", 500, 500);
    osWindow->setVisible(true);

    Window xWindow = osWindow->getNativeWindow();

    // Creating the EGL window should fail with EGL_BAD_MATCH
    int nReturnedConfigs = 0;
    EGLConfig config;
    ASSERT_TRUE(EGL_TRUE == eglGetConfigs(display, &config, 1, &nReturnedConfigs));
    ASSERT_EQ(1, nReturnedConfigs);

    EGLSurface window = eglCreateWindowSurface(display, config, xWindow, nullptr);
    ASSERT_EQ(EGL_NO_SURFACE, window);
    ASSERT_EGL_ERROR(EGL_BAD_MATCH);

    SafeDelete(osWindow);
}

ANGLE_INSTANTIATE_TEST(EGLX11VisualHintTest, ES2_OPENGL());
