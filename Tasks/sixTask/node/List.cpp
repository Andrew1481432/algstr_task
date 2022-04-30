#include "List.h"

#include "../../../Utils/Utils.h"

using namespace TaskSix;
using namespace Utils;

bool operator < (Node &p2, Node &p1) { // a1 > a2
	bool result = p1.numRecordBook.compare(p2.numRecordBook)>0;
	//bool result = Utils::getNumStr(p1.numRecordBook)>Utils::getNumStr(p2.numRecordBook);
	return result;
}

bool List::is_empty() {
	return first == nullptr;
}

void List::insertBefore(Node *p, Node* next, uint64_t &Cf, uint64_t &Mf) {
	if(next != nullptr) {
		Node *prev = next->prev;
		if (prev == nullptr) { // первый элемент
			p->next = first;
			first->prev = p;
			Mf+=2;
			first = p;
		} else {
			prev->next = p;
			next->prev = p;
			p->prev = prev;
			p->next = next;
			Mf+=4;
		}
	} else { // вставка последним
		last->next = p;
		p->prev = last;
		Mf+=2;
		last = p;
	}
}

void List::push_front(string numRecordBook, int numGroup, int mark, uint64_t &Cf, uint64_t &Mf) {
	Node *p = new Node(numRecordBook, numGroup, mark);

	Cf++;
	if (is_empty()) {
		first = p;
		last = p;
		return;
	} else {
		Node *selectNode = first;

		while (selectNode && *selectNode < *p) {
			Cf++;
			selectNode = selectNode->next;
		}
		if(selectNode != nullptr){
			Cf++;
		}

		insertBefore(p, selectNode, Cf, Mf);
	}
}

Node* List::find(string numRecordBook) {
	Node *selectNode = first;
	while(selectNode) {
		if(selectNode->numRecordBook == numRecordBook) {
			return selectNode;
		}
		selectNode = selectNode->next;
	}
	return nullptr;
}

void List::remove(Node *selectNode) {
	if(selectNode->prev == nullptr) { // первый элемент
		first = selectNode->next;
	} else {
		selectNode->prev->next = selectNode->next;
	}

	if(selectNode->next == nullptr) { // последний элемент
		last = selectNode->prev;
	} else {
		selectNode->next->prev = selectNode->prev;
	}
	delete selectNode;
}

void List::print(int mode) {
	Node *selectNode = mode==LEFT?first:last;
	while(selectNode) {
		cout << "Номер зачетной книжки: " << selectNode->numRecordBook << " Номер группы: " << selectNode->numGroup << " Оценка: " << selectNode->mark << endl;
		selectNode = mode==LEFT?selectNode->next:selectNode->prev;
	}
}

/*
Удалить узлы с указанным
номером группы.
 */
int List::remove(int numGroup) {
	Node *selectNode = first;
	int i = 0;
	while(selectNode) {
		if(selectNode->numGroup == numGroup) {
			remove(selectNode);
			i++;
		}
		selectNode = selectNode->next;
	}
	return i;
}

int List::remove(string numRecordBook) {
	Node *selectNode = first;
	int i = 0;
	while(selectNode) {
		if(selectNode->numRecordBook == numRecordBook) {
			remove(selectNode);
			i++;
		}
		selectNode = selectNode->next;
	}
	return i;
}

/*
Сформировать новый список из
исходного, включив в него узлы с
оценкой неуд, исключив их при
этом из исходного списка
 */
List* List::getListBadMark() {
	uint64_t test;

	List *list = new List();
	Node *selectNode = first;
	while(selectNode) {
		Node *nodeNext = selectNode->next;
		if(selectNode->mark == MARK::UNSATISFACTORY) {
			list->push_front(selectNode->numRecordBook, selectNode->numGroup, selectNode->mark, test, test);
			remove(selectNode);
		}
		selectNode = nodeNext;
	}
	return list;
}

List::~List() {
	Node *selectNode = first;
	while(selectNode) {
		delete selectNode;
		selectNode = selectNode->next;
	}
}