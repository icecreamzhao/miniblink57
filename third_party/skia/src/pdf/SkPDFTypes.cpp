<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkPDFTypes.h"
<<<<<<< HEAD
#include "SkDeflate.h"
#include "SkPDFUtils.h"
#include "SkStream.h"
#include "SkStreamPriv.h"
=======
#include "SkPDFUtils.h"
#include "SkStream.h"

#ifdef SK_BUILD_FOR_WIN
    #define SNPRINTF    _snprintf
#else
    #define SNPRINTF    snprintf
#endif
>>>>>>> miniblink49

////////////////////////////////////////////////////////////////////////////////

SkString* pun(char* x) { return reinterpret_cast<SkString*>(x); }
<<<<<<< HEAD
const SkString* pun(const char* x)
{
    return reinterpret_cast<const SkString*>(x);
}

SkPDFUnion::SkPDFUnion(Type t)
    : fType(t)
{
}

SkPDFUnion::~SkPDFUnion()
{
    switch (fType) {
    case Type::kNameSkS:
    case Type::kStringSkS:
        pun(fSkString)->~SkString();
        return;
    case Type::kObjRef:
    case Type::kObject:
        SkASSERT(fObject);
        fObject->unref();
        return;
    default:
        return;
    }
}

SkPDFUnion& SkPDFUnion::operator=(SkPDFUnion&& other)
{
    if (this != &other) {
        this->~SkPDFUnion();
        new (this) SkPDFUnion(std::move(other));
=======
const SkString* pun(const char* x) {
    return reinterpret_cast<const SkString*>(x);
}

SkPDFUnion::SkPDFUnion(Type t) : fType(t) {}

SkPDFUnion::~SkPDFUnion() {
    switch (fType) {
        case Type::kNameSkS:
        case Type::kStringSkS:
            pun(fSkString)->~SkString();
            return;
        case Type::kObjRef:
        case Type::kObject:
            SkSafeUnref(fObject);
            return;
        default:
            return;
    }
}

SkPDFUnion& SkPDFUnion::operator=(SkPDFUnion&& other) {
    if (this != &other) {
        this->~SkPDFUnion();
        SkNEW_PLACEMENT_ARGS(this, SkPDFUnion, (other.move()));
>>>>>>> miniblink49
    }
    return *this;
}

<<<<<<< HEAD
SkPDFUnion::SkPDFUnion(SkPDFUnion&& other)
{
=======
SkPDFUnion::SkPDFUnion(SkPDFUnion&& other) {
>>>>>>> miniblink49
    SkASSERT(this != &other);
    memcpy(this, &other, sizeof(*this));
    other.fType = Type::kDestroyed;
}

#if 0
SkPDFUnion SkPDFUnion::copy() const {
    SkPDFUnion u(fType);
    memcpy(&u, this, sizeof(u));
    switch (fType) {
        case Type::kNameSkS:
        case Type::kStringSkS:
<<<<<<< HEAD
            new (pun(u.fSkString)) SkString(*pun(fSkString));
            return u;
        case Type::kObjRef:
        case Type::kObject:
            SkRef(u.fObject);
            return u;
        default:
            return u;
=======
            SkNEW_PLACEMENT_ARGS(pun(u.fSkString), SkString,
                                 (*pun(fSkString)));
            return u.move();
        case Type::kObjRef:
        case Type::kObject:
            SkRef(u.fObject);
            return u.move();
        default:
            return u.move();
>>>>>>> miniblink49
    }
}
SkPDFUnion& SkPDFUnion::operator=(const SkPDFUnion& other) {
    return *this = other.copy();
}
SkPDFUnion::SkPDFUnion(const SkPDFUnion& other) {
    *this = other.copy();
}
#endif

<<<<<<< HEAD
bool SkPDFUnion::isName() const
{
=======
bool SkPDFUnion::isName() const {
>>>>>>> miniblink49
    return Type::kName == fType || Type::kNameSkS == fType;
}

#ifdef SK_DEBUG
// Most names need no escaping.  Such names are handled as static
// const strings.
<<<<<<< HEAD
bool is_valid_name(const char* n)
{
=======
bool is_valid_name(const char* n) {
>>>>>>> miniblink49
    static const char kControlChars[] = "/%()<>[]{}";
    while (*n) {
        if (*n < '!' || *n > '~' || strchr(kControlChars, *n)) {
            return false;
        }
        ++n;
    }
    return true;
}
<<<<<<< HEAD
#endif // SK_DEBUG

// Given an arbitrary string, write it as a valid name (not including
// leading slash).
static void write_name_escaped(SkWStream* o, const char* name)
{
=======
#endif  // SK_DEBUG

// Given an arbitrary string, write it as a valid name (not including
// leading slash).
static void write_name_escaped(SkWStream* o, const char* name) {
>>>>>>> miniblink49
    static const char kToEscape[] = "#/%()<>[]{}";
    static const char kHex[] = "0123456789ABCDEF";
    for (const uint8_t* n = reinterpret_cast<const uint8_t*>(name); *n; ++n) {
        if (*n < '!' || *n > '~' || strchr(kToEscape, *n)) {
<<<<<<< HEAD
            char buffer[3] = { '#', '\0', '\0' };
=======
            char buffer[3] = {'#', '\0', '\0'};
>>>>>>> miniblink49
            buffer[1] = kHex[(*n >> 4) & 0xF];
            buffer[2] = kHex[*n & 0xF];
            o->write(buffer, sizeof(buffer));
        } else {
            o->write(n, 1);
        }
    }
}

<<<<<<< HEAD
void SkPDFUnion::emitObject(SkWStream* stream,
    const SkPDFObjNumMap& objNumMap,
    const SkPDFSubstituteMap& substitutes) const
{
    switch (fType) {
    case Type::kInt:
        stream->writeDecAsText(fIntValue);
        return;
    case Type::kBool:
        stream->writeText(fBoolValue ? "true" : "false");
        return;
    case Type::kScalar:
        SkPDFUtils::AppendScalar(fScalarValue, stream);
        return;
    case Type::kName:
        stream->writeText("/");
        SkASSERT(is_valid_name(fStaticString));
        stream->writeText(fStaticString);
        return;
    case Type::kString:
        SkASSERT(fStaticString);
        SkPDFUtils::WriteString(stream, fStaticString,
            strlen(fStaticString));
        return;
    case Type::kNameSkS:
        stream->writeText("/");
        write_name_escaped(stream, pun(fSkString)->c_str());
        return;
    case Type::kStringSkS:
        SkPDFUtils::WriteString(stream, pun(fSkString)->c_str(),
            pun(fSkString)->size());
        return;
    case Type::kObjRef:
        stream->writeDecAsText(objNumMap.getObjectNumber(
            substitutes.getSubstitute(fObject)));
        stream->writeText(" 0 R"); // Generation number is always 0.
        return;
    case Type::kObject:
        fObject->emitObject(stream, objNumMap, substitutes);
        return;
    default:
        SkDEBUGFAIL("SkPDFUnion::emitObject with bad type");
=======
static void write_string(SkWStream* o, const SkString& s) {
    o->write(s.c_str(), s.size());
}

static SkString format_string(const SkString& s) {
    return SkPDFUtils::FormatString(s.c_str(), s.size());
}

static SkString format_string(const char* s) {
    return SkPDFUtils::FormatString(s, strlen(s));
}

void SkPDFUnion::emitObject(SkWStream* stream,
                            const SkPDFObjNumMap& objNumMap,
                            const SkPDFSubstituteMap& substitutes) const {
    switch (fType) {
        case Type::kInt:
            stream->writeDecAsText(fIntValue);
            return;
        case Type::kBool:
            stream->writeText(fBoolValue ? "true" : "false");
            return;
        case Type::kScalar:
            SkPDFUtils::AppendScalar(fScalarValue, stream);
            return;
        case Type::kName:
            stream->writeText("/");
            SkASSERT(is_valid_name(fStaticString));
            stream->writeText(fStaticString);
            return;
        case Type::kString:
            SkASSERT(fStaticString);
            write_string(stream, format_string(fStaticString));
            return;
        case Type::kNameSkS:
            stream->writeText("/");
            write_name_escaped(stream, pun(fSkString)->c_str());
            return;
        case Type::kStringSkS:
            write_string(stream, format_string(*pun(fSkString)));
            return;
        case Type::kObjRef:
            stream->writeDecAsText(objNumMap.getObjectNumber(
                    substitutes.getSubstitute(fObject)));
            stream->writeText(" 0 R");  // Generation number is always 0.
            return;
        case Type::kObject:
            fObject->emitObject(stream, objNumMap, substitutes);
            return;
        default:
            SkDEBUGFAIL("SkPDFUnion::emitObject with bad type");
>>>>>>> miniblink49
    }
}

void SkPDFUnion::addResources(SkPDFObjNumMap* objNumMap,
<<<<<<< HEAD
    const SkPDFSubstituteMap& substituteMap) const
{
    switch (fType) {
    case Type::kInt:
    case Type::kBool:
    case Type::kScalar:
    case Type::kName:
    case Type::kString:
    case Type::kNameSkS:
    case Type::kStringSkS:
        return; // These have no resources.
    case Type::kObjRef: {
        SkPDFObject* obj = substituteMap.getSubstitute(fObject);
        objNumMap->addObjectRecursively(obj, substituteMap);
        return;
    }
    case Type::kObject:
        fObject->addResources(objNumMap, substituteMap);
        return;
    default:
        SkDEBUGFAIL("SkPDFUnion::addResources with bad type");
    }
}

SkPDFUnion SkPDFUnion::Int(int32_t value)
{
    SkPDFUnion u(Type::kInt);
    u.fIntValue = value;
    return u;
}

SkPDFUnion SkPDFUnion::Bool(bool value)
{
    SkPDFUnion u(Type::kBool);
    u.fBoolValue = value;
    return u;
}

SkPDFUnion SkPDFUnion::Scalar(SkScalar value)
{
    SkPDFUnion u(Type::kScalar);
    u.fScalarValue = value;
    return u;
}

SkPDFUnion SkPDFUnion::Name(const char* value)
{
=======
                              const SkPDFSubstituteMap& substituteMap) const {
    switch (fType) {
        case Type::kInt:
        case Type::kBool:
        case Type::kScalar:
        case Type::kName:
        case Type::kString:
        case Type::kNameSkS:
        case Type::kStringSkS:
            return;  // These have no resources.
        case Type::kObjRef: {
            SkPDFObject* obj = substituteMap.getSubstitute(fObject);
            if (objNumMap->addObject(obj)) {
                obj->addResources(objNumMap, substituteMap);
            }
            return;
        }
        case Type::kObject:
            fObject->addResources(objNumMap, substituteMap);
            return;
        default:
            SkDEBUGFAIL("SkPDFUnion::addResources with bad type");
    }
}

SkPDFUnion SkPDFUnion::Int(int32_t value) {
    SkPDFUnion u(Type::kInt);
    u.fIntValue = value;
    return u.move();
}

SkPDFUnion SkPDFUnion::Bool(bool value) {
    SkPDFUnion u(Type::kBool);
    u.fBoolValue = value;
    return u.move();
}

SkPDFUnion SkPDFUnion::Scalar(SkScalar value) {
    SkPDFUnion u(Type::kScalar);
    u.fScalarValue = value;
    return u.move();
}

SkPDFUnion SkPDFUnion::Name(const char* value) {
>>>>>>> miniblink49
    SkPDFUnion u(Type::kName);
    SkASSERT(value);
    SkASSERT(is_valid_name(value));
    u.fStaticString = value;
<<<<<<< HEAD
    return u;
}

SkPDFUnion SkPDFUnion::String(const char* value)
{
    SkPDFUnion u(Type::kString);
    SkASSERT(value);
    u.fStaticString = value;
    return u;
}

SkPDFUnion SkPDFUnion::Name(const SkString& s)
{
    SkPDFUnion u(Type::kNameSkS);
    new (pun(u.fSkString)) SkString(s);
    return u;
}

SkPDFUnion SkPDFUnion::String(const SkString& s)
{
    SkPDFUnion u(Type::kStringSkS);
    new (pun(u.fSkString)) SkString(s);
    return u;
}

SkPDFUnion SkPDFUnion::ObjRef(sk_sp<SkPDFObject> objSp)
{
    SkPDFUnion u(Type::kObjRef);
    SkASSERT(objSp.get());
    u.fObject = objSp.release(); // take ownership into union{}
    return u;
}

SkPDFUnion SkPDFUnion::Object(sk_sp<SkPDFObject> objSp)
{
    SkPDFUnion u(Type::kObject);
    SkASSERT(objSp.get());
    u.fObject = objSp.release(); // take ownership into union{}
    return u;
=======
    return u.move();
}

SkPDFUnion SkPDFUnion::String(const char* value) {
    SkPDFUnion u(Type::kString);
    SkASSERT(value);
    u.fStaticString = value;
    return u.move();
}

SkPDFUnion SkPDFUnion::Name(const SkString& s) {
    SkPDFUnion u(Type::kNameSkS);
    SkNEW_PLACEMENT_ARGS(pun(u.fSkString), SkString, (s));
    return u.move();
}

SkPDFUnion SkPDFUnion::String(const SkString& s) {
    SkPDFUnion u(Type::kStringSkS);
    SkNEW_PLACEMENT_ARGS(pun(u.fSkString), SkString, (s));
    return u.move();
}

SkPDFUnion SkPDFUnion::ObjRef(SkPDFObject* ptr) {
    SkPDFUnion u(Type::kObjRef);
    SkASSERT(ptr);
    u.fObject = ptr;
    return u.move();
}

SkPDFUnion SkPDFUnion::Object(SkPDFObject* ptr) {
    SkPDFUnion u(Type::kObject);
    SkASSERT(ptr);
    u.fObject = ptr;
    return u.move();
>>>>>>> miniblink49
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#if 0 // Enable if needed.
void SkPDFAtom::emitObject(SkWStream* stream,
                           const SkPDFObjNumMap& objNumMap,
                           const SkPDFSubstituteMap& substitutes) const {
=======
#if 0  // Enable if needed.
void SkPDFAtom::emitObject(SkWStream* stream,
                           const SkPDFObjNumMap& objNumMap,
                           const SkPDFSubstituteMap& substitutes) {
>>>>>>> miniblink49
    fValue.emitObject(stream, objNumMap, substitutes);
}
void SkPDFAtom::addResources(SkPDFObjNumMap* map,
                             const SkPDFSubstituteMap& substitutes) const {
    fValue.addResources(map, substitutes);
}
<<<<<<< HEAD
#endif // 0

////////////////////////////////////////////////////////////////////////////////

SkPDFArray::SkPDFArray() { SkDEBUGCODE(fDumped = false;) }

SkPDFArray::~SkPDFArray() { this->drop(); }

void SkPDFArray::drop()
{
    fValues.reset();
    SkDEBUGCODE(fDumped = true;)
=======
#endif  // 0

////////////////////////////////////////////////////////////////////////////////

SkPDFArray::SkPDFArray() {}
SkPDFArray::~SkPDFArray() {
    for (SkPDFUnion& value : fValues) {
        value.~SkPDFUnion();
    }
    fValues.reset();
>>>>>>> miniblink49
}

int SkPDFArray::size() const { return fValues.count(); }

<<<<<<< HEAD
void SkPDFArray::reserve(int length)
{
    // TODO(halcanary): implement SkTArray<T>::reserve() or change the
    // contstructor of SkPDFArray to take reserve size.
}

void SkPDFArray::emitObject(SkWStream* stream,
    const SkPDFObjNumMap& objNumMap,
    const SkPDFSubstituteMap& substitutes) const
{
    SkASSERT(!fDumped);
=======
void SkPDFArray::reserve(int length) { fValues.setReserve(length); }

void SkPDFArray::emitObject(SkWStream* stream,
                             const SkPDFObjNumMap& objNumMap,
                             const SkPDFSubstituteMap& substitutes) {
>>>>>>> miniblink49
    stream->writeText("[");
    for (int i = 0; i < fValues.count(); i++) {
        fValues[i].emitObject(stream, objNumMap, substitutes);
        if (i + 1 < fValues.count()) {
            stream->writeText(" ");
        }
    }
    stream->writeText("]");
}

void SkPDFArray::addResources(SkPDFObjNumMap* catalog,
<<<<<<< HEAD
    const SkPDFSubstituteMap& substitutes) const
{
    SkASSERT(!fDumped);
=======
                              const SkPDFSubstituteMap& substitutes) const {
>>>>>>> miniblink49
    for (const SkPDFUnion& value : fValues) {
        value.addResources(catalog, substitutes);
    }
}

<<<<<<< HEAD
void SkPDFArray::append(SkPDFUnion&& value)
{
    fValues.emplace_back(std::move(value));
}

void SkPDFArray::appendInt(int32_t value)
{
    this->append(SkPDFUnion::Int(value));
}

void SkPDFArray::appendBool(bool value)
{
    this->append(SkPDFUnion::Bool(value));
}

void SkPDFArray::appendScalar(SkScalar value)
{
    this->append(SkPDFUnion::Scalar(value));
}

void SkPDFArray::appendName(const char name[])
{
    this->append(SkPDFUnion::Name(SkString(name)));
}

void SkPDFArray::appendName(const SkString& name)
{
    this->append(SkPDFUnion::Name(name));
}

void SkPDFArray::appendString(const SkString& value)
{
    this->append(SkPDFUnion::String(value));
}

void SkPDFArray::appendString(const char value[])
{
    this->append(SkPDFUnion::String(value));
}

void SkPDFArray::appendObject(sk_sp<SkPDFObject> objSp)
{
    this->append(SkPDFUnion::Object(std::move(objSp)));
}

void SkPDFArray::appendObjRef(sk_sp<SkPDFObject> objSp)
{
    this->append(SkPDFUnion::ObjRef(std::move(objSp)));
=======
void SkPDFArray::append(SkPDFUnion&& value) {
    SkNEW_PLACEMENT_ARGS(fValues.append(), SkPDFUnion, (value.move()));
}

void SkPDFArray::appendInt(int32_t value) {
    this->append(SkPDFUnion::Int(value));
}

void SkPDFArray::appendBool(bool value) {
    this->append(SkPDFUnion::Bool(value));
}

void SkPDFArray::appendScalar(SkScalar value) {
    this->append(SkPDFUnion::Scalar(value));
}

void SkPDFArray::appendName(const char name[]) {
    this->append(SkPDFUnion::Name(SkString(name)));
}

void SkPDFArray::appendName(const SkString& name) {
    this->append(SkPDFUnion::Name(name));
}

void SkPDFArray::appendString(const SkString& value) {
    this->append(SkPDFUnion::String(value));
}

void SkPDFArray::appendString(const char value[]) {
    this->append(SkPDFUnion::String(value));
}

void SkPDFArray::appendObject(SkPDFObject* value) {
    this->append(SkPDFUnion::Object(value));
}

void SkPDFArray::appendObjRef(SkPDFObject* value) {
    this->append(SkPDFUnion::ObjRef(value));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkPDFDict::~SkPDFDict() { this->drop(); }

void SkPDFDict::drop()
{
    fRecords.reset();
    SkDEBUGCODE(fDumped = true;)
}

SkPDFDict::SkPDFDict(const char type[])
{
    SkDEBUGCODE(fDumped = false;) if (type)
    {
        this->insertName("Type", type);
    }
}

void SkPDFDict::emitObject(SkWStream* stream,
    const SkPDFObjNumMap& objNumMap,
    const SkPDFSubstituteMap& substitutes) const
{
    stream->writeText("<<");
    this->emitAll(stream, objNumMap, substitutes);
    stream->writeText(">>");
}

void SkPDFDict::emitAll(SkWStream* stream,
    const SkPDFObjNumMap& objNumMap,
    const SkPDFSubstituteMap& substitutes) const
{
    SkASSERT(!fDumped);
=======
SkPDFDict::SkPDFDict() {}

SkPDFDict::~SkPDFDict() { this->clear(); }

SkPDFDict::SkPDFDict(const char type[]) { this->insertName("Type", type); }

void SkPDFDict::emitObject(SkWStream* stream,
                           const SkPDFObjNumMap& objNumMap,
                           const SkPDFSubstituteMap& substitutes) {
    stream->writeText("<<");
>>>>>>> miniblink49
    for (int i = 0; i < fRecords.count(); i++) {
        fRecords[i].fKey.emitObject(stream, objNumMap, substitutes);
        stream->writeText(" ");
        fRecords[i].fValue.emitObject(stream, objNumMap, substitutes);
        if (i + 1 < fRecords.count()) {
            stream->writeText("\n");
        }
    }
<<<<<<< HEAD
}

void SkPDFDict::addResources(SkPDFObjNumMap* catalog,
    const SkPDFSubstituteMap& substitutes) const
{
    SkASSERT(!fDumped);
=======
    stream->writeText(">>");
}

void SkPDFDict::addResources(SkPDFObjNumMap* catalog,
                             const SkPDFSubstituteMap& substitutes) const {
>>>>>>> miniblink49
    for (int i = 0; i < fRecords.count(); i++) {
        fRecords[i].fKey.addResources(catalog, substitutes);
        fRecords[i].fValue.addResources(catalog, substitutes);
    }
}

<<<<<<< HEAD
SkPDFDict::Record::Record(SkPDFUnion&& k, SkPDFUnion&& v)
    : fKey(std::move(k))
    , fValue(std::move(v))
{
}

SkPDFDict::Record::Record(SkPDFDict::Record&& o)
    : fKey(std::move(o.fKey))
    , fValue(std::move(o.fValue))
{
}

SkPDFDict::Record& SkPDFDict::Record::operator=(SkPDFDict::Record&& o)
{
    fKey = std::move(o.fKey);
    fValue = std::move(o.fValue);
    return *this;
=======
void SkPDFDict::set(SkPDFUnion&& name, SkPDFUnion&& value) {
    Record* rec = fRecords.append();
    SkASSERT(name.isName());
    SkNEW_PLACEMENT_ARGS(&rec->fKey, SkPDFUnion, (name.move()));
    SkNEW_PLACEMENT_ARGS(&rec->fValue, SkPDFUnion, (value.move()));
>>>>>>> miniblink49
}

int SkPDFDict::size() const { return fRecords.count(); }

<<<<<<< HEAD
void SkPDFDict::insertObjRef(const char key[], sk_sp<SkPDFObject> objSp)
{
    fRecords.emplace_back(SkPDFUnion::Name(key), SkPDFUnion::ObjRef(std::move(objSp)));
}

void SkPDFDict::insertObjRef(const SkString& key, sk_sp<SkPDFObject> objSp)
{
    fRecords.emplace_back(SkPDFUnion::Name(key), SkPDFUnion::ObjRef(std::move(objSp)));
}

void SkPDFDict::insertObject(const char key[], sk_sp<SkPDFObject> objSp)
{
    fRecords.emplace_back(SkPDFUnion::Name(key), SkPDFUnion::Object(std::move(objSp)));
}
void SkPDFDict::insertObject(const SkString& key, sk_sp<SkPDFObject> objSp)
{
    fRecords.emplace_back(SkPDFUnion::Name(key), SkPDFUnion::Object(std::move(objSp)));
}

void SkPDFDict::insertBool(const char key[], bool value)
{
    fRecords.emplace_back(SkPDFUnion::Name(key), SkPDFUnion::Bool(value));
}

void SkPDFDict::insertInt(const char key[], int32_t value)
{
    fRecords.emplace_back(SkPDFUnion::Name(key), SkPDFUnion::Int(value));
}

void SkPDFDict::insertInt(const char key[], size_t value)
{
    this->insertInt(key, SkToS32(value));
}

void SkPDFDict::insertScalar(const char key[], SkScalar value)
{
    fRecords.emplace_back(SkPDFUnion::Name(key), SkPDFUnion::Scalar(value));
}

void SkPDFDict::insertName(const char key[], const char name[])
{
    fRecords.emplace_back(SkPDFUnion::Name(key), SkPDFUnion::Name(name));
}

void SkPDFDict::insertName(const char key[], const SkString& name)
{
    fRecords.emplace_back(SkPDFUnion::Name(key), SkPDFUnion::Name(name));
}

void SkPDFDict::insertString(const char key[], const char value[])
{
    fRecords.emplace_back(SkPDFUnion::Name(key), SkPDFUnion::String(value));
}

void SkPDFDict::insertString(const char key[], const SkString& value)
{
    fRecords.emplace_back(SkPDFUnion::Name(key), SkPDFUnion::String(value));
=======
void SkPDFDict::insertObjRef(const char key[], SkPDFObject* value) {
    this->set(SkPDFUnion::Name(key), SkPDFUnion::ObjRef(value));
}
void SkPDFDict::insertObjRef(const SkString& key, SkPDFObject* value) {
    this->set(SkPDFUnion::Name(key), SkPDFUnion::ObjRef(value));
}

void SkPDFDict::insertObject(const char key[], SkPDFObject* value) {
    this->set(SkPDFUnion::Name(key), SkPDFUnion::Object(value));
}
void SkPDFDict::insertObject(const SkString& key, SkPDFObject* value) {
    this->set(SkPDFUnion::Name(key), SkPDFUnion::Object(value));
}

void SkPDFDict::insertBool(const char key[], bool value) {
    this->set(SkPDFUnion::Name(key), SkPDFUnion::Bool(value));
}

void SkPDFDict::insertInt(const char key[], int32_t value) {
    this->set(SkPDFUnion::Name(key), SkPDFUnion::Int(value));
}

void SkPDFDict::insertInt(const char key[], size_t value) {
    this->insertInt(key, SkToS32(value));
}

void SkPDFDict::insertScalar(const char key[], SkScalar value) {
    this->set(SkPDFUnion::Name(key), SkPDFUnion::Scalar(value));
}

void SkPDFDict::insertName(const char key[], const char name[]) {
    this->set(SkPDFUnion::Name(key), SkPDFUnion::Name(name));
}

void SkPDFDict::insertName(const char key[], const SkString& name) {
    this->set(SkPDFUnion::Name(key), SkPDFUnion::Name(name));
}

void SkPDFDict::insertString(const char key[], const char value[]) {
    this->set(SkPDFUnion::Name(key), SkPDFUnion::String(value));
}

void SkPDFDict::insertString(const char key[], const SkString& value) {
    this->set(SkPDFUnion::Name(key), SkPDFUnion::String(value));
}

void SkPDFDict::clear() {
    for (Record& rec : fRecords) {
        rec.fKey.~SkPDFUnion();
        rec.fValue.~SkPDFUnion();
    }
    fRecords.reset();
>>>>>>> miniblink49
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkPDFSharedStream::SkPDFSharedStream(SkStreamAsset* data)
    : fAsset(data)
    , fDict(new SkPDFDict)
{
    SkDEBUGCODE(fDumped = false;)
        SkASSERT(data);
}

SkPDFSharedStream::~SkPDFSharedStream() { this->drop(); }

void SkPDFSharedStream::drop()
{
    fAsset.reset();
    fDict.reset(nullptr);
    SkDEBUGCODE(fDumped = true;)
}

#ifdef SK_PDF_LESS_COMPRESSION
void SkPDFSharedStream::emitObject(
    SkWStream* stream,
    const SkPDFObjNumMap& objNumMap,
    const SkPDFSubstituteMap& substitutes) const
{
    SkASSERT(!fDumped);
    std::unique_ptr<SkStreamAsset> dup(fAsset->duplicate());
    SkASSERT(dup && dup->hasLength());
    size_t length = dup->getLength();
    stream->writeText("<<");
    fDict->emitAll(stream, objNumMap, substitutes);
    stream->writeText("\n");
    SkPDFUnion::Name("Length").emitObject(
        stream, objNumMap, substitutes);
    stream->writeText(" ");
    SkPDFUnion::Int(length).emitObject(
        stream, objNumMap, substitutes);
    stream->writeText("\n>>stream\n");
    SkStreamCopy(stream, dup.get());
    stream->writeText("\nendstream");
}
#else
void SkPDFSharedStream::emitObject(
    SkWStream* stream,
    const SkPDFObjNumMap& objNumMap,
    const SkPDFSubstituteMap& substitutes) const
{
    SkASSERT(!fDumped);
    SkDynamicMemoryWStream buffer;
    SkDeflateWStream deflateWStream(&buffer);
    // Since emitObject is const, this function doesn't change the dictionary.
    std::unique_ptr<SkStreamAsset> dup(fAsset->duplicate()); // Cheap copy
    SkASSERT(dup);
    SkStreamCopy(&deflateWStream, dup.get());
    deflateWStream.finalize();
    size_t length = buffer.bytesWritten();
    stream->writeText("<<");
    fDict->emitAll(stream, objNumMap, substitutes);
    stream->writeText("\n");
    SkPDFUnion::Name("Length").emitObject(stream, objNumMap, substitutes);
    stream->writeText(" ");
    SkPDFUnion::Int(length).emitObject(stream, objNumMap, substitutes);
    stream->writeText("\n");
    SkPDFUnion::Name("Filter").emitObject(stream, objNumMap, substitutes);
    stream->writeText(" ");
    SkPDFUnion::Name("FlateDecode").emitObject(stream, objNumMap, substitutes);
    stream->writeText(">>");
    stream->writeText(" stream\n");
    buffer.writeToStream(stream);
    stream->writeText("\nendstream");
}
#endif

void SkPDFSharedStream::addResources(
    SkPDFObjNumMap* catalog, const SkPDFSubstituteMap& substitutes) const
{
    SkASSERT(!fDumped);
    fDict->addResources(catalog, substitutes);
}

////////////////////////////////////////////////////////////////////////////////

SkPDFSubstituteMap::~SkPDFSubstituteMap()
{
    fSubstituteMap.foreach (
        [](SkPDFObject*, SkPDFObject** v) { (*v)->unref(); });
}

void SkPDFSubstituteMap::setSubstitute(SkPDFObject* original,
    SkPDFObject* substitute)
{
=======
SkPDFSubstituteMap::~SkPDFSubstituteMap() {
    fSubstituteMap.foreach(
            [](SkPDFObject*, SkPDFObject** v) { (*v)->unref(); });
}

void SkPDFSubstituteMap::setSubstitute(SkPDFObject* original,
                                       SkPDFObject* substitute) {
>>>>>>> miniblink49
    SkASSERT(original != substitute);
    SkASSERT(!fSubstituteMap.find(original));
    fSubstituteMap.set(original, SkRef(substitute));
}

<<<<<<< HEAD
SkPDFObject* SkPDFSubstituteMap::getSubstitute(SkPDFObject* object) const
{
=======
SkPDFObject* SkPDFSubstituteMap::getSubstitute(SkPDFObject* object) const {
>>>>>>> miniblink49
    SkPDFObject** found = fSubstituteMap.find(object);
    return found ? *found : object;
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool SkPDFObjNumMap::addObject(SkPDFObject* obj)
{
=======
bool SkPDFObjNumMap::addObject(SkPDFObject* obj) {
>>>>>>> miniblink49
    if (fObjectNumbers.find(obj)) {
        return false;
    }
    fObjectNumbers.set(obj, fObjectNumbers.count() + 1);
<<<<<<< HEAD
    fObjects.emplace_back(sk_ref_sp(obj));
    return true;
}

void SkPDFObjNumMap::addObjectRecursively(SkPDFObject* obj,
    const SkPDFSubstituteMap& subs)
{
    if (obj && this->addObject(obj)) {
        obj->addResources(this, subs);
    }
}

int32_t SkPDFObjNumMap::getObjectNumber(SkPDFObject* obj) const
{
=======
    fObjects.push(obj);
    return true;
}

int32_t SkPDFObjNumMap::getObjectNumber(SkPDFObject* obj) const {
>>>>>>> miniblink49
    int32_t* objectNumberFound = fObjectNumbers.find(obj);
    SkASSERT(objectNumberFound);
    return *objectNumberFound;
}

<<<<<<< HEAD
#ifdef SK_PDF_IMAGE_STATS
SkAtomic<int> gDrawImageCalls(0);
SkAtomic<int> gJpegImageObjects(0);
SkAtomic<int> gRegularImageObjects(0);

void SkPDFImageDumpStats()
{
    SkDebugf("\ntotal PDF drawImage/drawBitmap calls: %d\n"
             "total PDF jpeg images: %d\n"
             "total PDF regular images: %d\n",
        gDrawImageCalls.load(),
        gJpegImageObjects.load(),
        gRegularImageObjects.load());
}
#endif // SK_PDF_IMAGE_STATS
=======
>>>>>>> miniblink49
