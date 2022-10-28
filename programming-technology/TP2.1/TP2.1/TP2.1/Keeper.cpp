#include "Keeper.h"


Keeper::Keeper()
{
	this->size_p = 0;
	p = new Poet[1];
}

int Keeper::get_size()
{
	return size_p;
}

void Keeper::add_poet(Poet new_p)
{
	Poet* new_poets = new Poet[size_p + 1];
	for (int i = 0; i < size_p; i++) {
		new_poets[i] = p[i];
	}
	new_poets[size_p] = new_p;
	size_p++;
	p = new_poets;
}

void Keeper::delete_poet(int id)
{
	if (size_p <= 0) exception;
	Poet* new_poets = new Poet[size_p - 1];
	int k = 0;
	for (int i = 0; i < size_p; i++) {
		if (i == id) continue;
		new_poets[k] = p[i];
		k++;
	}
	//delete[] new_poets;
	p = new_poets;
	size_p--;
}

Poet Keeper::get_poet(int id)
{
	if (id >= size_p) { cout << "замени на эксепшен!" << endl; return p[0]; }//TODO: замени на эксепшен! 
	return p[id];
}



void Keeper::Save()
{
	ofstream out;          // поток для записи
	out.open("data.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		for (int i = 0; i < size_p; i++) {
			out << p[i].get_fullname() << endl;
			out << p[i].get_years_of_birth() << endl;
			out << p[i].get_years_of_death() << endl;
			out << p[i].get_name_books() << endl;
		}
	}
	out.close();
}

void Keeper::Read()
{
	string fn;//новое ФИО
	int yob;//года
	int yod;//года
	string new_name_of_book;
	ifstream in("data.txt");
	if (in.is_open())
	{
		for (int i = 0; i < size_p; i++) {
			getline(in, fn);
			in >> yob;
			in >> yod;
			getline(in, new_name_of_book);//TODO: сделать красиво - сейчас применяется для переноса на другую строку
			getline(in, new_name_of_book);

			Poet new_p(fn, yob, yod, &new_name_of_book, 2);
			p[i] = new_p;

			cout << p[i].get_fullname() << p[i].get_years_of_birth() << p[i].get_years_of_death() << *p[i].get_name_books() << endl;
		}
	}
	in.close(); // закрываем файл
}

void Keeper::print_poet(int id)
{
	if (id >= size_p) { return; }
	cout << p[id].get_fullname() << endl;
	cout << p[id].get_years_of_birth() << endl;
	cout << p[id].get_years_of_death() << endl;
	int new_nub = p->get_number_of_books();
	for (int i = 0; i < new_nub; i++)
		cout << p[id].get_name_books()[i] << endl;
}



