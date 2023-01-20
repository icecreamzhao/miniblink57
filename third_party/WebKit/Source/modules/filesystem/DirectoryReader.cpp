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
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/filesystem/DirectoryReader.h"

#include "core/fileapi/FileError.h"
#include "modules/filesystem/EntriesCallback.h"
#include "modules/filesystem/Entry.h"
#include "modules/filesystem/ErrorCallback.h"
<<<<<<< HEAD
#include "modules/filesystem/FileSystemCallbacks.h"
=======
>>>>>>> miniblink49

namespace blink {

class DirectoryReader::EntriesCallbackHelper final : public EntriesCallback {
public:
    explicit EntriesCallbackHelper(DirectoryReader* reader)
        : m_reader(reader)
    {
    }

    void handleEvent(const EntryHeapVector& entries) override
    {
        m_reader->addEntries(entries);
    }

    DEFINE_INLINE_VIRTUAL_TRACE()
    {
        visitor->trace(m_reader);
        EntriesCallback::trace(visitor);
    }

private:
<<<<<<< HEAD
    // FIXME: This Member keeps the reader alive until all of the readDirectory
    // results are received. crbug.com/350285
    Member<DirectoryReader> m_reader;
};

class DirectoryReader::ErrorCallbackHelper final : public ErrorCallbackBase {
=======
    // FIXME: This Member keeps the reader alive until all of the readDirectory results are received. crbug.com/350285
    Member<DirectoryReader> m_reader;
};

class DirectoryReader::ErrorCallbackHelper final : public ErrorCallback {
>>>>>>> miniblink49
public:
    explicit ErrorCallbackHelper(DirectoryReader* reader)
        : m_reader(reader)
    {
    }

<<<<<<< HEAD
    void invoke(FileError::ErrorCode error) override { m_reader->onError(error); }
=======
    void handleEvent(FileError* error) override
    {
        m_reader->onError(error);
    }
>>>>>>> miniblink49

    DEFINE_INLINE_VIRTUAL_TRACE()
    {
        visitor->trace(m_reader);
<<<<<<< HEAD
        ErrorCallbackBase::trace(visitor);
=======
        ErrorCallback::trace(visitor);
>>>>>>> miniblink49
    }

private:
    Member<DirectoryReader> m_reader;
};

<<<<<<< HEAD
DirectoryReader::DirectoryReader(DOMFileSystemBase* fileSystem,
    const String& fullPath)
=======
DirectoryReader::DirectoryReader(DOMFileSystemBase* fileSystem, const String& fullPath)
>>>>>>> miniblink49
    : DirectoryReaderBase(fileSystem, fullPath)
    , m_isReading(false)
{
}

<<<<<<< HEAD
DirectoryReader::~DirectoryReader() { }

void DirectoryReader::readEntries(EntriesCallback* entriesCallback,
    ErrorCallback* errorCallback)
{
    if (!m_isReading) {
        m_isReading = true;
        filesystem()->readDirectory(this, m_fullPath,
            new EntriesCallbackHelper(this),
            new ErrorCallbackHelper(this));
    }

    if (m_error) {
        filesystem()->reportError(ScriptErrorCallback::wrap(errorCallback),
            m_error);
=======
DirectoryReader::~DirectoryReader()
{
}

void DirectoryReader::readEntries(EntriesCallback* entriesCallback, ErrorCallback* errorCallback)
{
    if (!m_isReading) {
        m_isReading = true;
        filesystem()->readDirectory(this, m_fullPath, new EntriesCallbackHelper(this), new ErrorCallbackHelper(this));
    }

    if (m_error) {
        filesystem()->scheduleCallback(errorCallback, m_error);
>>>>>>> miniblink49
        return;
    }

    if (m_entriesCallback) {
<<<<<<< HEAD
        // Non-null m_entriesCallback means multiple readEntries() calls are made
        // concurrently. We don't allow doing it.
        filesystem()->reportError(ScriptErrorCallback::wrap(errorCallback),
            FileError::kInvalidStateErr);
=======
        // Non-null m_entriesCallback means multiple readEntries() calls are made concurrently. We don't allow doing it.
        filesystem()->scheduleCallback(errorCallback, FileError::create(FileError::INVALID_STATE_ERR));
>>>>>>> miniblink49
        return;
    }

    if (!m_hasMoreEntries || !m_entries.isEmpty()) {
<<<<<<< HEAD
        if (entriesCallback) {
            DOMFileSystem::scheduleCallback(
                filesystem()->getExecutionContext(),
                WTF::bind(&EntriesCallback::handleEvent,
                    wrapPersistent(entriesCallback),
                    PersistentHeapVector<Member<Entry>>(m_entries)));
        }
=======
        filesystem()->scheduleCallback(entriesCallback, m_entries);
>>>>>>> miniblink49
        m_entries.clear();
        return;
    }

    m_entriesCallback = entriesCallback;
    m_errorCallback = errorCallback;
}

void DirectoryReader::addEntries(const EntryHeapVector& entries)
{
    m_entries.appendVector(entries);
    m_errorCallback = nullptr;
    if (m_entriesCallback) {
        EntriesCallback* entriesCallback = m_entriesCallback.release();
        EntryHeapVector entries;
        entries.swap(m_entries);
        entriesCallback->handleEvent(entries);
    }
}

<<<<<<< HEAD
void DirectoryReader::onError(FileError::ErrorCode error)
{
    m_error = error;
    m_entriesCallback = nullptr;
    if (m_errorCallback)
        m_errorCallback->handleEvent(FileError::createDOMException(error));
=======
void DirectoryReader::onError(FileError* error)
{
    m_error = error;
    m_entriesCallback = nullptr;
    if (m_errorCallback) {
        ErrorCallback* errorCallback = m_errorCallback.release();
        errorCallback->handleEvent(error);
    }
>>>>>>> miniblink49
}

DEFINE_TRACE(DirectoryReader)
{
    visitor->trace(m_entries);
<<<<<<< HEAD
=======
    visitor->trace(m_error);
>>>>>>> miniblink49
    visitor->trace(m_entriesCallback);
    visitor->trace(m_errorCallback);
    DirectoryReaderBase::trace(visitor);
}

<<<<<<< HEAD
} // namespace blink
=======
}
>>>>>>> miniblink49
