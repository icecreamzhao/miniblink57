<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkWriter32.h"

class WriterBench : public Benchmark {
public:
<<<<<<< HEAD
    bool isSuitableFor(Backend backend) override
    {
=======
    bool isSuitableFor(Backend backend) override {
>>>>>>> miniblink49
        return backend == kNonRendering_Backend;
    }

protected:
<<<<<<< HEAD
    const char* onGetName() override
    {
        return "writer";
    }

    void onDraw(int loops, SkCanvas*) override
    {
=======
    const char* onGetName() override {
        return "writer";
    }

    void onDraw(const int loops, SkCanvas*) override {
>>>>>>> miniblink49
        static const char gStr[] = "abcdefghimjklmnopqrstuvwxyz";
        static const size_t gLen = strlen(gStr);
        SkWriter32 writer;
        for (int i = 0; i < loops; i++) {
            for (size_t j = 0; j <= gLen; j++) {
                writer.writeString(gStr, j);
            }
        }
    }

private:
    typedef Benchmark INHERITED;
};

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new WriterBench();)
=======
DEF_BENCH( return new WriterBench(); )
>>>>>>> miniblink49
