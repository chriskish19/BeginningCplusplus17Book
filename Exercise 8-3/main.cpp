/*exercise 8-3. Write a program that accepts from two to four command-line arguments.
if it is called with less than two or more than four arguments, output a message telling
the user what they should do and then exit. if the number of arguments is correct,
output them, each on a separate line.*/

//visual studio isnt setup for this its command line is used from the properties and with macros...
#include <iostream>


int main(int argc, char* argv[])
{
	for (int i{}; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}
}