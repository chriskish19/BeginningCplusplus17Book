/*exercise 8-5. Define a function that checks whether a given number is prime. Your
primal check does not have to be efficient; any algorithm you can think of will do. in
case you have forgotten, a prime number is a natural number strictly greater than
1 and with no positive divisors other than 1 and itself. Write another function that
generates a vector<> with all natural numbers less or equal to a first number and
starting from another. By default it should start from 1. Create a third function that
given a vector<> of numbers outputs another vector<> containing all the prime
numbers it found in its input. use these three functions to create a program that prints
out all prime numbers less or equal to a number chosen by the user (print, for instance,
15 primes per line). note: in principle, you do not need any vectors to print these prime
numbers; obviously, these extra functions have been added for the sake of the exercise.*/

#include <vector>
#include <iostream>
#include <memory>
//the third function prints the vector with the primes
//the second function generates natural numbers
//first function finds the primes

//function decl
void Generate_natural(int size, std::unique_ptr<std::vector<int>> &my_vec_ptr);
void print_primes(std::unique_ptr<std::vector<int>>& my_vec_ptr);
void find_primes(std::unique_ptr<std::vector<int>>& my_vec_ptr, std::unique_ptr<std::vector<int>>& my_prime_ptr);


#define debug false

int main()
{
#if debug
	int size{ 400 };
#endif

#if !debug	
	int size;
	std::cout << "How many numbers to check for primes? ";
	std::cin >> size;
#endif	
	std::unique_ptr<std::vector<int>> natural_num = std::make_unique<std::vector<int>>(size);
	std::unique_ptr<std::vector<int>> prime_num = std::make_unique<std::vector<int>>();

	Generate_natural(size,natural_num);

	find_primes(natural_num,prime_num);
	print_primes(prime_num);
	
	
	return 0;
}

void Generate_natural(int size,std::unique_ptr<std::vector<int>> &my_vec_ptr)
{
	for (int i{ 1 },j{0}; j < size; i++,j++)
	{
		my_vec_ptr->at(j) = i;
	}
}

void print_primes(std::unique_ptr<std::vector<int>>& my_vec_ptr)
{
	int count{};
	for (auto i : *my_vec_ptr)
	{
		if (count % 15 || count == 0)
			std::cout << i << ",";
		else
			std::cout << i << std::endl;
		count++;
	}

}

void find_primes(std::unique_ptr<std::vector<int>>& my_vec_ptr, std::unique_ptr<std::vector<int>>& my_prime_ptr)
{
	for (int i{}; i<my_vec_ptr->size();i++)
	{
		for (int j{2}; j < i; j++)
		{
			if (!(my_vec_ptr->at(i) % j))
				my_vec_ptr->at(i) = 0;
		}
	}

	for (auto i : *my_vec_ptr)
	{
		if (i != 0)
			my_prime_ptr->push_back(i);
	}

}