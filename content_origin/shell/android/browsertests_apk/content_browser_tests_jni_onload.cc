// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/android/base_jni_registrar.h"
#include "base/android/jni_android.h"
#include "base/bind.h"
#include "content/public/app/content_jni_onload.h"
#include "content/public/app/content_main.h"
#include "content/shell/android/shell_jni_registrar.h"
#include "content/shell/app/shell_main_delegate.h"
#include "testing/android/native_test/native_test_launcher.h"

namespace {

bool RegisterJNI(JNIEnv* env)
{
    return base::android::RegisterJni(env) && content::android::RegisterShellJni(env) && testing::android::RegisterNativeTestJNI(env);
}

bool Init()
{
    content::SetContentMainDelegate(new content::ShellMainDelegate());
    return true;
}

} // namespace

// This is called by the VM when the shared library is first loaded.
JNI_EXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    std::vector<base::android::RegisterCallback> register_callbacks;
    register_callbacks.push_back(base::Bind(&RegisterJNI));
    std::vector<base::android::InitCallback> init_callbacks;
    init_callbacks.push_back(base::Bind(&Init));
    if (!content::android::OnJNIOnLoadRegisterJNI(vm, register_callbacks) || !content::android::OnJNIOnLoadInit(init_callbacks)) {
        return -1;
    }
    return JNI_VERSION_1_4;
}
