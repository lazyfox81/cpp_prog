#include <iostream>

// Метод пузырьковой сортировки

int main(){
	const int n = 10;
	int arr[n] = {10, 30, 20, -5, -60, -40, 2, -30, 4, -10};
	
	for (int i = 0; i < n-1; ++i){
		for (int j = 0; j < n-1; ++j){
			if (arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	for(int i = 0; i < n; ++i)
		std::cout << arr[i]<<' ';
	std::cout << '\n';
	
	return 0;
}

