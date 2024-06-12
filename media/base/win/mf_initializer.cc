// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/base/win/mf_initializer.h"

#include <mfapi.h>

#include "base/lazy_instance.h"
#include "base/macros.h"

namespace media {

namespace {

    // LazyInstance to initialize the Media Foundation Library.
    class MFInitializer {
    public:
        MFInitializer()
        {
            //support_xp {
            using MFStartupFunc = decltype(::MFStartup)*;
            static const auto mf_startup = reinterpret_cast<MFStartupFunc>(::GetProcAddress(::GetModuleHandleW(L"Mfplat.dll"), "MFStartup"));
            if (mf_startup) {
                mf_started_ = (mf_startup(MF_VERSION, MFSTARTUP_LITE) == S_OK);
            }
            //}
        }

        ~MFInitializer()
        {
            //support_xp {
            if (mf_started_) {
                using MFShutdownFunc = decltype(::MFShutdown)*;
                static const auto mf_shutdown = reinterpret_cast<MFShutdownFunc>(
                    ::GetProcAddress(::GetModuleHandleW(L"Mfplat.dll"), "MFShutdown"));
                if (mf_shutdown) {
                    mf_shutdown();
                }
            }
            //}
        }

    private:
        //support_xp {
        bool mf_started_ = false;
        //}
        DISALLOW_COPY_AND_ASSIGN(MFInitializer);
    };

    base::LazyInstance<MFInitializer> g_mf_initializer = LAZY_INSTANCE_INITIALIZER;

} // namespace

void InitializeMediaFoundation()
{
    g_mf_initializer.Get();
}

} // namespace media
