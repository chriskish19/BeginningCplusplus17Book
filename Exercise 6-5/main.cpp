/*exercise 6-5. revisit exercise 6-3, but this time use a smart pointer to store the array,
that is, if you haven’t already done so from the start. a good student should’ve known
not to use the low-level memory allocation primitives....*/

#include <iostream>
#include <cmath>
#include <memory>
#include <vector>

int main()
{
	size_t size{};
	double total{};


	std::cout << "Enter a size for the array: ";
	std::cin >> size;


	auto MyBox{ std::make_unique<double[]>(size) };

	for (size_t i = 0; i < size; i++)
	{
		//fill array
		MyBox[i] = 1 / pow((i + 1), 2);

		//sum elements
		total += MyBox[i];
	}

	total = sqrt(total * 6);

	std::cout << "Total:" << total << std::endl;





	
	return 0;
}