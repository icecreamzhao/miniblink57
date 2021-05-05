// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "HTTPNames.h"

#include "wtf/StdLibExtras.h"

// Generated from:
// - ../../third_party/WebKit/Source/platform/network/HTTPNames.in

namespace blink {
namespace HTTPNames {

    using namespace WTF;

    void* NamesStorage[HTTPNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

    const AtomicString& Accept = reinterpret_cast<AtomicString*>(&NamesStorage)[0];
    const AtomicString& Accept_CH = reinterpret_cast<AtomicString*>(&NamesStorage)[1];
    const AtomicString& Access_Control_Allow_External = reinterpret_cast<AtomicString*>(&NamesStorage)[2];
    const AtomicString& Access_Control_Allow_Headers = reinterpret_cast<AtomicString*>(&NamesStorage)[3];
    const AtomicString& Access_Control_Allow_Methods = reinterpret_cast<AtomicString*>(&NamesStorage)[4];
    const AtomicString& Access_Control_Allow_Origin = reinterpret_cast<AtomicString*>(&NamesStorage)[5];
    const AtomicString& Access_Control_Expose_Headers = reinterpret_cast<AtomicString*>(&NamesStorage)[6];
    const AtomicString& Access_Control_Max_Age = reinterpret_cast<AtomicString*>(&NamesStorage)[7];
    const AtomicString& Access_Control_Request_External = reinterpret_cast<AtomicString*>(&NamesStorage)[8];
    const AtomicString& Access_Control_Request_Headers = reinterpret_cast<AtomicString*>(&NamesStorage)[9];
    const AtomicString& Access_Control_Request_Method = reinterpret_cast<AtomicString*>(&NamesStorage)[10];
    const AtomicString& Allow_CSP_From = reinterpret_cast<AtomicString*>(&NamesStorage)[11];
    const AtomicString& Cache_Control = reinterpret_cast<AtomicString*>(&NamesStorage)[12];
    const AtomicString& Content_DPR = reinterpret_cast<AtomicString*>(&NamesStorage)[13];
    const AtomicString& Content_Disposition = reinterpret_cast<AtomicString*>(&NamesStorage)[14];
    const AtomicString& Content_Language = reinterpret_cast<AtomicString*>(&NamesStorage)[15];
    const AtomicString& Content_Security_Policy = reinterpret_cast<AtomicString*>(&NamesStorage)[16];
    const AtomicString& Content_Security_Policy_Report_Only = reinterpret_cast<AtomicString*>(&NamesStorage)[17];
    const AtomicString& Content_Type = reinterpret_cast<AtomicString*>(&NamesStorage)[18];
    const AtomicString& Date = reinterpret_cast<AtomicString*>(&NamesStorage)[19];
    const AtomicString& ETag = reinterpret_cast<AtomicString*>(&NamesStorage)[20];
    const AtomicString& Embedding_CSP = reinterpret_cast<AtomicString*>(&NamesStorage)[21];
    const AtomicString& Expires = reinterpret_cast<AtomicString*>(&NamesStorage)[22];
    const AtomicString& Feature_Policy = reinterpret_cast<AtomicString*>(&NamesStorage)[23];
    const AtomicString& GET = reinterpret_cast<AtomicString*>(&NamesStorage)[24];
    const AtomicString& HEAD = reinterpret_cast<AtomicString*>(&NamesStorage)[25];
    const AtomicString& If_Match = reinterpret_cast<AtomicString*>(&NamesStorage)[26];
    const AtomicString& If_Modified_Since = reinterpret_cast<AtomicString*>(&NamesStorage)[27];
    const AtomicString& If_None_Match = reinterpret_cast<AtomicString*>(&NamesStorage)[28];
    const AtomicString& If_Range = reinterpret_cast<AtomicString*>(&NamesStorage)[29];
    const AtomicString& If_Unmodified_Since = reinterpret_cast<AtomicString*>(&NamesStorage)[30];
    const AtomicString& Last_Event_ID = reinterpret_cast<AtomicString*>(&NamesStorage)[31];
    const AtomicString& Last_Modified = reinterpret_cast<AtomicString*>(&NamesStorage)[32];
    const AtomicString& Link = reinterpret_cast<AtomicString*>(&NamesStorage)[33];
    const AtomicString& Location = reinterpret_cast<AtomicString*>(&NamesStorage)[34];
    const AtomicString& OPTIONS = reinterpret_cast<AtomicString*>(&NamesStorage)[35];
    const AtomicString& Origin = reinterpret_cast<AtomicString*>(&NamesStorage)[36];
    const AtomicString& Origin_Trial = reinterpret_cast<AtomicString*>(&NamesStorage)[37];
    const AtomicString& POST = reinterpret_cast<AtomicString*>(&NamesStorage)[38];
    const AtomicString& Ping_From = reinterpret_cast<AtomicString*>(&NamesStorage)[39];
    const AtomicString& Ping_To = reinterpret_cast<AtomicString*>(&NamesStorage)[40];
    const AtomicString& Pragma = reinterpret_cast<AtomicString*>(&NamesStorage)[41];
    const AtomicString& Purpose = reinterpret_cast<AtomicString*>(&NamesStorage)[42];
    const AtomicString& Range = reinterpret_cast<AtomicString*>(&NamesStorage)[43];
    const AtomicString& Referer = reinterpret_cast<AtomicString*>(&NamesStorage)[44];
    const AtomicString& Referrer_Policy = reinterpret_cast<AtomicString*>(&NamesStorage)[45];
    const AtomicString& Refresh = reinterpret_cast<AtomicString*>(&NamesStorage)[46];
    const AtomicString& Resource_Freshness = reinterpret_cast<AtomicString*>(&NamesStorage)[47];
    const AtomicString& SourceMap = reinterpret_cast<AtomicString*>(&NamesStorage)[48];
    const AtomicString& Suborigin = reinterpret_cast<AtomicString*>(&NamesStorage)[49];
    const AtomicString& Timing_Allow_Origin = reinterpret_cast<AtomicString*>(&NamesStorage)[50];
    const AtomicString& Upgrade_Insecure_Requests = reinterpret_cast<AtomicString*>(&NamesStorage)[51];
    const AtomicString& User_Agent = reinterpret_cast<AtomicString*>(&NamesStorage)[52];
    const AtomicString& Vary = reinterpret_cast<AtomicString*>(&NamesStorage)[53];
    const AtomicString& X_Content_Type_Options = reinterpret_cast<AtomicString*>(&NamesStorage)[54];
    const AtomicString& X_DNS_Prefetch_Control = reinterpret_cast<AtomicString*>(&NamesStorage)[55];
    const AtomicString& X_DevTools_Emulate_Network_Conditions_Client_Id = reinterpret_cast<AtomicString*>(&NamesStorage)[56];
    const AtomicString& X_Frame_Options = reinterpret_cast<AtomicString*>(&NamesStorage)[57];
    const AtomicString& X_SourceMap = reinterpret_cast<AtomicString*>(&NamesStorage)[58];
    const AtomicString& X_XSS_Protection = reinterpret_cast<AtomicString*>(&NamesStorage)[59];

    void init()
    {
        struct NameEntry {
            const char* name;
            unsigned hash;
            unsigned char length;
        };

        static const NameEntry kNames[] = {
            { "Accept", 16044384, 6 },
            { "Accept-CH", 8016737, 9 },
            { "Access-Control-Allow-External", 8605227, 29 },
            { "Access-Control-Allow-Headers", 1266438, 28 },
            { "Access-Control-Allow-Methods", 3562078, 28 },
            { "Access-Control-Allow-Origin", 15441179, 27 },
            { "Access-Control-Expose-Headers", 7723476, 29 },
            { "Access-Control-Max-Age", 283611, 22 },
            { "Access-Control-Request-External", 7007971, 31 },
            { "Access-Control-Request-Headers", 1508482, 30 },
            { "Access-Control-Request-Method", 16377097, 29 },
            { "Allow-CSP-From", 12361355, 14 },
            { "Cache-Control", 7757542, 13 },
            { "Content-DPR", 8569724, 11 },
            { "Content-Disposition", 362682, 19 },
            { "Content-Language", 3105184, 16 },
            { "Content-Security-Policy", 4305016, 23 },
            { "Content-Security-Policy-Report-Only", 13963024, 35 },
            { "Content-Type", 7448957, 12 },
            { "Date", 3151137, 4 },
            { "ETag", 10343133, 4 },
            { "Embedding-CSP", 8731345, 13 },
            { "Expires", 9729139, 7 },
            { "Feature-Policy", 1082240, 14 },
            { "GET", 1490282, 3 },
            { "HEAD", 3699341, 4 },
            { "If-Match", 10647657, 8 },
            { "If-Modified-Since", 13772578, 17 },
            { "If-None-Match", 4893326, 13 },
            { "If-Range", 8269837, 8 },
            { "If-Unmodified-Since", 12269155, 19 },
            { "Last-Event-ID", 2469869, 13 },
            { "Last-Modified", 3916406, 13 },
            { "Link", 1568545, 4 },
            { "Location", 1088524, 8 },
            { "OPTIONS", 680577, 7 },
            { "Origin", 13877165, 6 },
            { "Origin-Trial", 12788968, 12 },
            { "POST", 13393727, 4 },
            { "Ping-From", 10612987, 9 },
            { "Ping-To", 1685887, 7 },
            { "Pragma", 7452047, 6 },
            { "Purpose", 7036395, 7 },
            { "Range", 6535599, 5 },
            { "Referer", 15797945, 7 },
            { "Referrer-Policy", 11153730, 15 },
            { "Refresh", 7822740, 7 },
            { "Resource-Freshness", 15499919, 18 },
            { "SourceMap", 10731005, 9 },
            { "Suborigin", 428756, 9 },
            { "Timing-Allow-Origin", 3756500, 19 },
            { "Upgrade-Insecure-Requests", 15356604, 25 },
            { "User-Agent", 13018365, 10 },
            { "Vary", 16275252, 4 },
            { "X-Content-Type-Options", 7241058, 22 },
            { "X-DNS-Prefetch-Control", 8848020, 22 },
            { "X-DevTools-Emulate-Network-Conditions-Client-Id", 2223533, 47 },
            { "X-Frame-Options", 15031229, 15 },
            { "X-SourceMap", 10540689, 11 },
            { "X-XSS-Protection", 15642148, 16 },
        };

        for (size_t i = 0; i < WTF_ARRAY_LENGTH(kNames); i++) {
            StringImpl* stringImpl = StringImpl::createStatic(kNames[i].name, kNames[i].length, kNames[i].hash);
            void* address = reinterpret_cast<AtomicString*>(&NamesStorage) + i;
            new (address) AtomicString(stringImpl);
        }
    }

} // HTTPNames
} // namespace blink
