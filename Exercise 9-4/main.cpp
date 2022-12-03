/*exercise 9-4. Write your own version of the std::size() family of functions called
my_size() that work not only for fixed-size arrays but also for std::vector<> and
std::array<> objects. You are not allowed to use the sizeof() operator.*/



#include <vector>
#include <array>
#include <iostream>


template<typename T, size_t _size>
constexpr size_t my_size(const T(&)[_size]);

template<typename T>
constexpr size_t my_size(const T Cont);

int main()
{
	int hello[50]{1,2,3,4,5,6};
	std::vector<int> Vec(50);
	std::array<int, 50> arry{};
	


	std::cout << my_size(arry) << std::endl;
}

template<typename T, size_t _size>
constexpr size_t my_size(const T (&)[_size])
{
	return _size;
}

template<typename T>
constexpr size_t my_size(const T Cont)
{
	return Cont.size();
}