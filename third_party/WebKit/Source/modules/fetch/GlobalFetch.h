// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GlobalFetch_h
#define GlobalFetch_h

#include "bindings/core/v8/ScriptPromise.h"
#include "modules/ModulesExport.h"
#include "modules/fetch/Request.h"
<<<<<<< HEAD
=======
#include "wtf/WeakPtr.h"
>>>>>>> miniblink49

namespace blink {

class Dictionary;
class DOMWindow;
class ExceptionState;
class ScriptState;
class WorkerGlobalScope;

class GlobalFetch {
<<<<<<< HEAD
    STATIC_ONLY(GlobalFetch);

public:
    class MODULES_EXPORT ScopedFetcher : public GarbageCollectedMixin {
    public:
        virtual ~ScopedFetcher();

        virtual ScriptPromise fetch(ScriptState*,
            const RequestInfo&,
            const Dictionary&,
            ExceptionState&)
            = 0;

        static ScopedFetcher* from(DOMWindow&);
        static ScopedFetcher* from(WorkerGlobalScope&);
=======
public:
    class MODULES_EXPORT ScopedFetcher {
    public:
        virtual ~ScopedFetcher();

        virtual ScriptPromise fetch(ScriptState*, const RequestInfo&, const Dictionary&, ExceptionState&) = 0;

        static WeakPtr<ScopedFetcher> from(DOMWindow&);
        static WeakPtr<ScopedFetcher> from(WorkerGlobalScope&);
>>>>>>> miniblink49

        DECLARE_VIRTUAL_TRACE();
    };

<<<<<<< HEAD
    static ScriptPromise fetch(ScriptState*,
        DOMWindow&,
        const RequestInfo&,
        const Dictionary&,
        ExceptionState&);
    static ScriptPromise fetch(ScriptState*,
        WorkerGlobalScope&,
        const RequestInfo&,
        const Dictionary&,
        ExceptionState&);
=======
    static ScriptPromise fetch(ScriptState*, DOMWindow&, const RequestInfo&, const Dictionary&, ExceptionState&);
    static ScriptPromise fetch(ScriptState*, WorkerGlobalScope&, const RequestInfo&, const Dictionary&, ExceptionState&);
>>>>>>> miniblink49
};

} // namespace blink

#endif // GlobalFetch_h
