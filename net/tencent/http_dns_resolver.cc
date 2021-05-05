

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "android/log.h"
#include "des_util.h"
#include "http_dns_resolver.h"
#include "net/base/address_list.h"
#include "net/tencent/net_logger.h"

namespace net {

static const char* DNS_TENCENT_SERVER = "119.29.29.29";
static const int BUFFER_SIZE = 1024;
const char* HttpDnsResolver::encryptKey_ = "jZOB/Em=";

HttpDnsResolver* HttpDnsResolver::_instance = NULL;

HttpDnsResolver::HttpDnsResolver()
{
    desUtil_ = new DesUtil(encryptKey_);
}

HttpDnsResolver::~HttpDnsResolver()
{
    delete desUtil_;
}

std::string HttpDnsResolver::getTencentDnsServer()
{
    return DNS_TENCENT_SERVER;
}

int HttpDnsResolver::parseDNSInfo(const char* host, AddressFamily address_family, std::string& rawcontents, AddressList* addr_list, int* os_error)
{
    ///定义sockfd
    int sock_cli = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_cli < 0) //-1
    {
        *os_error = errno;
        close(sock_cli);
        return errno | 0x3400; //52
    }

    int block_flags = 0, nonblock_flags = 0;

    if ((block_flags = fcntl(sock_cli, F_GETFL, 0)) < 0) //-1
    {
        close(sock_cli);
        *os_error = errno;
        return errno | 0x3D00; //61
    }

    if ((nonblock_flags = fcntl(sock_cli, F_SETFL, nonblock_flags | O_NONBLOCK)) < 0) {
        close(sock_cli);
        *os_error = errno;
        return errno | 0x4400; //68
    }

    ///定义sockaddr_in
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80); ///服务器端口
    servaddr.sin_addr.s_addr = inet_addr(DNS_TENCENT_SERVER); ///服务器ip

    ///连接服务器，成功返回0，错误返回-1
    if (connect(sock_cli, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) //-1
    {
        if (errno != EINPROGRESS) {
            close(sock_cli);
            *os_error = errno;
            return errno | 0x5500; //85
        }
    }

    fd_set fdr, fdw;

    FD_ZERO(&fdr);
    FD_ZERO(&fdw);

    FD_SET(sock_cli, &fdr);
    FD_SET(sock_cli, &fdw);

    struct timeval timeout = { 4, 0 };
    /*
       On  success,  select() and pselect() return the number of file descriptors contained in the three returned descriptor sets (that is, the total number of bits
       that are set in readfds, writefds, exceptfds) which may be zero if the timeout expires before anything interesting happens.  On error, -1  is  returned,  and
       errno is set appropriately; the sets and timeout become undefined, so do not rely on their contents after an error.
    */
    int res = select(sock_cli + 1, &fdr, &fdw, NULL, &timeout);
    if (res < 0) //-1  error occured.
    {
        close(sock_cli);
        *os_error = errno;
        return errno | 0x6C00;
    }

    if (res == 0) //time out man page.
    {
        close(sock_cli);
        *os_error = errno;
        return errno | 0x7300;
    }

    if (res == 2) //Never invoked.
    {
        //timeout
        close(sock_cli);
        *os_error = errno;
        return errno | 0x7B00;
    }

    if ((nonblock_flags = fcntl(sock_cli, F_SETFL, block_flags)) < 0) {
        close(sock_cli);
        *os_error = errno;
        return errno | 0x8200;
    }

    int retsnd = setsockopt(sock_cli, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout, sizeof(timeout));
    int retrcv = setsockopt(sock_cli, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));
    if (retsnd < 0 || retrcv < 0) {
        close(sock_cli);
        *os_error = errno;
        return errno | 0x8B00; //139
    }

    /****************************/
    char* encrypt = new char[BUFFER_SIZE];
    memset(encrypt, 0, BUFFER_SIZE * sizeof(char));
    desUtil_->encrypt_domain(host, &encrypt, BUFFER_SIZE);
    /****************************/

    char sendbuf[BUFFER_SIZE];
    memset(sendbuf, 0, BUFFER_SIZE);
    int len = snprintf(sendbuf, BUFFER_SIZE, "GET /d?dn=%s&id=227 HTTP/1.1\r\n", encrypt);
    if (len >= BUFFER_SIZE) {
        close(sock_cli);
        return 123 | 0x9700;
    }
    snprintf(sendbuf + len, BUFFER_SIZE - len, "Host: %s:80\r\n", DNS_TENCENT_SERVER);
    strcat(sendbuf, "UserAgent: QQBrowser X5\r\n");
    strcat(sendbuf, "Accept: text/html,*/*;q=0.8\r\n\r\n");

    delete[] encrypt;

    char recvbuf[BUFFER_SIZE];
    memset(recvbuf, 0, BUFFER_SIZE);

    int sendlen = send(sock_cli, sendbuf, strlen(sendbuf), 0); ///发送
    if (sendlen == -1) {
        *os_error = errno;
        close(sock_cli);
        return errno | 0xA500; //165
    }

    int recvlen = recv(sock_cli, recvbuf, sizeof(recvbuf), 0); ///接收
    if (recvlen != -1) //OK.
    {
        char* split = strstr(recvbuf, "\r\n\r\n");
        if (split != NULL) {
            char* content = split + 4;

            char* raw_content = new char[BUFFER_SIZE];
            memset(raw_content, 0, BUFFER_SIZE * sizeof(char));
            int lendec = desUtil_->decrypt_result(content, &raw_content, BUFFER_SIZE);

            if (lendec <= 0 || strlen(raw_content) < 7) // strlen(1.1.1.1) == 7
            {
                NET_LOG_DNS("HttpDns resolve <%s> to IP <%s>", host, raw_content);
                close(sock_cli);
                return EAI_NODATA | 0xB800;
            }

            //NET_LOG_DNS("Need parse Host %s, Decrypted data is %s", host, raw_content);
            rawcontents = raw_content;
            char* comma = strstr(raw_content, ";");
            if (comma != NULL)
                *comma = 0;

            NET_LOG_DNS("HttpDns resolve <%s> to IP <%s>", host, raw_content);

            struct sockaddr_in resolvedAddr;
            bzero(&resolvedAddr, sizeof(resolvedAddr));

            //resolvedAddr.sin_addr = addr;
            if (inet_aton(raw_content, &resolvedAddr.sin_addr) == 0) //invalid ip address.
            {
                close(sock_cli);
                return errno | 0xCA00; //202
            }

            resolvedAddr.sin_family = AF_INET;
            resolvedAddr.sin_port = htons(80);

            delete[] raw_content;
            IPEndPoint iep;
            if (iep.FromSockAddr((struct sockaddr*)&resolvedAddr, sizeof(resolvedAddr))) {
                addr_list->push_back(iep);
            }
        }
    }

    close(sock_cli);
    if (addr_list->size() > 0) {
        *os_error = 0;
        return 0;
    } else {
        *os_error = EAI_NODATA;
        return EAI_NODATA | 0xDC00;
    }
}

}
