#include <iostream>

int main() {

	int n = 0;
	std::cin >> n;

	int t1 = 0;
	int t5 = 0;
	int t10 = 0;
	int t20 = 0;
	int t60 = 0;

	if (n >= 60)
	{
		t60 = n / 60;
		n = n % 60;
	}
	if (n >= 20)
	{
		t20 = n / 20;
		n = n % 20;
	}
	if (n >= 10)
	{
		t10 = n / 10;
		n = n % 10;
	}
	if (n >= 5)
	{
		t5 = n / 5;
		n = n % 5;
	}
	t1 = n;

	if (t1 * 15 + t5 * 70 + t10 * 125 + t20 * 230 >= 440)
	{
		t1 = 0;
		t5 = 0;
		t10 = 0;
		t20 = 0;
		t60 += 1;
	}
	if (t1 * 15 + t5 * 70 + t10 * 125 >= 230)
	{
		t1 = 0;
		t5 = 0;
		t10 = 0;
		t20 += 1;
	}
	if (t1 * 15 + t5 * 70 >= 125)
	{
		t1 = 0;
		t5 = 0;
		t10 += 1;
	}

	std::cout << t1 << " ";
	std::cout << t5 << " ";
	std::cout << t10 << " ";
	std::cout << t20 << " ";
	std::cout << t60;

	return EXIT_SUCCESS;
}