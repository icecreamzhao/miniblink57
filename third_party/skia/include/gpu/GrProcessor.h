/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrProcessor_DEFINED
#define GrProcessor_DEFINED

<<<<<<< HEAD
#include "../private/SkAtomics.h"
#include "GrBufferAccess.h"
=======
>>>>>>> miniblink49
#include "GrColor.h"
#include "GrProcessorUnitTest.h"
#include "GrProgramElement.h"
#include "GrTextureAccess.h"
#include "SkMath.h"
<<<<<<< HEAD
#include "SkString.h"
=======
>>>>>>> miniblink49

class GrContext;
class GrCoordTransform;
class GrInvariantOutput;

/**
 * Used by processors to build their keys. It incorporates each per-processor key into a larger
 * shader key.
 */
class GrProcessorKeyBuilder {
public:
<<<<<<< HEAD
    GrProcessorKeyBuilder(SkTArray<unsigned char, true>* data)
        : fData(data)
        , fCount(0)
    {
        SkASSERT(0 == fData->count() % sizeof(uint32_t));
    }

    void add32(uint32_t v)
    {
=======
    GrProcessorKeyBuilder(SkTArray<unsigned char, true>* data) : fData(data), fCount(0) {
        SkASSERT(0 == fData->count() % sizeof(uint32_t));
    }

    void add32(uint32_t v) {
>>>>>>> miniblink49
        ++fCount;
        fData->push_back_n(4, reinterpret_cast<uint8_t*>(&v));
    }

    /** Inserts count uint32_ts into the key. The returned pointer is only valid until the next
        add*() call. */
<<<<<<< HEAD
    uint32_t* SK_WARN_UNUSED_RESULT add32n(int count)
    {
=======
    uint32_t* SK_WARN_UNUSED_RESULT add32n(int count) {
>>>>>>> miniblink49
        SkASSERT(count > 0);
        fCount += count;
        return reinterpret_cast<uint32_t*>(fData->push_back_n(4 * count));
    }

    size_t size() const { return sizeof(uint32_t) * fCount; }

private:
    SkTArray<uint8_t, true>* fData; // unowned ptr to the larger key.
<<<<<<< HEAD
    int fCount; // number of uint32_ts added to fData by the processor.
=======
    int fCount;                     // number of uint32_ts added to fData by the processor.
>>>>>>> miniblink49
};

/** Provides custom shader code to the Ganesh shading pipeline. GrProcessor objects *must* be
    immutable: after being constructed, their fields may not change.

    Dynamically allocated GrProcessors are managed by a per-thread memory pool. The ref count of an
<<<<<<< HEAD
    processor must reach 0 before the thread terminates and the pool is destroyed.
=======
    processor must reach 0 before the thread terminates and the pool is destroyed. To create a
    static processor use the helper macro GR_CREATE_STATIC_PROCESSOR declared below.
>>>>>>> miniblink49
 */
class GrProcessor : public GrProgramElement {
public:
    virtual ~GrProcessor();

    /** Human-meaningful string to identify this prcoessor; may be embedded
        in generated shader code. */
    virtual const char* name() const = 0;

<<<<<<< HEAD
    // Human-readable dump of all information
    virtual SkString dumpInfo() const
    {
        SkString str;
        str.appendf("Missing data");
        return str;
    }

=======
>>>>>>> miniblink49
    int numTextures() const { return fTextureAccesses.count(); }

    /** Returns the access pattern for the texture at index. index must be valid according to
        numTextures(). */
    const GrTextureAccess& textureAccess(int index) const { return *fTextureAccesses[index]; }

    /** Shortcut for textureAccess(index).texture(); */
    GrTexture* texture(int index) const { return this->textureAccess(index).getTexture(); }

<<<<<<< HEAD
    int numBuffers() const { return fBufferAccesses.count(); }

    /** Returns the access pattern for the buffer at index. index must be valid according to
        numBuffers(). */
    const GrBufferAccess& bufferAccess(int index) const
    {
        return *fBufferAccesses[index];
    }

    /**
     * Platform specific built-in features that a processor can request for the fragment shader.
     */
    enum RequiredFeatures {
        kNone_RequiredFeatures = 0,
        kFragmentPosition_RequiredFeature = 1 << 0,
        kSampleLocations_RequiredFeature = 1 << 1
    };

    GR_DECL_BITFIELD_OPS_FRIENDS(RequiredFeatures);

    RequiredFeatures requiredFeatures() const { return fRequiredFeatures; }
=======
    /** Will this processor read the fragment position? */
    bool willReadFragmentPosition() const { return fWillReadFragmentPosition; }
>>>>>>> miniblink49

    void* operator new(size_t size);
    void operator delete(void* target);

<<<<<<< HEAD
    void* operator new(size_t size, void* placement)
    {
        return ::operator new(size, placement);
    }
    void operator delete(void* target, void* placement)
    {
=======
    void* operator new(size_t size, void* placement) {
        return ::operator new(size, placement);
    }
    void operator delete(void* target, void* placement) {
>>>>>>> miniblink49
        ::operator delete(target, placement);
    }

    /**
      * Helper for down-casting to a GrProcessor subclass
      */
<<<<<<< HEAD
    template <typename T>
    const T& cast() const { return *static_cast<const T*>(this); }

    uint32_t classID() const
    {
        SkASSERT(kIllegalProcessorClassID != fClassID);
        return fClassID;
    }

protected:
    GrProcessor()
        : fClassID(kIllegalProcessorClassID)
        , fRequiredFeatures(kNone_RequiredFeatures)
    {
    }

    /**
     * Subclasses call these from their constructor to register sampler sources. The processor
     * subclass manages the lifetime of the objects (these functions only store pointers). The
     * GrTextureAccess and/or GrBufferAccess instances are typically member fields of the
     * GrProcessor subclass. These must only be called from the constructor because GrProcessors
     * are immutable.
     */
    virtual void addTextureAccess(const GrTextureAccess* textureAccess);
    virtual void addBufferAccess(const GrBufferAccess* bufferAccess);

    bool hasSameSamplers(const GrProcessor&) const;

    /**
     * If the prcoessor will generate code that uses platform specific built-in features, then it
     * must call these methods from its constructor. Otherwise, requests to use these features will
     * be denied.
     */
    void setWillReadFragmentPosition() { fRequiredFeatures |= kFragmentPosition_RequiredFeature; }
    void setWillUseSampleLocations() { fRequiredFeatures |= kSampleLocations_RequiredFeature; }

    void combineRequiredFeatures(const GrProcessor& other)
    {
        fRequiredFeatures |= other.fRequiredFeatures;
    }

    template <typename PROC_SUBCLASS>
    void initClassID()
    {
        static uint32_t kClassID = GenClassID();
        fClassID = kClassID;
    }

    uint32_t fClassID;
    SkSTArray<4, const GrTextureAccess*, true> fTextureAccesses;
    SkSTArray<2, const GrBufferAccess*, true> fBufferAccesses;

private:
    static uint32_t GenClassID()
    {
=======
    template <typename T> const T& cast() const { return *static_cast<const T*>(this); }

    uint32_t classID() const { SkASSERT(kIllegalProcessorClassID != fClassID); return fClassID; }

protected:
    GrProcessor() : fClassID(kIllegalProcessorClassID), fWillReadFragmentPosition(false) {}

    /**
     * Subclasses call this from their constructor to register GrTextureAccesses. The processor
     * subclass manages the lifetime of the accesses (this function only stores a pointer). The
     * GrTextureAccess is typically a member field of the GrProcessor subclass. This must only be
     * called from the constructor because GrProcessors are immutable.
     */
    void addTextureAccess(const GrTextureAccess* textureAccess);

    bool hasSameTextureAccesses(const GrProcessor&) const;

    /**
     * If the prcoessor will generate a backend-specific processor that will read the fragment
     * position in the FS then it must call this method from its constructor. Otherwise, the
     * request to access the fragment position will be denied.
     */
    void setWillReadFragmentPosition() { fWillReadFragmentPosition = true; }

    template <typename PROC_SUBCLASS> void initClassID() {
         static uint32_t kClassID = GenClassID();
         fClassID = kClassID;
    }

    uint32_t fClassID;

private:
    static uint32_t GenClassID() {
>>>>>>> miniblink49
        // fCurrProcessorClassID has been initialized to kIllegalProcessorClassID. The
        // atomic inc returns the old value not the incremented value. So we add
        // 1 to the returned value.
        uint32_t id = static_cast<uint32_t>(sk_atomic_inc(&gCurrProcessorClassID)) + 1;
        if (!id) {
            SkFAIL("This should never wrap as it should only be called once for each GrProcessor "
                   "subclass.");
        }
        return id;
    }

    enum {
        kIllegalProcessorClassID = 0,
    };
    static int32_t gCurrProcessorClassID;

<<<<<<< HEAD
    RequiredFeatures fRequiredFeatures;
=======
    SkSTArray<4, const GrTextureAccess*, true>   fTextureAccesses;
    bool                                         fWillReadFragmentPosition;
>>>>>>> miniblink49

    typedef GrProgramElement INHERITED;
};

<<<<<<< HEAD
GR_MAKE_BITFIELD_OPS(GrProcessor::RequiredFeatures);
=======
/**
 * This creates a processor outside of the memory pool. The processor's destructor will be called
 * at global destruction time. NAME will be the name of the created instance.
 */
#define GR_CREATE_STATIC_PROCESSOR(NAME, PROC_CLASS, ARGS)                                 \
static SkAlignedSStorage<sizeof(PROC_CLASS)> g_##NAME##_Storage;                           \
static PROC_CLASS* NAME SkNEW_PLACEMENT_ARGS(g_##NAME##_Storage.get(), PROC_CLASS, ARGS);  \
static SkAutoTDestroy<GrProcessor> NAME##_ad(NAME);
>>>>>>> miniblink49

#endif
