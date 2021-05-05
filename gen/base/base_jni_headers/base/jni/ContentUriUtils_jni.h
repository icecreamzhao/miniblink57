// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/base/ContentUriUtils

#ifndef org_chromium_base_ContentUriUtils_JNI
#define org_chromium_base_ContentUriUtils_JNI

#include <jni.h>

#include "../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kContentUriUtilsClassPath[] = "org/chromium/base/ContentUriUtils";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_ContentUriUtils_clazz __attribute__((unused)) = 0;
#define ContentUriUtils_clazz(env) base::android::LazyGetClass(env, kContentUriUtilsClassPath, &g_ContentUriUtils_clazz)

} // namespace

// Step 2: method stubs.

static base::subtle::AtomicWord g_ContentUriUtils_openContentUriForRead = 0;
static jint Java_ContentUriUtils_openContentUriForRead(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context,
    const base::android::JavaRefOrBare<jstring>& uriString)
{
    CHECK_CLAZZ(env, ContentUriUtils_clazz(env),
        ContentUriUtils_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, ContentUriUtils_clazz(env),
        "openContentUriForRead",
        "("
        "Landroid/content/Context;"
        "Ljava/lang/String;"
        ")"
        "I",
        &g_ContentUriUtils_openContentUriForRead);

    jint ret = env->CallStaticIntMethod(ContentUriUtils_clazz(env),
        method_id, context.obj(), uriString.obj());
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_ContentUriUtils_contentUriExists = 0;
static jboolean Java_ContentUriUtils_contentUriExists(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context,
    const base::android::JavaRefOrBare<jstring>& uriString)
{
    CHECK_CLAZZ(env, ContentUriUtils_clazz(env),
        ContentUriUtils_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, ContentUriUtils_clazz(env),
        "contentUriExists",
        "("
        "Landroid/content/Context;"
        "Ljava/lang/String;"
        ")"
        "Z",
        &g_ContentUriUtils_contentUriExists);

    jboolean ret = env->CallStaticBooleanMethod(ContentUriUtils_clazz(env),
        method_id, context.obj(), uriString.obj());
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_ContentUriUtils_getMimeType = 0;
static base::android::ScopedJavaLocalRef<jstring>
Java_ContentUriUtils_getMimeType(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context,
    const base::android::JavaRefOrBare<jstring>& uriString)
{
    CHECK_CLAZZ(env, ContentUriUtils_clazz(env),
        ContentUriUtils_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, ContentUriUtils_clazz(env),
        "getMimeType",
        "("
        "Landroid/content/Context;"
        "Ljava/lang/String;"
        ")"
        "Ljava/lang/String;",
        &g_ContentUriUtils_getMimeType);

    jstring ret = static_cast<jstring>(env->CallStaticObjectMethod(ContentUriUtils_clazz(env),
        method_id, context.obj(), uriString.obj()));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

// Step 3: RegisterNatives.

#endif // org_chromium_base_ContentUriUtils_JNI
