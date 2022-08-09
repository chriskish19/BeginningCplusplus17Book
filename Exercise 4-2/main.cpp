/*exercise 4-2. Write another program that prompts for two integers to be entered.
this time, any negative number or zero is to be rejected. next, check whether one
of the (strictly positive) numbers is an exact multiple of the other. For example, 63 is
a multiple of 1, 3, 7, 9, 21, or 63. note that the user should be allowed to enter the
numbers in any order. that is, it does not matter whether the user enters the largest
number first or the smaller one; both should work correctly!*/

#include <iostream>
#include <stdlib.h>

int main()
{
	int a, b;
	
	while (true)
	{
		std::cout << "Enter an integer:" << std::endl;
		std::cin >> a;

		std::cout << "Enter a second integer:" << std::endl;
		std::cin >> b;

		a = abs(a);
		b = abs(b);
		if (a == 0 || b==0)
		{
			std::cout << "The integers cannot be zero" << std::endl;
			std::cout << "Reenter the integers" << std::endl;
			continue;
		}

		if (a % b == 0 || b % a == 0)
		{
			std::cout << "The numbers are multiples of one another" << std::endl;
		}

		break;
	}
	




}