#include "curves.h"
// реализация по умолчанию
// деструктор
Curves::~Curves() {}
// Изменение координат или угла
void Curves::setX(float newX) {
	x = newX;
}
float Curves::getY() {
	return y;
}
