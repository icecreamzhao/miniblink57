// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_CDM_SIMPLE_CDM_BUFFER_H_
#define MEDIA_CDM_SIMPLE_CDM_BUFFER_H_

#include <stddef.h>
#include <stdint.h>

#include <vector>

#include "base/macros.h"
#include "media/cdm/api/content_decryption_module.h"

namespace media {

// cdm::Buffer implementation that provides access to memory. This is a simple
// implementation that stores the data in a std::vector<uint8_t>.
class SimpleCdmBuffer : public cdm::Buffer {
public:
    static SimpleCdmBuffer* Create(size_t capacity);

    // cdm::Buffer implementation.
    void Destroy() final;
    uint32_t Capacity() const final;
    uint8_t* Data() final;
    void SetSize(uint32_t size) final;
    uint32_t Size() const final;

private:
    SimpleCdmBuffer(uint32_t capacity);
    ~SimpleCdmBuffer() final;

    std::vector<uint8_t> buffer_;
    uint32_t size_;

    DISALLOW_COPY_AND_ASSIGN(SimpleCdmBuffer);
};

} // namespace media

#endif // MEDIA_CDM_SIMPLE_CDM_BUFFER_H_
