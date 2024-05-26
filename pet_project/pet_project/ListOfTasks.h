#pragma once

#include "Task.h"
#include "stdafx.h"

class List
{
private:
	static const char char_sep   = '\n';
	static const int  points_max = 100;
	static const int  points_min = 5;

	Box<Task>* first;  
	Box<Task>* getLast();

	void deleteNext(Box<Task>*);

public:

	// Возвращает число элементов списка
	int get_number_of_elements() const;

	// Возвращает число очков, распределенных по таскам 
	int get_points_total() const;

	// Возвращает число очков, которое осталось для зачисления
	int get_points_left() const
	{
		return get_points_max() - get_points_total();
	}

	// Возвращает максимальное число очков
	int get_points_max() const
	{
		return points_max;
	}

	// Возвращает минимальное число очков
	int get_points_min() const
	{
		return points_min;
	}

	// Пуст ли список?
	bool isEmpty()
	{
		return (first == nullptr);
	}

	/* Возвращает указатель на n-ый (нумерация с нуля) элемент списка. Если
	 список пуст или n больше, чем (число_элементов_в_списке - 1), то
	 возвращает указатель на нуль. */
	Box<Task>* getBoxByNumber(const int&);

	// Конструктор по умолчанию
	List()
	{
		first = nullptr;
	}

	// Конструктор копирования
	List(const List&); 

	/* Деструктор заботится об освобождении памяти в момент, когда объект
	List уничтожается */
	~List()
	{
		free();
	}

	// Функция, освобождающая память
	void free();

	// Добавление элемента типа Task в список
	void add(const Task&);

	/*Удаление из списка
	 * Подходящая реализация выбирается в зависимости от
	 * того, какой аргумент передаётся в функцию pop()
	 */
	void pop(const int &);
	void pop(Box<Task> *);

	// Вывод в бинарный файл и чтение из него
	void writeToFile (std::ofstream &) const;
	void readFromFile(std::ifstream &);

	/*
	 * Глубокое присваивание: элементы, для которых распределялась память,
	 * копируются, а не просто обзаводятся названием-указателем.
	 */
	List& operator=(const List&);

	// Дружественные функции: не являются членами класса, но имеют доступ к
	// тому, что объявлено в блоке private
	friend ostream & operator<<(ostream &, const List &);
	friend istream & operator>>(istream &, List &);

	// Считает число выполненных тасков и очков, полученных за их выполнение
	void countCompleted(int&, int&) const;

	// Функция для целей отладки
	void show();
};
