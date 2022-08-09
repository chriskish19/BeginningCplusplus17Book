/* exercise 7-3. Write a program that reads a text string of arbitrary length from the
keyboard and prompts for entry of a word that is to be found in the string. the
program should find and replace all occurrences of this word, regardless of case,
by as many asterisks as there are characters in the word. it should then output
the new string. only whole words are to be replaced. For example, if the string is
"Our house is at your disposal." and the word that is to be found is "our", then
the resultant string should be as follows: "*** house is at your disposal." and not
"*** house is at y*** disposal." */

#include <string>
#include <iostream>
#include <cctype>

int main()
{
	std::string sentence{};
	std::string tmp_sentence{};
	std::string tmp_word{};
	std::string word{};
	size_t found{};
	size_t index{};
	size_t findChar{};
	std::string separators{ " .-;" };
	size_t endChar{};
	size_t resultChar{};


	std::cout << "Enter a sentence to be modified: ";
	std::getline(std::cin, sentence);
	std::cout << std::endl;

	std::cout << "Enter a word to be found and replaced in the sentence you just entered: ";
	std::cin >> word;
	std::cout << std::endl;

	tmp_sentence = sentence; 
	tmp_word = word;

	//change case to lower for tmp_sentence
	for (size_t i{};i<tmp_sentence.length(); i++) 
	{
		if (isupper(tmp_sentence[i]))
		{
			tmp_sentence[i] = tolower(tmp_sentence[i]);
		}
		
	}
	
	//change case to lower for tmp_word
	for (size_t i{}; i<tmp_word.length(); i++)
	{
		if (isupper(tmp_word[i]))
		{
			tmp_word[i] = tolower(tmp_word[i]);
		}

	}
	 


	size_t check_word{};
	size_t check_word_2{};
	bool flag{ true };
	//This searches the string sentence and finds a word using temp holders so that case doesnt matter then once it finds the positions of word the original sentence gets replaced at those positions. The positions are findChar and endChar.
	while (true)
	{
		//find the word, returns an array position
		found = tmp_sentence.find(tmp_word,index); //use tmp_sentence for the search
		if (found == std::string::npos) //check found hasnt hit the end of the string
		{
			break;
		}
		
		//logic machine for finding whole word
		if (found > 0) //if found is greater than zero, we go backwards in the sentence string with find_last_of looking for separators starting at found. if there are no separators then the found word is not a whole word so we set the index to find the next separators starting at found and we set the replacement machine to off.
		{
			
			check_word = tmp_sentence.find_last_of(separators, found); //goes backwards in the sentence string looking for separators
			check_word_2 = tmp_sentence.find_first_not_of(tmp_word, found); //finds the next character not in tmp_word in the sentence string.
			
			if (check_word == std::string::npos||check_word<found-1) //std::string::npos means no position found. found -1 because if check_word is one less than found it means there is a separator one position behind the word.
			{
				check_word = 0; //reset
				index = tmp_sentence.find_first_of(separators, found); //find the next separators
				flag = false; // turn off replacement machine
			}
			else if (check_word_2 == std::string::npos) // means were at the end of the string and the word is whole
			{
				check_word_2 = 0; //reset
				check_word = 0; //reset
				flag = true; //turn on replacement machine
			}
			else if(check_word_2 == tmp_sentence.find_first_of(separators,check_word_2)) //check if the end of the word is a separator, if it is the word is whole
			{
				check_word = 0; //reset
				flag = true; //turn on replacement machine
			}
		}
		else //we are at the begining of the sentence string. We start by finding the first character that isnt tmp_word starting at found. Then we check if no position was found and if no position is found it means we are at the end of the sentence string. So we turn on replacement machine and reset check_word. We then check to see if check_word is a separator,if it is turn on replacement machine. If check_word isnt either of those it means found is not a whole word so we reset check_word, turn off replacement machine and set the index ahead to find the next separator.
		{
			check_word = tmp_sentence.find_first_not_of(tmp_word, found);
			if (check_word == std::string::npos)
			{
				flag = true; //turn on replacement machine
				check_word = 0; //reset 
			}
			else if (check_word == tmp_sentence.find_first_of(separators, check_word)) //check to see if check_word is a separator, if it is turn on replacement machine.
			{
				flag = true;
			}
			else
			{
				check_word = 0; //reset
				flag = false; // skip replacement
				index = tmp_sentence.find_first_of(separators, found); //find the next separator
			}
		}





		//Replacement machine
		if (flag)
		{
			//find the first char
			findChar = tmp_sentence.find_first_of(tmp_word, found);
		
			//find the end of the word looking for separators
			endChar = tmp_sentence.find_last_of(tmp_word, found+tmp_word.length()); 
		
			if (findChar == std::string::npos && endChar == std::string::npos) //check both findChar and endChar havent hit the end of the string
			{
			break;
			}
		
			resultChar = endChar - findChar + 1; //difference in starting and ending, gives a count of the word to be replaced. added 1 because subtracting array positions results in one less than the actual count of the positions say 17 and 19 result is 2 but its actually 3 positions. That should work as a quick fix.
			//replace(start character, count, count for how many *, replacement char *)
			sentence.replace(findChar, resultChar, resultChar,'*');
		
			index = endChar; //set index to end of word
		}

		

	}
	
	std::cout << sentence << std::endl;
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}