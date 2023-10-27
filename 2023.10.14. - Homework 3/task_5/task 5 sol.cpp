#include <iostream>

int main()
{
	int k = 0;
	int palindrome = 0;
	int count = 0;
	int n = 0;
	std::cin >> k;

	for (int i = 1; i <= k; i++)
	{
		n = i;

		while (n > 0)
		{
			palindrome = palindrome * 10 + n % 10;
			n /= 10;
		}

		if (i == palindrome)
			count += 1;

		palindrome = 0;
	}

	std::cout << count;

	return EXIT_SUCCESS;
}