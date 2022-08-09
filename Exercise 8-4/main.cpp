/*exercise 8-4. Create a function, plus(), that adds two values and returns their sum.
provide overloaded versions to work with int, double, and strings, and test that they
work with the following calls:
const int n {plus(3, 4)};
const double d {plus(3.2, 4.2)};
const string s {plus("he", "llo")};
const string s1 {"aaa"};
const string s2 {"bbb"};
const string s3 {plus(s1, s2)};
Can you explain why the following doesn’t work?
const auto d {plus(3, 4.2)};*/


#include <string>
#include <iostream>

const int n{ plus(3, 4) };
const double d{ plus(3.2, 4.2) };
const std::string s{ plus("he", "llo") };
const std::string s1{ "aaa" };
const std::string s2{ "bbb" };
const std::string s3{ plus(s1, s2) };

const auto d{ plus(3.0, 4.2) }; //it doesnt work because 3 is an int if you do 3.0 then it works, compiler reads the literals as they are

int main()
{

}

int plus(int i, int j)
{
	return i + j;
}

double plus(double i, double j)
{
	return i + j;
}

std::string plus(std::string one, std::string two)
{
	return one + two;
}