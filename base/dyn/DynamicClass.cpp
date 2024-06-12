/*
 * DynamicClass.cpp
 *
 *  Created on: 2013-5-13
 *      Author: launliu
 */
#include "DynamicClass.h"
#include <cstddef>

#include "android/log.h"

typedef long Pointer;

namespace tencent {

inline static void* getVirtualMethod(void* instance, int offset)
{
    return reinterpret_cast<void*>(*(reinterpret_cast<int*>(*reinterpret_cast<int*>(instance)) + offset));
}

/*
有2种情况:
1，遇到虚表尾位置， 并且提供替换的虚函数已经全部替换完毕， 正常退出
2, 当虚表遇到纯虚函数， 而且提供替换的虚函数没有实现这个纯虚函数时， 非正常退出
存在虚表中函数指向为0的情况， 当包含纯虚构造函数时，
所以子类覆盖应格外注意， 提供替换的虚函数， 应实现所有的纯虚函数
*/
static int traverseVirtualTable(void** table, void* superInstance, const OverrideVirtualMethod* overrideMethods, size_t methodSize)
{
    int offset = 0;
    int hit = 0; //已命中的符号数目

    while (true) {
        void* vptr = getVirtualMethod(superInstance, offset);

        for (int i = 0; i < (int)methodSize && hit < (int)methodSize; i++) { //hit < methodSize， 需要替换的虚函数全部命中，即不用进入循环
            const OverrideVirtualMethod& method = overrideMethods[i];

            if (offset == method.virtualOffset) {
                vptr = method.clientMethod;
                hit++;
                break;
            }
        }

        if (vptr == 0) {
            break;
        }

        if (table) {
            table[offset] = vptr;
        }
        offset++;
    }

    if (table) {
        table[offset] = 0;
    }

    return offset + 1;
}

static void initializeVirtualTable(void**& table, void* superInstance, const OverrideVirtualMethod* passedMethods, size_t methodSize)
{
    size_t vtable_szie = traverseVirtualTable(0, superInstance, passedMethods, methodSize);
    typedef void* VoidPointer;
    table = new VoidPointer[vtable_szie];
    traverseVirtualTable(table, superInstance, passedMethods, methodSize);
}

struct DynamicInstance {
    void* clientData;
};

void* DynamicClass::internalAllocateInstance(size_t superClassSize, void* clientData)
{
    void* instance = new char[superClassSize + sizeof(DynamicInstance)];
    DynamicInstance* di = (DynamicInstance*)((char*)instance + superClassSize);
    di->clientData = clientData;
    return instance;
}

void DynamicClass::deallocateInstance(void* clientData)
{
    delete[](char*) clientData;
}

void DynamicClass::internalOverrideSuperclassInstance(void* superInstance)
{
    base::AutoLock lock(m_initializeLock);
    if (!m_virtualTable) {
        initializeVirtualTable(m_virtualTable, superInstance, m_overrideMethods, m_overrideMethodSize);
    }
    (*(Pointer*)superInstance) = (Pointer)m_virtualTable;
}

void* DynamicClass::internalGetDataFromSuperclassPointer(void* superInstance, size_t superClassSize)
{
    DynamicInstance* instance = (DynamicInstance*)((char*)superInstance + superClassSize);
    return instance->clientData;
}

DynamicClass::DynamicClass(OverrideVirtualMethod* methods, size_t size)
    : m_virtualTable(0)
{
    m_overrideMethods = new OverrideVirtualMethod[size];
    m_overrideMethodSize = size;

    // For client's methods
    for (size_t i = 0; i < size; i++) {
        m_overrideMethods[i] = methods[i];
    }
}

DynamicClass::~DynamicClass()
{
    if (m_virtualTable) {
        delete (m_virtualTable);
    }

    if (m_overrideMethods) {
        delete m_overrideMethods;
    }
}

} /* namespace tencent */
