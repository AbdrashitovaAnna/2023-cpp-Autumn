#include <iostream>

int main()
{
	int n = 0;
	int k = 0;
	int pow = 1;
	std::cin >> n;

	while (pow < n)
	{
		pow = pow * 2;
		k += 1;
	}

	std::cout << k;

	return EXIT_SUCCESS;
}