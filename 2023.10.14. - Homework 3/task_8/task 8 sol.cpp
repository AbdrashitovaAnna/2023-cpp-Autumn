#include <iostream>

int main() {
	int a = 0;
	int b = 0;
	int n = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	char min = 'A', max = 'B';
	bool is_possible = false;
	if (b < a)
	{
		int temp1 = 0;
		temp1 = b;
		b = a;
		a = temp1;

		char temp2 = ' ';
		temp2 = min;
		min = max;
		max = temp2;
	}

	int limit = 100001;
	int a_current_volume = 0;
	int b_current_volume = 0;

	int k = 0;
	while (k <= limit)
	{
		k += 2;
		if (b - b_current_volume >= a)
		{
			b_current_volume += a;
			a_current_volume = 0;
		}
		else
		{
			k += 2;
			b_current_volume = a - (b - b_current_volume);
			a_current_volume = a - (b - b_current_volume);
		}
		if (n == b_current_volume || n == a_current_volume)
		{
			is_possible = true;
			break;
		}
	}

	a_current_volume = 0;
	b_current_volume = 0;

	if (is_possible)
	{
		b_current_volume = 0;

		while (true)
		{
			std::cout << '>' << min << std::endl;
			std::cout << min << '>' << max << std::endl;
			if (b - b_current_volume >= a)
			{
				b_current_volume += a;
				a_current_volume = 0;
				if (n == b_current_volume || n == a_current_volume)
					break;
			}
			else
			{
				b_current_volume = a - (b - b_current_volume);
				a_current_volume = b_current_volume;
				if (n == b_current_volume || n == a_current_volume)
					break;
				std::cout << max << '>' << std::endl;
				std::cout << min << '>' << max << std::endl;

			}

		}
	}
	else
		std::cout << "Impossible";

	return 0;
}