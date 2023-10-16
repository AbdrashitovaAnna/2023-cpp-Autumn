#include <iostream>
int main() {
	int r = 0;
	std::cin >> r;
	std::cout << "The next number for the number " << r << " is " << r + 1 << "." << std::endl;
	std::cout << "The previous number for the number " << r << " is " << r - 1 << "." << std::endl;
	return 0;
}