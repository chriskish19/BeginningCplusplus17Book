/*exercise 9-1. in C++17, the standard library algorithm header gained the handy
std::clamp() function template. the expression clamp(a,b,c) is used to clamp
the value a to a given closed interval [b,c]. that is, if a is less than b, the result of the
expression will be b; and if a is greater than c, the result will be c; otherwise, if a lies
within the interval [b,c], clamp() simply returns a. Write your own my_clamp() function
template and try it with a little test program.*/

#include <iostream>
#include <algorithm>


template<typename T>
constexpr const T& Clamp_(const T& val_, const T& min_, const T& max_);



int main()
{
	int num{ 100 };
	int low{ 10 };
	int high{ 110 };
	
	
	std::cout << Clamp_(num, low, high);
	
	
	
	
	return 0;
}

template<typename T>
constexpr const T& Clamp_(const T& val_, const T& min_, const T& max_)
{
	if (val_ > max_)
		return max_;
	if (val_ < min_)
		return min_;
	if (val_ > min_ && val_ < max_)
		return val_;
}