#pragma once

#include "float_unary.h"

class Stack
{
private:
	struct Cell{
		float_unary float_unary_element;
		Cell* nextElem;
		~Cell();
	} C;
	Cell* top = nullptr;
	int size;
public:
	explicit Stack();
	explicit Stack(int);
	explicit Stack(const Stack&);

	~Stack();


	// стековские операции
	void pushElement(float); 
	void pushElement();
	void pop();

	// set элементов
	void setLastValue(float);
	//void setElement(float_unary);

	// получение приватных элементов
	int getSize();
	float& getLastValue();
	float_unary& getLastElement();
	float_unary& getElements();
	void printStack();
	void output(Cell* a);
};

