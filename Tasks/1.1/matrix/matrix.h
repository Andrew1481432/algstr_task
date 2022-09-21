#include <iostream>

using namespace std;

class matrix {

public:
    int rows; //строки
    int cols; //столбцы
    double **m; //указатель на таблицу чисел

    matrix(int, int); //конструктор
    matrix();
    ~matrix(); //Диструктор

    void show(); //вывод на экран
    void setRand(); //заполнение числами

    int getDet(double**, int);
    int getDet();

    double* operator [] (int) const;

    matrix operator * (matrix &) const;
    matrix& operator = (matrix &);
    matrix& operator = (double);

    matrix(matrix &); //конструктор копирования

    int getRows() {
        return rows;
    }

    int getCols() {
        return cols;
    }
};

matrix operator + (matrix, matrix);
ostream& operator << (ostream &, matrix &);