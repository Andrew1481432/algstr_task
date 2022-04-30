#include "Task.h"
#include "firstTask/firstTask.h"
#include "secondTask/secondTask.h"
#include "thirdTask/thirdTask.h"
#include "fourthTask/fourthTask.h"
#include "fiveTask/fiveTask.h"
#include "sixTask/sixTask.h"

#include <iostream>

using namespace std;
using namespace Utils;

using namespace TaskSecond;
using namespace TaskThird;
using namespace TaskFourth;
using namespace TaskFive;
using namespace TaskSix;

std::map<int, Task*> Task::tasks;

void Task::init() {
    reg(new FirstTask());
    reg(new SecondTask());
    reg(new ThirdTask());
	reg(new FourthTask());
	reg(new FiveTask());
	reg(new SixTask());
}

bool Task::issetTasks() {
    return !tasks.empty();
}

void Task::run() {
    cout << ">> Введите номер работы: ";
    int n = Utils::getInput<int>();

    if(tasks.find(n) != tasks.end()) { // isset()
        tasks[n]->execute();
    } else {
        cout << "Введен неверный номер работы!" << endl;
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

