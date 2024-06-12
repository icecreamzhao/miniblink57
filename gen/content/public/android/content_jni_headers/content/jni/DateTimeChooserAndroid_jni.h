// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/content/browser/input/DateTimeChooserAndroid

#ifndef org_chromium_content_browser_input_DateTimeChooserAndroid_JNI
#define org_chromium_content_browser_input_DateTimeChooserAndroid_JNI

#include <jni.h>

#include "../../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kDateTimeChooserAndroidClassPath[] = "org/chromium/content/browser/input/DateTimeChooserAndroid";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_DateTimeChooserAndroid_clazz __attribute__((unused))
= 0;
#define DateTimeChooserAndroid_clazz(env) base::android::LazyGetClass(env, kDateTimeChooserAndroidClassPath, &g_DateTimeChooserAndroid_clazz)

} // namespace

namespace content {

// Step 2: method stubs.
JNI_GENERATOR_EXPORT void
Java_org_chromium_content_browser_input_DateTimeChooserAndroid_nativeReplaceDateTime(JNIEnv*
                                                                                         env,
    jobject jcaller,
    jlong nativeDateTimeChooserAndroid,
    jdouble dialogValue)
{
    DateTimeChooserAndroid* native = reinterpret_cast<DateTimeChooserAndroid*>(nativeDateTimeChooserAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "ReplaceDateTime");
    return native->ReplaceDateTime(env, base::android::JavaParamRef<jobject>(env, jcaller), dialogValue);
}

JNI_GENERATOR_EXPORT void
Java_org_chromium_content_browser_input_DateTimeChooserAndroid_nativeCancelDialog(JNIEnv*
                                                                                      env,
    jobject jcaller,
    jlong nativeDateTimeChooserAndroid)
{
    DateTimeChooserAndroid* native = reinterpret_cast<DateTimeChooserAndroid*>(nativeDateTimeChooserAndroid);
    CHECK_NATIVE_PTR(env, jcaller, native, "CancelDialog");
    return native->CancelDialog(env, base::android::JavaParamRef<jobject>(env, jcaller));
}

static base::subtle::AtomicWord g_DateTimeChooserAndroid_createDateTimeChooser = 0;
static base::android::ScopedJavaLocalRef<jobject>
Java_DateTimeChooserAndroid_createDateTimeChooser(JNIEnv* env, const base::android::JavaRefOrBare<jobject>& windowAndroid,
    jlong nativeDateTimeChooserAndroid,
    JniIntWrapper dialogType,
    jdouble dialogValue,
    jdouble min,
    jdouble max,
    jdouble step,
    const base::android::JavaRefOrBare<jobjectArray>& suggestions)
{
    CHECK_CLAZZ(env, DateTimeChooserAndroid_clazz(env),
        DateTimeChooserAndroid_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, DateTimeChooserAndroid_clazz(env),
        "createDateTimeChooser",
        "("
        "Lorg/chromium/ui/base/WindowAndroid;"
        "J"
        "I"
        "D"
        "D"
        "D"
        "D"
        "[Lorg/chromium/content/browser/picker/DateTimeSuggestion;"
        ")"
        "Lorg/chromium/content/browser/input/DateTimeChooserAndroid;",
        &g_DateTimeChooserAndroid_createDateTimeChooser);

    jobject ret = env->CallStaticObjectMethod(DateTimeChooserAndroid_clazz(env),
        method_id, windowAndroid.obj(), nativeDateTimeChooserAndroid,
        as_jint(dialogType), dialogValue, min, max, step,
        suggestions.obj());
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_DateTimeChooserAndroid_createSuggestionsArray
    = 0;
static base::android::ScopedJavaLocalRef<jobjectArray>
Java_DateTimeChooserAndroid_createSuggestionsArray(JNIEnv* env,
    JniIntWrapper size)
{
    CHECK_CLAZZ(env, DateTimeChooserAndroid_clazz(env),
        DateTimeChooserAndroid_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, DateTimeChooserAndroid_clazz(env),
        "createSuggestionsArray",
        "("
        "I"
        ")"
        "[Lorg/chromium/content/browser/picker/DateTimeSuggestion;",
        &g_DateTimeChooserAndroid_createSuggestionsArray);

    jobjectArray ret = static_cast<jobjectArray>(env->CallStaticObjectMethod(DateTimeChooserAndroid_clazz(env),
        method_id, as_jint(size)));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobjectArray>(env, ret);
}

static base::subtle::AtomicWord g_DateTimeChooserAndroid_setDateTimeSuggestionAt
    = 0;
static void Java_DateTimeChooserAndroid_setDateTimeSuggestionAt(JNIEnv* env,
    const base::android::JavaRefOrBare<jobjectArray>& array,
    JniIntWrapper index,
    jdouble value,
    const base::android::JavaRefOrBare<jstring>& localizedValue,
    const base::android::JavaRefOrBare<jstring>& label)
{
    CHECK_CLAZZ(env, DateTimeChooserAndroid_clazz(env),
        DateTimeChooserAndroid_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, DateTimeChooserAndroid_clazz(env),
        "setDateTimeSuggestionAt",
        "("
        "[Lorg/chromium/content/browser/picker/DateTimeSuggestion;"
        "I"
        "D"
        "Ljava/lang/String;"
        "Ljava/lang/String;"
        ")"
        "V",
        &g_DateTimeChooserAndroid_setDateTimeSuggestionAt);

    env->CallStaticVoidMethod(DateTimeChooserAndroid_clazz(env),
        method_id, array.obj(), as_jint(index), value, localizedValue.obj(),
        label.obj());
    jni_generator::CheckException(env);
}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsDateTimeChooserAndroid[] = {
    { "nativeReplaceDateTime",
        "("
        "J"
        "D"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_input_DateTimeChooserAndroid_nativeReplaceDateTime) },
    { "nativeCancelDialog",
        "("
        "J"
        ")"
        "V",
        reinterpret_cast<void*>(Java_org_chromium_content_browser_input_DateTimeChooserAndroid_nativeCancelDialog) },
};

static bool RegisterNativesImpl(JNIEnv* env)
{
    if (base::android::IsManualJniRegistrationDisabled())
        return true;

    const int kMethodsDateTimeChooserAndroidSize = arraysize(kMethodsDateTimeChooserAndroid);

    if (env->RegisterNatives(DateTimeChooserAndroid_clazz(env),
            kMethodsDateTimeChooserAndroid,
            kMethodsDateTimeChooserAndroidSize)
        < 0) {
        jni_generator::HandleRegistrationError(
            env, DateTimeChooserAndroid_clazz(env), __FILE__);
        return false;
    }

    return true;
}

} // namespace content

#endif // org_chromium_content_browser_input_DateTimeChooserAndroid_JNI
