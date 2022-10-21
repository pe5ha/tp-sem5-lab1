#include "Stack.h"
#include <iostream>

using namespace std;

// конструктор Stack
// ќпределение
Stack::Stack() {
	Cell* c = new Cell();
	srand(time(0));
	c->float_unary_element.setValue((float)(rand()) / RAND_MAX * 1000);
	c->nextElem = top;
	top = c;
	size = 1;
}
//конструктор копировани€
Stack::Stack(const Stack& oldElements) :
	C(oldElements.C), top(oldElements.top), size(oldElements.size)
{
	;
}
Stack::Stack(int newSize) {
	Cell* c = new Cell();
	srand(time(0)); // инициализаци€ генератора случайных чисел с помощью метки времени 0.
	
	for (int i = 0; i < newSize; i++) {
		pushElement((float)(rand()) / RAND_MAX * 1000);
	}
}
//десторуктор
Stack::~Stack() {
	delete top;
}
Stack::Cell::~Cell() {
	delete nextElem;
}

// вывод стека
void Stack::printStack() {
	output(top);
}
// получение последнего значени€ —тека
float& Stack::getLastValue() {
	return top->float_unary_element.getValue();
}
float_unary& Stack::getLastElement() {
	return top->float_unary_element;
}
void Stack::setLastValue(float newValue) {
	top->float_unary_element.setValue(newValue);
}
//void Stack::setElement(float_unary newValue) {
//	
//}
int Stack::getSize() {
	return this->size;
}


// —тек операции
void Stack::pushElement(float newElement) {
	Cell* c = new Cell();
	c->float_unary_element.setValue(newElement);
	c->nextElem = top;
	top = c;
	this->size++;
}
void Stack::pushElement() {
	float newElement = (float)(rand()) / RAND_MAX * 1000;
	Cell* c = new Cell();
	c->float_unary_element.setValue(newElement);
	c->nextElem = top;
	top = c;
	this->size++;
}

void Stack::pop() {
	if (size == 0) { cout << "—тек пуст" << endl; return; }
	Cell* a;
	a = top;
	top = a->nextElem;
	this->size--;
}
void Stack::output(Cell* a)
{
	if (a == NULL) return;
	output(a->nextElem);
	cout << a->float_unary_element.getValue() << " ";
}
