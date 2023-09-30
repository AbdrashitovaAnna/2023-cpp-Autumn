#include <iostream>
int main() {
	int V = 0;
	int T = 0;
	int S1 = 0;
	int S2 = 0;
	std::cin >> V >> T;
	S1 = (V * T) % 109;
	S2 = ((S1 + 109) % 109) + 1;
	std::cout << S2;

	return 0;
}