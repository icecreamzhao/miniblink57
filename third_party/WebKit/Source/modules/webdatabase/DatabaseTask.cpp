/*
 * Copyright (C) 2007, 2008, 2013 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/webdatabase/DatabaseTask.h"

#include "modules/webdatabase/Database.h"
#include "modules/webdatabase/DatabaseContext.h"
#include "modules/webdatabase/DatabaseThread.h"
<<<<<<< HEAD
#include "modules/webdatabase/StorageLog.h"

namespace blink {

DatabaseTask::DatabaseTask(Database* database, WaitableEvent* completeEvent)
    : m_database(database)
    , m_completeEvent(completeEvent)
#if DCHECK_IS_ON()
=======
#include "platform/Logging.h"

namespace blink {

DatabaseTask::DatabaseTask(Database* database, TaskSynchronizer* synchronizer)
    : m_database(database)
    , m_synchronizer(synchronizer)
#if !LOG_DISABLED
>>>>>>> miniblink49
    , m_complete(false)
#endif
{
}

DatabaseTask::~DatabaseTask()
{
<<<<<<< HEAD
#if DCHECK_IS_ON()
    DCHECK(m_complete || !m_completeEvent);
=======
#if !LOG_DISABLED
    ASSERT(m_complete || !m_synchronizer);
>>>>>>> miniblink49
#endif
}

void DatabaseTask::run()
{
<<<<<<< HEAD
// Database tasks are meant to be used only once, so make sure this one hasn't
// been performed before.
#if DCHECK_IS_ON()
    ASSERT(!m_complete);
#endif

    if (!m_completeEvent && !m_database->getDatabaseContext()->databaseThread()->isDatabaseOpen(m_database.get())) {
        taskCancelled();
#if DCHECK_IS_ON()
=======
    // Database tasks are meant to be used only once, so make sure this one hasn't been performed before.
#if !LOG_DISABLED
    ASSERT(!m_complete);
#endif

    if (!m_synchronizer && !m_database->databaseContext()->databaseThread()->isDatabaseOpen(m_database.get())) {
        taskCancelled();
#if !LOG_DISABLED
>>>>>>> miniblink49
        m_complete = true;
#endif
        return;
    }
<<<<<<< HEAD
#if DCHECK_IS_ON()
    STORAGE_DVLOG(1) << "Performing " << debugTaskName() << " " << this;
#endif
    m_database->resetAuthorizer();
    doPerformTask();

    if (m_completeEvent)
        m_completeEvent->signal();

#if DCHECK_IS_ON()
=======

    WTF_LOG(StorageAPI, "Performing %s %p\n", debugTaskName(), this);

    m_database->resetAuthorizer();
    doPerformTask();

    if (m_synchronizer)
        m_synchronizer->taskCompleted();

#if !LOG_DISABLED
>>>>>>> miniblink49
    m_complete = true;
#endif
}

// *** DatabaseOpenTask ***
<<<<<<< HEAD
// Opens the database file and verifies the version matches the expected
// version.

Database::DatabaseOpenTask::DatabaseOpenTask(Database* database,
    bool setVersionInNewDatabase,
    WaitableEvent* completeEvent,
    DatabaseError& error,
    String& errorMessage,
    bool& success)
    : DatabaseTask(database, completeEvent)
=======
// Opens the database file and verifies the version matches the expected version.

Database::DatabaseOpenTask::DatabaseOpenTask(Database* database, bool setVersionInNewDatabase, TaskSynchronizer* synchronizer, DatabaseError& error, String& errorMessage, bool& success)
    : DatabaseTask(database, synchronizer)
>>>>>>> miniblink49
    , m_setVersionInNewDatabase(setVersionInNewDatabase)
    , m_error(error)
    , m_errorMessage(errorMessage)
    , m_success(success)
{
<<<<<<< HEAD
    DCHECK(completeEvent); // A task with output parameters is supposed to be
        // synchronous.
=======
    ASSERT(synchronizer); // A task with output parameters is supposed to be synchronous.
>>>>>>> miniblink49
}

void Database::DatabaseOpenTask::doPerformTask()
{
    String errorMessage;
<<<<<<< HEAD
    m_success = database()->performOpenAndVerify(m_setVersionInNewDatabase,
        m_error, errorMessage);
=======
    m_success = database()->performOpenAndVerify(m_setVersionInNewDatabase, m_error, errorMessage);
>>>>>>> miniblink49
    if (!m_success)
        m_errorMessage = errorMessage.isolatedCopy();
}

<<<<<<< HEAD
#if DCHECK_IS_ON()
=======
#if !LOG_DISABLED
>>>>>>> miniblink49
const char* Database::DatabaseOpenTask::debugTaskName() const
{
    return "DatabaseOpenTask";
}
#endif

// *** DatabaseCloseTask ***
// Closes the database.

<<<<<<< HEAD
Database::DatabaseCloseTask::DatabaseCloseTask(Database* database,
    WaitableEvent* completeEvent)
    : DatabaseTask(database, completeEvent)
=======
Database::DatabaseCloseTask::DatabaseCloseTask(Database* database, TaskSynchronizer* synchronizer)
    : DatabaseTask(database, synchronizer)
>>>>>>> miniblink49
{
}

void Database::DatabaseCloseTask::doPerformTask()
{
    database()->close();
}

<<<<<<< HEAD
#if DCHECK_IS_ON()
=======
#if !LOG_DISABLED
>>>>>>> miniblink49
const char* Database::DatabaseCloseTask::debugTaskName() const
{
    return "DatabaseCloseTask";
}
#endif

// *** DatabaseTransactionTask ***
// Starts a transaction that will report its results via a callback.

<<<<<<< HEAD
Database::DatabaseTransactionTask::DatabaseTransactionTask(
    SQLTransactionBackend* transaction)
=======
Database::DatabaseTransactionTask::DatabaseTransactionTask(SQLTransactionBackend* transaction)
>>>>>>> miniblink49
    : DatabaseTask(transaction->database(), 0)
    , m_transaction(transaction)
{
}

<<<<<<< HEAD
Database::DatabaseTransactionTask::~DatabaseTransactionTask() { }
=======
Database::DatabaseTransactionTask::~DatabaseTransactionTask()
{
}
>>>>>>> miniblink49

void Database::DatabaseTransactionTask::doPerformTask()
{
    m_transaction->performNextStep();
}

void Database::DatabaseTransactionTask::taskCancelled()
{
    // If the task is being destructed without the transaction ever being run,
    // then we must either have an error or an interruption. Give the
    // transaction a chance to clean up since it may not have been able to
    // run to its clean up state.

    // Transaction phase 2 cleanup. See comment on "What happens if a
    // transaction is interrupted?" at the top of SQLTransactionBackend.cpp.

    m_transaction->notifyDatabaseThreadIsShuttingDown();
}

<<<<<<< HEAD
#if DCHECK_IS_ON()
=======
#if !LOG_DISABLED
>>>>>>> miniblink49
const char* Database::DatabaseTransactionTask::debugTaskName() const
{
    return "DatabaseTransactionTask";
}
#endif

// *** DatabaseTableNamesTask ***
// Retrieves a list of all tables in the database - for WebInspector support.

<<<<<<< HEAD
Database::DatabaseTableNamesTask::DatabaseTableNamesTask(
    Database* database,
    WaitableEvent* completeEvent,
    Vector<String>& names)
    : DatabaseTask(database, completeEvent)
    , m_tableNames(names)
{
    DCHECK(completeEvent); // A task with output parameters is supposed to be
        // synchronous.
=======
Database::DatabaseTableNamesTask::DatabaseTableNamesTask(Database* database, TaskSynchronizer* synchronizer, Vector<String>& names)
    : DatabaseTask(database, synchronizer)
    , m_tableNames(names)
{
    ASSERT(synchronizer); // A task with output parameters is supposed to be synchronous.
>>>>>>> miniblink49
}

void Database::DatabaseTableNamesTask::doPerformTask()
{
    m_tableNames = database()->performGetTableNames();
}

<<<<<<< HEAD
#if DCHECK_IS_ON()
=======
#if !LOG_DISABLED
>>>>>>> miniblink49
const char* Database::DatabaseTableNamesTask::debugTaskName() const
{
    return "DatabaseTableNamesTask";
}
#endif

} // namespace blink
