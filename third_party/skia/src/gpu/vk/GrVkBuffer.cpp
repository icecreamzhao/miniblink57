/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrVkBuffer.h"
#include "GrVkGpu.h"
#include "GrVkMemory.h"
#include "GrVkUtil.h"

#define VK_CALL(GPU, X) GR_VK_CALL(GPU->vkInterface(), X)

#ifdef SK_DEBUG
#define VALIDATE() this->validate()
#else
#define VALIDATE() \
    do {           \
    } while (false)
#endif

const GrVkBuffer::Resource* GrVkBuffer::Create(const GrVkGpu* gpu, const Desc& desc)
{
    VkBuffer buffer;
    GrVkAlloc alloc;

    // create the buffer object
    VkBufferCreateInfo bufInfo;
    memset(&bufInfo, 0, sizeof(VkBufferCreateInfo));
    bufInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufInfo.flags = 0;
    bufInfo.size = desc.fSizeInBytes;
    switch (desc.fType) {
    case kVertex_Type:
        bufInfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
        break;
    case kIndex_Type:
        bufInfo.usage = VK_BUFFER_USAGE_INDEX_BUFFER_BIT;
        break;
    case kUniform_Type:
        bufInfo.usage = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT;
        break;
    case kCopyRead_Type:
        bufInfo.usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
        break;
    case kCopyWrite_Type:
        bufInfo.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        break;
    }
    bufInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    bufInfo.queueFamilyIndexCount = 0;
    bufInfo.pQueueFamilyIndices = nullptr;

    VkResult err;
    err = VK_CALL(gpu, CreateBuffer(gpu->device(), &bufInfo, nullptr, &buffer));
    if (err) {
        return nullptr;
    }

    if (!GrVkMemory::AllocAndBindBufferMemory(gpu,
            buffer,
            desc.fType,
            &alloc)) {
        return nullptr;
    }

    const GrVkBuffer::Resource* resource = new GrVkBuffer::Resource(buffer, alloc, desc.fType);
    if (!resource) {
        VK_CALL(gpu, DestroyBuffer(gpu->device(), buffer, nullptr));
        GrVkMemory::FreeBufferMemory(gpu, desc.fType, alloc);
        return nullptr;
    }

    return resource;
}

void GrVkBuffer::addMemoryBarrier(const GrVkGpu* gpu,
    VkAccessFlags srcAccessMask,
    VkAccessFlags dstAccesMask,
    VkPipelineStageFlags srcStageMask,
    VkPipelineStageFlags dstStageMask,
    bool byRegion) const
{
    VkBufferMemoryBarrier bufferMemoryBarrier = {
        VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER, // sType
        NULL, // pNext
        srcAccessMask, // srcAccessMask
        dstAccesMask, // dstAccessMask
        VK_QUEUE_FAMILY_IGNORED, // srcQueueFamilyIndex
        VK_QUEUE_FAMILY_IGNORED, // dstQueueFamilyIndex
        this->buffer(), // buffer
        0, // offset
        fDesc.fSizeInBytes, // size
    };

    // TODO: restrict to area of buffer we're interested in
    gpu->addBufferMemoryBarrier(srcStageMask, dstStageMask, byRegion, &bufferMemoryBarrier);
}

void GrVkBuffer::Resource::freeGPUData(const GrVkGpu* gpu) const
{
    SkASSERT(fBuffer);
    SkASSERT(fAlloc.fMemory);
    VK_CALL(gpu, DestroyBuffer(gpu->device(), fBuffer, nullptr));
    GrVkMemory::FreeBufferMemory(gpu, fType, fAlloc);
}

void GrVkBuffer::vkRelease(const GrVkGpu* gpu)
{
    VALIDATE();
    fResource->unref(gpu);
    fResource = nullptr;
    fMapPtr = nullptr;
    VALIDATE();
}

void GrVkBuffer::vkAbandon()
{
    fResource->unrefAndAbandon();
    fResource = nullptr;
    fMapPtr = nullptr;
    VALIDATE();
}

void* GrVkBuffer::vkMap(const GrVkGpu* gpu)
{
    VALIDATE();
    SkASSERT(!this->vkIsMapped());

    if (!fResource->unique()) {
        // in use by the command buffer, so we need to create a new one
        fResource->unref(gpu);
        fResource = Create(gpu, fDesc);
    }

    const GrVkAlloc& alloc = this->alloc();
    VkResult err = VK_CALL(gpu, MapMemory(gpu->device(), alloc.fMemory, alloc.fOffset, VK_WHOLE_SIZE, 0, &fMapPtr));
    if (err) {
        fMapPtr = nullptr;
    }

    VALIDATE();
    return fMapPtr;
}

void GrVkBuffer::vkUnmap(const GrVkGpu* gpu)
{
    VALIDATE();
    SkASSERT(this->vkIsMapped());

    VK_CALL(gpu, UnmapMemory(gpu->device(), this->alloc().fMemory));

    fMapPtr = nullptr;
}

bool GrVkBuffer::vkIsMapped() const
{
    VALIDATE();
    return SkToBool(fMapPtr);
}

bool GrVkBuffer::vkUpdateData(const GrVkGpu* gpu, const void* src, size_t srcSizeInBytes,
    bool* createdNewBuffer)
{
    SkASSERT(!this->vkIsMapped());
    VALIDATE();
    if (srcSizeInBytes > fDesc.fSizeInBytes) {
        return false;
    }

    if (!fResource->unique()) {
        // in use by the command buffer, so we need to create a new one
        fResource->unref(gpu);
        fResource = Create(gpu, fDesc);
        if (createdNewBuffer) {
            *createdNewBuffer = true;
        }
    }

    void* mapPtr;
    const GrVkAlloc& alloc = this->alloc();
    VkResult err = VK_CALL(gpu, MapMemory(gpu->device(), alloc.fMemory, alloc.fOffset, srcSizeInBytes, 0, &mapPtr));

    if (VK_SUCCESS != err) {
        return false;
    }

    memcpy(mapPtr, src, srcSizeInBytes);

    VK_CALL(gpu, UnmapMemory(gpu->device(), alloc.fMemory));

    return true;
}

void GrVkBuffer::validate() const
{
    SkASSERT(!fResource || kVertex_Type == fDesc.fType || kIndex_Type == fDesc.fType
        || kCopyRead_Type == fDesc.fType || kCopyWrite_Type == fDesc.fType
        || kUniform_Type == fDesc.fType);
}
