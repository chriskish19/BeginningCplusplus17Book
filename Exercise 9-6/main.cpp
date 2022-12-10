/*exercise 9-6. in the previous chapter, you studied a quicksort algorithm that worked
for pointers-to-strings. Generalize the implementation of Ex8_18.cpp so that it works
for vectors of any type (any type for which the < operator exists, that is). Write a
main() function that uses this to sort some vectors with different element types and
outputs both the (typo)sorted and unsorted element lists. naturally, you should do this by
also creating a function template that streams vectors with arbitrary element types to
std::cout.*/




// includes
#include <vector>		// std::vector
#include <iostream>		// std::cout
#include <iomanip>		// std::setw(..)





// Function Prototypes: See definitions for more info
template <typename T> void swap(std::vector<T>& data, int first, int second);
template <typename T> void display(std::vector<T>& data, int out_width = 5);
template <typename T> void sort(std::vector<T>& data);




int main()
{
	std::vector<int> test1{ 9,4,6,3,2,5 };					// test values set 1
	display(test1);											// list unsorted values
	sort(test1);											// sort the values
	display(test1);											// display the sorted values


	std::vector<char> test2{ 'g','h','r','d','s','t' };		// test values set 2
	display(test2);											// list unsorted values
	sort(test2);											// sort the values
	display(test2);											// display the sorted values



	std::vector<double> test3{ 0.5,6.3,8.9,1.3,5.0,9.0 };	// test values set 3
	display(test3);											// list unsorted values
	sort(test3);											// sort the values
	display(test3);											// display the sorted values



	return 0;
}



// PURPOSE:		swaps values at a given position	
// data:		vector of typename T reference
// Pos_first:	first position in the vector
// Pos_second:	second position in the vector
template <typename T> void swap(std::vector<T>& data, int Pos_first, int Pos_second)
{
	T temp{};									// temp variable holder
	temp = data[Pos_first];						// Set temp equal to the position to be swapped
	data[Pos_first] = data[Pos_second];			// Swap the second position to the first
	data[Pos_second] = temp;					// Set the second position equal to the first 
}


// PURPOSE:		display the values in data to the console using std::cout
// data:		a reference to values stored in a vector of template type T
// out_width:	number of characters to be used as field width
template <typename T> void display(std::vector<T>& data,int out_width = 5)
{
	for(auto& i : data)
	{
		std::cout << std::setw(out_width) << i;
	}
	std::cout << std::endl;
}


template <typename T> void sort(std::vector<T>& data)
{

}