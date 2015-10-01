#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using std::cin;
using std::cout;

//------------------------------------------------------
struct node {
		char name[20]; 		// Имя переменной
		char value[10]; 	// Значение переменной
		node* next; 		//Ссылка на следующий элемент списка
};
//------------------------------------------------------
struct dyn_list {
		node* head; 		// Первый элемент (голова) списка
		node* tail; 		// Последний элемент (хвост) списка
}; 
//------------------------------------------------------

// Создание пустого списка
void constr_list(dyn_list &l){
	l.head = 0;
}

// Проверка списка на пустоту
bool chk_empty(dyn_list l){
	return (l.head==NULL);
}

 // Включение в список нового компонента
void node_in(dyn_list &l, char* n, char* v){
	node* c = new node;
	strncpy(c->name, n, 20);
	strncpy(c->value, v, 10);
	c->next = 0;
	if (chk_empty(l))
		l.head = c;
	else
		l.tail->next = c;
	l.tail = c;
} 

// Поиск компонента в списке по имени
//Возвращать наша функция будет адрес найденного узла или NULL, если ничего не найдено. Искать начнем с компонента, 
//на который указывает head и, двигаясь вперед, сравнивать имя текущей переменной с искомым. В функции поиска мы можем 
//не боясь, передвигать ссылку head, так как передаем ее НЕ по ссылке. 
//Функция int *strcmp(char *s1, char *s2) сравнивает строки и возвращает отрицат. (если s1 меньше s2), нулевое (если s1 равно s2)
//или положительное (если s1 больше s2) значение
node* search(dyn_list l, const char *n){
	while (l.head != NULL)	{
		if (!strcmp(l.head->name,n))
			return l.head;
		l.head = l.head->next;
	}
	return l.head;
} 

// Удаление компонента из списка
void node_del(dyn_list &l, node* c){
	if (c == l.head){
		l.head = c->next;
		return;
	}
	node* r = new node;
	r = l.head; 
	while (r->next != c)
		r = r->next;
	
	//Нашли элемент r->next = c. Тогда передвигаем указатель на следующий: r->next = c->next и удаляем эл-т с.
	r->next = c->next; 
	delete c;
} 

// Изменение значения компонента
void node_edit(node &c, const char* v){
	strncpy(c.value, v, 10);
} 

// Вывод списка в файл
void print(dyn_list l, char* file_out){
	std::ofstream* out = new std::ofstream(file_out);
	while (l.head != NULL) {
		out->write(l.head->name, strlen(l.head->name));
		out->write(" ",1);
		out->write(l.head->value, strlen(l.head->value));
		out->write(" ",1);
		l.head = l.head->next;
	}
	out->close();
}

// Очистка списка
void clean(dyn_list &l){
	while(l.head){
		node* temp = l.head->next;
		delete l.head;
		l.head = temp;
	}
}

int main(){
	char* file_input = new char[50];
	char* file_output = new char[50];
	char* buf_name = new char[20];
	char* buf_value = new char [10];
	dyn_list vars; 					// Динамический список
	
	cout << "Enter name of input file -> ";
	cin >> file_input;
	cout << "Enter name of output file -> ";
	cin >> file_output;
	
	std::ifstream* inp = new std::ifstream(file_input);
	
	if (!inp->good()){
		cout << "File opening error!\n";
		return 0;
	} 
	
	constr_list(vars);				// Создание пустого списка
	
	while (!inp->eof()){
		inp->getline(buf_name, 20, ' ');
		inp->getline(buf_value, 10, ' ');
		node_in(vars, buf_name, buf_value);
	}
	inp->close();
		
	node* p = new node;
	
	p = search(vars,"z");
	if (p) node_del(vars, p);
	
	p = search(vars, "abc");
	if (p) node_edit(*p, "45");
	
	print(vars, file_output);
	clean(vars);
	
	
	return 0;
} 
