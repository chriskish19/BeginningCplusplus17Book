/*Exercise 4-8. Create a program that prompts the user to enter an amount of money 
between $0 and $10 (decimal places allowed). Any other value is to be rejected politely. 
Determine how many quarters (25c), dimes (10c), nickels (5c), and pennies (1c) are 
needed to make up that amount. For our non-American readers, one dollar ($) equals 
100 cents (c). Output this information to the screen and ensure that the output makes 
grammatical sense (for example, if you need only one dime, then the output should be 
“1 dime” and not “1 dimes”).*/

#include <iostream>
#include <math.h>

int MoneyCalc(double money, double CoinValue, double& cents)
{
	float NumberOfCoins{};

	NumberOfCoins = money / CoinValue;
	cents = modf(NumberOfCoins, &NumberOfCoins);
	cents = cents * CoinValue;
	return static_cast<int>(NumberOfCoins);
}

int MoneyCalc(double CoinValue, double& cents)
{
	float NumberOfCoins{};

	NumberOfCoins = cents / CoinValue;
	cents = modf(NumberOfCoins, &NumberOfCoins);
	cents = cents * CoinValue;
	return static_cast<int>(NumberOfCoins);
}


int main()
{
	const float dimeValue = 0.10;
	const float pennieValue = 0.01;
	const float quarterValue = 0.25;
	const float nickelValue = 0.05;

	double money{}, cents{};

	int int_dimesCount{}, int_quartersCount{}, int_nickelsCount{}, int_penniesCount{}, int_dollarsCount{};

	while (true)
	{
		std::cout << "Enter an amount of money no greater than $10" << std::endl;
		std::cin >> money;

		if (money > 10)
		{
			std::cout << "Try a number that is less" << std::endl;
			continue;
		}
		break;
	}
	
	
	// quarters calculation
	int_quartersCount = MoneyCalc(money, quarterValue, cents);;
	
	// dimes calculation
	int_dimesCount = MoneyCalc(dimeValue, cents);
	
	// nickels calculation
	int_nickelsCount = MoneyCalc(nickelValue, cents);

	// pennies calculation
	int_penniesCount = MoneyCalc(pennieValue, cents);

	std::cout << "Your money in: " << std::endl;
	std::cout << "Quarters: " << int_quartersCount << std::endl;
	std::cout << "Dimes: " << int_dimesCount << std::endl;
	std::cout << "Nickels: " << int_nickelsCount << std::endl;
	std::cout << "Pennies: " << int_penniesCount << std::endl;
	

	return 0;
}