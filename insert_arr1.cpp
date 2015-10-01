// Вставка элемента в массив
#include <iostream>
#include <cstdlib>
using std::cout;

typedef int T;

struct list{
	T* data;
	int length;
	int max_length;
};
// Вставка элемента в массив
void insert (T x, list& L, int index){
	for (int j = L.length; j > index; --j){
		L.data[j] = L.data[j - 1];
	}
	L.data[index] = x;
	++L.length;
}

// Удаление элемента из массива
void delete_ (list& L, int index){
	for (int j = index; j < L.length; ++j){
		L.data[j] = L.data[j + 1];
	}
	--L.length;
}

int main (){
	list a;
	a.data = new T[10];
	a.max_length = 10;
	a.length = 5;
	for  (int i =0; i < a.length; ++i){
		a.data[i] = rand()%10;
		cout << a.data[i] << ' ';
	}
	cout << '\n';
	insert(10, a, 3);
	for  (int i =0; i < a.length; ++i){
		cout << a.data[i] << ' ';
	}
	cout << '\n' << a.length << '\n';
	
	delete_(a, 2);
	for  (int i =0; i < a.length; ++i){
		cout << a.data[i] << ' ';
	}
	cout << '\n' << a.length << '\n';
	
	delete [] a.data;
	return 0;
}