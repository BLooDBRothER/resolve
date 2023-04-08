#include "dns_resolver.h"

void DnsResolver::resolveIp(char *url, char *protocol){
    getaddrinfo(url, protocol, 0, &ai);
}

void DnsResolver::resolveName(){

}

void DnsResolver::displayIp(){
    struct addrinfo *ai_temp = ai;
    std::unordered_map<uint32_t, bool> ip4_list;
    std::unordered_map<std::string, bool> ip6_list;

    while(ai_temp){
        char ip4[INET_ADDRSTRLEN];
        char ip6[INET6_ADDRSTRLEN];

        if(ai_temp->ai_family == AF_INET){
            struct sockaddr_in *sa4 = (struct sockaddr_in *)ai_temp->ai_addr;
            if(ip4_list[sa4->sin_addr.s_addr]){
                ai_temp = ai_temp->ai_next;
                continue;
            }
            inet_ntop(AF_INET, &sa4->sin_addr.s_addr, ip4, INET_ADDRSTRLEN);
            std::cout << "IP4: " << ip4 << std::endl;
            ip4_list[sa4->sin_addr.s_addr] = true;
        }
        else{
            struct sockaddr_in6 *sa6 = (struct sockaddr_in6 *)ai_temp->ai_addr;
            inet_ntop(AF_INET6, &sa6->sin6_addr.s6_addr, ip6, INET6_ADDRSTRLEN);
            if(ip6_list[ip6]){
                ai_temp = ai_temp->ai_next;
                continue;
            }
            std::cout << "IP6: " << ip6 << std::endl;
            ip6_list[ip6] = true;
        }
        ai_temp = ai_temp->ai_next;
    }
}

