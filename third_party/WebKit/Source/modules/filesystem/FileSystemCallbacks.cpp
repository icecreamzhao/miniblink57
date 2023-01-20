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
#include "modules/filesystem/FileSystemCallbacks.h"

#include "core/dom/ExecutionContext.h"
#include "core/fileapi/BlobCallback.h"
#include "core/fileapi/File.h"
#include "core/fileapi/FileError.h"
#include "core/html/VoidCallback.h"
=======
#include "config.h"
#include "modules/filesystem/FileSystemCallbacks.h"

#include "core/dom/ExecutionContext.h"
#include "core/fileapi/File.h"
#include "core/fileapi/FileError.h"
#include "core/html/VoidCallback.h"
#include "core/inspector/InspectorInstrumentation.h"
>>>>>>> miniblink49
#include "modules/filesystem/DOMFilePath.h"
#include "modules/filesystem/DOMFileSystem.h"
#include "modules/filesystem/DOMFileSystemBase.h"
#include "modules/filesystem/DirectoryEntry.h"
#include "modules/filesystem/DirectoryReader.h"
#include "modules/filesystem/Entry.h"
#include "modules/filesystem/EntryCallback.h"
#include "modules/filesystem/ErrorCallback.h"
<<<<<<< HEAD
=======
#include "modules/filesystem/FileCallback.h"
>>>>>>> miniblink49
#include "modules/filesystem/FileEntry.h"
#include "modules/filesystem/FileSystemCallback.h"
#include "modules/filesystem/FileWriterBase.h"
#include "modules/filesystem/FileWriterBaseCallback.h"
#include "modules/filesystem/Metadata.h"
#include "modules/filesystem/MetadataCallback.h"
#include "platform/FileMetadata.h"
#include "public/platform/WebFileWriter.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

FileSystemCallbacksBase::FileSystemCallbacksBase(
    ErrorCallbackBase* errorCallback,
    DOMFileSystemBase* fileSystem,
    ExecutionContext* context)
    : m_errorCallback(errorCallback)
    , m_fileSystem(fileSystem)
    , m_executionContext(context)
{
    if (m_fileSystem)
        m_fileSystem->addPendingCallbacks();
=======

namespace blink {

FileSystemCallbacksBase::FileSystemCallbacksBase(ErrorCallback* errorCallback, DOMFileSystemBase* fileSystem, ExecutionContext* context)
    : m_errorCallback(errorCallback)
    , m_fileSystem(fileSystem)
    , m_executionContext(context)
    , m_asyncOperationId(0)
{
    if (m_fileSystem)
        m_fileSystem->addPendingCallbacks();
    if (m_executionContext)
        m_asyncOperationId = InspectorInstrumentation::traceAsyncOperationStarting(m_executionContext.get(), "FileSystem");
>>>>>>> miniblink49
}

FileSystemCallbacksBase::~FileSystemCallbacksBase()
{
    if (m_fileSystem)
        m_fileSystem->removePendingCallbacks();
<<<<<<< HEAD
=======
    if (m_asyncOperationId && m_executionContext)
        InspectorInstrumentation::traceAsyncOperationCompleted(m_executionContext.get(), m_asyncOperationId);
>>>>>>> miniblink49
}

void FileSystemCallbacksBase::didFail(int code)
{
    if (m_errorCallback)
<<<<<<< HEAD
        invokeOrScheduleCallback(m_errorCallback.release(),
            static_cast<FileError::ErrorCode>(code));
=======
        handleEventOrScheduleCallback(m_errorCallback.release(), FileError::create(static_cast<FileError::ErrorCode>(code)));
>>>>>>> miniblink49
}

bool FileSystemCallbacksBase::shouldScheduleCallback() const
{
<<<<<<< HEAD
    return !shouldBlockUntilCompletion() && m_executionContext && m_executionContext->isContextSuspended();
}

template <typename CB, typename CBArg>
void FileSystemCallbacksBase::invokeOrScheduleCallback(CB* callback,
    CBArg arg)
{
    DCHECK(callback);
    if (callback) {
        if (shouldScheduleCallback()) {
            DOMFileSystem::scheduleCallback(
                m_executionContext.get(),
                WTF::bind(&CB::invoke, wrapPersistent(callback), arg));
        } else {
            callback->invoke(arg);
        }
    }
    m_executionContext.clear();
}

template <typename CB, typename CBArg>
void FileSystemCallbacksBase::handleEventOrScheduleCallback(CB* callback,
    CBArg* arg)
{
    DCHECK(callback);
    if (callback) {
        if (shouldScheduleCallback()) {
            DOMFileSystem::scheduleCallback(
                m_executionContext.get(),
                WTF::bind(&CB::handleEvent, wrapPersistent(callback),
                    wrapPersistent(arg)));
        } else {
            callback->handleEvent(arg);
        }
    }
    m_executionContext.clear();
}

template <typename CB>
void FileSystemCallbacksBase::handleEventOrScheduleCallback(CB* callback)
{
    DCHECK(callback);
    if (callback) {
        if (shouldScheduleCallback()) {
            DOMFileSystem::scheduleCallback(
                m_executionContext.get(),
                WTF::bind(&CB::handleEvent, wrapPersistent(callback)));
        } else {
            callback->handleEvent();
        }
    }
    m_executionContext.clear();
}

// ScriptErrorCallback --------------------------------------------------------

// static
ScriptErrorCallback* ScriptErrorCallback::wrap(ErrorCallback* callback)
{
    // DOMFileSystem operations take an optional (nullable) callback. If a
    // script callback was not passed, don't bother creating a dummy wrapper
    // and checking during invoke().
    if (!callback)
        return nullptr;
    return new ScriptErrorCallback(callback);
}

DEFINE_TRACE(ScriptErrorCallback)
{
    ErrorCallbackBase::trace(visitor);
    visitor->trace(m_callback);
}

void ScriptErrorCallback::invoke(FileError::ErrorCode error)
{
    m_callback->handleEvent(FileError::createDOMException(error));
};

ScriptErrorCallback::ScriptErrorCallback(ErrorCallback* callback)
    : m_callback(callback)
{
=======
    return !shouldBlockUntilCompletion() && m_executionContext && m_executionContext->activeDOMObjectsAreSuspended();
}

template <typename CB, typename CBArg>
void FileSystemCallbacksBase::handleEventOrScheduleCallback(RawPtr<CB> callback, CBArg* arg)
{
    ASSERT(callback);
    InspectorInstrumentationCookie cookie = InspectorInstrumentation::traceAsyncOperationCompletedCallbackStarting(m_executionContext.get(), m_asyncOperationId);
    if (shouldScheduleCallback())
        DOMFileSystem::scheduleCallback(m_executionContext.get(), callback.get(), arg);
    else if (callback)
        callback->handleEvent(arg);
    m_executionContext.clear();
    InspectorInstrumentation::traceAsyncCallbackCompleted(cookie);
}

template <typename CB>
void FileSystemCallbacksBase::handleEventOrScheduleCallback(RawPtr<CB> callback)
{
    ASSERT(callback);
    InspectorInstrumentationCookie cookie = InspectorInstrumentation::traceAsyncOperationCompletedCallbackStarting(m_executionContext.get(), m_asyncOperationId);
    if (shouldScheduleCallback())
        DOMFileSystem::scheduleCallback(m_executionContext.get(), callback.get());
    else if (callback)
        callback->handleEvent();
    m_executionContext.clear();
    InspectorInstrumentation::traceAsyncCallbackCompleted(cookie);
>>>>>>> miniblink49
}

// EntryCallbacks -------------------------------------------------------------

<<<<<<< HEAD
std::unique_ptr<AsyncFileSystemCallbacks> EntryCallbacks::create(
    EntryCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context,
    DOMFileSystemBase* fileSystem,
    const String& expectedPath,
    bool isDirectory)
{
    return WTF::wrapUnique(new EntryCallbacks(successCallback, errorCallback,
        context, fileSystem, expectedPath,
        isDirectory));
}

EntryCallbacks::EntryCallbacks(EntryCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context,
    DOMFileSystemBase* fileSystem,
    const String& expectedPath,
    bool isDirectory)
=======
PassOwnPtr<AsyncFileSystemCallbacks> EntryCallbacks::create(EntryCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context, DOMFileSystemBase* fileSystem, const String& expectedPath, bool isDirectory)
{
    return adoptPtr(new EntryCallbacks(successCallback, errorCallback, context, fileSystem, expectedPath, isDirectory));
}

EntryCallbacks::EntryCallbacks(EntryCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context, DOMFileSystemBase* fileSystem, const String& expectedPath, bool isDirectory)
>>>>>>> miniblink49
    : FileSystemCallbacksBase(errorCallback, fileSystem, context)
    , m_successCallback(successCallback)
    , m_expectedPath(expectedPath)
    , m_isDirectory(isDirectory)
{
}

void EntryCallbacks::didSucceed()
{
    if (m_successCallback) {
        if (m_isDirectory)
<<<<<<< HEAD
            handleEventOrScheduleCallback(
                m_successCallback.release(),
                DirectoryEntry::create(m_fileSystem, m_expectedPath));
        else
            handleEventOrScheduleCallback(
                m_successCallback.release(),
                FileEntry::create(m_fileSystem, m_expectedPath));
=======
            handleEventOrScheduleCallback(m_successCallback.release(), DirectoryEntry::create(m_fileSystem, m_expectedPath));
        else
            handleEventOrScheduleCallback(m_successCallback.release(), FileEntry::create(m_fileSystem, m_expectedPath));
>>>>>>> miniblink49
    }
}

// EntriesCallbacks -----------------------------------------------------------

<<<<<<< HEAD
std::unique_ptr<AsyncFileSystemCallbacks> EntriesCallbacks::create(
    EntriesCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context,
    DirectoryReaderBase* directoryReader,
    const String& basePath)
{
    return WTF::wrapUnique(new EntriesCallbacks(
        successCallback, errorCallback, context, directoryReader, basePath));
}

EntriesCallbacks::EntriesCallbacks(EntriesCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context,
    DirectoryReaderBase* directoryReader,
    const String& basePath)
    : FileSystemCallbacksBase(errorCallback,
        directoryReader->filesystem(),
        context)
=======
PassOwnPtr<AsyncFileSystemCallbacks> EntriesCallbacks::create(EntriesCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context, DirectoryReaderBase* directoryReader, const String& basePath)
{
    return adoptPtr(new EntriesCallbacks(successCallback, errorCallback, context, directoryReader, basePath));
}

EntriesCallbacks::EntriesCallbacks(EntriesCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context, DirectoryReaderBase* directoryReader, const String& basePath)
    : FileSystemCallbacksBase(errorCallback, directoryReader->filesystem(), context)
>>>>>>> miniblink49
    , m_successCallback(successCallback)
    , m_directoryReader(directoryReader)
    , m_basePath(basePath)
{
    ASSERT(m_directoryReader);
}

<<<<<<< HEAD
void EntriesCallbacks::didReadDirectoryEntry(const String& name,
    bool isDirectory)
{
    if (isDirectory)
        m_entries.push_back(
            DirectoryEntry::create(m_directoryReader->filesystem(),
                DOMFilePath::append(m_basePath, name)));
    else
        m_entries.push_back(
            FileEntry::create(m_directoryReader->filesystem(),
                DOMFilePath::append(m_basePath, name)));
=======
void EntriesCallbacks::didReadDirectoryEntry(const String& name, bool isDirectory)
{
    if (isDirectory)
        m_entries.append(DirectoryEntry::create(m_directoryReader->filesystem(), DOMFilePath::append(m_basePath, name)));
    else
        m_entries.append(FileEntry::create(m_directoryReader->filesystem(), DOMFilePath::append(m_basePath, name)));
>>>>>>> miniblink49
}

void EntriesCallbacks::didReadDirectoryEntries(bool hasMore)
{
    m_directoryReader->setHasMoreEntries(hasMore);
    EntryHeapVector entries;
    entries.swap(m_entries);
    // FIXME: delay the callback iff shouldScheduleCallback() is true.
<<<<<<< HEAD
    if (m_successCallback)
        m_successCallback->handleEvent(entries);
=======
    InspectorInstrumentationCookie cookie = InspectorInstrumentation::traceAsyncCallbackStarting(m_executionContext.get(), m_asyncOperationId);
    if (m_successCallback)
        m_successCallback->handleEvent(entries);
    InspectorInstrumentation::traceAsyncCallbackCompleted(cookie);
    if (!hasMore)
        InspectorInstrumentation::traceAsyncOperationCompleted(m_executionContext.get(), m_asyncOperationId);
>>>>>>> miniblink49
}

// FileSystemCallbacks --------------------------------------------------------

<<<<<<< HEAD
std::unique_ptr<AsyncFileSystemCallbacks> FileSystemCallbacks::create(
    FileSystemCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context,
    FileSystemType type)
{
    return WTF::wrapUnique(
        new FileSystemCallbacks(successCallback, errorCallback, context, type));
}

FileSystemCallbacks::FileSystemCallbacks(FileSystemCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context,
    FileSystemType type)
=======
PassOwnPtr<AsyncFileSystemCallbacks> FileSystemCallbacks::create(FileSystemCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context, FileSystemType type)
{
    return adoptPtr(new FileSystemCallbacks(successCallback, errorCallback, context, type));
}

FileSystemCallbacks::FileSystemCallbacks(FileSystemCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context, FileSystemType type)
>>>>>>> miniblink49
    : FileSystemCallbacksBase(errorCallback, nullptr, context)
    , m_successCallback(successCallback)
    , m_type(type)
{
}

<<<<<<< HEAD
void FileSystemCallbacks::didOpenFileSystem(const String& name,
    const KURL& rootURL)
{
    if (m_successCallback)
        handleEventOrScheduleCallback(
            m_successCallback.release(),
            DOMFileSystem::create(m_executionContext.get(), name, m_type, rootURL));
=======
void FileSystemCallbacks::didOpenFileSystem(const String& name, const KURL& rootURL)
{
    if (m_successCallback)
        handleEventOrScheduleCallback(m_successCallback.release(), DOMFileSystem::create(m_executionContext.get(), name, m_type, rootURL));
>>>>>>> miniblink49
}

// ResolveURICallbacks --------------------------------------------------------

<<<<<<< HEAD
std::unique_ptr<AsyncFileSystemCallbacks> ResolveURICallbacks::create(
    EntryCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context)
{
    return WTF::wrapUnique(
        new ResolveURICallbacks(successCallback, errorCallback, context));
}

ResolveURICallbacks::ResolveURICallbacks(EntryCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context)
=======
PassOwnPtr<AsyncFileSystemCallbacks> ResolveURICallbacks::create(EntryCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context)
{
    return adoptPtr(new ResolveURICallbacks(successCallback, errorCallback, context));
}

ResolveURICallbacks::ResolveURICallbacks(EntryCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context)
>>>>>>> miniblink49
    : FileSystemCallbacksBase(errorCallback, nullptr, context)
    , m_successCallback(successCallback)
{
}

<<<<<<< HEAD
void ResolveURICallbacks::didResolveURL(const String& name,
    const KURL& rootURL,
    FileSystemType type,
    const String& filePath,
    bool isDirectory)
=======
void ResolveURICallbacks::didResolveURL(const String& name, const KURL& rootURL, FileSystemType type, const String& filePath, bool isDirectory)
>>>>>>> miniblink49
{
    DOMFileSystem* filesystem = DOMFileSystem::create(m_executionContext.get(), name, type, rootURL);
    DirectoryEntry* root = filesystem->root();

    String absolutePath;
<<<<<<< HEAD
    if (!DOMFileSystemBase::pathToAbsolutePath(type, root, filePath,
            absolutePath)) {
        invokeOrScheduleCallback(m_errorCallback.release(),
            FileError::kInvalidModificationErr);
=======
    if (!DOMFileSystemBase::pathToAbsolutePath(type, root, filePath, absolutePath)) {
        handleEventOrScheduleCallback(m_errorCallback.release(), FileError::create(FileError::INVALID_MODIFICATION_ERR));
>>>>>>> miniblink49
        return;
    }

    if (isDirectory)
<<<<<<< HEAD
        handleEventOrScheduleCallback(
            m_successCallback.release(),
            DirectoryEntry::create(filesystem, absolutePath));
    else
        handleEventOrScheduleCallback(m_successCallback.release(),
            FileEntry::create(filesystem, absolutePath));
=======
        handleEventOrScheduleCallback(m_successCallback.release(), DirectoryEntry::create(filesystem, absolutePath));
    else
        handleEventOrScheduleCallback(m_successCallback.release(), FileEntry::create(filesystem, absolutePath));
>>>>>>> miniblink49
}

// MetadataCallbacks ----------------------------------------------------------

<<<<<<< HEAD
std::unique_ptr<AsyncFileSystemCallbacks> MetadataCallbacks::create(
    MetadataCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context,
    DOMFileSystemBase* fileSystem)
{
    return WTF::wrapUnique(new MetadataCallbacks(successCallback, errorCallback,
        context, fileSystem));
}

MetadataCallbacks::MetadataCallbacks(MetadataCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context,
    DOMFileSystemBase* fileSystem)
=======
PassOwnPtr<AsyncFileSystemCallbacks> MetadataCallbacks::create(MetadataCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context, DOMFileSystemBase* fileSystem)
{
    return adoptPtr(new MetadataCallbacks(successCallback, errorCallback, context, fileSystem));
}

MetadataCallbacks::MetadataCallbacks(MetadataCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context, DOMFileSystemBase* fileSystem)
>>>>>>> miniblink49
    : FileSystemCallbacksBase(errorCallback, fileSystem, context)
    , m_successCallback(successCallback)
{
}

void MetadataCallbacks::didReadMetadata(const FileMetadata& metadata)
{
    if (m_successCallback)
<<<<<<< HEAD
        handleEventOrScheduleCallback(m_successCallback.release(),
            Metadata::create(metadata));
=======
        handleEventOrScheduleCallback(m_successCallback.release(), Metadata::create(metadata));
>>>>>>> miniblink49
}

// FileWriterBaseCallbacks ----------------------------------------------------

<<<<<<< HEAD
std::unique_ptr<AsyncFileSystemCallbacks> FileWriterBaseCallbacks::create(
    FileWriterBase* fileWriter,
    FileWriterBaseCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context)
{
    return WTF::wrapUnique(new FileWriterBaseCallbacks(
        fileWriter, successCallback, errorCallback, context));
}

FileWriterBaseCallbacks::FileWriterBaseCallbacks(
    FileWriterBase* fileWriter,
    FileWriterBaseCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context)
=======
PassOwnPtr<AsyncFileSystemCallbacks> FileWriterBaseCallbacks::create(FileWriterBase* fileWriter, FileWriterBaseCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context)
{
    return adoptPtr(new FileWriterBaseCallbacks(fileWriter, successCallback, errorCallback, context));
}

FileWriterBaseCallbacks::FileWriterBaseCallbacks(FileWriterBase* fileWriter, FileWriterBaseCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context)
>>>>>>> miniblink49
    : FileSystemCallbacksBase(errorCallback, nullptr, context)
    , m_fileWriter(fileWriter)
    , m_successCallback(successCallback)
{
}

<<<<<<< HEAD
void FileWriterBaseCallbacks::didCreateFileWriter(
    std::unique_ptr<WebFileWriter> fileWriter,
    long long length)
{
    m_fileWriter->initialize(std::move(fileWriter), length);
    if (m_successCallback)
        handleEventOrScheduleCallback(m_successCallback.release(),
            m_fileWriter.release());
=======
void FileWriterBaseCallbacks::didCreateFileWriter(PassOwnPtr<WebFileWriter> fileWriter, long long length)
{
    m_fileWriter->initialize(fileWriter, length);
    if (m_successCallback)
        handleEventOrScheduleCallback(m_successCallback.release(), m_fileWriter.release().get());
>>>>>>> miniblink49
}

// SnapshotFileCallback -------------------------------------------------------

<<<<<<< HEAD
std::unique_ptr<AsyncFileSystemCallbacks> SnapshotFileCallback::create(
    DOMFileSystemBase* filesystem,
    const String& name,
    const KURL& url,
    BlobCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context)
{
    return WTF::wrapUnique(new SnapshotFileCallback(
        filesystem, name, url, successCallback, errorCallback, context));
}

SnapshotFileCallback::SnapshotFileCallback(DOMFileSystemBase* filesystem,
    const String& name,
    const KURL& url,
    BlobCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context)
=======
PassOwnPtr<AsyncFileSystemCallbacks> SnapshotFileCallback::create(DOMFileSystemBase* filesystem, const String& name, const KURL& url, FileCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context)
{
    return adoptPtr(new SnapshotFileCallback(filesystem, name, url, successCallback, errorCallback, context));
}

SnapshotFileCallback::SnapshotFileCallback(DOMFileSystemBase* filesystem, const String& name, const KURL& url, FileCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context)
>>>>>>> miniblink49
    : FileSystemCallbacksBase(errorCallback, filesystem, context)
    , m_name(name)
    , m_url(url)
    , m_successCallback(successCallback)
{
}

<<<<<<< HEAD
void SnapshotFileCallback::didCreateSnapshotFile(
    const FileMetadata& metadata,
    PassRefPtr<BlobDataHandle> snapshot)
=======
void SnapshotFileCallback::didCreateSnapshotFile(const FileMetadata& metadata, PassRefPtr<BlobDataHandle> snapshot)
>>>>>>> miniblink49
{
    if (!m_successCallback)
        return;

<<<<<<< HEAD
    // We can't directly use the snapshot blob data handle because the content
    // type on it hasn't been set.  The |snapshot| param is here to provide a a
    // chain of custody thru thread bridging that is held onto until *after* we've
    // coined a File with a new handle that has the correct type set on it. This
    // allows the blob storage system to track when a temp file can and can't be
    // safely deleted.

    handleEventOrScheduleCallback(
        m_successCallback.release(),
        DOMFileSystemBase::createFile(metadata, m_url, m_fileSystem->type(),
            m_name));
=======
    // We can't directly use the snapshot blob data handle because the content type on it hasn't been set.
    // The |snapshot| param is here to provide a a chain of custody thru thread bridging that is held onto until
    // *after* we've coined a File with a new handle that has the correct type set on it. This allows the
    // blob storage system to track when a temp file can and can't be safely deleted.

    handleEventOrScheduleCallback(m_successCallback.release(), DOMFileSystemBase::createFile(metadata, m_url, m_fileSystem->type(), m_name));
>>>>>>> miniblink49
}

// VoidCallbacks --------------------------------------------------------------

<<<<<<< HEAD
std::unique_ptr<AsyncFileSystemCallbacks> VoidCallbacks::create(
    VoidCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context,
    DOMFileSystemBase* fileSystem)
{
    return WTF::wrapUnique(
        new VoidCallbacks(successCallback, errorCallback, context, fileSystem));
}

VoidCallbacks::VoidCallbacks(VoidCallback* successCallback,
    ErrorCallbackBase* errorCallback,
    ExecutionContext* context,
    DOMFileSystemBase* fileSystem)
=======
PassOwnPtr<AsyncFileSystemCallbacks> VoidCallbacks::create(VoidCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context, DOMFileSystemBase* fileSystem)
{
    return adoptPtr(new VoidCallbacks(successCallback, errorCallback, context, fileSystem));
}

VoidCallbacks::VoidCallbacks(VoidCallback* successCallback, ErrorCallback* errorCallback, ExecutionContext* context, DOMFileSystemBase* fileSystem)
>>>>>>> miniblink49
    : FileSystemCallbacksBase(errorCallback, fileSystem, context)
    , m_successCallback(successCallback)
{
}

void VoidCallbacks::didSucceed()
{
    if (m_successCallback)
        handleEventOrScheduleCallback(m_successCallback.release());
}

} // namespace blink
