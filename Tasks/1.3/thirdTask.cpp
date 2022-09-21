#include "thirdTask.h"
#include "../../Utils/Utils.h"

/*
	//https://habr.com/ru/post/415935/
	//https://youtu.be/kPRA0W1kECg?t=218
	// shellsort implementation
	//https://www.softwaretestinghelp.com/shell-sort/#:~:text=In%20shell%20sort%2C%20the%20list,are%20%E2%80%9Ci%E2%80%9D%20elements%20apart.

	//https://codelab.ru/task/shell_sort:optimization/
	//https://github.com/kurt-krueckeberg/shell-sort/blob/master/shell-sort.h
 */

namespace TaskThird {

	enum ModeWork {
		RANDOM = 1,
		INPUT,
		DESC, // DESCending убывающий
		ASC // ascending возрастающий
	};

	std::string ThirdTask::getName() {
		return "Практическая работа № 1.3";
	}

	string ThirdTask::getId() {
		return "1.3";
	}

	void printArr(unique_ptr<int[]> &arr, int N, const string& name = "") {
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

	// region task2


	void quickSort(unique_ptr<int[]> &arr, int first, int last, uint64_t &Cf, uint64_t &Mf){
		int i = first, j = last, x = arr[(first + last)/2];

		auto begin = chrono::steady_clock::now();
		do {
			while (arr[i] < x) {
				i++;
				Cf++;
			}
			Cf++;

			while (arr[j] > x) {
				j--;
				Cf++;
			}
			Cf++;

			if(i <= j) {
				Cf++;
				if (arr[i] > arr[j]) {
					std::swap(arr[i], arr[j]);
					Mf += 3;
				}
				i++; j--;
			}
		} while (i <= j);

		if (i < last)
			quickSort(arr, i, last, Cf, Mf);

		if (first < j)
			quickSort(arr, first, j, Cf, Mf);
	}

	void quickSort(unique_ptr<int[]> &arr, int N){
		uint64_t Cf = 0;
		uint64_t Mf = 0;
		auto begin = chrono::steady_clock::now();
		quickSort(arr, 0, N-1, Cf, Mf);
		uint64_t Tp = Cf+Mf;
		auto end = chrono::steady_clock::now();
		auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
		cout << "Rоличество операций сравнения Cf = " << Cf << endl;
		cout << "Фактическое количество операций перемещения Mf = " << Mf << endl;
		cout << "Тп(n)=Cф+Mф: " << Tp << endl;
		cout << "Время выполнения T(n) = " << elapsed_ms.count() << endl;
	}

	//Быстрая сортировка (Хоара)
	void executeTask2(unique_ptr<int[]> &arr, int N) {
		//printArr(arr, N, "Исходный массив");
		quickSort(arr, N);
		//printArr(arr, N, "Отсортирован методом быстрой сортировка (Хоара)");
	}

	// endregion

	// region task1

	void shellSortPass(unique_ptr<int[]> &arr, const int N, int gap, uint64_t &Cf, uint64_t &Mf) {
		for (int i = gap; i < N; ++i) {
			// insert element i into the slice data[i-h], data[i-2h], ...
			Mf++;
			int temp = arr[i];

			int j = i;
			for(; j-gap >= 0 && temp < arr[j-gap]; j -= gap) {
				Cf++;

				Mf++;
				arr[j] = arr[j-gap];
			}
			Cf++;

			Mf++;
			arr[j] = temp;
		}
	}

	/*
	* Sedgewick's increment sequence h(j) = 4^(j+1) + 3*2^j + 1 for some j
	* Note that h(0) = 8, so you have to manually do something like h(-1) = 1
	*
	* https://github.com/aaronoah/algorithm-notes/blob/master/docs/sorting/shell-sort.md
	*
	* The runtime is O(n^(4/3)) BAD
	* O(n^(7/6)) в среднем
	*/
	void shellSortSedgewick(unique_ptr<int[]> &arr, const int N) {
		uint64_t Cf = 0;
		uint64_t Mf = 0;

		auto begin = chrono::steady_clock::now();
		time_t start = clock();

		int x;
		// find the value of x that oversteps N and backtrack one
		for (x = 0; pow(4.0, x+1) + 3*pow(2.0, x)+1 < N; x++);
		x--;

		int h;
		for (; x >= -1; x--) {
			if (x == -1) {
				h = 1;
			} else {
				h = pow(4.0, x+1) + 3*pow(2.0, x)+1;
			}
			//std::cout << "h(" << x << ") = " << h << std::endl;
			// can just as easily write all these increment sequences with a call to an h-sort
			shellSortPass(arr, N, h, Cf, Mf);
		}

		uint64_t Tp = Cf+Mf;
		auto end = chrono::steady_clock::now();
		time_t last = clock();
		auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
		cout << "Rоличество операций сравнения Cf = " << Cf << endl;
		cout << "Фактическое количество операций перемещения Mf = " << Mf << endl;
		cout << "Тп(n)=Cф+Mф: " << Tp << endl;
		cout << "Время выполнения(chrono) T(n) = " << elapsed_ms.count() << endl;
		cout << "Время выполнения(clock) T(n) = " << (last-start)/(CLOCKS_PER_SEC/1000) << " мс." << endl;
	}

	// алгоритм ускоренной(Усовершенствованный) сортировки
	// Шелла со смещениями Р. Седжвика.
	void executeTask1(unique_ptr<int[]> &arr, int N) {
		//printArr(arr, N, "Исходный массив");
		shellSortSedgewick(arr, N);
		//printArr(arr, N, "Отсортирован методом Шелла со смещениями Р. Седжвика");
	}

	// endregion


	void serchmax(int n,int *mass)
	{

	}

	void test1(unique_ptr<int[]> &mass, int n) {
		int i(0),q(0),kol(-1),h(0);

		time_t start = clock();

		//auto begin = chrono::steady_clock::now();

		for (i = 0; q * 3 < n;i++) {
			if (i % 2 == 0 || i == 0) {
				q = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
			} else {
				q = 8 * pow(2, i) - 6 * pow(2, (i+1) / 2) + 1;
			}
			kol++;
		}
		int *arr = new int[kol];
		for (i = 0; i <= kol; i++) {
			if (i % 2 == 0 || i == 0) {
				q = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
			} else {
				q = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
			}
			arr[i] = q;
		}

		for (int i = kol; i >= 0; i--){
			for (int q = arr[i]; q < n; q++){
				for (int f = q - arr[i]; f >= 0 && mass[f] > mass[f+arr[i]]; f-=arr[i]) {
					h = mass[f];
					mass[f] = mass[f + arr[i]];
					mass[f + arr[i]] = h;
				}
			}
		}

		time_t last = clock();
		//auto end = chrono::steady_clock::now();
		//auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
		//cout << "Rоличество операций сравнения Cf = " << Cf << endl;
		//cout << "Фактическое количество операций перемещения Mf = " << Mf << endl;
		//cout << "Тп(n)=Cф+Mф: " << Tp << endl;
		//cout << "Время выполнения T(n) = " << elapsed_ms.count() << endl;
		cout << "Время выполнения T(n) = " << (last-start)/(CLOCKS_PER_SEC/1000) << " мс." << endl;
	}

	//14 Шелла со смещениями Р. Седжвика.
	//Быстрая сортировка (Хоара)
	int ThirdTask::execute() {
		cout << "test1" << endl;
		cout << "Выберите задание:\n>> 1 - Задание № 1\n>> 2 - Задание № 2\n>> Введите ID задания: ";
		int taskSelected = Utils::getInput<int>();
		cout << "N = ";
		int N = Utils::getInput<int>();

		std::unique_ptr<int[]> arr(new int[N]);

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
				return EXIT_FAILURE;
		}


		switch (taskSelected) {
			case 1:
				executeTask1(arr, N);
				break;
			case 2:
				executeTask2(arr, N);
				break;

			case 3:
				test1(arr, N);
				break;

			default:
				cout << "Такой задачи в занятии не существует!" << endl;
				return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
}
