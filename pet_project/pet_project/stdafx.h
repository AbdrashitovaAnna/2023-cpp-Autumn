#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <ctime>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::time_t;
using std::getline;

const string Numbers = "0123456789";

// Число цифровых знаков в корректной дате
const short correctDateLength = 8;

// Для очистки экрана
// https://stackoverflow.com/questions/7911166/clearing-the-console-in-c 

// Если текущая операционная система — Windows, то подключаем windows.h;
// Если ОС другая, подключаем unistd.h
#ifdef _WIN32 || _WIN64
#include <windows.h>
#else
#include <unistd.h>
#endif
