#include <iostream>
#include <string>

using namespace std;

class Writter
{
protected:
	string fullname;
	int *years_of_live;
	string name_books; // TODO: разобраться, сделать ли его массивом

	string biography;

	bool filmed;
public:
	//~Writter(); TODO: - сделать деструктор

	virtual string get_fullname();
	virtual int* get_years_of_live();
	virtual string get_name_books();
	virtual string get_biography();
	virtual bool get_filmed();

	//TODO: set
	virtual void set_fullname(string fullname);
	virtual void set_years_of_live(int* years_of_live);
	virtual void set_name_books(string name_books);
};