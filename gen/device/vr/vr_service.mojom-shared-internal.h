// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_VR_VR_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_VR_VR_SERVICE_MOJOM_SHARED_INTERNAL_H_

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
namespace device {
namespace mojom {
    namespace internal {
        class VRFieldOfView_Data;
        class VRPose_Data;
        class VRDisplayCapabilities_Data;
        class VREyeParameters_Data;
        class VRStageParameters_Data;
        class VRDisplayInfo_Data;
        class VRLayerBounds_Data;

        struct VRDisplayEventReason_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
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
        class VRFieldOfView_Data {
        public:
            static VRFieldOfView_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRFieldOfView_Data))) VRFieldOfView_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float upDegrees;
            float downDegrees;
            float leftDegrees;
            float rightDegrees;

        private:
            VRFieldOfView_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRFieldOfView_Data() = delete;
        };
        static_assert(sizeof(VRFieldOfView_Data) == 24,
            "Bad sizeof(VRFieldOfView_Data)");
        class VRPose_Data {
        public:
            static VRPose_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRPose_Data))) VRPose_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            double timestamp;
            mojo::internal::Pointer<mojo::internal::Array_Data<float>> orientation;
            mojo::internal::Pointer<mojo::internal::Array_Data<float>> position;
            mojo::internal::Pointer<mojo::internal::Array_Data<float>> angularVelocity;
            mojo::internal::Pointer<mojo::internal::Array_Data<float>> linearVelocity;
            mojo::internal::Pointer<mojo::internal::Array_Data<float>> angularAcceleration;
            mojo::internal::Pointer<mojo::internal::Array_Data<float>> linearAcceleration;
            uint32_t poseIndex;
            uint8_t padfinal_[4];

        private:
            VRPose_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRPose_Data() = delete;
        };
        static_assert(sizeof(VRPose_Data) == 72,
            "Bad sizeof(VRPose_Data)");
        class VRDisplayCapabilities_Data {
        public:
            static VRDisplayCapabilities_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplayCapabilities_Data))) VRDisplayCapabilities_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t hasOrientation : 1;
            uint8_t hasPosition : 1;
            uint8_t hasExternalDisplay : 1;
            uint8_t canPresent : 1;
            uint8_t padfinal_[7];

        private:
            VRDisplayCapabilities_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplayCapabilities_Data() = delete;
        };
        static_assert(sizeof(VRDisplayCapabilities_Data) == 16,
            "Bad sizeof(VRDisplayCapabilities_Data)");
        class VREyeParameters_Data {
        public:
            static VREyeParameters_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VREyeParameters_Data))) VREyeParameters_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::VRFieldOfView_Data> fieldOfView;
            mojo::internal::Pointer<mojo::internal::Array_Data<float>> offset;
            uint32_t renderWidth;
            uint32_t renderHeight;

        private:
            VREyeParameters_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VREyeParameters_Data() = delete;
        };
        static_assert(sizeof(VREyeParameters_Data) == 32,
            "Bad sizeof(VREyeParameters_Data)");
        class VRStageParameters_Data {
        public:
            static VRStageParameters_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRStageParameters_Data))) VRStageParameters_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<float>> standingTransform;
            float sizeX;
            float sizeZ;

        private:
            VRStageParameters_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRStageParameters_Data() = delete;
        };
        static_assert(sizeof(VRStageParameters_Data) == 24,
            "Bad sizeof(VRStageParameters_Data)");
        class VRDisplayInfo_Data {
        public:
            static VRDisplayInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplayInfo_Data))) VRDisplayInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t index;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> displayName;
            mojo::internal::Pointer<internal::VRDisplayCapabilities_Data> capabilities;
            mojo::internal::Pointer<internal::VRStageParameters_Data> stageParameters;
            mojo::internal::Pointer<internal::VREyeParameters_Data> leftEye;
            mojo::internal::Pointer<internal::VREyeParameters_Data> rightEye;

        private:
            VRDisplayInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplayInfo_Data() = delete;
        };
        static_assert(sizeof(VRDisplayInfo_Data) == 56,
            "Bad sizeof(VRDisplayInfo_Data)");
        class VRLayerBounds_Data {
        public:
            static VRLayerBounds_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRLayerBounds_Data))) VRLayerBounds_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float left;
            float top;
            float width;
            float height;

        private:
            VRLayerBounds_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRLayerBounds_Data() = delete;
        };
        static_assert(sizeof(VRLayerBounds_Data) == 24,
            "Bad sizeof(VRLayerBounds_Data)");
        constexpr uint32_t kVRService_SetClient_Name = 0;
        class VRService_SetClient_Params_Data {
        public:
            static VRService_SetClient_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRService_SetClient_Params_Data))) VRService_SetClient_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data client;

        private:
            VRService_SetClient_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRService_SetClient_Params_Data() = delete;
        };
        static_assert(sizeof(VRService_SetClient_Params_Data) == 16,
            "Bad sizeof(VRService_SetClient_Params_Data)");
        class VRService_SetClient_ResponseParams_Data {
        public:
            static VRService_SetClient_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRService_SetClient_ResponseParams_Data))) VRService_SetClient_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t numberOfConnectedDevices;
            uint8_t padfinal_[4];

        private:
            VRService_SetClient_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRService_SetClient_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(VRService_SetClient_ResponseParams_Data) == 16,
            "Bad sizeof(VRService_SetClient_ResponseParams_Data)");
        constexpr uint32_t kVRService_SetListeningForActivate_Name = 1;
        class VRService_SetListeningForActivate_Params_Data {
        public:
            static VRService_SetListeningForActivate_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRService_SetListeningForActivate_Params_Data))) VRService_SetListeningForActivate_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t listening : 1;
            uint8_t padfinal_[7];

        private:
            VRService_SetListeningForActivate_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRService_SetListeningForActivate_Params_Data() = delete;
        };
        static_assert(sizeof(VRService_SetListeningForActivate_Params_Data) == 16,
            "Bad sizeof(VRService_SetListeningForActivate_Params_Data)");
        constexpr uint32_t kVRServiceClient_OnDisplayConnected_Name = 0;
        class VRServiceClient_OnDisplayConnected_Params_Data {
        public:
            static VRServiceClient_OnDisplayConnected_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRServiceClient_OnDisplayConnected_Params_Data))) VRServiceClient_OnDisplayConnected_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data display;
            mojo::internal::Handle_Data request;
            uint8_t pad1_[4];
            mojo::internal::Pointer<internal::VRDisplayInfo_Data> displayInfo;

        private:
            VRServiceClient_OnDisplayConnected_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRServiceClient_OnDisplayConnected_Params_Data() = delete;
        };
        static_assert(sizeof(VRServiceClient_OnDisplayConnected_Params_Data) == 32,
            "Bad sizeof(VRServiceClient_OnDisplayConnected_Params_Data)");
        constexpr uint32_t kVRDisplay_GetPose_Name = 0;
        class VRDisplay_GetPose_Params_Data {
        public:
            static VRDisplay_GetPose_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplay_GetPose_Params_Data))) VRDisplay_GetPose_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            VRDisplay_GetPose_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplay_GetPose_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplay_GetPose_Params_Data) == 8,
            "Bad sizeof(VRDisplay_GetPose_Params_Data)");
        class VRDisplay_GetPose_ResponseParams_Data {
        public:
            static VRDisplay_GetPose_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplay_GetPose_ResponseParams_Data))) VRDisplay_GetPose_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::VRPose_Data> pose;

        private:
            VRDisplay_GetPose_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplay_GetPose_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(VRDisplay_GetPose_ResponseParams_Data) == 16,
            "Bad sizeof(VRDisplay_GetPose_ResponseParams_Data)");
        constexpr uint32_t kVRDisplay_ResetPose_Name = 1;
        class VRDisplay_ResetPose_Params_Data {
        public:
            static VRDisplay_ResetPose_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplay_ResetPose_Params_Data))) VRDisplay_ResetPose_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            VRDisplay_ResetPose_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplay_ResetPose_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplay_ResetPose_Params_Data) == 8,
            "Bad sizeof(VRDisplay_ResetPose_Params_Data)");
        constexpr uint32_t kVRDisplay_RequestPresent_Name = 2;
        class VRDisplay_RequestPresent_Params_Data {
        public:
            static VRDisplay_RequestPresent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplay_RequestPresent_Params_Data))) VRDisplay_RequestPresent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t secureOrigin : 1;
            uint8_t padfinal_[7];

        private:
            VRDisplay_RequestPresent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplay_RequestPresent_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplay_RequestPresent_Params_Data) == 16,
            "Bad sizeof(VRDisplay_RequestPresent_Params_Data)");
        class VRDisplay_RequestPresent_ResponseParams_Data {
        public:
            static VRDisplay_RequestPresent_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplay_RequestPresent_ResponseParams_Data))) VRDisplay_RequestPresent_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            VRDisplay_RequestPresent_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplay_RequestPresent_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(VRDisplay_RequestPresent_ResponseParams_Data) == 16,
            "Bad sizeof(VRDisplay_RequestPresent_ResponseParams_Data)");
        constexpr uint32_t kVRDisplay_ExitPresent_Name = 3;
        class VRDisplay_ExitPresent_Params_Data {
        public:
            static VRDisplay_ExitPresent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplay_ExitPresent_Params_Data))) VRDisplay_ExitPresent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            VRDisplay_ExitPresent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplay_ExitPresent_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplay_ExitPresent_Params_Data) == 8,
            "Bad sizeof(VRDisplay_ExitPresent_Params_Data)");
        constexpr uint32_t kVRDisplay_SubmitFrame_Name = 4;
        class VRDisplay_SubmitFrame_Params_Data {
        public:
            static VRDisplay_SubmitFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplay_SubmitFrame_Params_Data))) VRDisplay_SubmitFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::VRPose_Data> pose;

        private:
            VRDisplay_SubmitFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplay_SubmitFrame_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplay_SubmitFrame_Params_Data) == 16,
            "Bad sizeof(VRDisplay_SubmitFrame_Params_Data)");
        constexpr uint32_t kVRDisplay_UpdateLayerBounds_Name = 5;
        class VRDisplay_UpdateLayerBounds_Params_Data {
        public:
            static VRDisplay_UpdateLayerBounds_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplay_UpdateLayerBounds_Params_Data))) VRDisplay_UpdateLayerBounds_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::VRLayerBounds_Data> leftBounds;
            mojo::internal::Pointer<internal::VRLayerBounds_Data> rightBounds;

        private:
            VRDisplay_UpdateLayerBounds_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplay_UpdateLayerBounds_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplay_UpdateLayerBounds_Params_Data) == 24,
            "Bad sizeof(VRDisplay_UpdateLayerBounds_Params_Data)");
        constexpr uint32_t kVRDisplayClient_OnChanged_Name = 0;
        class VRDisplayClient_OnChanged_Params_Data {
        public:
            static VRDisplayClient_OnChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplayClient_OnChanged_Params_Data))) VRDisplayClient_OnChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::VRDisplayInfo_Data> display;

        private:
            VRDisplayClient_OnChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplayClient_OnChanged_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplayClient_OnChanged_Params_Data) == 16,
            "Bad sizeof(VRDisplayClient_OnChanged_Params_Data)");
        constexpr uint32_t kVRDisplayClient_OnExitPresent_Name = 1;
        class VRDisplayClient_OnExitPresent_Params_Data {
        public:
            static VRDisplayClient_OnExitPresent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplayClient_OnExitPresent_Params_Data))) VRDisplayClient_OnExitPresent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            VRDisplayClient_OnExitPresent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplayClient_OnExitPresent_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplayClient_OnExitPresent_Params_Data) == 8,
            "Bad sizeof(VRDisplayClient_OnExitPresent_Params_Data)");
        constexpr uint32_t kVRDisplayClient_OnBlur_Name = 2;
        class VRDisplayClient_OnBlur_Params_Data {
        public:
            static VRDisplayClient_OnBlur_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplayClient_OnBlur_Params_Data))) VRDisplayClient_OnBlur_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            VRDisplayClient_OnBlur_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplayClient_OnBlur_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplayClient_OnBlur_Params_Data) == 8,
            "Bad sizeof(VRDisplayClient_OnBlur_Params_Data)");
        constexpr uint32_t kVRDisplayClient_OnFocus_Name = 3;
        class VRDisplayClient_OnFocus_Params_Data {
        public:
            static VRDisplayClient_OnFocus_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplayClient_OnFocus_Params_Data))) VRDisplayClient_OnFocus_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            VRDisplayClient_OnFocus_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplayClient_OnFocus_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplayClient_OnFocus_Params_Data) == 8,
            "Bad sizeof(VRDisplayClient_OnFocus_Params_Data)");
        constexpr uint32_t kVRDisplayClient_OnActivate_Name = 4;
        class VRDisplayClient_OnActivate_Params_Data {
        public:
            static VRDisplayClient_OnActivate_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplayClient_OnActivate_Params_Data))) VRDisplayClient_OnActivate_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t reason;
            uint8_t padfinal_[4];

        private:
            VRDisplayClient_OnActivate_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplayClient_OnActivate_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplayClient_OnActivate_Params_Data) == 16,
            "Bad sizeof(VRDisplayClient_OnActivate_Params_Data)");
        constexpr uint32_t kVRDisplayClient_OnDeactivate_Name = 5;
        class VRDisplayClient_OnDeactivate_Params_Data {
        public:
            static VRDisplayClient_OnDeactivate_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VRDisplayClient_OnDeactivate_Params_Data))) VRDisplayClient_OnDeactivate_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t reason;
            uint8_t padfinal_[4];

        private:
            VRDisplayClient_OnDeactivate_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VRDisplayClient_OnDeactivate_Params_Data() = delete;
        };
        static_assert(sizeof(VRDisplayClient_OnDeactivate_Params_Data) == 16,
            "Bad sizeof(VRDisplayClient_OnDeactivate_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_VR_VR_SERVICE_MOJOM_SHARED_INTERNAL_H_