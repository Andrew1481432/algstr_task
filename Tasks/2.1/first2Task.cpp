#include "first2Task.h"

namespace first2Task {

	std::string First2Task::getName(){
		return "Практическая работа № 2.1";
	}

	std::string First2Task::getId() {
		return "2.1";
	}

	void ex1() {
		unsigned int digit = 0x5c0;
		unsigned int mask = 1<<31|1<<30|1<<29;

		const int n = 32;
		cout << "Число: " << digit << " -- " << std::bitset<n>(digit).to_string() << endl;
		cout << "Маска: " << mask << " -- " << std::bitset<n>(mask).to_string() << endl;
		cout << "Вывод: " << (digit|mask) << " -- " << std::bitset<n>((digit|mask)).to_string() << endl;
	}

	void ex2() {
		cout << "Введите число:\n>> ";
		unsigned int digit = Utils::getInput<int>();

		const int n = 32;
		unsigned int mask = ~(1<<14|1<<12|1<<3);
		cout << "Число: " << digit << " -- " << std::bitset<n>(digit).to_string() << endl;
		cout << "Маска: " << mask << " -- " << std::bitset<n>(mask).to_string() << endl;
		digit &= mask;
		cout << "Вывод: " << digit << " -- " << std::bitset<n>(digit).to_string() << endl;
	}

	void ex3() {
		cout << "Введите число:\n>> ";
		unsigned int digit = Utils::getInput<int>();

		const int n = 32;
		cout << "Число: " << digit << " -- " << std::bitset<n>(digit).to_string() << endl;
		cout << "Множитель: 4" << endl;
		digit <<= 2;
		cout << "Результат: " << digit << " -- " << std::bitset<n>(digit).to_string() << endl;
	}

	void ex4() {
		cout << "Введите число:\n>> ";
		unsigned int digit = Utils::getInput<int>();

		const int n = 32;
		cout << "Число: " << digit << " -- " << std::bitset<n>(digit).to_string() << endl;
		cout << "Делитель: 4" << endl;
		digit >>= 2;
		cout << "Результат: " << digit << " -- " << std::bitset<n>(digit).to_string() << endl;
	}

	void ex5() {
		// Маска может быть инициализирована единицей в
		// младшем разряде (вар 1) или единицей в старшем разряде (вар 2).

		// Установить n-ый бит в 1, используя маску пункта 2
		cout << "Введите число:\n>> ";
		unsigned int digit = Utils::getInput<int>();
		cout << "Введите номер бита\n>> ";
		unsigned int shift = Utils::getInput<int>();
		if(shift > 31) {
			cout << "Сдвиг не должен превышать 31!" << endl;
			return;
		}
		unsigned int mask = 1<<31; // единицей в старшем разряде
		mask >>= 31-shift; // Установить n-ый бит в 1

		const int n = 32;
		cout << "Число: " << digit << " -- " << std::bitset<n>(digit).to_string() << endl;
		cout << "Маска: " << mask << " -- " << std::bitset<n>(mask).to_string() << endl;
		cout << "Вывод: " << (digit|mask) << " -- " << std::bitset<n>((digit|mask)).to_string() << endl;
	}

	int First2Task::execute(){
		cout << "Выберите задание:\n>> 1 - Задание № 1.\n>> 2 - Задание № 2.\n>> 3 - Задание № 3.\n>> 4 - Задание № 4.\n>> 5 - Задание № 5.\n>> Введите ID задания: ";
		int taskSelected = Utils::getInput<int>();
		switch (taskSelected) {
			case 1:
				ex1();
				break;

			case 2:
				ex2();
				break;

			case 3:
				ex3();
				break;

			case 4:
				ex4();
				break;

			case 5:
				ex5();
				break;

			default:
				cout << "Такой задачи в занятии не существует!" << endl;
				return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
}
