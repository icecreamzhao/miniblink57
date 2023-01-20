/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkNetPipeController_DEFINED
#define SkNetPipeController_DEFINED
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkGPipe.h"
#include "SkSockets.h"
#include "SkTypes.h"
=======
#include "SkTypes.h"
#include "SkCanvas.h"
#include "SkGPipe.h"
#include "SkSockets.h"
>>>>>>> miniblink49
class SkNetPipeController : public SkGPipeController {
public:
    SkNetPipeController(SkCanvas* target);
    ~SkNetPipeController();

    virtual void* requestBlock(size_t minRequest, size_t* actual);
    virtual void notifyWritten(size_t bytes);

    int writeToSocket(SkSocket* sockfd, SkSocket::DataType type);
    void enablePlayback() { fPlayback = true; }
    void disablePlayback() { fPlayback = false; }

private:
<<<<<<< HEAD
    SkGPipeReader fReader;
    bool fPlayback;
    void* fBlock;
    size_t fBlockSize;
    size_t fBytesWritten;
    int fAtomsWritten;
    size_t fTotalWritten;

    SkGPipeReader::Status fStatus;
=======
    SkGPipeReader   fReader;
    bool            fPlayback;
    void*           fBlock;
    size_t          fBlockSize;
    size_t          fBytesWritten;
    int             fAtomsWritten;
    size_t          fTotalWritten;

    SkGPipeReader::Status   fStatus;
>>>>>>> miniblink49
};
#endif
