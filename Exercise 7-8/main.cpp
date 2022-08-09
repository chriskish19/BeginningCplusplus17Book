/*exercise 7-8. repeat exercise 7-7, only this time the user inputs the numbers one by
one, each time followed by an enter. the input should be gathered as a sequence of
distinct strings—for the sake of the exercise still not directly as integers—which are
then concatenated to a single string. the input is still terminated by a # character. also,
this time, you’re not allowed to use a string stream anymore to extract the numbers
from the resulting string*/



#include <vector>
#include <iostream>
#include <sstream>

#define debug false

int main()
{
	//Variables
#if debug	
	std::vector<std::string> string_box{"25","45","67","104","45"};
#endif	
#if !debug
	std::vector<std::string> string_box{};
#endif
	std::vector<int> int_box{};
	std::string sequence{};
	int total{};
#if !debug
	std::cout << "Enter a sequence of numbers press enter after each entry. Press # and enter to end input: ";
	
	//fill vector with numbers
	while (true) 
	{
		std::cin >> sequence;
		if (sequence.find('#') != std::string::npos) //when # is found this statement evaluates to true
			break;
		else
			string_box.push_back(sequence);
	}
#endif	
	for (auto i : string_box)
		int_box.push_back(std::stoi(i));

	for (auto i : int_box)
		total += i;

	std::cout << total << std::endl;





	
	
	return 0;
}