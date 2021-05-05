// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_VERSION_MOJOM_H_
#define MOJO_COMMON_VERSION_MOJOM_H_

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
#include "mojo/common/version.mojom-shared.h"
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
        class Version;
        using VersionPtr = mojo::StructPtr<Version>;

        class Version {
        public:
            using DataView = VersionDataView;
            using Data_ = internal::Version_Data;

            static VersionPtr New();

            template <typename U>
            static VersionPtr From(const U& u)
            {
                return mojo::TypeConverter<VersionPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, Version>::Convert(*this);
            }

            Version();
            ~Version();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = VersionPtr>
            VersionPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, Version>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static std::vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Version::DataView, std::vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const std::vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Version::DataView, std::vector<uint8_t>>(
                    input, output);
            }

            std::vector<uint32_t> components;
        };

        template <typename StructPtrType>
        VersionPtr Version::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->components = mojo::internal::Clone(components);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, Version>::value>::type*>
        bool Version::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->components, other.components))
                return false;
            return true;
        }

    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {

template <>
struct StructTraits<::mojo::common::mojom::Version::DataView,
    ::mojo::common::mojom::VersionPtr> {
    static bool IsNull(const ::mojo::common::mojom::VersionPtr& input) { return !input; }
    static void SetToNull(::mojo::common::mojom::VersionPtr* output) { output->reset(); }

    static const decltype(::mojo::common::mojom::Version::components)& components(
        const ::mojo::common::mojom::VersionPtr& input)
    {
        return input->components;
    }

    static bool Read(::mojo::common::mojom::Version::DataView input, ::mojo::common::mojom::VersionPtr* output);
};

} // namespace mojo

#endif // MOJO_COMMON_VERSION_MOJOM_H_