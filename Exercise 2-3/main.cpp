//exercise 2-3. Create a program that converts inches to feet and inches. In case
//you’re unfamiliar with imperial units : 1 foot equals 12 inches.an input of 77 inches,
//for instance, should thus produce an output of 6 feet and 5 inches.prompt the user
//to enter an integer value corresponding to the number of inches and then make the
//conversion and output the result.

#include <iostream>

void inchConvToFeet(int inches)
{
	int feet;
	feet = inches / 12;
	inches = inches % 12;

	std::cout << feet << "ft" << " " << inches << "in" << "\n";

}

int main()
{
	int inch;
	std::cout << " Enter number of inches to convert:";
	scanf_s("%d", &inch);
	std::cout << "\n";
	inchConvToFeet(inch);
	
	
	return 0;
}