#include "zero2Task.h"

namespace zero2Task {
	string DIR_RESOURCES = "/Users/testerdev/Desktop/Учеба/Уник/семестр_3/сиаод/практика_1/";

	int arr[1 + N / BITSPERWORD]; // 31251

	/*
Алгоритм на псевдокоде
//Часть 1: инициализация массива битов нулями

for i←0 tо n
bit[i]:=0;

//Часть 2: Заполнение битового массива значениями.
//Чтение числа из файла в переменную i

bit[i]:=1

//Часть 3: Формирование упорядоченного выходного файла

for i←0 tо n
if bit[i]=1 then записать i в файл;
	 */

	/**
	 * Реализовать алгоритм сортировки данных, хранящихся в файле из занятия 1.
	 */
	std::string Zero2Task::getName(){
		return "Практическая работа № 2.0";
	}

	std::string Zero2Task::getId(){
		return "2.0";
	}

	void set(int i) {
		arr[i >> SHIFT] |= (1 << (i & maska));
	}

	void clr(int i) {
		arr[i >> SHIFT] &= (1 << (i & maska));
	}

	void setI(int i) {
		arr[i >> SHIFT] &= (1 << (i & maska));
	}

	bool createFileWithRandN() {
		ofstream test(DIR_RESOURCES+"file.txt");
		if (!test) {
			cout << "Ошибка выполнения программы, не удалось найти файл file.txt!" << endl;
			return EXIT_FAILURE;
		}
		cout << "Вывод сгенерированного массива: " << endl;
		for (int i = 0; i < N; i++) {
			int magicRand = (rand()%N)+1;
			test << magicRand << " ";
			cout << magicRand << ((i != N-1) ? "," : "");
		}
		cout << endl;
		test.close();
		return EXIT_SUCCESS;
	}

	int Zero2Task::execute(){
		cout << "Хотите создать файл с рандомными значениями?\n0 - Нет\n1 - Да\n>> ";
		int val;
		cin >> val;
		if (val == 1) {
			bool res = createFileWithRandN();
			if(EXIT_FAILURE == res) {
				return res;
			}
		}

		//Часть 1: инициализация массива битов нулями
		for (int i(0); i < N; i++) {
			arr[i] = 0;
		}

		//Часть 2: Заполнение битового массива значениями.
		fstream test(DIR_RESOURCES+"file.txt", ios::in);
		if (!test) {
			cout << "Ошибка выполнения программы, не удалось найти файл file.txt!" << endl;
			return EXIT_FAILURE;
		}

		int i = 0;
		//Чтение числа из файла в переменную i
		while (test >> i) {
			set(i);
		}
		test.close();

		//Часть 3: Формирование упорядоченного выходного файла
		test.open(DIR_RESOURCES+"file.txt", ios::out);
		cout << "Вывод упорядоченного выходного файла: " << endl;
		for (int i(0); i < N; i++) {
			int val = arr[i >> SHIFT];
			val >>= (i & maska);
			if((val & 1) == 1) {
				cout << i << ((i != N-1) ? "," : "");
				test << i << " ";
			}
		}
		cout << endl;
		test.close();
		return EXIT_SUCCESS;
	}
}
