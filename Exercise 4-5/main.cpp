/*Exercise 4-5. Add some code at the end of the main() function of Ex4_06.cpp to 
print an additional message. If you have exactly one mouse, output a message of the 
form “It is a brown/white mouse.” Otherwise, if you have multiple mice, compose a 
grammatically correct message of the form “Of these mice, N is a/are brown mouse/
mice.” If you have no mice, no new message needs to be printed. Use an appropriate 
mixture of conditional operators and if/else statements.
*/


#include  <iostream>

int main()
{
    int mice{};               // Count of all mice
    int brown{};              // Count of brown mice
    int white{};              // Count of white  mice

    std::cout << "How many brown mice do you have? ";
    std::cin >> brown;
    std::cout << "How many white mice do you have? ";
    std::cin >> white;

    mice = brown + white;

    std::cout << "You have " << mice
        << (mice == 1 ? " mouse" : " mice")
        << " in total." << std::endl;

    if (mice == 1)
    {
        
        if (brown == 1)
        {
            std::cout << "You have " << brown << " brown mouse" << std::endl;
        }
        else
        {
            std::cout << "You have " << white << " white mouse" << std::endl;
        }
    }
    else
    {
        std::cout << "You have " << brown << " brown mice and " << white << " white mice" << std::endl;
    }
   
}