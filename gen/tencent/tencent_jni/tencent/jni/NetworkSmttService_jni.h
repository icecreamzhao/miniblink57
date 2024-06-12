// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     com/tencent/smtt/net/NetworkSmttService

#ifndef com_tencent_smtt_net_NetworkSmttService_JNI
#define com_tencent_smtt_net_NetworkSmttService_JNI

#include <jni.h>

#include "../../../../../../../base/android/jni_generator/jni_generator_helper.h"

#include "base/android/jni_int_wrapper.h"

// Step 1: forward declarations.
namespace {
const char kNetworkSmttServiceClassPath[] = "com/tencent/smtt/net/NetworkSmttService";
// Leaking this jclass as we cannot use LazyInstance from some threads.
base::subtle::AtomicWord g_NetworkSmttService_clazz __attribute__((unused)) = 0;
#define NetworkSmttService_clazz(env) base::android::LazyGetClass(env, kNetworkSmttServiceClassPath, &g_NetworkSmttService_clazz)

} // namespace

namespace tencent {

// Step 2: method stubs.

static base::subtle::AtomicWord g_NetworkSmttService_isSpdyProxySignEnabled = 0;
static jboolean Java_NetworkSmttService_isSpdyProxySignEnabled(JNIEnv* env)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "isSpdyProxySignEnabled",
        "("
        ")"
        "Z",
        &g_NetworkSmttService_isSpdyProxySignEnabled);

    jboolean ret = env->CallStaticBooleanMethod(NetworkSmttService_clazz(env),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_NetworkSmttService_getDebugCustomHosts = 0;
static base::android::ScopedJavaLocalRef<jstring>
Java_NetworkSmttService_getDebugCustomHosts(JNIEnv* env)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "getDebugCustomHosts",
        "("
        ")"
        "Ljava/lang/String;",
        &g_NetworkSmttService_getDebugCustomHosts);

    jstring ret = static_cast<jstring>(env->CallStaticObjectMethod(NetworkSmttService_clazz(env),
        method_id));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_NetworkSmttService_getDebugTbsProxyType = 0;
static jint Java_NetworkSmttService_getDebugTbsProxyType(JNIEnv* env)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "getDebugTbsProxyType",
        "("
        ")"
        "I",
        &g_NetworkSmttService_getDebugTbsProxyType);

    jint ret = env->CallStaticIntMethod(NetworkSmttService_clazz(env),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_NetworkSmttService_getSubResConnectType = 0;
static jint Java_NetworkSmttService_getSubResConnectType(JNIEnv* env)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "getSubResConnectType",
        "("
        ")"
        "I",
        &g_NetworkSmttService_getSubResConnectType);

    jint ret = env->CallStaticIntMethod(NetworkSmttService_clazz(env),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_NetworkSmttService_onReportMetrics = 0;
static void Java_NetworkSmttService_onReportMetrics(JNIEnv* env, const base::android::JavaRefOrBare<jstring>& url,
    jlong sentBytes,
    jlong receivedBytes,
    JniIntWrapper stateCode,
    const base::android::JavaRefOrBare<jstring>& mimeType,
    JniIntWrapper ProxyType,
    jboolean isMainResource,
    const base::android::JavaRefOrBare<jstring>& metricsSaved,
    jboolean isMiniQB,
    jboolean wasCached)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "onReportMetrics",
        "("
        "Ljava/lang/String;"
        "J"
        "J"
        "I"
        "Ljava/lang/String;"
        "I"
        "Z"
        "Ljava/lang/String;"
        "Z"
        "Z"
        ")"
        "V",
        &g_NetworkSmttService_onReportMetrics);

    env->CallStaticVoidMethod(NetworkSmttService_clazz(env),
        method_id, url.obj(), sentBytes, receivedBytes, as_jint(stateCode),
        mimeType.obj(), as_jint(ProxyType), isMainResource,
        metricsSaved.obj(), isMiniQB, wasCached);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_NetworkSmttService_getSpdyProxyAddress = 0;
static base::android::ScopedJavaLocalRef<jstring>
Java_NetworkSmttService_getSpdyProxyAddress(JNIEnv* env, const base::android::JavaRefOrBare<jstring>& url,
    jboolean isMainResource,
    const base::android::JavaRefOrBare<jstring>& refer)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "getSpdyProxyAddress",
        "("
        "Ljava/lang/String;"
        "Z"
        "Ljava/lang/String;"
        ")"
        "Ljava/lang/String;",
        &g_NetworkSmttService_getSpdyProxyAddress);

    jstring ret = static_cast<jstring>(env->CallStaticObjectMethod(NetworkSmttService_clazz(env),
        method_id, url.obj(), isMainResource, refer.obj()));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_NetworkSmttService_reportDnsResolveResults = 0;
static void Java_NetworkSmttService_reportDnsResolveResults(JNIEnv* env,
    JniIntWrapper dnsType,
    JniIntWrapper errorCode,
    const base::android::JavaRefOrBare<jstring>& hostname,
    const base::android::JavaRefOrBare<jstring>& dnsResult,
    const base::android::JavaRefOrBare<jstring>& dnsServer)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "reportDnsResolveResults",
        "("
        "I"
        "I"
        "Ljava/lang/String;"
        "Ljava/lang/String;"
        "Ljava/lang/String;"
        ")"
        "V",
        &g_NetworkSmttService_reportDnsResolveResults);

    env->CallStaticVoidMethod(NetworkSmttService_clazz(env),
        method_id, as_jint(dnsType), as_jint(errorCode), hostname.obj(),
        dnsResult.obj(), dnsServer.obj());
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord
    g_NetworkSmttService_getDnsResolveTypeForThisDomain
    = 0;
static jint Java_NetworkSmttService_getDnsResolveTypeForThisDomain(JNIEnv* env,
    const base::android::JavaRefOrBare<jstring>& host)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), 0);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "getDnsResolveTypeForThisDomain",
        "("
        "Ljava/lang/String;"
        ")"
        "I",
        &g_NetworkSmttService_getDnsResolveTypeForThisDomain);

    jint ret = env->CallStaticIntMethod(NetworkSmttService_clazz(env),
        method_id, host.obj());
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord
    g_NetworkSmttService_shouldConvertToHttpsForThisDomain
    = 0;
static jboolean
Java_NetworkSmttService_shouldConvertToHttpsForThisDomain(JNIEnv* env, const base::android::JavaRefOrBare<jstring>& host)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "shouldConvertToHttpsForThisDomain",
        "("
        "Ljava/lang/String;"
        ")"
        "Z",
        &g_NetworkSmttService_shouldConvertToHttpsForThisDomain);

    jboolean ret = env->CallStaticBooleanMethod(NetworkSmttService_clazz(env),
        method_id, host.obj());
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_NetworkSmttService_getSpdyProxyStatus = 0;
static base::android::ScopedJavaLocalRef<jobjectArray>
Java_NetworkSmttService_getSpdyProxyStatus(JNIEnv* env, const base::android::JavaRefOrBare<jstring>& url,
    jboolean isMainResource,
    const base::android::JavaRefOrBare<jstring>& refer)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "getSpdyProxyStatus",
        "("
        "Ljava/lang/String;"
        "Z"
        "Ljava/lang/String;"
        ")"
        "[Ljava/lang/String;",
        &g_NetworkSmttService_getSpdyProxyStatus);

    jobjectArray ret = static_cast<jobjectArray>(env->CallStaticObjectMethod(NetworkSmttService_clazz(env),
        method_id, url.obj(), isMainResource, refer.obj()));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobjectArray>(env, ret);
}

static base::subtle::AtomicWord g_NetworkSmttService_getExtraQHeaders = 0;
static base::android::ScopedJavaLocalRef<jobjectArray>
Java_NetworkSmttService_getExtraQHeaders(JNIEnv* env, const base::android::JavaRefOrBare<jstring>& url,
    JniIntWrapper resourceType,
    jboolean isUseProxy,
    jboolean isMiniQB)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "getExtraQHeaders",
        "("
        "Ljava/lang/String;"
        "I"
        "Z"
        "Z"
        ")"
        "[Ljava/lang/String;",
        &g_NetworkSmttService_getExtraQHeaders);

    jobjectArray ret = static_cast<jobjectArray>(env->CallStaticObjectMethod(NetworkSmttService_clazz(env),
        method_id, url.obj(), as_jint(resourceType), isUseProxy, isMiniQB));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jobjectArray>(env, ret);
}

static base::subtle::AtomicWord g_NetworkSmttService_getTbsGUID = 0;
static base::android::ScopedJavaLocalRef<jstring>
Java_NetworkSmttService_getTbsGUID(JNIEnv* env)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "getTbsGUID",
        "("
        ")"
        "Ljava/lang/String;",
        &g_NetworkSmttService_getTbsGUID);

    jstring ret = static_cast<jstring>(env->CallStaticObjectMethod(NetworkSmttService_clazz(env),
        method_id));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_NetworkSmttService_isNeedQHeaders = 0;
static jboolean Java_NetworkSmttService_isNeedQHeaders(JNIEnv* env, const base::android::JavaRefOrBare<jstring>& url)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "isNeedQHeaders",
        "("
        "Ljava/lang/String;"
        ")"
        "Z",
        &g_NetworkSmttService_isNeedQHeaders);

    jboolean ret = env->CallStaticBooleanMethod(NetworkSmttService_clazz(env),
        method_id, url.obj());
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord g_NetworkSmttService_getApnNameWithSSID = 0;
static base::android::ScopedJavaLocalRef<jstring>
Java_NetworkSmttService_getApnNameWithSSID(JNIEnv* env)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), NULL);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "getApnNameWithSSID",
        "("
        ")"
        "Ljava/lang/String;",
        &g_NetworkSmttService_getApnNameWithSSID);

    jstring ret = static_cast<jstring>(env->CallStaticObjectMethod(NetworkSmttService_clazz(env),
        method_id));
    jni_generator::CheckException(env);
    return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord g_NetworkSmttService_notifySpdyProxyFailHandler
    = 0;
static void Java_NetworkSmttService_notifySpdyProxyFailHandler(JNIEnv* env,
    const base::android::JavaRefOrBare<jstring>& proxyHost,
    JniIntWrapper errorId)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "notifySpdyProxyFailHandler",
        "("
        "Ljava/lang/String;"
        "I"
        ")"
        "V",
        &g_NetworkSmttService_notifySpdyProxyFailHandler);

    env->CallStaticVoidMethod(NetworkSmttService_clazz(env),
        method_id, proxyHost.obj(), as_jint(errorId));
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord
    g_NetworkSmttService_notifyProxyQualityWithExtraUserWaitInfo
    = 0;
static void
Java_NetworkSmttService_notifyProxyQualityWithExtraUserWaitInfo(JNIEnv* env,
    const base::android::JavaRefOrBare<jstring>& proxyHost,
    JniIntWrapper errorId,
    const base::android::JavaRefOrBare<jstring>& url,
    const base::android::JavaRefOrBare<jstring>& phrase,
    JniIntWrapper waitTime_ms)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "notifyProxyQualityWithExtraUserWaitInfo",
        "("
        "Ljava/lang/String;"
        "I"
        "Ljava/lang/String;"
        "Ljava/lang/String;"
        "I"
        ")"
        "V",
        &g_NetworkSmttService_notifyProxyQualityWithExtraUserWaitInfo);

    env->CallStaticVoidMethod(NetworkSmttService_clazz(env),
        method_id, proxyHost.obj(), as_jint(errorId), url.obj(), phrase.obj(),
        as_jint(waitTime_ms));
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_NetworkSmttService_notifySpdyProxyCheckResult
    = 0;
static void Java_NetworkSmttService_notifySpdyProxyCheckResult(JNIEnv* env,
    jboolean result)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "notifySpdyProxyCheckResult",
        "("
        "Z"
        ")"
        "V",
        &g_NetworkSmttService_notifySpdyProxyCheckResult);

    env->CallStaticVoidMethod(NetworkSmttService_clazz(env),
        method_id, result);
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_NetworkSmttService_notifyDirectVisitDomain = 0;
static void Java_NetworkSmttService_notifyDirectVisitDomain(JNIEnv* env, const base::android::JavaRefOrBare<jstring>& url,
    JniIntWrapper statusCode)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "notifyDirectVisitDomain",
        "("
        "Ljava/lang/String;"
        "I"
        ")"
        "V",
        &g_NetworkSmttService_notifyDirectVisitDomain);

    env->CallStaticVoidMethod(NetworkSmttService_clazz(env),
        method_id, url.obj(), as_jint(statusCode));
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord g_NetworkSmttService_notifyDirectVisitRegular = 0;
static void Java_NetworkSmttService_notifyDirectVisitRegular(JNIEnv* env, const base::android::JavaRefOrBare<jstring>& Regular)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env));
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "notifyDirectVisitRegular",
        "("
        "Ljava/lang/String;"
        ")"
        "V",
        &g_NetworkSmttService_notifyDirectVisitRegular);

    env->CallStaticVoidMethod(NetworkSmttService_clazz(env),
        method_id, Regular.obj());
    jni_generator::CheckException(env);
}

static base::subtle::AtomicWord
    g_NetworkSmttService_isTbsImpatientNetworkEnabled
    = 0;
static jboolean Java_NetworkSmttService_isTbsImpatientNetworkEnabled(JNIEnv*
        env)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "isTbsImpatientNetworkEnabled",
        "("
        ")"
        "Z",
        &g_NetworkSmttService_isTbsImpatientNetworkEnabled);

    jboolean ret = env->CallStaticBooleanMethod(NetworkSmttService_clazz(env),
        method_id);
    jni_generator::CheckException(env);
    return ret;
}

static base::subtle::AtomicWord
    g_NetworkSmttService_allowUseContentCacheBusiness
    = 0;
static jboolean Java_NetworkSmttService_allowUseContentCacheBusiness(JNIEnv*
                                                                         env,
    const base::android::JavaRefOrBare<jstring>& host,
    const base::android::JavaRefOrBare<jstring>& path,
    jboolean isMiniQB)
{
    CHECK_CLAZZ(env, NetworkSmttService_clazz(env),
        NetworkSmttService_clazz(env), false);
    jmethodID method_id = base::android::MethodID::LazyGet<
        base::android::MethodID::TYPE_STATIC>(
        env, NetworkSmttService_clazz(env),
        "allowUseContentCacheBusiness",
        "("
        "Ljava/lang/String;"
        "Ljava/lang/String;"
        "Z"
        ")"
        "Z",
        &g_NetworkSmttService_allowUseContentCacheBusiness);

    jboolean ret = env->CallStaticBooleanMethod(NetworkSmttService_clazz(env),
        method_id, host.obj(), path.obj(), isMiniQB);
    jni_generator::CheckException(env);
    return ret;
}

// Step 3: RegisterNatives.

} // namespace tencent

#endif // com_tencent_smtt_net_NetworkSmttService_JNI
