// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PushMessageData_h
#define PushMessageData_h

#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/ScriptWrappable.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
<<<<<<< HEAD
#include "wtf/Vector.h"
=======
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

namespace blink {

<<<<<<< HEAD
class ArrayBufferOrArrayBufferViewOrUSVString;
=======
>>>>>>> miniblink49
class Blob;
class DOMArrayBuffer;
class ExceptionState;
class ScriptState;

<<<<<<< HEAD
class MODULES_EXPORT PushMessageData final
    : public GarbageCollectedFinalized<PushMessageData>,
      public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();

public:
    static PushMessageData* create(const String& data);
    static PushMessageData* create(
        const ArrayBufferOrArrayBufferViewOrUSVString& data);

    virtual ~PushMessageData();

    DOMArrayBuffer* arrayBuffer() const;
    Blob* blob() const;
    ScriptValue json(ScriptState*, ExceptionState&) const;
    String text() const;
=======
class MODULES_EXPORT PushMessageData final : public GarbageCollectedFinalized<PushMessageData>, public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();

public:
    static PushMessageData* create()
    {
        return new PushMessageData();
    }

    static PushMessageData* create(const String& messageData)
    {
        return new PushMessageData(messageData);
    }

    virtual ~PushMessageData();

    PassRefPtr<DOMArrayBuffer> arrayBuffer() const;
    Blob* blob() const;
    ScriptValue json(ScriptState*, ExceptionState&) const;
    const String& text() const;
>>>>>>> miniblink49

    DECLARE_TRACE();

private:
<<<<<<< HEAD
    PushMessageData(const char* data, unsigned bytesSize);

    Vector<char> m_data;
=======
    PushMessageData();
    explicit PushMessageData(const String& messageData);

    String m_messageData;
>>>>>>> miniblink49
};

} // namespace blink

#endif // PushMessageData_h
