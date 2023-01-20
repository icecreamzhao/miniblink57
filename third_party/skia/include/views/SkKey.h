
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkKey_DEFINED
#define SkKey_DEFINED

#include "SkTypes.h"

enum SkKey {
    //reordering these to match android.app.KeyEvent
<<<<<<< HEAD
    kNONE_SkKey, //corresponds to android's UNKNOWN
=======
    kNONE_SkKey,    //corresponds to android's UNKNOWN
>>>>>>> miniblink49

    kLeftSoftKey_SkKey,
    kRightSoftKey_SkKey,

<<<<<<< HEAD
    kHome_SkKey, //!< the home key - added to match android
    kBack_SkKey, //!< (CLR)
    kSend_SkKey, //!< the green (talk) key
    kEnd_SkKey, //!< the red key
=======
    kHome_SkKey,    //!< the home key - added to match android
    kBack_SkKey,    //!< (CLR)
    kSend_SkKey,    //!< the green (talk) key
    kEnd_SkKey,     //!< the red key
>>>>>>> miniblink49

    k0_SkKey,
    k1_SkKey,
    k2_SkKey,
    k3_SkKey,
    k4_SkKey,
    k5_SkKey,
    k6_SkKey,
    k7_SkKey,
    k8_SkKey,
    k9_SkKey,
<<<<<<< HEAD
    kStar_SkKey, //!< the * key
    kHash_SkKey, //!< the # key
=======
    kStar_SkKey,    //!< the * key
    kHash_SkKey,    //!< the # key
>>>>>>> miniblink49

    kUp_SkKey,
    kDown_SkKey,
    kLeft_SkKey,
    kRight_SkKey,

<<<<<<< HEAD
    kOK_SkKey, //!< the center key

    kVolUp_SkKey, //!< volume up - match android
    kVolDown_SkKey, //!< volume down - same
    kPower_SkKey, //!< power button - same
    kCamera_SkKey, //!< camera         - same
=======
    kOK_SkKey,      //!< the center key

    kVolUp_SkKey,   //!< volume up - match android
    kVolDown_SkKey, //!< volume down - same
    kPower_SkKey,   //!< power button - same
    kCamera_SkKey,  //!< camera         - same
>>>>>>> miniblink49

    kSkKeyCount
};

enum SkModifierKeys {
<<<<<<< HEAD
    kShift_SkModifierKey = 1 << 0,
    kControl_SkModifierKey = 1 << 1,
    kOption_SkModifierKey = 1 << 2, // same as ALT
    kCommand_SkModifierKey = 1 << 3,
=======
    kShift_SkModifierKey    = 1 << 0,
    kControl_SkModifierKey  = 1 << 1,
    kOption_SkModifierKey   = 1 << 2,   // same as ALT
    kCommand_SkModifierKey  = 1 << 3,
>>>>>>> miniblink49
};

#endif
