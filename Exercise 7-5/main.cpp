/*exercise 7-5. generalize the program of exercise 7-4 such that it ignores spaces when
deciding whether two strings are anagrams. With this generalized definition, funeral
and real fun are considered anagrams, as are eleven plus two and twelve plus one,
along with desperation and a rope ends it.*/

#include <string>
#include <iostream>
#include <algorithm>

#define debug false
#define MAX_COUNT 50

int main()
{
#if debug	
	std::string word1{"eleven plus two"};
	std::string word2{"twelve plus one"};
#endif
	
	size_t count_word1[MAX_COUNT]{};
	size_t counter_word1{};

	size_t count_word2[MAX_COUNT]{};
	size_t counter_word2{};

	size_t total_word1{};
	size_t total_word2{};


#if !debug	
	std::string word1{};
	std::string word2{};
#endif
	

#if !debug
	std::cout << "Enter a word to test if its an anagram of the other: ";
	std::getline(std::cin, word1);
	std::cout << std::endl;

	std::cout << "Enter the second word: ";
	std::getline(std::cin, word2);
	std::cout << std::endl;
#endif
	
	word1.erase(remove_if(word1.begin(), word1.end(), isspace), word1.end());
	word2.erase(remove_if(word2.begin(), word2.end(), isspace), word2.end());

	
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