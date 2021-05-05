// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/device/bluetooth/ChromeBluetoothRemoteGattDescriptor

#ifndef org_chromium_device_bluetooth_ChromeBluetoothRemoteGattDescriptor_JNI
#define org_chromium_device_bluetooth_ChromeBluetoothRemoteGattDescriptor_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kChromeBluetoothRemoteGattDescriptorClassPath[] = "org/chromium/device/bluetooth/ChromeBluetoothRemoteGattDescriptor";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_ChromeBluetoothRemoteGattDescriptor_clazz
    __attribute__((unused))
    = 0;
#define ChromeBluetoothRemoteGattDescriptor_clazz(env) base::android::LazyGetClass(env, kChromeBluetoothRemoteGattDescriptorClassPath, &g_ChromeBluetoothRemoteGattDescriptor_clazz)

} // namespace

namespace device {

// Step 2: method stubs.
JNI_GENERATOR_EXPORT void
Java_org_chromium_device_bluetooth_ChromeBluetoothRemoteGattDescriptor_nativeOnRead(JNIEnv*
                                                                                        env,
    jobject jcaller,
    jlong nativeBluetoothRemoteGattDescriptorAndroid,
    jint status,
    jbyteArray value)
{
    BluetoothRemoteGattDescriptorAndroid* native = reinterpret_cast<BluetoothRemoteGattDescriptorAndroid*>(nativeBluetoothRemoteGattDescriptorAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "OnRead");
    return native->OnRead(env, base::android::JavaParamRef<jobject>(env, jcaller),
        status, base::android::JavaParamRef<jbyteArray>(env, value));
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_device_bluetooth_ChromeBluetoothRemoteGattDescriptor_nativeOnWrite(JNIEnv*
                                                                                         env,
    jobject jcaller,
    jlong nativeBluetoothRemoteGattDescriptorAndroid,
    jint status)
{
    BluetoothRemoteGattDescriptorAndroid* native = reinterpret_cast<BluetoothRemoteGattDescriptorAndroid*>(nativeBluetoothRemoteGattDescriptorAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "OnWrite");
    return native->OnWrite(env, base::android::JavaParamRef<jobject>(env, jcaller), status);
}

static base::subtle::AtomicWord
    g_ChromeBluetoothRemoteGattDescriptor_onBluetoothRemoteGattDescriptorAndroidDestruction
    = 0;
static void
Java_ChromeBluetoothRemoteGattDescriptor_onBluetoothRemoteGattDescriptorAndroidDestruction(JNIEnv*
                                                                                               env,
    const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeBluetoothRemoteGattDescriptor_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeBluetoothRemoteGattDescriptor_clazz(env),
        "onBluetoothRemoteGattDescriptorAndroidDestruction",
        "("
        ")"
        "V",
        &g_ChromeBluetoothRemoteGattDescriptor_onBluetoothRemoteGattDescriptorAndroidDestruction);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_ChromeBluetoothRemoteGattDescriptor_create = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_ChromeBluetoothRemoteGattDescriptor_create(JNIEnv* env, jlong nativeBluetoothRemoteGattDescriptorAndroid,
    const base::android::JavaRefOrBare<jobject>& bluetoothGattDescriptorWrapper,
    const base::android::JavaRefOrBare<jobject>& chromeDevice)
{
    CHECK_CLAZZ(env, ChromeBluetoothRemoteGattDescriptor_clazz(env),
        ChromeBluetoothRemoteGattDescriptor_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, ChromeBluetoothRemoteGattDescriptor_clazz(env),
        "create",
        "("
        "J"
        "Ljava/lang/Object;"
        "Lorg/chromium/device/bluetooth/ChromeBluetoothDevice;"
        ")"
        "Lorg/chromium/device/bluetooth/ChromeBluetoothRemoteGattDescriptor;",
        &g_ChromeBluetoothRemoteGattDescriptor_create);

    jobject ret = env->CallStaticObjectMethod(ChromeBluetoothRemoteGattDescriptor_clazz(env),
        method_id, nativeBluetoothRemoteGattDescriptorAndroid,
        bluetoothGattDescriptorWrapper.obj(), chromeDevice.obj());
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_ChromeBluetoothRemoteGattDescriptor_getUUID = 0;
static base::android::ScopedJavaLocalRef<jstring>
Java_ChromeBluetoothRemoteGattDescriptor_getUUID(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeBluetoothRemoteGattDescriptor_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeBluetoothRemoteGattDescriptor_clazz(env),
        "getUUID",
        "("
        ")"
        "Ljava/lang/String;",
        &g_ChromeBluetoothRemoteGattDescriptor_getUUID);

    jstring ret = static_cast<jstring>(env->CallObjectMethod(obj.obj(),
        method_id));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord
    g_ChromeBluetoothRemoteGattDescriptor_readRemoteDescriptor
    = 0;
static jboolean
Java_ChromeBluetoothRemoteGattDescriptor_readRemoteDescriptor(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeBluetoothRemoteGattDescriptor_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeBluetoothRemoteGattDescriptor_clazz(env),
        "readRemoteDescriptor",
        "("
        ")"
        "Z",
        &g_ChromeBluetoothRemoteGattDescriptor_readRemoteDescriptor);

    jboolean ret = env->CallBooleanMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord
    g_ChromeBluetoothRemoteGattDescriptor_writeRemoteDescriptor
    = 0;
static jboolean
Java_ChromeBluetoothRemoteGattDescriptor_writeRemoteDescriptor(JNIEnv* env,
    const base::android::JavaRefOrBare<jobject>& obj, const base::android::JavaRefOrBare<jbyteArray>& value)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeBluetoothRemoteGattDescriptor_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeBluetoothRemoteGattDescriptor_clazz(env),
        "writeRemoteDescriptor",
        "("
        "[B"
        ")"
        "Z",
        &g_ChromeBluetoothRemoteGattDescriptor_writeRemoteDescriptor);

    jboolean ret = env->CallBooleanMethod(obj.obj(),
        method_id, value.obj());
    jni_generator::CheckException(env);
    return ret;
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsChromeBluetoothRemoteGattDescriptor[] = {
    { "nativeOnRead",
        "("
        "J"
        "I"
        "[B"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_device_bluetooth_ChromeBluetoothRemoteGattDescriptor_nativeOnRead) },
    { "nativeOnWrite",
        "("
        "J"
        "I"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_device_bluetooth_ChromeBluetoothRemoteGattDescriptor_nativeOnWrite) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsChromeBluetoothRemoteGattDescriptorSize = arraysize(kMethodsChromeBluetoothRemoteGattDescriptor);

    if (env->RegisterNatives(ChromeBluetoothRemoteGattDescriptor_clazz(env),
            kMethodsChromeBluetoothRemoteGattDescriptor,
            kMethodsChromeBluetoothRemoteGattDescriptorSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, ChromeBluetoothRemoteGattDescriptor_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace device

#endif // org_chromium_device_bluetooth_ChromeBluetoothRemoteGattDescriptor_JNI
