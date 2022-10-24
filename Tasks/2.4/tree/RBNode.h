#ifndef CIAOD_TASKS_2_4_TREE_RBNODE_H
#define CIAOD_TASKS_2_4_TREE_RBNODE_H

#include <iostream>

using namespace std;

namespace fourth2Task {
	struct RBNode { // структура для представления узлов дерева
		//Тип значения узла: Строка – имя
		string name;

		RBNode *parent = nullptr;
		RBNode *left = nullptr;
		RBNode *right = nullptr;

		// 0 - черный, 1 - красный
		bool color;

		RBNode(string name) {
			this->name = name;
		}
	};
}

#endif //CIAOD_TASKS_2_4_TREE_RBNODE_H
