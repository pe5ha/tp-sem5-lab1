#include <iostream>
#include <string>

using namespace std;

class Writter
{
protected:
	string fullname;
	string name_books; // TODO: разобраться, сделать ли его массивом
public:
	//~Writter(); TODO: - сделать деструктор

	virtual string get_fullname() = 0;
	virtual string get_name_books() = 0;

	virtual void set_fullname(string fullname) = 0;
	virtual void set_name_books(string name_books) = 0;
};