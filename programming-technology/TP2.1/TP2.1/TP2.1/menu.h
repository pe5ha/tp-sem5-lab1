#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

namespace Menu {
	void menu_output(short); //отрисовка меню
	void set_color(WORD color);
	enum colors_;
	void menu();
}
