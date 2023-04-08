#include <iostream>
#include "dns_resolver.h"

using namespace std;

int main(){
    DnsResolver resolver;

    char input[100];
    char protocol[30];

    cout << "Enter URL: ";
    cin >> input;
    cout << endl << "Enter protocol: ";
    cin >> protocol;

    resolver.resolveIp(input, protocol);
    resolver.displayIp();
}
