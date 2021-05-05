// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_RANGE_MOJO_RANGE_MOJOM_H_
#define UI_GFX_RANGE_MOJO_RANGE_MOJOM_H_

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
#include "ui/gfx/range/mojo/range.mojom-shared.h"
#include "ui/gfx/range/range.h"
#include "ui/gfx/range/range_f.h"
#include <string>
#include <vector>

namespace gfx {
namespace mojom {
    class Range;
    using RangePtr = mojo::InlinedStructPtr<Range>;

    class RangeF;
    using RangeFPtr = mojo::InlinedStructPtr<RangeF>;

    class Range {
    public:
        using DataView = RangeDataView;
        using Data_ = internal::Range_Data;

        static RangePtr New();

        template <typename U>
        static RangePtr From(const U& u)
        {
            return mojo::TypeConverter<RangePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Range>::Convert(*this);
        }

        Range();
        ~Range();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = RangePtr>
        RangePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Range>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Range::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Range::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t start;
        uint32_t end;
    };

    class RangeF {
    public:
        using DataView = RangeFDataView;
        using Data_ = internal::RangeF_Data;

        static RangeFPtr New();

        template <typename U>
        static RangeFPtr From(const U& u)
        {
            return mojo::TypeConverter<RangeFPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RangeF>::Convert(*this);
        }

        RangeF();
        ~RangeF();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = RangeFPtr>
        RangeFPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RangeF>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                RangeF::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                RangeF::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float start;
        float end;
    };

    template <typename StructPtrType>
    RangePtr Range::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->start = mojo::internal::Clone(start);
        rv->end = mojo::internal::Clone(end);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Range>::value>::type*>
    bool Range::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->start, other.start))
            return false;
        if (!mojo::internal::Equals(this->end, other.end))
            return false;
        return true;
    }
    template <typename StructPtrType>
    RangeFPtr RangeF::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->start = mojo::internal::Clone(start);
        rv->end = mojo::internal::Clone(end);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RangeF>::value>::type*>
    bool RangeF::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->start, other.start))
            return false;
        if (!mojo::internal::Equals(this->end, other.end))
            return false;
        return true;
    }

} // namespace mojom
} // namespace gfx

namespace mojo {

template <>
struct StructTraits<::gfx::mojom::Range::DataView,
    ::gfx::mojom::RangePtr> {
    static bool IsNull(const ::gfx::mojom::RangePtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::RangePtr* output) { output->reset(); }

    static decltype(::gfx::mojom::Range::start) start(
        const ::gfx::mojom::RangePtr& input)
    {
        return input->start;
    }

    static decltype(::gfx::mojom::Range::end) end(
        const ::gfx::mojom::RangePtr& input)
    {
        return input->end;
    }

    static bool Read(::gfx::mojom::Range::DataView input, ::gfx::mojom::RangePtr* output);
};

template <>
struct StructTraits<::gfx::mojom::RangeF::DataView,
    ::gfx::mojom::RangeFPtr> {
    static bool IsNull(const ::gfx::mojom::RangeFPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::RangeFPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::RangeF::start) start(
        const ::gfx::mojom::RangeFPtr& input)
    {
        return input->start;
    }

    static decltype(::gfx::mojom::RangeF::end) end(
        const ::gfx::mojom::RangeFPtr& input)
    {
        return input->end;
    }

    static bool Read(::gfx::mojom::RangeF::DataView input, ::gfx::mojom::RangeFPtr* output);
};

} // namespace mojo

#endif // UI_GFX_RANGE_MOJO_RANGE_MOJOM_H_