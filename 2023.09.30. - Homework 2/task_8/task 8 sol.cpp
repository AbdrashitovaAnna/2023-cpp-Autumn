#include <iostream>

int main()
{
	int a = 3;
	int b = 2;
	int c = 1;
	int z = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	if (a >= b)
	{
		z = b;
		b = a;
		a = z;
	}
	if (a >= c)
	{
		z = c;
		c = a;
		a = z;
	}
	if (b >= c)
	{
		z = b;
		b = c;
		c = z;
	}

	std::cout << a << " ";
	std::cout << b << " ";
	std::cout << c;

	return EXIT_SUCCESS;

}