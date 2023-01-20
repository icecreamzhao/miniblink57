// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "platform/heap/BlinkGCMemoryDumpProvider.h"

#include "base/trace_event/process_memory_dump.h"
#include "public/platform/Platform.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "wtf/Threading.h"

=======
#include "config.h"
#include "platform/heap/BlinkGCMemoryDumpProvider.h"

#include "public/platform/Platform.h"
#include "public/platform/WebProcessMemoryDump.h"
#include "wtf/Threading.h"

#include <gtest/gtest.h>

>>>>>>> miniblink49
namespace blink {

TEST(BlinkGCDumpProviderTest, MemoryDump)
{
<<<<<<< HEAD
    base::trace_event::MemoryDumpArgs args = {
        base::trace_event::MemoryDumpLevelOfDetail::DETAILED
    };
    std::unique_ptr<base::trace_event::ProcessMemoryDump> dump(
        new base::trace_event::ProcessMemoryDump(nullptr, args));
    BlinkGCMemoryDumpProvider::instance()->OnMemoryDump(args, dump.get());
    DCHECK(dump->GetAllocatorDump("blink_gc"));
    DCHECK(dump->GetAllocatorDump("blink_gc/allocated_objects"));
=======
    WebProcessMemoryDump* dump  = Platform::current()->createProcessMemoryDump();
    ASSERT(dump);
    BlinkGCMemoryDumpProvider::instance()->onMemoryDump(dump);
    ASSERT(dump->getMemoryAllocatorDump(String::format("blink_gc/thread_%lu", static_cast<unsigned long>(WTF::currentThread()))));
    ASSERT(dump->getMemoryAllocatorDump(String::format("blink_gc/thread_%lu/allocated_objects", static_cast<unsigned long>(WTF::currentThread()))));
>>>>>>> miniblink49
}

} // namespace blink
