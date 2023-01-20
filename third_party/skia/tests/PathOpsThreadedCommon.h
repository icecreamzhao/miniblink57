/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef PathOpsThreadedCommon_DEFINED
#define PathOpsThreadedCommon_DEFINED

#include "SkGraphics.h"
<<<<<<< HEAD
=======
#include "SkRunnable.h"
>>>>>>> miniblink49
#include "SkTDArray.h"

#define PATH_STR_SIZE 512

class PathOpsThreadedRunnable;

namespace skiatest {
class Reporter;
}

struct PathOpsThreadState {
    unsigned char fA;
    unsigned char fB;
    unsigned char fC;
    unsigned char fD;
    char* fPathStr;
    const char* fKey;
    char fSerialNo[256];
    skiatest::Reporter* fReporter;
    SkBitmap* fBitmap;
};

class PathOpsThreadedTestRunner {
public:
<<<<<<< HEAD
    PathOpsThreadedTestRunner(skiatest::Reporter* reporter)
        : fReporter(reporter)
    {
    }
=======
    PathOpsThreadedTestRunner(skiatest::Reporter* reporter) : fReporter(reporter) {}
>>>>>>> miniblink49

    ~PathOpsThreadedTestRunner();

    void render();

public:
    SkTDArray<PathOpsThreadedRunnable*> fRunnables;
    skiatest::Reporter* fReporter;
};

<<<<<<< HEAD
class PathOpsThreadedRunnable {
public:
    PathOpsThreadedRunnable(void (*testFun)(PathOpsThreadState*), int a, int b, int c, int d,
        PathOpsThreadedTestRunner* runner)
    {
=======
class PathOpsThreadedRunnable : public SkRunnable {
public:
    PathOpsThreadedRunnable(void (*testFun)(PathOpsThreadState*), int a, int b, int c, int d,
            PathOpsThreadedTestRunner* runner) {
>>>>>>> miniblink49
        fState.fA = a;
        fState.fB = b;
        fState.fC = c;
        fState.fD = d;
        fState.fReporter = runner->fReporter;
        fTestFun = testFun;
    }

    PathOpsThreadedRunnable(void (*testFun)(PathOpsThreadState*), const char* str,
<<<<<<< HEAD
        PathOpsThreadedTestRunner* runner)
    {
=======
            PathOpsThreadedTestRunner* runner) {
>>>>>>> miniblink49
        SkASSERT(strlen(str) < sizeof(fState.fSerialNo) - 1);
        strcpy(fState.fSerialNo, str);
        fState.fReporter = runner->fReporter;
        fTestFun = testFun;
    }

    PathOpsThreadedRunnable(void (*testFun)(PathOpsThreadState*), int dirNo, const char* str,
<<<<<<< HEAD
        PathOpsThreadedTestRunner* runner)
    {
=======
            PathOpsThreadedTestRunner* runner) {
>>>>>>> miniblink49
        SkASSERT(strlen(str) < sizeof(fState.fSerialNo) - 1);
        fState.fA = dirNo;
        strcpy(fState.fSerialNo, str);
        fState.fReporter = runner->fReporter;
        fTestFun = testFun;
    }

<<<<<<< HEAD
    void operator()()
    {
=======
    void run() override {
>>>>>>> miniblink49
        SkBitmap bitmap;
        fState.fBitmap = &bitmap;
        char pathStr[PATH_STR_SIZE];
        fState.fPathStr = pathStr;
        SkGraphics::SetTLSFontCacheLimit(1 * 1024 * 1024);
        (*fTestFun)(&fState);
    }

private:
    PathOpsThreadState fState;
    void (*fTestFun)(PathOpsThreadState*);
};

#endif
