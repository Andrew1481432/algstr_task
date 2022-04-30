#ifndef CIAOD_NODE_H
#define CIAOD_NODE_H

#include <iostream>

using namespace std;

namespace TaskSix {
	struct Node {
		// region Информационная часть узла (полезные данные)
		string numRecordBook; // (key) Номер зач. книжки (буквенно-цифровой)
		int numGroup; // Номер группы
		int mark; // оценка
		// endregion

		Node *next;
		Node *prev;
		Node(string _numRecordBook, int _numGroup, int _mark): numRecordBook(_numRecordBook),
		                                                        numGroup(_numGroup), mark(_mark),
																next(nullptr), prev(nullptr) {}
	};
}


#endif //CIAOD_NODE_H
