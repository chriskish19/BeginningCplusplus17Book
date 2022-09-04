/*exercise 8-9. Modify the solution of exercise 8-8 such that it counts the number of
times the call power(1.5,1000) performs a multiplication. Do so by replacing each
multiplication with a helper function mult() that takes two arguments, prints a
message of how many multiplications have been performed thus far, and then simply
returns the product of both arguments. use at least one static variable*/

#include <iostream>
double power(int base, int exp);
double multi(int base, int exp, double(*func)(int, int));

int main()
{
	std::cout << power(2, 10) << std::endl;
}

double power(int base, int exp)
{
	if (exp == 0)      return 1.0;
	else if (exp > 0)  return multi(base,exp,power);
	else /* n < 0 */   return 1.0 / power(base, -exp);

}

double multi(int base,int exp,double(*func)(int,int) )
{
	static int count{};
	count++;
	std::cout << "This many multiplications thus far: " << count << std::endl;
	return base * func(base,exp-1);

}