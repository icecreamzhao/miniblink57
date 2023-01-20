/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef Timer_DEFINED
#define Timer_DEFINED

<<<<<<< HEAD
#include "SkString.h"
#include "SkTime.h"
#include "SkTypes.h"

class WallTimer {
public:
    WallTimer()
        : fWall(-1)
    {
    }

    void start() { fWall = SkTime::GetNSecs(); }
    void end() { fWall = (SkTime::GetNSecs() - fWall) * 1e-6; }

    double fWall; // Milliseconds.
=======
#include "SkTypes.h"
#include "SkString.h"

#if defined(SK_BUILD_FOR_WIN32)
    #include "SysTimer_windows.h"
#elif defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
    #include "SysTimer_mach.h"
#elif defined(SK_BUILD_FOR_UNIX) || defined(SK_BUILD_FOR_ANDROID)
    #include "SysTimer_posix.h"
#endif

#if SK_SUPPORT_GPU
    #include "GpuTimer.h"
#endif

class SkGLContext;

/**
 * SysTimers and GpuTimers are implemented orthogonally.
 * This class combines 2 SysTimers and a GpuTimer into one single,
 * platform specific Timer with a simple interface. The truncated
 * timer doesn't include the time required for the GPU to finish
 * its rendering. It should always be <= the un-truncated system
 * times and (for GPU configurations) can be used to roughly (very
 * roughly) gauge the GPU load/backlog.
 */
class Timer {
public:
    explicit Timer(SkGLContext* gl = NULL);

    void start();
    void truncatedEnd();
    void end();

    // All times in milliseconds.
    double fCpu;
    double fWall;
    double fTruncatedCpu;
    double fTruncatedWall;
    double fGpu;

private:
    SysTimer fSysTimer;
    SysTimer fTruncatedSysTimer;
#if SK_SUPPORT_GPU
    GpuTimer fGpuTimer;
#endif
};

// Same as Timer above, supporting only fWall but with much lower overhead.
// (Typically, ~30ns instead of Timer's ~1us.)
class WallTimer {
public:
    WallTimer();

    void start();
    void end();

    double fWall;  // Milliseconds.

private:
    SysTimer fSysTimer;
>>>>>>> miniblink49
};

SkString HumanizeMs(double);

#endif
