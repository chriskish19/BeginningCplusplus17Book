 /*exercise 7-1. Write a program that reads and stores the first names of any number of
students, along with their grades. Calculate and output the average grade and output
the names and grades of all the students in a table with the name and grade for three
students on each line.*/


#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::vector<std::string> nameVec;
	std::string name;
	std::vector<unsigned int> gradeVec;
	unsigned int grade;
	std::string more;
	

	while (true)
	{
		std::cout << "Enter a students name: ";
		std::cin >> name;
		std::cout << std::endl;
		
		nameVec.push_back(name);

		std::cout << "Enter students grade: ";
		std::cin >> grade;
		std::cout << std::endl;

		gradeVec.push_back(grade);

		std::cout << "More to Enter? y or n? ";
		std::cin >> more;

		if (more.compare("y") == 0)
		{
			continue;
		}
		else
		{
			break;
		}
	}


	unsigned int space{ 10 };
	unsigned int dash{ 65 };

	std::cout.fill('-');
	std::cout.width(dash);
	std::cout << "-";
	std::cout << std::endl;



	unsigned int column_count{ 3 };
	unsigned int column_reset{ 0 };

	bool flag_nameVec{ true };
	unsigned int i_nameVec{};
	unsigned int count_nameVec{};

	bool flag_gradeVec{ false };
	unsigned int i_gradeVec{};
	unsigned int count_gradeVec{};

	while (i_nameVec < nameVec.size() && i_gradeVec < gradeVec.size())
	{

		while (flag_nameVec && (i_nameVec < nameVec.size()))
		{
			if (count_nameVec == column_count)
			{
				flag_gradeVec = true;
				flag_nameVec = false;
				count_nameVec = column_reset;
				std::cout << std::endl;
				break;
			}
			if (count_nameVec == column_reset)
			{
				std::cout << "Student Name: ";
				std::cout.fill(' ');
				std::cout.width(space);
				std::cout << " ";
			}
			std::cout << nameVec.at(i_nameVec);
			std::cout.fill(' ');
			std::cout.width(space);
			std::cout << " ";
			count_nameVec++;
			i_nameVec++;
			
		}
	
		while (flag_gradeVec && (i_gradeVec < gradeVec.size()))
		{
			if (count_gradeVec == column_count)
			{
				flag_nameVec = true;
				flag_gradeVec = false;
				count_gradeVec = column_reset;
				std::cout << std::endl;
				break;
			}
			if (count_gradeVec == column_reset)
			{
				std::cout << "Student Grade: ";
				std::cout.fill(' ');
				std::cout.width(space);
				std::cout << " ";
			}
			std::cout << gradeVec.at(i_gradeVec);
			std::cout.fill(' ');
			std::cout.width(space);
			std::cout << " ";
			count_gradeVec++;
			i_gradeVec++;
		}





	}
	


	
	
	




	



	return 0;
}