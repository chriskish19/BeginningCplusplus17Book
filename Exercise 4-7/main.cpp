/*Exercise 4-7. Implement a program that prompts for input of a letter. Use a library 
function to determine whether the letter is a vowel and whether it is lowercase or not, 
and output the result. Finally, output the lowercase letter together with its character 
code as a binary value.*/

#include <iostream>
#include <cctype>
#include <bitset>

int main()
{
	char c;
	bool LowerCase;
	std::cout << "Enter a letter" << std::endl;
	std::cin >> c;

	switch (c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		std::cout << "You entered a vowel." << std::endl;
		break;
	}
	LowerCase=islower(c);

	if (LowerCase)
	{
		std::cout << "The letter you entered is a lowercase letter" << std::endl;
	}
	else
	{
		std::cout << "The letter you entered is not a lowercase letter" << std::endl;
		c = tolower(c);
	}
	
	std::cout << "The letter is: " << c << std::endl;
	std::cout << "The letter in binary is: " << std::bitset<8>(c) << std::endl;




	
	return 0;
}