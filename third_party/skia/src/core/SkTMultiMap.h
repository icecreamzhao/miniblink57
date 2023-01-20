<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkTMultiMap_DEFINED
#define SkTMultiMap_DEFINED

#include "GrTypes.h"
#include "SkTDynamicHash.h"

/** A set that contains pointers to instances of T. Instances can be looked up with key Key.
 * Multiple (possibly same) values can have the same key.
 */
template <typename T,
<<<<<<< HEAD
    typename Key,
    typename HashTraits = T>
class SkTMultiMap {
    struct ValueList {
        explicit ValueList(T* value)
            : fValue(value)
            , fNext(nullptr)
        {
        }
=======
          typename Key,
          typename HashTraits=T>
class SkTMultiMap {
    struct ValueList {
        explicit ValueList(T* value) : fValue(value), fNext(NULL) {}
>>>>>>> miniblink49

        static const Key& GetKey(const ValueList& e) { return HashTraits::GetKey(*e.fValue); }
        static uint32_t Hash(const Key& key) { return HashTraits::Hash(key); }
        T* fValue;
        ValueList* fNext;
    };
<<<<<<< HEAD

public:
    SkTMultiMap()
        : fCount(0)
    {
    }

    ~SkTMultiMap()
    {
=======
public:
    SkTMultiMap() : fCount(0) {}

    ~SkTMultiMap() {
>>>>>>> miniblink49
        SkASSERT(fCount == 0);
        SkASSERT(fHash.count() == 0);
    }

<<<<<<< HEAD
    void insert(const Key& key, T* value)
    {
=======
    void insert(const Key& key, T* value) {
>>>>>>> miniblink49
        ValueList* list = fHash.find(key);
        if (list) {
            // The new ValueList entry is inserted as the second element in the
            // linked list, and it will contain the value of the first element.
<<<<<<< HEAD
            ValueList* newEntry = new ValueList(list->fValue);
=======
            ValueList* newEntry = SkNEW_ARGS(ValueList, (list->fValue));
>>>>>>> miniblink49
            newEntry->fNext = list->fNext;
            // The existing first ValueList entry is updated to contain the
            // inserted value.
            list->fNext = newEntry;
            list->fValue = value;
        } else {
<<<<<<< HEAD
            fHash.add(new ValueList(value));
=======
            fHash.add(SkNEW_ARGS(ValueList, (value)));
>>>>>>> miniblink49
        }

        ++fCount;
    }

<<<<<<< HEAD
    void remove(const Key& key, const T* value)
    {
=======
    void remove(const Key& key, const T* value) {
>>>>>>> miniblink49
        ValueList* list = fHash.find(key);
        // Since we expect the caller to be fully aware of what is stored, just
        // assert that the caller removes an existing value.
        SkASSERT(list);
<<<<<<< HEAD
        ValueList* prev = nullptr;
=======
        ValueList* prev = NULL;
>>>>>>> miniblink49
        while (list->fValue != value) {
            prev = list;
            list = list->fNext;
        }

        if (list->fNext) {
            ValueList* next = list->fNext;
            list->fValue = next->fValue;
            list->fNext = next->fNext;
<<<<<<< HEAD
            delete next;
        } else if (prev) {
            prev->fNext = nullptr;
            delete list;
        } else {
            fHash.remove(key);
            delete list;
=======
            SkDELETE(next);
        } else if (prev) {
            prev->fNext = NULL;
            SkDELETE(list);
        } else {
            fHash.remove(key);
            SkDELETE(list);
>>>>>>> miniblink49
        }

        --fCount;
    }

<<<<<<< HEAD
    T* find(const Key& key) const
    {
=======
    T* find(const Key& key) const {
>>>>>>> miniblink49
        ValueList* list = fHash.find(key);
        if (list) {
            return list->fValue;
        }
<<<<<<< HEAD
        return nullptr;
    }

    template <class FindPredicate>
    T* find(const Key& key, const FindPredicate f)
    {
        ValueList* list = fHash.find(key);
        while (list) {
            if (f(list->fValue)) {
=======
        return NULL;
    }

    template<class FindPredicate>
    T* find(const Key& key, const FindPredicate f) {
        ValueList* list = fHash.find(key);
        while (list) {
            if (f(list->fValue)){
>>>>>>> miniblink49
                return list->fValue;
            }
            list = list->fNext;
        }
<<<<<<< HEAD
        return nullptr;
=======
        return NULL;
>>>>>>> miniblink49
    }

    int count() const { return fCount; }

#ifdef SK_DEBUG
<<<<<<< HEAD
    class ConstIter {
    public:
        explicit ConstIter(const SkTMultiMap* mmap)
            : fIter(&(mmap->fHash))
            , fList(nullptr)
        {
            if (!fIter.done()) {
                fList = &(*fIter);
            }
        }

        bool done() const
        {
            return fIter.done();
        }

        const T* operator*()
        {
            SkASSERT(fList);
            return fList->fValue;
        }

        void operator++()
        {
            if (fList) {
                fList = fList->fNext;
            }
            if (!fList) {
                ++fIter;
                if (!fIter.done()) {
                    fList = &(*fIter);
                }
            }
        }

    private:
        typename SkTDynamicHash<ValueList, Key>::ConstIter fIter;
        const ValueList* fList;
    };

    bool has(const T* value, const Key& key) const
    {
        for (ValueList* list = fHash.find(key); list; list = list->fNext) {
            if (list->fValue == value) {
                return true;
            }
        }
        return false;
    }

    // This is not particularly fast and only used for validation, so debug only.
    int countForKey(const Key& key) const
    {
=======
    // This is not particularly fast and only used for validation, so debug only.
    int countForKey(const Key& key) const {
>>>>>>> miniblink49
        int count = 0;
        ValueList* list = fHash.find(key);
        while (list) {
            list = list->fNext;
            ++count;
        }
        return count;
    }
#endif

private:
    SkTDynamicHash<ValueList, Key> fHash;
    int fCount;
};

#endif
