#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Keeper.h"

using namespace std;

namespace Menu {
	void menu_output(short); //отрисовка меню
	void set_color(WORD color);
	enum colors_;
	void menu();

	void add_a_writter();
	void menu_add_a_writter(short);
}
