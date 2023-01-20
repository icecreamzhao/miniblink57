// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MediaKeyStatusMap_h
#define MediaKeyStatusMap_h

<<<<<<< HEAD
#include "bindings/core/v8/Iterable.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/ScriptWrappable.h"
=======
#include "bindings/core/v8/Maplike.h"
#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/core/v8/UnionTypesCore.h"
>>>>>>> miniblink49
#include "core/dom/DOMArrayPiece.h"
#include "platform/heap/Heap.h"

namespace blink {

class ExceptionState;
<<<<<<< HEAD
=======
class Iterator;
>>>>>>> miniblink49
class ScriptState;
class WebData;

// Represents a read-only map (to JavaScript) of key IDs and their current
// status known to a particular session. Since it can be updated any time there
// is a keychange event, iteration order and completeness is not guaranteed
// if the event loop runs.
<<<<<<< HEAD
class MediaKeyStatusMap final
    : public GarbageCollected<MediaKeyStatusMap>,
      public ScriptWrappable,
      public PairIterable<ArrayBufferOrArrayBufferView, String> {
    DEFINE_WRAPPERTYPEINFO();

=======
class MediaKeyStatusMap final : public GarbageCollected<MediaKeyStatusMap>, public ScriptWrappable, public Maplike<ArrayBufferOrArrayBufferView, String> {
    DEFINE_WRAPPERTYPEINFO();
>>>>>>> miniblink49
private:
    // MapEntry holds the keyId (DOMArrayBuffer) and status (MediaKeyStatus as
    // String) for each entry.
    class MapEntry;

<<<<<<< HEAD
    // The key ids and their status are kept in a list, as order is important.
    // Note that order (or lack of it) is not specified in the EME spec.
    using MediaKeyStatusMapType = HeapVector<Member<MapEntry>>;
=======
    // As the number of keys per session should be small, the key ids and
    // their status are kept in a list rather than a proper map.
    typedef HeapVector<Member<MapEntry>> MapType;
>>>>>>> miniblink49

public:
    MediaKeyStatusMap() { }

    void clear();
<<<<<<< HEAD
    void addEntry(WebData keyId, const String& status);
=======
    void addEntry(WebData source, const String& status);
>>>>>>> miniblink49
    const MapEntry& at(size_t) const;

    // IDL attributes / methods
    size_t size() const { return m_entries.size(); }
<<<<<<< HEAD
    bool has(const ArrayBufferOrArrayBufferView& keyId);
    ScriptValue get(ScriptState*, const ArrayBufferOrArrayBufferView& keyId);
=======
>>>>>>> miniblink49

    DECLARE_VIRTUAL_TRACE();

private:
<<<<<<< HEAD
    // PairIterable<> implementation.
    IterationSource* startIteration(ScriptState*, ExceptionState&) override;

    size_t indexOf(const DOMArrayPiece& keyId) const;

    MediaKeyStatusMapType m_entries;
=======
    IterationSource* startIteration(ScriptState*, ExceptionState&) override;
    bool getMapEntry(ScriptState*, const ArrayBufferOrArrayBufferView&, String&, ExceptionState&) override;

    size_t indexOf(const DOMArrayPiece& key) const;

    MapType m_entries;
>>>>>>> miniblink49
};

} // namespace blink

#endif // MediaKeyStatusMap_h
