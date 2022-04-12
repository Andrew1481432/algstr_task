#include "matrix.h"

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

ostream& operator << (ostream &dfdf, matrix &K) {
    K.show();
    return dfdf;
}

//==================================

double* matrix::operator[] (int r) const {
    if (rows == 0) {
        return nullptr;
    }//пустая матрица

    if (r >= rows) {
        return m[r%rows];
    }//индекс > rows

    if (r < 0) {
        return m[rows - r % rows];
    }//индекс отрицательный

    if (r < 0 || r >= rows) {
        return m[rows - r % rows];
    }

    return m[r]; //индекс нормальный
}

//===============[глубокое копирование]===================

matrix& matrix::operator = (matrix &K) {
    rows = K.rows;
    cols = K.cols;

    if (rows < 1 || cols < 1) {
        return *this;
    }

    m = new double *[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new double[cols];
        for (int k = 0; k < cols; k++) {
            m[i][k] = K[i][k];
        }
    }
    return *this;
}

//==============[оператор присвоения]====================

matrix & matrix::operator = (double f) {
    if (rows < 1 || cols < 1) {
        return *this;
    }

    for (int i = 0; i < rows; i++) {
        for (int k = 0; k < cols; k++) {
            m[i][k] = f;
        }
    }
    return *this;
}

//=============[конструктор копирования]=====================

matrix::matrix(matrix &K) {
    rows = K.rows;
    cols = K.cols;

    if (rows < 1 || cols < 1) {
        return;
    }

    m = new double *[rows]; //создание строк
    for (int i = 0; i < rows; i++) {
        m[i] = new double[cols];
        for (int k = 0; k < cols; k++) {
            m[i][k] = K[i][k];
        }
    }
}

//==================================

void matrix::show() {
    if (rows < 1 || cols < 1) {
        cout << "debug::матрица " << this << " пустая\n";
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int k = 0; k < cols; k++) {
            cout << setw(6) << m[i][k];
        }
        cout << endl;
    }
}

//----------------------------------

void matrix::setRand() {
    if (rows < 1 || cols < 1) {
        //cout << "debug::матрица " << this << " пустая" << endl;
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int k = 0; k < cols; k++) {
            m[i][k] = rand() % 100;
        }
    }
}

//----------------------------------

matrix::matrix() {
    rows = 0;
    cols = 0;
    m = nullptr;

    //cout << "debug::Создана пустая матрица " << this << endl;
}

//----------------------------------

matrix::matrix(int r, int c) {
    if (r < 1 || c < 1) {
        rows = 0;
        cols = 0;
        m = nullptr;

        cout << "Ошибка размера матрицы " << this << endl;
        return;
    }

    rows = r;
    cols = c;

    m = new double *[rows]; //создание строк
    for (int i = 0; i < rows; i++) {
        m[i] = new double [cols];
        for (int k = 0; k < cols; k++) {
            m[i][k] = 0;
        }
    }

}

//----------------------------------

matrix::~matrix() {
    if (rows < 1 || cols < 1) {
        //cout << "Пустая матрица " << this << " удалена\n";
        return;
    }

    for (int i = 0; i < rows; i++) {
        delete m[i];
    }
    delete m;
    //cout << "Матрица " << this << " удалена\n";
}

//----------------------------------

//-----------[детерминант матрицы]-------------

void clearMemory(double** a, int n) { //Функция освобождения памяти, выделенной под двумерный динамический массив
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete [] a;
}

int matrix::getDet() {
    int r = getRows();
    int c = getCols();
    if(r == c) {
        return getDet(m, r);
    } else {
        cout << "Матрица должна быть квадратична!" << endl;
        return -1;
    }
}

int matrix::getDet(double **a, int n) {
    if (n == 1)
        return a[0][0];
    else if (n == 2)
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else {
        int d = 0;
        for (int k = 0; k < n; k++) {
            double **m = new double *[n - 1];
            for (int i = 0; i < n - 1; i++) {
                m[i] = new double[n - 1];
            }
            for (int i = 1; i < n; i++) {
                int t = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    m[i - 1][t] = a[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * a[0][k] * getDet(m, n - 1);
            clearMemory(m, n - 1); //Освобождаем память, выделенную под алгебраическое дополнение
        }
        return d; //Возвращаем определитель матрицы
    }
}

//-----------[сложение]-------------

matrix operator + (matrix R, matrix D) {
    if((R.getRows() != D.getRows()) || (R.getCols() != D.getCols())) {
        matrix result;
        return result;
    }

    matrix result(R.getRows(), D.getCols());

    for(int i(0); i < R.getRows(); i++)
        for(int j(0); j < R.getCols(); j++)
            result[i][j] = R[i][j] + D[i][j];

    return result;
}

//-----------[умножение]-------------

matrix matrix::operator * (matrix &L) const {
    if(cols != L.rows){
        cout<<"Данные матрицы перемножить невозможно!"<<endl;
        return {};
    } else {
        matrix otv(rows, L.cols);
        for (int i = 0; i < rows; i++)
            for (int k = 0; k < L.cols; k++) {
                otv[i][k]=0;
                for (int g = 0; g <L.rows ; g++) {
                    otv[i][k] += m[i][g] * L[g][k];
                }
            }
        return otv;
    }
}

