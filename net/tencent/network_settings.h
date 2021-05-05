// Copyright (c) 2016 The Tencent Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_TENCENT_NETWORK_SETTINGS_H_
#define NET_TENCENT_NETWORK_SETTINGS_H_

#include "net/tencent/network_utils.h"
#include <string>

/**
 * Coomy
 * 各种自定义的网络参数配置找不到？都暂时统一的放在这里吧。
 * */

namespace net {
// TODO(Coomy):归为类？可以外部设置，类似websetting？
// 鉴于以后可能会变成一个类似WebSettings的类，所以这里不管是配置值还是开关，都应该有对应的成员变量

class NetworkSettings {

private:
    //////////////////////////////////////////////////////////
    /////////////////////// 变量定义 /////////////////////////
    //////////////////////////////////////////////////////////
    // TODO(Coomy):去除const 和 static，以对象形式被URLRequestContext持有。

    /************************ 数值类 *************************/
    // 读超时 TODO:根据NQE变化（see: chromium_org/net/nqe [网络质量侦测]）
    static const int kTransportReadTimeoutInSeconds_WIFI;
    static const int kTransportReadTimeoutInSeconds_CELLULAR;

    // socket连接超时
    static const int kTransportConnectJobTimeoutInSeconds_WIFI_Min;
    static const int kTransportConnectJobTimeoutInSeconds_CELLULAR_Min;
    static const int kTransportConnectJobTimeoutInSeconds_WIFI_Max;
    static const int kTransportConnectJobTimeoutInSeconds_CELLULAR_Max;
    static int mWifiTimeout;
    static int mGprsTimeout;

    // spdy proxy连接忍耐时间
    static const int kProxyImpatientTimerDurationInMilliseconds_WIFI;
    static const int kProxyImpatientTimerDurationInMilliseconds_CELLULAR;

    // 代理连接失败如果因为网络连接问题，则延迟5秒重试
    static const int kProxyErrorForOfflineRetryDelayInMilliseconds;

    static const std::string kTbsUserGUID;

    /************************ 开关类 *************************/
    static const bool kIsProxyImpatientJobEnabled;
    static const bool kIsSpdySignGuidFrameEnabled; // spdy染色帧开关

public:
    //////////////////////////////////////////////////////////
    /////////////////////// 方法定义 /////////////////////////
    //////////////////////////////////////////////////////////

    /************************ 数值类 *************************/
    // socket 连接超时 in seconds.
    static void SetTransportConnectTimeout(int wifiTimeout, int gprsTimeout);
    static int GetTransportConnectTimeout();

    // http 读超时 in seconds.
    static int GetTransportReadTimeout();

    // spdy proxy 连接的忍耐时间；该时间内如果spdy代理连接还没成功，则同时发起一个直连连接，谁先返回用谁。
    static int GetProxyImpatientTimerDuration();

    static int GetProxyErrorForOfflineRetryDelay();

    // 用户guid.
    static std::string GetTbsUserGUID();

    /************************ 开关类 *************************/
    // 代理连接请求后若干秒如果没连成功，则并发一个直连握手job请求
    static bool IsProxyImpatientJobEnabled();

    // 是否在spdy session创建的时候，发送GUID染色帧
    static bool IsSpdySignGuidFrameEnabled();
};

} // namespace net

#endif // NET_TENCENT_NETWORK_SETTINGS_H_
