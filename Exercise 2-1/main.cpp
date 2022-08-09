//exercise 2-1. Write a program that will compute the area of a circle. the program
//should prompt for the radius of the circle to be entered from the keyboard, calculate the
//area using the formula area = pi * radius* radius, and then display the result.

#include <iostream>

float CalcArea(float &radius)
{
	const float pi = 3.1459;
	return pi * radius * radius;
}


int main()
{
	float radius;
	
	std::cout << "Enter radius: " << "\n";
	scanf_s("%f", &radius);
	std::cout << "Area is: " << CalcArea(radius) << "\n";

	return 0;
}