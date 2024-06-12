// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/components/signin/ChildAccountInfoFetcher

#ifndef org_chromium_components_signin_ChildAccountInfoFetcher_JNI
#define org_chromium_components_signin_ChildAccountInfoFetcher_JNI

#include <jni.h>

#include "../../../../../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kChildAccountInfoFetcherClassPath[] = "org/chromium/components/signin/ChildAccountInfoFetcher";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_ChildAccountInfoFetcher_clazz __attribute__((unused))
= 0;
#define ChildAccountInfoFetcher_clazz(env) base::android::LazyGetClass(env, kChildAccountInfoFetcherClassPath, &g_ChildAccountInfoFetcher_clazz)

} // namespace

// Step 2: method stubs.

static void SetIsChildAccount(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
    jlong accountFetcherServicePtr,
    const base::android::JavaParamRef<jstring>& accountId,
    jboolean isChildAccount);

JNI_GENERATOR_EXPORT void
Java_org_chromium_components_signin_ChildAccountInfoFetcher_nativeSetIsChildAccount(JNIEnv*
                                                                                        env,
    jclass jcaller,
    jlong accountFetcherServicePtr,
    jstring accountId,
    jboolean isChildAccount)
{
    return SetIsChildAccount(env, base::android::JavaParamRef<jclass>(env, jcaller), accountFetcherServicePtr,
        base::android::JavaParamRef<jstring>(env, accountId), isChildAccount);
}

static base::subtle::AtomicWord g_ChildAccountInfoFetcher_create = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_ChildAccountInfoFetcher_create(JNIEnv* env, jlong nativeAccountFetcherService,
    const base::android::JavaRefOrBare<jstring>& accountId,
    const base::android::JavaRefOrBare<jstring>& accountName)
{
    CHECK_CLAZZ(env, ChildAccountInfoFetcher_clazz(env),
        ChildAccountInfoFetcher_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, ChildAccountInfoFetcher_clazz(env),
        "create",
        "("
        "J"
        "Ljava/lang/String;"
        "Ljava/lang/String;"
        ")"
        "Lorg/chromium/components/signin/ChildAccountInfoFetcher;",
        &g_ChildAccountInfoFetcher_create);

    jobject ret = env->CallStaticObjectMethod(ChildAccountInfoFetcher_clazz(env),
        method_id, nativeAccountFetcherService, accountId.obj(),
        accountName.obj());
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_ChildAccountInfoFetcher_destroy = 0;
static void Java_ChildAccountInfoFetcher_destroy(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChildAccountInfoFetcher_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChildAccountInfoFetcher_clazz(env),
        "destroy",
        "("
        ")"
        "V",
        &g_ChildAccountInfoFetcher_destroy);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsChildAccountInfoFetcher[] = {
    { "nativeSetIsChildAccount",
        "("
        "J"
        "Ljava/lang/String;"
        "Z"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_components_signin_ChildAccountInfoFetcher_nativeSetIsChildAccount) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsChildAccountInfoFetcherSize = arraysize(kMethodsChildAccountInfoFetcher);

    if (env->RegisterNatives(ChildAccountInfoFetcher_clazz(env),
            kMethodsChildAccountInfoFetcher,
            kMethodsChildAccountInfoFetcherSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, ChildAccountInfoFetcher_clazz(env), __FILE__);
        return false;
    }

    return true;
}

#endif // org_chromium_components_signin_ChildAccountInfoFetcher_JNI
