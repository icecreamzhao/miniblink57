/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrProcessor.h"
#include "GrContext.h"
<<<<<<< HEAD
=======
#include "GrCoordTransform.h"
>>>>>>> miniblink49
#include "GrGeometryProcessor.h"
#include "GrInvariantOutput.h"
#include "GrMemoryPool.h"
#include "GrXferProcessor.h"
#include "SkSpinlock.h"

#if SK_ALLOW_STATIC_GLOBAL_INITIALIZERS

class GrFragmentProcessor;
class GrGeometryProcessor;

/*
 * Originally these were both in the processor unit test header, but then it seemed to cause linker
 * problems on android.
 */
<<<<<<< HEAD
template <>
SkTArray<GrProcessorTestFactory<GrFragmentProcessor>*, true>*
GrProcessorTestFactory<GrFragmentProcessor>::GetFactories()
{
=======
template<>
SkTArray<GrProcessorTestFactory<GrFragmentProcessor>*, true>*
GrProcessorTestFactory<GrFragmentProcessor>::GetFactories() {
>>>>>>> miniblink49
    static SkTArray<GrProcessorTestFactory<GrFragmentProcessor>*, true> gFactories;
    return &gFactories;
}

<<<<<<< HEAD
template <>
SkTArray<GrProcessorTestFactory<GrXPFactory>*, true>*
GrProcessorTestFactory<GrXPFactory>::GetFactories()
{
=======
template<>
SkTArray<GrProcessorTestFactory<GrXPFactory>*, true>*
GrProcessorTestFactory<GrXPFactory>::GetFactories() {
>>>>>>> miniblink49
    static SkTArray<GrProcessorTestFactory<GrXPFactory>*, true> gFactories;
    return &gFactories;
}

<<<<<<< HEAD
template <>
SkTArray<GrProcessorTestFactory<GrGeometryProcessor>*, true>*
GrProcessorTestFactory<GrGeometryProcessor>::GetFactories()
{
=======
template<>
SkTArray<GrProcessorTestFactory<GrGeometryProcessor>*, true>*
GrProcessorTestFactory<GrGeometryProcessor>::GetFactories() {
>>>>>>> miniblink49
    static SkTArray<GrProcessorTestFactory<GrGeometryProcessor>*, true> gFactories;
    return &gFactories;
}

/*
 * To ensure we always have successful static initialization, before creating from the factories
 * we verify the count is as expected.  If a new factory is added, then these numbers must be
 * manually adjusted.
 */
<<<<<<< HEAD
static const int kFPFactoryCount = 40;
static const int kGPFactoryCount = 14;
static const int kXPFactoryCount = 6;

template <>
void GrProcessorTestFactory<GrFragmentProcessor>::VerifyFactoryCount()
{
=======
static const int kFPFactoryCount = 37;
static const int kGPFactoryCount = 14;
static const int kXPFactoryCount = 5;

template<>
void GrProcessorTestFactory<GrFragmentProcessor>::VerifyFactoryCount() {
>>>>>>> miniblink49
    if (kFPFactoryCount != GetFactories()->count()) {
        SkFAIL("Wrong number of fragment processor factories!");
    }
}

<<<<<<< HEAD
template <>
void GrProcessorTestFactory<GrGeometryProcessor>::VerifyFactoryCount()
{
=======
template<>
void GrProcessorTestFactory<GrGeometryProcessor>::VerifyFactoryCount() {
>>>>>>> miniblink49
    if (kGPFactoryCount != GetFactories()->count()) {
        SkFAIL("Wrong number of geometry processor factories!");
    }
}

<<<<<<< HEAD
template <>
void GrProcessorTestFactory<GrXPFactory>::VerifyFactoryCount()
{
=======
template<>
void GrProcessorTestFactory<GrXPFactory>::VerifyFactoryCount() {
>>>>>>> miniblink49
    if (kXPFactoryCount != GetFactories()->count()) {
        SkFAIL("Wrong number of xp factory factories!");
    }
}

#endif

<<<<<<< HEAD
=======

>>>>>>> miniblink49
// We use a global pool protected by a mutex(spinlock). Chrome may use the same GrContext on
// different threads. The GrContext is not used concurrently on different threads and there is a
// memory barrier between accesses of a context on different threads. Also, there may be multiple
// GrContexts and those contexts may be in use concurrently on different threads.
namespace {
<<<<<<< HEAD
static SkSpinlock gProcessorSpinlock;
=======
SK_DECLARE_STATIC_SPINLOCK(gProcessorSpinlock);
>>>>>>> miniblink49
class MemoryPoolAccessor {
public:
    MemoryPoolAccessor() { gProcessorSpinlock.acquire(); }

    ~MemoryPoolAccessor() { gProcessorSpinlock.release(); }

<<<<<<< HEAD
    GrMemoryPool* pool() const
    {
=======
    GrMemoryPool* pool() const {
>>>>>>> miniblink49
        static GrMemoryPool gPool(4096, 4096);
        return &gPool;
    }
};
}

int32_t GrProcessor::gCurrProcessorClassID = GrProcessor::kIllegalProcessorClassID;

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
GrProcessor::~GrProcessor() { }

void GrProcessor::addTextureAccess(const GrTextureAccess* access)
{
=======
GrProcessor::~GrProcessor() {}

void GrProcessor::addTextureAccess(const GrTextureAccess* access) {
>>>>>>> miniblink49
    fTextureAccesses.push_back(access);
    this->addGpuResource(access->getProgramTexture());
}

<<<<<<< HEAD
void GrProcessor::addBufferAccess(const GrBufferAccess* access)
{
    fBufferAccesses.push_back(access);
    this->addGpuResource(access->getProgramBuffer());
}

void* GrProcessor::operator new(size_t size)
{
    return MemoryPoolAccessor().pool()->allocate(size);
}

void GrProcessor::operator delete(void* target)
{
    return MemoryPoolAccessor().pool()->release(target);
}

bool GrProcessor::hasSameSamplers(const GrProcessor& that) const
{
    if (this->numTextures() != that.numTextures() || this->numBuffers() != that.numBuffers()) {
=======
void* GrProcessor::operator new(size_t size) {
    return MemoryPoolAccessor().pool()->allocate(size);
}

void GrProcessor::operator delete(void* target) {
    return MemoryPoolAccessor().pool()->release(target);
}

bool GrProcessor::hasSameTextureAccesses(const GrProcessor& that) const {
    if (this->numTextures() != that.numTextures()) {
>>>>>>> miniblink49
        return false;
    }
    for (int i = 0; i < this->numTextures(); ++i) {
        if (this->textureAccess(i) != that.textureAccess(i)) {
            return false;
        }
    }
<<<<<<< HEAD
    for (int i = 0; i < this->numBuffers(); ++i) {
        if (this->bufferAccess(i) != that.bufferAccess(i)) {
            return false;
        }
    }
=======
>>>>>>> miniblink49
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
// Initial static variable from GrXPFactory
int32_t GrXPFactory::gCurrXPFClassID = GrXPFactory::kIllegalXPFClassID;
=======
void GrFragmentProcessor::addCoordTransform(const GrCoordTransform* transform) {
    fCoordTransforms.push_back(transform);
    fUsesLocalCoords = fUsesLocalCoords || transform->sourceCoords() == kLocal_GrCoordSet;
    SkDEBUGCODE(transform->setInProcessor();)
}

bool GrFragmentProcessor::hasSameTransforms(const GrFragmentProcessor& that) const {
    if (fCoordTransforms.count() != that.fCoordTransforms.count()) {
        return false;
    }
    int count = fCoordTransforms.count();
    for (int i = 0; i < count; ++i) {
        if (*fCoordTransforms[i] != *that.fCoordTransforms[i]) {
            return false;
        }
    }
    return true;
}

void GrFragmentProcessor::computeInvariantOutput(GrInvariantOutput* inout) const {
    this->onComputeInvariantOutput(inout);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Initial static variable from GrXPFactory
int32_t GrXPFactory::gCurrXPFClassID =
        GrXPFactory::kIllegalXPFClassID;
>>>>>>> miniblink49
