#pragma once
#include "curves.h"
class Hyperbola : Curves
{
private:
	float k; // коэф гиперболы
public:
	~Hyperbola();

	virtual void calculateY();
	virtual void setX(float newX);
	virtual float getY();

	void setK(float newA);
};

