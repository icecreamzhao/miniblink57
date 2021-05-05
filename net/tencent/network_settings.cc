// Copyright (c) 2016 The Tencent Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/tencent/network_settings.h"
#include "net/tencent/net_logger.h"
#include "tencent/native/network_smtt_service.h"

namespace net {

//////////////////////////////////////////////////////////
/////////////////////// 变量定义 /////////////////////////
//////////////////////////////////////////////////////////

// 读超时 TODO:根据NQE变化（see: chromium_org/net/nqe [网络质量侦测]）
const int NetworkSettings::kTransportReadTimeoutInSeconds_WIFI = 60;
const int NetworkSettings::kTransportReadTimeoutInSeconds_CELLULAR = 60;

// socket连接超时
const int NetworkSettings::kTransportConnectJobTimeoutInSeconds_WIFI_Min = 10;
const int NetworkSettings::kTransportConnectJobTimeoutInSeconds_CELLULAR_Min = 22;
const int NetworkSettings::kTransportConnectJobTimeoutInSeconds_WIFI_Max = 240;
const int NetworkSettings::kTransportConnectJobTimeoutInSeconds_CELLULAR_Max = 240;
int NetworkSettings::mWifiTimeout = 0;
int NetworkSettings::mGprsTimeout = 0;

// SYN超时重传节奏：
//    Android 4.1+ ：1s/2s/4s/8s/16s/32s
//    Android 4.0- ：3s/6s/12s/24s/48s
// 为了避免这个问题，这里调成3s
const int NetworkSettings::kProxyImpatientTimerDurationInMilliseconds_WIFI = 3000; //milliseconds
const int NetworkSettings::kProxyImpatientTimerDurationInMilliseconds_CELLULAR = 3000; //milliseconds

const int NetworkSettings::kProxyErrorForOfflineRetryDelayInMilliseconds = 5000; // 5 seconds

// GUID
const std::string NetworkSettings::kTbsUserGUID = "";

// static
const bool NetworkSettings::kIsProxyImpatientJobEnabled = true;

// static
const bool NetworkSettings::kIsSpdySignGuidFrameEnabled = true;

//////////////////////////////////////////////////////////
/////////////////////// 方法定义 /////////////////////////
//////////////////////////////////////////////////////////

// static

void NetworkSettings::SetTransportConnectTimeout(int wifiTimeout, int gprsTimeout)
{
    mWifiTimeout = wifiTimeout;
    mGprsTimeout = gprsTimeout;
}

int NetworkSettings::GetTransportConnectTimeout()
{
    if (NetworkUtils::IsNetworkWifi()) {
        if (mWifiTimeout > kTransportConnectJobTimeoutInSeconds_WIFI_Max || mWifiTimeout < kTransportConnectJobTimeoutInSeconds_WIFI_Min)
            return 0;
        return mWifiTimeout;
    } else if (NetworkUtils::IsNetworkCellular()) {
        if (mGprsTimeout > kTransportConnectJobTimeoutInSeconds_CELLULAR_Max || mGprsTimeout < kTransportConnectJobTimeoutInSeconds_CELLULAR_Min)
            return 0;
        return mWifiTimeout;
    } else {
        return 0;
    }
}

// static
int NetworkSettings::GetTransportReadTimeout()
{
    return NetworkUtils::IsNetworkWifi()
        ? kTransportReadTimeoutInSeconds_WIFI
        : kTransportReadTimeoutInSeconds_CELLULAR;
}

// static
int NetworkSettings::GetProxyImpatientTimerDuration()
{
    return NetworkUtils::IsNetworkWifi()
        ? kProxyImpatientTimerDurationInMilliseconds_WIFI
        : kProxyImpatientTimerDurationInMilliseconds_CELLULAR;
}

// static
int NetworkSettings::GetProxyErrorForOfflineRetryDelay()
{
    return kProxyErrorForOfflineRetryDelayInMilliseconds;
}

// static
std::string NetworkSettings::GetTbsUserGUID()
{
    return NetworkSettings::kTbsUserGUID.empty()
        ? tencent::NetworkSmttService::GetInstance().GetTbsGUID()
        : NetworkSettings::kTbsUserGUID;
}

// static
bool NetworkSettings::IsProxyImpatientJobEnabled()
{
    NET_LOG_BASE("NetworkSettings::IsProxyImpatientJobEnabled kIsProxyImpatientJobEnabled:%d other:%d", (int)NetworkSettings::kIsProxyImpatientJobEnabled, (int)tencent::NetworkSmttService::GetInstance().IsNetworkImpatientJobEnabled());
    return NetworkSettings::kIsProxyImpatientJobEnabled
        && tencent::NetworkSmttService::GetInstance().IsNetworkImpatientJobEnabled();
}

// static
bool NetworkSettings::IsSpdySignGuidFrameEnabled()
{
    // DEBUG CODE TODO: remove while 3.0 work is done.
    //  FILE *debug = fopen("/sdcard/disable-sign", "r");
    //  if ( debug != NULL ) {
    //    return false;
    //  }
    // DEBUG CODE
    return NetworkSettings::kIsSpdySignGuidFrameEnabled
        && tencent::NetworkSmttService::GetInstance().IsSpdySignGuidFrameEnabled();
}

} // namespace net
