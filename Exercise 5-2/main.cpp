/*Exercise 5-2. Write a program that uses a while loop to accumulate the sum of an 
arbitrary number of integers entered by the user. After every iteration, ask the user 
whether he or she is done entering numbers. The program should output the total of all 
the values and the overall average as a floating-point value.*/

#include <iostream>
#include <vector>

int main()
{
	int iter{};
	int total{};
	float average{};
	int cin;
	std::vector<int> MyVec;
	char c{};

	while (true)
	{
		
		std::cout << "Enter an integer:";
		std::cin >> cin;
		MyVec.push_back(cin);
		std::cout << std::endl;
		std::cout << " Would you like to continue? y or n: ";
		std::cin >> c;
		
		if (c == 'y')
		{
			continue;
		}
		else
		{
			int size = MyVec.size();
			for (int i = 0; i < size; i++)
			{
				total = MyVec.at(i) + total;
			}
			average = total / size;
			std::cout << "The total of the integers entered is: " << total << std::endl;
			std::cout << "The average of the integers is: " << average << std::endl;
			
			break;

		}
		break;
		
	}

	return 0;
}