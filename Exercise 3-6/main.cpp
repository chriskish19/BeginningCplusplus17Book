/* exercise 3-6. We’ll conclude with one more exercise for puzzle fans (and exclusively
so). Write a program that prompts for two integer values to be entered and store them
in integer variables, a and b, say. swap the values of a and b without using a third
variable. output the values of a and b.
hint: this is a particularly tough nut to crack. to solve this puzzle, you exclusively need
one single compound assignment operator. */


#include <iostream>



int main()
{
	int a, b;

	puts("Enter an integer a: ");
	scanf_s("%d", &a);
	puts("\n");
	puts("Enter another integer b: ");
	scanf_s("%d", &b);
	puts("\n");

	// memory of a and b stored in a
	a = a ^ b;

	// b = a now
	b = a ^ b;

	// a = b now
	a = b ^ a;

	// Print out a and b
	std::cout << "a: " << a << " b: " << b;

	return 0;
}