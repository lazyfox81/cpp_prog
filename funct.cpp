#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
// Работа с функциями

// Функция вывода одномерного массива
void print_arr(const int *arr, const int n){
	// как вариант void print_arr(int arr[], const int n)
	for (int i = 0; i < n; ++i){
		cout << arr[i] << ' '; // как вариант cout << *(arr+i) << ' ';
	}
	cout << '\n';
}

// Функция вычисления суммы элементов одномерного массива
int sum(const int* arr, const int n){
	int sum = 0;
	int i;
	for (i = 0; i < n; ++i){
		sum+=arr[i];
	}
	return sum;
}

// Функция вывода двумерного массива
void print_arr(int **arr, const int n, const int m){
	int i;
	int j;
	for (i = 0; i < n; ++i){
		for (j = 0; j < m; ++j){
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}
	
	
int main(){
	const int n = 10;
	// Формирование одномерного массива
	int vec[n];
	int i;
	int j;
	for (i = 0; i < n; ++i) 
		vec[i]=rand()%10;
	print_arr(vec, n);
	cout << sum(vec, n) << '\n';
	
	// Формирование двумерного массива
	int row = 4;
	int column = 5;
	int **matr = new int *[row];// row - строка, column - столбец
	for (i = 0; i < row; ++i) 
		matr[i] = new int [column];
	
	// Заполнение двумерного массива
	for (i = 0; i < row; ++i){
		for (j = 0; j < column; ++j)
			matr[i][j] = rand()%10;
	}
	cout  << '\n';
	print_arr(matr, row, column);
	return 0;
}

