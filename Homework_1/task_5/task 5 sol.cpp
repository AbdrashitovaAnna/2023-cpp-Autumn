#include <iostream>
int main() {
	int v = 0;
	int t = 0;
	int s1 = 0;
	int s2 = 0;
	std::cin >> v >> t;
	s1 = (v * t) % 109;
	s2 = ((s1 + 109) % 109) + 1;
	std::cout << s2;

	return 0;
}