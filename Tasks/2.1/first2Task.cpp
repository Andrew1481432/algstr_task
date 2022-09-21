#include "first2Task.h"

namespace first2Task {
	string DIR_RESOURCES = "/Users/testerdev/Desktop/Учеба/Уник/семестр_3/сиаод/практика_1/";

	std::string First2Task::getName(){
		return "Практическая работа № 2.1";
	}

	std::string First2Task::getId() {
		return "2.1";
	}

	int First2Task::execute(){
		cout << "Hello World!" << endl;
		return EXIT_SUCCESS;
	}
}
