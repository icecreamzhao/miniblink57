
#ifndef HTTP_DNS_RESOLVER
#define HTTP_DNS_RESOLVER

#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "des_util.h"
#include "net/base/address_family.h"

namespace net {

class AddressList;

class HttpDnsResolver {
private:
    //初始化Socket
    HttpDnsResolver();

public:
    //关闭socket.
    ~HttpDnsResolver();

    static HttpDnsResolver* getInstance()
    {
        if (_instance == NULL) {
            _instance = new HttpDnsResolver();
        }

        return _instance;
    }

    static std::string getTencentDnsServer();

    int parseDNSInfo(const char* host, AddressFamily address_family, std::string& result_str, AddressList* addr_list, int* os_error);

private:
    static HttpDnsResolver* _instance;
    DesUtil* desUtil_;

    static const char* encryptKey_;
};

}
#endif
