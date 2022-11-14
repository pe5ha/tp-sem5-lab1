#include "Fantasist.h"

Fantasist::Fantasist()
{
	this->fullname = "NULL";
	this->books = new string[0];
	this->number_of_books = 0;
	this->filmed = NULL;
}

Fantasist::Fantasist(string fullname, string* books, int nob, bool filmed)
{
	this->fullname = fullname;
	this->books = books;
	this->number_of_books = nob;
	this->filmed = filmed;
}

Fantasist::Fantasist(const Fantasist& ref_Fantast)
{
	fullname = ref_Fantast.fullname;
	books = ref_Fantast.books;
	number_of_books = ref_Fantast.number_of_books;
	filmed = ref_Fantast.filmed;
}

string Fantasist::get_fullname()
{
	return Writer::get_fullname();
}

string* Fantasist::get_books()
{
	return Writer::get_books();
}

void Fantasist::set_fullname(string fullname)
{
	Writer::set_fullname(fullname);
}

void Fantasist::set_books(string* books)
{
	Writer::set_books(books);
}

void Fantasist::set_number_of_books(int new_nob)
{
	Writer::set_number_of_books(new_nob);
}

void Fantasist::set_book(string book, int old_book_id)
{
	Writer::set_book(book, old_book_id);
}

void Fantasist::set_filmed(bool filmed)
{
	this->filmed = filmed;
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

bool Fantasist::is_filmed()
{
	return this->filmed;
}

