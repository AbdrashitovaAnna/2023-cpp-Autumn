#pragma once

// Вспомогательная структура данных для построения списка
 

template <typename Any>
class Box
{
public:
	Any item;
	Box<Any> * next;

	Box()
	{
		next = nullptr;
	}
};