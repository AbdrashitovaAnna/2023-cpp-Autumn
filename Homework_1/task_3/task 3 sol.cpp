#include <iostream>

int main() {
	long long int n = 0;
	std::cin >> n;
	n = (n - 5) / 10;
	std::cout << n * (n + 1) * 100 + 25;

	return 0;
}