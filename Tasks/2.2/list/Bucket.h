#ifndef CIAOD_SECOND2_BUCKET_H
#define CIAOD_SECOND2_BUCKET_H

#include <iostream>

#include "Node.h"

namespace second2Task {
	struct Bucket {
		int hash = -1;

		Node* entry = nullptr;

		bool isEmpty() {
			return hash == -1;
		}

		void add(Node *entry) {
			if(this->entry == nullptr) {
				this->entry = entry;
			} else {
				Node *ent = this->entry;
				while(ent->nextEntry != nullptr) {
					ent = ent->nextEntry;
				}
				ent->nextEntry = entry;
			}
		}

		Node* get(int id) {
			if(this->entry != nullptr) {
				Node *ent = this->entry;
				while(ent != nullptr) {
					if(ent->id == id) {
						return ent;
					}
					ent = ent->nextEntry;
				}
			}
			return nullptr;
		}

		bool remove(int id) {
			if(this->entry != nullptr) {
				Node *ent = this->entry;
				if(ent->id == id) {
					if(ent->nextEntry != nullptr) {
						this->entry = ent->nextEntry;
					} else {
						this->entry = nullptr;
						hash = -1;
					}
					delete ent;
					return true;
				} else {
					Node *prevNode = entry;
					Node *nextNode = entry->nextEntry;
					Node *findNode = nullptr;
					if(nextNode != nullptr) {
						while(nextNode != nullptr) {
							if(nextNode->id == id) {
								findNode = nextNode;
								break;
							}
							prevNode = nextNode;
							nextNode = nextNode->nextEntry;
						}
						if(findNode != nullptr) {
							if(findNode->nextEntry != nullptr) {
								prevNode->nextEntry = findNode->nextEntry;
							} else {
								prevNode->nextEntry = nullptr;
							}

							delete findNode;
							return true;
						}
					}
				}
			}
			return false;
		}
	};
}


#endif //CIAOD_SECOND2_BUCKET_H
