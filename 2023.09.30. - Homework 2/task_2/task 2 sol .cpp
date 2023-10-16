#include <iostream>

int main() {
	int s = 0;
	int d = 0;
	std::cin >> s >> d;
	if (s == 1 && d == 1) {
		std::cout << "YES";
	}
	else if (s != 1 && d != 1) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}

	return EXIT_SUCCESS;
}