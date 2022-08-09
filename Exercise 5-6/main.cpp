/*Exercise 5-6. Create a vector<> container with elements containing the integers from 
1 to an arbitrary upper bound entered by the user. Output the elements from the vector 
that contain values that are not multiples of 7 or 13. Output them 10 on a line, aligned 
in columns.*/

#include <vector>
#include <iostream>
#include <cmath>

int main()
{
	std::vector<unsigned int> Integers;
	unsigned int limit{};
	const unsigned int Multiple_7{ 7 };
	const unsigned int Multiple_13{ 13 };
	const unsigned int columnWidth{ 10 };
	

	std::cout << "How many integers would you like?" << std::endl;
	std::cin >> limit;
	

	for (unsigned int i = 0; i < limit; i++)
	{	
		if (i % Multiple_7 && i % Multiple_13)
		{
			Integers.push_back(i);
		}
	}
	
	for (unsigned int i = 0; i < Integers.size(); i++)
	{	
		if (i % columnWidth || i==0)
		{
			std::cout << Integers.at(i) << ", ";
		}
		else
		{
			std::cout << Integers.at(i) << ", " << std::endl;
		}
	}

	
	return 0;
}