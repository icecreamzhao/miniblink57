<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkMovie.h"
#include "SkCanvas.h"
#include "SkPaint.h"

// We should never see this in normal operation since our time values are
// 0-based. So we use it as a sentinal.
#define UNINITIALIZED_MSEC ((SkMSec)-1)

SkMovie::SkMovie()
{
<<<<<<< HEAD
    fInfo.fDuration = UNINITIALIZED_MSEC; // uninitialized
=======
    fInfo.fDuration = UNINITIALIZED_MSEC;  // uninitialized
>>>>>>> miniblink49
    fCurrTime = UNINITIALIZED_MSEC; // uninitialized
    fNeedBitmap = true;
}

void SkMovie::ensureInfo()
{
    if (fInfo.fDuration == UNINITIALIZED_MSEC && !this->onGetInfo(&fInfo))
<<<<<<< HEAD
        memset(&fInfo, 0, sizeof(fInfo)); // failure
=======
        memset(&fInfo, 0, sizeof(fInfo));   // failure
>>>>>>> miniblink49
}

SkMSec SkMovie::duration()
{
    this->ensureInfo();
    return fInfo.fDuration;
}

int SkMovie::width()
{
    this->ensureInfo();
    return fInfo.fWidth;
}

int SkMovie::height()
{
    this->ensureInfo();
    return fInfo.fHeight;
}

int SkMovie::isOpaque()
{
    this->ensureInfo();
    return fInfo.fIsOpaque;
}

bool SkMovie::setTime(SkMSec time)
{
    SkMSec dur = this->duration();
    if (time > dur)
        time = dur;

    bool changed = false;
<<<<<<< HEAD
    if (time != fCurrTime) {
=======
    if (time != fCurrTime)
    {
>>>>>>> miniblink49
        fCurrTime = time;
        changed = this->onSetTime(time);
        fNeedBitmap |= changed;
    }
    return changed;
}

const SkBitmap& SkMovie::bitmap()
{
<<<<<<< HEAD
    if (fCurrTime == UNINITIALIZED_MSEC) // uninitialized
        this->setTime(0);

    if (fNeedBitmap) {
        if (!this->onGetBitmap(&fBitmap)) // failure
=======
    if (fCurrTime == UNINITIALIZED_MSEC)    // uninitialized
        this->setTime(0);

    if (fNeedBitmap)
    {
        if (!this->onGetBitmap(&fBitmap))   // failure
>>>>>>> miniblink49
            fBitmap.reset();
        fNeedBitmap = false;
    }
    return fBitmap;
}

////////////////////////////////////////////////////////////////////

#include "SkStream.h"

<<<<<<< HEAD
SkMovie* SkMovie::DecodeMemory(const void* data, size_t length)
{
=======
SkMovie* SkMovie::DecodeMemory(const void* data, size_t length) {
>>>>>>> miniblink49
    SkMemoryStream stream(data, length, false);
    return SkMovie::DecodeStream(&stream);
}

<<<<<<< HEAD
SkMovie* SkMovie::DecodeFile(const char path[])
{
    SkAutoTDelete<SkStreamRewindable> stream(SkStream::NewFromFile(path));
    return stream.get() ? SkMovie::DecodeStream(stream) : nullptr;
=======
SkMovie* SkMovie::DecodeFile(const char path[]) {
    SkAutoTDelete<SkStreamRewindable> stream(SkStream::NewFromFile(path));
    return stream.get() ? SkMovie::DecodeStream(stream) : NULL;
>>>>>>> miniblink49
}
