// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_CDM_SIMPLE_CDM_ALLOCATOR_H_
#define MEDIA_CDM_SIMPLE_CDM_ALLOCATOR_H_

#include <stddef.h>
#include <stdint.h>
#include <memory>

#include "base/macros.h"
#include "media/cdm/cdm_allocator.h"

namespace media {

// This is a simple CdmAllocator for testing.
class SimpleCdmAllocator : public CdmAllocator {
public:
    SimpleCdmAllocator();
    ~SimpleCdmAllocator() final;

    // CdmAllocator implementation.
    cdm::Buffer* CreateCdmBuffer(size_t capacity) final;
    std::unique_ptr<VideoFrameImpl> CreateCdmVideoFrame() final;

private:
    DISALLOW_COPY_AND_ASSIGN(SimpleCdmAllocator);
};

} // namespace media

#endif // MEDIA_CDM_SIMPLE_CDM_ALLOCATOR_H_
