#include<iostream>
#include<cstdlib>

int main(int, char**)
{
	int n = 0;
	int count = 0;
	std::cin >> n;

	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
		if (*(a + i) > 0)
		{
			count += 1;
		}
	}

	std::cout << count;

	free(a);

	return EXIT_SUCCESS;
}