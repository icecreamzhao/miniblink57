// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: variations_seed.proto

#ifndef PROTOBUF_variations_5fseed_2eproto__INCLUDED
#define PROTOBUF_variations_5fseed_2eproto__INCLUDED

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

#include "study.pb.h"
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
// @@protoc_insertion_point(includes)

namespace variations {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_variations_5fseed_2eproto();
void protobuf_AssignDesc_variations_5fseed_2eproto();
void protobuf_ShutdownFile_variations_5fseed_2eproto();

class VariationsSeed;

// ===================================================================

class VariationsSeed : public ::google::protobuf::MessageLite {
public:
    VariationsSeed();
    virtual ~VariationsSeed();

    VariationsSeed(const VariationsSeed& from);

    inline VariationsSeed& operator=(const VariationsSeed& from)
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

    static const VariationsSeed& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    // Returns the internal default instance pointer. This function can
    // return NULL thus should not be used by the user. This is intended
    // for Protobuf internal code. Please use default_instance() declared
    // above instead.
    static inline const VariationsSeed* internal_default_instance()
    {
        return default_instance_;
    }
#endif

    GOOGLE_ATTRIBUTE_NOINLINE void Swap(VariationsSeed* other);

    // implements Message ----------------------------------------------

    inline VariationsSeed* New() const { return New(NULL); }

    VariationsSeed* New(::google::protobuf::Arena* arena) const;
    void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
    void CopyFrom(const VariationsSeed& from);
    void MergeFrom(const VariationsSeed& from);
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
    void InternalSwap(VariationsSeed* other);

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

    // optional string serial_number = 1;
    bool has_serial_number() const;
    void clear_serial_number();
    static const int kSerialNumberFieldNumber = 1;
    const ::std::string& serial_number() const;
    void set_serial_number(const ::std::string& value);
    void set_serial_number(const char* value);
    void set_serial_number(const char* value, size_t size);
    ::std::string* mutable_serial_number();
    ::std::string* release_serial_number();
    void set_allocated_serial_number(::std::string* serial_number);

    // repeated .variations.Study study = 2;
    int study_size() const;
    void clear_study();
    static const int kStudyFieldNumber = 2;
    const ::variations::Study& study(int index) const;
    ::variations::Study* mutable_study(int index);
    ::variations::Study* add_study();
    ::google::protobuf::RepeatedPtrField<::variations::Study>*
    mutable_study();
    const ::google::protobuf::RepeatedPtrField<::variations::Study>&
    study() const;

    // optional string country_code = 3;
    bool has_country_code() const;
    void clear_country_code();
    static const int kCountryCodeFieldNumber = 3;
    const ::std::string& country_code() const;
    void set_country_code(const ::std::string& value);
    void set_country_code(const char* value);
    void set_country_code(const char* value, size_t size);
    ::std::string* mutable_country_code();
    ::std::string* release_country_code();
    void set_allocated_country_code(::std::string* country_code);

    // @@protoc_insertion_point(class_scope:variations.VariationsSeed)
private:
    inline void set_has_serial_number();
    inline void clear_has_serial_number();
    inline void set_has_country_code();
    inline void clear_has_country_code();

    ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
    ::google::protobuf::Arena* _arena_ptr_;

    ::google::protobuf::uint32 _has_bits_[1];
    mutable int _cached_size_;
    ::google::protobuf::internal::ArenaStringPtr serial_number_;
    ::google::protobuf::RepeatedPtrField<::variations::Study> study_;
    ::google::protobuf::internal::ArenaStringPtr country_code_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    friend void protobuf_AddDesc_variations_5fseed_2eproto_impl();
#else
    friend void protobuf_AddDesc_variations_5fseed_2eproto();
#endif
    friend void protobuf_AssignDesc_variations_5fseed_2eproto();
    friend void protobuf_ShutdownFile_variations_5fseed_2eproto();

    void InitAsDefaultInstance();
    static VariationsSeed* default_instance_;
};
// ===================================================================

// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// VariationsSeed

// optional string serial_number = 1;
inline bool VariationsSeed::has_serial_number() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void VariationsSeed::set_has_serial_number()
{
    _has_bits_[0] |= 0x00000001u;
}
inline void VariationsSeed::clear_has_serial_number()
{
    _has_bits_[0] &= ~0x00000001u;
}
inline void VariationsSeed::clear_serial_number()
{
    serial_number_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_serial_number();
}
inline const ::std::string& VariationsSeed::serial_number() const
{
    // @@protoc_insertion_point(field_get:variations.VariationsSeed.serial_number)
    return serial_number_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void VariationsSeed::set_serial_number(const ::std::string& value)
{
    set_has_serial_number();
    serial_number_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:variations.VariationsSeed.serial_number)
}
inline void VariationsSeed::set_serial_number(const char* value)
{
    set_has_serial_number();
    serial_number_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:variations.VariationsSeed.serial_number)
}
inline void VariationsSeed::set_serial_number(const char* value, size_t size)
{
    set_has_serial_number();
    serial_number_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:variations.VariationsSeed.serial_number)
}
inline ::std::string* VariationsSeed::mutable_serial_number()
{
    set_has_serial_number();
    // @@protoc_insertion_point(field_mutable:variations.VariationsSeed.serial_number)
    return serial_number_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* VariationsSeed::release_serial_number()
{
    // @@protoc_insertion_point(field_release:variations.VariationsSeed.serial_number)
    clear_has_serial_number();
    return serial_number_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void VariationsSeed::set_allocated_serial_number(::std::string* serial_number)
{
    if (serial_number != NULL) {
        set_has_serial_number();
    } else {
        clear_has_serial_number();
    }
    serial_number_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), serial_number);
    // @@protoc_insertion_point(field_set_allocated:variations.VariationsSeed.serial_number)
}

// repeated .variations.Study study = 2;
inline int VariationsSeed::study_size() const
{
    return study_.size();
}
inline void VariationsSeed::clear_study()
{
    study_.Clear();
}
inline const ::variations::Study& VariationsSeed::study(int index) const
{
    // @@protoc_insertion_point(field_get:variations.VariationsSeed.study)
    return study_.Get(index);
}
inline ::variations::Study* VariationsSeed::mutable_study(int index)
{
    // @@protoc_insertion_point(field_mutable:variations.VariationsSeed.study)
    return study_.Mutable(index);
}
inline ::variations::Study* VariationsSeed::add_study()
{
    // @@protoc_insertion_point(field_add:variations.VariationsSeed.study)
    return study_.Add();
}
inline ::google::protobuf::RepeatedPtrField<::variations::Study>*
VariationsSeed::mutable_study()
{
    // @@protoc_insertion_point(field_mutable_list:variations.VariationsSeed.study)
    return &study_;
}
inline const ::google::protobuf::RepeatedPtrField<::variations::Study>&
VariationsSeed::study() const
{
    // @@protoc_insertion_point(field_list:variations.VariationsSeed.study)
    return study_;
}

// optional string country_code = 3;
inline bool VariationsSeed::has_country_code() const
{
    return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void VariationsSeed::set_has_country_code()
{
    _has_bits_[0] |= 0x00000004u;
}
inline void VariationsSeed::clear_has_country_code()
{
    _has_bits_[0] &= ~0x00000004u;
}
inline void VariationsSeed::clear_country_code()
{
    country_code_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_country_code();
}
inline const ::std::string& VariationsSeed::country_code() const
{
    // @@protoc_insertion_point(field_get:variations.VariationsSeed.country_code)
    return country_code_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void VariationsSeed::set_country_code(const ::std::string& value)
{
    set_has_country_code();
    country_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
    // @@protoc_insertion_point(field_set:variations.VariationsSeed.country_code)
}
inline void VariationsSeed::set_country_code(const char* value)
{
    set_has_country_code();
    country_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
    // @@protoc_insertion_point(field_set_char:variations.VariationsSeed.country_code)
}
inline void VariationsSeed::set_country_code(const char* value, size_t size)
{
    set_has_country_code();
    country_code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        ::std::string(reinterpret_cast<const char*>(value), size));
    // @@protoc_insertion_point(field_set_pointer:variations.VariationsSeed.country_code)
}
inline ::std::string* VariationsSeed::mutable_country_code()
{
    set_has_country_code();
    // @@protoc_insertion_point(field_mutable:variations.VariationsSeed.country_code)
    return country_code_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* VariationsSeed::release_country_code()
{
    // @@protoc_insertion_point(field_release:variations.VariationsSeed.country_code)
    clear_has_country_code();
    return country_code_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void VariationsSeed::set_allocated_country_code(::std::string* country_code)
{
    if (country_code != NULL) {
        set_has_country_code();
    } else {
        clear_has_country_code();
    }
    country_code_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), country_code);
    // @@protoc_insertion_point(field_set_allocated:variations.VariationsSeed.country_code)
}

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

} // namespace variations

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_variations_5fseed_2eproto__INCLUDED
