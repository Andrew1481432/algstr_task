#include "sixTask.h"
#include "node/List.h"
#include "node/Node.h"

using namespace Utils;

namespace TaskSix {
    std::string SixTask::getName() {
        return "Практическая работа № 6";
    }

    int SixTask::getId() {
        return 6;
    }

    void SixTask::execute() {
		cout << "Список:\n>> 1 - Создания списка вручную\n>> 2 - Использовать список установленный пресетом\n>> ";
        int workMode = Utils::getInput<int>();

        List *l = new List();
		
	    auto inputData = [&](int i, uint64_t &Cf, uint64_t &Mf){
		    string numRecordBook;
		    int numGroup, mark;
		    cout << i + 1 << ") Номер зач. книжки(буквенно-цифровой) = ";
		    cin >> numRecordBook;
		    cout << i + 1 << ") Номер группы(цифра) = ";
		    numGroup = getInput<int>();
		    cout << i + 1 << ") Оценка(цифра) = ";
		    mark = getInput<int>();
		    l->push_front(numRecordBook, numGroup, mark, Cf, Mf);
		};
	    auto printList = [&](List* l){
		    cout << "В каком формате выводить:\n1. Слева направо\n2. Справа налево" << endl;
		    cout << ">> ";
		    int modePrint = getInput<int>();
		    if (modePrint == 1 || modePrint == 2) {
			    l->print(modePrint-1);
		    } else {
			    cout << "Введено некорректное значение!" << endl;
		    }
	    };
	    // region test
	    uint64_t Cf = 0;
	    uint64_t Mf = 0;
	    chrono::time_point begin = chrono::steady_clock::now();
	    // endregion

	    auto printTest = [&](){
		    uint64_t Tp = Cf+Mf;
		    auto end = chrono::steady_clock::now();
		    auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
		    cout << "Rоличество операций сравнения Cf = " << Cf << endl;
		    cout << "Фактическое количество операций перемещения Mf = " << Mf << endl;
		    cout << "Тп(n)=Cф+Mф: " << Tp << endl;
		    cout << "Время выполнения T(n) = " << elapsed_ms.count() << endl;
		};

		switch (workMode) {
            case 1: { //а) создания нового списка вручную
                cout << "Введите длину списка: ";
                int n = getInput<int>();

	            begin = chrono::steady_clock::now();
                cout << "Введите информацию о зачетных книжках студентов:" << endl;
                for (int i = 0; i < n; i++) {
					inputData(i, Cf, Mf);
                }
            }
            break;
            case 2: {// б) использования уже готового списка для тестирования заданий
				l->push_front("21И0746", 1521, 5, Cf, Mf);
				l->push_front("21И0245", 1521, 5, Cf, Mf);
				l->push_front("17Щ0447", 0117, 4, Cf, Mf);
				l->push_front("21И0149", 1421, 4, Cf, Mf);
				l->push_front("21И0159", 1421, 5, Cf, Mf);
				l->push_front("21И0051", 1421, 5, Cf, Mf);
				l->push_front("21И0421", 1421, 2, Cf, Mf);
				l->push_front("21И0421", 1421, 2, Cf, Mf);
				l->push_front("21И0321", 1421, 3, Cf, Mf);
				l->push_front("21И0321", 1321, 2, Cf, Mf);
				l->push_front("21И0320", 1321, 2, Cf, Mf);
				l->push_front("21А0320", 1321, 2, Cf, Mf);
				l->push_front("21E0320", 1321, 2, Cf, Mf);
				l->push_front("21H0320", 1451, 2, Cf, Mf);
				l->push_front("21C0320", 1121, 2, Cf, Mf);
	            l->push_front("21И0320", 1321, 2, Cf, Mf);
	            l->push_front("21А0320", 1321, 2, Cf, Mf);
	            l->push_front("21E0320", 1321, 2, Cf, Mf);
	            l->push_front("21H0320", 1451, 2, Cf, Mf);
	            l->push_front("21C0320", 1121, 2, Cf, Mf);

	            l->push_front("21И0746", 1521, 5, Cf, Mf);
	            l->push_front("21И0245", 1521, 5, Cf, Mf);
	            l->push_front("17Щ0447", 0117, 4, Cf, Mf);
	            l->push_front("21И0149", 1421, 4, Cf, Mf);
	            l->push_front("21И0159", 1421, 5, Cf, Mf);
	            l->push_front("21И0051", 1421, 5, Cf, Mf);
	            l->push_front("21И0421", 1421, 2, Cf, Mf);
	            l->push_front("21И0421", 1421, 2, Cf, Mf);
	            l->push_front("21И0321", 1421, 3, Cf, Mf);
	            l->push_front("21И0321", 1321, 2, Cf, Mf);
	            l->push_front("21И0320", 1321, 2, Cf, Mf);
	            l->push_front("21А0320", 1321, 2, Cf, Mf);
	            l->push_front("21E0320", 1321, 2, Cf, Mf);
	            l->push_front("21H0320", 1451, 2, Cf, Mf);
	            l->push_front("21C0320", 1121, 2, Cf, Mf);
	            l->push_front("21И0320", 1321, 2, Cf, Mf);
	            l->push_front("21А0320", 1321, 2, Cf, Mf);
	            l->push_front("21E0320", 1321, 2, Cf, Mf);
	            l->push_front("21H0320", 1451, 2, Cf, Mf);
	            l->push_front("21C0320", 1121, 2, Cf, Mf);

	            l->push_front("21И0746", 1521, 5, Cf, Mf);
	            l->push_front("21И0245", 1521, 5, Cf, Mf);
	            l->push_front("17Щ0447", 0117, 4, Cf, Mf);
	            l->push_front("21И0149", 1421, 4, Cf, Mf);
	            l->push_front("21И0159", 1421, 5, Cf, Mf);
	            l->push_front("21И0051", 1421, 5, Cf, Mf);
	            l->push_front("21И0421", 1421, 2, Cf, Mf);
	            l->push_front("21И0421", 1421, 2, Cf, Mf);
	            l->push_front("21И0321", 1421, 3, Cf, Mf);
	            l->push_front("21И0321", 1321, 2, Cf, Mf);
	            l->push_front("21И0320", 1321, 2, Cf, Mf);
	            l->push_front("21А0320", 1321, 2, Cf, Mf);
	            l->push_front("21E0320", 1321, 2, Cf, Mf);
	            l->push_front("21H0320", 1451, 2, Cf, Mf);
	            l->push_front("21C0320", 1121, 2, Cf, Mf);
	            l->push_front("21И0320", 1321, 2, Cf, Mf);
	            l->push_front("21А0320", 1321, 2, Cf, Mf);
	            l->push_front("21E0320", 1321, 2, Cf, Mf);
	            l->push_front("21H0320", 1451, 2, Cf, Mf);
	            l->push_front("21C0320", 1121, 2, Cf, Mf);

	            l->push_front("21И0746", 1521, 5, Cf, Mf);
	            l->push_front("21И0245", 1521, 5, Cf, Mf);
	            l->push_front("17Щ0447", 0117, 4, Cf, Mf);
	            l->push_front("21И0149", 1421, 4, Cf, Mf);
	            l->push_front("21И0159", 1421, 5, Cf, Mf);
	            l->push_front("21И0051", 1421, 5, Cf, Mf);
	            l->push_front("21И0421", 1421, 2, Cf, Mf);
	            l->push_front("21И0421", 1421, 2, Cf, Mf);
	            l->push_front("21И0321", 1421, 3, Cf, Mf);
	            l->push_front("21И0321", 1321, 2, Cf, Mf);
	            l->push_front("21И0320", 1321, 2, Cf, Mf);
	            l->push_front("21А0320", 1321, 2, Cf, Mf);
	            l->push_front("21E0320", 1321, 2, Cf, Mf);
	            l->push_front("21H0320", 1451, 2, Cf, Mf);
	            l->push_front("21C0320", 1121, 2, Cf, Mf);
	            l->push_front("21И0320", 1321, 2, Cf, Mf);
	            l->push_front("21А0320", 1321, 2, Cf, Mf);
	            l->push_front("21E0320", 1321, 2, Cf, Mf);
	            l->push_front("21H0320", 1451, 2, Cf, Mf);
	            l->push_front("21C0320", 1121, 2, Cf, Mf);

	            l->push_front("21И0746", 1521, 5, Cf, Mf);
	            l->push_front("21И0245", 1521, 5, Cf, Mf);
	            l->push_front("17Щ0447", 0117, 4, Cf, Mf);
	            l->push_front("21И0149", 1421, 4, Cf, Mf);
	            l->push_front("21И0159", 1421, 5, Cf, Mf);
	            l->push_front("21И0051", 1421, 5, Cf, Mf);
	            l->push_front("21И0421", 1421, 2, Cf, Mf);
	            l->push_front("21И0421", 1421, 2, Cf, Mf);
	            l->push_front("21И0321", 1421, 3, Cf, Mf);
	            l->push_front("21И0321", 1321, 2, Cf, Mf);
	            l->push_front("21И0320", 1321, 2, Cf, Mf);
	            l->push_front("21А0320", 1321, 2, Cf, Mf);
	            l->push_front("21E0320", 1321, 2, Cf, Mf);
	            l->push_front("21H0320", 1451, 2, Cf, Mf);
	            l->push_front("21C0320", 1121, 2, Cf, Mf);
	            l->push_front("21И0320", 1321, 2, Cf, Mf);
	            l->push_front("21А0320", 1321, 2, Cf, Mf);
	            l->push_front("21E0320", 1321, 2, Cf, Mf);
	            l->push_front("21H0320", 1451, 2, Cf, Mf);
	            l->push_front("21C0320", 1121, 2, Cf, Mf);
            }
            break;
            default:
                cout << "Введено некорректное значение!" << endl;
                return;
        }
		printTest();

		bool exit = true;
		while(exit) {
			cout << "Введите номер функции:\n1. Вывод списка\n2. Удалить узлы с указанным номером группы.\n"
					"3. Вставить новый узел перед первым узлом \n4. Сформировать новый список из исходного, включив в него узлы с оценкой неуд, исключив их при этом из исходного списка.\n"
					"5. Найти эл-n из списка\n"
					"6. Выйти" << endl;
			cout << ">> ";
			int choice = getInput<int>();
			switch (choice) {
				case 1: {
					printList(l);
				}
				break;

				case 2: {
					cout << "Введите номер группы, который надо удалить из списка" << endl;
					cout << ">> ";
					int numGroup = getInput<int>();
					int result = l->remove(numGroup);
					cout << "Удалено элементов " << result << endl;
				}
				break;

				case 3: {
					Cf = Mf = 0;
					cout << "Введите зачетку, которую хотите вставить:" << endl;
					inputData(0, Cf, Mf);
					printTest();
				}

				case 4: {
					List *newList = l->getListBadMark();
					cout << "Список с неудовлетворительными оценками:" << endl;
					printList(newList);
				}
				break;

				case 5: {
					cout << "Введите номер зач. книжки, чтобы получить по ней подробную информацию:" << endl;
					string numRecordBook;
					cout << ">> ";
					cin >> numRecordBook;
					Node *selectNode = l->find(numRecordBook);
					if(selectNode != nullptr) {
						cout << "Номер зачетной книжки: " << selectNode->numRecordBook << " Номер группы: " << selectNode->numGroup << " Оценка: " << selectNode->mark << endl;
					} else {
						cout << "Информация по введному номеру зач. книжке не обнаружена!" << endl;
					}
				}
				break;

				default:
					exit = false;
			}
		}
    }
}