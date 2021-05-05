// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_TRACING_PUBLIC_INTERFACES_TRACING_MOJOM_SHARED_H_
#define SERVICES_TRACING_PUBLIC_INTERFACES_TRACING_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/tracing/public/interfaces/tracing.mojom-shared-internal.h"

namespace tracing {
namespace mojom {
    class StartupPerformanceTimesDataView;

} // namespace mojom
} // namespace tracing

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::tracing::mojom::StartupPerformanceTimesDataView> {
        using Data = ::tracing::mojom::internal::StartupPerformanceTimes_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace tracing {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class ProviderInterfaceBase {
    };

    using ProviderPtrDataView = mojo::InterfacePtrDataView<ProviderInterfaceBase>;
    using ProviderRequestDataView = mojo::InterfaceRequestDataView<ProviderInterfaceBase>;
    using ProviderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ProviderInterfaceBase>;
    using ProviderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ProviderInterfaceBase>;
    class RecorderInterfaceBase {
    };

    using RecorderPtrDataView = mojo::InterfacePtrDataView<RecorderInterfaceBase>;
    using RecorderRequestDataView = mojo::InterfaceRequestDataView<RecorderInterfaceBase>;
    using RecorderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RecorderInterfaceBase>;
    using RecorderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RecorderInterfaceBase>;
    class CollectorInterfaceBase {
    };

    using CollectorPtrDataView = mojo::InterfacePtrDataView<CollectorInterfaceBase>;
    using CollectorRequestDataView = mojo::InterfaceRequestDataView<CollectorInterfaceBase>;
    using CollectorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<CollectorInterfaceBase>;
    using CollectorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<CollectorInterfaceBase>;
    class StartupPerformanceDataCollectorInterfaceBase {
    };

    using StartupPerformanceDataCollectorPtrDataView = mojo::InterfacePtrDataView<StartupPerformanceDataCollectorInterfaceBase>;
    using StartupPerformanceDataCollectorRequestDataView = mojo::InterfaceRequestDataView<StartupPerformanceDataCollectorInterfaceBase>;
    using StartupPerformanceDataCollectorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<StartupPerformanceDataCollectorInterfaceBase>;
    using StartupPerformanceDataCollectorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<StartupPerformanceDataCollectorInterfaceBase>;
    class FactoryInterfaceBase {
    };

    using FactoryPtrDataView = mojo::InterfacePtrDataView<FactoryInterfaceBase>;
    using FactoryRequestDataView = mojo::InterfaceRequestDataView<FactoryInterfaceBase>;
    using FactoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<FactoryInterfaceBase>;
    using FactoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<FactoryInterfaceBase>;
    class StartupPerformanceTimesDataView {
    public:
        StartupPerformanceTimesDataView() { }

        StartupPerformanceTimesDataView(
            internal::StartupPerformanceTimes_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t service_manager_process_creation_time() const
        {
            return data_->service_manager_process_creation_time;
        }
        int64_t service_manager_main_entry_point_time() const
        {
            return data_->service_manager_main_entry_point_time;
        }
        int64_t browser_message_loop_start_ticks() const
        {
            return data_->browser_message_loop_start_ticks;
        }
        int64_t browser_window_display_ticks() const
        {
            return data_->browser_window_display_ticks;
        }
        int64_t browser_open_tabs_time_delta() const
        {
            return data_->browser_open_tabs_time_delta;
        }
        int64_t first_web_contents_main_frame_load_ticks() const
        {
            return data_->first_web_contents_main_frame_load_ticks;
        }
        int64_t first_visually_non_empty_layout_ticks() const
        {
            return data_->first_visually_non_empty_layout_ticks;
        }

    private:
        internal::StartupPerformanceTimes_Data* data_ = nullptr;
    };

    class Provider_StartTracing_ParamsDataView {
    public:
        Provider_StartTracing_ParamsDataView() { }

        Provider_StartTracing_ParamsDataView(
            internal::Provider_StartTracing_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCategoriesDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCategories(UserType* output)
        {
            auto* pointer = data_->categories.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeRecorder()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::tracing::mojom::RecorderPtrDataView>(
                &data_->recorder, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Provider_StartTracing_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Provider_StopTracing_ParamsDataView {
    public:
        Provider_StopTracing_ParamsDataView() { }

        Provider_StopTracing_ParamsDataView(
            internal::Provider_StopTracing_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Provider_StopTracing_Params_Data* data_ = nullptr;
    };

    class Recorder_Record_ParamsDataView {
    public:
        Recorder_Record_ParamsDataView() { }

        Recorder_Record_ParamsDataView(
            internal::Recorder_Record_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetJsonDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadJson(UserType* output)
        {
            auto* pointer = data_->json.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Recorder_Record_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Collector_Start_ParamsDataView {
    public:
        Collector_Start_ParamsDataView() { }

        Collector_Start_ParamsDataView(
            internal::Collector_Start_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedDataPipeProducerHandle TakeStream()
        {
            mojo::ScopedDataPipeProducerHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedDataPipeProducerHandle>(
                &data_->stream, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetCategoriesDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCategories(UserType* output)
        {
            auto* pointer = data_->categories.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Collector_Start_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Collector_StopAndFlush_ParamsDataView {
    public:
        Collector_StopAndFlush_ParamsDataView() { }

        Collector_StopAndFlush_ParamsDataView(
            internal::Collector_StopAndFlush_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Collector_StopAndFlush_Params_Data* data_ = nullptr;
    };

    class StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_ParamsDataView {
    public:
        StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_ParamsDataView() { }

        StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_ParamsDataView(
            internal::StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t time() const
        {
            return data_->time;
        }

    private:
        internal::StartupPerformanceDataCollector_SetServiceManagerProcessCreationTime_Params_Data* data_ = nullptr;
    };

    class StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_ParamsDataView {
    public:
        StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_ParamsDataView() { }

        StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_ParamsDataView(
            internal::StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t time() const
        {
            return data_->time;
        }

    private:
        internal::StartupPerformanceDataCollector_SetServiceManagerMainEntryPointTime_Params_Data* data_ = nullptr;
    };

    class StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_ParamsDataView {
    public:
        StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_ParamsDataView() { }

        StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_ParamsDataView(
            internal::StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t ticks() const
        {
            return data_->ticks;
        }

    private:
        internal::StartupPerformanceDataCollector_SetBrowserMessageLoopStartTicks_Params_Data* data_ = nullptr;
    };

    class StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_ParamsDataView {
    public:
        StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_ParamsDataView() { }

        StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_ParamsDataView(
            internal::StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t ticks() const
        {
            return data_->ticks;
        }

    private:
        internal::StartupPerformanceDataCollector_SetBrowserWindowDisplayTicks_Params_Data* data_ = nullptr;
    };

    class StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_ParamsDataView {
    public:
        StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_ParamsDataView() { }

        StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_ParamsDataView(
            internal::StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t delta() const
        {
            return data_->delta;
        }

    private:
        internal::StartupPerformanceDataCollector_SetBrowserOpenTabsTimeDelta_Params_Data* data_ = nullptr;
    };

    class StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_ParamsDataView {
    public:
        StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_ParamsDataView() { }

        StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_ParamsDataView(
            internal::StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t ticks() const
        {
            return data_->ticks;
        }

    private:
        internal::StartupPerformanceDataCollector_SetFirstWebContentsMainFrameLoadTicks_Params_Data* data_ = nullptr;
    };

    class StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_ParamsDataView {
    public:
        StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_ParamsDataView() { }

        StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_ParamsDataView(
            internal::StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t ticks() const
        {
            return data_->ticks;
        }

    private:
        internal::StartupPerformanceDataCollector_SetFirstVisuallyNonEmptyLayoutTicks_Params_Data* data_ = nullptr;
    };

    class StartupPerformanceDataCollector_GetStartupPerformanceTimes_ParamsDataView {
    public:
        StartupPerformanceDataCollector_GetStartupPerformanceTimes_ParamsDataView() { }

        StartupPerformanceDataCollector_GetStartupPerformanceTimes_ParamsDataView(
            internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_Params_Data* data_ = nullptr;
    };

    class StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParamsDataView {
    public:
        StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParamsDataView() { }

        StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParamsDataView(
            internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTimesDataView(
            StartupPerformanceTimesDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTimes(UserType* output)
        {
            auto* pointer = data_->times.Get();
            return mojo::internal::Deserialize<::tracing::mojom::StartupPerformanceTimesDataView>(
                pointer, output, context_);
        }

    private:
        internal::StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Factory_CreateRecorder_ParamsDataView {
    public:
        Factory_CreateRecorder_ParamsDataView() { }

        Factory_CreateRecorder_ParamsDataView(
            internal::Factory_CreateRecorder_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeProvider()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::tracing::mojom::ProviderPtrDataView>(
                &data_->provider, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Factory_CreateRecorder_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace tracing

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::tracing::mojom::StartupPerformanceTimesDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::tracing::mojom::StartupPerformanceTimesDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::tracing::mojom::internal::StartupPerformanceTimes_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::tracing::mojom::internal::StartupPerformanceTimes_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::tracing::mojom::internal::StartupPerformanceTimes_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->service_manager_process_creation_time = CallWithContext(Traits::service_manager_process_creation_time, input, custom_context);
            result->service_manager_main_entry_point_time = CallWithContext(Traits::service_manager_main_entry_point_time, input, custom_context);
            result->browser_message_loop_start_ticks = CallWithContext(Traits::browser_message_loop_start_ticks, input, custom_context);
            result->browser_window_display_ticks = CallWithContext(Traits::browser_window_display_ticks, input, custom_context);
            result->browser_open_tabs_time_delta = CallWithContext(Traits::browser_open_tabs_time_delta, input, custom_context);
            result->first_web_contents_main_frame_load_ticks = CallWithContext(Traits::first_web_contents_main_frame_load_ticks, input, custom_context);
            result->first_visually_non_empty_layout_ticks = CallWithContext(Traits::first_visually_non_empty_layout_ticks, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::tracing::mojom::internal::StartupPerformanceTimes_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::tracing::mojom::StartupPerformanceTimesDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace tracing {
namespace mojom {

    inline void Provider_StartTracing_ParamsDataView::GetCategoriesDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->categories.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Recorder_Record_ParamsDataView::GetJsonDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->json.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Collector_Start_ParamsDataView::GetCategoriesDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->categories.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void StartupPerformanceDataCollector_GetStartupPerformanceTimes_ResponseParamsDataView::GetTimesDataView(
        StartupPerformanceTimesDataView* output)
    {
        auto pointer = data_->times.Get();
        *output = StartupPerformanceTimesDataView(pointer, context_);
    }

} // namespace mojom
} // namespace tracing

#endif // SERVICES_TRACING_PUBLIC_INTERFACES_TRACING_MOJOM_SHARED_H_
