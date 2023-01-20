/*
 * Copyright (C) 2010 Google Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FileWriter_h
#define FileWriter_h

<<<<<<< HEAD
#include "bindings/core/v8/ActiveScriptWrappable.h"
#include "core/dom/ContextLifecycleObserver.h"
=======
#include "core/dom/ActiveDOMObject.h"
>>>>>>> miniblink49
#include "core/dom/ExecutionContext.h"
#include "core/fileapi/FileError.h"
#include "modules/EventTargetModules.h"
#include "modules/filesystem/FileWriterBase.h"
#include "platform/heap/Handle.h"
#include "public/platform/WebFileWriterClient.h"

namespace blink {

class Blob;
class ExceptionState;
class ExecutionContext;

<<<<<<< HEAD
class FileWriter final : public EventTargetWithInlineData,
                         public FileWriterBase,
                         public ActiveScriptWrappable<FileWriter>,
                         public ContextLifecycleObserver,
                         public WebFileWriterClient {
    DEFINE_WRAPPERTYPEINFO();
    USING_GARBAGE_COLLECTED_MIXIN(FileWriter);
    USING_PRE_FINALIZER(FileWriter, dispose);

=======
class FileWriter final
#if ENABLE(OILPAN)
    : public EventTargetWithInlineData
    , public FileWriterBase
#else
    : public FileWriterBase
    , public EventTargetWithInlineData
#endif
    , public ActiveDOMObject
    , public WebFileWriterClient {
    REFCOUNTED_GARBAGE_COLLECTED_EVENT_TARGET(FileWriterBase);
    DEFINE_WRAPPERTYPEINFO();
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(FileWriter);
>>>>>>> miniblink49
public:
    static FileWriter* create(ExecutionContext*);
    ~FileWriter() override;

<<<<<<< HEAD
    enum ReadyState { kInit = 0,
        kWriting = 1,
        kDone = 2 };
=======
    enum ReadyState {
        INIT = 0,
        WRITING = 1,
        DONE = 2
    };
>>>>>>> miniblink49

    void write(Blob*, ExceptionState&);
    void seek(long long position, ExceptionState&);
    void truncate(long long length, ExceptionState&);
    void abort(ExceptionState&);
<<<<<<< HEAD
    ReadyState getReadyState() const { return m_readyState; }
    DOMException* error() const { return m_error.get(); }
=======
    ReadyState readyState() const { return m_readyState; }
    FileError* error() const { return m_error.get(); }
>>>>>>> miniblink49

    // WebFileWriterClient
    void didWrite(long long bytes, bool complete) override;
    void didTruncate() override;
    void didFail(WebFileError) override;

<<<<<<< HEAD
    // ContextLifecycleObserver
    void contextDestroyed(ExecutionContext*) override;

    // ScriptWrappable
    bool hasPendingActivity() const final;

    // EventTarget
    const AtomicString& interfaceName() const override;
    ExecutionContext* getExecutionContext() const override
    {
        return ContextLifecycleObserver::getExecutionContext();
    }
=======
    // ActiveDOMObject
    void stop() override;
    bool hasPendingActivity() const override;

    // EventTarget
    const AtomicString& interfaceName() const override;
    ExecutionContext* executionContext() const override { return ActiveDOMObject::executionContext(); }
>>>>>>> miniblink49

    DEFINE_ATTRIBUTE_EVENT_LISTENER(writestart);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(progress);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(write);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(abort);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(error);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(writeend);

    DECLARE_VIRTUAL_TRACE();

private:
    enum Operation {
        OperationNone,
        OperationWrite,
        OperationTruncate,
        OperationAbort
    };

    explicit FileWriter(ExecutionContext*);

    void completeAbort();

    void doOperation(Operation);

    void signalCompletion(FileError::ErrorCode);

    void fireEvent(const AtomicString& type);

    void setError(FileError::ErrorCode, ExceptionState&);

<<<<<<< HEAD
    void dispose();

    Member<DOMException> m_error;
=======
    Member<FileError> m_error;
>>>>>>> miniblink49
    ReadyState m_readyState;
    Operation m_operationInProgress;
    Operation m_queuedOperation;
    long long m_bytesWritten;
    long long m_bytesToWrite;
    long long m_truncateLength;
    long long m_numAborts;
    long long m_recursionDepth;
    double m_lastProgressNotificationTimeMS;
    Member<Blob> m_blobBeingWritten;
<<<<<<< HEAD
=======
    int m_asyncOperationId;
>>>>>>> miniblink49
};

} // namespace blink

#endif // FileWriter_h
