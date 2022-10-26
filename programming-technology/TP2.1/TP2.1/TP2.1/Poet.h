#pragma once
#include "Writter.h"
class Poet : public Writter
{
public:
	Poet();
	Poet(string fullname, int* years_of_live, string name_books);// конструктор с парам-ми
	Poet(const Poet &ref_Poet); // конструктор копирования

	//годы жизни
	int* years_of_live;

	//геттеры
	string get_fullname() override;
	int* get_years_of_live();
	string get_name_books() override;

	//сеттеры
	void set_fullname(string fullname)override;
	void set_years_of_live(int* years_of_live);
	void set_name_books(string name_books)override;
};

