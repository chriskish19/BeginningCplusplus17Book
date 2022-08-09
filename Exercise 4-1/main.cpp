/*exercise 4-1. Write a program that prompts for two integers to be entered and then uses an
if-else statement to output a message that states whether the integers are the same.*/

#include <iostream>

int main()
{
	int a, b;
	std::cout << "Enter an integer" << std::endl;
	std::cin >> a;

	std::cout << "Enter a second integer" << std::endl;
	std::cin >> b;

	if (a == b)
	{
		std::cout << "The integers are equal" << std::endl;
	}

}