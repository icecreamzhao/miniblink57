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
#include "SkDeque.h"

struct SkDeque::Block {
    Block* fNext;
    Block* fPrev;
    char* fBegin; // start of used section in this chunk
    char* fEnd; // end of used section in this chunk
    char* fStop; // end of the allocated chunk

    char* start() { return (char*)(this + 1); }
    const char* start() const { return (const char*)(this + 1); }

    void init(size_t size)
    {
        fNext = fPrev = nullptr;
        fBegin = fEnd = nullptr;
        fStop = (char*)this + size;
=======

#include "SkDeque.h"

struct SkDeque::Block {
    Block*  fNext;
    Block*  fPrev;
    char*   fBegin; // start of used section in this chunk
    char*   fEnd;   // end of used section in this chunk
    char*   fStop;  // end of the allocated chunk

    char*       start() { return (char*)(this + 1); }
    const char* start() const { return (const char*)(this + 1); }

    void init(size_t size) {
        fNext   = fPrev = NULL;
        fBegin  = fEnd = NULL;
        fStop   = (char*)this + size;
>>>>>>> miniblink49
    }
};

SkDeque::SkDeque(size_t elemSize, int allocCount)
<<<<<<< HEAD
    : fElemSize(elemSize)
    , fInitialStorage(nullptr)
    , fCount(0)
    , fAllocCount(allocCount)
{
    SkASSERT(allocCount >= 1);
    fFrontBlock = fBackBlock = nullptr;
    fFront = fBack = nullptr;
}

SkDeque::SkDeque(size_t elemSize, void* storage, size_t storageSize, int allocCount)
    : fElemSize(elemSize)
    , fInitialStorage(storage)
    , fCount(0)
    , fAllocCount(allocCount)
{
    SkASSERT(storageSize == 0 || storage != nullptr);
=======
        : fElemSize(elemSize)
        , fInitialStorage(NULL)
        , fCount(0)
        , fAllocCount(allocCount) {
    SkASSERT(allocCount >= 1);
    fFrontBlock = fBackBlock = NULL;
    fFront = fBack = NULL;
}

SkDeque::SkDeque(size_t elemSize, void* storage, size_t storageSize, int allocCount)
        : fElemSize(elemSize)
        , fInitialStorage(storage)
        , fCount(0)
        , fAllocCount(allocCount) {
    SkASSERT(storageSize == 0 || storage != NULL);
>>>>>>> miniblink49
    SkASSERT(allocCount >= 1);

    if (storageSize >= sizeof(Block) + elemSize) {
        fFrontBlock = (Block*)storage;
        fFrontBlock->init(storageSize);
    } else {
<<<<<<< HEAD
        fFrontBlock = nullptr;
    }
    fBackBlock = fFrontBlock;
    fFront = fBack = nullptr;
}

SkDeque::~SkDeque()
{
=======
        fFrontBlock = NULL;
    }
    fBackBlock = fFrontBlock;
    fFront = fBack = NULL;
}

SkDeque::~SkDeque() {
>>>>>>> miniblink49
    Block* head = fFrontBlock;
    Block* initialHead = (Block*)fInitialStorage;

    while (head) {
        Block* next = head->fNext;
        if (head != initialHead) {
            this->freeBlock(head);
        }
        head = next;
    }
}

<<<<<<< HEAD
void* SkDeque::push_front()
{
    fCount += 1;

    if (nullptr == fFrontBlock) {
        fFrontBlock = this->allocateBlock(fAllocCount);
        fBackBlock = fFrontBlock; // update our linklist
    }

    Block* first = fFrontBlock;
    char* begin;

    if (nullptr == first->fBegin) {
=======
void* SkDeque::push_front() {
    fCount += 1;

    if (NULL == fFrontBlock) {
        fFrontBlock = this->allocateBlock(fAllocCount);
        fBackBlock = fFrontBlock;     // update our linklist
    }

    Block*  first = fFrontBlock;
    char*   begin;

    if (NULL == first->fBegin) {
>>>>>>> miniblink49
    INIT_CHUNK:
        first->fEnd = first->fStop;
        begin = first->fStop - fElemSize;
    } else {
        begin = first->fBegin - fElemSize;
<<<<<<< HEAD
        if (begin < first->start()) { // no more room in this chunk
=======
        if (begin < first->start()) {    // no more room in this chunk
>>>>>>> miniblink49
            // should we alloc more as we accumulate more elements?
            first = this->allocateBlock(fAllocCount);
            first->fNext = fFrontBlock;
            fFrontBlock->fPrev = first;
            fFrontBlock = first;
            goto INIT_CHUNK;
        }
    }

    first->fBegin = begin;

<<<<<<< HEAD
    if (nullptr == fFront) {
        SkASSERT(nullptr == fBack);
=======
    if (NULL == fFront) {
        SkASSERT(NULL == fBack);
>>>>>>> miniblink49
        fFront = fBack = begin;
    } else {
        SkASSERT(fBack);
        fFront = begin;
    }

    return begin;
}

<<<<<<< HEAD
void* SkDeque::push_back()
{
    fCount += 1;

    if (nullptr == fBackBlock) {
=======
void* SkDeque::push_back() {
    fCount += 1;

    if (NULL == fBackBlock) {
>>>>>>> miniblink49
        fBackBlock = this->allocateBlock(fAllocCount);
        fFrontBlock = fBackBlock; // update our linklist
    }

<<<<<<< HEAD
    Block* last = fBackBlock;
    char* end;

    if (nullptr == last->fBegin) {
=======
    Block*  last = fBackBlock;
    char*   end;

    if (NULL == last->fBegin) {
>>>>>>> miniblink49
    INIT_CHUNK:
        last->fBegin = last->start();
        end = last->fBegin + fElemSize;
    } else {
        end = last->fEnd + fElemSize;
<<<<<<< HEAD
        if (end > last->fStop) { // no more room in this chunk
=======
        if (end > last->fStop) {  // no more room in this chunk
>>>>>>> miniblink49
            // should we alloc more as we accumulate more elements?
            last = this->allocateBlock(fAllocCount);
            last->fPrev = fBackBlock;
            fBackBlock->fNext = last;
            fBackBlock = last;
            goto INIT_CHUNK;
        }
    }

    last->fEnd = end;
    end -= fElemSize;

<<<<<<< HEAD
    if (nullptr == fBack) {
        SkASSERT(nullptr == fFront);
=======
    if (NULL == fBack) {
        SkASSERT(NULL == fFront);
>>>>>>> miniblink49
        fFront = fBack = end;
    } else {
        SkASSERT(fFront);
        fBack = end;
    }

    return end;
}

<<<<<<< HEAD
void SkDeque::pop_front()
{
    SkASSERT(fCount > 0);
    fCount -= 1;

    Block* first = fFrontBlock;

    SkASSERT(first != nullptr);

    if (first->fBegin == nullptr) { // we were marked empty from before
        first = first->fNext;
        first->fPrev = nullptr;
        this->freeBlock(fFrontBlock);
        fFrontBlock = first;
        SkASSERT(first != nullptr); // else we popped too far
=======
void SkDeque::pop_front() {
    SkASSERT(fCount > 0);
    fCount -= 1;

    Block*  first = fFrontBlock;

    SkASSERT(first != NULL);

    if (first->fBegin == NULL) {  // we were marked empty from before
        first = first->fNext;
        first->fPrev = NULL;
        this->freeBlock(fFrontBlock);
        fFrontBlock = first;
        SkASSERT(first != NULL);    // else we popped too far
>>>>>>> miniblink49
    }

    char* begin = first->fBegin + fElemSize;
    SkASSERT(begin <= first->fEnd);

    if (begin < fFrontBlock->fEnd) {
        first->fBegin = begin;
        SkASSERT(first->fBegin);
        fFront = first->fBegin;
    } else {
<<<<<<< HEAD
        first->fBegin = first->fEnd = nullptr; // mark as empty
        if (nullptr == first->fNext) {
            fFront = fBack = nullptr;
=======
        first->fBegin = first->fEnd = NULL;  // mark as empty
        if (NULL == first->fNext) {
            fFront = fBack = NULL;
>>>>>>> miniblink49
        } else {
            SkASSERT(first->fNext->fBegin);
            fFront = first->fNext->fBegin;
        }
    }
}

<<<<<<< HEAD
void SkDeque::pop_back()
{
=======
void SkDeque::pop_back() {
>>>>>>> miniblink49
    SkASSERT(fCount > 0);
    fCount -= 1;

    Block* last = fBackBlock;

<<<<<<< HEAD
    SkASSERT(last != nullptr);

    if (last->fEnd == nullptr) { // we were marked empty from before
        last = last->fPrev;
        last->fNext = nullptr;
        this->freeBlock(fBackBlock);
        fBackBlock = last;
        SkASSERT(last != nullptr); // else we popped too far
=======
    SkASSERT(last != NULL);

    if (last->fEnd == NULL) {  // we were marked empty from before
        last = last->fPrev;
        last->fNext = NULL;
        this->freeBlock(fBackBlock);
        fBackBlock = last;
        SkASSERT(last != NULL);  // else we popped too far
>>>>>>> miniblink49
    }

    char* end = last->fEnd - fElemSize;
    SkASSERT(end >= last->fBegin);

    if (end > last->fBegin) {
        last->fEnd = end;
        SkASSERT(last->fEnd);
        fBack = last->fEnd - fElemSize;
    } else {
<<<<<<< HEAD
        last->fBegin = last->fEnd = nullptr; // mark as empty
        if (nullptr == last->fPrev) {
            fFront = fBack = nullptr;
=======
        last->fBegin = last->fEnd = NULL;    // mark as empty
        if (NULL == last->fPrev) {
            fFront = fBack = NULL;
>>>>>>> miniblink49
        } else {
            SkASSERT(last->fPrev->fEnd);
            fBack = last->fPrev->fEnd - fElemSize;
        }
    }
}

<<<<<<< HEAD
int SkDeque::numBlocksAllocated() const
{
=======
int SkDeque::numBlocksAllocated() const {
>>>>>>> miniblink49
    int numBlocks = 0;

    for (const Block* temp = fFrontBlock; temp; temp = temp->fNext) {
        ++numBlocks;
    }

    return numBlocks;
}

<<<<<<< HEAD
SkDeque::Block* SkDeque::allocateBlock(int allocCount)
{
=======
SkDeque::Block* SkDeque::allocateBlock(int allocCount) {
>>>>>>> miniblink49
    Block* newBlock = (Block*)sk_malloc_throw(sizeof(Block) + allocCount * fElemSize);
    newBlock->init(sizeof(Block) + allocCount * fElemSize);
    return newBlock;
}

<<<<<<< HEAD
void SkDeque::freeBlock(Block* block)
{
=======
void SkDeque::freeBlock(Block* block) {
>>>>>>> miniblink49
    sk_free(block);
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkDeque::Iter::Iter()
    : fCurBlock(nullptr)
    , fPos(nullptr)
    , fElemSize(0)
{
}

SkDeque::Iter::Iter(const SkDeque& d, IterStart startLoc)
{
=======
SkDeque::Iter::Iter() : fCurBlock(NULL), fPos(NULL), fElemSize(0) {}

SkDeque::Iter::Iter(const SkDeque& d, IterStart startLoc) {
>>>>>>> miniblink49
    this->reset(d, startLoc);
}

// Due to how reset and next work, next actually returns the current element
// pointed to by fPos and then updates fPos to point to the next one.
<<<<<<< HEAD
void* SkDeque::Iter::next()
{
    char* pos = fPos;

    if (pos) { // if we were valid, try to move to the next setting
=======
void* SkDeque::Iter::next() {
    char* pos = fPos;

    if (pos) {   // if we were valid, try to move to the next setting
>>>>>>> miniblink49
        char* next = pos + fElemSize;
        SkASSERT(next <= fCurBlock->fEnd);
        if (next == fCurBlock->fEnd) { // exhausted this chunk, move to next
            do {
                fCurBlock = fCurBlock->fNext;
<<<<<<< HEAD
            } while (fCurBlock != nullptr && fCurBlock->fBegin == nullptr);
            next = fCurBlock ? fCurBlock->fBegin : nullptr;
=======
            } while (fCurBlock != NULL && fCurBlock->fBegin == NULL);
            next = fCurBlock ? fCurBlock->fBegin : NULL;
>>>>>>> miniblink49
        }
        fPos = next;
    }
    return pos;
}

// Like next, prev actually returns the current element pointed to by fPos and
// then makes fPos point to the previous element.
<<<<<<< HEAD
void* SkDeque::Iter::prev()
{
    char* pos = fPos;

    if (pos) { // if we were valid, try to move to the prior setting
=======
void* SkDeque::Iter::prev() {
    char* pos = fPos;

    if (pos) {   // if we were valid, try to move to the prior setting
>>>>>>> miniblink49
        char* prev = pos - fElemSize;
        SkASSERT(prev >= fCurBlock->fBegin - fElemSize);
        if (prev < fCurBlock->fBegin) { // exhausted this chunk, move to prior
            do {
                fCurBlock = fCurBlock->fPrev;
<<<<<<< HEAD
            } while (fCurBlock != nullptr && fCurBlock->fEnd == nullptr);
            prev = fCurBlock ? fCurBlock->fEnd - fElemSize : nullptr;
=======
            } while (fCurBlock != NULL && fCurBlock->fEnd == NULL);
            prev = fCurBlock ? fCurBlock->fEnd - fElemSize : NULL;
>>>>>>> miniblink49
        }
        fPos = prev;
    }
    return pos;
}

// reset works by skipping through the spare blocks at the start (or end)
// of the doubly linked list until a non-empty one is found. The fPos
// member is then set to the first (or last) element in the block. If
// there are no elements in the deque both fCurBlock and fPos will come
<<<<<<< HEAD
// out of this routine nullptr.
void SkDeque::Iter::reset(const SkDeque& d, IterStart startLoc)
{
=======
// out of this routine NULL.
void SkDeque::Iter::reset(const SkDeque& d, IterStart startLoc) {
>>>>>>> miniblink49
    fElemSize = d.fElemSize;

    if (kFront_IterStart == startLoc) {
        // initialize the iterator to start at the front
        fCurBlock = d.fFrontBlock;
<<<<<<< HEAD
        while (fCurBlock && nullptr == fCurBlock->fBegin) {
            fCurBlock = fCurBlock->fNext;
        }
        fPos = fCurBlock ? fCurBlock->fBegin : nullptr;
    } else {
        // initialize the iterator to start at the back
        fCurBlock = d.fBackBlock;
        while (fCurBlock && nullptr == fCurBlock->fEnd) {
            fCurBlock = fCurBlock->fPrev;
        }
        fPos = fCurBlock ? fCurBlock->fEnd - fElemSize : nullptr;
=======
        while (fCurBlock && NULL == fCurBlock->fBegin) {
            fCurBlock = fCurBlock->fNext;
        }
        fPos = fCurBlock ? fCurBlock->fBegin : NULL;
    } else {
        // initialize the iterator to start at the back
        fCurBlock = d.fBackBlock;
        while (fCurBlock && NULL == fCurBlock->fEnd) {
            fCurBlock = fCurBlock->fPrev;
        }
        fPos = fCurBlock ? fCurBlock->fEnd - fElemSize : NULL;
>>>>>>> miniblink49
    }
}
