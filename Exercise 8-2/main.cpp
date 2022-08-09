/*exercise 8-2. Write a function that reads a string or array of characters as input and
reverses it. Justify your choice of parameter type? provide a main() function to test
your function that prompts for a string of characters, reverses them, and outputs the
reversed string.*/

#include <string>
#include <iostream>


std::string reverse_string(std::string name);

int main()
{
	
	std::cout<< reverse_string("ding dong");
	return 0;
}

std::string reverse_string(std::string name)
{
	std::string reversed{name};
	size_t length{ name.length() - 1 };

	for (int i = 0; i < name.length(); i++)
	{
		reversed[i] = name[length - i];
	}
	return reversed;
}