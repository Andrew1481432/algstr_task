#include "sevenTask.h"

using namespace Utils;
//https://www.cyberforum.ru/cpp-beginners/thread2160352.html

namespace TaskSeven {
	enum ModeWork {
		RANDOM = 1,
		INPUT,
		DESC, // DESCending убывающий
		ASC // ascending возрастающий
	};

	/**
	 * Пузырьковая сортировка
	 *
	 * Вид: Линейная рекурсия
	 * Вызов: прямой
	 *
	 * @param start указатель на начало динамического массива
	 * @param end указатель на конец динамического массива
	 * @param depth int
	 */
	void recSimpleTradeSort(int* start, int* end, int depth = 0){
		bool isSort = false;
		for(int *i = start; i < end; i++) {
			if(*i>*(i+1)) {
				isSort = true;
				std::swap(*i,*(i+1));
			}
		}
		if(isSort) {
			recSimpleTradeSort(start, end-1, depth+1);
		} else {
			cout << "Максимальная глубина рекурсии: " << depth << endl;
		}
	}

	void printArr(int *&arr, int N, const string& name = "") {
		// region вывод массива
		//cout << "Вывод массива (начало) " << name << endl;
		cout << "=-= " << name << " =-=" << endl;
		for(int i(0); i < N; i++) {
			cout << arr[i] << ((i != N-1) ? ", " : "");
		}
		cout << endl;
		//cout << "Вывод массива (конец) " << name << endl;
		// endregion
	}

	void executeTask1() {
		cout << "Размер массива = ";
		int N = Utils::getInput<int>();
		int *arr = new int[N];

		cout << "Режим работы программы:\n>> 1 - случайное заполнение.\n>> 2 - ручной ввод.\n>> 3 - (убывание) худший случай.\n>> 4 - (возрастание) лучший случай.\n>> Введите ID режима работы: ";
		int modeWork = Utils::getInput<int>();

		switch (modeWork) {
			case RANDOM:
				// region заполнение массива рандомными числами
				for(int i = 0; i < N; i++) {
					int magicRand = rand() % N + 1;

					arr[i] = magicRand;
				}
				// endregion
				break;

			case INPUT:
				for(int i = 0; i < N; i++) {
					cout << "arr[" << i+1 << "/" << N << "]=";
					int inp = Utils::getInput<int>();
					arr[i] = inp;
				}
				break;

			case DESC:
				// (убывание) худший случай
				for(int i = 0; i < N; i++) {
					arr[i] = N-i;
				}
				break;

			case ASC:
				// (возрастание) лучший случай
				for(int i = 0; i < N; i++) {
					arr[i] = i+1;
				}
				break;

			default:
				cout << "Режим работы не обнаружен!" << endl;
				return;
		}
		printArr(arr, N, "Исходный массив");
		recSimpleTradeSort(arr, arr+(N-1));
		printArr(arr, N, "Отсортированный массив");
		delete []arr;
	}

	void executeTask2() {
		cout << "Введите значения для заполнения List!" << endl;
		cout << "Введите размер List: ";
		int N = getInput<int>();
		int num;
		List* list = new List();
		for(int i = 0; i<N; i++) {
			cout << i+1 <<") узел = ";
			num = getInput<int>();
			list->push_back(num);
		}
		List* reversedList = list->reverse();
		reversedList->print();

		delete reversedList;
		delete list;
	}
}
using namespace TaskSeven;

std::string SevenTask::getName() {
	return "Практическая работа № 7";
}

int SevenTask::getId() {
	return 7;
}

void SevenTask::execute() {
	cout << "Выберите задание:\n>> 1 - Задание № 1\n>> 2 - Задание № 2\n>> Введите ID задания: ";
	int taskSelected = Utils::getInput<int>();
	switch(taskSelected) {
		case 1: // Сортировка массива по возрастанию
			executeTask1();
			break;

		case 2:
			executeTask2();
			break;

		default:
			cout << "Задание "<<taskSelected<<" не найдено!" << endl;
	}
}