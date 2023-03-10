// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/media/ScreenCapture

#ifndef org_chromium_media_ScreenCapture_JNI
#define org_chromium_media_ScreenCapture_JNI

#include <jni.h>

#include "../../../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kScreenCaptureClassPath[] = "org/chromium/media/ScreenCapture";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_ScreenCapture_clazz __attribute__((unused)) = 0;
#define ScreenCapture_clazz(env) base::android::LazyGetClass(env, kScreenCaptureClassPath, &g_ScreenCapture_clazz)

} // namespace

namespace media {

// Step 2: method stubs.
JNI_GENERATOR_EXPORT void
Java_org_chromium_media_ScreenCapture_nativeOnRGBAFrameAvailable(JNIEnv*
                                                                     env,
    jobject jcaller,
    jlong nativeScreenCaptureMachineAndroid,
    jobject buf,
    jint left,
    jint top,
    jint width,
    jint height,
    jint rowStride,
    jlong timestamp)
{
    ScreenCaptureMachineAndroid* native = reinterpret_cast<ScreenCaptureMachineAndroid*>(nativeScreenCaptureMachineAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "OnRGBAFrameAvailable");
    return native->OnRGBAFrameAvailable(env,
        base::android::JavaParamRef<jobject>(env, jcaller),
        base::android::JavaParamRef<jobject>(env, buf), left, top, width, height,
        rowStride, timestamp);
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_media_ScreenCapture_nativeOnI420FrameAvailable(JNIEnv*
                                                                     env,
    jobject jcaller,
    jlong nativeScreenCaptureMachineAndroid,
    jobject yBuffer,
    jint yStride,
    jobject uBuffer,
    jobject vBuffer,
    jint uvRowStride,
    jint uvPixelStride,
    jint left,
    jint top,
    jint width,
    jint height,
    jlong timestamp)
{
    ScreenCaptureMachineAndroid* native = reinterpret_cast<ScreenCaptureMachineAndroid*>(nativeScreenCaptureMachineAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "OnI420FrameAvailable");
    return native->OnI420FrameAvailable(env,
        base::android::JavaParamRef<jobject>(env, jcaller),
        base::android::JavaParamRef<jobject>(env, yBuffer), yStride,
        base::android::JavaParamRef<jobject>(env, uBuffer),
        base::android::JavaParamRef<jobject>(env, vBuffer), uvRowStride,
        uvPixelStride, left, top, width, height, timestamp);
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_media_ScreenCapture_nativeOnActivityResult(JNIEnv* env,
    jobject jcaller,
    jlong nativeScreenCaptureMachineAndroid,
    jboolean result)
{
    ScreenCaptureMachineAndroid* native = reinterpret_cast<ScreenCaptureMachineAndroid*>(nativeScreenCaptureMachineAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "OnActivityResult");
    return native->OnActivityResult(env, base::android::JavaParamRef<jobject>(env, jcaller), result);
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_media_ScreenCapture_nativeOnOrientationChange(JNIEnv* env,
    jobject jcaller,
    jlong nativeScreenCaptureMachineAndroid,
    jint rotation)
{
    ScreenCaptureMachineAndroid* native = reinterpret_cast<ScreenCaptureMachineAndroid*>(nativeScreenCaptureMachineAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "OnOrientationChange");
    return native->OnOrientationChange(env,
        base::android::JavaParamRef<jobject>(env, jcaller), rotation);
}

static base::subtle::AtomicWord g_ScreenCapture_createScreenCaptureMachine = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_ScreenCapture_createScreenCaptureMachine(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context,
    jlong nativeScreenCaptureMachineAndroid)
{
    CHECK_CLAZZ(env, ScreenCapture_clazz(env),
        ScreenCapture_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, ScreenCapture_clazz(env),
        "createScreenCaptureMachine",
        "("
        "Landroid/content/Context;"
        "J"
        ")"
        "Lorg/chromium/media/ScreenCapture;",
        &g_ScreenCapture_createScreenCaptureMachine);

    jobject ret = env->CallStaticObjectMethod(ScreenCapture_clazz(env),
        method_id, context.obj(), nativeScreenCaptureMachineAndroid);
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_ScreenCapture_allocate = 0;
static jboolean Java_ScreenCapture_allocate(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper width,
    JniIntWrapper height)
{
    CHECK_CLAZZ(env, obj.obj(),
        ScreenCapture_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ScreenCapture_clazz(env),
        "allocate",
        "("
        "I"
        "I"
        ")"
        "Z",
        &g_ScreenCapture_allocate);

    jboolean ret = env->CallBooleanMethod(obj.obj(),
        method_id, as_jint(width), as_jint(height));
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_ScreenCapture_startPrompt = 0;
static jboolean Java_ScreenCapture_startPrompt(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ScreenCapture_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ScreenCapture_clazz(env),
        "startPrompt",
        "("
        ")"
        "Z",
        &g_ScreenCapture_startPrompt);

    jboolean ret = env->CallBooleanMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_ScreenCapture_startCapture = 0;
static void Java_ScreenCapture_startCapture(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ScreenCapture_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ScreenCapture_clazz(env),
        "startCapture",
        "("
        ")"
        "V",
        &g_ScreenCapture_startCapture);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_ScreenCapture_stopCapture = 0;
static void Java_ScreenCapture_stopCapture(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ScreenCapture_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ScreenCapture_clazz(env),
        "stopCapture",
        "("
        ")"
        "V",
        &g_ScreenCapture_stopCapture);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsScreenCapture[] = {
    { "nativeOnRGBAFrameAvailable",
        "("
        "J"
        "Ljava/nio/ByteBuffer;"
        "I"
        "I"
        "I"
        "I"
        "I"
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_media_ScreenCapture_nativeOnRGBAFrameAvailable) },
    { "nativeOnI420FrameAvailable",
        "("
        "J"
        "Ljava/nio/ByteBuffer;"
        "I"
        "Ljava/nio/ByteBuffer;"
        "Ljava/nio/ByteBuffer;"
        "I"
        "I"
        "I"
        "I"
        "I"
        "I"
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_media_ScreenCapture_nativeOnI420FrameAvailable) },
    { "nativeOnActivityResult",
        "("
        "J"
        "Z"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_media_ScreenCapture_nativeOnActivityResult) },
    { "nativeOnOrientationChange",
        "("
        "J"
        "I"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_media_ScreenCapture_nativeOnOrientationChange) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsScreenCaptureSize = arraysize(kMethodsScreenCapture);

    if (env->RegisterNatives(ScreenCapture_clazz(env),
            kMethodsScreenCapture,
            kMethodsScreenCaptureSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, ScreenCapture_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace media

#endif // org_chromium_media_ScreenCapture_JNI
