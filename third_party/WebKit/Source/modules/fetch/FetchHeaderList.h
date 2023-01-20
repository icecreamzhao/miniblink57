// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FetchHeaderList_h
#define FetchHeaderList_h

#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
<<<<<<< HEAD
#include "wtf/PassRefPtr.h"
#include "wtf/Vector.h"
#include "wtf/text/WTFString.h"
#include <memory>
=======
#include "wtf/OwnPtr.h"
#include "wtf/PassRefPtr.h"
#include "wtf/Vector.h"
#include "wtf/text/WTFString.h"
>>>>>>> miniblink49
#include <utility>

namespace blink {

class Header;

// http://fetch.spec.whatwg.org/#terminology-headers
<<<<<<< HEAD
class MODULES_EXPORT FetchHeaderList final
    : public GarbageCollectedFinalized<FetchHeaderList> {
public:
    typedef std::pair<String, String> Header;
    static FetchHeaderList* create();
    FetchHeaderList* clone() const;
=======
class MODULES_EXPORT FetchHeaderList final : public GarbageCollectedFinalized<FetchHeaderList> {
public:
    typedef std::pair<String, String> Header;
    static FetchHeaderList* create();
    FetchHeaderList* clone();
>>>>>>> miniblink49

    ~FetchHeaderList();
    void append(const String&, const String&);
    void set(const String&, const String&);
    // FIXME: Implement parse()
    String extractMIMEType() const;

    size_t size() const;
    void remove(const String&);
    bool get(const String&, String&) const;
    void getAll(const String&, Vector<String>&) const;
    bool has(const String&) const;
    void clearList();

    bool containsNonSimpleHeader() const;
<<<<<<< HEAD
    void sortAndCombine();

    const Vector<std::unique_ptr<Header>>& list() const { return m_headerList; }
    const Header& entry(size_t index) const
    {
        return *(m_headerList[index].get());
    }
=======

    const Vector<OwnPtr<Header>>& list() const { return m_headerList; }
    const Header& entry(size_t index) const { return *(m_headerList[index].get()); }
>>>>>>> miniblink49

    static bool isValidHeaderName(const String&);
    static bool isValidHeaderValue(const String&);

    DEFINE_INLINE_TRACE() { }

private:
    FetchHeaderList();
<<<<<<< HEAD
    Vector<std::unique_ptr<Header>> m_headerList;
=======
    Vector<OwnPtr<Header>> m_headerList;
>>>>>>> miniblink49
};

} // namespace blink

#endif // FetchHeaderList_h
