/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkRemotableFontMgr.h"
<<<<<<< HEAD
#include "SkOnce.h"

SkRemotableFontIdentitySet::SkRemotableFontIdentitySet(int count, SkFontIdentity** data)
    : fCount(count)
    , fData(count)
=======

#include "SkLazyPtr.h"

SkRemotableFontIdentitySet::SkRemotableFontIdentitySet(int count, SkFontIdentity** data)
      : fCount(count), fData(count)
>>>>>>> miniblink49
{
    SkASSERT(data);
    *data = fData;
}

<<<<<<< HEAD
SkRemotableFontIdentitySet* SkRemotableFontIdentitySet::NewEmpty()
{
    static SkOnce once;
    static SkRemotableFontIdentitySet* empty;
    once([] { empty = new SkRemotableFontIdentitySet; });
    return SkRef(empty);
=======
// As a template argument, this must have external linkage.
SkRemotableFontIdentitySet* sk_remotable_font_identity_set_new() {
    return SkNEW(SkRemotableFontIdentitySet);
}

SK_DECLARE_STATIC_LAZY_PTR(SkRemotableFontIdentitySet, empty, sk_remotable_font_identity_set_new);
SkRemotableFontIdentitySet* SkRemotableFontIdentitySet::NewEmpty() {
    return SkRef(empty.get());
>>>>>>> miniblink49
}
