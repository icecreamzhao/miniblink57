// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/display/chromeos/test/action_logger_util.h"

#include <stddef.h>

#include "base/format_macros.h"
#include "base/logging.h"
#include "base/strings/stringprintf.h"
#include "ui/display/types/display_mode.h"
#include "ui/display/types/display_snapshot.h"
#include "ui/display/types/gamma_ramp_rgb_entry.h"
#include "ui/display/types/native_display_delegate.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/size.h"

namespace ui {
namespace test {

    std::string DisplaySnapshotToString(const DisplaySnapshot& output)
    {
        return base::StringPrintf("id=%" PRId64, output.display_id());
    }

    std::string GetBackgroundAction(uint32_t color_argb)
    {
        return base::StringPrintf("background(0x%x)", color_argb);
    }

    std::string GetAddOutputModeAction(const DisplaySnapshot& output,
        const DisplayMode* mode)
    {
        return base::StringPrintf("add_mode(output=%" PRId64 ",mode=%s)",
            output.display_id(), mode->ToString().c_str());
    }

    std::string GetCrtcAction(const DisplaySnapshot& output,
        const DisplayMode* mode,
        const gfx::Point& origin)
    {
        return base::StringPrintf("crtc(display=[%s],x=%d,y=%d,mode=[%s])",
            DisplaySnapshotToString(output).c_str(), origin.x(),
            origin.y(),
            mode ? mode->ToString().c_str() : "NULL");
    }

    std::string GetFramebufferAction(const gfx::Size& size,
        const DisplaySnapshot* out1,
        const DisplaySnapshot* out2)
    {
        return base::StringPrintf(
            "framebuffer(width=%d,height=%d,display1=%s,display2=%s)", size.width(),
            size.height(), out1 ? DisplaySnapshotToString(*out1).c_str() : "NULL",
            out2 ? DisplaySnapshotToString(*out2).c_str() : "NULL");
    }

    std::string GetSetHDCPStateAction(const DisplaySnapshot& output,
        HDCPState state)
    {
        return base::StringPrintf("set_hdcp(id=%" PRId64 ",state=%d)",
            output.display_id(), state);
    }

    std::string SetGammaRampAction(const ui::DisplaySnapshot& output,
        const std::vector<GammaRampRGBEntry>& lut)
    {
        std::string table;
        for (size_t i = 0; i < lut.size(); ++i) {
            table += base::StringPrintf(",rgb[%" PRIuS "]=%04x%04x%04x", i, lut[i].r,
                lut[i].g, lut[i].b);
        }

        return base::StringPrintf("set_gamma_ramp(id=%" PRId64 "%s)",
            output.display_id(), table.c_str());
    }

    std::string JoinActions(const char* action, ...)
    {
        std::string actions;

        va_list arg_list;
        va_start(arg_list, action);
        while (action) {
            if (!actions.empty())
                actions += ",";
            actions += action;
            action = va_arg(arg_list, const char*);
        }
        va_end(arg_list);
        return actions;
    }

} // namespace test
} // namespace ui
