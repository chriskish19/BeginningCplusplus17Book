/*Exercise 5-7. Write a program that will read and store an arbitrary sequence of records 
relating to products. Each record includes three items of data—an integer product 
number, a quantity, and a unit price. For product number 1001, the quantity is 25, 
and the unit price is $9.95. Because you do not know yet how to create compound 
types, simply use three different array-like sequences to represent these records. 
The program should output each product on a separate line and include the total cost. 
The last line should output the total cost for all products. Columns should align, so the 
output should be something like this:
Product Quantity Unit Price Cost
1001 25 $9.95 $248.75
1003 10 $15.50 $155.00
$403.75*/

#include <iostream>


int main()
{
	const unsigned int buffer{ 50 };
	unsigned int productNumber[buffer]{};
	unsigned int quantity[buffer]{};
	float unitPrice[buffer]{};
	float cost[buffer]{};
	char c{};
	unsigned int count{};
	float totalCost{};
	

	for (int i = 0; i < buffer; i++)
	{
		std::cout << "Enter product number: ";
		std::cin >> productNumber[i];
		std::cout << std::endl;

		std::cout << "Enter quantity: ";
		std::cin >> quantity[i];
		std::cout << std::endl;

		std::cout << "Enter unit price: ";
		std::cin >> unitPrice[i];
		std::cout << std::endl;

		std::cout << "More values to enter? y or n? ";
		std::cin >> c;
		std::cout << std::endl;

		if (c == 'y')
		{
			continue;
		}
		else
		{
			count = i+1;
		}
		break;
	}
	
	unsigned int lines{ 66 };
	unsigned int spaces_label{ 10 };
	unsigned int spaces_products{ 17 };
	unsigned int spaces_total{ 56 };

	std::cout.fill('-');
	std::cout.width(lines);
	std::cout << '-' << std::endl;
	
	std::cout << "Product"; 
	std::cout.fill(' ');
	std::cout.width(spaces_label);
	std::cout << ' ';
	
	std::cout << "Quantity";
	std::cout.fill(' ');
	std::cout.width(spaces_label);
	std::cout << ' ';
	
	std::cout << "Unit Price";
	std::cout.fill(' ');
	std::cout.width(spaces_label);
	std::cout << ' ';
	
	std::cout << "Cost";
	std::cout.fill(' ');
	std::cout.width(spaces_label);
	std::cout << ' ' << std::endl;
	
	std::cout.fill('-');
	std::cout.width(lines);
	std::cout << '-' << std::endl;

	for (int i = 0; i < count; i++)
	{
		cost[i] = quantity[i] * unitPrice[i];
		totalCost += cost[i];
		
		std::cout << productNumber[i];
		std::cout.fill(' ');
		std::cout.width(spaces_products);
		std::cout << ' ' ;

		std::cout << quantity[i];
		std::cout.fill(' ');
		std::cout.width(spaces_products);
		std::cout << ' ';

		std::cout << '$'<< unitPrice[i];
		std::cout.fill(' ');
		std::cout.width(spaces_products);
		std::cout << ' ';

		std::cout << '$'<< cost[i];
		std::cout.fill(' ');
		std::cout.width(spaces_products);
		std::cout << ' ';
		std::cout << std::endl; 
	}
	
	std::cout.fill(' ');
	std::cout.width(spaces_total);
	std::cout << '$' << totalCost;
}


