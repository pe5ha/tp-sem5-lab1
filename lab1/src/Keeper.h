#include <iostream>
#include <fstream>
#include "Poet.h"
#include <sstream>    
/*Разработать класс Keeper, который реализует контейнер для хранения и обработки
объектов. Класс Keeper должен обеспечивать следующие функции:
▪ добавление и удаление производных объектов абстрактного класса Writter
▪ полное сохранение себя в файле;
▪ полное восстановление себя из файла.
*/

class keeper
{
private:
	int size_p;
	Poet* p;

	string* split(string str, char ch);
public:
	//конструкторы
	keeper();
	keeper(int, Poet*);
	keeper(const keeper&);

	void add_poet(Poet new_p);
	void delete_poet(int id); // мб заменить на шаблон?

	//template <typename T>
	//void add(T newT) { if (std::is_same<T, Poet>::value) p[size_p++] = newT; }

	int get_size();

	Poet get_poet(int id);
	//вывод поэта
	void print_poet();// все поэты
	void print_poet(int id); // поэты по id

	void add_book_poet(string);
	void delete_book_poet();

	void Save();
	void Read();
};