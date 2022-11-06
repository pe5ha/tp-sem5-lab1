#include "Keeper.h"




keeper::keeper()
{
	this->size_p = 0;
	p = new Poet[1];
}

keeper::keeper(int size_p, Poet *p)
{
	this->size_p = size_p;
	this->p = p;
}

keeper::keeper(const keeper& ref_k)
{
	this->size_p = ref_k.size_p;
	this->p = ref_k.p;
	//TODO: ������� ������������ � ��� ������ �������
}

int keeper::get_size()
{
	return size_p;
}

void keeper::add_poet(Poet new_p)
{
	size_p++;
	Poet* new_poets = new Poet[size_p];
	for (int i = 0; i < size_p - 1; i++) {
		new_poets[i] = p[i];
	}
	new_poets[size_p - 1] = new_p; // ���������
	p = new_poets;
}

void keeper::delete_poet(int id)
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

Poet keeper::get_poet(int id)
{
	if (id >= size_p) { cout << "������ �� ��������!" << endl; return p[0]; }//TODO: ������ �� ��������! 
	return p[id];
}



void keeper::Save()
{
	ofstream out;          // ����� ��� ������
	out.open("data.txt");  // �������� ���� ��� ������
	if (out.is_open())
	{
		for (int i = 0; i < size_p; i++) {
			if (i != 0)
				out << "\n";
			out << "Poet" << endl;
			out << p[i].get_fullname() << endl;
			out << p[i].get_years_of_birth() << endl;
			out << p[i].get_years_of_death() << endl;
			
			//���������� ���������� ����
			out << p[i].get_number_of_books();
			for (int j = 0; j < p[i].get_number_of_books(); j++) {
				out << ";" << p[i].get_name_books()[j];
				cout << ";" << p[i].get_name_books()[j];
			}
		}
	}
	out.close();
}

void keeper::Read()
{
	string fn;//����� ���
	int yob;//����
	int yod;//����
	string new_name_of_book;
	ifstream in("data.txt");
	cout << in.is_open();
	if (in.is_open())
	{
		int i = 0;
		/*
		1 ������ - �������� ������: 'p' - ����
		2 ������ - �������� ���
		3 ������ - �������� ��������� �������� ������������
		4-5 ������ - �������� ���� �����
		� ������...
		*/
		while(!in.eof()) {
			string c;
			getline(in, c);
			if (c == "Poet") {/*TODO: ������� � ���������� �������*/
				getline(in, fn);
				in >> yob;
				in >> yod;
				getline(in, new_name_of_book);//TODO: ������� ������� - ������ ����������� ��� �������� �� ������ ������
				getline(in, new_name_of_book);
				string* new_books = split(new_name_of_book, ';');
				int size_books = stoi(new_books[0]);
				cout << size_books << endl;
				//test 

				//����������� ����� ��������
				Poet new_p(fn, yob, yod, new_books, size_books);//��������� ��������� ��������
				add_poet(new_p);
				i++;
			}
			else if (c == "Romanist") {}
			else if (c == "Fantast") {}
		}
	}
	in.close(); // ��������� ����
}

void keeper::print_poet()
{
	for (int i = 0; i < size_p; i++) {
		cout << "\n���� " << i + 1 << ": " << endl;
		print_poet(i);
	}
}

// TODO: �����������, ������ �� ������� �� ����� ����� 4-5 ������� - �������� ������������
//������ ��-�� cout
void keeper::print_poet(int id)
{
	if (id >= size_p) { return; }
	cout << p[id].get_fullname() << endl;
	cout << p[id].get_years_of_birth() << endl;
	cout << p[id].get_years_of_death() << endl;
	int new_nub = p[id].get_number_of_books();
	if (p[id].get_number_of_books() == 0) { cout << "���� ����" << endl; }
	for (int i = 1; i <= new_nub; i++)
		cout << p[id].get_name_books()[i] << endl;
}

void keeper::add_book_poet(string book)
{
	p->add_book(book);
}

void keeper::delete_book_poet()
{
	p->delete_book();
}

string* keeper::split(string str, char ch)
{
	stringstream stream(str);
	string* s = new string();
	int size = 0;
	std::string item;
	while (getline(stream, item, ch)) {
		size++;
		string* new_s = new string[size];
		for (int i = 0; i < size - 1; i++) {
			new_s[i] = s[i];
		}
		new_s[size - 1] = item;
		s = new_s;
	}
	stream.flush();
	return s;
}

