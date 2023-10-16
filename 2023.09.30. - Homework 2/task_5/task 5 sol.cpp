#include <iostream>

int main()
{
	int n = 0;
	std::cin >> n;

	if (10 <= n % 100 && n % 100 <= 20)
	{
		std::cout << n << " bochek" << std::endl;
	}
	else
	{
		if (n % 10 == 1)
		{
			std::cout << n << " bochka" << std::endl;
		}
		else if (2 <= n % 10 && n % 10 <= 4)
		{
			std::cout << n << " bochki" << std::endl;
		}
		else
		{
			std::cout << n << " bochek" << std::endl;
		}
	}

	return EXIT_SUCCESS;
}
