#include <iostream>

int main() {
	long long int N = 0;
	std::cin >> N;
	N = (N - 5) / 10;
	std::cout << N * (N + 1) * 100 + 25;

	return 0;
}