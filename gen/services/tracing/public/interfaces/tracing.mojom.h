// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_TRACING_PUBLIC_INTERFACES_TRACING_MOJOM_H_
#define SERVICES_TRACING_PUBLIC_INTERFACES_TRACING_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "services/tracing/public/interfaces/tracing.mojom-shared.h"
#include <string>
#include <vector>

namespace tracing {
namespace mojom {
    class Provider;
    using ProviderPtr = mojo::InterfacePtr<Provider>;
    using ProviderPtrInfo = mojo::InterfacePtrInfo<Provider>;
    using ThreadSafeProviderPtr = mojo::ThreadSafeInterfacePtr<Provider>;
    using ProviderRequest = mojo::InterfaceRequest<Provider>;
    using ProviderAssociatedPtr = mojo::AssociatedInterfacePtr<Provider>;
    using ThreadSafeProviderAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Provider>;
    using ProviderAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Provider>;
    using ProviderAssociatedRequest = mojo::AssociatedInterfaceRequest<Provider>;

    class Recorder;
    using RecorderPtr = mojo::InterfacePtr<Recorder>;
    using RecorderPtrInfo = mojo::InterfacePtrInfo<Recorder>;
    using ThreadSafeRecorderPtr = mojo::ThreadSafeInterfacePtr<Recorder>;
    using RecorderRequest = mojo::InterfaceRequest<Recorder>;
    using RecorderAssociatedPtr = mojo::AssociatedInterfacePtr<Recorder>;
    using ThreadSafeRecorderAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Recorder>;
    using RecorderAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Recorder>;
    using RecorderAssociatedRequest = mojo::AssociatedInterfaceRequest<Recorder>;

    class Collector;
    using CollectorPtr = mojo::InterfacePtr<Collector>;
    using CollectorPtrInfo = mojo::InterfacePtrInfo<Collector>;
    using ThreadSafeCollectorPtr = mojo::ThreadSafeInterfacePtr<Collector>;
    using CollectorRequest = mojo::InterfaceRequest<Collector>;
    using CollectorAssociatedPtr = mojo::AssociatedInterfacePtr<Collector>;
    using ThreadSafeCollectorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Collector>;
    using CollectorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Collector>;
    using CollectorAssociatedRequest = mojo::AssociatedInterfaceRequest<Collector>;

    class StartupPerformanceDataCollector;
    using StartupPerformanceDataCollectorPtr = mojo::InterfacePtr<StartupPerformanceDataCollector>;
    using StartupPerformanceDataCollectorPtrInfo = mojo::InterfacePtrInfo<StartupPerformanceDataCollector>;
    using ThreadSafeStartupPerformanceDataCollectorPtr = mojo::ThreadSafeInterfacePtr<StartupPerformanceDataCollector>;
    using StartupPerformanceDataCollectorRequest = mojo::InterfaceRequest<StartupPerformanceDataCollector>;
    using StartupPerformanceDataCollectorAssociatedPtr = mojo::AssociatedInterfacePtr<StartupPerformanceDataCollector>;
    using ThreadSafeStartupPerformanceDataCollectorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<StartupPerformanceDataCollector>;
    using StartupPerformanceDataCollectorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<StartupPerformanceDataCollector>;
    using StartupPerformanceDataCollectorAssociatedRequest = mojo::AssociatedInterfaceRequest<StartupPerformanceDataCollector>;

    class Factory;
    using FactoryPtr = mojo::InterfacePtr<Factory>;
    using FactoryPtrInfo = mojo::InterfacePtrInfo<Factory>;
    using ThreadSafeFactoryPtr = mojo::ThreadSafeInterfacePtr<Factory>;
    using FactoryRequest = mojo::InterfaceRequest<Factory>;
    using FactoryAssociatedPtr = mojo::AssociatedInterfacePtr<Factory>;
    using ThreadSafeFactoryAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Factory>;
    using FactoryAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Factory>;
    using FactoryAssociatedRequest = mojo::AssociatedInterfaceRequest<Factory>;

    class StartupPerformanceTimes;
    using StartupPerformanceTimesPtr = mojo::StructPtr<StartupPerformanceTimes>;

    class ProviderProxy;

    template <typename ImplRefTraits>
    class ProviderStub;

    class ProviderRequestValidator;

    class Provider
        : public ProviderInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ProviderProxy;

        template <typename ImplRefTraits>
        using Stub_ = ProviderStub<ImplRefTraits>;

        using RequestValidator_ = ProviderRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kStartTracingMinVersion = 0,
            kStopTracingMinVersion = 0,
        };
        virtual ~Provider() { }

        virtual void StartTracing(const std::string& categories, RecorderPtr recorder) = 0;

        virtual void StopTracing() = 0;
    };

    class RecorderProxy;

    template <typename ImplRefTraits>
    class RecorderStub;

    class RecorderRequestValidator;

    class Recorder
        : public RecorderInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = RecorderProxy;

        template <typename ImplRefTraits>
        using Stub_ = RecorderStub<ImplRefTraits>;

        using RequestValidator_ = RecorderRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kRecordMinVersion = 0,
        };
        virtual ~Recorder() { }

        virtual void Record(const std::string& json) = 0;
    };

    class CollectorProxy;

    template <typename ImplRefTraits>
    class CollectorStub;

    class CollectorRequestValidator;

    class Collector
        : public CollectorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = CollectorProxy;

        template <typename ImplRefTraits>
        using Stub_ = CollectorStub<ImplRefTraits>;

        using RequestValidator_ = CollectorRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kStartMinVersion = 0,
            kStopAndFlushMinVersion = 0,
        };
        virtual ~Collector() { }

        virtual void Start(mojo::ScopedDataPipeProducerHandle stream, const std::string& categories) = 0;

        virtual void StopAndFlush() = 0;
    };

    class StartupPerformanceDataCollectorProxy;

    template <typename ImplRefTraits>
    class StartupPerformanceDataCollectorStub;

    class StartupPerformanceDataCollectorRequestValidator;
    class StartupPerformanceDataCollectorResponseValidator;

    class StartupPerformanceDataCollector
        : public StartupPerformanceDataCollectorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = StartupPerformanceDataCollectorProxy;

        template <typename ImplRefTraits>
        using Stub_ = StartupPerformanceDataCollectorStub<ImplRefTraits>;

        using RequestValidator_ = StartupPerformanceDataCollectorRequestValidator;
        using ResponseValidator_ = StartupPerformanceDataCollectorResponseValidator;
        enum MethodMinVersions : uint32_t {
            kSetServiceManagerProcessCreationTimeMinVersion = 0,
            kSetServiceManagerMainEntryPointTimeMinVersion = 0,
            kSetBrowserMessageLoopStartTicksMinVersion = 0,
            kSetBrowserWindowDisplayTicksMinVersion = 0,
            kSetBrowserOpenTabsTimeDeltaMinVersion = 0,
            kSetFirstWebContentsMainFrameLoadTicksMinVersion = 0,
            kSetFirstVisuallyNonEmptyLayoutTicksMinVersion = 0,
            kGetStartupPerformanceTimesMinVersion = 0,
        };
        virtual ~StartupPerformanceDataCollector() { }

        virtual void SetServiceManagerProcessCreationTime(int64_t time) = 0;

        virtual void SetServiceManagerMainEntryPointTime(int64_t time) = 0;

        virtual void SetBrowserMessageLoopStartTicks(int64_t ticks) = 0;

        virtual void SetBrowserWindowDisplayTicks(int64_t ticks) = 0;

        virtual void SetBrowserOpenTabsTimeDelta(int64_t delta) = 0;

        virtual void SetFirstWebContentsMainFrameLoadTicks(int64_t ticks) = 0;

        virtual void SetFirstVisuallyNonEmptyLayoutTicks(int64_t ticks) = 0;

        using GetStartupPerformanceTimesCallback = base::Callback<void(StartupPerformanceTimesPtr)>;
        virtual void GetStartupPerformanceTimes(const GetStartupPerformanceTimesCallback& callback) = 0;
    };

    class FactoryProxy;

    template <typename ImplRefTraits>
    class FactoryStub;

    class FactoryRequestValidator;

    class Factory
        : public FactoryInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = FactoryProxy;

        template <typename ImplRefTraits>
        using Stub_ = FactoryStub<ImplRefTraits>;

        using RequestValidator_ = FactoryRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kCreateRecorderMinVersion = 0,
        };
        virtual ~Factory() { }

        virtual void CreateRecorder(ProviderPtr provider) = 0;
    };

    class ProviderProxy
        : public Provider {
    public:
        explicit ProviderProxy(mojo::MessageReceiverWithResponder* receiver);
        void StartTracing(const std::string& categories, RecorderPtr recorder) override;
        void StopTracing() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class RecorderProxy
        : public Recorder {
    public:
        explicit RecorderProxy(mojo::MessageReceiverWithResponder* receiver);
        void Record(const std::string& json) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CollectorProxy
        : public Collector {
    public:
        explicit CollectorProxy(mojo::MessageReceiverWithResponder* receiver);
        void Start(mojo::ScopedDataPipeProducerHandle stream, const std::string& categories) override;
        void StopAndFlush() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class StartupPerformanceDataCollectorProxy
        : public StartupPerformanceDataCollector {
    public:
        explicit StartupPerformanceDataCollectorProxy(mojo::MessageReceiverWithResponder* receiver);
        void SetServiceManagerProcessCreationTime(int64_t time) override;
        void SetServiceManagerMainEntryPointTime(int64_t time) override;
        void SetBrowserMessageLoopStartTicks(int64_t ticks) override;
        void SetBrowserWindowDisplayTicks(int64_t ticks) override;
        void SetBrowserOpenTabsTimeDelta(int64_t delta) override;
        void SetFirstWebContentsMainFrameLoadTicks(int64_t ticks) override;
        void SetFirstVisuallyNonEmptyLayoutTicks(int64_t ticks) override;
        void GetStartupPerformanceTimes(const GetStartupPerformanceTimesCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class FactoryProxy
        : public Factory {
    public:
        explicit FactoryProxy(mojo::MessageReceiverWithResponder* receiver);
        void CreateRecorder(ProviderPtr provider) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class ProviderStubDispatch {
    public:
        static bool Accept(Provider* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Provider* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Provider>>
    class ProviderStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ProviderStub() { }
        ~ProviderStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ProviderStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ProviderStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class RecorderStubDispatch {
    public:
        static bool Accept(Recorder* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Recorder* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Recorder>>
    class RecorderStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        RecorderStub() { }
        ~RecorderStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return RecorderStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return RecorderStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CollectorStubDispatch {
    public:
        static bool Accept(Collector* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Collector* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Collector>>
    class CollectorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        CollectorStub() { }
        ~CollectorStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return CollectorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return CollectorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class StartupPerformanceDataCollectorStubDispatch {
    public:
        static bool Accept(StartupPerformanceDataCollector* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(StartupPerformanceDataCollector* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<StartupPerformanceDataCollector>>
    class StartupPerformanceDataCollectorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        StartupPerformanceDataCollectorStub() { }
        ~StartupPerformanceDataCollectorStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return StartupPerformanceDataCollectorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return StartupPerformanceDataCollectorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class FactoryStubDispatch {
    public:
        static bool Accept(Factory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Factory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Factory>>
    class FactoryStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        FactoryStub() { }
        ~FactoryStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return FactoryStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return FactoryStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ProviderRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class RecorderRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CollectorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class StartupPerformanceDataCollectorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class FactoryRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class StartupPerformanceDataCollectorResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class StartupPerformanceTimes {
    public:
        using DataView = StartupPerformanceTimesDataView;
        using Data_ = internal::StartupPerformanceTimes_Data;

        static StartupPerformanceTimesPtr New();

        template <typename U>
        static StartupPerformanceTimesPtr From(const U& u)
        {
            return mojo::TypeConverter<StartupPerformanceTimesPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, StartupPerformanceTimes>::Convert(*this);
        }

        StartupPerformanceTimes();
        ~StartupPerformanceTimes();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = StartupPerformanceTimesPtr>
        StartupPerformanceTimesPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, StartupPerformanceTimes>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                StartupPerformanceTimes::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                StartupPerformanceTimes::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int64_t service_manager_process_creation_time;
        int64_t service_manager_main_entry_point_time;
        int64_t browser_message_loop_start_ticks;
        int64_t browser_window_display_ticks;
        int64_t browser_open_tabs_time_delta;
        int64_t first_web_contents_main_frame_load_ticks;
        int64_t first_visually_non_empty_layout_ticks;
    };

    template <typename StructPtrType>
    StartupPerformanceTimesPtr StartupPerformanceTimes::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->service_manager_process_creation_time = mojo::internal::Clone(service_manager_process_creation_time);
        rv->service_manager_main_entry_point_time = mojo::internal::Clone(service_manager_main_entry_point_time);
        rv->browser_message_loop_start_ticks = mojo::internal::Clone(browser_message_loop_start_ticks);
        rv->browser_window_display_ticks = mojo::internal::Clone(browser_window_display_ticks);
        rv->browser_open_tabs_time_delta = mojo::internal::Clone(browser_open_tabs_time_delta);
        rv->first_web_contents_main_frame_load_ticks = mojo::internal::Clone(first_web_contents_main_frame_load_ticks);
        rv->first_visually_non_empty_layout_ticks = mojo::internal::Clone(first_visually_non_empty_layout_ticks);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, StartupPerformanceTimes>::value>::type*>
    bool StartupPerformanceTimes::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->service_manager_process_creation_time, other.service_manager_process_creation_time))
            return false;
        if (!mojo::internal::Equals(this->service_manager_main_entry_point_time, other.service_manager_main_entry_point_time))
            return false;
        if (!mojo::internal::Equals(this->browser_message_loop_start_ticks, other.browser_message_loop_start_ticks))
            return false;
        if (!mojo::internal::Equals(this->browser_window_display_ticks, other.browser_window_display_ticks))
            return false;
        if (!mojo::internal::Equals(this->browser_open_tabs_time_delta, other.browser_open_tabs_time_delta))
            return false;
        if (!mojo::internal::Equals(this->first_web_contents_main_frame_load_ticks, other.first_web_contents_main_frame_load_ticks))
            return false;
        if (!mojo::internal::Equals(this->first_visually_non_empty_layout_ticks, other.first_visually_non_empty_layout_ticks))
            return false;
        return true;
    }

} // namespace mojom
} // namespace tracing

namespace mojo {

template <>
struct StructTraits<::tracing::mojom::StartupPerformanceTimes::DataView,
    ::tracing::mojom::StartupPerformanceTimesPtr> {
    static bool IsNull(const ::tracing::mojom::StartupPerformanceTimesPtr& input) { return !input; }
    static void SetToNull(::tracing::mojom::StartupPerformanceTimesPtr* output) { output->reset(); }

    static decltype(::tracing::mojom::StartupPerformanceTimes::service_manager_process_creation_time) service_manager_process_creation_time(
        const ::tracing::mojom::StartupPerformanceTimesPtr& input)
    {
        return input->service_manager_process_creation_time;
    }

    static decltype(::tracing::mojom::StartupPerformanceTimes::service_manager_main_entry_point_time) service_manager_main_entry_point_time(
        const ::tracing::mojom::StartupPerformanceTimesPtr& input)
    {
        return input->service_manager_main_entry_point_time;
    }

    static decltype(::tracing::mojom::StartupPerformanceTimes::browser_message_loop_start_ticks) browser_message_loop_start_ticks(
        const ::tracing::mojom::StartupPerformanceTimesPtr& input)
    {
        return input->browser_message_loop_start_ticks;
    }

    static decltype(::tracing::mojom::StartupPerformanceTimes::browser_window_display_ticks) browser_window_display_ticks(
        const ::tracing::mojom::StartupPerformanceTimesPtr& input)
    {
        return input->browser_window_display_ticks;
    }

    static decltype(::tracing::mojom::StartupPerformanceTimes::browser_open_tabs_time_delta) browser_open_tabs_time_delta(
        const ::tracing::mojom::StartupPerformanceTimesPtr& input)
    {
        return input->browser_open_tabs_time_delta;
    }

    static decltype(::tracing::mojom::StartupPerformanceTimes::first_web_contents_main_frame_load_ticks) first_web_contents_main_frame_load_ticks(
        const ::tracing::mojom::StartupPerformanceTimesPtr& input)
    {
        return input->first_web_contents_main_frame_load_ticks;
    }

    static decltype(::tracing::mojom::StartupPerformanceTimes::first_visually_non_empty_layout_ticks) first_visually_non_empty_layout_ticks(
        const ::tracing::mojom::StartupPerformanceTimesPtr& input)
    {
        return input->first_visually_non_empty_layout_ticks;
    }

    static bool Read(::tracing::mojom::StartupPerformanceTimes::DataView input, ::tracing::mojom::StartupPerformanceTimesPtr* output);
};

} // namespace mojo

#endif // SERVICES_TRACING_PUBLIC_INTERFACES_TRACING_MOJOM_H_