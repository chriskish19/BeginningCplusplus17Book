/*exercise 9-3. Write a function template plus() that takes two arguments of potentially
different types and returns a value equal to the sum of both arguments. next, make
sure that plus() can be used as well to add the values pointed to by two given
pointers.*/

#include<string>
#include<iostream>



template<typename T,typename Ty>
T plus(T one, Ty two);

const char* plus(const char* one, const char* two);
int main()
{
	std::string added{};
	added = plus(static_cast<std::string>("hello"), static_cast < std::string>( "world"));
	std::cout << added << std::endl;
	int i{};

	const char* added_ch_p{};
	added_ch_p = plus("hello", "world");
	while (added_ch_p[i] != '\0')
	{
		
		std::cout << added_ch_p[i];
		i++;
	}
	
	//delete[]added_ch_p;	 // Release memory
	added_ch_p = nullptr; // Reset the pointer
	return 0;
}

template<typename T, typename Ty>
T plus(T one, Ty two)
{
	return one + two;
}

const char* plus(const char* one, const char* two)
{
	std::string one_s{ one };
	std::string two_s{ two };

	static std::string added_s{ one_s + two_s };
	const char** added_ch_p = new const char*[added_s.length()];

	*added_ch_p = added_s.c_str();
	return *added_ch_p;
}