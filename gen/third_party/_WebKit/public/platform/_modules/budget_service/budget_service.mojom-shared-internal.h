// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BUDGET_SERVICE_BUDGET_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BUDGET_SERVICE_BUDGET_SERVICE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "url/mojo/origin.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace blink {
namespace mojom {
    namespace internal {
        class BudgetState_Data;

        struct BudgetOperationType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
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

        struct BudgetServiceErrorType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
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
        class BudgetState_Data {
        public:
            static BudgetState_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BudgetState_Data))) BudgetState_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            double budget_at;
            double time;

        private:
            BudgetState_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BudgetState_Data() = delete;
        };
        static_assert(sizeof(BudgetState_Data) == 24,
            "Bad sizeof(BudgetState_Data)");
        constexpr uint32_t kBudgetService_GetCost_Name = 0;
        class BudgetService_GetCost_Params_Data {
        public:
            static BudgetService_GetCost_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BudgetService_GetCost_Params_Data))) BudgetService_GetCost_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t operation;
            uint8_t padfinal_[4];

        private:
            BudgetService_GetCost_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BudgetService_GetCost_Params_Data() = delete;
        };
        static_assert(sizeof(BudgetService_GetCost_Params_Data) == 16,
            "Bad sizeof(BudgetService_GetCost_Params_Data)");
        class BudgetService_GetCost_ResponseParams_Data {
        public:
            static BudgetService_GetCost_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BudgetService_GetCost_ResponseParams_Data))) BudgetService_GetCost_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            double cost;

        private:
            BudgetService_GetCost_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BudgetService_GetCost_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(BudgetService_GetCost_ResponseParams_Data) == 16,
            "Bad sizeof(BudgetService_GetCost_ResponseParams_Data)");
        constexpr uint32_t kBudgetService_GetBudget_Name = 1;
        class BudgetService_GetBudget_Params_Data {
        public:
            static BudgetService_GetBudget_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BudgetService_GetBudget_Params_Data))) BudgetService_GetBudget_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;

        private:
            BudgetService_GetBudget_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BudgetService_GetBudget_Params_Data() = delete;
        };
        static_assert(sizeof(BudgetService_GetBudget_Params_Data) == 16,
            "Bad sizeof(BudgetService_GetBudget_Params_Data)");
        class BudgetService_GetBudget_ResponseParams_Data {
        public:
            static BudgetService_GetBudget_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BudgetService_GetBudget_ResponseParams_Data))) BudgetService_GetBudget_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error_type;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::BudgetState_Data>>> budget;

        private:
            BudgetService_GetBudget_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BudgetService_GetBudget_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(BudgetService_GetBudget_ResponseParams_Data) == 24,
            "Bad sizeof(BudgetService_GetBudget_ResponseParams_Data)");
        constexpr uint32_t kBudgetService_Reserve_Name = 2;
        class BudgetService_Reserve_Params_Data {
        public:
            static BudgetService_Reserve_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BudgetService_Reserve_Params_Data))) BudgetService_Reserve_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;
            int32_t operation;
            uint8_t padfinal_[4];

        private:
            BudgetService_Reserve_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BudgetService_Reserve_Params_Data() = delete;
        };
        static_assert(sizeof(BudgetService_Reserve_Params_Data) == 24,
            "Bad sizeof(BudgetService_Reserve_Params_Data)");
        class BudgetService_Reserve_ResponseParams_Data {
        public:
            static BudgetService_Reserve_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BudgetService_Reserve_ResponseParams_Data))) BudgetService_Reserve_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error_type;
            uint8_t success : 1;
            uint8_t padfinal_[3];

        private:
            BudgetService_Reserve_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BudgetService_Reserve_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(BudgetService_Reserve_ResponseParams_Data) == 16,
            "Bad sizeof(BudgetService_Reserve_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BUDGET_SERVICE_BUDGET_SERVICE_MOJOM_SHARED_INTERNAL_H_