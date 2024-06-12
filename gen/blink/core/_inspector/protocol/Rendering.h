// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_Rendering_h
#define blink_protocol_Rendering_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.

namespace blink {
namespace protocol {
    namespace Rendering {

        // ------------- Forward and enum declarations.

        // ------------- Type and builder declarations.

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse setShowPaintRects(bool in_result) = 0;
            virtual DispatchResponse setShowDebugBorders(bool in_show) = 0;
            virtual DispatchResponse setShowFPSCounter(bool in_show) = 0;
            virtual DispatchResponse setShowScrollBottleneckRects(bool in_show) = 0;
            virtual DispatchResponse setShowViewportSizeOnResize(bool in_show) = 0;

            virtual DispatchResponse disable()
            {
                return DispatchResponse::OK();
            }
        };

        // ------------- Frontend interface.

        class CORE_EXPORT Frontend {
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

        class CORE_EXPORT Dispatcher {
        public:
            static void wire(UberDispatcher*, Backend*);

        private:
            Dispatcher() { }
        };

        // ------------- Metainfo.

        class CORE_EXPORT Metainfo {
        public:
            using BackendClass = Backend;
            using FrontendClass = Frontend;
            using DispatcherClass = Dispatcher;
            static const char domainName[];
            static const char commandPrefix[];
            static const char version[];
        };

    } // namespace Rendering
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_Rendering_h)
