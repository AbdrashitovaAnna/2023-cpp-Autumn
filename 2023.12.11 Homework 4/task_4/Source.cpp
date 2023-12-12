#include<iostream>
#include<cstdlib>

int main(int, char**)
{
	int n = 0;
	int max_el = 0;
	std::cin >> n;

	int* a = (int*)malloc(sizeof(int) * n);

	std::cin >> *a;
	max_el = *a;

	for (int i = 1; i < n; ++i)
	{
		std::cin >> *(a + i);
		if (*(a + i) > max_el)
		{
			max_el = *(a + i);
		}
	}

	std::cout << max_el;

	free(a);

	return EXIT_SUCCESS;
}