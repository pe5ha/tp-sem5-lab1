#include "hyperbola.h"

Hyperbola::~Hyperbola() {}

void Hyperbola::calculateY() {
	y = k / x;
}
void Hyperbola::setX(float newX) {
	Curves::setX(newX);
}
float Hyperbola::getY() {
	return Curves::getY();
}

void Hyperbola::setK(float newK) {
	k = newK;
}



