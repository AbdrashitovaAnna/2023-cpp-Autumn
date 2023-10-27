#include <iostream>

int main()
{
	long int x = 0;
	std::cin >> x;
	long int result = 0;

	while (x > 0)
	{
		result = result * 10 + x % 10;
		x /= 10;
	}

	std::cout << result;

	return EXIT_SUCCESS;
}