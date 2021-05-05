// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_BEGIN_FRAME_ARGS_MOJOM_BLINK_H_
#define CC_IPC_BEGIN_FRAME_ARGS_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/begin_frame_args.mojom-shared.h"
#include "mojo/common/time.mojom-blink.h"
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

#include "base/files/file.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/resources/returned_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_sequence.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace cc {
namespace mojom {
    namespace blink {
        using BeginFrameArgsType = BeginFrameArgsType; // Alias for definition in the parent namespace.
        class BeginFrameArgs;
        using BeginFrameArgsPtr = mojo::StructPtr<BeginFrameArgs>;

        class BeginFrameArgs {
        public:
            using DataView = BeginFrameArgsDataView;
            using Data_ = internal::BeginFrameArgs_Data;

            static BeginFrameArgsPtr New();

            template <typename U>
            static BeginFrameArgsPtr From(const U& u)
            {
                return mojo::TypeConverter<BeginFrameArgsPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, BeginFrameArgs>::Convert(*this);
            }

            BeginFrameArgs();
            ~BeginFrameArgs();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = BeginFrameArgsPtr>
            BeginFrameArgsPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, BeginFrameArgs>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    BeginFrameArgs::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    BeginFrameArgs::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::mojo::common::mojom::blink::TimeTicksPtr frame_time;
            ::mojo::common::mojom::blink::TimeTicksPtr deadline;
            ::mojo::common::mojom::blink::TimeDeltaPtr interval;
            uint64_t sequence_number;
            uint32_t source_id;
            BeginFrameArgsType type;
            bool on_critical_path;

        private:
            DISALLOW_COPY_AND_ASSIGN(BeginFrameArgs);
        };

        template <typename StructPtrType>
        BeginFrameArgsPtr BeginFrameArgs::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->frame_time = mojo::internal::Clone(frame_time);
            rv->deadline = mojo::internal::Clone(deadline);
            rv->interval = mojo::internal::Clone(interval);
            rv->sequence_number = mojo::internal::Clone(sequence_number);
            rv->source_id = mojo::internal::Clone(source_id);
            rv->type = mojo::internal::Clone(type);
            rv->on_critical_path = mojo::internal::Clone(on_critical_path);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, BeginFrameArgs>::value>::type*>
        bool BeginFrameArgs::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->frame_time, other.frame_time))
                return false;
            if (!mojo::internal::Equals(this->deadline, other.deadline))
                return false;
            if (!mojo::internal::Equals(this->interval, other.interval))
                return false;
            if (!mojo::internal::Equals(this->sequence_number, other.sequence_number))
                return false;
            if (!mojo::internal::Equals(this->source_id, other.source_id))
                return false;
            if (!mojo::internal::Equals(this->type, other.type))
                return false;
            if (!mojo::internal::Equals(this->on_critical_path, other.on_critical_path))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::blink::BeginFrameArgs::DataView,
    ::cc::mojom::blink::BeginFrameArgsPtr> {
    static bool IsNull(const ::cc::mojom::blink::BeginFrameArgsPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::BeginFrameArgsPtr* output) { output->reset(); }

    static const decltype(::cc::mojom::blink::BeginFrameArgs::frame_time)& frame_time(
        const ::cc::mojom::blink::BeginFrameArgsPtr& input)
    {
        return input->frame_time;
    }

    static const decltype(::cc::mojom::blink::BeginFrameArgs::deadline)& deadline(
        const ::cc::mojom::blink::BeginFrameArgsPtr& input)
    {
        return input->deadline;
    }

    static const decltype(::cc::mojom::blink::BeginFrameArgs::interval)& interval(
        const ::cc::mojom::blink::BeginFrameArgsPtr& input)
    {
        return input->interval;
    }

    static decltype(::cc::mojom::blink::BeginFrameArgs::sequence_number) sequence_number(
        const ::cc::mojom::blink::BeginFrameArgsPtr& input)
    {
        return input->sequence_number;
    }

    static decltype(::cc::mojom::blink::BeginFrameArgs::source_id) source_id(
        const ::cc::mojom::blink::BeginFrameArgsPtr& input)
    {
        return input->source_id;
    }

    static decltype(::cc::mojom::blink::BeginFrameArgs::type) type(
        const ::cc::mojom::blink::BeginFrameArgsPtr& input)
    {
        return input->type;
    }

    static decltype(::cc::mojom::blink::BeginFrameArgs::on_critical_path) on_critical_path(
        const ::cc::mojom::blink::BeginFrameArgsPtr& input)
    {
        return input->on_critical_path;
    }

    static bool Read(::cc::mojom::blink::BeginFrameArgs::DataView input, ::cc::mojom::blink::BeginFrameArgsPtr* output);
};

} // namespace mojo

#endif // CC_IPC_BEGIN_FRAME_ARGS_MOJOM_BLINK_H_