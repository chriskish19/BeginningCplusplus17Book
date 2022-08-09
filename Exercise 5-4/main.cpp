/*Exercise 5-4. Use std::cin.getline(…) to obtain a C-style string of maximum 1,000 
characters from the user. Count the number of characters the user entered using an 
appropriate loop. Next, write a second loop that prints out all characters, one by one, 
but in a reverse order.*/

#include <iostream>

int main()
{
	const int buffer{1000};
	char c[buffer];
	int count{};


	std::cout << "Enter some characters to be counted and reversed: " << std::endl;
	std::cin.getline(c, buffer);

	while (c[count]!='\0')
	{
		count++;
	}
	std::cout << "The number of characters is: " << count << std::endl;
	
	// printed characters in reverse
	for (int i = 0; i <= count; i++)
	{
		std::cout << c[count - i] << std::endl;
	}

	return 0; 
}