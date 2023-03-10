// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/android_webview/AwDevToolsServer

#ifndef org_chromium_android_webview_AwDevToolsServer_JNI
#define org_chromium_android_webview_AwDevToolsServer_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kAwDevToolsServerClassPath[] = "org/chromium/android_webview/AwDevToolsServer";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_AwDevToolsServer_clazz __attribute__((unused)) = 0;
#define AwDevToolsServer_clazz(env) base::android::LazyGetClass(env, kAwDevToolsServerClassPath, &g_AwDevToolsServer_clazz)

} // namespace

namespace android_webview {

// Step 2: method stubs.

static jlong InitRemoteDebugging(JNIEnv* env, const base::android::JavaParamRef<jobject>& jcaller);

JNI_GENERATOR_EXPORT jlong
Java_org_chromium_android_1webview_AwDevToolsServer_nativeInitRemoteDebugging(JNIEnv*
                                                                                  env,
    jobject jcaller)
{
    return InitRemoteDebugging(env, base::android::JavaParamRef<jobject>(env, jcaller));
}

static void DestroyRemoteDebugging(JNIEnv* env, const base::android::JavaParamRef<jobject>& jcaller,
    jlong devToolsServer);

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwDevToolsServer_nativeDestroyRemoteDebugging(JNIEnv*
                                                                                     env,
    jobject jcaller,
    jlong devToolsServer)
{
    return DestroyRemoteDebugging(env, base::android::JavaParamRef<jobject>(env, jcaller), devToolsServer);
}

static void SetRemoteDebuggingEnabled(JNIEnv* env, const base::android::JavaParamRef<jobject>& jcaller,
    jlong devToolsServer,
    jboolean enabled);

JNI_GENERATOR_EXPORT void
Java_org_chromium_android_1webview_AwDevToolsServer_nativeSetRemoteDebuggingEnabled(JNIEnv*
                                                                                        env,
    jobject jcaller,
    jlong devToolsServer,
    jboolean enabled)
{
    return SetRemoteDebuggingEnabled(env,
        base::android::JavaParamRef<jobject>(env, jcaller), devToolsServer,
        enabled);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsAwDevToolsServer[] = {
    { "nativeInitRemoteDebugging",
        "("
        ")"
        "J",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwDevToolsServer_nativeInitRemoteDebugging) },
    { "nativeDestroyRemoteDebugging",
        "("
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwDevToolsServer_nativeDestroyRemoteDebugging) },
    { "nativeSetRemoteDebuggingEnabled",
        "("
        "J"
        "Z"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_android_1webview_AwDevToolsServer_nativeSetRemoteDebuggingEnabled) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsAwDevToolsServerSize = arraysize(kMethodsAwDevToolsServer);

    if (env->RegisterNatives(AwDevToolsServer_clazz(env),
            kMethodsAwDevToolsServer,
            kMethodsAwDevToolsServerSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, AwDevToolsServer_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace android_webview

#endif // org_chromium_android_webview_AwDevToolsServer_JNI
