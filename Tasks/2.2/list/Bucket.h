#ifndef CIAOD_SECOND2_BUCKET_H
#define CIAOD_SECOND2_BUCKET_H

#include <iostream>

#include "Node.h"

namespace second2Task {
	struct Bucket {
	private:
		bool closed = false;
		Node* entry = nullptr;
	public:
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

		Node* getEntry() {
			return this->entry;
		}

		void remove() {
			if(isClosed() && this->entry != nullptr) {
				closed = false;
				delete this->entry;
				this->entry = nullptr;
			} else {
				throw std::invalid_argument("You are trying to remove a non-existent element");
			}
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
