#pragma once
#include "menu.h"
namespace Menu {
	keeper k;
	bool isRead = false;

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
		cout << "�������� ��� ������� ��������\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ����� � ������ ������������ ��� ������� �\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "������� ��������\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ������\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "��������� ������\n";
		if (menu == 6)
			set_color(RED);
		else set_color(WHITE);
		cout << "��������� ������\n";
		if (menu == 7)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ������\n";
		if (menu == 8)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ������\n";
		if (menu == 9)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ������\n";
		if (menu == 10)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ������\n";
		if (menu == 11)
			set_color(RED);
		else set_color(WHITE);
		cout << "Exit\n" << endl;
	}

	void menu() {
		menu_output(1);
		char key_tmp; //��������� ������
		char key; //�����
		short func = 1; //������ �������
		bool ENTER_;
		bool exit = false;

		while (!exit) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			//���������� ����
			switch (key) {
			case 80: //����
				func++;
				if (func > 11)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 11;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			int del_id;

			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� ��� ������� ��������
					add_or_delete_a_writter();
					break;
				case 2: //�������� ����� � ������ ������������
					add_or_delete_book();
					break;
				case 3: //����� ��������(���������)
					print_writter();
					break;
				case 4: //��������� ������
					change_data();
					break;
				case 5: //��������� ������
					k.Save();
					cout << "������ ���������" << endl;
					_getch();
					break;
				case 6: // ��������� ������
					if (!isRead)
					k.Read();
					cout << "������ ����������" << endl;
					_getch();
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
		char key_tmp; //��������� ������
		char key; //�����
		bool ENTER_;
		short func = 1;
		bool exit = false;

		menu_add_or_delete_a_writter(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;


			switch (key) {
			case 80: //����
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			//TODO: ���������
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� �����
					cout << "������� ��� �����, ��� ��� ��������, ��� ������ � ���� ��� ������������ (������� ������� �������� ��� ������������)" << endl;
					add_a_poet();
					return;
				case 2: //�������� ���������
					cout << "������� ��� ���������, ��� ��� ��������, ��� ������ � ���� ��� ������������ (������� ������� �������� ��� ������������), ������� ���������" << endl;
					add_a_novelist();
					break;
				case 3: //�������� ��������
					cout << "������� ��� �������� � ���� ��� ������������ (������� ������� �������� ��� ������������), 1 - ���� ���� �����, 0 ���� �� ����" << endl;
					add_a_fantast();
					break;
				case 4: //������� �����
					cout << "������� id ����� ��� ��������" << endl;
					delete_a_poet();
					return;
				case 5: //������� ���������
					cout << "������� id ����� ��� ��������" << endl;
					delete_a_novelist();
					break;
				case 6: //������� ��������
					cout << "������� id ����� ��� ��������" << endl;
					delete_a_fantast();
					break;
				case 7: //�����
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
		cout << "�������� �����\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ���������\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ��������\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "������� ��������\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "������� �����\n";
		if (menu == 6)
			set_color(RED);
		else set_color(WHITE);
		cout << "������� ���������\n";
		if (menu == 7)
			set_color(RED);
		else set_color(WHITE);
		cout << "�����\n";
	}
	void add_a_poet()
	{
		string fullname;
		int year_of_birth, year_of_death;
		string* books = new string[1];
		getline(cin, fullname);
		cin >> year_of_birth;
		cin >> year_of_death;
		getline(cin, books[0]);
		getline(cin, books[0]);
		Poet p(fullname, year_of_birth, year_of_death, books, 1);
		k.add_poet(p);
	}
	void delete_a_poet()
	{
		int id;
		cin >> id;
		k.delete_poet(id);
	}
	void add_a_novelist()
	{
		string fullname;
		int year_of_birth, year_of_death;
		string* books = new string[1];
		string biography;
		getline(cin, fullname);
		cin >> year_of_birth;
		cin >> year_of_death;
		getline(cin, books[0]);
		getline(cin, books[0]);
		getline(cin, biography);
		Novelist n(fullname, year_of_birth, year_of_death, books, 1, biography);
		k.add_novelist(n);
	}
	void delete_a_novelist()
	{
		int id;
		cin >> id;
		k.delete_novelist(id);
	}
	void add_a_fantast()
	{
		string fullname;
		string* books = new string[1];
		string isFilmed;
		getline(cin, fullname);
		getline(cin, books[0]);
		getline(cin, isFilmed);
		int IF = stoi(isFilmed);
		Fantast f(fullname,books, 1, IF);
		k.add_fantast(f);
	}
	void delete_a_fantast()
	{
		int id;
		cin >> id;
		k.delete_fantast(id);
	}
	void add_or_delete_book()
	{
		char key_tmp; //��������� ������
		char key; //�����
		bool ENTER_;
		short func = 1;
		bool exit = false;

		menu_add_book(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;


			switch (key) {
			case 80: //����
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			//TODO: ���������
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� ����� �����
					add_book_poet();
					return;
				case 2: //�������� ����� ���������
					add_book_novelist();
					break;
				case 3: //�������� ����� ��������
					add_book_fantast();
					break;
				case 4: //������� ����� �����
					delete_book_poet();
					return;
				case 5: //������� ����� ���������
					delete_book_novelist();
					break;
				case 6: //������� ����� ��������
					delete_book_fantast();
					break;
				case 7: //�����
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
		cout << "�������� ����� �����\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ����� ���������\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ����� ��������\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "������� ����� �����\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "������� ����� ���������\n";
		if (menu == 6)
			set_color(RED);
		else set_color(WHITE);
		cout << "������� ����� ��������\n";
		if (menu == 7)
			set_color(RED);
		else set_color(WHITE);
		cout << "�����\n";
	}
	void add_book_poet()
	{
		string new_book; string idStr; int id;
		cout << "������� �������� ����� � id ����� ����� ENTER" << endl;
		getline(cin, new_book);
		getline(cin, idStr);
		id = stoi(idStr);
		k.add_book_poet(new_book, id);
	}
	void delete_book_poet()
	{
		int id;
		cout << "������� id" << endl;
		cin >> id;
		k.delete_book_poet(id);
	}

	void add_book_novelist()
	{
		string new_book; string idStr; int id;
		cout << "������� �������� ����� � id ��������� ����� ENTER" << endl;
		getline(cin, new_book);
		getline(cin, idStr);
		id = stoi(idStr);
		k.add_book_novelist(new_book, id);
	}

	void delete_book_novelist()
	{
		int id;
		cout << "������� id" << endl;
		cin >> id;
		k.delete_book_novelist(id);
	}

	void add_book_fantast()
	{
		string new_book; string idStr; int id;
		cout << "������� �������� ����� � id �������� ����� ENTER" << endl;
		getline(cin, new_book);
		getline(cin, idStr);
		id = stoi(idStr);
		k.add_book_fantast(new_book, id);
	}

	void delete_book_fantast()
	{
		int id;
		cout << "������� id" << endl;
		cin >> id;
		k.delete_book_fantast(id);
	}


	void print_writter()
	{
		char key_tmp; //��������� ������
		char key; //�����
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
			case 80: //����
				func++;
				if (func > 8)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 8;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			//TODO: ���������
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //������� ����� �� id
					cout << "������� id" << endl;
					cin >> id;
					k.print_poet(id);
					cout << "������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					return;
				case 2: //������� ��������� �� id
					cout << "������� id" << endl;
					cin >> id;
					k.print_novelist(id);
					cout << "������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 3: //������� �������� �� id
					cout << "������� id" << endl;
					cin >> id;
					k.print_fantast(id);
					cout << "������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 4: //������� ���� ������
					k.print_poet();
					cout << "������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					return;
				case 5: //������� ���� ����������
					k.print_novelist();
					cout << "������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 6: //������� ���� ���������
					k.print_fantast();
					cout << "������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 7: //������� ���� ���������
					k.print_all();
					cout << "������� ENTER ����� ���������� ����������!" << endl;
					_getch();
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
		cout << "����� ����� �� id\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "����� ��������� �� id\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "����� �������� �� id\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "����� ���� ������\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "����� ���� ����������\n";
		if (menu == 6)
			set_color(RED);
		else set_color(WHITE);
		cout << "����� ���� ���������\n";
		if (menu == 7)
			set_color(RED);
		else set_color(WHITE);
		cout << "����� ���� ���������\n";
		if (menu == 8)
			set_color(RED);
		else set_color(WHITE);
		cout << "�����\n";
	}
	void change_data()
	{
		char key_tmp; //��������� ������
		char key; //�����
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
			case 80: //����
				func++;
				if (func > 4)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 4;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			//TODO: ���������
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� ������ ����� �� id
					cout << "������� id" << endl;
					cin >> id;
					change_p(k.get_poet(id));
					return;
				case 2: //�������� ������ ��������� �� id
					cout << "������� id" << endl;
					cin >> id;
					change_n(k.get_novelist(id));
					break;
				case 3: //�������� ������ �������� �� id
					cout << "������� id" << endl;
					cin >> id;
					change_f(k.get_fantast(id));
					break;
				case 4: //������� ���� ������
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
		cout << "�������� ������ ����� �� id\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ������ ��������� �� id\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ������ �������� �� id\n";

		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "�����\n";
	}
	void change_p(Poet poet)
	{
		char key_tmp; //��������� ������
		char key; //�����
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
			case 80: //����
				func++;
				if (func > 5)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 5;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			//TODO: ���������
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� ������ ����� �� id
					cout << "������� ����� ���" << endl;
					cin >> fullname;
					poet.set_fullname(fullname);
					return;
				case 2: //�������� ������ ��������� �� id
					cout << "������� ����� ���� ��������" << endl;
					cin >> year_of_birth;
					poet.set_years_of_birth(year_of_birth);
					break;
				case 3: //�������� ������ �������� �� id
					cout << "������� ����� ���� ������" << endl;
					cin >> year_of_death;
					poet.set_years_of_death(year_of_death);
					break;
				case 4:
					cout << "������� id �����, ������� ������ ��������" << endl;
					cin >> id;
					cout << "������� �������� ������ ������������" << endl;
					cin >> book;
					poet.set_book(book, id);
					return;
				case 5: //������� ���� ������
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
		cout << "�������� ���\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ��� ��������\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ��� ������\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ������������\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "�����\n";

	}
	void change_n(Novelist novelist)
	{
		char key_tmp; //��������� ������
		char key; //�����
		bool ENTER_;
		short func = 1;
		bool exit = false;
		string fullname;
		int year_of_birth;
		int year_of_death;
		string book;
		int id;
		string bio;
		menu_change_n(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			switch (key) {
			case 80: //����
				func++;
				if (func > 5)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 5;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			//TODO: ���������
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� ������ ����� �� id
					cout << "������� ����� ���" << endl;
					cin >> fullname;
					novelist.set_fullname(fullname);
					break;
				case 2: //�������� ������ ��������� �� id
					cout << "������� ����� ���� ��������" << endl;
					cin >> year_of_birth;
					novelist.set_years_of_birth(year_of_birth);
					break;
				case 3: //�������� ������ �������� �� id
					cout << "������� ����� ���� ������" << endl;
					cin >> year_of_death;
					novelist.set_years_of_death(year_of_death);
					break;
				case 4:
					cout << "������� id �����, ������� ������ ��������" << endl;
					cin >> id;
					cout << "������� �������� ������ ������������" << endl;
					cin >> book;
					novelist.set_book(book, id);
					break;
				case 5:
					cout << "������� ����� ��������� ��� ���������" << endl;
					cin >> bio;
					break;
				case 6:
					return;
				}
			}
			menu_change_n(func);
		}
	}
	void menu_change_n(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "====================================\n\n";
		if (menu == 1)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ���\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ��� ��������\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ��� ������\n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ������������\n";
		if (menu == 5)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ���������\n";
		if (menu == 6)
			set_color(RED);
		else set_color(WHITE);
		cout << "�����\n";
	}
	void change_f(Fantast fantast)
	{
		char key_tmp; //��������� ������
		char key; //�����
		bool ENTER_;
		short func = 1;
		bool exit = false;
		string fullname;
		int year_of_birth;
		int year_of_death;
		string book;
		int id;
		int isFilmed;
		menu_change_f(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			switch (key) {
			case 80: //����
				func++;
				if (func > 4)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 4;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			//TODO: ���������
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: 
					cout << "������� ����� ���" << endl;
					cin >> fullname;
					fantast.set_fullname(fullname);
					break;
				case 2: 
					cout << "������� id �����, ������� ������ ��������" << endl;
					cin >> id;
					cout << "������� �������� ������ ������������" << endl;
					cin >> book;
					fantast.set_book(book, id);
					break;
				case 3: 
					cout << "������� 1 ���� ����� ����, ���� �� ���� - ������� 0";
					cin >> isFilmed;
					fantast.set_isFilmed(isFilmed);
					break;
				case 4:
					return;
				}
			}
			menu_change_f(func);
		}
	}
	void menu_change_f(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "====================================\n\n";
		if (menu == 1)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ���\n";
		if (menu == 2)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ������������\n";
		if (menu == 3)
			set_color(RED);
		else set_color(WHITE);
		cout << "�������� ����� '���� �� �����'? \n";
		if (menu == 4)
			set_color(RED);
		else set_color(WHITE);
		cout << "�����\n";
	}
}