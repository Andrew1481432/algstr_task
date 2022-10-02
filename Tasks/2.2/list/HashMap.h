#ifndef CIAOD_SECOND2_HASHMAP_H
#define CIAOD_SECOND2_HASHMAP_H

#include "Node.h"
#include "Bucket.h"

#include <iostream>
#include <functional>

namespace second2Task {

class HashMap {
		const int SIZE = 16;

		int size; // размер Map (макс. кол-во записей)
		int amount; // кол-во записей

		Bucket* buckets = nullptr; // массив полезных данных

	public:
		HashMap() {
			this->size = SIZE;
			this->amount = 0;

			buckets = new Bucket[this->size];
		}

		~HashMap() {
			Bucket *bucket;
			for(int i = 0; i < this->size; i++) {
				bucket = &this->buckets[i];
				Node* ent = bucket->entry;
				Node* tempEnt;
				while(ent != nullptr) {
					tempEnt = ent;
					ent = ent->nextEntry;
					delete tempEnt;
				}
			}
			delete []buckets;
		}

		void remove(int id) {
			int code = this->getHash(id);

			bool resultEx = buckets[code].remove(id);
			if(resultEx) {
				amount--; // уменьшаем кол-во записей
				cout << "Удаление прошло успешно!\n";
			} else {
				cout << "Нет элемента с таким номером\n";
			}
		}

		Node* findNodeById(int id) {
			int hashCode = this->getHash(id);
			Bucket *bucket = &buckets[hashCode];
			if(bucket != nullptr && bucket->hash != -1) {
				return bucket->get(id);
			} else {
				return nullptr;
			}
		}

		void show() {
			bool flag;
			for (int i = 0; i < size; i++) { // проходимся по buckets
				cout << i + 1 << ") ";
				flag = false;
				if (!buckets[i].isEmpty()) {
					Node *node = buckets[i].entry;
					while(node != nullptr) {
						if (flag) cout << "      ";
						node->show();
						flag = true;

						node = node->nextEntry;
					}
				} else {
					cout << "-----пусто-----" << endl;
				}
			}
		}

		void insert(Node *node) {
			if (this->checkOverflow()) {
				this->resize();
			}
			int hashCode = node->getHash(this->size);

			Bucket *bucket = &this->buckets[hashCode];
			bucket->hash = hashCode;
			bucket->add(node);

			amount++;
		}

	private:

		int getHash(int id) {
			return id % this->size;
		}

		void resize() {
			Bucket *bucket;
			int oldSize = this->size;

			this->size *= 2;
			Bucket *newBuckets = new Bucket[this->size];
			for(int i = 0; i < oldSize; i++) {
				bucket = &this->buckets[i];

				Node* ent = bucket->entry;
				if(ent == nullptr) {
					continue;
				}
				if(ent->nextEntry == nullptr) {
					int hashCode = ent->getHash(this->size);
					Bucket *newBucket = &newBuckets[hashCode];
					newBucket->hash = hashCode;
					newBucket->add(ent);
				} else{
					Node *startEnt = bucket->entry;
					Node *lastEnt;
					do {
						ent = startEnt;
						lastEnt = startEnt;

						while(ent->nextEntry != nullptr) {
							lastEnt = ent;
							ent = ent->nextEntry;
						}
						lastEnt->nextEntry = nullptr;

						int hashCode = ent->getHash(this->size);
						Bucket *newBucket = &newBuckets[hashCode];
						newBucket->hash = hashCode;
						newBucket->add(ent);
					} while(startEnt != ent);
				}
			}
			delete []buckets;
			this->buckets = newBuckets;
			cout << "Рехеширование прошло успешно\n";
		}

		bool checkOverflow() { // проверка не переполнение
			return (((double)amount + 1) / size) >= 0.75;
		}
	};

	ostream& operator << (ostream &dfdf, HashMap &m) {
		m.show();
		return dfdf;
	}


}

#endif //CIAOD_SECOND2_HASHMAP_H