#include <iostream>
#include <cstring>
#include <cstdlib>

using std::cin;
using std::cout;

// Консольный калькулятор

int main(){
	double a, b, res;
	int i, j, a_num; // b_num;
	const int MAX_LEN = 21;
	char str[MAX_LEN], a_str[10], b_str[10];
	char op;
	cin.getline(str, MAX_LEN);
	int str_len = strlen(str); //возвращает длину строки 2,36+7,58 9 символов
	bool pr = true; //признак идентификации оператора

	for(i = 1; i < str_len; ++i){
		switch(str[i]){
			case '+': op = str[i]; a_num = i; pr = true; break;
			case '-': op = str[i]; a_num = i; pr = true; break;
			case '*': op = str[i]; a_num = i; pr = true; break;
			case '/': op = str[i]; a_num = i; pr = true; break;
			default : pr = false;
		}
		if (pr) break;
	}
	//cout << MAX_LEN << ' '<< str_len << ' ' << a_num << ' ' << pr <<'\n';
	if (!pr) {
		cout << "Operation is not defined!\n";
		return 1;
	}
	
	strncpy(a_str, str, a_num); 	// копирует первые a_num символов из str в a_str
	a_str[a_num]=0;			// добавление нуль-символа в конец строки
	
	j = 0;
	for (i = a_num+1; i <= str_len; ++i){
		b_str[j] = str[i];
		++j;
	}
	//b_num = strlen(b_str);
	
	//cout << a_str << ' ' << b_str << ' ' << a_num << ' ' << b_num << ' ' << op << ' ' << pr << '\n';
	
	a = atof(a_str); // преобразование строки в число типа double, описание функции в <cstdlib>
	b = atof(b_str);
		
	bool f = true;
	
	switch (op){
		case '+': res = a + b; break; // если не будет break она пробежит все case до конца и выйдет на последнем
		case '-': res = a - b; break;
		case '*': res = a * b; break;
		case '/': res = a / b; break;
		default : cout << "No definable operation\n"; f = false;
	}
	if (f) cout << res << '\n';// 3.46 + 2.45 
	return 0;
}