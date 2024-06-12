// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/base/win/mf_helpers.h"

namespace media {

namespace mf {

    void LogDXVAError(int line)
    {
        LOG(ERROR) << "Error in dxva_video_decode_accelerator_win.cc on line "
                   << line;
    }

    base::win::ScopedComPtr<IMFSample> CreateEmptySampleWithBuffer(
        uint32_t buffer_length,
        int align)
    {
        CHECK_GT(buffer_length, 0U);

        base::win::ScopedComPtr<IMFSample> sample;
        //support_xp {
        using MFCreateSampleFunc = decltype(::MFCreateSample)*;
        static const auto mf_create_sample = reinterpret_cast<MFCreateSampleFunc>(
            ::GetProcAddress(::GetModuleHandleW(L"Mfplat.dll"), "MFCreateSample"));
        HRESULT hr = E_FAIL;
        if (mf_create_sample) {
            hr = mf_create_sample(sample.Receive());
        }
        //}
        RETURN_ON_HR_FAILURE(hr, "MFCreateSample failed",
            base::win::ScopedComPtr<IMFSample>());

        base::win::ScopedComPtr<IMFMediaBuffer> buffer;
        if (align == 0) {
            // Note that MFCreateMemoryBuffer is same as MFCreateAlignedMemoryBuffer
            // with the align argument being 0.
            //support_xp {
            using MFCreateMemoryBufferFunc = decltype(::MFCreateMemoryBuffer)*;
            static const auto mf_create_memory_buffer = reinterpret_cast<MFCreateMemoryBufferFunc>(
                ::GetProcAddress(::GetModuleHandleW(L"Mfplat.dll"), "MFCreateMemoryBuffer"));
            if (mf_create_memory_buffer) {
                hr = mf_create_memory_buffer(buffer_length, buffer.Receive());
            } else {
                hr = E_FAIL;
            }
            //}
        } else {
            //support_xp {
            using MFCreateAlignedMemoryBufferFunc = decltype(::MFCreateAlignedMemoryBuffer)*;
            static const auto mf_create_aligned_memory_buffer = reinterpret_cast<MFCreateAlignedMemoryBufferFunc>(
                ::GetProcAddress(::GetModuleHandleW(L"Mfplat.dll"), "MFCreateAlignedMemoryBuffer"));
            if (mf_create_aligned_memory_buffer) {
                hr = mf_create_aligned_memory_buffer(buffer_length, align - 1, buffer.Receive());
            } else {
                hr = E_FAIL;
            }
            //}
        }
        RETURN_ON_HR_FAILURE(hr, "Failed to create memory buffer for sample",
            base::win::ScopedComPtr<IMFSample>());

        hr = sample->AddBuffer(buffer.get());
        RETURN_ON_HR_FAILURE(hr, "Failed to add buffer to sample",
            base::win::ScopedComPtr<IMFSample>());

        buffer->SetCurrentLength(0);
        return sample;
    }

    MediaBufferScopedPointer::MediaBufferScopedPointer(IMFMediaBuffer* media_buffer)
        : media_buffer_(media_buffer)
        , buffer_(nullptr)
        , max_length_(0)
        , current_length_(0)
    {
        HRESULT hr = media_buffer_->Lock(&buffer_, &max_length_, &current_length_);
        CHECK(SUCCEEDED(hr));
    }

    MediaBufferScopedPointer::~MediaBufferScopedPointer()
    {
        HRESULT hr = media_buffer_->Unlock();
        CHECK(SUCCEEDED(hr));
    }

} // namespace mf

} // namespace media
