// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/android_webview/AwContentsLifecycleNotifier

#ifndef org_chromium_android_webview_AwContentsLifecycleNotifier_JNI
#define org_chromium_android_webview_AwContentsLifecycleNotifier_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kAwContentsLifecycleNotifierClassPath[] = "org/chromium/android_webview/AwContentsLifecycleNotifier";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_AwContentsLifecycleNotifier_clazz
    __attribute__((unused))
    = 0;
#define AwContentsLifecycleNotifier_clazz(env) base::android::LazyGetClass(env, kAwContentsLifecycleNotifierClassPath, &g_AwContentsLifecycleNotifier_clazz)

} // namespace

namespace android_webview {

// Step 2: method stubs.

static base::subtle::AtomicWord g_AwContentsLifecycleNotifier_onWebViewCreated = 0;
static void Java_AwContentsLifecycleNotifier_onWebViewCreated(JNIEnv* env)
{
    CHECK_CLAZZ(env, AwContentsLifecycleNotifier_clazz(env),
        AwContentsLifecycleNotifier_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, AwContentsLifecycleNotifier_clazz(env),
        "onWebViewCreated",
        "("
        ")"
        "V",
        &g_AwContentsLifecycleNotifier_onWebViewCreated);

    env->CallStaticVoidMethod(AwContentsLifecycleNotifier_clazz(env),
        method_id);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_AwContentsLifecycleNotifier_onWebViewDestroyed
    = 0;
static void Java_AwContentsLifecycleNotifier_onWebViewDestroyed(JNIEnv* env)
{
    CHECK_CLAZZ(env, AwContentsLifecycleNotifier_clazz(env),
        AwContentsLifecycleNotifier_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, AwContentsLifecycleNotifier_clazz(env),
        "onWebViewDestroyed",
        "("
        ")"
        "V",
        &g_AwContentsLifecycleNotifier_onWebViewDestroyed);

    env->CallStaticVoidMethod(AwContentsLifecycleNotifier_clazz(env),
        method_id);
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

} // namespace android_webview

#endif // org_chromium_android_webview_AwContentsLifecycleNotifier_JNI
