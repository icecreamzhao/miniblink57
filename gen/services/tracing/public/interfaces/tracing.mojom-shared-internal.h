// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_TRACING_PUBLIC_INTERFACES_TRACING_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_TRACING_PUBLIC_INTERFACES_TRACING_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace tracing {
namespace mojom {
    namespace internal {
        class StartupPerformanceTimes_Data;

#pragma pack(push, 1)
        class StartupPerformanceTimes_Data {
        public:
            static StartupPerformanceTimes_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StartupPerformanceTimes_Data))) StartupPerformanceTimes_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t service_manager_process_creation_time;
            int64_t service_manager_main_entry_point_time;
            int64_t browser_message_loop_start_ticks;
            int64_t browser_window_display_ticks;
            int64_t browser_open_tabs_time_delta;
            int64_t first_web_contents_main_frame_load_ticks;
            int64_t first_visually_non_empty_layout_ticks;

        private:
            StartupPerformanceTimes_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StartupPerformanceTimes_Data() = delete;
        };
        static_assert(sizeof(StartupPerformanceTimes_Data) == 64,
            "Bad sizeof(StartupPerformanceTimes_Data)");
        constexpr uint32_t kProvider_StartTracing_Name = 0;
        class Provider_StartTracing_Params_Data {
        public:
            static Provider_StartTracing_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Provider_StartTracing_Params_Data))) Provider_StartTracing_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> categories;
            mojo::internal::Interface_Data recorder;

        private:
            Provider_StartTracing_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Provider_StartTracing_Params_Data() = delete;
        };
        static_assert(sizeof(Provider_StartTracing_Params_Data) == 24,
            "Bad sizeof(Provider_StartTracing_Params_Data)");
        constexpr uint32_t kProvider_StopTracing_Name = 1;
        class Provider_StopTracing_Params_Data {
        public:
            static Provider_StopTracing_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Provider_StopTracing_Params_Data))) Provider_StopTracing_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Provider_StopTracing_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Provider_StopTracing_Params_Data() = delete;
        };
        static_assert(sizeof(Provider_StopTracing_Params_Data) == 8,
            "Bad sizeof(Provider_StopTracing_Params_Data)");
        constexpr uint32_t kRecorder_Record_Name = 0;
        class Recorder_Record_Params_Data {
        public:
            static Recorder_Record_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Recorder_Record_Params_Data))) Recorder_Record_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> json;

        private:
            Recorder_Record_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Recorder_Record_Params_Data() = delete;
        };
        static_assert(sizeof(Recorder_Record_Params_Data) == 16,
            "Bad sizeof(Recorder_Record_Params_Data)");
        constexpr uint32_t kCollector_Start_Name = 0;
        class Collector_Start_Params_Data {
        public:
            static Collector_Start_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Collector_Start_Params_Data))) Collector_Start_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data stream;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> categories;

        private:
            Collector_Start_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Collector_Start_Params_Data() = delete;
        };
        static_assert(sizeof(Collector_Start_Params_Data) == 24,
            "Bad sizeof(Collector_Start_Params_Data)");
        constexpr uint32_t kCollector_StopAndFlush_Name = 1;
        class Collector_StopAndFlush_Params_Data {
        public:
            static Collector_StopAndFlush_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Collector_StopAndFlush_Params_Data))) Collector_StopAndFlush_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Collector_StopAndFlush_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Collector_StopAndFlush_Params_Data() = delete;
        };
        static_assert(sizeof(Collector_StopAndFlush_Params_Data) == 8,
            "Bad sizeof(Collector_StopAndFlush_Params_Data)");
        constexpr uint32_t kStartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Name = 0;
        class StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data {
        public:
            static StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data))) StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t time;

        private:
            StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data() = delete;
        };
        static_assert(sizeof(StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data) == 16,
            "Bad sizeof(StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data)");
        constexpr uint32_t kStartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Name = 1;
        class StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data {
        public:
            static StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data))) StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t time;

        private:
            StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data() = delete;
        };
        static_assert(sizeof(StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data) == 16,
            "Bad sizeof(StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data)");
        constexpr uint32_t kStartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Name = 2;
        class StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data {
        public:
            static StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data))) StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t ticks;

        private:
            StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data() = delete;
        };
        static_assert(sizeof(StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data) == 16,
            "Bad sizeof(StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data)");
        constexpr uint32_t kStartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Name = 3;
        class StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data {
        public:
            static StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data))) StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t ticks;

        private:
            StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data() = delete;
        };
        static_assert(sizeof(StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data) == 16,
            "Bad sizeof(StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data)");
        constexpr uint32_t kStartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Name = 4;
        class StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data {
        public:
            static StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data))) StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t delta;

        private:
            StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data() = delete;
        };
        static_assert(sizeof(StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data) == 16,
            "Bad sizeof(StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data)");
        constexpr uint32_t kStartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Name = 5;
        class StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data {
        public:
            static StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data))) StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t ticks;

        private:
            StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data() = delete;
        };
        static_assert(sizeof(StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data) == 16,
            "Bad sizeof(StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data)");
        constexpr uint32_t kStartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Name = 6;
        class StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data {
        public:
            static StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data))) StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t ticks;

        private:
            StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data() = delete;
        };
        static_assert(sizeof(StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data) == 16,
            "Bad sizeof(StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data)");
        constexpr uint32_t kStartupPerformanceDataCollector_GetStartupPerformanceTimes_Name = 7;
        class StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data {
        public:
            static StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data))) StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data() = delete;
        };
        static_assert(sizeof(StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data) == 8,
            "Bad sizeof(StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data)");
        class StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data {
        public:
            static StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data))) StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::StartupPerformanceTimes_Data> times;

        private:
            StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data) == 16,
            "Bad sizeof(StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data)");
        constexpr uint32_t kFactory_CreateRecorder_Name = 0;
        class Factory_CreateRecorder_Params_Data {
        public:
            static Factory_CreateRecorder_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Factory_CreateRecorder_Params_Data))) Factory_CreateRecorder_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data provider;

        private:
            Factory_CreateRecorder_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Factory_CreateRecorder_Params_Data() = delete;
        };
        static_assert(sizeof(Factory_CreateRecorder_Params_Data) == 16,
            "Bad sizeof(Factory_CreateRecorder_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace tracing

#endif // SERVICES_TRACING_PUBLIC_INTERFACES_TRACING_MOJOM_SHARED_INTERNAL_H_