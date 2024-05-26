#include "ListOfTasks.h"

// Функция, которая возвращает указатель на последний элемент
Box<Task> * List::getLast()
{
	Box<Task> * temp = first;
	while (temp->next != nullptr)
		temp = temp->next;

	return temp;
}

// Возвращает число элементов списка
int List::get_number_of_elements() const
{
	int num = 0;

	Box<Task> * temp = first;
	while (temp != nullptr)
	{
		++num;
		temp = temp->next;
	}

	return num;
}

// Возвращает число очков, которые уже раскиданы по таскам
int List::get_points_total() const
{
	Box<Task> * temp = first;

	int sum = 0;
	while (temp != nullptr)
	{
		sum += temp->item.get_points();
		temp = temp->next;
	}

	return sum;
}

// Возвращает указатель на n-ый (нумерация с нуля) элемент списка. Если
// список пуст или n больше, чем (число элементов в списке - 1), то
// возвращает указатель на нуль.
Box<Task> * List::getBoxByNumber(const int & n)
{
	Box<Task> * temp = first;
	for (int i = 0; (temp != nullptr) && (i < n); ++i)
		temp = temp->next;

	return temp;
}

// Конструктор копирования
List::List(const List & L)
{
	// Делаем действия, предполагаемые по умолчанию
	first = nullptr;

	Box<Task> * temp = L.first;
	while (temp != nullptr)
	{
		add(temp->item);
		temp = temp->next;
	}
}

// Функция, освобождающая память
void List::free()
{
	if (isEmpty())
		return;

	Box<Task> * temp = first;
	while (temp != nullptr)
	{
		// cout << "Element at addr " << temp << endl;
		first = first->next;
		delete temp;
		temp = first;
	}

	first = nullptr;
}

// Добавление элемента типа Task в список
void List::add(const Task & _item)
{
	Box<Task> * temp = new Box<Task>;
	temp->item = _item;
	temp->next = nullptr;

	if (isEmpty())
		first = temp;
	else
		getLast()->next = temp;

	// cout << "element added" << endl;
}

// Вытолкнуть следующий элемент списка (это функция, предназначенная для
// «внутреннего» использования другими методами класса, поэтому живёт в
// блоке private)
void List::deleteNext(Box<Task>* prev)
{
	if (prev == nullptr)
		return;

	if (prev->next != nullptr)
	{
		Box<Task> * popping = prev->next;
		/*
		   cout << "prev          = " << prev << endl
		   << "popping       = " << popping << endl
		   << "popping->next = " << popping->next << endl
		   << endl;
		   */

		// Очевидный (неочевидный?) переход
		if (popping->next != nullptr)
			prev->next = popping->next;
		else
			prev->next = nullptr;

		// Освобождаем место по указателю popping
		delete popping;
	}
	else
		return;
}

// Удаление из списка элемента по номеру
void List::pop(const int & k = 0)
{
	Box<Task> * temp = first;

	// Если выкидываем начальный элемент, то нужно переместить указатель на
	// первый элемент
	if (k == 0)
	{
		first = first->next;
		delete temp;
		return;
	}

	// Идём до (k-1)-го элемента списка, чтобы перебросить его указатель
	// next с элемента номер k на элемент номер k+1 (если он существует).
	int i = 0;
	while ((temp != nullptr) && (i < k - 1))
	{
		temp = temp->next;
		++i;
	}

	// Сейчас temp — (k-1)-ый элемент списка или nullptr. Если temp ==
	// nullptr, то делать нечего.

	deleteNext(temp);
}

// Удаление из списка элемента по указателю
void List::pop(Box<Task> * box)
{
	if (first == nullptr)
		return;

	Box<Task> * temp = first;

	if (first == box)
	{
		first = first->next;
		delete temp;
		return;
	}

	while ((temp != nullptr) && (temp->next != box))
		temp = temp->next;

	deleteNext(temp);
}

// Так наызваемое глубокое присваивание: элементы, для которых
// распределялась память, _копируются_, а не просто обзаводятся
// псевдонимом-указателем.
List & List::operator=(const List & B)
{
	free();
	first = nullptr;

	Box<Task> * temp = B.first;
	while (temp != nullptr)
	{
		add(temp->item);
		temp = temp->next;
	}

	return *(this);
}

// Вывод в бинарный файл
void List::writeToFile (std::ofstream & ofs) const
{
	// Сначала выводим число элементов списка, чтобы, когда будем читать,
	// знать, сколько элементов списка читать
	int numberOfElements = get_number_of_elements();

	// Пишем посчитанное число тем же образом, что и остальные данные —
	// воспринимаем указатель на начало переменной как указатель на char и
	// пишем столько байт, какова длина этой переменной в байтах
	ofs.write((char *) &numberOfElements, sizeof(numberOfElements));

	// Далее идём по списку и пишем каждый из тасков

	Box<Task> * temp = first;

	for (int i = 0; i < numberOfElements; ++i)
	{
		temp->item.writeToFile(ofs);
		temp = temp->next;
	}

	return;
}

// Ввод из бинарного файла
void List::readFromFile(std::ifstream & ifs)
{
	// Сначала читаем число элементов списка: дело в том, что если читать
	// список просто до тех пор, пока читается, то чтение будет происходить и
	// после окончания файла — флаг eof (end of file) почему-то не
	// устанавливается при таком способе чтения и записи
	int numberOfElements = 0;
	ifs.read((char *) &numberOfElements, sizeof(numberOfElements));

	Task task;

	// Читаем по одному таску из файла, пока не считаем все numberOfElements
	// элементов
	for (int i = 0; i < numberOfElements; ++i)
	{
		task.readFromFile(ifs);
		add(task);
	}


	return;
}

// Дружественная функция
// Вывод на экран
ostream & operator<<(ostream & os, const List & L)
{
	os << "n\tdate       time\t\tpoints\tdone\tdescription" << endl;

	int k = 0;
	Box<Task> * temp = L.first;

	while (temp != nullptr)
	{
		os << k << '\t';
		++k;

		os << temp->item << List::char_sep;
		temp = temp->next;
	}

	return os;
}

// Дружественная функция
// Ввод с консоли
istream & operator>>(istream & is, List & L)
{
	L.free();
	Task temp;
	while (is >> temp)
	{
		L.add(temp);
	}

	return is;
}

// Функция для целей отладки
void List::show()
{
	if (isEmpty())
		return;

	int n = 0;
	Box<Task> * temp = first;
	cout << "num\taddress\t\titem" << endl;
	while (temp != nullptr)
	{
		cout << n << '\t' << temp << '\t' << temp->item << endl;
		temp = temp->next;
		++n;
	}
	cout << endl;
}

// Считает число выполненных тасков
void List::countCompleted(int & numberCompleted, int & pointsCompleted) const
{
	numberCompleted = 0;
	pointsCompleted = 0;

	// Идём по списку и считаем те элементы, которые выполнены.
	Box<Task> * temp = first;
	while (temp != nullptr)
	{
		if (temp->item.is_it_done())
		{
			++numberCompleted;
			pointsCompleted += temp->item.get_points();
		}
		temp = temp->next;
	}

	return;
}
