// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_HTTP_HTTP_REQUEST_INFO_H__
#define NET_HTTP_HTTP_REQUEST_INFO_H__

#include <string>

#include "net/base/net_export.h"
#include "net/base/privacy_mode.h"
#include "net/http/http_request_headers.h"
#include "tencent/build/config_net.h"
#include "url/gurl.h"

namespace net {

class UploadDataStream;

struct NET_EXPORT HttpRequestInfo {
    enum RequestMotivation {
        // TODO(mbelshe): move these into Client Socket.
        PRECONNECT_MOTIVATED, // Request was motivated by a prefetch.
        OMNIBOX_MOTIVATED, // Request was motivated by the omnibox.
        NORMAL_MOTIVATION, // No special motivation associated with the request.
        EARLY_LOAD_MOTIVATED, // When browser asks a tab to open an URL, this short
        // circuits that path (of waiting for the renderer to
        // do the URL request), and starts loading ASAP.
    };

#if ENABLE_TENCENT(NETWORK_REFACTOR)
    // 我们的网络是资源敏感的，很多逻辑需要依赖资源类型去做，因此必须添加这些信息；
    // 应该与 content/public/common/resource_type.h 一致
    enum Type {
        MAIN_FRAME = 0, // top level page
        SUB_FRAME, // frame or iframe
        STYLESHEET, // a CSS stylesheet
        SCRIPT, // an external script
        IMAGE, // an image (jpg/gif/png/etc)
        FONT_RESOURCE, // a font
        SUB_RESOURCE, // an "other" subresource.
        OBJECT, // an object (or embed) tag for a plugin,
        // or a resource that a plugin requested.
        MEDIA, // a media resource.
        WORKER, // the main resource of a dedicated worker.
        SHARED_WORKER, // the main resource of a shared worker.
        PREFETCH, // an explicitly requested prefetch
        FAVICON, // a favicon
        XHR, // a XMLHttpRequest
        RESOURCE_TYPE_PING, // a ping request for <a ping>/sendBeacon.
        RESOURCE_TYPE_SERVICE_WORKER, // the main resource of a service worker.
        RESOURCE_TYPE_CSP_REPORT, // a report of Content Security Policy
        // violations.
        RESOURCE_TYPE_PLUGIN_RESOURCE, // a resource that a plugin requested.
        RESOURCE_TYPE_LAST_TYPE,
        LAST_TYPE // Place holder so we don't need to change ValidType
        // everytime.
    };

    int resource_type;
#endif

    HttpRequestInfo();
    HttpRequestInfo(const HttpRequestInfo& other);
    ~HttpRequestInfo();

    // The requested URL.
    GURL url;

    // The method to use (GET, POST, etc.).
    std::string method;

    // Any extra request headers (including User-Agent).
    HttpRequestHeaders extra_headers;

    // Any upload data.
    UploadDataStream* upload_data_stream;

    // Any load flags (see load_flags.h).
    int load_flags;

    // The motivation behind this request.
    RequestMotivation motivation;

    // If enabled, then request must be sent over connection that cannot be
    // tracked by the server (e.g. without channel id).
    PrivacyMode privacy_mode;

    // If present, the host of the referrer whose TokenBindingID should be
    // included in a referred TokenBinding.
    std::string token_binding_referrer;
};

} // namespace net

#endif // NET_HTTP_HTTP_REQUEST_INFO_H__
