// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/base/JNIUtils

#ifndef org_chromium_base_JNIUtils_JNI
#define org_chromium_base_JNIUtils_JNI

#include <jni.h>

#include "../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kJNIUtilsClassPath[] = "org/chromium/base/JNIUtils";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_JNIUtils_clazz __attribute__((unused)) = 0;
#define JNIUtils_clazz(env) base::android::LazyGetClass(env, kJNIUtilsClassPath, &g_JNIUtils_clazz)

} // namespace

// Step 2: method stubs.

static base::subtle::AtomicWord g_JNIUtils_getClassLoader = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_JNIUtils_getClassLoader(JNIEnv* env)
{
    CHECK_CLAZZ(env, JNIUtils_clazz(env),
        JNIUtils_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, JNIUtils_clazz(env),
        "getClassLoader",
        "("
        ")"
        "Ljava/lang/Object;",
        &g_JNIUtils_getClassLoader);

    jobject ret = env->CallStaticObjectMethod(JNIUtils_clazz(env),
        method_id);
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

// Step 3: RegisterNatives.

#endif // org_chromium_base_JNIUtils_JNI
