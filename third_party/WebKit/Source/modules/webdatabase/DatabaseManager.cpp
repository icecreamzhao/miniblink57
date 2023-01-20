/*
 * Copyright (C) 2012 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/webdatabase/DatabaseManager.h"

#include "bindings/core/v8/ExceptionMessages.h"
#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "core/dom/ExecutionContextTask.h"
<<<<<<< HEAD
#include "core/dom/TaskRunnerHelper.h"
=======
>>>>>>> miniblink49
#include "core/inspector/ConsoleMessage.h"
#include "modules/webdatabase/Database.h"
#include "modules/webdatabase/DatabaseCallback.h"
#include "modules/webdatabase/DatabaseClient.h"
#include "modules/webdatabase/DatabaseContext.h"
#include "modules/webdatabase/DatabaseTask.h"
#include "modules/webdatabase/DatabaseTracker.h"
<<<<<<< HEAD
#include "modules/webdatabase/StorageLog.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/WebTraceLocation.h"
#include "wtf/PtrUtil.h"
=======
#include "platform/Logging.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/WebTraceLocation.h"
#include "wtf/MainThread.h"
>>>>>>> miniblink49

namespace blink {

static DatabaseManager* s_databaseManager;

DatabaseManager& DatabaseManager::manager()
{
<<<<<<< HEAD
    DCHECK(isMainThread());
=======
    ASSERT(isMainThread());
>>>>>>> miniblink49
    if (!s_databaseManager)
        s_databaseManager = new DatabaseManager();
    return *s_databaseManager;
}

void DatabaseManager::terminateDatabaseThread()
{
<<<<<<< HEAD
    DCHECK(isMainThread());
    if (!s_databaseManager)
        return;
    for (const Member<DatabaseContext>& context :
        s_databaseManager->m_contextMap.values())
=======
    ASSERT(isMainThread());
    if (!s_databaseManager)
        return;
    for (const Member<DatabaseContext>& context : s_databaseManager->m_contextMap.values())
>>>>>>> miniblink49
        context->stopDatabases();
}

DatabaseManager::DatabaseManager()
<<<<<<< HEAD
{
}

DatabaseManager::~DatabaseManager() { }

// This is just for ignoring DatabaseCallback::handleEvent()'s return value.
static void databaseCallbackHandleEvent(DatabaseCallback* callback,
    Database* database)
{
    callback->handleEvent(database);
}

DatabaseContext* DatabaseManager::existingDatabaseContextFor(
    ExecutionContext* context)
=======
#if ENABLE(ASSERT)
    : m_databaseContextRegisteredCount(0)
    , m_databaseContextInstanceCount(0)
#endif
{
}

DatabaseManager::~DatabaseManager()
{
}

class DatabaseCreationCallbackTask final : public ExecutionContextTask {
public:
    static PassOwnPtr<DatabaseCreationCallbackTask> create(Database* database, DatabaseCallback* creationCallback)
    {
        return adoptPtr(new DatabaseCreationCallbackTask(database, creationCallback));
    }

    void performTask(ExecutionContext*) override
    {
        m_creationCallback->handleEvent(m_database.get());
    }

    String taskNameForInstrumentation() const override
    {
        return "openDatabase";
    }

private:
    DatabaseCreationCallbackTask(Database* database, DatabaseCallback* callback)
        : m_database(database)
        , m_creationCallback(callback)
    {
    }

    Persistent<Database> m_database;
    Persistent<DatabaseCallback> m_creationCallback;
};

DatabaseContext* DatabaseManager::existingDatabaseContextFor(ExecutionContext* context)
>>>>>>> miniblink49
{
    ASSERT(m_databaseContextRegisteredCount >= 0);
    ASSERT(m_databaseContextInstanceCount >= 0);
    ASSERT(m_databaseContextRegisteredCount <= m_databaseContextInstanceCount);
    return m_contextMap.get(context);
}

<<<<<<< HEAD
DatabaseContext* DatabaseManager::databaseContextFor(
    ExecutionContext* context)
=======
DatabaseContext* DatabaseManager::databaseContextFor(ExecutionContext* context)
>>>>>>> miniblink49
{
    if (DatabaseContext* databaseContext = existingDatabaseContextFor(context))
        return databaseContext;
    return DatabaseContext::create(context);
}

<<<<<<< HEAD
void DatabaseManager::registerDatabaseContext(
    DatabaseContext* databaseContext)
{
    ExecutionContext* context = databaseContext->getExecutionContext();
    m_contextMap.set(context, databaseContext);
#if DCHECK_IS_ON()
=======
void DatabaseManager::registerDatabaseContext(DatabaseContext* databaseContext)
{
    ExecutionContext* context = databaseContext->executionContext();
    m_contextMap.set(context, databaseContext);
#if ENABLE(ASSERT)
>>>>>>> miniblink49
    m_databaseContextRegisteredCount++;
#endif
}

<<<<<<< HEAD
void DatabaseManager::unregisterDatabaseContext(
    DatabaseContext* databaseContext)
{
    ExecutionContext* context = databaseContext->getExecutionContext();
    ASSERT(m_contextMap.get(context));
#if DCHECK_IS_ON()
=======
void DatabaseManager::unregisterDatabaseContext(DatabaseContext* databaseContext)
{
    ExecutionContext* context = databaseContext->executionContext();
    ASSERT(m_contextMap.get(context));
#if ENABLE(ASSERT)
>>>>>>> miniblink49
    m_databaseContextRegisteredCount--;
#endif
    m_contextMap.remove(context);
}

<<<<<<< HEAD
#if DCHECK_IS_ON()
=======
#if ENABLE(ASSERT)
>>>>>>> miniblink49
void DatabaseManager::didConstructDatabaseContext()
{
    m_databaseContextInstanceCount++;
}

void DatabaseManager::didDestructDatabaseContext()
{
    m_databaseContextInstanceCount--;
    ASSERT(m_databaseContextRegisteredCount <= m_databaseContextInstanceCount);
}
#endif

<<<<<<< HEAD
void DatabaseManager::throwExceptionForDatabaseError(
    DatabaseError error,
    const String& errorMessage,
    ExceptionState& exceptionState)
=======
void DatabaseManager::throwExceptionForDatabaseError(DatabaseError error, const String& errorMessage, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    switch (error) {
    case DatabaseError::None:
        return;
    case DatabaseError::GenericSecurityError:
        exceptionState.throwSecurityError(errorMessage);
        return;
    case DatabaseError::InvalidDatabaseState:
        exceptionState.throwDOMException(InvalidStateError, errorMessage);
        return;
    default:
        ASSERT_NOT_REACHED();
    }
}

<<<<<<< HEAD
static void logOpenDatabaseError(ExecutionContext* context,
    const String& name)
{
    STORAGE_DVLOG(1) << "Database " << name << " for origin "
                     << context->getSecurityOrigin()->toString()
                     << " not allowed to be established";
}

Database* DatabaseManager::openDatabaseInternal(ExecutionContext* context,
    const String& name,
    const String& expectedVersion,
    const String& displayName,
    unsigned estimatedSize,
    bool setVersionInNewDatabase,
    DatabaseError& error,
    String& errorMessage)
=======
static void logOpenDatabaseError(ExecutionContext* context, const String& name)
{
    WTF_LOG(StorageAPI, "Database %s for origin %s not allowed to be established", name.ascii().data(),
        context->securityOrigin()->toString().ascii().data());
}

Database* DatabaseManager::openDatabaseInternal(ExecutionContext* context,
    const String& name, const String& expectedVersion, const String& displayName,
    unsigned long estimatedSize, bool setVersionInNewDatabase, DatabaseError& error, String& errorMessage)
>>>>>>> miniblink49
{
    ASSERT(error == DatabaseError::None);

    DatabaseContext* backendContext = databaseContextFor(context)->backend();
<<<<<<< HEAD
    if (DatabaseTracker::tracker().canEstablishDatabase(
            backendContext, name, displayName, estimatedSize, error)) {
        Database* backend = new Database(backendContext, name, expectedVersion,
            displayName, estimatedSize);
        if (backend->openAndVerifyVersion(setVersionInNewDatabase, error,
                errorMessage))
=======
    if (DatabaseTracker::tracker().canEstablishDatabase(backendContext, name, displayName, estimatedSize, error)) {
        Database* backend = new Database(backendContext, name, expectedVersion, displayName, estimatedSize);
        if (backend->openAndVerifyVersion(setVersionInNewDatabase, error, errorMessage))
>>>>>>> miniblink49
            return backend;
    }

    ASSERT(error != DatabaseError::None);
    switch (error) {
    case DatabaseError::GenericSecurityError:
        logOpenDatabaseError(context, name);
        return nullptr;

    case DatabaseError::InvalidDatabaseState:
        logErrorMessage(context, errorMessage);
        return nullptr;

    default:
        ASSERT_NOT_REACHED();
    }
    return nullptr;
}

Database* DatabaseManager::openDatabase(ExecutionContext* context,
<<<<<<< HEAD
    const String& name,
    const String& expectedVersion,
    const String& displayName,
    unsigned estimatedSize,
    DatabaseCallback* creationCallback,
    DatabaseError& error,
    String& errorMessage)
=======
    const String& name, const String& expectedVersion, const String& displayName,
    unsigned long estimatedSize, DatabaseCallback* creationCallback,
    DatabaseError& error, String& errorMessage)
>>>>>>> miniblink49
{
    ASSERT(error == DatabaseError::None);

    bool setVersionInNewDatabase = !creationCallback;
<<<<<<< HEAD
    Database* database = openDatabaseInternal(
        context, name, expectedVersion, displayName, estimatedSize,
        setVersionInNewDatabase, error, errorMessage);
=======
    Database* database = openDatabaseInternal(context, name,
        expectedVersion, displayName, estimatedSize, setVersionInNewDatabase, error, errorMessage);
>>>>>>> miniblink49
    if (!database)
        return nullptr;

    databaseContextFor(context)->setHasOpenDatabases();
<<<<<<< HEAD
    DatabaseClient::from(context)->didOpenDatabase(
        database, context->getSecurityOrigin()->host(), name, expectedVersion);

    if (database->isNew() && creationCallback) {
        STORAGE_DVLOG(1) << "Scheduling DatabaseCreationCallbackTask for database "
                         << database;
        database->getExecutionContext()->postTask(
            TaskType::DatabaseAccess, BLINK_FROM_HERE,
            createSameThreadTask(&databaseCallbackHandleEvent,
                wrapPersistent(creationCallback),
                wrapPersistent(database)),
            "openDatabase");
=======
    DatabaseClient::from(context)->didOpenDatabase(database, context->securityOrigin()->host(), name, expectedVersion);

    if (database->isNew() && creationCallback) {
        WTF_LOG(StorageAPI, "Scheduling DatabaseCreationCallbackTask for database %p\n", database);
        database->executionContext()->postTask(FROM_HERE, DatabaseCreationCallbackTask::create(database, creationCallback));
>>>>>>> miniblink49
    }

    ASSERT(database);
    return database;
}

<<<<<<< HEAD
String DatabaseManager::fullPathForDatabase(SecurityOrigin* origin,
    const String& name,
    bool createIfDoesNotExist)
{
    return DatabaseTracker::tracker().fullPathForDatabase(origin, name,
        createIfDoesNotExist);
}

void DatabaseManager::logErrorMessage(ExecutionContext* context,
    const String& message)
{
    context->addConsoleMessage(
        ConsoleMessage::create(StorageMessageSource, ErrorMessageLevel, message));
=======
String DatabaseManager::fullPathForDatabase(SecurityOrigin* origin, const String& name, bool createIfDoesNotExist)
{
    return DatabaseTracker::tracker().fullPathForDatabase(origin, name, createIfDoesNotExist);
}

void DatabaseManager::logErrorMessage(ExecutionContext* context, const String& message)
{
    context->addConsoleMessage(ConsoleMessage::create(StorageMessageSource, ErrorMessageLevel, message));
>>>>>>> miniblink49
}

} // namespace blink
