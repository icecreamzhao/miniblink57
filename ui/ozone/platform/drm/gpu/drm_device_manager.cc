// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/ozone/platform/drm/gpu/drm_device_manager.h"

#include <utility>

#include "base/file_descriptor_posix.h"
#include "base/single_thread_task_runner.h"
#include "ui/ozone/platform/drm/gpu/drm_device.h"
#include "ui/ozone/platform/drm/gpu/drm_device_generator.h"

namespace ui {

namespace {

    class FindByDevicePath {
    public:
        explicit FindByDevicePath(const base::FilePath& path)
            : path_(path)
        {
        }

        bool operator()(const scoped_refptr<DrmDevice>& device)
        {
            return device->device_path() == path_;
        }

    private:
        base::FilePath path_;
    };

} // namespace

DrmDeviceManager::DrmDeviceManager(
    scoped_ptr<DrmDeviceGenerator> drm_device_generator)
    : drm_device_generator_(std::move(drm_device_generator))
{
}

DrmDeviceManager::~DrmDeviceManager()
{
    DCHECK(drm_device_map_.empty());
}

bool DrmDeviceManager::AddDrmDevice(const base::FilePath& path,
    const base::FileDescriptor& fd)
{
    base::File file(fd.fd);
    auto it = std::find_if(devices_.begin(), devices_.end(), FindByDevicePath(path));
    if (it != devices_.end()) {
        VLOG(2) << "Got request to add existing device: " << path.value();
        return false;
    }

    scoped_refptr<DrmDevice> device = drm_device_generator_->CreateDevice(
        path, std::move(file), !primary_device_);
    if (!device) {
        LOG(ERROR) << "Could not initialize DRM device for " << path.value();
        return false;
    }

    if (!primary_device_)
        primary_device_ = device;

    devices_.push_back(device);
    return true;
}

void DrmDeviceManager::RemoveDrmDevice(const base::FilePath& path)
{
    auto it = std::find_if(devices_.begin(), devices_.end(), FindByDevicePath(path));
    if (it == devices_.end()) {
        VLOG(2) << "Got request to remove non-existent device: " << path.value();
        return;
    }

    DCHECK_NE(primary_device_, *it);
    devices_.erase(it);
}

void DrmDeviceManager::UpdateDrmDevice(gfx::AcceleratedWidget widget,
    const scoped_refptr<DrmDevice>& device)
{
    drm_device_map_[widget] = device;
}

void DrmDeviceManager::RemoveDrmDevice(gfx::AcceleratedWidget widget)
{
    auto it = drm_device_map_.find(widget);
    if (it != drm_device_map_.end())
        drm_device_map_.erase(it);
}

scoped_refptr<DrmDevice> DrmDeviceManager::GetDrmDevice(
    gfx::AcceleratedWidget widget)
{
    if (widget == gfx::kNullAcceleratedWidget)
        return primary_device_;

    auto it = drm_device_map_.find(widget);
    DCHECK(it != drm_device_map_.end())
        << "Attempting to get device for unknown widget " << widget;
    // If the widget isn't associated with a display (headless mode) we can
    // allocate buffers from any controller since they will never be scanned out.
    // Use the primary DRM device as a fallback when allocating these buffers.
    if (!it->second)
        return primary_device_;

    return it->second;
}

const DrmDeviceVector& DrmDeviceManager::GetDrmDevices() const
{
    return devices_;
}

} // namespace ui
