/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrVkRenderTarget.h"

#include "GrRenderTargetPriv.h"
#include "GrVkCommandBuffer.h"
#include "GrVkFramebuffer.h"
#include "GrVkGpu.h"
#include "GrVkImageView.h"
#include "GrVkResourceProvider.h"
#include "GrVkUtil.h"

#include "vk/GrVkTypes.h"

#define VK_CALL(GPU, X) GR_VK_CALL(GPU->vkInterface(), X)

// We're virtually derived from GrSurface (via GrRenderTarget) so its
// constructor must be explicitly called.
GrVkRenderTarget::GrVkRenderTarget(GrVkGpu* gpu,
    SkBudgeted budgeted,
    const GrSurfaceDesc& desc,
    const GrVkImageInfo& info,
    const GrVkImageInfo& msaaInfo,
    const GrVkImageView* colorAttachmentView,
    const GrVkImageView* resolveAttachmentView,
    GrVkImage::Wrapped wrapped)
    : GrSurface(gpu, desc)
    , GrVkImage(info, wrapped)
    // for the moment we only support 1:1 color to stencil
    , GrRenderTarget(gpu, desc, kUnified_SampleConfig)
    , fFramebuffer(nullptr)
    , fColorAttachmentView(colorAttachmentView)
    , fMSAAImage(new GrVkImage(msaaInfo, GrVkImage::kNot_Wrapped))
    , fResolveAttachmentView(resolveAttachmentView)
    , fCachedSimpleRenderPass(nullptr)
{
    SkASSERT(desc.fSampleCnt);
    // The plus 1 is to account for the resolve texture.
    fColorValuesPerPixel = desc.fSampleCnt + 1; // TODO: this still correct?
    this->createFramebuffer(gpu);
    this->registerWithCache(budgeted);
}

// We're virtually derived from GrSurface (via GrRenderTarget) so its
// constructor must be explicitly called.
GrVkRenderTarget::GrVkRenderTarget(GrVkGpu* gpu,
    const GrSurfaceDesc& desc,
    const GrVkImageInfo& info,
    const GrVkImageInfo& msaaInfo,
    const GrVkImageView* colorAttachmentView,
    const GrVkImageView* resolveAttachmentView,
    GrVkImage::Wrapped wrapped)
    : GrSurface(gpu, desc)
    , GrVkImage(info, wrapped)
    // for the moment we only support 1:1 color to stencil
    , GrRenderTarget(gpu, desc, kUnified_SampleConfig)
    , fFramebuffer(nullptr)
    , fColorAttachmentView(colorAttachmentView)
    , fMSAAImage(new GrVkImage(msaaInfo, GrVkImage::kNot_Wrapped))
    , fResolveAttachmentView(resolveAttachmentView)
    , fCachedSimpleRenderPass(nullptr)
{
    SkASSERT(desc.fSampleCnt);
    // The plus 1 is to account for the resolve texture.
    fColorValuesPerPixel = desc.fSampleCnt + 1; // TODO: this still correct?
    this->createFramebuffer(gpu);
}

// We're virtually derived from GrSurface (via GrRenderTarget) so its
// constructor must be explicitly called.
GrVkRenderTarget::GrVkRenderTarget(GrVkGpu* gpu,
    SkBudgeted budgeted,
    const GrSurfaceDesc& desc,
    const GrVkImageInfo& info,
    const GrVkImageView* colorAttachmentView,
    GrVkImage::Wrapped wrapped)
    : GrSurface(gpu, desc)
    , GrVkImage(info, wrapped)
    , GrRenderTarget(gpu, desc, kUnified_SampleConfig)
    , fFramebuffer(nullptr)
    , fColorAttachmentView(colorAttachmentView)
    , fMSAAImage(nullptr)
    , fResolveAttachmentView(nullptr)
    , fCachedSimpleRenderPass(nullptr)
{
    SkASSERT(!desc.fSampleCnt);
    fColorValuesPerPixel = 1;
    this->createFramebuffer(gpu);
    this->registerWithCache(budgeted);
}

// We're virtually derived from GrSurface (via GrRenderTarget) so its
// constructor must be explicitly called.
GrVkRenderTarget::GrVkRenderTarget(GrVkGpu* gpu,
    const GrSurfaceDesc& desc,
    const GrVkImageInfo& info,
    const GrVkImageView* colorAttachmentView,
    GrVkImage::Wrapped wrapped)
    : GrSurface(gpu, desc)
    , GrVkImage(info, wrapped)
    , GrRenderTarget(gpu, desc, kUnified_SampleConfig)
    , fFramebuffer(nullptr)
    , fColorAttachmentView(colorAttachmentView)
    , fMSAAImage(nullptr)
    , fResolveAttachmentView(nullptr)
    , fCachedSimpleRenderPass(nullptr)
{
    SkASSERT(!desc.fSampleCnt);
    fColorValuesPerPixel = 1;
    this->createFramebuffer(gpu);
}

GrVkRenderTarget*
GrVkRenderTarget::Create(GrVkGpu* gpu,
    SkBudgeted budgeted,
    const GrSurfaceDesc& desc,
    const GrVkImageInfo& info,
    GrVkImage::Wrapped wrapped)
{
    VkFormat pixelFormat;
    GrPixelConfigToVkFormat(desc.fConfig, &pixelFormat);

    VkImage colorImage;

    // create msaa surface if necessary
    GrVkImageInfo msInfo;
    const GrVkImageView* resolveAttachmentView = nullptr;
    if (desc.fSampleCnt) {
        GrVkImage::ImageDesc msImageDesc;
        msImageDesc.fImageType = VK_IMAGE_TYPE_2D;
        msImageDesc.fFormat = pixelFormat;
        msImageDesc.fWidth = desc.fWidth;
        msImageDesc.fHeight = desc.fHeight;
        msImageDesc.fLevels = 1;
        msImageDesc.fSamples = desc.fSampleCnt;
        msImageDesc.fImageTiling = VK_IMAGE_TILING_OPTIMAL;
        msImageDesc.fUsageFlags = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        msImageDesc.fMemProps = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;

        if (!GrVkImage::InitImageInfo(gpu, msImageDesc, &msInfo)) {
            return nullptr;
        }

        // Set color attachment image
        colorImage = msInfo.fImage;

        // Create Resolve attachment view
        resolveAttachmentView = GrVkImageView::Create(gpu, info.fImage, pixelFormat,
            GrVkImageView::kColor_Type, 1);
        if (!resolveAttachmentView) {
            GrVkImage::DestroyImageInfo(gpu, &msInfo);
            return nullptr;
        }
    } else {
        // Set color attachment image
        colorImage = info.fImage;
    }

    // Get color attachment view
    const GrVkImageView* colorAttachmentView = GrVkImageView::Create(gpu, colorImage, pixelFormat,
        GrVkImageView::kColor_Type, 1);
    if (!colorAttachmentView) {
        if (desc.fSampleCnt) {
            resolveAttachmentView->unref(gpu);
            GrVkImage::DestroyImageInfo(gpu, &msInfo);
        }
        return nullptr;
    }

    GrVkRenderTarget* texRT;
    if (desc.fSampleCnt) {
        texRT = new GrVkRenderTarget(gpu, budgeted, desc, info, msInfo,
            colorAttachmentView, resolveAttachmentView, wrapped);
    } else {
        texRT = new GrVkRenderTarget(gpu, budgeted, desc, info, colorAttachmentView, wrapped);
    }

    return texRT;
}

GrVkRenderTarget*
GrVkRenderTarget::CreateNewRenderTarget(GrVkGpu* gpu,
    SkBudgeted budgeted,
    const GrSurfaceDesc& desc,
    const GrVkImage::ImageDesc& imageDesc)
{
    SkASSERT(imageDesc.fUsageFlags & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT);

    GrVkImageInfo info;
    if (!GrVkImage::InitImageInfo(gpu, imageDesc, &info)) {
        return nullptr;
    }

    GrVkRenderTarget* rt = GrVkRenderTarget::Create(gpu, budgeted, desc, info,
        GrVkImage::kNot_Wrapped);
    if (!rt) {
        GrVkImage::DestroyImageInfo(gpu, &info);
    }
    return rt;
}

GrVkRenderTarget*
GrVkRenderTarget::CreateWrappedRenderTarget(GrVkGpu* gpu,
    const GrSurfaceDesc& desc,
    GrWrapOwnership ownership,
    const GrVkImageInfo* info)
{
    SkASSERT(info);
    // We can wrap a rendertarget without its allocation, as long as we don't take ownership
    SkASSERT(VK_NULL_HANDLE != info->fImage);
    SkASSERT(VK_NULL_HANDLE != info->fAlloc.fMemory || kAdopt_GrWrapOwnership != ownership);

    GrVkImage::Wrapped wrapped = kBorrow_GrWrapOwnership == ownership ? GrVkImage::kBorrowed_Wrapped
                                                                      : GrVkImage::kAdopted_Wrapped;

    GrVkRenderTarget* rt = GrVkRenderTarget::Create(gpu, SkBudgeted::kNo, desc, *info, wrapped);

    return rt;
}

bool GrVkRenderTarget::completeStencilAttachment()
{
    this->createFramebuffer(this->getVkGpu());
    return true;
}

void GrVkRenderTarget::createFramebuffer(GrVkGpu* gpu)
{
    if (fFramebuffer) {
        fFramebuffer->unref(gpu);
    }
    if (fCachedSimpleRenderPass) {
        fCachedSimpleRenderPass->unref(gpu);
    }

    // Vulkan requires us to create a compatible renderpass before we can create our framebuffer,
    // so we use this to get a (cached) basic renderpass, only for creation.
    fCachedSimpleRenderPass = gpu->resourceProvider().findCompatibleRenderPass(*this, &fCompatibleRPHandle);

    // Stencil attachment view is stored in the base RT stencil attachment
    const GrVkImageView* stencilView = this->stencilAttachmentView();
    fFramebuffer = GrVkFramebuffer::Create(gpu, this->width(), this->height(),
        fCachedSimpleRenderPass, fColorAttachmentView,
        fResolveAttachmentView, stencilView);
    SkASSERT(fFramebuffer);
}

void GrVkRenderTarget::getAttachmentsDescriptor(
    GrVkRenderPass::AttachmentsDescriptor* desc,
    GrVkRenderPass::AttachmentFlags* attachmentFlags) const
{
    int colorSamples = this->numColorSamples();
    VkFormat colorFormat;
    GrPixelConfigToVkFormat(this->config(), &colorFormat);
    desc->fColor.fFormat = colorFormat;
    desc->fColor.fSamples = colorSamples ? colorSamples : 1;
    *attachmentFlags = GrVkRenderPass::kColor_AttachmentFlag;
    uint32_t attachmentCount = 1;
    if (colorSamples > 0) {
        desc->fResolve.fFormat = colorFormat;
        desc->fResolve.fSamples = 1;
        *attachmentFlags |= GrVkRenderPass::kResolve_AttachmentFlag;
        ++attachmentCount;
    }

    const GrStencilAttachment* stencil = this->renderTargetPriv().getStencilAttachment();
    if (stencil) {
        const GrVkStencilAttachment* vkStencil = static_cast<const GrVkStencilAttachment*>(stencil);
        desc->fStencil.fFormat = vkStencil->vkFormat();
        desc->fStencil.fSamples = vkStencil->numSamples() ? vkStencil->numSamples() : 1;
        // Currently in vulkan stencil and color attachments must all have same number of samples
        SkASSERT(desc->fColor.fSamples == desc->fStencil.fSamples);
        *attachmentFlags |= GrVkRenderPass::kStencil_AttachmentFlag;
        ++attachmentCount;
    }
    desc->fAttachmentCount = attachmentCount;
}

GrVkRenderTarget::~GrVkRenderTarget()
{
    // either release or abandon should have been called by the owner of this object.
    SkASSERT(!fMSAAImage);
    SkASSERT(!fResolveAttachmentView);
    SkASSERT(!fColorAttachmentView);
    SkASSERT(!fFramebuffer);
    SkASSERT(!fCachedSimpleRenderPass);
}

void GrVkRenderTarget::addResources(GrVkCommandBuffer& commandBuffer) const
{
    commandBuffer.addResource(this->framebuffer());
    commandBuffer.addResource(this->resource());
    commandBuffer.addResource(this->colorAttachmentView());
    if (this->msaaImageResource()) {
        commandBuffer.addResource(this->msaaImageResource());
        commandBuffer.addResource(this->resolveAttachmentView());
    }
    if (this->stencilImageResource()) {
        commandBuffer.addResource(this->stencilImageResource());
        commandBuffer.addResource(this->stencilAttachmentView());
    }
}

void GrVkRenderTarget::releaseInternalObjects()
{
    GrVkGpu* gpu = this->getVkGpu();

    if (fMSAAImage) {
        fMSAAImage->releaseImage(gpu);
        fMSAAImage = nullptr;
    }

    if (fResolveAttachmentView) {
        fResolveAttachmentView->unref(gpu);
        fResolveAttachmentView = nullptr;
    }
    if (fColorAttachmentView) {
        fColorAttachmentView->unref(gpu);
        fColorAttachmentView = nullptr;
    }
    if (fFramebuffer) {
        fFramebuffer->unref(gpu);
        fFramebuffer = nullptr;
    }
    if (fCachedSimpleRenderPass) {
        fCachedSimpleRenderPass->unref(gpu);
        fCachedSimpleRenderPass = nullptr;
    }
}

void GrVkRenderTarget::abandonInternalObjects()
{
    if (fMSAAImage) {
        fMSAAImage->abandonImage();
        fMSAAImage = nullptr;
    }

    if (fResolveAttachmentView) {
        fResolveAttachmentView->unrefAndAbandon();
        fResolveAttachmentView = nullptr;
    }
    if (fColorAttachmentView) {
        fColorAttachmentView->unrefAndAbandon();
        fColorAttachmentView = nullptr;
    }
    if (fFramebuffer) {
        fFramebuffer->unrefAndAbandon();
        fFramebuffer = nullptr;
    }
    if (fCachedSimpleRenderPass) {
        fCachedSimpleRenderPass->unrefAndAbandon();
        fCachedSimpleRenderPass = nullptr;
    }
}

void GrVkRenderTarget::onRelease()
{
    this->releaseInternalObjects();
    this->releaseImage(this->getVkGpu());
    GrRenderTarget::onRelease();
}

void GrVkRenderTarget::onAbandon()
{
    this->abandonInternalObjects();
    this->abandonImage();
    GrRenderTarget::onAbandon();
}

GrBackendObject GrVkRenderTarget::getRenderTargetHandle() const
{
    // Currently just passing back the pointer to the main Image::Resource as the handle
    return (GrBackendObject)&fResource;
}

const GrVkResource* GrVkRenderTarget::stencilImageResource() const
{
    const GrStencilAttachment* stencil = this->renderTargetPriv().getStencilAttachment();
    if (stencil) {
        const GrVkStencilAttachment* vkStencil = static_cast<const GrVkStencilAttachment*>(stencil);
        return vkStencil->imageResource();
    }

    return nullptr;
}

const GrVkImageView* GrVkRenderTarget::stencilAttachmentView() const
{
    const GrStencilAttachment* stencil = this->renderTargetPriv().getStencilAttachment();
    if (stencil) {
        const GrVkStencilAttachment* vkStencil = static_cast<const GrVkStencilAttachment*>(stencil);
        return vkStencil->stencilView();
    }

    return nullptr;
}

GrVkGpu* GrVkRenderTarget::getVkGpu() const
{
    SkASSERT(!this->wasDestroyed());
    return static_cast<GrVkGpu*>(this->getGpu());
}
