#ifndef CIAOD_SECOND2_NODE_H
#define CIAOD_SECOND2_NODE_H

#include <iostream>

using namespace std;

namespace second2Task {

	// вариант 1: цепное хеширование
	// читательский абонемент
	// номер читательского (5-значное число) (ключ) - фио, адрес
	struct Node {
		int id = -1; // номер абонемента (ключ)
		string name; // фио
		string address; // адрес

		Node* nextEntry;

		Node(int id, string name, string address) {
			this->id = id;
			this->name = name;
			this->address = address;
		}

		// хэш-функция
		int getHash(int sizeArr) {
			return this->id % sizeArr;
		}

		// вывод
		void show() {
			if (id < 0) {
				cout << "пусто";
				return;
			}
			cout << id << "\tФИО: " << name << ", адрес: " << address << "\n";
		}
	};
}


#endif //CIAOD_SECOND2_NODE_H
