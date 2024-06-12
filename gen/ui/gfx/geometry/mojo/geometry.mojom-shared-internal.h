// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_SHARED_INTERNAL_H_
#define UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

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
namespace gfx {
namespace mojom {
    namespace internal {
        class Point_Data;
        class PointF_Data;
        class Size_Data;
        class SizeF_Data;
        class Rect_Data;
        class RectF_Data;
        class Insets_Data;
        class InsetsF_Data;
        class Vector2d_Data;
        class Vector2dF_Data;

#pragma pack(push, 1)
        class Point_Data {
        public:
            static Point_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Point_Data))) Point_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t x;
            int32_t y;

        private:
            Point_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Point_Data() = delete;
        };
        static_assert(sizeof(Point_Data) == 16,
            "Bad sizeof(Point_Data)");
        class PointF_Data {
        public:
            static PointF_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PointF_Data))) PointF_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float x;
            float y;

        private:
            PointF_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PointF_Data() = delete;
        };
        static_assert(sizeof(PointF_Data) == 16,
            "Bad sizeof(PointF_Data)");
        class Size_Data {
        public:
            static Size_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Size_Data))) Size_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t width;
            int32_t height;

        private:
            Size_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Size_Data() = delete;
        };
        static_assert(sizeof(Size_Data) == 16,
            "Bad sizeof(Size_Data)");
        class SizeF_Data {
        public:
            static SizeF_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SizeF_Data))) SizeF_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float width;
            float height;

        private:
            SizeF_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SizeF_Data() = delete;
        };
        static_assert(sizeof(SizeF_Data) == 16,
            "Bad sizeof(SizeF_Data)");
        class Rect_Data {
        public:
            static Rect_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Rect_Data))) Rect_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t x;
            int32_t y;
            int32_t width;
            int32_t height;

        private:
            Rect_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Rect_Data() = delete;
        };
        static_assert(sizeof(Rect_Data) == 24,
            "Bad sizeof(Rect_Data)");
        class RectF_Data {
        public:
            static RectF_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RectF_Data))) RectF_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float x;
            float y;
            float width;
            float height;

        private:
            RectF_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RectF_Data() = delete;
        };
        static_assert(sizeof(RectF_Data) == 24,
            "Bad sizeof(RectF_Data)");
        class Insets_Data {
        public:
            static Insets_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Insets_Data))) Insets_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t top;
            int32_t left;
            int32_t bottom;
            int32_t right;

        private:
            Insets_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Insets_Data() = delete;
        };
        static_assert(sizeof(Insets_Data) == 24,
            "Bad sizeof(Insets_Data)");
        class InsetsF_Data {
        public:
            static InsetsF_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InsetsF_Data))) InsetsF_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float top;
            float left;
            float bottom;
            float right;

        private:
            InsetsF_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InsetsF_Data() = delete;
        };
        static_assert(sizeof(InsetsF_Data) == 24,
            "Bad sizeof(InsetsF_Data)");
        class Vector2d_Data {
        public:
            static Vector2d_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Vector2d_Data))) Vector2d_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t x;
            int32_t y;

        private:
            Vector2d_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Vector2d_Data() = delete;
        };
        static_assert(sizeof(Vector2d_Data) == 16,
            "Bad sizeof(Vector2d_Data)");
        class Vector2dF_Data {
        public:
            static Vector2dF_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Vector2dF_Data))) Vector2dF_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float x;
            float y;

        private:
            Vector2dF_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Vector2dF_Data() = delete;
        };
        static_assert(sizeof(Vector2dF_Data) == 16,
            "Bad sizeof(Vector2dF_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace gfx

#endif // UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_SHARED_INTERNAL_H_