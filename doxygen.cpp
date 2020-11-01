#ifndef __PRETTY_FUNCTION__
#include "pretty.h"
#endif

#include <iostream>
#include <vector>
#include <map>

#include "lib.h"




int main(int, char *[]) {

    char test_char(-1);
    print_ip(test_char);
    std::cout << std::endl;

    short test_short(0);
    print_ip(test_short);
    std::cout << std::endl;

    int test_int(2130706433);
    print_ip(test_int);
    std::cout << std::endl;

    long test_long(8875824491850138409);
    print_ip(test_long);
    std::cout << std::endl;

    return 0;
}
