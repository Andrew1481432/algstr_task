#ifndef CIAOD_TaskSeven_NODE_H
#define CIAOD_TaskSeven_NODE_H

#include <iostream>

using namespace std;

namespace TaskSeven {
	struct Node {
		// region Информационная часть узла (полезные данные)
		int data;
		// endregion

		Node *next;
		Node(int _data): data(_data), next(nullptr) {}
	};
}


#endif //CIAOD_TaskSeven_NODE_H
