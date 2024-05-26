#pragma once

#include "stdafx.h"
#include "Box.h"
#include "Task.h"
#include "ListOfTasks.h"
#include "inOutFiles.h"

const char nullChar = '0';

void flushInput();
void enterText(Task &);
void enterPoints(const List &, Task &);
int convertToInt(const char & c);
void enterDate();
void editTask(Box<Task> *, List &);
void deleteTask(const int &, List &);
void addTask(List &);
void listMenu(List &, bool &);
void showTasks(List &);
void greetings(List &);
void clrscr();
