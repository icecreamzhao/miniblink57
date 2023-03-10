// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/content/app/ChildProcessServiceImpl

#ifndef org_chromium_content_app_ChildProcessServiceImpl_JNI
#define org_chromium_content_app_ChildProcessServiceImpl_JNI

#include <jni.h>

#include "../../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kChildProcessServiceImplClassPath[] = "org/chromium/content/app/ChildProcessServiceImpl";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_ChildProcessServiceImpl_clazz __attribute__((unused))
= 0;
#define ChildProcessServiceImpl_clazz(env) base::android::LazyGetClass(env, kChildProcessServiceImplClassPath, &g_ChildProcessServiceImpl_clazz)

} // namespace

namespace content {

// Step 2: method stubs.

static void RegisterGlobalFileDescriptor(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
    jint id,
    jint fd,
    jlong offset,
    jlong size);

JNI_GENERATOR_EXPORT void
Java_org_chromium_content_app_ChildProcessServiceImpl_nativeRegisterGlobalFileDescriptor(JNIEnv*
                                                                                             env,
    jclass jcaller,
    jint id,
    jint fd,
    jlong offset,
    jlong size)
{
    return RegisterGlobalFileDescriptor(env,
        base::android::JavaParamRef<jclass>(env, jcaller), id, fd, offset, size);
}

static void InitChildProcessImpl(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
    const base::android::JavaParamRef<jobject>& serviceImpl,
    jint cpuCount,
    jlong cpuFeatures);

JNI_GENERATOR_EXPORT void
Java_org_chromium_content_app_ChildProcessServiceImpl_nativeInitChildProcessImpl(JNIEnv*
                                                                                     env,
    jclass jcaller,
    jobject serviceImpl,
    jint cpuCount,
    jlong cpuFeatures)
{
    return InitChildProcessImpl(env, base::android::JavaParamRef<jclass>(env, jcaller), base::android::JavaParamRef<jobject>(env, serviceImpl),
        cpuCount, cpuFeatures);
}

static void ExitChildProcess(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller);

JNI_GENERATOR_EXPORT void
Java_org_chromium_content_app_ChildProcessServiceImpl_nativeExitChildProcess(JNIEnv*
                                                                                 env,
    jclass jcaller)
{
    return ExitChildProcess(env, base::android::JavaParamRef<jclass>(env, jcaller));
}

static void ShutdownMainThread(JNIEnv* env, const base::android::JavaParamRef<jobject>& jcaller);

JNI_GENERATOR_EXPORT void
Java_org_chromium_content_app_ChildProcessServiceImpl_nativeShutdownMainThread(JNIEnv*
                                                                                   env,
    jobject jcaller)
{
    return ShutdownMainThread(env, base::android::JavaParamRef<jobject>(env, jcaller));
}

static base::subtle::AtomicWord
    g_ChildProcessServiceImpl_establishSurfaceTexturePeer
    = 0;
static void Java_ChildProcessServiceImpl_establishSurfaceTexturePeer(JNIEnv*
                                                                         env,
    const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper pid,
    const base::android::JavaRefOrBare<jobject>& surfaceObject,
    JniIntWrapper primaryID,
    JniIntWrapper secondaryID)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChildProcessServiceImpl_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChildProcessServiceImpl_clazz(env),
        "establishSurfaceTexturePeer",
        "("
        "I"
        "Ljava/lang/Object;"
        "I"
        "I"
        ")"
        "V",
        &g_ChildProcessServiceImpl_establishSurfaceTexturePeer);

    env->CallVoidMethod(obj.obj(),
        method_id, as_jint(pid), surfaceObject.obj(), as_jint(primaryID),
        as_jint(secondaryID));
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord
    g_ChildProcessServiceImpl_forwardSurfaceTextureForSurfaceRequest
    = 0;
static void
Java_ChildProcessServiceImpl_forwardSurfaceTextureForSurfaceRequest(JNIEnv*
                                                                        env,
    const base::android::JavaRefOrBare<jobject>& obj, const base::android::JavaRefOrBare<jobject>& requestToken,
    const base::android::JavaRefOrBare<jobject>& surfaceTexture)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChildProcessServiceImpl_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChildProcessServiceImpl_clazz(env),
        "forwardSurfaceTextureForSurfaceRequest",
        "("
        "Lorg/chromium/base/UnguessableToken;"
        "Landroid/graphics/SurfaceTexture;"
        ")"
        "V",
        &g_ChildProcessServiceImpl_forwardSurfaceTextureForSurfaceRequest);

    env->CallVoidMethod(obj.obj(),
        method_id, requestToken.obj(), surfaceTexture.obj());
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_ChildProcessServiceImpl_getViewSurface = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_ChildProcessServiceImpl_getViewSurface(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper surfaceId)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChildProcessServiceImpl_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChildProcessServiceImpl_clazz(env),
        "getViewSurface",
        "("
        "I"
        ")"
        "Landroid/view/Surface;",
        &g_ChildProcessServiceImpl_getViewSurface);

    jobject ret = env->CallObjectMethod(obj.obj(),
        method_id, as_jint(surfaceId));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsChildProcessServiceImpl[] = {
    { "nativeRegisterGlobalFileDescriptor",
        "("
        "I"
        "I"
        "J"
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_content_app_ChildProcessServiceImpl_nativeRegisterGlobalFileDescriptor) },
    { "nativeInitChildProcessImpl",
        "("
        "Lorg/chromium/content/app/ChildProcessServiceImpl;"
        "I"
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_content_app_ChildProcessServiceImpl_nativeInitChildProcessImpl) },
    { "nativeExitChildProcess",
        "("
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_content_app_ChildProcessServiceImpl_nativeExitChildProcess) },
    { "nativeShutdownMainThread",
        "("
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_content_app_ChildProcessServiceImpl_nativeShutdownMainThread) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsChildProcessServiceImplSize = arraysize(kMethodsChildProcessServiceImpl);

    if (env->RegisterNatives(ChildProcessServiceImpl_clazz(env),
            kMethodsChildProcessServiceImpl,
            kMethodsChildProcessServiceImplSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, ChildProcessServiceImpl_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace content

#endif // org_chromium_content_app_ChildProcessServiceImpl_JNI
