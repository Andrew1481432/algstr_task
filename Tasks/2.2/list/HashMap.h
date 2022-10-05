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
				if(bucket->isClosed()) {
					bucket->remove();
				}
			}
			delete []buckets;
		}

		// удалить Node из таблицы
		void remove(int id) {
			Bucket *bucket = findBucketById(id);
			if(bucket != nullptr) {
				bucket->remove();
				cout << "Удаление прошло успешно!\n";
			} else {
				cout << "Нет элемента с таким номером\n";
			}
		}

		// найти ведро по ключу
		Bucket* findBucketById(int id) {
			int i = 0;
			int hashCode = this->getHash(id, i);
			Bucket *bucket = &this->buckets[hashCode];
			while(!bucket->isClosed() || bucket->isClosed() && bucket->getEntry()->id != id) {
				i++;
				if(this->checkIterationLimit(i)) {
					return nullptr;
				}
				hashCode = this->getHash(id, i);
				bucket = &this->buckets[hashCode];
			}
			return bucket;
		}

		// форматированный вывод таблицы в консоль
		void show() {
			for (int i = 0; i < size; i++) { // проходимся по buckets
				cout << i + 1 << ") ";
				Bucket *bucket = &buckets[i];
				if (bucket->isClosed()) {
					Node *node = bucket->getEntry();
					cout << "(";
					bucket->show();
					cout << ")";
					cout << "      ";
					node->show();
				} else {
					cout << "-----пусто-----" << endl;
				}
			}
		}

		// добавить в таблицу
		void insert(Node *node) {
			if(isFull()) { // temp
				cout<<("ERROR : Hash Table Full\n");
				return;
			}

			int i = 0;
			int hashCode = this->getHash(node->id, i);
			Bucket *bucket = &this->buckets[hashCode];
			while(bucket->isClosed()) {
				i++;
				if(this->checkIterationLimit(i)) {
					// TODO
					cout<<("ERROR : Suitable hashes with "+std::to_string(hashCode)+" for the table are busy\n");
					cout<<("ERROR : You need to try rehash and try again to insert the node\n");
					return;
				}
				hashCode = this->getHash(node->id, i);
				bucket = &this->buckets[hashCode];
			}
			bucket->hash = hashCode;
			bucket->add(node, i);

			amount++;
		}

	private:

		int getHash(int id, int i) {
			//адрес=h(x)+ih2(x)
			int key = (this->getHash1(id) + i*this->getHash2(id))%this->size;
			if(key>SIZE-1) {
				throw std::invalid_argument(std::to_string(key)+" > SIZE | "+"iteration: " + std::to_string(i));
			}
			return key;
		}

		int getHash1(int id) {
			return id % this->size;
		}

		int getHash2(int id) {
			return id % (this->size-1) + 1;
		}

		/**
		 * todo temp function
		 *
		 * @deprecated
		 */
		bool isFull() {
			return this->amount == SIZE;
		}

		bool checkIterationLimit(int i) {
			return i>amount;
		}

		// проверка не переполнение
		bool checkOverflow() {
			return (((double) amount + 1) / size) >= 0.75;
		}

		// рехэширование таблицы
		void resize() {
			// TODO
			cout << "Рехеширование прошло успешно\n";
		}
	};

	ostream& operator << (ostream &dfdf, HashMap &m) {
		m.show();
		return dfdf;
	}
}

#endif //CIAOD_SECOND2_HASHMAP_H
