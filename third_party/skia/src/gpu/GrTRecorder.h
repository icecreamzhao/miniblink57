/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrTRecorder_DEFINED
#define GrTRecorder_DEFINED

<<<<<<< HEAD
#include "SkTypes.h"

template <typename TBase, typename TAlign>
class GrTRecorder;
template <typename TItem>
struct GrTRecorderAllocWrapper;
=======
#include "SkTemplates.h"
#include "SkTypes.h"

template<typename TBase, typename TAlign> class GrTRecorder;
template<typename TItem> struct GrTRecorderAllocWrapper;
>>>>>>> miniblink49

/**
 * Records a list of items with a common base type, optional associated data, and
 * permanent memory addresses.
 *
 * This class preallocates its own chunks of memory for hosting objects, so new items can
 * be created without excessive calls to malloc().
 *
 * To create a new item and append it to the back of the list, use the following macros:
 *
 *     GrNEW_APPEND_TO_RECORDER(recorder, SubclassName, (args))
 *     GrNEW_APPEND_WITH_DATA_TO_RECORDER(recorder, SubclassName, (args), sizeOfData)
 *
 * Upon reset or delete, the items are destructed in the same order they were received,
 * not reverse (stack) order.
 *
 * @param TBase   Common base type of items in the list. If TBase is not a class with a
 *                virtual destructor, the client is responsible for invoking any necessary
 *                destructors.
 *
 *                For now, any subclass used in the list must have the same start address
 *                as TBase (or in other words, the types must be convertible via
 *                reinterpret_cast<>). Classes with multiple inheritance (or any subclass
 *                on an obscure compiler) may not be compatible. This is runtime asserted
 *                in debug builds.
 *
 * @param TAlign  A type whose size is the desired memory alignment for object allocations.
 *                This should be the largest known alignment requirement for all objects
 *                that may be stored in the list.
 */
<<<<<<< HEAD
template <typename TBase, typename TAlign>
class GrTRecorder : SkNoncopyable {
=======
template<typename TBase, typename TAlign> class GrTRecorder : SkNoncopyable {
>>>>>>> miniblink49
public:
    class Iter;
    class ReverseIter;

    /**
     * Create a recorder.
     *
     * @param initialSizeInBytes  The amount of memory reserved by the recorder initially,
                                  and after calls to reset().
     */
    GrTRecorder(int initialSizeInBytes)
<<<<<<< HEAD
        : fHeadBlock(MemBlock::Alloc(LengthOf(initialSizeInBytes), nullptr))
        , fTailBlock(fHeadBlock)
        , fLastItem(nullptr)
    {
    }

    ~GrTRecorder()
    {
=======
        : fHeadBlock(MemBlock::Alloc(LengthOf(initialSizeInBytes), NULL)),
          fTailBlock(fHeadBlock),
          fLastItem(NULL) {}

    ~GrTRecorder() {
>>>>>>> miniblink49
        this->reset();
        MemBlock::Free(fHeadBlock);
    }

    bool empty() { return !fLastItem; }

<<<<<<< HEAD
    TBase& back()
    {
        SkASSERT(!this->empty());
        return *reinterpret_cast<TBase*>(fLastItem);
=======
    TBase& back() {
        SkASSERT(!this->empty());
        return *fLastItem;
>>>>>>> miniblink49
    }

    /**
     * Removes and destroys the last block added to the recorder. It may not be called when the
     * recorder is empty.
     */
    void pop_back();

    /**
     * Destruct all items in the list and reset to empty.
     */
    void reset();

    /**
     * Retrieve the extra data associated with an item that was allocated using
     * GrNEW_APPEND_WITH_DATA_TO_RECORDER().
     *
     * @param item  The item whose data to retrieve. The pointer must be of the same type
     *              that was allocated initally; it can't be a pointer to a base class.
     *
     * @return The item's associated data.
     */
<<<<<<< HEAD
    template <typename TItem>
    static const void* GetDataForItem(const TItem* item)
    {
        const TAlign* ptr = reinterpret_cast<const TAlign*>(item);
        return &ptr[length_of<TItem>::kValue];
    }
    template <typename TItem>
    static void* GetDataForItem(TItem* item)
    {
=======
    template<typename TItem> static const void* GetDataForItem(const TItem* item) {
        const TAlign* ptr = reinterpret_cast<const TAlign*>(item);
        return &ptr[length_of<TItem>::kValue];
    }
    template<typename TItem> static void* GetDataForItem(TItem* item) {
>>>>>>> miniblink49
        TAlign* ptr = reinterpret_cast<TAlign*>(item);
        return &ptr[length_of<TItem>::kValue];
    }

private:
<<<<<<< HEAD
    template <typename TItem>
    struct length_of {
=======
    template<typename TItem> struct length_of {
>>>>>>> miniblink49
        enum { kValue = (sizeof(TItem) + sizeof(TAlign) - 1) / sizeof(TAlign) };
    };
    static int LengthOf(int bytes) { return (bytes + sizeof(TAlign) - 1) / sizeof(TAlign); }

    struct Header {
        int fTotalLength; // The length of an entry including header, item, and data in TAligns.
<<<<<<< HEAD
        int fPrevLength; // Same but for the previous entry. Used for iterating backwards.
    };
    template <typename TItem>
    void* alloc_back(int dataLength);

    struct MemBlock : SkNoncopyable {
        /** Allocates a new block and appends it to prev if not nullptr. The length param is in units
            of TAlign. */
        static MemBlock* Alloc(int length, MemBlock* prev)
        {
=======
        int fPrevLength;  // Same but for the previous entry. Used for iterating backwards.
    };
    template<typename TItem> TItem* alloc_back(int dataLength);

    struct MemBlock : SkNoncopyable {
        /** Allocates a new block and appends it to prev if not NULL. The length param is in units
            of TAlign. */
        static MemBlock* Alloc(int length, MemBlock* prev) {
>>>>>>> miniblink49
            MemBlock* block = reinterpret_cast<MemBlock*>(
                sk_malloc_throw(sizeof(TAlign) * (length_of<MemBlock>::kValue + length)));
            block->fLength = length;
            block->fBack = 0;
<<<<<<< HEAD
            block->fNext = nullptr;
            block->fPrev = prev;
            if (prev) {
                SkASSERT(nullptr == prev->fNext);
=======
            block->fNext = NULL;
            block->fPrev = prev;
            if (prev) {
                SkASSERT(NULL == prev->fNext);
>>>>>>> miniblink49
                prev->fNext = block;
            }
            return block;
        }

        // Frees from this block forward. Also adjusts prev block's next ptr.
<<<<<<< HEAD
        static void Free(MemBlock* block)
        {
            if (block && block->fPrev) {
                SkASSERT(block->fPrev->fNext == block);
                block->fPrev->fNext = nullptr;
=======
        static void Free(MemBlock* block) {
            if (block && block->fPrev) {
                SkASSERT(block->fPrev->fNext == block);
                block->fPrev->fNext = NULL;
>>>>>>> miniblink49
            }
            while (block) {
                MemBlock* next = block->fNext;
                sk_free(block);
                block = next;
            }
        }

<<<<<<< HEAD
        TAlign& operator[](int i)
        {
            return reinterpret_cast<TAlign*>(this)[length_of<MemBlock>::kValue + i];
        }

        int fLength; // Length in units of TAlign of the block.
        int fBack; // Offset, in TAligns, to unused portion of the memory block.
=======
        TAlign& operator [](int i) {
            return reinterpret_cast<TAlign*>(this)[length_of<MemBlock>::kValue + i];
        }

        int       fLength; // Length in units of TAlign of the block.
        int       fBack;   // Offset, in TAligns, to unused portion of the memory block.
>>>>>>> miniblink49
        MemBlock* fNext;
        MemBlock* fPrev;
    };
    MemBlock* const fHeadBlock;
    MemBlock* fTailBlock;

<<<<<<< HEAD
    void* fLastItem; // really a ptr to TBase

    template <typename TItem>
    friend struct GrTRecorderAllocWrapper;

    template <typename UBase, typename UAlign, typename UItem>
    friend void* operator new(size_t, GrTRecorder<UBase, UAlign>&,
        const GrTRecorderAllocWrapper<UItem>&);
=======
    TBase*    fLastItem;

    template<typename TItem> friend struct GrTRecorderAllocWrapper;

    template <typename UBase, typename UAlign, typename UItem>
    friend void* operator new(size_t, GrTRecorder<UBase, UAlign>&,
                              const GrTRecorderAllocWrapper<UItem>&);
>>>>>>> miniblink49

    friend class Iter;
    friend class ReverseIter;
};

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
template <typename TBase, typename TAlign>
void GrTRecorder<TBase, TAlign>::pop_back()
{
=======
template<typename TBase, typename TAlign>
void GrTRecorder<TBase, TAlign>::pop_back() {
>>>>>>> miniblink49
    SkASSERT(fLastItem);
    Header* header = reinterpret_cast<Header*>(
        reinterpret_cast<TAlign*>(fLastItem) - length_of<Header>::kValue);
    fTailBlock->fBack -= header->fTotalLength;
<<<<<<< HEAD
    reinterpret_cast<TBase*>(fLastItem)->~TBase();
=======
    fLastItem->~TBase();
>>>>>>> miniblink49

    int lastItemLength = header->fPrevLength;

    if (!header->fPrevLength) {
        // We popped the first entry in the recorder.
        SkASSERT(0 == fTailBlock->fBack);
<<<<<<< HEAD
        fLastItem = nullptr;
=======
        fLastItem = NULL;
>>>>>>> miniblink49
        return;
    }
    while (!fTailBlock->fBack) {
        // We popped the last entry in a block that isn't the head block. Move back a block but
        // don't free it since we'll probably grow into it shortly.
        fTailBlock = fTailBlock->fPrev;
        SkASSERT(fTailBlock);
    }
<<<<<<< HEAD
    fLastItem = &(*fTailBlock)[fTailBlock->fBack - lastItemLength + length_of<Header>::kValue];
}

template <typename TBase, typename TAlign>
template <typename TItem>
void* GrTRecorder<TBase, TAlign>::alloc_back(int dataLength)
{
=======
    fLastItem = reinterpret_cast<TBase*>(
        &(*fTailBlock)[fTailBlock->fBack - lastItemLength + length_of<Header>::kValue]);
}

template<typename TBase, typename TAlign>
template<typename TItem>
TItem* GrTRecorder<TBase, TAlign>::alloc_back(int dataLength) {
>>>>>>> miniblink49
    // Find the header of the previous entry and get its length. We need to store that in the new
    // header for backwards iteration (pop_back()).
    int prevLength = 0;
    if (fLastItem) {
        Header* lastHeader = reinterpret_cast<Header*>(
            reinterpret_cast<TAlign*>(fLastItem) - length_of<Header>::kValue);
        prevLength = lastHeader->fTotalLength;
    }

    const int totalLength = length_of<Header>::kValue + length_of<TItem>::kValue + dataLength;

    // Check if there is room in the current block and if not walk to next (allocating if
    // necessary). Note that pop_back() and reset() can leave the recorder in a state where it
    // has preallocated blocks hanging off the tail that are currently unused.
    while (fTailBlock->fBack + totalLength > fTailBlock->fLength) {
        if (!fTailBlock->fNext) {
            fTailBlock = MemBlock::Alloc(SkTMax(2 * fTailBlock->fLength, totalLength), fTailBlock);
        } else {
            fTailBlock = fTailBlock->fNext;
        }
        SkASSERT(0 == fTailBlock->fBack);
    }

    Header* header = reinterpret_cast<Header*>(&(*fTailBlock)[fTailBlock->fBack]);
<<<<<<< HEAD
    void* rawPtr = &(*fTailBlock)[fTailBlock->fBack + length_of<Header>::kValue];
=======
    TItem* rawPtr = reinterpret_cast<TItem*>(
                        &(*fTailBlock)[fTailBlock->fBack + length_of<Header>::kValue]);
>>>>>>> miniblink49

    header->fTotalLength = totalLength;
    header->fPrevLength = prevLength;
    fLastItem = rawPtr;
    fTailBlock->fBack += totalLength;

    // FIXME: We currently require that the base and subclass share the same start address.
    // This is not required by the C++ spec, and is likely to not be true in the case of
    // multiple inheritance or a base class that doesn't have virtual methods (when the
    // subclass does). It would be ideal to find a more robust solution that comes at no
    // extra cost to performance or code generality.
    SkDEBUGCODE(void* baseAddr = fLastItem;
                void* subclassAddr = rawPtr);
    SkASSERT(baseAddr == subclassAddr);

    return rawPtr;
}

/**
 * Iterates through a recorder from front to back. The initial state of the iterator is
 * to not have the front item loaded yet; next() must be called first. Usage model:
 *
 *    GrTRecorder<TBase, TAlign>::Iter iter(recorder);
 *    while (iter.next()) {
 *        iter->doSomething();
 *    }
 */
<<<<<<< HEAD
template <typename TBase, typename TAlign>
class GrTRecorder<TBase, TAlign>::Iter {
public:
    Iter(GrTRecorder& recorder)
        : fBlock(recorder.fHeadBlock)
        , fPosition(0)
        , fItem(nullptr)
    {
    }

    bool next()
    {
=======
template<typename TBase, typename TAlign>
class GrTRecorder<TBase, TAlign>::Iter {
public:
    Iter(GrTRecorder& recorder) : fBlock(recorder.fHeadBlock), fPosition(0), fItem(NULL) {}

    bool next() {
>>>>>>> miniblink49
        while (fPosition >= fBlock->fBack) {
            SkASSERT(fPosition == fBlock->fBack);
            if (!fBlock->fNext) {
                return false;
            }
            fBlock = fBlock->fNext;
            fPosition = 0;
        }

        Header* header = reinterpret_cast<Header*>(&(*fBlock)[fPosition]);
        fItem = reinterpret_cast<TBase*>(&(*fBlock)[fPosition + length_of<Header>::kValue]);
        fPosition += header->fTotalLength;
        return true;
    }

<<<<<<< HEAD
    TBase* get() const
    {
=======
    TBase* get() const {
>>>>>>> miniblink49
        SkASSERT(fItem);
        return fItem;
    }

    TBase* operator->() const { return this->get(); }

private:
    MemBlock* fBlock;
<<<<<<< HEAD
    int fPosition;
    TBase* fItem;
=======
    int       fPosition;
    TBase*    fItem;
>>>>>>> miniblink49
};

/**
 * Iterates through a recorder in reverse, from back to front. This version mirrors "Iter",
 * so the initial state is to have recorder.back() loaded already. (Note that this will
 * assert if the recorder is empty.) Usage model:
 *
 *    GrTRecorder<TBase, TAlign>::ReverseIter reverseIter(recorder);
 *    do {
 *        reverseIter->doSomething();
 *    } while (reverseIter.previous());
 */
<<<<<<< HEAD
template <typename TBase, typename TAlign>
class GrTRecorder<TBase, TAlign>::ReverseIter {
public:
    ReverseIter(GrTRecorder& recorder)
        : fBlock(recorder.fTailBlock)
        , fItem(&recorder.back())
    {
=======
template<typename TBase, typename TAlign>
class GrTRecorder<TBase, TAlign>::ReverseIter {
public:
    ReverseIter(GrTRecorder& recorder)
        : fBlock(recorder.fTailBlock),
          fItem(&recorder.back()) {
>>>>>>> miniblink49
        Header* lastHeader = reinterpret_cast<Header*>(
            reinterpret_cast<TAlign*>(fItem) - length_of<Header>::kValue);
        fPosition = fBlock->fBack - lastHeader->fTotalLength;
    }

<<<<<<< HEAD
    bool previous()
    {
=======
    bool previous() {
>>>>>>> miniblink49
        Header* header = reinterpret_cast<Header*>(&(*fBlock)[fPosition]);

        while (0 == fPosition) {
            if (!fBlock->fPrev) {
                // We've reached the front of the recorder.
                return false;
            }
            fBlock = fBlock->fPrev;
            fPosition = fBlock->fBack;
        }

        fPosition -= header->fPrevLength;
        SkASSERT(fPosition >= 0);

        fItem = reinterpret_cast<TBase*>(&(*fBlock)[fPosition + length_of<Header>::kValue]);
        return true;
    }

    TBase* get() const { return fItem; }
    TBase* operator->() const { return this->get(); }

private:
    MemBlock* fBlock;
<<<<<<< HEAD
    int fPosition;
    TBase* fItem;
};

template <typename TBase, typename TAlign>
void GrTRecorder<TBase, TAlign>::reset()
{
=======
    int       fPosition;
    TBase*    fItem;
};

template<typename TBase, typename TAlign>
void GrTRecorder<TBase, TAlign>::reset() {
>>>>>>> miniblink49
    Iter iter(*this);
    while (iter.next()) {
        iter->~TBase();
    }

    // Assume the next time this recorder fills up it will use approximately the same
    // amount of space as last time. Leave enough space for up to ~50% growth; free
    // everything else.
    if (fTailBlock->fBack <= fTailBlock->fLength / 2) {
        MemBlock::Free(fTailBlock->fNext);
    } else if (fTailBlock->fNext) {
        MemBlock::Free(fTailBlock->fNext->fNext);
<<<<<<< HEAD
        fTailBlock->fNext->fNext = nullptr;
=======
        fTailBlock->fNext->fNext = NULL;
>>>>>>> miniblink49
    }

    for (MemBlock* block = fHeadBlock; block; block = block->fNext) {
        block->fBack = 0;
    }

    fTailBlock = fHeadBlock;
<<<<<<< HEAD
    fLastItem = nullptr;
=======
    fLastItem = NULL;
>>>>>>> miniblink49
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
template <typename TItem>
struct GrTRecorderAllocWrapper {
    GrTRecorderAllocWrapper()
        : fDataLength(0)
    {
    }

    template <typename TBase, typename TAlign>
    GrTRecorderAllocWrapper(const GrTRecorder<TBase, TAlign>&, int sizeOfData)
        : fDataLength(GrTRecorder<TBase, TAlign>::LengthOf(sizeOfData))
    {
    }
=======
template<typename TItem> struct GrTRecorderAllocWrapper {
    GrTRecorderAllocWrapper() : fDataLength(0) {}

    template <typename TBase, typename TAlign>
    GrTRecorderAllocWrapper(const GrTRecorder<TBase, TAlign>&, int sizeOfData)
        : fDataLength(GrTRecorder<TBase, TAlign>::LengthOf(sizeOfData)) {}
>>>>>>> miniblink49

    const int fDataLength;
};

template <typename TBase, typename TAlign, typename TItem>
void* operator new(size_t size, GrTRecorder<TBase, TAlign>& recorder,
<<<<<<< HEAD
    const GrTRecorderAllocWrapper<TItem>& wrapper)
{
=======
                   const GrTRecorderAllocWrapper<TItem>& wrapper) {
>>>>>>> miniblink49
    SkASSERT(size == sizeof(TItem));
    return recorder.template alloc_back<TItem>(wrapper.fDataLength);
}

template <typename TBase, typename TAlign, typename TItem>
<<<<<<< HEAD
void operator delete(void*, GrTRecorder<TBase, TAlign>&, const GrTRecorderAllocWrapper<TItem>&)
{
    // We only provide an operator delete to work around compiler warnings that can come
    // up for an unmatched operator new when compiling with exceptions.
    SK_ABORT("Invalid Operation");
=======
void operator delete(void*, GrTRecorder<TBase, TAlign>&, const GrTRecorderAllocWrapper<TItem>&) {
    // We only provide an operator delete to work around compiler warnings that can come
    // up for an unmatched operator new when compiling with exceptions.
    SK_CRASH();
>>>>>>> miniblink49
}

#define GrNEW_APPEND_TO_RECORDER(recorder, type_name, args) \
    (new (recorder, GrTRecorderAllocWrapper<type_name>()) type_name args)

#define GrNEW_APPEND_WITH_DATA_TO_RECORDER(recorder, type_name, args, size_of_data) \
    (new (recorder, GrTRecorderAllocWrapper<type_name>(recorder, size_of_data)) type_name args)

#endif
