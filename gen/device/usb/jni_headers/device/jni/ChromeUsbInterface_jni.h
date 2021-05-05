// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/device/usb/ChromeUsbInterface

#ifndef org_chromium_device_usb_ChromeUsbInterface_JNI
#define org_chromium_device_usb_ChromeUsbInterface_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kChromeUsbInterfaceClassPath[] = "org/chromium/device/usb/ChromeUsbInterface";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_ChromeUsbInterface_clazz __attribute__((unused)) = 0;
#define ChromeUsbInterface_clazz(env) base::android::LazyGetClass(env, kChromeUsbInterfaceClassPath, &g_ChromeUsbInterface_clazz)

} // namespace

namespace device {

// Step 2: method stubs.

static base::subtle::AtomicWord g_ChromeUsbInterface_create = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_ChromeUsbInterface_create(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& iface)
{
    CHECK_CLAZZ(env, ChromeUsbInterface_clazz(env),
        ChromeUsbInterface_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, ChromeUsbInterface_clazz(env),
        "create",
        "("
        "Landroid/hardware/usb/UsbInterface;"
        ")"
        "Lorg/chromium/device/usb/ChromeUsbInterface;",
        &g_ChromeUsbInterface_create);

    jobject ret = env->CallStaticObjectMethod(ChromeUsbInterface_clazz(env),
        method_id, iface.obj());
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_ChromeUsbInterface_getInterfaceNumber = 0;
static jint Java_ChromeUsbInterface_getInterfaceNumber(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeUsbInterface_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeUsbInterface_clazz(env),
        "getInterfaceNumber",
        "("
        ")"
        "I",
        &g_ChromeUsbInterface_getInterfaceNumber);

    jint ret = env->CallIntMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_ChromeUsbInterface_getAlternateSetting = 0;
static jint Java_ChromeUsbInterface_getAlternateSetting(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeUsbInterface_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeUsbInterface_clazz(env),
        "getAlternateSetting",
        "("
        ")"
        "I",
        &g_ChromeUsbInterface_getAlternateSetting);

    jint ret = env->CallIntMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_ChromeUsbInterface_getInterfaceClass = 0;
static jint Java_ChromeUsbInterface_getInterfaceClass(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeUsbInterface_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeUsbInterface_clazz(env),
        "getInterfaceClass",
        "("
        ")"
        "I",
        &g_ChromeUsbInterface_getInterfaceClass);

    jint ret = env->CallIntMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_ChromeUsbInterface_getInterfaceSubclass = 0;
static jint Java_ChromeUsbInterface_getInterfaceSubclass(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeUsbInterface_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeUsbInterface_clazz(env),
        "getInterfaceSubclass",
        "("
        ")"
        "I",
        &g_ChromeUsbInterface_getInterfaceSubclass);

    jint ret = env->CallIntMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_ChromeUsbInterface_getInterfaceProtocol = 0;
static jint Java_ChromeUsbInterface_getInterfaceProtocol(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeUsbInterface_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeUsbInterface_clazz(env),
        "getInterfaceProtocol",
        "("
        ")"
        "I",
        &g_ChromeUsbInterface_getInterfaceProtocol);

    jint ret = env->CallIntMethod(obj.obj(),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_ChromeUsbInterface_getEndpoints = 0;
static base::android::ScopedJavaLocalRef<jobjectArray>
Java_ChromeUsbInterface_getEndpoints(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& obj)
{
    CHECK_CLAZZ(env, obj.obj(),
        ChromeUsbInterface_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_INSTANCE>(
        env, ChromeUsbInterface_clazz(env),
        "getEndpoints",
        "("
        ")"
        "[Landroid/hardware/usb/UsbEndpoint;",
        &g_ChromeUsbInterface_getEndpoints);

    jobjectArray ret = static_cast<jobjectArray>(env->CallObjectMethod(obj.obj(),
        method_id));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobjectArray>(env, ret);
}

// Step 3: RegisterNatives.

} // namespace device

#endif // org_chromium_device_usb_ChromeUsbInterface_JNI
