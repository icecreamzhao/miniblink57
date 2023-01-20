/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkLuaCanvas.h"
#include "SkLua.h"

extern "C" {
<<<<<<< HEAD
#include "lauxlib.h"
#include "lua.h"
=======
    #include "lua.h"
    #include "lauxlib.h"
>>>>>>> miniblink49
}

class AutoCallLua : public SkLua {
public:
<<<<<<< HEAD
    AutoCallLua(lua_State* L, const char func[], const char verb[])
        : INHERITED(L)
    {
=======
    AutoCallLua(lua_State* L, const char func[], const char verb[]) : INHERITED(L) {
>>>>>>> miniblink49
        lua_getglobal(L, func);
        if (!lua_isfunction(L, -1)) {
            int t = lua_type(L, -1);
            SkDebugf("--- expected function %d\n", t);
        }

        lua_newtable(L);
        this->pushString(verb, "verb");
    }

<<<<<<< HEAD
    ~AutoCallLua()
    {
=======
    ~AutoCallLua() {
>>>>>>> miniblink49
        lua_State* L = this->get();
        if (lua_pcall(L, 1, 0, 0) != LUA_OK) {
            SkDebugf("lua err: %s\n", lua_tostring(L, -1));
        }
        lua_settop(L, -1);
    }

    void pushEncodedText(SkPaint::TextEncoding, const void*, size_t);

private:
    typedef SkLua INHERITED;
};

<<<<<<< HEAD
#define AUTO_LUA(verb) AutoCallLua lua(fL, fFunc.c_str(), verb)
=======
#define AUTO_LUA(verb)  AutoCallLua lua(fL, fFunc.c_str(), verb)

>>>>>>> miniblink49

///////////////////////////////////////////////////////////////////////////////

void AutoCallLua::pushEncodedText(SkPaint::TextEncoding enc, const void* text,
<<<<<<< HEAD
    size_t length)
{
    switch (enc) {
    case SkPaint::kUTF8_TextEncoding:
        this->pushString((const char*)text, length, "text");
        break;
    case SkPaint::kUTF16_TextEncoding: {
        SkString str;
        str.setUTF16((const uint16_t*)text, length);
        this->pushString(str, "text");
    } break;
    case SkPaint::kGlyphID_TextEncoding:
        this->pushArrayU16((const uint16_t*)text, SkToInt(length >> 1),
            "glyphs");
        break;
    case SkPaint::kUTF32_TextEncoding:
        break;
=======
                                  size_t length) {
    switch (enc) {
        case SkPaint::kUTF8_TextEncoding:
            this->pushString((const char*)text, length, "text");
            break;
        case SkPaint::kUTF16_TextEncoding: {
            SkString str;
            str.setUTF16((const uint16_t*)text, length);
            this->pushString(str, "text");
        } break;
        case SkPaint::kGlyphID_TextEncoding:
            this->pushArrayU16((const uint16_t*)text, SkToInt(length >> 1),
                               "glyphs");
            break;
        case SkPaint::kUTF32_TextEncoding:
            break;
>>>>>>> miniblink49
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkLuaCanvas::pushThis()
{
=======
void SkLuaCanvas::pushThis() {
>>>>>>> miniblink49
    SkLua(fL).pushCanvas(this);
}

///////////////////////////////////////////////////////////////////////////////

SkLuaCanvas::SkLuaCanvas(int width, int height, lua_State* L, const char func[])
    : INHERITED(width, height)
    , fL(L)
<<<<<<< HEAD
    , fFunc(func)
{
}

SkLuaCanvas::~SkLuaCanvas() { }

void SkLuaCanvas::willSave()
{
=======
    , fFunc(func) {
}

SkLuaCanvas::~SkLuaCanvas() {}

void SkLuaCanvas::willSave() {
>>>>>>> miniblink49
    AUTO_LUA("save");
    this->INHERITED::willSave();
}

<<<<<<< HEAD
SkCanvas::SaveLayerStrategy SkLuaCanvas::getSaveLayerStrategy(const SaveLayerRec& rec)
{
    AUTO_LUA("saveLayer");
    if (rec.fBounds) {
        lua.pushRect(*rec.fBounds, "bounds");
    }
    if (rec.fPaint) {
        lua.pushPaint(*rec.fPaint, "paint");
    }

    (void)this->INHERITED::getSaveLayerStrategy(rec);
=======
SkCanvas::SaveLayerStrategy SkLuaCanvas::willSaveLayer(const SkRect* bounds, const SkPaint* paint,
                                                       SaveFlags flags) {
    AUTO_LUA("saveLayer");
    if (bounds) {
        lua.pushRect(*bounds, "bounds");
    }
    if (paint) {
        lua.pushPaint(*paint, "paint");
    }

    this->INHERITED::willSaveLayer(bounds, paint, flags);
>>>>>>> miniblink49
    // No need for a layer.
    return kNoLayer_SaveLayerStrategy;
}

<<<<<<< HEAD
void SkLuaCanvas::willRestore()
{
=======
void SkLuaCanvas::willRestore() {
>>>>>>> miniblink49
    AUTO_LUA("restore");
    this->INHERITED::willRestore();
}

<<<<<<< HEAD
void SkLuaCanvas::didConcat(const SkMatrix& matrix)
{
    switch (matrix.getType()) {
    case SkMatrix::kTranslate_Mask: {
        AUTO_LUA("translate");
        lua.pushScalar(matrix.getTranslateX(), "dx");
        lua.pushScalar(matrix.getTranslateY(), "dy");
        break;
    }
    case SkMatrix::kScale_Mask: {
        AUTO_LUA("scale");
        lua.pushScalar(matrix.getScaleX(), "sx");
        lua.pushScalar(matrix.getScaleY(), "sy");
        break;
    }
    default: {
        AUTO_LUA("concat");
        // pushMatrix added in https://codereview.chromium.org/203203004/
        // Doesn't seem to have ever been working correctly since added
        // lua.pushMatrix(matrix);
        break;
    }
=======
void SkLuaCanvas::didConcat(const SkMatrix& matrix) {
    switch (matrix.getType()) {
        case SkMatrix::kTranslate_Mask: {
            AUTO_LUA("translate");
            lua.pushScalar(matrix.getTranslateX(), "dx");
            lua.pushScalar(matrix.getTranslateY(), "dy");
            break;
        }
        case SkMatrix::kScale_Mask: {
            AUTO_LUA("scale");
            lua.pushScalar(matrix.getScaleX(), "sx");
            lua.pushScalar(matrix.getScaleY(), "sy");
            break;
        }
        default: {
            AUTO_LUA("concat");
            // pushMatrix added in https://codereview.chromium.org/203203004/
            // Doesn't seem to have ever been working correctly since added
            // lua.pushMatrix(matrix);
            break;
        }
>>>>>>> miniblink49
    }

    this->INHERITED::didConcat(matrix);
}

<<<<<<< HEAD
void SkLuaCanvas::didSetMatrix(const SkMatrix& matrix)
{
    this->INHERITED::didSetMatrix(matrix);
}

void SkLuaCanvas::onClipRect(const SkRect& r, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkLuaCanvas::didSetMatrix(const SkMatrix& matrix) {
    this->INHERITED::didSetMatrix(matrix);
}

void SkLuaCanvas::onClipRect(const SkRect& r, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    AUTO_LUA("clipRect");
    lua.pushRect(r, "rect");
    lua.pushBool(kSoft_ClipEdgeStyle == edgeStyle, "aa");
    this->INHERITED::onClipRect(r, op, edgeStyle);
}

<<<<<<< HEAD
void SkLuaCanvas::onClipRRect(const SkRRect& rrect, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkLuaCanvas::onClipRRect(const SkRRect& rrect, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    AUTO_LUA("clipRRect");
    lua.pushRRect(rrect, "rrect");
    lua.pushBool(kSoft_ClipEdgeStyle == edgeStyle, "aa");
    this->INHERITED::onClipRRect(rrect, op, edgeStyle);
}

<<<<<<< HEAD
void SkLuaCanvas::onClipPath(const SkPath& path, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkLuaCanvas::onClipPath(const SkPath& path, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    AUTO_LUA("clipPath");
    lua.pushPath(path, "path");
    lua.pushBool(kSoft_ClipEdgeStyle == edgeStyle, "aa");
    this->INHERITED::onClipPath(path, op, edgeStyle);
}

<<<<<<< HEAD
void SkLuaCanvas::onClipRegion(const SkRegion& deviceRgn, SkRegion::Op op)
{
=======
void SkLuaCanvas::onClipRegion(const SkRegion& deviceRgn, SkRegion::Op op) {
>>>>>>> miniblink49
    AUTO_LUA("clipRegion");
    this->INHERITED::onClipRegion(deviceRgn, op);
}

<<<<<<< HEAD
void SkLuaCanvas::onDrawPaint(const SkPaint& paint)
{
=======
void SkLuaCanvas::onDrawPaint(const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawPaint");
    lua.pushPaint(paint, "paint");
}

void SkLuaCanvas::onDrawPoints(PointMode mode, size_t count,
<<<<<<< HEAD
    const SkPoint pts[], const SkPaint& paint)
{
=======
                               const SkPoint pts[], const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawPoints");
    lua.pushArrayPoint(pts, SkToInt(count), "points");
    lua.pushPaint(paint, "paint");
}

<<<<<<< HEAD
void SkLuaCanvas::onDrawOval(const SkRect& rect, const SkPaint& paint)
{
=======
void SkLuaCanvas::onDrawOval(const SkRect& rect, const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawOval");
    lua.pushRect(rect, "rect");
    lua.pushPaint(paint, "paint");
}

<<<<<<< HEAD
void SkLuaCanvas::onDrawRect(const SkRect& rect, const SkPaint& paint)
{
=======
void SkLuaCanvas::onDrawRect(const SkRect& rect, const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawRect");
    lua.pushRect(rect, "rect");
    lua.pushPaint(paint, "paint");
}

<<<<<<< HEAD
void SkLuaCanvas::onDrawRRect(const SkRRect& rrect, const SkPaint& paint)
{
=======
void SkLuaCanvas::onDrawRRect(const SkRRect& rrect, const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawRRect");
    lua.pushRRect(rrect, "rrect");
    lua.pushPaint(paint, "paint");
}

void SkLuaCanvas::onDrawDRRect(const SkRRect& outer, const SkRRect& inner,
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                               const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawDRRect");
    lua.pushRRect(outer, "outer");
    lua.pushRRect(inner, "inner");
    lua.pushPaint(paint, "paint");
}

<<<<<<< HEAD
void SkLuaCanvas::onDrawPath(const SkPath& path, const SkPaint& paint)
{
=======
void SkLuaCanvas::onDrawPath(const SkPath& path, const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawPath");
    lua.pushPath(path, "path");
    lua.pushPaint(paint, "paint");
}

void SkLuaCanvas::onDrawBitmap(const SkBitmap& bitmap, SkScalar x, SkScalar y,
<<<<<<< HEAD
    const SkPaint* paint)
{
=======
                               const SkPaint* paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawBitmap");
    if (paint) {
        lua.pushPaint(*paint, "paint");
    }
}

void SkLuaCanvas::onDrawBitmapRect(const SkBitmap& bitmap, const SkRect* src, const SkRect& dst,
<<<<<<< HEAD
    const SkPaint* paint, SrcRectConstraint)
{
=======
                                   const SkPaint* paint, DrawBitmapRectFlags flags) {
>>>>>>> miniblink49
    AUTO_LUA("drawBitmapRect");
    if (paint) {
        lua.pushPaint(*paint, "paint");
    }
}

void SkLuaCanvas::onDrawBitmapNine(const SkBitmap& bitmap, const SkIRect& center, const SkRect& dst,
<<<<<<< HEAD
    const SkPaint* paint)
{
=======
                                   const SkPaint* paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawBitmapNine");
    if (paint) {
        lua.pushPaint(*paint, "paint");
    }
}

<<<<<<< HEAD
void SkLuaCanvas::onDrawImage(const SkImage* image, SkScalar x, SkScalar y, const SkPaint* paint)
{
=======
void SkLuaCanvas::onDrawImage(const SkImage* image, SkScalar x, SkScalar y, const SkPaint* paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawImage");
    if (paint) {
        lua.pushPaint(*paint, "paint");
    }
}

void SkLuaCanvas::onDrawImageRect(const SkImage* image, const SkRect* src, const SkRect& dst,
<<<<<<< HEAD
    const SkPaint* paint, SrcRectConstraint)
{
=======
                                  const SkPaint* paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawImageRect");
    if (paint) {
        lua.pushPaint(*paint, "paint");
    }
}

<<<<<<< HEAD
void SkLuaCanvas::onDrawText(const void* text, size_t byteLength, SkScalar x, SkScalar y,
    const SkPaint& paint)
{
=======
void SkLuaCanvas::onDrawSprite(const SkBitmap& bitmap, int x, int y, const SkPaint* paint) {
    AUTO_LUA("drawSprite");
    if (paint) {
        lua.pushPaint(*paint, "paint");
    }
}

void SkLuaCanvas::onDrawText(const void* text, size_t byteLength, SkScalar x, SkScalar y,
                             const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawText");
    lua.pushEncodedText(paint.getTextEncoding(), text, byteLength);
    lua.pushPaint(paint, "paint");
}

void SkLuaCanvas::onDrawPosText(const void* text, size_t byteLength, const SkPoint pos[],
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                                const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawPosText");
    lua.pushEncodedText(paint.getTextEncoding(), text, byteLength);
    lua.pushPaint(paint, "paint");
}

void SkLuaCanvas::onDrawPosTextH(const void* text, size_t byteLength, const SkScalar xpos[],
<<<<<<< HEAD
    SkScalar constY, const SkPaint& paint)
{
=======
                                 SkScalar constY, const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawPosTextH");
    lua.pushEncodedText(paint.getTextEncoding(), text, byteLength);
    lua.pushPaint(paint, "paint");
}

void SkLuaCanvas::onDrawTextOnPath(const void* text, size_t byteLength, const SkPath& path,
<<<<<<< HEAD
    const SkMatrix* matrix, const SkPaint& paint)
{
=======
                                   const SkMatrix* matrix, const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawTextOnPath");
    lua.pushPath(path, "path");
    lua.pushEncodedText(paint.getTextEncoding(), text, byteLength);
    lua.pushPaint(paint, "paint");
}

<<<<<<< HEAD
void SkLuaCanvas::onDrawTextBlob(const SkTextBlob* blob, SkScalar x, SkScalar y,
    const SkPaint& paint)
{
=======
void SkLuaCanvas::onDrawTextBlob(const SkTextBlob *blob, SkScalar x, SkScalar y,
                                 const SkPaint &paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawTextBlob");
    lua.pushTextBlob(blob, "blob");
    lua.pushScalar(x, "x");
    lua.pushScalar(y, "y");
    lua.pushPaint(paint, "paint");
}

void SkLuaCanvas::onDrawPicture(const SkPicture* picture, const SkMatrix* matrix,
<<<<<<< HEAD
    const SkPaint* paint)
{
=======
                                const SkPaint* paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawPicture");
    // call through so we can see the nested picture ops
    this->INHERITED::onDrawPicture(picture, matrix, paint);
}

void SkLuaCanvas::onDrawVertices(VertexMode vmode, int vertexCount,
<<<<<<< HEAD
    const SkPoint vertices[], const SkPoint texs[],
    const SkColor colors[], SkXfermode* xmode,
    const uint16_t indices[], int indexCount,
    const SkPaint& paint)
{
=======
                                 const SkPoint vertices[], const SkPoint texs[],
                                 const SkColor colors[], SkXfermode* xmode,
                                 const uint16_t indices[], int indexCount,
                                 const SkPaint& paint) {
>>>>>>> miniblink49
    AUTO_LUA("drawVertices");
    lua.pushPaint(paint, "paint");
}
