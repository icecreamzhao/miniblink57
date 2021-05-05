
#ifndef UDP_DNS_RESOLVER
#define UDP_DNS_RESOLVER

#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "net/base/address_family.h"

namespace net {

class AddressList;

class UdpDnsResolver {
private:
    UdpDnsResolver() { }

public:
    ~UdpDnsResolver() { }
    static UdpDnsResolver* getInstance()
    {
        if (_instance == NULL) {
            _instance = new UdpDnsResolver();
        }

        return _instance;
    }

    static std::string getTencentDnsServer();
    int parseDNSInfo(const char* host, AddressFamily address_family, HostResolverFlags host_resolver_flags, AddressList* addr_list, int* os_error);

private:
    int send_dns_request(const char* dns_name);
    int parse_dns_response(struct addrinfo* ai, AddressList* addr_list);

    /**
     * Generate DNS question chunk
     */
    void generate_question(const char* dns_name, unsigned char* buf, int* len);

    /**
     * Check whether the current byte is 
     * a dns pointer or a length
     */
    int is_pointer(unsigned char in);

    /**
     * Parse data chunk into dns name
     * @param chunk The complete response chunk
     * @param ptr The pointer points to data
     * @param out This will be filled with dns name
     * @param len This will be filled with the length of dns name
     */
    void parse_dns_name(unsigned char* chunk, unsigned char* ptr, char* out, int* len);

    static UdpDnsResolver* _instance;
    int socketfd;
    struct sockaddr_in dest;
};

}
#endif
