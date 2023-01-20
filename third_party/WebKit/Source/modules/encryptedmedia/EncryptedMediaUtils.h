// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef EncryptedMediaUtils_h
#define EncryptedMediaUtils_h

#include "public/platform/WebEncryptedMediaTypes.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
=======
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

namespace blink {

class EncryptedMediaUtils {
<<<<<<< HEAD
    STATIC_ONLY(EncryptedMediaUtils);

public:
    static WebEncryptedMediaInitDataType convertToInitDataType(
        const String& initDataType);
    static String convertFromInitDataType(WebEncryptedMediaInitDataType);

    static WebEncryptedMediaSessionType convertToSessionType(
        const String& sessionType);
    static String convertFromSessionType(WebEncryptedMediaSessionType);
=======
public:
    static WebEncryptedMediaInitDataType convertToInitDataType(const String& initDataType);
    static String convertFromInitDataType(WebEncryptedMediaInitDataType);

    static WebEncryptedMediaSessionType convertToSessionType(const String& sessionType);
    static String convertFromSessionType(WebEncryptedMediaSessionType);

private:
    EncryptedMediaUtils();
>>>>>>> miniblink49
};

} // namespace blink

#endif // EncryptedMediaUtils_h
