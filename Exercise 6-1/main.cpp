/*Exercise 6-1. Write a program that declares and initializes an array with the first 50 odd 
(as in not even) numbers. Output the numbers from the array ten to a line using pointer 
notation and then output them in reverse order, also using pointer notation.*/
#include <iostream>


int main()
{
	unsigned int oddNum[50]{};
	unsigned int Size{ std::size(oddNum) };

	for (int i = 0; i < Size; i++)
	{
		oddNum[i] = i * 2 + 1;

		if (i % 10 || i==0)
		{
			std::cout <<  * (oddNum + i)<<", ";
		}
		else
		{
			std::cout << * (oddNum + i) << ", " << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;

	//Reverse order
	for (int i = Size-1; i >= 0; --i)
	{
		if (i % 10 || i == 0)
		{
			std::cout << *(oddNum + i) << ", ";
		}
		else
		{
			std::cout << *(oddNum + i) << ", " << std::endl;
		}
	}


	return 0;
}