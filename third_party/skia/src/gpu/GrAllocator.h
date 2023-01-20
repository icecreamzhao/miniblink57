/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrAllocator_DEFINED
#define GrAllocator_DEFINED

#include "GrConfig.h"
#include "GrTypes.h"
#include "SkTArray.h"
#include "SkTypes.h"

class GrAllocator : SkNoncopyable {
public:
    ~GrAllocator() { this->reset(); }

    /**
     * Create an allocator
     *
     * @param   itemSize        the size of each item to allocate
     * @param   itemsPerBlock   the number of items to allocate at once
     * @param   initialBlock    optional memory to use for the first block.
     *                          Must be at least itemSize*itemsPerBlock sized.
     *                          Caller is responsible for freeing this memory.
     */
    GrAllocator(size_t itemSize, int itemsPerBlock, void* initialBlock)
        : fItemSize(itemSize)
        , fItemsPerBlock(itemsPerBlock)
<<<<<<< HEAD
        , fOwnFirstBlock(nullptr == initialBlock)
        , fCount(0)
        , fInsertionIndexInBlock(0)
    {
=======
        , fOwnFirstBlock(NULL == initialBlock)
        , fCount(0)
        , fInsertionIndexInBlock(0) {
>>>>>>> miniblink49
        SkASSERT(itemsPerBlock > 0);
        fBlockSize = fItemSize * fItemsPerBlock;
        if (fOwnFirstBlock) {
            // This force us to allocate a new block on push_back().
            fInsertionIndexInBlock = fItemsPerBlock;
        } else {
            fBlocks.push_back() = initialBlock;
            fInsertionIndexInBlock = 0;
        }
    }

    /**
     * Adds an item and returns pointer to it.
     *
     * @return pointer to the added item.
     */
<<<<<<< HEAD
    void* push_back()
    {
=======
    void* push_back() {
>>>>>>> miniblink49
        // we always have at least one block
        if (fItemsPerBlock == fInsertionIndexInBlock) {
            fBlocks.push_back() = sk_malloc_throw(fBlockSize);
            fInsertionIndexInBlock = 0;
        }
        void* ret = (char*)fBlocks.back() + fItemSize * fInsertionIndexInBlock;
        ++fCount;
        ++fInsertionIndexInBlock;
        return ret;
    }

    /**
     * Remove the last item, only call if count() != 0
     */
<<<<<<< HEAD
    void pop_back()
    {
=======
    void pop_back() {
>>>>>>> miniblink49
        SkASSERT(fCount);
        SkASSERT(fInsertionIndexInBlock > 0);
        --fInsertionIndexInBlock;
        --fCount;
        if (0 == fInsertionIndexInBlock) {
            // Never delete the first block
            if (fBlocks.count() > 1) {
                sk_free(fBlocks.back());
                fBlocks.pop_back();
                fInsertionIndexInBlock = fItemsPerBlock;
            }
        }
    }

    /**
     * Removes all added items.
     */
<<<<<<< HEAD
    void reset()
    {
=======
    void reset() {
>>>>>>> miniblink49
        int firstBlockToFree = fOwnFirstBlock ? 0 : 1;
        for (int i = firstBlockToFree; i < fBlocks.count(); ++i) {
            sk_free(fBlocks[i]);
        }
        if (fOwnFirstBlock) {
            fBlocks.reset();
            // This force us to allocate a new block on push_back().
            fInsertionIndexInBlock = fItemsPerBlock;
        } else {
            fBlocks.pop_back_n(fBlocks.count() - 1);
            fInsertionIndexInBlock = 0;
        }
        fCount = 0;
    }

    /**
     * Returns the item count.
     */
<<<<<<< HEAD
    int count() const
    {
=======
    int count() const {
>>>>>>> miniblink49
        return fCount;
    }

    /**
     * Is the count 0?
     */
    bool empty() const { return 0 == fCount; }

    /**
     * Access last item, only call if count() != 0
     */
<<<<<<< HEAD
    void* back()
    {
=======
    void* back() {
>>>>>>> miniblink49
        SkASSERT(fCount);
        SkASSERT(fInsertionIndexInBlock > 0);
        return (char*)(fBlocks.back()) + (fInsertionIndexInBlock - 1) * fItemSize;
    }

    /**
     * Access last item, only call if count() != 0
     */
<<<<<<< HEAD
    const void* back() const
    {
=======
    const void* back() const {
>>>>>>> miniblink49
        SkASSERT(fCount);
        SkASSERT(fInsertionIndexInBlock > 0);
        return (const char*)(fBlocks.back()) + (fInsertionIndexInBlock - 1) * fItemSize;
    }

    /**
     * Iterates through the allocator. This is faster than using operator[] when walking linearly
     * through the allocator.
     */
    class Iter {
    public:
        /**
         * Initializes the iterator. next() must be called before get().
         */
        Iter(const GrAllocator* allocator)
            : fAllocator(allocator)
            , fBlockIndex(-1)
            , fIndexInBlock(allocator->fItemsPerBlock - 1)
<<<<<<< HEAD
            , fItemIndex(-1)
        {
        }
=======
            , fItemIndex(-1) {}
>>>>>>> miniblink49

        /**
         * Advances the iterator. Iteration is finished when next() returns false.
         */
<<<<<<< HEAD
        bool next()
        {
=======
        bool next() {
>>>>>>> miniblink49
            ++fIndexInBlock;
            ++fItemIndex;
            if (fIndexInBlock == fAllocator->fItemsPerBlock) {
                ++fBlockIndex;
                fIndexInBlock = 0;
            }
            return fItemIndex < fAllocator->fCount;
        }

        /**
         * Gets the current iterator value. Call next() at least once before calling. Don't call
         * after next() returns false.
         */
<<<<<<< HEAD
        void* get() const
        {
            SkASSERT(fItemIndex >= 0 && fItemIndex < fAllocator->fCount);
            return (char*)fAllocator->fBlocks[fBlockIndex] + fIndexInBlock * fAllocator->fItemSize;
=======
        void* get() const {
            SkASSERT(fItemIndex >= 0 && fItemIndex < fAllocator->fCount);
            return (char*) fAllocator->fBlocks[fBlockIndex] + fIndexInBlock * fAllocator->fItemSize;
>>>>>>> miniblink49
        }

    private:
        const GrAllocator* fAllocator;
<<<<<<< HEAD
        int fBlockIndex;
        int fIndexInBlock;
        int fItemIndex;
=======
        int                fBlockIndex;
        int                fIndexInBlock;
        int                fItemIndex;
>>>>>>> miniblink49
    };

    /**
     * Access item by index.
     */
<<<<<<< HEAD
    void* operator[](int i)
    {
        SkASSERT(i >= 0 && i < fCount);
        return (char*)fBlocks[i / fItemsPerBlock] + fItemSize * (i % fItemsPerBlock);
=======
    void* operator[] (int i) {
        SkASSERT(i >= 0 && i < fCount);
        return (char*)fBlocks[i / fItemsPerBlock] +
               fItemSize * (i % fItemsPerBlock);
>>>>>>> miniblink49
    }

    /**
     * Access item by index.
     */
<<<<<<< HEAD
    const void* operator[](int i) const
    {
        SkASSERT(i >= 0 && i < fCount);
        return (const char*)fBlocks[i / fItemsPerBlock] + fItemSize * (i % fItemsPerBlock);
=======
    const void* operator[] (int i) const {
        SkASSERT(i >= 0 && i < fCount);
        return (const char*)fBlocks[i / fItemsPerBlock] +
               fItemSize * (i % fItemsPerBlock);
>>>>>>> miniblink49
    }

protected:
    /**
     * Set first block of memory to write into.  Must be called before any other methods.
<<<<<<< HEAD
     * This requires that you have passed nullptr in the constructor.
=======
     * This requires that you have passed NULL in the constructor.
>>>>>>> miniblink49
     *
     * @param   initialBlock    optional memory to use for the first block.
     *                          Must be at least itemSize*itemsPerBlock sized.
     *                          Caller is responsible for freeing this memory.
     */
<<<<<<< HEAD
    void setInitialBlock(void* initialBlock)
    {
=======
    void setInitialBlock(void* initialBlock) {
>>>>>>> miniblink49
        SkASSERT(0 == fCount);
        SkASSERT(0 == fBlocks.count());
        SkASSERT(fItemsPerBlock == fInsertionIndexInBlock);
        fOwnFirstBlock = false;
        fBlocks.push_back() = initialBlock;
        fInsertionIndexInBlock = 0;
    }

    // For access to above function.
<<<<<<< HEAD
    template <typename T>
    friend class GrTAllocator;
=======
    template <typename T> friend class GrTAllocator;
>>>>>>> miniblink49

private:
    static const int NUM_INIT_BLOCK_PTRS = 8;

<<<<<<< HEAD
    SkSTArray<NUM_INIT_BLOCK_PTRS, void*, true> fBlocks;
    size_t fBlockSize;
    size_t fItemSize;
    int fItemsPerBlock;
    bool fOwnFirstBlock;
    int fCount;
    int fInsertionIndexInBlock;
=======
    SkSTArray<NUM_INIT_BLOCK_PTRS, void*, true>   fBlocks;
    size_t                                        fBlockSize;
    size_t                                        fItemSize;
    int                                           fItemsPerBlock;
    bool                                          fOwnFirstBlock;
    int                                           fCount;
    int                                           fInsertionIndexInBlock;
>>>>>>> miniblink49

    typedef SkNoncopyable INHERITED;
};

<<<<<<< HEAD
template <typename T>
class GrTAllocator;
template <typename T>
void* operator new(size_t, GrTAllocator<T>*);

template <typename T>
class GrTAllocator : SkNoncopyable {
=======
template <typename T> class GrTAllocator;
template <typename T> void* operator new(size_t, GrTAllocator<T>*);

template <typename T> class GrTAllocator : SkNoncopyable {
>>>>>>> miniblink49
public:
    virtual ~GrTAllocator() { this->reset(); };

    /**
     * Create an allocator
     *
     * @param   itemsPerBlock   the number of items to allocate at once
     */
    explicit GrTAllocator(int itemsPerBlock)
<<<<<<< HEAD
        : fAllocator(sizeof(T), itemsPerBlock, nullptr)
    {
    }
=======
        : fAllocator(sizeof(T), itemsPerBlock, NULL) {}
>>>>>>> miniblink49

    /**
     * Adds an item and returns it.
     *
     * @return the added item.
     */
<<<<<<< HEAD
    T& push_back()
    {
        void* item = fAllocator.push_back();
        SkASSERT(item);
        new (item) T;
        return *(T*)item;
    }

    T& push_back(const T& t)
    {
        void* item = fAllocator.push_back();
        SkASSERT(item);
        new (item) T(t);
=======
    T& push_back() {
        void* item = fAllocator.push_back();
        SkASSERT(item);
        SkNEW_PLACEMENT(item, T);
        return *(T*)item;
    }

    T& push_back(const T& t) {
        void* item = fAllocator.push_back();
        SkASSERT(item);
        SkNEW_PLACEMENT_ARGS(item, T, (t));
>>>>>>> miniblink49
        return *(T*)item;
    }

    /**
     * Remove the last item, only call if count() != 0
     */
<<<<<<< HEAD
    void pop_back()
    {
=======
    void pop_back() {
>>>>>>> miniblink49
        this->back().~T();
        fAllocator.pop_back();
    }

    /**
     * Removes all added items.
     */
<<<<<<< HEAD
    void reset()
    {
=======
    void reset() {
>>>>>>> miniblink49
        int c = fAllocator.count();
        for (int i = 0; i < c; ++i) {
            ((T*)fAllocator[i])->~T();
        }
        fAllocator.reset();
    }

    /**
     * Returns the item count.
     */
<<<<<<< HEAD
    int count() const
    {
=======
    int count() const {
>>>>>>> miniblink49
        return fAllocator.count();
    }

    /**
     * Is the count 0?
     */
    bool empty() const { return fAllocator.empty(); }

    /**
     * Access last item, only call if count() != 0
     */
<<<<<<< HEAD
    T& back()
    {
=======
    T& back() {
>>>>>>> miniblink49
        return *(T*)fAllocator.back();
    }

    /**
     * Access last item, only call if count() != 0
     */
<<<<<<< HEAD
    const T& back() const
    {
=======
    const T& back() const {
>>>>>>> miniblink49
        return *(const T*)fAllocator.back();
    }

    /**
     * Iterates through the allocator. This is faster than using operator[] when walking linearly
     * through the allocator.
     */
    class Iter {
    public:
        /**
         * Initializes the iterator. next() must be called before get() or ops * and ->.
         */
<<<<<<< HEAD
        Iter(const GrTAllocator* allocator)
            : fImpl(&allocator->fAllocator)
        {
        }
=======
        Iter(const GrTAllocator* allocator) : fImpl(&allocator->fAllocator) {}
>>>>>>> miniblink49

        /**
         * Advances the iterator. Iteration is finished when next() returns false.
         */
        bool next() { return fImpl.next(); }

        /**
         * Gets the current iterator value. Call next() at least once before calling. Don't call
         * after next() returns false.
         */
<<<<<<< HEAD
        T* get() const { return (T*)fImpl.get(); }
=======
        T* get() const { return (T*) fImpl.get(); }
>>>>>>> miniblink49

        /**
         * Convenience operators. Same rules for calling apply as get().
         */
        T& operator*() const { return *this->get(); }
        T* operator->() const { return this->get(); }

    private:
        GrAllocator::Iter fImpl;
    };

    /**
     * Access item by index.
     */
<<<<<<< HEAD
    T& operator[](int i)
    {
=======
    T& operator[] (int i) {
>>>>>>> miniblink49
        return *(T*)(fAllocator[i]);
    }

    /**
     * Access item by index.
     */
<<<<<<< HEAD
    const T& operator[](int i) const
    {
=======
    const T& operator[] (int i) const {
>>>>>>> miniblink49
        return *(const T*)(fAllocator[i]);
    }

protected:
    /*
     * Set first block of memory to write into.  Must be called before any other methods.
     *
     * @param   initialBlock    optional memory to use for the first block.
     *                          Must be at least size(T)*itemsPerBlock sized.
     *                          Caller is responsible for freeing this memory.
     */
<<<<<<< HEAD
    void setInitialBlock(void* initialBlock)
    {
=======
    void setInitialBlock(void* initialBlock) {
>>>>>>> miniblink49
        fAllocator.setInitialBlock(initialBlock);
    }

private:
    friend void* operator new<T>(size_t, GrTAllocator*);

    GrAllocator fAllocator;
    typedef SkNoncopyable INHERITED;
};

<<<<<<< HEAD
template <int N, typename T>
class GrSTAllocator : public GrTAllocator<T> {
=======
template <int N, typename T> class GrSTAllocator : public GrTAllocator<T> {
>>>>>>> miniblink49
private:
    typedef GrTAllocator<T> INHERITED;

public:
<<<<<<< HEAD
    GrSTAllocator()
        : INHERITED(N)
    {
=======
    GrSTAllocator() : INHERITED(N) {
>>>>>>> miniblink49
        this->setInitialBlock(fStorage.get());
    }

private:
    SkAlignedSTStorage<N, T> fStorage;
};

<<<<<<< HEAD
template <typename T>
void* operator new(size_t size, GrTAllocator<T>* allocator)
{
=======
template <typename T> void* operator new(size_t size, GrTAllocator<T>* allocator) {
>>>>>>> miniblink49
    return allocator->fAllocator.push_back();
}

// Skia doesn't use C++ exceptions but it may be compiled with them enabled. Having an op delete
// to match the op new silences warnings about missing op delete when a constructor throws an
// exception.
<<<<<<< HEAD
template <typename T>
void operator delete(void*, GrTAllocator<T>*)
{
    SK_ABORT("Invalid Operation");
=======
template <typename T> void operator delete(void*, GrTAllocator<T>*) {
    SK_CRASH();
>>>>>>> miniblink49
}

#define GrNEW_APPEND_TO_ALLOCATOR(allocator_ptr, type_name, args) \
    new (allocator_ptr) type_name args

#endif
