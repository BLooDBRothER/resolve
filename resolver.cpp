#include "resolver.h"

void Resolver::resolveIp(char *url, char *protocol){
    int res = getaddrinfo(url, protocol, 0, &ai);
    if(res){
        cout << "Invalid Data";
        return;
    }
    displayIp();
}

void Resolver::resolveName(char *ip){
    struct sockaddr_in sa;
    inet_pton(AF_INET, ip, &sa.sin_addr);
    sa.sin_family = AF_INET;

    int res = getnameinfo((struct sockaddr *)&sa, sizeof sa, hostname, sizeof hostname, service, sizeof service, NI_NAMEREQD);
    if(res){
        cout << "No Name Found";
        return;
    }
    cout << hostname;
}

void Resolver::displayIp(){
    struct addrinfo *ai_temp = ai;
    unordered_map<string, bool> ip_list;

    while(ai_temp){
        void *addr;
        char ip_str[INET6_ADDRSTRLEN];
        string ip_ver;

        if(ai_temp->ai_family == AF_INET){
            struct sockaddr_in *sa4 = (struct sockaddr_in *)ai_temp->ai_addr;
            addr = &sa4->sin_addr.s_addr;
            ip_ver = "IP4: ";
        }
        else{
            struct sockaddr_in6 *sa6 = (struct sockaddr_in6 *)ai_temp->ai_addr;
            addr = &sa6->sin6_addr.s6_addr;
            ip_ver = "IP6: ";
        }
        inet_ntop(ai_temp->ai_family, addr, ip_str, sizeof ip_str);
        if(ip_list[ip_str]){
            ai_temp = ai_temp->ai_next;
            continue;
        }
        ip_list[ip_str] = true;
        cout << ip_ver << ip_str << endl;
        ai_temp = ai_temp->ai_next;
    }
}

