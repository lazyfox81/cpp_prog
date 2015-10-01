#include <iostream>
using std::cin;
using std::cout;

int main(){
	char ch[30];
	char ch2[30];
	int n = 4;
	for(int i = 0;  i< n; ++i){
		cin >> ch[i];
		if (ch[i] < 'x') ch2[i] = ch[i] + 3;
		else ch2[i] = 'a' + (ch[i] - 'x');
	}
	for (int i = 0; i < n; ++i){
		cout << ch2[i] << ' ';
	}
	cout << '\n';
	return 0;
}