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

#ifndef WebURL_h
#define WebURL_h

<<<<<<< HEAD
#include "WebCommon.h"
#include "WebString.h"
#include "url/third_party/mozilla/url_parse.h"
#include "third_party/WebKit/public/platform/WebCString.h"

#if !INSIDE_BLINK
#include "url/gurl.h"
=======
#include "WebCString.h"
#include "WebString.h"
//#include <url/third_party/mozilla/url_parse.h>

#if !INSIDE_BLINK
#include <url/gurl.h>
>>>>>>> miniblink49
#endif

namespace blink {

class KURL;

class WebURL {
public:
<<<<<<< HEAD
    ~WebURL() { }
=======
    ~WebURL()
    {
    }
>>>>>>> miniblink49

    WebURL()
        : m_isValid(false)
    {
    }

<<<<<<< HEAD
    WebURL(const WebURL& url);

    WebURL& operator=(const WebURL& url);

    const WebString& string() const { return m_string; }
=======
    WebURL(const WebURL& url)
        : m_string(url.m_string)
        //, m_parsed(url.m_parsed)
        , m_isValid(url.m_isValid)
    {
    }

    WebURL& operator=(const WebURL& url)
    {
        m_string = url.m_string;
        //m_parsed = url.m_parsed;
        m_isValid = url.m_isValid;
        return *this;
    }
>>>>>>> miniblink49

    // FIXME: Remove this API.
    WebCString spec() const
    {
        std::string spec = m_string.utf8();
        return WebCString(spec.data(), spec.length());
    }

<<<<<<< HEAD
    const url::Parsed& parsed() const { return m_parsed; }

    bool isValid() const { return m_isValid; }

    bool isEmpty() const { return m_string.isEmpty(); }

    bool isNull() const { return m_string.isEmpty(); }

    BLINK_PLATFORM_EXPORT bool protocolIs(const char* protocol) const;
=======
    const WebString& string() const
    {
        return m_string;
    }

//     const url::Parsed& parsed() const
//     {
//         return m_parsed;
//     }

    bool isValid() const
    {
        return m_isValid;
    }

    bool isEmpty() const
    {
        return m_string.isEmpty();
    }

    bool isNull() const
    {
        return m_string.isEmpty();
    }
>>>>>>> miniblink49

#if INSIDE_BLINK
    BLINK_PLATFORM_EXPORT WebURL(const KURL&);
    BLINK_PLATFORM_EXPORT WebURL& operator=(const KURL&);
    BLINK_PLATFORM_EXPORT operator KURL() const;
#else
<<<<<<< HEAD
//     WebURL(const GURL& url);
//     WebURL& operator=(const GURL& url);
//     operator GURL() const;
    operator GURL() const
    {
        //return isNull() ? GURL() : GURL(m_string.utf8(), m_parsed, m_isValid);
        return isNull() ? GURL() : GURL(m_string.utf8());
    }

    WebURL(const GURL& url)
        : m_string(WebString::fromUTF8(url.possibly_invalid_spec()))
        ,
        //m_parsed(url.parsed_for_possibly_invalid_spec()),
        m_isValid(url.is_valid())
=======
    WebURL(const GURL& url)
        : m_string(WebString::fromUTF8(url.possibly_invalid_spec()))
        , m_parsed(url.parsed_for_possibly_invalid_spec())
        , m_isValid(url.is_valid())
>>>>>>> miniblink49
    {
    }

    WebURL& operator=(const GURL& url)
    {
        m_string = WebString::fromUTF8(url.possibly_invalid_spec());
<<<<<<< HEAD
        //m_parsed = url.parsed_for_possibly_invalid_spec();
        m_isValid = url.is_valid();

        return *this;
    }
=======
        m_parsed = url.parsed_for_possibly_invalid_spec();
        m_isValid = url.is_valid();
        return *this;
    }

    operator GURL() const
    {
        return isNull() ? GURL() : GURL(m_string.utf8(), m_parsed, m_isValid);
    }
>>>>>>> miniblink49
#endif

private:
    WebString m_string;
<<<<<<< HEAD
    url::Parsed m_parsed;
=======
    //url::Parsed m_parsed;
>>>>>>> miniblink49
    bool m_isValid;
};

inline bool operator==(const WebURL& a, const WebURL& b)
{
    return a.string().equals(b.string());
}

inline bool operator!=(const WebURL& a, const WebURL& b)
{
    return !(a == b);
}

} // namespace blink

#endif
