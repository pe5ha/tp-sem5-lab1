#include <iostream>
#include "straight.h"
#include "hyperbola.h"
#include "ellipse.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");


	Straight line; // объект класса "прямая"
	Hyperbola hyphyp; // объект класса "гипербола"
	Ellipse ellipse; // объект класса "эллипс"

	char c = -1;

	cout << "1 - Вычислить 'y' прямой линии\n"
		"2 - Вычислить 'y' гиперболы\n"
		"3 - Вычислить 'y' эллипса\n"
		"0 - выйти"
		<< endl;
	int angle; // угол
	float b;// смещение
	float x;// x
	float k;// коэфициент гиперболы
	float ellipseA, ellipseB;// полуоси эллипса
	do {
		switch (c) {
			// прямая
		case '1':
			// узнаем угол
			do {
				cout << "Укажите градус угла: " << endl;
				cin >> angle;
			} while (angle < -360 || angle > 360);
			line.setAngle(angle);

			if (angle == 90 || angle == 270 ||
				angle == -90 || angle == -270) {
				cout << "y = бесконечности вне зависимости от х"
					" или b." << endl;
				cout << "Выберете действие: ";
				break;
			}
			// узнаем смещение b
			cout << "Введите смещение - 'b'" << endl;
			cin >> b;
			line.setB(b);
			if (angle == 0 || angle == 180 || angle == 360
				|| angle == -360 || angle == -180) {
				cout << "В независимости от х, y = " << b << endl;
				cout << "Выберете действие: ";
				break;
			}
			// узнаем х
			cout << "Введите 'х'" << endl;
			cin >> x;
			line.setX(x);

			line.calculateY();
			cout << "y = " << line.getY() << endl;
			cout << "Выберете действие: ";
			break;

			// гипербола
		case '2':
			do {
				cout << "Введите коэфициент гиперболы (формула: y = k / x)" << endl;
				cin >> k;
				hyphyp.setK(k);
			} while (k == 0);

			cout << "Введите x" << endl;
			cin >> x;
			hyphyp.setX(x);
			if (x == 0) {
				cout << "асимптота стремится к нулю, но не достигает его" << endl;
				break;
			}

			hyphyp.calculateY();
			(k > 0) ?
				cout << "гипербола расположена в 1 и 3 четвертях" << endl :
				cout << "гипербола расположена в 2 и 4 четвертях" << endl;
			cout << "y = " << hyphyp.getY() << endl;

			cout << "Выберете действие: ";
			break;
			// эллипс
		case '3':
			// задаём малую полуось
			do {
				cout << "Введите полуось a: " << endl;
				cin >> ellipseA;
				ellipse.setA(ellipseA);
			} while (ellipseA <= 0);
			// задаём большую полуось (должна быть больше малой)
			do {
				cout << "Введите полуось b: " << endl;
				cin >> ellipseB;
				ellipse.setB(ellipseB);
			} while (ellipseB <= 0);

			// задаём х
			cout << "Введите x: " << endl;
			cin >> x;
			ellipse.setX(x);
			if (abs(x) > ellipseA)
				cout << "нету такого Y у эллипса, который соответствует вашему x" << endl;
			else if (abs(x) == ellipseA) {
				ellipse.calculateY();
				cout << "y = " << ellipse.getY() << endl;
			}
			else {
				ellipse.calculateY();
				cout << "y = " << ellipse.getY() << " и y = " << -ellipse.getY() << endl;
			}
			cout << "Выберете действие: ";
			break;
		}
	} while ((c = getchar()) != '0');
}

