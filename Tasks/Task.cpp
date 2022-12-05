#include "Task.h"

#include "1.1/firstTask.h"
#include "1.2/secondTask.h"
#include "1.3/thirdTask.h"
#include "1.4/fourthTask.h"
#include "1.5/fiveTask.h"
#include "1.6/sixTask.h"
#include "1.7/sevenTask.h"

#include "2.0/zero2Task.h"
#include "2.1/first2Task.h"
#include "2.2/second2Task.h"
#include "2.3/third2Task.h"
#include "2.4/fourth2Task.h"
#include "2.5/five2Task.h"
#include "2.6/six2Task.h"

#include <iostream>

using namespace std;
using namespace Utils;

using namespace TaskSecond;
using namespace TaskThird;
using namespace TaskFourth;
using namespace TaskFive;
using namespace TaskSix;
using namespace TaskSeven;

using namespace zero2Task;
using namespace first2Task;
using namespace second2Task;
using namespace third2Task;
using namespace fourth2Task;
using namespace five2Task;
using namespace six2Task;

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
	reg(new Zero2Task());
	reg(new First2Task());
	reg(new Second2Task());
	reg(new Third2Task());
	reg(new Fourth2Task());
	reg(new Five2Task());
	reg(new Six2Task());
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
	if(tasks.find(task->getId()) != tasks.end()) {
		throw std::invalid_argument("This task has already been added");
	}
    Task::tasks[task->getId()] = task;
}

