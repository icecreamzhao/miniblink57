// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cc/playback/clip_path_display_item.h"

#include <stddef.h>
#include <stdint.h>

#include "base/strings/stringprintf.h"
#include "base/trace_event/trace_event_argument.h"
// #include "cc/proto/display_item.pb.h"
// #include "cc/proto/skia_conversions.h"
#include "third_party/skia/include/core/SkCanvas.h"

namespace cc {

ClipPathDisplayItem::ClipPathDisplayItem(const SkPath& clip_path,
    bool antialias)
    : DisplayItem(CLIP_PATH)
{
    SetNew(clip_path, antialias);
}

ClipPathDisplayItem::ClipPathDisplayItem(const proto::DisplayItem& proto)
    : DisplayItem(CLIP_PATH)
{
    //   DCHECK_EQ(proto::DisplayItem::Type_ClipPath, proto.type());
    //
    //   const proto::ClipPathDisplayItem& details = proto.clip_path_item();
    //   bool antialias = details.antialias();
    //
    //   SkPath clip_path;
    //   if (details.has_clip_path()) {
    //     size_t bytes_read = clip_path.readFromMemory(details.clip_path().data(),
    //                                                  details.clip_path().size());
    //     DCHECK_EQ(details.clip_path().size(), bytes_read);
    //   }
    //
    //   SetNew(clip_path, antialias);
}

ClipPathDisplayItem::~ClipPathDisplayItem()
{
}

void ClipPathDisplayItem::SetNew(const SkPath& clip_path,
    bool antialias)
{
    clip_path_ = clip_path;
    antialias_ = antialias;
}

void ClipPathDisplayItem::ToProtobuf(proto::DisplayItem* proto) const
{
    //   proto->set_type(proto::DisplayItem::Type_ClipPath);
    //
    //   proto::ClipPathDisplayItem* details = proto->mutable_clip_path_item();
    //   details->set_antialias(antialias_);
    //
    //   // Just use skia's serialization method for the SkPath for now.
    //   size_t path_size = clip_path_.writeToMemory(nullptr);
    //   if (path_size > 0) {
    //     std::unique_ptr<uint8_t[]> buffer(new uint8_t[path_size]);
    //     clip_path_.writeToMemory(buffer.get());
    //     details->set_clip_path(buffer.get(), path_size);
    //   }
}

void ClipPathDisplayItem::Raster(SkCanvas* canvas,
    SkPicture::AbortCallback* callback) const
{
    canvas->save();
    canvas->clipPath(clip_path_, SkRegion::kIntersect_Op, antialias_);
}

void ClipPathDisplayItem::AsValueInto(
    const gfx::Rect& visual_rect,
    base::trace_event::TracedValue* array) const
{
    array->AppendString(base::StringPrintf(
        "ClipPathDisplayItem length: %d visualRect: [%s]",
        clip_path_.countPoints(), visual_rect.ToString().c_str()));
}

EndClipPathDisplayItem::EndClipPathDisplayItem()
    : DisplayItem(END_CLIP_PATH)
{
}

EndClipPathDisplayItem::EndClipPathDisplayItem(const proto::DisplayItem& proto)
    : DisplayItem(END_CLIP_PATH)
{
    //DCHECK_EQ(proto::DisplayItem::Type_EndClipPath, proto.type());
}

EndClipPathDisplayItem::~EndClipPathDisplayItem()
{
}

void EndClipPathDisplayItem::ToProtobuf(proto::DisplayItem* proto) const
{
    //proto->set_type(proto::DisplayItem::Type_EndClipPath);
}

void EndClipPathDisplayItem::Raster(
    SkCanvas* canvas,
    SkPicture::AbortCallback* callback) const
{
    canvas->restore();
}

void EndClipPathDisplayItem::AsValueInto(
    const gfx::Rect& visual_rect,
    base::trace_event::TracedValue* array) const
{
    array->AppendString(
        base::StringPrintf("EndClipPathDisplayItem visualRect: [%s]",
            visual_rect.ToString().c_str()));
}

} // namespace cc
