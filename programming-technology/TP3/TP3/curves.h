#pragma once
#define PI 3.14159265 

class Curves // это абстрактный класс
{
protected:
	float x; // координата, вводимая пользователем
	float y; // получаемая y
public:
	virtual ~Curves();
	virtual void calculateY() = 0;
	virtual void setX(float newX);	
	virtual float getY();
};

