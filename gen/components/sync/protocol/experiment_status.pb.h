// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: experiment_status.proto

#ifndef PROTOBUF_experiment_5fstatus_2eproto__INCLUDED
#define PROTOBUF_experiment_5fstatus_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include "experiments_specifics.pb.h"
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
// @@protoc_insertion_point(includes)

namespace sync_pb {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_experiment_5fstatus_2eproto();
void protobuf_AssignDesc_experiment_5fstatus_2eproto();
void protobuf_ShutdownFile_experiment_5fstatus_2eproto();

class ExperimentStatusRequest;
class ExperimentStatusResponse;

// ===================================================================

class ExperimentStatusRequest : public ::google::protobuf::MessageLite {
public:
    ExperimentStatusRequest();
    virtual ~ExperimentStatusRequest();

    ExperimentStatusRequest(const ExperimentStatusRequest& from);

    inline ExperimentStatusRequest& operator=(const ExperimentStatusRequest& from)
    {
        CopyFrom(from);
        return *this;
    }

    inline const ::std::string& unknown_fields() const
    {
        return _unknown_fields_.GetNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }

    inline ::std::string* mutable_unknown_fields()
    {
        return _unknown_fields_.MutableNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }

    static const ExperimentStatusRequest& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    // Returns the internal default instance pointer. This function can
    // return NULL thus should not be used by the user. This is intended
    // for Protobuf internal code. Please use default_instance() declared
    // above instead.
    static inline const ExperimentStatusRequest* internal_default_instance()
    {
        return default_instance_;
    }
#endif

    GOOGLE_ATTRIBUTE_NOINLINE void Swap(ExperimentStatusRequest* other);

    // implements Message ----------------------------------------------

    inline ExperimentStatusRequest* New() const { return New(NULL); }

    ExperimentStatusRequest* New(::google::protobuf::Arena* arena) const;
    void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
    void CopyFrom(const ExperimentStatusRequest& from);
    void MergeFrom(const ExperimentStatusRequest& from);
    void Clear();
    bool IsInitialized() const;

    int ByteSize() const;
    bool MergePartialFromCodedStream(
        ::google::protobuf::io::CodedInputStream* input);
    void SerializeWithCachedSizes(
        ::google::protobuf::io::CodedOutputStream* output) const;
    void DiscardUnknownFields();
    int GetCachedSize() const { return _cached_size_; }

private:
    void SharedCtor();
    void SharedDtor();
    void SetCachedSize(int size) const;
    void InternalSwap(ExperimentStatusRequest* other);

private:
    inline ::google::protobuf::Arena* GetArenaNoVirtual() const
    {
        return _arena_ptr_;
    }
    inline ::google::protobuf::Arena* MaybeArenaPtr() const
    {
        return _arena_ptr_;
    }

public:
    ::std::string GetTypeName() const;

    // nested types ----------------------------------------------------

    // accessors -------------------------------------------------------

    // repeated string experiment_name = 1;
    int experiment_name_size() const;
    void clear_experiment_name();
    static const int kExperimentNameFieldNumber = 1;
    const ::std::string& experiment_name(int index) const;
    ::std::string* mutable_experiment_name(int index);
    void set_experiment_name(int index, const ::std::string& value);
    void set_experiment_name(int index, const char* value);
    void set_experiment_name(int index, const char* value, size_t size);
    ::std::string* add_experiment_name();
    void add_experiment_name(const ::std::string& value);
    void add_experiment_name(const char* value);
    void add_experiment_name(const char* value, size_t size);
    const ::google::protobuf::RepeatedPtrField<::std::string>& experiment_name() const;
    ::google::protobuf::RepeatedPtrField<::std::string>* mutable_experiment_name();

    // @@protoc_insertion_point(class_scope:sync_pb.ExperimentStatusRequest)
private:
    ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
    ::google::protobuf::Arena* _arena_ptr_;

    ::google::protobuf::uint32 _has_bits_[1];
    mutable int _cached_size_;
    ::google::protobuf::RepeatedPtrField<::std::string> experiment_name_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    friend void protobuf_AddDesc_experiment_5fstatus_2eproto_impl();
#else
    friend void protobuf_AddDesc_experiment_5fstatus_2eproto();
#endif
    friend void protobuf_AssignDesc_experiment_5fstatus_2eproto();
    friend void protobuf_ShutdownFile_experiment_5fstatus_2eproto();

    void InitAsDefaultInstance();
    static ExperimentStatusRequest* default_instance_;
};
// -------------------------------------------------------------------

class ExperimentStatusResponse : public ::google::protobuf::MessageLite {
public:
    ExperimentStatusResponse();
    virtual ~ExperimentStatusResponse();

    ExperimentStatusResponse(const ExperimentStatusResponse& from);

    inline ExperimentStatusResponse& operator=(const ExperimentStatusResponse& from)
    {
        CopyFrom(from);
        return *this;
    }

    inline const ::std::string& unknown_fields() const
    {
        return _unknown_fields_.GetNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }

    inline ::std::string* mutable_unknown_fields()
    {
        return _unknown_fields_.MutableNoArena(
            &::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }

    static const ExperimentStatusResponse& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    // Returns the internal default instance pointer. This function can
    // return NULL thus should not be used by the user. This is intended
    // for Protobuf internal code. Please use default_instance() declared
    // above instead.
    static inline const ExperimentStatusResponse* internal_default_instance()
    {
        return default_instance_;
    }
#endif

    GOOGLE_ATTRIBUTE_NOINLINE void Swap(ExperimentStatusResponse* other);

    // implements Message ----------------------------------------------

    inline ExperimentStatusResponse* New() const { return New(NULL); }

    ExperimentStatusResponse* New(::google::protobuf::Arena* arena) const;
    void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
    void CopyFrom(const ExperimentStatusResponse& from);
    void MergeFrom(const ExperimentStatusResponse& from);
    void Clear();
    bool IsInitialized() const;

    int ByteSize() const;
    bool MergePartialFromCodedStream(
        ::google::protobuf::io::CodedInputStream* input);
    void SerializeWithCachedSizes(
        ::google::protobuf::io::CodedOutputStream* output) const;
    void DiscardUnknownFields();
    int GetCachedSize() const { return _cached_size_; }

private:
    void SharedCtor();
    void SharedDtor();
    void SetCachedSize(int size) const;
    void InternalSwap(ExperimentStatusResponse* other);

private:
    inline ::google::protobuf::Arena* GetArenaNoVirtual() const
    {
        return _arena_ptr_;
    }
    inline ::google::protobuf::Arena* MaybeArenaPtr() const
    {
        return _arena_ptr_;
    }

public:
    ::std::string GetTypeName() const;

    // nested types ----------------------------------------------------

    // accessors -------------------------------------------------------

    // optional int32 poll_interval_seconds = 1 [default = 3600];
    bool has_poll_interval_seconds() const;
    void clear_poll_interval_seconds();
    static const int kPollIntervalSecondsFieldNumber = 1;
    ::google::protobuf::int32 poll_interval_seconds() const;
    void set_poll_interval_seconds(::google::protobuf::int32 value);

    // repeated .sync_pb.ExperimentsSpecifics experiment = 2;
    int experiment_size() const;
    void clear_experiment();
    static const int kExperimentFieldNumber = 2;
    const ::sync_pb::ExperimentsSpecifics& experiment(int index) const;
    ::sync_pb::ExperimentsSpecifics* mutable_experiment(int index);
    ::sync_pb::ExperimentsSpecifics* add_experiment();
    ::google::protobuf::RepeatedPtrField<::sync_pb::ExperimentsSpecifics>*
    mutable_experiment();
    const ::google::protobuf::RepeatedPtrField<::sync_pb::ExperimentsSpecifics>&
    experiment() const;

    // @@protoc_insertion_point(class_scope:sync_pb.ExperimentStatusResponse)
private:
    inline void set_has_poll_interval_seconds();
    inline void clear_has_poll_interval_seconds();

    ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
    ::google::protobuf::Arena* _arena_ptr_;

    ::google::protobuf::uint32 _has_bits_[1];
    mutable int _cached_size_;
    ::google::protobuf::RepeatedPtrField<::sync_pb::ExperimentsSpecifics> experiment_;
    ::google::protobuf::int32 poll_interval_seconds_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    friend void protobuf_AddDesc_experiment_5fstatus_2eproto_impl();
#else
    friend void protobuf_AddDesc_experiment_5fstatus_2eproto();
#endif
    friend void protobuf_AssignDesc_experiment_5fstatus_2eproto();
    friend void protobuf_ShutdownFile_experiment_5fstatus_2eproto();

    void InitAsDefaultInstance();
    static ExperimentStatusResponse* default_instance_;
};
// ===================================================================

// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ExperimentStatusRequest

// repeated string experiment_name = 1;
inline int ExperimentStatusRequest::experiment_name_size() const
{
    return experiment_name_.size();
}
inline void ExperimentStatusRequest::clear_experiment_name()
{
    experiment_name_.Clear();
}
inline const ::std::string& ExperimentStatusRequest::experiment_name(int index) const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExperimentStatusRequest.experiment_name)
    return experiment_name_.Get(index);
}
inline ::std::string* ExperimentStatusRequest::mutable_experiment_name(int index)
{
    // @@protoc_insertion_point(field_mutable:sync_pb.ExperimentStatusRequest.experiment_name)
    return experiment_name_.Mutable(index);
}
inline void ExperimentStatusRequest::set_experiment_name(int index, const ::std::string& value)
{
    // @@protoc_insertion_point(field_set:sync_pb.ExperimentStatusRequest.experiment_name)
    experiment_name_.Mutable(index)->assign(value);
}
inline void ExperimentStatusRequest::set_experiment_name(int index, const char* value)
{
    experiment_name_.Mutable(index)->assign(value);
    // @@protoc_insertion_point(field_set_char:sync_pb.ExperimentStatusRequest.experiment_name)
}
inline void ExperimentStatusRequest::set_experiment_name(int index, const char* value, size_t size)
{
    experiment_name_.Mutable(index)->assign(
        reinterpret_cast<const char*>(value), size);
    // @@protoc_insertion_point(field_set_pointer:sync_pb.ExperimentStatusRequest.experiment_name)
}
inline ::std::string* ExperimentStatusRequest::add_experiment_name()
{
    // @@protoc_insertion_point(field_add_mutable:sync_pb.ExperimentStatusRequest.experiment_name)
    return experiment_name_.Add();
}
inline void ExperimentStatusRequest::add_experiment_name(const ::std::string& value)
{
    experiment_name_.Add()->assign(value);
    // @@protoc_insertion_point(field_add:sync_pb.ExperimentStatusRequest.experiment_name)
}
inline void ExperimentStatusRequest::add_experiment_name(const char* value)
{
    experiment_name_.Add()->assign(value);
    // @@protoc_insertion_point(field_add_char:sync_pb.ExperimentStatusRequest.experiment_name)
}
inline void ExperimentStatusRequest::add_experiment_name(const char* value, size_t size)
{
    experiment_name_.Add()->assign(reinterpret_cast<const char*>(value), size);
    // @@protoc_insertion_point(field_add_pointer:sync_pb.ExperimentStatusRequest.experiment_name)
}
inline const ::google::protobuf::RepeatedPtrField<::std::string>&
ExperimentStatusRequest::experiment_name() const
{
    // @@protoc_insertion_point(field_list:sync_pb.ExperimentStatusRequest.experiment_name)
    return experiment_name_;
}
inline ::google::protobuf::RepeatedPtrField<::std::string>*
ExperimentStatusRequest::mutable_experiment_name()
{
    // @@protoc_insertion_point(field_mutable_list:sync_pb.ExperimentStatusRequest.experiment_name)
    return &experiment_name_;
}

// -------------------------------------------------------------------

// ExperimentStatusResponse

// optional int32 poll_interval_seconds = 1 [default = 3600];
inline bool ExperimentStatusResponse::has_poll_interval_seconds() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ExperimentStatusResponse::set_has_poll_interval_seconds()
{
    _has_bits_[0] |= 0x00000001u;
}
inline void ExperimentStatusResponse::clear_has_poll_interval_seconds()
{
    _has_bits_[0] &= ~0x00000001u;
}
inline void ExperimentStatusResponse::clear_poll_interval_seconds()
{
    poll_interval_seconds_ = 3600;
    clear_has_poll_interval_seconds();
}
inline ::google::protobuf::int32 ExperimentStatusResponse::poll_interval_seconds() const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExperimentStatusResponse.poll_interval_seconds)
    return poll_interval_seconds_;
}
inline void ExperimentStatusResponse::set_poll_interval_seconds(::google::protobuf::int32 value)
{
    set_has_poll_interval_seconds();
    poll_interval_seconds_ = value;
    // @@protoc_insertion_point(field_set:sync_pb.ExperimentStatusResponse.poll_interval_seconds)
}

// repeated .sync_pb.ExperimentsSpecifics experiment = 2;
inline int ExperimentStatusResponse::experiment_size() const
{
    return experiment_.size();
}
inline void ExperimentStatusResponse::clear_experiment()
{
    experiment_.Clear();
}
inline const ::sync_pb::ExperimentsSpecifics& ExperimentStatusResponse::experiment(int index) const
{
    // @@protoc_insertion_point(field_get:sync_pb.ExperimentStatusResponse.experiment)
    return experiment_.Get(index);
}
inline ::sync_pb::ExperimentsSpecifics* ExperimentStatusResponse::mutable_experiment(int index)
{
    // @@protoc_insertion_point(field_mutable:sync_pb.ExperimentStatusResponse.experiment)
    return experiment_.Mutable(index);
}
inline ::sync_pb::ExperimentsSpecifics* ExperimentStatusResponse::add_experiment()
{
    // @@protoc_insertion_point(field_add:sync_pb.ExperimentStatusResponse.experiment)
    return experiment_.Add();
}
inline ::google::protobuf::RepeatedPtrField<::sync_pb::ExperimentsSpecifics>*
ExperimentStatusResponse::mutable_experiment()
{
    // @@protoc_insertion_point(field_mutable_list:sync_pb.ExperimentStatusResponse.experiment)
    return &experiment_;
}
inline const ::google::protobuf::RepeatedPtrField<::sync_pb::ExperimentsSpecifics>&
ExperimentStatusResponse::experiment() const
{
    // @@protoc_insertion_point(field_list:sync_pb.ExperimentStatusResponse.experiment)
    return experiment_;
}

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// @@protoc_insertion_point(namespace_scope)

} // namespace sync_pb

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_experiment_5fstatus_2eproto__INCLUDED
