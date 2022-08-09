/*exercise 6-6. revisit exercise 6-4 and replace any raw pointers with smart pointers
there as well.*/



#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

int main()
{

	size_t size{};
	double total{};

	std::cout << "Enter a size for the array: ";
	std::cin >> size;

	auto MyVec = std::make_unique<std::vector<double>>(size);

	for (size_t i = 0; i < size; i++)
	{
		//fill array
		(*MyVec)[i] = 1.0 / ((i + 1) * (i + 1));
	}

	for (auto i : *MyVec)
	{
		total += i;
	}

	total = sqrt(total * 6);

	std::cout << "Total:" << total << std::endl;





	return 0;
}