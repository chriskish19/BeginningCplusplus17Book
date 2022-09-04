/*exercise 8-7. the so-called fibonacci function is popular among lecturers in computer
science and mathematics for introducing recursion. this function has to compute the
nth number from the famous fibonacci sequence, named after italian mathematician
Leonardo of pisa, known also as fibonacci. this sequence of positive integer numbers
is characterized by the fact that every number after the first two is the sum of the two
preceding ones. for n ≥ 1, the sequence is defined as follows:
1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181...
for convenience, computer scientists mostly define an additional zeroth fibonacci
number as zero. Write a function to compute the nth fibonacci number recursively.
test it with a simple program that prompts the user for how many numbers should be
computed and then prints them out one by one, each on a different line.
extra: While the naive recursive version of the fibonacci function is very elegant—the
code matches nearly verbatim with common mathematical definitions—it is notorious
for being very slow. if you ask the computer to compute, say, 100 fibonacci numbers,
you’ll notice that it becomes noticeably slower and slower as n becomes larger. Do
you think you can rewrite the function to use a loop instead of recursion? how many
numbers can you correctly compute now?
hint: in each iteration of the loop, you’ll naturally want to compute a next number. to do
this, all you need are the previous two numbers. so, there should be no need to keep
track of the full sequence in, for instance, a vector<>.*/

#include <iostream>

// recursive version of function
#define slowyrecursive false

#if !slowyrecursive  
int main()
{
	int number{ };
	std::cout << "Enter how many fibonacci numbers:";
	std::cin >> number;
	

	size_t start{1};
	size_t next{1};
	size_t total{};
	
	for (int i{}; i < number; i++)
	{
		total = start + next; //1+1 = 2 //3 + 5 = 8
		start = total + next; //2+1 = 3 // 5+ 8 = 13
		next = total + start; // 2+3 = 5 // 8 + 13 = 21

		std::cout << total << "," << start << "," << next << std::endl;
	}

	return 0;
}

#endif

#if slowyrecursive 

int fib(int n);

int main()
{
	int number{};
	std::cout << "How many fibi numbers?";
	std::cin >> number;
	fib(number);
	
	return 0;
}


int fib(int n)
	{
		if (n <= 1)
			return n;
		return fib(n - 1) + fib(n - 2);
	}


#endif