// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/media/VideoCaptureFactory

#ifndef org_chromium_media_VideoCaptureFactory_JNI
#define org_chromium_media_VideoCaptureFactory_JNI

#include <jni.h>

#include "../../../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kVideoCaptureFactoryClassPath[] = "org/chromium/media/VideoCaptureFactory";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_VideoCaptureFactory_clazz __attribute__((unused)) = 0;
#define VideoCaptureFactory_clazz(env) base::android::LazyGetClass(env, kVideoCaptureFactoryClassPath, &g_VideoCaptureFactory_clazz)

} // namespace

namespace media {

// Step 2: method stubs.

static base::subtle::AtomicWord g_VideoCaptureFactory_isLegacyOrDeprecatedDevice
    = 0;
static jboolean Java_VideoCaptureFactory_isLegacyOrDeprecatedDevice(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& context,
    JniIntWrapper id)
{
    CHECK_CLAZZ(env, VideoCaptureFactory_clazz(env),
        VideoCaptureFactory_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VideoCaptureFactory_clazz(env),
        "isLegacyOrDeprecatedDevice",
        "("
        "Landroid/content/Context;"
        "I"
        ")"
        "Z",
        &g_VideoCaptureFactory_isLegacyOrDeprecatedDevice);

    jboolean ret = env->CallStaticBooleanMethod(VideoCaptureFactory_clazz(env),
        method_id, context.obj(), as_jint(id));
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_VideoCaptureFactory_createVideoCapture = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_VideoCaptureFactory_createVideoCapture(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context,
    JniIntWrapper id,
    jlong nativeVideoCaptureDeviceAndroid)
{
    CHECK_CLAZZ(env, VideoCaptureFactory_clazz(env),
        VideoCaptureFactory_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VideoCaptureFactory_clazz(env),
        "createVideoCapture",
        "("
        "Landroid/content/Context;"
        "I"
        "J"
        ")"
        "Lorg/chromium/media/VideoCapture;",
        &g_VideoCaptureFactory_createVideoCapture);

    jobject ret = env->CallStaticObjectMethod(VideoCaptureFactory_clazz(env),
        method_id, context.obj(), as_jint(id),
        nativeVideoCaptureDeviceAndroid);
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_VideoCaptureFactory_getNumberOfCameras = 0;
static jint Java_VideoCaptureFactory_getNumberOfCameras(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& appContext)
{
    CHECK_CLAZZ(env, VideoCaptureFactory_clazz(env),
        VideoCaptureFactory_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VideoCaptureFactory_clazz(env),
        "getNumberOfCameras",
        "("
        "Landroid/content/Context;"
        ")"
        "I",
        &g_VideoCaptureFactory_getNumberOfCameras);

    jint ret = env->CallStaticIntMethod(VideoCaptureFactory_clazz(env),
        method_id, appContext.obj());
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_VideoCaptureFactory_getCaptureApiType = 0;
static jint Java_VideoCaptureFactory_getCaptureApiType(JNIEnv* env,
    JniIntWrapper id,
    const base::android::JavaRefOrBare<jobject>& appContext)
{
    CHECK_CLAZZ(env, VideoCaptureFactory_clazz(env),
        VideoCaptureFactory_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VideoCaptureFactory_clazz(env),
        "getCaptureApiType",
        "("
        "I"
        "Landroid/content/Context;"
        ")"
        "I",
        &g_VideoCaptureFactory_getCaptureApiType);

    jint ret = env->CallStaticIntMethod(VideoCaptureFactory_clazz(env),
        method_id, as_jint(id), appContext.obj());
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_VideoCaptureFactory_getDeviceName = 0;
static base::android::ScopedJavaLocalRef<jstring>
Java_VideoCaptureFactory_getDeviceName(JNIEnv* env, JniIntWrapper id,
    const base::android::JavaRefOrBare<jobject>& appContext)
{
    CHECK_CLAZZ(env, VideoCaptureFactory_clazz(env),
        VideoCaptureFactory_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VideoCaptureFactory_clazz(env),
        "getDeviceName",
        "("
        "I"
        "Landroid/content/Context;"
        ")"
        "Ljava/lang/String;",
        &g_VideoCaptureFactory_getDeviceName);

    jstring ret = static_cast<jstring>(env->CallStaticObjectMethod(VideoCaptureFactory_clazz(env),
        method_id, as_jint(id), appContext.obj()));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_VideoCaptureFactory_getDeviceSupportedFormats
    = 0;
static base::android::ScopedJavaLocalRef<jobjectArray>
Java_VideoCaptureFactory_getDeviceSupportedFormats(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& appContext,
    JniIntWrapper id)
{
    CHECK_CLAZZ(env, VideoCaptureFactory_clazz(env),
        VideoCaptureFactory_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VideoCaptureFactory_clazz(env),
        "getDeviceSupportedFormats",
        "("
        "Landroid/content/Context;"
        "I"
        ")"
        "[Lorg/chromium/media/VideoCaptureFormat;",
        &g_VideoCaptureFactory_getDeviceSupportedFormats);

    jobjectArray ret = static_cast<jobjectArray>(env->CallStaticObjectMethod(VideoCaptureFactory_clazz(env),
        method_id, appContext.obj(), as_jint(id)));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobjectArray>(env, ret);
}

static base::subtle::AtomicWord g_VideoCaptureFactory_getCaptureFormatWidth = 0;
static jint Java_VideoCaptureFactory_getCaptureFormatWidth(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& format)
{
    CHECK_CLAZZ(env, VideoCaptureFactory_clazz(env),
        VideoCaptureFactory_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VideoCaptureFactory_clazz(env),
        "getCaptureFormatWidth",
        "("
        "Lorg/chromium/media/VideoCaptureFormat;"
        ")"
        "I",
        &g_VideoCaptureFactory_getCaptureFormatWidth);

    jint ret = env->CallStaticIntMethod(VideoCaptureFactory_clazz(env),
        method_id, format.obj());
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_VideoCaptureFactory_getCaptureFormatHeight = 0;
static jint Java_VideoCaptureFactory_getCaptureFormatHeight(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& format)
{
    CHECK_CLAZZ(env, VideoCaptureFactory_clazz(env),
        VideoCaptureFactory_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VideoCaptureFactory_clazz(env),
        "getCaptureFormatHeight",
        "("
        "Lorg/chromium/media/VideoCaptureFormat;"
        ")"
        "I",
        &g_VideoCaptureFactory_getCaptureFormatHeight);

    jint ret = env->CallStaticIntMethod(VideoCaptureFactory_clazz(env),
        method_id, format.obj());
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_VideoCaptureFactory_getCaptureFormatFramerate
    = 0;
static jint Java_VideoCaptureFactory_getCaptureFormatFramerate(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& format)
{
    CHECK_CLAZZ(env, VideoCaptureFactory_clazz(env),
        VideoCaptureFactory_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VideoCaptureFactory_clazz(env),
        "getCaptureFormatFramerate",
        "("
        "Lorg/chromium/media/VideoCaptureFormat;"
        ")"
        "I",
        &g_VideoCaptureFactory_getCaptureFormatFramerate);

    jint ret = env->CallStaticIntMethod(VideoCaptureFactory_clazz(env),
        method_id, format.obj());
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord
    g_VideoCaptureFactory_getCaptureFormatPixelFormat
    = 0;
static jint Java_VideoCaptureFactory_getCaptureFormatPixelFormat(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& format)
{
    CHECK_CLAZZ(env, VideoCaptureFactory_clazz(env),
        VideoCaptureFactory_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VideoCaptureFactory_clazz(env),
        "getCaptureFormatPixelFormat",
        "("
        "Lorg/chromium/media/VideoCaptureFormat;"
        ")"
        "I",
        &g_VideoCaptureFactory_getCaptureFormatPixelFormat);

    jint ret = env->CallStaticIntMethod(VideoCaptureFactory_clazz(env),
        method_id, format.obj());
    jni_generator::CheckException(env);
    return ret;
}

// Step 3: RegisterNatives.

} // namespace media

#endif // org_chromium_media_VideoCaptureFactory_JNI
