
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkInterpolator_DEFINED
#define SkInterpolator_DEFINED

#include "SkScalar.h"

class SkInterpolatorBase : SkNoncopyable {
public:
    enum Result {
        kNormal_Result,
        kFreezeStart_Result,
        kFreezeEnd_Result
    };
<<<<<<< HEAD

protected:
    SkInterpolatorBase();
    ~SkInterpolatorBase();

public:
    void reset(int elemCount, int frameCount);
=======
protected:
    SkInterpolatorBase();
    ~SkInterpolatorBase();
public:
    void    reset(int elemCount, int frameCount);
>>>>>>> miniblink49

    /** Return the start and end time for this interpolator.
        If there are no key frames, return false.
        @param startTime If not null, returns the time (in milliseconds) of the
                         first keyframe. If there are no keyframes, this param
                         is ignored (left unchanged).
        @param endTime If not null, returns the time (in milliseconds) of the
                       last keyframe. If there are no keyframes, this parameter
                       is ignored (left unchanged).
        @return True if there are key frames, or false if there are none.
    */
<<<<<<< HEAD
    bool getDuration(SkMSec* startTime, SkMSec* endTime) const;
=======
    bool    getDuration(SkMSec* startTime, SkMSec* endTime) const;

>>>>>>> miniblink49

    /** Set the whether the repeat is mirrored.
        @param mirror If true, the odd repeats interpolate from the last key
                      frame and the first.
    */
<<<<<<< HEAD
    void setMirror(bool mirror)
    {
=======
    void setMirror(bool mirror) {
>>>>>>> miniblink49
        fFlags = SkToU8((fFlags & ~kMirror) | (int)mirror);
    }

    /** Set the repeat count. The repeat count may be fractional.
        @param repeatCount Multiplies the total time by this scalar.
    */
<<<<<<< HEAD
    void setRepeatCount(SkScalar repeatCount) { fRepeat = repeatCount; }
=======
    void    setRepeatCount(SkScalar repeatCount) { fRepeat = repeatCount; }
>>>>>>> miniblink49

    /** Set the whether the repeat is mirrored.
        @param reset If true, the odd repeats interpolate from the last key
                     frame and the first.
    */
<<<<<<< HEAD
    void setReset(bool reset)
    {
        fFlags = SkToU8((fFlags & ~kReset) | (int)reset);
    }

    Result timeToT(SkMSec time, SkScalar* T, int* index, bool* exact) const;
=======
    void setReset(bool reset) {
        fFlags = SkToU8((fFlags & ~kReset) | (int)reset);
    }

    Result  timeToT(SkMSec time, SkScalar* T, int* index, SkBool* exact) const;
>>>>>>> miniblink49

protected:
    enum Flags {
        kMirror = 1,
        kReset = 2,
        kHasBlend = 4
    };
    static SkScalar ComputeRelativeT(SkMSec time, SkMSec prevTime,
<<<<<<< HEAD
        SkMSec nextTime, const SkScalar blend[4] = NULL);
=======
                             SkMSec nextTime, const SkScalar blend[4] = NULL);
>>>>>>> miniblink49
    int16_t fFrameCount;
    uint8_t fElemCount;
    uint8_t fFlags;
    SkScalar fRepeat;
    struct SkTimeCode {
<<<<<<< HEAD
        SkMSec fTime;
        SkScalar fBlend[4];
    };
    SkTimeCode* fTimes; // pointer into fStorage
    void* fStorage;
#ifdef SK_DEBUG
    SkTimeCode (*fTimesArray)[10];
=======
        SkMSec  fTime;
        SkScalar fBlend[4];
    };
    SkTimeCode* fTimes;     // pointer into fStorage
    void* fStorage;
#ifdef SK_DEBUG
    SkTimeCode(* fTimesArray)[10];
>>>>>>> miniblink49
#endif
};

class SkInterpolator : public SkInterpolatorBase {
public:
    SkInterpolator();
    SkInterpolator(int elemCount, int frameCount);
<<<<<<< HEAD
    void reset(int elemCount, int frameCount);
=======
    void    reset(int elemCount, int frameCount);
>>>>>>> miniblink49

    /** Add or replace a key frame, copying the values[] data into the
        interpolator.
        @param index    The index of this frame (frames must be ordered by time)
        @param time The millisecond time for this frame
        @param values   The array of values [elemCount] for this frame. The data
                        is copied into the interpolator.
        @param blend    A positive scalar specifying how to blend between this
                        and the next key frame. [0...1) is a cubic lag/log/lag
                        blend (slow to change at the beginning and end)
                        1 is a linear blend (default)
    */
    bool setKeyFrame(int index, SkMSec time, const SkScalar values[],
<<<<<<< HEAD
        const SkScalar blend[4] = NULL);
=======
                     const SkScalar blend[4] = NULL);
>>>>>>> miniblink49

    /** Return the computed values given the specified time. Return whether
        those values are the result of pinning to either the first
        (kFreezeStart) or last (kFreezeEnd), or from interpolated the two
        nearest key values (kNormal).
        @param time The time to sample (in milliseconds)
        @param (may be null) where to write the computed values.
    */
    Result timeToValues(SkMSec time, SkScalar values[] = NULL) const;

private:
<<<<<<< HEAD
    SkScalar* fValues; // pointer into fStorage
#ifdef SK_DEBUG
    SkScalar (*fScalarsArray)[10];
=======
    SkScalar* fValues;  // pointer into fStorage
#ifdef SK_DEBUG
    SkScalar(* fScalarsArray)[10];
>>>>>>> miniblink49
#endif
    typedef SkInterpolatorBase INHERITED;
};

<<<<<<< HEAD
/** Interpolate a cubic curve, typically to provide an ease-in ease-out transition.
    All the parameters are in the range of [0...1].
    The input value is treated as the x-coordinate of the cubic.
    The output value is the y-coordinate on the cubic at the x-coordinate.

    @param value        The x-coordinate pinned between [0..1].
    @param bx,by,cx,cy  The cubic control points where the cubic is specified
                        as (0,0) (bx,by) (cx,cy) (1,1)
    @return             the corresponding y-coordinate value, from [0..1].
*/
SkScalar SkUnitCubicInterp(SkScalar value, SkScalar bx, SkScalar by,
    SkScalar cx, SkScalar cy);
=======
/** Given all the parameters are [0...1], apply the cubic specified by (0,0)
    (bx,by) (cx,cy) (1,1) to value, returning the answer, also [0...1].
*/
SkScalar SkUnitCubicInterp(SkScalar value, SkScalar bx, SkScalar by,
                           SkScalar cx, SkScalar cy);
>>>>>>> miniblink49

#endif
