// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "public/web/WebScriptSource.h"

#include "bindings/core/v8/ScriptSourceCode.h"
#include "wtf/text/TextPosition.h"

namespace blink {

WebScriptSource::operator ScriptSourceCode() const
{
<<<<<<< HEAD
    TextPosition position(OrdinalNumber::fromOneBasedInt(startLine),
        OrdinalNumber::first());
=======
    TextPosition position(OrdinalNumber::fromOneBasedInt(startLine), OrdinalNumber::first());
>>>>>>> miniblink49
    return ScriptSourceCode(code, url, position);
}

} // namespace blink
