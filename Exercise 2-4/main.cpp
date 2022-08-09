//exercise 2-4. For your birthday you’ve been given a long tape measure and an
//instrument that measures angles(the angle between the horizontaland a line to the top
//of a tree, for instance).If you know the distance, d, you are from a tree, and the height,
//h, of your eye when peering into your angle - measuring device, you can calculate the
//height of the tree with the formula h + d * tan(angle).Create a program to read h in
//inches, d in feetand inches, and angle in degrees from the keyboard, and output the
//height of the tree in feet

#include <iostream>
#include <math.h>


float ObjectHeightCalc(int &eyeHeight,int &distanceFeet,int &distanceInches,float &angle)
{
	const float pi = 3.1459;
	float Distance = distanceFeet*12 + distanceInches; //convert to inches
	angle = angle * (pi / 180); //convert to radians
	return (eyeHeight + Distance * tan(angle))/12; //convert to feet
}

int main()
{
	int eyeHeight, distanceFeet, distanceInches;
	float angle;
	
	std::cout << "Enter your height in inches: ";
	scanf_s("%d", &eyeHeight);
	std::cout << "\n";
	std::cout << "Enter the distance in feet and inches:" << "\n";
	std::cout << "Feet: ";
	scanf_s("%d", &distanceFeet);
	std::cout << "\n";
	std::cout << "Inches:";
	scanf_s("%d", &distanceInches);
	std::cout << "\n";
	std::cout << "Enter the Angle in degrees:";
	scanf_s("%f", &angle);
	std::cout << "\n";
	std::cout << "The height of the object is: "<< ObjectHeightCalc(eyeHeight, distanceFeet, distanceInches, angle) << "ft";

	return 0;
}