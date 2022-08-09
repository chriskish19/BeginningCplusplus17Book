/*Exercise 5-3. Create a program that uses a do-while loop to count the number of 
nonwhitespace characters entered on a line. The count should end when the first 
# character is found.*/

#include <iostream>
#include <string>

int main()
{
	const int buffer{ 50 };
	char c[buffer];
	memset(c, '\0', buffer);


	int charCount{};
	int count{};
	
	
	std::cout << "Enter some characters and they will be counted, Max 50" << std::endl;
	std::cin.getline(c,buffer);
	
	do 
	{
		if (c[count] != ' ')
		{
			charCount++;
		}
		count++;
	} while (c[count] != '#' && c[count] != '\0');

	std::cout << "The total character count is: " << charCount << std::endl;
	
	return 0;
}