#ifndef CIAOD_TASK_H

#include <string>
#include <map>

#define CIAOD_TASK_H

// Статика является фабрикой для задач
class Task{
        static std::map<std::string, Task*> tasks;
        static void reg(Task *);

    public:
        static void init();
        static bool issetTasks();

        static void show();
        static int run();

        virtual std::string getName() = 0;
        virtual std::string getId() = 0;

        virtual int execute() = 0;
};

#endif //CIAOD_TASK_H