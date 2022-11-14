#include "Writer.h"
class Fantasist : public Writer
{
private:
	bool isFilmed;
public:
	Fantasist();
	Fantasist(string fullname, string *name_books, int nob, bool isFilmed);// конструктор с парам-ми
	Fantasist(const Fantasist &ref_Fantast); // конструктор копирования

	//геттеры
	string get_fullname() override;
	string* get_name_books() override;
	int get_number_of_books()override;

	bool get_isFilmed();

	//сеттеры
	void set_fullname(string fullname)override;
	void set_name_books(string* name_books)override;
	void set_number_of_books(int new_nob)override;

	void set_book(string, int old_book_id)override;

	void set_isFilmed(bool isFilmed);

	//изменение данных
	void add_book(string)override;
	void delete_book()override;
};

