#include "firstTask.h"
#include "../../Utils/Utils.h"
#include <chrono>
#include "matrix/matrix.h"
#include <iomanip>

enum ModeWork {
    RANDOM = 1,
    INPUT
};

std::string FirstTask::getName() {
    return "Практическая работа № 1.1";
}

string FirstTask::getId() {
    return "1.1";
}

void dumpChrono() {
    auto begin = chrono::steady_clock::now();
    getchar();
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
    cout << "The time: " << elapsed_ms.count() << " ms\n";
}

// region Задание 1

void delSecondMethod(unique_ptr<int[]> &x, int &n, int key) {
    auto begin = chrono::steady_clock::now();
    int counterEquels = 0;
    int counterMove = 0;

    int j = 0;
    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        counterEquels++;
        if (x[i] != key) {
            j++;
        }
    }
    n = j;

    cout << "[Второй алгоритм]"<< endl;
    cout << "Перемещений на первый метод: " << counterMove << "\nПроведено сравнений: " << counterEquels << endl;
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "Время выполнения второго алгоритма (миллисекунды): " << elapsed_ms.count() << endl;
}

void delFirstMethod(unique_ptr<int[]> &x, int &n, int key) {
    auto begin = chrono::steady_clock::now();
    int counterEquels = 0, counterMove = 0;
    int i = 0;
    while (i <= n) {
        counterEquels++;
        if (x[i] == key) {
            for (int j = i; j < n; j++) {
                x[j] = x[j + 1];
                counterMove++;
            }
            x[n] = 0;
            n--;
        } else {
            i++;
        }
    }

    cout << "[Первый алгоритм]"<< endl;
    cout << "Перемещений на первый метод: " << counterMove << "\nПроведено сравнений: " << counterEquels << endl;
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "Время выполнения первого алгоритма (миллисекунды): " << elapsed_ms.count() << endl;
}

void printArr(unique_ptr<int[]> &arr, int N, const string& name = "") {
    // region вывод массива
    cout << "Вывод массива (начало) " << name << endl;
    for(int i(0); i < N; i++) {
        cout << arr[i] << ((i != N-1) ? ", " : "");
    }
    cout << endl;
    cout << "Вывод массива (конец) " << name << endl;
    // endregion
}

unique_ptr<int[]> copy(unique_ptr<int[]> &arr, int len) {
    std::unique_ptr<int[]> copyResult(new int[len]);
    for (int i = 0; i < len; i++) {
        copyResult[i] = arr[i];
    }
    return copyResult;
}

void executeTask1() {
    srand(time(NULL));
    const int N = 100;

    std::unique_ptr<int[]> arr(new int[N]);

    cout << "Режим работы программы:\n>> 1 - случайное заполнение.\n>> 2 - ручной ввод.\n>> Введите ID режима работы: ";
    int modeWork = Utils::getInput<int>();

    switch (modeWork) {
        case RANDOM:
            // region заполнение массива рандомными числами
            for(int i = 0; i < N; i++) {
                int magicRand = rand() % N + 1;

                arr[i] = magicRand;
            }
            // endregion
            break;

        case INPUT:
            for(int i = 0; i < N; i++) {
                cout << "arr[" << i+1 << "/" << N << "]=";
                int inp = Utils::getInput<int>();
                arr[i] = inp;
            }
            break;

        default:
            cout << "Режим работы не обнаружен!" << endl;
            return;
    }

    printArr(arr, N, "Изначальный массив");

    cout << "Введите удаляемое число:\n>> ";
    int key = Utils::getInput<int>();

    // region первый алгоритм
    auto arrayFirstAlg = copy(arr, N);
    int nFirst = N;

    delFirstMethod(arrayFirstAlg, nFirst, key);
    printArr(arrayFirstAlg, nFirst, "Массив первого алгоритма");
    // endregion

    // region второй алгоритм
    auto arraySecondAlg = copy(arr, N);
    int nSecond = N;

    delSecondMethod(arraySecondAlg, nSecond, key);
    printArr(arraySecondAlg, nSecond, "Массив второго алгоритма");
    // endregion
}

// endregion

// region Задание 2


/**
 * Вариант 6.
 *
 * Найти максимальный элемент в части матрицы, расположенной над главной диагональю.
 */

/**
 * ! - граница глав. диагонали. * - подходящие значения
 *   7!    49*    73*    58*
    30    72!    44*    78*
    23     9    40!    65*
    92    42    87     3!
 */

void executeTask2() {
    cout << "Введите кол-во строк матрицы: ";
    int rows = Utils::getInput<int>();
    cout << "Введите кол-во столбцов матрицы: ";
    int cols = Utils::getInput<int>();


    auto begin = chrono::steady_clock::now();
    double **arr = new double *[rows]; //создание строк
    for (int i = 0; i < rows; i++) {
        arr[i] = new double [cols];
        for (int k = 0; k < cols; k++) {
            arr[i][k] = rand() % 100;
        }
    }


    int max = arr[0][0];
    for(int i=0; i<rows; i++) {
        for(int j=cols-1; j > i; j--) {
            if(arr[i][j]>max){
                max = arr[i][j];
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int k = 0; k < cols; k++) {
            cout << setw(6) << arr[i][k];
        }
        cout << endl;
    }

    cout<<"Max is "<<max << endl; //arr[2][0] 3(строка)x1(столбец)

    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
    cout << "The time: " << elapsed_ms.count() << " ms\n";
}

// endregion

int FirstTask::execute() {
    cout << "Выберите задание :\n>> 1 - Задание № 1.\n>> 2 - Задание № 2.\n>> Введите ID задания: ";
    int taskSelected = Utils::getInput<int>();

    switch (taskSelected) {
        case 1:
            executeTask1();
            break;

        case 2:
            executeTask2();
            break;

        default:
            cout << "Такой задачи в занятии не существует!" << endl;
            return EXIT_FAILURE;
    }
	return EXIT_SUCCESS;
}
