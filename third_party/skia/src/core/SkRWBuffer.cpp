/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkRWBuffer.h"
<<<<<<< HEAD
#include "SkAtomics.h"
=======
>>>>>>> miniblink49
#include "SkStream.h"

// Force small chunks to be a page's worth
static const size_t kMinAllocSize = 4096;

struct SkBufferBlock {
<<<<<<< HEAD
    SkBufferBlock* fNext; // updated by the writer
    size_t fUsed; // updated by the writer
    const size_t fCapacity;

    SkBufferBlock(size_t capacity)
        : fNext(nullptr)
        , fUsed(0)
        , fCapacity(capacity)
    {
    }

    const void* startData() const { return this + 1; };

    size_t avail() const { return fCapacity - fUsed; }
    void* availData() { return (char*)this->startData() + fUsed; }

    static SkBufferBlock* Alloc(size_t length)
    {
        size_t capacity = LengthToCapacity(length);
        void* buffer = sk_malloc_throw(sizeof(SkBufferBlock) + capacity);
        return new (buffer) SkBufferBlock(capacity);
    }

    // Return number of bytes actually appended. Important that we always completely this block
    // before spilling into the next, since the reader uses fCapacity to know how many it can read.
    //
    size_t append(const void* src, size_t length)
    {
=======
    SkBufferBlock*  fNext;
    size_t          fUsed;
    size_t          fCapacity;
    
    const void* startData() const { return this + 1; };
    
    size_t avail() const { return fCapacity - fUsed; }
    void* availData() { return (char*)this->startData() + fUsed; }
    
    static SkBufferBlock* Alloc(size_t length) {
        size_t capacity = LengthToCapacity(length);
        SkBufferBlock* block = (SkBufferBlock*)sk_malloc_throw(sizeof(SkBufferBlock) + capacity);
        block->fNext = NULL;
        block->fUsed = 0;
        block->fCapacity = capacity;
        return block;
    }

    // Return number of bytes actually appended
    size_t append(const void* src, size_t length) {
>>>>>>> miniblink49
        this->validate();
        size_t amount = SkTMin(this->avail(), length);
        memcpy(this->availData(), src, amount);
        fUsed += amount;
        this->validate();
        return amount;
    }

<<<<<<< HEAD
    // Do not call in the reader thread, since the writer may be updating fUsed.
    // (The assertion is still true, but TSAN still may complain about its raciness.)
    void validate() const
    {
=======
    void validate() const {
>>>>>>> miniblink49
#ifdef SK_DEBUG
        SkASSERT(fCapacity > 0);
        SkASSERT(fUsed <= fCapacity);
#endif
    }

private:
<<<<<<< HEAD
    static size_t LengthToCapacity(size_t length)
    {
=======
    static size_t LengthToCapacity(size_t length) {
>>>>>>> miniblink49
        const size_t minSize = kMinAllocSize - sizeof(SkBufferBlock);
        return SkTMax(length, minSize);
    }
};

struct SkBufferHead {
    mutable int32_t fRefCnt;
<<<<<<< HEAD
    SkBufferBlock fBlock;

    SkBufferHead(size_t capacity)
        : fRefCnt(1)
        , fBlock(capacity)
    {
    }

    static size_t LengthToCapacity(size_t length)
    {
=======
    SkBufferBlock   fBlock;

    static size_t LengthToCapacity(size_t length) {
>>>>>>> miniblink49
        const size_t minSize = kMinAllocSize - sizeof(SkBufferHead);
        return SkTMax(length, minSize);
    }

<<<<<<< HEAD
    static SkBufferHead* Alloc(size_t length)
    {
        size_t capacity = LengthToCapacity(length);
        size_t size = sizeof(SkBufferHead) + capacity;
        void* buffer = sk_malloc_throw(size);
        return new (buffer) SkBufferHead(capacity);
    }

    void ref() const
    {
        SkASSERT(fRefCnt > 0);
        sk_atomic_inc(&fRefCnt);
    }

    void unref() const
    {
=======
    static SkBufferHead* Alloc(size_t length) {
        size_t capacity = LengthToCapacity(length);
        size_t size = sizeof(SkBufferHead) + capacity;
        SkBufferHead* head = (SkBufferHead*)sk_malloc_throw(size);
        head->fRefCnt = 1;
        head->fBlock.fNext = NULL;
        head->fBlock.fUsed = 0;
        head->fBlock.fCapacity = capacity;
        return head;
    }
    
    void ref() const {
        SkASSERT(fRefCnt > 0);
        sk_atomic_inc(&fRefCnt);
    }
    
    void unref() const {
>>>>>>> miniblink49
        SkASSERT(fRefCnt > 0);
        // A release here acts in place of all releases we "should" have been doing in ref().
        if (1 == sk_atomic_fetch_add(&fRefCnt, -1, sk_memory_order_acq_rel)) {
            // Like unique(), the acquire is only needed on success.
            SkBufferBlock* block = fBlock.fNext;
            sk_free((void*)this);
            while (block) {
                SkBufferBlock* next = block->fNext;
                sk_free(block);
                block = next;
            }
        }
    }
<<<<<<< HEAD

    void validate(size_t minUsed, const SkBufferBlock* tail = nullptr) const
    {
=======
    
    void validate(size_t minUsed, SkBufferBlock* tail = NULL) const {
>>>>>>> miniblink49
#ifdef SK_DEBUG
        SkASSERT(fRefCnt > 0);
        size_t totalUsed = 0;
        const SkBufferBlock* block = &fBlock;
        const SkBufferBlock* lastBlock = block;
        while (block) {
            block->validate();
            totalUsed += block->fUsed;
            lastBlock = block;
            block = block->fNext;
        }
        SkASSERT(minUsed <= totalUsed);
        if (tail) {
            SkASSERT(tail == lastBlock);
        }
#endif
    }
};

<<<<<<< HEAD
///////////////////////////////////////////////////////////////////////////////////////////////////
// The reader can only access block.fCapacity (which never changes), and cannot access
// block.fUsed, which may be updated by the writer.
//
SkROBuffer::SkROBuffer(const SkBufferHead* head, size_t available, const SkBufferBlock* tail)
    : fHead(head)
    , fAvailable(available)
    , fTail(tail)
{
    if (head) {
        fHead->ref();
        SkASSERT(available > 0);
        head->validate(available, tail);
    } else {
        SkASSERT(0 == available);
        SkASSERT(!tail);
    }
}

SkROBuffer::~SkROBuffer()
{
    if (fHead) {
=======
SkROBuffer::SkROBuffer(const SkBufferHead* head, size_t used) : fHead(head), fUsed(used) {
    if (head) {
        fHead->ref();
        SkASSERT(used > 0);
        head->validate(used);
    } else {
        SkASSERT(0 == used);
    }
}

SkROBuffer::~SkROBuffer() {
    if (fHead) {
        fHead->validate(fUsed);
>>>>>>> miniblink49
        fHead->unref();
    }
}

<<<<<<< HEAD
SkROBuffer::Iter::Iter(const SkROBuffer* buffer)
{
    this->reset(buffer);
}

void SkROBuffer::Iter::reset(const SkROBuffer* buffer)
{
    fBuffer = buffer;
    if (buffer && buffer->fHead) {
        fBlock = &buffer->fHead->fBlock;
        fRemaining = buffer->fAvailable;
    } else {
        fBlock = nullptr;
=======
SkROBuffer::Iter::Iter(const SkROBuffer* buffer) {
    this->reset(buffer);
}

void SkROBuffer::Iter::reset(const SkROBuffer* buffer) {
    if (buffer) {
        fBlock = &buffer->fHead->fBlock;
        fRemaining = buffer->fUsed;
    } else {
        fBlock = NULL;
>>>>>>> miniblink49
        fRemaining = 0;
    }
}

<<<<<<< HEAD
const void* SkROBuffer::Iter::data() const
{
    return fRemaining ? fBlock->startData() : nullptr;
}

size_t SkROBuffer::Iter::size() const
{
    if (!fBlock) {
        return 0;
    }
    return SkTMin(fBlock->fCapacity, fRemaining);
}

bool SkROBuffer::Iter::next()
{
    if (fRemaining) {
        fRemaining -= this->size();
        if (fBuffer->fTail == fBlock) {
            // There are more blocks, but fBuffer does not know about them.
            SkASSERT(0 == fRemaining);
            fBlock = nullptr;
        } else {
            fBlock = fBlock->fNext;
        }
=======
const void* SkROBuffer::Iter::data() const {
    return fRemaining ? fBlock->startData() : NULL;
}

size_t SkROBuffer::Iter::size() const {
    return SkTMin(fBlock->fUsed, fRemaining);
}

bool SkROBuffer::Iter::next() {
    if (fRemaining) {
        fRemaining -= this->size();
        fBlock = fBlock->fNext;
>>>>>>> miniblink49
    }
    return fRemaining != 0;
}

<<<<<<< HEAD
///////////////////////////////////////////////////////////////////////////////////////////////////

SkRWBuffer::SkRWBuffer(size_t initialCapacity)
    : fHead(nullptr)
    , fTail(nullptr)
    , fTotalUsed(0)
{
}

SkRWBuffer::~SkRWBuffer()
{
    this->validate();
    if (fHead) {
        fHead->unref();
    }
}

// It is important that we always completely fill the current block before spilling over to the
// next, since our reader will be using fCapacity (min'd against its total available) to know how
// many bytes to read from a given block.
//
void SkRWBuffer::append(const void* src, size_t length)
{
=======
SkRWBuffer::SkRWBuffer(size_t initialCapacity) : fHead(NULL), fTail(NULL), fTotalUsed(0) {}

SkRWBuffer::~SkRWBuffer() {
    this->validate();
    fHead->unref();
}

void SkRWBuffer::append(const void* src, size_t length) {
>>>>>>> miniblink49
    this->validate();
    if (0 == length) {
        return;
    }

    fTotalUsed += length;

<<<<<<< HEAD
    if (nullptr == fHead) {
=======
    if (NULL == fHead) {
>>>>>>> miniblink49
        fHead = SkBufferHead::Alloc(length);
        fTail = &fHead->fBlock;
    }

    size_t written = fTail->append(src, length);
    SkASSERT(written <= length);
    src = (const char*)src + written;
    length -= written;

    if (length) {
        SkBufferBlock* block = SkBufferBlock::Alloc(length);
        fTail->fNext = block;
        fTail = block;
        written = fTail->append(src, length);
        SkASSERT(written == length);
    }
    this->validate();
}

<<<<<<< HEAD
#ifdef SK_DEBUG
void SkRWBuffer::validate() const
{
    if (fHead) {
        fHead->validate(fTotalUsed, fTail);
    } else {
        SkASSERT(nullptr == fTail);
=======
void* SkRWBuffer::append(size_t length) {
    this->validate();
    if (0 == length) {
        return NULL;
    }

    fTotalUsed += length;
    
    if (NULL == fHead) {
        fHead = SkBufferHead::Alloc(length);
        fTail = &fHead->fBlock;
    } else if (fTail->avail() < length) {
        SkBufferBlock* block = SkBufferBlock::Alloc(length);
        fTail->fNext = block;
        fTail = block;
    }

    fTail->fUsed += length;
    this->validate();
    return (char*)fTail->availData() - length;
}

#ifdef SK_DEBUG
void SkRWBuffer::validate() const {
    if (fHead) {
        fHead->validate(fTotalUsed, fTail);
    } else {
        SkASSERT(NULL == fTail);
>>>>>>> miniblink49
        SkASSERT(0 == fTotalUsed);
    }
}
#endif

<<<<<<< HEAD
SkROBuffer* SkRWBuffer::newRBufferSnapshot() const
{
    return new SkROBuffer(fHead, fTotalUsed, fTail);
=======
SkROBuffer* SkRWBuffer::newRBufferSnapshot() const {
    return SkNEW_ARGS(SkROBuffer, (fHead, fTotalUsed));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////////////////////////

class SkROBufferStreamAsset : public SkStreamAsset {
<<<<<<< HEAD
    void validate() const
    {
=======
    void validate() const {
>>>>>>> miniblink49
#ifdef SK_DEBUG
        SkASSERT(fGlobalOffset <= fBuffer->size());
        SkASSERT(fLocalOffset <= fIter.size());
        SkASSERT(fLocalOffset <= fGlobalOffset);
#endif
    }

#ifdef SK_DEBUG
    class AutoValidate {
        SkROBufferStreamAsset* fStream;
<<<<<<< HEAD

    public:
        AutoValidate(SkROBufferStreamAsset* stream)
            : fStream(stream)
        {
            stream->validate();
        }
        ~AutoValidate() { fStream->validate(); }
    };
#define AUTO_VALIDATE AutoValidate av(this);
#else
#define AUTO_VALIDATE
#endif

public:
    SkROBufferStreamAsset(const SkROBuffer* buffer)
        : fBuffer(SkRef(buffer))
        , fIter(buffer)
    {
=======
    public:
        AutoValidate(SkROBufferStreamAsset* stream) : fStream(stream) { stream->validate(); }
        ~AutoValidate() { fStream->validate(); }
    };
    #define AUTO_VALIDATE   AutoValidate av(this);
#else
    #define AUTO_VALIDATE
#endif

public:
    SkROBufferStreamAsset(const SkROBuffer* buffer) : fBuffer(SkRef(buffer)), fIter(buffer) {
>>>>>>> miniblink49
        fGlobalOffset = fLocalOffset = 0;
    }

    virtual ~SkROBufferStreamAsset() { fBuffer->unref(); }

    size_t getLength() const override { return fBuffer->size(); }

<<<<<<< HEAD
    bool rewind() override
    {
=======
    bool rewind() override {
>>>>>>> miniblink49
        AUTO_VALIDATE
        fIter.reset(fBuffer);
        fGlobalOffset = fLocalOffset = 0;
        return true;
    }

<<<<<<< HEAD
    size_t read(void* dst, size_t request) override
    {
=======
    size_t read(void* dst, size_t request) override {
>>>>>>> miniblink49
        AUTO_VALIDATE
        size_t bytesRead = 0;
        for (;;) {
            size_t size = fIter.size();
            SkASSERT(fLocalOffset <= size);
            size_t avail = SkTMin(size - fLocalOffset, request - bytesRead);
            if (dst) {
                memcpy(dst, (const char*)fIter.data() + fLocalOffset, avail);
                dst = (char*)dst + avail;
            }
            bytesRead += avail;
            fLocalOffset += avail;
            SkASSERT(bytesRead <= request);
            if (bytesRead == request) {
                break;
            }
            // If we get here, we've exhausted the current iter
            SkASSERT(fLocalOffset == size);
            fLocalOffset = 0;
            if (!fIter.next()) {
<<<<<<< HEAD
                break; // ran out of data
=======
                break;   // ran out of data
>>>>>>> miniblink49
            }
        }
        fGlobalOffset += bytesRead;
        SkASSERT(fGlobalOffset <= fBuffer->size());
        return bytesRead;
    }

<<<<<<< HEAD
    bool isAtEnd() const override
    {
        return fBuffer->size() == fGlobalOffset;
    }

    SkStreamAsset* duplicate() const override { return new SkROBufferStreamAsset(fBuffer); }

    size_t getPosition() const override
    {
        return fGlobalOffset;
    }

    bool seek(size_t position) override
    {
=======
    bool isAtEnd() const override {
        return fBuffer->size() == fGlobalOffset;
    }
    
    SkStreamAsset* duplicate() const override {
        return SkNEW_ARGS(SkROBufferStreamAsset, (fBuffer));
    }
    
    size_t getPosition() const {
        return fGlobalOffset;
    }
    
    bool seek(size_t position) {
>>>>>>> miniblink49
        AUTO_VALIDATE
        if (position < fGlobalOffset) {
            this->rewind();
        }
        (void)this->skip(position - fGlobalOffset);
        return true;
    }
<<<<<<< HEAD

    bool move(long offset) override
    {
=======
    
    bool move(long offset) {
>>>>>>> miniblink49
        AUTO_VALIDATE
        offset += fGlobalOffset;
        if (offset <= 0) {
            this->rewind();
        } else {
            (void)this->seek(SkToSizeT(offset));
        }
        return true;
    }
<<<<<<< HEAD

    SkStreamAsset* fork() const override
    {
=======
    
    SkStreamAsset* fork() const override {
>>>>>>> miniblink49
        SkStreamAsset* clone = this->duplicate();
        clone->seek(this->getPosition());
        return clone;
    }
<<<<<<< HEAD

private:
    const SkROBuffer* fBuffer;
    SkROBuffer::Iter fIter;
    size_t fLocalOffset;
    size_t fGlobalOffset;
};

SkStreamAsset* SkRWBuffer::newStreamSnapshot() const
{
    SkAutoTUnref<SkROBuffer> buffer(this->newRBufferSnapshot());
    return new SkROBufferStreamAsset(buffer);
=======
    

private:
    const SkROBuffer*   fBuffer;
    SkROBuffer::Iter    fIter;
    size_t              fLocalOffset;
    size_t              fGlobalOffset;
};

SkStreamAsset* SkRWBuffer::newStreamSnapshot() const {
    SkAutoTUnref<SkROBuffer> buffer(this->newRBufferSnapshot());
    return SkNEW_ARGS(SkROBufferStreamAsset, (buffer));
>>>>>>> miniblink49
}
