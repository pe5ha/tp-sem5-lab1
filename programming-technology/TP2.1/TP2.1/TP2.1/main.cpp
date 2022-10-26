#include <iostream>
#include "Poet.h"
#include "Keeper.h"

/*Класс Печатное издание хранит книги поэтов, романистов и фантастов. Для
поэтов определено: ФИО, годы жизни, несколько основных произведений. Для
романистов определено: ФИО, годы жизни, несколько произведений, краткая
биография. Для фантастов определено: ФИО, несколько произведений, сняты
ли фильмы по книгам.
*/
/*Разработать класс Keeper, который реализует контейнер для хранения и обработки
объектов. Класс Keeper должен обеспечивать следующие функции:
▪ добавление и удаление производных объектов абстрактного класса Writter
▪ полное сохранение себя в файле;
▪ полное восстановление себя из файла.
*/

/*TODO: 
1)Keeper 
2)Меню

*/

int main()
{
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    Keeper k;
    cout << "Keeper is here!" << endl;

    //tete

    Poet new_p1("Semyon", 2002, 2100, "little prince");
    Poet new_p2("Kirill", 2000, 2024, "little prince");

    k.add_poet(new_p1);
    k.add_poet(new_p2);
    k.get_poet(0).get_fullname();
    k.get_poet(1).get_fullname();
    k.get_of_number_poet();
    k.Save();
    k.Read();
    cout << k.get_of_number_poet();
    k.add(new_p1);
    cout << k.get_of_number_poet();
    for (int i = 0; i < k.get_of_number_poet(); i++) {
        k.print_poet(i);
    }
}
