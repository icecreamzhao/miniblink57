/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkNetPipeController.h"

<<<<<<< HEAD
SkNetPipeController::SkNetPipeController(SkCanvas* target)
    : fReader(target)
{
=======
SkNetPipeController::SkNetPipeController(SkCanvas* target) : fReader(target) {
>>>>>>> miniblink49
    fBlock = NULL;
    fBlockSize = fBytesWritten = 0;
    fPlayback = true;
    fStatus = SkGPipeReader::kDone_Status;
    fTotalWritten = 0;
    fAtomsWritten = 0;
}
<<<<<<< HEAD
SkNetPipeController::~SkNetPipeController()
{
    sk_free(fBlock);
}

int SkNetPipeController::writeToSocket(SkSocket* sockfd, SkSocket::DataType type)
{
=======
SkNetPipeController::~SkNetPipeController() {
    sk_free(fBlock);
}

int SkNetPipeController::writeToSocket(SkSocket* sockfd, SkSocket::DataType type) {
>>>>>>> miniblink49
    if (NULL != sockfd && fTotalWritten > 4)
        return sockfd->writePacket(fBlock, fBytesWritten, type);
    else
        return -1;
}

<<<<<<< HEAD
void* SkNetPipeController::requestBlock(size_t minRequest, size_t* actual)
{
=======
void* SkNetPipeController::requestBlock(size_t minRequest, size_t* actual) {
>>>>>>> miniblink49
    sk_free(fBlock);

    fBlockSize = minRequest * 4;
    fBlock = sk_malloc_throw(fBlockSize);
    fBytesWritten = 0;
    *actual = fBlockSize;
    return fBlock;
}

<<<<<<< HEAD
void SkNetPipeController::notifyWritten(size_t bytes)
{
=======
void SkNetPipeController::notifyWritten(size_t bytes) {
>>>>>>> miniblink49
    SkASSERT(fBytesWritten + bytes <= fBlockSize);

    if (fPlayback) {
        fStatus = fReader.playback((const char*)fBlock + fBytesWritten, bytes);
    }

    SkASSERT(SkGPipeReader::kError_Status != fStatus);
    fBytesWritten += bytes;
    fTotalWritten += bytes;

    fAtomsWritten += 1;
}
