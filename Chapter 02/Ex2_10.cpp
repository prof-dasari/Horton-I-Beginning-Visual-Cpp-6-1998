// EX2_10.CPP
// Using a using directive
#include <iostream>

namespace myStuff
{
	int value = 0;
}

using namespace myStuff;

int main()
{
	std::cout << "enter an integer: ";
	std::cin >> value;
	std::cout << "\nYou entered " << value
		 << std::endl;

	return 0;
}