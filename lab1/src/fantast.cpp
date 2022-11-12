#include "fantast.h"

Fantast::Fantast()
{
	this->fullname = "NULL";
	this->name_books = new string[0];
	this->number_of_books = 0;
	this->isFilmed = NULL;
}

Fantast::Fantast(string fullname, string* name_books, int nob, bool isFilmed)
{
	this->fullname = fullname;
	this->name_books = name_books;
	this->number_of_books = nob;
	this->isFilmed = isFilmed;
}

Fantast::Fantast(const Fantast& ref_Fantast)
{
	fullname = ref_Fantast.fullname;
	name_books = ref_Fantast.name_books;
	number_of_books = ref_Fantast.number_of_books;
	isFilmed = ref_Fantast.isFilmed;
}

string Fantast::get_fullname()
{
	return Writter::get_fullname();
}

string* Fantast::get_name_books()
{
	return Writter::get_name_books();
}

void Fantast::set_fullname(string fullname)
{
	Writter::set_fullname(fullname);
}

void Fantast::set_name_books(string* name_books)
{
	Writter::set_name_books(name_books);
}

void Fantast::set_number_of_books(int new_nob)
{
	Writter::set_number_of_books(new_nob);
}

void Fantast::set_book(string book, int old_book_id)
{
	Writter::set_book(book, old_book_id);
}

void Fantast::set_isFilmed(bool isFilmed)
{
	this->isFilmed = isFilmed;
}

void Fantast::add_book(string new_book)
{
	Writter::add_book(new_book);
}

void Fantast::delete_book()
{
	Writter::delete_book();
}

int Fantast::get_number_of_books()
{
	return Writter::get_number_of_books();
}

bool Fantast::get_isFilmed()
{
	return this->isFilmed;
}

