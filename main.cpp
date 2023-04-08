#include <iostream>
#include <string.h>
#include "resolver.h"

#define INFO_MSG "Provide with any one of the following option\n<name> - To convert domain name -> IP\n<ip> - To convert IP -> name"

using namespace std;

int main(int argc, char *argv[]){
    Resolver resolver;
    if(argc < 2){
        cout << INFO_MSG;
        return 0;
    }
    char input[100];
    char protocol[30];

    if(!strcmp(argv[1], "name")){
        cout << "Enter URL: ";
        cin >> input;
        cout << endl << "Enter protocol: ";
        cin >> protocol;
        resolver.resolveIp(input, protocol);
    }
    else if(!strcmp(argv[1], "ip")){
        cout << "Enter IP Address: ";
        cin >> input;
        resolver.resolveName(input);
    }
    else{
        cout << INFO_MSG;
    }
}
