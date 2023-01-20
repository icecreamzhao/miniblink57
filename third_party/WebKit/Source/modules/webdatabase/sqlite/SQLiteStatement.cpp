/*
 * Copyright (C) 2006, 2007, 2008 Apple Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "modules/webdatabase/sqlite/SQLiteStatement.h"

#include "modules/webdatabase/sqlite/SQLLog.h"
#include "modules/webdatabase/sqlite/SQLValue.h"
#include "platform/heap/SafePoint.h"
#include "third_party/sqlite/sqlite3.h"
#include "wtf/Assertions.h"
#include "wtf/PtrUtil.h"
#include "wtf/text/CString.h"
#include <memory>

// SQLite 3.6.16 makes sqlite3_prepare_v2 automatically retry preparing the
// statement once if the database scheme has changed. We rely on this behavior.
=======
#include "config.h"
#include "modules/webdatabase/sqlite/SQLiteStatement.h"

#include "modules/webdatabase/sqlite/SQLValue.h"
#include "platform/Logging.h"
#include "platform/heap/SafePoint.h"
#include "wtf/Assertions.h"
#include "wtf/text/CString.h"
#include <sqlite3.h>

// SQLite 3.6.16 makes sqlite3_prepare_v2 automatically retry preparing the statement
// once if the database scheme has changed. We rely on this behavior.
>>>>>>> miniblink49
#if SQLITE_VERSION_NUMBER < 3006016
#error SQLite version 3.6.16 or newer is required
#endif

namespace {

// Only return error codes consistent with 3.7.6.3.
int restrictError(int error)
{
    switch (error) {
    case SQLITE_IOERR_READ:
    case SQLITE_IOERR_SHORT_READ:
    case SQLITE_IOERR_WRITE:
    case SQLITE_IOERR_FSYNC:
    case SQLITE_IOERR_DIR_FSYNC:
    case SQLITE_IOERR_TRUNCATE:
    case SQLITE_IOERR_FSTAT:
    case SQLITE_IOERR_UNLOCK:
    case SQLITE_IOERR_RDLOCK:
    case SQLITE_IOERR_DELETE:
    case SQLITE_IOERR_BLOCKED:
    case SQLITE_IOERR_NOMEM:
    case SQLITE_IOERR_ACCESS:
    case SQLITE_IOERR_CHECKRESERVEDLOCK:
    case SQLITE_IOERR_LOCK:
    case SQLITE_IOERR_CLOSE:
    case SQLITE_IOERR_DIR_CLOSE:
    case SQLITE_IOERR_SHMOPEN:
    case SQLITE_IOERR_SHMSIZE:
    case SQLITE_IOERR_SHMLOCK:
    case SQLITE_LOCKED_SHAREDCACHE:
    case SQLITE_BUSY_RECOVERY:
    case SQLITE_CANTOPEN_NOTEMPDIR:
        return error;
    default:
        return (error & 0xff);
    }
}

<<<<<<< HEAD
} // namespace
=======
}
>>>>>>> miniblink49

namespace blink {

SQLiteStatement::SQLiteStatement(SQLiteDatabase& db, const String& sql)
    : m_database(db)
    , m_query(sql)
    , m_statement(0)
<<<<<<< HEAD
=======
#if ENABLE(ASSERT)
    , m_isPrepared(false)
#endif
>>>>>>> miniblink49
{
}

SQLiteStatement::~SQLiteStatement()
{
    finalize();
}

int SQLiteStatement::prepare()
{
    ASSERT(!m_isPrepared);

    CString query = m_query.stripWhiteSpace().utf8();

    // Need to pass non-stack |const char*| and |sqlite3_stmt*| to avoid race
    // with Oilpan stack scanning.
<<<<<<< HEAD
    std::unique_ptr<const char*> tail = WTF::wrapUnique(new const char*);
    std::unique_ptr<sqlite3_stmt*> statement = WTF::wrapUnique(new sqlite3_stmt*);
=======
    OwnPtr<const char*> tail = adoptPtr(new const char*);
    OwnPtr<sqlite3_stmt*> statement = adoptPtr(new sqlite3_stmt*);
>>>>>>> miniblink49
    *tail = nullptr;
    *statement = nullptr;
    int error;
    {
<<<<<<< HEAD
        SafePointScope scope(BlinkGC::HeapPointersOnStack);

        SQL_DVLOG(1) << "SQL - prepare - " << query.data();

        // Pass the length of the string including the null character to
        // sqlite3_prepare_v2; this lets SQLite avoid an extra string copy.
        size_t lengthIncludingNullCharacter = query.length() + 1;

        error = sqlite3_prepare_v2(m_database.sqlite3Handle(), query.data(),
            lengthIncludingNullCharacter, statement.get(),
            tail.get());
=======
        SafePointScope scope(ThreadState::HeapPointersOnStack);

        WTF_LOG(SQLDatabase, "SQL - prepare - %s", query.data());

        // Pass the length of the string including the null character to sqlite3_prepare_v2;
        // this lets SQLite avoid an extra string copy.
        size_t lengthIncludingNullCharacter = query.length() + 1;

        error = sqlite3_prepare_v2(m_database.sqlite3Handle(), query.data(), lengthIncludingNullCharacter, statement.get(), tail.get());
>>>>>>> miniblink49
    }
    m_statement = *statement;

    if (error != SQLITE_OK)
<<<<<<< HEAD
        SQL_DVLOG(1) << "sqlite3_prepare16 failed (" << error << ")\n"
                     << query.data() << "\n"
                     << sqlite3_errmsg(m_database.sqlite3Handle());
    else if (*tail && **tail)
        error = SQLITE_ERROR;

#if DCHECK_IS_ON()
=======
        WTF_LOG(SQLDatabase, "sqlite3_prepare16 failed (%i)\n%s\n%s", error, query.data(), sqlite3_errmsg(m_database.sqlite3Handle()));
    else if (*tail && **tail)
        error = SQLITE_ERROR;

#if ENABLE(ASSERT)
>>>>>>> miniblink49
    m_isPrepared = error == SQLITE_OK;
#endif
    return restrictError(error);
}

int SQLiteStatement::step()
{
<<<<<<< HEAD
    SafePointScope scope(BlinkGC::HeapPointersOnStack);
    // ASSERT(m_isPrepared);
=======
    SafePointScope scope(ThreadState::HeapPointersOnStack);
    //ASSERT(m_isPrepared);
>>>>>>> miniblink49

    if (!m_statement)
        return SQLITE_OK;

    // The database needs to update its last changes count before each statement
    // in order to compute properly the lastChanges() return value.
    m_database.updateLastChangesCount();

<<<<<<< HEAD
    SQL_DVLOG(1) << "SQL - step - " << m_query;
    int error = sqlite3_step(m_statement);
    if (error != SQLITE_DONE && error != SQLITE_ROW) {
        SQL_DVLOG(1) << "sqlite3_step failed (" << error << " )\nQuery - "
                     << m_query << "\nError - "
                     << sqlite3_errmsg(m_database.sqlite3Handle());
=======
    WTF_LOG(SQLDatabase, "SQL - step - %s", m_query.ascii().data());
    int error = sqlite3_step(m_statement);
    if (error != SQLITE_DONE && error != SQLITE_ROW) {
        WTF_LOG(SQLDatabase, "sqlite3_step failed (%i)\nQuery - %s\nError - %s",
            error, m_query.ascii().data(), sqlite3_errmsg(m_database.sqlite3Handle()));
>>>>>>> miniblink49
    }

    return restrictError(error);
}

int SQLiteStatement::finalize()
{
<<<<<<< HEAD
#if DCHECK_IS_ON()
=======
#if ENABLE(ASSERT)
>>>>>>> miniblink49
    m_isPrepared = false;
#endif
    if (!m_statement)
        return SQLITE_OK;
<<<<<<< HEAD
    SQL_DVLOG(1) << "SQL - finalize - " << m_query;
=======
    WTF_LOG(SQLDatabase, "SQL - finalize - %s", m_query.ascii().data());
>>>>>>> miniblink49
    int result = sqlite3_finalize(m_statement);
    m_statement = 0;
    return restrictError(result);
}

bool SQLiteStatement::executeCommand()
{
    if (!m_statement && prepare() != SQLITE_OK)
        return false;
    ASSERT(m_isPrepared);
    if (step() != SQLITE_DONE) {
        finalize();
        return false;
    }
    finalize();
    return true;
}

int SQLiteStatement::bindText(int index, const String& text)
{
    ASSERT(m_isPrepared);
    ASSERT(index > 0);
    ASSERT(static_cast<unsigned>(index) <= bindParameterCount());

<<<<<<< HEAD
    String text16(text);
    text16.ensure16Bit();
    return restrictError(
        sqlite3_bind_text16(m_statement, index, text16.characters16(),
            sizeof(UChar) * text16.length(), SQLITE_TRANSIENT));
=======
    // SQLite treats uses zero pointers to represent null strings, which means we need to make sure to map null WTFStrings to zero pointers.
    ASSERT(!String().charactersWithNullTermination().data());
    return restrictError(sqlite3_bind_text16(m_statement, index, text.charactersWithNullTermination().data(), sizeof(UChar) * text.length(), SQLITE_TRANSIENT));
>>>>>>> miniblink49
}

int SQLiteStatement::bindDouble(int index, double number)
{
    ASSERT(m_isPrepared);
    ASSERT(index > 0);
    ASSERT(static_cast<unsigned>(index) <= bindParameterCount());

    return restrictError(sqlite3_bind_double(m_statement, index, number));
}

int SQLiteStatement::bindNull(int index)
{
    ASSERT(m_isPrepared);
    ASSERT(index > 0);
    ASSERT(static_cast<unsigned>(index) <= bindParameterCount());

    return restrictError(sqlite3_bind_null(m_statement, index));
}

int SQLiteStatement::bindValue(int index, const SQLValue& value)
{
<<<<<<< HEAD
    switch (value.getType()) {
    case SQLValue::StringValue:
        return bindText(index, value.string());
    case SQLValue::NumberValue:
        return bindDouble(index, value.number());
    case SQLValue::NullValue:
        return bindNull(index);
=======
    switch (value.type()) {
        case SQLValue::StringValue:
            return bindText(index, value.string());
        case SQLValue::NumberValue:
            return bindDouble(index, value.number());
        case SQLValue::NullValue:
            return bindNull(index);
>>>>>>> miniblink49
    }

    ASSERT_NOT_REACHED();
    return SQLITE_ERROR;
}

unsigned SQLiteStatement::bindParameterCount() const
{
    ASSERT(m_isPrepared);
    if (!m_statement)
        return 0;
    return sqlite3_bind_parameter_count(m_statement);
}

int SQLiteStatement::columnCount()
{
    ASSERT(m_isPrepared);
    if (!m_statement)
        return 0;
    return sqlite3_data_count(m_statement);
}

String SQLiteStatement::getColumnName(int col)
{
    ASSERT(col >= 0);
    if (!m_statement)
        if (prepareAndStep() != SQLITE_ROW)
            return String();
    if (columnCount() <= col)
        return String();
<<<<<<< HEAD
    return String(
        reinterpret_cast<const UChar*>(sqlite3_column_name16(m_statement, col)));
=======
    return String(reinterpret_cast<const UChar*>(sqlite3_column_name16(m_statement, col)));
>>>>>>> miniblink49
}

SQLValue SQLiteStatement::getColumnValue(int col)
{
    ASSERT(col >= 0);
    if (!m_statement)
        if (prepareAndStep() != SQLITE_ROW)
            return SQLValue();
    if (columnCount() <= col)
        return SQLValue();

    // SQLite is typed per value. optional column types are
    // "(mostly) ignored"
    sqlite3_value* value = sqlite3_column_value(m_statement, col);
    switch (sqlite3_value_type(value)) {
<<<<<<< HEAD
    case SQLITE_INTEGER: // SQLValue and JS don't represent integers, so use
        // FLOAT -case
    case SQLITE_FLOAT:
        return SQLValue(sqlite3_value_double(value));
    case SQLITE_BLOB: // SQLValue and JS don't represent blobs, so use TEXT
        // -case
    case SQLITE_TEXT: {
        const UChar* string = reinterpret_cast<const UChar*>(sqlite3_value_text16(value));
        unsigned length = sqlite3_value_bytes16(value) / sizeof(UChar);
        return SQLValue(StringImpl::create8BitIfPossible(string, length));
    }
    case SQLITE_NULL:
        return SQLValue();
    default:
        break;
=======
        case SQLITE_INTEGER:    // SQLValue and JS don't represent integers, so use FLOAT -case
        case SQLITE_FLOAT:
            return SQLValue(sqlite3_value_double(value));
        case SQLITE_BLOB:       // SQLValue and JS don't represent blobs, so use TEXT -case
        case SQLITE_TEXT: {
            const UChar* string = reinterpret_cast<const UChar*>(sqlite3_value_text16(value));
            unsigned length = WTF::lengthOfNullTerminatedString(string);
            return SQLValue(StringImpl::create8BitIfPossible(string, length));
        }
        case SQLITE_NULL:
            return SQLValue();
        default:
            break;
>>>>>>> miniblink49
    }
    ASSERT_NOT_REACHED();
    return SQLValue();
}

String SQLiteStatement::getColumnText(int col)
{
    ASSERT(col >= 0);
    if (!m_statement)
        if (prepareAndStep() != SQLITE_ROW)
            return String();
    if (columnCount() <= col)
        return String();
    const UChar* string = reinterpret_cast<const UChar*>(sqlite3_column_text16(m_statement, col));
<<<<<<< HEAD
    return StringImpl::create8BitIfPossible(
        string, sqlite3_column_bytes16(m_statement, col) / sizeof(UChar));
=======
    return StringImpl::create8BitIfPossible(string, sqlite3_column_bytes16(m_statement, col) / sizeof(UChar));
>>>>>>> miniblink49
}

int SQLiteStatement::getColumnInt(int col)
{
    ASSERT(col >= 0);
    if (!m_statement)
        if (prepareAndStep() != SQLITE_ROW)
            return 0;
    if (columnCount() <= col)
        return 0;
    return sqlite3_column_int(m_statement, col);
}

int64_t SQLiteStatement::getColumnInt64(int col)
{
    ASSERT(col >= 0);
    if (!m_statement)
        if (prepareAndStep() != SQLITE_ROW)
            return 0;
    if (columnCount() <= col)
        return 0;
    return sqlite3_column_int64(m_statement, col);
}

} // namespace blink
