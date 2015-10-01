// Работа со строками
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;

int main(){
	char str[] = "Sample string";
	char buf[32]; //Буфер больше копируемой строки
	
	memset(buf, 0, sizeof(buf));  // очистка буфера для вывода; функция из библиотеки cstring
	
	cout << str << '\n';
	cout << buf << '\n';
	
	strcpy(buf, str); // фуккция копирования строки из библиотеки cstring
	 
	cout << buf << '\n';
	
	return 0;
}