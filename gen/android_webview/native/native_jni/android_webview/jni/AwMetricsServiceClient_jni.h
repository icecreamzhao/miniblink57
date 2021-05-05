// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/android_webview/AwMetricsServiceClient

#ifndef org_chromium_android_webview_AwMetricsServiceClient_JNI
#define org_chromium_android_webview_AwMetricsServiceClient_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kAwMetricsServiceClientClassPath[] = "org/chromium/android_webview/AwMetricsServiceClient";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_AwMetricsServiceClient_clazz __attribute__((unused))
= 0;
#define AwMetricsServiceClient_clazz(env) base::android::LazyGetClass(env, kAwMetricsServiceClientClassPath, &g_AwMetricsServiceClient_clazz)

} // namespace

namespace android_webview {

// Step 2: method stubs.

static void SetMetricsEnabled(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
    jboolean enabled);

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwMetricsServiceClient_nativeSetMetricsEnabled(JNIEnv*
                                                                                      env,
    jclass jcaller,
    jboolean enabled)
{
    return SetMetricsEnabled(env, base::android::JavaParamRef<jclass>(env, jcaller), enabled);
}

static base::subtle::AtomicWord g_AwMetricsServiceClient_nativeInitialized = 0;
static void Java_AwMetricsServiceClient_nativeInitialized(JNIEnv* env)
{
    CHECK_CLAZZ(env, AwMetricsServiceClient_clazz(env),
        AwMetricsServiceClient_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, AwMetricsServiceClient_clazz(env),
        "nativeInitialized",
        "("
        ")"
        "V",
        &g_AwMetricsServiceClient_nativeInitialized);

    env->CallStaticVoidMethod(AwMetricsServiceClient_clazz(env),
        method_id);
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsAwMetricsServiceClient[] = {
    { "nativeSetMetricsEnabled",
        "("
        "Z"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwMetricsServiceClient_nativeSetMetricsEnabled) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsAwMetricsServiceClientSize = arraysize(kMethodsAwMetricsServiceClient);

    if (env->RegisterNatives(AwMetricsServiceClient_clazz(env),
            kMethodsAwMetricsServiceClient,
            kMethodsAwMetricsServiceClientSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, AwMetricsServiceClient_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace android_webview

#endif // org_chromium_android_webview_AwMetricsServiceClient_JNI
