// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_MOJO_COMPOSITOR_FRAME_SINK_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_MOJO_COMPOSITOR_FRAME_SINK_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "cc/ipc/begin_frame_args.mojom-shared-internal.h"
#include "cc/ipc/compositor_frame.mojom-shared-internal.h"
#include "cc/ipc/frame_sink_id.mojom-shared-internal.h"
#include "cc/ipc/local_frame_id.mojom-shared-internal.h"
#include "cc/ipc/returned_resource.mojom-shared-internal.h"
#include "cc/ipc/surface_reference.mojom-shared-internal.h"
#include "cc/ipc/surface_sequence.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace cc {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kMojoCompositorFrameSink_SetNeedsBeginFrame_Name = 0;
        class MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data {
        public:
            static MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data))) MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t needs_begin_frame : 1;
            uint8_t padfinal_[7];

        private:
            MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data() = delete;
        };
        static_assert(sizeof(MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data) == 16,
            "Bad sizeof(MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data)");
        constexpr uint32_t kMojoCompositorFrameSink_SubmitCompositorFrame_Name = 1;
        class MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data {
        public:
            static MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data))) MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::LocalFrameId_Data> local_frame_id;
            mojo::internal::Pointer<::cc::mojom::internal::CompositorFrame_Data> frame;

        private:
            MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data() = delete;
        };
        static_assert(sizeof(MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data) == 24,
            "Bad sizeof(MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data)");
        constexpr uint32_t kMojoCompositorFrameSink_EvictFrame_Name = 2;
        class MojoCompositorFrameSink_EvictFrame_Params_Data {
        public:
            static MojoCompositorFrameSink_EvictFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MojoCompositorFrameSink_EvictFrame_Params_Data))) MojoCompositorFrameSink_EvictFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            MojoCompositorFrameSink_EvictFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MojoCompositorFrameSink_EvictFrame_Params_Data() = delete;
        };
        static_assert(sizeof(MojoCompositorFrameSink_EvictFrame_Params_Data) == 8,
            "Bad sizeof(MojoCompositorFrameSink_EvictFrame_Params_Data)");
        constexpr uint32_t kMojoCompositorFrameSink_Require_Name = 3;
        class MojoCompositorFrameSink_Require_Params_Data {
        public:
            static MojoCompositorFrameSink_Require_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MojoCompositorFrameSink_Require_Params_Data))) MojoCompositorFrameSink_Require_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::LocalFrameId_Data> local_frame_id;
            mojo::internal::Pointer<::cc::mojom::internal::SurfaceSequence_Data> sequence;

        private:
            MojoCompositorFrameSink_Require_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MojoCompositorFrameSink_Require_Params_Data() = delete;
        };
        static_assert(sizeof(MojoCompositorFrameSink_Require_Params_Data) == 24,
            "Bad sizeof(MojoCompositorFrameSink_Require_Params_Data)");
        constexpr uint32_t kMojoCompositorFrameSink_Satisfy_Name = 4;
        class MojoCompositorFrameSink_Satisfy_Params_Data {
        public:
            static MojoCompositorFrameSink_Satisfy_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MojoCompositorFrameSink_Satisfy_Params_Data))) MojoCompositorFrameSink_Satisfy_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::SurfaceSequence_Data> sequence;

        private:
            MojoCompositorFrameSink_Satisfy_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MojoCompositorFrameSink_Satisfy_Params_Data() = delete;
        };
        static_assert(sizeof(MojoCompositorFrameSink_Satisfy_Params_Data) == 16,
            "Bad sizeof(MojoCompositorFrameSink_Satisfy_Params_Data)");
        constexpr uint32_t kMojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Name = 0;
        class MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data {
        public:
            static MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data))) MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data() = delete;
        };
        static_assert(sizeof(MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data) == 8,
            "Bad sizeof(MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data)");
        constexpr uint32_t kMojoCompositorFrameSinkClient_OnBeginFrame_Name = 1;
        class MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data {
        public:
            static MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data))) MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::BeginFrameArgs_Data> args;

        private:
            MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data() = delete;
        };
        static_assert(sizeof(MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data) == 16,
            "Bad sizeof(MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data)");
        constexpr uint32_t kMojoCompositorFrameSinkClient_ReclaimResources_Name = 2;
        class MojoCompositorFrameSinkClient_ReclaimResources_Params_Data {
        public:
            static MojoCompositorFrameSinkClient_ReclaimResources_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MojoCompositorFrameSinkClient_ReclaimResources_Params_Data))) MojoCompositorFrameSinkClient_ReclaimResources_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::ReturnedResourceArray_Data> resources;

        private:
            MojoCompositorFrameSinkClient_ReclaimResources_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MojoCompositorFrameSinkClient_ReclaimResources_Params_Data() = delete;
        };
        static_assert(sizeof(MojoCompositorFrameSinkClient_ReclaimResources_Params_Data) == 16,
            "Bad sizeof(MojoCompositorFrameSinkClient_ReclaimResources_Params_Data)");
        constexpr uint32_t kMojoCompositorFrameSinkClient_WillDrawSurface_Name = 3;
        class MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data {
        public:
            static MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data))) MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data() = delete;
        };
        static_assert(sizeof(MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data) == 8,
            "Bad sizeof(MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data)");
        constexpr uint32_t kMojoCompositorFrameSinkPrivate_AddChildFrameSink_Name = 0;
        class MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data {
        public:
            static MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data))) MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::FrameSinkId_Data> child_frame_sink_id;

        private:
            MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data() = delete;
        };
        static_assert(sizeof(MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data) == 16,
            "Bad sizeof(MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data)");
        constexpr uint32_t kMojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Name = 1;
        class MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data {
        public:
            static MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data))) MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::FrameSinkId_Data> child_frame_sink_id;

        private:
            MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data() = delete;
        };
        static_assert(sizeof(MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data) == 16,
            "Bad sizeof(MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_MOJO_COMPOSITOR_FRAME_SINK_MOJOM_SHARED_INTERNAL_H_