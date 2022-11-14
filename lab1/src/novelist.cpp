#include "Novelist.h"

Novelist::Novelist()
{
	this->fullname = "NULL";
	this->year_of_birth = NULL;
	this->year_of_death = NULL;
	this->books = new string[0];
	this->number_of_books = 0;
	this->biography = "NULL";
}


Novelist::Novelist(string fullname, int year_of_birth, int year_of_death, string *books, int nob, string biography)
{
	this->fullname = fullname;
	this->year_of_birth = year_of_birth;
	this->year_of_death = year_of_death;
	this->books = books;
	this->number_of_books = nob;
	this->biography = biography;
}

Novelist::Novelist(const Novelist& ref_Novelist)
{
	fullname = ref_Novelist.fullname;
	year_of_birth = ref_Novelist.year_of_birth;
	year_of_death = ref_Novelist.year_of_death;
	books = ref_Novelist.books;
	number_of_books = ref_Novelist.number_of_books;
	biography = ref_Novelist.biography;
}

string Novelist::get_fullname()
{
	return Writer::get_fullname();
}

int Novelist::get_years_of_birth()
{
	return year_of_birth;
}

int Novelist::get_years_of_death()
{
	return year_of_death;
}

string Novelist::get_biography()
{
	return this->biography;
}

string* Novelist::get_books()
{
	return Writer::get_books();
}

void Novelist::set_fullname(string fullname)
{
	Writer::set_fullname(fullname);
}

void Novelist::set_years_of_birth(int year_of_birth)
{
	this->year_of_birth = year_of_birth;
}

void Novelist::set_years_of_death(int year_of_death)
{
	this->year_of_death = year_of_death;
}

void Novelist::set_books(string* books)
{
	Writer::set_books(books);
}

void Novelist::set_number_of_books(int new_nob)
{
	Writer::set_number_of_books(new_nob);
}

void Novelist::set_book(string book, int old_book_id)
{
	Writer::set_book(book, old_book_id);
}

void Novelist::set_biography(string biography)
{
	this->biography = biography;
}

void Novelist::add_book(string new_book)
{
	Writer::add_book(new_book);
}

void Novelist::delete_book()
{
	Writer::delete_book();
}

int Novelist::get_number_of_books()
{
	return Writer::get_number_of_books();
}

