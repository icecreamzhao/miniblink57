/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkSurface_Gpu_DEFINED
#define SkSurface_Gpu_DEFINED

#include "SkSurface_Base.h"

#if SK_SUPPORT_GPU

class SkGpuDevice;

class SkSurface_Gpu : public SkSurface_Base {
public:
<<<<<<< HEAD
    SkSurface_Gpu(sk_sp<SkGpuDevice>);
=======
    SkSurface_Gpu(SkGpuDevice*);
>>>>>>> miniblink49
    virtual ~SkSurface_Gpu();

    GrBackendObject onGetTextureHandle(BackendHandleAccess) override;
    bool onGetRenderTargetHandle(GrBackendObject*, BackendHandleAccess) override;
    SkCanvas* onNewCanvas() override;
<<<<<<< HEAD
    sk_sp<SkSurface> onNewSurface(const SkImageInfo&) override;
    sk_sp<SkImage> onNewImageSnapshot(SkBudgeted, ForceCopyMode) override;
    void onCopyOnWrite(ContentChangeMode) override;
    void onDiscard() override;
    void onPrepareForExternalIO() override;

    SkGpuDevice* getDevice() { return fDevice.get(); }

private:
    sk_sp<SkGpuDevice> fDevice;
=======
    SkSurface* onNewSurface(const SkImageInfo&) override;
    SkImage* onNewImageSnapshot(Budgeted) override;
    void onCopyOnWrite(ContentChangeMode) override;
    void onDiscard() override;

    SkGpuDevice* getDevice() { return fDevice; }

private:
    SkGpuDevice* fDevice;
>>>>>>> miniblink49

    typedef SkSurface_Base INHERITED;
};

#endif // SK_SUPPORT_GPU

#endif // SkSurface_Gpu_DEFINED
