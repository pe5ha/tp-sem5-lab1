#include "Writer.h"
class Fantasist : public Writer
{
private:
	bool filmed;
public:
	Fantasist();
	Fantasist(string fullname, string *books, int nob, bool filmed);// конструктор с парам-ми
	Fantasist(const Fantasist &ref_Fantast); // конструктор копирования

	//геттеры
	string get_fullname() override;
	string* get_books() override;
	int get_number_of_books()override;

	bool is_filmed();

	//сеттеры
	void set_fullname(string fullname)override;
	void set_books(string* books)override;
	void set_number_of_books(int new_nob)override;

	void set_book(string, int old_book_id)override;

	void set_filmed(bool filmed);

	//изменение данных
	void add_book(string)override;
	void delete_book()override;
};

