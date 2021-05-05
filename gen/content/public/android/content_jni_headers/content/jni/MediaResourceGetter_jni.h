// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/content/browser/MediaResourceGetter

#ifndef org_chromium_content_browser_MediaResourceGetter_JNI
#define org_chromium_content_browser_MediaResourceGetter_JNI

#include <jni.h>

#include "../../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kMediaMetadataClassPath[] = "org/chromium/content/browser/MediaResourceGetter$MediaMetadata";
const char kMediaResourceGetterClassPath[] = "org/chromium/content/browser/MediaResourceGetter";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_MediaMetadata_clazz __attribute__((unused)) = 0;
#define MediaMetadata_clazz(env) base::android::LazyGetClass(env, kMediaMetadataClassPath, &g_MediaMetadata_clazz)
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_MediaResourceGetter_clazz __attribute__((unused)) = 0;
#define MediaResourceGetter_clazz(env) base::android::LazyGetClass(env, kMediaResourceGetterClassPath, &g_MediaResourceGetter_clazz)

} // namespace

namespace content {

// Step 2: method stubs.

static base::subtle::AtomicWord g_MediaMetadata_getDurationInMilliseconds = 0;
static jint Java_MediaMetadata_getDurationInMilliseconds(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        MediaMetadata_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, MediaMetadata_clazz(env),
        "getDurationInMilliseconds",
        "("
        ")"
        "I",
        &g_MediaMetadata_getDurationInMilliseconds);

    jint ret = env->CallIntMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_MediaMetadata_getWidth = 0;
static jint Java_MediaMetadata_getWidth(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        MediaMetadata_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, MediaMetadata_clazz(env),
        "getWidth",
        "("
        ")"
        "I",
        &g_MediaMetadata_getWidth);

    jint ret = env->CallIntMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_MediaMetadata_getHeight = 0;
static jint Java_MediaMetadata_getHeight(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        MediaMetadata_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, MediaMetadata_clazz(env),
        "getHeight",
        "("
        ")"
        "I",
        &g_MediaMetadata_getHeight);

    jint ret = env->CallIntMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_MediaMetadata_isSuccess = 0;
static jboolean Java_MediaMetadata_isSuccess(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        MediaMetadata_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, MediaMetadata_clazz(env),
        "isSuccess",
        "("
        ")"
        "Z",
        &g_MediaMetadata_isSuccess);

    jboolean ret = env->CallBooleanMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_MediaResourceGetter_extractMediaMetadata = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_MediaResourceGetter_extractMediaMetadata(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context,
    const base::android::JavaRefOrBare<jstring>& url,
    const base::android::JavaRefOrBare<jstring>& cookies,
    const base::android::JavaRefOrBare<jstring>& userAgent)
{
    CHECK_CLAZZ(env, MediaResourceGetter_clazz(env),
        MediaResourceGetter_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, MediaResourceGetter_clazz(env),
        "extractMediaMetadata",
        "("
        "Landroid/content/Context;"
        "Ljava/lang/String;"
        "Ljava/lang/String;"
        "Ljava/lang/String;"
        ")"
        "Lorg/chromium/content/browser/MediaResourceGetter$MediaMetadata;",
        &g_MediaResourceGetter_extractMediaMetadata);

    jobject ret = env->CallStaticObjectMethod(MediaResourceGetter_clazz(env),
        method_id, context.obj(), url.obj(), cookies.obj(), userAgent.obj());
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_MediaResourceGetter_extractMediaMetadataFromFd
    = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_MediaResourceGetter_extractMediaMetadataFromFd(JNIEnv* env,
    JniIntWrapper fd,
    jlong offset,
    jlong length)
{
    CHECK_CLAZZ(env, MediaResourceGetter_clazz(env),
        MediaResourceGetter_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, MediaResourceGetter_clazz(env),
        "extractMediaMetadataFromFd",
        "("
        "I"
        "J"
        "J"
        ")"
        "Lorg/chromium/content/browser/MediaResourceGetter$MediaMetadata;",
        &g_MediaResourceGetter_extractMediaMetadataFromFd);

    jobject ret = env->CallStaticObjectMethod(MediaResourceGetter_clazz(env),
        method_id, as_jint(fd), offset, length);
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

// Step 3: RegisterNatives.

} // namespace content

#endif // org_chromium_content_browser_MediaResourceGetter_JNI
