/*exercise 4-4. it’s time to make good on a promise. somewhere in this chapter we
said we’d look for someone “who is older than 21, younger than 35, is female, has
a bachelor’s or master’s degree, is unmarried, and speaks hindi or Urdu.” Write a
program that prompts the user for these qualifications and then outputs whether they
qualify for these very specific requirements. to this end, you should define an integer
variable age, a character variable gender (to hold 'm' for male and 'f' for female),
a variable degree of an enumeration type AcademicDegree (possible values: none,
associate, bachelor, professional, master, doctor), and three Boolean variables:
married, speaksHindi, and speaksUrdu. emulate a trivial online job interview, and
query your applicant for input on all these variables. people who enter invalid values do
not qualify, of course, and should be ruled out as early as possible (that is, immediately
after entering any invalid value; ruling them out precognitively prior to entering invalid
values, sadly, is not possible yet in standard C++).*/

#include <iostream>

int main()
{
	int age;
	char gender;
	int edu;
	enum class education{none,associate,bachelor,professional,master,doctor};
	bool married, speaksHindi, speaksUrdu;
	education degree;
	char flag;



	std::cout << "Welcome to the Job interview" << std::endl;

	std::cout << "How old are you? ";
	std::cin >> age;
	std::cout << std::endl;

	if (!(age > 21 && age < 35))
	{
		std::cout << "Sorry we are looking for someone between 21 and 35 years of age" << std::endl;
		return 0;
	}

	std::cout << "Are you male or female, type f for female and m for male: ";
	std::cin >> gender;
	std::cout << std::endl;

	if (gender == 'm')
	{
		std::cout << "Sorry we are looking for a female" << std::endl;
		return 0;
	}

	std::cout << "Whats your education? Choose from the following and type the number it corresponds to: none = 1 , associate = 2 , bachelor = 3 , professional = 4 , master = 5, doctor = 6 ";
	std::cin >> edu;
	
	switch (edu)
	{
	case 1:
		degree = education::none;
		break;
	case 2:
		degree = education::associate;
		break;
	case 3:
		degree = education::bachelor;
		break;
	case 4:
		degree = education::professional;
		break;
	case 5:
		degree = education::master;
		break;
	case 6:
		degree = education::doctor;
		break;
	default:
		std::cout << "Error Retry Entry" << std::endl;
	}

	if (!(degree == education::bachelor || degree == education::master))
	{
		std::cout << "Sorry we are looking for someone more qualified" << std::endl;
		return 0;
	}
	
	std::cout << "Are you married? y or n" << std::endl;
	std::cin >> flag;

	if (flag == 'y')
	{
		married = true;
		std::cout << "Sorry we are looking for someone single" << std::endl;
		return 0;
	}
	else
	{
		married = false;
		flag = NULL;
	}

	std::cout << "Do you speak Hindi or Urdu? y or n" << std::endl;
	std::cin >> flag;

	if (flag == 'y')
	{
		std::cout << "Success you are qulified for the job" << std::endl;
	}
	else
	{
		std::cout << "Sorry we are looking for someone who speaks Hindi or Urdu" << std::endl;
		return 0;
	}






	
	return 0;
}