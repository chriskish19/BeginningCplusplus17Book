/*exercise 9-6. in the previous chapter, you studied a quicksort algorithm that worked
for pointers-to-strings. Generalize the implementation of Ex8_18.cpp so that it works
for vectors of any type (any type for which the < operator exists, that is). Write a
main() function that uses this to sort some vectors with different element types and
outputs both the unsorted and unsorted element lists. naturally, you should do this by
also creating a function template that streams vectors with arbitrary element types to
std::cout.*/

#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <string_view>
#include <vector>


template<typename T>
using Words = std::shared_ptr<std::vector<T>>;

// Swap address at position first with address at position second
template<typename T>
void swap(Words<T> words, size_t first, size_t second);

// Function to output the words
template<typename T>
void show_words(const Words<T> words);

// Sort strings in ascending sequence
// Addresses of words to be sorted are from words[start] to words[end]
template<typename T>
void sort(Words<T> words, size_t start, size_t end);

// Sort strings in ascending sequence
template<typename T> 
void sort(Words<T> words);

// Find the maximum word length
template<typename T> 
size_t max_word_length(const Words<T> words);

int main()
{
	
	std::vector<int> Vec_int{ 2,4,5,6,7,45,43,5,45,65 };
	Words<int> words_int{&Vec_int};

	sort(words_int);
	show_words(words_int);
	
	
	
	
	return 0;
}

// Sort strings in ascending sequence
// Addresses of words to be sorted are from words[start] to words[end]
template<typename T>
void sort(Words<T> words, size_t start, size_t end)
{
	// start index must be less than end index for 2 or more elements
	if (!(start < end))
		return;

	// Choose middle address to partition set
	swap(words, start, (start + end) / 2);                            // Swap middle address with start

	// Check words against chosen word
	size_t current{ start };
	for (size_t i{ start + 1 }; i <= end; i++)
	{
		if (words->at(i) < words->at(start))                                  // Is word less than chosen word?
			swap(words, ++current, i);                                    // Yes, so swap to the left
	}

	swap(words, start, current);                                      // Swap chosen and last swapped words

	if (current > start) sort(words, start, current - 1);             // Sort left subset if exists
	if (end > current + 1) sort(words, current + 1, end);             // Sort right subset if exists
}

// Swap address at position first with address at position second
template<typename T>
void swap(Words<T> words, size_t first, size_t second)
{
	auto temp{ *words[first] };
	*words[first] = *words[second];
	*words[second] = temp;
}

// Function to output the words
template<typename T>
void show_words(const Words<T> words)
{
	const size_t field_width{ max_word_length(words) + 1 };
	const size_t words_per_line{ 8 };
	std::cout << std::left << std::setw(field_width) << words->at(0);     // Output the first word

	size_t words_in_line{};                                            // Words in the current line
	for (size_t i{ 1 }; i < words->size(); ++i)
	{ // Output newline when initial letter changes or after 8 per line
		if ((words->at(i) != words->at(i-1)) || ++words_in_line == words_per_line)
		{
			words_in_line = 0;
			std::cout << std::endl;
		}
		std::cout << std::setw(field_width) << words->at(i);                 // Output a word
	}
	std::cout << std::endl;
}

// Sort strings in ascending sequence
template<typename T>
void sort(Words<T> words)
{
	if (!words->empty())
		sort(words, 0, words->size() - 1);
}

// Find the maximum word length
template<typename T>
size_t max_word_length(const Words<T> words)
{
	size_t max{};
	for (auto& word : *words)
		if (max < word->length()) max = word->length();
	return max;
}