<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkPDFDevice_DEFINED
#define SkPDFDevice_DEFINED

#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkClipStack.h"
#include "SkData.h"
#include "SkDevice.h"
#include "SkPaint.h"
=======

#ifndef SkPDFDevice_DEFINED
#define SkPDFDevice_DEFINED

#include "SkDevice.h"
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkPaint.h"
#include "SkPath.h"
#include "SkPicture.h"
>>>>>>> miniblink49
#include "SkRect.h"
#include "SkRefCnt.h"
#include "SkStream.h"
#include "SkTDArray.h"
<<<<<<< HEAD

#include "SkSinglyLinkedList.h"

class SkImageBitmap;
class SkPath;
class SkPDFArray;
class SkPDFCanon;
class SkPDFDevice;
class SkPDFDocument;
=======
#include "SkTemplates.h"

class SkPDFArray;
class SkPDFCanon;
class SkPDFDevice;
>>>>>>> miniblink49
class SkPDFDict;
class SkPDFFont;
class SkPDFFormXObject;
class SkPDFGlyphSetMap;
<<<<<<< HEAD
class SkPDFObject;
class SkRRect;

=======
class SkPDFGraphicState;
class SkPDFObject;
class SkPDFShader;
class SkPDFStream;
class SkRRect;

// Private classes.
struct ContentEntry;
struct GraphicStateEntry;
struct NamedDestination;

>>>>>>> miniblink49
/** \class SkPDFDevice

    The drawing context for the PDF backend.
*/
<<<<<<< HEAD
class SkPDFDevice final : public SkBaseDevice {
=======
class SkPDFDevice : public SkBaseDevice {
>>>>>>> miniblink49
public:
    /** Create a PDF drawing context.  SkPDFDevice applies a
     *  scale-and-translate transform to move the origin from the
     *  bottom left (PDF default) to the top left (Skia default).
     *  @param pageSize Page size in point units.
     *         1 point == 127/360 mm == 1/72 inch
     *  @param rasterDpi the DPI at which features without native PDF
     *         support will be rasterized (e.g. draw image with
     *         perspective, draw text with perspective, ...).  A
     *         larger DPI would create a PDF that reflects the
     *         original intent with better fidelity, but it can make
     *         for larger PDF files too, which would use more memory
     *         while rendering, and it would be slower to be processed
     *         or sent online or to printer.  A good choice is
     *         SK_ScalarDefaultRasterDPI(72.0f).
<<<<<<< HEAD
     *  @param SkPDFDocument.  A non-null pointer back to the
     *         document.  The document is repsonsible for
     *         de-duplicating across pages (via the SkPDFCanon) and
     *         for early serializing of large immutable objects, such
     *         as images (via SkPDFDocument::serialize()).
     */
    static SkPDFDevice* Create(SkISize pageSize,
        SkScalar rasterDpi,
        SkPDFDocument* doc)
    {
        return new SkPDFDevice(pageSize, rasterDpi, doc, true);
=======
     *  @param SkPDFCanon.  Should be non-null, and shared by all
     *         devices in a document.
     */
    static SkPDFDevice* Create(SkISize pageSize,
                               SkScalar rasterDpi,
                               SkPDFCanon* canon) {
        return SkNEW_ARGS(SkPDFDevice, (pageSize, rasterDpi, canon, true));
>>>>>>> miniblink49
    }

    /** Create a PDF drawing context without fipping the y-axis. */
    static SkPDFDevice* CreateUnflipped(SkISize pageSize,
<<<<<<< HEAD
        SkScalar rasterDpi,
        SkPDFDocument* doc)
    {
        return new SkPDFDevice(pageSize, rasterDpi, doc, false);
=======
                                        SkScalar rasterDpi,
                                        SkPDFCanon* canon) {
        return SkNEW_ARGS(SkPDFDevice, (pageSize, rasterDpi, canon, false));
>>>>>>> miniblink49
    }

    virtual ~SkPDFDevice();

    /** These are called inside the per-device-layer loop for each draw call.
     When these are called, we have already applied any saveLayer operations,
     and are handling any looping from the paint, and any effects from the
     DrawFilter.
     */
    void drawPaint(const SkDraw&, const SkPaint& paint) override;
    void drawPoints(const SkDraw&, SkCanvas::PointMode mode,
<<<<<<< HEAD
        size_t count, const SkPoint[],
        const SkPaint& paint) override;
=======
                    size_t count, const SkPoint[],
                    const SkPaint& paint) override;
>>>>>>> miniblink49
    void drawRect(const SkDraw&, const SkRect& r, const SkPaint& paint) override;
    void drawOval(const SkDraw&, const SkRect& oval, const SkPaint& paint) override;
    void drawRRect(const SkDraw&, const SkRRect& rr, const SkPaint& paint) override;
    void drawPath(const SkDraw&, const SkPath& origpath,
<<<<<<< HEAD
        const SkPaint& paint, const SkMatrix* prePathMatrix,
        bool pathIsMutable) override;
    void drawBitmapRect(const SkDraw& draw, const SkBitmap& bitmap, const SkRect* src,
        const SkRect& dst, const SkPaint&, SkCanvas::SrcRectConstraint) override;
    void drawBitmap(const SkDraw&, const SkBitmap& bitmap,
        const SkMatrix& matrix, const SkPaint&) override;
    void drawSprite(const SkDraw&, const SkBitmap& bitmap, int x, int y,
        const SkPaint& paint) override;
    void drawImage(const SkDraw&,
        const SkImage*,
        SkScalar x,
        SkScalar y,
        const SkPaint&) override;
    void drawImageRect(const SkDraw&,
        const SkImage*,
        const SkRect* src,
        const SkRect& dst,
        const SkPaint&,
        SkCanvas::SrcRectConstraint) override;
    void drawText(const SkDraw&, const void* text, size_t len,
        SkScalar x, SkScalar y, const SkPaint&) override;
    void drawPosText(const SkDraw&, const void* text, size_t len,
        const SkScalar pos[], int scalarsPerPos,
        const SkPoint& offset, const SkPaint&) override;
    void drawVertices(const SkDraw&, SkCanvas::VertexMode,
        int vertexCount, const SkPoint verts[],
        const SkPoint texs[], const SkColor colors[],
        SkXfermode* xmode, const uint16_t indices[],
        int indexCount, const SkPaint& paint) override;
    void drawDevice(const SkDraw&, SkBaseDevice*, int x, int y,
        const SkPaint&) override;
=======
                  const SkPaint& paint, const SkMatrix* prePathMatrix,
                  bool pathIsMutable) override;
    void drawBitmapRect(const SkDraw& draw, const SkBitmap& bitmap,
                        const SkRect* src, const SkRect& dst,
                        const SkPaint& paint,
                        SkCanvas::DrawBitmapRectFlags flags) override;
    void drawBitmap(const SkDraw&, const SkBitmap& bitmap,
                    const SkMatrix& matrix, const SkPaint&) override;
    void drawSprite(const SkDraw&, const SkBitmap& bitmap, int x, int y,
                    const SkPaint& paint) override;
    void drawText(const SkDraw&, const void* text, size_t len,
                  SkScalar x, SkScalar y, const SkPaint&) override;
    void drawPosText(const SkDraw&, const void* text, size_t len,
                     const SkScalar pos[], int scalarsPerPos,
                     const SkPoint& offset, const SkPaint&) override;
    void drawVertices(const SkDraw&, SkCanvas::VertexMode,
                      int vertexCount, const SkPoint verts[],
                      const SkPoint texs[], const SkColor colors[],
                      SkXfermode* xmode, const uint16_t indices[],
                      int indexCount, const SkPaint& paint) override;
    void drawDevice(const SkDraw&, SkBaseDevice*, int x, int y,
                    const SkPaint&) override;
>>>>>>> miniblink49

    void onAttachToCanvas(SkCanvas* canvas) override;
    void onDetachFromCanvas() override;
    SkImageInfo imageInfo() const override;

<<<<<<< HEAD
    // PDF specific methods.

    /** Create the resource dictionary for this device. */
    sk_sp<SkPDFDict> makeResourceDict() const;
=======
    enum DrawingArea {
        kContent_DrawingArea,  // Drawing area for the page content.
        kMargin_DrawingArea,   // Drawing area for the margin content.
    };

    /** Sets the drawing area for the device. Subsequent draw calls are directed
     *  to the specific drawing area (margin or content). The default drawing
     *  area is the content drawing area.
     *
     *  Currently if margin content is drawn and then a complex (for PDF) xfer
     *  mode is used, like SrcIn, Clear, etc, the margin content will get
     *  clipped. A simple way to avoid the bug is to always draw the margin
     *  content last.
     */
    void setDrawingArea(DrawingArea drawingArea);

    // PDF specific methods.

    /** Create the resource dictionary for this device.
     */
    SkPDFDict* createResourceDict() const;
>>>>>>> miniblink49

    /** Get the fonts used on this device.
     */
    const SkTDArray<SkPDFFont*>& getFontResources() const;

<<<<<<< HEAD
    /** Add our annotations (link to urls and destinations) to the supplied
     *  array.
     *  @param array Array to add annotations to.
     */
    void appendAnnotations(SkPDFArray* array) const;

=======
>>>>>>> miniblink49
    /** Add our named destinations to the supplied dictionary.
     *  @param dict  Dictionary to add destinations to.
     *  @param page  The PDF object representing the page for this device.
     */
    void appendDestinations(SkPDFDict* dict, SkPDFObject* page) const;

<<<<<<< HEAD
    /** Returns a copy of the media box for this device. */
    sk_sp<SkPDFArray> copyMediaBox() const;

    /** Returns a SkStream with the page contents.
     */
    std::unique_ptr<SkStreamAsset> content() const;
=======
    /** Returns a copy of the media box for this device. The caller is required
     *  to unref() this when it is finished.
     */
    SkPDFArray* copyMediaBox() const;

    /** Get the annotations from this page, or NULL if there are none.
     */
    SkPDFArray* getAnnotations() const { return fAnnotations; }

    /** Returns a SkStream with the page contents.  The caller is responsible
     *  for a deleting the returned value.
     */
    SkStreamAsset* content() const;
>>>>>>> miniblink49

    /** Writes the page contents to the stream. */
    void writeContent(SkWStream*) const;

<<<<<<< HEAD
    const SkMatrix& initialTransform() const
    {
=======
    const SkMatrix& initialTransform() const {
>>>>>>> miniblink49
        return fInitialTransform;
    }

    /** Returns a SkPDFGlyphSetMap which represents glyph usage of every font
     *  that shows on this device.
     */
<<<<<<< HEAD
    const SkPDFGlyphSetMap& getFontGlyphUsage() const
    {
        return *(fFontGlyphUsage.get());
    }

    SkPDFCanon* getCanon() const;

    // It is important to not confuse GraphicStateEntry with SkPDFGraphicState, the
    // later being our representation of an object in the PDF file.
    struct GraphicStateEntry {
        GraphicStateEntry();

        // Compare the fields we care about when setting up a new content entry.
        bool compareInitialState(const GraphicStateEntry& b);

        SkMatrix fMatrix;
        // We can't do set operations on Paths, though PDF natively supports
        // intersect.  If the clip stack does anything other than intersect,
        // we have to fall back to the region.  Treat fClipStack as authoritative.
        // See https://bugs.skia.org/221
        SkClipStack fClipStack;
        SkRegion fClipRegion;

        // When emitting the content entry, we will ensure the graphic state
        // is set to these values first.
        SkColor fColor;
        SkScalar fTextScaleX; // Zero means we don't care what the value is.
        SkPaint::Style fTextFill; // Only if TextScaleX is non-zero.
        int fShaderIndex;
        int fGraphicStateIndex;

        // We may change the font (i.e. for Type1 support) within a
        // ContentEntry.  This is the one currently in effect, or nullptr if none.
        SkPDFFont* fFont;
        // In PDF, text size has no default value. It is only valid if fFont is
        // not nullptr.
        SkScalar fTextSize;
    };

protected:
    const SkBitmap& onAccessBitmap() override
    {
        return fLegacyBitmap;
    }

    sk_sp<SkSurface> makeSurface(const SkImageInfo&, const SkSurfaceProps&) override;

    void drawAnnotation(const SkDraw&, const SkRect&, const char key[], SkData* value) override;

private:
    struct RectWithData {
        SkRect rect;
        sk_sp<SkData> data;
        RectWithData(const SkRect& rect, SkData* data)
            : rect(rect)
            , data(SkRef(data))
        {
        }
        RectWithData(RectWithData&& other)
            : rect(other.rect)
            , data(std::move(other.data))
        {
        }
        RectWithData& operator=(RectWithData&& other)
        {
            rect = other.rect;
            data = std::move(other.data);
            return *this;
        }
    };

    struct NamedDestination {
        sk_sp<SkData> nameData;
        SkPoint point;
        NamedDestination(SkData* nameData, const SkPoint& point)
            : nameData(SkRef(nameData))
            , point(point)
        {
        }
        NamedDestination(NamedDestination&& other)
            : nameData(std::move(other.nameData))
            , point(other.point)
        {
        }
        NamedDestination& operator=(NamedDestination&& other)
        {
            nameData = std::move(other.nameData);
            point = other.point;
            return *this;
        }
    };

=======
    const SkPDFGlyphSetMap& getFontGlyphUsage() const {
        return *(fFontGlyphUsage.get());
    }

#ifdef SK_DEBUG
    SkPDFCanon* getCanon() const { return fCanon; }
#endif  // SK_DEBUG

protected:
    const SkBitmap& onAccessBitmap() override {
        return fLegacyBitmap;
    }

    SkSurface* newSurface(const SkImageInfo&, const SkSurfaceProps&) override;

private:
>>>>>>> miniblink49
    // TODO(vandebo): push most of SkPDFDevice's state into a core object in
    // order to get the right access levels without using friend.
    friend class ScopedContentEntry;

    SkISize fPageSize;
    SkISize fContentSize;
    SkMatrix fInitialTransform;
    SkClipStack fExistingClipStack;
    SkRegion fExistingClipRegion;
<<<<<<< HEAD

    SkTArray<RectWithData> fLinkToURLs;
    SkTArray<RectWithData> fLinkToDestinations;
    SkTArray<NamedDestination> fNamedDestinations;
=======
    SkPDFArray* fAnnotations;
    SkTDArray<NamedDestination*> fNamedDestinations;
>>>>>>> miniblink49

    SkTDArray<SkPDFObject*> fGraphicStateResources;
    SkTDArray<SkPDFObject*> fXObjectResources;
    SkTDArray<SkPDFFont*> fFontResources;
    SkTDArray<SkPDFObject*> fShaderResources;

<<<<<<< HEAD
    struct ContentEntry {
        GraphicStateEntry fState;
        SkDynamicMemoryWStream fContent;
    };
    SkSinglyLinkedList<ContentEntry> fContentEntries;

    const SkClipStack* fClipStack;

    // Glyph ids used for each font on this device.
    std::unique_ptr<SkPDFGlyphSetMap> fFontGlyphUsage;
=======
    SkAutoTDelete<ContentEntry> fContentEntries;
    ContentEntry* fLastContentEntry;
    SkAutoTDelete<ContentEntry> fMarginContentEntries;
    ContentEntry* fLastMarginContentEntry;
    DrawingArea fDrawingArea;

    const SkClipStack* fClipStack;

    // Accessor and setter functions based on the current DrawingArea.
    SkAutoTDelete<ContentEntry>* getContentEntries();

    // Glyph ids used for each font on this device.
    SkAutoTDelete<SkPDFGlyphSetMap> fFontGlyphUsage;
>>>>>>> miniblink49

    SkScalar fRasterDpi;

    SkBitmap fLegacyBitmap;

<<<<<<< HEAD
    SkPDFDocument* fDocument;
    ////////////////////////////////////////////////////////////////////////////

    SkPDFDevice(SkISize pageSize,
        SkScalar rasterDpi,
        SkPDFDocument* doc,
        bool flip);
=======
    SkPDFCanon* fCanon;  // Owned by SkDocument_PDF
    ////////////////////////////////////////////////////////////////////////////

    SkPDFDevice(SkISize pageSize,
                SkScalar rasterDpi,
                SkPDFCanon* canon,
                bool flip);

    ContentEntry* getLastContentEntry();
    void setLastContentEntry(ContentEntry* contentEntry);
>>>>>>> miniblink49

    SkBaseDevice* onCreateDevice(const CreateInfo&, const SkPaint*) override;

    void init();
    void cleanUp(bool clearFontUsage);
    SkPDFFormXObject* createFormXObjectFromDevice();

    void drawFormXObjectWithMask(int xObjectIndex,
<<<<<<< HEAD
        SkPDFFormXObject* mask,
        const SkClipStack* clipStack,
        const SkRegion& clipRegion,
        SkXfermode::Mode mode,
        bool invertClip);

    // If the paint or clip is such that we shouldn't draw anything, this
    // returns nullptr and does not create a content entry.
    // setUpContentEntry and finishContentEntry can be used directly, but
    // the preferred method is to use the ScopedContentEntry helper class.
    ContentEntry* setUpContentEntry(const SkClipStack* clipStack,
        const SkRegion& clipRegion,
        const SkMatrix& matrix,
        const SkPaint& paint,
        bool hasText,
        SkPDFFormXObject** dst);
    void finishContentEntry(SkXfermode::Mode xfermode,
        SkPDFFormXObject* dst,
        SkPath* shape);
    bool isContentEmpty();

    void populateGraphicStateEntryFromPaint(const SkMatrix& matrix,
        const SkClipStack& clipStack,
        const SkRegion& clipRegion,
        const SkPaint& paint,
        bool hasText,
        GraphicStateEntry* entry);
=======
                                 SkPDFFormXObject* mask,
                                 const SkClipStack* clipStack,
                                 const SkRegion& clipRegion,
                                 SkXfermode::Mode mode,
                                 bool invertClip);

    // If the paint or clip is such that we shouldn't draw anything, this
    // returns NULL and does not create a content entry.
    // setUpContentEntry and finishContentEntry can be used directly, but
    // the preferred method is to use the ScopedContentEntry helper class.
    ContentEntry* setUpContentEntry(const SkClipStack* clipStack,
                                    const SkRegion& clipRegion,
                                    const SkMatrix& matrix,
                                    const SkPaint& paint,
                                    bool hasText,
                                    SkPDFFormXObject** dst);
    void finishContentEntry(SkXfermode::Mode xfermode,
                            SkPDFFormXObject* dst,
                            SkPath* shape);
    bool isContentEmpty();

    void populateGraphicStateEntryFromPaint(const SkMatrix& matrix,
                                            const SkClipStack& clipStack,
                                            const SkRegion& clipRegion,
                                            const SkPaint& paint,
                                            bool hasText,
                                            GraphicStateEntry* entry);
>>>>>>> miniblink49
    int addGraphicStateResource(SkPDFObject* gs);
    int addXObjectResource(SkPDFObject* xObject);

    void updateFont(const SkPaint& paint, uint16_t glyphID, ContentEntry* contentEntry);
    int getFontResourceIndex(SkTypeface* typeface, uint16_t glyphID);

    void internalDrawPaint(const SkPaint& paint, ContentEntry* contentEntry);
<<<<<<< HEAD

    void internalDrawImage(const SkMatrix& origMatrix,
        const SkClipStack* clipStack,
        const SkRegion& origClipRegion,
        SkImageBitmap imageBitmap,
        const SkPaint& paint);

    bool handleInversePath(const SkDraw& d, const SkPath& origPath,
        const SkPaint& paint, bool pathIsMutable,
        const SkMatrix* prePathMatrix = nullptr);
    void handlePointAnnotation(const SkPoint&, const SkMatrix&, const char key[], SkData* value);
    void handlePathAnnotation(const SkPath&, const SkDraw& d, const char key[], SkData* value);
=======
    void internalDrawBitmap(const SkMatrix& matrix,
                            const SkClipStack* clipStack,
                            const SkRegion& clipRegion,
                            const SkBitmap& bitmap,
                            const SkIRect* srcRect,
                            const SkPaint& paint);

    /** Helper method for copyContentToData. It is responsible for copying the
     *  list of content entries |entry| to |data|.
     */
    void copyContentEntriesToData(ContentEntry* entry, SkWStream* data) const;

    bool handleInversePath(const SkDraw& d, const SkPath& origPath,
                           const SkPaint& paint, bool pathIsMutable,
                           const SkMatrix* prePathMatrix = NULL);
    bool handleRectAnnotation(const SkRect& r, const SkMatrix& matrix,
                              const SkPaint& paint);
    bool handlePointAnnotation(const SkPoint* points, size_t count,
                               const SkMatrix& matrix, const SkPaint& paint);
    void addAnnotation(SkPDFDict*);
    void handleLinkToURL(SkData* urlData, const SkRect& r,
                         const SkMatrix& matrix);
    void handleLinkToNamedDest(SkData* nameData, const SkRect& r,
                               const SkMatrix& matrix);
    void defineNamedDestination(SkData* nameData, const SkPoint& point,
                                const SkMatrix& matrix);
>>>>>>> miniblink49

    typedef SkBaseDevice INHERITED;

    // TODO(edisonn): Only SkDocument_PDF and SkPDFImageShader should be able to create
    // an SkPDFDevice
    //friend class SkDocument_PDF;
    //friend class SkPDFImageShader;
};

#endif
