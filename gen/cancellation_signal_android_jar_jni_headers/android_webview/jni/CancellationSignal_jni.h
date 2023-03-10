// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     android/os/CancellationSignal

#ifndef android_os_CancellationSignal_JNI
#define android_os_CancellationSignal_JNI

#include <jni.h>

#include "../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kCancellationSignalClassPath[] = "android/os/CancellationSignal";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_CancellationSignal_clazz __attribute__((unused)) = 0;
#define CancellationSignal_clazz(env) base::android::LazyGetClass(env, kCancellationSignalClassPath, &g_CancellationSignal_clazz)

} // namespace

namespace JNI_CancellationSignal {

// Step 2: method stubs.

static base::subtle::AtomicWord g_CancellationSignal_isCanceled = 0;
static jboolean Java_CancellationSignal_isCanceled(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj) __attribute__((unused));
static jboolean Java_CancellationSignal_isCanceled(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        CancellationSignal_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, CancellationSignal_clazz(env),
        "isCanceled",
        "()Z",
        &g_CancellationSignal_isCanceled);

    jboolean ret = env->CallBooleanMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_CancellationSignal_throwIfCanceled = 0;
static void Java_CancellationSignal_throwIfCanceled(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj) __attribute__((unused));
static void Java_CancellationSignal_throwIfCanceled(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        CancellationSignal_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, CancellationSignal_clazz(env),
        "throwIfCanceled",
        "()V",
        &g_CancellationSignal_throwIfCanceled);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_CancellationSignal_cancel = 0;
static void Java_CancellationSignal_cancel(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj) __attribute__((unused));
static void Java_CancellationSignal_cancel(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        CancellationSignal_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, CancellationSignal_clazz(env),
        "cancel",
        "()V",
        &g_CancellationSignal_cancel);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_CancellationSignal_setOnCancelListener = 0;
static void Java_CancellationSignal_setOnCancelListener(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, const base::android::JavaRefOrBare<jobject>& p0) __attribute__((unused));
static void Java_CancellationSignal_setOnCancelListener(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, const base::android::JavaRefOrBare<jobject>& p0)
{
    CHECK_CLAZZ(env, obj.obj(),
        CancellationSignal_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, CancellationSignal_clazz(env),
        "setOnCancelListener",
        "(Landroid/os/CancellationSignal$OnCancelListener;)V",
        &g_CancellationSignal_setOnCancelListener);

    env->CallVoidMethod(obj.obj(),
        method_id, p0.obj());
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_CancellationSignal_Constructor = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_CancellationSignal_Constructor(JNIEnv* env) __attribute__((unused));
static base::android::ScopedJavaLocalRef<jobject>
Java_CancellationSignal_Constructor(JNIEnv* env)
{
    CHECK_CLAZZ(env, CancellationSignal_clazz(env),
        CancellationSignal_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, CancellationSignal_clazz(env),
        "<init>",
        "()V",
        &g_CancellationSignal_Constructor);

    jobject ret = env->NewObject(CancellationSignal_clazz(env),
        method_id);
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

// Step 3: RegisterNatives.

} // namespace JNI_CancellationSignal

#endif // android_os_CancellationSignal_JNI
