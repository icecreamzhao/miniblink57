
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDeque_DEFINED
#define SkDeque_DEFINED

#include "SkTypes.h"

/*
 * The deque class works by blindly creating memory space of a specified element
 * size. It manages the memory as a doubly linked list of blocks each of which
 * can contain multiple elements. Pushes and pops add/remove blocks from the
 * beginning/end of the list as necessary while each block tracks the used
 * portion of its memory.
 * One behavior to be aware of is that the pops do not immediately remove an
 * empty block from the beginning/end of the list (Presumably so push/pop pairs
 * on the block boundaries don't cause thrashing). This can result in the first/
 * last element not residing in the first/last block.
 */
class SK_API SkDeque : SkNoncopyable {
public:
    /**
     * elemSize specifies the size of each individual element in the deque
     * allocCount specifies how many elements are to be allocated as a block
     */
    explicit SkDeque(size_t elemSize, int allocCount = 1);
    SkDeque(size_t elemSize, void* storage, size_t storageSize, int allocCount = 1);
    ~SkDeque();

<<<<<<< HEAD
    bool empty() const { return 0 == fCount; }
    int count() const { return fCount; }
    size_t elemSize() const { return fElemSize; }

    const void* front() const { return fFront; }
    const void* back() const { return fBack; }

    void* front()
    {
        return (void*)((const SkDeque*)this)->front();
    }

    void* back()
    {
=======
    bool    empty() const { return 0 == fCount; }
    int     count() const { return fCount; }
    size_t  elemSize() const { return fElemSize; }

    const void* front() const { return fFront; }
    const void* back() const  { return fBack; }

    void* front() {
        return (void*)((const SkDeque*)this)->front();
    }

    void* back() {
>>>>>>> miniblink49
        return (void*)((const SkDeque*)this)->back();
    }

    /**
     * push_front and push_back return a pointer to the memory space
     * for the new element
     */
    void* push_front();
    void* push_back();

    void pop_front();
    void pop_back();

private:
    struct Block;

public:
    class Iter {
    public:
        enum IterStart {
            kFront_IterStart,
            kBack_IterStart
        };

        /**
         * Creates an uninitialized iterator. Must be reset()
         */
        Iter();

        Iter(const SkDeque& d, IterStart startLoc);
        void* next();
        void* prev();

        void reset(const SkDeque& d, IterStart startLoc);

    private:
        SkDeque::Block* fCurBlock;
<<<<<<< HEAD
        char* fPos;
        size_t fElemSize;
=======
        char*           fPos;
        size_t          fElemSize;
>>>>>>> miniblink49
    };

    // Inherit privately from Iter to prevent access to reverse iteration
    class F2BIter : private Iter {
    public:
<<<<<<< HEAD
        F2BIter() { }
=======
        F2BIter() {}
>>>>>>> miniblink49

        /**
         * Wrap Iter's 2 parameter ctor to force initialization to the
         * beginning of the deque
         */
<<<<<<< HEAD
        F2BIter(const SkDeque& d)
            : INHERITED(d, kFront_IterStart)
        {
        }
=======
        F2BIter(const SkDeque& d) : INHERITED(d, kFront_IterStart) {}
>>>>>>> miniblink49

        using Iter::next;

        /**
         * Wrap Iter::reset to force initialization to the beginning of the
         * deque
         */
<<<<<<< HEAD
        void reset(const SkDeque& d)
        {
=======
        void reset(const SkDeque& d) {
>>>>>>> miniblink49
            this->INHERITED::reset(d, kFront_IterStart);
        }

    private:
        typedef Iter INHERITED;
    };

private:
    // allow unit test to call numBlocksAllocated
    friend class DequeUnitTestHelper;

<<<<<<< HEAD
    void* fFront;
    void* fBack;

    Block* fFrontBlock;
    Block* fBackBlock;
    size_t fElemSize;
    void* fInitialStorage;
    int fCount; // number of elements in the deque
    int fAllocCount; // number of elements to allocate per block

    Block* allocateBlock(int allocCount);
    void freeBlock(Block* block);
=======
    void*   fFront;
    void*   fBack;

    Block*  fFrontBlock;
    Block*  fBackBlock;
    size_t  fElemSize;
    void*   fInitialStorage;
    int     fCount;             // number of elements in the deque
    int     fAllocCount;        // number of elements to allocate per block

    Block*  allocateBlock(int allocCount);
    void    freeBlock(Block* block);
>>>>>>> miniblink49

    /**
     * This returns the number of chunk blocks allocated by the deque. It
     * can be used to gauge the effectiveness of the selected allocCount.
     */
<<<<<<< HEAD
    int numBlocksAllocated() const;
=======
    int  numBlocksAllocated() const;
>>>>>>> miniblink49
};

#endif
