/*exercise 6-3. Write a program that reads an array size from the keyboard and
dynamically allocates an array of that size to hold floating-point values. Using pointer
notation, initialize all the elements of the array so that the value of the element at
index position n is 1 / (n + 1)2 . Calculate the sum of the elements using array notation,
multiply the sum by 6, and output the square root of that result. */

#include <iostream>
#include <cmath>

int main()
{
	size_t size{};
	double total{};

	std::cout << "Enter a size for the array: ";
	std::cin >> size;

	double *MyBox = new double[size]; //remeber to delete and nullptr

	for (size_t i = 0; i < size; i++)
	{
		//fill array
		*(MyBox + i) = 1 / pow((i + 1),2);

		//sum elements
		total += *(MyBox + i);
	}

	total = sqrt(total * 6);

	std::cout << "Total:" << total << std::endl;

	



	delete[]MyBox;
	MyBox=nullptr ;
	return 0;
}