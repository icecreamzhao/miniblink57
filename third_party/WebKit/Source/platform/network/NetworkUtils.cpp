// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "platform/network/NetworkUtils.h"

//#include "components/mime_util/mime_util.h"
// #include "net/base/data_url.h"
// #include "net/base/ip_address.h"
// #include "net/base/net_errors.h"
// #include "net/base/registry_controlled_domains/registry_controlled_domain.h"
// #include "net/base/url_util.h"
// #include "net/http/http_response_headers.h"
#include "platform/SharedBuffer.h"
#include "platform/weborigin/KURL.h"
#include "public/platform/URLConversion.h"
#include "public/platform/WebString.h"
// #include "url/gurl.h"
#include "platform/network/HTTPParsers.h"
#include "wtf/text/StringUTF8Adaptor.h"
#include "wtf/text/WTFString.h"
#include "net/DataURL.h"

namespace {

// net::registry_controlled_domains::PrivateRegistryFilter
// getNetPrivateRegistryFilter(blink::NetworkUtils::PrivateRegistryFilter filter) {
//   switch (filter) {
//     case blink::NetworkUtils::IncludePrivateRegistries:
//       return net::registry_controlled_domains::INCLUDE_PRIVATE_REGISTRIES;
//     case blink::NetworkUtils::ExcludePrivateRegistries:
//       return net::registry_controlled_domains::EXCLUDE_PRIVATE_REGISTRIES;
//   }
//   // There are only two NetworkUtils::PrivateRegistryFilter enum entries, so
//   // we should never reach this point. However, we must have a default return
//   // value to avoid a compiler error.
//   NOTREACHED();
//   return net::registry_controlled_domains::INCLUDE_PRIVATE_REGISTRIES;
// }

} // namespace

namespace blink {

namespace NetworkUtils {

    bool isReservedIPAddress(const String& host)
    {
        //   net::IPAddress address;
        //   StringUTF8Adaptor utf8(host);
        //   if (!net::ParseURLHostnameToAddress(utf8.asStringPiece(), &address))
        //     return false;
        //   return address.IsReserved();
        return false;
    }

    bool isLocalHostname(const String& host, bool* isLocal6)
    {
        //   StringUTF8Adaptor utf8(host);
        //   return net::IsLocalHostname(utf8.asStringPiece(), isLocal6);
        return false;
    }

    String getDomainAndRegistry(const String& host, PrivateRegistryFilter filter)
    {
        //   StringUTF8Adaptor hostUtf8(host);
        //   std::string domain = net::registry_controlled_domains::GetDomainAndRegistry(
        //       hostUtf8.asStringPiece(), getNetPrivateRegistryFilter(filter));
        //   return String(domain.data(), domain.length());
        KURL url(ParsedURLString, host);
        return url.host();
    }

    PassRefPtr<SharedBuffer> parseDataURL(const KURL& url,
        AtomicString& mimeType,
        AtomicString& charset)
    {
        //   std::string utf8MimeType;
        //   std::string utf8Charset;
        //   std::string data;
        //   if (net::DataURL::Parse(WebStringToGURL(url.getString()), &utf8MimeType,
        //                           &utf8Charset, &data) &&
        //       mime_util::IsSupportedMimeType(utf8MimeType)) {
        //     mimetype = WebString::fromUTF8(utf8MimeType);
        //     charset = WebString::fromUTF8(utf8Charset);
        //     return SharedBuffer::create(data.data(), data.size());
        //   }

      String mimeTypeStr;
      String charsetStr;
      Vector<char> data;
      if (!net::parseDataURL(url, mimeTypeStr, charsetStr, data))
          return nullptr;
      
      mimeType = AtomicString(mimeTypeStr);
      charset = AtomicString(charsetStr);
      return SharedBuffer::create(data.data(), data.size());

//         String urlString = url.string();
// 
//         int index = urlString.find(',');
//         if (index == -1) {
//             return nullptr;
//         }
// 
//         String mediaType = urlString.substring(5, index - 5);
//         CString data = urlString.substring(index + 1).utf8();
// 
//         bool base64 = mediaType.endsWith(";base64", WTF::TextCaseASCIIInsensitive);
//         if (base64)
//             mediaType = mediaType.left(mediaType.length() - 7);
// 
//         if (mediaType.isEmpty())
//             mediaType = "text/plain";
// 
//         mimeType = AtomicString(extractMIMETypeFromMediaType(WTF::AtomicString(mediaType)));
//         charset = AtomicString(extractCharsetFromMediaType(WTF::AtomicString(mediaType)));
// 
//         if (charset.isEmpty())
//             charset = "US-ASCII";
// 
//         return SharedBuffer::create(data.data(), data.length());
    }

    bool isRedirectResponseCode(int responseCode)
    {
        //return net::HttpResponseHeaders::IsRedirectResponseCode(responseCode);

        // Users probably want to see 300 (multiple choice) pages, so we don't count
        // them as redirects that need to be followed.
        return (responseCode == 301 || responseCode == 302 || responseCode == 303 || responseCode == 307 || responseCode == 308);
    }

} // NetworkUtils

} // namespace blink
