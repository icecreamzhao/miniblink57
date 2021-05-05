// Copyright (c) 2016 The Tencent Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/* Author : Coomy.
 * Date   : 2016.8.26
 * Desc   : 网络自定义代理接口，content层实现之
 *
 * */

#ifndef NET_TENCENT_PROXY_LISTENER_H_
#define NET_TENCENT_PROXY_LISTENER_H_

namespace net {
class URLRequest;

// NetworkDelegate中按需要创建
// 这个接口提供给ProxyProvider去使用，它构造了类似NetworkDelegate的我们【需要】的一些通知接口！
// 当Provider需要感知NetworkDelegate的一些回调信息，并逐个的通知给Agent，那就需要在这里扩展通知。provider和agent都会实现这个接口，因此就形成了一个类似装饰者模式的实现！
class ProxyListener {
public:
    ProxyListener() { }
    virtual ~ProxyListener() { }

    virtual void OnResponseStarted(URLRequest* request) = 0;
    virtual void OnCompleted(URLRequest* request, bool started) = 0;
};

} // namespace net

#endif // NET_TENCENT_PROXY_LISTENER_H_
