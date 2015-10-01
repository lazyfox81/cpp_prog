// Вставка элемента в массив
#include <iostream>
using std::cout;

typedef int T;
int len;

void insert (T x, T* d, int& L, int index){
	// x - значение вставляемого элемента, *d - указатель на массив, 
	//int& L - создание ссылки на длину массива
	//index - индекс вставляемого элемента
	for (int j = L; j > index; --j){
		// первая итерация j = L. Этого элемента в массиве пока не было (там лежит 0)
		// Поэтому важно чтобы память, зарезервированная под массив была больше рассматриваемой длины
		d[j] = d[j - 1]; // i-ый элемент становится равен i-1
	}
	d[index] = x;
	++L;
}

// Удаление элемента из массива
void delete_ (T* d, int& L, int index){
	for (int j = index; j < L; ++j){
		d[j] = d [j + 1];
	}
	--L;
}

int main (){
	len = 5;
	T data [10] = {3, 4, 5, 8, 10};
	
	insert (6, data, len, 3);
	for (int i = 0; i < len; ++i){
		cout << data[i] << ' ';
	}
	cout << '\n' << len << '\n';
	
	delete_ (data, len, 2);
	for (int i = 0; i < len; ++i){
		cout << data[i] << ' ';
	}
	cout << '\n' << len << '\n';
	return 0;
}