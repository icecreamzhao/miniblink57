// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/base/EarlyTraceEvent

#ifndef org_chromium_base_EarlyTraceEvent_JNI
#define org_chromium_base_EarlyTraceEvent_JNI

#include <jni.h>

#include "../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kEarlyTraceEventClassPath[] = "org/chromium/base/EarlyTraceEvent";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_EarlyTraceEvent_clazz __attribute__((unused)) = 0;
#define EarlyTraceEvent_clazz(env) base::android::LazyGetClass(env, kEarlyTraceEventClassPath, &g_EarlyTraceEvent_clazz)

} // namespace

namespace base {
namespace android {

    // Step 2: method stubs.

    static void RecordEarlyEvent(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
        const base::android::JavaParamRef<jstring>& name,
        jlong beginTimeMs,
        jlong endTimeMs,
        jint threadId);

    JNI_GENERATOR_EXPORT void
    Java_org_chromium_base_EarlyTraceEvent_nativeRecordEarlyEvent(JNIEnv* env,
        jclass jcaller,
        jstring name,
        jlong beginTimeMs,
        jlong endTimeMs,
        jint threadId)
    {
        return RecordEarlyEvent(env, base::android::JavaParamRef<jclass>(env, jcaller), base::android::JavaParamRef<jstring>(env, name), beginTimeMs,
            endTimeMs, threadId);
    }

    // Step 3: RegisterNatives.

    static const JNINativeMethod kMethodsEarlyTraceEvent[] = {
        { "nativeRecordEarlyEvent",
            "("
            "Ljava/lang/String;"
            "J"
            "J"
            "I"
            ")"
            "V",
            reinterpret_cast<void*>(Java_org_chromium_base_EarlyTraceEvent_nativeRecordEarlyEvent) },
    };

    static bool RegisterNativesImpl(JNIEnv* env)
    {
        if (base::android::IsManualJniRegistrationDisabled())
            return true;

        const int kMethodsEarlyTraceEventSize = arraysize(kMethodsEarlyTraceEvent);

        if (env->RegisterNatives(EarlyTraceEvent_clazz(env),
                kMethodsEarlyTraceEvent,
                kMethodsEarlyTraceEventSize)
            < 0) {
            jni_generator::HandleRegistrationError(
                env, EarlyTraceEvent_clazz(env), __FILE__);
            return false;
        }

        return true;
    }

} // namespace android
} // namespace base

#endif // org_chromium_base_EarlyTraceEvent_JNI
