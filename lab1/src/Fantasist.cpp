#include "Fantasist.h"

Fantasist::Fantasist()
{
	this->fullname = "NULL";
	this->name_books = new string[0];
	this->number_of_books = 0;
	this->isFilmed = NULL;
}

Fantasist::Fantasist(string fullname, string* name_books, int nob, bool isFilmed)
{
	this->fullname = fullname;
	this->name_books = name_books;
	this->number_of_books = nob;
	this->isFilmed = isFilmed;
}

Fantasist::Fantasist(const Fantasist& ref_Fantast)
{
	fullname = ref_Fantast.fullname;
	name_books = ref_Fantast.name_books;
	number_of_books = ref_Fantast.number_of_books;
	isFilmed = ref_Fantast.isFilmed;
}

string Fantasist::get_fullname()
{
	return Writer::get_fullname();
}

string* Fantasist::get_name_books()
{
	return Writer::get_name_books();
}

void Fantasist::set_fullname(string fullname)
{
	Writer::set_fullname(fullname);
}

void Fantasist::set_name_books(string* name_books)
{
	Writer::set_name_books(name_books);
}

void Fantasist::set_number_of_books(int new_nob)
{
	Writer::set_number_of_books(new_nob);
}

void Fantasist::set_book(string book, int old_book_id)
{
	Writer::set_book(book, old_book_id);
}

void Fantasist::set_isFilmed(bool isFilmed)
{
	this->isFilmed = isFilmed;
}

void Fantasist::add_book(string new_book)
{
	Writer::add_book(new_book);
}

void Fantasist::delete_book()
{
	Writer::delete_book();
}

int Fantasist::get_number_of_books()
{
	return Writer::get_number_of_books();
}

bool Fantasist::get_isFilmed()
{
	return this->isFilmed;
}

