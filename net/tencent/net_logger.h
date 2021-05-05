// Copyright (c) 2009 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_TENCENT_NET_LOGGER_H_
#define NET_TENCENT_NET_LOGGER_H_

#include <android/log.h>
#include <string>

using std::string;

namespace net {

#define NET_DEBUG_MODE 1

#if NET_DEBUG_MODE
/*
 *  Coomy. LOG自己加吧，最好是一些比较大的范畴。
 * */

#define NET_LOG_BASE(FORMAT, ...)                                                     \
    {                                                                                 \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_BASE", FORMAT, ##__VA_ARGS__); \
    }

#define NET_LOG_LOADER(FORMAT, ...)                                                     \
    {                                                                                   \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_LOADER", FORMAT, ##__VA_ARGS__); \
    }

// 请求相关，URLRequest/URLRequestJob
#define NET_LOG_REQUEST(FORMAT, ...)                                                     \
    {                                                                                    \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_REQUEST", FORMAT, ##__VA_ARGS__); \
    }

// Cache相关
#define NET_LOG_CACHE(FORMAT, ...)                                                     \
    {                                                                                  \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_CACHE", FORMAT, ##__VA_ARGS__); \
    }

// Network Transaction相关，收发请求数据
#define NET_LOG_TRANS(FORMAT, ...)                                                     \
    {                                                                                  \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_TRANS", FORMAT, ##__VA_ARGS__); \
    }

// Stream构造相关，收发请求数据
#define NET_LOG_STREAM(FORMAT, ...)                                                     \
    {                                                                                   \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_STREAM", FORMAT, ##__VA_ARGS__); \
    }

// 代理相关，主要是系统代理 [非SPDY]
#define NET_LOG_PROXY(FORMAT, ...)                                                     \
    {                                                                                  \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_PROXY", FORMAT, ##__VA_ARGS__); \
    }

// spdy http2 协议相关
#define NET_LOG_HTTP2(FORMAT, ...)                                                     \
    {                                                                                  \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_HTTP2", FORMAT, ##__VA_ARGS__); \
    }

// SOCKET连接相关，ConnectJob系列及相关的LOG [可细化]
#define NET_LOG_SOCKET(FORMAT, ...)                                                     \
    {                                                                                   \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_SOCKET", FORMAT, ##__VA_ARGS__); \
    }

#define NET_LOG_DNS(FORMAT, ...)                                                     \
    {                                                                                \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_DNS", FORMAT, ##__VA_ARGS__); \
    }

#define NET_LOG_DNS_STORE(FORMAT, ...)                                                     \
    {                                                                                      \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_DNS_STORE", FORMAT, ##__VA_ARGS__); \
    }

#define NET_LOG_PREDICTOR(FORMAT, ...)                                                     \
    {                                                                                      \
        __android_log_print(ANDROID_LOG_ERROR, "NETLOG_PREDICTOR", FORMAT, ##__VA_ARGS__); \
    }

#else

#define NET_LOG_BASE(FORMAT, ...)
#define NET_LOG_LOADER(FORMAT, ...)
#define NET_LOG_REQUEST(FORMAT, ...)
#define NET_LOG_CACHE(FORMAT, ...)
#define NET_LOG_TRANS(FORMAT, ...)
#define NET_LOG_STREAM(FORMAT, ...)
#define NET_LOG_PROXY(FORMAT, ...)
#define NET_LOG_SPDY(FORMAT, ...)
#define NET_LOG_HTTP2(FORMAT, ...)
#define NET_LOG_SOCKET(FORMAT, ...)
#define NET_LOG_DNS(FORMAT, ...)
#define NET_LOG_DNS_STORE(FORMAT, ...)
#define NET_LOG_PREDICTOR(FORMAT, ...)
#endif //NET_DEBUG_MODE

#if NET_DEBUG_MODE
// HttpNetworkTransaction Loop State Flag!
const string HTTP_NETWORK_TRANSACTION_STATE[] = {
    "STATE_NOTIFY_BEFORE_CREATE_STREAM",
    "STATE_CREATE_STREAM",
    "STATE_CREATE_STREAM_COMPLETE",
    "STATE_INIT_STREAM",
    "STATE_INIT_STREAM_COMPLETE",
    "STATE_GENERATE_PROXY_AUTH_TOKEN",
    "STATE_GENERATE_PROXY_AUTH_TOKEN_COMPLETE",
    "STATE_GENERATE_SERVER_AUTH_TOKEN",
    "STATE_GENERATE_SERVER_AUTH_TOKEN_COMPLETE",
    "STATE_INIT_REQUEST_BODY",
    "STATE_INIT_REQUEST_BODY_COMPLETE",
    "STATE_BUILD_REQUEST",
    "STATE_BUILD_REQUEST_COMPLETE",
    "STATE_SEND_REQUEST",
    "STATE_SEND_REQUEST_COMPLETE",
    "STATE_READ_HEADERS",
    "STATE_READ_HEADERS_COMPLETE",
    "STATE_READ_BODY",
    "STATE_READ_BODY_COMPLETE",
    "STATE_DRAIN_BODY_FOR_AUTH_RESTART",
    "STATE_DRAIN_BODY_FOR_AUTH_RESTART_COMPLETE",
    "STATE_NONE"
};

const string HTTP_CACHE_TRANSACTION_STATE[] = {
    "STATE_NONE",
    "STATE_GET_BACKEND",
    "STATE_GET_BACKEND_COMPLETE",
    "STATE_SEND_REQUEST",
    "STATE_SEND_REQUEST_COMPLETE",
    "STATE_SUCCESSFUL_SEND_REQUEST",
    "STATE_NETWORK_READ",
    "STATE_NETWORK_READ_COMPLETE",
    "STATE_INIT_ENTRY",
    "STATE_OPEN_ENTRY",
    "STATE_OPEN_ENTRY_COMPLETE",
    "STATE_CREATE_ENTRY",
    "STATE_CREATE_ENTRY_COMPLETE",
    "STATE_DOOM_ENTRY",
    "STATE_DOOM_ENTRY_COMPLETE",
    "STATE_ADD_TO_ENTRY",
    "STATE_ADD_TO_ENTRY_COMPLETE",
    "STATE_START_PARTIAL_CACHE_VALIDATION",
    "STATE_COMPLETE_PARTIAL_CACHE_VALIDATION",
    "STATE_UPDATE_CACHED_RESPONSE",
    "STATE_UPDATE_CACHED_RESPONSE_COMPLETE",
    "STATE_OVERWRITE_CACHED_RESPONSE",
    "STATE_TRUNCATE_CACHED_DATA",
    "STATE_TRUNCATE_CACHED_DATA_COMPLETE",
    "STATE_TRUNCATE_CACHED_METADATA",
    "STATE_TRUNCATE_CACHED_METADATA_COMPLETE",
    "STATE_PARTIAL_HEADERS_RECEIVED",
    "STATE_CACHE_READ_RESPONSE",
    "STATE_CACHE_READ_RESPONSE_COMPLETE",
    "STATE_CACHE_WRITE_RESPONSE",
    "STATE_CACHE_WRITE_TRUNCATED_RESPONSE",
    "STATE_CACHE_WRITE_RESPONSE_COMPLETE",
    "STATE_CACHE_READ_METADATA",
    "STATE_CACHE_READ_METADATA_COMPLETE",
    "STATE_CACHE_QUERY_DATA",
    "STATE_CACHE_QUERY_DATA_COMPLETE",
    "STATE_CACHE_READ_DATA",
    "STATE_CACHE_READ_DATA_COMPLETE",
    "STATE_CACHE_WRITE_DATA",
    "STATE_CACHE_WRITE_DATA_COMPLETE"
};

const string HTTP_STREAM_FACTORY_IMPL_JOB_STATE[] = {
    "STATE_START",
    "STATE_RESOLVE_PROXY",
    "STATE_RESOLVE_PROXY_COMPLETE",
    "STATE_RESOLVE_CUSTOM_PROXY",
    "STATE_RESOLVE_CUSTOM_PROXY_COMPLETE",
    "STATE_WAIT_FOR_JOB",
    "STATE_WAIT_FOR_JOB_COMPLETE",
    "STATE_INIT_CONNECTION",
    "STATE_INIT_CONNECTION_COMPLETE",
    "STATE_WAITING_USER_ACTION",
    "STATE_RESTART_TUNNEL_AUTH",
    "STATE_RESTART_TUNNEL_AUTH_COMPLETE",
    "STATE_CREATE_STREAM",
    "STATE_CREATE_STREAM_COMPLETE",
    "STATE_DRAIN_BODY_FOR_AUTH_RESTART",
    "STATE_DRAIN_BODY_FOR_AUTH_RESTART_COMPLETE",
    "STATE_DONE",
    "STATE_NONE"
};
#endif

} // namespace spdy

#endif // NET_TENCENT_NET_LOGGER_H_
