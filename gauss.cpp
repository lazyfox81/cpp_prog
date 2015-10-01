#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iomanip>
using std::cin;
using std::cout;

//------------------------------------------------------------------------------
// Решение системы линейных уравнений методом Гаусса с выбором главного элемента
//------------------------------------------------------------------------------

// Запуск программы на исполнение: ./a.out < gauss_data.txt

// Печать двумерного массива.
void pr_matrix (float **matrix, const int row, const int column){
    for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){
            // Зададим точность вывода данных.
            // Действует до следующего явного задания точности вывода
            // флаг fixed - печатать вещественные числа в форме с
            // фиксированной точкой. Иначе точность будет обозначать число
            // значащих цифр
            cout    << std::setprecision(5)
                    << std::setiosflags(std::ios::fixed);

			cout << std::setw(12) << matrix[i][j];
		}
		cout << '\n';
	}
    cout << '\n';

    // Сбросим установленные флаги
    cout << std::resetiosflags(std::ios::fixed);
}

//------------------------------------------------------
int main(){

    int row, column;
    cin >> row;
    cin >> column;
    cout << row << ' ' << column << '\n' << '\n';

    // Инициализация массива
    float **matrix = new float *[row];
    for (int i = 0; i < row; ++i){
        matrix[i] = new float [column];
    }

    // Ввод матрицы
    for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){
            cin >> matrix[i][j];
		}
	}

    // Вывод введенной матрицы
    pr_matrix (matrix, row, column);

    //----------------------------------------------
    // Выбор главного элемента
    // Поиск максимального по модулю элемента при X1
    float max = 0;
    int row_max = 0;
    for (int i = 0; i < row; ++i){
        if (abs(matrix[i][0]) > abs(max)) {max = matrix[i][0]; row_max = i;}
    }
    cout << max << ' ' << row_max << '\n' << '\n';

    // Ставим уравнение с максимальным первым членом на первое место
    // если только это уравнение уже не является первым
    if (matrix[0][0] != max){
        float *buffer = new float [column];
        for (int j = 0; j < column; ++j){
            buffer[j] = matrix[0][j];
            matrix[0][j] = matrix[row_max][j];
            matrix[row_max][j] = buffer[j];
        }
	    delete[] buffer;
    }

    // Вывод исправленной матрицы
    pr_matrix (matrix, row, column);
    //----------------------------------------------


    //----------------------------------------------
    // Приведение матрицы  к диагональному виду. Прямой ход
    float buffer;
    for (int i=0; i<row; ++i){
        //Первый элемент строки; на него будем делить все элементы, чтобы
        //привести текущее уравнение к виду [1 a12 a13]
        buffer = matrix[i][i];
        for (int j=0; j<column; ++j){
            matrix[i][j] = matrix[i][j] / buffer;
        }
        // Далее из каждого следующего уравнения вычитается текущее уравнение,
        // умноженное на соответствующий коэффициент, чтобы исключить одно
        // из неизвестных
        for (int i1=i+1; i1<row; ++i1){
            buffer = matrix[i1][i];
            for (int j=0; j<column; ++j){
                matrix[i1][j] = matrix[i1][j] - matrix[i][j]*buffer;
            }
        }
        pr_matrix (matrix, row, column);
    }
    //---------------------------------------------

    //---------------------------------------------
    // Вычисление значений неизвестных. Обратный ход
    float *x = new float [row];
    float s;
    x[row-1] = matrix[row-1][row];

    for (int i = row-2; i>=0; --i){
        s = 0;
        for (int j = row - 1; j > i; --j){
            s = s + matrix[i][j]*x[j];
        }
        x[i]=matrix[i][column-1] - s;
    }

    //Вывод значений неизвестных
    for (int i = 0; i < row; ++i){
         cout    << std::setprecision(5)
                 << std::setiosflags(std::ios::fixed);
         cout << x[i] << ' ';
    }
    cout << '\n';
    //---------------------------------------------

	// Очистка динамической памяти
    for (int i=0; i < row; ++i)
		delete[] matrix[i];
	delete[] matrix;
	delete[] x;


    return 0;
}
