#ifndef CIAOD_LIST_H
#define CIAOD_LIST_H

#include "Node.h"

namespace TaskSix {
	enum PRINT_MODE{
		LEFT = 0, //Слева направо
		RIGHT //Справа налево
	};

	enum MARK{
		UNSATISFACTORY = 2,
		SATISFACTORY,
		GOOD,
		GREAT
	};

	struct List {
			Node *first;
			Node *last;

			List() : first(nullptr), last(nullptr) {}

			bool is_empty();
			void push_front(string, int, int, uint64_t&, uint64_t&);

			/** поиск по номеру зачетной книжки **/
			Node* find(string);
			void remove(Node *);
			/** удаление по номеру группы **/
			int remove(int);
			/** удаление по ключу **/
			int remove(string);
			/** Вывод **/
			void print(int);
			/** Новый список с плохими оценками **/
			List* getListBadMark();

			~List();
		private:
			/** элемент, элемент перед каким вставляем **/
			void insertBefore(Node *, Node*, uint64_t&, uint64_t&);
	};
}

#endif //CIAOD_LIST_H
