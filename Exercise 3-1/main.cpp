//exercise 3-1. Create a program that prompts for input of an integer and store it
//as an int.invert all the bits in the valueand store the result.output the original
//value, the value with the bits inverted, and the inverted value plus 1, each in
//hexadecimal representationand on one line.on the next line, output the same
//numbers in decimal representation.these two lines should be formatted such that
//they look like a table, where the values in the same column are right aligned in
//a suitable field width.all hexadecimal values should have leading zeros so eight
//hexadecimal digits always appear.
//note: Flipping all bitsand adding one—ring any bells ? Can you perhaps already deduce
//what the output will be before you run the program ?

#include <iostream>
#include <bitset>

int main()
{
	int number;
	int invertedNumber;
	std::cout << "Enter an integer: ";
	scanf_s("%d", &number);
	invertedNumber = ~number;
	

	std::cout << "Hex: " << std::hex << number << "," << invertedNumber << "," << invertedNumber++ <<"\n";
	std::cout << "Decimal: " << std::dec << number << "," << invertedNumber << "," << invertedNumber++;
	return 0;
}