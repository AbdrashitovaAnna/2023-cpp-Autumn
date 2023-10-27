#include <iostream>
#include <cmath>

int main()
{
	int n = 0;
	std::cin >> n;
	int amount = 0;

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (n / i == i)
				amount += 1;

			else
			{
				amount += 2;
			}
		}
	}
	std::cout << amount;

	return EXIT_SUCCESS;
}