#include<iostream>
#include<string>

long long int degree(int number, int deg)
{
	long long int result = 1;
	result = 1;
	for (int i = 0; i < deg; ++i)
	{
		result = result * number;
	}
	return result;
}

int main(int argc, char* argv[])
{
	std::string result = "";
	long long int n = 0;
	std::cin >> n;

	char k = '0';
	long long int div = 0;
	std::string div_C = "A";

	for (int i = 0; i < 8; ++i)
	{
		div = (n / degree(16, (7 - i)));
		if (div > 9)
		{
			if (div == 10) { div_C = 'A'; }
			else if (div == 11) { div_C = 'B'; }
			else if (div == 12) { div_C = 'C'; }
			else if (div == 13) { div_C = 'D'; }
			else if (div == 14) { div_C = 'E'; }
			else if (div == 15) { div_C = 'F'; };
			result.append(div_C);
		}
		else
		{
			div_C = std::to_string(div);
			result.append(div_C);
		}
		n = n % degree(16, (7 - i));
	}

	std::string result_2 = "";

	for (int i = 0; i < result.length(); ++i)
	{
		result_2 += result[result.length() - i - 1];
	}

	std::cout << result_2 << std::endl;
	long long int result_3 = 0;

	for (int i = 0; i < result_2.length(); ++i)
	{
		if (result_2[i] == 'A')
		{
			div = 10; result_3 += div * degree(16, result_2.length() - i - 1);
		}
		else if (result_2[i] == 'B') { div = 11; result_3 += div * degree(16, result_2.length() - i - 1); }
		else if (result_2[i] == 'C') { div = 12; result_3 += div * degree(16, result_2.length() - i - 1); }
		else if (result_2[i] == 'D') { div = 13; result_3 += div * degree(16, result_2.length() - i - 1); }
		else if (result_2[i] == 'E') { div = 14; result_3 += div * degree(16, result_2.length() - i - 1); }
		else if (result_2[i] == 'F') { div = 15; result_3 += div * degree(16, result_2.length() - i - 1); }
		else
		{
			result_3 += ((int)result_2[i] - '0') * degree(16, result_2.length() - i - 1);
		}
	}
	std::cout << (result_3) << std::endl;


	return EXIT_SUCCESS;
}