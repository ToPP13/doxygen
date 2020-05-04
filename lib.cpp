#include "lib.h"
#include "version.h"

int version()
{
    return PROJECT_VERSION_PATCH;
}


void print_ip(long int ip_as_int)
{
    auto res = int2Bytes(ip_as_int);
    print_ip_as_vec(res.begin(), res.end());
}


void print_ip(std::string ip)
{
    std::cout << ip << std::endl;;
}


