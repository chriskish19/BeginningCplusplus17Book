/*exercise 7-2. Write a program that reads text entered over an arbitrary number of lines.
Find and record each unique word that appears in the text and record the number of
occurrences of each word. output the words and their occurrence counts. Words and
counts should align in columns. the words should align to the left; the counts to the
right. there should be three words per row in your table.*/

#include <vector>
#include <string>
#include <iostream>

int main()
{
	std::vector<std::string> wordsBox{};
	
	std::string sentence{};
	std::string separators{ ",.- ()" };
	std::string word{};
	size_t index{};
	size_t SeparatorPosition{}; 
	size_t counter{};
	size_t wordCounter{};

	std::cout << "Enter a sentence: ";
	std::getline(std::cin, sentence);


	while (SeparatorPosition!=std::string::npos && index!=std::string::npos)
	{
		SeparatorPosition = sentence.find_first_of(separators, index);
		word = sentence.substr(index, SeparatorPosition-index); 
		index +=word.length();
		wordsBox.push_back(word);
		if (index == SeparatorPosition)
		{
			index = sentence.find_first_not_of(separators, SeparatorPosition);
		}

	}

	std::vector<size_t> wordCount(wordsBox.size());
	//comparing machine
	for (int i = 0; i < wordsBox.size(); i++)
	{
		for (int j = 0; j < wordsBox.size(); j++)
		{
			if(wordsBox.at(i).compare(wordsBox.at(j))==0)
			{
				wordCount.at(j)++;
			}
		
		}
		
		 
	}

	//Printing table machine
	for (int i = 0; i < wordsBox.size(); i++)
	{
		if (i % 3 || i==0)
		{
			std::cout << wordsBox.at(i)<< "         " << wordCount.at(i) <<"         ";
		}
		else
		{
			std::cout << std::endl;
			std::cout << wordsBox.at(i) << "         " << wordCount.at(i) << "         ";
		}
	}


	return 0;
}
