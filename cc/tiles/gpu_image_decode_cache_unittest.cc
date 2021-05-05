// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cc/tiles/gpu_image_decode_cache.h"

#include "cc/playback/draw_image.h"
#include "cc/test/test_context_provider.h"
#include "cc/test/test_tile_task_runner.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "third_party/skia/include/core/SkRefCnt.h"

namespace cc {
namespace {

    size_t kGpuMemoryLimitBytes = 96 * 1024 * 1024;
    class TestGpuImageDecodeCache : public GpuImageDecodeCache {
    public:
        explicit TestGpuImageDecodeCache(ContextProvider* context)
            : GpuImageDecodeCache(context,
                ResourceFormat::RGBA_8888,
                kGpuMemoryLimitBytes)
        {
        }
    };

    sk_sp<SkImage> CreateImage(int width, int height)
    {
        SkBitmap bitmap;
        bitmap.allocPixels(SkImageInfo::MakeN32Premul(width, height));
        return SkImage::MakeFromBitmap(bitmap);
    }

    SkMatrix CreateMatrix(const SkSize& scale, bool is_decomposable)
    {
        SkMatrix matrix;
        matrix.setScale(scale.width(), scale.height());

        if (!is_decomposable) {
            // Perspective is not decomposable, add it.
            matrix[SkMatrix::kMPersp0] = 0.1f;
        }

        return matrix;
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageSameImage)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        sk_sp<SkImage> image = CreateImage(100, 100);
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(1.5f, 1.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        DrawImage another_draw_image(
            image, SkIRect::MakeWH(image->width(), image->height()), quality,
            CreateMatrix(SkSize::Make(1.5f, 1.5f), is_decomposable));
        scoped_refptr<TileTask> another_task;
        need_unref = cache.GetTaskForImageAndRef(
            another_draw_image, ImageDecodeCache::TracingInfo(), &another_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task.get() == another_task.get());

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());

        cache.UnrefImage(draw_image);
        cache.UnrefImage(draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageSmallerScale)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        sk_sp<SkImage> image = CreateImage(100, 100);
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(1.5f, 1.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        DrawImage another_draw_image(
            image, SkIRect::MakeWH(image->width(), image->height()), quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> another_task;
        need_unref = cache.GetTaskForImageAndRef(
            another_draw_image, ImageDecodeCache::TracingInfo(), &another_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task.get() == another_task.get());

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());

        cache.UnrefImage(draw_image);
        cache.UnrefImage(another_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageLowerQuality)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        sk_sp<SkImage> image = CreateImage(100, 100);
        bool is_decomposable = true;
        SkMatrix matrix = CreateMatrix(SkSize::Make(0.4f, 0.4f), is_decomposable);

        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            kHigh_SkFilterQuality, matrix);
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        DrawImage another_draw_image(image,
            SkIRect::MakeWH(image->width(), image->height()),
            kLow_SkFilterQuality, matrix);
        scoped_refptr<TileTask> another_task;
        need_unref = cache.GetTaskForImageAndRef(
            another_draw_image, ImageDecodeCache::TracingInfo(), &another_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task.get() == another_task.get());

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());

        cache.UnrefImage(draw_image);
        cache.UnrefImage(another_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageDifferentImage)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> first_image = CreateImage(100, 100);
        DrawImage first_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            quality, CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> first_task;
        bool need_unref = cache.GetTaskForImageAndRef(
            first_draw_image, ImageDecodeCache::TracingInfo(), &first_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(first_task);

        sk_sp<SkImage> second_image = CreateImage(100, 100);
        DrawImage second_draw_image(
            second_image,
            SkIRect::MakeWH(second_image->width(), second_image->height()), quality,
            CreateMatrix(SkSize::Make(0.25f, 0.25f), is_decomposable));
        scoped_refptr<TileTask> second_task;
        need_unref = cache.GetTaskForImageAndRef(
            second_draw_image, ImageDecodeCache::TracingInfo(), &second_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(second_task);
        EXPECT_TRUE(first_task.get() != second_task.get());

        TestTileTaskRunner::ProcessTask(first_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(first_task.get());
        TestTileTaskRunner::ProcessTask(second_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(second_task.get());

        cache.UnrefImage(first_draw_image);
        cache.UnrefImage(second_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageLargerScale)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> first_image = CreateImage(100, 100);
        DrawImage first_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            quality, CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> first_task;
        bool need_unref = cache.GetTaskForImageAndRef(
            first_draw_image, ImageDecodeCache::TracingInfo(), &first_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(first_task);

        TestTileTaskRunner::ProcessTask(first_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(first_task.get());

        cache.UnrefImage(first_draw_image);

        DrawImage second_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            quality, CreateMatrix(SkSize::Make(1.0f, 1.0f), is_decomposable));
        scoped_refptr<TileTask> second_task;
        need_unref = cache.GetTaskForImageAndRef(
            second_draw_image, ImageDecodeCache::TracingInfo(), &second_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(second_task);
        EXPECT_TRUE(first_task.get() != second_task.get());

        DrawImage third_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            quality, CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> third_task;
        need_unref = cache.GetTaskForImageAndRef(
            third_draw_image, ImageDecodeCache::TracingInfo(), &third_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(third_task.get() == second_task.get());

        TestTileTaskRunner::ProcessTask(second_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(second_task.get());

        cache.UnrefImage(second_draw_image);
        cache.UnrefImage(third_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageLargerScaleNoReuse)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> first_image = CreateImage(100, 100);
        DrawImage first_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            quality, CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> first_task;
        bool need_unref = cache.GetTaskForImageAndRef(
            first_draw_image, ImageDecodeCache::TracingInfo(), &first_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(first_task);

        DrawImage second_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            quality, CreateMatrix(SkSize::Make(1.0f, 1.0f), is_decomposable));
        scoped_refptr<TileTask> second_task;
        need_unref = cache.GetTaskForImageAndRef(
            second_draw_image, ImageDecodeCache::TracingInfo(), &second_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(second_task);
        EXPECT_TRUE(first_task.get() != second_task.get());

        DrawImage third_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            quality, CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> third_task;
        need_unref = cache.GetTaskForImageAndRef(
            third_draw_image, ImageDecodeCache::TracingInfo(), &third_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(third_task.get() == first_task.get());

        TestTileTaskRunner::ProcessTask(first_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(first_task.get());
        TestTileTaskRunner::ProcessTask(second_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(second_task.get());

        cache.UnrefImage(first_draw_image);
        cache.UnrefImage(second_draw_image);
        cache.UnrefImage(third_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageHigherQuality)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkMatrix matrix = CreateMatrix(SkSize::Make(0.4f, 0.4f), is_decomposable);

        sk_sp<SkImage> first_image = CreateImage(100, 100);
        DrawImage first_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            kLow_SkFilterQuality, matrix);
        scoped_refptr<TileTask> first_task;
        bool need_unref = cache.GetTaskForImageAndRef(
            first_draw_image, ImageDecodeCache::TracingInfo(), &first_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(first_task);

        TestTileTaskRunner::ProcessTask(first_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(first_task.get());

        cache.UnrefImage(first_draw_image);

        DrawImage second_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            kHigh_SkFilterQuality, matrix);
        scoped_refptr<TileTask> second_task;
        need_unref = cache.GetTaskForImageAndRef(
            second_draw_image, ImageDecodeCache::TracingInfo(), &second_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(second_task);
        EXPECT_TRUE(first_task.get() != second_task.get());

        TestTileTaskRunner::ProcessTask(second_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(second_task.get());

        cache.UnrefImage(second_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageAlreadyDecodedAndLocked)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);
        EXPECT_EQ(task->dependencies().size(), 1u);
        EXPECT_TRUE(task->dependencies()[0]);

        // Run the decode but don't complete it (this will keep the decode locked).
        TestTileTaskRunner::ScheduleTask(task->dependencies()[0].get());
        TestTileTaskRunner::RunTask(task->dependencies()[0].get());

        // Cancel the upload.
        TestTileTaskRunner::CancelTask(task.get());
        TestTileTaskRunner::CompleteTask(task.get());

        // Get the image again - we should have an upload task, but no dependent
        // decode task, as the decode was already locked.
        scoped_refptr<TileTask> another_task;
        need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &another_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(another_task);
        EXPECT_EQ(another_task->dependencies().size(), 0u);

        TestTileTaskRunner::ProcessTask(another_task.get());

        // Finally, complete the original decode task.
        TestTileTaskRunner::CompleteTask(task->dependencies()[0].get());

        cache.UnrefImage(draw_image);
        cache.UnrefImage(draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageAlreadyDecodedNotLocked)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);
        EXPECT_EQ(task->dependencies().size(), 1u);
        EXPECT_TRUE(task->dependencies()[0]);

        // Run the decode.
        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());

        // Cancel the upload.
        TestTileTaskRunner::CancelTask(task.get());
        TestTileTaskRunner::CompleteTask(task.get());

        // Unref the image.
        cache.UnrefImage(draw_image);

        // Get the image again - we should have an upload task and a dependent decode
        // task - this dependent task will typically just re-lock the image.
        scoped_refptr<TileTask> another_task;
        need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &another_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(another_task);
        EXPECT_EQ(another_task->dependencies().size(), 1u);
        EXPECT_TRUE(task->dependencies()[0]);

        TestTileTaskRunner::ProcessTask(another_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(another_task.get());

        cache.UnrefImage(draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageAlreadyUploaded)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);
        EXPECT_EQ(task->dependencies().size(), 1u);
        EXPECT_TRUE(task->dependencies()[0]);

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ScheduleTask(task.get());
        TestTileTaskRunner::RunTask(task.get());

        scoped_refptr<TileTask> another_task;
        need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &another_task);
        EXPECT_TRUE(need_unref);
        EXPECT_FALSE(another_task);

        TestTileTaskRunner::CompleteTask(task.get());

        cache.UnrefImage(draw_image);
        cache.UnrefImage(draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageCanceledGetsNewTask)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());

        scoped_refptr<TileTask> another_task;
        need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &another_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(another_task.get() == task.get());

        // Didn't run the task, so cancel it.
        TestTileTaskRunner::CancelTask(task.get());
        TestTileTaskRunner::CompleteTask(task.get());

        // Fully cancel everything (so the raster would unref things).
        cache.UnrefImage(draw_image);
        cache.UnrefImage(draw_image);

        // Here a new task is created.
        scoped_refptr<TileTask> third_task;
        need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &third_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(third_task);
        EXPECT_FALSE(third_task.get() == task.get());

        TestTileTaskRunner::ProcessTask(third_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(third_task.get());

        cache.UnrefImage(draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetTaskForImageCanceledWhileReffedGetsNewTask)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        ASSERT_GT(task->dependencies().size(), 0u);
        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());

        scoped_refptr<TileTask> another_task;
        need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &another_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(another_task.get() == task.get());

        // Didn't run the task, so cancel it.
        TestTileTaskRunner::CancelTask(task.get());
        TestTileTaskRunner::CompleteTask(task.get());

        // 2 Unrefs, so that the decode is unlocked as well.
        cache.UnrefImage(draw_image);
        cache.UnrefImage(draw_image);

        // Note that here, everything is reffed, but a new task is created. This is
        // possible with repeated schedule/cancel operations.
        scoped_refptr<TileTask> third_task;
        need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &third_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(third_task);
        EXPECT_FALSE(third_task.get() == task.get());

        ASSERT_GT(third_task->dependencies().size(), 0u);
        TestTileTaskRunner::ProcessTask(third_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(third_task.get());

        // Unref!
        cache.UnrefImage(draw_image);
    }

    TEST(GpuImageDecodeCacheTest, NoTaskForImageAlreadyFailedDecoding)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        // Didn't run the task, so cancel it.
        TestTileTaskRunner::CancelTask(task.get());
        TestTileTaskRunner::CompleteTask(task.get());

        cache.SetImageDecodingFailedForTesting(draw_image);

        scoped_refptr<TileTask> another_task;
        need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &another_task);
        EXPECT_FALSE(need_unref);
        EXPECT_EQ(another_task.get(), nullptr);

        cache.UnrefImage(draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetDecodedImageForDraw)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_TRUE(decoded_draw_image.image());
        EXPECT_TRUE(decoded_draw_image.image()->isTextureBacked());
        EXPECT_FALSE(decoded_draw_image.is_at_raster_decode());
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));

        cache.DrawWithImageFinished(draw_image, decoded_draw_image);
        cache.UnrefImage(draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetLargeDecodedImageForDraw)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(1, 24000);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(1.0f, 1.0f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_TRUE(decoded_draw_image.image());
        EXPECT_FALSE(decoded_draw_image.image()->isTextureBacked());
        EXPECT_FALSE(decoded_draw_image.is_at_raster_decode());
        EXPECT_TRUE(cache.DiscardableIsLockedForTesting(draw_image));

        cache.DrawWithImageFinished(draw_image, decoded_draw_image);
        cache.UnrefImage(draw_image);
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));
    }

    TEST(GpuImageDecodeCacheTest, GetDecodedImageForDrawAtRasterDecode)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        cache.SetCachedBytesLimitForTesting(0);

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(1.0f, 1.0f), is_decomposable));

        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_FALSE(need_unref);
        EXPECT_FALSE(task);

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_TRUE(decoded_draw_image.image());
        EXPECT_TRUE(decoded_draw_image.image()->isTextureBacked());
        EXPECT_TRUE(decoded_draw_image.is_at_raster_decode());
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));

        cache.DrawWithImageFinished(draw_image, decoded_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetDecodedImageForDrawLargerScale)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());

        DrawImage larger_draw_image(
            image, SkIRect::MakeWH(image->width(), image->height()), quality,
            CreateMatrix(SkSize::Make(1.5f, 1.5f), is_decomposable));
        scoped_refptr<TileTask> larger_task;
        bool larger_need_unref = cache.GetTaskForImageAndRef(
            larger_draw_image, ImageDecodeCache::TracingInfo(), &larger_task);
        EXPECT_TRUE(larger_need_unref);
        EXPECT_TRUE(larger_task);

        TestTileTaskRunner::ProcessTask(larger_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(larger_task.get());

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_TRUE(decoded_draw_image.image());
        EXPECT_TRUE(decoded_draw_image.image()->isTextureBacked());
        EXPECT_FALSE(decoded_draw_image.is_at_raster_decode());
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));

        DecodedDrawImage larger_decoded_draw_image = cache.GetDecodedImageForDraw(larger_draw_image);
        EXPECT_TRUE(larger_decoded_draw_image.image());
        EXPECT_TRUE(larger_decoded_draw_image.image()->isTextureBacked());
        EXPECT_FALSE(larger_decoded_draw_image.is_at_raster_decode());
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));

        EXPECT_FALSE(decoded_draw_image.image() == larger_decoded_draw_image.image());

        cache.DrawWithImageFinished(draw_image, decoded_draw_image);
        cache.UnrefImage(draw_image);
        cache.DrawWithImageFinished(larger_draw_image, larger_decoded_draw_image);
        cache.UnrefImage(larger_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetDecodedImageForDrawHigherQuality)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkMatrix matrix = CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable);

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            kLow_SkFilterQuality, matrix);
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());

        DrawImage higher_quality_draw_image(
            image, SkIRect::MakeWH(image->width(), image->height()),
            kHigh_SkFilterQuality, matrix);
        scoped_refptr<TileTask> hq_task;
        bool hq_needs_unref = cache.GetTaskForImageAndRef(
            higher_quality_draw_image, ImageDecodeCache::TracingInfo(), &hq_task);
        EXPECT_TRUE(hq_needs_unref);
        EXPECT_TRUE(hq_task);

        TestTileTaskRunner::ProcessTask(hq_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(hq_task.get());

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_TRUE(decoded_draw_image.image());
        EXPECT_TRUE(decoded_draw_image.image()->isTextureBacked());
        EXPECT_FALSE(decoded_draw_image.is_at_raster_decode());
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));

        DecodedDrawImage larger_decoded_draw_image = cache.GetDecodedImageForDraw(higher_quality_draw_image);
        EXPECT_TRUE(larger_decoded_draw_image.image());
        EXPECT_TRUE(larger_decoded_draw_image.image()->isTextureBacked());
        EXPECT_FALSE(larger_decoded_draw_image.is_at_raster_decode());
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));

        EXPECT_FALSE(decoded_draw_image.image() == larger_decoded_draw_image.image());

        cache.DrawWithImageFinished(draw_image, decoded_draw_image);
        cache.UnrefImage(draw_image);
        cache.DrawWithImageFinished(higher_quality_draw_image,
            larger_decoded_draw_image);
        cache.UnrefImage(higher_quality_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetDecodedImageForDrawNegative)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(
            image, SkIRect::MakeWH(image->width(), image->height()), quality,
            CreateMatrix(SkSize::Make(-0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_TRUE(decoded_draw_image.image());
        EXPECT_EQ(decoded_draw_image.image()->width(), 50);
        EXPECT_EQ(decoded_draw_image.image()->height(), 50);
        EXPECT_TRUE(decoded_draw_image.image()->isTextureBacked());
        EXPECT_FALSE(decoded_draw_image.is_at_raster_decode());
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));

        cache.DrawWithImageFinished(draw_image, decoded_draw_image);
        cache.UnrefImage(draw_image);
    }

    TEST(GpuImageDecodeCacheTest, GetLargeScaledDecodedImageForDraw)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(1, 48000);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_TRUE(decoded_draw_image.image());
        // The mip level scale should never go below 0 in any dimension.
        EXPECT_EQ(1, decoded_draw_image.image()->width());
        EXPECT_EQ(24000, decoded_draw_image.image()->height());
        EXPECT_FALSE(decoded_draw_image.image()->isTextureBacked());
        EXPECT_FALSE(decoded_draw_image.is_at_raster_decode());
        EXPECT_TRUE(cache.DiscardableIsLockedForTesting(draw_image));

        cache.DrawWithImageFinished(draw_image, decoded_draw_image);
        cache.UnrefImage(draw_image);
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));
    }

    TEST(GpuImageDecodeCacheTest, AtRasterUsedDirectlyIfSpaceAllows)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        cache.SetCachedBytesLimitForTesting(0);

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));

        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_FALSE(need_unref);
        EXPECT_FALSE(task);

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_TRUE(decoded_draw_image.image());
        EXPECT_TRUE(decoded_draw_image.image()->isTextureBacked());
        EXPECT_TRUE(decoded_draw_image.is_at_raster_decode());
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));

        cache.SetCachedBytesLimitForTesting(96 * 1024 * 1024);

        // Finish our draw after increasing the memory limit, image should be added to
        // cache.
        cache.DrawWithImageFinished(draw_image, decoded_draw_image);

        scoped_refptr<TileTask> another_task;
        bool another_task_needs_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(another_task_needs_unref);
        EXPECT_FALSE(another_task);
        cache.UnrefImage(draw_image);
    }

    TEST(GpuImageDecodeCacheTest,
        GetDecodedImageForDrawAtRasterDecodeMultipleTimes)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        cache.SetCachedBytesLimitForTesting(0);

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_TRUE(decoded_draw_image.image());
        EXPECT_TRUE(decoded_draw_image.image()->isTextureBacked());
        EXPECT_TRUE(decoded_draw_image.is_at_raster_decode());
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));

        DecodedDrawImage another_decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_EQ(decoded_draw_image.image()->uniqueID(),
            another_decoded_draw_image.image()->uniqueID());

        cache.DrawWithImageFinished(draw_image, decoded_draw_image);
        cache.DrawWithImageFinished(draw_image, another_decoded_draw_image);
    }

    TEST(GpuImageDecodeCacheTest,
        GetLargeDecodedImageForDrawAtRasterDecodeMultipleTimes)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(1, 24000);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(1.0f, 1.0f), is_decomposable));

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_TRUE(decoded_draw_image.image());
        EXPECT_FALSE(decoded_draw_image.image()->isTextureBacked());
        EXPECT_TRUE(decoded_draw_image.is_at_raster_decode());
        EXPECT_TRUE(cache.DiscardableIsLockedForTesting(draw_image));

        cache.DrawWithImageFinished(draw_image, decoded_draw_image);
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));

        DecodedDrawImage second_decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_TRUE(second_decoded_draw_image.image());
        EXPECT_FALSE(second_decoded_draw_image.image()->isTextureBacked());
        EXPECT_TRUE(second_decoded_draw_image.is_at_raster_decode());
        EXPECT_TRUE(cache.DiscardableIsLockedForTesting(draw_image));

        cache.DrawWithImageFinished(draw_image, second_decoded_draw_image);
        EXPECT_FALSE(cache.DiscardableIsLockedForTesting(draw_image));
    }

    TEST(GpuImageDecodeCacheTest, ZeroSizedImagesAreSkipped)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.f, 0.f), is_decomposable));

        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_FALSE(task);
        EXPECT_FALSE(need_unref);

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_FALSE(decoded_draw_image.image());

        cache.DrawWithImageFinished(draw_image, decoded_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, NonOverlappingSrcRectImagesAreSkipped)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(
            image, SkIRect::MakeXYWH(150, 150, image->width(), image->height()),
            quality, CreateMatrix(SkSize::Make(1.f, 1.f), is_decomposable));

        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_FALSE(task);
        EXPECT_FALSE(need_unref);

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image);
        EXPECT_FALSE(decoded_draw_image.image());

        cache.DrawWithImageFinished(draw_image, decoded_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, CanceledTasksDoNotCountAgainstBudget)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(
            image, SkIRect::MakeXYWH(0, 0, image->width(), image->height()), quality,
            CreateMatrix(SkSize::Make(1.f, 1.f), is_decomposable));

        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_NE(0u, cache.GetBytesUsedForTesting());
        EXPECT_TRUE(task);
        EXPECT_TRUE(need_unref);

        TestTileTaskRunner::CancelTask(task->dependencies()[0].get());
        TestTileTaskRunner::CompleteTask(task->dependencies()[0].get());
        TestTileTaskRunner::CancelTask(task.get());
        TestTileTaskRunner::CompleteTask(task.get());

        cache.UnrefImage(draw_image);
        EXPECT_EQ(0u, cache.GetBytesUsedForTesting());
    }

    TEST(GpuImageDecodeCacheTest, ShouldAggressivelyFreeResources)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        sk_sp<SkImage> image = CreateImage(100, 100);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> task;
        {
            bool need_unref = cache.GetTaskForImageAndRef(
                draw_image, ImageDecodeCache::TracingInfo(), &task);
            EXPECT_TRUE(need_unref);
            EXPECT_TRUE(task);
        }

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());

        cache.UnrefImage(draw_image);

        // We should now have data image in our cache.
        DCHECK_GT(cache.GetBytesUsedForTesting(), 0u);

        // Tell our cache to aggressively free resources.
        cache.SetShouldAggressivelyFreeResources(true);
        DCHECK_EQ(0u, cache.GetBytesUsedForTesting());

        // Attempting to upload a new image should result in at-raster decode.
        {
            bool need_unref = cache.GetTaskForImageAndRef(
                draw_image, ImageDecodeCache::TracingInfo(), &task);
            EXPECT_FALSE(need_unref);
            EXPECT_FALSE(task);
        }

        // We now tell the cache to not aggressively free resources. Uploads
        // should work again.
        cache.SetShouldAggressivelyFreeResources(false);
        {
            bool need_unref = cache.GetTaskForImageAndRef(
                draw_image, ImageDecodeCache::TracingInfo(), &task);
            EXPECT_TRUE(need_unref);
            EXPECT_TRUE(task);
        }

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());

        // The image should be in our cache after un-ref.
        cache.UnrefImage(draw_image);
        DCHECK_GT(cache.GetBytesUsedForTesting(), 0u);
    }

    TEST(GpuImageDecodeCacheTest, OrphanedImagesFreeOnReachingZeroRefs)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        // Create a downscaled image.
        sk_sp<SkImage> first_image = CreateImage(100, 100);
        DrawImage first_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            quality, CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> first_task;
        bool need_unref = cache.GetTaskForImageAndRef(
            first_draw_image, ImageDecodeCache::TracingInfo(), &first_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(first_task);

        // The budget should account for exactly one image.
        EXPECT_EQ(cache.GetBytesUsedForTesting(),
            cache.GetDrawImageSizeForTesting(first_draw_image));

        // Create a larger version of |first_image|, this should immediately free the
        // memory used by |first_image| for the smaller scale.
        DrawImage second_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            quality, CreateMatrix(SkSize::Make(1.0f, 1.0f), is_decomposable));
        scoped_refptr<TileTask> second_task;
        need_unref = cache.GetTaskForImageAndRef(
            second_draw_image, ImageDecodeCache::TracingInfo(), &second_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(second_task);
        EXPECT_TRUE(first_task.get() != second_task.get());

        TestTileTaskRunner::ProcessTask(second_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(second_task.get());

        cache.UnrefImage(second_draw_image);

        // The budget should account for both images one image.
        EXPECT_EQ(cache.GetBytesUsedForTesting(),
            cache.GetDrawImageSizeForTesting(second_draw_image) + cache.GetDrawImageSizeForTesting(first_draw_image));

        // Unref the first image, it was orphaned, so it should be immediately
        // deleted.
        TestTileTaskRunner::ProcessTask(first_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(first_task.get());
        cache.UnrefImage(first_draw_image);

        // The budget should account for exactly one image.
        EXPECT_EQ(cache.GetBytesUsedForTesting(),
            cache.GetDrawImageSizeForTesting(second_draw_image));
    }

    TEST(GpuImageDecodeCacheTest, OrphanedZeroRefImagesImmediatelyDeleted)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        // Create a downscaled image.
        sk_sp<SkImage> first_image = CreateImage(100, 100);
        DrawImage first_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            quality, CreateMatrix(SkSize::Make(0.5f, 0.5f), is_decomposable));
        scoped_refptr<TileTask> first_task;
        bool need_unref = cache.GetTaskForImageAndRef(
            first_draw_image, ImageDecodeCache::TracingInfo(), &first_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(first_task);

        TestTileTaskRunner::ProcessTask(first_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(first_task.get());
        cache.UnrefImage(first_draw_image);

        // The budget should account for exactly one image.
        EXPECT_EQ(cache.GetBytesUsedForTesting(),
            cache.GetDrawImageSizeForTesting(first_draw_image));

        // Create a larger version of |first_image|, this should immediately free the
        // memory used by |first_image| for the smaller scale.
        DrawImage second_draw_image(
            first_image, SkIRect::MakeWH(first_image->width(), first_image->height()),
            quality, CreateMatrix(SkSize::Make(1.0f, 1.0f), is_decomposable));
        scoped_refptr<TileTask> second_task;
        need_unref = cache.GetTaskForImageAndRef(
            second_draw_image, ImageDecodeCache::TracingInfo(), &second_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(second_task);
        EXPECT_TRUE(first_task.get() != second_task.get());

        TestTileTaskRunner::ProcessTask(second_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(second_task.get());

        cache.UnrefImage(second_draw_image);

        // The budget should account for exactly one image.
        EXPECT_EQ(cache.GetBytesUsedForTesting(),
            cache.GetDrawImageSizeForTesting(second_draw_image));
    }

    TEST(GpuImageDecodeCacheTest, QualityCappedAtMedium)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        sk_sp<SkImage> image = CreateImage(100, 100);
        bool is_decomposable = true;
        SkMatrix matrix = CreateMatrix(SkSize::Make(0.4f, 0.4f), is_decomposable);

        // Create an image with kLow_FilterQuality.
        DrawImage low_draw_image(image,
            SkIRect::MakeWH(image->width(), image->height()),
            kLow_SkFilterQuality, matrix);
        scoped_refptr<TileTask> low_task;
        bool need_unref = cache.GetTaskForImageAndRef(
            low_draw_image, ImageDecodeCache::TracingInfo(), &low_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(low_task);

        // Get the same image at kMedium_FilterQuality. We can't re-use low, so we
        // should get a new task/ref.
        DrawImage medium_draw_image(image,
            SkIRect::MakeWH(image->width(), image->height()),
            kMedium_SkFilterQuality, matrix);
        scoped_refptr<TileTask> medium_task;
        need_unref = cache.GetTaskForImageAndRef(
            medium_draw_image, ImageDecodeCache::TracingInfo(), &medium_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(medium_task.get());
        EXPECT_FALSE(low_task.get() == medium_task.get());

        // Get the same image at kHigh_FilterQuality. We should re-use medium.
        DrawImage large_draw_image(image,
            SkIRect::MakeWH(image->width(), image->height()),
            kHigh_SkFilterQuality, matrix);
        scoped_refptr<TileTask> large_task;
        need_unref = cache.GetTaskForImageAndRef(
            large_draw_image, ImageDecodeCache::TracingInfo(), &large_task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(medium_task.get() == large_task.get());

        TestTileTaskRunner::ProcessTask(low_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(low_task.get());
        TestTileTaskRunner::ProcessTask(medium_task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(medium_task.get());

        cache.UnrefImage(low_draw_image);
        cache.UnrefImage(medium_draw_image);
        cache.UnrefImage(large_draw_image);
    }

    // Ensure that switching to a mipped version of an image after the initial
    // cache entry creation doesn't cause a buffer overflow/crash.
    TEST(GpuImageDecodeCacheTest, GetDecodedImageForDrawMipUsageChange)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());
        bool is_decomposable = true;
        SkFilterQuality quality = kHigh_SkFilterQuality;

        // Create an image decode task and cache entry that does not need mips.
        sk_sp<SkImage> image = CreateImage(4000, 4000);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            quality,
            CreateMatrix(SkSize::Make(1.0f, 1.0f), is_decomposable));
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        // Cancel the task without ever using it.
        TestTileTaskRunner::CancelTask(task->dependencies()[0].get());
        TestTileTaskRunner::CompleteTask(task->dependencies()[0].get());
        TestTileTaskRunner::CancelTask(task.get());
        TestTileTaskRunner::CompleteTask(task.get());

        cache.UnrefImage(draw_image);

        // Must hold context lock before calling GetDecodedImageForDraw /
        // DrawWithImageFinished.
        ContextProvider::ScopedContextLock context_lock(context_provider.get());

        // Do an at-raster decode of the above image that *does* require mips.
        DrawImage draw_image_mips(
            image, SkIRect::MakeWH(image->width(), image->height()), quality,
            CreateMatrix(SkSize::Make(0.6f, 0.6f), is_decomposable));
        DecodedDrawImage decoded_draw_image = cache.GetDecodedImageForDraw(draw_image_mips);
        cache.DrawWithImageFinished(draw_image_mips, decoded_draw_image);
    }

    TEST(GpuImageDecodeCacheTest, MemoryStateSuspended)
    {
        auto context_provider = TestContextProvider::Create();
        context_provider->BindToCurrentThread();
        TestGpuImageDecodeCache cache(context_provider.get());

        // First Insert an image into our cache.
        sk_sp<SkImage> image = CreateImage(1, 1);
        bool is_decomposable = true;
        SkMatrix matrix = CreateMatrix(SkSize::Make(1.0f, 1.0f), is_decomposable);
        DrawImage draw_image(image, SkIRect::MakeWH(image->width(), image->height()),
            kLow_SkFilterQuality, matrix);
        scoped_refptr<TileTask> task;
        bool need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());
        cache.UnrefImage(draw_image);

        // The image should be cached.
        DCHECK_GT(cache.GetBytesUsedForTesting(), 0u);
        DCHECK_EQ(cache.GetNumCacheEntriesForTesting(), 1u);

        // Set us to the not visible state (prerequisite for SUSPENDED).
        cache.SetShouldAggressivelyFreeResources(true);

        // Image should be cached, but not using memory budget.
        DCHECK_EQ(cache.GetBytesUsedForTesting(), 0u);
        DCHECK_EQ(cache.GetNumCacheEntriesForTesting(), 1u);

        // Set us to the SUSPENDED state.
        cache.OnMemoryStateChange(base::MemoryState::SUSPENDED);

        // Nothing should be cached.
        DCHECK_EQ(cache.GetBytesUsedForTesting(), 0u);
        DCHECK_EQ(cache.GetNumCacheEntriesForTesting(), 0u);

        // Attempts to get a task for the image should fail, as we have no space (at
        // raster only).
        need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_FALSE(need_unref);
        EXPECT_FALSE(task);

        // Restore us to visible and NORMAL memory state.
        cache.OnMemoryStateChange(base::MemoryState::NORMAL);
        cache.SetShouldAggressivelyFreeResources(false);

        // We should now be able to create a task again (space available).
        need_unref = cache.GetTaskForImageAndRef(
            draw_image, ImageDecodeCache::TracingInfo(), &task);
        EXPECT_TRUE(need_unref);
        EXPECT_TRUE(task);

        TestTileTaskRunner::ProcessTask(task->dependencies()[0].get());
        TestTileTaskRunner::ProcessTask(task.get());
        cache.UnrefImage(draw_image);
    }

} // namespace
} // namespace cc
