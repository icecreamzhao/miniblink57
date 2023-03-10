// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/bind.h"
#include "base/compiler_specific.h"
#include "base/macros.h"
#include "base/path_service.h"
#include "base/test/launcher/unit_test_launcher.h"
#include "base/test/test_discardable_memory_allocator.h"
#include "base/test/test_suite.h"
#include "build/build_config.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "ui/base/resource/resource_bundle.h"
#include "ui/base/ui_base_paths.h"

#if defined(OS_MACOSX)
#include "base/test/mock_chrome_application_mac.h"
#else
#include "ui/gl/test/gl_surface_test_support.h"
#endif

namespace {

class MessageCenterTestSuite : public base::TestSuite {
public:
    MessageCenterTestSuite(int argc, char** argv)
        : base::TestSuite(argc, argv)
    {
    }

protected:
    void Initialize() override
    {
#if defined(OS_MACOSX)
        mock_cr_app::RegisterMockCrApp();
#else
        gfx::GLSurfaceTestSupport::InitializeOneOff();
#endif
        base::TestSuite::Initialize();
        ui::RegisterPathProvider();

        base::FilePath ui_test_pak_path;
        ASSERT_TRUE(PathService::Get(ui::UI_TEST_PAK, &ui_test_pak_path));
        ui::ResourceBundle::InitSharedInstanceWithPakPath(ui_test_pak_path);

        base::DiscardableMemoryAllocator::SetInstance(
            &discardable_memory_allocator_);
    }

    void Shutdown() override
    {
        ui::ResourceBundle::CleanupSharedInstance();
        base::TestSuite::Shutdown();
    }

private:
    base::TestDiscardableMemoryAllocator discardable_memory_allocator_;

    DISALLOW_COPY_AND_ASSIGN(MessageCenterTestSuite);
};

} // namespace

int main(int argc, char** argv)
{
    MessageCenterTestSuite test_suite(argc, argv);

    return base::LaunchUnitTests(
        argc,
        argv,
        base::Bind(&MessageCenterTestSuite::Run, base::Unretained(&test_suite)));
}
