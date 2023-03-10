// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/content/browser/AppWebMessagePortService

#ifndef org_chromium_content_browser_AppWebMessagePortService_JNI
#define org_chromium_content_browser_AppWebMessagePortService_JNI

#include <jni.h>

#include "../../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kAppWebMessagePortServiceClassPath[] = "org/chromium/content/browser/AppWebMessagePortService";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_AppWebMessagePortService_clazz
    __attribute__((unused))
    = 0;
#define AppWebMessagePortService_clazz(env) base::android::LazyGetClass(env, kAppWebMessagePortServiceClassPath, &g_AppWebMessagePortService_clazz)

} // namespace

namespace content {

// Step 2: method stubs.

static jlong InitAppWebMessagePortService(JNIEnv* env, const base::android::JavaParamRef<jobject>& jcaller);

JNI_GENERATOR_EXPORT jlong
Java_org_chromium_content_browser_AppWebMessagePortService_nativeInitAppWebMessagePortService(JNIEnv*
                                                                                                  env,
    jobject jcaller)
{
    return InitAppWebMessagePortService(env,
        base::android::JavaParamRef<jobject>(env, jcaller));
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_content_browser_AppWebMessagePortService_nativePostAppToWebMessage(JNIEnv*
                                                                                         env,
    jobject jcaller,
    jlong nativeAppWebMessagePortServiceImpl,
    jint senderId,
    jstring message,
    jintArray portIds)
{
    AppWebMessagePortServiceImpl* native = reinterpret_cast<AppWebMessagePortServiceImpl*>(nativeAppWebMessagePortServiceImpl);
    CHECK_NATIVE_PTR(env, jcaller, native, "PostAppToWebMessage");
    return native->PostAppToWebMessage(env,
        base::android::JavaParamRef<jobject>(env, jcaller), senderId,
        base::android::JavaParamRef<jstring>(env, message),
        base::android::JavaParamRef<jintArray>(env, portIds));
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_content_browser_AppWebMessagePortService_nativeClosePort(JNIEnv*
                                                                               env,
    jobject jcaller,
    jlong nativeAppWebMessagePortServiceImpl,
    jint messagePortId)
{
    AppWebMessagePortServiceImpl* native = reinterpret_cast<AppWebMessagePortServiceImpl*>(nativeAppWebMessagePortServiceImpl);
    CHECK_NATIVE_PTR(env, jcaller, native, "ClosePort");
    return native->ClosePort(env, base::android::JavaParamRef<jobject>(env, jcaller), messagePortId);
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_content_browser_AppWebMessagePortService_nativeReleaseMessages(JNIEnv*
                                                                                     env,
    jobject jcaller,
    jlong nativeAppWebMessagePortServiceImpl,
    jint messagePortId)
{
    AppWebMessagePortServiceImpl* native = reinterpret_cast<AppWebMessagePortServiceImpl*>(nativeAppWebMessagePortServiceImpl);
    CHECK_NATIVE_PTR(env, jcaller, native, "ReleaseMessages");
    return native->ReleaseMessages(env, base::android::JavaParamRef<jobject>(env, jcaller), messagePortId);
}

static base::subtle::AtomicWord
    g_AppWebMessagePortService_onMessageChannelCreated
    = 0;
static void Java_AppWebMessagePortService_onMessageChannelCreated(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper portId1,
    JniIntWrapper portId2,
    const base::android::JavaRefOrBare<jobjectArray>& ports)
{
    CHECK_CLAZZ(env, obj.obj(),
        AppWebMessagePortService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, AppWebMessagePortService_clazz(env),
        "onMessageChannelCreated",
        "("
        "I"
        "I"
        "[Lorg/chromium/content/browser/AppWebMessagePort;"
        ")"
        "V",
        &g_AppWebMessagePortService_onMessageChannelCreated);

    env->CallVoidMethod(obj.obj(),
        method_id, as_jint(portId1), as_jint(portId2), ports.obj());
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_AppWebMessagePortService_onReceivedMessage = 0;
static void Java_AppWebMessagePortService_onReceivedMessage(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper portId,
    const base::android::JavaRefOrBare<jstring>& message,
    const base::android::JavaRefOrBare<jintArray>& ports)
{
    CHECK_CLAZZ(env, obj.obj(),
        AppWebMessagePortService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, AppWebMessagePortService_clazz(env),
        "onReceivedMessage",
        "("
        "I"
        "Ljava/lang/String;"
        "[I"
        ")"
        "V",
        &g_AppWebMessagePortService_onReceivedMessage);

    env->CallVoidMethod(obj.obj(),
        method_id, as_jint(portId), message.obj(), ports.obj());
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord
    g_AppWebMessagePortService_unregisterNativeAppWebMessagePortService
    = 0;
static void
Java_AppWebMessagePortService_unregisterNativeAppWebMessagePortService(JNIEnv*
                                                                           env,
    const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        AppWebMessagePortService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, AppWebMessagePortService_clazz(env),
        "unregisterNativeAppWebMessagePortService",
        "("
        ")"
        "V",
        &g_AppWebMessagePortService_unregisterNativeAppWebMessagePortService);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsAppWebMessagePortService[] = {
    { "nativeInitAppWebMessagePortService",
        "("
        ")"
        "J",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_AppWebMessagePortService_nativeInitAppWebMessagePortService) },
    { "nativePostAppToWebMessage",
        "("
        "J"
        "I"
        "Ljava/lang/String;"
        "[I"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_AppWebMessagePortService_nativePostAppToWebMessage) },
    { "nativeClosePort",
        "("
        "J"
        "I"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_AppWebMessagePortService_nativeClosePort) },
    { "nativeReleaseMessages",
        "("
        "J"
        "I"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_AppWebMessagePortService_nativeReleaseMessages) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsAppWebMessagePortServiceSize = arraysize(kMethodsAppWebMessagePortService);

    if (env->RegisterNatives(AppWebMessagePortService_clazz(env),
            kMethodsAppWebMessagePortService,
            kMethodsAppWebMessagePortServiceSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, AppWebMessagePortService_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace content

#endif // org_chromium_content_browser_AppWebMessagePortService_JNI
