#include "SampleCode.h"
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkCornerPathEffect.h"
#include "SkGPipe.h"
#include "SkNetPipeController.h"
#include "SkOSMenu.h"
#include "SkSockets.h"
#include "SkView.h"
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGPipe.h"
#include "SkSockets.h"
#include "SkNetPipeController.h"
#include "SkCornerPathEffect.h"
#include "SkOSMenu.h"
>>>>>>> miniblink49
#include <map>

/**
 * Drawing Server
 *
 * This simple drawing server can accept connections from multiple drawing
 * clients simultaneously. It accumulates drawing data from each client each
 * frame, stores it in the appropriate place, and then broadcasts incremental
 * changes back to all the clients. Each logical packet, meaning one brush
 * stoke in this case can be of two types, append and replace. Append types are
 * completed strokes ready to be stored in the fData queue and will no longer be
 * modified. Replace types are drawing operations that are still in progress on
 * the client side, so they are appended to fBuffer. The location and size of
 * the buffered data for each client is stored in a map and updated properly.
 * Each time a new replace drawing call is received from a client, its previous
 * buffered data is discarded.
 * Since the Server keeps all the complete drawing data and the latest buffered
 * data, it's able to switch between vector and bitmap drawing
 */

class DrawingServerView : public SampleView {
public:
<<<<<<< HEAD
    DrawingServerView()
    {
=======
    DrawingServerView(){
>>>>>>> miniblink49
        fServer = new SkTCPServer(40000);
        fServer->suspendWrite();
        fTotalBytesRead = fTotalBytesWritten = 0;
        fVector = true;
    }
<<<<<<< HEAD
    ~DrawingServerView()
    {
=======
    ~DrawingServerView() {
>>>>>>> miniblink49
        delete fServer;
        fData.reset();
        fBuffer.reset();
        fClientMap.clear();
    }

<<<<<<< HEAD
    virtual void requestMenu(SkOSMenu* menu)
    {
=======
    virtual void requestMenu(SkOSMenu* menu) {
>>>>>>> miniblink49
        menu->setTitle("Drawing Server");
        menu->appendAction("Clear", this->getSinkID());
        menu->appendSwitch("Vector", "Vector", this->getSinkID(), fVector);
    }

protected:
    static void readData(int cid, const void* data, size_t size,
<<<<<<< HEAD
        SkSocket::DataType type, void* context)
    {
=======
                         SkSocket::DataType type, void* context) {
>>>>>>> miniblink49
        DrawingServerView* view = (DrawingServerView*)context;
        view->onRead(cid, data, size, type);
    }

<<<<<<< HEAD
    void onRead(int cid, const void* data, size_t size, SkSocket::DataType type)
    {
=======
    void onRead(int cid, const void* data, size_t size, SkSocket::DataType type) {
>>>>>>> miniblink49
        if (NULL == data && size <= 0)
            return;

        ClientState* cs;
        std::map<int, ClientState*>::iterator it = fClientMap.find(cid);
        if (it == fClientMap.end()) { //New client
            cs = new ClientState;
            cs->bufferBase = 0;
            cs->bufferSize = 0;
            fClientMap[cid] = cs;
<<<<<<< HEAD
        } else {
=======
        }
        else {
>>>>>>> miniblink49
            cs = it->second;
        }

        if (type == SkSocket::kPipeReplace_type) {
            fBuffer.remove(cs->bufferBase, cs->bufferSize);

            for (it = fClientMap.begin(); it != fClientMap.end(); ++it) {
                if (cid == it->first)
                    continue;
                else {
                    if (it->second->bufferBase > cs->bufferBase) {
                        it->second->bufferBase -= cs->bufferSize;
                        SkASSERT(it->second->bufferBase >= 0);
                    }
                }
            }

            cs->bufferBase = fBuffer.count();
            cs->bufferSize = size;
            fBuffer.append(size, (const char*)data);
<<<<<<< HEAD
        } else if (type == SkSocket::kPipeAppend_type) {
            fData.append(size, (const char*)data);
            fServer->resumeWrite();
            fServer->writePacket(fData.begin() + fTotalBytesWritten,
                fData.count() - fTotalBytesWritten,
                SkSocket::kPipeAppend_type);
            fTotalBytesWritten = fData.count();
            fServer->suspendWrite();
        } else {
=======
        }
        else if (type == SkSocket::kPipeAppend_type) {
            fData.append(size, (const char*)data);
            fServer->resumeWrite();
            fServer->writePacket(fData.begin() + fTotalBytesWritten,
                                 fData.count() - fTotalBytesWritten,
                                 SkSocket::kPipeAppend_type);
            fTotalBytesWritten = fData.count();
            fServer->suspendWrite();
        }
        else {
>>>>>>> miniblink49
            //other types of data
        }
    }

<<<<<<< HEAD
    bool onQuery(SkEvent* evt)
    {
=======
    bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "Drawing Server");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    bool onEvent(const SkEvent& evt)
    {
=======
    bool onEvent(const SkEvent& evt) {
>>>>>>> miniblink49
        if (SkOSMenu::FindAction(evt, "Clear")) {
            this->clear();
            return true;
        }
        if (SkOSMenu::FindSwitchState(evt, "Vector", &fVector)) {
            this->clearBitmap();
            return true;
        }
        return this->INHERITED::onEvent(evt);
    }

<<<<<<< HEAD
    virtual void onDrawContent(SkCanvas* canvas)
    {
=======

    virtual void onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
        if (fCurrMatrix != canvas->getTotalMatrix()) {
            fTotalBytesRead = 0;
            fCurrMatrix = canvas->getTotalMatrix();
        }

        fServer->acceptConnections();
        if (fServer->readPacket(readData, this) > 0) {
            fServer->resumeWrite();
<<<<<<< HEAD
        } else {
=======
        }
        else {
>>>>>>> miniblink49
            fServer->suspendWrite();
        }

        size_t bytesRead;
        SkGPipeReader::Status stat;
        SkCanvas bufferCanvas(fBase);
        SkCanvas* tempCanvas;
        while (fTotalBytesRead < fData.count()) {
            if (fVector) {
                tempCanvas = canvas;
            } else {
                tempCanvas = &bufferCanvas;
            }
            SkGPipeReader reader(tempCanvas);
            stat = reader.playback(fData.begin() + fTotalBytesRead,
<<<<<<< HEAD
                fData.count() - fTotalBytesRead,
                &bytesRead);
=======
                                   fData.count() - fTotalBytesRead,
                                   &bytesRead);
>>>>>>> miniblink49
            SkASSERT(SkGPipeReader::kError_Status != stat);
            fTotalBytesRead += bytesRead;
        }
        if (fVector) {
            fTotalBytesRead = 0;
        } else {
            canvas->drawBitmap(fBase, 0, 0, NULL);
        }

        size_t totalBytesRead = 0;
        while (totalBytesRead < fBuffer.count()) {
            SkGPipeReader reader(canvas);
            stat = reader.playback(fBuffer.begin() + totalBytesRead,
<<<<<<< HEAD
                fBuffer.count() - totalBytesRead,
                &bytesRead);
=======
                                   fBuffer.count() - totalBytesRead,
                                   &bytesRead);
>>>>>>> miniblink49
            SkASSERT(SkGPipeReader::kError_Status != stat);
            totalBytesRead += bytesRead;
        }

        fServer->writePacket(fBuffer.begin(), fBuffer.count(),
<<<<<<< HEAD
            SkSocket::kPipeReplace_type);
=======
                             SkSocket::kPipeReplace_type);
>>>>>>> miniblink49

        this->inval(NULL);
    }

<<<<<<< HEAD
    virtual void onSizeChange()
    {
        this->INHERITED::onSizeChange();
        fBase.setConfig(SkBitmap::kARGB_8888_Config,
            this->width(),
            this->height());
=======
    virtual void onSizeChange() {
        this->INHERITED::onSizeChange();
        fBase.setConfig(SkBitmap::kARGB_8888_Config,
                        this->width(),
                        this->height());
>>>>>>> miniblink49
        fBase.allocPixels(NULL);
        this->clearBitmap();
    }

private:
<<<<<<< HEAD
    void clear()
    {
=======
    void clear() {
>>>>>>> miniblink49
        fData.reset();
        fBuffer.reset();
        fTotalBytesRead = fTotalBytesWritten = 0;
        fClientMap.clear();
        this->clearBitmap();
    }
<<<<<<< HEAD
    void clearBitmap()
    {
=======
    void clearBitmap() {
>>>>>>> miniblink49
        fTotalBytesRead = 0;
        fBase.eraseColor(fBGColor);
    }

    struct ClientState {
        int bufferBase;
        int bufferSize;
    };

    std::map<int, ClientState*> fClientMap;
<<<<<<< HEAD
    SkTDArray<char> fData;
    SkTDArray<char> fBuffer;
    size_t fTotalBytesRead;
    size_t fTotalBytesWritten;
    SkMatrix fCurrMatrix;
    SkBitmap fBase;
    bool fVector;
    SkTCPServer* fServer;
    typedef SampleView INHERITED;
};

=======
    SkTDArray<char>             fData;
    SkTDArray<char>             fBuffer;
    size_t                      fTotalBytesRead;
    size_t                      fTotalBytesWritten;
    SkMatrix                    fCurrMatrix;
    SkBitmap                    fBase;
    bool                        fVector;
    SkTCPServer*                fServer;
    typedef SampleView INHERITED;
};


>>>>>>> miniblink49
///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new DrawingServerView; }
static SkViewRegister reg(MyFactory);
