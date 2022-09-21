#include "Task.h"

#include "1.1/firstTask.h"
#include "1.2/secondTask.h"
#include "1.3/thirdTask.h"
#include "1.4/fourthTask.h"
#include "1.5/fiveTask.h"
#include "1.6/sixTask.h"
#include "1.7/sevenTask.h"

#include <iostream>

using namespace std;
using namespace Utils;

using namespace TaskSecond;
using namespace TaskThird;
using namespace TaskFourth;
using namespace TaskFive;
using namespace TaskSix;
using namespace TaskSeven;

std::map<string, Task*> Task::tasks;

void Task::init() {
	// region 1-ый семестр
    reg(new FirstTask());
    reg(new SecondTask());
    reg(new ThirdTask());
	reg(new FourthTask());
	reg(new FiveTask());
	reg(new SixTask());
	reg(new SevenTask());
	// endregion

	// region 2-ой семестр
	// TODO
	// endregion
}

bool Task::issetTasks() {
    return !tasks.empty();
}

int Task::run() {
    cout << ">> Введите номер работы: ";
    string val;
	cin >> val;

    if(tasks.find(val) != tasks.end()) { // isset()
        return tasks[val]->execute();
    } else {
        cout << "Введен неверный номер работы!" << endl;
	    return EXIT_FAILURE;
    }
}

void Task::show() {
    cout << "Выберите работу для проверки:" << endl;

    for (const auto& [key, task]: tasks){
        cout << ">> " << key << " - " << task->getName() << endl;
    }
}

void Task::reg(Task *task) {
    Task::tasks[task->getId()] = task;
}

