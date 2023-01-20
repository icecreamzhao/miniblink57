<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDescriptor_DEFINED
#define SkDescriptor_DEFINED

#include "SkChecksum.h"
#include "SkTypes.h"

class SkDescriptor : SkNoncopyable {
public:
<<<<<<< HEAD
    static size_t ComputeOverhead(int entryCount)
    {
=======
    static size_t ComputeOverhead(int entryCount) {
>>>>>>> miniblink49
        SkASSERT(entryCount >= 0);
        return sizeof(SkDescriptor) + entryCount * sizeof(Entry);
    }

<<<<<<< HEAD
    static SkDescriptor* Alloc(size_t length)
    {
=======
    static SkDescriptor* Alloc(size_t length) {
>>>>>>> miniblink49
        SkASSERT(SkAlign4(length) == length);
        SkDescriptor* desc = (SkDescriptor*)sk_malloc_throw(length);
        return desc;
    }

<<<<<<< HEAD
    static void Free(SkDescriptor* desc)
    {
        sk_free(desc);
    }

    void init()
    {
        fLength = sizeof(SkDescriptor);
        fCount = 0;
=======
    static void Free(SkDescriptor* desc) {
        sk_free(desc);
    }

    void init() {
        fLength = sizeof(SkDescriptor);
        fCount  = 0;
>>>>>>> miniblink49
    }

    uint32_t getLength() const { return fLength; }

<<<<<<< HEAD
    void* addEntry(uint32_t tag, size_t length, const void* data = nullptr)
    {
        SkASSERT(tag);
        SkASSERT(SkAlign4(length) == length);
        SkASSERT(this->findEntry(tag, nullptr) == nullptr);
=======
    void* addEntry(uint32_t tag, size_t length, const void* data = NULL) {
        SkASSERT(tag);
        SkASSERT(SkAlign4(length) == length);
        SkASSERT(this->findEntry(tag, NULL) == NULL);
>>>>>>> miniblink49

        Entry* entry = (Entry*)((char*)this + fLength);
        entry->fTag = tag;
        entry->fLen = SkToU32(length);
        if (data) {
            memcpy(entry + 1, data, length);
        }

        fCount += 1;
        fLength = SkToU32(fLength + sizeof(Entry) + length);
        return (entry + 1); // return its data
    }

<<<<<<< HEAD
    void computeChecksum()
    {
=======
    void computeChecksum() {
>>>>>>> miniblink49
        fChecksum = SkDescriptor::ComputeChecksum(this);
    }

#ifdef SK_DEBUG
<<<<<<< HEAD
    void assertChecksum() const
    {
=======
    void assertChecksum() const {
>>>>>>> miniblink49
        SkASSERT(SkDescriptor::ComputeChecksum(this) == fChecksum);
    }
#endif

<<<<<<< HEAD
    const void* findEntry(uint32_t tag, uint32_t* length) const
    {
        const Entry* entry = (const Entry*)(this + 1);
        int count = fCount;
=======
    const void* findEntry(uint32_t tag, uint32_t* length) const {
        const Entry* entry = (const Entry*)(this + 1);
        int          count = fCount;
>>>>>>> miniblink49

        while (--count >= 0) {
            if (entry->fTag == tag) {
                if (length) {
                    *length = entry->fLen;
                }
                return entry + 1;
            }
            entry = (const Entry*)((const char*)(entry + 1) + entry->fLen);
        }
<<<<<<< HEAD
        return nullptr;
    }

    SkDescriptor* copy() const
    {
=======
        return NULL;
    }

    SkDescriptor* copy() const {
>>>>>>> miniblink49
        SkDescriptor* desc = SkDescriptor::Alloc(fLength);
        memcpy(desc, this, fLength);
        return desc;
    }

<<<<<<< HEAD
    bool operator==(const SkDescriptor& other) const
    {
        // probe to see if we have a good checksum algo
        //        SkASSERT(a.fChecksum != b.fChecksum || memcmp(&a, &b, a.fLength) == 0);
=======
    bool equals(const SkDescriptor& other) const {
        // probe to see if we have a good checksum algo
//        SkASSERT(a.fChecksum != b.fChecksum || memcmp(&a, &b, a.fLength) == 0);
>>>>>>> miniblink49

        // the first value we should look at is the checksum, so this loop
        // should terminate early if they descriptors are different.
        // NOTE: if we wrote a sentinel value at the end of each, we chould
        //       remove the aa < stop test in the loop...
        const uint32_t* aa = (const uint32_t*)this;
        const uint32_t* bb = (const uint32_t*)&other;
        const uint32_t* stop = (const uint32_t*)((const char*)aa + fLength);
        do {
            if (*aa++ != *bb++)
                return false;
        } while (aa < stop);
        return true;
    }
<<<<<<< HEAD
    bool operator!=(const SkDescriptor& other) const { return !(*this == other); }
=======
>>>>>>> miniblink49

    uint32_t getChecksum() const { return fChecksum; }

    struct Entry {
        uint32_t fTag;
        uint32_t fLen;
    };

#ifdef SK_DEBUG
<<<<<<< HEAD
    uint32_t getCount() const
    {
        return fCount;
    }
#endif

private:
    uint32_t fChecksum; // must be first
    uint32_t fLength; // must be second
    uint32_t fCount;

    static uint32_t ComputeChecksum(const SkDescriptor* desc)
    {
=======
    uint32_t getCount() const { return fCount; }
#endif

private:
    uint32_t fChecksum;  // must be first
    uint32_t fLength;    // must be second
    uint32_t fCount;

    static uint32_t ComputeChecksum(const SkDescriptor* desc) {
>>>>>>> miniblink49
        const uint32_t* ptr = (const uint32_t*)desc + 1; // skip the checksum field
        size_t len = desc->fLength - sizeof(uint32_t);
        return SkChecksum::Murmur3(ptr, len);
    }

    // private so no one can create one except our factories
<<<<<<< HEAD
    SkDescriptor() { }
=======
    SkDescriptor() {}
>>>>>>> miniblink49
};

#include "SkScalerContext.h"

class SkAutoDescriptor : SkNoncopyable {
public:
<<<<<<< HEAD
    SkAutoDescriptor()
        : fDesc(nullptr)
    {
    }
    SkAutoDescriptor(size_t size)
        : fDesc(nullptr)
    {
        this->reset(size);
    }
    SkAutoDescriptor(const SkDescriptor& desc)
        : fDesc(nullptr)
    {
        size_t size = desc.getLength();
        this->reset(size);
        memcpy(fDesc, &desc, size);
    }

    ~SkAutoDescriptor() { this->free(); }

    void reset(size_t size)
    {
=======
    SkAutoDescriptor() : fDesc(NULL) {}
    SkAutoDescriptor(size_t size) : fDesc(NULL) { this->reset(size); }

    ~SkAutoDescriptor() { this->free(); }

    void reset(size_t size) {
>>>>>>> miniblink49
        this->free();
        if (size <= sizeof(fStorage)) {
            fDesc = (SkDescriptor*)(void*)fStorage;
        } else {
            fDesc = SkDescriptor::Alloc(size);
        }
    }

<<<<<<< HEAD
    SkDescriptor* getDesc() const
    {
        SkASSERT(fDesc);
        return fDesc;
    }

private:
    void free()
    {
=======
    SkDescriptor* getDesc() const { SkASSERT(fDesc); return fDesc; }
private:
    void free() {
>>>>>>> miniblink49
        if (fDesc != (SkDescriptor*)(void*)fStorage) {
            SkDescriptor::Free(fDesc);
        }
    }

    enum {
<<<<<<< HEAD
        kStorageSize = sizeof(SkDescriptor)
            + sizeof(SkDescriptor::Entry) + sizeof(SkScalerContext::Rec) // for rec
            + sizeof(SkDescriptor::Entry) + sizeof(void*) // for typeface
            + 32 // slop for occational small extras
    };
    SkDescriptor* fDesc;
    uint32_t fStorage[(kStorageSize + 3) >> 2];
};
#define SkAutoDescriptor(...) SK_REQUIRE_LOCAL_VAR(SkAutoDescriptor)

=======
        kStorageSize =  sizeof(SkDescriptor)
                        + sizeof(SkDescriptor::Entry) + sizeof(SkScalerContext::Rec)    // for rec
                        + sizeof(SkDescriptor::Entry) + sizeof(void*)                   // for typeface
                        + 32   // slop for occational small extras
    };
    SkDescriptor*   fDesc;
    uint32_t        fStorage[(kStorageSize + 3) >> 2];
};
#define SkAutoDescriptor(...) SK_REQUIRE_LOCAL_VAR(SkAutoDescriptor)


>>>>>>> miniblink49
#endif
