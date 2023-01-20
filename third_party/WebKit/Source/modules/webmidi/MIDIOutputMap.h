// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MIDIOutputMap_h
#define MIDIOutputMap_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "modules/webmidi/MIDIOutput.h"
#include "modules/webmidi/MIDIPortMap.h"

namespace blink {

<<<<<<< HEAD
class MIDIOutputMap : public MIDIPortMap<MIDIOutput>, public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();

=======
class ScriptState;

class MIDIOutputMap : public MIDIPortMap<MIDIOutput>, public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();
>>>>>>> miniblink49
public:
    explicit MIDIOutputMap(HeapVector<Member<MIDIOutput>>&);
};

} // namespace blink

#endif
