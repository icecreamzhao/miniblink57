// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/base/SystemMessageHandler

#ifndef org_chromium_base_SystemMessageHandler_JNI
#define org_chromium_base_SystemMessageHandler_JNI

#include <jni.h>

#include "../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kSystemMessageHandlerClassPath[] = "org/chromium/base/SystemMessageHandler";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_SystemMessageHandler_clazz __attribute__((unused)) = 0;
#define SystemMessageHandler_clazz(env) base::android::LazyGetClass(env, kSystemMessageHandlerClassPath, &g_SystemMessageHandler_clazz)

} // namespace

// Step 2: method stubs.

static void DoRunLoopOnce(JNIEnv* env, const base::android::JavaParamRef<jobject>& jcaller,
    jlong messagePumpDelegateNative,
    jlong messagePumpNative,
    jlong delayedScheduledTimeTicks);

JNI_GENERATOR_EXPORT void
Java_org_chromium_base_SystemMessageHandler_nativeDoRunLoopOnce(JNIEnv* env,
    jobject jcaller,
    jlong messagePumpDelegateNative,
    jlong messagePumpNative,
    jlong delayedScheduledTimeTicks)
{
    return DoRunLoopOnce(env, base::android::JavaParamRef<jobject>(env, jcaller),
        messagePumpDelegateNative, messagePumpNative, delayedScheduledTimeTicks);
}

static base::subtle::AtomicWord g_SystemMessageHandler_scheduleWork = 0;
static void Java_SystemMessageHandler_scheduleWork(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        SystemMessageHandler_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, SystemMessageHandler_clazz(env),
        "scheduleWork",
        "("
        ")"
        "V",
        &g_SystemMessageHandler_scheduleWork);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_SystemMessageHandler_scheduleDelayedWork = 0;
static void Java_SystemMessageHandler_scheduleDelayedWork(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, jlong delayedTimeTicks,
    jlong millis)
{
    CHECK_CLAZZ(env, obj.obj(),
        SystemMessageHandler_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, SystemMessageHandler_clazz(env),
        "scheduleDelayedWork",
        "("
        "J"
        "J"
        ")"
        "V",
        &g_SystemMessageHandler_scheduleDelayedWork);

    env->CallVoidMethod(obj.obj(),
        method_id, delayedTimeTicks, millis);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_SystemMessageHandler_removeAllPendingMessages
    = 0;
static void Java_SystemMessageHandler_removeAllPendingMessages(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        SystemMessageHandler_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, SystemMessageHandler_clazz(env),
        "removeAllPendingMessages",
        "("
        ")"
        "V",
        &g_SystemMessageHandler_removeAllPendingMessages);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_SystemMessageHandler_create = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_SystemMessageHandler_create(JNIEnv* env, jlong messagePumpDelegateNative,
    jlong messagePumpNative)
{
    CHECK_CLAZZ(env, SystemMessageHandler_clazz(env),
        SystemMessageHandler_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, SystemMessageHandler_clazz(env),
        "create",
        "("
        "J"
        "J"
        ")"
        "Lorg/chromium/base/SystemMessageHandler;",
        &g_SystemMessageHandler_create);

    jobject ret = env->CallStaticObjectMethod(SystemMessageHandler_clazz(env),
        method_id, messagePumpDelegateNative, messagePumpNative);
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsSystemMessageHandler[] = {
    { "nativeDoRunLoopOnce",
        "("
        "J"
        "J"
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_base_SystemMessageHandler_nativeDoRunLoopOnce) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsSystemMessageHandlerSize = arraysize(kMethodsSystemMessageHandler);

    if (env->RegisterNatives(SystemMessageHandler_clazz(env),
            kMethodsSystemMessageHandler,
            kMethodsSystemMessageHandlerSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, SystemMessageHandler_clazz(env), __FILE__);
        return false;
    }

    return true;
}

#endif // org_chromium_base_SystemMessageHandler_JNI
