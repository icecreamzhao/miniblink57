/*
<<<<<<< HEAD
 * Copyright (C) 2005, 2006, 2007, 2008, 2011, 2012 Apple Inc. All rights
 * reserved.
=======
 * Copyright (C) 2005, 2006, 2007, 2008, 2011, 2012 Apple Inc. All rights reserved.
>>>>>>> miniblink49
 * Copyright (C) 2011, Benjamin Poulain <ikipou@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef WTF_LinkedHashSet_h
#define WTF_LinkedHashSet_h

#include "wtf/AddressSanitizer.h"
<<<<<<< HEAD
#include "wtf/HashSet.h"
#include "wtf/allocator/PartitionAllocator.h"
=======
#include "wtf/DefaultAllocator.h"
#include "wtf/HashSet.h"
#include "wtf/OwnPtr.h"
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49

namespace WTF {

// LinkedHashSet: Just like HashSet, this class provides a Set
// interface - a collection of unique objects with O(1) insertion,
// removal and test for containership. However, it also has an
// order - iterating it will always give back values in the order
// in which they are added.

// Unlike ListHashSet, but like most WTF collections, iteration is NOT safe
// against mutation of the LinkedHashSet.

<<<<<<< HEAD
template <typename Value,
    typename HashFunctions,
    typename HashTraits,
    typename Allocator>
class LinkedHashSet;

template <typename LinkedHashSet>
class LinkedHashSetIterator;
template <typename LinkedHashSet>
class LinkedHashSetConstIterator;
template <typename LinkedHashSet>
class LinkedHashSetReverseIterator;
template <typename LinkedHashSet>
class LinkedHashSetConstReverseIterator;

template <typename Value, typename HashFunctions, typename Allocator>
struct LinkedHashSetTranslator;
template <typename Value, typename Allocator>
struct LinkedHashSetExtractor;
template <typename Value, typename ValueTraits, typename Allocator>
struct LinkedHashSetTraits;

class LinkedHashSetNodeBase {
    DISALLOW_NEW();

public:
    LinkedHashSetNodeBase()
        : m_prev(this)
        , m_next(this)
    {
    }

    NO_SANITIZE_ADDRESS
=======
template<typename Value, typename HashFunctions, typename HashTraits, typename Allocator> class LinkedHashSet;

template<typename LinkedHashSet> class LinkedHashSetIterator;
template<typename LinkedHashSet> class LinkedHashSetConstIterator;
template<typename LinkedHashSet> class LinkedHashSetReverseIterator;
template<typename LinkedHashSet> class LinkedHashSetConstReverseIterator;

template<typename Value, typename HashFunctions, typename Allocator> struct LinkedHashSetTranslator;
template<typename Value, typename Allocator> struct LinkedHashSetExtractor;
template<typename Value, typename ValueTraits, typename Allocator> struct LinkedHashSetTraits;

class LinkedHashSetNodeBase {
public:
    LinkedHashSetNodeBase() : m_prev(this), m_next(this) { }

    NO_LAZY_SWEEP_SANITIZE_ADDRESS
>>>>>>> miniblink49
    void unlink()
    {
        if (!m_next)
            return;
<<<<<<< HEAD
        DCHECK(m_prev);
        DCHECK(m_next->m_prev == this);
        DCHECK(m_prev->m_next == this);
=======
        ASSERT(m_prev);
        ASSERT(m_next->m_prev == this);
        ASSERT(m_prev->m_next == this);
>>>>>>> miniblink49
        m_next->m_prev = m_prev;
        m_prev->m_next = m_next;
    }

<<<<<<< HEAD
    ~LinkedHashSetNodeBase() { unlink(); }
=======
    ~LinkedHashSetNodeBase()
    {
        unlink();
    }
>>>>>>> miniblink49

    void insertBefore(LinkedHashSetNodeBase& other)
    {
        other.m_next = this;
        other.m_prev = m_prev;
        m_prev->m_next = &other;
        m_prev = &other;
<<<<<<< HEAD
        DCHECK(other.m_next);
        DCHECK(other.m_prev);
        DCHECK(m_next);
        DCHECK(m_prev);
=======
        ASSERT(other.m_next);
        ASSERT(other.m_prev);
        ASSERT(m_next);
        ASSERT(m_prev);
>>>>>>> miniblink49
    }

    void insertAfter(LinkedHashSetNodeBase& other)
    {
        other.m_prev = this;
        other.m_next = m_next;
        m_next->m_prev = &other;
        m_next = &other;
<<<<<<< HEAD
        DCHECK(other.m_next);
        DCHECK(other.m_prev);
        DCHECK(m_next);
        DCHECK(m_prev);
    }

    LinkedHashSetNodeBase(LinkedHashSetNodeBase* prev,
        LinkedHashSetNodeBase* next)
        : m_prev(prev)
        , m_next(next)
    {
        DCHECK((prev && next) || (!prev && !next));
=======
        ASSERT(other.m_next);
        ASSERT(other.m_prev);
        ASSERT(m_next);
        ASSERT(m_prev);
    }

    LinkedHashSetNodeBase(LinkedHashSetNodeBase* prev, LinkedHashSetNodeBase* next)
        : m_prev(prev)
        , m_next(next)
    {
        ASSERT((prev && next) || (!prev && !next));
>>>>>>> miniblink49
    }

    LinkedHashSetNodeBase* m_prev;
    LinkedHashSetNodeBase* m_next;

protected:
    // If we take a copy of a node we can't copy the next and prev pointers,
    // since they point to something that does not point at us. This is used
    // inside the shouldExpand() "if" in HashTable::add.
    LinkedHashSetNodeBase(const LinkedHashSetNodeBase& other)
        : m_prev(0)
<<<<<<< HEAD
        , m_next(0)
    {
    }

    LinkedHashSetNodeBase(LinkedHashSetNodeBase&& other)
        : m_prev(other.m_prev)
        , m_next(other.m_next)
    {
        other.m_prev = nullptr;
        other.m_next = nullptr;
        if (m_next) {
            m_prev->m_next = this;
            m_next->m_prev = this;
        }
    }
=======
        , m_next(0) { }
>>>>>>> miniblink49

private:
    // Should not be used.
    LinkedHashSetNodeBase& operator=(const LinkedHashSetNodeBase& other);
};

<<<<<<< HEAD
template <typename ValueArg, typename Allocator>
class LinkedHashSetNode : public LinkedHashSetNodeBase {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    LinkedHashSetNode(const ValueArg& value,
        LinkedHashSetNodeBase* prev,
        LinkedHashSetNodeBase* next)
=======
template<typename ValueArg, typename Allocator>
class LinkedHashSetNode : public LinkedHashSetNodeBase {
public:
    LinkedHashSetNode(const ValueArg& value, LinkedHashSetNodeBase* prev, LinkedHashSetNodeBase* next)
>>>>>>> miniblink49
        : LinkedHashSetNodeBase(prev, next)
        , m_value(value)
    {
    }

<<<<<<< HEAD
    LinkedHashSetNode(LinkedHashSetNode&& other)
        : LinkedHashSetNodeBase(std::move(other))
        , m_value(std::move(other.m_value))
    {
    }

    ValueArg m_value;

private:
    WTF_MAKE_NONCOPYABLE(LinkedHashSetNode);
};

template <typename ValueArg,
    typename HashFunctions = typename DefaultHash<ValueArg>::Hash,
    typename TraitsArg = HashTraits<ValueArg>,
    typename Allocator = PartitionAllocator>
class LinkedHashSet {
    USE_ALLOCATOR(LinkedHashSet, Allocator);

=======
    ValueArg m_value;

private:
    // Not used.
    LinkedHashSetNode(const LinkedHashSetNode&);
};

template<
    typename ValueArg,
    typename HashFunctions = typename DefaultHash<ValueArg>::Hash,
    typename TraitsArg = HashTraits<ValueArg>,
    typename Allocator = DefaultAllocator>
class LinkedHashSet {
    WTF_USE_ALLOCATOR(LinkedHashSet, Allocator);
>>>>>>> miniblink49
private:
    typedef ValueArg Value;
    typedef TraitsArg Traits;
    typedef LinkedHashSetNode<Value, Allocator> Node;
    typedef LinkedHashSetNodeBase NodeBase;
<<<<<<< HEAD
    typedef LinkedHashSetTranslator<Value, HashFunctions, Allocator>
        NodeHashFunctions;
    typedef LinkedHashSetTraits<Value, Traits, Allocator> NodeHashTraits;

    typedef HashTable<Node,
        Node,
        IdentityExtractor,
        NodeHashFunctions,
        NodeHashTraits,
        NodeHashTraits,
        Allocator>
        ImplType;
=======
    typedef LinkedHashSetTranslator<Value, HashFunctions, Allocator> NodeHashFunctions;
    typedef LinkedHashSetTraits<Value, Traits, Allocator> NodeHashTraits;

    typedef HashTable<Node, Node, IdentityExtractor,
        NodeHashFunctions, NodeHashTraits, NodeHashTraits, Allocator> ImplType;
>>>>>>> miniblink49

public:
    typedef LinkedHashSetIterator<LinkedHashSet> iterator;
    friend class LinkedHashSetIterator<LinkedHashSet>;
    typedef LinkedHashSetConstIterator<LinkedHashSet> const_iterator;
    friend class LinkedHashSetConstIterator<LinkedHashSet>;

    typedef LinkedHashSetReverseIterator<LinkedHashSet> reverse_iterator;
    friend class LinkedHashSetReverseIterator<LinkedHashSet>;
<<<<<<< HEAD
    typedef LinkedHashSetConstReverseIterator<LinkedHashSet>
        const_reverse_iterator;
    friend class LinkedHashSetConstReverseIterator<LinkedHashSet>;

    struct AddResult final {
        STACK_ALLOCATED();
=======
    typedef LinkedHashSetConstReverseIterator<LinkedHashSet> const_reverse_iterator;
    friend class LinkedHashSetConstReverseIterator<LinkedHashSet>;

    struct AddResult {
>>>>>>> miniblink49
        AddResult(const typename ImplType::AddResult& hashTableAddResult)
            : storedValue(&hashTableAddResult.storedValue->m_value)
            , isNewEntry(hashTableAddResult.isNewEntry)
        {
        }

        Value* storedValue;
        bool isNewEntry;
    };

    typedef typename HashTraits<Value>::PeekInType ValuePeekInType;

    LinkedHashSet();
    LinkedHashSet(const LinkedHashSet&);
<<<<<<< HEAD
    LinkedHashSet(LinkedHashSet&&);
    LinkedHashSet& operator=(const LinkedHashSet&);
    LinkedHashSet& operator=(LinkedHashSet&&);
=======
    LinkedHashSet& operator=(const LinkedHashSet&);
>>>>>>> miniblink49

    // Needs finalization. The anchor needs to unlink itself from the chain.
    ~LinkedHashSet();

<<<<<<< HEAD
    static void finalize(void* pointer)
    {
        reinterpret_cast<LinkedHashSet*>(pointer)->~LinkedHashSet();
    }
=======
    static void finalize(void* pointer) { reinterpret_cast<LinkedHashSet*>(pointer)->~LinkedHashSet(); }
>>>>>>> miniblink49
    void finalizeGarbageCollectedObject() { finalize(this); }

    void swap(LinkedHashSet&);

    unsigned size() const { return m_impl.size(); }
    unsigned capacity() const { return m_impl.capacity(); }
    bool isEmpty() const { return m_impl.isEmpty(); }

    iterator begin() { return makeIterator(firstNode()); }
    iterator end() { return makeIterator(anchor()); }
    const_iterator begin() const { return makeConstIterator(firstNode()); }
    const_iterator end() const { return makeConstIterator(anchor()); }

    reverse_iterator rbegin() { return makeReverseIterator(lastNode()); }
    reverse_iterator rend() { return makeReverseIterator(anchor()); }
<<<<<<< HEAD
    const_reverse_iterator rbegin() const
    {
        return makeConstReverseIterator(lastNode());
    }
    const_reverse_iterator rend() const
    {
        return makeConstReverseIterator(anchor());
    }
=======
    const_reverse_iterator rbegin() const { return makeConstReverseIterator(lastNode()); }
    const_reverse_iterator rend() const { return makeConstReverseIterator(anchor()); }
>>>>>>> miniblink49

    Value& first();
    const Value& first() const;
    void removeFirst();

    Value& last();
    const Value& last() const;
    void removeLast();

    iterator find(ValuePeekInType);
    const_iterator find(ValuePeekInType) const;
    bool contains(ValuePeekInType) const;

<<<<<<< HEAD
    // An alternate version of find() that finds the object by hashing and
    // comparing with some other type, to avoid the cost of type conversion.
    // The HashTranslator interface is defined in HashSet.
    template <typename HashTranslator, typename T>
    iterator find(const T&);
    template <typename HashTranslator, typename T>
    const_iterator find(const T&) const;
    template <typename HashTranslator, typename T>
    bool contains(const T&) const;

    // The return value of add is a pair of a pointer to the stored value,
    // and a bool that is true if an new entry was added.
    template <typename IncomingValueType>
    AddResult add(IncomingValueType&&);
=======
    // An alternate version of find() that finds the object by hashing and comparing
    // with some other type, to avoid the cost of type conversion.
    // The HashTranslator interface is defined in HashSet.
    template<typename HashTranslator, typename T> iterator find(const T&);
    template<typename HashTranslator, typename T> const_iterator find(const T&) const;
    template<typename HashTranslator, typename T> bool contains(const T&) const;

    // The return value of add is a pair of a pointer to the stored value,
    // and a bool that is true if an new entry was added.
    AddResult add(ValuePeekInType);
>>>>>>> miniblink49

    // Same as add() except that the return value is an
    // iterator. Useful in cases where it's needed to have the
    // same return value as find() and where it's not possible to
    // use a pointer to the storedValue.
<<<<<<< HEAD
    template <typename IncomingValueType>
    iterator addReturnIterator(IncomingValueType&&);

    // Add the value to the end of the collection. If the value was already in
    // the list, it is moved to the end.
    template <typename IncomingValueType>
    AddResult appendOrMoveToLast(IncomingValueType&&);

    // Add the value to the beginning of the collection. If the value was already
    // in the list, it is moved to the beginning.
    template <typename IncomingValueType>
    AddResult prependOrMoveToFirst(IncomingValueType&&);

    template <typename IncomingValueType>
    AddResult insertBefore(ValuePeekInType beforeValue,
        IncomingValueType&& newValue);
    template <typename IncomingValueType>
    AddResult insertBefore(iterator it, IncomingValueType&& newValue)
    {
        return m_impl.template add<NodeHashFunctions>(
            std::forward<IncomingValueType>(newValue), it.getNode());
    }
=======
    iterator addReturnIterator(ValuePeekInType);

    // Add the value to the end of the collection. If the value was already in
    // the list, it is moved to the end.
    AddResult appendOrMoveToLast(ValuePeekInType);

    // Add the value to the beginning of the collection. If the value was already in
    // the list, it is moved to the beginning.
    AddResult prependOrMoveToFirst(ValuePeekInType);

    AddResult insertBefore(ValuePeekInType beforeValue, ValuePeekInType newValue);
    AddResult insertBefore(iterator it, ValuePeekInType newValue) { return m_impl.template add<NodeHashFunctions>(newValue, it.node()); }
>>>>>>> miniblink49

    void remove(ValuePeekInType);
    void remove(iterator);
    void clear() { m_impl.clear(); }
<<<<<<< HEAD
    template <typename Collection>
    void removeAll(const Collection& other)
    {
        WTF::removeAll(*this, other);
    }

    template <typename VisitorDispatcher>
    void trace(VisitorDispatcher visitor)
    {
        m_impl.trace(visitor);
        // Should the underlying table be moved by GC, register a callback
        // that fixes up the interior pointers that the (Heap)LinkedHashSet keeps.
        if (m_impl.m_table) {
            Allocator::registerBackingStoreCallback(
                visitor, m_impl.m_table, moveBackingCallback,
                reinterpret_cast<void*>(&m_anchor));
        }
    }

    int64_t modifications() const { return m_impl.modifications(); }
    void checkModifications(int64_t mods) const
    {
        m_impl.checkModifications(mods);
    }

private:
    Node* anchor() { return reinterpret_cast<Node*>(&m_anchor); }
    const Node* anchor() const
    {
        return reinterpret_cast<const Node*>(&m_anchor);
    }
    Node* firstNode() { return reinterpret_cast<Node*>(m_anchor.m_next); }
    const Node* firstNode() const
    {
        return reinterpret_cast<const Node*>(m_anchor.m_next);
    }
    Node* lastNode() { return reinterpret_cast<Node*>(m_anchor.m_prev); }
    const Node* lastNode() const
    {
        return reinterpret_cast<const Node*>(m_anchor.m_prev);
    }

    iterator makeIterator(const Node* position)
    {
        return iterator(position, this);
    }
    const_iterator makeConstIterator(const Node* position) const
    {
        return const_iterator(position, this);
    }
    reverse_iterator makeReverseIterator(const Node* position)
    {
        return reverse_iterator(position, this);
    }
    const_reverse_iterator makeConstReverseIterator(const Node* position) const
    {
        return const_reverse_iterator(position, this);
    }

    static void moveBackingCallback(void* anchor,
        void* from,
        void* to,
        size_t size)
    {
        // Note: the hash table move may have been overlapping; linearly scan the
        // entire table and fixup interior pointers into the old region with
        // correspondingly offset ones into the new.
        size_t tableSize = size / sizeof(Node);
        Node* table = reinterpret_cast<Node*>(to);
        NodeBase* fromStart = reinterpret_cast<NodeBase*>(from);
        NodeBase* fromEnd = reinterpret_cast<NodeBase*>(reinterpret_cast<uintptr_t>(from) + size);
        for (Node* element = table + tableSize - 1; element >= table; element--) {
            Node& node = *element;
            if (ImplType::isEmptyOrDeletedBucket(node))
                continue;
            if (node.m_next >= fromStart && node.m_next < fromEnd) {
                size_t diff = reinterpret_cast<uintptr_t>(node.m_next) - reinterpret_cast<uintptr_t>(from);
                node.m_next = reinterpret_cast<NodeBase*>(reinterpret_cast<uintptr_t>(to) + diff);
            }
            if (node.m_prev >= fromStart && node.m_prev < fromEnd) {
                size_t diff = reinterpret_cast<uintptr_t>(node.m_prev) - reinterpret_cast<uintptr_t>(from);
                node.m_prev = reinterpret_cast<NodeBase*>(reinterpret_cast<uintptr_t>(to) + diff);
            }
        }
        NodeBase* anchorNode = reinterpret_cast<NodeBase*>(anchor);
        if (anchorNode->m_next >= fromStart && anchorNode->m_next < fromEnd) {
            size_t diff = reinterpret_cast<uintptr_t>(anchorNode->m_next) - reinterpret_cast<uintptr_t>(from);
            anchorNode->m_next = reinterpret_cast<NodeBase*>(reinterpret_cast<uintptr_t>(to) + diff);
        }
        if (anchorNode->m_prev >= fromStart && anchorNode->m_prev < fromEnd) {
            size_t diff = reinterpret_cast<uintptr_t>(anchorNode->m_prev) - reinterpret_cast<uintptr_t>(from);
            anchorNode->m_prev = reinterpret_cast<NodeBase*>(reinterpret_cast<uintptr_t>(to) + diff);
        }
    }
=======
    template<typename Collection>
    void removeAll(const Collection& other) { WTF::removeAll(*this, other); }

    using HasInlinedTraceMethodMarker = int;
    template<typename VisitorDispatcher>
    void trace(VisitorDispatcher visitor) { m_impl.trace(visitor); }

    int64_t modifications() const { return m_impl.modifications(); }
    void checkModifications(int64_t mods) const { m_impl.checkModifications(mods); }

private:
    Node* anchor() { return reinterpret_cast<Node*>(&m_anchor); }
    const Node* anchor() const { return reinterpret_cast<const Node*>(&m_anchor); }
    Node* firstNode() { return reinterpret_cast<Node*>(m_anchor.m_next); }
    const Node* firstNode() const { return reinterpret_cast<const Node*>(m_anchor.m_next); }
    Node* lastNode() { return reinterpret_cast<Node*>(m_anchor.m_prev); }
    const Node* lastNode() const { return reinterpret_cast<const Node*>(m_anchor.m_prev); }

    iterator makeIterator(const Node* position) { return iterator(position, this); }
    const_iterator makeConstIterator(const Node* position) const { return const_iterator(position, this); }
    reverse_iterator makeReverseIterator(const Node* position) { return reverse_iterator(position, this); }
    const_reverse_iterator makeConstReverseIterator(const Node* position) const { return const_reverse_iterator(position, this); }
>>>>>>> miniblink49

    ImplType m_impl;
    NodeBase m_anchor;
};

<<<<<<< HEAD
template <typename Value, typename HashFunctions, typename Allocator>
struct LinkedHashSetTranslator {
    STATIC_ONLY(LinkedHashSetTranslator);
    typedef LinkedHashSetNode<Value, Allocator> Node;
    typedef LinkedHashSetNodeBase NodeBase;
    typedef typename HashTraits<Value>::PeekInType ValuePeekInType;
    static unsigned hash(const Node& node)
    {
        return HashFunctions::hash(node.m_value);
    }
    static unsigned hash(const ValuePeekInType& key)
    {
        return HashFunctions::hash(key);
    }
    static bool equal(const Node& a, const ValuePeekInType& b)
    {
        return HashFunctions::equal(a.m_value, b);
    }
    static bool equal(const Node& a, const Node& b)
    {
        return HashFunctions::equal(a.m_value, b.m_value);
    }
    template <typename IncomingValueType>
    static void translate(Node& location,
        IncomingValueType&& key,
        NodeBase* anchor)
    {
        anchor->insertBefore(location);
        location.m_value = std::forward<IncomingValueType>(key);
=======
template<typename Value, typename HashFunctions, typename Allocator>
struct LinkedHashSetTranslator {
    typedef LinkedHashSetNode<Value, Allocator> Node;
    typedef LinkedHashSetNodeBase NodeBase;
    typedef typename HashTraits<Value>::PeekInType ValuePeekInType;
    static unsigned hash(const Node& node) { return HashFunctions::hash(node.m_value); }
    static unsigned hash(const ValuePeekInType& key) { return HashFunctions::hash(key); }
    static bool equal(const Node& a, const ValuePeekInType& b) { return HashFunctions::equal(a.m_value, b); }
    static bool equal(const Node& a, const Node& b) { return HashFunctions::equal(a.m_value, b.m_value); }
    static void translate(Node& location, ValuePeekInType key, NodeBase* anchor)
    {
        anchor->insertBefore(location);
        location.m_value = key;
>>>>>>> miniblink49
    }

    // Empty (or deleted) slots have the m_next pointer set to null, but we
    // don't do anything to the other fields, which may contain junk.
    // Therefore you can't compare a newly constructed empty value with a
    // slot and get the right answer.
    static const bool safeToCompareToEmptyOrDeleted = false;
};

<<<<<<< HEAD
template <typename Value, typename Allocator>
struct LinkedHashSetExtractor {
    STATIC_ONLY(LinkedHashSetExtractor);
    static const Value& extract(const LinkedHashSetNode<Value, Allocator>& node)
    {
        return node.m_value;
    }
};

template <typename Value, typename ValueTraitsArg, typename Allocator>
struct LinkedHashSetTraits
    : public SimpleClassHashTraits<LinkedHashSetNode<Value, Allocator>> {
    STATIC_ONLY(LinkedHashSetTraits);
=======
template<typename Value, typename Allocator>
struct LinkedHashSetExtractor {
    static const Value& extract(const LinkedHashSetNode<Value, Allocator>& node) { return node.m_value; }
};

template<typename Value, typename ValueTraitsArg, typename Allocator>
struct LinkedHashSetTraits : public SimpleClassHashTraits<LinkedHashSetNode<Value, Allocator>> {
>>>>>>> miniblink49
    typedef LinkedHashSetNode<Value, Allocator> Node;
    typedef ValueTraitsArg ValueTraits;

    // The slot is empty when the m_next field is zero so it's safe to zero
    // the backing.
    static const bool emptyValueIsZero = true;

    static const bool hasIsEmptyValueFunction = true;
    static bool isEmptyValue(const Node& node) { return !node.m_next; }

    static const int deletedValue = -1;

<<<<<<< HEAD
    static void constructDeletedValue(Node& slot, bool)
    {
        slot.m_next = reinterpret_cast<Node*>(deletedValue);
    }
    static bool isDeletedValue(const Node& slot)
    {
        return slot.m_next == reinterpret_cast<Node*>(deletedValue);
    }

    // Whether we need to trace and do weak processing depends on the traits of
    // the type inside the node.
    template <typename U = void>
    struct IsTraceableInCollection {
        STATIC_ONLY(IsTraceableInCollection);
        static const bool value = ValueTraits::template IsTraceableInCollection<>::value;
=======
    static void constructDeletedValue(Node& slot, bool) { slot.m_next = reinterpret_cast<Node*>(deletedValue); }
    static bool isDeletedValue(const Node& slot) { return slot.m_next == reinterpret_cast<Node*>(deletedValue); }

    // Whether we need to trace and do weak processing depends on the traits of
    // the type inside the node.
    template<typename U = void>
    struct NeedsTracingLazily {
        static const bool value = ValueTraits::template NeedsTracingLazily<>::value;
>>>>>>> miniblink49
    };
    static const WeakHandlingFlag weakHandlingFlag = ValueTraits::weakHandlingFlag;
};

<<<<<<< HEAD
template <typename LinkedHashSetType>
class LinkedHashSetIterator {
    DISALLOW_NEW();

=======
template<typename LinkedHashSetType>
class LinkedHashSetIterator {
>>>>>>> miniblink49
private:
    typedef typename LinkedHashSetType::Node Node;
    typedef typename LinkedHashSetType::Traits Traits;

    typedef typename LinkedHashSetType::Value& ReferenceType;
    typedef typename LinkedHashSetType::Value* PointerType;

    typedef LinkedHashSetConstIterator<LinkedHashSetType> const_iterator;

<<<<<<< HEAD
    Node* getNode() { return const_cast<Node*>(m_iterator.getNode()); }

protected:
    LinkedHashSetIterator(const Node* position, LinkedHashSetType* m_container)
        : m_iterator(position, m_container)
=======
    Node* node() { return const_cast<Node*>(m_iterator.node()); }

protected:
    LinkedHashSetIterator(const Node* position, LinkedHashSetType* m_container)
        : m_iterator(position , m_container)
>>>>>>> miniblink49
    {
    }

public:
    // Default copy, assignment and destructor are OK.

    PointerType get() const { return const_cast<PointerType>(m_iterator.get()); }
    ReferenceType operator*() const { return *get(); }
    PointerType operator->() const { return get(); }

<<<<<<< HEAD
    LinkedHashSetIterator& operator++()
    {
        ++m_iterator;
        return *this;
    }
    LinkedHashSetIterator& operator--()
    {
        --m_iterator;
        return *this;
    }
=======
    LinkedHashSetIterator& operator++() { ++m_iterator; return *this; }
    LinkedHashSetIterator& operator--() { --m_iterator; return *this; }
>>>>>>> miniblink49

    // Postfix ++ and -- intentionally omitted.

    // Comparison.
<<<<<<< HEAD
    bool operator==(const LinkedHashSetIterator& other) const
    {
        return m_iterator == other.m_iterator;
    }
    bool operator!=(const LinkedHashSetIterator& other) const
    {
        return m_iterator != other.m_iterator;
    }
=======
    bool operator==(const LinkedHashSetIterator& other) const { return m_iterator == other.m_iterator; }
    bool operator!=(const LinkedHashSetIterator& other) const { return m_iterator != other.m_iterator; }
>>>>>>> miniblink49

    operator const_iterator() const { return m_iterator; }

protected:
    const_iterator m_iterator;
<<<<<<< HEAD
    template <typename T, typename U, typename V, typename W>
    friend class LinkedHashSet;
};

template <typename LinkedHashSetType>
class LinkedHashSetConstIterator {
    DISALLOW_NEW();

=======
    template<typename T, typename U, typename V, typename W> friend class LinkedHashSet;
};

template<typename LinkedHashSetType>
class LinkedHashSetConstIterator {
>>>>>>> miniblink49
private:
    typedef typename LinkedHashSetType::Node Node;
    typedef typename LinkedHashSetType::Traits Traits;

    typedef const typename LinkedHashSetType::Value& ReferenceType;
    typedef const typename LinkedHashSetType::Value* PointerType;

<<<<<<< HEAD
    const Node* getNode() const { return static_cast<const Node*>(m_position); }

protected:
    LinkedHashSetConstIterator(const LinkedHashSetNodeBase* position,
        const LinkedHashSetType* container)
        : m_position(position)
#if DCHECK_IS_ON()
=======
    const Node* node() const { return static_cast<const Node*>(m_position); }

protected:
    LinkedHashSetConstIterator(const LinkedHashSetNodeBase* position, const LinkedHashSetType* container)
        : m_position(position)
#if ENABLE(ASSERT)
>>>>>>> miniblink49
        , m_container(container)
        , m_containerModifications(container->modifications())
#endif
    {
    }

public:
    PointerType get() const
    {
        checkModifications();
        return &static_cast<const Node*>(m_position)->m_value;
    }
    ReferenceType operator*() const { return *get(); }
    PointerType operator->() const { return get(); }

    LinkedHashSetConstIterator& operator++()
    {
<<<<<<< HEAD
        DCHECK(m_position);
=======
        ASSERT(m_position);
>>>>>>> miniblink49
        checkModifications();
        m_position = m_position->m_next;
        return *this;
    }

    LinkedHashSetConstIterator& operator--()
    {
<<<<<<< HEAD
        DCHECK(m_position);
=======
        ASSERT(m_position);
>>>>>>> miniblink49
        checkModifications();
        m_position = m_position->m_prev;
        return *this;
    }

    // Postfix ++ and -- intentionally omitted.

    // Comparison.
    bool operator==(const LinkedHashSetConstIterator& other) const
    {
        return m_position == other.m_position;
    }
    bool operator!=(const LinkedHashSetConstIterator& other) const
    {
        return m_position != other.m_position;
    }

private:
    const LinkedHashSetNodeBase* m_position;
<<<<<<< HEAD
#if DCHECK_IS_ON()
    void checkModifications() const
    {
        m_container->checkModifications(m_containerModifications);
    }
    const LinkedHashSetType* m_container;
    int64_t m_containerModifications;
#else
    void checkModifications() const
    {
    }
#endif
    template <typename T, typename U, typename V, typename W>
    friend class LinkedHashSet;
    friend class LinkedHashSetIterator<LinkedHashSetType>;
};

template <typename LinkedHashSetType>
class LinkedHashSetReverseIterator
    : public LinkedHashSetIterator<LinkedHashSetType> {
    typedef LinkedHashSetIterator<LinkedHashSetType> Superclass;
    typedef LinkedHashSetConstReverseIterator<LinkedHashSetType>
        const_reverse_iterator;
    typedef typename LinkedHashSetType::Node Node;

protected:
    LinkedHashSetReverseIterator(const Node* position,
        LinkedHashSetType* container)
        : Superclass(position, container)
    {
    }

public:
    LinkedHashSetReverseIterator& operator++()
    {
        Superclass::operator--();
        return *this;
    }
    LinkedHashSetReverseIterator& operator--()
    {
        Superclass::operator++();
        return *this;
    }

    // Postfix ++ and -- intentionally omitted.

    operator const_reverse_iterator() const
    {
        return *reinterpret_cast<const_reverse_iterator*>(this);
    }

    template <typename T, typename U, typename V, typename W>
    friend class LinkedHashSet;
};

template <typename LinkedHashSetType>
class LinkedHashSetConstReverseIterator
    : public LinkedHashSetConstIterator<LinkedHashSetType> {
=======
#if ENABLE(ASSERT)
    void checkModifications() const { m_container->checkModifications(m_containerModifications); }
    const LinkedHashSetType* m_container;
    int64_t m_containerModifications;
#else
    void checkModifications() const { }
#endif
    template<typename T, typename U, typename V, typename W> friend class LinkedHashSet;
    friend class LinkedHashSetIterator<LinkedHashSetType>;
};

template<typename LinkedHashSetType>
class LinkedHashSetReverseIterator : public LinkedHashSetIterator<LinkedHashSetType> {
    typedef LinkedHashSetIterator<LinkedHashSetType> Superclass;
    typedef LinkedHashSetConstReverseIterator<LinkedHashSetType> const_reverse_iterator;
    typedef typename LinkedHashSetType::Node Node;

protected:
    LinkedHashSetReverseIterator(const Node* position, LinkedHashSetType* container)
        : Superclass(position, container) { }

public:
    LinkedHashSetReverseIterator& operator++() { Superclass::operator--(); return *this; }
    LinkedHashSetReverseIterator& operator--() { Superclass::operator++(); return *this; }

    // Postfix ++ and -- intentionally omitted.

    operator const_reverse_iterator() const { return *reinterpret_cast<const_reverse_iterator*>(this); }

    template<typename T, typename U, typename V, typename W> friend class LinkedHashSet;
};

template<typename LinkedHashSetType>
class LinkedHashSetConstReverseIterator : public LinkedHashSetConstIterator<LinkedHashSetType> {
>>>>>>> miniblink49
    typedef LinkedHashSetConstIterator<LinkedHashSetType> Superclass;
    typedef typename LinkedHashSetType::Node Node;

public:
<<<<<<< HEAD
    LinkedHashSetConstReverseIterator(const Node* position,
        const LinkedHashSetType* container)
        : Superclass(position, container)
    {
    }

    LinkedHashSetConstReverseIterator& operator++()
    {
        Superclass::operator--();
        return *this;
    }
    LinkedHashSetConstReverseIterator& operator--()
    {
        Superclass::operator++();
        return *this;
    }

    // Postfix ++ and -- intentionally omitted.

    template <typename T, typename U, typename V, typename W>
    friend class LinkedHashSet;
};

template <typename T, typename U, typename V, typename Allocator>
inline LinkedHashSet<T, U, V, Allocator>::LinkedHashSet()
{
    static_assert(
        Allocator::isGarbageCollected || !IsPointerToGarbageCollectedType<T>::value,
        "Cannot put raw pointers to garbage-collected classes into "
        "an off-heap LinkedHashSet. Use HeapLinkedHashSet<Member<T>> instead.");
}

template <typename T, typename U, typename V, typename W>
=======
    LinkedHashSetConstReverseIterator(const Node* position, const LinkedHashSetType* container)
        : Superclass(position, container) { }

    LinkedHashSetConstReverseIterator& operator++() { Superclass::operator--(); return *this; }
    LinkedHashSetConstReverseIterator& operator--() { Superclass::operator++(); return *this; }

    // Postfix ++ and -- intentionally omitted.

    template<typename T, typename U, typename V, typename W> friend class LinkedHashSet;
};

template<typename T, typename U, typename V, typename W>
inline LinkedHashSet<T, U, V, W>::LinkedHashSet() { }

template<typename T, typename U, typename V, typename W>
>>>>>>> miniblink49
inline LinkedHashSet<T, U, V, W>::LinkedHashSet(const LinkedHashSet& other)
    : m_anchor()
{
    const_iterator end = other.end();
    for (const_iterator it = other.begin(); it != end; ++it)
        add(*it);
}

<<<<<<< HEAD
template <typename T, typename U, typename V, typename W>
inline LinkedHashSet<T, U, V, W>::LinkedHashSet(LinkedHashSet&& other)
    : m_anchor()
{
    swap(other);
}

template <typename T, typename U, typename V, typename W>
inline LinkedHashSet<T, U, V, W>& LinkedHashSet<T, U, V, W>::operator=(
    const LinkedHashSet& other)
=======
template<typename T, typename U, typename V, typename W>
inline LinkedHashSet<T, U, V, W>& LinkedHashSet<T, U, V, W>::operator=(const LinkedHashSet& other)
>>>>>>> miniblink49
{
    LinkedHashSet tmp(other);
    swap(tmp);
    return *this;
}

<<<<<<< HEAD
template <typename T, typename U, typename V, typename W>
inline LinkedHashSet<T, U, V, W>& LinkedHashSet<T, U, V, W>::operator=(
    LinkedHashSet&& other)
{
    swap(other);
    return *this;
}

template <typename T, typename U, typename V, typename W>
=======
template<typename T, typename U, typename V, typename W>
>>>>>>> miniblink49
inline void LinkedHashSet<T, U, V, W>::swap(LinkedHashSet& other)
{
    m_impl.swap(other.m_impl);
    swapAnchor(m_anchor, other.m_anchor);
}

<<<<<<< HEAD
template <typename T, typename U, typename V, typename Allocator>
=======
template<typename T, typename U, typename V, typename Allocator>
>>>>>>> miniblink49
inline LinkedHashSet<T, U, V, Allocator>::~LinkedHashSet()
{
    // The destructor of m_anchor will implicitly be called here, which will
    // unlink the anchor from the collection.
}

<<<<<<< HEAD
template <typename T, typename U, typename V, typename W>
inline T& LinkedHashSet<T, U, V, W>::first()
{
    DCHECK(!isEmpty());
    return firstNode()->m_value;
}

template <typename T, typename U, typename V, typename W>
inline const T& LinkedHashSet<T, U, V, W>::first() const
{
    DCHECK(!isEmpty());
    return firstNode()->m_value;
}

template <typename T, typename U, typename V, typename W>
inline void LinkedHashSet<T, U, V, W>::removeFirst()
{
    DCHECK(!isEmpty());
    m_impl.remove(static_cast<Node*>(m_anchor.m_next));
}

template <typename T, typename U, typename V, typename W>
inline T& LinkedHashSet<T, U, V, W>::last()
{
    DCHECK(!isEmpty());
    return lastNode()->m_value;
}

template <typename T, typename U, typename V, typename W>
inline const T& LinkedHashSet<T, U, V, W>::last() const
{
    DCHECK(!isEmpty());
    return lastNode()->m_value;
}

template <typename T, typename U, typename V, typename W>
inline void LinkedHashSet<T, U, V, W>::removeLast()
{
    DCHECK(!isEmpty());
    m_impl.remove(static_cast<Node*>(m_anchor.m_prev));
}

template <typename T, typename U, typename V, typename W>
inline typename LinkedHashSet<T, U, V, W>::iterator
LinkedHashSet<T, U, V, W>::find(ValuePeekInType value)
{
    LinkedHashSet::Node* node = m_impl.template lookup<LinkedHashSet::NodeHashFunctions, ValuePeekInType>(
        value);
=======
template<typename T, typename U, typename V, typename W>
inline T& LinkedHashSet<T, U, V, W>::first()
{
    ASSERT(!isEmpty());
    return firstNode()->m_value;
}

template<typename T, typename U, typename V, typename W>
inline const T& LinkedHashSet<T, U, V, W>::first() const
{
    ASSERT(!isEmpty());
    return firstNode()->m_value;
}

template<typename T, typename U, typename V, typename W>
inline void LinkedHashSet<T, U, V, W>::removeFirst()
{
    ASSERT(!isEmpty());
    m_impl.remove(static_cast<Node*>(m_anchor.m_next));
}

template<typename T, typename U, typename V, typename W>
inline T& LinkedHashSet<T, U, V, W>::last()
{
    ASSERT(!isEmpty());
    return lastNode()->m_value;
}

template<typename T, typename U, typename V, typename W>
inline const T& LinkedHashSet<T, U, V, W>::last() const
{
    ASSERT(!isEmpty());
    return lastNode()->m_value;
}

template<typename T, typename U, typename V, typename W>
inline void LinkedHashSet<T, U, V, W>::removeLast()
{
    ASSERT(!isEmpty());
    m_impl.remove(static_cast<Node*>(m_anchor.m_prev));
}

template<typename T, typename U, typename V, typename W>
inline typename LinkedHashSet<T, U, V, W>::iterator LinkedHashSet<T, U, V, W>::find(ValuePeekInType value)
{
    LinkedHashSet::Node* node = m_impl.template lookup<LinkedHashSet::NodeHashFunctions, ValuePeekInType>(value);
>>>>>>> miniblink49
    if (!node)
        return end();
    return makeIterator(node);
}

<<<<<<< HEAD
template <typename T, typename U, typename V, typename W>
inline typename LinkedHashSet<T, U, V, W>::const_iterator
LinkedHashSet<T, U, V, W>::find(ValuePeekInType value) const
{
    const LinkedHashSet::Node* node = m_impl.template lookup<LinkedHashSet::NodeHashFunctions, ValuePeekInType>(
        value);
=======
template<typename T, typename U, typename V, typename W>
inline typename LinkedHashSet<T, U, V, W>::const_iterator LinkedHashSet<T, U, V, W>::find(ValuePeekInType value) const
{
    const LinkedHashSet::Node* node = m_impl.template lookup<LinkedHashSet::NodeHashFunctions, ValuePeekInType>(value);
>>>>>>> miniblink49
    if (!node)
        return end();
    return makeConstIterator(node);
}

<<<<<<< HEAD
template <typename Translator>
struct LinkedHashSetTranslatorAdapter {
    STATIC_ONLY(LinkedHashSetTranslatorAdapter);
    template <typename T>
    static unsigned hash(const T& key)
    {
        return Translator::hash(key);
    }
    template <typename T, typename U>
    static bool equal(const T& a, const U& b)
    {
        return Translator::equal(a.m_value, b);
    }
};

template <typename Value, typename U, typename V, typename W>
template <typename HashTranslator, typename T>
inline typename LinkedHashSet<Value, U, V, W>::iterator
LinkedHashSet<Value, U, V, W>::find(const T& value)
=======
template<typename Translator>
struct LinkedHashSetTranslatorAdapter {
    template<typename T> static unsigned hash(const T& key) { return Translator::hash(key); }
    template<typename T, typename U> static bool equal(const T& a, const U& b) { return Translator::equal(a.m_value, b); }
};

template<typename Value, typename U, typename V, typename W>
template<typename HashTranslator, typename T>
inline typename LinkedHashSet<Value, U, V, W>::iterator LinkedHashSet<Value, U, V, W>::find(const T& value)
>>>>>>> miniblink49
{
    typedef LinkedHashSetTranslatorAdapter<HashTranslator> TranslatedFunctions;
    const LinkedHashSet::Node* node = m_impl.template lookup<TranslatedFunctions, const T&>(value);
    if (!node)
        return end();
    return makeIterator(node);
}

<<<<<<< HEAD
template <typename Value, typename U, typename V, typename W>
template <typename HashTranslator, typename T>
inline typename LinkedHashSet<Value, U, V, W>::const_iterator
LinkedHashSet<Value, U, V, W>::find(const T& value) const
=======
template<typename Value, typename U, typename V, typename W>
template<typename HashTranslator, typename T>
inline typename LinkedHashSet<Value, U, V, W>::const_iterator LinkedHashSet<Value, U, V, W>::find(const T& value) const
>>>>>>> miniblink49
{
    typedef LinkedHashSetTranslatorAdapter<HashTranslator> TranslatedFunctions;
    const LinkedHashSet::Node* node = m_impl.template lookup<TranslatedFunctions, const T&>(value);
    if (!node)
        return end();
    return makeConstIterator(node);
}

<<<<<<< HEAD
template <typename Value, typename U, typename V, typename W>
template <typename HashTranslator, typename T>
inline bool LinkedHashSet<Value, U, V, W>::contains(const T& value) const
{
    return m_impl
        .template contains<LinkedHashSetTranslatorAdapter<HashTranslator>>(value);
}

template <typename T, typename U, typename V, typename W>
=======
template<typename Value, typename U, typename V, typename W>
template<typename HashTranslator, typename T>
inline bool LinkedHashSet<Value, U, V, W>::contains(const T& value) const
{
    return m_impl.template contains<LinkedHashSetTranslatorAdapter<HashTranslator>>(value);
}

template<typename T, typename U, typename V, typename W>
>>>>>>> miniblink49
inline bool LinkedHashSet<T, U, V, W>::contains(ValuePeekInType value) const
{
    return m_impl.template contains<NodeHashFunctions>(value);
}

<<<<<<< HEAD
template <typename Value,
    typename HashFunctions,
    typename Traits,
    typename Allocator>
template <typename IncomingValueType>
typename LinkedHashSet<Value, HashFunctions, Traits, Allocator>::AddResult
LinkedHashSet<Value, HashFunctions, Traits, Allocator>::add(
    IncomingValueType&& value)
{
    return m_impl.template add<NodeHashFunctions>(
        std::forward<IncomingValueType>(value), &m_anchor);
}

template <typename T, typename U, typename V, typename W>
template <typename IncomingValueType>
typename LinkedHashSet<T, U, V, W>::iterator
LinkedHashSet<T, U, V, W>::addReturnIterator(IncomingValueType&& value)
{
    typename ImplType::AddResult result = m_impl.template add<NodeHashFunctions>(
        std::forward<IncomingValueType>(value), &m_anchor);
    return makeIterator(result.storedValue);
}

template <typename T, typename U, typename V, typename W>
template <typename IncomingValueType>
typename LinkedHashSet<T, U, V, W>::AddResult
LinkedHashSet<T, U, V, W>::appendOrMoveToLast(IncomingValueType&& value)
{
    typename ImplType::AddResult result = m_impl.template add<NodeHashFunctions>(
        std::forward<IncomingValueType>(value), &m_anchor);
=======
template<typename Value, typename HashFunctions, typename Traits, typename Allocator>
typename LinkedHashSet<Value, HashFunctions, Traits, Allocator>::AddResult LinkedHashSet<Value, HashFunctions, Traits, Allocator>::add(ValuePeekInType value)
{
    return m_impl.template add<NodeHashFunctions>(value, &m_anchor);
}

template<typename T, typename U, typename V, typename W>
typename LinkedHashSet<T, U, V, W>::iterator LinkedHashSet<T, U, V, W>::addReturnIterator(ValuePeekInType value)
{
    typename ImplType::AddResult result = m_impl.template add<NodeHashFunctions>(value, &m_anchor);
    return makeIterator(result.storedValue);
}

template<typename T, typename U, typename V, typename W>
typename LinkedHashSet<T, U, V, W>::AddResult LinkedHashSet<T, U, V, W>::appendOrMoveToLast(ValuePeekInType value)
{
    typename ImplType::AddResult result = m_impl.template add<NodeHashFunctions>(value, &m_anchor);
>>>>>>> miniblink49
    Node* node = result.storedValue;
    if (!result.isNewEntry) {
        node->unlink();
        m_anchor.insertBefore(*node);
    }
    return result;
}

<<<<<<< HEAD
template <typename T, typename U, typename V, typename W>
template <typename IncomingValueType>
typename LinkedHashSet<T, U, V, W>::AddResult
LinkedHashSet<T, U, V, W>::prependOrMoveToFirst(IncomingValueType&& value)
{
    typename ImplType::AddResult result = m_impl.template add<NodeHashFunctions>(
        std::forward<IncomingValueType>(value), m_anchor.m_next);
=======
template<typename T, typename U, typename V, typename W>
typename LinkedHashSet<T, U, V, W>::AddResult LinkedHashSet<T, U, V, W>::prependOrMoveToFirst(ValuePeekInType value)
{
    typename ImplType::AddResult result = m_impl.template add<NodeHashFunctions>(value, m_anchor.m_next);
>>>>>>> miniblink49
    Node* node = result.storedValue;
    if (!result.isNewEntry) {
        node->unlink();
        m_anchor.insertAfter(*node);
    }
    return result;
}

<<<<<<< HEAD
template <typename T, typename U, typename V, typename W>
template <typename IncomingValueType>
typename LinkedHashSet<T, U, V, W>::AddResult
LinkedHashSet<T, U, V, W>::insertBefore(ValuePeekInType beforeValue,
    IncomingValueType&& newValue)
{
    return insertBefore(find(beforeValue),
        std::forward<IncomingValueType>(newValue));
}

template <typename T, typename U, typename V, typename W>
=======
template<typename T, typename U, typename V, typename W>
typename LinkedHashSet<T, U, V, W>::AddResult LinkedHashSet<T, U, V, W>::insertBefore(ValuePeekInType beforeValue, ValuePeekInType newValue)
{
    return insertBefore(find(beforeValue), newValue);
}

template<typename T, typename U, typename V, typename W>
>>>>>>> miniblink49
inline void LinkedHashSet<T, U, V, W>::remove(iterator it)
{
    if (it == end())
        return;
<<<<<<< HEAD
    m_impl.remove(it.getNode());
}

template <typename T, typename U, typename V, typename W>
=======
    m_impl.remove(it.node());
}

template<typename T, typename U, typename V, typename W>
>>>>>>> miniblink49
inline void LinkedHashSet<T, U, V, W>::remove(ValuePeekInType value)
{
    remove(find(value));
}

inline void swapAnchor(LinkedHashSetNodeBase& a, LinkedHashSetNodeBase& b)
{
<<<<<<< HEAD
    DCHECK(a.m_prev);
    DCHECK(a.m_next);
    DCHECK(b.m_prev);
    DCHECK(b.m_next);
    swap(a.m_prev, b.m_prev);
    swap(a.m_next, b.m_next);
    if (b.m_next == &a) {
        DCHECK_EQ(b.m_prev, &a);
=======
    ASSERT(a.m_prev && a.m_next && b.m_prev && b.m_next);
    swap(a.m_prev, b.m_prev);
    swap(a.m_next, b.m_next);
    if (b.m_next == &a) {
        ASSERT(b.m_prev == &a);
>>>>>>> miniblink49
        b.m_next = &b;
        b.m_prev = &b;
    } else {
        b.m_next->m_prev = &b;
        b.m_prev->m_next = &b;
    }
    if (a.m_next == &b) {
<<<<<<< HEAD
        DCHECK_EQ(a.m_prev, &b);
=======
        ASSERT(a.m_prev == &b);
>>>>>>> miniblink49
        a.m_next = &a;
        a.m_prev = &a;
    } else {
        a.m_next->m_prev = &a;
        a.m_prev->m_next = &a;
    }
}

inline void swap(LinkedHashSetNodeBase& a, LinkedHashSetNodeBase& b)
{
<<<<<<< HEAD
    DCHECK_NE(a.m_next, &a);
    DCHECK_NE(b.m_next, &b);
=======
    ASSERT(a.m_next != &a && b.m_next != &b);
>>>>>>> miniblink49
    swap(a.m_prev, b.m_prev);
    swap(a.m_next, b.m_next);
    if (b.m_next) {
        b.m_next->m_prev = &b;
        b.m_prev->m_next = &b;
    }
    if (a.m_next) {
        a.m_next->m_prev = &a;
        a.m_prev->m_next = &a;
    }
}

<<<<<<< HEAD
template <typename T, typename Allocator>
inline void swap(LinkedHashSetNode<T, Allocator>& a,
    LinkedHashSetNode<T, Allocator>& b)
=======
template<typename T, typename Allocator>
inline void swap(LinkedHashSetNode<T, Allocator>& a, LinkedHashSetNode<T, Allocator>& b)
>>>>>>> miniblink49
{
    typedef LinkedHashSetNodeBase Base;
    // The key and value cannot be swapped atomically, and it would be
    // wrong to have a GC when only one was swapped and the other still
    // contained garbage (eg. from a previous use of the same slot).
    // Therefore we forbid a GC until both the key and the value are
    // swapped.
    Allocator::enterGCForbiddenScope();
    swap(static_cast<Base&>(a), static_cast<Base&>(b));
    swap(a.m_value, b.m_value);
    Allocator::leaveGCForbiddenScope();
}

<<<<<<< HEAD
} // namespace WTF
=======
// Warning: After and while calling this you have a collection with deleted
// pointers. Consider using a smart pointer like OwnPtr and calling clear()
// instead.
template<typename ValueType, typename T, typename U>
void deleteAllValues(const LinkedHashSet<ValueType, T, U>& set)
{
    typedef typename LinkedHashSet<ValueType, T, U>::const_iterator iterator;
    iterator end = set.end();
    for (iterator it = set.begin(); it != end; ++it)
        delete *it;
}

#if !ENABLE(OILPAN)
template<typename T, typename U, typename V>
struct NeedsTracing<LinkedHashSet<T, U, V>> {
    static const bool value = false;
};
#endif

}
>>>>>>> miniblink49

using WTF::LinkedHashSet;

#endif /* WTF_LinkedHashSet_h */
