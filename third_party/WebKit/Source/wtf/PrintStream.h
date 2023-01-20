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

#ifndef PrintStream_h
#define PrintStream_h

<<<<<<< HEAD
#include "wtf/Allocator.h"
#include "wtf/Compiler.h"
#include "wtf/Noncopyable.h"
#include "wtf/StdLibExtras.h"
#include "wtf/WTFExport.h"
#include <stdarg.h>
=======
#include <stdarg.h>
#include "wtf/FastAllocBase.h"
#include "wtf/Noncopyable.h"
#include "wtf/StdLibExtras.h"
#include "wtf/WTFExport.h"
>>>>>>> miniblink49

namespace WTF {

class CString;
class String;

class WTF_EXPORT PrintStream {
<<<<<<< HEAD
    USING_FAST_MALLOC(PrintStream);
    WTF_MAKE_NONCOPYABLE(PrintStream);

=======
    WTF_MAKE_FAST_ALLOCATED(PrintStream); WTF_MAKE_NONCOPYABLE(PrintStream);
>>>>>>> miniblink49
public:
    PrintStream();
    virtual ~PrintStream();

<<<<<<< HEAD
    PRINTF_FORMAT(2, 3)
    void printf(const char* format, ...);
    PRINTF_FORMAT(2, 0)
    virtual void vprintf(const char* format, va_list) = 0;
=======
    void printf(const char* format, ...) WTF_ATTRIBUTE_PRINTF(2, 3);
    virtual void vprintf(const char* format, va_list) WTF_ATTRIBUTE_PRINTF(2, 0) = 0;
>>>>>>> miniblink49

    // Typically a no-op for many subclasses of PrintStream, this is a hint that
    // the implementation should flush its buffers if it had not done so already.
    virtual void flush();

<<<<<<< HEAD
    template <typename T>
=======
    template<typename T>
>>>>>>> miniblink49
    void print(const T& value)
    {
        printInternal(*this, value);
    }

<<<<<<< HEAD
    template <typename T1, typename... RemainingTypes>
=======
    template<typename T1, typename... RemainingTypes>
>>>>>>> miniblink49
    void print(const T1& value1, const RemainingTypes&... values)
    {
        print(value1);
        print(values...);
    }
};

WTF_EXPORT void printInternal(PrintStream&, const char*);
WTF_EXPORT void printInternal(PrintStream&, const CString&);
WTF_EXPORT void printInternal(PrintStream&, const String&);
<<<<<<< HEAD
inline void printInternal(PrintStream& out, char* value)
{
    printInternal(out, static_cast<const char*>(value));
}
inline void printInternal(PrintStream& out, CString& value)
{
    printInternal(out, static_cast<const CString&>(value));
}
inline void printInternal(PrintStream& out, String& value)
{
    printInternal(out, static_cast<const String&>(value));
}
=======
inline void printInternal(PrintStream& out, char* value) { printInternal(out, static_cast<const char*>(value)); }
inline void printInternal(PrintStream& out, CString& value) { printInternal(out, static_cast<const CString&>(value)); }
inline void printInternal(PrintStream& out, String& value) { printInternal(out, static_cast<const String&>(value)); }
>>>>>>> miniblink49
WTF_EXPORT void printInternal(PrintStream&, bool);
WTF_EXPORT void printInternal(PrintStream&, int);
WTF_EXPORT void printInternal(PrintStream&, unsigned);
WTF_EXPORT void printInternal(PrintStream&, long);
WTF_EXPORT void printInternal(PrintStream&, unsigned long);
WTF_EXPORT void printInternal(PrintStream&, long long);
WTF_EXPORT void printInternal(PrintStream&, unsigned long long);
WTF_EXPORT void printInternal(PrintStream&, float);
WTF_EXPORT void printInternal(PrintStream&, double);

<<<<<<< HEAD
template <typename T>
=======
template<typename T>
>>>>>>> miniblink49
void printInternal(PrintStream& out, const T& value)
{
    value.dump(out);
}

<<<<<<< HEAD
#define MAKE_PRINT_ADAPTOR(Name, Type, function)                      \
    class Name final {                                                \
        STACK_ALLOCATED();                                            \
                                                                      \
    public:                                                           \
        Name(const Type& value)                                       \
            : m_value(value)                                          \
        {                                                             \
        }                                                             \
        void dump(PrintStream& out) const { function(out, m_value); } \
                                                                      \
    private:                                                          \
        Type m_value;                                                 \
    }

#define MAKE_PRINT_METHOD_ADAPTOR(Name, Type, method)              \
    class Name final {                                             \
        STACK_ALLOCATED();                                         \
                                                                   \
    public:                                                        \
        Name(const Type& value)                                    \
            : m_value(value)                                       \
        {                                                          \
        }                                                          \
        void dump(PrintStream& out) const { m_value.method(out); } \
                                                                   \
    private:                                                       \
        const Type& m_value;                                       \
    }

#define MAKE_PRINT_METHOD(Type, dumpMethod, method)                  \
    MAKE_PRINT_METHOD_ADAPTOR(DumperFor_##method, Type, dumpMethod); \
=======
#define MAKE_PRINT_ADAPTOR(Name, Type, function) \
    class Name {                                 \
    public:                                      \
        Name(const Type& value)                  \
            : m_value(value)                     \
        {                                        \
        }                                        \
        void dump(PrintStream& out) const        \
        {                                        \
            function(out, m_value);              \
        }                                        \
    private:                                     \
        Type m_value;                            \
    }

#define MAKE_PRINT_METHOD_ADAPTOR(Name, Type, method) \
    class Name {                                 \
    public:                                      \
        Name(const Type& value)                  \
            : m_value(value)                     \
        {                                        \
        }                                        \
        void dump(PrintStream& out) const        \
        {                                        \
            m_value.method(out);                 \
        }                                        \
    private:                                     \
        const Type& m_value;                     \
    }

#define MAKE_PRINT_METHOD(Type, dumpMethod, method) \
    MAKE_PRINT_METHOD_ADAPTOR(DumperFor_##method, Type, dumpMethod);    \
>>>>>>> miniblink49
    DumperFor_##method method() const { return DumperFor_##method(*this); }

// Use an adaptor-based dumper for characters to avoid situations where
// you've "compressed" an integer to a character and it ends up printing
// as ASCII when you wanted it to print as a number.
void dumpCharacter(PrintStream&, char);
MAKE_PRINT_ADAPTOR(CharacterDump, char, dumpCharacter);

<<<<<<< HEAD
} // namespace WTF

using WTF::CharacterDump;
using WTF::PrintStream;

#endif // PrintStream_h
=======
template<typename T>
class PointerDump {
public:
    PointerDump(const T* ptr)
        : m_ptr(ptr)
    {
    }

    void dump(PrintStream& out) const
    {
        if (m_ptr)
            printInternal(out, *m_ptr);
        else
            out.print("(null)");
    }
private:
    const T* m_ptr;
};

template<typename T>
PointerDump<T> pointerDump(const T* ptr) { return PointerDump<T>(ptr); }

} // namespace WTF

using WTF::CharacterDump;
using WTF::PointerDump;
using WTF::PrintStream;
using WTF::pointerDump;

#endif // PrintStream_h

>>>>>>> miniblink49
