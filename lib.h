#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <tuple>

int version();


#define USE_PRETTY 1


// calculate factorial of int
template<typename T>
void print_ip_as_vec(T begin, T end)
{
    for(T ip_part = begin; ip_part != end; ++ip_part)
    {
        if (ip_part != begin)
        {
            std::cout << ".";
        }
        std::cout << *ip_part;
    }
}

//void print_ip(int);
void print_ip(long);

void print_ip(std::string);

template<typename Container>
void print_ip(const Container& cont)
{
    print_ip_as_vec(cont.cbegin(), cont.cend());
//    for (auto const& x : cont)
//    {
//        if (&x != cont.back())
//        {
//            std::cout << ".";
//        }
//        std::cout << *x;
//    }
    //   std::cout << '\n';
//   for (auto const& x : cont) {
//      std::cout << x << " ";
//   }
//   std::cout << '\n';
}

//template<typename T>
//void print_ip(std::list<T> vc)
//{
//    print_ip_as_vec(vc.begin(), vc.end());
//}

//template<typename T>
//void print_ip(std::vector<T> ls)
//{
//    print_ip_as_vec(ls.begin(), ls.end());
//}

//template <typename... T>
//void foo(int a, std::tuple<T...> TupleTest);

//// make_tuple so we don't need to enter all the type names
//foo(0, std::make_tuple(2, "TEST", 5.5));


// https://stackoverflow.com/questions/42494715/c-transform-a-stdtuplea-a-a-to-a-stdvector-or-stddeque
template<typename first_type, typename tuple_type, size_t ...index>
auto to_vector_helper(const tuple_type &t, std::index_sequence<index...>)
{
    return std::vector<first_type>{
        std::get<index>(t)...
            };
}

template<typename first_type, typename ...others>
auto to_vector(const std::tuple<first_type, others...> &t)
{
    typedef typename std::remove_reference<decltype(t)>::type tuple_type;

    constexpr auto s =
        std::tuple_size<tuple_type>::value;

    return to_vector_helper<first_type, tuple_type>
        (t, std::make_index_sequence<s>{});
}

// https://stackoverflow.com/questions/8747406/tuple-as-function-argument
template <typename... T>
void print_ip(std::tuple<T...> TupleTest)
{
    auto to_vec = to_vector(TupleTest);
    print_ip(to_vec);
}

template<typename Val>
std::vector<Val> int2Bytes(Val paramInt)
{
    unsigned char* p = (unsigned char*)  &paramInt;
    std::vector<Val> arrayOfByte(4);
    for (Val i = 0; i < 4; i++)
        arrayOfByte[3-i] = p[i];
    return arrayOfByte;
}
//std::vector<long> int2Bytes(long paramInt);
