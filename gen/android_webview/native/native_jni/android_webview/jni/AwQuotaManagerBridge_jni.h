// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/android_webview/AwQuotaManagerBridge

#ifndef org_chromium_android_webview_AwQuotaManagerBridge_JNI
#define org_chromium_android_webview_AwQuotaManagerBridge_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kAwQuotaManagerBridgeClassPath[] = "org/chromium/android_webview/AwQuotaManagerBridge";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_AwQuotaManagerBridge_clazz __attribute__((unused)) = 0;
#define AwQuotaManagerBridge_clazz(env) base::android::LazyGetClass(env, kAwQuotaManagerBridgeClassPath, &g_AwQuotaManagerBridge_clazz)

} // namespace

namespace android_webview {

// Step 2: method stubs.

static jlong GetDefaultNativeAwQuotaManagerBridge(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller);

JNI_GENERATOR_EXPORT jlong
Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeGetDefaultNativeAwQuotaManagerBridge(JNIEnv*
                                                                                                       env,
    jclass jcaller)
{
    return GetDefaultNativeAwQuotaManagerBridge(env,
        base::android::JavaParamRef<jclass>(env, jcaller));
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeInit(JNIEnv*
                                                                       env,
    jobject jcaller,
    jlong nativeAwQuotaManagerBridgeImpl)
{
    AwQuotaManagerBridgeImpl* native = reinterpret_cast<AwQuotaManagerBridgeImpl*>(nativeAwQuotaManagerBridgeImpl);
    CHECK_NATIVE_PTR(env, jcaller, native, "Init");
    return native->Init(env, base::android::JavaParamRef<jobject>(env, jcaller));
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeDeleteAllData(JNIEnv*
                                                                                env,
    jobject jcaller,
    jlong nativeAwQuotaManagerBridgeImpl)
{
    AwQuotaManagerBridgeImpl* native = reinterpret_cast<AwQuotaManagerBridgeImpl*>(nativeAwQuotaManagerBridgeImpl);
    CHECK_NATIVE_PTR(env, jcaller, native, "DeleteAllData");
    return native->DeleteAllData(env, base::android::JavaParamRef<jobject>(env, jcaller));
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeDeleteOrigin(JNIEnv*
                                                                               env,
    jobject jcaller,
    jlong nativeAwQuotaManagerBridgeImpl,
    jstring origin)
{
    AwQuotaManagerBridgeImpl* native = reinterpret_cast<AwQuotaManagerBridgeImpl*>(nativeAwQuotaManagerBridgeImpl);
    CHECK_NATIVE_PTR(env, jcaller, native, "DeleteOrigin");
    return native->DeleteOrigin(env, base::android::JavaParamRef<jobject>(env, jcaller), base::android::JavaParamRef<jstring>(env, origin));
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeGetOrigins(JNIEnv*
                                                                             env,
    jobject jcaller,
    jlong nativeAwQuotaManagerBridgeImpl,
    jint callbackId)
{
    AwQuotaManagerBridgeImpl* native = reinterpret_cast<AwQuotaManagerBridgeImpl*>(nativeAwQuotaManagerBridgeImpl);
    CHECK_NATIVE_PTR(env, jcaller, native, "GetOrigins");
    return native->GetOrigins(env, base::android::JavaParamRef<jobject>(env, jcaller), callbackId);
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeGetUsageAndQuotaForOrigin(JNIEnv*
                                                                                            env,
    jobject jcaller,
    jlong nativeAwQuotaManagerBridgeImpl,
    jstring origin,
    jint callbackId,
    jboolean isQuota)
{
    AwQuotaManagerBridgeImpl* native = reinterpret_cast<AwQuotaManagerBridgeImpl*>(nativeAwQuotaManagerBridgeImpl);
    CHECK_NATIVE_PTR(env, jcaller, native, "GetUsageAndQuotaForOrigin");
    return native->GetUsageAndQuotaForOrigin(env,
        base::android::JavaParamRef<jobject>(env, jcaller),
        base::android::JavaParamRef<jstring>(env, origin), callbackId, isQuota);
}

static base::subtle::AtomicWord g_AwQuotaManagerBridge_onGetOriginsCallback = 0;
static void Java_AwQuotaManagerBridge_onGetOriginsCallback(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper callbackId,
    const base::android::JavaRefOrBare<jobjectArray>& origin,
    const base::android::JavaRefOrBare<jlongArray>& usages,
    const base::android::JavaRefOrBare<jlongArray>& quotas)
{
    CHECK_CLAZZ(env, obj.obj(),
        AwQuotaManagerBridge_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, AwQuotaManagerBridge_clazz(env),
        "onGetOriginsCallback",
        "("
        "I"
        "[Ljava/lang/String;"
        "[J"
        "[J"
        ")"
        "V",
        &g_AwQuotaManagerBridge_onGetOriginsCallback);

    env->CallVoidMethod(obj.obj(),
        method_id, as_jint(callbackId), origin.obj(), usages.obj(),
        quotas.obj());
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord
    g_AwQuotaManagerBridge_onGetUsageAndQuotaForOriginCallback
    = 0;
static void
Java_AwQuotaManagerBridge_onGetUsageAndQuotaForOriginCallback(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper callbackId,
    jboolean isQuota,
    jlong usage,
    jlong quota)
{
    CHECK_CLAZZ(env, obj.obj(),
        AwQuotaManagerBridge_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, AwQuotaManagerBridge_clazz(env),
        "onGetUsageAndQuotaForOriginCallback",
        "("
        "I"
        "Z"
        "J"
        "J"
        ")"
        "V",
        &g_AwQuotaManagerBridge_onGetUsageAndQuotaForOriginCallback);

    env->CallVoidMethod(obj.obj(),
        method_id, as_jint(callbackId), isQuota, usage, quota);
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsAwQuotaManagerBridge[] = {
    { "nativeGetDefaultNativeAwQuotaManagerBridge",
        "("
        ")"
        "J",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeGetDefaultNativeAwQuotaManagerBridge) },
    { "nativeInit",
        "("
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeInit) },
    { "nativeDeleteAllData",
        "("
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeDeleteAllData) },
    { "nativeDeleteOrigin",
        "("
        "J"
        "Ljava/lang/String;"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeDeleteOrigin) },
    { "nativeGetOrigins",
        "("
        "J"
        "I"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeGetOrigins) },
    { "nativeGetUsageAndQuotaForOrigin",
        "("
        "J"
        "Ljava/lang/String;"
        "I"
        "Z"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwQuotaManagerBridge_nativeGetUsageAndQuotaForOrigin) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsAwQuotaManagerBridgeSize = arraysize(kMethodsAwQuotaManagerBridge);

    if (env->RegisterNatives(AwQuotaManagerBridge_clazz(env),
            kMethodsAwQuotaManagerBridge,
            kMethodsAwQuotaManagerBridgeSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, AwQuotaManagerBridge_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace android_webview

#endif // org_chromium_android_webview_AwQuotaManagerBridge_JNI
