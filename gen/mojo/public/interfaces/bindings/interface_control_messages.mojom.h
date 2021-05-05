// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_PUBLIC_INTERFACES_BINDINGS_INTERFACE_CONTROL_MESSAGES_MOJOM_H_
#define MOJO_PUBLIC_INTERFACES_BINDINGS_INTERFACE_CONTROL_MESSAGES_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/bindings_export.h"
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
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom-shared.h"
#include <string>
#include <vector>

namespace mojo {
namespace interface_control {
    constexpr uint32_t kRunMessageId = 0xFFFFFFFFU;
    constexpr uint32_t kRunOrClosePipeMessageId = 0xFFFFFFFEU;
    class RunMessageParams;
    using RunMessageParamsPtr = mojo::StructPtr<RunMessageParams>;

    class RunResponseMessageParams;
    using RunResponseMessageParamsPtr = mojo::StructPtr<RunResponseMessageParams>;

    class QueryVersion;
    using QueryVersionPtr = mojo::InlinedStructPtr<QueryVersion>;

    class QueryVersionResult;
    using QueryVersionResultPtr = mojo::InlinedStructPtr<QueryVersionResult>;

    class FlushForTesting;
    using FlushForTestingPtr = mojo::InlinedStructPtr<FlushForTesting>;

    class RunOrClosePipeMessageParams;
    using RunOrClosePipeMessageParamsPtr = mojo::StructPtr<RunOrClosePipeMessageParams>;

    class RequireVersion;
    using RequireVersionPtr = mojo::InlinedStructPtr<RequireVersion>;

    class SendDisconnectReason;
    using SendDisconnectReasonPtr = mojo::InlinedStructPtr<SendDisconnectReason>;

    class RunInput;

    typedef mojo::StructPtr<RunInput> RunInputPtr;

    class RunOutput;

    typedef mojo::StructPtr<RunOutput> RunOutputPtr;

    class RunOrClosePipeInput;

    typedef mojo::StructPtr<RunOrClosePipeInput> RunOrClosePipeInputPtr;

    class MOJO_CPP_BINDINGS_EXPORT QueryVersion {
    public:
        using DataView = QueryVersionDataView;
        using Data_ = internal::QueryVersion_Data;

        static QueryVersionPtr New();

        template <typename U>
        static QueryVersionPtr From(const U& u)
        {
            return mojo::TypeConverter<QueryVersionPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, QueryVersion>::Convert(*this);
        }

        QueryVersion();
        ~QueryVersion();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = QueryVersionPtr>
        QueryVersionPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, QueryVersion>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                QueryVersion::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                QueryVersion::DataView, std::vector<uint8_t>>(
                input, output);
        }
    };

    class MOJO_CPP_BINDINGS_EXPORT QueryVersionResult {
    public:
        using DataView = QueryVersionResultDataView;
        using Data_ = internal::QueryVersionResult_Data;

        static QueryVersionResultPtr New();

        template <typename U>
        static QueryVersionResultPtr From(const U& u)
        {
            return mojo::TypeConverter<QueryVersionResultPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, QueryVersionResult>::Convert(*this);
        }

        QueryVersionResult();
        ~QueryVersionResult();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = QueryVersionResultPtr>
        QueryVersionResultPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, QueryVersionResult>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                QueryVersionResult::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                QueryVersionResult::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t version;
    };

    class MOJO_CPP_BINDINGS_EXPORT FlushForTesting {
    public:
        using DataView = FlushForTestingDataView;
        using Data_ = internal::FlushForTesting_Data;

        static FlushForTestingPtr New();

        template <typename U>
        static FlushForTestingPtr From(const U& u)
        {
            return mojo::TypeConverter<FlushForTestingPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FlushForTesting>::Convert(*this);
        }

        FlushForTesting();
        ~FlushForTesting();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FlushForTestingPtr>
        FlushForTestingPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FlushForTesting>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FlushForTesting::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FlushForTesting::DataView, std::vector<uint8_t>>(
                input, output);
        }
    };

    class MOJO_CPP_BINDINGS_EXPORT RequireVersion {
    public:
        using DataView = RequireVersionDataView;
        using Data_ = internal::RequireVersion_Data;

        static RequireVersionPtr New();

        template <typename U>
        static RequireVersionPtr From(const U& u)
        {
            return mojo::TypeConverter<RequireVersionPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RequireVersion>::Convert(*this);
        }

        RequireVersion();
        ~RequireVersion();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = RequireVersionPtr>
        RequireVersionPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RequireVersion>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                RequireVersion::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                RequireVersion::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t version;
    };

    class MOJO_CPP_BINDINGS_EXPORT SendDisconnectReason {
    public:
        using DataView = SendDisconnectReasonDataView;
        using Data_ = internal::SendDisconnectReason_Data;

        static SendDisconnectReasonPtr New();

        template <typename U>
        static SendDisconnectReasonPtr From(const U& u)
        {
            return mojo::TypeConverter<SendDisconnectReasonPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, SendDisconnectReason>::Convert(*this);
        }

        SendDisconnectReason();
        ~SendDisconnectReason();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = SendDisconnectReasonPtr>
        SendDisconnectReasonPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, SendDisconnectReason>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                SendDisconnectReason::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                SendDisconnectReason::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t custom_reason;
        std::string description;
    };

    class MOJO_CPP_BINDINGS_EXPORT RunInput {
    public:
        using DataView = RunInputDataView;
        using Data_ = internal::RunInput_Data;
        using Tag = Data_::RunInput_Tag;

        static RunInputPtr New();

        template <typename U>
        static RunInputPtr From(const U& u)
        {
            return mojo::TypeConverter<RunInputPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RunInput>::Convert(*this);
        }

        RunInput();
        ~RunInput();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename UnionPtrType = RunInputPtr>
        RunInputPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RunInput>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        Tag which() const
        {
            return tag_;
        }

        bool is_query_version() const { return tag_ == Tag::QUERY_VERSION; }

        QueryVersionPtr& get_query_version() const
        {
            DCHECK(tag_ == Tag::QUERY_VERSION);
            return *(data_.query_version);
        }

        void set_query_version(QueryVersionPtr query_version);
        bool is_flush_for_testing() const { return tag_ == Tag::FLUSH_FOR_TESTING; }

        FlushForTestingPtr& get_flush_for_testing() const
        {
            DCHECK(tag_ == Tag::FLUSH_FOR_TESTING);
            return *(data_.flush_for_testing);
        }

        void set_flush_for_testing(FlushForTestingPtr flush_for_testing);

    private:
        friend class mojo::internal::UnionAccessor<RunInput>;
        union Union_ {
            Union_() { }
            ~Union_() { }
            QueryVersionPtr* query_version;
            FlushForTestingPtr* flush_for_testing;
        };
        void SwitchActive(Tag new_active);
        void SetActive(Tag new_active);
        void DestroyActive();
        Tag tag_;
        Union_ data_;
    };
    class MOJO_CPP_BINDINGS_EXPORT RunOutput {
    public:
        using DataView = RunOutputDataView;
        using Data_ = internal::RunOutput_Data;
        using Tag = Data_::RunOutput_Tag;

        static RunOutputPtr New();

        template <typename U>
        static RunOutputPtr From(const U& u)
        {
            return mojo::TypeConverter<RunOutputPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RunOutput>::Convert(*this);
        }

        RunOutput();
        ~RunOutput();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename UnionPtrType = RunOutputPtr>
        RunOutputPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RunOutput>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        Tag which() const
        {
            return tag_;
        }

        bool is_query_version_result() const { return tag_ == Tag::QUERY_VERSION_RESULT; }

        QueryVersionResultPtr& get_query_version_result() const
        {
            DCHECK(tag_ == Tag::QUERY_VERSION_RESULT);
            return *(data_.query_version_result);
        }

        void set_query_version_result(QueryVersionResultPtr query_version_result);

    private:
        friend class mojo::internal::UnionAccessor<RunOutput>;
        union Union_ {
            Union_() { }
            ~Union_() { }
            QueryVersionResultPtr* query_version_result;
        };
        void SwitchActive(Tag new_active);
        void SetActive(Tag new_active);
        void DestroyActive();
        Tag tag_;
        Union_ data_;
    };
    class MOJO_CPP_BINDINGS_EXPORT RunOrClosePipeInput {
    public:
        using DataView = RunOrClosePipeInputDataView;
        using Data_ = internal::RunOrClosePipeInput_Data;
        using Tag = Data_::RunOrClosePipeInput_Tag;

        static RunOrClosePipeInputPtr New();

        template <typename U>
        static RunOrClosePipeInputPtr From(const U& u)
        {
            return mojo::TypeConverter<RunOrClosePipeInputPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RunOrClosePipeInput>::Convert(*this);
        }

        RunOrClosePipeInput();
        ~RunOrClosePipeInput();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename UnionPtrType = RunOrClosePipeInputPtr>
        RunOrClosePipeInputPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RunOrClosePipeInput>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        Tag which() const
        {
            return tag_;
        }

        bool is_require_version() const { return tag_ == Tag::REQUIRE_VERSION; }

        RequireVersionPtr& get_require_version() const
        {
            DCHECK(tag_ == Tag::REQUIRE_VERSION);
            return *(data_.require_version);
        }

        void set_require_version(RequireVersionPtr require_version);
        bool is_send_disconnect_reason() const { return tag_ == Tag::SEND_DISCONNECT_REASON; }

        SendDisconnectReasonPtr& get_send_disconnect_reason() const
        {
            DCHECK(tag_ == Tag::SEND_DISCONNECT_REASON);
            return *(data_.send_disconnect_reason);
        }

        void set_send_disconnect_reason(SendDisconnectReasonPtr send_disconnect_reason);

    private:
        friend class mojo::internal::UnionAccessor<RunOrClosePipeInput>;
        union Union_ {
            Union_() { }
            ~Union_() { }
            RequireVersionPtr* require_version;
            SendDisconnectReasonPtr* send_disconnect_reason;
        };
        void SwitchActive(Tag new_active);
        void SetActive(Tag new_active);
        void DestroyActive();
        Tag tag_;
        Union_ data_;
    };

    class MOJO_CPP_BINDINGS_EXPORT RunMessageParams {
    public:
        using DataView = RunMessageParamsDataView;
        using Data_ = internal::RunMessageParams_Data;

        static RunMessageParamsPtr New();

        template <typename U>
        static RunMessageParamsPtr From(const U& u)
        {
            return mojo::TypeConverter<RunMessageParamsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RunMessageParams>::Convert(*this);
        }

        RunMessageParams();
        ~RunMessageParams();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = RunMessageParamsPtr>
        RunMessageParamsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RunMessageParams>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                RunMessageParams::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                RunMessageParams::DataView, std::vector<uint8_t>>(
                input, output);
        }

        RunInputPtr input;

    private:
        DISALLOW_COPY_AND_ASSIGN(RunMessageParams);
    };

    class MOJO_CPP_BINDINGS_EXPORT RunResponseMessageParams {
    public:
        using DataView = RunResponseMessageParamsDataView;
        using Data_ = internal::RunResponseMessageParams_Data;

        static RunResponseMessageParamsPtr New();

        template <typename U>
        static RunResponseMessageParamsPtr From(const U& u)
        {
            return mojo::TypeConverter<RunResponseMessageParamsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RunResponseMessageParams>::Convert(*this);
        }

        RunResponseMessageParams();
        ~RunResponseMessageParams();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = RunResponseMessageParamsPtr>
        RunResponseMessageParamsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RunResponseMessageParams>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                RunResponseMessageParams::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                RunResponseMessageParams::DataView, std::vector<uint8_t>>(
                input, output);
        }

        RunOutputPtr output;

    private:
        DISALLOW_COPY_AND_ASSIGN(RunResponseMessageParams);
    };

    class MOJO_CPP_BINDINGS_EXPORT RunOrClosePipeMessageParams {
    public:
        using DataView = RunOrClosePipeMessageParamsDataView;
        using Data_ = internal::RunOrClosePipeMessageParams_Data;

        static RunOrClosePipeMessageParamsPtr New();

        template <typename U>
        static RunOrClosePipeMessageParamsPtr From(const U& u)
        {
            return mojo::TypeConverter<RunOrClosePipeMessageParamsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RunOrClosePipeMessageParams>::Convert(*this);
        }

        RunOrClosePipeMessageParams();
        ~RunOrClosePipeMessageParams();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = RunOrClosePipeMessageParamsPtr>
        RunOrClosePipeMessageParamsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RunOrClosePipeMessageParams>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                RunOrClosePipeMessageParams::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                RunOrClosePipeMessageParams::DataView, std::vector<uint8_t>>(
                input, output);
        }

        RunOrClosePipeInputPtr input;

    private:
        DISALLOW_COPY_AND_ASSIGN(RunOrClosePipeMessageParams);
    };

    template <typename UnionPtrType>
    RunInputPtr RunInput::Clone() const
    {
        // Use UnionPtrType to prevent the compiler from trying to compile this
        // without being asked.
        UnionPtrType rv(New());
        switch (tag_) {
        case Tag::QUERY_VERSION:
            rv->set_query_version(mojo::internal::Clone(*data_.query_version));
            break;
        case Tag::FLUSH_FOR_TESTING:
            rv->set_flush_for_testing(mojo::internal::Clone(*data_.flush_for_testing));
            break;
        };
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RunInput>::value>::type*>
    bool RunInput::Equals(const T& other) const
    {
        if (tag_ != other.which())
            return false;

        switch (tag_) {
        case Tag::QUERY_VERSION:
            return mojo::internal::Equals(*(data_.query_version), *(other.data_.query_version));
        case Tag::FLUSH_FOR_TESTING:
            return mojo::internal::Equals(*(data_.flush_for_testing), *(other.data_.flush_for_testing));
        };

        return false;
    }
    template <typename UnionPtrType>
    RunOutputPtr RunOutput::Clone() const
    {
        // Use UnionPtrType to prevent the compiler from trying to compile this
        // without being asked.
        UnionPtrType rv(New());
        switch (tag_) {
        case Tag::QUERY_VERSION_RESULT:
            rv->set_query_version_result(mojo::internal::Clone(*data_.query_version_result));
            break;
        };
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RunOutput>::value>::type*>
    bool RunOutput::Equals(const T& other) const
    {
        if (tag_ != other.which())
            return false;

        switch (tag_) {
        case Tag::QUERY_VERSION_RESULT:
            return mojo::internal::Equals(*(data_.query_version_result), *(other.data_.query_version_result));
        };

        return false;
    }
    template <typename UnionPtrType>
    RunOrClosePipeInputPtr RunOrClosePipeInput::Clone() const
    {
        // Use UnionPtrType to prevent the compiler from trying to compile this
        // without being asked.
        UnionPtrType rv(New());
        switch (tag_) {
        case Tag::REQUIRE_VERSION:
            rv->set_require_version(mojo::internal::Clone(*data_.require_version));
            break;
        case Tag::SEND_DISCONNECT_REASON:
            rv->set_send_disconnect_reason(mojo::internal::Clone(*data_.send_disconnect_reason));
            break;
        };
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RunOrClosePipeInput>::value>::type*>
    bool RunOrClosePipeInput::Equals(const T& other) const
    {
        if (tag_ != other.which())
            return false;

        switch (tag_) {
        case Tag::REQUIRE_VERSION:
            return mojo::internal::Equals(*(data_.require_version), *(other.data_.require_version));
        case Tag::SEND_DISCONNECT_REASON:
            return mojo::internal::Equals(*(data_.send_disconnect_reason), *(other.data_.send_disconnect_reason));
        };

        return false;
    }
    template <typename StructPtrType>
    RunMessageParamsPtr RunMessageParams::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->input = mojo::internal::Clone(input);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RunMessageParams>::value>::type*>
    bool RunMessageParams::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->input, other.input))
            return false;
        return true;
    }
    template <typename StructPtrType>
    RunResponseMessageParamsPtr RunResponseMessageParams::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->output = mojo::internal::Clone(output);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RunResponseMessageParams>::value>::type*>
    bool RunResponseMessageParams::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->output, other.output))
            return false;
        return true;
    }
    template <typename StructPtrType>
    QueryVersionPtr QueryVersion::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, QueryVersion>::value>::type*>
    bool QueryVersion::Equals(const T& other) const
    {
        return true;
    }
    template <typename StructPtrType>
    QueryVersionResultPtr QueryVersionResult::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->version = mojo::internal::Clone(version);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, QueryVersionResult>::value>::type*>
    bool QueryVersionResult::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->version, other.version))
            return false;
        return true;
    }
    template <typename StructPtrType>
    FlushForTestingPtr FlushForTesting::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FlushForTesting>::value>::type*>
    bool FlushForTesting::Equals(const T& other) const
    {
        return true;
    }
    template <typename StructPtrType>
    RunOrClosePipeMessageParamsPtr RunOrClosePipeMessageParams::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->input = mojo::internal::Clone(input);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RunOrClosePipeMessageParams>::value>::type*>
    bool RunOrClosePipeMessageParams::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->input, other.input))
            return false;
        return true;
    }
    template <typename StructPtrType>
    RequireVersionPtr RequireVersion::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->version = mojo::internal::Clone(version);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RequireVersion>::value>::type*>
    bool RequireVersion::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->version, other.version))
            return false;
        return true;
    }
    template <typename StructPtrType>
    SendDisconnectReasonPtr SendDisconnectReason::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->custom_reason = mojo::internal::Clone(custom_reason);
        rv->description = mojo::internal::Clone(description);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, SendDisconnectReason>::value>::type*>
    bool SendDisconnectReason::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->custom_reason, other.custom_reason))
            return false;
        if (!mojo::internal::Equals(this->description, other.description))
            return false;
        return true;
    }

} // namespace interface_control
} // namespace mojo

namespace mojo {

template <>
struct MOJO_CPP_BINDINGS_EXPORT StructTraits<::mojo::interface_control::RunMessageParams::DataView,
    ::mojo::interface_control::RunMessageParamsPtr> {
    static bool IsNull(const ::mojo::interface_control::RunMessageParamsPtr& input) { return !input; }
    static void SetToNull(::mojo::interface_control::RunMessageParamsPtr* output) { output->reset(); }

    static const decltype(::mojo::interface_control::RunMessageParams::input)& input(
        const ::mojo::interface_control::RunMessageParamsPtr& input)
    {
        return input->input;
    }

    static bool Read(::mojo::interface_control::RunMessageParams::DataView input, ::mojo::interface_control::RunMessageParamsPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT StructTraits<::mojo::interface_control::RunResponseMessageParams::DataView,
    ::mojo::interface_control::RunResponseMessageParamsPtr> {
    static bool IsNull(const ::mojo::interface_control::RunResponseMessageParamsPtr& input) { return !input; }
    static void SetToNull(::mojo::interface_control::RunResponseMessageParamsPtr* output) { output->reset(); }

    static const decltype(::mojo::interface_control::RunResponseMessageParams::output)& output(
        const ::mojo::interface_control::RunResponseMessageParamsPtr& input)
    {
        return input->output;
    }

    static bool Read(::mojo::interface_control::RunResponseMessageParams::DataView input, ::mojo::interface_control::RunResponseMessageParamsPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT StructTraits<::mojo::interface_control::QueryVersion::DataView,
    ::mojo::interface_control::QueryVersionPtr> {
    static bool IsNull(const ::mojo::interface_control::QueryVersionPtr& input) { return !input; }
    static void SetToNull(::mojo::interface_control::QueryVersionPtr* output) { output->reset(); }

    static bool Read(::mojo::interface_control::QueryVersion::DataView input, ::mojo::interface_control::QueryVersionPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT StructTraits<::mojo::interface_control::QueryVersionResult::DataView,
    ::mojo::interface_control::QueryVersionResultPtr> {
    static bool IsNull(const ::mojo::interface_control::QueryVersionResultPtr& input) { return !input; }
    static void SetToNull(::mojo::interface_control::QueryVersionResultPtr* output) { output->reset(); }

    static decltype(::mojo::interface_control::QueryVersionResult::version) version(
        const ::mojo::interface_control::QueryVersionResultPtr& input)
    {
        return input->version;
    }

    static bool Read(::mojo::interface_control::QueryVersionResult::DataView input, ::mojo::interface_control::QueryVersionResultPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT StructTraits<::mojo::interface_control::FlushForTesting::DataView,
    ::mojo::interface_control::FlushForTestingPtr> {
    static bool IsNull(const ::mojo::interface_control::FlushForTestingPtr& input) { return !input; }
    static void SetToNull(::mojo::interface_control::FlushForTestingPtr* output) { output->reset(); }

    static bool Read(::mojo::interface_control::FlushForTesting::DataView input, ::mojo::interface_control::FlushForTestingPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT StructTraits<::mojo::interface_control::RunOrClosePipeMessageParams::DataView,
    ::mojo::interface_control::RunOrClosePipeMessageParamsPtr> {
    static bool IsNull(const ::mojo::interface_control::RunOrClosePipeMessageParamsPtr& input) { return !input; }
    static void SetToNull(::mojo::interface_control::RunOrClosePipeMessageParamsPtr* output) { output->reset(); }

    static const decltype(::mojo::interface_control::RunOrClosePipeMessageParams::input)& input(
        const ::mojo::interface_control::RunOrClosePipeMessageParamsPtr& input)
    {
        return input->input;
    }

    static bool Read(::mojo::interface_control::RunOrClosePipeMessageParams::DataView input, ::mojo::interface_control::RunOrClosePipeMessageParamsPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT StructTraits<::mojo::interface_control::RequireVersion::DataView,
    ::mojo::interface_control::RequireVersionPtr> {
    static bool IsNull(const ::mojo::interface_control::RequireVersionPtr& input) { return !input; }
    static void SetToNull(::mojo::interface_control::RequireVersionPtr* output) { output->reset(); }

    static decltype(::mojo::interface_control::RequireVersion::version) version(
        const ::mojo::interface_control::RequireVersionPtr& input)
    {
        return input->version;
    }

    static bool Read(::mojo::interface_control::RequireVersion::DataView input, ::mojo::interface_control::RequireVersionPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT StructTraits<::mojo::interface_control::SendDisconnectReason::DataView,
    ::mojo::interface_control::SendDisconnectReasonPtr> {
    static bool IsNull(const ::mojo::interface_control::SendDisconnectReasonPtr& input) { return !input; }
    static void SetToNull(::mojo::interface_control::SendDisconnectReasonPtr* output) { output->reset(); }

    static decltype(::mojo::interface_control::SendDisconnectReason::custom_reason) custom_reason(
        const ::mojo::interface_control::SendDisconnectReasonPtr& input)
    {
        return input->custom_reason;
    }

    static const decltype(::mojo::interface_control::SendDisconnectReason::description)& description(
        const ::mojo::interface_control::SendDisconnectReasonPtr& input)
    {
        return input->description;
    }

    static bool Read(::mojo::interface_control::SendDisconnectReason::DataView input, ::mojo::interface_control::SendDisconnectReasonPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT UnionTraits<::mojo::interface_control::RunInput::DataView,
    ::mojo::interface_control::RunInputPtr> {
    static bool IsNull(const ::mojo::interface_control::RunInputPtr& input) { return !input; }
    static void SetToNull(::mojo::interface_control::RunInputPtr* output) { output->reset(); }

    static ::mojo::interface_control::RunInput::Tag GetTag(const ::mojo::interface_control::RunInputPtr& input)
    {
        return input->which();
    }

    static const ::mojo::interface_control::QueryVersionPtr& query_version(const ::mojo::interface_control::RunInputPtr& input)
    {
        return input->get_query_version();
    }

    static const ::mojo::interface_control::FlushForTestingPtr& flush_for_testing(const ::mojo::interface_control::RunInputPtr& input)
    {
        return input->get_flush_for_testing();
    }

    static bool Read(::mojo::interface_control::RunInput::DataView input, ::mojo::interface_control::RunInputPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT UnionTraits<::mojo::interface_control::RunOutput::DataView,
    ::mojo::interface_control::RunOutputPtr> {
    static bool IsNull(const ::mojo::interface_control::RunOutputPtr& input) { return !input; }
    static void SetToNull(::mojo::interface_control::RunOutputPtr* output) { output->reset(); }

    static ::mojo::interface_control::RunOutput::Tag GetTag(const ::mojo::interface_control::RunOutputPtr& input)
    {
        return input->which();
    }

    static const ::mojo::interface_control::QueryVersionResultPtr& query_version_result(const ::mojo::interface_control::RunOutputPtr& input)
    {
        return input->get_query_version_result();
    }

    static bool Read(::mojo::interface_control::RunOutput::DataView input, ::mojo::interface_control::RunOutputPtr* output);
};

template <>
struct MOJO_CPP_BINDINGS_EXPORT UnionTraits<::mojo::interface_control::RunOrClosePipeInput::DataView,
    ::mojo::interface_control::RunOrClosePipeInputPtr> {
    static bool IsNull(const ::mojo::interface_control::RunOrClosePipeInputPtr& input) { return !input; }
    static void SetToNull(::mojo::interface_control::RunOrClosePipeInputPtr* output) { output->reset(); }

    static ::mojo::interface_control::RunOrClosePipeInput::Tag GetTag(const ::mojo::interface_control::RunOrClosePipeInputPtr& input)
    {
        return input->which();
    }

    static const ::mojo::interface_control::RequireVersionPtr& require_version(const ::mojo::interface_control::RunOrClosePipeInputPtr& input)
    {
        return input->get_require_version();
    }

    static const ::mojo::interface_control::SendDisconnectReasonPtr& send_disconnect_reason(const ::mojo::interface_control::RunOrClosePipeInputPtr& input)
    {
        return input->get_send_disconnect_reason();
    }

    static bool Read(::mojo::interface_control::RunOrClosePipeInput::DataView input, ::mojo::interface_control::RunOrClosePipeInputPtr* output);
};

} // namespace mojo

#endif // MOJO_PUBLIC_INTERFACES_BINDINGS_INTERFACE_CONTROL_MESSAGES_MOJOM_H_