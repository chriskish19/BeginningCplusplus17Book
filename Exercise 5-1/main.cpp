/*Exercise 5-1. Write a program that outputs the squares of the odd integers from 1 up to 
a limit that is entered by the user.*/


#include <iostream>
#include <stdlib.h>

int main()
{
	int iter{};
	const int square{ 2 };
	const int even{ 2 };
	std::cout << " How many iterations to square odd integers starting with 1? ";
	std::cin >> iter;

	//no negatives
	iter = abs(iter);
	
	
	for (int i = 1; i < iter +1; i = i+even)
	{
		std::cout << (i ^ square) << std::endl;
	}

	return 0;
}