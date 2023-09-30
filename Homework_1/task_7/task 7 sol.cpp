#include <iostream>
int main() {
	int R = 0;
	std::cin >> R;
	std::cout << "The next number for the number " << R << " is " << R + 1 << "." << std::endl;
	std::cout << "The previous number for the number " << R << " is " << R - 1 << "." << std::endl;
	return 0;
}