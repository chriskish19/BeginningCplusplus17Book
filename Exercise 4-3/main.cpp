/*exercise 4-3. Create a program that prompts for input of a number (nonintegral numbers
are allowed) between 1 and 100. Use a nested if, first to verify that the number is within
this range and then, if it is, to determine whether it is greater than, less than, or equal to
50. the program should output information about what was found.*/

#include <iostream>

int main()
{
	float number;

	std::cout << "Enter a number between 1 and 100" << std::endl;
	std::cin >> number;

	if (number < 100 && number > 1)
	{
		if (number > 50)
		{
			std::cout << "Number is Greater than 50" << std::endl;
		}
		else if (number < 50)
		{
			std::cout << "Number is less than 50" << std::endl;
		}
		else
		{
			std::cout << "Number is equal to 50" << std::endl;
		}
	}
	else
	{
		std::cout << "Number is outside of 1 and 100" << std::endl;
	}
}