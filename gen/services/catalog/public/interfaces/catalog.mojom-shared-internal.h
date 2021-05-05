// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_CATALOG_PUBLIC_INTERFACES_CATALOG_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_CATALOG_PUBLIC_INTERFACES_CATALOG_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/common/file_path.mojom-shared-internal.h"
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
namespace catalog {
namespace mojom {
    namespace internal {
        class Entry_Data;

#pragma pack(push, 1)
        class Entry_Data {
        public:
            static Entry_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Entry_Data))) Entry_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<mojo::internal::String_Data> display_name;

        private:
            Entry_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Entry_Data() = delete;
        };
        static_assert(sizeof(Entry_Data) == 24,
            "Bad sizeof(Entry_Data)");
        constexpr uint32_t kCatalog_GetEntries_Name = 0;
        class Catalog_GetEntries_Params_Data {
        public:
            static Catalog_GetEntries_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Catalog_GetEntries_Params_Data))) Catalog_GetEntries_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> names;

        private:
            Catalog_GetEntries_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Catalog_GetEntries_Params_Data() = delete;
        };
        static_assert(sizeof(Catalog_GetEntries_Params_Data) == 16,
            "Bad sizeof(Catalog_GetEntries_Params_Data)");
        class Catalog_GetEntries_ResponseParams_Data {
        public:
            static Catalog_GetEntries_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Catalog_GetEntries_ResponseParams_Data))) Catalog_GetEntries_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::Entry_Data>>> entries;

        private:
            Catalog_GetEntries_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Catalog_GetEntries_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Catalog_GetEntries_ResponseParams_Data) == 16,
            "Bad sizeof(Catalog_GetEntries_ResponseParams_Data)");
        constexpr uint32_t kCatalog_GetEntriesProvidingCapability_Name = 1;
        class Catalog_GetEntriesProvidingCapability_Params_Data {
        public:
            static Catalog_GetEntriesProvidingCapability_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Catalog_GetEntriesProvidingCapability_Params_Data))) Catalog_GetEntriesProvidingCapability_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> capability;

        private:
            Catalog_GetEntriesProvidingCapability_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Catalog_GetEntriesProvidingCapability_Params_Data() = delete;
        };
        static_assert(sizeof(Catalog_GetEntriesProvidingCapability_Params_Data) == 16,
            "Bad sizeof(Catalog_GetEntriesProvidingCapability_Params_Data)");
        class Catalog_GetEntriesProvidingCapability_ResponseParams_Data {
        public:
            static Catalog_GetEntriesProvidingCapability_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Catalog_GetEntriesProvidingCapability_ResponseParams_Data))) Catalog_GetEntriesProvidingCapability_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::Entry_Data>>> entries;

        private:
            Catalog_GetEntriesProvidingCapability_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Catalog_GetEntriesProvidingCapability_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Catalog_GetEntriesProvidingCapability_ResponseParams_Data) == 16,
            "Bad sizeof(Catalog_GetEntriesProvidingCapability_ResponseParams_Data)");
        constexpr uint32_t kCatalog_GetEntriesConsumingMIMEType_Name = 2;
        class Catalog_GetEntriesConsumingMIMEType_Params_Data {
        public:
            static Catalog_GetEntriesConsumingMIMEType_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Catalog_GetEntriesConsumingMIMEType_Params_Data))) Catalog_GetEntriesConsumingMIMEType_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> mime_type;

        private:
            Catalog_GetEntriesConsumingMIMEType_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Catalog_GetEntriesConsumingMIMEType_Params_Data() = delete;
        };
        static_assert(sizeof(Catalog_GetEntriesConsumingMIMEType_Params_Data) == 16,
            "Bad sizeof(Catalog_GetEntriesConsumingMIMEType_Params_Data)");
        class Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data {
        public:
            static Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data))) Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::Entry_Data>>> entries;

        private:
            Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data) == 16,
            "Bad sizeof(Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data)");
        constexpr uint32_t kCatalog_GetEntriesSupportingScheme_Name = 3;
        class Catalog_GetEntriesSupportingScheme_Params_Data {
        public:
            static Catalog_GetEntriesSupportingScheme_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Catalog_GetEntriesSupportingScheme_Params_Data))) Catalog_GetEntriesSupportingScheme_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> protocol_scheme;

        private:
            Catalog_GetEntriesSupportingScheme_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Catalog_GetEntriesSupportingScheme_Params_Data() = delete;
        };
        static_assert(sizeof(Catalog_GetEntriesSupportingScheme_Params_Data) == 16,
            "Bad sizeof(Catalog_GetEntriesSupportingScheme_Params_Data)");
        class Catalog_GetEntriesSupportingScheme_ResponseParams_Data {
        public:
            static Catalog_GetEntriesSupportingScheme_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Catalog_GetEntriesSupportingScheme_ResponseParams_Data))) Catalog_GetEntriesSupportingScheme_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::Entry_Data>>> entries;

        private:
            Catalog_GetEntriesSupportingScheme_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Catalog_GetEntriesSupportingScheme_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Catalog_GetEntriesSupportingScheme_ResponseParams_Data) == 16,
            "Bad sizeof(Catalog_GetEntriesSupportingScheme_ResponseParams_Data)");
        constexpr uint32_t kCatalogControl_OverrideManifestPath_Name = 0;
        class CatalogControl_OverrideManifestPath_Params_Data {
        public:
            static CatalogControl_OverrideManifestPath_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CatalogControl_OverrideManifestPath_Params_Data))) CatalogControl_OverrideManifestPath_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<::mojo::common::mojom::internal::FilePath_Data> path;

        private:
            CatalogControl_OverrideManifestPath_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CatalogControl_OverrideManifestPath_Params_Data() = delete;
        };
        static_assert(sizeof(CatalogControl_OverrideManifestPath_Params_Data) == 24,
            "Bad sizeof(CatalogControl_OverrideManifestPath_Params_Data)");
        class CatalogControl_OverrideManifestPath_ResponseParams_Data {
        public:
            static CatalogControl_OverrideManifestPath_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CatalogControl_OverrideManifestPath_ResponseParams_Data))) CatalogControl_OverrideManifestPath_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            CatalogControl_OverrideManifestPath_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CatalogControl_OverrideManifestPath_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(CatalogControl_OverrideManifestPath_ResponseParams_Data) == 8,
            "Bad sizeof(CatalogControl_OverrideManifestPath_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace catalog

#endif // SERVICES_CATALOG_PUBLIC_INTERFACES_CATALOG_MOJOM_SHARED_INTERNAL_H_