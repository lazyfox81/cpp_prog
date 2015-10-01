// Решение нелинейных уравнений методом дихотомии
// (деления отрезка пополам)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using std::cin;
using std::cout;

typedef double T;

T eq_1 (T x){
	T y = log(x) + 4*x;
	return y;
}

T div_half (T a, T b, T eps){
	int n = 0;
	//cout << a << "   "<< b << '\n';
	T y1 = eq_1(a);
	T y2 = eq_1(b);

	if (y1*y2 > 0){
		cout << "No solution" << '\n';
		exit(1);//выход из программы библиотека sctdlib
	}

	do{
		T x = (a + b)/2;
        cout.setf(std::ios::left); // выравнивание по левому краю
       	cout << std::setw(4) << n << std::setw(12) << a <<
            std::setw(12) << b << std::setw(12) << x << '\n';
        // setw(int) - устанавливает максимальную ширину поля вывода
		T y1 = eq_1(a);
		T y2 = eq_1(x);
		if (y1*y2 > 0) a = x;
		else b = x;
		++n; // номер итерации
	}while ((b - a) > eps);

	T x = (a + b)/2;
   	cout << std::setw(4) << n << std::setw(12) << a <<
        std::setw(12) << b << std::setw(12) << x << '\n';
	return x;
}

int main(){
	T a, b, eps;
	cin >> a >> b >> eps;
    cout << '\n';
	T x = div_half(a, b, eps);
	cout << '\n' << x << '\n';
	return 0;
}
