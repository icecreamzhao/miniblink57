// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_TIME_MOJOM_H_
#define MOJO_COMMON_TIME_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "mojo/common/time.mojom-shared.h"
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
#include <string>
#include <vector>

namespace mojo {
namespace common {
    namespace mojom {
        using Time = mojo::NativeStruct;
        using TimePtr = mojo::NativeStructPtr;

        class TimeDelta;
        using TimeDeltaPtr = mojo::InlinedStructPtr<TimeDelta>;

        using TimeTicks = mojo::NativeStruct;
        using TimeTicksPtr = mojo::NativeStructPtr;

        class TimeDelta {
        public:
            using DataView = TimeDeltaDataView;
            using Data_ = internal::TimeDelta_Data;

            static TimeDeltaPtr New();

            template <typename U>
            static TimeDeltaPtr From(const U& u)
            {
                return mojo::TypeConverter<TimeDeltaPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, TimeDelta>::Convert(*this);
            }

            TimeDelta();
            ~TimeDelta();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = TimeDeltaPtr>
            TimeDeltaPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, TimeDelta>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static std::vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    TimeDelta::DataView, std::vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const std::vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    TimeDelta::DataView, std::vector<uint8_t>>(
                    input, output);
            }

            int64_t microseconds;
        };

        template <typename StructPtrType>
        TimeDeltaPtr TimeDelta::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->microseconds = mojo::internal::Clone(microseconds);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, TimeDelta>::value>::type*>
        bool TimeDelta::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->microseconds, other.microseconds))
                return false;
            return true;
        }

    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {

template <>
struct StructTraits<::mojo::common::mojom::TimeDelta::DataView,
    ::mojo::common::mojom::TimeDeltaPtr> {
    static bool IsNull(const ::mojo::common::mojom::TimeDeltaPtr& input) { return !input; }
    static void SetToNull(::mojo::common::mojom::TimeDeltaPtr* output) { output->reset(); }

    static decltype(::mojo::common::mojom::TimeDelta::microseconds) microseconds(
        const ::mojo::common::mojom::TimeDeltaPtr& input)
    {
        return input->microseconds;
    }

    static bool Read(::mojo::common::mojom::TimeDelta::DataView input, ::mojo::common::mojom::TimeDeltaPtr* output);
};

} // namespace mojo

#endif // MOJO_COMMON_TIME_MOJOM_H_