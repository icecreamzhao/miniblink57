// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/mojo/system/impl/WatcherImpl

#ifndef org_chromium_mojo_system_impl_WatcherImpl_JNI
#define org_chromium_mojo_system_impl_WatcherImpl_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kWatcherImplClassPath[] = "org/chromium/mojo/system/impl/WatcherImpl";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_WatcherImpl_clazz __attribute__((unused)) = 0;
#define WatcherImpl_clazz(env) base::android::LazyGetClass(env, kWatcherImplClassPath, &g_WatcherImpl_clazz)

} // namespace

namespace mojo {
namespace android {

    // Step 2: method stubs.

    static jlong CreateWatcher(JNIEnv* env, const base::android::JavaParamRef<jobject>& jcaller);

    JNI_GENERATOR_EXPORT jlong
    Java_org_chromium_mojo_system_impl_WatcherImpl_nativeCreateWatcher(JNIEnv*
                                                                           env,
        jobject jcaller)
    {
        return CreateWatcher(env, base::android::JavaParamRef<jobject>(env, jcaller));
    }

    static jint Start(JNIEnv* env, const base::android::JavaParamRef<jobject>& jcaller,
        jlong implPtr,
        jint mojoHandle,
        jint flags);

    JNI_GENERATOR_EXPORT jint
    Java_org_chromium_mojo_system_impl_WatcherImpl_nativeStart(JNIEnv* env,
        jobject jcaller,
        jlong implPtr,
        jint mojoHandle,
        jint flags)
    {
        return Start(env, base::android::JavaParamRef<jobject>(env, jcaller), implPtr,
            mojoHandle, flags);
    }

    static void Cancel(JNIEnv* env, const base::android::JavaParamRef<jobject>& jcaller,
        jlong implPtr);

    JNI_GENERATOR_EXPORT void
    Java_org_chromium_mojo_system_impl_WatcherImpl_nativeCancel(JNIEnv* env,
        jobject jcaller,
        jlong implPtr)
    {
        return Cancel(env, base::android::JavaParamRef<jobject>(env, jcaller),
            implPtr);
    }

    static void Delete(JNIEnv* env, const base::android::JavaParamRef<jobject>& jcaller,
        jlong implPtr);

    JNI_GENERATOR_EXPORT void
    Java_org_chromium_mojo_system_impl_WatcherImpl_nativeDelete(JNIEnv* env,
        jobject jcaller,
        jlong implPtr)
    {
        return Delete(env, base::android::JavaParamRef<jobject>(env, jcaller),
            implPtr);
    }

    static base::subtle::AtomicWord g_WatcherImpl_onHandleReady = 0;
    static void Java_WatcherImpl_onHandleReady(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper result)
    {
        CHECK_CLAZZ(env, obj.obj(),
            WatcherImpl_clazz(env));
        jmethodID method_id = base::android::MethodID::LazyGet<
            base::android::MethodID::TYPE_INSTANCE>(
            env, WatcherImpl_clazz(env),
            "onHandleReady",
            "("
            "I"
            ")"
            "V",
            &g_WatcherImpl_onHandleReady);

        env->CallVoidMethod(obj.obj(),
            method_id, as_jint(result));
        jni_generator::CheckException(env);
    }

    // Step 3: RegisterNatives.

    static const JNINativeMethod kMethodsWatcherImpl[] = {
        { "nativeCreateWatcher",
            "("
            ")"
            "J",
            reinterpret_cast<void*>(Java_org_chromium_mojo_system_impl_WatcherImpl_nativeCreateWatcher) },
        { "nativeStart",
            "("
            "J"
            "I"
            "I"
            ")"
            "I",
            reinterpret_cast<void*>(Java_org_chromium_mojo_system_impl_WatcherImpl_nativeStart) },
        { "nativeCancel",
            "("
            "J"
            ")"
            "V",
            reinterpret_cast<void*>(Java_org_chromium_mojo_system_impl_WatcherImpl_nativeCancel) },
        { "nativeDelete",
            "("
            "J"
            ")"
            "V",
            reinterpret_cast<void*>(Java_org_chromium_mojo_system_impl_WatcherImpl_nativeDelete) },
    };

    static bool RegisterNativesImpl(JNIEnv* env)
    {
        if (base::android::IsManualJniRegistrationDisabled())
            return true;

        const int kMethodsWatcherImplSize = arraysize(kMethodsWatcherImpl);

        if (env->RegisterNatives(WatcherImpl_clazz(env),
                kMethodsWatcherImpl,
                kMethodsWatcherImplSize)
            < 0) {
            jni_generator::HandleRegistrationError(
                env, WatcherImpl_clazz(env), __FILE__);
            return false;
        }

        return true;
    }

} // namespace android
} // namespace mojo

#endif // org_chromium_mojo_system_impl_WatcherImpl_JNI
