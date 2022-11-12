#pragma once
#include "Writter.h"
class Poet : public Writter
{
public:
	Poet();
	Poet(string fullname, int year_of_birth, int year_of_death , string *name_books, int nob);// ����������� � �����-��
	Poet(const Poet &ref_Poet); // ����������� �����������

	//���� �����
	int year_of_birth;
	int year_of_death;

	//�������
	string get_fullname() override;
	int get_years_of_birth();
	int get_years_of_death();
	string* get_name_books() override;
	int get_number_of_books()override;

	//�������
	void set_fullname(string fullname)override;
	void set_years_of_birth(int year_of_birth);
	void set_years_of_death(int year_of_death);
	void set_name_books(string* name_books)override;
	void set_number_of_books(int new_nob)override;

	void set_book(string, int old_book_id)override;

	//��������� ������
	void add_book(string)override;
	void delete_book()override;
};

