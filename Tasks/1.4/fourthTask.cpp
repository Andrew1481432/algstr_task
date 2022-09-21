#include "fourthTask.h"

using namespace TaskFourth;

std::string FourthTask::getName()
{
	return "Практическая работа № 1.4";
}

std::string FourthTask::getId(){
	return "1.4";
}

enum TypeALG{
	DIRECT_MERGE = 1, // прямого слияния(простое слияние)
	NATURAL_MERGE // естественного слияния
};

enum RESULTCODE {
	ERROR = -1,
	CONTINUE,
	STOP
};

// region Product
struct Product{
	string name; //Наименование товара
	string countryIm; //Страна импортирующая товар
	int count; //(в штуках)
};

// if (prA2.countryIm.compare(prA1.countryIm)>0) { // a1 < a2
bool operator < (Product &p1, Product &p2) {
	return p2.countryIm.compare(p1.countryIm)>0;
}

bool operator > (Product &p1, Product &p2) { // a1 > a2
	return p1.countryIm.compare(p2.countryIm)>0;
}

vector<string> split(const string& s, char delim) {
	vector<string> res;
	std::stringstream ss(s);
	string item;
	while(std::getline(ss, item, delim)) {
		res.push_back(item);
	}
	return res;
}

Product parseProduct(string raw) {
	Product result = Product();
	auto res = split(raw, '|');
	result.name = res[0];
	result.countryIm = res[1];
	result.count = stoi(res[2]);
	return result;
}

// endregion

void quickSort(vector<string> &arr, int first, int last, uint64_t &Cf, uint64_t &Mf) {
	int i = first, j = last;
	string x = arr[(first + last)/2];
	Product prX = parseProduct(x);

	do {
		Product prArrI = parseProduct(arr[i]);
		while (prArrI < prX) {
			i++;
			prArrI = parseProduct(arr[i]);
			Cf++;
		}
		Cf++;

		Product prArrJ = parseProduct(arr[j]);
		while (prArrJ > prX) {
			j--;
			prArrJ = parseProduct(arr[j]);
			Cf++;
		}
		Cf++;

		if(i <= j) {
			Cf++;

			prArrI = parseProduct(arr[i]);
			prArrJ = parseProduct(arr[j]);
			if (prArrI > prArrJ) {
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

string DIR_RESOURCES = "/Users/andrew1481432/Desktop/Учеба/Уник/семестр_2/сиаод/практика_4/resources/";

// region Алгоритм естественного слияния

void mergeSeriesOnFile(fstream &A, fstream &B, fstream &C, uint64_t &Cf, uint64_t &Mf) {
	vector<string> buf;
	string lastElB, lastElC, currentEl;

	A.open(DIR_RESOURCES + "A.txt", ios::out);
	B.open(DIR_RESOURCES + "B.txt", ios::in);
	C.open(DIR_RESOURCES + "C.txt", ios::in);

	// todo решить пробему с lastElB, когда значение может не записаться в buff
	while(!B.eof() || !C.eof()) {
		if(!B.eof()) {
			if (lastElB.empty()){
				getline(B, lastElB);
			}
			buf.push_back(lastElB);
			while (getline(B, currentEl)) {
				Product prLast = parseProduct(lastElB);
				Product prCurrent = parseProduct(currentEl);
				if (prLast > prCurrent && !C.eof()) {
					lastElB = currentEl;
					break;
				}

				buf.push_back(currentEl);
				lastElB = currentEl;
			}
		}

		if(!C.eof()) {
			if (lastElC.empty()) {
				getline(C, lastElC);
			}
			buf.push_back(lastElC);
			while (getline(C, currentEl)){
				Product prLast = parseProduct(lastElB);
				Product prCurrent = parseProduct(currentEl);
				if (prLast > prCurrent && !B.eof()){
					lastElC = currentEl;
					break;
				}

				buf.push_back(currentEl);
				lastElC = currentEl;
			}
		}

		quickSort(buf, 0, buf.size() - 1, Cf, Mf);
		for(auto &s: buf) {
			A << s << "\n";
		}
		buf.clear();
	}
	C.close();
	B.close();
	A.close();

	// region Вывод
	string temp, temp1;
	// region A:
	A.open(DIR_RESOURCES + "A.txt", ios::in);
	cout << "Сливаем в файл А по сериям:" << endl;

	if(!getline(A, temp)) {
		cout << "Error::Ошибка с чтения файла A.txt" << endl;
		return;
	}
	Product prTemp = parseProduct(temp);
	cout << "A: ";
	cout << prTemp.countryIm;
	while(getline(A, temp1)) {
		prTemp = parseProduct(temp);
		Product prTemp1 = parseProduct(temp1);
		if(prTemp > prTemp1) {
			cout << "’";
		}
		cout << " ";
		cout << prTemp.countryIm;
		temp = temp1;
	}
	cout << endl;
	A.close();
	// endregion
	// endregion
}

int breakingSeriesOnFile(fstream &A, fstream &B, fstream &C, uint64_t &Cf, uint64_t &Mf) {
	string temp, temp1;
	A.open(DIR_RESOURCES + "A.txt", ios::in);
	B.open(DIR_RESOURCES + "B.txt", ios::out);
	C.open(DIR_RESOURCES + "C.txt", ios::out);

	getline(A, temp);
	B << temp << "\n";
	bool isBWrite = true;
	int switchCounter = 0;
	while(getline(A, temp1)) {
		Cf++;
		Product prTemp = parseProduct(temp);
		Product prTemp1 = parseProduct(temp1);
		if(prTemp > prTemp1) {
			isBWrite = !isBWrite;
			switchCounter++;
		}
		if(isBWrite){
			B << temp1 << "\n";
		} else {
			C << temp1 << "\n";
		}
		temp = temp1;
	}
	if(switchCounter == 0) {
		return STOP;
	}
	Cf++;

	C.close();
	B.close();
	A.close();

	// region Вывод
	// region B:
	B.open(DIR_RESOURCES + "B.txt", ios::in);
	cout << "Разбиваем по сериям:" << endl;

	if(!getline(B, temp)) {
		cout << "Error::Ошибка с чтения файла B.txt" << endl;
		return ERROR;
	}
	Product prTemp = parseProduct(temp);
	cout << "B: ";
	cout << prTemp.countryIm;
	while(getline(B, temp1)) {
		prTemp = parseProduct(temp);
		Product prTemp1 = parseProduct(temp1);
		if(prTemp > prTemp1) {
			cout << "’";
		}
		cout << " ";
		cout << prTemp1.countryIm;
		temp = temp1;
	}
	cout << endl;
	B.close();
	// endregion

	// region С:
	C.open(DIR_RESOURCES + "C.txt", ios::in);
	if(!getline(C, temp)) {
		cout << "Error::Ошибка с чтения файла C.txt" << endl;
		return ERROR;
	}
	prTemp = parseProduct(temp);
	cout << "C: ";
	cout << prTemp.countryIm;
	while(getline(C, temp1)) {
		prTemp = parseProduct(temp);
		Product prTemp1 = parseProduct(temp1);
		if(prTemp > prTemp1) {
			cout << "’";
		}
		cout << " ";
		cout << prTemp1.countryIm;
		temp = temp1;
	}
	cout << endl;
	C.close();
	// endregion
	// endregion
	return CONTINUE;
}

void naturalMergingSort(fstream &A) {
	uint64_t Cf = 0;
	uint64_t Mf = 0;
	auto begin = chrono::steady_clock::now();

	fstream B, C;

	while(true) {
		int id = breakingSeriesOnFile(A, B, C, Cf, Mf);
		if(id == STOP) {
			break;
		} else if(id == ERROR) {
			return;
		}
		mergeSeriesOnFile(A, B, C, Cf, Mf);
	}

	string temp = DIR_RESOURCES + "B.txt";
	std::remove(temp.c_str());
	temp = DIR_RESOURCES + "C.txt";
	std::remove(temp.c_str());

	uint64_t Tp = Cf+Mf;
	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
	cout << "Rоличество операций сравнения Cf = " << Cf << endl;
	cout << "Фактическое количество операций перемещения Mf = " << Mf << endl;
	cout << "Тп(n)=Cф+Mф: " << Tp << endl;
	cout << "Время выполнения T(n) = " << elapsed_ms.count() << endl;
}
// endregion

// region прямая сортировка слиянием

void breakingOnFile(fstream &A, fstream &B, fstream &C, int gap, uint64_t &Cf, uint64_t &Mf) {
	string temp;
	A.open(DIR_RESOURCES + "A.txt", ios::in);
	B.open(DIR_RESOURCES + "B.txt", ios::out);
	C.open(DIR_RESOURCES + "C.txt", ios::out);

	getline(A, temp);
	int tempGap;
	while(!A.eof()) {
		Cf++;
		tempGap = gap;
		Cf++;
		while(tempGap>0 && !A.eof()) {
			Cf++;
			B << temp << "\n";
			getline(A, temp);
			tempGap--;
		}
		tempGap = gap;
		Cf++;
		while(tempGap>0 && !A.eof()) {
			Cf++;
			C << temp << "\n";
			getline(A, temp);
			tempGap--;
		}
	}
	Cf++;

	C.close();
	B.close();
	A.close();

	// region Вывод
	B.open(DIR_RESOURCES + "B.txt", ios::in);
	C.open(DIR_RESOURCES + "C.txt", ios::in);
	cout << "Разбиваем по " << gap << " элементу:" << endl;
	cout << "B: ";
	tempGap = gap;
	while(getline(B, temp)) {
		cout << parseProduct(temp).countryIm << " ";
		tempGap--;
		if(tempGap <= 0) {
			tempGap = gap;
			cout << " ";
		}
	}
	cout << endl;
	B.close();
	cout << "C: ";
	tempGap = gap;
	while(getline(C, temp)) {
		cout << parseProduct(temp).countryIm << " ";
		tempGap--;
		if(tempGap <= 0) {
			tempGap = gap;
			cout << " ";
		}
	}
	cout << endl;
	C.close();
	// endregion
}

void mergeOnFile(fstream &A, fstream &B, fstream &C, int gap, uint64_t &Cf, uint64_t &Mf) {
	string temp, temp1, temp2;

	A.open(DIR_RESOURCES + "A.txt", ios::out);
	B.open(DIR_RESOURCES + "B.txt", ios::in);
	C.open(DIR_RESOURCES + "C.txt", ios::in);

	getline(C, temp2);
	getline(B, temp1);
	while(!C.eof() && !B.eof()) { // относительно множества проходимся
		Cf+=2;

		int i = 0;
		int j = 0;

		while(i < gap && j < gap && !C.eof() && !B.eof()) { // мы относительно подмножества сравниваем с подмножеством другого файла
			Cf++;
			Mf++;

			Product prA1 = parseProduct(temp1);
			Product prA2 = parseProduct(temp2);
			if(prA2 < prA1) {
				A << temp2 << "\n";
				getline(C, temp2);
				j++;
			} else {
				A << temp1 << "\n";
				getline(B, temp1);
				i++;
			}
		}

		while (i < gap && !B.eof()) { // закидываем остатки B в главный файл
			Cf++;
			Mf++;

			A << temp1 << "\n";
			getline(B, temp1);
			i++;
		}
		while (j < gap && !C.eof()) { // закидываем остатки C в главный файл
			Cf++;
			Mf++;

			A << temp2 << "\n";
			getline(C, temp2);
			j++;
		}
	}
	Cf++;

	// region если четность не соблюдена
	while(!B.eof()) {
		Cf++;

		Mf++;
		A << temp1 << "\n";
		getline(B, temp1);
	}
	Cf++;

	while(!C.eof()) {
		Cf++;

		Mf++;
		A << temp2 << "\n";
		getline(C, temp2);
	}
	Cf++;
	// endregion

	C.close();
	B.close();
	A.close();

	// region выводим
	A.open(DIR_RESOURCES + "A.txt", ios::in);
	cout << "Сливаем в упорядоченные "<< gap*2 <<":" << endl;

	cout << "A: ";
	int tempGap = gap*2;
	while(getline(A, temp)) {
		cout << parseProduct(temp).countryIm << " ";
		tempGap--;
		if(tempGap <= 0) {
			tempGap = gap*2;
			cout << " ";
		}
	}
	cout << endl;
	A.close();
	// endregion
}

//Двухфазная сортировка – это сортировка, в которой отдельно реализуется две фазы: распределение и слияние
//Двухпутевым слиянием (два вспомогательных файла используется)
void simpleMergingSort(fstream &A) {
	uint64_t Cf = 0;
	uint64_t Mf = 0;
	auto begin = chrono::steady_clock::now();

	int gap; // счетчик для while, (длина серий) к примеру в первом проходе при слиянии будет 2^1 = 2, то есть[{2, 5}, {2, 7}, ...]
	int N = 0;

	fstream B, C;
	A.open(DIR_RESOURCES + "A.txt", ios::in);
	string tempLine;
	while(getline(A, tempLine)){
		N++;
	}
	cout << "Количество записей: " << N << endl;
	A.close();

	// in - из файла во внутрь массива(программы)
	// out - из программы в файл

	gap = 1;
	while (gap < N) {
		breakingOnFile(A, B, C, gap, Cf, Mf);
		mergeOnFile(A, B, C, gap, Cf, Mf);
		gap *= 2; // длина серий 2^i (1, после первого шага она равна 2, после второго – 4, после третьего – 8, после k -го шага – 2^k)
	}
	string temp = DIR_RESOURCES + "B.txt";
	std::remove(temp.c_str());
	temp = DIR_RESOURCES + "C.txt";
	std::remove(temp.c_str());

	uint64_t Tp = Cf+Mf;
	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
	cout << "Rоличество операций сравнения Cf = " << Cf << endl;
	cout << "Фактическое количество операций перемещения Mf = " << Mf << endl;
	cout << "Тп(n)=Cф+Mф: " << Tp << endl;
	cout << "Время выполнения T(n) = " << elapsed_ms.count() << endl;
}

// endregion

int FourthTask::execute() {
	cout << "Выберите задание:\n>> 1 - Задание № 1(прямого слияния)\n>> 2 - Задание № 2(естественного слияния)\n>> Введите ID задания: ";
	int taskSelected = Utils::getInput<int>();

	fstream A;
	A.open(DIR_RESOURCES + "A.txt", ios::in);
	if (!A) {
		cout << "Исходный файл(A.txt) не может быть прочитан!" << endl;
		return EXIT_FAILURE;
	}
	A.close();

	switch (taskSelected) {
		case DIRECT_MERGE:
			simpleMergingSort(A);
			break;

		case NATURAL_MERGE:
			naturalMergingSort(A);
			break;
	}
	return EXIT_SUCCESS;
}