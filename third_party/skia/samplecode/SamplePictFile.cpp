/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "DecodeFile.h"
#include "SampleCode.h"
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkDumpCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
=======
#include "SampleCode.h"
#include "SkDumpCanvas.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkImageDecoder.h"
>>>>>>> miniblink49
#include "SkOSFile.h"
#include "SkPath.h"
#include "SkPicture.h"
#include "SkPictureRecorder.h"
#include "SkRandom.h"
#include "SkRegion.h"
#include "SkShader.h"
<<<<<<< HEAD
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkUtils.h"
#include "SkView.h"
=======
#include "SkUtils.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkTime.h"
#include "SkTypeface.h"
>>>>>>> miniblink49
#include "SkXfermode.h"

#include "SkStream.h"
#include "SkSurface.h"
<<<<<<< HEAD

#include "SkGlyphCache.h"

#include "SkDrawFilter.h"
class SkCounterDrawFilter : public SkDrawFilter {
public:
    SkCounterDrawFilter(int count)
        : fCount(count)
    {
    }

    bool filter(SkPaint*, Type t) override
    {
        return --fCount >= 0;
    }

    int fCount;
};

class PictFileView : public SampleView {
public:
    PictFileView(const char name[] = nullptr)
        : fFilename(name)
        , fBBox(kNo_BBoxType)
        , fTileSize(SkSize::Make(0, 0))
    {
        for (int i = 0; i < kBBoxTypeCount; ++i) {
            fPictures[i] = nullptr;
        }
        fCount = 0;
    }

    virtual ~PictFileView()
    {
=======
#include "SkXMLParser.h"

#include "SkGlyphCache.h"

class PictFileView : public SampleView {
public:
    PictFileView(const char name[] = NULL)
        : fFilename(name)
        , fBBox(kNo_BBoxType)
        , fTileSize(SkSize::Make(0, 0)) {
        for (int i = 0; i < kBBoxTypeCount; ++i) {
            fPictures[i] = NULL;
        }
    }

    virtual ~PictFileView() {
>>>>>>> miniblink49
        for (int i = 0; i < kBBoxTypeCount; ++i) {
            SkSafeUnref(fPictures[i]);
        }
    }

<<<<<<< HEAD
    void onTileSizeChanged(const SkSize& tileSize) override
    {
=======
    void onTileSizeChanged(const SkSize &tileSize) override {
>>>>>>> miniblink49
        if (tileSize != fTileSize) {
            fTileSize = tileSize;
        }
    }

protected:
    // overrides from SkEventSink
<<<<<<< HEAD
    bool onQuery(SkEvent* evt) override
    {
        if (SampleCode::TitleQ(*evt)) {
            SkString name("P:");
            const char* basename = strrchr(fFilename.c_str(), SkPATH_SEPARATOR);
            name.append(basename ? basename + 1 : fFilename.c_str());
=======
    bool onQuery(SkEvent* evt) override {
        if (SampleCode::TitleQ(*evt)) {
            SkString name("P:");
            const char* basename = strrchr(fFilename.c_str(), SkPATH_SEPARATOR);
            name.append(basename ? basename+1: fFilename.c_str());
>>>>>>> miniblink49
            switch (fBBox) {
            case kNo_BBoxType:
                // No name appended
                break;
            case kRTree_BBoxType:
                name.append(" <bbox: R>");
                break;
            default:
                SkASSERT(false);
                break;
            }
            SampleCode::TitleR(evt, name.c_str());
            return true;
        }
<<<<<<< HEAD
        SkUnichar uni;
        if (SampleCode::CharQ(*evt, &uni)) {
            switch (uni) {
            case 'n':
                fCount += 1;
                this->inval(nullptr);
                return true;
            case 'p':
                fCount -= 1;
                this->inval(nullptr);
                return true;
            case 's':
                fCount = 0;
                this->inval(nullptr);
                return true;
            default:
                break;
            }
        }
        return this->INHERITED::onQuery(evt);
    }

    bool onEvent(const SkEvent& evt) override
    {
=======
        return this->INHERITED::onQuery(evt);
    }

    bool onEvent(const SkEvent& evt) override {
>>>>>>> miniblink49
        if (evt.isType("PictFileView::toggleBBox")) {
            fBBox = (BBoxType)((fBBox + 1) % kBBoxTypeCount);
            return true;
        }
        return this->INHERITED::onEvent(evt);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
=======
    void onDrawContent(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkASSERT(static_cast<int>(fBBox) < kBBoxTypeCount);
        SkPicture** picture = fPictures + fBBox;

#ifdef SK_GLYPHCACHE_TRACK_HASH_STATS
        SkGraphics::PurgeFontCache();
#endif

        if (!*picture) {
<<<<<<< HEAD
            *picture = LoadPicture(fFilename.c_str(), fBBox).release();
        }
        if (*picture) {
            SkCounterDrawFilter filter(fCount);
            if (fCount > 0) {
                canvas->setDrawFilter(&filter);
            }
            canvas->drawPicture(*picture);
            canvas->setDrawFilter(nullptr);
=======
            *picture = LoadPicture(fFilename.c_str(), fBBox);
        }
        if (*picture) {
            canvas->drawPicture(*picture);
>>>>>>> miniblink49
        }

#ifdef SK_GLYPHCACHE_TRACK_HASH_STATS
        SkGlyphCache::Dump();
        SkDebugf("\n");
#endif
    }

private:
    enum BBoxType {
        kNo_BBoxType,
        kRTree_BBoxType,

        kLast_BBoxType = kRTree_BBoxType,
    };
    static const int kBBoxTypeCount = kLast_BBoxType + 1;

<<<<<<< HEAD
    SkString fFilename;
    SkPicture* fPictures[kBBoxTypeCount];
    BBoxType fBBox;
    SkSize fTileSize;
    int fCount;

    sk_sp<SkPicture> LoadPicture(const char path[], BBoxType bbox)
    {
        sk_sp<SkPicture> pic;

        SkBitmap bm;
        if (decode_file(path, &bm)) {
            bm.setImmutable();
            SkPictureRecorder recorder;
            SkCanvas* can = recorder.beginRecording(SkIntToScalar(bm.width()),
                SkIntToScalar(bm.height()),
                nullptr, 0);
            can->drawBitmap(bm, 0, 0, nullptr);
            pic = recorder.finishRecordingAsPicture();
        } else {
            SkFILEStream stream(path);
            if (stream.isValid()) {
                pic = SkPicture::MakeFromStream(&stream);
=======
    SkString    fFilename;
    SkPicture*  fPictures[kBBoxTypeCount];
    BBoxType    fBBox;
    SkSize      fTileSize;

    SkPicture* LoadPicture(const char path[], BBoxType bbox) {
        SkAutoTUnref<SkPicture> pic;

        SkBitmap bm;
        if (SkImageDecoder::DecodeFile(path, &bm)) {
            bm.setImmutable();
            SkPictureRecorder recorder;
            SkCanvas* can = recorder.beginRecording(SkIntToScalar(bm.width()),
                                                    SkIntToScalar(bm.height()),
                                                    NULL, 0);
            can->drawBitmap(bm, 0, 0, NULL);
            pic.reset(recorder.endRecording());
        } else {
            SkFILEStream stream(path);
            if (stream.isValid()) {
                pic.reset(SkPicture::CreateFromStream(&stream));
>>>>>>> miniblink49
            } else {
                SkDebugf("coun't load picture at \"path\"\n", path);
            }

            if (false) { // re-record
                SkPictureRecorder recorder;
                pic->playback(recorder.beginRecording(pic->cullRect().width(),
<<<<<<< HEAD
                    pic->cullRect().height(),
                    nullptr, 0));
                sk_sp<SkPicture> p2(recorder.finishRecordingAsPicture());
=======
                                                      pic->cullRect().height(),
                                                      NULL, 0));
                SkAutoTUnref<SkPicture> p2(recorder.endRecording());
>>>>>>> miniblink49

                SkString path2(path);
                path2.append(".new.skp");
                SkFILEWStream writer(path2.c_str());
                p2->serialize(&writer);
            }
        }

<<<<<<< HEAD
        if (nullptr == pic) {
            return nullptr;
=======
        if (NULL == pic) {
            return NULL;
>>>>>>> miniblink49
        }

        SkAutoTDelete<SkBBHFactory> factory;
        switch (bbox) {
        case kNo_BBoxType:
            // no bbox playback necessary
<<<<<<< HEAD
            return pic;
        case kRTree_BBoxType:
            factory.reset(new SkRTreeFactory);
=======
            return pic.detach();
        case kRTree_BBoxType:
            factory.reset(SkNEW(SkRTreeFactory));
>>>>>>> miniblink49
            break;
        default:
            SkASSERT(false);
        }

        SkPictureRecorder recorder;
        pic->playback(recorder.beginRecording(pic->cullRect().width(),
<<<<<<< HEAD
            pic->cullRect().height(),
            factory.get(), 0));
        return recorder.finishRecordingAsPicture();
=======
                                              pic->cullRect().height(),
                                              factory.get(), 0));
        return recorder.endRecording();
>>>>>>> miniblink49
    }

    typedef SampleView INHERITED;
};

SampleView* CreateSamplePictFileView(const char filename[]);
<<<<<<< HEAD
SampleView* CreateSamplePictFileView(const char filename[])
{
=======
SampleView* CreateSamplePictFileView(const char filename[]) {
>>>>>>> miniblink49
    return new PictFileView(filename);
}

//////////////////////////////////////////////////////////////////////////////

#if 0
static SkView* MyFactory() { return new PictFileView; }
static SkViewRegister reg(MyFactory);
#endif
