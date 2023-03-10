// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/device/usb/ChromeUsbService

#ifndef org_chromium_device_usb_ChromeUsbService_JNI
#define org_chromium_device_usb_ChromeUsbService_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kChromeUsbServiceClassPath[] = "org/chromium/device/usb/ChromeUsbService";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_ChromeUsbService_clazz __attribute__((unused)) = 0;
#define ChromeUsbService_clazz(env) base::android::LazyGetClass(env, kChromeUsbServiceClassPath, &g_ChromeUsbService_clazz)

} // namespace

namespace device {

// Step 2: method stubs.
JNI_GENERATOR_EXPORT void
Java_org_chromium_device_usb_ChromeUsbService_nativeDeviceAttached(JNIEnv*
                                                                       env,
    jobject jcaller,
    jlong nativeUsbServiceAndroid,
    jobject device)
{
    UsbServiceAndroid* native = reinterpret_cast<UsbServiceAndroid*>(nativeUsbServiceAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "DeviceAttached");
    return native->DeviceAttached(env, base::android::JavaParamRef<jobject>(env, jcaller), base::android::JavaParamRef<jobject>(env, device));
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_device_usb_ChromeUsbService_nativeDeviceDetached(JNIEnv*
                                                                       env,
    jobject jcaller,
    jlong nativeUsbServiceAndroid,
    jint deviceId)
{
    UsbServiceAndroid* native = reinterpret_cast<UsbServiceAndroid*>(nativeUsbServiceAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "DeviceDetached");
    return native->DeviceDetached(env, base::android::JavaParamRef<jobject>(env, jcaller), deviceId);
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_device_usb_ChromeUsbService_nativeDevicePermissionRequestComplete(JNIEnv*
                                                                                        env,
    jobject jcaller,
    jlong nativeUsbServiceAndroid,
    jint deviceId,
    jboolean granted)
{
    UsbServiceAndroid* native = reinterpret_cast<UsbServiceAndroid*>(nativeUsbServiceAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "DevicePermissionRequestComplete");
    return native->DevicePermissionRequestComplete(env,
        base::android::JavaParamRef<jobject>(env, jcaller), deviceId, granted);
}

static base::subtle::AtomicWord g_ChromeUsbService_create = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_ChromeUsbService_create(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context,
    jlong usbServiceAndroid)
{
    CHECK_CLAZZ(env, ChromeUsbService_clazz(env),
        ChromeUsbService_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, ChromeUsbService_clazz(env),
        "create",
        "("
        "Landroid/content/Context;"
        "J"
        ")"
        "Lorg/chromium/device/usb/ChromeUsbService;",
        &g_ChromeUsbService_create);

    jobject ret = env->CallStaticObjectMethod(ChromeUsbService_clazz(env),
        method_id, context.obj(), usbServiceAndroid);
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_ChromeUsbService_getDevices = 0;
static base::android::ScopedJavaLocalRef<jobjectArray>
Java_ChromeUsbService_getDevices(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeUsbService_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeUsbService_clazz(env),
        "getDevices",
        "("
        ")"
        "[Ljava/lang/Object;",
        &g_ChromeUsbService_getDevices);

    jobjectArray ret = static_cast<jobjectArray>(env->CallObjectMethod(obj.obj(),
        method_id));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobjectArray>(env, ret);
}

static base::subtle::AtomicWord g_ChromeUsbService_openDevice = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_ChromeUsbService_openDevice(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, const base::android::JavaRefOrBare<jobject>& wrapper)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeUsbService_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeUsbService_clazz(env),
        "openDevice",
        "("
        "Lorg/chromium/device/usb/ChromeUsbDevice;"
        ")"
        "Landroid/hardware/usb/UsbDeviceConnection;",
        &g_ChromeUsbService_openDevice);

    jobject ret = env->CallObjectMethod(obj.obj(),
        method_id, wrapper.obj());
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_ChromeUsbService_requestDevicePermission = 0;
static void Java_ChromeUsbService_requestDevicePermission(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj, const base::android::JavaRefOrBare<jobject>& wrapper,
    jlong nativeCallback)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeUsbService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeUsbService_clazz(env),
        "requestDevicePermission",
        "("
        "Lorg/chromium/device/usb/ChromeUsbDevice;"
        "J"
        ")"
        "V",
        &g_ChromeUsbService_requestDevicePermission);

    env->CallVoidMethod(obj.obj(),
        method_id, wrapper.obj(), nativeCallback);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_ChromeUsbService_close = 0;
static void Java_ChromeUsbService_close(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeUsbService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeUsbService_clazz(env),
        "close",
        "("
        ")"
        "V",
        &g_ChromeUsbService_close);

    env->CallVoidMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsChromeUsbService[] = {
    { "nativeDeviceAttached",
        "("
        "J"
        "Landroid/hardware/usb/UsbDevice;"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_device_usb_ChromeUsbService_nativeDeviceAttached) },
    { "nativeDeviceDetached",
        "("
        "J"
        "I"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_device_usb_ChromeUsbService_nativeDeviceDetached) },
    { "nativeDevicePermissionRequestComplete",
        "("
        "J"
        "I"
        "Z"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_device_usb_ChromeUsbService_nativeDevicePermissionRequestComplete) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsChromeUsbServiceSize = arraysize(kMethodsChromeUsbService);

    if (env->RegisterNatives(ChromeUsbService_clazz(env),
            kMethodsChromeUsbService,
            kMethodsChromeUsbServiceSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, ChromeUsbService_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace device

#endif // org_chromium_device_usb_ChromeUsbService_JNI
