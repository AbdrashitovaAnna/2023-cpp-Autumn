#include<iostream>
#include<algorithm>

void printArray(int* a, int len);
void expandArray(int*& a, int& len);
void addElement(int*& a, int& len, int element);
void contractArray(int*& a, int& len);
bool indexValid(int index, int len);
void stdsort(int* a, int len);
int extractElement(int*& a, int& len, int index);
void printReverseArray(int* a, int len);
void printMenu();
void reverseArray(int*& a, int len);
void reverseMinMax(int*& a, int len);
void deleteDublicat(int*& a, int& len);


int main(int argc, char* argv[])
{
	int* a = nullptr;
	int len = 0;
	bool exit = false;
	while (!exit)
	{
		{
			system("cls");
			printMenu();
			printArray(a, len);
		}
		int choice = 0;
		{
			std::cin >> choice;
		}
		{
			switch (choice)
			{
			case 0:
				exit = true;
				break;
			case 1:
				printArray(a, len);
				system("pause");
				break;
			case 2:
			{
				int element = 0;
				std::cout << "Input element to add : ";
				std::cin >> element;
				addElement(a, len, element);
				break;
			}
			case 3:
			{
				int index = 0;
				std::cout << "Input index to extract : ";
				std::cin >> index;
				std::cout << "Extracted  " << extractElement(a, len, index) << std::endl;
				break;
			}
			case 4:
			{
				std::cout << "std::sort" << std::endl;
				stdsort(a, len);
				printArray(a, len);
				break;
			}
			case 5:
			{
				std::cout << "Reverse Array" << std::endl;
				reverseArray(a, len);
				break;
			}
			case 6:
			{
				reverseMinMax(a, len);
				break;
			}
			case 7:
			{
				deleteDublicat(a, len);
				break;
			}
			case 8:
			{
				int n = 0;
				std::cout << "Enter a number adding elements" << std::endl;
				std::cin >> n;
				for (int i = 0; i < n; i++)
				{
					addElement(a, len, std::rand() % 100);
				}
				break;
			}
			default:
				std::cout << "Unknown command" << std::endl;
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}

void printArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[i] << " ";
		}
	}
	std::cout << std::endl;
}

void expandArray(int*& a, int& len)
{
	int* newA = new int[len + 1]{ 0 };
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
	}
	a = newA;
	++len;
}

void addElement(int*& a, int& len, int element)
{
	expandArray(a, len);
	a[len - 1] = element;
}

void contractArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		int* newA = new int[len - 1]{ 0 };
		for (int i = 0; i < len - 1; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
		a = newA;
		--len;
	}
}

bool indexValid(int index, int len)
{
	return (index >= 0 && index < len);

}

int extractElement(int*& a, int& len, int index)
{
	int res = -1;
	if (indexValid(index, len))
	{
		res = a[index];
		for (int i = index; i < len - 1; ++i)
		{
			a[i] = a[i + 1];
		}
		contractArray(a, len);
	}
	return res;
}

void stdsort(int* a, int len)
{
	std::sort(a, a + len);
}

void printReverseArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[len - i - 1] << " ";
		}
	}
	std::cout << std::endl;
}

void reverseArray(int*& a, int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		int k = 0;
		k = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = k;
	}
}

int max(int* a, int len)
{
	int result = 0;
	for (int i = 1; i < len; i++)
	{
		if (a[result] < a[i])
		{
			result = i;
		}
	}
	return result;
}

int min(int* a, int len)
{
	int result = 0;
	for (int i = 1; i < len; i++)
	{
		if (a[result] > a[i])
		{
			result = i;
		}
	}
	return result;
}
void reverseMinMax(int*& a, int len)
{
	int k = 0;
	int MIN = min(a, len);
	int MAX = max(a, len);
	k = a[MAX];
	a[MAX] = a[MIN];
	a[MIN] = k;
}

void deleteDublicat(int*& a, int& len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int j = i + 1;
		while (true)
		{
			if (j < len)
			{
				if (a[i] == a[j])
				{
					extractElement(a, len, j);
				}
				else
				{
					j += 1;
				}
			}

			else
			{
				break;
			}
		}
	}
}

void printMenu()
{
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Print array" << std::endl;
	std::cout << "2 - Add element to array" << std::endl;
	std::cout << "3 - Extract element from array" << std::endl;
	std::cout << "4 - Sort the array in ascending order" << std::endl;
	std::cout << "5 - Reverse array" << std::endl;
	std::cout << "6 - Reverse first max and first min" << std::endl;
	std::cout << "7 - Delete dublicats" << std::endl;
	std::cout << "8 - Add n random elements" << std::endl;

}