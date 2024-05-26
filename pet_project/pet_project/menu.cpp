#include "menu.h"

/*
 * Когда пользователь вводит что-то и нажимает на  Enter,  происходит несколько
 * вещей. Введённая строка вместе с символом '\n' перехода на новую строку
 * загружается в буфер ввода того потока, который используется (если ввод шёл с
 * помощью  cin,  то в буфер  cin).  Из этого буфера происходит попытка считать
 * тот тип данных, который просят. Если это один символ, то читается _ровно
 * один символ_, а остальное остаётся в буфере. При следующем вводе читается не
 * то, что вводит пользователь, а _остаток буфера_. Если нужно, чтобы программа
 * прочитала ровно то, что ввели, тогда нужно освободить буфер. Это делается
 * так: мы считываем буфер посимвольно, пока не наткнёмся на символ '\n'.
 * Команда cin.get() выдаёт следующий прочитанный символ, а в условии цикла
 * проверяется, не дошли ли мы до конца строки.
 */

void flushInput()
{
	while (cin.get() != '\n')
		continue;
}

void enterText(Task& task)
{
	string str;
	cout << "Enter task's text (one line):\n";
	getline(cin, str);
	task.set_text(str);
}


void enterPoints(const List& currentList, Task& task)
{
	int points;
	bool isInputCorrect = false;

	while (!isInputCorrect)
	{
		cout << "Enter task's points (from "
			 << currentList.get_points_min()
			 << " to "
			 << currentList.get_points_left() + task.get_points()
			 << "): ";

		cin >> points;

		if ((points < currentList.get_points_min()) ||
			(points > currentList.get_points_left() + task.get_points()))
		{
			cout << "You can't assign this value." << endl;
			flushInput();
		}
		else
		{
			task.set_points(points);
			isInputCorrect = true;
		}
	}
}

int convertToInt(const char& c)
{
	return c + nullChar;
}

void enterDate()
{
	string dateString;
	int    dateArray[correctDateLength] = { 0 };
	bool   isInputCorrect = false;
	size_t currentNumber;
	int    currentArrayIndex = 0;

	while (!isInputCorrect)
	{
		cout << "Please, enter a date (dd/mm/yyyy): ";
		getline(cin, dateString);

		/*
		 * Проверка корректности ввода даты.
		 * Днём считаются первые два найденные числа,
		 * месяцем — вторые два,
		 * годом — четыре далее.
		 * Между этими числами может стоять любое количество любых символов.
		 */

		currentArrayIndex = 0;

		for (
			int i = 0;
			(i < dateString.length()) &&
			(currentArrayIndex < correctDateLength);
			++i
			)
		{
			currentNumber = Numbers.find(dateString[i]);
			if (currentNumber == string::npos)
				continue;
			else
			{
				dateArray[currentArrayIndex] = currentNumber;
				++currentArrayIndex;
			}
		}

		isInputCorrect = (currentArrayIndex == correctDateLength);

		if (isInputCorrect)
		{
			int day, month, year;

			day   = dateArray[0] * 10 + dateArray[1];
			month = dateArray[2] * 10 + dateArray[3];
			year  = dateArray[4] * 1000 +
					dateArray[5] * 100 +
					dateArray[6] * 10 +
					dateArray[7];
		}
		else
			cout << "Your input is wrong." << endl;
	}
}

void editTask(Box<Task> * taskbox, List & currentList)
{
	cout << "What would you like to do?" << endl
		 << "  1. Change task's state (done / undone)." << endl
		 << "  2. Change task's text." << endl
		 << "  3. Change task's points." << endl
		 << "  4. Delete task." << endl
		 << endl;

	char choice;
	choice = cin.get();
	flushInput();

	bool isInputCorrect = false;

	while (!isInputCorrect)
	{
		switch (choice)
		{
		case '1':
			taskbox->item.switch_done();
			isInputCorrect = true;
			break;

		case '2':
			enterText(taskbox->item);
			isInputCorrect = true;
			break;

		case '3':
			enterPoints(currentList, taskbox->item);
			flushInput();
			isInputCorrect = true;
			break;

		case '4':
			currentList.pop(taskbox);
			isInputCorrect = true;
			break;

		default:
			cout << "Please, enter correct value: ";
			choice = cin.get();

			break;
		}
	}
}

void deleteTask(const int& n, List& currentList)
{
	currentList.pop(n);
	return;
}

void addTask(List& currentList)
{
	if (currentList.get_points_left() < currentList.get_points_min())
	{
		cout << "You already have enough tasks for today :)" << endl;
		return;
	}

	Task task;

	enterText(task);
	enterPoints(currentList, task);

	currentList.add(task);

	return;
}

void listMenu(List& currentList, bool& exitFromLoop)
{
	cout << "Select an option:"         << endl
		 << "  1: add    task;"         << endl
		 << "  2: edit   task;"         << endl
		 << "  3: delete task;"         << endl
		 << "  s: save current list;"   << endl
		 << "  q: exit without saving." << endl;

	bool isInputCorrect = false;

	char choice;

	while (!isInputCorrect)
	{
		choice = cin.get();
		flushInput();

		switch (choice)
		{
		case '1':
			isInputCorrect = true;
			addTask(currentList);
			flushInput();
			break;

		case '2':
			isInputCorrect = true;

			if (currentList.isEmpty())
				cout << "List is empty." << endl;
			else
			{
				int n;
				cout << "Enter number of task to edit: ";
				cin >> n;
				flushInput();
				if ((n >= 0) && (n <= currentList.get_number_of_elements()))
					editTask(currentList.getBoxByNumber(n), currentList);
				else
					cout << "Your number is out of range!" << endl;
			}

			break;

		case '3':
			isInputCorrect = true;

			if (currentList.isEmpty())
				cout << "List is empty." << endl;
			else
			{
				int n;
				cout << "Enter number of task to delete: ";
				cin >> n;
				flushInput();
				if ((n >= 0) && (n <= currentList.get_number_of_elements()))
					deleteTask(n, currentList);
				else
					cout << "Your number is out of range!" << endl;
			}

			break;

		case 's':
			isInputCorrect = true;
			saveFile(currentList);
			break;

		case 'q':
			isInputCorrect = true;
			exitFromLoop   = true;
			break;

		default:
			cout << "Please, enter a correct input: ";
			break;
		}
	}

	return;
}

void showTasks(List& currentList)
{
	if (currentList.isEmpty())
		cout << "List is empty." << endl;
	else
	{
		cout << currentList << endl;

		int numberCompleted = 1;
		int pointsCompleted = 2;

		currentList.countCompleted(numberCompleted, pointsCompleted);

		cout << "Completed tasks: " << numberCompleted << endl
			 << "Total points:    " << pointsCompleted << endl;
	}
}

void greetings(List& currentList)
{
	clrscr();

	bool exitFromLoop = false;
	cout << "Hello! This is Task Manager." << endl;
	cout << "Here is the current list of your tasks." << endl << endl;

	loadFile(currentList);

	while (!exitFromLoop)
	{
		showTasks(currentList);
		cout << endl;
		listMenu(currentList, exitFromLoop);
		clrscr();
		cout << "Hello! This is Task Manager." << endl;
		cout << "Here is the current list of your tasks." << endl << endl;
	}

	clrscr();
}

// https://stackoverflow.com/questions/7911166/clearing-the-console-in-c 
#ifdef _WIN32 || _WIN64

void clrscr()
{
    HANDLE hStdOut;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // Fetch existing console mode so we correctly add a flag and not turn off others
    DWORD mode = 0;
    if (!GetConsoleMode(hStdOut, &mode))
    {
		return; //::GetLastError();
    }

    // Hold original mode to restore on exit to be cooperative with other command-line apps.
    const DWORD originalMode = mode;
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    // Try to set the mode.
    if (!SetConsoleMode(hStdOut, mode))
    {
		return;//::GetLastError();
    }

    // Write the sequence for clearing the display.
    DWORD written = 0;
    PCWSTR sequence = L"\x1b[2J";
    if (!WriteConsoleW(hStdOut, sequence, (DWORD)wcslen(sequence), &written, NULL))
    {
        // If we fail, try to restore the mode on the way out.
        SetConsoleMode(hStdOut, originalMode);
		return;//::GetLastError();
    }

    // To also clear the scroll back, emit L"\x1b[3J" as well.
    // 2J only clears the visible window and 3J only clears the scroll back.

    // Restore the mode on the way out to be nice to other command-line applications.
    SetConsoleMode(hStdOut, originalMode);
}

#else

void clrscr()
{
	write(1,"\E[H\E[2J",7);
}

#endif
