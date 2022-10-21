#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "funksForStack.cpp"
#include "stack.h"
#include <stdlib.h>

using namespace std;

void menu_oputput(Stack&, HANDLE, short); //отрисовка меню
void set_color(HANDLE, WORD); //установка цвета
void clrscr(HANDLE); //очистка экрана(быстрее cls)
enum colors_ {
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED
};

int main() {
	setlocale(LC_ALL, "Russian");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int sizeStack;
	do {
		cout << "Введите размер стека: " << endl;
		cin >> sizeStack;
	} while (sizeStack <= 0);
	Stack s(sizeStack); //стэк
	bool clearConsole = 0;
	menu_oputput(s, hConsole, 1);
	char tmp; //временное хранилище символов
	char key; //выбор опции
	short function = 1; //запуск функции
	bool ENTER_;
	bool exit = false;

	while (!exit) {
		ENTER_ = false;
		tmp = _getch();
		if (tmp == 224) //проверка на стрелочки
			key = _getch();
		else key = tmp;

		switch (key) {
		case 80: //стрелочка вниз
			function++;
			if (function > 15)
				function = 1;
			break;
		case 72: //стрелочка вверх
			function--;
			if (function < 1)
				function = 15;
			break;
		case 13: //enter
			ENTER_ = true;
			break;
		}

		if (ENTER_) { //запуск функции
			float_unary yourFU;

			if (s.getSize() != 0) {
				yourFU = s.getLastElement();
			}
			else {
				cout << "Стек пуст - Последнего элемента нету!" 
					<< "Добавим элемент и теперь приступим к делу" << endl;
				s.pushElement();
				yourFU = s.getLastElement();
			}
			float_unary helper;
			float f_u_value;
			switch (function) {
			case 1:
				// добавление элемента
				s.pushElement();
				clearConsole = 1;
				break;
			case 2:
				// извлечение элемента
				if (s.getSize() == 0) {
					cout << "Стек пуст" << endl;
					clearConsole = 0;
					break;
				}
				s.pop();
				clearConsole = 1;
				break;
			case 3:
				// fu++
				s.getLastElement()++;
				clearConsole = 1;
				break;
			case 4:
				// fu--
				s.getLastElement()--;
				clearConsole = 1;
				break;
			case 5:
				// ++fu
				++s.getLastElement();
				clearConsole = 1;
				break;
			case 6:
				// --fu
				--s.getLastElement();
				clearConsole = 1;
				break;
			case 7:
				// +
				cout << "Введите вещественное значение с которым будете работать дальше: " << endl;
				cin >> f_u_value;
				helper = f_u_value + yourFU.getValue();
				yourFU = helper;
				s.setLastValue(yourFU.getValue());
				cout << "Ответ: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 8:
				// -
				cout << "Введите вещественное значение с которым будете работать дальше: " << endl;
				cin >> f_u_value;
				helper = yourFU.getValue() - f_u_value;
				yourFU = helper;
				s.setLastValue(yourFU.getValue());
				cout << "Ответ: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 9:
				// *
				cout << "Введите вещественное значение с которым будете работать дальше: " << endl;
				cin >> f_u_value;
				helper = yourFU.getValue() * f_u_value;
				yourFU = helper;
				s.setLastValue(yourFU.getValue());
				cout << "Ответ: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 10:
				// /
				cout << "Введите вещественное значение с которым будете работать дальше: " << endl;
				cin >> f_u_value;
				helper = yourFU.getValue() / f_u_value;
				yourFU = helper;
				s.setLastValue(yourFU.getValue());
				cout << "Ответ: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 11:
				// +=
				cout << "Введите вещественное значение с которым будете работать дальше: " << endl;
				cin >> f_u_value;
				yourFU += f_u_value;
				s.setLastValue(yourFU.getValue());
				cout << "Ответ: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 12:
				// -=
				cout << "Введите вещественное значение с которым будете работать дальше: " << endl;
				cin >> f_u_value;
				yourFU -= f_u_value;
				s.setLastValue(yourFU.getValue());
				cout << "Ответ: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 13:
				// *=
				cout << "Введите вещественное значение с которым будете работать дальше: " << endl;
				cin >> f_u_value;
				yourFU *= f_u_value;
				s.setLastValue(yourFU.getValue());
				cout << "Ответ: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 14:
				// /=
				cout << "Введите вещественное значение с которым будете работать дальше: " << endl;
				cin >> f_u_value;
				yourFU /= f_u_value;
				s.setLastValue(yourFU.getValue());
				cout << "Ответ: " << yourFU.getValue() << endl;
				clearConsole = 1;
				break;
			case 15:
				// +=
				return 0;
			}
		}
		if (clearConsole == 1) {
			system("cls");
			clearConsole = 0;
		}
		menu_oputput(s, hConsole, function);
	}
	return 0;
}

void menu_oputput(Stack& s, HANDLE console, short menu) {
	clrscr(console);
	set_color(console, WHITE);
	//вывод очереди на экран
	cout << "Стек: ";
	s.printStack();

	cout << endl << "====================================\n";
	if (menu == 1)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "Добавление элемента в стек" << endl;
	if (menu == 2)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "Извлечение элемента из стека" << endl;
	if (menu == 3)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<последний элемент стека>++" << endl;
	if (menu == 4)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<последний элемент стека>--" << endl;
	if (menu == 5)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "++<последний элемент стека>" << endl;
	if (menu == 6)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "--<последний элемент стека>" << endl;
	if (menu == 7)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<последний элемент стека(float_unary) = "
		"<последний элемент стека(float_unary) + <ваш float>" << endl;
	if (menu == 8)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<последний элемент стека(float_unary) = "
		"<последний элемент стека(float_unary) - <ваш float>" << endl;
	if (menu == 9)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<последний элемент стека(float_unary) = "
		"<последний элемент стека(float_unary) * <ваш float>" << endl;
	if (menu == 10)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<последний элемент стека(float_unary) = "
		"<последний элемент стека(float_unary) / <ваш float>" << endl;
	if (menu == 11)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<последний элемент стека(float_unary) += <ваш float>" << endl;
	if (menu == 12)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<последний элемент стека(float_unary) -= <ваш float>" << endl;
	if (menu == 13)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<последний элемент стека(float_unary) *= <ваш float>" << endl;
	if (menu == 14)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "<последний элемент стека(float_unary) /= <ваш float>" << endl;
	if (menu == 15)
		set_color(console, RED);
	else set_color(console, WHITE);
	cout << "exit\n\n";
}

void set_color(HANDLE console, WORD color) {
	SetConsoleTextAttribute(console, color);
}

void clrscr(HANDLE console) {
	COORD cur_pos;
	cur_pos.X = 0;
	cur_pos.Y = 0;
	SetConsoleCursorPosition(console, cur_pos);
}