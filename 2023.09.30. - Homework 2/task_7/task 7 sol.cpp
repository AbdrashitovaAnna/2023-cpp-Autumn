#include <iostream>

int main() {
	int n = 0;
	std::cin >> n;

	if (n / 100 > 0)
	{
		std::cout << "C";
		n %= 100;
	}

	if (n / 90 > 0)
	{
		std::cout << "XC";
		n %= 90;
	}

	if (n / 50 > 0)
	{
		std::cout << 'L';
		n %= 50;
	}

	if (n / 40 > 0)
	{
		std::cout << "XL";
		n %= 40;
	}

	if (n / 10 > 0)
	{
		std::string stuff(n / 10, 'X');
		std::cout << stuff;
		n %= 10;
	}

	if (n / 9 > 0)
	{
		std::cout << "IX";
		n %= 9;
	}

	if (n / 5 > 0)
	{
		std::cout << "V";
		n %= 5;
	}

	if (n / 4 > 0)
	{
		std::cout << "IV";
		n %= 4;
	}

	if (n > 0)
	{
		std::string stuff(n, 'I');
		std::cout << stuff;
	}

	return EXIT_SUCCESS;
}
