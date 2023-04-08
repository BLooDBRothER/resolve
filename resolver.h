#include <iostream>
#include <unordered_map>
#include <arpa/inet.h>
#include <netdb.h>

using namespace std;

class Resolver{
    private:
        struct addrinfo *ai; // to store ip addr info
        char hostname[2048], service[20]; // to store domain info
        void displayIp();

    public:
        void resolveIp(char *, char *);
        void resolveName(char *);
};
