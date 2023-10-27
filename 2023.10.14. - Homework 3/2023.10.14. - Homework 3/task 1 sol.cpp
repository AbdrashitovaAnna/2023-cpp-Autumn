#include <iostream>

int main()
{
	int n = 0;
	int amount = 0;
	int val = 1;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cout << val << " ";
		amount += 1;

		if (val == amount)
		{
			val += 1;
			amount = 0;
		}

	}

	return EXIT_SUCCESS;
}