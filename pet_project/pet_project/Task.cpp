#include "Task.h"

// Вывод даты в формате строки
string Task::get_date_formatted() const
{
	/* std::size_t strftime(
	 *     char *          str,
	 *     std::size_t     count,
	 *     const char *    format,
	 *     const std::tm * tp
	 * )
	 *
	 * Преобразует информацию о дате и времени из заданного календарного времени
	 * tp в многобайтовую символьную строку str, заканчивающуюся нулем, в соответствии с
	 * форматированием, указанным в строке format. Записывается до count байт.
	 */

	char date_format[std::size("dd/mm/yyyy hh:mm")];

	std::strftime
	(
		std::data(date_format),
		std::size(date_format),
		"%d/%m/%Y %H:%M",
		// gmtime(&date)
		localtime(&date)
	);

	return date_format;

}

 // Вывод в бинарный файл одного таска
void Task::writeToFile(std::ofstream& ofs) const
{
	// (char*) &date:
	// берём данные по адресу  &date,  воспринимаем как строку, читаем из неё
	// ровно  sizeof(date)  символов и записываем их _как они есть_ в файл,
	// ассоциированный с потоком  ofs.
	ofs.write((char*) &date,   sizeof(date));
	ofs.write((char*) &points, sizeof(points));
	ofs.write((char*) &done,   sizeof(done));

	// Пишем сначала размер текста, а затем сам текст
	size_t text_size = text.size();
	ofs.write((char*) &text_size, sizeof(text_size));

	// Пишем не &text, а &text[0], так как нам нужна только строка,
	// а не весь объект  string  целиком (в  string  содержится не только сама
	// строка, но ещё и некоторая служебная информация, которая тоже занимает
	// место).
	ofs.write((char*) &text[0], text_size);

	return;
}

// Ввод из бинарного файла одного таска
void Task::readFromFile(std::ifstream & ifs)
{
	// Сначала читаем дату, затем — очки и флаг, сделано ли
	ifs.read((char*) &date,   sizeof(date));
	ifs.read((char*) &points, sizeof(points));
	ifs.read((char*) &done,   sizeof(done));

	// Затем читаем размер текста
	size_t text_size;
	ifs.read((char*) &text_size, sizeof(text_size));

	// Теперь размер текста (строки) лежит в переменной  text_size,  и
	// можно прочитать нужное количество байт текста. Для начала нужно
	// изменить размер строки  text;  в классе  string  есть метод
	// resize(size_t &) для этого:
	text.resize(text_size);
	ifs.read((char*) &text[0], text_size);

	return;
}

// Вывод (по смыслу — на консоль) таска в форматированном виде
ostream & operator<<(ostream & os, const Task & task)
{

	os << task.get_date_formatted() << '\t'
	   << task.get_points() << '\t'
	   << '[';

	if (task.is_it_done())
		os << '*';
	else
		os << ' ';
	os << ']' << '\t';

	os << task.get_text();

	return os;
};

// Ввод (по смыслу — с консоли) таска
std::istream & operator>>(istream & is, Task & task)
{
	time_t _date;
	string _text;
	int    _points;
	bool   _done;

	is >> _date >> _text >> _points >> _done;

	task.date   = _date;
	task.text   = _text;
	task.points = _points;
	task.done   = _done;

	return is;
}
