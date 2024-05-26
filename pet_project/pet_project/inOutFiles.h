#pragma once

#include "ListOfTasks.h"
#include "stdafx.h"

// Сохраняем имена файлов в строковой постоянной 
const string finNameDefault ("save.tasks");
const string foutNameDefault("save.tasks");

// Попытка загрузить данные из файла
void loadFile(List&, string finName = finNameDefault);

// Попытка записать данные в файл
void saveFile(const List&, string foutName = foutNameDefault);