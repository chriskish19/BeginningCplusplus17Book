/*exercise 7-6. Write a program that reads a text string of arbitrary length from the
keyboard followed by a string containing one or more letters. output a list of all the
whole words in the text that begin with any of the letters, uppercase or lowercase.*/


#include <string>
#include <iostream>
#include <array>

#define debug false
#define MAX_ARRAY 50

int main()
{
#if !debug	
	std::string sentence{};
	std::string letters{};
#endif

#if debug
	std::string sentence{"Hello world my favorite"};
	std::string letters{"HWmf"};
#endif

	//Variables
	std::string tmp_sentence{};
	std::string tmp_letters{};
	std::string separators{ " " };
	std::array<std::string, MAX_ARRAY> box{};

#if !debug
	std::cout << "Enter a sentence: ";
	std::getline(std::cin, sentence);
	std::cout << std::endl;

	std::cout << "Enter some letters: ";
	std::getline(std::cin, letters);
	std::cout << std::endl;
#endif

	//initialize temps
	tmp_sentence = sentence;
	tmp_letters = letters;

	//set temps to lower case
	for (int i = 0; i < tmp_sentence.length(); i++)
	{
		if (isupper(tmp_sentence[i]))
		{
			tmp_sentence[i] = tolower(tmp_sentence[i]);
		}
	}

	//set temps to lower case
	for (int i = 0; i < tmp_letters.length(); i++)
	{
		if (isupper(tmp_letters[i]))
		{
			tmp_letters[i] = tolower(tmp_letters[i]);
		}
	}
	
	//Matches letters to a word in sentence, the first letter in the word and saves it in box which is an array
	for (size_t i{}, temp_letter{},index{}; temp_letter != std::string::npos; i++) //i++ executes before testing the condition which is why the if statement for index==std::string::npos is needed otherwise I would've added it in the for loop condition.
	{	
		temp_letter = tmp_sentence.find_first_not_of(separators, index);
		for (size_t j{}; j < tmp_letters.length(); j++)
		{
			if (tmp_letters[j] == tmp_sentence[temp_letter]) 
				box[i] = sentence.substr(index, tmp_sentence.find_first_of(separators, index)-index);
		}
		index = tmp_sentence.find_first_of(separators, index);
		if (index == std::string::npos) //check index before adding one because adding one to std::string::npos resets it back to zero
			break;
		else
			index++; //add one to advance past separator
	}

	//output the found words that matched the first letter
	for (auto i : box)
		std::cout << i << std::endl;

	return 0;
}