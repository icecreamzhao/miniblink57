// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/url_request/url_request_interceptor.h"

namespace net {

URLRequestInterceptor::URLRequestInterceptor()
{
}

URLRequestInterceptor::~URLRequestInterceptor()
{
}

URLRequestJob* URLRequestInterceptor::MaybeInterceptRedirect(
    URLRequest* request,
    NetworkDelegate* network_delegate,
    const GURL& location) const
{
    return nullptr;
}

URLRequestJob* URLRequestInterceptor::MaybeInterceptResponse(
    URLRequest* request, NetworkDelegate* network_delegate) const
{
    return nullptr;
}

} // namespace net
