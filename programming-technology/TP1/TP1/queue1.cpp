#include "queue1.h"
#include <iostream>

using namespace std;

int Queue1::findRange(Queue q) {
	int size = q.getSize();
	if (size < 1) { return -1; }
	if (size == 1) {  return 0; }
	int maxElement = q.getElementValue(0);
	int minElement = q.getElementValue(0);
	int newElem;
	for (int i = 0; i < size; i++) {
		newElem = q.getElementValue(i);
		if (newElem > maxElement) { maxElement = newElem; }
		if (newElem < minElement) { minElement = newElem; }
	}
	return maxElement - minElement;
}