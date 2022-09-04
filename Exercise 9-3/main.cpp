/*exercise 9-3. Write a function template plus() that takes two arguments of potentially
different types and returns a value equal to the sum of both arguments. next, make
sure that plus() can be used as well to add the values pointed to by two given
pointers.*/

#include<string>
#include<iostream>



template<typename T,typename Ty>
T plus(T one, Ty two);


int main()
{
	std::string added{};
	added = plus(static_cast<std::string>("hello"), static_cast < std::string>( "world"));
	std::cout << added << std::endl;

	const char added_{};
	added_ = plus<const char>("hello", "world");
	std::cout << added_ << std::endl;
	
	return 0;
}

template<typename T, typename Ty>
T plus(T one, Ty two)
{
	return one + two;
}

