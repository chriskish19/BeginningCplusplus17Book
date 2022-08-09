//exercise 2-2. using your solution for exercise 2-1, improve the code so that the user
//can control the precision of the output by entering the number of digits required.to
//really show off how accurate floating - point numbers can be, you can perhaps switch
//to double - precision floating - point arithmetic as well.you’ll need a more precise
//approximation of π. 3.141592653589793238 will do fine

#include <iostream>
#include <iomanip>

double CalcArea(double radius)
{
	const double pi = 3.141592653589793238;
	return pi * radius * radius;
}


int main()
{
	double radius;
	int sigfigDigits;

	std::cout << "Enter radius: ";
	scanf_s("%lf", &radius);
	std::cout << "\n";
	std::cout << "Enter desired Number of significant digits:";
	scanf_s("%d", &sigfigDigits);
	std::cout << "\n";
	std::cout << std::setprecision(sigfigDigits);
	std::cout << "Area is: " << CalcArea(radius);

	return 0;
}