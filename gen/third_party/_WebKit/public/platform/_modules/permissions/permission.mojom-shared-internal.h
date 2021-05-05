// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PERMISSIONS_PERMISSION_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PERMISSIONS_PERMISSION_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "third_party/WebKit/public/platform/modules/permissions/permission_status.mojom-shared-internal.h"
#include "url/mojo/origin.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace blink {
namespace mojom {
    namespace internal {
        class MidiPermissionDescriptor_Data;
        class PermissionDescriptor_Data;
        class PermissionDescriptorExtension_Data;

        struct PermissionName_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

#pragma pack(push, 1)

        class PermissionDescriptorExtension_Data {
        public:
            // Used to identify Mojom Union Data Classes.
            typedef void MojomUnionDataType;

            PermissionDescriptorExtension_Data() { }
            // Do nothing in the destructor since it won't be called when it is a
            // non-inlined union.
            ~PermissionDescriptorExtension_Data() { }

            static PermissionDescriptorExtension_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionDescriptorExtension_Data))) PermissionDescriptorExtension_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context,
                bool inlined);

            bool is_null() const { return size == 0; }

            void set_null()
            {
                size = 0U;
                tag = static_cast<PermissionDescriptorExtension_Tag>(0);
                data.unknown = 0U;
            }

            enum class PermissionDescriptorExtension_Tag : uint32_t {

                MIDI,
            };

            // A note on layout:
            // "Each non-static data member is allocated as if it were the sole member of
            // a struct." - Section 9.5.2 ISO/IEC 14882:2011 (The C++ Spec)
            union MOJO_ALIGNAS(8) Union_ {
                mojo::internal::Pointer<internal::MidiPermissionDescriptor_Data> f_midi;
                uint64_t unknown;
            };

            uint32_t size;
            PermissionDescriptorExtension_Tag tag;
            Union_ data;
        };
        static_assert(sizeof(PermissionDescriptorExtension_Data) == mojo::internal::kUnionDataSize,
            "Bad sizeof(PermissionDescriptorExtension_Data)");
        class MidiPermissionDescriptor_Data {
        public:
            static MidiPermissionDescriptor_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MidiPermissionDescriptor_Data))) MidiPermissionDescriptor_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t sysex : 1;
            uint8_t padfinal_[7];

        private:
            MidiPermissionDescriptor_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MidiPermissionDescriptor_Data() = delete;
        };
        static_assert(sizeof(MidiPermissionDescriptor_Data) == 16,
            "Bad sizeof(MidiPermissionDescriptor_Data)");
        class PermissionDescriptor_Data {
        public:
            static PermissionDescriptor_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionDescriptor_Data))) PermissionDescriptor_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t name;
            uint8_t pad0_[4];
            internal::PermissionDescriptorExtension_Data extension;

        private:
            PermissionDescriptor_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PermissionDescriptor_Data() = delete;
        };
        static_assert(sizeof(PermissionDescriptor_Data) == 32,
            "Bad sizeof(PermissionDescriptor_Data)");
        constexpr uint32_t kPermissionObserver_OnPermissionStatusChange_Name = 0;
        class PermissionObserver_OnPermissionStatusChange_Params_Data {
        public:
            static PermissionObserver_OnPermissionStatusChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionObserver_OnPermissionStatusChange_Params_Data))) PermissionObserver_OnPermissionStatusChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            PermissionObserver_OnPermissionStatusChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PermissionObserver_OnPermissionStatusChange_Params_Data() = delete;
        };
        static_assert(sizeof(PermissionObserver_OnPermissionStatusChange_Params_Data) == 16,
            "Bad sizeof(PermissionObserver_OnPermissionStatusChange_Params_Data)");
        constexpr uint32_t kPermissionService_HasPermission_Name = 0;
        class PermissionService_HasPermission_Params_Data {
        public:
            static PermissionService_HasPermission_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionService_HasPermission_Params_Data))) PermissionService_HasPermission_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PermissionDescriptor_Data> permission;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;

        private:
            PermissionService_HasPermission_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PermissionService_HasPermission_Params_Data() = delete;
        };
        static_assert(sizeof(PermissionService_HasPermission_Params_Data) == 24,
            "Bad sizeof(PermissionService_HasPermission_Params_Data)");
        class PermissionService_HasPermission_ResponseParams_Data {
        public:
            static PermissionService_HasPermission_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionService_HasPermission_ResponseParams_Data))) PermissionService_HasPermission_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            PermissionService_HasPermission_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PermissionService_HasPermission_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(PermissionService_HasPermission_ResponseParams_Data) == 16,
            "Bad sizeof(PermissionService_HasPermission_ResponseParams_Data)");
        constexpr uint32_t kPermissionService_RequestPermission_Name = 1;
        class PermissionService_RequestPermission_Params_Data {
        public:
            static PermissionService_RequestPermission_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionService_RequestPermission_Params_Data))) PermissionService_RequestPermission_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PermissionDescriptor_Data> permission;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;
            uint8_t user_gesture : 1;
            uint8_t padfinal_[7];

        private:
            PermissionService_RequestPermission_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PermissionService_RequestPermission_Params_Data() = delete;
        };
        static_assert(sizeof(PermissionService_RequestPermission_Params_Data) == 32,
            "Bad sizeof(PermissionService_RequestPermission_Params_Data)");
        class PermissionService_RequestPermission_ResponseParams_Data {
        public:
            static PermissionService_RequestPermission_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionService_RequestPermission_ResponseParams_Data))) PermissionService_RequestPermission_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            PermissionService_RequestPermission_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PermissionService_RequestPermission_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(PermissionService_RequestPermission_ResponseParams_Data) == 16,
            "Bad sizeof(PermissionService_RequestPermission_ResponseParams_Data)");
        constexpr uint32_t kPermissionService_RequestPermissions_Name = 2;
        class PermissionService_RequestPermissions_Params_Data {
        public:
            static PermissionService_RequestPermissions_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionService_RequestPermissions_Params_Data))) PermissionService_RequestPermissions_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::PermissionDescriptor_Data>>> permission;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;
            uint8_t user_gesture : 1;
            uint8_t padfinal_[7];

        private:
            PermissionService_RequestPermissions_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PermissionService_RequestPermissions_Params_Data() = delete;
        };
        static_assert(sizeof(PermissionService_RequestPermissions_Params_Data) == 32,
            "Bad sizeof(PermissionService_RequestPermissions_Params_Data)");
        class PermissionService_RequestPermissions_ResponseParams_Data {
        public:
            static PermissionService_RequestPermissions_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionService_RequestPermissions_ResponseParams_Data))) PermissionService_RequestPermissions_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<int32_t>> statuses;

        private:
            PermissionService_RequestPermissions_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PermissionService_RequestPermissions_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(PermissionService_RequestPermissions_ResponseParams_Data) == 16,
            "Bad sizeof(PermissionService_RequestPermissions_ResponseParams_Data)");
        constexpr uint32_t kPermissionService_RevokePermission_Name = 3;
        class PermissionService_RevokePermission_Params_Data {
        public:
            static PermissionService_RevokePermission_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionService_RevokePermission_Params_Data))) PermissionService_RevokePermission_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PermissionDescriptor_Data> permission;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;

        private:
            PermissionService_RevokePermission_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PermissionService_RevokePermission_Params_Data() = delete;
        };
        static_assert(sizeof(PermissionService_RevokePermission_Params_Data) == 24,
            "Bad sizeof(PermissionService_RevokePermission_Params_Data)");
        class PermissionService_RevokePermission_ResponseParams_Data {
        public:
            static PermissionService_RevokePermission_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionService_RevokePermission_ResponseParams_Data))) PermissionService_RevokePermission_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            PermissionService_RevokePermission_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PermissionService_RevokePermission_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(PermissionService_RevokePermission_ResponseParams_Data) == 16,
            "Bad sizeof(PermissionService_RevokePermission_ResponseParams_Data)");
        constexpr uint32_t kPermissionService_AddPermissionObserver_Name = 4;
        class PermissionService_AddPermissionObserver_Params_Data {
        public:
            static PermissionService_AddPermissionObserver_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PermissionService_AddPermissionObserver_Params_Data))) PermissionService_AddPermissionObserver_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PermissionDescriptor_Data> permission;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;
            int32_t last_known_status;
            mojo::internal::Interface_Data observer;
            uint8_t padfinal_[4];

        private:
            PermissionService_AddPermissionObserver_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PermissionService_AddPermissionObserver_Params_Data() = delete;
        };
        static_assert(sizeof(PermissionService_AddPermissionObserver_Params_Data) == 40,
            "Bad sizeof(PermissionService_AddPermissionObserver_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PERMISSIONS_PERMISSION_MOJOM_SHARED_INTERNAL_H_