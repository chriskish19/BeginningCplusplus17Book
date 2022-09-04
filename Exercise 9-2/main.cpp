/*exercise 9-2. alter the last lines of Ex9_01’s main() function as follows:
const auto a_string = "A", z_string = "Z";
std::cout << "Larger of " << a_string << " and " << z_string
<< " is " << larger(a_string, z_string) << std::endl;
if you now run the program, you may very well get the following output (if not, try
rearranging the order in which a_string and z_string are declared):
Larger of 1.5 and 2.5 is 2.5
Larger of 3.5 and 4.5 is 4.5
Larger of 17011983 and 10 is 17011983
Larger of A and Z is A

What’s that? "A" is larger than "Z"? Can you explain exactly what went wrong? Can
you fix it?
hint: to compare two character arrays, you could perhaps first convert them to another
string representation.
*/

// Using a function template
#include <iostream>
#include <string>

template<typename T> T larger(T a, T b);    // Function template prototype

template <typename T>
T larger_(T a, T b);

int main()
{
    std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
    std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;

    int big_int{ 17011983 }, small_int{ 10 };
    std::cout << "Larger of " << big_int << " and " << small_int << " is "
        << larger(big_int, small_int) << std::endl;

    const auto a_string{ "A" }, z_string{ "Z" };
    std::cout << "Larger of \"" << a_string << "\" and \"" << z_string << "\" is "
        << '"' << larger_(a_string, z_string) << '"' << std::endl;
}

// Template for functions to return the larger of two values
template <typename T>
T larger(T a, T b)
{
    return a > b ? a : b;
}

template <typename T>
T larger_(T a, T b)
{
    return *a > *b ? a : b;
}