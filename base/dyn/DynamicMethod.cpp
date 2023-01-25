/*
 * DynamicMethod.cpp
 *
 *  Created on: 2013年3月14日
 *      Author: launliu
 */

#include "DynamicMethod.h"

#define ISBIT64 (sizeof(void*) == 8)

namespace tencent {

void* getVirtualMethodAtOffset(void* instance, int offset)
{
    if (ISBIT64) {
        return reinterpret_cast<void*>(*(reinterpret_cast<long*>(*reinterpret_cast<long*>(instance)) + offset));
    } else {
        return reinterpret_cast<void*>(*(reinterpret_cast<int*>(*reinterpret_cast<int*>(instance)) + offset));
    }
}

int computeVirtualOffset(void* obj, void* method)
{
    int i = 0;
    while (void* entry = getVirtualMethodAtOffset(obj, i)) {
        if (method == entry)
            return i;
        i++;
    }

    return -1;
}

} //namespace tencent
