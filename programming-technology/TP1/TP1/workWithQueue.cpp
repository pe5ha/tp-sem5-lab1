#include <iostream>
#include <stdio.h>
#include "queue.h"
#include "queue1.h"
#include "element.h"
#include "workWithQueue.h"

using namespace std;

QueueFunsks::QueueFunsks() {}
Queue* QueueFunsks::pushQueue(Queue* oldQueues, int queueCount)
{
	Queue* newQueues = new Queue[queueCount];
	for (int i = 0; i < queueCount - 1; i++) {
		newQueues[i] = oldQueues[i];
	}

	delete[] oldQueues;
	return newQueues;
}
Queue* QueueFunsks::deleteQueue(Queue* oldQueues, int queueCount)
{
	Queue* newQueues = new Queue[queueCount];
	for (int i = 0; i < queueCount - 1; i++) {
		newQueues[i] = oldQueues[i];
	}

	delete[] oldQueues;
	return newQueues;
}
Queue* QueueFunsks::copyQueue(Queue* oldQueues, int queueCount, int selectedQueue)
{
	Queue copyQ(oldQueues[selectedQueue]); // метод копирования в действии

	Queue* newQueues = new Queue[queueCount];
	for (int i = 0; i < queueCount - 1; i++) {
		newQueues[i] = oldQueues[i];
	}
	newQueues[queueCount - 1] = copyQ;
	delete[] oldQueues;
	return newQueues;
}
Queue* QueueFunsks::mergeQueue(Queue* oldQueues, int queueCount, int selectedQueue1, int selectedQueue2)
{
	int sizeQueue1 = oldQueues[selectedQueue1].getSize();
	int sizeQueue2 = oldQueues[selectedQueue2].getSize();
	int sizeElementsInQueues = sizeQueue1 + sizeQueue2;

	int numberOfMergeQueue =
		(selectedQueue1 < selectedQueue2) ? selectedQueue1 : selectedQueue2; // выбор индекса
	Queue* newQueues = new Queue[sizeElementsInQueues];

	Element elem;
	int i = 0; int k = 0;
	while (i < sizeElementsInQueues) {
		if (i < sizeQueue1) { // если очередь ещё не закончилась
			elem = oldQueues[selectedQueue1].getElement(i);
			newQueues[numberOfMergeQueue].addElement(elem.value);
		}
		if (i < sizeQueue2) { // если очередь ещё не закончилась
			elem = oldQueues[selectedQueue2].getElement(i);
			newQueues[numberOfMergeQueue].addElement(elem.value);
		}
		i++;
	}

	for (int i = 0; i < queueCount; i++) {
		if (i == selectedQueue1 || i == selectedQueue2) { continue; }
		newQueues[i] = oldQueues[i];
	}

	delete[] oldQueues;
	return newQueues;
}
int QueueFunsks::findRangeThroughChildClass(Queue q)
{
	Queue1 dQueue;
	int range = dQueue.findRange(q);

	return range;
}
