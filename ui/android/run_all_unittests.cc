// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/android/jni_android.h"
#include "base/bind.h"
#include "base/compiler_specific.h"
#include "base/macros.h"
#include "base/path_service.h"
#include "base/test/launcher/unit_test_launcher.h"
#include "base/test/test_suite.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "ui/android/ui_android_jni_registrar.h"
#include "ui/base/resource/resource_bundle.h"
#include "ui/base/ui_base_paths.h"
#include "ui/gfx/android/gfx_jni_registrar.h"

namespace {

class UIAndroidTestSuite : public base::TestSuite {
public:
    UIAndroidTestSuite(int argc, char** argv)
        : base::TestSuite(argc, argv)
    {
    }

protected:
    void Initialize() override
    {
        base::TestSuite::Initialize();

        gfx::android::RegisterJni(base::android::AttachCurrentThread());
        ui::RegisterUIAndroidJni(base::android::AttachCurrentThread());

        ui::RegisterPathProvider();

        base::FilePath ui_test_pak_path;
        ASSERT_TRUE(PathService::Get(ui::UI_TEST_PAK, &ui_test_pak_path));
        ui::ResourceBundle::InitSharedInstanceWithPakPath(ui_test_pak_path);
    }

    void Shutdown() override
    {
        ui::ResourceBundle::CleanupSharedInstance();
        base::TestSuite::Shutdown();
    }

private:
    DISALLOW_COPY_AND_ASSIGN(UIAndroidTestSuite);
};

} // namespace

int main(int argc, char** argv)
{
    UIAndroidTestSuite test_suite(argc, argv);

    return base::LaunchUnitTests(
        argc, argv,
        base::Bind(&UIAndroidTestSuite::Run, base::Unretained(&test_suite)));
}
