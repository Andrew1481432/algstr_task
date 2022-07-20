#include "List.h"

#include "../../../Utils/Utils.h"

using namespace Utils;
using namespace TaskSeven;

static int countCallsReverse;

bool List::is_empty() {
	return first == nullptr;
}

/**
 * Добавляет элемент в самое начало списка
 * @param data
 */
void List::push_front(int data) {
	Node *p = new Node(data);
	if (is_empty()) {
		first = p;
		last = p;
		return;
	}
	p->next = first;
	first = p;
}


/**
 * Добавляет элемент в самый конец списка
 * @param data
 */
void List::push_back(int data) {
	Node *p = new Node(data);
	if (is_empty()) {
		first = p;
		last = p;
		return;
	}
	last->next = p;
	last = p;
}

void List::reverse(List* list, Node *node) {
	countCallsReverse++;
	if(node == nullptr) {
		return;
	}
	list->push_front(node->data);
	reverse(list, node->next);
}

/**
 * Создать новый однонаправленный список из исходного однонаправленного списка,
 * записав его элементы, наоборот.
 *
 * Вид: Линейная рекурсия
 * Вызов: Косвенная
 *
 * @return
 */
List* List::reverse() {
	List* reversedList = new List();
	reverse(reversedList, first);

	cout << "Максимальная глубина рекурсии reverse: " << countCallsReverse << endl;
	countCallsReverse = 0;

	return reversedList;
}

void List::print() {
	if (is_empty()) return;
	Node *node = first;

	cout << "Значения узлов: ";
	while (node) {
		cout << node->data << ", ";
		node = node->next;
	}
	cout << "\b\b\n";
}

List::~List() {
	Node *select = first;
	Node *next = nullptr;
	while(select != nullptr) {
		next = select->next;
		delete select;
		select = next;
	}
}