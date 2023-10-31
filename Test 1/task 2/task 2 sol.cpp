#include <iostream> 

int main()
{
	int n = 0;
	std::cin >> n;

	for (int j = 0; j < n; j++)
	{
		for (int i = j; i < n + j; i++)
		{
			std::cout << i % 2 + 1;
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}