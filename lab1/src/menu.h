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

	//добавление и удаление писателей
	void add_or_delete_a_writter();
	void menu_add_or_delete_a_writter(short);
	void add_a_poet();
	void delete_a_poet();

	void add_a_novelist();
	void delete_a_novelist();

	void add_a_fantast();
	void delete_a_fantast();

	//добавление и удаление книг
	void add_or_delete_book();
	void menu_add_book(short);

	void add_book_poet();
	void delete_book_poet();

	void add_book_novelist();
	void delete_book_novelist();

	void add_book_fantast();
	void delete_book_fantast();

	//вывод писателя
	void print_writter();
	void menu_print_writter(short);

	//изменение данных
	void change_data();
	void menu_change_data(short);
	void change_p(Poet);
	void menu_change_p(short);
	void change_n(Novelist);
	void menu_change_n(short);
	void change_f(Fantasist);
	void menu_change_f(short);

}
