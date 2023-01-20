// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DOMWindowStorage_h
#define DOMWindowStorage_h

<<<<<<< HEAD
#include "core/frame/LocalDOMWindow.h"
=======
#include "core/frame/DOMWindowProperty.h"
>>>>>>> miniblink49
#include "platform/Supplementable.h"
#include "platform/heap/Handle.h"

namespace blink {

class DOMWindow;
class ExceptionState;
<<<<<<< HEAD
class LocalDOMWindow;
class Storage;

class DOMWindowStorage final : public GarbageCollected<DOMWindowStorage>,
                               public Supplement<LocalDOMWindow> {
    USING_GARBAGE_COLLECTED_MIXIN(DOMWindowStorage);

=======
class Storage;

class DOMWindowStorage final : public NoBaseWillBeGarbageCollected<DOMWindowStorage>, public WillBeHeapSupplement<LocalDOMWindow>, public DOMWindowProperty {
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(DOMWindowStorage);
    DECLARE_EMPTY_VIRTUAL_DESTRUCTOR_WILL_BE_REMOVED(DOMWindowStorage);
>>>>>>> miniblink49
public:
    static DOMWindowStorage& from(LocalDOMWindow&);
    static Storage* sessionStorage(DOMWindow&, ExceptionState&);
    static Storage* localStorage(DOMWindow&, ExceptionState&);

    Storage* sessionStorage(ExceptionState&) const;
    Storage* localStorage(ExceptionState&) const;
    Storage* optionalSessionStorage() const { return m_sessionStorage.get(); }
    Storage* optionalLocalStorage() const { return m_localStorage.get(); }

    DECLARE_TRACE();

private:
    explicit DOMWindowStorage(LocalDOMWindow&);
    static const char* supplementName();

<<<<<<< HEAD
    mutable Member<Storage> m_sessionStorage;
    mutable Member<Storage> m_localStorage;
=======
    RawPtrWillBeMember<LocalDOMWindow> m_window;
    mutable PersistentWillBeMember<Storage> m_sessionStorage;
    mutable PersistentWillBeMember<Storage> m_localStorage;

>>>>>>> miniblink49
};

} // namespace blink

#endif // DOMWindowStorage_h
