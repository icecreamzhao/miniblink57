/*
 * Copyright 2014 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "wtf/text/StringConcatenate.h"

#include "wtf/text/StringImpl.h"

// This macro is helpful for testing how many intermediate Strings are created
// while evaluating an expression containing operator+.
=======
#include "config.h"
#include "StringConcatenate.h"

// This macro is helpful for testing how many intermediate Strings are created while evaluating an
// expression containing operator+.
>>>>>>> miniblink49
#ifndef WTF_STRINGTYPEADAPTER_COPIED_WTF_STRING
#define WTF_STRINGTYPEADAPTER_COPIED_WTF_STRING() ((void)0)
#endif

<<<<<<< HEAD
void WTF::StringTypeAdapter<char*>::writeTo(LChar* destination) const
=======
void WTF::StringTypeAdapter<char*>::writeTo(LChar* destination)
>>>>>>> miniblink49
{
    for (unsigned i = 0; i < m_length; ++i)
        destination[i] = static_cast<LChar>(m_buffer[i]);
}

<<<<<<< HEAD
void WTF::StringTypeAdapter<char*>::writeTo(UChar* destination) const
=======
void WTF::StringTypeAdapter<char*>::writeTo(UChar* destination)
>>>>>>> miniblink49
{
    for (unsigned i = 0; i < m_length; ++i) {
        unsigned char c = m_buffer[i];
        destination[i] = c;
    }
}

WTF::StringTypeAdapter<LChar*>::StringTypeAdapter(LChar* buffer)
    : m_buffer(buffer)
    , m_length(strlen(reinterpret_cast<char*>(buffer)))
{
}

<<<<<<< HEAD
void WTF::StringTypeAdapter<LChar*>::writeTo(LChar* destination) const
=======
void WTF::StringTypeAdapter<LChar*>::writeTo(LChar* destination)
>>>>>>> miniblink49
{
    memcpy(destination, m_buffer, m_length * sizeof(LChar));
}

<<<<<<< HEAD
void WTF::StringTypeAdapter<LChar*>::writeTo(UChar* destination) const
=======
void WTF::StringTypeAdapter<LChar*>::writeTo(UChar* destination)
>>>>>>> miniblink49
{
    StringImpl::copyChars(destination, m_buffer, m_length);
}

WTF::StringTypeAdapter<const UChar*>::StringTypeAdapter(const UChar* buffer)
    : m_buffer(buffer)
<<<<<<< HEAD
    , m_length(lengthOfNullTerminatedString(buffer))
{
}

void WTF::StringTypeAdapter<const UChar*>::writeTo(UChar* destination) const
=======
{
    size_t len = 0;
    while (m_buffer[len] != UChar(0))
        ++len;

    RELEASE_ASSERT(len <= std::numeric_limits<unsigned>::max());

    m_length = len;
}

void WTF::StringTypeAdapter<const UChar*>::writeTo(UChar* destination)
>>>>>>> miniblink49
{
    memcpy(destination, m_buffer, m_length * sizeof(UChar));
}

WTF::StringTypeAdapter<const char*>::StringTypeAdapter(const char* buffer)
<<<<<<< HEAD
    : m_buffer(buffer)
    , m_length(strlen(buffer))
{
}

void WTF::StringTypeAdapter<const char*>::writeTo(LChar* destination) const
=======
: m_buffer(buffer)
, m_length(strlen(buffer))
{
}

void WTF::StringTypeAdapter<const char*>::writeTo(LChar* destination)
>>>>>>> miniblink49
{
    memcpy(destination, m_buffer, static_cast<size_t>(m_length) * sizeof(LChar));
}

<<<<<<< HEAD
void WTF::StringTypeAdapter<const char*>::writeTo(UChar* destination) const
=======
void WTF::StringTypeAdapter<const char*>::writeTo(UChar* destination)
>>>>>>> miniblink49
{
    for (unsigned i = 0; i < m_length; ++i) {
        unsigned char c = m_buffer[i];
        destination[i] = c;
    }
}

WTF::StringTypeAdapter<const LChar*>::StringTypeAdapter(const LChar* buffer)
<<<<<<< HEAD
    : m_buffer(buffer)
    , m_length(strlen(reinterpret_cast<const char*>(buffer)))
{
}

void WTF::StringTypeAdapter<const LChar*>::writeTo(LChar* destination) const
=======
: m_buffer(buffer)
, m_length(strlen(reinterpret_cast<const char*>(buffer)))
{
}

void WTF::StringTypeAdapter<const LChar*>::writeTo(LChar* destination)
>>>>>>> miniblink49
{
    memcpy(destination, m_buffer, static_cast<size_t>(m_length) * sizeof(LChar));
}

<<<<<<< HEAD
void WTF::StringTypeAdapter<const LChar*>::writeTo(UChar* destination) const
=======
void WTF::StringTypeAdapter<const LChar*>::writeTo(UChar* destination)
>>>>>>> miniblink49
{
    StringImpl::copyChars(destination, m_buffer, m_length);
}

<<<<<<< HEAD
void WTF::StringTypeAdapter<StringView>::writeTo(LChar* destination) const
{
    DCHECK(is8Bit());
    StringImpl::copyChars(destination, m_view.characters8(), m_view.length());
    WTF_STRINGTYPEADAPTER_COPIED_WTF_STRING();
}

void WTF::StringTypeAdapter<StringView>::writeTo(UChar* destination) const
{
    if (is8Bit())
        StringImpl::copyChars(destination, m_view.characters8(), m_view.length());
    else
        StringImpl::copyChars(destination, m_view.characters16(), m_view.length());
    WTF_STRINGTYPEADAPTER_COPIED_WTF_STRING();
}
=======
void WTF::StringTypeAdapter<Vector<char>>::writeTo(LChar* destination)
{
    for (size_t i = 0; i < m_buffer.size(); ++i)
        destination[i] = static_cast<unsigned char>(m_buffer[i]);
}

void WTF::StringTypeAdapter<Vector<char>>::writeTo(UChar* destination)
{
    for (size_t i = 0; i < m_buffer.size(); ++i)
        destination[i] = static_cast<unsigned char>(m_buffer[i]);
}

void WTF::StringTypeAdapter<Vector<LChar>>::writeTo(LChar* destination)
{
    for (size_t i = 0; i < m_buffer.size(); ++i)
        destination[i] = m_buffer[i];
}

void WTF::StringTypeAdapter<Vector<LChar>>::writeTo(UChar* destination)
{
    for (size_t i = 0; i < m_buffer.size(); ++i)
        destination[i] = m_buffer[i];
}

void WTF::StringTypeAdapter<String>::writeTo(LChar* destination)
{
    unsigned length = m_buffer.length();

    ASSERT(is8Bit());
    const LChar* data = m_buffer.characters8();
    for (unsigned i = 0; i < length; ++i)
        destination[i] = data[i];

    WTF_STRINGTYPEADAPTER_COPIED_WTF_STRING();
}

void WTF::StringTypeAdapter<String>::writeTo(UChar* destination)
{
    unsigned length = m_buffer.length();

    if (is8Bit()) {
        const LChar* data = m_buffer.characters8();
        for (unsigned i = 0; i < length; ++i)
            destination[i] = data[i];
    } else {
        const UChar* data = m_buffer.characters16();
        for (unsigned i = 0; i < length; ++i)
            destination[i] = data[i];
    }

    WTF_STRINGTYPEADAPTER_COPIED_WTF_STRING();
}

>>>>>>> miniblink49
