#pragma once
#include "Menu.h"
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

		set_color(menu == 1 ? RED : WHITE);
		cout << "�������� ��� ������� ��������\n";

		set_color(menu == 2 ? RED : WHITE);
		cout << "�������� ��� ������� ����� � ������ ������������\n";

		set_color(menu == 3 ? RED : WHITE);
		cout << "������� ��������\n";

		set_color(menu == 4 ? RED : WHITE);
		cout << "�������� ������\n";

		set_color(menu == 5 ? RED : WHITE);
		cout << "��������� ������\n";

		set_color(menu == 6 ? RED : WHITE);
		cout << "��������� ������\n";

		set_color(menu == 7 ? RED : WHITE);
		cout << "�����\n" << endl;
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

		set_color(menu == 1 ? RED : WHITE);
		cout << "�������� �����\n";

		set_color(menu == 2 ? RED : WHITE);
		cout << "�������� ���������\n";

		set_color(menu == 3 ? RED : WHITE);
		cout << "�������� ��������\n";

		set_color(menu == 4 ? RED : WHITE);
		cout << "������� ��������\n";

		set_color(menu == 5 ? RED : WHITE);
		cout << "������� �����\n";

		set_color(menu == 6 ? RED : WHITE);
		cout << "������� ���������\n";

		set_color(menu == 7 ? RED : WHITE);
		cout << "�����\n";
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

		set_color(menu == 1 ? RED : WHITE);
		cout << "�������� ����� �����\n";

		set_color(menu == 2 ? RED : WHITE);
		cout << "�������� ����� ���������\n";

		set_color(menu == 3 ? RED : WHITE);
		cout << "�������� ����� ��������\n";

		set_color(menu == 4 ? RED : WHITE);
		cout << "������� ����� �����\n";

		set_color(menu == 5 ? RED : WHITE);
		cout << "������� ����� ���������\n";

		set_color(menu == 6 ? RED : WHITE);
		cout << "������� ����� ��������\n";

		set_color(menu == 7 ? RED : WHITE);
		cout << "�����\n";
	}



	void add_a_poet()
	{
		string fullname;
		int year_of_birth, year_of_death; string yob, yod;
		string* books = new string[1];
		getline(cin, fullname);
		getline(cin, yob);
		getline(cin, yod);
		try {
			for (int i = 0; i < yob.length(); i++) { // ���� �� ��������
				if (yob[i] >= 'A' && yob[i] <= 'Z' || yob[i] >= 'a' && yob[i] <= 'z'
					|| yod[i] >= 'A' && yod[i] <= 'Z' || yod[i] >= 'a' && yod[i] <= 'z')
					throw "������ - � ���� �������� ���� �����";
				break;
			}
		}
		catch (string s) {
			cout << s << endl;
		}
		year_of_birth = stoi(yob);
		year_of_death = stoi(yod);
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
		int year_of_birth, year_of_death; string yob, yod;
		string* books = new string[1];
		string biography;
		getline(cin, fullname);
		getline(cin, yob);
		getline(cin, yod);
		try {
			for (int i = 0; i < yob.length(); i++) { // ���� �� ��������
				if (yob[i] >= 'A' && yob[i] <= 'Z' || yob[i] >= 'a' && yob[i] <= 'z'
					|| yod[i] >= 'A' && yod[i] <= 'Z' || yod[i] >= 'a' && yod[i] <= 'z')
					throw "������ - � ���� �������� ���� �����";
				break;
			}
		}
		catch (string s) {
			cout << s << endl;
		}
		year_of_birth = stoi(yob);
		year_of_death = stoi(yod);
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
		string* books = new string[20];
		string filmed;
		getline(cin, fullname);
		getline(cin, books[0]);
		getline(cin, filmed);
		int IF = 0;
		try {
			if (filmed != "0" && filmed != "1") {
				throw "������ - � filmed ������� �� 0 ��� 1";
			}
		}
		catch (string s) {
			cout << s << endl;
		}
		IF = stoi(filmed);
		Fantasist f(fullname,books, 1, IF);
		k.add_fantast(f);
	}
	void delete_a_fantast()
	{
		int id;
		cin >> id;
		k.delete_fantast(id);
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
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					return;
				case 2: //������� ��������� �� id
					cout << "������� id" << endl;
					cin >> id;
					k.print_novelist(id);
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 3: //������� �������� �� id
					cout << "������� id" << endl;
					cin >> id;
					k.print_fantast(id);
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 4: //������� ���� ������
					k.print_poet();
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					return;
				case 5: //������� ���� ����������
					k.print_novelist();
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 6: //������� ���� ���������
					k.print_fantast();
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 7: //������� ���� ���������
					k.print_all();
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
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

		set_color(menu == 1 ? RED : WHITE);
		cout << "����� ����� �� id\n";

		set_color(menu == 2 ? RED : WHITE);
		cout << "����� ��������� �� id\n";

		set_color(menu == 3 ? RED : WHITE);
		cout << "����� �������� �� id\n";

		set_color(menu == 4 ? RED : WHITE);
		cout << "����� ���� ������\n";

		set_color(menu == 5 ? RED : WHITE);
		cout << "����� ���� ����������\n";

		set_color(menu == 6 ? RED : WHITE);
		cout << "����� ���� ���������\n";

		set_color(menu == 7 ? RED : WHITE);
		cout << "����� ���� ���������\n";

		set_color(menu == 8 ? RED : WHITE);
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

		set_color(menu == 1 ? RED : WHITE);
		cout << "�������� ������ ����� �� id\n";

		set_color(menu == 2 ? RED : WHITE);
		cout << "�������� ������ ��������� �� id\n";

		set_color(menu == 3 ? RED : WHITE);
		cout << "�������� ������ �������� �� id\n";

		set_color(menu == 4 ? RED : WHITE);
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
					getline(cin,fullname);
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
					getline(cin,book);
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

		set_color(menu == 1 ? RED : WHITE);
		cout << "�������� ���\n";

		set_color(menu == 2 ? RED : WHITE);
		cout << "�������� ��� ��������\n";

		set_color(menu == 3 ? RED : WHITE);
		cout << "�������� ��� ������\n";

		set_color(menu == 4 ? RED : WHITE);
		cout << "�������� ������������\n";

		set_color(menu == 5 ? RED : WHITE);
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
					getline(cin, fullname);
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
					getline(cin,book);
					novelist.set_book(book, id);
					break;
				case 5:
					cout << "������� ����� ��������� ��� ���������" << endl;
					getline(cin, bio);
					novelist.set_biography(bio);
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

		set_color(menu == 1 ? RED : WHITE);
		cout << "�������� ���\n";

		set_color(menu == 2 ? RED : WHITE);
		cout << "�������� ��� ��������\n";

		set_color(menu == 3 ? RED : WHITE);
		cout << "�������� ��� ������\n";

		set_color(menu == 4 ? RED : WHITE);
		cout << "�������� ������������\n";

		set_color(menu == 5 ? RED : WHITE);
		cout << "�������� ���������\n";

		set_color(menu == 6 ? RED : WHITE);
		cout << "�����\n";
	}
	void change_f(Fantasist fantast)
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
		int filmed;
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
					getline(cin, fullname);
					fantast.set_fullname(fullname);
					break;
				case 2: 
					cout << "������� id �����, ������� ������ ��������" << endl;
					cin >> id;
					cout << "������� �������� ������ ������������" << endl;
					getline(cin,book);
					fantast.set_book(book, id);
					break;
				case 3: 
					cout << "������� 1 ���� ����� ����, ���� �� ���� - ������� 0";
					cin >> filmed;
					fantast.set_filmed(filmed);
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

		set_color(menu == 1 ? RED : WHITE);
		cout << "�������� ���\n";

		set_color(menu == 2 ? RED : WHITE);
		cout << "�������� ������������\n";

		set_color(menu == 3 ? RED : WHITE);
		cout << "�������� ����� '���� �� �����'? \n";

		set_color(menu == 4 ? RED : WHITE);
		cout << "�����\n";
	}
}