// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/device/bluetooth/Wrappers

#ifndef org_chromium_device_bluetooth_Wrappers_JNI
#define org_chromium_device_bluetooth_Wrappers_JNI

#include <jni.h>

#include "../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kWrappersClassPath[] = "org/chromium/device/bluetooth/Wrappers";
const char kBluetoothAdapterWrapperClassPath[] = "org/chromium/device/bluetooth/Wrappers$BluetoothAdapterWrapper";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_Wrappers_clazz __attribute__((unused)) = 0;
#define Wrappers_clazz(env) base::android::LazyGetClass(env, kWrappersClassPath, &g_Wrappers_clazz)
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_BluetoothAdapterWrapper_clazz __attribute__((unused))
= 0;
#define BluetoothAdapterWrapper_clazz(env) base::android::LazyGetClass(env, kBluetoothAdapterWrapperClassPath, &g_BluetoothAdapterWrapper_clazz)

} // namespace

namespace device {

// Step 2: method stubs.

static base::subtle::AtomicWord
    g_BluetoothAdapterWrapper_createWithDefaultAdapter
    = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_BluetoothAdapterWrapper_createWithDefaultAdapter(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& context)
{
    CHECK_CLAZZ(env, BluetoothAdapterWrapper_clazz(env),
        BluetoothAdapterWrapper_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, BluetoothAdapterWrapper_clazz(env),
        "createWithDefaultAdapter",
        "("
        "Landroid/content/Context;"
        ")"
        "Lorg/chromium/device/bluetooth/Wrappers$BluetoothAdapterWrapper;",
        &g_BluetoothAdapterWrapper_createWithDefaultAdapter);

    jobject ret = env->CallStaticObjectMethod(BluetoothAdapterWrapper_clazz(env),
        method_id, context.obj());
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

// Step 3: RegisterNatives.

} // namespace device

#endif // org_chromium_device_bluetooth_Wrappers_JNI
