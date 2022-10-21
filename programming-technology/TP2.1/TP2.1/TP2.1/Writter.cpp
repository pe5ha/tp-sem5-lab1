#include "Writter.h"

string Writter::get_fullname()
{
	return fullname;
}

int* Writter::get_years_of_live()
{
	return years_of_live;
}

string Writter::get_name_books()
{
	return name_books;
}

string Writter::get_biography()
{
	return biography;
}

bool Writter::get_filmed()
{
	return filmed;
}

void Writter::set_fullname(string fullname)
{
	this->fullname = fullname;
}

void Writter::set_years_of_live(int* years_of_live)
{
	this->years_of_live = years_of_live;
}

void Writter::set_name_books(string name_books)
{
	this->name_books = name_books;
}
