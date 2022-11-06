#pragma once
#include "menu.h"
namespace Menu {
	keeper k;

	void set_color(WORD color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
	enum colors {
		RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
		WHITE = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED
	};
	void menu_output(short menu) {
		set_color(WHITE);
		system("cls");

		cout << endl << "====================================\n\n";
		if (menu == 1)
			set_color(RED);
		else set_color(WHITE);
		cout << "Добавить или удалить писателя\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "добавить книгу в список произведений или удалить её\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "Вывести писателя\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "изменить данные\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "сохранить данные\n";
		if (menu == 6)
			set_color(RED);
		else set_color(WHITE);
		cout << "прочитать данные\n";
		if (menu == 7)
			set_color(RED);
		else set_color(WHITE);
		cout << "ненужная строка\n";
		if (menu == 8)
			set_color(RED);
		else set_color(WHITE);
		cout << "ненужная строка\n";
		if (menu == 9)
			set_color(RED);
		else set_color(WHITE);
		cout << "ненужная строка\n";
		if (menu == 10)
			set_color(RED);
		else set_color(WHITE);
		cout << "ненужная строка\n";
		if (menu == 11)
			set_color(RED);
		else set_color(WHITE);
		cout << "Exit\n" << endl;
	}

	void menu() {
		//test zone
		//Keeper k;

		//k.Save();
		//


		k.Read();
		menu_output(1);
		char key_tmp; //временный символ
		char key; //опция
		short func = 1; //запуск функции
		bool ENTER_;
		bool exit = false;

		while (!exit) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			//управление меню
			switch (key) {
			case 80: //вниз
				func++;
				if (func > 11)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 11;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			int del_id;

			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //добавить или удалить писателя
					add_or_delete_a_writter();
					break;
				case 2: //добавить книгу в список произведений
					add_or_delete_book();
					break;
				case 3: //вывод писателя(писателей)
					print_writter();
					break;
				case 4: //изменение данных
					change_data();
					break;
				case 5: //сохранить данные
					k.Save();
					break;
				case 6: // прочитать данные
					k.Read();
					break;
				case 7: 
					break;
				case 8: //
					break;
				case 9: //Save to file
					break;
				case 10: //Extract from file
					break;
				case 11: //Exit
					exit = true;
					break;
				}
			}

			menu_output(func);
		}
	}
	void add_or_delete_a_writter()
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;

		menu_add_or_delete_a_writter(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;


			switch (key) {
			case 80: //вниз
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			//TODO: потестить
			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //Добавить поэта
					cout << "Введите ФИО поэта, его год рождения, год смерти и одно его произведение (позднее сможете добавить ещё произведения)" << endl;
					add_a_poet();
					return;
				case 2: //Добавить романиста
					break;
				case 3: //Добавить фантаста
					break;
				case 4: //Удалить поэта
					cout << "Введите id поэта для удаления" << endl;
					delete_a_poet();
					return;
				case 5: //Удалить романиста
					break;
				case 6: //Удалить фантаста
					break;
				case 7: //Назад
					return;

				}
			}
			menu_add_or_delete_a_writter(func);
		}
	}


	void menu_add_or_delete_a_writter(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "====================================\n\n";
		if (menu == 1)
			set_color(RED);
		else set_color(WHITE);
		cout << "Добавить поэта\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "Добавить романиста\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "Добавить фантаста\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "Удалить фантаста\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "Удалить поэта\n";
		if (menu == 6)
			set_color(RED);
		else set_color(WHITE);
		cout << "Удалить романиста\n";
		if (menu == 7)
			set_color(RED);
		else set_color(WHITE);
		cout << "Назад\n";
	}
	void add_a_poet()
	{
		string fullname;
		int year_of_birth, year_of_death;
		string* books = new string[1];
		cin >> fullname;
		cin >> year_of_birth;
		cin >> year_of_death;
		cin >> books[0];
		Poet p(fullname, year_of_birth, year_of_death, books, 1);
		k.add_poet(p);
	}
	void delete_a_poet()
	{
		int id;
		cin >> id;
		k.delete_poet(id);
	}
	void add_or_delete_book()
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;

		menu_add_book(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;


			switch (key) {
			case 80: //вниз
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			//TODO: потестить
			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //Добавить книгу поэта
					add_book_poet();
					return;
				case 2: //Добавить книгу романиста
					break;
				case 3: //Добавить книгу фантаста
					break;
				case 4: //Удалить книгу поэта

					return;
				case 5: //Удалить книгу романиста
					break;
				case 6: //Удалить книгу фантаста
					break;
				case 7: //Назад
					return;

				}
			}
			menu_add_book(func);
		}
	}
	void menu_add_book(short menu)
	{
			set_color(WHITE);
			system("cls");

			cout << endl << "====================================\n\n";
			if (menu == 1)
				set_color(RED);
			else set_color(WHITE);
			cout << "Добавить книгу поэту\n";
			if (menu == 2)
				set_color(RED);
			else set_color(WHITE);
			cout << "Добавить книгу романисту\n";
			if (menu == 3)
				set_color(RED);
			else set_color(WHITE);
			cout << "Добавить книгу фантасту\n";
			if (menu == 4)
				set_color(RED);
			else set_color(WHITE);
			cout << "Удалить книгу поэту\n";
			if (menu == 5)
				set_color(RED);
			else set_color(WHITE);
			cout << "Удалить книгу романисту\n";
			if (menu == 6)
				set_color(RED);
			else set_color(WHITE);
			cout << "Удалить книгу фантасту\n";
			if (menu == 7)
				set_color(RED);
			else set_color(WHITE);
			cout << "Назад\n";
	}
	void add_book_poet()
	{
		string new_book;
		cout << "Введите название книги" << endl;
		cin >> new_book;
		k.add_book_poet(new_book);
	}
	void delete_book_poet()
	{
		k.delete_book_poet();
	}


	void print_writter()
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;
		int id;

		menu_print_writter(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;


			switch (key) {
			case 80: //вниз
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			//TODO: потестить
			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //Вывести поэта по id
					cout << "Введите id" << endl;
					cin >> id;
					k.print_poet(id);
					cout << "Нажмите ENTER чтобы продолжить продолжить!" << endl;
					_getch(); 
					return;
				case 2: //Вывести романиста по id
					cin >> id;
					break;
				case 3: //Вывести фантаста по id
					cin >> id;
					break;
				case 4: //Вывести всех поэтов
					k.print_poet();
					cout << "Нажмите ENTER чтобы продолжить продолжить!" << endl;
					_getch();
					return;
				case 5: //Вывести всех романистов
					break;
				case 6: //Вывести всех фантастов
					break;
				case 7: //Вывести всех писателей
					break;
				case 8:
					return;
				}
			}
			menu_print_writter(func);
		}
	}
	void menu_print_writter(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "====================================\n\n";
		if (menu == 1)
			set_color(RED);
		else set_color(WHITE);
		cout << "Вывод поэта по id\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "Вывод романиста по id\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "Вывод фантаста по id\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "Вывод всех поэтов\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "Вывод всех романистов\n";
		if (menu == 6)
			set_color(RED);
		else set_color(WHITE);
		cout << "Вывод всех фантастов\n";
		if (menu == 7)
			set_color(RED);
		else set_color(WHITE);
		cout << "Вывод всех писателей\n";
		if (menu == 8)
			set_color(RED);
		else set_color(WHITE);
		cout << "Назад\n";
	}
	void change_data()
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;
		int id;

		menu_change_data(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			switch (key) {
			case 80: //вниз
				func++;
				if (func > 4)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 4;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			//TODO: потестить
			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //Изменить данные поэта по id
					cout << "Введите id" << endl;
					cin >> id;
					change_p(k.get_poet(id));
					return;
				case 2: //Изменить данные романиста по id
					cout << "Введите id" << endl;
					cin >> id;
					break;
				case 3: //Изменить данные фантаста по id
					cout << "Введите id" << endl;
					cin >> id;
					break;
				case 4: //Вывести всех поэтов
					return;
				}
			}
			menu_change_data(func);
		}
	}
	void menu_change_data(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "====================================\n\n";
		if (menu == 1)
			set_color(RED);
		else set_color(WHITE);
		cout << "Изменить данные поэта по id\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "Изменить данные романиста по id\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "Изменить данные фантаста по id\n";
		
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "Назад\n";
	}
	void change_p(Poet poet)
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;
		string fullname;
		int year_of_birth;
		int year_of_death;
		string book;
		int id;
		menu_change_p(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			switch (key) {
			case 80: //вниз
				func++;
				if (func > 5)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 5;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			//TODO: потестить
			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //Изменить данные поэта по id
					cout << "Введите новое ФИО" << endl;
					cin >> fullname;
					poet.set_fullname(fullname);
					return;
				case 2: //Изменить данные романиста по id
					cout << "Введите новую дату рождения" << endl;
					cin >> year_of_birth;
					poet.set_years_of_birth(year_of_birth);
					break;
				case 3: //Изменить данные фантаста по id
					cout << "Введите новую дату смерти" << endl;
					cin >> year_of_death;
					poet.set_years_of_death(year_of_death);
					break;
				case 4:
					cout << "Введите id книги, которую хотите изменить" << endl;
					cin >> id;
					cout << "Введите название нового произведения" << endl;
					cin >> book;
					poet.set_book(book, id);
					return;
				case 5: //Вывести всех поэтов
					return;
				}
			}
			menu_change_p(func);
		}
	}
	void menu_change_p(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "====================================\n\n";
		if (menu == 1)
			set_color(RED);
		else set_color(WHITE);
		cout << "Изменить ФИО\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "Изменить год рождения\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "Изменить год смерти\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "Изменить произведение\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "Назад\n";

	}
}