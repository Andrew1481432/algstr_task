#include "secondTask.h"
#include "../../Utils/Utils.h"
#include <chrono>
#include <iomanip>

namespace TaskSecond {

	void printArr(unique_ptr<int[]> &arr, int N, const string& name = "") {
		// region вывод массива
		cout << "Вывод массива (начало) " << name << endl;
		for(int i(0); i < N; i++) {
			cout << arr[i] << ((i != N-1) ? ", " : "");
		}
		cout << endl;
		cout << "Вывод массива (конец) " << name << endl;
		// endregion
	}

	unique_ptr<int[]> copy(unique_ptr<int[]> &arr, int len) {
		std::unique_ptr<int[]> copyResult(new int[len]);
		for (int i = 0; i < len; i++) {
			copyResult[i] = arr[i];
		}
		return copyResult;
	}

	enum ModeWork {
		RANDOM = 1,
		INPUT
	};

	std::string SecondTask::getName() {
		return "Практическая работа № 1.2";
	}

	std::string SecondTask::getId() {
		return "1.2";
	}

	void dumpChrono() {
		auto begin = chrono::steady_clock::now();
		getchar();
		auto end = chrono::steady_clock::now();
		auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
		cout << "The time: " << elapsed_ms.count() << " ms\n";
	}

	/*void rvereseArray(int *arr, int start, int end, int &Mf){
		while (start < end){
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			Mf += 1;

			start++;
			end--;
		}
	}

	void shift(int *a, int startLen, int s, int size, int &Mf){
		s = size - s; // если убрать эту строку, то сдвиг будет идти "влево"

		rvereseArray(a, startLen, s-1, Mf);
		//rvereseArray(test, startLen+s-1, size-1); todo s = size - s; если убрать эту строку, то сдвиг будет идти "влево"
		rvereseArray(a, startLen, size-1, Mf);

		a += startLen;
		std::reverse(a, a + s);
		//std::reverse(a + s, a + size);
		std::reverse(a, a + size);
	}*/

	void selectSort(unique_ptr<int[]> &arr, int size) {
		unsigned long long int Cf = 0;
		unsigned long long int Mf = 0; // 8 байт

		auto begin = chrono::steady_clock::now();
		for (int i = 0; i < size - 1; i++) {
			int minKey = i;
			for (int j = i+1; j < size; j++) { // поиск минимального элемента массива
				Cf++;
				if (arr[j] < arr[minKey]) {
					minKey = j;
				}
			}

			if (minKey != i) {
				Mf++;
				std::swap(arr[i], arr[minKey]);
			}
		}

		unsigned long long int Tp = Cf+Mf;
		auto end = chrono::steady_clock::now();
		auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
		cout << "Rоличество операций сравнения Cf = " << Cf << endl;
		cout << "Фактическое количество операций перемещения Mf = " << Mf << endl;
		cout << "Тп(n)=Cф+Mф: " << Tp << endl;
		cout << "Время выполнения T(n) = " << elapsed_ms.count() << endl;
	}

	void shiftRight(int *a, int startKey, int s, int size, unsigned long long int &Mf){
		for(int i = size-1; i-s>=startKey; i--) {
			a[i] = a[i-s];
			Mf++;
		}
		for(int i = (startKey+s)-1; i>=startKey; i--) {
			a[i] = 0;
		}
	}

	void insertionSort(unique_ptr<int[]> &arr, int size) {
		unsigned long long Cf = 0;
		unsigned long long int Mf = 0; // 8 байт

		int *result = new int[size];
		for(int i(0); i < size; i++) {
			result[i] = INT32_MAX;
		}

		auto begin = chrono::steady_clock::now();
		for (int i = 0; i < size; i++) {
			//int j = size-1;
			int j = i;
			for(; result[j] > arr[i] && j >= 0; j--) { // поиск подходящего места для элемента массива
				Cf++;
			}
			Cf++;

			shiftRight(result, j + 1, 1, size, Mf);
			result[j+1] = arr[i];
		}

		arr.reset(result);

		unsigned long long int Tp = Cf+Mf;
		auto end = chrono::steady_clock::now();
		auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
		cout << "Rоличество операций сравнения Cf = " << Cf << endl;
		cout << "Фактическое количество операций перемещения Mf = " << Mf << endl;
		cout << "Тп(n)=Cф+Mф: " << Tp << endl;
		cout << "Время выполнения T(n) = " << elapsed_ms.count() << endl;
	}



	/**
	 * Простого обмена (Exchange sort) метод «пузырька»
	 *
	 * количество операций сравнения Сф
	 * фактическое количество операций перемещения Мф
	 * вычислением времени выполнения T(n) в мс
	 */
	void simpleTradeSort(unique_ptr<int[]> &arr, int size) {
		unsigned long long int Cf = 0;
		unsigned long long int Mf = 0;

		auto begin = chrono::steady_clock::now();

		for (int i = size-1; i > 0; i--) {
			Cf++;

			for (int j = 0; j < i; j++) {
				Cf++;

				Cf++;
				if (arr[j]>arr[j+1]) {
					Mf += 3;
					std::swap(arr[j], arr[j + 1]);
				}
			}
			Cf++;
		}
		Cf++;

		unsigned long long int Tp = Cf+Mf;
		auto end = chrono::steady_clock::now();
		auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
		cout << "Rоличество операций сравнения Cf = " << Cf << endl;
		cout << "Фактическое количество операций перемещения Mf = " << Mf << endl;
		cout << "Тп(n)=Cф+Mф: " << Tp << endl;
		cout << "Время выполнения T(n) = " << elapsed_ms.count() << endl;
	}


	void executeTask1(unique_ptr<int[]> &arr, int N) {
		// region debug
//		int *test = arr.get();
//		int *debug = new int[10];
//		for(int i = 0; i < 10; i++) {
//			debug[i] = test[i];
//		}
		// endregion

		printArr(arr, N, "Исходный массив");
		simpleTradeSort(arr, N);
		printArr(arr, N, "Отсортирован массив методом простого обмена");
	}

	void executeTask3(unique_ptr<int[]> &arr, int N) {
		printArr(arr, N, "Исходный массив");
		insertionSort(arr, N);
		printArr(arr, N, "Отсортирован массив методом вставки");
	}

	void executeTask4(unique_ptr<int[]> &arr, int N) {
		printArr(arr, N, "Исходный массив");
		selectSort(arr, N);
		printArr(arr, N, "Отсортирован массив методом вставки");
	}

	int SecondTask::execute() {
		srand(time(NULL));
		cout << "Выберите задание:\n>> 1 - Задание № 1\n>> 2 - Задание № 2\n>> 3 - Задание № 3\n>> *4 - Задание № 4\n>> Введите ID задания: ";
		int taskSelected = Utils::getInput<int>();

		cout << "N = ";
		int N = Utils::getInput<int>();
		std::unique_ptr<int[]> arr(new int[N]);

		cout << "Режим работы программы:\n>> 1 - случайное заполнение.\n>> 2 - ручной ввод.\n>> Введите ID режима работы: ";
		int modeWork = Utils::getInput<int>();

		switch (modeWork) {
			case RANDOM:
				// region заполнение массива рандомными числами
				/*for(int i = 0; i < N; i++) {
					int magicRand = rand() % N + 1;

					arr[i] = magicRand;
				}*/
				// todo по убыванию худший случай
				for(int i = 0; i < N; i++) {
					arr[i] = N-i;
					//arr[i] = i+1;
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

			default:
				cout << "Режим работы не обнаружен!" << endl;
				return EXIT_FAILURE;
		}

		switch (taskSelected) {
			case 1:
			case 2:
				executeTask1(arr, N);
				break;

			case 3:
				executeTask3(arr, N);
				break;

			case 4:
				executeTask4(arr, N);
				break;

			default:
				cout << "Такой задачи в занятии не существует!" << endl;
				return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
}
