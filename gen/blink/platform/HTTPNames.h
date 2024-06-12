// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HTTPNames_h
#define HTTPNames_h

#include "platform/PlatformExport.h"
#include "wtf/text/AtomicString.h"

// Generated from:
// - ../../third_party/WebKit/Source/platform/network/HTTPNames.in

namespace blink {
namespace HTTPNames {

    PLATFORM_EXPORT extern const WTF::AtomicString& Accept;
    PLATFORM_EXPORT extern const WTF::AtomicString& Accept_CH;
    PLATFORM_EXPORT extern const WTF::AtomicString& Access_Control_Allow_External;
    PLATFORM_EXPORT extern const WTF::AtomicString& Access_Control_Allow_Headers;
    PLATFORM_EXPORT extern const WTF::AtomicString& Access_Control_Allow_Methods;
    PLATFORM_EXPORT extern const WTF::AtomicString& Access_Control_Allow_Origin;
    PLATFORM_EXPORT extern const WTF::AtomicString& Access_Control_Expose_Headers;
    PLATFORM_EXPORT extern const WTF::AtomicString& Access_Control_Max_Age;
    PLATFORM_EXPORT extern const WTF::AtomicString& Access_Control_Request_External;
    PLATFORM_EXPORT extern const WTF::AtomicString& Access_Control_Request_Headers;
    PLATFORM_EXPORT extern const WTF::AtomicString& Access_Control_Request_Method;
    PLATFORM_EXPORT extern const WTF::AtomicString& Allow_CSP_From;
    PLATFORM_EXPORT extern const WTF::AtomicString& Cache_Control;
    PLATFORM_EXPORT extern const WTF::AtomicString& Content_DPR;
    PLATFORM_EXPORT extern const WTF::AtomicString& Content_Disposition;
    PLATFORM_EXPORT extern const WTF::AtomicString& Content_Language;
    PLATFORM_EXPORT extern const WTF::AtomicString& Content_Security_Policy;
    PLATFORM_EXPORT extern const WTF::AtomicString& Content_Security_Policy_Report_Only;
    PLATFORM_EXPORT extern const WTF::AtomicString& Content_Type;
    PLATFORM_EXPORT extern const WTF::AtomicString& Date;
    PLATFORM_EXPORT extern const WTF::AtomicString& ETag;
    PLATFORM_EXPORT extern const WTF::AtomicString& Embedding_CSP;
    PLATFORM_EXPORT extern const WTF::AtomicString& Expires;
    PLATFORM_EXPORT extern const WTF::AtomicString& Feature_Policy;
    PLATFORM_EXPORT extern const WTF::AtomicString& GET;
    PLATFORM_EXPORT extern const WTF::AtomicString& HEAD;
    PLATFORM_EXPORT extern const WTF::AtomicString& If_Match;
    PLATFORM_EXPORT extern const WTF::AtomicString& If_Modified_Since;
    PLATFORM_EXPORT extern const WTF::AtomicString& If_None_Match;
    PLATFORM_EXPORT extern const WTF::AtomicString& If_Range;
    PLATFORM_EXPORT extern const WTF::AtomicString& If_Unmodified_Since;
    PLATFORM_EXPORT extern const WTF::AtomicString& Last_Event_ID;
    PLATFORM_EXPORT extern const WTF::AtomicString& Last_Modified;
    PLATFORM_EXPORT extern const WTF::AtomicString& Link;
    PLATFORM_EXPORT extern const WTF::AtomicString& Location;
    PLATFORM_EXPORT extern const WTF::AtomicString& OPTIONS;
    PLATFORM_EXPORT extern const WTF::AtomicString& Origin;
    PLATFORM_EXPORT extern const WTF::AtomicString& Origin_Trial;
    PLATFORM_EXPORT extern const WTF::AtomicString& POST;
    PLATFORM_EXPORT extern const WTF::AtomicString& Ping_From;
    PLATFORM_EXPORT extern const WTF::AtomicString& Ping_To;
    PLATFORM_EXPORT extern const WTF::AtomicString& Pragma;
    PLATFORM_EXPORT extern const WTF::AtomicString& Purpose;
    PLATFORM_EXPORT extern const WTF::AtomicString& Range;
    PLATFORM_EXPORT extern const WTF::AtomicString& Referer;
    PLATFORM_EXPORT extern const WTF::AtomicString& Referrer_Policy;
    PLATFORM_EXPORT extern const WTF::AtomicString& Refresh;
    PLATFORM_EXPORT extern const WTF::AtomicString& Resource_Freshness;
    PLATFORM_EXPORT extern const WTF::AtomicString& SourceMap;
    PLATFORM_EXPORT extern const WTF::AtomicString& Suborigin;
    PLATFORM_EXPORT extern const WTF::AtomicString& Timing_Allow_Origin;
    PLATFORM_EXPORT extern const WTF::AtomicString& Upgrade_Insecure_Requests;
    PLATFORM_EXPORT extern const WTF::AtomicString& User_Agent;
    PLATFORM_EXPORT extern const WTF::AtomicString& Vary;
    PLATFORM_EXPORT extern const WTF::AtomicString& X_Content_Type_Options;
    PLATFORM_EXPORT extern const WTF::AtomicString& X_DNS_Prefetch_Control;
    PLATFORM_EXPORT extern const WTF::AtomicString& X_DevTools_Emulate_Network_Conditions_Client_Id;
    PLATFORM_EXPORT extern const WTF::AtomicString& X_Frame_Options;
    PLATFORM_EXPORT extern const WTF::AtomicString& X_SourceMap;
    PLATFORM_EXPORT extern const WTF::AtomicString& X_XSS_Protection;

    const unsigned HTTPNamesCount = 60;

    PLATFORM_EXPORT void init();

} // HTTPNames
} // namespace blink

#endif
