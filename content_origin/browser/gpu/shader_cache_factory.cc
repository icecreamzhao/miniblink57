// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/gpu/shader_cache_factory.h"

#include "base/single_thread_task_runner.h"
#include "gpu/ipc/host/shader_disk_cache.h"

namespace content {

namespace {

    gpu::ShaderCacheFactory* factory_instance = nullptr;

    void CreateFactoryInstance(
        scoped_refptr<base::SingleThreadTaskRunner> cache_task_runner)
    {
        DCHECK(!factory_instance);
        factory_instance = new gpu::ShaderCacheFactory(std::move(cache_task_runner));
    }

} // namespace

void InitShaderCacheFactorySingleton(
    scoped_refptr<base::SingleThreadTaskRunner> task_runner,
    scoped_refptr<base::SingleThreadTaskRunner> cache_task_runner)
{
    if (task_runner->BelongsToCurrentThread()) {
        CreateFactoryInstance(std::move(cache_task_runner));
    } else {
        task_runner->PostTask(FROM_HERE, base::Bind(&CreateFactoryInstance, std::move(cache_task_runner)));
    }
}

gpu::ShaderCacheFactory* GetShaderCacheFactorySingleton()
{
    DCHECK(!factory_instance || factory_instance->CalledOnValidThread());
    return factory_instance;
}

} // namespace content
