/*exercise 7-7. Create a program that reads an arbitrarily long sequence of integer
numbers typed by the user into a single string object. the numbers of this sequence
are to be separated by spaces and terminated by a # character. in other words, the user
does not have to press enter between two consecutive numbers. next, use a string
stream to extract all numbers from the string one by one, add these numbers together,
and output their sum*/

#include <string>
#include <iostream>
#include <sstream>
#include <array>

#define debug true

#define MAX_ARRAY 50

int main()
{
#if debug	
	std::string sequence{"25 67 56 78 104 105"};
#endif
	std::stringstream ss;
	std::array<int, MAX_ARRAY> box{};
	int total{};
#if !debug
	std::string sequence{};
	std::cout << "Enter a sequence of numbers separated by spaces ";
	std::getline(std::cin, sequence);
#endif
	
	ss.str(sequence);

	int i{};
	while (ss)
	{
		ss >> std::skipws >> box[i];
		i++;
	}

	for (auto i : box)
		total += i;
	
	std::cout << total << std::endl;

}