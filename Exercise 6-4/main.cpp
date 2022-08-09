/*exercise 6-4. repeat the calculation in exercise 6-3 but using a vector<> container
allocated in the free store. test the program with more than 100,000 elements. do you
notice anything interesting about the result?*/



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

	auto *MyVec = new std::vector<double>(size);

	for (size_t i = 0; i < size; i++)
	{
		//fill array
		(*MyVec)[i] = 1.0 / ((i + 1) * (i + 1));
	}

	for (auto i : *MyVec)
	{
		total +=i;
	}
	
	total = sqrt(total * 6);

	std::cout << "Total:" << total << std::endl;




	delete MyVec;
	MyVec = nullptr;
	return 0;
}