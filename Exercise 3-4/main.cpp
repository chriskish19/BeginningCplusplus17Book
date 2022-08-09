//exercise 3-4. Write a program to read four characters from the keyboard and pack
//them into a single integer variable.display the value of this variable as hexadecimal.
//unpack the four bytes of the variable and output them in reverse order, with the low -
//order byte first.

#include <iostream>
#include <bitset>

void reverseBin(std::bitset<33>& characterSet)
{
	int size = 32; 

	for (int i = 0; i < size; i++)
	{
		std::cout << characterSet[size-i];
	}
}

int main()
{
	
	std::bitset<33> characters;
	int offset{};
	int counter{};
	
	for(int i = 0; i<4;i++)
	{
		char ch{};
		
		std::cout << "Enter a character: ";
		scanf_s(" %c", &ch);
		std::cout << std::endl;
		std::bitset<32> mychar(ch);
		for (int i = 0;i< sizeof(char)+offset; i++)
		{
			characters[i] = mychar[i];		
		}
		
		offset = offset + 8;
		
	}
	
	int int_characters;
	int_characters = static_cast<int>(characters.to_ulong());

	std::cout << "In hex: "<< std::hex << int_characters << "\n";
	std::cout << std::endl;
	std::cout << "In binary: " << characters;
	std::cout << std::endl;
	std::cout << "In reverse: ";
	reverseBin(characters);
}