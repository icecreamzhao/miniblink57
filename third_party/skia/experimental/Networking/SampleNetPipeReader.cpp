#include "SampleCode.h"
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkGPipe.h"
#include "SkGradientShader.h"
#include "SkOSMenu.h"
#include "SkSockets.h"
#include "SkView.h"
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGPipe.h"
#include "SkSockets.h"
#include "SkOSMenu.h"
>>>>>>> miniblink49

/**
 * A simple networked pipe reader
 *
 * This view will connect to a user specified server, in this case meaning any
 * Skia app that's has a SkTCPServer set up to broadcast its piped drawing data,
 * received all the data transmitted and attempt to reproduce the drawing calls.
 * This reader will only keep the latest batch of data. In order to keep up with
 * the server, which may be producing data at a much higher rate than the reader
 * is consuming, the reader will attempt multiple reads and only render the
 * latest frame. this behavior can be adjusted by changing MAX_READS_PER_FRAME
 * or disabled by setting fSync to false
 */

#define MAX_READS_PER_FRAME 12

class NetPipeReaderView : public SampleView {
public:
<<<<<<< HEAD
    NetPipeReaderView()
    {
=======
    NetPipeReaderView() {
>>>>>>> miniblink49
        fSocket = NULL;
        fSync = true;
    }

<<<<<<< HEAD
    ~NetPipeReaderView()
    {
=======
    ~NetPipeReaderView() {
>>>>>>> miniblink49
        if (fSocket) {
            delete fSocket;
        }
        fDataArray.reset();
    }
<<<<<<< HEAD
    virtual void requestMenu(SkOSMenu* menu)
    {
        menu->setTitle("Net Pipe Reader");
        menu->appendTextField("Server IP", "Server IP", this->getSinkID(),
            "IP address");
=======
    virtual void requestMenu(SkOSMenu* menu) {
        menu->setTitle("Net Pipe Reader");
        menu->appendTextField("Server IP", "Server IP", this->getSinkID(),
                              "IP address");
>>>>>>> miniblink49
        menu->appendSwitch("Sync", "Sync", this->getSinkID(), fSync);
    }

protected:
    static void readData(int cid, const void* data, size_t size,
<<<<<<< HEAD
        SkSocket::DataType type, void* context)
    {
=======
                         SkSocket::DataType type, void* context) {
>>>>>>> miniblink49
        NetPipeReaderView* view = (NetPipeReaderView*)context;
        view->onRead(data, size);
    }

<<<<<<< HEAD
    void onRead(const void* data, size_t size)
    {
=======
    void onRead(const void* data, size_t size) {
>>>>>>> miniblink49
        if (size > 0)
            fDataArray.append(size, (const char*)data);
    }

<<<<<<< HEAD
    bool onQuery(SkEvent* evt)
    {
=======
    bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "Net Pipe Reader");
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
        SkString s;
        if (SkOSMenu::FindText(evt, "Server IP", &s)) {
            if (NULL != fSocket) {
                delete fSocket;
            }
            fSocket = new SkTCPClient(s.c_str());
            fSocket->connectToServer();
            SkDebugf("Connecting to %s\n", s.c_str());
            return true;
        }
        if (SkOSMenu::FindSwitchState(evt, "Sync", &fSync))
            return true;
        return this->INHERITED::onEvent(evt);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas)
    {
=======
    void onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
        if (NULL == fSocket)
            return;

        if (fSocket->isConnected()) {
            int dataToRemove = fDataArray.count();
            if (fSync) {
                int numreads = 0;
<<<<<<< HEAD
                while (fSocket->readPacket(readData, this) > 0 && numreads < MAX_READS_PER_FRAME) {
=======
                while (fSocket->readPacket(readData, this) > 0 &&
                       numreads < MAX_READS_PER_FRAME) {
>>>>>>> miniblink49
                    // at this point, new data has been read and stored, discard
                    // old data since it's not needed anymore
                    SkASSERT(fDataArray.count() > dataToRemove);
                    fDataArray.remove(0, dataToRemove);
                    dataToRemove = fDataArray.count();
                    ++numreads;
                }
                // clean up if max reads reached
<<<<<<< HEAD
                if (numreads == MAX_READS_PER_FRAME && fDataArray.count() > dataToRemove)
                    fDataArray.remove(0, dataToRemove);
            } else {
                if (fSocket->readPacket(readData, this) > 0)
                    fDataArray.remove(0, dataToRemove);
            }
        } else
=======
                if (numreads == MAX_READS_PER_FRAME &&
                    fDataArray.count() > dataToRemove)
                    fDataArray.remove(0, dataToRemove);
            }
            else {
                if (fSocket->readPacket(readData, this) > 0)
                    fDataArray.remove(0, dataToRemove);
            }
        }
        else
>>>>>>> miniblink49
            fSocket->connectToServer();

        SkGPipeReader reader(canvas);
        size_t bytesRead;
        SkGPipeReader::Status fStatus = reader.playback(fDataArray.begin(),
<<<<<<< HEAD
            fDataArray.count(),
            &bytesRead);
=======
                                                        fDataArray.count(),
                                                        &bytesRead);
>>>>>>> miniblink49
        SkASSERT(SkGPipeReader::kError_Status != fStatus);
        this->inval(NULL);
    }

private:
    bool fSync;
    SkTDArray<char> fDataArray;
    SkTCPClient* fSocket;
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new NetPipeReaderView; }
static SkViewRegister reg(MyFactory);
