#include "straight.h"
#include <iostream>

Straight::~Straight() {}

void Straight::calculateY() {
	y = tan(angle * PI / 180) * x + b; // kx + b - стандартна€ формула
}
void Straight::setX(float newX) {
	Curves::setX(newX);
}
// »зменение координат или угла

void Straight::setAngle(int newAngle) {
	this->angle = newAngle; // используетс€ реализаци€ по умолчанию класса Curves
}

void Straight::setB(float newB) {
	this->b = newB;
}


