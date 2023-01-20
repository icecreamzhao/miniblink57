/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkSockets.h"
#include "SkData.h"
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <unistd.h>

SkSocket::SkSocket()
{
=======
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "SkSockets.h"
#include "SkData.h"

SkSocket::SkSocket() {
>>>>>>> miniblink49
    fMaxfd = 0;
    FD_ZERO(&fMasterSet);
    fConnected = false;
    fReady = false;
    fReadSuspended = false;
    fWriteSuspended = false;
    fSockfd = this->createSocket();
}

<<<<<<< HEAD
SkSocket::~SkSocket()
{
=======
SkSocket::~SkSocket() {
>>>>>>> miniblink49
    this->closeSocket(fSockfd);
    shutdown(fSockfd, 2); //stop sending/receiving
}

<<<<<<< HEAD
int SkSocket::createSocket()
{
=======
int SkSocket::createSocket() {
>>>>>>> miniblink49
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        SkDebugf("ERROR opening socket\n");
        return -1;
    }
    int reuse = 1;

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0) {
        SkDebugf("error: %s\n", strerror(errno));
        return -1;
    }
#ifdef NONBLOCKING_SOCKETS
    this->setNonBlocking(sockfd);
#endif
    //SkDebugf("Opened fd:%d\n", sockfd);
    fReady = true;
    return sockfd;
}

<<<<<<< HEAD
void SkSocket::closeSocket(int sockfd)
{
=======
void SkSocket::closeSocket(int sockfd) {
>>>>>>> miniblink49
    if (!fReady)
        return;

    close(sockfd);
    //SkDebugf("Closed fd:%d\n", sockfd);

    if (FD_ISSET(sockfd, &fMasterSet)) {
        FD_CLR(sockfd, &fMasterSet);
        if (sockfd >= fMaxfd) {
            while (FD_ISSET(fMaxfd, &fMasterSet) == false && fMaxfd > 0)
                fMaxfd -= 1;
        }
    }
    if (0 == fMaxfd)
        fConnected = false;
}

<<<<<<< HEAD
void SkSocket::onFailedConnection(int sockfd)
{
    this->closeSocket(sockfd);
}

void SkSocket::setNonBlocking(int sockfd)
{
=======
void SkSocket::onFailedConnection(int sockfd) {
    this->closeSocket(sockfd);
}

void SkSocket::setNonBlocking(int sockfd) {
>>>>>>> miniblink49
    int flags = fcntl(sockfd, F_GETFL);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
}

<<<<<<< HEAD
void SkSocket::addToMasterSet(int sockfd)
{
=======
void SkSocket::addToMasterSet(int sockfd) {
>>>>>>> miniblink49
    FD_SET(sockfd, &fMasterSet);
    if (sockfd > fMaxfd)
        fMaxfd = sockfd;
}

int SkSocket::readPacket(void (*onRead)(int, const void*, size_t, DataType,
<<<<<<< HEAD
                             void*),
    void* context)
{
=======
                                        void*), void* context) {
>>>>>>> miniblink49
    if (!fConnected || !fReady || NULL == onRead || NULL == context
        || fReadSuspended)
        return -1;

    int totalBytesRead = 0;

    char packet[PACKET_SIZE];
    for (int i = 0; i <= fMaxfd; ++i) {
<<<<<<< HEAD
        if (!FD_ISSET(i, &fMasterSet))
=======
        if (!FD_ISSET (i, &fMasterSet))
>>>>>>> miniblink49
            continue;

        memset(packet, 0, PACKET_SIZE);
        SkDynamicMemoryWStream stream;
        int attempts = 0;
        bool failure = false;
        int bytesReadInTransfer = 0;
        int bytesReadInPacket = 0;
        header h;
        h.done = false;
        h.bytes = 0;
        while (!h.done && fConnected && !failure) {
            int retval = read(i, packet + bytesReadInPacket,
<<<<<<< HEAD
                PACKET_SIZE - bytesReadInPacket);
=======
                              PACKET_SIZE - bytesReadInPacket);
>>>>>>> miniblink49

            ++attempts;
            if (retval < 0) {
#ifdef NONBLOCKING_SOCKETS
                if (errno == EWOULDBLOCK || errno == EAGAIN) {
                    if (bytesReadInPacket > 0 || bytesReadInTransfer > 0)
                        continue; //incomplete packet or frame, keep tring
                    else
                        break; //nothing to read
                }
#endif
                //SkDebugf("Read() failed with error: %s\n", strerror(errno));
                failure = true;
                break;
            }

            if (retval == 0) {
                //SkDebugf("Peer closed connection or connection failed\n");
                failure = true;
                break;
            }

            SkASSERT(retval > 0);
            bytesReadInPacket += retval;
            if (bytesReadInPacket < PACKET_SIZE) {
                //SkDebugf("Read %d/%d\n", bytesReadInPacket, PACKET_SIZE);
                continue; //incomplete packet, keep trying
            }

            SkASSERT((bytesReadInPacket == PACKET_SIZE) && !failure);
            memcpy(&h.done, packet, sizeof(bool));
            memcpy(&h.bytes, packet + sizeof(bool), sizeof(int));
            memcpy(&h.type, packet + sizeof(bool) + sizeof(int), sizeof(DataType));
            if (h.bytes > CONTENT_SIZE || h.bytes <= 0) {
                //SkDebugf("bad packet\n");
                failure = true;
                break;
            }
            //SkDebugf("read packet(done:%d, bytes:%d) from fd:%d in %d tries\n",
            //         h.done, h.bytes, fSockfd, attempts);
            stream.write(packet + HEADER_SIZE, h.bytes);
            bytesReadInPacket = 0;
            attempts = 0;
            bytesReadInTransfer += h.bytes;
        }

        if (failure) {
            onRead(i, NULL, 0, h.type, context);
            this->onFailedConnection(i);
            continue;
        }

        if (bytesReadInTransfer > 0) {
            SkData* data = stream.copyToData();
            SkASSERT(data->size() == bytesReadInTransfer);
            onRead(i, data->data(), data->size(), h.type, context);
            data->unref();

            totalBytesRead += bytesReadInTransfer;
        }
    }
    return totalBytesRead;
}

<<<<<<< HEAD
int SkSocket::writePacket(void* data, size_t size, DataType type)
{
    if (size < 0 || NULL == data || !fConnected || !fReady || fWriteSuspended)
=======
int SkSocket::writePacket(void* data, size_t size, DataType type) {
    if (size < 0|| NULL == data || !fConnected || !fReady || fWriteSuspended)
>>>>>>> miniblink49
        return -1;

    int totalBytesWritten = 0;
    header h;
    char packet[PACKET_SIZE];
    for (int i = 0; i <= fMaxfd; ++i) {
<<<<<<< HEAD
        if (!FD_ISSET(i, &fMasterSet))
=======
        if (!FD_ISSET (i, &fMasterSet))
>>>>>>> miniblink49
            continue;

        int bytesWrittenInTransfer = 0;
        int bytesWrittenInPacket = 0;
        int attempts = 0;
        bool failure = false;
        while (bytesWrittenInTransfer < size && fConnected && !failure) {
            memset(packet, 0, PACKET_SIZE);
            h.done = (size - bytesWrittenInTransfer <= CONTENT_SIZE);
            h.bytes = (h.done) ? size - bytesWrittenInTransfer : CONTENT_SIZE;
            h.type = type;
            memcpy(packet, &h.done, sizeof(bool));
            memcpy(packet + sizeof(bool), &h.bytes, sizeof(int));
            memcpy(packet + sizeof(bool) + sizeof(int), &h.type, sizeof(DataType));
            memcpy(packet + HEADER_SIZE, (char*)data + bytesWrittenInTransfer,
<<<<<<< HEAD
                h.bytes);

            int retval = write(i, packet + bytesWrittenInPacket,
                PACKET_SIZE - bytesWrittenInPacket);
=======
                   h.bytes);

            int retval = write(i, packet + bytesWrittenInPacket,
                               PACKET_SIZE - bytesWrittenInPacket);
>>>>>>> miniblink49
            attempts++;

            if (retval < 0) {
                if (errno == EPIPE) {
                    //SkDebugf("broken pipe, client closed connection");
                    failure = true;
                    break;
                }
#ifdef NONBLOCKING_SOCKETS
                else if (errno == EWOULDBLOCK || errno == EAGAIN) {
                    if (bytesWrittenInPacket > 0 || bytesWrittenInTransfer > 0)
                        continue; //incomplete packet or frame, keep trying
                    else
                        break; //client not available, skip current transfer
                }
#endif
                else {
                    //SkDebugf("write(%d) failed with error:%s\n", i,
                    //         strerror(errno));
                    failure = true;
                    break;
                }
            }

            bytesWrittenInPacket += retval;
            if (bytesWrittenInPacket < PACKET_SIZE)
                continue; //incomplete packet, keep trying

            SkASSERT(bytesWrittenInPacket == PACKET_SIZE);
            //SkDebugf("wrote to packet(done:%d, bytes:%d) to fd:%d in %d tries\n",
            //         h.done, h.bytes, i, attempts);
            bytesWrittenInTransfer += h.bytes;
            bytesWrittenInPacket = 0;
            attempts = 0;
        }

        if (failure)
            this->onFailedConnection(i);

        totalBytesWritten += bytesWrittenInTransfer;
    }
    return totalBytesWritten;
}

////////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
SkTCPServer::SkTCPServer(int port)
{
=======
SkTCPServer::SkTCPServer(int port) {
>>>>>>> miniblink49
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(fSockfd, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        SkDebugf("ERROR on binding: %s\n", strerror(errno));
        fReady = false;
    }
}

<<<<<<< HEAD
SkTCPServer::~SkTCPServer()
{
    this->disconnectAll();
}

int SkTCPServer::acceptConnections()
{
=======
SkTCPServer::~SkTCPServer() {
    this->disconnectAll();
}

int SkTCPServer::acceptConnections() {
>>>>>>> miniblink49
    if (!fReady)
        return -1;

    listen(fSockfd, MAX_WAITING_CLIENTS);
    int newfd;
    for (int i = 0; i < MAX_WAITING_CLIENTS; ++i) {
#ifdef NONBLOCKING_SOCKETS
        fd_set workingSet;
        FD_ZERO(&workingSet);
        FD_SET(fSockfd, &workingSet);
        timeval timeout;
<<<<<<< HEAD
        timeout.tv_sec = 0;
=======
        timeout.tv_sec  = 0;
>>>>>>> miniblink49
        timeout.tv_usec = 0;
        int sel = select(fSockfd + 1, &workingSet, NULL, NULL, &timeout);
        if (sel < 0) {
            SkDebugf("select() failed with error %s\n", strerror(errno));
            continue;
        }
        if (sel == 0) //select() timed out
            continue;
#endif
        sockaddr_in clientAddr;
        socklen_t clientLen = sizeof(clientAddr);
        newfd = accept(fSockfd, (struct sockaddr*)&clientAddr, &clientLen);
<<<<<<< HEAD
        if (newfd < 0) {
=======
        if (newfd< 0) {
>>>>>>> miniblink49
            SkDebugf("accept() failed with error %s\n", strerror(errno));
            continue;
        }
        SkDebugf("New incoming connection - %d\n", newfd);
        fConnected = true;
#ifdef NONBLOCKING_SOCKETS
        this->setNonBlocking(newfd);
#endif
        this->addToMasterSet(newfd);
    }
    return 0;
}

<<<<<<< HEAD
int SkTCPServer::disconnectAll()
{
=======

int SkTCPServer::disconnectAll() {
>>>>>>> miniblink49
    if (!fConnected || !fReady)
        return -1;
    for (int i = 0; i <= fMaxfd; ++i) {
        if (FD_ISSET(i, &fMasterSet))
            this->closeSocket(i);
    }
    fConnected = false;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
SkTCPClient::SkTCPClient(const char* hostname, int port)
{
=======
SkTCPClient::SkTCPClient(const char* hostname, int port) {
>>>>>>> miniblink49
    //Add fSockfd since the client will be using it to read/write
    this->addToMasterSet(fSockfd);

    hostent* server = gethostbyname(hostname);
    if (server) {
        fServerAddr.sin_family = AF_INET;
        memcpy((char*)&fServerAddr.sin_addr.s_addr, (char*)server->h_addr,
<<<<<<< HEAD
            server->h_length);
        fServerAddr.sin_port = htons(port);
    } else {
=======
               server->h_length);
        fServerAddr.sin_port = htons(port);
    }
    else {
>>>>>>> miniblink49
        //SkDebugf("ERROR, no such host\n");
        fReady = false;
    }
}

<<<<<<< HEAD
void SkTCPClient::onFailedConnection(int sockfd)
{ //cleanup and recreate socket
=======
void SkTCPClient::onFailedConnection(int sockfd) { //cleanup and recreate socket
>>>>>>> miniblink49
    SkASSERT(sockfd == fSockfd);
    this->closeSocket(fSockfd);
    fSockfd = this->createSocket();
    //Add fSockfd since the client will be using it to read/write
    this->addToMasterSet(fSockfd);
}

<<<<<<< HEAD
int SkTCPClient::connectToServer()
{
=======
int SkTCPClient::connectToServer() {
>>>>>>> miniblink49
    if (!fReady)
        return -1;
    if (fConnected)
        return 0;

    int conn = connect(fSockfd, (sockaddr*)&fServerAddr, sizeof(fServerAddr));
    if (conn < 0) {
#ifdef NONBLOCKING_SOCKETS
        if (errno == EINPROGRESS || errno == EALREADY)
            return conn;
#endif
        if (errno != EISCONN) {
            //SkDebugf("error: %s\n", strerror(errno));
            this->onFailedConnection(fSockfd);
            return conn;
        }
    }
    fConnected = true;
    SkDebugf("Succesfully reached server\n");
    return 0;
}
