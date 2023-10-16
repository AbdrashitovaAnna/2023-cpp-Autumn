#include <iostream>

int main() {
	int y = 0;
	std::cin >> y;

	if (y % 4 == 0 && y % 100 != 0 || y % 400 ==0) 
	{
		std::cout << "YES";
	}
	
	else 
	{
		std::cout << "NO";
	}

	return EXIT_SUCCESS;
}