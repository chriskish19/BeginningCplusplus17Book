/*Exercise 5-5. Write a program equivalent to that of Exercise 5-4, except for the 
following:
If before you used a for loop to count the characters, you now use while, or vice versa.
This time you should first reverse the characters in the array, before printing them 
out left to right (for the sake of the exercise you could still use a loop to print out the 
characters one by one).*/



#include <iostream>

int main()
{
	const int buffer{ 1000 };
	char c[buffer];
	char swap[buffer];
	int count{};


	std::cout << "Enter some characters to be counted and reversed: " << std::endl;
	std::cin.getline(c, buffer);

	for (; c[count] != '\0'; )
	{
		count++;
	}
	std::cout << "The number of characters is: " << count << std::endl;

	std::cout << "The characters in reverse: ";
	// printed characters in reverse
	for (int i = 0; i <= count; i++)
	{
		swap[i] = c[count - i];
		std::cout << swap[i];
	}

	return 0;
}