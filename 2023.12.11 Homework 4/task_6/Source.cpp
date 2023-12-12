#include<iostream>
#include<cstdlib>

int main(int, char**)
{
	int n = 0;
	int max_val = 0;
	int min_val = 0;
	int max_index = 0;
	int min_index = 0;
	std::cin >> n;

	int* a = (int*)malloc(sizeof(int) * n);

	std::cin >> *a;
	max_val = *a;
	min_val = *a;

	for (int i = 1; i < n; ++i)
	{
		std::cin >> *(a + i);
		if (*(a + i) >= max_val)
		{
			max_val = *(a + i);
			max_index = i;
		}
		if (*(a + i) < min_val)
		{
			min_val = *(a + i);
			min_index = i;
		}
	}

	*(a + max_index) = min_val;
	*(a + min_index) = max_val;

	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}

	free(a);

	return EXIT_SUCCESS;
}