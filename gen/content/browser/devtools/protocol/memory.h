// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_protocol_Memory_h
#define content_protocol_Memory_h

#include "content/browser/devtools/protocol/protocol.h"
#include "content/common/content_export.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.

namespace content {
namespace protocol {
    namespace Memory {

        // ------------- Forward and enum declarations.
        // Memory pressure level.
        using PressureLevel = String;

        namespace PressureLevelEnum {
            CONTENT_EXPORT extern const char* Moderate;
            CONTENT_EXPORT extern const char* Critical;
        } // namespace PressureLevelEnum

        // ------------- Type and builder declarations.

        // ------------- Backend interface.

        class CONTENT_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse SetPressureNotificationsSuppressed(bool in_suppressed) = 0;
            virtual DispatchResponse SimulatePressureNotification(const String& in_level) = 0;

            virtual DispatchResponse Disable()
            {
                return DispatchResponse::OK();
            }
        };

        // ------------- Frontend interface.

        class CONTENT_EXPORT Frontend {
        public:
            explicit Frontend(FrontendChannel* frontendChannel)
                : m_frontendChannel(frontendChannel)
            {
            }

            void flush();
            void sendRawNotification(const String&);

        private:
            FrontendChannel* m_frontendChannel;
        };

        // ------------- Dispatcher.

        class CONTENT_EXPORT Dispatcher {
        public:
            static void wire(UberDispatcher*, Backend*);

        private:
            Dispatcher() { }
        };

        // ------------- Metainfo.

        class CONTENT_EXPORT Metainfo {
        public:
            using BackendClass = Backend;
            using FrontendClass = Frontend;
            using DispatcherClass = Dispatcher;
            static const char domainName[];
            static const char commandPrefix[];
            static const char version[];
        };

    } // namespace Memory
} // namespace content
} // namespace protocol

#endif // !defined(content_protocol_Memory_h)
