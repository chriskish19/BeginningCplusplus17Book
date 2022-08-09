/*Exercise 4-6. Write a program that determines, using only the conditional operator, if an 
integer that is entered has a value that is 20 or less, is greater than 20 but not greater 
than 30, is greater than 30 but not exceeding 100, or is greater than 100.*/

#include <iostream>

int main()
{
	int a;
	bool numberTest;
	std::cout << "Enter an integer:" << std::endl;
	std::cin >> a;

	numberTest = a < 20 ? true : false;
	std::cout << "Is the integer less than 20: " << std::boolalpha<< numberTest << std::endl;

	numberTest = (a >20 && a<30) ? true: false;
	std::cout << "Is the integer greater than 20 and but not greater than 30: " << std::boolalpha << numberTest << std::endl;
	
	numberTest = (a > 30 && a < 100) ? true : false;
	std::cout << "Is the integer greater than 30 and but not greater than 100: " << std::boolalpha << numberTest << std::endl;
	
	numberTest = a > 100 ? true : false;
	std::cout << "Is the integer greater than 100: " << std::boolalpha << numberTest << std::endl;




	return 0;
}