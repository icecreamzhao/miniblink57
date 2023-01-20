/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkDiscardableMemoryPool.h"

#include "Test.h"

<<<<<<< HEAD
DEF_TEST(DiscardableMemoryPool, reporter)
{
    SkAutoTUnref<SkDiscardableMemoryPool> pool(
        SkDiscardableMemoryPool::Create(1, nullptr));
=======
DEF_TEST(DiscardableMemoryPool, reporter) {
    SkAutoTUnref<SkDiscardableMemoryPool> pool(
        SkDiscardableMemoryPool::Create(1, NULL));
>>>>>>> miniblink49
    pool->setRAMBudget(3);
    REPORTER_ASSERT(reporter, 0 == pool->getRAMUsed());

    SkAutoTDelete<SkDiscardableMemory> dm1(pool->create(100));
<<<<<<< HEAD
    REPORTER_ASSERT(reporter, dm1->data() != nullptr);
=======
    REPORTER_ASSERT(reporter, dm1->data() != NULL);
>>>>>>> miniblink49
    REPORTER_ASSERT(reporter, 100 == pool->getRAMUsed());
    dm1->unlock();
    REPORTER_ASSERT(reporter, 0 == pool->getRAMUsed());
    REPORTER_ASSERT(reporter, !dm1->lock());

<<<<<<< HEAD
=======

>>>>>>> miniblink49
    SkAutoTDelete<SkDiscardableMemory> dm2(pool->create(200));
    REPORTER_ASSERT(reporter, 200 == pool->getRAMUsed());
    pool->setRAMBudget(400);
    dm2->unlock();
    REPORTER_ASSERT(reporter, 200 == pool->getRAMUsed());
    REPORTER_ASSERT(reporter, dm2->lock());
    dm2->unlock();
    pool->dumpPool();
    REPORTER_ASSERT(reporter, !dm2->lock());
    REPORTER_ASSERT(reporter, 0 == pool->getRAMUsed());
}
