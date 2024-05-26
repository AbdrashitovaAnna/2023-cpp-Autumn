#pragma once

#include "Box.h"
#include "stdafx.h"


class Task
{
private:
	// Дата берётся системной
	time_t date;
	string text;
	int    points;
	bool   done;

public:

	Task(
		time_t _date    = std::time(nullptr),
		string _text    = "",
		int    _points  = 0,
		bool   _done    = false
	)
	{
		date   = _date;
		text   = _text;
		points = _points;
		done   = _done;
	}

	// Вывод даты в формате строки
	string get_date_formatted() const;

	time_t get_date() const
	{
		return date;
	}

	string get_text() const
	{
		return text;
	}

	int get_points() const
	{
		return points;
	}

	bool is_it_done() const
	{
		return done;
	}

	void set_date(const time_t& _date)
	{
		date = _date;
	}

	void set_text(const string& _text)
	{
		text = _text;
	}

	void set_points(const int& _points)
	{
		points = _points;
	}

	void set_done()
	{
		done = true;
	}

	void set_undone()
	{
		done = false;
	}

	void switch_done()
	{
		done = 1 xor done;
	}

	// Вывод в бинарный файл одного таска
	void writeToFile(std::ofstream &) const;

	// Ввод из бинарного файла одного таска
	void readFromFile(std::ifstream &);

	friend ostream & operator<<(ostream &, const Task &);
	friend istream & operator>>(istream &, Task &);

};
