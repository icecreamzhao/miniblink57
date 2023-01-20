/*
 * Copyright (C) 2007 Apple Inc. All rights reserved.
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

#ifndef SQLError_h
#define SQLError_h

#include "bindings/core/v8/ScriptWrappable.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
#include "wtf/text/WTFString.h"
#include <memory>
=======
#include "wtf/text/WTFString.h"
>>>>>>> miniblink49

namespace blink {

class SQLErrorData {
<<<<<<< HEAD
    USING_FAST_MALLOC(SQLErrorData);

public:
    static std::unique_ptr<SQLErrorData> create(unsigned code,
        const String& message)
    {
        return WTF::wrapUnique(new SQLErrorData(code, message));
    }

    static std::unique_ptr<SQLErrorData> create(unsigned code,
        const char* message,
        int sqliteCode,
        const char* sqliteMessage)
    {
        return create(
            code, String::format("%s (%d %s)", message, sqliteCode, sqliteMessage));
    }

    static std::unique_ptr<SQLErrorData> create(const SQLErrorData& data)
=======
public:
    static PassOwnPtr<SQLErrorData> create(unsigned code, const String& message)
    {
        return adoptPtr(new SQLErrorData(code, message));
    }

    static PassOwnPtr<SQLErrorData> create(unsigned code, const char* message, int sqliteCode, const char* sqliteMessage)
    {
        return create(code, String::format("%s (%d %s)", message, sqliteCode, sqliteMessage));
    }

    static PassOwnPtr<SQLErrorData> create(const SQLErrorData& data)
>>>>>>> miniblink49
    {
        return create(data.code(), data.message());
    }

<<<<<<< HEAD
    SQLErrorData(const SQLErrorData& data)
        : m_code(data.m_code)
        , m_message(data.m_message.isolatedCopy())
    {
    }
=======
    SQLErrorData(const SQLErrorData& data) : m_code(data.m_code), m_message(data.m_message.isolatedCopy()) { }
>>>>>>> miniblink49

    unsigned code() const { return m_code; }
    String message() const { return m_message.isolatedCopy(); }

private:
<<<<<<< HEAD
    SQLErrorData(unsigned code, const String& message)
        : m_code(code)
        , m_message(message.isolatedCopy())
    {
    }
=======
    SQLErrorData(unsigned code, const String& message) : m_code(code), m_message(message.isolatedCopy()) { }
>>>>>>> miniblink49

    unsigned m_code;
    String m_message;
};

<<<<<<< HEAD
class SQLError final : public GarbageCollectedFinalized<SQLError>,
                       public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();

public:
    static SQLError* create(const SQLErrorData& data)
    {
        return new SQLError(data);
    }
=======
class SQLError : public GarbageCollectedFinalized<SQLError>, public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();
public:
    static SQLError* create(const SQLErrorData& data) { return new SQLError(data); }
>>>>>>> miniblink49
    DEFINE_INLINE_TRACE() { }

    unsigned code() const { return m_data.code(); }
    String message() const { return m_data.message(); }

    enum SQLErrorCode {
<<<<<<< HEAD
        kUnknownErr = 0,
        kDatabaseErr = 1,
        kVersionErr = 2,
        kTooLargeErr = 3,
        kQuotaErr = 4,
        kSyntaxErr = 5,
        kConstraintErr = 6,
        kTimeoutErr = 7
=======
        UNKNOWN_ERR = 0,
        DATABASE_ERR = 1,
        VERSION_ERR = 2,
        TOO_LARGE_ERR = 3,
        QUOTA_ERR = 4,
        SYNTAX_ERR = 5,
        CONSTRAINT_ERR = 6,
        TIMEOUT_ERR = 7
>>>>>>> miniblink49
    };

    static const char quotaExceededErrorMessage[];
    static const char unknownErrorMessage[];
    static const char versionErrorMessage[];

private:
    explicit SQLError(const SQLErrorData& data)
<<<<<<< HEAD
        : m_data(data)
    {
    }
=======
        : m_data(data) { }
>>>>>>> miniblink49

    const SQLErrorData m_data;
};

} // namespace blink

#endif // SQLError_h
