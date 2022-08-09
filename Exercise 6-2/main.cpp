/*Exercise 6-2. Revisit the previous exercise, but instead of accessing the array values 
using the loop counter, this time you should employ pointer increments (using the 
++ operator) to traverse the array when outputting it for the first time. After that, use 
pointer decrements (using --) to traverse the array again in the reverse direction.*/


#include <iostream>


int main()
{
	unsigned int oddNum[50]{};
	unsigned int Size{ std::size(oddNum) };
	unsigned int* p_oddNum{ oddNum };

	for (int i = 0; i < Size; i++)
	{
		oddNum[i] = i * 2 + 1;

		if (i % 10 || i == 0)
		{
			std::cout << *(++p_oddNum-1) << ", ";
		}
		else
		{
			std::cout << *(++p_oddNum-1) << ", " << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;

	//Reverse order
	for (int i = Size - 1; i >= 0; --i)
	{
		if (i % 10 || i == 0)
		{
			std::cout << *(--p_oddNum) << ", ";
		}
		else
		{
			std::cout << *(--p_oddNum) << ", " << std::endl;
		}
	}


	return 0;
}