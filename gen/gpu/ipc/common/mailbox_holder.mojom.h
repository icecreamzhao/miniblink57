// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_MAILBOX_HOLDER_MOJOM_H_
#define GPU_IPC_COMMON_MAILBOX_HOLDER_MOJOM_H_

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
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/mailbox.mojom.h"
#include "gpu/ipc/common/mailbox_holder.mojom-shared.h"
#include "gpu/ipc/common/surface_handle.h"
#include "gpu/ipc/common/sync_token.mojom.h"
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
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include <string>
#include <vector>

namespace gpu {
namespace mojom {
    class MailboxHolder;
    using MailboxHolderPtr = mojo::StructPtr<MailboxHolder>;

    class MailboxHolder {
    public:
        using DataView = MailboxHolderDataView;
        using Data_ = internal::MailboxHolder_Data;

        static MailboxHolderPtr New();

        template <typename U>
        static MailboxHolderPtr From(const U& u)
        {
            return mojo::TypeConverter<MailboxHolderPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, MailboxHolder>::Convert(*this);
        }

        MailboxHolder();
        ~MailboxHolder();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = MailboxHolderPtr>
        MailboxHolderPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, MailboxHolder>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                MailboxHolder::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                MailboxHolder::DataView, std::vector<uint8_t>>(
                input, output);
        }

        gpu::Mailbox mailbox;
        ::gpu::SyncToken sync_token;
        uint32_t texture_target;
    };

    template <typename StructPtrType>
    MailboxHolderPtr MailboxHolder::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->mailbox = mojo::internal::Clone(mailbox);
        rv->sync_token = mojo::internal::Clone(sync_token);
        rv->texture_target = mojo::internal::Clone(texture_target);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, MailboxHolder>::value>::type*>
    bool MailboxHolder::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->mailbox, other.mailbox))
            return false;
        if (!mojo::internal::Equals(this->sync_token, other.sync_token))
            return false;
        if (!mojo::internal::Equals(this->texture_target, other.texture_target))
            return false;
        return true;
    }

} // namespace mojom
} // namespace gpu

namespace mojo {

template <>
struct StructTraits<::gpu::mojom::MailboxHolder::DataView,
    ::gpu::mojom::MailboxHolderPtr> {
    static bool IsNull(const ::gpu::mojom::MailboxHolderPtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::MailboxHolderPtr* output) { output->reset(); }

    static const decltype(::gpu::mojom::MailboxHolder::mailbox)& mailbox(
        const ::gpu::mojom::MailboxHolderPtr& input)
    {
        return input->mailbox;
    }

    static const decltype(::gpu::mojom::MailboxHolder::sync_token)& sync_token(
        const ::gpu::mojom::MailboxHolderPtr& input)
    {
        return input->sync_token;
    }

    static decltype(::gpu::mojom::MailboxHolder::texture_target) texture_target(
        const ::gpu::mojom::MailboxHolderPtr& input)
    {
        return input->texture_target;
    }

    static bool Read(::gpu::mojom::MailboxHolder::DataView input, ::gpu::mojom::MailboxHolderPtr* output);
};

} // namespace mojo

#endif // GPU_IPC_COMMON_MAILBOX_HOLDER_MOJOM_H_