// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/base/Callback

#ifndef org_chromium_base_Callback_JNI
#define org_chromium_base_Callback_JNI

#include <jni.h>

#include "../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kCallbackClassPath[] = "org/chromium/base/Callback";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_Callback_clazz __attribute__((unused)) = 0;
#define Callback_clazz(env) base::android::LazyGetClass(env, kCallbackClassPath, &g_Callback_clazz)

} // namespace

// Step 2: method stubs.

static base::subtle::AtomicWord g_Callback_onResultFromNativeV_JLO = 0;
static void Java_Callback_onResultFromNativeV_JLO(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, const base::android::JavaRefOrBare<jobject>& result)
{
    CHECK_CLAZZ(env, obj.obj(),
        Callback_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, Callback_clazz(env),
        "onResultFromNative",
        "("
        "Ljava/lang/Object;"
        ")"
        "V",
        &g_Callback_onResultFromNativeV_JLO);

    env->CallVoidMethod(obj.obj(),
        method_id, result.obj());
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_Callback_onResultFromNativeV_Z = 0;
static void Java_Callback_onResultFromNativeV_Z(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, jboolean result)
{
    CHECK_CLAZZ(env, obj.obj(),
        Callback_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, Callback_clazz(env),
        "onResultFromNative",
        "("
        "Z"
        ")"
        "V",
        &g_Callback_onResultFromNativeV_Z);

    env->CallVoidMethod(obj.obj(),
        method_id, result);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_Callback_onResultFromNativeV_I = 0;
static void Java_Callback_onResultFromNativeV_I(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper result)
{
    CHECK_CLAZZ(env, obj.obj(),
        Callback_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, Callback_clazz(env),
        "onResultFromNative",
        "("
        "I"
        ")"
        "V",
        &g_Callback_onResultFromNativeV_I);

    env->CallVoidMethod(obj.obj(),
        method_id, as_jint(result));
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

#endif // org_chromium_base_Callback_JNI
