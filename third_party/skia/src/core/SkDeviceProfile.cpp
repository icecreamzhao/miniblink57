/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkDeviceProfile.h"
#include "SkMutex.h"

#define DEFAULT_GAMMAEXP 2.2f
#define DEFAULT_CONTRASTSCALE 0.5f
#define DEFAULT_LCDCONFIG SkDeviceProfile::kNone_LCDConfig
#define DEFAULT_FONTHINTLEVEL SkDeviceProfile::kSlight_FontHintLevel

static float pin(float value, float min, float max)
{
=======

#include "SkDeviceProfile.h"
#include "SkMutex.h"

#define DEFAULT_GAMMAEXP        2.2f
#define DEFAULT_CONTRASTSCALE   0.5f
#define DEFAULT_LCDCONFIG       SkDeviceProfile::kNone_LCDConfig
#define DEFAULT_FONTHINTLEVEL   SkDeviceProfile::kSlight_FontHintLevel

static float pin(float value, float min, float max) {
>>>>>>> miniblink49
    if (value < min) {
        value = min;
    } else if (value > max) {
        value = max;
    }
    return value;
}

SkDeviceProfile::SkDeviceProfile(float gammaExp, float contrast,
<<<<<<< HEAD
    LCDConfig config, FontHintLevel level)
{
=======
                                 LCDConfig config, FontHintLevel level) {
>>>>>>> miniblink49
    fGammaExponent = pin(gammaExp, 0, 10);
    fContrastScale = pin(contrast, 0, 1);
    fLCDConfig = config;
    fFontHintLevel = level;
}

void SkDeviceProfile::generateTableForLuminanceByte(U8CPU lumByte,
<<<<<<< HEAD
    uint8_t table[256]) const
{
=======
                                                    uint8_t table[256]) const {
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

SkDeviceProfile* SkDeviceProfile::Create(float gammaExp,
<<<<<<< HEAD
    float contrast,
    LCDConfig config,
    FontHintLevel level)
{
    return new SkDeviceProfile(gammaExp, contrast, config, level);
=======
                                         float contrast,
                                         LCDConfig config,
                                         FontHintLevel level) {
    return SkNEW_ARGS(SkDeviceProfile, (gammaExp, contrast, config, level));
>>>>>>> miniblink49
}

SK_DECLARE_STATIC_MUTEX(gMutex);
static SkDeviceProfile* gDefaultProfile;
static SkDeviceProfile* gGlobalProfile;

<<<<<<< HEAD
SkDeviceProfile* SkDeviceProfile::GetDefault()
{
    SkAutoMutexAcquire amc(gMutex);

    if (nullptr == gDefaultProfile) {
        gDefaultProfile = SkDeviceProfile::Create(DEFAULT_GAMMAEXP,
            DEFAULT_CONTRASTSCALE,
            DEFAULT_LCDCONFIG,
            DEFAULT_FONTHINTLEVEL);
=======
SkDeviceProfile* SkDeviceProfile::GetDefault() {
    SkAutoMutexAcquire amc(gMutex);

    if (NULL == gDefaultProfile) {
        gDefaultProfile = SkDeviceProfile::Create(DEFAULT_GAMMAEXP,
                                                  DEFAULT_CONTRASTSCALE,
                                                  DEFAULT_LCDCONFIG,
                                                  DEFAULT_FONTHINTLEVEL);
>>>>>>> miniblink49
    }
    return gDefaultProfile;
}

<<<<<<< HEAD
SkDeviceProfile* SkDeviceProfile::RefGlobal()
{
    SkAutoMutexAcquire amc(gMutex);

    if (nullptr == gGlobalProfile) {
=======
SkDeviceProfile* SkDeviceProfile::RefGlobal() {
    SkAutoMutexAcquire amc(gMutex);

    if (NULL == gGlobalProfile) {
>>>>>>> miniblink49
        gGlobalProfile = SkDeviceProfile::GetDefault();
    }
    gGlobalProfile->ref();
    return gGlobalProfile;
}

<<<<<<< HEAD
void SkDeviceProfile::SetGlobal(SkDeviceProfile* profile)
{
=======
void SkDeviceProfile::SetGlobal(SkDeviceProfile* profile) {
>>>>>>> miniblink49
    SkAutoMutexAcquire amc(gMutex);

    SkRefCnt_SafeAssign(gGlobalProfile, profile);
}
