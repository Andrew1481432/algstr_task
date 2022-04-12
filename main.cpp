#include <iostream>
#include "Tasks/Task.h"

using namespace std;

int main() {
    Task::init();

    if(Task::issetTasks()) {
	    restart:
        Task::show();
        Task::run();

	    int isStayInProgramm = 0;
	    cout << "Вы хотите продолжить? 1-остаться 0-выход из программы: ";
	    cin >> isStayInProgramm;
	    if(std::cin.fail()) {
		    std::cin.clear();
		    goto exit;
	    }

	    switch (isStayInProgramm) {
		    case 1:
			    goto restart;

		    case 0:
		    default:
				exit:
			    // костыль system Pause (чтобы VS сode не закрывал)
			    // в принципе есть "system("pause");", но так как я работаю на MACOS в IDE Xcode. Библетеки <windows.h> у меня нету...
			    cout << "Нажмите ENTER для завершения программы..." << endl;
			    fgetc(stdin);
			    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	    }
    } else {
        cout << "Задач не обнаружено!" << endl;
	    return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
