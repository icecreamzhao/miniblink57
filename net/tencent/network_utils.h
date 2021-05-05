// Copyright (c) 2016 The Tencent Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_TENCENT_NETWORK_UTILS_H_
#define NET_TENCENT_NETWORK_UTILS_H_

#include "net/http/http_request_info.h"
#include "url/gurl.h"

/**
 *
 * */

namespace net {

class URLRequestContext;

// 网络工具类
class NetworkUtils {
public:
    // 是wifi网络
    static bool IsNetworkWifi();

    // 是蜂窝移动网络
    static bool IsNetworkCellular();

    // 断网离线
    static bool IsNetworkOffline();

    // 预连接
    static void PreconnectUrl(
        URLRequestContext* context,
        const GURL& url,
        int count = 1,
        bool is_direct = true,
        bool allow_credentials = true);
};

} // namespace net

#endif // NET_TENCENT_NETWORK_UTILS_H_
