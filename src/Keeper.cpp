#include "Keeper.h"


string* Keeper::split(string str, char ch)
{
	stringstream stream(str);
	string* s = new string();
	int size = 0;
	std::string item;
	while (getline(stream, item, ch)) {
		size++;
		string* new_s = new string[size];
		cout << "size = " << size << "\n item = " << item << "\n";
		for (int i = 0; i < size - 1; i++) {
			new_s[i] = s[i];
		}
		new_s[size - 1] = item;
		s = new_s;
	}
	return s;
}

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
			for (int j = 0; j < p[i].get_number_of_books(); j++)
				out << p[i].get_name_books()[j] << endl;
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
		int i = 0;
		while(!in.eof()) {
			getline(in, fn);
			in >> yob;
			in >> yod;
			getline(in, new_name_of_book);//TODO: сделать красиво - сейчас применяется для переноса на другую строку
			getline(in, new_name_of_book);
			string* new_books = split(new_name_of_book, ';');

			int size_str = new_books->size();
			//присваиваем новые значения
			Poet new_p(fn, yob, yod, new_books, size_str);//исправить последний параметр
			add_poet(new_p);

			print_poet(i);
			i++;
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



