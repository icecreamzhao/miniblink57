// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/midi/UsbMidiDeviceAndroid

#ifndef org_chromium_midi_UsbMidiDeviceAndroid_JNI
#define org_chromium_midi_UsbMidiDeviceAndroid_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kUsbMidiDeviceAndroidClassPath[] = "org/chromium/midi/UsbMidiDeviceAndroid";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_UsbMidiDeviceAndroid_clazz __attribute__((unused)) = 0;
#define UsbMidiDeviceAndroid_clazz(env) base::android::LazyGetClass(env, kUsbMidiDeviceAndroidClassPath, &g_UsbMidiDeviceAndroid_clazz)

} // namespace

namespace midi {

// Step 2: method stubs.
JNI_GENERATOR_EXPORT void
Java_org_chromium_midi_UsbMidiDeviceAndroid_nativeOnData(JNIEnv* env,
    jobject jcaller,
    jlong nativeUsbMidiDeviceAndroid,
    jint endpointNumber,
    jbyteArray data)
{
    UsbMidiDeviceAndroid* native = reinterpret_cast<UsbMidiDeviceAndroid*>(nativeUsbMidiDeviceAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "OnData");
    return native->OnData(env, base::android::JavaParamRef<jobject>(env, jcaller),
        endpointNumber, base::android::JavaParamRef<jbyteArray>(env, data));
}

static base::subtle::AtomicWord g_UsbMidiDeviceAndroid_registerSelf = 0;
static void Java_UsbMidiDeviceAndroid_registerSelf(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, jlong nativePointer)
{
    CHECK_CLAZZ(env, obj.obj(),
        UsbMidiDeviceAndroid_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, UsbMidiDeviceAndroid_clazz(env),
        "registerSelf",
        "("
        "J"
        ")"
        "V",
        &g_UsbMidiDeviceAndroid_registerSelf);

    env->CallVoidMethod(obj.obj(),
        method_id, nativePointer);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_UsbMidiDeviceAndroid_send = 0;
static void Java_UsbMidiDeviceAndroid_send(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper endpointNumber,
    const base::android::JavaRefOrBare<jbyteArray>& bs)
{
    CHECK_CLAZZ(env, obj.obj(),
        UsbMidiDeviceAndroid_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, UsbMidiDeviceAndroid_clazz(env),
        "send",
        "("
        "I"
        "[B"
        ")"
        "V",
        &g_UsbMidiDeviceAndroid_send);

    env->CallVoidMethod(obj.obj(),
        method_id, as_jint(endpointNumber), bs.obj());
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_UsbMidiDeviceAndroid_getDescriptors = 0;
static base::android::ScopedJavaLocalRef<jbyteArray>
Java_UsbMidiDeviceAndroid_getDescriptors(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        UsbMidiDeviceAndroid_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, UsbMidiDeviceAndroid_clazz(env),
        "getDescriptors",
        "("
        ")"
        "[B",
        &g_UsbMidiDeviceAndroid_getDescriptors);

    jbyteArray ret = static_cast<jbyteArray>(env->CallObjectMethod(obj.obj(),
        method_id));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jbyteArray>(env, ret);
}

static base::subtle::AtomicWord g_UsbMidiDeviceAndroid_getStringDescriptor = 0;
static base::android::ScopedJavaLocalRef<jbyteArray>
Java_UsbMidiDeviceAndroid_getStringDescriptor(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, JniIntWrapper index)
{
    CHECK_CLAZZ(env, obj.obj(),
        UsbMidiDeviceAndroid_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, UsbMidiDeviceAndroid_clazz(env),
        "getStringDescriptor",
        "("
        "I"
        ")"
        "[B",
        &g_UsbMidiDeviceAndroid_getStringDescriptor);

    jbyteArray ret = static_cast<jbyteArray>(env->CallObjectMethod(obj.obj(),
        method_id, as_jint(index)));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jbyteArray>(env, ret);
}

static base::subtle::AtomicWord g_UsbMidiDeviceAndroid_close = 0;
static void Java_UsbMidiDeviceAndroid_close(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        UsbMidiDeviceAndroid_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, UsbMidiDeviceAndroid_clazz(env),
        "close",
        "("
        ")"
        "V",
        &g_UsbMidiDeviceAndroid_close);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsUsbMidiDeviceAndroid[] = {
    { "nativeOnData",
        "("
        "J"
        "I"
        "[B"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_midi_UsbMidiDeviceAndroid_nativeOnData) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsUsbMidiDeviceAndroidSize = arraysize(kMethodsUsbMidiDeviceAndroid);

    if (env->RegisterNatives(UsbMidiDeviceAndroid_clazz(env),
            kMethodsUsbMidiDeviceAndroid,
            kMethodsUsbMidiDeviceAndroidSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, UsbMidiDeviceAndroid_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace midi

#endif // org_chromium_midi_UsbMidiDeviceAndroid_JNI
