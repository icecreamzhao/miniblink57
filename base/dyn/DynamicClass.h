/*
 * DynamicClass.h
 *
 *  Created on: 2013-5-13
 *      Author: launliu
 */

#ifndef DYNAMICCLASS_H_
#define DYNAMICCLASS_H_

#include "DynamicMethod.h"
#include "base/macros.h"
#include "base/synchronization/lock.h"

namespace tencent {

struct OverrideVirtualMethod {
    void* clientMethod;
    int virtualOffset;
};

class DynamicClass {
public:
    DynamicClass(OverrideVirtualMethod* methods, size_t size);
    ~DynamicClass();

    template <class SuperClass>
    SuperClass* allocateInstance(void* clientData)
    {
        return (SuperClass*)internalAllocateInstance(sizeof(SuperClass), clientData);
    }

    static void deallocateInstance(void* clientData);

    template <class SuperClass>
    inline void overrideSuperclassInstance(SuperClass* instance)
    {
        internalOverrideSuperclassInstance(reinterpret_cast<void*>(instance));
    }

    template <class SuperClass, typename DataType>
    static inline DataType getDataFromSuperclassPointer(SuperClass* instance)
    {
        return reinterpret_cast<DataType>(internalGetDataFromSuperclassPointer(reinterpret_cast<void*>(instance), sizeof(SuperClass)));
    }

private:
    void* internalAllocateInstance(size_t superClassSize, void* clientData);
    void internalOverrideSuperclassInstance(void* superInstance);

    static void* internalGetDataFromSuperclassPointer(void* superClassPointer, size_t superClassSize);

private:
    void** m_virtualTable;

    OverrideVirtualMethod* m_overrideMethods;
    size_t m_overrideMethodSize;

    base::Lock m_initializeLock;

    DISALLOW_COPY(DynamicClass);
};

} /* namespace tencent */
#endif /* DYNAMICCLASS_H_ */
