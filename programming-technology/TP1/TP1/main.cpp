#include <iostream>
#include <stdio.h>
#include "queue.h"
#include "queue1.h"
#include "workWithQueue.h"
#include "element.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	/*menuOutput();*/

	int queueCount = 0; // изначальный размер массива очередей
	Queue* queues = new Queue[queueCount]; // это сам массив очередей
	QueueFunsks queueFunk; // В этом классе содержатся функции для работы с массивом очередей

	int newElementInQueue; // новый элемент 
	int selectedQueue; // выбранная очередь
	int selectedQueue2; // выбранная очередь 2
	int range; // размах

	char c = 11;
	cout << "menu output\n"
		"0 – Добавление очереди \n"
		"1 – Удаление очереди \n"
		"2 – Добавление элемента очереди \n"
		"3 – Извлечение элемента очереди\n"
		"4 – Вывод очереди на экран\n"
		"5 – Размах очереди (Задание)\n"
		"6 – Создание копии очереди\n"
		"7 – Слияние очередей и вывод результата на экран\n"
		"8 – Выход из программы\n"
		<< endl;
	do {
			switch (c)
			{
				// добавление очереди
			case '0':
				queueCount++;
				queues = queueFunk.pushQueue(queues, queueCount);
				cout << "Добавлена очередь с индексом " << queueCount - 1 << endl;
				break;
			case '1':
				// удаление очереди
				// проверка на пустоту массива очередей
				if (queueCount == 0) { cout << "Очередей нет" << endl; break; }

				queueCount--;
				queues = queueFunk.deleteQueue(queues, queueCount);
				cout << "Удалена очередь с индексом " << queueCount << endl;
				break;
			case '2':
				// Добавление элемента
				// проверка на пустоту массива очередей
				if (queueCount == 0) { cout << "Очередей нет" << endl; break; }
				// выбор очереди
				do {
					cout << "Введите индекс очереди: ";
					cin >> selectedQueue;
				} while (selectedQueue >= queueCount || selectedQueue < 0);

				cout << "Добавить элемент: ";
				cin >> newElementInQueue;

				queues[selectedQueue].addElement(newElementInQueue);
				cout << "Добавлен элемент '" << newElementInQueue <<
					"' в очередь с индексом " << selectedQueue << endl;
				break;
			case '3':
				// извлечение элемента
				if (queueCount == 0) { cout << "Очередей нет" << endl; break; }

				do {
					cout << "Введите индекс очереди: ";
					cin >> selectedQueue;
				} while (selectedQueue >= queueCount || selectedQueue < 0);

				queues[selectedQueue].deleteElement();
				cout << "Извлечен элемент" <<
					" из очереди с индексом " << selectedQueue << endl;
				break;
			case '4':
				// вывод очереди(ей) на экран
				if (queueCount == 0) { cout << "Очередей нет" << endl; break; }
				do {
					cout <<
						"1)Введите индекс очереди, если хотите вывести очередь по индексу.\n"
						<< "2)Введите '-1' - если хотите вывести все очереди: ";
					cin >> selectedQueue;
				} while (selectedQueue >= queueCount || selectedQueue < -1);
				if (selectedQueue == -1) {
					for (int i = 0; i < queueCount; i++) {
						cout << "Очередь [" << i << "]: ";
						queues[i].printQueue();
					}
				}
				else {
					cout << "\nОчередь [" << selectedQueue << "]: ";
					queues[selectedQueue].printQueue();
				}
				break;
			case '5':
				// размах очереди
				if (queueCount == 0) { cout << "Очередей нет" << endl; break; }

				do {
					cout << "Введите индекс очереди: ";
					cin >> selectedQueue;
				} while (selectedQueue >= queueCount || selectedQueue < 0);

				range = queueFunk.findRangeThroughChildClass(queues[selectedQueue]);
				cout << "Размах из очереди с индексом " << selectedQueue <<
					" равен " << range << endl;
				break;
			case '6':
				// копировать очередь
				if (queueCount == 0) { cout << "Очередей нет" << endl; break; }

				do {
					cout << "Введите индекс очереди: ";
					cin >> selectedQueue;
				} while (selectedQueue >= queueCount || selectedQueue < 0);

				queueCount++;
				queues = queueFunk.copyQueue(queues, queueCount, selectedQueue);
				cout << "Очередь номер " << selectedQueue <<
					" скопирована с индексом " << queueCount - 1 << endl;
				break;
			case '7':
				// слияние двух очередей
				if (queueCount < 2) { cout << "Очередей меньше двух" << endl; break; }

				do {
					cout << "Введите индекс 1-ой очереди: ";
					cin >> selectedQueue;
					cout << "Введите индекс 2-ой очереди: ";
					cin >> selectedQueue2;
				} while (selectedQueue >= queueCount || selectedQueue < 0 ||
					selectedQueue2 >= queueCount || selectedQueue2 < 0 ||
					selectedQueue == selectedQueue2);

				queueCount--;
				queues = queueFunk.mergeQueue(queues, queueCount, selectedQueue, selectedQueue2);
				for (int i = 0; i < queueCount; i++) {
					cout << "Очередь [" << i << "]: ";
					queues[i].printQueue();
				}
				break;
			default:
				for (int i = 0; i <= 100; i++)
					cout << "_";
				cout << "\n\nВыберите действие: ";
				break;
		}
	} while ((c = getchar()) != '8');
	//удаление очередей
	delete[] queues;
}
