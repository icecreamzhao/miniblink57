// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/base/MemoryPressureListener

#ifndef org_chromium_base_MemoryPressureListener_JNI
#define org_chromium_base_MemoryPressureListener_JNI

#include <jni.h>

#include "../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kMemoryPressureListenerClassPath[] = "org/chromium/base/MemoryPressureListener";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_MemoryPressureListener_clazz __attribute__((unused))
= 0;
#define MemoryPressureListener_clazz(env) base::android::LazyGetClass(env, kMemoryPressureListenerClassPath, &g_MemoryPressureListener_clazz)

} // namespace

// Step 2: method stubs.

static void OnMemoryPressure(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
    jint memoryPressureType);

JNI_GENERATOR_EXPORT void
Java_org_chromium_base_MemoryPressureListener_nativeOnMemoryPressure(JNIEnv*
                                                                         env,
    jclass jcaller,
    jint memoryPressureType)
{
    return OnMemoryPressure(env, base::android::JavaParamRef<jclass>(env, jcaller), memoryPressureType);
}

static base::subtle::AtomicWord g_MemoryPressureListener_registerSystemCallback
    = 0;
static void Java_MemoryPressureListener_registerSystemCallback(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& context)
{
    CHECK_CLAZZ(env, MemoryPressureListener_clazz(env),
        MemoryPressureListener_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, MemoryPressureListener_clazz(env),
        "registerSystemCallback",
        "("
        "Landroid/content/Context;"
        ")"
        "V",
        &g_MemoryPressureListener_registerSystemCallback);

    env->CallStaticVoidMethod(MemoryPressureListener_clazz(env),
        method_id, context.obj());
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsMemoryPressureListener[] = {
    { "nativeOnMemoryPressure",
        "("
        "I"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_base_MemoryPressureListener_nativeOnMemoryPressure) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsMemoryPressureListenerSize = arraysize(kMethodsMemoryPressureListener);

    if (env->RegisterNatives(MemoryPressureListener_clazz(env),
            kMethodsMemoryPressureListener,
            kMethodsMemoryPressureListenerSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, MemoryPressureListener_clazz(env), __FILE__);
        return false;
    }

    return true;
}

#endif // org_chromium_base_MemoryPressureListener_JNI
