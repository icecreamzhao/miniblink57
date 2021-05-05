// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: metadata.proto

#ifndef PROTOBUF_metadata_2eproto__INCLUDED
#define PROTOBUF_metadata_2eproto__INCLUDED

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

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_util.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
// @@protoc_insertion_point(includes)

namespace safe_browsing {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_metadata_2eproto();
void protobuf_AssignDesc_metadata_2eproto();
void protobuf_ShutdownFile_metadata_2eproto();

class MalwarePatternType;
class SocialEngineeringPatternType;

enum MalwarePatternType_PATTERN_TYPE {
    MalwarePatternType_PATTERN_TYPE_TYPE_UNSPECIFIED = 0,
    MalwarePatternType_PATTERN_TYPE_LANDING = 1,
    MalwarePatternType_PATTERN_TYPE_DISTRIBUTION = 2
};
bool MalwarePatternType_PATTERN_TYPE_IsValid(int value);
const MalwarePatternType_PATTERN_TYPE MalwarePatternType_PATTERN_TYPE_PATTERN_TYPE_MIN = MalwarePatternType_PATTERN_TYPE_TYPE_UNSPECIFIED;
const MalwarePatternType_PATTERN_TYPE MalwarePatternType_PATTERN_TYPE_PATTERN_TYPE_MAX = MalwarePatternType_PATTERN_TYPE_DISTRIBUTION;
const int MalwarePatternType_PATTERN_TYPE_PATTERN_TYPE_ARRAYSIZE = MalwarePatternType_PATTERN_TYPE_PATTERN_TYPE_MAX + 1;

enum SocialEngineeringPatternType_PATTERN_TYPE {
    SocialEngineeringPatternType_PATTERN_TYPE_TYPE_UNSPECIFIED = 0,
    SocialEngineeringPatternType_PATTERN_TYPE_SOCIAL_ENGINEERING_ADS = 1,
    SocialEngineeringPatternType_PATTERN_TYPE_SOCIAL_ENGINEERING_LANDING = 2,
    SocialEngineeringPatternType_PATTERN_TYPE_PHISHING = 3
};
bool SocialEngineeringPatternType_PATTERN_TYPE_IsValid(int value);
const SocialEngineeringPatternType_PATTERN_TYPE SocialEngineeringPatternType_PATTERN_TYPE_PATTERN_TYPE_MIN = SocialEngineeringPatternType_PATTERN_TYPE_TYPE_UNSPECIFIED;
const SocialEngineeringPatternType_PATTERN_TYPE SocialEngineeringPatternType_PATTERN_TYPE_PATTERN_TYPE_MAX = SocialEngineeringPatternType_PATTERN_TYPE_PHISHING;
const int SocialEngineeringPatternType_PATTERN_TYPE_PATTERN_TYPE_ARRAYSIZE = SocialEngineeringPatternType_PATTERN_TYPE_PATTERN_TYPE_MAX + 1;

// ===================================================================

class MalwarePatternType : public ::google::protobuf::MessageLite {
public:
    MalwarePatternType();
    virtual ~MalwarePatternType();

    MalwarePatternType(const MalwarePatternType& from);

    inline MalwarePatternType& operator=(const MalwarePatternType& from)
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

    static const MalwarePatternType& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    // Returns the internal default instance pointer. This function can
    // return NULL thus should not be used by the user. This is intended
    // for Protobuf internal code. Please use default_instance() declared
    // above instead.
    static inline const MalwarePatternType* internal_default_instance()
    {
        return default_instance_;
    }
#endif

    GOOGLE_ATTRIBUTE_NOINLINE void Swap(MalwarePatternType* other);

    // implements Message ----------------------------------------------

    inline MalwarePatternType* New() const { return New(NULL); }

    MalwarePatternType* New(::google::protobuf::Arena* arena) const;
    void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
    void CopyFrom(const MalwarePatternType& from);
    void MergeFrom(const MalwarePatternType& from);
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
    void InternalSwap(MalwarePatternType* other);

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

    typedef MalwarePatternType_PATTERN_TYPE PATTERN_TYPE;
    static const PATTERN_TYPE TYPE_UNSPECIFIED = MalwarePatternType_PATTERN_TYPE_TYPE_UNSPECIFIED;
    static const PATTERN_TYPE LANDING = MalwarePatternType_PATTERN_TYPE_LANDING;
    static const PATTERN_TYPE DISTRIBUTION = MalwarePatternType_PATTERN_TYPE_DISTRIBUTION;
    static inline bool PATTERN_TYPE_IsValid(int value)
    {
        return MalwarePatternType_PATTERN_TYPE_IsValid(value);
    }
    static const PATTERN_TYPE PATTERN_TYPE_MIN = MalwarePatternType_PATTERN_TYPE_PATTERN_TYPE_MIN;
    static const PATTERN_TYPE PATTERN_TYPE_MAX = MalwarePatternType_PATTERN_TYPE_PATTERN_TYPE_MAX;
    static const int PATTERN_TYPE_ARRAYSIZE = MalwarePatternType_PATTERN_TYPE_PATTERN_TYPE_ARRAYSIZE;

    // accessors -------------------------------------------------------

    // required .safe_browsing.MalwarePatternType.PATTERN_TYPE pattern_type = 1;
    bool has_pattern_type() const;
    void clear_pattern_type();
    static const int kPatternTypeFieldNumber = 1;
    ::safe_browsing::MalwarePatternType_PATTERN_TYPE pattern_type() const;
    void set_pattern_type(::safe_browsing::MalwarePatternType_PATTERN_TYPE value);

    // @@protoc_insertion_point(class_scope:safe_browsing.MalwarePatternType)
private:
    inline void set_has_pattern_type();
    inline void clear_has_pattern_type();

    ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
    ::google::protobuf::Arena* _arena_ptr_;

    ::google::protobuf::uint32 _has_bits_[1];
    mutable int _cached_size_;
    int pattern_type_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    friend void protobuf_AddDesc_metadata_2eproto_impl();
#else
    friend void protobuf_AddDesc_metadata_2eproto();
#endif
    friend void protobuf_AssignDesc_metadata_2eproto();
    friend void protobuf_ShutdownFile_metadata_2eproto();

    void InitAsDefaultInstance();
    static MalwarePatternType* default_instance_;
};
// -------------------------------------------------------------------

class SocialEngineeringPatternType : public ::google::protobuf::MessageLite {
public:
    SocialEngineeringPatternType();
    virtual ~SocialEngineeringPatternType();

    SocialEngineeringPatternType(const SocialEngineeringPatternType& from);

    inline SocialEngineeringPatternType& operator=(const SocialEngineeringPatternType& from)
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

    static const SocialEngineeringPatternType& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    // Returns the internal default instance pointer. This function can
    // return NULL thus should not be used by the user. This is intended
    // for Protobuf internal code. Please use default_instance() declared
    // above instead.
    static inline const SocialEngineeringPatternType* internal_default_instance()
    {
        return default_instance_;
    }
#endif

    GOOGLE_ATTRIBUTE_NOINLINE void Swap(SocialEngineeringPatternType* other);

    // implements Message ----------------------------------------------

    inline SocialEngineeringPatternType* New() const { return New(NULL); }

    SocialEngineeringPatternType* New(::google::protobuf::Arena* arena) const;
    void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
    void CopyFrom(const SocialEngineeringPatternType& from);
    void MergeFrom(const SocialEngineeringPatternType& from);
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
    void InternalSwap(SocialEngineeringPatternType* other);

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

    typedef SocialEngineeringPatternType_PATTERN_TYPE PATTERN_TYPE;
    static const PATTERN_TYPE TYPE_UNSPECIFIED = SocialEngineeringPatternType_PATTERN_TYPE_TYPE_UNSPECIFIED;
    static const PATTERN_TYPE SOCIAL_ENGINEERING_ADS = SocialEngineeringPatternType_PATTERN_TYPE_SOCIAL_ENGINEERING_ADS;
    static const PATTERN_TYPE SOCIAL_ENGINEERING_LANDING = SocialEngineeringPatternType_PATTERN_TYPE_SOCIAL_ENGINEERING_LANDING;
    static const PATTERN_TYPE PHISHING = SocialEngineeringPatternType_PATTERN_TYPE_PHISHING;
    static inline bool PATTERN_TYPE_IsValid(int value)
    {
        return SocialEngineeringPatternType_PATTERN_TYPE_IsValid(value);
    }
    static const PATTERN_TYPE PATTERN_TYPE_MIN = SocialEngineeringPatternType_PATTERN_TYPE_PATTERN_TYPE_MIN;
    static const PATTERN_TYPE PATTERN_TYPE_MAX = SocialEngineeringPatternType_PATTERN_TYPE_PATTERN_TYPE_MAX;
    static const int PATTERN_TYPE_ARRAYSIZE = SocialEngineeringPatternType_PATTERN_TYPE_PATTERN_TYPE_ARRAYSIZE;

    // accessors -------------------------------------------------------

    // optional .safe_browsing.SocialEngineeringPatternType.PATTERN_TYPE pattern_type = 1;
    bool has_pattern_type() const;
    void clear_pattern_type();
    static const int kPatternTypeFieldNumber = 1;
    ::safe_browsing::SocialEngineeringPatternType_PATTERN_TYPE pattern_type() const;
    void set_pattern_type(::safe_browsing::SocialEngineeringPatternType_PATTERN_TYPE value);

    // @@protoc_insertion_point(class_scope:safe_browsing.SocialEngineeringPatternType)
private:
    inline void set_has_pattern_type();
    inline void clear_has_pattern_type();

    ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
    ::google::protobuf::Arena* _arena_ptr_;

    ::google::protobuf::uint32 _has_bits_[1];
    mutable int _cached_size_;
    int pattern_type_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
    friend void protobuf_AddDesc_metadata_2eproto_impl();
#else
    friend void protobuf_AddDesc_metadata_2eproto();
#endif
    friend void protobuf_AssignDesc_metadata_2eproto();
    friend void protobuf_ShutdownFile_metadata_2eproto();

    void InitAsDefaultInstance();
    static SocialEngineeringPatternType* default_instance_;
};
// ===================================================================

// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// MalwarePatternType

// required .safe_browsing.MalwarePatternType.PATTERN_TYPE pattern_type = 1;
inline bool MalwarePatternType::has_pattern_type() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MalwarePatternType::set_has_pattern_type()
{
    _has_bits_[0] |= 0x00000001u;
}
inline void MalwarePatternType::clear_has_pattern_type()
{
    _has_bits_[0] &= ~0x00000001u;
}
inline void MalwarePatternType::clear_pattern_type()
{
    pattern_type_ = 0;
    clear_has_pattern_type();
}
inline ::safe_browsing::MalwarePatternType_PATTERN_TYPE MalwarePatternType::pattern_type() const
{
    // @@protoc_insertion_point(field_get:safe_browsing.MalwarePatternType.pattern_type)
    return static_cast<::safe_browsing::MalwarePatternType_PATTERN_TYPE>(pattern_type_);
}
inline void MalwarePatternType::set_pattern_type(::safe_browsing::MalwarePatternType_PATTERN_TYPE value)
{
    assert(::safe_browsing::MalwarePatternType_PATTERN_TYPE_IsValid(value));
    set_has_pattern_type();
    pattern_type_ = value;
    // @@protoc_insertion_point(field_set:safe_browsing.MalwarePatternType.pattern_type)
}

// -------------------------------------------------------------------

// SocialEngineeringPatternType

// optional .safe_browsing.SocialEngineeringPatternType.PATTERN_TYPE pattern_type = 1;
inline bool SocialEngineeringPatternType::has_pattern_type() const
{
    return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SocialEngineeringPatternType::set_has_pattern_type()
{
    _has_bits_[0] |= 0x00000001u;
}
inline void SocialEngineeringPatternType::clear_has_pattern_type()
{
    _has_bits_[0] &= ~0x00000001u;
}
inline void SocialEngineeringPatternType::clear_pattern_type()
{
    pattern_type_ = 0;
    clear_has_pattern_type();
}
inline ::safe_browsing::SocialEngineeringPatternType_PATTERN_TYPE SocialEngineeringPatternType::pattern_type() const
{
    // @@protoc_insertion_point(field_get:safe_browsing.SocialEngineeringPatternType.pattern_type)
    return static_cast<::safe_browsing::SocialEngineeringPatternType_PATTERN_TYPE>(pattern_type_);
}
inline void SocialEngineeringPatternType::set_pattern_type(::safe_browsing::SocialEngineeringPatternType_PATTERN_TYPE value)
{
    assert(::safe_browsing::SocialEngineeringPatternType_PATTERN_TYPE_IsValid(value));
    set_has_pattern_type();
    pattern_type_ = value;
    // @@protoc_insertion_point(field_set:safe_browsing.SocialEngineeringPatternType.pattern_type)
}

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// @@protoc_insertion_point(namespace_scope)

} // namespace safe_browsing

#ifndef SWIG
namespace google {
namespace protobuf {

    template <>
    struct is_proto_enum<::safe_browsing::MalwarePatternType_PATTERN_TYPE> : ::google::protobuf::internal::true_type {
    };
    template <>
    struct is_proto_enum<::safe_browsing::SocialEngineeringPatternType_PATTERN_TYPE> : ::google::protobuf::internal::true_type {
    };

} // namespace protobuf
} // namespace google
#endif // SWIG

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_metadata_2eproto__INCLUDED
