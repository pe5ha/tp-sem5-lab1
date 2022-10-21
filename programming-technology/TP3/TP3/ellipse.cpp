#include "ellipse.h"
#include "math.h"

Ellipse::~Ellipse(){}

void Ellipse::calculateY() {
	y = sqrt(b*b*(1 - (x*x/a/a)));
}
void Ellipse::setX(float newX) {
	Curves::setX(newX);
}
void Ellipse::setA(float newA) {
	a = newA;
}
void Ellipse::setB(float newB) {
	b = newB;
}
