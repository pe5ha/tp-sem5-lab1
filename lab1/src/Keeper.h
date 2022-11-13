﻿#include <iostream>
#include <fstream>
#include "Poet.h"
#include "novelist.h"
#include "fantast.h"
#include <sstream>    

/*Разработать класс Keeper, который реализует контейнер для хранения и обработки
объектов. Класс Keeper должен обеспечивать следующие функции:
▪ добавление и удаление производных объектов абстрактного класса Writter
▪ полное сохранение себя в файле;
▪ полное восстановление себя из файла.
*/

class keeper
{
private:
	int size_p;
	int size_n;
	int size_f;
	Poet* p;
	Novelist* n;
	Fantast* f;

	string* split(string str, char ch);
public:
	//конструкторы
	keeper();
	keeper(int size_p, int size_n, int size_f ,Poet* p, Novelist* n, Fantast* f);
	keeper(const keeper&);

	void add_poet(Poet new_p);
	void delete_poet(int id);

	void add_novelist(Novelist new_n);
	void delete_novelist(int id);

	void add_fantast(Fantast new_f);
	void delete_fantast(int id);


	//template <typename T>
	//void add(T newT) { if (std::is_same<T, Poet>::value) p[size_p++] = newT; }

	int get_size();

	Poet get_poet(int id);
	Novelist get_novelist(int id);
	Fantast get_fantast(int id);
	//вывод 
	void print_poet();// все поэты
	void print_poet(int id); // поэты по id

	void print_novelist();
	void print_novelist(int id);

	void print_fantast();
	void print_fantast(int id);

	void print_all();

	//добавление и удаление книг
	void add_book_poet(string, int id);
	void delete_book_poet(int);

	void add_book_novelist(string, int id);
	void delete_book_novelist(int id);

	void add_book_fantast(string, int id);
	void delete_book_fantast(int id);


	//сохранение и чтение файла
	void Save();
	void Read();
};