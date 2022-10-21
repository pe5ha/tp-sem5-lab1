#include <iostream>
#include "Poet.h"
/*Разработать класс Keeper, который реализует контейнер для хранения и обработки
объектов. Класс Keeper должен обеспечивать следующие функции:
▪ добавление и удаление производных объектов абстрактного класса Writter
▪ полное сохранение себя в файле;
▪ полное восстановление себя из файла.
*/


class Keeper
{
private:
	int size_p;
	Poet* p;

public:
	//конструкторы
	Keeper();


	void hellower();
	void add_poet(string fullname, int* years_of_live, string name_books);
	int get_of_number_poet();
};

