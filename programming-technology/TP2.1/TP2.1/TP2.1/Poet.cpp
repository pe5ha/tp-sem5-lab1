#include "Poet.h"

Poet::Poet()
{
	this->fullname = "NULL";
	this->year_of_birth = NULL;
	this->year_of_death = NULL;
	this->name_books = "NULL";
}

Poet::Poet(string fullname, int year_of_birth, int year_of_death, string name_books)
{
	this->fullname = fullname;
	this->year_of_birth = year_of_birth;
	this->year_of_death = year_of_death;
	this->name_books = name_books;
}

Poet::Poet(const Poet& ref_Poet)
{
	fullname = ref_Poet.fullname;
	year_of_birth = ref_Poet.year_of_birth;
	year_of_death = ref_Poet.year_of_death;
	name_books = ref_Poet.name_books;
}

string Poet::get_fullname()
{
	return Writter::get_fullname();
}

int Poet::get_years_of_birth()
{
	return year_of_birth;
}

int Poet::get_years_of_death()
{
	return year_of_death;
}

string Poet::get_name_books()
{
	return Writter::get_name_books();
}

void Poet::set_fullname(string fullname)
{
	Writter::set_fullname(fullname);
}

void Poet::set_years_of_birth(int year_of_birth)
{
	this->year_of_birth = year_of_birth;
}

void Poet::set_years_of_death(int year_of_death)
{
	this->year_of_death = year_of_death;
}

void Poet::set_name_books(string name_books)
{
	Writter::set_name_books(name_books);
}

void Poet::change_fullname(string fullname)
{
	this->fullname = fullname;
}

void Poet::change_year_of_birth(int year_of_birth)
{
	this->year_of_birth = year_of_birth;
}

void Poet::change_year_of_death(int year_of_death)
{
	this->year_of_death = year_of_death;
}

void Poet::change_name_of_book(string name_books)
{
	this->name_books = name_books;
}
