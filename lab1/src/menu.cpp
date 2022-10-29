#pragma once
#include "menu.h"
#include "Keeper.h"
namespace Menu {
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
		cout << "Добавить писателя\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "Удалить книгу поэта\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "Вывод книг поэта\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "Delete the last element\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "Delete by index\n";
		if (menu == 6)
			set_color(RED);
		else set_color(WHITE);
		cout << "Out keeper\n";
		if (menu == 7)
			set_color(RED);
		else set_color(WHITE);
		cout << "Change\n";
		if (menu == 8)
			set_color(RED);
		else set_color(WHITE);
		cout << "Clear\n";
		if (menu == 9)
			set_color(RED);
		else set_color(WHITE);
		cout << "Save to file\n";
		if (menu == 10)
			set_color(RED);
		else set_color(WHITE);
		cout << "Extract from file\n";
		if (menu == 11)
			set_color(RED);
		else set_color(WHITE);
		cout << "Exit\n" << endl;
	}
	
	void menu() {
		//test zone
		Keeper k;
		/*string new_name_books[2] = {"1Kniga", "2Kniga"};
		Poet new_p("Semyon", 2002, 2160, new_name_books, 2);
		k.add_poet(new_p);

		k.Save();*/
		k.Read();

		//
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
				case 1: //add a book
					break;
				case 2: //add a textbook
					break;
				case 3: //add a chancellery
					break;
				case 4: //Delete the last element
					break;
				case 5: //Delete by index
					break;
				case 6: //Out keepe
					break;
				case 7: //Change
					break;
				case 8: //Clear
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
}
