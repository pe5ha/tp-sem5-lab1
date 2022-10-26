#include "Writter.h"

string Writter::get_fullname()
{
	return fullname;
}

string Writter::get_name_books()
{
	return name_books;
}

void Writter::set_fullname(string fullname)
{
	this->fullname = fullname;
}

void Writter::set_name_books(string name_books)
{
	this->name_books = name_books;
}
