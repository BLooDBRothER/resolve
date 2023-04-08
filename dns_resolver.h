#include <iostream>
#include <unordered_map>
#include <arpa/inet.h>
#include <netdb.h>

class DnsResolver{
    private:
        struct addrinfo *ai;

    public:
        void resolveIp(char *, char *);
        void resolveName();
        void displayIp();
};
