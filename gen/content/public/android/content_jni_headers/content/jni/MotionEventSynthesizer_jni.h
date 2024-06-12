// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/content/browser/MotionEventSynthesizer

#ifndef org_chromium_content_browser_MotionEventSynthesizer_JNI
#define org_chromium_content_browser_MotionEventSynthesizer_JNI

#include <jni.h>

#include "../../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kMotionEventSynthesizerClassPath[] = "org/chromium/content/browser/MotionEventSynthesizer";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_MotionEventSynthesizer_clazz __attribute__((unused))
= 0;
#define MotionEventSynthesizer_clazz(env) base::android::LazyGetClass(env, kMotionEventSynthesizerClassPath, &g_MotionEventSynthesizer_clazz)

} // namespace

namespace content {

// Step 2: method stubs.

static base::subtle::AtomicWord g_MotionEventSynthesizer_setPointer = 0;
static void Java_MotionEventSynthesizer_setPointer(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper index,
    JniIntWrapper x,
    JniIntWrapper y,
    JniIntWrapper id)
{
    CHECK_CLAZZ(env, obj.obj(),
        MotionEventSynthesizer_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, MotionEventSynthesizer_clazz(env),
        "setPointer",
        "("
        "I"
        "I"
        "I"
        "I"
        ")"
        "V",
        &g_MotionEventSynthesizer_setPointer);

    env->CallVoidMethod(obj.obj(),
        method_id, as_jint(index), as_jint(x), as_jint(y), as_jint(id));
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_MotionEventSynthesizer_setScrollDeltas = 0;
static void Java_MotionEventSynthesizer_setScrollDeltas(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper x,
    JniIntWrapper y,
    JniIntWrapper dx,
    JniIntWrapper dy)
{
    CHECK_CLAZZ(env, obj.obj(),
        MotionEventSynthesizer_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, MotionEventSynthesizer_clazz(env),
        "setScrollDeltas",
        "("
        "I"
        "I"
        "I"
        "I"
        ")"
        "V",
        &g_MotionEventSynthesizer_setScrollDeltas);

    env->CallVoidMethod(obj.obj(),
        method_id, as_jint(x), as_jint(y), as_jint(dx), as_jint(dy));
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_MotionEventSynthesizer_inject = 0;
static void Java_MotionEventSynthesizer_inject(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper action,
    JniIntWrapper pointerCount,
    jlong timeInMs)
{
    CHECK_CLAZZ(env, obj.obj(),
        MotionEventSynthesizer_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, MotionEventSynthesizer_clazz(env),
        "inject",
        "("
        "I"
        "I"
        "J"
        ")"
        "V",
        &g_MotionEventSynthesizer_inject);

    env->CallVoidMethod(obj.obj(),
        method_id, as_jint(action), as_jint(pointerCount), timeInMs);
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

} // namespace content

#endif // org_chromium_content_browser_MotionEventSynthesizer_JNI
