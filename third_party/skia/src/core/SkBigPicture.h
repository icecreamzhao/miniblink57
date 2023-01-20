/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkBigPicture_DEFINED
#define SkBigPicture_DEFINED

<<<<<<< HEAD
#include "SkOnce.h"
#include "SkPicture.h"
#include "SkRect.h"
#include "SkTemplates.h"

class SkBBoxHierarchy;
class SkMatrix;
=======
#include "SkPicture.h"
#include "SkLazyPtr.h"

class SkBBoxHierarchy;
>>>>>>> miniblink49
class SkRecord;

// An implementation of SkPicture supporting an arbitrary number of drawing commands.
class SkBigPicture final : public SkPicture {
public:
    // AccelData provides a base class for device-specific acceleration data.
<<<<<<< HEAD
    class AccelData : public SkRefCnt {
    };
=======
    class AccelData : public SkRefCnt { };
>>>>>>> miniblink49

    // An array of refcounted const SkPicture pointers.
    class SnapshotArray : ::SkNoncopyable {
    public:
<<<<<<< HEAD
        SnapshotArray(const SkPicture* pics[], int count)
            : fPics(pics)
            , fCount(count)
        {
        }
        ~SnapshotArray()
        {
            for (int i = 0; i < fCount; i++) {
                fPics[i]->unref();
            }
        }

        const SkPicture* const* begin() const { return fPics; }
        int count() const { return fCount; }

=======
        SnapshotArray(const SkPicture* pics[], int count) : fPics(pics), fCount(count) {}
        ~SnapshotArray() { for (int i = 0; i < fCount; i++) { fPics[i]->unref(); } }

        const SkPicture* const* begin() const { return fPics; }
        int count() const { return fCount; }
>>>>>>> miniblink49
    private:
        SkAutoTMalloc<const SkPicture*> fPics;
        int fCount;
    };

    SkBigPicture(const SkRect& cull,
<<<<<<< HEAD
        SkRecord*, // We take ownership of the caller's ref.
        SnapshotArray*, // We take exclusive ownership.
        SkBBoxHierarchy*, // We take ownership of the caller's ref.
        AccelData*, // We take ownership of the caller's ref.
        size_t approxBytesUsedBySubPictures);

    // SkPicture overrides
    void playback(SkCanvas*, AbortCallback*) const override;
    SkRect cullRect() const override;
=======
                 SkRecord*,            // We take ownership of the caller's ref.
                 SnapshotArray*,       // We take exclusive ownership.
                 SkBBoxHierarchy*,     // We take ownership of the caller's ref.
                 AccelData*,           // We take ownership of the caller's ref.
                 size_t approxBytesUsedBySubPictures);


// SkPicture overrides
    void playback(SkCanvas*, AbortCallback*) const override;
    SkRect cullRect() const override;
    bool hasText() const override;
>>>>>>> miniblink49
    bool willPlayBackBitmaps() const override;
    int approximateOpCount() const override;
    size_t approximateBytesUsed() const override;
    const SkBigPicture* asSkBigPicture() const override { return this; }

<<<<<<< HEAD
    // Used by GrLayerHoister
    void partialPlayback(SkCanvas*,
        int start,
        int stop,
        const SkMatrix& initialCTM) const;
    // Used by GrRecordReplaceDraw
    const SkBBoxHierarchy* bbh() const { return fBBH; }
    const SkRecord* record() const { return fRecord; }
=======
// Used by GrLayerHoister
    void partialPlayback(SkCanvas*,
                         unsigned start,
                         unsigned stop,
                         const SkMatrix& initialCTM) const;
// Used by GrRecordReplaceDraw
    const SkBBoxHierarchy* bbh() const { return fBBH; }
    const SkRecord*     record() const { return fRecord; }
>>>>>>> miniblink49
    const AccelData* accelData() const { return fAccelData; }

private:
    struct Analysis {
<<<<<<< HEAD
        void init(const SkRecord&);
=======
        explicit Analysis(const SkRecord&);
>>>>>>> miniblink49

        bool suitableForGpuRasterization(const char** reason) const;

        uint8_t fNumSlowPathsAndDashEffects;
<<<<<<< HEAD
        bool fWillPlaybackBitmaps : 1;
=======
        bool    fWillPlaybackBitmaps : 1;
        bool    fHasText             : 1;
>>>>>>> miniblink49
    };

    int numSlowPaths() const override;
    const Analysis& analysis() const;
    int drawableCount() const;
    SkPicture const* const* drawablePicts() const;

<<<<<<< HEAD
    const SkRect fCullRect;
    const size_t fApproxBytesUsedBySubPictures;
    mutable SkOnce fAnalysisOnce;
    mutable Analysis fAnalysis;
    SkAutoTUnref<const SkRecord> fRecord;
    SkAutoTDelete<const SnapshotArray> fDrawablePicts;
    SkAutoTUnref<const SkBBoxHierarchy> fBBH;
    SkAutoTUnref<const AccelData> fAccelData;
};

#endif //SkBigPicture_DEFINED
=======
    const SkRect                          fCullRect;
    const size_t                          fApproxBytesUsedBySubPictures;
    SkLazyPtr<const Analysis>             fAnalysis;
    SkAutoTUnref<const SkRecord>          fRecord;
    SkAutoTDelete<const SnapshotArray>    fDrawablePicts;
    SkAutoTUnref<const SkBBoxHierarchy>   fBBH;
    SkAutoTUnref<const AccelData>         fAccelData;
};

#endif//SkBigPicture_DEFINED
>>>>>>> miniblink49
