#include "seven2Task.h"
#include <chrono>
#include <cmath>

namespace seven2Task {

	enum TypeALG{
		BRUTE_FORCE = 1, // решение в лоб
		DYNAMIC // решение с помощью динамического программирования
	};

	/**
	 * Посчитать число последовательностей нулей и единиц длины n,
	 * в которых не встречаются две идущие подряд единицы.
	 */

	std::string Seven2Task::getName() {
		return "Практическая работа № 2.7";
	}

	std::string Seven2Task::getId(){
		return "2.7";
	}

	string toBinary(int n) {
		std::string r;
		while(n!=0) {
			r =(n%2==0 ?"0":"1")+r;
			n/=2;
		}
		if(r.empty()) {
			r = "0";
		}
		return r;
	}

	const int MAX = 100001;
	int arr[MAX];

	int f(int n) { // Алгоритм динамического программирования для поиска последовательностей 0 и 1
		switch (n) {
			case 0:
				return 0;
			case 1:
				return 2;
			case 2:
				return 3;
		}
		arr[1] = 2;
		arr[2] = 3;
		for(int i(3); i < n+1; i++) {
			arr[i] = arr[i-1]+arr[i-2];
		}
		return arr[n];
	}


	bool validateNumber(int number) {
		bool lastEl1 = false;
		while(number > 0) {
			int n = number % 10;

			if(lastEl1 && n == 1) {
				return false;
			}

			lastEl1 = n == 1;
			number /= 10;
		}
		return true;
	}

	int Seven2Task::execute(){
		int number = 0;
		selectTask:
		cout << "Выберите задание:\n>> 1 - Задание № 1(грубой силы)\n>> 2 - Задание № 2(динамическое программирование)\n>> Введите ID задания: ";
		int taskSelected = Utils::getInput<int>();

		switch (taskSelected) {
			case BRUTE_FORCE: {
				cout << "n - ";
				number = Utils::getInput<int>();

				auto begin = chrono::steady_clock::now();
				int count = 0;
				for(int i = 0; i < pow(2, number); i++) {
					string str = toBinary(i);
					for(int j = str.size(); j < number; j++) {
						str.insert(0, "0");
					}
					if(validateNumber(stoi(str))) {
						count++;
					}
				}
				cout << "Число: " << count << endl;

				auto end = chrono::steady_clock::now();
				auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
				cout << "The time: " << elapsed_ms.count() << " ms\n";
			}
			break;

			case DYNAMIC: {
				cout << "n - ";
				number = Utils::getInput<int>();

				auto begin = chrono::steady_clock::now();

				cout << "Число: " << f(number) << endl;

				auto end = chrono::steady_clock::now();
				auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
				cout << "The time: " << elapsed_ms.count() << " ms\n";
			}
			break;

			default:
				cout << "Задача не обнаружена!" << endl;
				goto selectTask;
		}
		return EXIT_SUCCESS;
	}

}
