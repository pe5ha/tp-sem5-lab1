#include "Writer.h"

void Writer::add_book(string new_book)
{
	number_of_books++;
	string* new_books = new string[number_of_books];
	for (int i = 0; i < number_of_books - 1; i++) {
		new_books[i] = books[i];
	}
	new_books[number_of_books - 1] = new_book;
	books = new_books;
}

void Writer::delete_book()
{
	number_of_books--;
	string* new_books = new string[number_of_books];
	for (int i = 0; i < number_of_books; i++) {
		new_books[i] = books[i];
	}
	books = new_books;
}

string Writer::get_fullname()
{
	return fullname;
}

string* Writer::get_books()
{
	return books;
}

void Writer::set_fullname(string fullname)
{
	this->fullname = fullname;
}

void Writer::set_books(string *books)
{
	this->books = books;
}
int Writer::get_number_of_books()
{
	return number_of_books;
}
void Writer::set_number_of_books(int new_nob)
{
	number_of_books = new_nob;
}

void Writer::set_book(string book, int old_book_id)
{
	this->books[old_book_id] = book;
}
