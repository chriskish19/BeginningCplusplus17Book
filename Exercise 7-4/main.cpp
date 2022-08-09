/*exercise 7-4. Write a program that prompts for the input of two words and determines
whether one is an anagram of the other. an anagram of a word is formed by
rearranging its letters, using each of the original letters precisely once. For instance,
listen and silent are anagrams of one another, but listens and silent are not.*/

#include <string>
#include <iostream>


#define debug false
#define MAX_COUNT 50

int main()
{
#if debug	
	std::string word1{"elevenplustwo"};
	std::string word2{"twelveplusone"};
#endif
	
#if !debug	
	std::string word1{};
	std::string word2{};
#endif
	size_t count_word1[MAX_COUNT]{};
	size_t counter_word1{};

	size_t count_word2[MAX_COUNT]{};
	size_t counter_word2{};

	size_t total_word1{};
	size_t total_word2{};

#if !debug
	std::cout << "Enter a word to test if its an anagram of the other: ";
	std::cin >> word1;
	std::cout << std::endl;

	std::cout << "Enter the second word: ";
	std::cin >> word2;
	std::cout << std::endl;
#endif
	


	if (word1.length() == word2.length())
	{
		for (int i = 0; i < word1.length(); i++)
		{
			for (int j = 0; j < word1.length(); j++)
			{
				if (word1.at(i) == word1.at(j))
				{
					count_word1[i] = counter_word1++;
				}
			}
		}


		for (int i = 0; i < word2.length(); i++)
		{
			for (int j = 0; j < word2.length(); j++)
			{
				if (word1.at(i) == word1.at(j))
				{
					count_word2[i] = counter_word2++;
				}
			}
		}

		for (auto i : count_word1)
		{
			total_word1 += i;
		}

		for (auto i : count_word2)
		{
			total_word2 += i;
		}

		if (total_word1 == total_word2)
		{
			std::cout << "The words are anagrams!" << std::endl;
		}
		else
		{
			std::cout << "The words are not anagrams" << std::endl;
		}
	}
	else
	{
		std::cout << "The words are different lengths" << std::endl;
	}
	


	
	
	
	
	
	return 0;



}