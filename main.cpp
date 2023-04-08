#include <iostream>
#include <string.h>
#include "resolver.h"

#define HELP_MSG "<name> - To convert domain name -> IP\n<ip> - To convert IP -> name"
#define INFO_MSG "Provide with any one of the following option\n"

using namespace std;

int main(int argc, char *argv[]){
    Resolver resolver;
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
    else if(!strcmp(argv[1], "help")){
        cout << HELP_MSG;
    }
    else{
        cout << INFO_MSG << HELP_MSG;
    }
}
