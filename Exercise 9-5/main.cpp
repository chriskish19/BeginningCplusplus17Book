/*exercise 9-5. Can you think of a way to verify that the compiler generates only one
instance of a function template for any given argument type? Do so for the larger()
function in Ex9_01.cpp*/



// Using a function template
#include <iostream>
#include <string>

// printing out types
#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

template <class T>
std::string type_name();


template<typename T> T larger(T a, T b);    // Function template prototype

int main()
{
    std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
    std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;

    int big_int{ 17011983 }, small_int{ 10 };
    std::cout << "Larger of " << big_int << " and " << small_int << " is "
        << larger(big_int, small_int) << std::endl;

    const auto a_string{ "A" }, z_string{ "Z" };
    std::cout << "Larger of \"" << a_string << "\" and \"" << z_string << "\" is "
        << '"' << larger(a_string, z_string) << '"' << std::endl;
}

// Template for functions to return the larger of two values
template <typename T>
T larger(T a, T b)
{
    static int count{};
    count++;
    std::cout << " Type: " << type_name<decltype(a)>() << " Count: " << count << std::endl;
    return a > b ? a : b;
}


template <class T>
std::string type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
    (
#ifndef _MSC_VER
        abi::__cxa_demangle(typeid(TR).name(), nullptr,
            nullptr, nullptr),
#else
        nullptr,
#endif
        std::free
    );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}