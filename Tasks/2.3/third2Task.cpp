#include "third2Task.h"
#include <algorithm>

namespace third2Task {

	std::string Third2Task::getName(){
		return "Практическая работа № 2.3";
	}

	std::string Third2Task::getId(){
		return "2.3";
	}

	/**
	 * Линейный поиск первого вхождения подстроки в строку
	 *
	 * @param str
	 * @param findStr
	 * @return int
	 */
	int linearFindStr(string str, string findStr) {
		//i – индекс в строке str, j – индекс в подстроке findStr,
		// ls – длина s, lt – длина findStr
		int ls = str.size();
		int lt = findStr.size();
		if(ls < lt) {
			return -1; // неудачный поиск
		}
		int i = 0, j = 0, f = 0;
		while(i < ls) { // сдвиг по str
			f = i; // начальный индекс возможного вхождения
			while(j < lt and str[i] == findStr[j]) { // сравнение до конца образца
				i++;
				j++;
			}
			if(j==lt) return f; // удачный поиск
			j = 0;
			i = f+1;
		}
		return -1; // неудачный поиск
	}


	/**
	 * Алгоритм Бойера-Мура-Хорспула
	 * найти последнее вхождение подстроки в строку.
	 *
	 * https://cmps-people.ok.ubc.ca/ylucet/DS/BoyerMoore.html
	 *
	 * https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%91%D0%BE%D0%B9%D0%B5%D1%80%D0%B0_%E2%80%94_%D0%9C%D1%83%D1%80%D0%B0#%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%91%D0%BE%D0%B9%D0%B5%D1%80%D0%B0_%E2%80%94_%D0%9C%D1%83%D1%80%D0%B0_%E2%80%94_%D0%A5%D0%BE%D1%80%D1%81%D0%BF%D1%83%D0%BB%D0%B0
	 *
	 * @param str
	 * @param findStr
	 * @return int
	 */
	int bmhFindStr(string str, string findStr) {
		int strLen = str.size();
		int findStrLen = findStr.size();
		if(strLen < findStrLen) {
			return -1; // неудачный поиск
		}

		// region формирование таблицы смещений

		const int SIZE_TABLE_ASCII = 1 << (8 * sizeof(char));
		int matchTable[SIZE_TABLE_ASCII];

		int lastCharacterLength = findStrLen - 1;
		for (int i = 0; i < SIZE_TABLE_ASCII; i++) {
			matchTable[i] = lastCharacterLength;
		}
		for(int i = 1; i < findStrLen; i++) {
			char symPattern = findStr[i];
			if(matchTable[(int)symPattern] == lastCharacterLength) {
				matchTable[(int)symPattern] = i;
			}
		}
		// endregion

		// region поиск образа в строке
		int i = strLen-1; // счетчик проверяемого символа в строке
		bool isFind = false;
		while(i >= 0) {
			for(int j = 0; j < findStrLen; j++) {
				int keyForStr = i-lastCharacterLength+j;
				if(keyForStr < 0) {
					return -1; // неудачный поиск
				}
				if(str[keyForStr] != findStr[j]) {
					int off = 0;
					if(j == 0) {
						off = matchTable[(int)str[keyForStr]]; // смещение, если не равен последний символ образа
					} else {
						off = matchTable[(int)findStr[j]]; // смещение, если не равен не последний символ образа
					}
					i -= off; // смещение счетчика строки
					isFind = false;
					break;
				}
				isFind = true;
			}
			if(isFind) {
				return i-lastCharacterLength; // удачный поиск
			}
		}
		// endregion
		return -1;
	}

	int Third2Task::execute(){
		string text, pattern;
		cout << "Введите строку: ";
		cin >> text;
		cout << "Введите подстроку: ";
		cin >> pattern;

		cout << "Выберите алгоритм сравнения:\n>> 1 - Алгоритм Линейный поиск.\n>> 2 - Алгоритм Бойера-Мура-Хорспула.\n>> Введите ID задания: ";
		int taskSelected = Utils::getInput<int>();
		int result = -1;
		switch (taskSelected){
			case 1:
				result = linearFindStr(text, pattern);
				break;

			case 2:
				result = bmhFindStr(text, pattern);
				break;

			default:
				cout << "Такой задачи в занятии не существует!" << endl;
				return EXIT_FAILURE;
		}
		if(result != -1) {
			cout << "Подстрока обнаружена: " << result << endl;
		} else {
			cout << "Вхождение подстроки не обнаружено в строке!" << endl;
		}
		return EXIT_SUCCESS;
	}
}
