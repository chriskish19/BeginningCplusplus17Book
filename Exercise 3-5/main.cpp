 /*exercise 3 - 5. Write a program that defines an enumeration of type Color where the
enumerators are Red, Green, Yellow, Purple, Blue, Black, and White. define the type
for enumerators as an unsigned integer type and arrange for the integer value of each
enumerator to be the rgB combination for the color it represents (you can easily find
the hexadecimal rgB encoding of any color online). Create variables of type Color
initialized with enumerators for yellow, purple, and green. access the enumerator value
and extract and output the rgB components as separate values */

#include <iostream>



int main()
{
	enum class color : unsigned int { Red = 0xFF0000, Green = 0x008000, Yellow = 0xFFFF00, Purple = 0x5500FF, Blue = 0x00ABFF, Black = 0x000000, White = 0xFFFFFF };

	color yellow{ color::Yellow };
	color purple{ color::Purple };
	color green{ color::Green };

	//							Red      Green	   Blue    
	unsigned int red_mask  { 0b11111111'00000000'00000000 };
	unsigned int green_mask{ 0b00000000'11111111'00000000 };
	unsigned int blue_mask { 0b00000000'00000000'11111111 };

	unsigned int Yellow_RedBits{ static_cast<unsigned int>(yellow) & red_mask };
	unsigned int Yellow_GreenBits{ static_cast<unsigned int>(yellow) & green_mask };
	unsigned int Yellow_BlueBits{ static_cast<unsigned int>(yellow) & blue_mask };

	unsigned int Purple_RedBits{ static_cast<unsigned int>(purple) & red_mask };
	unsigned int Purple_GreenBits{ static_cast<unsigned int>(purple) & green_mask };
	unsigned int Purple_BlueBits{ static_cast<unsigned int>(purple) & blue_mask };

	unsigned int Green_RedBits{ static_cast<unsigned int>(green) & red_mask };
	unsigned int Green_GreenBits{ static_cast<unsigned int>(green) & green_mask };
	unsigned int Green_BlueBits{ static_cast<unsigned int>(green) & blue_mask };


	Yellow_RedBits = Yellow_RedBits >> 16;
	Yellow_GreenBits = Yellow_GreenBits >> 8;
		
	Purple_RedBits = Purple_RedBits >> 16;
	Purple_GreenBits = Purple_GreenBits >> 8;

	Green_RedBits = Green_RedBits >> 16;
	Green_GreenBits = Green_GreenBits >> 8;





	std::cout << "Color Yellow, Red Component: "<< Yellow_RedBits << std::endl;
	std::cout << "Color Yellow, Green Component: " << Yellow_GreenBits << std::endl;
	std::cout << "Color Yellow, Blue Component: " << Yellow_BlueBits << std::endl;
	std::cout << std::endl;
	std::cout << "Color Purple, Red Component: " << Purple_RedBits << std::endl;
	std::cout << "Color Purple, Green Component: " << Purple_GreenBits << std::endl;
	std::cout << "Color Purple, Blue Component: " << Purple_BlueBits << std::endl;
	std::cout << std::endl;
	std::cout << "Color Green, Red Component: " << Green_RedBits << std::endl;
	std::cout << "Color Green, Green Component: " << Green_GreenBits << std::endl;
	std::cout << "Color Green, Blue Component: " << Green_BlueBits << std::endl;
}