// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/components/url_formatter/UrlFormatter

#ifndef org_chromium_components_url_formatter_UrlFormatter_JNI
#define org_chromium_components_url_formatter_UrlFormatter_JNI

#include <jni.h>

#include "../../../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kUrlFormatterClassPath[] = "org/chromium/components/url_formatter/UrlFormatter";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_UrlFormatter_clazz __attribute__((unused)) = 0;
#define UrlFormatter_clazz(env) base::android::LazyGetClass(env, kUrlFormatterClassPath, &g_UrlFormatter_clazz)

} // namespace

namespace url_formatter {
namespace android {

    // Step 2: method stubs.

    static base::android::ScopedJavaLocalRef<jstring> FixupUrl(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
        const base::android::JavaParamRef<jstring>& url);

    JNI_GENERATOR_EXPORT jstring
    Java_org_chromium_components_url_1formatter_UrlFormatter_nativeFixupUrl(JNIEnv*
                                                                                env,
        jclass jcaller,
        jstring url)
    {
        return FixupUrl(env, base::android::JavaParamRef<jclass>(env, jcaller),
            base::android::JavaParamRef<jstring>(env, url))
            .Release();
    }

    static base::android::ScopedJavaLocalRef<jstring> FormatUrlForDisplay(JNIEnv*
                                                                              env,
        const base::android::JavaParamRef<jclass>& jcaller,
        const base::android::JavaParamRef<jstring>& url);

    JNI_GENERATOR_EXPORT jstring
    Java_org_chromium_components_url_1formatter_UrlFormatter_nativeFormatUrlForDisplay(JNIEnv*
                                                                                           env,
        jclass jcaller,
        jstring url)
    {
        return FormatUrlForDisplay(env, base::android::JavaParamRef<jclass>(env, jcaller), base::android::JavaParamRef<jstring>(env, url)).Release();
    }

    static base::android::ScopedJavaLocalRef<jstring>
    FormatUrlForSecurityDisplay(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
        const base::android::JavaParamRef<jstring>& url);

    JNI_GENERATOR_EXPORT jstring
    Java_org_chromium_components_url_1formatter_UrlFormatter_nativeFormatUrlForSecurityDisplay(JNIEnv*
                                                                                                   env,
        jclass jcaller,
        jstring url)
    {
        return FormatUrlForSecurityDisplay(env,
            base::android::JavaParamRef<jclass>(env, jcaller),
            base::android::JavaParamRef<jstring>(env, url))
            .Release();
    }

    static base::android::ScopedJavaLocalRef<jstring>
    FormatUrlForSecurityDisplayOmitScheme(JNIEnv* env, const base::android::JavaParamRef<jclass>& jcaller,
        const base::android::JavaParamRef<jstring>& url);

    JNI_GENERATOR_EXPORT jstring
    Java_org_chromium_components_url_1formatter_UrlFormatter_nativeFormatUrlForSecurityDisplayOmitScheme(JNIEnv*
                                                                                                             env,
        jclass jcaller,
        jstring url)
    {
        return FormatUrlForSecurityDisplayOmitScheme(env,
            base::android::JavaParamRef<jclass>(env, jcaller),
            base::android::JavaParamRef<jstring>(env, url))
            .Release();
    }

    // Step 3: RegisterNatives.

    static const JNINativeMethod kMethodsUrlFormatter[] = {
        { "nativeFixupUrl",
            "("
            "Ljava/lang/String;"
            ")"
            "Ljava/lang/String;",
            reinterpret_cast<void*>(Java_org_chromium_components_url_1formatter_UrlFormatter_nativeFixupUrl) },
        { "nativeFormatUrlForDisplay",
            "("
            "Ljava/lang/String;"
            ")"
            "Ljava/lang/String;",
            reinterpret_cast<void*>(Java_org_chromium_components_url_1formatter_UrlFormatter_nativeFormatUrlForDisplay) },
        { "nativeFormatUrlForSecurityDisplay",
            "("
            "Ljava/lang/String;"
            ")"
            "Ljava/lang/String;",
            reinterpret_cast<void*>(Java_org_chromium_components_url_1formatter_UrlFormatter_nativeFormatUrlForSecurityDisplay) },
        { "nativeFormatUrlForSecurityDisplayOmitScheme",
            "("
            "Ljava/lang/String;"
            ")"
            "Ljava/lang/String;",
            reinterpret_cast<void*>(Java_org_chromium_components_url_1formatter_UrlFormatter_nativeFormatUrlForSecurityDisplayOmitScheme) },
    };

    static bool RegisterNativesImpl(JNIEnv* env)
    {
        if (base::android::IsManualJniRegistrationDisabled())
            return true;

        const int kMethodsUrlFormatterSize = arraysize(kMethodsUrlFormatter);

        if (env->RegisterNatives(UrlFormatter_clazz(env),
                kMethodsUrlFormatter,
                kMethodsUrlFormatterSize)
            < 0) {
            jni_generator::HandleRegistrationError(
                env, UrlFormatter_clazz(env), __FILE__);
            return false;
        }

        return true;
    }

} // namespace android
} // namespace url_formatter

#endif // org_chromium_components_url_formatter_UrlFormatter_JNI
