#pragma once
class float_unary
{
private:
	float value;
public:
	float_unary();
	float_unary(float);
	float_unary(const float_unary&);

	float_unary& operator--(); //префиксный метод перегрузки
	float_unary& operator++(); //префиксный метод перегрузки
	friend float_unary operator--(float_unary&, int); //постфиксный дружественный метод
	friend float_unary operator++(float_unary&, int); //постфиксный дружественный метод

	float_unary operator=(const float_unary&);
	friend float_unary& operator+(const float_unary&, float);
	friend float_unary& operator-(const float_unary&, float);
	friend float_unary& operator*(const float_unary&, float);
	friend float_unary& operator/(const float_unary&, float);
	float_unary operator+=(float);
	float_unary operator-=(float);
	float_unary operator*=(float); 
	float_unary operator/=(float);

	float& getValue();
	void setValue(float);
};

