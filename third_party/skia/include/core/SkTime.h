
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkTime_DEFINED
#define SkTime_DEFINED

#include "SkTypes.h"

class SkString;

/** \class SkTime
    Platform-implemented utilities to return time of day, and millisecond counter.
*/
<<<<<<< HEAD
class SK_API SkTime {
public:
    struct DateTime {
        int16_t fTimeZoneMinutes; // The number of minutes that GetDateTime()
            // is ahead of or behind UTC.
        uint16_t fYear; //!< e.g. 2005
        uint8_t fMonth; //!< 1..12
        uint8_t fDayOfWeek; //!< 0..6, 0==Sunday
        uint8_t fDay; //!< 1..31
        uint8_t fHour; //!< 0..23
        uint8_t fMinute; //!< 0..59
        uint8_t fSecond; //!< 0..59
=======
class SkTime {
public:
    struct DateTime {
        int16_t  fTimeZoneMinutes;  // The number of minutes that GetDateTime()
                                    // is ahead of or behind UTC.
        uint16_t fYear;          //!< e.g. 2005
        uint8_t  fMonth;         //!< 1..12
        uint8_t  fDayOfWeek;     //!< 0..6, 0==Sunday
        uint8_t  fDay;           //!< 1..31
        uint8_t  fHour;          //!< 0..23
        uint8_t  fMinute;        //!< 0..59
        uint8_t  fSecond;        //!< 0..59
>>>>>>> miniblink49

        void toISO8601(SkString* dst) const;
    };
    static void GetDateTime(DateTime*);

<<<<<<< HEAD
    static double GetSecs() { return GetNSecs() * 1e-9; }
    static double GetMSecs() { return GetNSecs() * 1e-6; }
    static double GetNSecs();
};

=======
    static SkMSec GetMSecs();
};

#if defined(SK_DEBUG) && defined(SK_BUILD_FOR_WIN32)
    extern SkMSec gForceTickCount;
#endif

#define SK_TIME_FACTOR      1

>>>>>>> miniblink49
///////////////////////////////////////////////////////////////////////////////

class SkAutoTime {
public:
    // The label is not deep-copied, so its address must remain valid for the
    // lifetime of this object
<<<<<<< HEAD
    SkAutoTime(const char* label = nullptr)
        : fLabel(label)
        , fNow(SkTime::GetMSecs())
    {
    }
    ~SkAutoTime()
    {
        uint64_t dur = static_cast<uint64_t>(SkTime::GetMSecs() - fNow);
        SkDebugf("%s %ld\n", fLabel ? fLabel : "", dur);
    }

private:
    const char* fLabel;
    double fNow;
=======
    SkAutoTime(const char* label = NULL, SkMSec minToDump = 0) : fLabel(label)
    {
        fNow = SkTime::GetMSecs();
        fMinToDump = minToDump;
    }
    ~SkAutoTime()
    {
        SkMSec dur = SkTime::GetMSecs() - fNow;
        if (dur >= fMinToDump) {
            SkDebugf("%s %d\n", fLabel ? fLabel : "", dur);
        }
    }
private:
    const char* fLabel;
    SkMSec      fNow;
    SkMSec      fMinToDump;
>>>>>>> miniblink49
};
#define SkAutoTime(...) SK_REQUIRE_LOCAL_VAR(SkAutoTime)

#endif
