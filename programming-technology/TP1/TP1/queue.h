#include "element.h"

#pragma once
class Queue
{
private:
	int size;
	Element *elements;
public:
	void addElement(int);
	void deleteElement();
	void printQueue();
	Queue();
	Queue(const Queue &);

	int getElementValue(int);
	Element getElement(int);
	int getSize();
};

