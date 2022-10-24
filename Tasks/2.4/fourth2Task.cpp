#include "fourth2Task.h"
#include "tree/RBTree.h"

namespace fourth2Task {

	std::string Fourth2Task::getName(){
		return "Практическая работа № 2.4";
	}

	std::string Fourth2Task::getId(){
		return "2.4";
	}

	/**
	 * Реализовать алгоритмы
	 * Тип значения узла: Строка – имя
	 * Тип дерева: Красно-чёрное дерево
	 * Вставка элемента: + (балансировка)
	 * - Симметричный обход
	 * - Обход в ширину
	 * - Найти сумму значений листьев
	 * - Найти высоту дерева
	 *
	 * @return
	 */
	int Fourth2Task::execute(){
		auto *tree = new RBTree();


		tree->InsertNode(new RBNode("hola"));
		tree->InsertNode(new RBNode("ahola1"));
		tree->InsertNode(new RBNode("ahola2"));
		tree->InsertNode(new RBNode("hola3"));

		cout << "Вывод таблицы" << endl;
		tree->print();
		cout << "=-=-=КОМАНДЫ=-=-=:\n>> 1 - Вставка элемента\n>> 2 - Симметричный обход\n>> 3 - Обход в ширину\n>> 4 - Найти сумму значений листьев\n>> 5 - Найти высоту дерева\n>> 6 - Вывод дерева\n>> 7 - Завершить работу\n";
		bool running = true;
		while(running) {
			cout << ">> Введите ID команды: ";
			int cmdSelected = Utils::getInput<int>();
			switch (cmdSelected) {
				case 1: { // Вставка элемента
					string name;
					cout << "Введите NAME: ";
					getline(cin, name);
					tree->InsertNode(new RBNode(name));
				}
				break;

				case 2: // Симметричный обход
					tree->symmetry();
					cout << endl;
					break;

				case 3: // Обход в ширину
					tree->width();
					cout << endl;
					break;

				case 4: // Найти сумму значений листьев
					cout << "сумма значений листьев: 0" << endl;
					break;

				case 5: // Найти высоту дерева
					cout << "Высота дерева: " << tree->getHeight() << endl;
					break;

				case 6: // Вывод дерева
					tree->print();
					break;

				case 7: // завершить работу
					running = false;
					break;

				default:
					cout << "Выбранная команда не найдена!" << endl;
			}
		}

		delete tree;
		return EXIT_SUCCESS;
	}
}
