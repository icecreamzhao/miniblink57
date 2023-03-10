// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_FORMATS_MP2T_TS_SECTION_CETS_PSSH_H_
#define MEDIA_FORMATS_MP2T_TS_SECTION_CETS_PSSH_H_

#include <stdint.h>
#include <vector>

#include "base/callback.h"
#include "base/macros.h"
#include "media/base/byte_queue.h"
#include "media/formats/mp2t/ts_section.h"

namespace media {
namespace mp2t {

    class TsSectionCetsPssh : public TsSection {
    public:
        using RegisterPsshBoxesCb = base::Callback<void(const std::vector<uint8_t>&)>;
        explicit TsSectionCetsPssh(const RegisterPsshBoxesCb& register_pssh_boxes_cb);
        ~TsSectionCetsPssh() override;

        // TsSection implementation.
        bool Parse(bool payload_unit_start_indicator,
            const uint8_t* buf,
            int size) override;
        void Flush() override;
        void Reset() override;

    private:
        RegisterPsshBoxesCb register_pssh_boxes_cb_;

        DISALLOW_COPY_AND_ASSIGN(TsSectionCetsPssh);
    };

} // namespace mp2t
} // namespace media

#endif
