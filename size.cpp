# include <iostream>
//# include <cstdlib>
//# include <math.h>
# include <limits> // определяет характеристики типов переменных
using namespace std;

// Выдает максимальное и минимальное число и размер в байтах
int main(){
  
  int max_int = std::numeric_limits<int>::max();
  int min_int = std::numeric_limits <int>::min();
  cout << min_int << "..." << max_int << endl;
  cout << sizeof(int) << endl;
  
  return 0;
  
  
}
