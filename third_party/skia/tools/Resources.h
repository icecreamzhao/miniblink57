/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef Resources_DEFINED
#define Resources_DEFINED

<<<<<<< HEAD
#include "SkRefCnt.h"
#include "SkString.h"

class SkBitmap;
class SkImage;
=======
#include "SkString.h"

class SkBitmap;
>>>>>>> miniblink49
class SkStreamAsset;
class SkTypeface;

SkString GetResourcePath(const char* resource = "");
<<<<<<< HEAD
void SetResourcePath(const char*);

bool GetResourceAsBitmap(const char* resource, SkBitmap* dst);
sk_sp<SkImage> GetResourceAsImage(const char* resource);
SkStreamAsset* GetResourceAsStream(const char* resource);
sk_sp<SkTypeface> MakeResourceAsTypeface(const char* resource);

#endif // Resources_DEFINED
=======
void SetResourcePath(const char* );

bool GetResourceAsBitmap(const char* resource, SkBitmap* dst);
SkStreamAsset* GetResourceAsStream(const char* resource);
SkTypeface* GetResourceAsTypeface(const char* resource);

#endif  // Resources_DEFINED
>>>>>>> miniblink49
