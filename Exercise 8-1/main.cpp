/*exercise 8-1. Write a function, validate_input(), that accepts two integer arguments
that represent the upper and lower limits for an integer that is to be entered. it should
accept a third argument that is a string describing the input, with the string being used
in the prompt for input to be entered. the function should prompt for input of the value
within the range specified by the first two arguments and include the string identifying the
type of value to be entered. the function should check the input and continue to prompt
for input until the value entered by the user is valid. use the validate_input() function
in a program that obtains a user’s date of birth and outputs it in the form of this example:
November 21, 2012

the program should be implemented so that separate functions, month(), year(),
and day(), manage the input of the corresponding numerical values. Don’t forget leap
years—february 29, 2017, is not allowed!
*/


#include <iostream>
#include <string>
#include <string_view>

//function decls
int month();
int year();
int day();
int validate_input(int lower, int upper, std::string_view description);


int main()
{
	int int_month{};
	int int_day{};
	int int_year{};
	std::string months[]{"blank","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	
	int_year = year();
	int_month = month();
	int_day = day();

	std::cout << "You were born on:" << months[int_month] << " " << int_day << ", " << int_year << std::endl;
}

int year()
{
	return validate_input(1900, 2021, "Enter the year you were born");
}

int month()
{
	return validate_input(1, 12, "Enter the month you were born");
}

int day()
{
	return validate_input(1, 31, "Enter the day you were born");
}

int validate_input(int lower, int upper, std::string_view description)
{
	int date{};
	bool flag{true};
	while (flag)
	{
		std::cout << description << " between " << lower << " and " << upper << std::endl;
		std::cin >> date;
		if (date<upper && date >lower)
		{
			flag = false;
			return date;
		}	
		else
		{
			flag = true;
			std::cout << "invalid entry, please reenter!" << std::endl;
		}
			

	}
}