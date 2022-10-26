#include "Poet.h"

Poet::Poet()
{
	this->fullname = "NULL";
	this->years_of_live = NULL;
	this->name_books = "NULL";
}

Poet::Poet(string fullname, int* years_of_live, string name_books)
{
	this->fullname = fullname;
	this->years_of_live = years_of_live;
	this->name_books = name_books;
}

Poet::Poet(const Poet& ref_Poet)
{
	fullname = ref_Poet.fullname;
	years_of_live = ref_Poet.years_of_live;
	name_books = ref_Poet.name_books;
}

string Poet::get_fullname()
{
	return Writter::get_fullname();
}

int* Poet::get_years_of_live()
{
	return years_of_live;
}

string Poet::get_name_books()
{
	return Writter::get_name_books();
}

void Poet::set_fullname(string fullname)
{
	Writter::set_fullname(fullname);
}

void Poet::set_years_of_live(int* years_of_live)
{
	this->years_of_live = years_of_live;
}

void Poet::set_name_books(string name_books)
{
	Writter::set_name_books(name_books);
}
