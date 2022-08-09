//exercise 3-2. Write a program to calculate how many square boxes can be contained
//in a single layer on a rectangular shelf, with no overhang.the dimensions of the shelf
//in feetand the dimension of a side of the box in inches are read from the keyboard.
//use variables of type double for the lengthand depth of the shelfand type int for the
//length of the side of a box.defineand initialize an integer constant to convert from feet
//to inches(1 foot equals 12 inches).Calculate the number of boxes that the shelf can
//hold in a single layer of type longand output the result.

#include <iostream>



int main()
{
	double shelfWidth; // in feet
	double shelfLength; //in feet
	int boxSide; // in inches
	const int feetToIn = 12;
	long NumberOfBoxes;


	std::cout << "Enter the width of the shelf in feet:";
	scanf_s("%lf", &shelfWidth);
	std::cout << "\n";

	std::cout << "Enter the length of the shelf in feet:";
	scanf_s("%lf", &shelfLength);
	std::cout << "\n";

	std::cout << "Enter a side of the box in inches:";
	scanf_s("%d", &boxSide);
	std::cout << "\n";

	if (boxSide > shelfLength)
	{
		std::cout << "box is bigger than the shelf" << "\n";
		std::cout << "setting box equal to the shelf";
		std::cout << "\n";
		boxSide = static_cast<int>(shelfLength*feetToIn);
	}

	shelfLength = shelfLength * feetToIn; //converting to inches
	
	NumberOfBoxes = static_cast<int>(shelfLength) / boxSide;

	std::cout << "The number of boxes that will fit on the shelf is:" << NumberOfBoxes;

}