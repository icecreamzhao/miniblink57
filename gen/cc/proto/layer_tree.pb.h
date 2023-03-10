// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: layer_tree.proto

#ifndef PROTOBUF_layer_5ftree_2eproto__INCLUDED
#define PROTOBUF_layer_5ftree_2eproto__INCLUDED

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

#include "layer.pb.h"
#include "layer_selection_bound.pb.h"
#include "size.pb.h"
#include "vector2df.pb.h"
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
// @@protoc_insertion_point(includes)
#include "cc/proto/cc_proto_export.h"

namespace cc {
namespace proto {

    // Internal implementation detail -- do not call these.
    void CC_PROTO_EXPORT protobuf_AddDesc_layer_5ftree_2eproto();
    void protobuf_AssignDesc_layer_5ftree_2eproto();
    void protobuf_ShutdownFile_layer_5ftree_2eproto();

    class LayerTree;

    // ===================================================================

    class CC_PROTO_EXPORT LayerTree : public ::google::protobuf::MessageLite {
    public:
        LayerTree();
        virtual ~LayerTree();

        LayerTree(const LayerTree& from);

        inline LayerTree& operator=(const LayerTree& from)
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

        static const LayerTree& default_instance();

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        // Returns the internal default instance pointer. This function can
        // return NULL thus should not be used by the user. This is intended
        // for Protobuf internal code. Please use default_instance() declared
        // above instead.
        static inline const LayerTree* internal_default_instance()
        {
            return default_instance_;
        }
#endif

        GOOGLE_ATTRIBUTE_NOINLINE void Swap(LayerTree* other);

        // implements Message ----------------------------------------------

        inline LayerTree* New() const { return New(NULL); }

        LayerTree* New(::google::protobuf::Arena* arena) const;
        void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
        void CopyFrom(const LayerTree& from);
        void MergeFrom(const LayerTree& from);
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
        void InternalSwap(LayerTree* other);

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

        // optional .cc.proto.LayerNode root_layer = 27;
        bool has_root_layer() const;
        void clear_root_layer();
        static const int kRootLayerFieldNumber = 27;
        const ::cc::proto::LayerNode& root_layer() const;
        ::cc::proto::LayerNode* mutable_root_layer();
        ::cc::proto::LayerNode* release_root_layer();
        void set_allocated_root_layer(::cc::proto::LayerNode* root_layer);

        // optional int32 overscroll_elasticity_layer_id = 3;
        bool has_overscroll_elasticity_layer_id() const;
        void clear_overscroll_elasticity_layer_id();
        static const int kOverscrollElasticityLayerIdFieldNumber = 3;
        ::google::protobuf::int32 overscroll_elasticity_layer_id() const;
        void set_overscroll_elasticity_layer_id(::google::protobuf::int32 value);

        // optional int32 page_scale_layer_id = 4;
        bool has_page_scale_layer_id() const;
        void clear_page_scale_layer_id();
        static const int kPageScaleLayerIdFieldNumber = 4;
        ::google::protobuf::int32 page_scale_layer_id() const;
        void set_page_scale_layer_id(::google::protobuf::int32 value);

        // optional int32 inner_viewport_scroll_layer_id = 5;
        bool has_inner_viewport_scroll_layer_id() const;
        void clear_inner_viewport_scroll_layer_id();
        static const int kInnerViewportScrollLayerIdFieldNumber = 5;
        ::google::protobuf::int32 inner_viewport_scroll_layer_id() const;
        void set_inner_viewport_scroll_layer_id(::google::protobuf::int32 value);

        // optional int32 outer_viewport_scroll_layer_id = 6;
        bool has_outer_viewport_scroll_layer_id() const;
        void clear_outer_viewport_scroll_layer_id();
        static const int kOuterViewportScrollLayerIdFieldNumber = 6;
        ::google::protobuf::int32 outer_viewport_scroll_layer_id() const;
        void set_outer_viewport_scroll_layer_id(::google::protobuf::int32 value);

        // optional float device_scale_factor = 13;
        bool has_device_scale_factor() const;
        void clear_device_scale_factor();
        static const int kDeviceScaleFactorFieldNumber = 13;
        float device_scale_factor() const;
        void set_device_scale_factor(float value);

        // optional float painted_device_scale_factor = 14;
        bool has_painted_device_scale_factor() const;
        void clear_painted_device_scale_factor();
        static const int kPaintedDeviceScaleFactorFieldNumber = 14;
        float painted_device_scale_factor() const;
        void set_painted_device_scale_factor(float value);

        // optional float page_scale_factor = 15;
        bool has_page_scale_factor() const;
        void clear_page_scale_factor();
        static const int kPageScaleFactorFieldNumber = 15;
        float page_scale_factor() const;
        void set_page_scale_factor(float value);

        // optional float min_page_scale_factor = 16;
        bool has_min_page_scale_factor() const;
        void clear_min_page_scale_factor();
        static const int kMinPageScaleFactorFieldNumber = 16;
        float min_page_scale_factor() const;
        void set_min_page_scale_factor(float value);

        // optional float max_page_scale_factor = 17;
        bool has_max_page_scale_factor() const;
        void clear_max_page_scale_factor();
        static const int kMaxPageScaleFactorFieldNumber = 17;
        float max_page_scale_factor() const;
        void set_max_page_scale_factor(float value);

        // optional uint32 background_color = 21;
        bool has_background_color() const;
        void clear_background_color();
        static const int kBackgroundColorFieldNumber = 21;
        ::google::protobuf::uint32 background_color() const;
        void set_background_color(::google::protobuf::uint32 value);

        // optional bool has_transparent_background = 22;
        bool has_has_transparent_background() const;
        void clear_has_transparent_background();
        static const int kHasTransparentBackgroundFieldNumber = 22;
        bool has_transparent_background() const;
        void set_has_transparent_background(bool value);

        // optional .cc.proto.LayerSelection selection = 29;
        bool has_selection() const;
        void clear_selection();
        static const int kSelectionFieldNumber = 29;
        const ::cc::proto::LayerSelection& selection() const;
        ::cc::proto::LayerSelection* mutable_selection();
        ::cc::proto::LayerSelection* release_selection();
        void set_allocated_selection(::cc::proto::LayerSelection* selection);

        // optional .cc.proto.Size device_viewport_size = 18;
        bool has_device_viewport_size() const;
        void clear_device_viewport_size();
        static const int kDeviceViewportSizeFieldNumber = 18;
        const ::cc::proto::Size& device_viewport_size() const;
        ::cc::proto::Size* mutable_device_viewport_size();
        ::cc::proto::Size* release_device_viewport_size();
        void set_allocated_device_viewport_size(::cc::proto::Size* device_viewport_size);

        // optional bool have_scroll_event_handlers = 23;
        bool has_have_scroll_event_handlers() const;
        void clear_have_scroll_event_handlers();
        static const int kHaveScrollEventHandlersFieldNumber = 23;
        bool have_scroll_event_handlers() const;
        void set_have_scroll_event_handlers(bool value);

        // optional uint32 touch_start_or_move_event_listener_properties = 24;
        bool has_touch_start_or_move_event_listener_properties() const;
        void clear_touch_start_or_move_event_listener_properties();
        static const int kTouchStartOrMoveEventListenerPropertiesFieldNumber = 24;
        ::google::protobuf::uint32 touch_start_or_move_event_listener_properties() const;
        void set_touch_start_or_move_event_listener_properties(::google::protobuf::uint32 value);

        // optional uint32 wheel_event_listener_properties = 25;
        bool has_wheel_event_listener_properties() const;
        void clear_wheel_event_listener_properties();
        static const int kWheelEventListenerPropertiesFieldNumber = 25;
        ::google::protobuf::uint32 wheel_event_listener_properties() const;
        void set_wheel_event_listener_properties(::google::protobuf::uint32 value);

        // optional uint32 touch_end_or_cancel_event_listener_properties = 26;
        bool has_touch_end_or_cancel_event_listener_properties() const;
        void clear_touch_end_or_cancel_event_listener_properties();
        static const int kTouchEndOrCancelEventListenerPropertiesFieldNumber = 26;
        ::google::protobuf::uint32 touch_end_or_cancel_event_listener_properties() const;
        void set_touch_end_or_cancel_event_listener_properties(::google::protobuf::uint32 value);

        // @@protoc_insertion_point(class_scope:cc.proto.LayerTree)
    private:
        inline void set_has_root_layer();
        inline void clear_has_root_layer();
        inline void set_has_overscroll_elasticity_layer_id();
        inline void clear_has_overscroll_elasticity_layer_id();
        inline void set_has_page_scale_layer_id();
        inline void clear_has_page_scale_layer_id();
        inline void set_has_inner_viewport_scroll_layer_id();
        inline void clear_has_inner_viewport_scroll_layer_id();
        inline void set_has_outer_viewport_scroll_layer_id();
        inline void clear_has_outer_viewport_scroll_layer_id();
        inline void set_has_device_scale_factor();
        inline void clear_has_device_scale_factor();
        inline void set_has_painted_device_scale_factor();
        inline void clear_has_painted_device_scale_factor();
        inline void set_has_page_scale_factor();
        inline void clear_has_page_scale_factor();
        inline void set_has_min_page_scale_factor();
        inline void clear_has_min_page_scale_factor();
        inline void set_has_max_page_scale_factor();
        inline void clear_has_max_page_scale_factor();
        inline void set_has_background_color();
        inline void clear_has_background_color();
        inline void set_has_has_transparent_background();
        inline void clear_has_has_transparent_background();
        inline void set_has_selection();
        inline void clear_has_selection();
        inline void set_has_device_viewport_size();
        inline void clear_has_device_viewport_size();
        inline void set_has_have_scroll_event_handlers();
        inline void clear_has_have_scroll_event_handlers();
        inline void set_has_touch_start_or_move_event_listener_properties();
        inline void clear_has_touch_start_or_move_event_listener_properties();
        inline void set_has_wheel_event_listener_properties();
        inline void clear_has_wheel_event_listener_properties();
        inline void set_has_touch_end_or_cancel_event_listener_properties();
        inline void clear_has_touch_end_or_cancel_event_listener_properties();

        ::google::protobuf::internal::ArenaStringPtr _unknown_fields_;
        ::google::protobuf::Arena* _arena_ptr_;

        ::google::protobuf::uint32 _has_bits_[1];
        mutable int _cached_size_;
        ::cc::proto::LayerNode* root_layer_;
        ::google::protobuf::int32 overscroll_elasticity_layer_id_;
        ::google::protobuf::int32 page_scale_layer_id_;
        ::google::protobuf::int32 inner_viewport_scroll_layer_id_;
        ::google::protobuf::int32 outer_viewport_scroll_layer_id_;
        float device_scale_factor_;
        float painted_device_scale_factor_;
        float page_scale_factor_;
        float min_page_scale_factor_;
        float max_page_scale_factor_;
        ::google::protobuf::uint32 background_color_;
        ::cc::proto::LayerSelection* selection_;
        ::cc::proto::Size* device_viewport_size_;
        bool has_transparent_background_;
        bool have_scroll_event_handlers_;
        ::google::protobuf::uint32 touch_start_or_move_event_listener_properties_;
        ::google::protobuf::uint32 wheel_event_listener_properties_;
        ::google::protobuf::uint32 touch_end_or_cancel_event_listener_properties_;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        friend void CC_PROTO_EXPORT protobuf_AddDesc_layer_5ftree_2eproto_impl();
#else
        friend void CC_PROTO_EXPORT protobuf_AddDesc_layer_5ftree_2eproto();
#endif
        friend void protobuf_AssignDesc_layer_5ftree_2eproto();
        friend void protobuf_ShutdownFile_layer_5ftree_2eproto();

        void InitAsDefaultInstance();
        static LayerTree* default_instance_;
    };
    // ===================================================================

    // ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
    // LayerTree

    // optional .cc.proto.LayerNode root_layer = 27;
    inline bool LayerTree::has_root_layer() const
    {
        return (_has_bits_[0] & 0x00000001u) != 0;
    }
    inline void LayerTree::set_has_root_layer()
    {
        _has_bits_[0] |= 0x00000001u;
    }
    inline void LayerTree::clear_has_root_layer()
    {
        _has_bits_[0] &= ~0x00000001u;
    }
    inline void LayerTree::clear_root_layer()
    {
        if (root_layer_ != NULL)
            root_layer_->::cc::proto::LayerNode::Clear();
        clear_has_root_layer();
    }
    inline const ::cc::proto::LayerNode& LayerTree::root_layer() const
    {
// @@protoc_insertion_point(field_get:cc.proto.LayerTree.root_layer)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        return root_layer_ != NULL ? *root_layer_ : *default_instance().root_layer_;
#else
        return root_layer_ != NULL ? *root_layer_ : *default_instance_->root_layer_;
#endif
    }
    inline ::cc::proto::LayerNode* LayerTree::mutable_root_layer()
    {
        set_has_root_layer();
        if (root_layer_ == NULL) {
            root_layer_ = new ::cc::proto::LayerNode;
        }
        // @@protoc_insertion_point(field_mutable:cc.proto.LayerTree.root_layer)
        return root_layer_;
    }
    inline ::cc::proto::LayerNode* LayerTree::release_root_layer()
    {
        // @@protoc_insertion_point(field_release:cc.proto.LayerTree.root_layer)
        clear_has_root_layer();
        ::cc::proto::LayerNode* temp = root_layer_;
        root_layer_ = NULL;
        return temp;
    }
    inline void LayerTree::set_allocated_root_layer(::cc::proto::LayerNode* root_layer)
    {
        delete root_layer_;
        root_layer_ = root_layer;
        if (root_layer) {
            set_has_root_layer();
        } else {
            clear_has_root_layer();
        }
        // @@protoc_insertion_point(field_set_allocated:cc.proto.LayerTree.root_layer)
    }

    // optional int32 overscroll_elasticity_layer_id = 3;
    inline bool LayerTree::has_overscroll_elasticity_layer_id() const
    {
        return (_has_bits_[0] & 0x00000002u) != 0;
    }
    inline void LayerTree::set_has_overscroll_elasticity_layer_id()
    {
        _has_bits_[0] |= 0x00000002u;
    }
    inline void LayerTree::clear_has_overscroll_elasticity_layer_id()
    {
        _has_bits_[0] &= ~0x00000002u;
    }
    inline void LayerTree::clear_overscroll_elasticity_layer_id()
    {
        overscroll_elasticity_layer_id_ = 0;
        clear_has_overscroll_elasticity_layer_id();
    }
    inline ::google::protobuf::int32 LayerTree::overscroll_elasticity_layer_id() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.overscroll_elasticity_layer_id)
        return overscroll_elasticity_layer_id_;
    }
    inline void LayerTree::set_overscroll_elasticity_layer_id(::google::protobuf::int32 value)
    {
        set_has_overscroll_elasticity_layer_id();
        overscroll_elasticity_layer_id_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.overscroll_elasticity_layer_id)
    }

    // optional int32 page_scale_layer_id = 4;
    inline bool LayerTree::has_page_scale_layer_id() const
    {
        return (_has_bits_[0] & 0x00000004u) != 0;
    }
    inline void LayerTree::set_has_page_scale_layer_id()
    {
        _has_bits_[0] |= 0x00000004u;
    }
    inline void LayerTree::clear_has_page_scale_layer_id()
    {
        _has_bits_[0] &= ~0x00000004u;
    }
    inline void LayerTree::clear_page_scale_layer_id()
    {
        page_scale_layer_id_ = 0;
        clear_has_page_scale_layer_id();
    }
    inline ::google::protobuf::int32 LayerTree::page_scale_layer_id() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.page_scale_layer_id)
        return page_scale_layer_id_;
    }
    inline void LayerTree::set_page_scale_layer_id(::google::protobuf::int32 value)
    {
        set_has_page_scale_layer_id();
        page_scale_layer_id_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.page_scale_layer_id)
    }

    // optional int32 inner_viewport_scroll_layer_id = 5;
    inline bool LayerTree::has_inner_viewport_scroll_layer_id() const
    {
        return (_has_bits_[0] & 0x00000008u) != 0;
    }
    inline void LayerTree::set_has_inner_viewport_scroll_layer_id()
    {
        _has_bits_[0] |= 0x00000008u;
    }
    inline void LayerTree::clear_has_inner_viewport_scroll_layer_id()
    {
        _has_bits_[0] &= ~0x00000008u;
    }
    inline void LayerTree::clear_inner_viewport_scroll_layer_id()
    {
        inner_viewport_scroll_layer_id_ = 0;
        clear_has_inner_viewport_scroll_layer_id();
    }
    inline ::google::protobuf::int32 LayerTree::inner_viewport_scroll_layer_id() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.inner_viewport_scroll_layer_id)
        return inner_viewport_scroll_layer_id_;
    }
    inline void LayerTree::set_inner_viewport_scroll_layer_id(::google::protobuf::int32 value)
    {
        set_has_inner_viewport_scroll_layer_id();
        inner_viewport_scroll_layer_id_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.inner_viewport_scroll_layer_id)
    }

    // optional int32 outer_viewport_scroll_layer_id = 6;
    inline bool LayerTree::has_outer_viewport_scroll_layer_id() const
    {
        return (_has_bits_[0] & 0x00000010u) != 0;
    }
    inline void LayerTree::set_has_outer_viewport_scroll_layer_id()
    {
        _has_bits_[0] |= 0x00000010u;
    }
    inline void LayerTree::clear_has_outer_viewport_scroll_layer_id()
    {
        _has_bits_[0] &= ~0x00000010u;
    }
    inline void LayerTree::clear_outer_viewport_scroll_layer_id()
    {
        outer_viewport_scroll_layer_id_ = 0;
        clear_has_outer_viewport_scroll_layer_id();
    }
    inline ::google::protobuf::int32 LayerTree::outer_viewport_scroll_layer_id() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.outer_viewport_scroll_layer_id)
        return outer_viewport_scroll_layer_id_;
    }
    inline void LayerTree::set_outer_viewport_scroll_layer_id(::google::protobuf::int32 value)
    {
        set_has_outer_viewport_scroll_layer_id();
        outer_viewport_scroll_layer_id_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.outer_viewport_scroll_layer_id)
    }

    // optional float device_scale_factor = 13;
    inline bool LayerTree::has_device_scale_factor() const
    {
        return (_has_bits_[0] & 0x00000020u) != 0;
    }
    inline void LayerTree::set_has_device_scale_factor()
    {
        _has_bits_[0] |= 0x00000020u;
    }
    inline void LayerTree::clear_has_device_scale_factor()
    {
        _has_bits_[0] &= ~0x00000020u;
    }
    inline void LayerTree::clear_device_scale_factor()
    {
        device_scale_factor_ = 0;
        clear_has_device_scale_factor();
    }
    inline float LayerTree::device_scale_factor() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.device_scale_factor)
        return device_scale_factor_;
    }
    inline void LayerTree::set_device_scale_factor(float value)
    {
        set_has_device_scale_factor();
        device_scale_factor_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.device_scale_factor)
    }

    // optional float painted_device_scale_factor = 14;
    inline bool LayerTree::has_painted_device_scale_factor() const
    {
        return (_has_bits_[0] & 0x00000040u) != 0;
    }
    inline void LayerTree::set_has_painted_device_scale_factor()
    {
        _has_bits_[0] |= 0x00000040u;
    }
    inline void LayerTree::clear_has_painted_device_scale_factor()
    {
        _has_bits_[0] &= ~0x00000040u;
    }
    inline void LayerTree::clear_painted_device_scale_factor()
    {
        painted_device_scale_factor_ = 0;
        clear_has_painted_device_scale_factor();
    }
    inline float LayerTree::painted_device_scale_factor() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.painted_device_scale_factor)
        return painted_device_scale_factor_;
    }
    inline void LayerTree::set_painted_device_scale_factor(float value)
    {
        set_has_painted_device_scale_factor();
        painted_device_scale_factor_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.painted_device_scale_factor)
    }

    // optional float page_scale_factor = 15;
    inline bool LayerTree::has_page_scale_factor() const
    {
        return (_has_bits_[0] & 0x00000080u) != 0;
    }
    inline void LayerTree::set_has_page_scale_factor()
    {
        _has_bits_[0] |= 0x00000080u;
    }
    inline void LayerTree::clear_has_page_scale_factor()
    {
        _has_bits_[0] &= ~0x00000080u;
    }
    inline void LayerTree::clear_page_scale_factor()
    {
        page_scale_factor_ = 0;
        clear_has_page_scale_factor();
    }
    inline float LayerTree::page_scale_factor() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.page_scale_factor)
        return page_scale_factor_;
    }
    inline void LayerTree::set_page_scale_factor(float value)
    {
        set_has_page_scale_factor();
        page_scale_factor_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.page_scale_factor)
    }

    // optional float min_page_scale_factor = 16;
    inline bool LayerTree::has_min_page_scale_factor() const
    {
        return (_has_bits_[0] & 0x00000100u) != 0;
    }
    inline void LayerTree::set_has_min_page_scale_factor()
    {
        _has_bits_[0] |= 0x00000100u;
    }
    inline void LayerTree::clear_has_min_page_scale_factor()
    {
        _has_bits_[0] &= ~0x00000100u;
    }
    inline void LayerTree::clear_min_page_scale_factor()
    {
        min_page_scale_factor_ = 0;
        clear_has_min_page_scale_factor();
    }
    inline float LayerTree::min_page_scale_factor() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.min_page_scale_factor)
        return min_page_scale_factor_;
    }
    inline void LayerTree::set_min_page_scale_factor(float value)
    {
        set_has_min_page_scale_factor();
        min_page_scale_factor_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.min_page_scale_factor)
    }

    // optional float max_page_scale_factor = 17;
    inline bool LayerTree::has_max_page_scale_factor() const
    {
        return (_has_bits_[0] & 0x00000200u) != 0;
    }
    inline void LayerTree::set_has_max_page_scale_factor()
    {
        _has_bits_[0] |= 0x00000200u;
    }
    inline void LayerTree::clear_has_max_page_scale_factor()
    {
        _has_bits_[0] &= ~0x00000200u;
    }
    inline void LayerTree::clear_max_page_scale_factor()
    {
        max_page_scale_factor_ = 0;
        clear_has_max_page_scale_factor();
    }
    inline float LayerTree::max_page_scale_factor() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.max_page_scale_factor)
        return max_page_scale_factor_;
    }
    inline void LayerTree::set_max_page_scale_factor(float value)
    {
        set_has_max_page_scale_factor();
        max_page_scale_factor_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.max_page_scale_factor)
    }

    // optional uint32 background_color = 21;
    inline bool LayerTree::has_background_color() const
    {
        return (_has_bits_[0] & 0x00000400u) != 0;
    }
    inline void LayerTree::set_has_background_color()
    {
        _has_bits_[0] |= 0x00000400u;
    }
    inline void LayerTree::clear_has_background_color()
    {
        _has_bits_[0] &= ~0x00000400u;
    }
    inline void LayerTree::clear_background_color()
    {
        background_color_ = 0u;
        clear_has_background_color();
    }
    inline ::google::protobuf::uint32 LayerTree::background_color() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.background_color)
        return background_color_;
    }
    inline void LayerTree::set_background_color(::google::protobuf::uint32 value)
    {
        set_has_background_color();
        background_color_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.background_color)
    }

    // optional bool has_transparent_background = 22;
    inline bool LayerTree::has_has_transparent_background() const
    {
        return (_has_bits_[0] & 0x00000800u) != 0;
    }
    inline void LayerTree::set_has_has_transparent_background()
    {
        _has_bits_[0] |= 0x00000800u;
    }
    inline void LayerTree::clear_has_has_transparent_background()
    {
        _has_bits_[0] &= ~0x00000800u;
    }
    inline void LayerTree::clear_has_transparent_background()
    {
        has_transparent_background_ = false;
        clear_has_has_transparent_background();
    }
    inline bool LayerTree::has_transparent_background() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.has_transparent_background)
        return has_transparent_background_;
    }
    inline void LayerTree::set_has_transparent_background(bool value)
    {
        set_has_has_transparent_background();
        has_transparent_background_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.has_transparent_background)
    }

    // optional .cc.proto.LayerSelection selection = 29;
    inline bool LayerTree::has_selection() const
    {
        return (_has_bits_[0] & 0x00001000u) != 0;
    }
    inline void LayerTree::set_has_selection()
    {
        _has_bits_[0] |= 0x00001000u;
    }
    inline void LayerTree::clear_has_selection()
    {
        _has_bits_[0] &= ~0x00001000u;
    }
    inline void LayerTree::clear_selection()
    {
        if (selection_ != NULL)
            selection_->::cc::proto::LayerSelection::Clear();
        clear_has_selection();
    }
    inline const ::cc::proto::LayerSelection& LayerTree::selection() const
    {
// @@protoc_insertion_point(field_get:cc.proto.LayerTree.selection)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        return selection_ != NULL ? *selection_ : *default_instance().selection_;
#else
        return selection_ != NULL ? *selection_ : *default_instance_->selection_;
#endif
    }
    inline ::cc::proto::LayerSelection* LayerTree::mutable_selection()
    {
        set_has_selection();
        if (selection_ == NULL) {
            selection_ = new ::cc::proto::LayerSelection;
        }
        // @@protoc_insertion_point(field_mutable:cc.proto.LayerTree.selection)
        return selection_;
    }
    inline ::cc::proto::LayerSelection* LayerTree::release_selection()
    {
        // @@protoc_insertion_point(field_release:cc.proto.LayerTree.selection)
        clear_has_selection();
        ::cc::proto::LayerSelection* temp = selection_;
        selection_ = NULL;
        return temp;
    }
    inline void LayerTree::set_allocated_selection(::cc::proto::LayerSelection* selection)
    {
        delete selection_;
        selection_ = selection;
        if (selection) {
            set_has_selection();
        } else {
            clear_has_selection();
        }
        // @@protoc_insertion_point(field_set_allocated:cc.proto.LayerTree.selection)
    }

    // optional .cc.proto.Size device_viewport_size = 18;
    inline bool LayerTree::has_device_viewport_size() const
    {
        return (_has_bits_[0] & 0x00002000u) != 0;
    }
    inline void LayerTree::set_has_device_viewport_size()
    {
        _has_bits_[0] |= 0x00002000u;
    }
    inline void LayerTree::clear_has_device_viewport_size()
    {
        _has_bits_[0] &= ~0x00002000u;
    }
    inline void LayerTree::clear_device_viewport_size()
    {
        if (device_viewport_size_ != NULL)
            device_viewport_size_->::cc::proto::Size::Clear();
        clear_has_device_viewport_size();
    }
    inline const ::cc::proto::Size& LayerTree::device_viewport_size() const
    {
// @@protoc_insertion_point(field_get:cc.proto.LayerTree.device_viewport_size)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
        return device_viewport_size_ != NULL ? *device_viewport_size_ : *default_instance().device_viewport_size_;
#else
        return device_viewport_size_ != NULL ? *device_viewport_size_ : *default_instance_->device_viewport_size_;
#endif
    }
    inline ::cc::proto::Size* LayerTree::mutable_device_viewport_size()
    {
        set_has_device_viewport_size();
        if (device_viewport_size_ == NULL) {
            device_viewport_size_ = new ::cc::proto::Size;
        }
        // @@protoc_insertion_point(field_mutable:cc.proto.LayerTree.device_viewport_size)
        return device_viewport_size_;
    }
    inline ::cc::proto::Size* LayerTree::release_device_viewport_size()
    {
        // @@protoc_insertion_point(field_release:cc.proto.LayerTree.device_viewport_size)
        clear_has_device_viewport_size();
        ::cc::proto::Size* temp = device_viewport_size_;
        device_viewport_size_ = NULL;
        return temp;
    }
    inline void LayerTree::set_allocated_device_viewport_size(::cc::proto::Size* device_viewport_size)
    {
        delete device_viewport_size_;
        device_viewport_size_ = device_viewport_size;
        if (device_viewport_size) {
            set_has_device_viewport_size();
        } else {
            clear_has_device_viewport_size();
        }
        // @@protoc_insertion_point(field_set_allocated:cc.proto.LayerTree.device_viewport_size)
    }

    // optional bool have_scroll_event_handlers = 23;
    inline bool LayerTree::has_have_scroll_event_handlers() const
    {
        return (_has_bits_[0] & 0x00004000u) != 0;
    }
    inline void LayerTree::set_has_have_scroll_event_handlers()
    {
        _has_bits_[0] |= 0x00004000u;
    }
    inline void LayerTree::clear_has_have_scroll_event_handlers()
    {
        _has_bits_[0] &= ~0x00004000u;
    }
    inline void LayerTree::clear_have_scroll_event_handlers()
    {
        have_scroll_event_handlers_ = false;
        clear_has_have_scroll_event_handlers();
    }
    inline bool LayerTree::have_scroll_event_handlers() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.have_scroll_event_handlers)
        return have_scroll_event_handlers_;
    }
    inline void LayerTree::set_have_scroll_event_handlers(bool value)
    {
        set_has_have_scroll_event_handlers();
        have_scroll_event_handlers_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.have_scroll_event_handlers)
    }

    // optional uint32 touch_start_or_move_event_listener_properties = 24;
    inline bool LayerTree::has_touch_start_or_move_event_listener_properties() const
    {
        return (_has_bits_[0] & 0x00008000u) != 0;
    }
    inline void LayerTree::set_has_touch_start_or_move_event_listener_properties()
    {
        _has_bits_[0] |= 0x00008000u;
    }
    inline void LayerTree::clear_has_touch_start_or_move_event_listener_properties()
    {
        _has_bits_[0] &= ~0x00008000u;
    }
    inline void LayerTree::clear_touch_start_or_move_event_listener_properties()
    {
        touch_start_or_move_event_listener_properties_ = 0u;
        clear_has_touch_start_or_move_event_listener_properties();
    }
    inline ::google::protobuf::uint32 LayerTree::touch_start_or_move_event_listener_properties() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.touch_start_or_move_event_listener_properties)
        return touch_start_or_move_event_listener_properties_;
    }
    inline void LayerTree::set_touch_start_or_move_event_listener_properties(::google::protobuf::uint32 value)
    {
        set_has_touch_start_or_move_event_listener_properties();
        touch_start_or_move_event_listener_properties_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.touch_start_or_move_event_listener_properties)
    }

    // optional uint32 wheel_event_listener_properties = 25;
    inline bool LayerTree::has_wheel_event_listener_properties() const
    {
        return (_has_bits_[0] & 0x00010000u) != 0;
    }
    inline void LayerTree::set_has_wheel_event_listener_properties()
    {
        _has_bits_[0] |= 0x00010000u;
    }
    inline void LayerTree::clear_has_wheel_event_listener_properties()
    {
        _has_bits_[0] &= ~0x00010000u;
    }
    inline void LayerTree::clear_wheel_event_listener_properties()
    {
        wheel_event_listener_properties_ = 0u;
        clear_has_wheel_event_listener_properties();
    }
    inline ::google::protobuf::uint32 LayerTree::wheel_event_listener_properties() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.wheel_event_listener_properties)
        return wheel_event_listener_properties_;
    }
    inline void LayerTree::set_wheel_event_listener_properties(::google::protobuf::uint32 value)
    {
        set_has_wheel_event_listener_properties();
        wheel_event_listener_properties_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.wheel_event_listener_properties)
    }

    // optional uint32 touch_end_or_cancel_event_listener_properties = 26;
    inline bool LayerTree::has_touch_end_or_cancel_event_listener_properties() const
    {
        return (_has_bits_[0] & 0x00020000u) != 0;
    }
    inline void LayerTree::set_has_touch_end_or_cancel_event_listener_properties()
    {
        _has_bits_[0] |= 0x00020000u;
    }
    inline void LayerTree::clear_has_touch_end_or_cancel_event_listener_properties()
    {
        _has_bits_[0] &= ~0x00020000u;
    }
    inline void LayerTree::clear_touch_end_or_cancel_event_listener_properties()
    {
        touch_end_or_cancel_event_listener_properties_ = 0u;
        clear_has_touch_end_or_cancel_event_listener_properties();
    }
    inline ::google::protobuf::uint32 LayerTree::touch_end_or_cancel_event_listener_properties() const
    {
        // @@protoc_insertion_point(field_get:cc.proto.LayerTree.touch_end_or_cancel_event_listener_properties)
        return touch_end_or_cancel_event_listener_properties_;
    }
    inline void LayerTree::set_touch_end_or_cancel_event_listener_properties(::google::protobuf::uint32 value)
    {
        set_has_touch_end_or_cancel_event_listener_properties();
        touch_end_or_cancel_event_listener_properties_ = value;
        // @@protoc_insertion_point(field_set:cc.proto.LayerTree.touch_end_or_cancel_event_listener_properties)
    }

#endif // !PROTOBUF_INLINE_NOT_IN_HEADERS

    // @@protoc_insertion_point(namespace_scope)

} // namespace proto
} // namespace cc

// @@protoc_insertion_point(global_scope)

#endif // PROTOBUF_layer_5ftree_2eproto__INCLUDED
