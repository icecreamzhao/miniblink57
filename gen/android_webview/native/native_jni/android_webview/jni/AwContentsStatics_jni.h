// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/android_webview/AwContentsStatics

#ifndef org_chromium_android_webview_AwContentsStatics_JNI
#define org_chromium_android_webview_AwContentsStatics_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kAwContentsStaticsClassPath[] = "org/chromium/android_webview/AwContentsStatics";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_AwContentsStatics_clazz __attribute__((unused)) = 0;
#define AwContentsStatics_clazz(env) base::android::LazyGetClass(env, kAwContentsStaticsClassPath, &g_AwContentsStatics_clazz)

} // namespace

namespace android_webview {

// Step 2: method stubs.

static void ClearClientCertPreferences(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
    const base::android::JavaParamRef<jobject>& callback);

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwContentsStatics_nativeClearClientCertPreferences(JNIEnv*
                                                                                          env,
    jclass jcaller,
    jobject callback)
{
    return ClearClientCertPreferences(env,
        base::android::JavaParamRef<jclass>(env, jcaller),
        base::android::JavaParamRef<jobject>(env, callback));
}

static base::android::ScopedJavaLocalRef<jstring>
GetUnreachableWebDataUrl(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller);

JNI_GENERATOR_EXPORT jstring
Java_org_chromium_android_1webview_AwContentsStatics_nativeGetUnreachableWebDataUrl(JNIEnv*
                                                                                        env,
    jclass jcaller)
{
    return GetUnreachableWebDataUrl(env, base::android::JavaParamRef<jclass>(env, jcaller)).Release();
}

static void SetLegacyCacheRemovalDelayForTest(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
    jlong timeoutMs);

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwContentsStatics_nativeSetLegacyCacheRemovalDelayForTest(JNIEnv*
                                                                                                 env,
    jclass jcaller,
    jlong timeoutMs)
{
    return SetLegacyCacheRemovalDelayForTest(env,
        base::android::JavaParamRef<jclass>(env, jcaller), timeoutMs);
}

static base::android::ScopedJavaLocalRef<jstring> GetProductVersion(JNIEnv* env,
    const base::android::JavaParamRef<jclass>& jcaller);

JNI_GENERATOR_EXPORT jstring
Java_org_chromium_android_1webview_AwContentsStatics_nativeGetProductVersion(JNIEnv*
                                                                                 env,
    jclass jcaller)
{
    return GetProductVersion(env, base::android::JavaParamRef<jclass>(env, jcaller)).Release();
}

static void SetServiceWorkerIoThreadClient(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
    const base::android::JavaParamRef<jobject>& ioThreadClient,
    const base::android::JavaParamRef<jobject>& browserContext);

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwContentsStatics_nativeSetServiceWorkerIoThreadClient(JNIEnv*
                                                                                              env,
    jclass jcaller,
    jobject ioThreadClient,
    jobject browserContext)
{
    return SetServiceWorkerIoThreadClient(env,
        base::android::JavaParamRef<jclass>(env, jcaller),
        base::android::JavaParamRef<jobject>(env, ioThreadClient),
        base::android::JavaParamRef<jobject>(env, browserContext));
}

static jboolean GetSafeBrowsingEnabled(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller);

JNI_GENERATOR_EXPORT jboolean
Java_org_chromium_android_1webview_AwContentsStatics_nativeGetSafeBrowsingEnabled(JNIEnv*
                                                                                      env,
    jclass jcaller)
{
    return GetSafeBrowsingEnabled(env, base::android::JavaParamRef<jclass>(env, jcaller));
}

static void SetSafeBrowsingEnabled(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
    jboolean enable);

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwContentsStatics_nativeSetSafeBrowsingEnabled(JNIEnv*
                                                                                      env,
    jclass jcaller,
    jboolean enable)
{
    return SetSafeBrowsingEnabled(env, base::android::JavaParamRef<jclass>(env, jcaller), enable);
}

static base::subtle::AtomicWord g_AwContentsStatics_clientCertificatesCleared = 0;
static void Java_AwContentsStatics_clientCertificatesCleared(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& callback)
{
    CHECK_CLAZZ(env, AwContentsStatics_clazz(env),
        AwContentsStatics_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, AwContentsStatics_clazz(env),
        "clientCertificatesCleared",
        "("
        "Ljava/lang/Runnable;"
        ")"
        "V",
        &g_AwContentsStatics_clientCertificatesCleared);

    env->CallStaticVoidMethod(AwContentsStatics_clazz(env),
        method_id, callback.obj());
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsAwContentsStatics[] = {
    { "nativeClearClientCertPreferences",
        "("
        "Ljava/lang/Runnable;"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwContentsStatics_nativeClearClientCertPreferences) },
    { "nativeGetUnreachableWebDataUrl",
        "("
        ")"
        "Ljava/lang/String;",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwContentsStatics_nativeGetUnreachableWebDataUrl) },
    { "nativeSetLegacyCacheRemovalDelayForTest",
        "("
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwContentsStatics_nativeSetLegacyCacheRemovalDelayForTest) },
    { "nativeGetProductVersion",
        "("
        ")"
        "Ljava/lang/String;",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwContentsStatics_nativeGetProductVersion) },
    { "nativeSetServiceWorkerIoThreadClient",
        "("
        "Lorg/chromium/android_webview/AwContentsIoThreadClient;"
        "Lorg/chromium/android_webview/AwBrowserContext;"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwContentsStatics_nativeSetServiceWorkerIoThreadClient) },
    { "nativeGetSafeBrowsingEnabled",
        "("
        ")"
        "Z",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwContentsStatics_nativeGetSafeBrowsingEnabled) },
    { "nativeSetSafeBrowsingEnabled",
        "("
        "Z"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwContentsStatics_nativeSetSafeBrowsingEnabled) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsAwContentsStaticsSize = arraysize(kMethodsAwContentsStatics);

    if (env->RegisterNatives(AwContentsStatics_clazz(env),
            kMethodsAwContentsStatics,
            kMethodsAwContentsStaticsSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, AwContentsStatics_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace android_webview

#endif // org_chromium_android_webview_AwContentsStatics_JNI
