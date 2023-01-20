/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
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

<<<<<<< HEAD
#include "modules/filesystem/DOMFileSystem.h"

#include "core/fileapi/BlobCallback.h"
#include "core/inspector/InspectorInstrumentation.h"
#include "modules/filesystem/DOMFilePath.h"
#include "modules/filesystem/DirectoryEntry.h"
=======
#include "config.h"
#include "modules/filesystem/DOMFileSystem.h"

#include "modules/filesystem/DOMFilePath.h"
#include "modules/filesystem/DirectoryEntry.h"
#include "modules/filesystem/ErrorCallback.h"
#include "modules/filesystem/FileCallback.h"
>>>>>>> miniblink49
#include "modules/filesystem/FileEntry.h"
#include "modules/filesystem/FileSystemCallbacks.h"
#include "modules/filesystem/FileWriter.h"
#include "modules/filesystem/FileWriterBaseCallback.h"
#include "modules/filesystem/FileWriterCallback.h"
#include "modules/filesystem/MetadataCallback.h"
#include "platform/FileMetadata.h"
<<<<<<< HEAD
#include "platform/WebTaskRunner.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/Platform.h"
#include "public/platform/WebFileSystem.h"
#include "public/platform/WebFileSystemCallbacks.h"
#include "public/platform/WebSecurityOrigin.h"
#include "wtf/text/StringBuilder.h"
#include "wtf/text/WTFString.h"
#include <memory>

namespace blink {

namespace {

    void runCallback(ExecutionContext* executionContext,
        std::unique_ptr<WTF::Closure> task)
    {
        if (!executionContext)
            return;
        DCHECK(executionContext->isContextThread());
        InspectorInstrumentation::AsyncTask asyncTask(executionContext, task.get(),
            true /* isInstrumented */);
        (*task)();
    }

} // namespace

// static
DOMFileSystem* DOMFileSystem::create(ExecutionContext* context,
    const String& name,
    FileSystemType type,
    const KURL& rootURL)
{
    return new DOMFileSystem(context, name, type, rootURL);
}

DOMFileSystem* DOMFileSystem::createIsolatedFileSystem(
    ExecutionContext* context,
    const String& filesystemId)
=======
#include "platform/weborigin/DatabaseIdentifier.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/WebFileSystem.h"
#include "public/platform/WebFileSystemCallbacks.h"
#include "wtf/OwnPtr.h"
#include "wtf/text/StringBuilder.h"
#include "wtf/text/WTFString.h"

namespace blink {

// static
DOMFileSystem* DOMFileSystem::create(ExecutionContext* context, const String& name, FileSystemType type, const KURL& rootURL)
{
    DOMFileSystem* fileSystem(new DOMFileSystem(context, name, type, rootURL));
    fileSystem->suspendIfNeeded();
    return fileSystem;
}

DOMFileSystem* DOMFileSystem::createIsolatedFileSystem(ExecutionContext* context, const String& filesystemId)
>>>>>>> miniblink49
{
    if (filesystemId.isEmpty())
        return 0;

    StringBuilder filesystemName;
<<<<<<< HEAD
    filesystemName.append(Platform::current()->fileSystemCreateOriginIdentifier(
        WebSecurityOrigin(context->getSecurityOrigin())));
    filesystemName.append(":Isolated_");
    filesystemName.append(filesystemId);

    // The rootURL created here is going to be attached to each filesystem request
    // and is to be validated each time the request is being handled.
    StringBuilder rootURL;
    rootURL.append("filesystem:");
    rootURL.append(context->getSecurityOrigin()->toString());
=======
    filesystemName.append(createDatabaseIdentifierFromSecurityOrigin(context->securityOrigin()));
    filesystemName.appendLiteral(":Isolated_");
    filesystemName.append(filesystemId);

    // The rootURL created here is going to be attached to each filesystem request and
    // is to be validated each time the request is being handled.
    StringBuilder rootURL;
    rootURL.appendLiteral("filesystem:");
    rootURL.append(context->securityOrigin()->toString());
>>>>>>> miniblink49
    rootURL.append('/');
    rootURL.append(isolatedPathPrefix);
    rootURL.append('/');
    rootURL.append(filesystemId);
    rootURL.append('/');

<<<<<<< HEAD
    return DOMFileSystem::create(context, filesystemName.toString(),
        FileSystemTypeIsolated,
        KURL(ParsedURLString, rootURL.toString()));
}

DOMFileSystem::DOMFileSystem(ExecutionContext* context,
    const String& name,
    FileSystemType type,
    const KURL& rootURL)
    : DOMFileSystemBase(context, name, type, rootURL)
    , ContextLifecycleObserver(context)
=======
    return DOMFileSystem::create(context, filesystemName.toString(), FileSystemTypeIsolated, KURL(ParsedURLString, rootURL.toString()));
}

DOMFileSystem::DOMFileSystem(ExecutionContext* context, const String& name, FileSystemType type, const KURL& rootURL)
    : DOMFileSystemBase(context, name, type, rootURL)
    , ActiveDOMObject(context)
>>>>>>> miniblink49
    , m_numberOfPendingCallbacks(0)
    , m_rootEntry(DirectoryEntry::create(this, DOMFilePath::root))
{
}

DirectoryEntry* DOMFileSystem::root() const
{
    return m_rootEntry.get();
}

void DOMFileSystem::addPendingCallbacks()
{
    ++m_numberOfPendingCallbacks;
}

void DOMFileSystem::removePendingCallbacks()
{
    ASSERT(m_numberOfPendingCallbacks > 0);
    --m_numberOfPendingCallbacks;
}

bool DOMFileSystem::hasPendingActivity() const
{
    ASSERT(m_numberOfPendingCallbacks >= 0);
    return m_numberOfPendingCallbacks;
}

<<<<<<< HEAD
void DOMFileSystem::reportError(ErrorCallbackBase* errorCallback,
    FileError::ErrorCode fileError)
{
    reportError(getExecutionContext(), errorCallback, fileError);
}

void DOMFileSystem::reportError(ExecutionContext* executionContext,
    ErrorCallbackBase* errorCallback,
    FileError::ErrorCode fileError)
{
    if (!errorCallback)
        return;
    scheduleCallback(executionContext,
        WTF::bind(&ErrorCallbackBase::invoke,
            wrapPersistent(errorCallback), fileError));
=======
void DOMFileSystem::reportError(ErrorCallback* errorCallback, FileError* fileError)
{
    scheduleCallback(errorCallback, fileError);
>>>>>>> miniblink49
}

namespace {

<<<<<<< HEAD
    class ConvertToFileWriterCallback : public FileWriterBaseCallback {
    public:
        static ConvertToFileWriterCallback* create(FileWriterCallback* callback)
        {
            return new ConvertToFileWriterCallback(callback);
        }

        DEFINE_INLINE_TRACE()
        {
            visitor->trace(m_callback);
            FileWriterBaseCallback::trace(visitor);
        }

        void handleEvent(FileWriterBase* fileWriterBase)
        {
            m_callback->handleEvent(static_cast<FileWriter*>(fileWriterBase));
        }

    private:
        explicit ConvertToFileWriterCallback(FileWriterCallback* callback)
            : m_callback(callback)
        {
        }
        Member<FileWriterCallback> m_callback;
    };

} // namespace

void DOMFileSystem::createWriter(const FileEntry* fileEntry,
    FileWriterCallback* successCallback,
    ErrorCallbackBase* errorCallback)
=======
class ConvertToFileWriterCallback : public FileWriterBaseCallback {
public:
    static ConvertToFileWriterCallback* create(FileWriterCallback* callback)
    {
        return new ConvertToFileWriterCallback(callback);
    }

    DEFINE_INLINE_TRACE()
    {
        visitor->trace(m_callback);
        FileWriterBaseCallback::trace(visitor);
    }

    void handleEvent(FileWriterBase* fileWriterBase)
    {
        m_callback->handleEvent(static_cast<FileWriter*>(fileWriterBase));
    }
private:
    explicit ConvertToFileWriterCallback(FileWriterCallback* callback)
        : m_callback(callback)
    {
    }
    Member<FileWriterCallback> m_callback;
};

}

void DOMFileSystem::createWriter(const FileEntry* fileEntry, FileWriterCallback* successCallback, ErrorCallback* errorCallback)
>>>>>>> miniblink49
{
    ASSERT(fileEntry);

    if (!fileSystem()) {
<<<<<<< HEAD
        reportError(errorCallback, FileError::kAbortErr);
        return;
    }

    FileWriter* fileWriter = FileWriter::create(getExecutionContext());
    FileWriterBaseCallback* conversionCallback = ConvertToFileWriterCallback::create(successCallback);
    std::unique_ptr<AsyncFileSystemCallbacks> callbacks = FileWriterBaseCallbacks::create(fileWriter, conversionCallback,
        errorCallback, m_context);
    fileSystem()->createFileWriter(createFileSystemURL(fileEntry), fileWriter,
        std::move(callbacks));
}

void DOMFileSystem::createFile(const FileEntry* fileEntry,
    BlobCallback* successCallback,
    ErrorCallbackBase* errorCallback)
{
    KURL fileSystemURL = createFileSystemURL(fileEntry);
    if (!fileSystem()) {
        reportError(errorCallback, FileError::kAbortErr);
        return;
    }

    fileSystem()->createSnapshotFileAndReadMetadata(
        fileSystemURL,
        SnapshotFileCallback::create(this, fileEntry->name(), fileSystemURL,
            successCallback, errorCallback, m_context));
}

void DOMFileSystem::scheduleCallback(ExecutionContext* executionContext,
    std::unique_ptr<WTF::Closure> task)
{
    DCHECK(executionContext->isContextThread());
    InspectorInstrumentation::asyncTaskScheduled(
        executionContext, taskNameForInstrumentation(), task.get());
    TaskRunnerHelper::get(TaskType::FileReading, executionContext)
        ->postTask(BLINK_FROM_HERE,
            WTF::bind(&runCallback, wrapWeakPersistent(executionContext),
                WTF::passed(std::move(task))));
=======
        reportError(errorCallback, FileError::create(FileError::ABORT_ERR));
        return;
    }

    FileWriter* fileWriter = FileWriter::create(executionContext());
    FileWriterBaseCallback* conversionCallback = ConvertToFileWriterCallback::create(successCallback);
    OwnPtr<AsyncFileSystemCallbacks> callbacks = FileWriterBaseCallbacks::create(fileWriter, conversionCallback, errorCallback, m_context);
    fileSystem()->createFileWriter(createFileSystemURL(fileEntry), fileWriter, callbacks.release());
}

void DOMFileSystem::createFile(const FileEntry* fileEntry, FileCallback* successCallback, ErrorCallback* errorCallback)
{
    KURL fileSystemURL = createFileSystemURL(fileEntry);
    if (!fileSystem()) {
        reportError(errorCallback, FileError::create(FileError::ABORT_ERR));
        return;
    }

    fileSystem()->createSnapshotFileAndReadMetadata(fileSystemURL, SnapshotFileCallback::create(this, fileEntry->name(), fileSystemURL, successCallback, errorCallback, m_context));
>>>>>>> miniblink49
}

DEFINE_TRACE(DOMFileSystem)
{
    DOMFileSystemBase::trace(visitor);
<<<<<<< HEAD
    ContextLifecycleObserver::trace(visitor);
=======
    ActiveDOMObject::trace(visitor);
>>>>>>> miniblink49
    visitor->trace(m_rootEntry);
}

} // namespace blink
