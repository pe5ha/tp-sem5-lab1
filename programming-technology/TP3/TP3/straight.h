#pragma once
#include "curves.h"
// y = kx + b
class Straight : public Curves
{
private:
	int angle;
	float b;
public:
	~Straight();

	virtual void calculateY();
	virtual void setX(float newX);

	void setAngle(int newAngle);
	void setB(float newB);


};
