#include <iostream>

int main()
{
	int n = 0;
	std::cin >> n;

	int current = 1;
	int previous = 0;
	int k = 0;

	for (int i = 2; i <= n; i++)
	{
		k = current;
		current = previous + current;
		previous = k;

	}

	std::cout << current;

	return EXIT_SUCCESS;
}