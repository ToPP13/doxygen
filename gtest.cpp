#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <gtest/gtest.h>
#include "lib.h"

TEST(gtest_version, gtest_version_basic)
{
    ASSERT_GT(version(), 0);
}


TEST(gtest_intToBytes, gtest_intToBytes_basic)
{
    auto d = int2Bytes(1234);
    std::vector<uint> awaited_res{0, 0, 4, 210};
    ASSERT_EQ(d,awaited_res);
}

TEST(gtest_print_ip, gtest_print_ip_basic)
{

//    Печать адреса как char(-1)
//    - Печать адреса как short(0)
//    - Печать адреса как int(2130706433)
//    - Печать адреса как long(8875824491850138409)

    std::string output("");
    std::string res = "0.0.4.210";
    std::string res_short = "4.210";
    std::string res_char = "255";

    int int_test = 1234;
    testing::internal::CaptureStdout();
    print_ip(int_test);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output,res);


    short short_test(1234);
    testing::internal::CaptureStdout();
    print_ip(short_test);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output,res_short);

    int long_test = 1234;
    testing::internal::CaptureStdout();
    print_ip(long_test);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output,res);

    char char_test(-1);
    testing::internal::CaptureStdout();
    print_ip(char_test);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output,res_char);

    std::string str_test = "trololo";
    testing::internal::CaptureStdout();
    print_ip(str_test);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output,str_test);

    std::vector<int> vc_test{0,0,4,210};
    testing::internal::CaptureStdout();
    print_ip(vc_test);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output,res);


    std::list<int> list_test{0,0,4,210};
    testing::internal::CaptureStdout();
    print_ip(list_test);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output,res);

    auto tuple_test = std::make_tuple(0,0,4,210);
    testing::internal::CaptureStdout();
    print_ip(tuple_test);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output,res);
}


