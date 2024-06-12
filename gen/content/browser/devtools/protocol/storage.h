// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_protocol_Storage_h
#define content_protocol_Storage_h

#include "content/browser/devtools/protocol/protocol.h"
#include "content/common/content_export.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.

namespace content {
namespace protocol {
    namespace Storage {

        // ------------- Forward and enum declarations.
        // Enum of possible storage types.
        using StorageType = String;

        namespace StorageTypeEnum {
            CONTENT_EXPORT extern const char* Appcache;
            CONTENT_EXPORT extern const char* Cookies;
            CONTENT_EXPORT extern const char* File_systems;
            CONTENT_EXPORT extern const char* Indexeddb;
            CONTENT_EXPORT extern const char* Local_storage;
            CONTENT_EXPORT extern const char* Shader_cache;
            CONTENT_EXPORT extern const char* Websql;
            CONTENT_EXPORT extern const char* Service_workers;
            CONTENT_EXPORT extern const char* Cache_storage;
            CONTENT_EXPORT extern const char* All;
        } // namespace StorageTypeEnum

        // ------------- Type and builder declarations.

        // ------------- Backend interface.

        class CONTENT_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse ClearDataForOrigin(const String& in_origin, const String& in_storageTypes) = 0;

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

    } // namespace Storage
} // namespace content
} // namespace protocol

#endif // !defined(content_protocol_Storage_h)
