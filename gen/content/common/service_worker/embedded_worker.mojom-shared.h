// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_SERVICE_WORKER_EMBEDDED_WORKER_MOJOM_SHARED_H_
#define CONTENT_COMMON_SERVICE_WORKER_EMBEDDED_WORKER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/service_worker/embedded_worker.mojom-shared-internal.h"
#include "content/common/service_worker/service_worker_event_dispatcher.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/service_manager/public/interfaces/interface_provider.mojom-shared.h"
#include "third_party/WebKit/public/web/console_message.mojom-shared.h"
#include "url/mojo/url.mojom-shared.h"

namespace content {
namespace mojom {
    using EmbeddedWorkerStartParamsDataView = mojo::NativeStructDataView;

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class EmbeddedWorkerInstanceClientInterfaceBase {
    };

    using EmbeddedWorkerInstanceClientPtrDataView = mojo::InterfacePtrDataView<EmbeddedWorkerInstanceClientInterfaceBase>;
    using EmbeddedWorkerInstanceClientRequestDataView = mojo::InterfaceRequestDataView<EmbeddedWorkerInstanceClientInterfaceBase>;
    using EmbeddedWorkerInstanceClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<EmbeddedWorkerInstanceClientInterfaceBase>;
    using EmbeddedWorkerInstanceClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<EmbeddedWorkerInstanceClientInterfaceBase>;
    class EmbeddedWorkerInstanceClient_StartWorker_ParamsDataView {
    public:
        EmbeddedWorkerInstanceClient_StartWorker_ParamsDataView() { }

        EmbeddedWorkerInstanceClient_StartWorker_ParamsDataView(
            internal::EmbeddedWorkerInstanceClient_StartWorker_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetParamsDataView(
            EmbeddedWorkerStartParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParams(UserType* output)
        {
            auto* pointer = data_->params.Get();
            return mojo::internal::Deserialize<::content::mojom::EmbeddedWorkerStartParamsDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeDispatcherRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::ServiceWorkerEventDispatcherRequestDataView>(
                &data_->dispatcher_request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::EmbeddedWorkerInstanceClient_StartWorker_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class EmbeddedWorkerInstanceClient_StopWorker_ParamsDataView {
    public:
        EmbeddedWorkerInstanceClient_StopWorker_ParamsDataView() { }

        EmbeddedWorkerInstanceClient_StopWorker_ParamsDataView(
            internal::EmbeddedWorkerInstanceClient_StopWorker_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::EmbeddedWorkerInstanceClient_StopWorker_Params_Data* data_ = nullptr;
    };

    class EmbeddedWorkerInstanceClient_StopWorker_ResponseParamsDataView {
    public:
        EmbeddedWorkerInstanceClient_StopWorker_ResponseParamsDataView() { }

        EmbeddedWorkerInstanceClient_StopWorker_ResponseParamsDataView(
            internal::EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data* data_ = nullptr;
    };

    class EmbeddedWorkerInstanceClient_ResumeAfterDownload_ParamsDataView {
    public:
        EmbeddedWorkerInstanceClient_ResumeAfterDownload_ParamsDataView() { }

        EmbeddedWorkerInstanceClient_ResumeAfterDownload_ParamsDataView(
            internal::EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data* data_ = nullptr;
    };

    class EmbeddedWorkerInstanceClient_AddMessageToConsole_ParamsDataView {
    public:
        EmbeddedWorkerInstanceClient_AddMessageToConsole_ParamsDataView() { }

        EmbeddedWorkerInstanceClient_AddMessageToConsole_ParamsDataView(
            internal::EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLevel(UserType* output) const
        {
            auto data_value = data_->level;
            return mojo::internal::Deserialize<::blink::mojom::ConsoleMessageLevel>(
                data_value, output);
        }

        ::blink::mojom::ConsoleMessageLevel level() const
        {
            return static_cast<::blink::mojom::ConsoleMessageLevel>(data_->level);
        }
        inline void GetMessageDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMessage(UserType* output)
        {
            auto* pointer = data_->message.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace content

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace content {
namespace mojom {

    inline void EmbeddedWorkerInstanceClient_StartWorker_ParamsDataView::GetParamsDataView(
        EmbeddedWorkerStartParamsDataView* output)
    {
        auto pointer = data_->params.Get();
        *output = EmbeddedWorkerStartParamsDataView(pointer, context_);
    }

    inline void EmbeddedWorkerInstanceClient_AddMessageToConsole_ParamsDataView::GetMessageDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->message.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_SERVICE_WORKER_EMBEDDED_WORKER_MOJOM_SHARED_H_
