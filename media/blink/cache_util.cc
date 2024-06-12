// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/blink/cache_util.h"

#include <stddef.h>

#include <string>

#include "base/macros.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/string_util.h"
#include "base/time/time.h"
// #include "net/http/http_util.h"
// #include "net/http/http_version.h"
#include "third_party/WebKit/public/platform/WebString.h"
#include "third_party/WebKit/public/platform/WebURLResponse.h"

using base::Time;
using base::TimeDelta;
//using net::HttpVersion;
using blink::WebURLResponse;

namespace media {

enum { kHttpOK = 200,
    kHttpPartialContent = 206 };
#define HTTP_LWS " \t"

bool IsLWS(char c)
{
    return strchr(HTTP_LWS, c) != NULL;
}

void TrimLWS(std::string::const_iterator* begin, std::string::const_iterator* end)
{
    // leading whitespace
    while (*begin < *end && IsLWS((*begin)[0]))
        ++(*begin);

    // trailing whitespace
    while (*begin < *end && IsLWS((*end)[-1]))
        --(*end);
}

bool HasStrongValidators(int version, const std::string& etag_header, const std::string& last_modified_header, const std::string& date_header)
{
    if (version < WebURLResponse::HTTPVersion_1_1)
        return false;

    if (!etag_header.empty()) {
        size_t slash = etag_header.find('/');
        if (slash == std::string::npos || slash == 0)
            return true;

        std::string::const_iterator i = etag_header.begin();
        std::string::const_iterator j = etag_header.begin() + slash;
        TrimLWS(&i, &j);
        if (!base::LowerCaseEqualsASCII(base::StringPiece(i, j), "w"))
            return true;
    }

    base::Time last_modified;
    if (!base::Time::FromString(last_modified_header.c_str(), &last_modified))
        return false;

    base::Time date;
    if (!base::Time::FromString(date_header.c_str(), &date))
        return false;

    return ((date - last_modified).InSeconds() >= 60);
}

uint32_t GetReasonsForUncacheability(const WebURLResponse& response)
{
    uint32_t reasons = 0;
    const int code = response.httpStatusCode();
    const int version = response.httpVersion();
    const int http_version = version;
    //       version == WebURLResponse::HTTPVersion_2_0
    //           ? HttpVersion(2, 0)
    //           : version == WebURLResponse::HTTPVersion_1_1
    //                 ? HttpVersion(1, 1)
    //                 : version == WebURLResponse::HTTPVersion_1_0
    //                       ? HttpVersion(1, 0)
    //                       : version == WebURLResponse::HTTPVersion_0_9
    //                             ? HttpVersion(0, 9)
    //                             : HttpVersion();
    if (code != kHttpOK && code != kHttpPartialContent)
        reasons |= kNoData;
    if (http_version < WebURLResponse::HTTPVersion_1_1 && code == kHttpPartialContent)
        reasons |= kPre11PartialResponse;
    if (code == kHttpPartialContent && !HasStrongValidators(http_version, response.httpHeaderField("etag").utf8(), response.httpHeaderField("Last-Modified").utf8(), response.httpHeaderField("Date").utf8())) {
        reasons |= kNoStrongValidatorOnPartialResponse;
    }

    std::string cache_control_header = base::ToLowerASCII(response.httpHeaderField("cache-control").utf8());
    if (cache_control_header.find("no-cache") != std::string::npos)
        reasons |= kNoCache;
    if (cache_control_header.find("no-store") != std::string::npos)
        reasons |= kNoStore;
    if (cache_control_header.find("must-revalidate") != std::string::npos)
        reasons |= kHasMustRevalidate;

    const TimeDelta kMinimumAgeForUsefulness = TimeDelta::FromSeconds(3600); // Arbitrary value.

    const char kMaxAgePrefix[] = "max-age=";
    const size_t kMaxAgePrefixLen = arraysize(kMaxAgePrefix) - 1;
    if (cache_control_header.substr(0, kMaxAgePrefixLen) == kMaxAgePrefix) {
        int64_t max_age_seconds;
        base::StringToInt64(
            base::StringPiece(cache_control_header.begin() + kMaxAgePrefixLen,
                cache_control_header.end()),
            &max_age_seconds);
        if (TimeDelta::FromSeconds(max_age_seconds) < kMinimumAgeForUsefulness)
            reasons |= kShortMaxAge;
    }

    Time date;
    Time expires;
    if (Time::FromString(response.httpHeaderField("Date").utf8().data(), &date) && Time::FromString(response.httpHeaderField("Expires").utf8().data(), &expires) && date > Time() && expires > Time() && (expires - date) < kMinimumAgeForUsefulness) {
        reasons |= kExpiresTooSoon;
    }

    return reasons;
}

base::TimeDelta GetCacheValidUntil(const WebURLResponse& response)
{
    std::string cache_control_header = base::ToLowerASCII(response.httpHeaderField("cache-control").utf8());
    if (cache_control_header.find("no-cache") != std::string::npos)
        return base::TimeDelta();
    if (cache_control_header.find("must-revalidate") != std::string::npos)
        return base::TimeDelta();

    // Max cache timeout ~= 1 month.
    base::TimeDelta ret = base::TimeDelta::FromDays(30);

    const char kMaxAgePrefix[] = "max-age=";
    const size_t kMaxAgePrefixLen = arraysize(kMaxAgePrefix) - 1;
    if (cache_control_header.substr(0, kMaxAgePrefixLen) == kMaxAgePrefix) {
        int64_t max_age_seconds;
        base::StringToInt64(
            base::StringPiece(cache_control_header.begin() + kMaxAgePrefixLen,
                cache_control_header.end()),
            &max_age_seconds);

        ret = std::min(ret, TimeDelta::FromSeconds(max_age_seconds));
    } else {
        // Note that |date| may be smaller than |expires|, which means we'll
        // return a timetick some time in the past.
        Time date;
        Time expires;
        if (Time::FromString(response.httpHeaderField("Date").utf8().data(),
                &date)
            && Time::FromString(response.httpHeaderField("Expires").utf8().data(),
                &expires)
            && date > Time() && expires > Time()) {
            ret = std::min(ret, expires - date);
        }
    }

    return ret;
}

} // namespace media
