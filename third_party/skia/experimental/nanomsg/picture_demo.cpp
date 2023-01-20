<<<<<<< HEAD
/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

=======
>>>>>>> miniblink49
#include "nanomsg/src/nn.h"
#include "nanomsg/src/pipeline.h"
#include "nanomsg/src/reqrep.h"

#include "SkCanvas.h"
#include "SkCommandLineFlags.h"
#include "SkData.h"
#include "SkForceLinking.h"
#include "SkGraphics.h"
#include "SkImageEncoder.h"
#include "SkOSFile.h"
#include "SkPicture.h"
#include "SkRandom.h"
#include "SkStream.h"

__SK_FORCE_IMAGE_DECODER_LINKING;

// To keep things simple, PictureHeader is fixed-size POD.
struct PictureHeader {
<<<<<<< HEAD
    SkMatrix matrix;
    SkRect clip;
    SkXfermode::Mode xfermode;
    pid_t pid;
    uint8_t alpha;
=======
    SkMatrix         matrix;
    SkRect           clip;
    SkXfermode::Mode xfermode;
    pid_t            pid;
    uint8_t          alpha;
>>>>>>> miniblink49

    PictureHeader()
        : matrix(SkMatrix::I())
        , clip(SkRect::MakeLargest())
        , xfermode(SkXfermode::kSrcOver_Mode)
        , pid(getpid())
<<<<<<< HEAD
        , alpha(0xFF)
    {
    }
};

// A little adaptor: nn_iovec wants a non-const pointer for no obvious reason.
static struct nn_iovec create_iov(const void* ptr, size_t size)
{
=======
        , alpha(0xFF) {}
};

// A little adaptor: nn_iovec wants a non-const pointer for no obvious reason.
static struct nn_iovec create_iov(const void* ptr, size_t size) {
>>>>>>> miniblink49
    struct nn_iovec iov = { const_cast<void*>(ptr), size };
    return iov;
}

<<<<<<< HEAD
static void send_picture(int socket, const PictureHeader& header, const SkData& skp)
{
=======
static void send_picture(int socket, const PictureHeader& header, const SkData& skp) {
>>>>>>> miniblink49
    // Vectored IO lets us send header and skp contiguously without first
    // copying them to a contiguous buffer.
    struct nn_iovec iov[] = {
        create_iov(&header, sizeof(header)),
        create_iov(skp.data(), skp.size()),
    };

    struct nn_msghdr msg;
    sk_bzero(&msg, sizeof(msg));
<<<<<<< HEAD
    msg.msg_iov = iov;
    msg.msg_iovlen = SK_ARRAY_COUNT(iov);

    nn_sendmsg(socket, &msg, 0 /*flags*/);
}

static sk_sp<SkPicture> recv_picture(int socket, PictureHeader* header)
{
    static const size_t hSize = sizeof(*header); // It's easy to slip up and use sizeof(header).

    void* msg;
    int size = nn_recv(socket, &msg, NN_MSG, 0 /*flags*/);
=======
    msg.msg_iov    = iov;
    msg.msg_iovlen = SK_ARRAY_COUNT(iov);

    nn_sendmsg(socket, &msg, 0/*flags*/);
}

static SkPicture* recv_picture(int socket, PictureHeader* header) {
    static const size_t hSize = sizeof(*header);  // It's easy to slip up and use sizeof(header).

    void* msg;
    int size = nn_recv(socket, &msg, NN_MSG, 0/*flags*/);
>>>>>>> miniblink49
    SkDebugf("%d bytes", size);

    // msg is first a fixed-size header, then an .skp.
    memcpy(header, msg, hSize);
    SkMemoryStream stream((uint8_t*)msg + hSize, size - hSize);
<<<<<<< HEAD
    sk_sp<SkPicture> pic = SkPicture::MakeFromStream(&stream);
=======
    SkPicture* pic = SkPicture::CreateFromStream(&stream);
>>>>>>> miniblink49

    SkDebugf(" from proccess %d:", header->pid);

    nn_freemsg(msg);
    return pic;
}

<<<<<<< HEAD
static void client(const char* skpPath, const char* dataEndpoint)
{
=======
static void client(const char* skpPath, const char* dataEndpoint) {
>>>>>>> miniblink49
    // Read the .skp.
    SkAutoTUnref<const SkData> skp(SkData::NewFromFileName(skpPath));
    if (!skp) {
        SkDebugf("Couldn't read %s\n", skpPath);
        exit(1);
    }
    SkMemoryStream stream(skp->data(), skp->size());
<<<<<<< HEAD
    sk_sp<SkPicture> picture(SkPicture::MakeFromStream(&stream));
=======
    SkAutoTUnref<SkPicture> picture(SkPicture::CreateFromStream(&stream));
>>>>>>> miniblink49

    PictureHeader header;
    SkRandom rand(picture->cullRect().width() * picture->cullRect().height());
    SkScalar r = rand.nextRangeScalar(0, picture->cullRect().width()),
             b = rand.nextRangeScalar(0, picture->cullRect().height()),
             l = rand.nextRangeScalar(0, r),
             t = rand.nextRangeScalar(0, b);
<<<<<<< HEAD
    header.clip.setLTRB(l, t, r, b);
=======
    header.clip.setLTRB(l,t,r,b);
>>>>>>> miniblink49
    header.matrix.setTranslate(-l, -t);
    header.matrix.postRotate(rand.nextRangeScalar(-25, 25));
    header.alpha = 0x7F;

    //Clients use NN_REQ (request) type sockets.
    int socket = nn_socket(AF_SP, NN_REQ);

    // Clients connect a socket to an endpoint.
    nn_connect(socket, dataEndpoint);

    // Send the picture and its header.
    SkDebugf("Sending %s (%d bytes)...", skpPath, skp->size());
    send_picture(socket, header, *skp);

    // Wait for ack.
    uint8_t ack;
<<<<<<< HEAD
    nn_recv(socket, &ack, sizeof(ack), 0 /*flags*/);
=======
    nn_recv(socket, &ack, sizeof(ack), 0/*flags*/);
>>>>>>> miniblink49
    SkDebugf(" ok.\n");
}

// Wait until socketA or socketB has something to tell us, and return which one.
<<<<<<< HEAD
static int poll_in(int socketA, int socketB)
{
=======
static int poll_in(int socketA, int socketB) {
>>>>>>> miniblink49
    struct nn_pollfd polls[] = {
        { socketA, NN_POLLIN, 0 },
        { socketB, NN_POLLIN, 0 },
    };

<<<<<<< HEAD
    nn_poll(polls, SK_ARRAY_COUNT(polls), -1 /*no timeout*/);

    if (polls[0].revents & NN_POLLIN) {
        return socketA;
    }
    if (polls[1].revents & NN_POLLIN) {
        return socketB;
    }
=======
    nn_poll(polls, SK_ARRAY_COUNT(polls), -1/*no timeout*/);

    if (polls[0].revents & NN_POLLIN) { return socketA; }
    if (polls[1].revents & NN_POLLIN) { return socketB; }
>>>>>>> miniblink49

    SkFAIL("unreachable");
    return 0;
}

<<<<<<< HEAD
static void server(const char* dataEndpoint, const char* controlEndpoint, SkCanvas* canvas)
{
    // NN_REP sockets receive a request then make a reply.  NN_PULL sockets just receive a request.
    int data = nn_socket(AF_SP, NN_REP);
    int control = nn_socket(AF_SP, NN_PULL);

    // Servers bind a socket to an endpoint.
    nn_bind(data, dataEndpoint);
=======
static void server(const char* dataEndpoint, const char* controlEndpoint, SkCanvas* canvas) {
    // NN_REP sockets receive a request then make a reply.  NN_PULL sockets just receive a request.
    int data    = nn_socket(AF_SP, NN_REP);
    int control = nn_socket(AF_SP, NN_PULL);

    // Servers bind a socket to an endpoint.
    nn_bind(data,    dataEndpoint);
>>>>>>> miniblink49
    nn_bind(control, controlEndpoint);

    while (true) {
        int ready = poll_in(data, control);

        // If we got any message on the control socket, we can stop.
        if (ready == control) {
            break;
        }

        // We should have an .skp waiting for us on data socket.
        PictureHeader header;
<<<<<<< HEAD
        sk_sp<SkPicture> picture(recv_picture(data, &header));
=======
        SkAutoTUnref<SkPicture> picture(recv_picture(data, &header));
>>>>>>> miniblink49

        SkPaint paint;
        paint.setAlpha(header.alpha);
        paint.setXfermodeMode(header.xfermode);

        canvas->saveLayer(NULL, &paint);
<<<<<<< HEAD
        canvas->concat(header.matrix);
        canvas->clipRect(header.clip);
        picture->playback(canvas);
=======
            canvas->concat(header.matrix);
            canvas->clipRect(header.clip);
            picture->playback(canvas);
>>>>>>> miniblink49
        canvas->restore();
        SkDebugf(" drew");

        // Send back an ack.
        uint8_t ack = 42;
<<<<<<< HEAD
        nn_send(data, &ack, sizeof(ack), 0 /*flags*/);
=======
        nn_send(data, &ack, sizeof(ack), 0/*flags*/);
>>>>>>> miniblink49
        SkDebugf(" and acked.\n");
    }
}

<<<<<<< HEAD
static void stop(const char* controlEndpoint)
{
=======
static void stop(const char* controlEndpoint) {
>>>>>>> miniblink49
    // An NN_PUSH socket can send messages but not receive them.
    int control = nn_socket(AF_SP, NN_PUSH);
    nn_connect(control, controlEndpoint);

    // Sending anything (including this 0-byte message) will tell server() to stop.
<<<<<<< HEAD
    nn_send(control, NULL, 0, 0 /*flags*/);
=======
    nn_send(control, NULL, 0, 0/*flags*/);
>>>>>>> miniblink49
}

DEFINE_string2(skp, r, "", ".skp to send (as client)");
DEFINE_string2(png, w, "", ".png to write (as server)");
DEFINE_bool(stop, false, "If true, tell server to stop and write its canvas out as a .png.");
<<<<<<< HEAD
DEFINE_string(data, "ipc://nanomsg-picture-data", "Endpoint for sending pictures.");
DEFINE_string(control, "ipc://nanomsg-picture-control", "Endpoint for control channel.");

int main(int argc, char** argv)
{
=======
DEFINE_string(data,    "ipc://nanomsg-picture-data",    "Endpoint for sending pictures.");
DEFINE_string(control, "ipc://nanomsg-picture-control", "Endpoint for control channel.");

int main(int argc, char** argv) {
>>>>>>> miniblink49
    SkAutoGraphics ag;
    SkCommandLineFlags::Parse(argc, argv);

    if (FLAGS_stop) {
        stop(FLAGS_control[0]);
    }

    if (!FLAGS_skp.isEmpty()) {
        client(FLAGS_skp[0], FLAGS_data[0]);
    }

    if (!FLAGS_png.isEmpty()) {
        SkBitmap bitmap;
        bitmap.allocN32Pixels(1000, 1000);
        SkCanvas canvas(bitmap);
        canvas.clear(0xFFFFFFFF);

        server(FLAGS_data[0], FLAGS_control[0], &canvas);
        canvas.flush();

        SkImageEncoder::EncodeFile(FLAGS_png[0], bitmap, SkImageEncoder::kPNG_Type, 100);
        SkDebugf("Wrote %s.\n", FLAGS_png[0]);
    }

    return 0;
}
