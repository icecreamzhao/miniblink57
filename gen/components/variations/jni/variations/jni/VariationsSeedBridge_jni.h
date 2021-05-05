// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/components/variations/firstrun/VariationsSeedBridge

#ifndef org_chromium_components_variations_firstrun_VariationsSeedBridge_JNI
#define org_chromium_components_variations_firstrun_VariationsSeedBridge_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kVariationsSeedBridgeClassPath[] = "org/chromium/components/variations/firstrun/VariationsSeedBridge";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_VariationsSeedBridge_clazz __attribute__((unused)) = 0;
#define VariationsSeedBridge_clazz(env) base::android::LazyGetClass(env, kVariationsSeedBridgeClassPath, &g_VariationsSeedBridge_clazz)

} // namespace

// Step 2: method stubs.

static base::subtle::AtomicWord g_VariationsSeedBridge_setVariationsFirstRunSeed
    = 0;
static void Java_VariationsSeedBridge_setVariationsFirstRunSeed(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& context,
    const base::android::JavaRefOrBare<jbyteArray>& rawSeed,
    const base::android::JavaRefOrBare<jstring>& signature,
    const base::android::JavaRefOrBare<jstring>& country,
    const base::android::JavaRefOrBare<jstring>& date,
    jboolean isGzipCompressed)
{
    CHECK_CLAZZ(env, VariationsSeedBridge_clazz(env),
        VariationsSeedBridge_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VariationsSeedBridge_clazz(env),
        "setVariationsFirstRunSeed",
        "("
        "Landroid/content/Context;"
        "[B"
        "Ljava/lang/String;"
        "Ljava/lang/String;"
        "Ljava/lang/String;"
        "Z"
        ")"
        "V",
        &g_VariationsSeedBridge_setVariationsFirstRunSeed);

    env->CallStaticVoidMethod(VariationsSeedBridge_clazz(env),
        method_id, context.obj(), rawSeed.obj(), signature.obj(),
        country.obj(), date.obj(), isGzipCompressed);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_VariationsSeedBridge_clearFirstRunPrefs = 0;
static void Java_VariationsSeedBridge_clearFirstRunPrefs(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context)
{
    CHECK_CLAZZ(env, VariationsSeedBridge_clazz(env),
        VariationsSeedBridge_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VariationsSeedBridge_clazz(env),
        "clearFirstRunPrefs",
        "("
        "Landroid/content/Context;"
        ")"
        "V",
        &g_VariationsSeedBridge_clearFirstRunPrefs);

    env->CallStaticVoidMethod(VariationsSeedBridge_clazz(env),
        method_id, context.obj());
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord
    g_VariationsSeedBridge_markVariationsSeedAsStored
    = 0;
static void Java_VariationsSeedBridge_markVariationsSeedAsStored(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& context)
{
    CHECK_CLAZZ(env, VariationsSeedBridge_clazz(env),
        VariationsSeedBridge_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VariationsSeedBridge_clazz(env),
        "markVariationsSeedAsStored",
        "("
        "Landroid/content/Context;"
        ")"
        "V",
        &g_VariationsSeedBridge_markVariationsSeedAsStored);

    env->CallStaticVoidMethod(VariationsSeedBridge_clazz(env),
        method_id, context.obj());
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord
    g_VariationsSeedBridge_getVariationsFirstRunSeedData
    = 0;
static base::android::ScopedJavaLocalRef<jbyteArray>
Java_VariationsSeedBridge_getVariationsFirstRunSeedData(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context)
{
    CHECK_CLAZZ(env, VariationsSeedBridge_clazz(env),
        VariationsSeedBridge_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VariationsSeedBridge_clazz(env),
        "getVariationsFirstRunSeedData",
        "("
        "Landroid/content/Context;"
        ")"
        "[B",
        &g_VariationsSeedBridge_getVariationsFirstRunSeedData);

    jbyteArray ret = static_cast<jbyteArray>(env->CallStaticObjectMethod(VariationsSeedBridge_clazz(env),
        method_id, context.obj()));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jbyteArray>(env, ret);
}

static base::subtle::AtomicWord
    g_VariationsSeedBridge_getVariationsFirstRunSeedSignature
    = 0;
static base::android::ScopedJavaLocalRef<jstring>
Java_VariationsSeedBridge_getVariationsFirstRunSeedSignature(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& context)
{
    CHECK_CLAZZ(env, VariationsSeedBridge_clazz(env),
        VariationsSeedBridge_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VariationsSeedBridge_clazz(env),
        "getVariationsFirstRunSeedSignature",
        "("
        "Landroid/content/Context;"
        ")"
        "Ljava/lang/String;",
        &g_VariationsSeedBridge_getVariationsFirstRunSeedSignature);

    jstring ret = static_cast<jstring>(env->CallStaticObjectMethod(VariationsSeedBridge_clazz(env),
        method_id, context.obj()));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord
    g_VariationsSeedBridge_getVariationsFirstRunSeedCountry
    = 0;
static base::android::ScopedJavaLocalRef<jstring>
Java_VariationsSeedBridge_getVariationsFirstRunSeedCountry(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& context)
{
    CHECK_CLAZZ(env, VariationsSeedBridge_clazz(env),
        VariationsSeedBridge_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VariationsSeedBridge_clazz(env),
        "getVariationsFirstRunSeedCountry",
        "("
        "Landroid/content/Context;"
        ")"
        "Ljava/lang/String;",
        &g_VariationsSeedBridge_getVariationsFirstRunSeedCountry);

    jstring ret = static_cast<jstring>(env->CallStaticObjectMethod(VariationsSeedBridge_clazz(env),
        method_id, context.obj()));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord
    g_VariationsSeedBridge_getVariationsFirstRunSeedDate
    = 0;
static base::android::ScopedJavaLocalRef<jstring>
Java_VariationsSeedBridge_getVariationsFirstRunSeedDate(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context)
{
    CHECK_CLAZZ(env, VariationsSeedBridge_clazz(env),
        VariationsSeedBridge_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VariationsSeedBridge_clazz(env),
        "getVariationsFirstRunSeedDate",
        "("
        "Landroid/content/Context;"
        ")"
        "Ljava/lang/String;",
        &g_VariationsSeedBridge_getVariationsFirstRunSeedDate);

    jstring ret = static_cast<jstring>(env->CallStaticObjectMethod(VariationsSeedBridge_clazz(env),
        method_id, context.obj()));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord
    g_VariationsSeedBridge_getVariationsFirstRunSeedIsGzipCompressed
    = 0;
static jboolean
Java_VariationsSeedBridge_getVariationsFirstRunSeedIsGzipCompressed(JNIEnv*
                                                                        env,
    const base::android::JavaRefOrBare<jobject>& context)
{
    CHECK_CLAZZ(env, VariationsSeedBridge_clazz(env),
        VariationsSeedBridge_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, VariationsSeedBridge_clazz(env),
        "getVariationsFirstRunSeedIsGzipCompressed",
        "("
        "Landroid/content/Context;"
        ")"
        "Z",
        &g_VariationsSeedBridge_getVariationsFirstRunSeedIsGzipCompressed);

    jboolean ret = env->CallStaticBooleanMethod(VariationsSeedBridge_clazz(env),
        method_id, context.obj());
    jni_generator::CheckException(env);
    return ret;
}

// Step 3: RegisterNatives.

#endif // org_chromium_components_variations_firstrun_VariationsSeedBridge_JNI
