#ifndef CIAOD_LIST_TaskSeven_H
#define CIAOD_LIST_TaskSeven_H

#include "Node.h"

namespace TaskSeven {
	struct List {
			Node *first;
			Node *last;

			List() : first(nullptr), last(nullptr) {}

			bool is_empty();
			void push_front(int);
			void push_back(int);
			void print();
			List* reverse();

			~List();
		private:
			void reverse(List*, Node*);
	};
}

#endif //CIAOD_LIST_TaskSeven_H
