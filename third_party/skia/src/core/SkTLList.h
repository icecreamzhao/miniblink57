/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkTLList_DEFINED
#define SkTLList_DEFINED

#include "SkTInternalLList.h"
<<<<<<< HEAD
#include "SkTypes.h"
#include <utility>
=======
#include "SkTemplates.h"

template <typename T> class SkTLList;
template <typename T>
inline void* operator new(size_t, SkTLList<T>* list,
                          typename SkTLList<T>::Placement placement,
                          const typename SkTLList<T>::Iter& location);
>>>>>>> miniblink49

/** Doubly-linked list of objects. The objects' lifetimes are controlled by the list. I.e. the
    the list creates the objects and they are deleted upon removal. This class block-allocates
    space for entries based on a param passed to the constructor.

    Elements of the list can be constructed in place using the following macros:
        SkNEW_INSERT_IN_LLIST_BEFORE(list, location, type_name, args)
        SkNEW_INSERT_IN_LLIST_AFTER(list, location, type_name, args)
    where list is a SkTLList<type_name>*, location is an iterator, and args is the paren-surrounded
    constructor arguments for type_name. These macros behave like addBefore() and addAfter().
<<<<<<< HEAD

    allocCnt is the number of objects to allocate as a group. In the worst case fragmentation
    each object is using the space required for allocCnt unfragmented objects.
*/
template <typename T, unsigned int N>
=======
*/
template <typename T>
>>>>>>> miniblink49
class SkTLList : SkNoncopyable {
private:
    struct Block;
    struct Node {
        char fObj[sizeof(T)];
        SK_DECLARE_INTERNAL_LLIST_INTERFACE(Node);
        Block* fBlock; // owning block.
    };
    typedef SkTInternalLList<Node> NodeList;

public:
<<<<<<< HEAD
    class Iter;

    SkTLList()
        : fCount(0)
    {
        fFirstBlock.fNodesInUse = 0;
        for (unsigned int i = 0; i < N; ++i) {
            fFreeList.addToHead(fFirstBlock.fNodes + i);
            fFirstBlock.fNodes[i].fBlock = &fFirstBlock;
        }
        this->validate();
    }

    ~SkTLList()
    {
=======

    class Iter;

    /** allocCnt is the number of objects to allocate as a group. In the worst case fragmentation
        each object is using the space required for allocCnt unfragmented objects. */
    SkTLList(int allocCnt = 1) : fCount(0), fAllocCnt(allocCnt) {
        SkASSERT(allocCnt > 0);
        this->validate();
    }

    ~SkTLList() {
>>>>>>> miniblink49
        this->validate();
        typename NodeList::Iter iter;
        Node* node = iter.init(fList, Iter::kHead_IterStart);
        while (node) {
            SkTCast<T*>(node->fObj)->~T();
            Block* block = node->fBlock;
            node = iter.next();
            if (0 == --block->fNodesInUse) {
<<<<<<< HEAD
                for (unsigned int i = 0; i < N; ++i) {
                    block->fNodes[i].~Node();
                }
                if (block != &fFirstBlock) {
                    sk_free(block);
                }
=======
                for (int i = 0; i < fAllocCnt; ++i) {
                    block->fNodes[i].~Node();
                }
                sk_free(block);
>>>>>>> miniblink49
            }
        }
    }

<<<<<<< HEAD
    /** Adds a new element to the list at the head. */
    template <typename... Args>
    T* addToHead(Args&&... args)
    {
        this->validate();
        Node* node = this->createNode();
        fList.addToHead(node);
        this->validate();
        return new (node->fObj) T(std::forward<Args>(args)...);
    }

    /** Adds a new element to the list at the tail. */
    template <typename... Args>
    T* addToTail(Args&&... args)
    {
        this->validate();
        Node* node = this->createNode();
        fList.addToTail(node);
        this->validate();
        return new (node->fObj) T(std::forward<Args>(args)...);
    }

    /** Adds a new element to the list before the location indicated by the iterator. If the
        iterator refers to a nullptr location then the new element is added at the tail */
    template <typename... Args>
    T* addBefore(Iter location, Args&&... args)
    {
        this->validate();
        Node* node = this->createNode();
        fList.addBefore(node, location.getNode());
        this->validate();
        return new (node->fObj) T(std::forward<Args>(args)...);
    }

    /** Adds a new element to the list after the location indicated by the iterator. If the
        iterator refers to a nullptr location then the new element is added at the head */
    template <typename... Args>
    T* addAfter(Iter location, Args&&... args)
    {
        this->validate();
        Node* node = this->createNode();
        fList.addAfter(node, location.getNode());
        this->validate();
        return new (node->fObj) T(std::forward<Args>(args)...);
=======
    T* addToHead(const T& t) {
        this->validate();
        Node* node = this->createNode();
        fList.addToHead(node);
        SkNEW_PLACEMENT_ARGS(node->fObj, T, (t));
        this->validate();
        return reinterpret_cast<T*>(node->fObj);
    }

    T* addToHead() {
        this->validate();
        Node* node = this->createNode();
        fList.addToHead(node);
        SkNEW_PLACEMENT(node->fObj, T);
        this->validate();
        return reinterpret_cast<T*>(node->fObj);
    }

    T* addToTail(const T& t) {
        this->validate();
        Node* node = this->createNode();
        fList.addToTail(node);
        SkNEW_PLACEMENT_ARGS(node->fObj, T, (t));
        this->validate();
        return reinterpret_cast<T*>(node->fObj);
    }

    T* addToTail() {
        this->validate();
        Node* node = this->createNode();
        fList.addToTail(node);
        SkNEW_PLACEMENT(node->fObj, T);
        this->validate();
        return reinterpret_cast<T*>(node->fObj);
    }

    /** Adds a new element to the list before the location indicated by the iterator. If the
        iterator refers to a NULL location then the new element is added at the tail */
    T* addBefore(const T& t, const Iter& location) {
        return SkNEW_PLACEMENT_ARGS(this->internalAddBefore(location), T, (t));
    }

    /** Adds a new element to the list after the location indicated by the iterator. If the
        iterator refers to a NULL location then the new element is added at the head */
    T* addAfter(const T& t, const Iter& location) {
        return SkNEW_PLACEMENT_ARGS(this->internalAddAfter(location), T, (t));
>>>>>>> miniblink49
    }

    /** Convenience methods for getting an iterator initialized to the head/tail of the list. */
    Iter headIter() const { return Iter(*this, Iter::kHead_IterStart); }
    Iter tailIter() const { return Iter(*this, Iter::kTail_IterStart); }

    T* head() { return Iter(*this, Iter::kHead_IterStart).get(); }
    T* tail() { return Iter(*this, Iter::kTail_IterStart).get(); }
    const T* head() const { return Iter(*this, Iter::kHead_IterStart).get(); }
    const T* tail() const { return Iter(*this, Iter::kTail_IterStart).get(); }

<<<<<<< HEAD
    void popHead()
    {
=======
    void popHead() {
>>>>>>> miniblink49
        this->validate();
        Node* node = fList.head();
        if (node) {
            this->removeNode(node);
        }
        this->validate();
    }

<<<<<<< HEAD
    void popTail()
    {
=======
    void popTail() {
>>>>>>> miniblink49
        this->validate();
        Node* node = fList.head();
        if (node) {
            this->removeNode(node);
        }
        this->validate();
    }

<<<<<<< HEAD
    void remove(T* t)
    {
=======
    void remove(T* t) {
>>>>>>> miniblink49
        this->validate();
        Node* node = reinterpret_cast<Node*>(t);
        SkASSERT(reinterpret_cast<T*>(node->fObj) == t);
        this->removeNode(node);
        this->validate();
    }

<<<<<<< HEAD
    void reset()
    {
=======
    void reset() {
>>>>>>> miniblink49
        this->validate();
        Iter iter(*this, Iter::kHead_IterStart);
        while (iter.get()) {
            Iter next = iter;
            next.next();
            this->remove(iter.get());
            iter = next;
        }
        SkASSERT(0 == fCount);
        this->validate();
    }

    int count() const { return fCount; }
<<<<<<< HEAD
    bool isEmpty() const
    {
        this->validate();
        return 0 == fCount;
    }

    bool operator==(const SkTLList& list) const
    {
=======
    bool isEmpty() const { this->validate(); return 0 == fCount; }

    bool operator== (const SkTLList& list) const {
>>>>>>> miniblink49
        if (this == &list) {
            return true;
        }
        if (fCount != list.fCount) {
            return false;
        }
        for (Iter a(*this, Iter::kHead_IterStart), b(list, Iter::kHead_IterStart);
             a.get();
             a.next(), b.next()) {
            SkASSERT(b.get()); // already checked that counts match.
            if (!(*a.get() == *b.get())) {
                return false;
            }
        }
        return true;
    }
<<<<<<< HEAD
    bool operator!=(const SkTLList& list) const { return !(*this == list); }
=======
    bool operator!= (const SkTLList& list) const { return !(*this == list); }
>>>>>>> miniblink49

    /** The iterator becomes invalid if the element it refers to is removed from the list. */
    class Iter : private NodeList::Iter {
    private:
        typedef typename NodeList::Iter INHERITED;

    public:
        typedef typename INHERITED::IterStart IterStart;
        //!< Start the iterator at the head of the list.
        static const IterStart kHead_IterStart = INHERITED::kHead_IterStart;
        //!< Start the iterator at the tail of the list.
        static const IterStart kTail_IterStart = INHERITED::kTail_IterStart;

<<<<<<< HEAD
        Iter() { }

        Iter(const SkTLList& list, IterStart start = kHead_IterStart)
        {
            INHERITED::init(list.fList, start);
        }

        T* init(const SkTLList& list, IterStart start = kHead_IterStart)
        {
=======
        Iter() {}

        Iter(const SkTLList& list, IterStart start = kHead_IterStart) {
            INHERITED::init(list.fList, start);
        }

        T* init(const SkTLList& list, IterStart start = kHead_IterStart) {
>>>>>>> miniblink49
            return this->nodeToObj(INHERITED::init(list.fList, start));
        }

        T* get() { return this->nodeToObj(INHERITED::get()); }

        T* next() { return this->nodeToObj(INHERITED::next()); }

        T* prev() { return this->nodeToObj(INHERITED::prev()); }

<<<<<<< HEAD
        Iter& operator=(const Iter& iter)
        {
            INHERITED::operator=(iter);
            return *this;
        }
=======
        Iter& operator= (const Iter& iter) { INHERITED::operator=(iter); return *this; }
>>>>>>> miniblink49

    private:
        friend class SkTLList;
        Node* getNode() { return INHERITED::get(); }

<<<<<<< HEAD
        T* nodeToObj(Node* node)
        {
            if (node) {
                return reinterpret_cast<T*>(node->fObj);
            } else {
                return nullptr;
=======
        T* nodeToObj(Node* node) {
            if (node) {
                return reinterpret_cast<T*>(node->fObj);
            } else {
                return NULL;
>>>>>>> miniblink49
            }
        }
    };

<<<<<<< HEAD
private:
    struct Block {
        int fNodesInUse;
        Node fNodes[N];
    };

    Node* createNode()
    {
=======
    // For use with operator new
    enum Placement {
        kBefore_Placement,
        kAfter_Placement,
    };

private:
    struct Block {
        int fNodesInUse;
        Node fNodes[1];
    };

    size_t blockSize() const { return sizeof(Block) + sizeof(Node) * (fAllocCnt-1); }

    Node* createNode() {
>>>>>>> miniblink49
        Node* node = fFreeList.head();
        if (node) {
            fFreeList.remove(node);
            ++node->fBlock->fNodesInUse;
        } else {
<<<<<<< HEAD
            // Should not get here when count == 0 because we always have the preallocated first
            // block.
            SkASSERT(fCount > 0);
            Block* block = reinterpret_cast<Block*>(sk_malloc_throw(sizeof(Block)));
            node = &block->fNodes[0];
            new (node) Node;
            node->fBlock = block;
            block->fNodesInUse = 1;
            for (unsigned int i = 1; i < N; ++i) {
                new (block->fNodes + i) Node;
=======
            Block* block = reinterpret_cast<Block*>(sk_malloc_flags(this->blockSize(), 0));
            node = &block->fNodes[0];
            SkNEW_PLACEMENT(node, Node);
            node->fBlock = block;
            block->fNodesInUse = 1;
            for (int i = 1; i < fAllocCnt; ++i) {
                SkNEW_PLACEMENT(block->fNodes + i, Node);
>>>>>>> miniblink49
                fFreeList.addToHead(block->fNodes + i);
                block->fNodes[i].fBlock = block;
            }
        }
        ++fCount;
        return node;
    }

<<<<<<< HEAD
    void removeNode(Node* node)
    {
        SkASSERT(node);
        fList.remove(node);
        SkTCast<T*>(node->fObj)->~T();
        Block* block = node->fBlock;
        // Don't ever elease the first block, just add its nodes to the free list
        if (0 == --block->fNodesInUse && block != &fFirstBlock) {
            for (unsigned int i = 0; i < N; ++i) {
=======
    void removeNode(Node* node) {
        SkASSERT(node);
        fList.remove(node);
        SkTCast<T*>(node->fObj)->~T();
        if (0 == --node->fBlock->fNodesInUse) {
            Block* block = node->fBlock;
            for (int i = 0; i < fAllocCnt; ++i) {
>>>>>>> miniblink49
                if (block->fNodes + i != node) {
                    fFreeList.remove(block->fNodes + i);
                }
                block->fNodes[i].~Node();
            }
            sk_free(block);
        } else {
            fFreeList.addToHead(node);
        }
        --fCount;
        this->validate();
    }

<<<<<<< HEAD
    void validate() const
    {
#ifdef SK_DEBUG
        SkASSERT((0 == fCount) == fList.isEmpty());
        if (0 == fCount) {
            // Should only have the nodes from the first block in the free list.
            SkASSERT(fFreeList.countEntries() == N);
        }
=======
    void validate() const {
#ifdef SK_DEBUG
        SkASSERT((0 == fCount) == fList.isEmpty());
        SkASSERT((0 != fCount) || fFreeList.isEmpty());

>>>>>>> miniblink49
        fList.validate();
        fFreeList.validate();
        typename NodeList::Iter iter;
        Node* freeNode = iter.init(fFreeList, Iter::kHead_IterStart);
        while (freeNode) {
            SkASSERT(fFreeList.isInList(freeNode));
            Block* block = freeNode->fBlock;
<<<<<<< HEAD
            // Only the first block is allowed to have all its nodes in the free list.
            SkASSERT(block->fNodesInUse > 0 || block == &fFirstBlock);
            SkASSERT((unsigned)block->fNodesInUse < N);
            int activeCnt = 0;
            int freeCnt = 0;
            for (unsigned int i = 0; i < N; ++i) {
=======
            SkASSERT(block->fNodesInUse > 0 && block->fNodesInUse < fAllocCnt);

            int activeCnt = 0;
            int freeCnt = 0;
            for (int i = 0; i < fAllocCnt; ++i) {
>>>>>>> miniblink49
                bool free = fFreeList.isInList(block->fNodes + i);
                bool active = fList.isInList(block->fNodes + i);
                SkASSERT(free != active);
                activeCnt += active;
                freeCnt += free;
            }
            SkASSERT(activeCnt == block->fNodesInUse);
            freeNode = iter.next();
        }

        int count = 0;
        Node* activeNode = iter.init(fList, Iter::kHead_IterStart);
        while (activeNode) {
            ++count;
            SkASSERT(fList.isInList(activeNode));
            Block* block = activeNode->fBlock;
<<<<<<< HEAD
            SkASSERT(block->fNodesInUse > 0 && (unsigned)block->fNodesInUse <= N);

            int activeCnt = 0;
            int freeCnt = 0;
            for (unsigned int i = 0; i < N; ++i) {
=======
            SkASSERT(block->fNodesInUse > 0 && block->fNodesInUse <= fAllocCnt);

            int activeCnt = 0;
            int freeCnt = 0;
            for (int i = 0; i < fAllocCnt; ++i) {
>>>>>>> miniblink49
                bool free = fFreeList.isInList(block->fNodes + i);
                bool active = fList.isInList(block->fNodes + i);
                SkASSERT(free != active);
                activeCnt += active;
                freeCnt += free;
            }
            SkASSERT(activeCnt == block->fNodesInUse);
            activeNode = iter.next();
        }
        SkASSERT(count == fCount);
#endif
    }

<<<<<<< HEAD
    NodeList fList;
    NodeList fFreeList;
    Block fFirstBlock;
    int fCount;
};

=======
    // Support in-place initializing of objects inserted into the list via operator new.
    friend void* operator new<T>(size_t,
                                 SkTLList* list,
                                 Placement placement,
                                 const Iter& location);


    // Helpers that insert the node and returns a pointer to where the new object should be init'ed.
    void* internalAddBefore(Iter location) {
        this->validate();
        Node* node = this->createNode();
        fList.addBefore(node, location.getNode());
        this->validate();
        return node->fObj;
    }

    void* internalAddAfter(Iter location) {
        this->validate();
        Node* node = this->createNode();
        fList.addAfter(node, location.getNode());
        this->validate();
        return node->fObj;
    }

    NodeList fList;
    NodeList fFreeList;
    int fCount;
    int fAllocCnt;

};

// Use the below macros rather than calling this directly
template <typename T>
void *operator new(size_t, SkTLList<T>* list,
                   typename SkTLList<T>::Placement placement,
                   const typename SkTLList<T>::Iter& location) {
    SkASSERT(list);
    if (SkTLList<T>::kBefore_Placement == placement) {
        return list->internalAddBefore(location);
    } else {
        return list->internalAddAfter(location);
    }
}

// Skia doesn't use C++ exceptions but it may be compiled with them enabled. Having an op delete
// to match the op new silences warnings about missing op delete when a constructor throws an
// exception.
template <typename T>
void operator delete(void*,
                     SkTLList<T>*,
                     typename SkTLList<T>::Placement,
                     const typename SkTLList<T>::Iter&) {
    SK_CRASH();
}

#define SkNEW_INSERT_IN_LLIST_BEFORE(list, location, type_name, args) \
    (new ((list), SkTLList< type_name >::kBefore_Placement, (location)) type_name args)

#define SkNEW_INSERT_IN_LLIST_AFTER(list, location, type_name, args) \
    (new ((list), SkTLList< type_name >::kAfter_Placement, (location)) type_name args)

#define SkNEW_INSERT_AT_LLIST_HEAD(list, type_name, args) \
    SkNEW_INSERT_IN_LLIST_BEFORE((list), (list)->headIter(), type_name, args)

#define SkNEW_INSERT_AT_LLIST_TAIL(list, type_name, args) \
    SkNEW_INSERT_IN_LLIST_AFTER((list), (list)->tailIter(), type_name, args)

>>>>>>> miniblink49
#endif
