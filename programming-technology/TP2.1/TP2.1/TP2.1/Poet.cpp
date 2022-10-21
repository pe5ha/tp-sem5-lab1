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
