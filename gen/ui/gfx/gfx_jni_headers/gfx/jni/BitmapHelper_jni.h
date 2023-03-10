// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/ui/gfx/BitmapHelper

#ifndef org_chromium_ui_gfx_BitmapHelper_JNI
#define org_chromium_ui_gfx_BitmapHelper_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kBitmapHelperClassPath[] = "org/chromium/ui/gfx/BitmapHelper";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_BitmapHelper_clazz __attribute__((unused)) = 0;
#define BitmapHelper_clazz(env) base::android::LazyGetClass(env, kBitmapHelperClassPath, &g_BitmapHelper_clazz)

} // namespace

namespace gfx {

// Step 2: method stubs.

static base::subtle::AtomicWord g_BitmapHelper_createBitmap = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_BitmapHelper_createBitmap(JNIEnv* env, JniIntWrapper width,
    JniIntWrapper height,
    JniIntWrapper bitmapFormatValue)
{
    CHECK_CLAZZ(env, BitmapHelper_clazz(env),
        BitmapHelper_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, BitmapHelper_clazz(env),
        "createBitmap",
        "("
        "I"
        "I"
        "I"
        ")"
        "Landroid/graphics/Bitmap;",
        &g_BitmapHelper_createBitmap);

    jobject ret = env->CallStaticObjectMethod(BitmapHelper_clazz(env),
        method_id, as_jint(width), as_jint(height),
        as_jint(bitmapFormatValue));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_BitmapHelper_getBitmapFormatForConfig = 0;
static jint Java_BitmapHelper_getBitmapFormatForConfig(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& bitmapConfig)
{
    CHECK_CLAZZ(env, BitmapHelper_clazz(env),
        BitmapHelper_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, BitmapHelper_clazz(env),
        "getBitmapFormatForConfig",
        "("
        "Landroid/graphics/Bitmap$Config;"
        ")"
        "I",
        &g_BitmapHelper_getBitmapFormatForConfig);

    jint ret = env->CallStaticIntMethod(BitmapHelper_clazz(env),
        method_id, bitmapConfig.obj());
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_BitmapHelper_getByteCount = 0;
static jint Java_BitmapHelper_getByteCount(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& bitmap)
{
    CHECK_CLAZZ(env, BitmapHelper_clazz(env),
        BitmapHelper_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, BitmapHelper_clazz(env),
        "getByteCount",
        "("
        "Landroid/graphics/Bitmap;"
        ")"
        "I",
        &g_BitmapHelper_getByteCount);

    jint ret = env->CallStaticIntMethod(BitmapHelper_clazz(env),
        method_id, bitmap.obj());
    jni_generator::CheckException(env);
    return ret;
}

// Step 3: RegisterNatives.

} // namespace gfx

#endif // org_chromium_ui_gfx_BitmapHelper_JNI
