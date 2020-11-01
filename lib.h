#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <tuple>
#include "type_traits"

int version();


#define USE_PRETTY 1


template<typename T>
std::vector<uint> int2Bytes(T paramInt) {
    unsigned char *p = (unsigned char *) &paramInt;
    size_t sz = sizeof(T);

    std::vector<uint> arrayOfByte(sz);
    for (size_t i = 0; i < sz; i++)
    {
        arrayOfByte[sz - 1 - i] = static_cast<uint>(p[i]);
    }
    return arrayOfByte;
}

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

template<typename Container, typename Container::iterator* = nullptr>
void print_ip(const Container& cont)
{
    print_ip_as_vec(cont.cbegin(), cont.cend());
}


template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
void print_ip(T & val)
{
    auto res = int2Bytes(val);
    print_ip_as_vec(res.begin(), res.end());
}

void print_ip(std::string & ip);



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
