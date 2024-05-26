#include "inOutFiles.h"

// Создаём потоки ввода и вывода (они пока не ассоциированы ни с какими
// файлами)
std::ifstream fin;
std::ofstream fout;

void loadFile(List& currentList, string finName)
{
	// Поток fin: попытка открыть файл с именем  finName  для записи; режим —
	// бинарный файл
	fin.open(finName, std::ios_base::in | std::ios_base::binary);

	// Если файл не открыт или файл не найден
	if (!fin.is_open())
	{
		cout << "Settings file \""
			 << finName
			 << "\" not found; we start from scratch."
			 << endl;

		currentList.free();
	}
	else
		// Иначе, если файл открыт, загрузить из него список в L
		currentList.readFromFile(fin);

	// Закрываем файл
	fin.close();

	return;
}

// Попытка записать настройки
void saveFile(const List& currentList, string foutName)
{

	// Поток fout: nопытка открыть файл с именем  foutName для записи; режим —
	// бинарный файл. По умолчанию файл  foutName  перезаписывается
	fout.open(foutName, std::ios_base::out | std::ios_base::binary);

	// Если файл не открыт или файл не найден
	if (!fout.is_open())
		cout << "Cannot open the file \""
			 << foutName
			 << "\" for writing."
			 << endl;
	else
	{
		currentList.writeToFile(fout);
		fout.close();
	}

	return;
}
