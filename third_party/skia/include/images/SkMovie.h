
/*
 * Copyright 2008 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkMovie_DEFINED
#define SkMovie_DEFINED

#include "SkCanvas.h"
#include "SkRefCnt.h"
=======

#ifndef SkMovie_DEFINED
#define SkMovie_DEFINED

#include "SkRefCnt.h"
#include "SkCanvas.h"
>>>>>>> miniblink49

class SkStreamRewindable;

class SkMovie : public SkRefCnt {
public:
<<<<<<< HEAD
=======
    

>>>>>>> miniblink49
    /** Try to create a movie from the stream. If the stream format is not
        supported, return NULL.
    */
    static SkMovie* DecodeStream(SkStreamRewindable*);
    /** Try to create a movie from the specified file path. If the file is not
        found, or the format is not supported, return NULL. If a movie is
        returned, the stream may be retained by the movie (via ref()) until
        the movie is finished with it (by calling unref()).
    */
    static SkMovie* DecodeFile(const char path[]);
    /** Try to create a movie from the specified memory.
        If the format is not supported, return NULL. If a movie is returned,
        the data will have been read or copied, and so the caller may free
        it.
    */
    static SkMovie* DecodeMemory(const void* data, size_t length);

<<<<<<< HEAD
    SkMSec duration();
    int width();
    int height();
    int isOpaque();
=======
    SkMSec  duration();
    int     width();
    int     height();
    int     isOpaque();
>>>>>>> miniblink49

    /** Specify the time code (between 0...duration) to sample a bitmap
        from the movie. Returns true if this time code generated a different
        bitmap/frame from the previous state (i.e. true means you need to
        redraw).
    */
    bool setTime(SkMSec);

    // return the right bitmap for the current time code
    const SkBitmap& bitmap();

protected:
    struct Info {
<<<<<<< HEAD
        SkMSec fDuration;
        int fWidth;
        int fHeight;
        bool fIsOpaque;
=======
        SkMSec  fDuration;
        int     fWidth;
        int     fHeight;
        bool    fIsOpaque;
>>>>>>> miniblink49
    };

    virtual bool onGetInfo(Info*) = 0;
    virtual bool onSetTime(SkMSec) = 0;
    virtual bool onGetBitmap(SkBitmap*) = 0;

    // visible for subclasses
    SkMovie();

private:
<<<<<<< HEAD
    Info fInfo;
    SkMSec fCurrTime;
    SkBitmap fBitmap;
    bool fNeedBitmap;
=======
    Info        fInfo;
    SkMSec      fCurrTime;
    SkBitmap    fBitmap;
    bool        fNeedBitmap;
>>>>>>> miniblink49

    void ensureInfo();

    typedef SkRefCnt INHERITED;
};

#endif
