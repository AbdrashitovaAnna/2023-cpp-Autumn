#include<iostream>
#include<cstdlib>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;

	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}

	for (int i = n - 1; i >= 0; --i)
	{
		if (*(a + i) <= 0)
		{
			for (int j = i + 1; j < n; ++j)
			{
				*(a + j - 1) = *(a + j);
			}
			n -= 1;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}

	free(a);

	return EXIT_SUCCESS;
}