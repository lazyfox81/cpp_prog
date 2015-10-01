// Потоки данных, файловые потоки
#include <iostream> 	//заголовочный файл, в котором содержатся описания классов, 
			//реализующих потоки ввода/вывода и объекты cin, cout
#include <fstream> 	//заголовочный файл, в котором содержатся описания классов, 
			//реализующих потоки ввода/вывода в файл
#include <cstring> 	// заголовочный файл содержащий описания функций для работы с символьными массивами, 
			//заканчивающимися нуль-символом  (по сути строками)

using std::cin;
using std::cout;
using std::ios;
//using namespace std;

int main(){
	std::ofstream out("test.txt");	//конструктор создает объект out класса ofstream (класс выходных файловых потоков), связанный с файлом test.txt
	if (!out){
		cout << "Cannot open file 'test.txt' for writing" << '\n';
		return 1; 						// выход из функции типа int с указанием на ошибку
	}
	double num = 100.45;
	char str[] = "This is a test.";
	out.write(reinterpret_cast<char *>(&num), sizeof(double));	//Приведение типа reinterpret_cast<char *> 
									//в вызове функции write() и read() необходимо в тех случаях, когда
									//параметр не является символьным массивом.
	// Функция write() определена для объекта out класса ofstream. Поэтому обращение к ней осуществляется в виде out.write()
	
	out.write (str, strlen(str));
	out.close();	
	// для закрытия потока определен метод close(); он неявно выполняется деструктором. Явный вызов выполняется тогда, когда необходимо
	// закрыть поток раньше конца его области видимости
	
	// Чтение из файла
	std::ifstream in("test.txt", ios::in); //флаги in (открыть для чтения);
	if (!in){
		cout << "Cannot open file 'test.txt' for reading" << '\n';
		return 1;
	}
	double check_num;
	char check_str[60];
	in.read(reinterpret_cast<char*>(&check_num), sizeof(double));
	in.read(check_str, 60);
	int lstr = in.gcount();		//количество прочитанных символов
	check_str[lstr] = 0;		//занести нуль-символ в конец строки; нумерация массива начинается с нуля
	
	cout << check_num << '\n' << check_str << '\n' << lstr << '\n';
	cout << sizeof(double)<< '\n';
	
	in.close();
	return 0;
	
	
} 