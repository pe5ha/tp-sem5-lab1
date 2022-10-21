#include <iostream>

#pragma once
class QueueFunsks {
public:
	QueueFunsks();
	Queue* pushQueue(Queue*, int);
	Queue* deleteQueue(Queue*, int);
	Queue* copyQueue(Queue*, int, int);
	Queue* mergeQueue(Queue*, int, int, int);
	int findRangeThroughChildClass(Queue);
};
