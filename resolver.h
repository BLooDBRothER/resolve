#include <iostream>
#include <unordered_map>
#include <arpa/inet.h>
#include <netdb.h>

class Resolver{
    private:
        struct addrinfo *ai;

    public:
        void resolveIp(char *, char *);
        void resolveName();
        void displayIp();
};
