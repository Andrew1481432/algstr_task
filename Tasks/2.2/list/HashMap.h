#ifndef CIAOD_SECOND2_HASHMAP_H
#define CIAOD_SECOND2_HASHMAP_H

#include "Node.h"
#include "Bucket.h"

#include <iostream>
#include <functional>

namespace second2Task {

class HashMap {
		const int SIZE = 16;

		int size; // размер таблицы
		int amount; // количество элементов в таблице

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

		// удалить из таблицы
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

		// найти запись по ключу
		Node* findNodeById(int id) {
			int hashCode = this->getHash(id);
			Bucket *bucket = &buckets[hashCode];
			if(bucket != nullptr && bucket->hash != -1) {
				return bucket->get(id);
			} else {
				return nullptr;
			}
		}

		// форматированный вывод таблицы в консоль
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

		// добавить в таблицу
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

		// хэш-функция
		int getHash(int id) {
			return id % this->size;
		}

		// рехэширование таблицы
		void resize() {
			Bucket *bucket;
			int oldSize = this->size;

			this->size *= 2;
			Bucket *newBuckets = new Bucket[this->size];
			for(int i = 0; i < oldSize; i++) {
				bucket = &this->buckets[i];

				Node* curEntry = bucket->entry;
				if(curEntry == nullptr) {
					continue;
				}
				if(curEntry->nextEntry == nullptr) {
					int hashCode = curEntry->getHash(this->size);
					Bucket *newBucket = &newBuckets[hashCode];
					newBucket->hash = hashCode;
					newBucket->add(curEntry);
				} else{
					Node *startEnt = bucket->entry;
					Node *prevEnt;
					do {
						curEntry = prevEnt = startEnt;
						while(curEntry->nextEntry != nullptr) {
							prevEnt = curEntry;
							curEntry = curEntry->nextEntry;
						}

						prevEnt->nextEntry = nullptr;
						int hashCode = curEntry->getHash(this->size);
						Bucket *newBucket = &newBuckets[hashCode];
						newBucket->hash = hashCode;
						newBucket->add(curEntry);
					} while(startEnt != curEntry);
				}
			}
			delete []buckets;
			this->buckets = newBuckets;
			cout << "Рехеширование прошло успешно\n";
		}

		// проверка не переполнение
		bool checkOverflow() {
			return (((double)amount + 1) / size) >= 0.75;
		}
	};

	ostream& operator << (ostream &dfdf, HashMap &m) {
		m.show();
		return dfdf;
	}
}

#endif //CIAOD_SECOND2_HASHMAP_H
