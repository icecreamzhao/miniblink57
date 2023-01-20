/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkSVGDevice_DEFINED
#define SkSVGDevice_DEFINED

#include "SkDevice.h"
<<<<<<< HEAD
#include "SkTemplates.h"
=======
>>>>>>> miniblink49

class SkXMLWriter;

class SkSVGDevice : public SkBaseDevice {
public:
    static SkBaseDevice* Create(const SkISize& size, SkXMLWriter* writer);

    SkImageInfo imageInfo() const override;

protected:
    void drawPaint(const SkDraw&, const SkPaint& paint) override;
    void drawPoints(const SkDraw&, SkCanvas::PointMode mode, size_t count,
<<<<<<< HEAD
        const SkPoint[], const SkPaint& paint) override;
=======
                    const SkPoint[], const SkPaint& paint) override;
>>>>>>> miniblink49
    void drawRect(const SkDraw&, const SkRect& r, const SkPaint& paint) override;
    void drawOval(const SkDraw&, const SkRect& oval, const SkPaint& paint) override;
    void drawRRect(const SkDraw&, const SkRRect& rr, const SkPaint& paint) override;
    void drawPath(const SkDraw&, const SkPath& path,
<<<<<<< HEAD
        const SkPaint& paint,
        const SkMatrix* prePathMatrix = nullptr,
        bool pathIsMutable = false) override;

    void drawBitmap(const SkDraw&, const SkBitmap& bitmap,
        const SkMatrix& matrix, const SkPaint& paint) override;
    void drawSprite(const SkDraw&, const SkBitmap& bitmap,
        int x, int y, const SkPaint& paint) override;
    void drawBitmapRect(const SkDraw&, const SkBitmap&,
        const SkRect* srcOrNull, const SkRect& dst,
        const SkPaint& paint, SkCanvas::SrcRectConstraint) override;

    void drawText(const SkDraw&, const void* text, size_t len,
        SkScalar x, SkScalar y, const SkPaint& paint) override;
    void drawPosText(const SkDraw&, const void* text, size_t len,
        const SkScalar pos[], int scalarsPerPos,
        const SkPoint& offset, const SkPaint& paint) override;
    void drawTextOnPath(const SkDraw&, const void* text, size_t len,
        const SkPath& path, const SkMatrix* matrix,
        const SkPaint& paint) override;
    void drawVertices(const SkDraw&, SkCanvas::VertexMode, int vertexCount,
        const SkPoint verts[], const SkPoint texs[],
        const SkColor colors[], SkXfermode* xmode,
        const uint16_t indices[], int indexCount,
        const SkPaint& paint) override;

    void drawDevice(const SkDraw&, SkBaseDevice*, int x, int y,
        const SkPaint&) override;
=======
                  const SkPaint& paint,
                  const SkMatrix* prePathMatrix = NULL,
                  bool pathIsMutable = false) override;

    void drawBitmap(const SkDraw&, const SkBitmap& bitmap,
                    const SkMatrix& matrix, const SkPaint& paint) override;
    void drawSprite(const SkDraw&, const SkBitmap& bitmap,
                    int x, int y, const SkPaint& paint) override;
    void drawBitmapRect(const SkDraw&, const SkBitmap&,
                        const SkRect* srcOrNull, const SkRect& dst,
                        const SkPaint& paint,
                        SkCanvas::DrawBitmapRectFlags flags) override;

    void drawText(const SkDraw&, const void* text, size_t len,
                  SkScalar x, SkScalar y, const SkPaint& paint) override;
    void drawPosText(const SkDraw&, const void* text, size_t len,
                     const SkScalar pos[], int scalarsPerPos,
                     const SkPoint& offset, const SkPaint& paint) override;
    void drawTextOnPath(const SkDraw&, const void* text, size_t len,
                        const SkPath& path, const SkMatrix* matrix,
                        const SkPaint& paint) override;
    void drawVertices(const SkDraw&, SkCanvas::VertexMode, int vertexCount,
                      const SkPoint verts[], const SkPoint texs[],
                      const SkColor colors[], SkXfermode* xmode,
                      const uint16_t indices[], int indexCount,
                      const SkPaint& paint) override;

    void drawDevice(const SkDraw&, SkBaseDevice*, int x, int y,
                    const SkPaint&) override;
>>>>>>> miniblink49
    const SkBitmap& onAccessBitmap() override;

private:
    SkSVGDevice(const SkISize& size, SkXMLWriter* writer);
    virtual ~SkSVGDevice();

    void drawBitmapCommon(const SkDraw& draw, const SkBitmap& bm, const SkPaint& paint);

    class AutoElement;
    class ResourceBucket;

<<<<<<< HEAD
    SkXMLWriter* fWriter;
    SkAutoTDelete<AutoElement> fRootElement;
    SkAutoTDelete<ResourceBucket> fResourceBucket;
    SkBitmap fLegacyBitmap;
=======
    SkXMLWriter*                  fWriter;
    SkAutoTDelete<AutoElement>    fRootElement;
    SkAutoTDelete<ResourceBucket> fResourceBucket;
    SkBitmap                      fLegacyBitmap;
>>>>>>> miniblink49

    typedef SkBaseDevice INHERITED;
};

#endif // SkSVGDevice_DEFINED
