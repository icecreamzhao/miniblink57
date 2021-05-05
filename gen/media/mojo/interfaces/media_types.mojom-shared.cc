// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "media/mojo/interfaces/media_types.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace media {
namespace mojom {

    namespace internal {

        // static
        bool Pattern_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Pattern_Data* object = static_cast<const Pattern_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 16 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            return true;
        }

        // static
        bool EncryptionScheme_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const EncryptionScheme_Data* object = static_cast<const EncryptionScheme_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 24 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!::media::mojom::internal::EncryptionScheme_CipherMode_Data ::Validate(object->mode, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->pattern, "null pattern field in EncryptionScheme",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->pattern, validation_context))
                return false;

            return true;
        }

        // static
        bool AudioDecoderConfig_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const AudioDecoderConfig_Data* object = static_cast<const AudioDecoderConfig_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 56 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!::media::mojom::internal::AudioCodec_Data ::Validate(object->codec, validation_context))
                return false;

            if (!::media::mojom::internal::SampleFormat_Data ::Validate(object->sample_format, validation_context))
                return false;

            if (!::media::mojom::internal::ChannelLayout_Data ::Validate(object->channel_layout, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->extra_data, "null extra_data field in AudioDecoderConfig",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams extra_data_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->extra_data, validation_context,
                    &extra_data_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->seek_preroll, "null seek_preroll field in AudioDecoderConfig",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->seek_preroll, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->encryption_scheme, "null encryption_scheme field in AudioDecoderConfig",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->encryption_scheme, validation_context))
                return false;

            return true;
        }

        // static
        bool VideoDecoderConfig_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const VideoDecoderConfig_Data* object = static_cast<const VideoDecoderConfig_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 64 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!::media::mojom::internal::VideoCodec_Data ::Validate(object->codec, validation_context))
                return false;

            if (!::media::mojom::internal::VideoCodecProfile_Data ::Validate(object->profile, validation_context))
                return false;

            if (!::media::mojom::internal::VideoPixelFormat_Data ::Validate(object->format, validation_context))
                return false;

            if (!::media::mojom::internal::ColorSpace_Data ::Validate(object->color_space, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->coded_size, "null coded_size field in VideoDecoderConfig",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->coded_size, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->visible_rect, "null visible_rect field in VideoDecoderConfig",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->visible_rect, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->natural_size, "null natural_size field in VideoDecoderConfig",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->natural_size, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->extra_data, "null extra_data field in VideoDecoderConfig",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams extra_data_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->extra_data, validation_context,
                    &extra_data_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->encryption_scheme, "null encryption_scheme field in VideoDecoderConfig",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->encryption_scheme, validation_context))
                return false;

            return true;
        }

        // static
        bool DecryptConfig_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const DecryptConfig_Data* object = static_cast<const DecryptConfig_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 32 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->key_id, "null key_id field in DecryptConfig",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams key_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->key_id, validation_context,
                    &key_id_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->iv, "null iv field in DecryptConfig",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams iv_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->iv, validation_context,
                    &iv_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->subsamples, "null subsamples field in DecryptConfig",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams subsamples_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->subsamples, validation_context,
                    &subsamples_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool DecoderBuffer_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const DecoderBuffer_Data* object = static_cast<const DecoderBuffer_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 72 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->timestamp, "null timestamp field in DecoderBuffer",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->timestamp, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->duration, "null duration field in DecoderBuffer",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->duration, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->side_data, "null side_data field in DecoderBuffer",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams side_data_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->side_data, validation_context,
                    &side_data_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidateStruct(object->decrypt_config, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->front_discard, "null front_discard field in DecoderBuffer",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->front_discard, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->back_discard, "null back_discard field in DecoderBuffer",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->back_discard, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->splice_timestamp, "null splice_timestamp field in DecoderBuffer",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->splice_timestamp, validation_context))
                return false;

            return true;
        }

        // static
        bool AudioBuffer_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const AudioBuffer_Data* object = static_cast<const AudioBuffer_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 48 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!::media::mojom::internal::SampleFormat_Data ::Validate(object->sample_format, validation_context))
                return false;

            if (!::media::mojom::internal::ChannelLayout_Data ::Validate(object->channel_layout, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->timestamp, "null timestamp field in AudioBuffer",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->timestamp, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->data, "null data field in AudioBuffer",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->data, validation_context,
                    &data_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool VideoFrame_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const VideoFrame_Data* object = static_cast<const VideoFrame_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 96 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!::media::mojom::internal::VideoPixelFormat_Data ::Validate(object->format, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->coded_size, "null coded_size field in VideoFrame",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->coded_size, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->visible_rect, "null visible_rect field in VideoFrame",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->visible_rect, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->natural_size, "null natural_size field in VideoFrame",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->natural_size, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->timestamp, "null timestamp field in VideoFrame",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->timestamp, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->frame_data,
                    "invalid frame_data field in VideoFrame", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->frame_data,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool PipelineStatistics_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PipelineStatistics_Data* object = static_cast<const PipelineStatistics_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 48 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace media

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
