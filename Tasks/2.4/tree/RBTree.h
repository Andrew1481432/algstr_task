#ifndef CIAOD_TASKS_2_4_TREE_RBTREE_H
#define CIAOD_TASKS_2_4_TREE_RBTREE_H

#include "RBNode.h"

namespace fourth2Task {
	class RBTree {

			int size;

			RBNode *nil = nullptr;
			RBNode *root = nullptr;

			void print(RBNode *, int);

			void fixUp(RBNode *);

			void leftRotate(RBNode *);

			void rightRotate(RBNode *);

		public:

			RBTree();

			int getHeight();

			//добавление узла в красно-черное дерево
			void InsertNode(RBNode*);

			void symmetry(RBNode*);

			void symmetry();

			void width();

			void print();

			void printTest(RBNode*, int);
	};
}

#endif //CIAOD_TASKS_2_4_TREE_RBTREE_H
