// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/content/browser/TracingControllerAndroid

#ifndef org_chromium_content_browser_TracingControllerAndroid_JNI
#define org_chromium_content_browser_TracingControllerAndroid_JNI

#include <jni.h>

#include "../../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kTracingControllerAndroidClassPath[] = "org/chromium/content/browser/TracingControllerAndroid";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_TracingControllerAndroid_clazz
    __attribute__((unused))
    = 0;
#define TracingControllerAndroid_clazz(env) base::android::LazyGetClass(env, kTracingControllerAndroidClassPath, &g_TracingControllerAndroid_clazz)

} // namespace

namespace content {

// Step 2: method stubs.

static jlong Init(JNIEnv* env, const base::android::JavaParamRef<jobject>& jcaller);

JNI_GENERATOR_EXPORT jlong
Java_org_chromium_content_browser_TracingControllerAndroid_nativeInit(JNIEnv*
                                                                          env,
    jobject jcaller)
{
    return Init(env, base::android::JavaParamRef<jobject>(env, jcaller));
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_content_browser_TracingControllerAndroid_nativeDestroy(JNIEnv*
                                                                             env,
    jobject jcaller,
    jlong nativeTracingControllerAndroid)
{
    TracingControllerAndroid* native = reinterpret_cast<TracingControllerAndroid*>(nativeTracingControllerAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "Destroy");
    return native->Destroy(env, base::android::JavaParamRef<jobject>(env, jcaller));
}

JNI_GENERATOR_EXPORT jboolean
Java_org_chromium_content_browser_TracingControllerAndroid_nativeStartTracing(JNIEnv*
                                                                                  env,
    jobject jcaller,
    jlong nativeTracingControllerAndroid,
    jstring categories,
    jstring traceOptions)
{
    TracingControllerAndroid* native = reinterpret_cast<TracingControllerAndroid*>(nativeTracingControllerAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "StartTracing", false);
    return native->StartTracing(env, base::android::JavaParamRef<jobject>(env, jcaller), base::android::JavaParamRef<jstring>(env, categories),
        base::android::JavaParamRef<jstring>(env, traceOptions));
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_content_browser_TracingControllerAndroid_nativeStopTracing(JNIEnv*
                                                                                 env,
    jobject jcaller,
    jlong nativeTracingControllerAndroid,
    jstring filename)
{
    TracingControllerAndroid* native = reinterpret_cast<TracingControllerAndroid*>(nativeTracingControllerAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "StopTracing");
    return native->StopTracing(env, base::android::JavaParamRef<jobject>(env, jcaller), base::android::JavaParamRef<jstring>(env, filename));
}

JNI_GENERATOR_EXPORT jboolean
Java_org_chromium_content_browser_TracingControllerAndroid_nativeGetKnownCategoryGroupsAsync(JNIEnv*
                                                                                                 env,
    jobject jcaller,
    jlong nativeTracingControllerAndroid)
{
    TracingControllerAndroid* native = reinterpret_cast<TracingControllerAndroid*>(nativeTracingControllerAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "GetKnownCategoryGroupsAsync", false);
    return native->GetKnownCategoryGroupsAsync(env,
        base::android::JavaParamRef<jobject>(env, jcaller));
}

static base::android::ScopedJavaLocalRef<jstring> GetDefaultCategories(JNIEnv*
                                                                           env,
    const base::android::JavaParamRef<jobject>& jcaller);

JNI_GENERATOR_EXPORT jstring
Java_org_chromium_content_browser_TracingControllerAndroid_nativeGetDefaultCategories(JNIEnv*
                                                                                          env,
    jobject jcaller)
{
    return GetDefaultCategories(env, base::android::JavaParamRef<jobject>(env, jcaller)).Release();
}

static base::subtle::AtomicWord
    g_TracingControllerAndroid_generateTracingFilePath
    = 0;
static base::android::ScopedJavaLocalRef<jstring>
Java_TracingControllerAndroid_generateTracingFilePath(JNIEnv* env)
{
    CHECK_CLAZZ(env, TracingControllerAndroid_clazz(env),
        TracingControllerAndroid_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, TracingControllerAndroid_clazz(env),
        "generateTracingFilePath",
        "("
        ")"
        "Ljava/lang/String;",
        &g_TracingControllerAndroid_generateTracingFilePath);

    jstring ret = static_cast<jstring>(env->CallStaticObjectMethod(TracingControllerAndroid_clazz(env),
        method_id));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_TracingControllerAndroid_onTracingStopped = 0;
static void Java_TracingControllerAndroid_onTracingStopped(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        TracingControllerAndroid_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, TracingControllerAndroid_clazz(env),
        "onTracingStopped",
        "("
        ")"
        "V",
        &g_TracingControllerAndroid_onTracingStopped);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsTracingControllerAndroid[] = {
    { "nativeInit",
        "("
        ")"
        "J",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_TracingControllerAndroid_nativeInit) },
    { "nativeDestroy",
        "("
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_TracingControllerAndroid_nativeDestroy) },
    { "nativeStartTracing",
        "("
        "J"
        "Ljava/lang/String;"
        "Ljava/lang/String;"
        ")"
        "Z",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_TracingControllerAndroid_nativeStartTracing) },
    { "nativeStopTracing",
        "("
        "J"
        "Ljava/lang/String;"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_TracingControllerAndroid_nativeStopTracing) },
    { "nativeGetKnownCategoryGroupsAsync",
        "("
        "J"
        ")"
        "Z",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_TracingControllerAndroid_nativeGetKnownCategoryGroupsAsync) },
    { "nativeGetDefaultCategories",
        "("
        ")"
        "Ljava/lang/String;",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_TracingControllerAndroid_nativeGetDefaultCategories) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsTracingControllerAndroidSize = arraysize(kMethodsTracingControllerAndroid);

    if (env->RegisterNatives(TracingControllerAndroid_clazz(env),
            kMethodsTracingControllerAndroid,
            kMethodsTracingControllerAndroidSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, TracingControllerAndroid_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace content

#endif // org_chromium_content_browser_TracingControllerAndroid_JNI
