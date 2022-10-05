#ifndef CIAOD_SECOND2_BUCKET_H
#define CIAOD_SECOND2_BUCKET_H

#include <iostream>

#include "Node.h"

namespace second2Task {
	struct Bucket {
	private:
		bool closed = false;
	public:
		Node* entry = nullptr;
		int hash = -1;
		int i = 0;

		bool isClosed() {
			return closed;
		}

		void add(Node *entry) {
			this->entry = entry;
			closed = true;
		}

		void add(Node *entry, int i) {
			this->add(entry);
			this->i = i;
		}

		Node* get(int id) {

			return nullptr;
		}

		bool remove(int id) {

			return false;
		}

		void show() {
			if (!closed) {
				cout << "пусто";
				return;
			}
			cout << "ХЕШ BUCKET: " << hash << "\tитерация: " << i;
		}
	};
}


#endif //CIAOD_SECOND2_BUCKET_H
