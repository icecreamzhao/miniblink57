/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
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
#include "modules/webdatabase/sqlite/SQLiteFileSystem.h"

#include "platform/heap/Handle.h"
#include "platform/heap/SafePoint.h"
<<<<<<< HEAD
#include "third_party/sqlite/sqlite3.h"
=======
#include <sqlite3.h>
>>>>>>> miniblink49
#include "wtf/text/CString.h"

// SQLiteFileSystem::registerSQLiteVFS() is implemented in the
// platform-specific files SQLiteFileSystemChromium{Win|Posix}.cpp
namespace blink {

<<<<<<< HEAD
SQLiteFileSystem::SQLiteFileSystem() { }

int SQLiteFileSystem::openDatabase(const String& filename, sqlite3** database)
{
    SafePointScope scope(BlinkGC::HeapPointersOnStack);
    return sqlite3_open_v2(filename.utf8().data(), database,
        SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
        "chromium_vfs");
=======
SQLiteFileSystem::SQLiteFileSystem()
{
}

int SQLiteFileSystem::openDatabase(const String& filename, sqlite3** database)
{
    SafePointScope scope(ThreadState::HeapPointersOnStack);
    return sqlite3_open_v2(filename.utf8().data(), database, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, "chromium_vfs");
>>>>>>> miniblink49
}

} // namespace blink
