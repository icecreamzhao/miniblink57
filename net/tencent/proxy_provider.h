// Copyright (c) 2016 The Tencent Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/* Author : Coomy.
 * Date   : 2016.8.23
 * Desc   : 网络自定义代理接口，content层实现之
 *
 * */

#ifndef NET_TENCENT_PROXY_PROVIDER_H_
#define NET_TENCENT_PROXY_PROVIDER_H_

#include <memory>

#include "net/base/host_port_pair.h"
#include "net/base/net_export.h"
#include "proxy_listener.h"
#include "tencent/build/config_net.h"

namespace net {

class HttpRequestInfo;
class BoundNetLog;
class ProxyInfo;
class ProxyListener;

// 代理的提供者
/*
 * 大致结构：
 * ProxyListener  --  NetworkDelegate
 *      |___________________
 *      |                   |
 * ProxyProvider -------> Agent
 *      |                   |
 * content-provider       content-agent
 *
 * 现在，网络模块给外部暴露了这样一个接口，可以让你响内部挂载代理。优先级：[ System Proxy > Custon Proxy(ProxyProvider) > Direct Connect ]
 * 它期望你通过Agent的形式去作特定代理的工作，然后把代理结果通过Provider提供给net模块内部。
 * */
class NET_EXPORT ProxyProvider : public ProxyListener {

public:
    ProxyProvider() { }
    virtual ~ProxyProvider() { }

    enum AgentType {
        DEBUG_PROXY_AGENT,
        TBS_SPDY_PROXY_AGENT
    };

    enum AgentResolveResult {
        RESULT_PROXY_READY, // 此Agent给输出了新代理地址
        RESULT_PROXY_NULL, // 此Agent没有输出任何新代理地址
        RESULT_PROXY_ERROR // 此Agent在执行过程中出错
    };

    // 它是Provider内部提供代理的载体，Provider可以持有很多这样的Agent，他们以链表的形式存储，root被Provider持有，越向后优先级越低。
    class Agent : public ProxyListener {
    public:
        //
        Agent() { }
        Agent(std::unique_ptr<Agent> pre) { pre->SetNext(std::move(pre)); }
        virtual ~Agent() { }

        // 当前Agent所持有的代理信息状态，出错后会invalide
        struct ProxyInfo {
            HostPortPair proxy_;
            bool valid_;
        }; // ProxyInfo

        virtual AgentResolveResult DoResolveProxy(
            const net::HttpRequestInfo& request,
            net::ProxyInfo* result,
            const net::BoundNetLog& net_log)
            = 0;

        // may be invalid.
        virtual ProxyInfo& GetProxyInfo()
        {
            if (!proxy_info_.valid_ && HasNext())
                return GetNext()->GetProxyInfo();

            return proxy_info_; // may be invalid.
        }

    protected:
        // 只给同类使用
        virtual bool HasNext() { return GetNext() != NULL; }
        virtual Agent* GetNext() { return next_agent_.get(); }
        virtual bool SetNext(std::unique_ptr<Agent> agent)
        {
            next_agent_ = std::move(agent);
            return true;
        }

        ProxyInfo proxy_info_;
        AgentType type_;

    private:
        std::unique_ptr<Agent> next_agent_;
    }; // Agent

    // 向Provider索要外部挂载的代理，结果通过ProxyInfo带出。如果Provider的Agent均没有任何代理输出，请把ProxyInfo保持原样！
    virtual int ResolveProxy(
        const HttpRequestInfo& request,
        ProxyInfo* result,
        const BoundNetLog& net_log)
        = 0;

    // Provider提供的代理出错了，做下记录
    virtual void SetProxyError(HostPortPair proxy, int errorCode) = 0;

private:
};

} // namespace net

#endif // NET_TENCENT_PROXY_PROVIDER_H_
