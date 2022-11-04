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

	void add_or_delete_a_writter();
	void menu_add_or_delete_a_writter(short);
	void add_a_poet();
	void delete_a_poet();

	void add_or_delete_book();
	void menu_add_book(short);
	void add_book_poet();
	void delete_book_poet();
}
