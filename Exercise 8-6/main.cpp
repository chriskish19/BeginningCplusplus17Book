/*exercise 8-6. implement a program that queries the user for a number of grades. a
grade is an integer number between 0 and 100 (both inclusive). the user can stop at
any time by entering a negative number. once all grades have been collected, your
program is to output the following statistics: the five highest grades, the five lowest
grades, the average grade, the median grade, and the standard deviation and variance
of the grades. of course, you’re to write a separate function to compute each of these
statistics. also, you must write the code to print five values only once. to practice, use
arrays to store any five extremes and not, for instance, vectors.

hint: as a preprocessing step, you should first sort the grades the user enters; you’ll
see that this will make writing the functions to compute the statistics much easier. You
can adapt the quicksort algorithm from Ex8_18 to work with grade numbers.
Caution: Make sure to do something sensible if the user enters less than five or even
zero grades. anything is fine, as long as it does not crash. perhaps you can practice
std::optional<> to deal with inputs such as an empty series of grades?
note: the median is the value that appears in the middle position of a sorted list. if
there is an even number of grades, there obviously is no single middle value—the
median is then defined as the mean of the two middle values. the formulas to compute
mean (μ) and standard deviation (σ) of a series of n grades xi are as follows:
*/



//header librarys
///////////////////////
#include <iostream>
#include <array>
#include <memory>
#include <cmath>


//Function decls
///////////////////////
void fiveHighest(int* my_array, size_t size);
void sort(int* my_array, size_t size,bool ascending = true);
void swap(int* my_array, size_t size, int i_position, int j_position);
void fiveLowest(int* my_array, size_t size);
int avgGrade(int* my_array, size_t size); // also called the mean
void cout(int out, std::string desc);
void cout(int* my_array, size_t size);
int FindMedian(int* my_array,size_t size);
int CountElements(int* my_array, size_t size, int ignoredValue = 0);
double variance(int* my_array, size_t size, int mean, int count);
double standardDev(double variance);



//debug hash define
////////////////////////////
#define debug true



int main()
{
	//variables needed
	const unsigned int Size{ 50 };
	const int minGrade{ 1 };
	const int maxGrade{ 100 };


//if debug true execute block
#if debug
	//array of grades to test with
	std::array<int, Size> grades{ 56,67,44,34,67,34,65,89,12,34,56 };
#endif


//if debug not true execute block
#if !debug
	
	// variables needed
	std::array<int, Size> grades{};
	int input{};

	// loop until end of grades array
	while (input < grades.size())
	{
		std::cout << "(Max 50 grades) Enter a grade, To stop enter a zero grade: ";
		std::cin >> grades[input];
		if (grades[input] < minGrade)
		{
			break;
		}
			
		if (grades[input] > maxGrade)
		{
			std::cout << "Please re-enter grade, max grade value is 100" << std::endl;
			continue;
		}
		input++;
	}
	
#endif
	
	//function calls
	/////////////////////////
	sort(grades.data(), Size); // ascending
	fiveHighest(grades.data(), Size);
	fiveLowest(grades.data(), Size);
	int average = avgGrade(grades.data(), Size);
	cout(average, "Average is");
	int median = FindMedian(grades.data(), Size);
	cout(median, "Median is");
	int count = CountElements(grades.data(), Size);
	double VarianceValue = variance(grades.data(), Size, average, count);
	double standardDevValue = standardDev(VarianceValue);
	cout(VarianceValue, "Variance is");
	cout(standardDevValue, "Standard Deviation is");



	return 0;
}



//functions defined
//////////////////////////


// displays five highest grades
void fiveHighest(int* my_array, size_t size)
{
	std::cout << "The five highest grades are: " << std::endl;
	for (size_t i{}; i < 5; ++i)
	{
		std::cout << my_array[i] << std::endl;
	}
}

// sorts an array in descending or ascending order
// false for descending order, default blank for ascending
void sort(int* my_array, size_t size, bool ascending)
{
	// sorting machine
	for (int i{}; i < size; i++)
	{
		for (int j{}; j < size; j++)
		{
			
			if (ascending)
			{
				// compare values
				if (my_array[i] > my_array[j])
				{
					//swap values
					swap(my_array, size, i, j);
				}
			}
			else //descending
			{
				// compare values
				if (my_array[i] < my_array[j])
				{
					//swap values
					swap(my_array, size, i, j);
				}
			}
		}
	}
}

// swap values in an array
void swap(int* my_array, size_t size, int i_position,int j_position)
{
	int swap{};
	swap = my_array[i_position];
	my_array[i_position] = my_array[j_position];
	my_array[j_position] = swap;
}

void fiveLowest(int* my_array, size_t size)
{
	int count{};
	std::cout << "The five lowest grades are: " << std::endl;
	for (size_t i{size-1}; i > 0; --i)
	{
		if (my_array[i] != 0 && count<5)
		{
			std::cout << my_array[i] << std::endl;
			count++;
		}
		
		
	}
}

// average grade returned
int avgGrade(int* my_array, size_t size)
{
	int count = CountElements(my_array, size);
	int sum{};
	// count number of actual elements
	for (int i{}; i < count; i++)
	{
		sum = my_array[i] + sum;		
	}
	return sum/count;
}

// std::cout a variable value
void cout(int out,std::string desc)
{
	std::cout << desc << ":" << out << std::endl;
}

// Median value returned
int FindMedian(int* my_array, size_t size)
{
	int count = CountElements(my_array, size);
	
	if (count % 2 == 0)
	{
		//even no middle
		return my_array[count / 2] + my_array[(count / 2) + 1];
		
	}
	else
	{
		//odd: has middle
		return my_array[(count-1)/2];
	}
	
	
}

// returns a count of filled elements
int CountElements(int* my_array, size_t size, int ignoredValue)
{
	int count{};
	// count number of actual elements
	for (int i{}; i < size; i++)
	{
		
		if (my_array[i] != ignoredValue)
		{
			count++;
		}

	}
	return count;
}

// returns variance calculation
double variance(int* my_array, size_t size, int mean, int count)
{
	//For the formula
	//N is count
	//xi is the elements
	//u is mean

	double square{};
	double total{};

	for (int i{}; i < count; i++)
	{
		// base , power
		square = pow(my_array[i] - mean, 2);
		total = total + square;
	}
	return total / count;	
}

// standard deviation calculation
double standardDev(double variance)
{
	return std::sqrt(variance);
}

// outputs an array values
void cout(int* my_array, size_t size)
{
	for (int i{}; i < size; i++)
	{
		std::cout << my_array[i] << std::endl;
	}
}