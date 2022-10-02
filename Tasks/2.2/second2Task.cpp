#include "second2Task.h"
#include "list/HashMap.h"

// вариант 1: цепное хеширование
// читательский абонемент
// номер читательского (5-значное число) (ключ) - фио, адрес
namespace second2Task {

	std::string Second2Task::getName(){
		return "Практическая работа № 2.2";
	}

	std::string Second2Task::getId() {
		return "2.2";
	}

	int Second2Task::execute(){
		auto* hashMap = new HashMap();
		hashMap->insert(new Node(22, "Andrew 12", "jsjaksj"));
		hashMap->insert(new Node(86, "Andrew", "sdvdsvs"));
		hashMap->insert(new Node(85, "Andrew", "dsvsdsd"));
		hashMap->insert(new Node(83292, "Andrew", "jsjaksj"));
		hashMap->insert(new Node(93892, "Andrew", "jsjaksj"));
		hashMap->insert(new Node(2342, "sdvcv", "jsjaksj"));
		hashMap->insert(new Node(24242, "sdvsd", "jsjaksj"));
		cout << "Вывод таблицы" << endl;
		cout << *hashMap;

		cout << "=-=-=КОМАНДЫ=-=-=:\n>> 1 - удаление\n>> 2 - добавить элемент\n>> 3 - найти элемент\n>> 4 - показать\n>> 5 - Завершить работу\n";
		bool running = true;
		while(running) {
			cout << ">> Введите ID команды: ";
			int cmdSelected = Utils::getInput<int>();
			switch (cmdSelected) {
				case 1: { // rem
					cout << "Введите ID записи для удаления: ";
					int id = Utils::getInput<int>();
					hashMap->remove(id);
				}
				break;

				case 2: { // add
					cout << "Введите ID записи для добавления: ";
					int id = Utils::getInput<int>();
					string name, addr;
					cout << "Введите ФИО: ";
					getline(cin, name);
					cout << "Введите адрес: ";
					getline(cin, addr);
					hashMap->insert(new Node(id, name, addr));
				}
				break;

				case 3: { // find
					cout << "Введите ID записи для поиска: ";
					int id = Utils::getInput<int>();
					Node *node = hashMap->findNodeById(id);
					if (node != nullptr){
						node->show();
					} else {
						cout << "Нет элемента с таким номером\n";
					}
				}
				break;

				case 4: // show
					cout << *hashMap << endl;
					break;

				case 5: // end
					running = false;
					break;

				case 6: { // rehash
					hashMap->insert(new Node(24342, "Ansvdsdrew", "jsjaksj"));
					hashMap->insert(new Node(2142, "svnkjsdnv", "jsjaksj"));
					hashMap->insert(new Node(4242, "vskdnvskd", "jsjaksj"));

					hashMap->insert(new Node(2424, "svdvkmdslvms", "jsjaksj"));
					hashMap->insert(new Node(242, "Andrendksjcndscw", "jsjaksj"));
					cout << endl;
					cout << *hashMap;
				}
				break;

				default:
					cout << "Выбранная команда не найдена!" << endl;
			}
		}
		return EXIT_SUCCESS;
	}
}
