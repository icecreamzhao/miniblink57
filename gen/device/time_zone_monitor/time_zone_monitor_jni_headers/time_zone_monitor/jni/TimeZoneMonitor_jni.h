// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/device/time_zone_monitor/TimeZoneMonitor

#ifndef org_chromium_device_time_zone_monitor_TimeZoneMonitor_JNI
#define org_chromium_device_time_zone_monitor_TimeZoneMonitor_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kTimeZoneMonitorClassPath[] = "org/chromium/device/time_zone_monitor/TimeZoneMonitor";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_TimeZoneMonitor_clazz __attribute__((unused)) = 0;
#define TimeZoneMonitor_clazz(env) base::android::LazyGetClass(env, kTimeZoneMonitorClassPath, &g_TimeZoneMonitor_clazz)

} // namespace

namespace device {

// Step 2: method stubs.
JNI_GENERATOR_EXPORT void
Java_org_chromium_device_time_1zone_1monitor_TimeZoneMonitor_nativeTimeZoneChangedFromJava(JNIEnv*
                                                                                               env,
    jobject jcaller,
    jlong nativeTimeZoneMonitorAndroid)
{
    TimeZoneMonitorAndroid* native = reinterpret_cast<TimeZoneMonitorAndroid*>(nativeTimeZoneMonitorAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "TimeZoneChangedFromJava");
    return native->TimeZoneChangedFromJava(env,
        base::android::JavaParamRef<jobject>(env, jcaller));
}

static base::subtle::AtomicWord g_TimeZoneMonitor_getInstance = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_TimeZoneMonitor_getInstance(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context,
    jlong nativePtr)
{
    CHECK_CLAZZ(env, TimeZoneMonitor_clazz(env),
        TimeZoneMonitor_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, TimeZoneMonitor_clazz(env),
        "getInstance",
        "("
        "Landroid/content/Context;"
        "J"
        ")"
        "Lorg/chromium/device/time_zone_monitor/TimeZoneMonitor;",
        &g_TimeZoneMonitor_getInstance);

    jobject ret = env->CallStaticObjectMethod(TimeZoneMonitor_clazz(env),
        method_id, context.obj(), nativePtr);
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_TimeZoneMonitor_stop = 0;
static void Java_TimeZoneMonitor_stop(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        TimeZoneMonitor_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, TimeZoneMonitor_clazz(env),
        "stop",
        "("
        ")"
        "V",
        &g_TimeZoneMonitor_stop);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsTimeZoneMonitor[] = {
    { "nativeTimeZoneChangedFromJava",
        "("
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_device_time_1zone_1monitor_TimeZoneMonitor_nativeTimeZoneChangedFromJava) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsTimeZoneMonitorSize = arraysize(kMethodsTimeZoneMonitor);

    if (env->RegisterNatives(TimeZoneMonitor_clazz(env),
            kMethodsTimeZoneMonitor,
            kMethodsTimeZoneMonitorSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, TimeZoneMonitor_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace device

#endif // org_chromium_device_time_zone_monitor_TimeZoneMonitor_JNI
